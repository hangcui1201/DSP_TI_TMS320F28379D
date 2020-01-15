;;#############################################################################
;;! \file source/fpu64/fid_i32byui32.asm
;;!
;;! \brief  Signed Integer (32-bit) Division
;;! \author Vishal Coelho  
;;! \date   03/30/2016 
;;
;; DESCRIPTION:
;;
;;   This function performs a 32-bit signed division (truncated)
;;
;; FUNCTIONS:
;;
;; void FID_i32byui32(int32_t *p_num_rem, int32_t *p_den_quo)
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
;; loop i = 31:-1:0
;;    T = (R << 1) + N(i) - D -- shift up remainder, tack on MSb of numerator
;;                            -- subtract divisor
;;    if(T >= 0)              -- if the difference is positive 
;;      R = T & 0xFFFFFFFF    ---- remainder = T        
;;      N = N << 1 + 1        ---- shift numerator up and add 1 (quotient)
;;    else                    -- else                  
;;      R = (R << 1) + N(31)  ---- shift up remainder, tack on MSb of numerator
;;      N = N << 1            ---- shift up numerator 
;;    end
;; endloop                    -- after 32 such iterations N has the quotient
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
;; cycles = 4(call) + 14(body) + 4(return)
;;        = 22
;;*****************************************************************************
    .page
    .if __TI_EABI__
    .asg    FID_i32byui32, _FID_i32byui32
    .endif
    .global _FID_i32byui32
    .sect   ".text"
_FID_i32byui32:
    .asmfunc
    MOV32        R1H, *+XAR4[0] ; R1H = dividend
    MOV32        R3H, *+XAR5[0] ; R3H = divisor
    ABSI32DIV32U R2H, R1H
    .asg        1, N
    .loop
    SUBC4UI32    R2H, R1H, R3H   
    .break  N == 8 
    .eval   N + 1, N
    .endloop
    NEGI32DIV32  R1H, R2H
    MOV32        *+XAR5[0], R1H  ; Save quotient
    MOV32        *+XAR4[0], R2H  ; Save remainder
    LRETR
    .unasg  N
    .endasmfunc

;; End of File
