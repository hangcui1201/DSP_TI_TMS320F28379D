;;#############################################################################
;;! \file source/fpu64/fft/rfft_f64_phase.asm
;;!
;;! \brief  Real Fast Fourier Transform Phase (Double Precision)
;;! \author Vishal Coelho
;;! \date   07/05/2016
;;
;; DESCRIPTION:
;;
;;   Calculates the phase for the 64-bit double precision floating point 
;;   real FFT.
;;
;; FUNCTIONS:
;;
;;  void RFFT_f64_phase (CFFT_F64_Handle)
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
;;  * RFFT_f64() has been called prior to this function
;;  * FFTSize is a power of 2 (atleast 32)
;;
;; ALGORITHM:
;;
;;     Calculate the complex FFT phase. The data is organized as follows in
;;     the output buffer after calculating FFT:
;;
;;  +----------------------------+
;;  |  R(0)                      | 0
;;  |  R(1)                      |
;;  |  R(2)                      | 
;;  |  R(3)                      |
;;  .                            .
;;  .                            .
;;  .                            .
;;  .  R(FFTSize/2 - 1)          .
;;  |  R(FFTSize/2) = fs/2       |
;;  |  I(FFTSize/2 - 1)          |
;;  .  I(FFTSize/2 - 2)          .
;;  .                            .
;;  .                            .
;;  .                            .
;;  |  I(N-4)                    | 
;;  |  I(N-3)                    |
;;  |  I(N-2)                    |
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
    .asg    RFFT_f64_phase, _RFFT_f64_phase
    .asg    atan2, _atan2l
    .endif
    
;; the includes

;; external references
    .ref    _atan2l
;; file globals

;;*****************************************************************************
;; void RFFT_f64_phase(CFFT_f64_Handle) 
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
;;   XAR6 : points to the input buffer[1]       
;;   XAR7 : points to the input buffer[N-1]     
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
    .global _RFFT_f64_phase
    .sect   ".text"
_RFFT_f64_phase:
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
    MOVL    XAR6, OBJ_CURR_INPUT_PTR; XAR6 -> input[0]
    MOVL    ACC, OBJ_CURR_INPUT_PTR ; ACC  -> input[0]
    ADD     ACC, OBJ_FFTSIZE << #2  ; ACC  -> input[N]
    MOVL    XAR7, ACC               ; XAR7 -> input[N]
    MOV     ACC, OBJ_FFTSIZE << #15 ; AH  = FFTSize/2
    SUB     AH, #2                  ; AH  = FFTSize/2 - 2
    MOVZ    AR0, AH                 ; AR0 = FFTSize/2 - 2
    
    ; phase[0] is done out of the loop
    MOV32   R1L, *XAR6++            ; R1 = Re[0]
    MOV32   R1H, *XAR6++
    PUSH    XAR7
    PUSH	XAR6
    PUSH	XAR5
    PUSH	XAR0
    ZERO    R0
    LCR     _atan2l                 ; R0 = phase[0] = atan2l(0, Re[0])
    POP		XAR0
    POP		XAR5
    POP		XAR6
    POP     XAR7
    MOV32   *XAR5++, R0L
    MOV32   *XAR5++, R0H
    
    ; phase[i], i = 1 : N/2 - 1
    .align  2
_RFFT_f64_phase_loop:
    MOV32   R1L, *XAR6++            ; R1 = Re[i]
    MOV32   R1H, *XAR6++
    MOV32   R0H, *--XAR7            ; R0 = Im[i]
    MOV32   R0L, *--XAR7
    PUSH	XAR6
    PUSH	XAR7
    PUSH	XAR5
    PUSH	XAR0
    LCR     _atan2l                 ; R0 = phase[i] = atan2l(Im[i], Re[i])
    POP		XAR0
    POP		XAR5
    POP		XAR7
    POP		XAR6
    MOV32   *XAR5++, R0L
    MOV32   *XAR5++, R0H
    BANZ    _RFFT_f64_phase_loop, AR0--
    
    ; phase[N/2] is done out of the loop
    MOV32   R1L, *XAR6++            ; R1 = Re[N/2]
    MOV32   R1H, *XAR6++
    ZERO    R0
    PUSH	XAR6
    PUSH	XAR5
    LCR     _atan2l                 ; R0 = phase[N/2] = atan2l(0, Re[N/2])
    POP		XAR5
    POP		XAR6
    MOV32   *XAR5++, R0L
    MOV32   *XAR5++, R0H
    
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
