;;#############################################################################
;;! \file source/fpu32/sqrt_f32.asm
;;!
;;! \brief  Fast 32-bit floating-point sqrt for the C28x + Floating-Point Unit.
;;! \author N/A
;;! \date   N/A
;;
;; DESCRIPTION:
;;
;;    This function computes a 32-bit floating point sqrt..
;;
;; FUNCTIONS:
;;
;;    float32 sqrtf(float32 X)
;;
;; ASSUMPTIONS:
;; 
;;
;; ALGORITHM:
;;
;;              Ye = Estimate(1/sqrt(X));
;;              Ye = Ye*(1.5 - Ye*Ye*X*0.5)
;;              Ye = Ye*(1.5 - Ye*Ye*X*0.5)
;;              Y  = sqrt(X) = X*Ye
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

       .page
       .if __TI_EABI__
       .asg        sqrtf, _sqrt
       .endif
       .global     _sqrt
       .text
	   .if (__TI_EABI__ = 0)
       ; For TI COFF double and float are the same size, so sqrtf() and sqrt()
       ; should be the same function
       .global _sqrtf
_sqrtf:
	   .endif
_sqrt:
                                        ; R0H = X on entry
        EISQRTF32   R1H, R0H            ; R1H = Ye = Estimate(1/sqrt(X))
        MPYF32      R2H, R0H, #0.5      ; R2H = X*0.5
        MPYF32      R3H, R1H, R1H       ; R3H = Ye*Ye
        NOP
        MPYF32      R3H, R3H, R2H       ; R3H = Ye*Ye*X*0.5
        NOP
        SUBF32      R3H, #1.5, R3H      ; R3H = 1.5 - Ye*Ye*X*0.5
        NOP
        MPYF32      R1H, R1H, R3H       ; R2H = Ye = Ye*(1.5 - Ye*Ye*X*0.5)
        NOP
        MPYF32      R3H, R1H, R2H       ; R3H = Ye*X*0.5
        NOP
        MPYF32      R3H, R1H, R3H       ; R3H = Ye*Ye*X*0.5
        NOP
        SUBF32      R3H, #1.5, R3H      ; R3H = 1.5 - Ye*Ye*X*0.5
        CMPF32      R0H, #0.0           ; Check if X == 0
        MPYF32      R1H, R1H, R3H       ; R2H = Ye = Ye*(1.5 - Ye*Ye*X*0.5)
        NOP
        MOV32       R1H, R0H, EQ        ; If X is zero, change the Ye estimate to 0
        MPYF32      R0H, R0H, R1H       ; R0H = Y = X*Ye = sqrt(X)
        LRETR
        .endasmfunc
    
;; End of File
