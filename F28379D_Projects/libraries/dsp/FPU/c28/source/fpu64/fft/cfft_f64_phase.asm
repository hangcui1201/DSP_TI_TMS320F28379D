;;#############################################################################
;;! \file source/fpu64/fft/cfft_f64_phase.asm
;;!
;;! \brief  Complex Fast Fourier Transform Phase (Double Precision)
;;! \author Vishal Coelho
;;! \date   02/01/2016
;;
;; DESCRIPTION:
;;
;;   Calculates the phase for the 64-bit double precision floating point 
;;   complex FFT.
;;
;; FUNCTIONS:
;;
;;  void CFFT_f64_phase (CFFT_F64_Handle)
;;  
;;   where CFFT_F64_Handle is defined as:
;;   typedef CFFT_f64_Struct* CFFT_F64_Handle;
;;  
;;  and where CFFT_f64_Struct is a structure defined as:
;;  
;;  typedef struct {
;;   long double *p_input;       //!< Pointer to the input buffer
;;   long double *p_output;      //!< Pointer to the output buffer
;;   long double *p_twiddles;    //!< Pointer to the twiddle factors
;;   long double *p_currInput;   //!< Points to input buffer at each FFT stage
;;   long double *p_currOutput;  //!< Points to output buffer at each FFT stage
;;   uint16_t    stages;         //!< Number of FFT stages
;;   uint16_t    FFTSize;        //!< FFT size (number of complex data points)
;;   void (*init)(void *);       //!< Pointer to the initialization function
;;   void (*calc)(void *);       //!< Pointer to the calculation function
;;   void (*mag)(void *);        //!< Pointer to the magnitude function
;;   void (*phase)(void *);      //!< Pointer to the phase function
;;   void (*win)(void *);        //!< Pointer to the windowing function
;;  }CFFT_f64_Struct;
;;
;; ASSUMPTIONS:
;;
;;  * CFFT_f64() has been called prior to this function
;;  * FFTSize is a power of 2 (atleast 32)
;;
;; ALGORITHM:
;;
;;     Calculate the complex FFT phase. The data is organized as follows in
;;     the output buffer after calculating FFT:
;;
;;  +----------------------------+
;;  |  R(0)                      | 0
;;  |  I(0)                      |
;;  |  R(1)                      | 
;;  |  I(1)                      |
;;  .                            .
;;  .                            .
;;  .                            .
;;  .                            .
;;  |  R(FFTSize/2) = fs/2       |
;;  |  I(FFTSize/2)              |
;;  .                            .
;;  .                            .
;;  .                            .
;;  .                            .
;;  |  R(N-2)                    | 
;;  |  I(N-2)                    |
;;  |  R(N-1)                    |
;;  |  I(N-1)                    | FFTSize - 1
;;  +----------------------------+
;;
;;  Group:            C2000
;;  Target Family:    C28x+FPU64
;;
;;#############################################################################
;; $TI Release: C28x Floating Point Unit Library V2.01.00.00 $
;; $Release Date: May 27, 2019 $
;; $Copyright: Copyright (C) 2019 Texas Instruments Incorporated -
;;             http://www.ti.com/ ALL RIGHTS RESERVED $
;;#############################################################################
    .if __TI_EABI__
    .asg CFFT_f64_phase, _CFFT_f64_phase
    .asg atan2, _atan2l
    .endif
;; the includes

;; external references
    .ref    _atan2l
;; file globals

;;*****************************************************************************
;; void CFFT_f64_phase(CFFT_f64_Handle) 
;;
;; The function takes a handle to the CFFT_f64 object as an argument. 
;;
;; Register Usage:                                                            
;;   XAR0 :            
;;   XAR1 : 
;;   XAR2 : 
;;   XAR3 :           
;;   XAR4 : points to the object                               
;;   XAR5 : points to the buffer (output pointer)                    
;;   XAR6 : points to the buffer (input pointer) 
;;   XAR7 :           
;;     AL : 
;;
;; Stack Usage:
;;
;;   |_______|<- Stack Pointer       (SP)
;;   |_______|<- R7H                 (SP-2)
;;   |_______|<- R6H                 (SP-4)
;;   |_______|<- R5H                 (SP-6)
;;   |_______|<- R4H                 (SP-8)
;;
;;*****************************************************************************

    .page
    .global _CFFT_f64_phase
    .sect   ".text"
_CFFT_f64_phase:
    .asmfunc
    .asg    *+XAR4[0], OBJ_CURR_INPUT_PTR
    .asg    *+XAR4[2], OBJ_CURR_OUTPUT_PTR
    .asg    *+XAR4[4], OBJ_STAGES 
    .asg    *+XAR4[5], OBJ_FFTSIZE
;;-----------------------------------------------------------------------------
;; Context Save <<TODO: see what RxH registers are used by the atan function 
;;                and whether we need to save these regs>>
;;-----------------------------------------------------------------------------
    MOV32   *SP++, R4H
    MOV32   *SP++, R5H
    MOV32   *SP++, R6H
    MOV32   *SP++, R7H
;;-----------------------------------------------------------------------------
;; The Complex FFT Phase
;;-----------------------------------------------------------------------------
    ADDB    XAR4, #6
    MOVL    XAR5, OBJ_CURR_OUTPUT_PTR
    MOVL    XAR6, OBJ_CURR_INPUT_PTR
    MOV     AL, OBJ_FFTSIZE         ; AL  = FFTSize
    SUBB    AL, #1                  ; AL  = FFTSize - 1
    MOVZ    AR0, AL                 ; AR0 = FFTSize - 1

_CFFT_f64_phase_loop:
    MOV32   R1L, *XAR6++            ; R1 = Re[i]
    MOV32   R1H, *XAR6++
    MOV32   R0L, *XAR6++            ; R0 = Im[i]
    MOV32   R0H, *XAR6++
    PUSH	XAR6
    PUSH	XAR5
    PUSH	XAR0
    LCR     _atan2l                 ; R0 = phase[i] = atan2l(Im[i], Re[i])
    POP		XAR0
    POP		XAR5
    POP		XAR6
    MOV32   *XAR5++, R0L
    MOV32   *XAR5++, R0H
    BANZ    _CFFT_f64_phase_loop, AR0--
    
;;-----------------------------------------------------------------------------
;; Context Restore
;;-----------------------------------------------------------------------------
    MOV32   R7H, *--SP
    MOV32   R6H, *--SP
    MOV32   R5H, *--SP
    MOV32   R4H, *--SP
    LRETR   
    .endasmfunc
    .unasg  OBJ_CURR_INPUT_PTR
    .unasg  OBJ_CURR_OUTPUT_PTR
    .unasg  OBJ_STAGES 
    .unasg  OBJ_FFTSIZE

;; End of File
