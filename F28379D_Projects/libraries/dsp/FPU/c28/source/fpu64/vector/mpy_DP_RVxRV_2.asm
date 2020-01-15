;;#############################################################################
;;! \file source/fpu64/vector/mpy_DP_RVxRV_2.asm
;;!
;;! \brief  C-Callable multiplication of a real vector and a real vector
;;! \author Vishal Coelho (adapted from SP version by David Alter)
;;! \date   07/15/2016
;;
;; DESCRIPTION: C-Callable multiplication of a real vector and a real vector
;;              y[i] = w[i]*x[i]
;;
;; FUNCTIONS:
;;   extern void mpy_SP_RVxRV_2(long double *y, const long double *w, 
;;                              const long double *x, const uint16_t N)
;;  
;; PARAMETERS:  long double *y = result real array
;;              long double *w = input real array #1
;;              long double *x = input real array #2
;;              uint16_t     N = length of w, x and y arrays
;;
;; RETURNS:    none
;;
;; BENCHMARK:  6*N + 17 cycles (including the call and return)
;;             
;; NOTES:
;;   1) N must be even, and at least 4.
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
;;  void mpy_SP_RVxRV_2(long double *y, const long double *w, 
;;                     const long double *x, const uint16_t N)
;;
;; C-Callable multiplication of a real vector and a real vector
;;              y[i] = w[i]*x[i]
;;
;; Register Usage:
;;     AL  :  N, length of the x and y array
;;   XAR4  : *y, pointer to the result real array
;;   XAR5  : *w, pointer to the first input real array
;;   XAR6  : *x, pointer to the second input real array
;;   
;; Stack Usage:
;;
;;   |_______|<- Stack Pointer                    (SP)
;;   |_______|<- rpc calling function             (SP-2)
;;   |_______|<- x                                (SP-4)
;;*****************************************************************************
    .if __TI_EABI__
    .asg mpy_DP_RVxRV_2, _mpy_DP_RVxRV_2
    .endif
    
    .page
    .global _mpy_DP_RVxRV_2
    .sect   ".text"
_mpy_DP_RVxRV_2:
    .asmfunc
    .asg    *-SP[4], STK_ARG_X
    MOVL    XAR6, STK_ARG_X
    SUBB    AL, #2              ; AL = N-2 (-1 for the RPTB, -1 since last 
                                ; iteration is done seperately)    
                                
    MOV32   R0L, *XAR5++        ; R0 = w[i]    
    MOV32   R0H, *XAR5++        ;
    MOV32   R1L, *XAR6++        ; R1 = x[i]    
    MOV32   R1H, *XAR6++        ;
    
    ;; Main Loop
    .align  2
    RPTB    _mpy_DP_RVxRV_2_loop, AL
    MPYF64  R2, R0, R1          ; *| R2 = w[i]*x[i]
 || MOV32   R0L, *XAR5++        ;  | R0 = w[i+1]
    MOV32   R0H, *XAR5++        ; 1|
    MOV32   R1L, *XAR6++        ; 2| R1 = x[i+1]    
    MOV32   R1H, *XAR6++        ;  |
    MOV32   *XAR4++, R2L        ;  | store y[i]
    MOV32   *XAR4++, R2H        ;  |
_mpy_DP_RVxRV_2_loop:

    ;; Last Iteration
    MPYF64  R2, R0, R1          ; *| R2 = w[i]*x[i]
    NOP                         ; 1|
    NOP                         ; 2|
    MOV32   *XAR4++, R2L        ;  | store y[i]
    MOV32   *XAR4++, R2H        ;  |
    LRETR
    .endasmfunc
    .unasg  STK_ARG_X
  
;; End of File
