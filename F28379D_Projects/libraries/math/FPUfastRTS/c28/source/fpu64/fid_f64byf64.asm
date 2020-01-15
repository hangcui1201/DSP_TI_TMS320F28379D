;;#############################################################################
;;! \file source/fpu64/fid_f64byf64.asm
;;!
;;! \brief  Double Precision Division
;;! \author Vishal Coelho  
;;! \date   04/18/2016 
;;
;; DESCRIPTION:
;;
;;   This function performs a 64-bit double precision division ()
;;
;; FUNCTIONS:
;;
;; void FID_f64byf64(long double *p_num, long double *p_den, 
;;                   long double *p_quo)
;;  
;; ASSUMPTIONS:
;;
;; ALGORITHM:
;;
;;  The algorithm used is a slow division method (Restoring division)
;;  see https://en.wikipedia.org/wiki/Division_algorithm#Restoring_division
;;
;;  Let N be the dividend (numerator), D the divisor (denominator), T a 
;;  temporary variable, i the bit index and loop iterator
;;  
;; S = sign(num)^sign(den)    -- extract the sign of the quotient
;; E_q = E_n - E_d - 1023     -- get the unbiased exponent of the quotient
;; D = D << 1                 -- shift divisor up 1
;;    Q = 0                   -- start with a quotient of 0
;; loop i = 56:-1:0
;;    T = (N << 1) - D        -- shift up dividend and subtract divisor
;;    if(T >= 0)              -- if the difference is positive 
;;      N = T & 0x003FF..FFUL ---- numerator = T(53:0)        
;;      Q = Q << 1 + 1        ---- shift quotient up and add 1 
;;    else                    -- else                  
;;      N = (N << 1) + Q(63)  ---- shift up numerator, tack on MSb of quotient
;;      Q = Q << 1            ---- shift up quotient 
;;    end
;; endloop
;; The final operation would be to round and shift down the quotient, insert
;; the sign and exponent to get the final value
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
;;   R0H   : exponent of the quotient
;;   R1    : quotient
;;   R2    : dividend
;;   R3    : divisor 
;;   XAR4  : pointer to dividend (numerator) 
;;   XAR5  : pointer to divisor (denominator)
;;   
;; Stack Usage:
;;
;;   |_______|<- Stack Pointer                    (SP)
;;   |_______|<- rpc calling function             (SP-2)
;;   |_______|<- pointer to quotient              (SP-4)
;;
;; cycles = 4(call) + 28(body) + 4(return)
;;        = 36
;;*****************************************************************************
    .page
    .if __TI_EABI__
    .asg    FID_f64byf64, _FID_f64byf64
    .endif
    .global _FID_f64byf64
    .sect   ".text"
_FID_f64byf64:
    .asmfunc
    .asg    *-SP[4], PTR_QUOTIENT
    
    MOV32       R2L, *+XAR4[0] ; [R2] = dividend
    MOV32       R2H, *+XAR4[2]
    MOV32       R3L, *+XAR5[0] ; [R3] = divisor
    MOV32       R3H, *+XAR5[2] 
    PREDIVF64   R0H, R2, R1, R3
    .asg    1, N
    .loop
    SUBC3F64    R2, R1, R3
    .break  N == 19
    .eval   N + 1, N
    .endloop
    POSTDIVF64  R1, R0H
    MOVL        XAR4, PTR_QUOTIENT
    MOV32       *+XAR4[0], R1L  ; Save quotient
    MOV32       *+XAR4[2], R1H
    LRETR
    
    .unasg  N
    .unasg  PTR_QUOTIENT
    .endasmfunc

;; End of File
