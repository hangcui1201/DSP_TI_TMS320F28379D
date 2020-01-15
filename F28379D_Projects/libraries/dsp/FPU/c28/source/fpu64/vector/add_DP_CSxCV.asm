;;#############################################################################
;;! \file source/fpu64/vector/add_DP_CSxCV.asm
;;!
;;! \brief  C-Callable addition of a complex scalar to a complex vector
;;! \author Vishal Coelho (adapted from SP version by David Alter)
;;! \date   07/08/2016
;;
;; DESCRIPTION: C-Callable addition of a complex scalar to a complex vector
;;              y_re[i] = x_re[i] + c_re
;;              y_im[i] = x_im[i] + c_im
;;
;; FUNCTIONS:
;;  void add_DP_CSxCV(complexf64_t *y, const complexf64_t *x, 
;;              const complexf64_t *c, const uint16_t N)
;;  
;; PARAMETERS:  complexf64_t *y = result complex array
;;              complexf64_t *x = input complex array
;;              complexf64_t *c = input complex scalar
;;              uint16_t      N = length of x and y arrays
;;
;; RETURNS:    none
;;
;; BENCHMARK:  8*N + 21 cycles (including the call and return)
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
;;  void add_DP_CSxCV(complexf64_t *y, const complexf64_t *x, 
;;              const complexf64_t *c, const uint16_t N)
;;
;; C-Callable addition of a complex scalar to a complex vector
;;      y_re[i] = x_re[i] + c_re
;;      y_im[i] = x_im[i] + c_im
;;
;;
;; Register Usage:
;;     AL  :  N, number of input elements
;;   XAR4  : *y, pointer to the complex output array
;;   XAR5  : *x, pointer to the complex input array
;;   
;;
;; Stack Usage:
;;
;;   |_______|<- Stack Pointer                    (SP)
;;   |_______|<- R4H                              (SP-2)
;;   |_______|<- rpc calling function             (SP-4)
;;   |_______|<- C                                (SP-6)
;;
;;*****************************************************************************
    .if __TI_EABI__
    .asg add_DP_CSxCV, _add_DP_CSxCV
    .endif

    .page
    .global _add_DP_CSxCV
    .sect   ".text"
_add_DP_CSxCV:
    .asmfunc
    .asg    *-SP[6], STK_ARG_C
    
    MOV32   *SP++, R4H      ; save R4H to the stack
    MOVL    XAR6, STK_ARG_C
    SUBB    AL, #2          ; AL = N - 2
    
    MOV32   R0L, *XAR6++    ; R0 = c_re
    MOV32   R0H, *XAR6++
    MOV32   R1L, *XAR6++    ; R1 = c_im
    MOV32   R1H, *XAR6++
    
    MOV32   R2L, *XAR5++    ; R2 = x_re[i]
    MOV32   R2H, *XAR5++    ;
    .align  2
    RPTB    _add_DP_CSxCV_loop, AL
    ADDF64  R4, R2, R0      ; *|   R4 = x_re[i] + c_re
 || MOV32   R3L, *XAR5++    ;  |   R3 = x_im[i]
    MOV32   R3H, *XAR5++    ; 1|
    ADDF64  R3, R3, R1      ; 2|*| R3 = x_im[i] + c_im
 || MOV32   R2L, *XAR5++    ;  | | R2 = x_re[i+1]
    MOV32   R2H, *XAR5++    ;  |1| 
    MOV32   *XAR4++, R4L    ;  |2| save R4
    MOV32   *XAR4++, R4H    ;  | | 
    MOV32   *XAR4++, R3L    ;  | | save R3
    MOV32   *XAR4++, R3H    ;  | |
_add_DP_CSxCV_loop
    ;; Last iteration done outside of loop
    ADDF64  R4, R2, R0      ; *|   R4 = x_re[i+1] + c_re
    MOV32   R3L, *XAR5++    ; 1|   R3 = x_im[i+1]
    MOV32   R3H, *XAR5++    ; 2|
    ADDF64  R3, R3, R1      ; *|   R3 = x_im[i+1] + c_im
 || MOV32   *XAR4++, R4L    ;  |   save R4
    MOV32   *XAR4++, R4H    ; 1|   
    MOV32   R4H, *--SP      ; 2|   restore R4H  
    MOV32   *XAR4++, R3L    ;  |   save R3
    MOV32   *XAR4++, R3H    ;  |
    LRETR
    .endasmfunc
    .unasg  STK_ARG_C

  
;; End of File
