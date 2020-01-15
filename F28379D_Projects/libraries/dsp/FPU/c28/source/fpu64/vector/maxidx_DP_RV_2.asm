;;#############################################################################
;;! \file source/fpu64/vector/maxidx_DP_RV_2.asm
;;!
;;! \brief  C-Callable index of maximum value of an even length real array
;;! \author Vishal Coelho (adapted from SP version by David Alter)
;;! \date   07/12/2016
;;
;; DESCRIPTION: C-Callable index of maximum value of an even length real array
;;
;; FUNCTIONS: extern uint16_t maxidx_DP_RV_2(const long double *x, 
;;                                const uint16_t N);
;;  
;; PARAMETERS:  long double *x = pointer to the input array
;;              uint16_t N     = length of x
;;
;; RETURNS:    uint16_t index = index of maximum value in x
;;
;; BENCHMARK:  4*N + 22 cycles (including the call and return)
;;
;; NOTES:
;;   1) N must be even and <= 65535.
;;   2) If more than one instance of the max value exists in x[], the function
;;      will return the index of the first occurrence (lowest index value).
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
;;  uint16_t maxidx_DP_RV_2(const long double *x, const uint16_t N)
;;
;; C-Callable index of maximum value of an even length real array
;;
;; Register Usage:
;;     AL  : N, the number of real data points
;;   XAR4  : *x, pointer to the real input array
;;
;;*****************************************************************************
    .if __TI_EABI__
    .asg maxidx_DP_RV_2, _maxidx_DP_RV_2
    .endif
    
    .page
    .global _maxidx_DP_RV_2
    .sect   ".text"
_maxidx_DP_RV_2:
    .asmfunc
    MOV32       R0L, *XAR4++    ; R0 = x[0] (initial max is first element 
    MOV32       R0H, *XAR4++    ; in x[])
    ZERO        R2              ; R2 = 0 (initial index is 0)
    ZERO        R3              ; R3 = 0 (index of first max candidate)
    LSR         AL, #1          ; AL = N/2
    SUBB        AL, #1          ; AL = N/2 - 1
    
    ;; Main Loop
    .align  2
    RPTB        _maxidx_DP_RV_2_loop, AL
    ADDF64      R3, R3, #1.0    ; *| increment index candidate
    MOV32       R1L, *XAR4++    ; 1| R1 = x[i] (max candidate)
    MOV32       R1H, *XAR4++    ; 2|
    ;; if max < max_candidate, max = max_candidate and index = index_candidate
    MAXF64      R0, R1          ;    if R0 < R1, R0 = R1 and R2 = R3
 || MOV64       R2, R3
    ADDF64      R3, R3, #1.0    ; *| increment index candidate
    MOV32       R1L, *XAR4++    ; 1| R1 = x[i] (max candidate)
    MOV32       R1H, *XAR4++    ; 2|
    ;; if max < max_candidate, max = max_candidate and index = index_candidate
    MAXF64      R0, R1          ;    if R0 < R1, R0 = R1 and R2 = R3
 || MOV64       R2, R3
_maxidx_DP_RV_2_loop:
    NOP
    ;; prepare the return value
    F64TOUI32   R2H, R2         ; *| convert index from float64 to uint32
    NOP                         ; 1|
    NOP                         ;    alignment cycle for FPU-to-CPU move
    MOV32       ACC, R2H        ;    index (return value) is in AL (uint16_t)
    LRETR
    .endasmfunc

  
;; End of File
