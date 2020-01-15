;;#############################################################################
;;! \file source/fpu64/fid_i64byui32.asm
;;!
;;! \brief  Signed (64-bit)/ Unsigned (32-bit) Division
;;! \author Vishal Coelho  
;;! \date   04/11/2016 
;;
;; DESCRIPTION:
;;
;;   This function performs a 64-bit signed/ 32-bit unsigned division 
;;  (truncated)
;;
;; FUNCTIONS:
;;
;; void FID_i64byui32(int64_t *p_num_rem, int64_t *p_den_quo)
;;  
;; ASSUMPTIONS:
;;
;; ALGORITHM:
;;
;;  The algorithm used is a slow division method (Restoring division)
;;  see https://en.wikipedia.org/wiki/Division_algorithm#Restoring_division
;;
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



;;*****************************************************************************
;; Truncated Division
;;
;;  Let N be the dividend, D the divisor, T a temporary variable and P 
;;  the partial remainder of each iteration, i the bit index and loop iterator
;;    F.TF = sign(num)
;;    F.NI = sign(num)
;;    N = |N| , D = |D|
;;    R = 0 -- start with a remainder of 0
;; loop i = 63:-1:0
;;    T = (R << 1) + N(i) - D -- shift up remainder, tack on MSb of numerator
;;                            -- subtract divisor
;;    if(T >= 0)              -- if the difference is positive 
;;      R = T & 0xFFF...FFUL  ---- remainder = T        
;;      N = N << 1 + 1        ---- shift numerator up and add 1 (quotient)
;;    else                    -- else                  
;;      R = (R << 1) + N(63)  ---- shift up remainder, tack on MSb of numerator
;;      N = N << 1            ---- shift up numerator 
;;    end
;; endloop                    -- after 64 such iterations N has the quotient
;;                            -- and R the remainder
;; if(F.TF == 1), Q = -Q      -- The quotient is in the variable that 
;;                            -- previously held the numerator
;; if(F.NI == 1), R = -R      -- In truncating division remainder follows the 
;;                            -- sign of the dividend
;; Register Usage:
;;   R1H : dividend (quotient)
;;   R2H : remainder
;;   R3H : divisor 
;;   XAR4: pointer to dividend (numerator) and subsequently remainders 
;;   XAR5: pointer to divisor (denominator) and subsequently quotient 
;; 
;; cycles = 4(call) + 28(body) + 4(return)
;;        = 36
;;*****************************************************************************
    .page
    .if __TI_EABI__
    .asg    FID_i64byui32, _FID_i64byui32
    .endif
    .global _FID_i64byui32
    .sect   ".text"
_FID_i64byui32:
    .asmfunc
    MOV32        R0H, *+XAR4[0] ; [R1H:R0H] = dividend
    MOV32        R1H, *+XAR4[2]
    MOV32        R3H, *+XAR5[0] ; R3H = divisor
    ABSI64DIV32U R2H, R1H:R0H
    .asg    1, N
    .loop
    SUBC4UI32   R2H, R1H, R3H   
    .break  N == 8
    .eval   N + 1, N
    .endloop
    SWAPF       R1, R0
    .asg    1, N
    .loop
    SUBC4UI32   R2H, R1H, R3H   
    .break  N == 8
    .eval   N + 1, N
    .endloop
    SWAPF        R1, R0
    ZERO         R4
    SWAPF        R4, R2
    NEGI64DIV64  R1H:R0H, R2H:R4H
    MOV32        *+XAR5[0], R0H
    MOV32        *+XAR5[2], R1H  ; Save quotient
    MOV32        *+XAR4[0], R4H
    MOV32        *+XAR4[2], R2H  ; Save remainder
    LRETR
    .unasg  N
    .endasmfunc

;; End of File
