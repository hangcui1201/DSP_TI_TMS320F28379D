;;#############################################################################
;;! \file source/fpu64/vector/rnd_DP_RS.asm
;;!
;;! \brief  C-Callable unbiased rounding of a floating point scalar.
;;! \author Vishal Coelho (adapted from SP version by David Alter)
;;! \date   07/15/2016
;;
;; FUNCTIONS:
;;   extern long double rnd_DP_RS(long double x);
;;  
;; PARAMETERS: long double x = input value
;;
;; RETURNS:    long double y = result
;;
;; BENCHMARK: 26 cycles (including the call and return)
;; 
;; NOTES:
;;   1) numerical examples:
;;      rnd_DP_RS(+4.4) = +4.0
;;      rnd_DP_RS(-4.4) = -4.0
;;      rnd_DP_RS(+4.5) = +5.0
;;      rnd_DP_RS(-4.5) = -5.0
;;      rnd_DP_RS(+4.6) = +5.0
;;      rnd_DP_RS(-4.6) = -5.0
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
;; long double rnd_DP_RS(long double x);
;;
;; C-Callable unbiased rounding of a floating point scalar
;;
;; Register Usage:
;;   XAR4  : pointer to x
;;   XAR6  : pointer to rounded result (return long double)
;;
;; Stack Usage:
;;
;;   |_______|<- Stack Pointer                    (SP)
;;   |_______|<- rpc calling function             (SP-2)
;;
;;*****************************************************************************
    .if __TI_EABI__
    .asg    rnd_DP_RS, _rnd_DP_RS
    .endif
    
    .page
    .global _rnd_DP_RS
    .sect   ".text"
_rnd_DP_RS:
    .asmfunc
    .asg    *-SP[4], STK_ARG_X
    MOV32   R0L, *+XAR4[0]          ; R0 = x
    MOV32   R0H, *+XAR4[2]          ;
    CMPF64  R0, #0.0                ; determine if x is positive or negative
    MOVST0  NF                      ; Copy NF from MSTF to ST0
    BF      _rnd_DP_RS_negative, LT ; if (x < 0) jump to negative branch
    
    ;; x is positive
    ADDF64  R0, #0.5, R0            ;  *| R0 = x + 0.5
    NOP                             ;  1|
    NOP                             ;  2|
    FRACF64 R1, R0                  ;  *| R1 = fraction of R0
    NOP                             ;  1|
    SUBF64  R0, R0, R1              ;  *| R0 = floor(x+0.5)
    NOP                             ;  1|
    NOP                             ;  2|
    MOV32   *+XAR6[0], R0L          ;   | Return R0
    MOV32   *+XAR6[2], R0H          ;   |
    LRETR                           ;1,2|
   
_rnd_DP_RS_negative:
    ;; x is negative
    ADDF64  R0, #-0.5, R0           ;  *| R0 = x - 0.5
    NOP                             ;  1|
    NOP                             ;  2|
    FRACF64 R1, R0                  ;  *| R1 = fraction of R0
    NOP                             ;  1|
    SUBF64  R0, R0, R1              ;  *| R0 = floor(x-q0.5)
    NOP                             ;  1|
    NOP                             ;  2|
    MOV32   *+XAR6[0], R0L          ;   | Return R0
    MOV32   *+XAR6[2], R0H          ;   |
    LRETR                           ;1,2|
   
    .endasmfunc
    .unasg  STK_ARG_X
  
;; End of File
