;;#############################################################################
;;! \file source/fpu64/vector/iabs_DP_CV.asm
;;!
;;! \brief  C-Callable inverse absolute value of a complex vector.
;;! \author Vishal Coelho (adapted from SP version by David Alter)
;;! \date   07/11/2016
;;
;; DESCRIPTION: C-Callable inverse absolute value of a complex vector
;;          y[i] = 1/sqrt(x_re[i]^2 + x_im[i]^2)
;;
;; FUNCTIONS:
;;   void iabs_DP_CV(long double *y, const complexf64_t *x, 
;;                  const uint16_t N)
;;  
;; PARAMETERS: long double *y     = output array
;;             complexf64_t *x    = input array
;;             uint16_t N         = length of x and y arrays
;;
;; RETURNS:    none
;;
;; BENCHMARK: 69*N + 8 cycles (including the call and return)
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
;;  void iabs_DP_CV(long double *y, const complexf64_t *x, 
;;                  const uint16_t N)
;;
;;  C-Callable absolute value of a complex vector
;;          y[i] = 1/sqrt(x_re[i]^2 + x_im[i]^2)
;;
;; Register Usage:
;;     AL  : N, the number of complex data points
;;    AR0  : N, the number of complex data points
;;   XAR4  : *y, pointer to the output array
;;   XAR5  : *x, pointer to the complex input array
;;
;;*****************************************************************************
    .if __TI_EABI__
    .asg iabs_DP_CV, _iabs_DP_CV
    .endif
    
    .page
    .global _iabs_DP_CV
    .sect   ".text"
_iabs_DP_CV:
    .asmfunc
    SUBB    AL, #1              ; AL  = N - 1
    MOVZ    AR0, AL             ; AR0 = N - 1
    
_iabs_DP_CV_loop:
    ;; Computing the magnitude squared
    MOV32       R0L, *XAR5++    ;    R0 = x_re[i]
    MOV32       R0H, *XAR5++    ;
    MPYF64      R0, R0, R0      ; *| R0 = x_re[i]^2
    MOV32       R1L, *XAR5++    ; 1| R1 = x_im[i]
    MOV32       R1H, *XAR5++    ; 2|
    MPYF64      R1, R1, R1      ; *| R1 = x_im[i]^2
    NOP                         ; 1|
    NOP                         ; 2|
    ADDF64      R0, R0, R1      ; *| R0 = x_re[i]^2 + x_im[i]^2
    NOP                         ; 1|
    NOP                         ; 2|
    
    ;; Compute the square root
    EISQRTF64   R1, R0          ; *| R1 = Ye = Estimate(1/sqrt(X))
    NOP                         ; 1|
    MPYF64      R2, R0, #0.5    ; *| R2 = X*0.5
    ;; run loop 3 times
    .align  2
    RPTB        #_iabs_DP_CV_isqrt_loop, #2 
    MPYF64      R3, R1, R1      ; 1|*| R3 = Ye*Ye
    NOP                         ; 2|1|
    NOP                         ;  |2|
    MPYF64      R3, R3, R2      ; *| | R3 = Ye*Ye*X*0.5
    NOP                         ; 1| | 
    NOP                         ; 2| | 
    SUBF64      R3, #1.5, R3    ; *| | R3 = 1.5 - Ye*Ye*X*0.5
    NOP                         ; 1| | 
    NOP                         ; 2| | 
    MPYF64      R1, R1, R3      ; *| | R1 = Ye = Ye*(1.5 - Ye*Ye*X*0.5)
    NOP                         ; 1| |
    NOP                         ; 2| |
_iabs_DP_CV_isqrt_loop:
    MPYF64      R3, R1, R2      ; *| R3 = Ye'''*X*0.5
    NOP                         ; 1|
    NOP                         ; 2|
    MPYF64      R3, R1, R3      ; *| R3 = Ye'''*Ye'''*X*0.5
    NOP                         ; 1|
    NOP                         ; 2|
    SUBF64      R3, #1.5, R3    ; *| R3 = 1.5 - Ye'''*Ye'''*X*0.5
    NOP                         ; 1|
    NOP                         ; 2|
    MPYF64      R0, R1, R3      ; *| R0 = Ye'''*(1.5 - Ye'''*Ye'''*X*0.5)
    NOP                         ; 1|
    NOP                         ; 2|
    MOV32       *XAR4++, R0L    ;
    MOV32       *XAR4++, R0H    ;
    BANZ        _iabs_DP_CV_loop, AR0--
    LRETR
    .endasmfunc

  
;; End of File
