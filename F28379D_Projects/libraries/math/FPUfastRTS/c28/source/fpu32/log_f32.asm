;;#############################################################################
;;! \file source/fpu32/log_f32.asm
;;!
;;! \brief  Fast single precision natural logarithm for the C28x + FPU32
;;! \author Vishal Coelho   
;;! \date   01/26/2017
;;
;; DESCRIPTION:
;;
;;   This function computes the 32-bit floating point logarithm log(x)
;;
;; FUNCTIONS:
;;
;;   This funciton will be called whenever the standard C library function
;;   log() is called.
;;   
;;   float32 X,Y;
;;   ...
;;   <X initalized>
;;   ...
;;   Y = logf(X); 
;;  
;; ASSUMPTIONS:
;;
;; ALGORITHM:
;;
;; 1. calculate the absolute of x, |x|
;; 2. A floating point number is represented as X=[S]1.M*2^E where S is the 
;;    sign bit, M the mantissa, and E the biased exponent. The natural
;;    logarithm of such a number is given by
;;
;;      log(X) = log(1.M) + E*log(2)$$
;;
;; 3. Separate the exponent of the input, store it as a float.
;; 4. Separate the mantissa (1.M), and then the fractional portion Xm = M
;; 5. Subtract the bias from the exponent and multiply by log(2)
;; 6. Calculate log(1.M) using the polynomial approximation 
;;
;;      log(1 + M) = a0 + M*(a1 + M*a2)$$
;;
;; 7. The result is $log(1+M) + E*log(2)$, where E is now the unbiased exponent
;;
;;  Group:            C2000
;;  Target Family:    C28x+FPU32
;;
;;#############################################################################
;; $TI Release: C28x Floating Point Unit Library V2.01.00.00 $
;; $Release Date: May 27, 2019 $
;; $Copyright: Copyright (C) 2019 Texas Instruments Incorporated -
;;             http://www.ti.com/ ALL RIGHTS RESERVED $
;;#############################################################################


;; external references
    .if __TI_EABI__
    .asg    FPU32logTable, _FPU32logTable
    .asg    FPU32LOG2, _FPU32LOG2
    .asg    logf, _log
    .endif
    .ref    _FPU32logTable
    .ref    _FPU32LOG2
    
;;*****************************************************************************
;; Register Usage:
;;   XAR0: pointer to the lookup table | R0H : x, argument
;;
;; Stack Usage:
;;
;;   |_______|<- Stack Pointer                    (SP)
;;   |_______|<- LF_X_EXP_U                       (SP-1)-----> Local Frame
;;   |_______|<- LF_ABS_X_H                       (SP-2)    |
;;   |_______|<- LF_ABS_X_L|LF_ABS_X|LF_X_MANT    (SP-3)----
;;   |_______|<- rpc calling function             (SP-4)
;;
;;*****************************************************************************
    .page
    .global _log
    .sect   ".text"
    
LOG_TBL_SZ  .set    0x4200  ;32(entries)
    .if (__TI_EABI__ = 0)
    ; For TI COFF double and float are the same size, so logf() and 
    ; log() should be the same function
    .global _logf
_logf:
    .endif
_log:   .asmfunc
    .asg          3, LF_SIZE
	.asg    *-SP[1], LF_X_EXP_U
    .asg    *-SP[2], LF_ABS_X_H
    .asg    *-SP[3], LF_ABS_X_L
    .asg    *-SP[3], LF_ABS_X
    .asg    *-SP[3], LF_X_MANT

;;-----------------------------------------------------------------------------
;; Context Save
;;-----------------------------------------------------------------------------
    ; The stack pointer is aligned to an even address by the calling function
    ADDB        SP, #LF_SIZE        
;;-----------------------------------------------------------------------------
;; The algorithm
;;-----------------------------------------------------------------------------
    MOV32       LF_ABS_X, R0H        ;
    ;-----PIPELINE STALL=3 CYC-------;
    MOV         ACC, LF_ABS_X_H << 9 ; AH = x.exp
    SUB         AH, #127             ;    = x.exp - SP_BIAS

    ;; ANDing the argument with 0x3FFFFFFF will zero out the sign bit, which 
    ;; is equivalent to doing the absolute operation, and the most significant 
    ;; exponent bit while ORing with 0x3F800000 will set the exponent to 
    ;; 127 (single) or 1023 (double)
    ;;
    ;; Consider 10 = 1.25x2^3. In single precision float the leading 1 of the 
    ;; significand is implicit and the exponent is biased around 127, so its 
    ;; physical representation is 
    ;;   31|30           23|22                                        0|
    ;;   +-+---------------+-------------------------------------------+
    ;;   |0|1|0|0|0|0|0|1|0|0|1|0                 ...........         0|
    ;;   +-+---------------+-------------------------------------------+
    ;;    S| biased exp    | mantissa                                  |
    ;;     | E = 127+3=131 | 0.25                                      |
    ;;
    ;; X & 0x3FFFFFFF
    ;;   31|30           23|22                                        0|
    ;;   +-+---------------+-------------------------------------------+
    ;;   |0|0|0|0|0|0|0|1|0|0|1|0                 ...........         0|
    ;;   +-+---------------+-------------------------------------------+
    ;;    S| biased exp    | mantissa                                  |
    ;;     | E = 2         | 0.25                                      |
    ;; (X & 0x3FFFFFFF) | 0x3F800000
    ;;   31|30           23|22                                        0|
    ;;   +-+---------------+-------------------------------------------+
    ;;   |0|0|1|1|1|1|1|1|1|0|1|0                 ...........         0|
    ;;   +-+---------------+-------------------------------------------+
    ;;    S| biased exp    | mantissa                                  |
    ;;     | E = 127       | 0.25                                      |    
    ;; Now the value of this float (after removing exponent bias)
    ;;   = 1.25 * 2^(127-127(BIAS)) = 1.25
    ;; We have extracted just the mantissa (or significand)
    AND         LF_ABS_X_H, #0x3FFF  ; (x&0x3FFFFFFF)|0x3F800000
    OR          LF_ABS_X_H, #0x3F80  
    ;-----PIPELINE STALL=3 CYC-------;
    MOV32       R0H, LF_X_MANT       ;     R0H = |x|.mant
    FRACF32     R0H, R0H             ; *|      = frac(|x|.mant) or Xm
    MOV         LF_X_EXP_U, AH       ; 1|
    MPYF32      R2H, R0H, #LOG_TBL_SZ
                                     ; *|   R2H = |x|.mant*TBL_SZ*3*szof(float)
    I16TOF32    R1H, LF_X_EXP_U ; 1|*| R1H = exp_unbiased
    F32TOUI16   R2H, R2H             ; *|1| R2H = (int)(Xm*32.0)
    MOVW		DP, #_FPU32LOG2		 ; 1|
	MOV16		LF_X_MANT, R2H	     ;
    MOV			AL, #_FPU32logTable+6
    .if __TI_EABI__
    ;; The assembler does the addition of FPU32logTable and 6 prior to
    ;; taking the high word
    MOV			AH, #$HI16(FPU32logTable)+6
    .else
	MOV			AH, #((_FPU32logTable+6)>>16)
	.endif
	ADD			ACC, LF_X_MANT << #2 ;      ACC += 4*(int)(Xm*32.0)
	ADD			ACC, LF_X_MANT << #1 ;          += 2*(int)(Xm*32.0)
									 ;      ACC  -> FPU32logTable[idx].A2+2
    MOVL	    XAR0, ACC			 ;      XAR0 -> FPU32logTable[idx].A2+2
    MOV32       R2H, *--XAR0         ;      R2H = A2
    MPYF32      R3H, R0H, R2H        ; *|   R3H = Xm*A2
    MOV32       R2H, *--XAR0         ; 1|   R2H = A1
	ADDF32      R3H, R2H, R3H        ; *|   R3H = A1 + Xm*A2
    MOV32       R2H, @_FPU32LOG2       ; 1|   R2H = log(2)
    MPYF32      R3H, R0H, R3H        ; *|   R3H = Xm*(A1+Xm*A2)
 || MOV32       R0H, *--XAR0         ;  |   R0H = A0
    MPYF32      R1H, R2H, R1H        ; 1|*| R1H = log(2)*exp_unbiased
    ADDF32      R3H, R0H, R3H        ; *|1| R3H = A0 + Xm*(A1+Xm*A2)
    SUBB        SP, #LF_SIZE         ; 1|   deallocate local frame
    ADDF32      R0H, R1H, R3H        ; *|   R0H = log_exp+log_mant   
    NOP                              ; 1|
    LRETR
    .endasmfunc
    .unasg  LF_SIZE
	.unasg  LF_X_EXP_U
    .unasg  LF_ABS_X_H
    .unasg  LF_ABS_X_L
    .unasg  LF_ABS_X
    .unasg  LF_X_MANT   
    
;; End of File
