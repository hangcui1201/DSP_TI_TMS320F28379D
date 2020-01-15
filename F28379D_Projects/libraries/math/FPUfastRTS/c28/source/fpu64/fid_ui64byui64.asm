;;#############################################################################
;;! \file source/fpu64/fid_ui64byui64.asm
;;!
;;! \brief  Unsigned Long (64-bit) / Unsigned Long (64-bit) 
;;! \author Vishal Coelho  
;;! \date   04/1/2016 
;;
;; DESCRIPTION:
;;
;;   This function performs a 64-bit/64-bit unsigned division (truncated)
;;
;; FUNCTIONS:
;;
;; void FID_ui64byui64(uint64_t *p_num_rem, uint64_t *p_den_quo)
;;  
;; ASSUMPTIONS:
;;
;; ALGORITHM:
;;
;;  The algorithm used is a slow division method (Restoring division)
;;  see https://en.wikipedia.org/wiki/Division_algorithm#Restoring_division
;;
;;  Let N be the dividend, D the divisor, T a temporary variable and P 
;;  the partial remainder of each iteration, i the bit index and loop iterator
;;  
;;    R = 0                   -- start with a remainder of 0
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
;; Register Usage:
;;   R1H:R0H  : dividend (quotient)
;;   R2H:R4H  : remainder
;;   R3H:R5H  : divisor 
;;   XAR4     : pointer to dividend (numerator) and subsequently remainders 
;;   XAR5     : pointer to divisor (denominator) and subsequently quotient 
;;
;; cycles = 4(call) + 42(body) + 4(return)
;;        = 50
;;*****************************************************************************
    .page
    .if __TI_EABI__
    .asg    FID_ui64byui64, _FID_ui64byui64
    .endif
    .global _FID_ui64byui64
    .sect   ".text"
_FID_ui64byui64:
    .asmfunc
    ZERO        R2
    ZERO        R4
    MOV32       R0H, *+XAR4[0] ; [R1H:R0H] = dividend
    MOV32       R1H, *+XAR4[2]
    MOV32       R5H, *+XAR5[0] 
    MOV32       R3H, *+XAR5[2] ; [R3H:R5H] = divisor
    
    .asg    1, N
    .loop
    SUBC2UI64   R2H:R4H, R1H:R0H, R3H:R5H   
    .break  N == 32
    .eval   N + 1, N
    .endloop

    MOV32       *+XAR5[0], R0H
    MOV32       *+XAR5[2], R1H  ; Save quotient
    MOV32       *+XAR4[0], R4H  
    MOV32       *+XAR4[2], R2H  ; Save remainder
    LRETR
    .unasg  N
    .endasmfunc

;; End of File
