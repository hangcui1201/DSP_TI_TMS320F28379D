;;#############################################################################
;;! \file source/fpu64/vector/mpy_DP_RSxRVxRV_2.asm
;;!
;;! \brief  C-Callable multiplication of a real scalar, a real vector, and a 
;;!         real vector
;;! \author Vishal Coelho (adapted from SP version by David Alter)
;;! \date   07/14/2016
;;
;; DESCRIPTION: C-Callable multiplication of a real scalar, a real vector, 
;;              and a real vector
;;              y[i] = c*w[i]*x[i]
;;
;; FUNCTIONS:
;;  extern void mpy_DP_RSxRVxRV_2(long double *y, const long double *w, 
;;                const long double *x, const long double c, const uint16_t N)
;;  
;; PARAMETERS:  long double *y = result real array
;;              long double *w = input real array #1
;;              long double *x = input real array #2
;;              long double  c = input real scalar
;;              uint16_t     N = length of w, x and y arrays
;;
;; RETURNS:    none
;;
;; BENCHMARK:  6*N + 27 cycles (including the call and return)
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
;;  void mpy_DP_RSxRVxRV_2(long double *y, const long double *w, 
;;                const long double *x, const long double c, const uint16_t N)
;;
;; C-Callable multiplication of a real scalar, a real vector, and a real vector
;;              y[i] = c*w[i]*x[i]
;;
;; Register Usage:
;;     AL  :  N, length of the x and y array
;;   XAR4  : *y, pointer to the result real array
;;   XAR5  : *w, pointer to the first input real array
;;   XAR6  : *x, pointer to the second input real array
;;   R0    :  c,  the real scalar
;;   
;; Stack Usage:
;;
;;   |_______|<- Stack Pointer                    (SP)
;;   |_______|<- R6H                              (SP-2)
;;   |_______|<- R5H                              (SP-4)
;;   |_______|<- R4H                              (SP-6)
;;   |_______|<- rpc calling function             (SP-8)
;;   |_______|<- pointer to x                     (SP-10)

;;*****************************************************************************
    .if __TI_EABI__
    .asg mpy_DP_RSxRVxRV_2, _mpy_DP_RSxRVxRV_2
    .endif
    
    .page
    .global _mpy_DP_RSxRVxRV_2
    .sect   ".text"
_mpy_DP_RSxRVxRV_2:
    .asmfunc
    .asg    *-SP[10], STK_ARG_X
    MOV32   *SP++, R4H          ; Save R4H to the stack
    MOV32   *SP++, R5H          ; save R5H to the stack
    MOV32   *SP++, R6H          ; save R6H to the stack
    MOVL    XAR6, STK_ARG_X     ; XAR6 = &x[0]
        
    LSR     AL, #1              ; AL = N/2
    SUBB    AL, #2              ; AL = N/2 - 2 (-1 for the RPTB, -1 since last 
                                ; iteration is done seperately)
                                
    MOV32   R6L, *XAR5++        ; R6 = w[i]
    MOV32   R6H, *XAR5++        ;
    MOV32   R2L, *XAR6++        ; R2 = x[i]
    MOV32   R2H, *XAR6++        ;
    
    MOV32   R4L, *XAR5++        ; R4 = w[i+1]
    MOV32   R4H, *XAR5++        ;
    MOV32   R5L, *XAR6++        ; R5 = x[i+1]
    MOV32   R5H, *XAR6++        ;
    
    ;; Main Loop
    .align  2
    RPTB    _mpy_DP_RSxRVxRV_2_loop, AL
    MPYF64  R3, R6, R2          ; *|   R3 = y[i] = w[i]*x[i]
 || MOV32   R6L, *XAR5++        ;  |   R6 = w[i] (next)  
    MOV32   R6H, *XAR5++        ; 1|
    MPYF64  R1, R4, R5          ; 2|*| R1 = y[i+1] = w[i+1]*x[i+1]
 || MOV32   R4L, *XAR5++        ;  | | R4 = w[i+1] (next)
    MOV32   R4H, *XAR5++        ;  |1| 
    MPYF64  R3, R0, R3          ; *|2| R3 = y[i] = c*w[i]*x[i]
 || MOV32   R2L, *XAR6++        ;  | | R2 = x[i] (next)
    MOV32   R2H, *XAR6++        ; 1| | 
    MPYF64  R1, R0, R1          ; 2|*| R1 = y[i+1] = c*w[i+1]*x[i+1]
 || MOV32   R5L, *XAR6++        ;  | | R5 = x[i+1] (next)
    MOV32   R5H, *XAR6++        ;  |1| 
    MOV32   *XAR4++, R3L        ;  |2| store y[i]
    MOV32   *XAR4++, R3H        ;  | | 
    MOV32   *XAR4++, R1L        ;  | | store y[i+1]
    MOV32   *XAR4++, R1H        ;  | | 
_mpy_DP_RSxRVxRV_2_loop:
    
    ;; Last Iteration
    MPYF64  R3, R6, R2          ; *|   R3 = y[i] = w[i]*x[i]
    MOV32   R6H, *--SP          ; 1|   restore R6H 
    MPYF64  R1, R4, R5          ; 2|*| R1 = y[i+1] = w[i+1]*x[i+1]
 || MOV32   R5H, *--SP          ;  | | restore R5H)
    MPYF64  R3, R0, R3          ; *|1| R3 = y[i] = c*w[i]*x[i]
    MOV32   R4H, *--SP          ; 1|2| restore R4H
    MPYF64  R1, R0, R1          ; 2|*| R1 = y[i+1] = c*w[i+1]*x[i+1]
    MOV32   *XAR4++, R3L        ;  |1| store y[i]
    MOV32   *XAR4++, R3H        ;  |2| 
    MOV32   *XAR4++, R1L        ;  | | store y[i+1]
    MOV32   *XAR4++, R1H        ;  | |
    LRETR
    .endasmfunc
    .unasg  STK_ARG_X
  
;; End of File
