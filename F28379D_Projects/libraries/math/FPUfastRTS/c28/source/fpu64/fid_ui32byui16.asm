;;#############################################################################
;;! \file source/fpu64/fid_ui32byui16.asm
;;!
;;! \brief  Unsigned Integer (32-bit) / Unsigned short (16-bit) Division
;;! \author Vishal Coelho  
;;! \date   04/15/2016 
;;
;; DESCRIPTION:
;;
;;   This function performs a 32-bit unsigned division (truncated)
;;
;; FUNCTIONS:
;;
;; void FID_ui32byui16(uint32_t *p_num_rem, uint32_t *p_den_quo)
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
;;    R = 0                   -- start with a remainder of 0
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
;;   R1H : dividend (quotient)
;;   R2H : remainder
;;   R3H : divisor 
;;   XAR4: pointer to dividend (numerator) and subsequently remainders 
;;   XAR5: pointer to divisor (denominator) and subsequently quotient 
;;
;; cycles = 4(call) + 17(body) + 4(return)
;;        = 25
;;*****************************************************************************
    .page
    .if __TI_EABI__
    .asg    FID_ui32byui16, _FID_ui32byui16
    .endif
    .global _FID_ui32byui16
    .sect   ".text"
_FID_ui32byui16:
    .asmfunc
    CLRC        SXM            ; Turn off sign extension
    MOV         ACC, *+XAR5[0] ; ACC = [0:divisor]
    MOV32       R3H, ACC       ; *| R3H = [0:divisor]
    MOV32       R1H, *+XAR4[0] ; 1| R1H = dividend
    ZERO        R2             ; 2| alignment cycle
    MOV16       *+XAR4[2], R2H ; 3| zero out high word of the remainder
    NOP                        ; 4| alignment cycle
    .asg    1, N
    .loop
    SUBC4UI32   R2H, R1H, R3H   
    .break  N == 8
    .eval   N + 1, N
    .endloop
    MOV32       *+XAR5[0], R1H  ; Save quotient
    MOV16       *+XAR4[0], R2H  ; Save remainder
    LRETR
    .unasg  N
    .endasmfunc

;; End of File
