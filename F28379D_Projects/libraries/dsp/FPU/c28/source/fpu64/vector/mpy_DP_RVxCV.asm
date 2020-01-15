;;#############################################################################
;;! \file source/fpu64/vector/mpy_DP_RVxCV.asm
;;!
;;! \brief  C-Callable multiplication of a real vector and a complex vector
;;! \author Vishal Coelho (adapted from SP version by David Alter)
;;! \date   07/15/2016
;;
;; DESCRIPTION: C-Callable multiplication of a real vector and a complex vector
;;              y_re[i] = x[i]*w_re[i]
;;              y_im[i] = x[i]*w_im[i]
;;
;; FUNCTIONS:
;;   extern void mpy_DP_RVxCV(complexf64_t *y, const complexf64_t *w, 
;;                            const long double *x, const uint16_t N)
;;  
;; PARAMETERS:  complexf64_t *y = result complex array
;;              complexf64_t *w = input complex array
;;              long double  *x = input real array
;;              uint16_t      N = length of w, x, and y arrays
;;
;; RETURNS:    none
;;
;; BENCHMARK:  10*N + 15 cycles (including the call and return)
;;             
;; NOTES:
;;   1) N must be at least 2.
;;   2) The type 'complexf64_t' is defined as
;;
;;      typedef struct {
;;         long double real;
;;         long double imag;
;;      } complexf64_t;
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
;; void mpy_DP_RVxCV(complexf64_t *y, const complexf64_t *w, 
;;                   const long double *x, const uint16_t N)
;;
;; C-Callable multiplication of a real vector and a complex vector
;;      y_re[i] = x[i]*w_re[i]
;;      y_im[i] = x[i]*w_im[i]
;;
;; Register Usage:
;;     AL  :  N, size of the vectors
;;   XAR4  : *y, pointer to the complex output
;;   XAR5  : *w, pointer to the complex input
;;   XAR6  : *x, pointer to the real input
;;   
;; Stack Usage:
;;
;;   |_______|<- Stack Pointer                    (SP)
;;   |_______|<- rpc calling function             (SP-2)
;;   |_______|<- pointer to x                     (SP-4)
;;*****************************************************************************
    .if __TI_EABI__
    .asg mpy_DP_RVxCV, _mpy_DP_RVxCV
    .endif
    
    .page
    .global _mpy_DP_RVxCV
    .sect   ".text"
_mpy_DP_RVxCV:
    .asmfunc
    .asg    *-SP[4], STK_ARG_X
    MOVL    XAR6, STK_ARG_X     ; XAR6 = &x[0]
    SUBB    AL, #2              ; AL = N-2 (-1 for the RPTB, -1 since last 
                                ; iteration is done seperately)
    MOV32   R0L, *XAR5++        ; R0 = w_re[i]
    MOV32   R0H, *XAR5++        ;

    ;; Main Loop
    .align  2
    RPTB    _mpy_DP_RVxCV_loop, AL
    MOV32   R1L, *XAR6++        ;      R1 = x[i]
    MOV32   R1H, *XAR6++        ;      
    MPYF64  R2, R1, R0          ; *|   R2 = x[i]*w_re[i]
 || MOV32   R0L, *XAR5++        ;  |   R0 = w_im[i]
    MOV32   R0H, *XAR5++        ; 1| 
    MPYF64  R3, R1, R0          ; 2|*| R3 = x[i]*w_im[i]
 || MOV32   R0L, *XAR5++        ;  | | R0 = w_re[i+1]
    MOV32   R0H, *XAR5++        ;  |1|
    MOV32   *XAR4++, R2L        ;  |2| store y_re[i]
    MOV32   *XAR4++, R2H        ;  | |
    MOV32   *XAR4++, R3L        ;  | | store y_im[i]
    MOV32   *XAR4++, R3H        ;  | | 
_mpy_DP_RVxCV_loop:
    
    ;; Last Iteration
    MOV32   R1L, *XAR6++        ;      R1 = x[i]
    MOV32   R1H, *XAR6++        ;      
    MPYF64  R2, R1, R0          ; *|   R2 = x[i]*w_re[i]
 || MOV32   R0L, *XAR5++        ;  |   R0 = w_im[i]
    MOV32   R0H, *XAR5++        ; 1| 
    MPYF64  R3, R1, R0          ; 2|*| R3 = x[i]*w_im[i]
    MOV32   *XAR4++, R2L        ;  |1| store y_re[i]
    MOV32   *XAR4++, R2H        ;  |2|
    MOV32   *XAR4++, R3L        ;  | | store y_im[i]
    MOV32   *XAR4++, R3H        ;  | | 
    LRETR
    .endasmfunc
    .unasg  STK_ARG_X
  
;; End of File
