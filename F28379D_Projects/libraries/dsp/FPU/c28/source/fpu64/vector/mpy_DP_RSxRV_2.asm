;;#############################################################################
;;! \file source/fpu64/vector/mpy_DP_RSxRV_2.asm
;;!
;;! \brief  C-Callable multiplication of a real scalar and a real vector
;;! \author Vishal Coelho (adapted from SP version by David Alter)
;;! \date   07/14/2016
;;
;; DESCRIPTION: C-Callable multiplication of a real scalar and a real vector
;;              y[i] = c*x[i]
;;
;; FUNCTIONS:
;;   extern void mpy_DP_RSxRV_2(long double *y, const long double *x, 
;;                 const long double c, const uint16_t N)
;;  
;; PARAMETERS:  long double *y = result real array
;;              long double *x = input real array
;;              long double c  = input real scalar
;;              uint16_t N     = length of x and y array
;;
;; RETURNS:    none
;;
;; BENCHMARK:  4*N + 18 cycles (including the call and return)
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
;;  void mpy_DP_RSxRV_2(long double *y, const long double *x, 
;;                 const long double c, const uint16_t N)
;;
;; C-Callable multiplication of a real scalar and a real vector
;;              y[i] = c*x[i]
;;
;; Register Usage:
;;     AL  :  N, length of the x and y array
;;   XAR4  : *y, pointer to the result real array
;;   XAR5  : *x, pointer to the input real array
;;   R0    :  c, the real scalar
;;   
;; Stack Usage:
;;
;;   |_______|<- Stack Pointer                    (SP)
;;   |_______|<- rpc calling function             (SP-2)
;;   |_______|<- pointer to c                     (SP-4)
;;*****************************************************************************
    .if __TI_EABI__
    .asg mpy_DP_RSxRV_2, _mpy_DP_RSxRV_2
    .endif
    
    .page
    .global _mpy_DP_RSxRV_2
    .sect   ".text"
_mpy_DP_RSxRV_2:
    .asmfunc
    LSR     AL, #1              ; AL = N/2
    SUBB    AL, #2              ; AL = N/2 - 2 (-1 for the RPTB, -1 since last 
                                ; iteration is done seperately)
    MOV32   R1L, *XAR5++        ; R1 = x[i]
    MOV32   R1H, *XAR5++        ;
    
    ;; Main Loop
    .align  2
    RPTB    _mpy_DP_RSxRV_2_loop, AL  
    MPYF64  R2, R0, R1          ; *|   R2 = c*x[i]
 || MOV32   R1L, *XAR5++        ;  |   R1 = x[i+1]
    MOV32   R1H, *XAR5++        ; 1| 
    MPYF64  R3, R0, R1          ; 2|*| R3 = c*x[i+1]
 || MOV32   R1L, *XAR5++        ;  | | R1 = x[i]
    MOV32   R1H, *XAR5++        ;  |1| 
    MOV32   *XAR4++, R2L        ;  |2| store y[i]
    MOV32   *XAR4++, R2H        ;  | | 
    MOV32   *XAR4++, R3L        ;  | | store y[i+1]
    MOV32   *XAR4++, R3H        ;  | | 
_mpy_DP_RSxRV_2_loop:

    ;; Last iteration
    MPYF64  R2, R0, R1          ; *|   R2 = c*x[i]
 || MOV32   R1L, *XAR5++        ;  |   R1 = x[i+1]
    MOV32   R1H, *XAR5++        ; 1| 
    MPYF64  R3, R0, R1          ; 2|*| R3 = c*x[i+1]
    MOV32   *XAR4++, R2L        ;  |1| store y[i]
    MOV32   *XAR4++, R2H        ;  |2| 
    MOV32   *XAR4++, R3L        ;  | | store y[i+1]
    MOV32   *XAR4++, R3H        ;  | |
    LRETR
    .endasmfunc
    .unasg  STK_ARG_C
  
;; End of File
