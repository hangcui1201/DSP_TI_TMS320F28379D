;;#############################################################################
;;! \file source/fpu64/fid_ui16byui16.asm
;;!
;;! \brief  Unsigned Integer (16-bit) Division
;;! \author Vishal Coelho  
;;! \date   04/14/2016 
;;
;; DESCRIPTION:
;;
;;   This function performs a 16-bit unsigned division (truncated)
;;
;; FUNCTIONS:
;;
;; void FID_ui16byui16(uint16_t *p_num_rem, uint16_t *p_den_quo)
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
;; loop i = 15:-1:0
;;    T = (R << 1) + N(i) - D -- shift up remainder, tack on MSb of numerator
;;                            -- subtract divisor
;;    if(T >= 0)              -- if the difference is positive 
;;      R = T & 0xFFFFFFFF    ---- remainder = T        
;;      N = N << 1 + 1        ---- shift numerator up and add 1 (quotient)
;;    else                    -- else                  
;;      R = (R << 1) + N(15)  ---- shift up remainder, tack on MSb of numerator
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
;;  XAR0 : initial load of the divisor
;;   R1H : dividend (quotient)
;;   R2H : remainder
;;   R3H : divisor 
;;   XAR4: pointer to dividend (numerator) and subsequently remainders 
;;   XAR5: pointer to divisor (denominator) and subsequently quotient 
;;
;; cycles = 4(call) + 15(body) + 4(return)
;;        = 23
;;*****************************************************************************
    .page
    .if __TI_EABI__
    .asg    FID_ui16byui16, _FID_ui16byui16
    .endif
    .global _FID_ui16byui16
    .sect   ".text"
_FID_ui16byui16:
    .asmfunc
    CLRC        SXM                    ; turn off sign-extenstion
    MOV         ACC, *+XAR5[0]         ;     ACC = [0:divisor]
    MOV32       R3H, ACC               ; *|  R3H  = divisor
    MOV         ACC, *+XAR4[0] << #16  ; 1|  ACC  = [dividend:0]
    MOV32       R1H, ACC               ; 2|*|R1H  = dividend
    ZERO        R2                     ; 3|1|alignment cycles 
    NOP                                ; 4|2|alignment cycles 
    NOP                                ;  |3|alignment cycles 
    NOP                                ;  |4|alignment cycles 
    .asg        1, N
    .loop
    SUBC4UI32   R2H, R1H, R3H   
    .break  N == 4
    .eval   N + 1, N
    .endloop
    MOV16       *+XAR5[0], R1H  ; Save quotient
    MOV16       *+XAR4[0], R2H  ; Save remainder
    LRETR
    .unasg  N
    .endasmfunc

;; End of File
