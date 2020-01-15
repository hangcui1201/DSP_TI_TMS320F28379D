;;#############################################################################
;;! \file source/fpu64/filter/fir_f64.asm
;;!
;;! \brief  Finite Impulse Response Filter (Double Precision)
;;! \author Vishal Coelho
;;! \date   01/06/2016
;;
;;  This routine implements the non-recursive difference equation of an 
;;  all-zero filter (FIR) of order N. All the coefficients of an all-zero 
;;  filter are assumed to be less than 1 in magnitude.    
;;
;; FUNCTIONS:
;;  void FIR_f64_init(FIR_f64_Handle) 
;;  void FIR_f64_calc(FIR_f64_Handle) 
;;  
;;  where FIR_f64_Handle is a pointer to a structure defined as:
;;
;;  typedef struct { 
;;      long double *p_coeff;    //!<  Pointer to the filter coefficients
;;      long double *p_dbuffer;  //!<  Delay buffer pointer
;;      long double *p_input;    //!<  Pointer to the latest input sample
;;      long double *p_output;   //!<  Pointer to the filter output
;;      uint16_t order;          //!<  Order of the filter
;;      void (*init)(void *);    //!<  Pointer to the initialization function
;;      void (*calc)(void *);    //!<  Pointer to the calculation function
;;  }FIR_f64;
;;
;; ALGORITHM:
;;
;; Difference Equation :
;;
;;       y(n)=H(0)*x(n)+H(1)*x(n-1)+H(2)*x(n-2)+....+H(N)*x(n-N)
;;
;;      where
;;              y(n)=output sample of the filter at index n 
;;              x(n)=input sample of the filter at index n 
;;
;; Transfer Function :
;;                                  
;;      Y(z)                -1        -2               -(N-1)        -N
;;     ----- = h(0) + h(1) z  + h(2) z  + ... +h(N-1) z      + h(N) z    
;;      X(z)
;;
;; Network Diagram  : 
;;
;;     dbuffer[0]          dbuffer[1]    dbuffer[2]    dbuffer[N}
;;     Input           -1  x(n-1)  -1    x(n-2)        x(n-N)
;;   x(n) >------o----z---->-o----z---->-o---  - ->- - o
;;               |           |           |             |
;;               |           |           |             |
;;               |           |           |             |
;;               v H(0)      v H(1)      v H(2)        v H(N)  
;;               |           |           |             |  
;;               |           |           |             |        output
;;               |---->-----(+)---->----(+)-- - -> -  (+)-----> y(n)    
;;
;;       Symbols Used :
;;             H(0),H(1),H(2),...,H(N) : filter coefficients
;;            x(n-1),x(n-2),...,x(n-N) : filter states (delay line elements)
;;                                x(n) : filter input 
;;                                y(n) : filter output
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

;; the includes

;; external references

;;*****************************************************************************
;; void FIR_f64_init(FIR_f64_Handle) 
;;
;; The initialization function will zero out the delay line buffer and the 
;; inputs. It takes a handle to the FIR_f64 object as an
;; argument
;;
;; Register Usage:
;;     AL  : loop counter
;;   XAR4  : arg(FIR_f64_Handle) 
;;   XAR5  : pointer to the delay line buffer
;;
;;*****************************************************************************
    .if __TI_EABI__
    .asg FIR_f64_init, _FIR_f64_init
    .endif

    .page
    .global _FIR_f64_init
    .sect   ".text"
_FIR_f64_init:
    .asmfunc
    ; The object pointer is incremented by 2 on entry to give the following
    ; offsets
    .asg    *+XAR4[0], PTR_DBUFFER
    .asg    *+XAR4[2], PTR_INPUT
    .asg    *+XAR4[4], PTR_OUTPUT
    .asg    *+XAR4[6], ORDER
    ZAPA                        ; ACC:P = 0
    ADDB    XAR4, #2            ; XAR4 -> obj.p_dbuffer
    MOVL    XAR5, PTR_DBUFFER   ; XAR5 -> dbuffer
    MOV     ACC, ORDER << #2    ; ACC = order * 4 (double precision)
    ADDB    AL, #3              ; ACC = (order + 1)*4 - 1
    RPT     AL                  ; Repeat nTaps (ACC+1) times
 || MOV     *XAR5++, #0         ; zero out delay line
    LRETR
    .endasmfunc
    .unasg  PTR_DBUFFER
    .unasg  PTR_INPUT
    .unasg  PTR_OUTPUT
    .unasg  ORDER
    
;;*****************************************************************************
;; void FIR_f64_calc(FIR_f64_Handle) 
;;
;; The function takes a handle to the FIR_f64 object as an argument. It gets
;; the current input from the object, runs the filter, and returns the output
;; to the object.
;;
;; Register Usage:
;;   XAR0: repeat block count               | R0: Delay Line element
;;   XAR1:                                  | R1: Coefficient
;;   XAR2:                                  | R2: H(i)*x(i)
;;   XAR3:                                  | R3: sum_i=0_to_N-1(H(i)*x(i))
;;   XAR4: pointer to the object            | R4: 
;;   XAR5: pointer to the input & output    | R5: 
;;   XAR6: Pointer to the delay line buffer | R6: 
;;   XAR7: Pointer to the coefficients      | R7: 
;;         (starts from the end)            | 
;;      P: Temporarily store the input x(n) | 
;;   
;;*****************************************************************************
    .if __TI_EABI__
    .asg FIR_f64_calc, _FIR_f64_calc
    .endif
    
    .page
    .global _FIR_f64_calc
    .sect   ".text"
_FIR_f64_calc:
    .asmfunc
    ; The object pointer is incremented by 2 on entry to give the following
    ; offsets
    .asg    *+XAR4[0], PTR_DBUFFER
    .asg    *+XAR4[2], PTR_INPUT
    .asg    *+XAR4[4], PTR_OUTPUT
    .asg    *+XAR4[6], ORDER

;;-----------------------------------------------------------------------------
;; Convolution
;;-----------------------------------------------------------------------------
    MOVL    ACC, *XAR4++        ; ACC  -> coefficients, XAR4 -> obj.p_dbuffer
    ADD     ACC, ORDER << #2    ; ACC  -> coefficients[last]
    MOVL    XAR7, ACC           ; XAR7 -> coefficients[last]
    
    MOVZ    AR0, ORDER          ; loop runs order (#taps-1) times
    SUBB    XAR0, #1            ;
    MOVL    XAR5, PTR_INPUT     ; XAR5 -> p_input
    MOVL    ACC,  PTR_DBUFFER   ; ACC  -> p_dbuffer[0]
    MOVL    XAR6, ACC           ; XAR6 -> p_dbuffer[0]
    
    ;; Store the current input to the delay line
    MOVL    P, *+XAR5[0]        ; P = x(n).L
    MOVL    *+XAR6[0], P        ;
    MOVL    P, *+XAR5[2]        ; P = x(n).H
    MOVL    *+XAR6[2], P        ; D(0) = x(n)
    
    ADD     ACC, ORDER << #2    ; ACC  -> p_dbuffer[last]
    MOVL    XAR6, ACC           ; XAR6 -> p_dbuffer[last]

    MOV32   R1L, *+XAR7[0]      ; R1 = H(N-1)
    MOV32   R1H, *+XAR7[2]      ; 
    MOV32   R0L, *+XAR6[0]      ; R0 = x(N-1)
    MOV32   R0H, *+XAR6[2]      ; 
    ZERO    R2                  ; R2 = 0.0
    ZERO    R3                  ; R3 = 0.0
    ;;
    ;; Do the next NTAPS-1 (order )multiply accumulates starting with the 
    ;; N-1 elements
    ;;  (H(N-1) * x(N-1))
    ;; +(H(N-2) * x(N-2))
    ;; +(H(N-3) * x(N-3))
    ;; +..
    ;; +..
    ;; +(H(1) * x(1))
    ;;
    .align  2
    NOP                         ; odd align the repeat block to satisfy 8 word
                                ; minimum block size
    RPTB    _FIR_f64_calc_loop, AR0
    MACF64  R3, R2, R2, R1, R0  ; *| R3+=R2 then R2=H(i)*x(i)
 || MOV32   R1H, *--XAR7        ;  | R1 = H(--i)
    MOV32   R1L, *--XAR7        ; 1|
    MOVDD32 R0H, *--XAR6        ; 2| R0 = x(--i)
    MOVDD32 R0L, *--XAR6        ; 
_FIR_f64_calc_loop:

    ;; Do the final multiply and two accumulates
    MPYF64  R2, R1, R0          ; *|    R2 = H(0)*x(0)
 || ADDF64  R3, R3, R2          ;  | *| R3 += R2
    NOP                         ; 1| 1|
    NOP                         ; 2| 2|
    ADDF64  R3, R3, R2          ; *| R3 += R2, R3 = y(n)
    NOP                         ; 1|
    ;; Store to the object
    MOVL    XAR5, PTR_OUTPUT    ; 2| XAR5 -> obj.p_output
    MOV32   *+XAR5[0], R3L
    MOV32   *+XAR5[2], R3H
    LRETR
    .endasmfunc
    .unasg  PTR_DBUFFER
    .unasg  PTR_INPUT
    .unasg  PTR_OUTPUT
    .unasg  CBINDEX
    .unasg  ORDER
    
;; End of File
