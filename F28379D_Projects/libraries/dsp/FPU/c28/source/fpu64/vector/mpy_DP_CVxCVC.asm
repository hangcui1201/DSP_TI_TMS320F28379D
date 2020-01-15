;;#############################################################################
;;! \file source/fpu64/vector/mpy_DP_CVxCVC.asm
;;!
;;! \brief  C-Callable multiplication of a complex vector (w) and the complex 
;;!         conjugate of a complex vector (x)
;;! \author Vishal Coelho (adapted from SP version by David Alter)
;;! \date   07/14/2016
;;
;; DESCRIPTION:  C-Callable multiplication of a complex vector (w) and the 
;;              complex conjugate of a complex vector (x)
;;              xconj_re[i] = x_re[i]
;;              xconj_im[i] = - x_im[i]
;;              y_re[i] = w_re[i]*x_re[i] - w_im[i]*xconj_im[i]
;;                      = w_re[i]*x_re[i] + w_im[i]*x_im[i]
;;              y_im[i] = w_re[i]*xconj_im[i] + w_im[i]*x_re[i]
;;                      = w_im[i]*x_re[i] - w_re[i]*x_im[i] 
;;
;; FUNCTIONS:
;;   extern void mpy_DP_CVxCVC(complexf64_t *y, const complexf64_t *w, 
;;                    const complexf64_t *x, const uint16_t N)
;;  
;; PARAMETERS:  complexf64_t *y = result complex array
;;              complexf64_t *w = input complex array #1
;;              complexf64_t *x = input complex array #2
;;              uint16_t N      = length of w, x, and y arrays
;;
;; RETURNS:    none
;;
;; BENCHMARK:  20*N + 16 cycles (including the call and return)
;;             
;; NOTES:
;;   1) The type 'complexf64_t' is defined as
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
;; void mpy_DP_CVxCVC(complexf64_t *y, const complexf64_t *w, 
;;                    const complexf64_t *x, const uint16_t N)
;;
;; C-Callable multiplication of a complex vector (w) and the 
;; complex conjugate of a complex vector (x)
;;    xconj_re[i] = x_re[i]
;;    xconj_im[i] = - x_im[i]
;;    y_re[i] = w_re[i]*x_re[i] - w_im[i]*xconj_im[i]
;;            = w_re[i]*x_re[i] + w_im[i]*x_im[i]
;;    y_im[i] = w_re[i]*xconj_im[i] + w_im[i]*x_re[i]
;;            = w_im[i]*x_re[i] - w_re[i]*x_im[i] 
;;
;; Register Usage:
;;     AL  :  N, size of the vectors
;;   XAR4  : *y, pointer to the complex output
;;   XAR5  : *w, pointer to the first complex input
;;   XAR6  : *x, pointer to the second complex input
;;   
;; Stack Usage:
;;
;;   |_______|<- Stack Pointer                    (SP)
;;   |_______|<- R4H                              (SP-2)
;;   |_______|<- rpc calling function             (SP-4)
;;   |_______|<- pointer to x                     (SP-6)
;;*****************************************************************************
    .if __TI_EABI__
    .asg mpy_DP_CVxCVC, _mpy_DP_CVxCVC
    .endif
    
    .page
    .global _mpy_DP_CVxCVC
    .sect   ".text"
_mpy_DP_CVxCVC:
    .asmfunc
    .asg    *-SP[6], STK_ARG_X
    MOV32   *SP++, R4H          ; save R4H to the stack
    MOVL    XAR6, STK_ARG_X     ; XAR6 = &x[0]
    SUBB    AL, #1              ; AL = N - 1 (-1 for RPTB)    
    .align  2
    RPTB    _mpy_DP_CVxCVC_loop, AL
    MOV32   R0L, *XAR5++        ;      R0 = w_re
    MOV32   R0H, *XAR5++        ;      
    MOV32   R2L, *XAR6++        ;      R2 = x_re
    MOV32   R2H, *XAR6++        ;      
    MPYF64  R3, R0, R2          ; *|   R3 = w_re * x_re
 || MOV32   R1L, *XAR5++        ;  |   R1 = w_im
    MOV32   R1H, *XAR5++        ; 1|   
    NOP                         ; 2|
    MPYF64  R2, R1, R2          ; *|   R2 = w_im * x_re
 || MOV32   R4L, *XAR6++        ;  |   R4 = x_im
    MOV32   R4H, *XAR6++        ; 1|   
    NOP                         ; 2|   
    MPYF64  R1, R1, R4          ; *|   R1 = w_im * x_im
    MPYF64  R0, R0, R4          ; 1|*| R0 = w_re * x_im
    NOP                         ; 2|1|
    ADDF64  R3, R3, R1          ; *|2| R3 = (w_re * x_re) + (w_im * x_im)
    SUBF64  R2, R2, R0          ; 1|*| R2 = (w_im * x_re) - (w_re * x_im)
    NOP                         ; 2|1|
    MOV32   *XAR4++, R3L        ;  |2| store real part of return value
    MOV32   *XAR4++, R3H        ;
    MOV32   *XAR4++, R2L        ;      store imag part of return value
    MOV32   *XAR4++, R2H        ;
_mpy_DP_CVxCVC_loop:

    MOV32   R4H, *--SP          ; restore R4H
    LRETR
    .endasmfunc
    .unasg  STK_ARG_X
  
;; End of File
