;;#############################################################################
;;! \file source/fpu64/vector/add_DP_CVxCV.asm
;;!
;;! \brief  C-Callable addition of a two complex vectors
;;! \author Vishal Coelho (adapted from SP version by David Alter)
;;! \date   07/11/2016
;;
;; DESCRIPTION: C-Callable addition of a complex scalar to a complex vector
;;              y_re[i] = w_re[i] + x_re[i]
;;              y_im[i] = w_im[i] + x_im[i]
;;
;; FUNCTIONS:
;;  void add_DP_CVxCV(complexf64_t *y, const complexf64_t *w, 
;;              const complexf64_t *x, const uint16_t N)
;;  
;; PARAMETERS:  complexf64_t *y = result complex array
;;              complexf64_t *w = input complex array #1
;;              complexf64_t *x = input complex array #2
;;              uint16_t      N = length of x and y arrays
;;
;; RETURNS:    none
;;
;; BENCHMARK:  12*N + 15 cycles (including the call and return)
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
;;  void add_DP_CVxCV(complexf64_t *y, const complexf64_t *w, 
;;              const complexf64_t *x, const uint16_t N)
;;
;; C-Callable addition of a complex scalar to a complex vector
;;              y_re[i] = w_re[i] + x_re[i]
;;              y_im[i] = w_im[i] + x_im[i]
;;
;;
;; Register Usage:
;;     AL  :  N, number of input elements
;;   XAR4  : *y, pointer to the complex output array
;;   XAR5  : *w, pointer to the complex input array #1
;;   XAR6  : *x, pointer to the complex input array #2   
;;
;; Stack Usage:
;;
;;   |_______|<- Stack Pointer                    (SP)
;;   |_______|<- rpc calling function             (SP-2)
;;   |_______|<- x                                (SP-4)
;;
;;*****************************************************************************
    .if __TI_EABI__
    .asg add_DP_CVxCV, _add_DP_CVxCV
    .endif
    
    .page
    .global _add_DP_CVxCV
    .sect   ".text"
_add_DP_CVxCV:
    .asmfunc
    .asg    *-SP[4], STK_ARG_X
    
    MOVL    XAR6, STK_ARG_X
    SUBB    AL, #2          ; AL = N - 2
    
    MOV32   R0L, *XAR5++    ; R0 = w_re[i]
    MOV32   R0H, *XAR5++    ;
    .align  2
    RPTB    _add_DP_CVxCV_loop, AL
    MOV32   R1L, *XAR6++    ;    R1 = x_re[i]
    MOV32   R1H, *XAR6++    ;
    ADDF64  R2, R0, R1      ; *| R2 = w_re[i] + x_re[i]
 || MOV32   R0L, *XAR5++    ;  | R0 = w_im[i]
    MOV32   R0H, *XAR5++    ; 1|
    MOV32   R1L, *XAR6++    ; 2| R1 = x_im[i]
    MOV32   R1H, *XAR6++    ;  | 
    ADDF64  R3, R0, R1      ; *| R3 = w_im[i] + x_im[i]
 || MOV32   R0L, *XAR5++    ;  | R0 = w_re[i+1]    
    MOV32   R0H, *XAR5++    ; 1| 
    MOV32   *XAR4++, R2L    ; 2| save y_re[i]
    MOV32   *XAR4++, R2H    ;  | 
    MOV32   *XAR4++, R3L    ;  | save y_im[i]
    MOV32   *XAR4++, R3H    ;  |
_add_DP_CVxCV_loop:

    ;; Last iteration done outside of loop
    MOV32   R1L, *XAR6++    ;    R1 = x_re[i]
    MOV32   R1H, *XAR6++    ;
    ADDF64  R2, R0, R1      ; *| R2 = w_re[i] + x_re[i]
 || MOV32   R0L, *XAR5++    ;  | R0 = w_im[i]
    MOV32   R0H, *XAR5++    ; 1|
    MOV32   R1L, *XAR6++    ; 2| R1 = x_im[i]
    MOV32   R1H, *XAR6++    ;  | 
    ADDF64  R3, R0, R1      ; *| R3 = w_im[i] + x_im[i]
    MOV32   *XAR4++, R2L    ; 1| save y_re[i]
    MOV32   *XAR4++, R2H    ; 2| 
    MOV32   *XAR4++, R3L    ;  | save y_im[i]
    MOV32   *XAR4++, R3H    ;  |
    LRETR
    .endasmfunc
    .unasg  STK_ARG_X

  
;; End of File
