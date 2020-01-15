;;#############################################################################
;;! \file source/fpu64/fid_i16byi16.asm
;;!
;;! \brief  Signed Integer (16-bit) Division
;;! \author Vishal Coelho  
;;! \date   03/30/2016 
;;
;; DESCRIPTION:
;;
;;   This function performs a 16-bit signed division (truncated, modulo or
;;   euclidean)
;;
;; FUNCTIONS:
;;
;; void FID_i16byi16_t(int16_t *p_num_rem, int16_t *p_den_quo)
;; void FID_i16byi16_m(int16_t *p_num_rem, int16_t *p_den_quo)
;; void FID_i16byi16_e(int16_t *p_num_rem, int16_t *p_den_quo)
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
;;    F.TF = sign(num) ^ sign(den)
;;    F.NI = sign(num)
;;    N = |N| , D = |D|
;;    R = 0 -- start with a remainder of 0
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
;; endloop                    -- after 16 such iterations N has the quotient
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
;; cycles = 4(call) + 17(body) + 4(return)
;;        = 25
;;*****************************************************************************
    .page
    .if __TI_EABI__
    .asg    FID_i16byi16_t, _FID_i16byi16_t
    .endif
    .global _FID_i16byi16_t
    .sect   ".text"
_FID_i16byi16_t:
    .asmfunc
    SETC        SXM                    ; turn on sign-extenstion
    MOV         ACC, *+XAR5[0]         ;     ACC = [S:divisor]
    MOV32       R3H, ACC               ; *|  R3H  = divisor
    MOV         ACC, *+XAR4[0] << #16  ; 1|  ACC  = [dividend:0]
    MOV32       R1H, ACC               ; 2|*|R1H  = dividend
    NOP                                ; 3|1|alignment cycles 
    NOP                                ; 4|2|alignment cycles 
    NOP                                ;  |3|alignment cycles 
    NOP                                ;  |4|alignment cycles 
    ABSI32DIV32 R2H, R1H, R3H   
    .asg    1, N
    .loop
    SUBC4UI32   R2H, R1H, R3H   
    .break  N == 4 
    .eval   N + 1, N
    .endloop
    NEGI32DIV32 R1H, R2H
    MOV16       *+XAR5[0], R1H         ; Save quotient
    MOV16       *+XAR4[0], R2H         ; Save remainder
    LRETR
    .unasg  N
    .endasmfunc

;;*****************************************************************************
;; Modulo (Floored) Division
;;
;;    F.TF = sign(num) ^ sign(den)
;;    F.NI = sign(num)
;;    N = |N| , D = |D|
;;    R = 0 -- start with a remainder of 0
;; loop i = 15:-1:0
;;    T = (R << 1) + N(i) - D -- shift up remainder, tack on MSb of numerator
;;                            -- subtract divisor
;;    if(T >= 0)              -- if the difference is positive 
;;      R = T & 0xFFFFFFFF    ---- remainder = T        
;;      N = N << 1 + 1        ---- shift numerator up and add 1 (quotient)
;;    else                    -- else                  
;;      R = (R << 1) + N(i)   ---- shift up remainder, tack on MSb of numerator
;;      N = N << 1            ---- shift up numerator 
;;    end
;; endloop                    -- after 16 such iterations N has the quotient
;;                            -- and R the remainder
;; if(rem != 0)F.ZI = 0
;; if(F.TF == 1 && F.ZI==0), 
;;  Q += 1                    -- The quotient is in the variable that 
;;  R  = D - R                -- previously held the numerator
;; if(F.TF == 1) Q = -Q
;; if(F.NI ^ F.TF) R = -R     -- In module division remainder follows the 
;;                            -- sign of the divisor
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
    .asg    FID_i16byi16_m, _FID_i16byi16_m
    .endif
    .global _FID_i16byi16_m
    .sect   ".text"
_FID_i16byi16_m:
    SETC         SXM                    ; turn on sign-extenstion
    MOV          ACC, *+XAR5[0]         ;     ACC = [S:divisor]
    MOV32        R3H, ACC               ; *|  R3H  = divisor
    MOV          ACC, *+XAR4[0] << #16  ; 1|  ACC  = [dividend:0]
    MOV32        R1H, ACC               ; 2|*|R1H  = dividend
    NOP                                 ; 3|1|alignment cycles 
    NOP                                 ; 4|2|alignment cycles 
    NOP                                 ;  |3|alignment cycles 
    NOP                                 ;  |4|alignment cycles 
    ABSI32DIV32  R2H, R1H, R3H          
    .asg    1, N
    .loop
    SUBC4UI32    R2H, R1H, R3H   
    .break  N == 4 
    .eval   N + 1, N
    .endloop
    MNEGI32DIV32 R1H, R2H, R3H
    MOV16        *+XAR5[0], R1H         ; Save quotient
    MOV16        *+XAR4[0], R2H         ; Save remainder
    LRETR
    .unasg  N
    .endasmfunc
    

;;*****************************************************************************
;; Euclidean Division
;;
;;    F.TF = sign(num) ^ sign(den)
;;    F.NI = sign(num)
;;    N = |N| , D = |D|
;;    R = 0 -- start with a remainder of 0
;; loop i = 15:-1:0
;;    T = (R << 1) + N(i) - D -- shift up remainder, tack on MSb of numerator
;;                            -- subtract divisor
;;    if(T >= 0)              -- if the difference is positive 
;;      R = T & 0xFFFFFFFF    ---- remainder = T        
;;      N = N << 1 + 1        ---- shift numerator up and add 1 (quotient)
;;    else                    -- else                  
;;      R = (R << 1) + N(i)   ---- shift up remainder, tack on MSb of numerator
;;      N = N << 1            ---- shift up numerator 
;;    end
;; endloop                    -- after 16 such iterations N has the quotient
;;                            -- and R the remainder
;; if(rem != 0)F.ZI = 0
;; if(F.NI == 1 && F.ZI==0), 
;;  Q += 1                    -- The quotient is in the variable that 
;;  R  = D - R                -- previously held the numerator
;; if(F.TF == 1) Q = -Q       -- In euclidean division remainder is always 
;;                            -- positive
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
    .asg    FID_i16byi16_e, _FID_i16byi16_e
    .endif
    .global _FID_i16byi16_e
    .sect   ".text"
_FID_i16byi16_e:
    .asmfunc
    SETC         SXM                    ; turn on sign-extenstion
    MOV          ACC, *+XAR5[0]         ;     ACC = [S:divisor]
    MOV32        R3H, ACC               ; *|  R3H  = divisor
    MOV          ACC, *+XAR4[0] << #16  ; 1|  ACC  = [dividend:0]
    MOV32        R1H, ACC               ; 2|*|R1H  = dividend
    NOP                                 ; 3|1|alignment cycles 
    NOP                                 ; 4|2|alignment cycles 
    NOP                                 ;  |3|alignment cycles 
    NOP                                 ;  |4|alignment cycles 
    ABSI32DIV32  R2H, R1H, R3H   
    .asg    1, N
    .loop
    SUBC4UI32    R2H, R1H, R3H   
    .break  N == 4 
    .eval   N + 1, N
    .endloop
    ENEGI32DIV32 R1H, R2H, R3H
    MOV16        *+XAR5[0], R1H         ; Save quotient
    MOV16        *+XAR4[0], R2H         ; Save remainder
    LRETR
    .unasg  N
    .endasmfunc
;; End of File
