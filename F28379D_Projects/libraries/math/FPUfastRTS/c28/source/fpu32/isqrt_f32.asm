;;#############################################################################
;;! \file source/fpu32/isqrt_f32.asm
;;!
;;! \brief  Fast 32-bit floating-point 1.0/sqrt(X) for the C28x + Floating-Point Unit.
;;! \author N/A  
;;! \date   N/A
;;
;;
;;DESCRIPTION:
;;
;;   This function computes a 32-bit floating point (1.0)/sqrt(X)
;;   Note: This function is not part of the normal RTS library.
;;
;;FUNCTIONS:
;;
;;   float32 isqrtf(float32 X)
;;
;;ASSUMPTIONS:
;;
;;
;;ALGORITHM:
;;
;;             Ye = Estimate(1/sqrt(X));
;;             Ye = Ye*(1.5 - Ye*Ye*X*0.5)
;;             Y  = Ye*(1.5 - Ye*Ye*X*0.5)
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
        .asg        isqrtf, _isqrt
        .endif
        .global     _isqrt
        .text
        .if (__TI_EABI__ = 0)
        ; For TI COFF double and float are the same size, so isqrtf() and 
        ; isqrt() should be the same function
        .global _isqrtf
_isqrtf:
        .endif
_isqrt:
        EISQRTF32   R1H,R0H             ; R1H = Ye = Estimate(1/sqrt(X))        
        MPYF32      R2H,R0H,#0.5        ; R2H = X*0.5
        MPYF32      R3H,R1H,R1H         ; R3H = Ye*Ye
        NOP
        MPYF32      R3H,R3H,R2H         ; R3H = Ye*Ye*X*0.5
        NOP
        SUBF32      R3H,#1.5,R3H        ; R3H = 1.5 - Ye*Ye*X*0.5
        NOP
        MPYF32      R1H,R1H,R3H         ; R2H = Ye = Ye*(1.5 - Ye*Ye*X*0.5)
        NOP

        MPYF32      R3H,R1H,R2H         ; R3H = Ye*X*0.5
        NOP
        MPYF32      R3H,R1H,R3H         ; R3H = Ye*Ye*X*0.5
        NOP
        SUBF32      R3H,#1.5,R3H        ; R3H = 1.5 - Ye*Ye*X*0.5
        NOP
        MPYF32      R0H,R1H,R3H         ; R0H = Ye = Ye*(1.5 - Ye*Ye*X*0.5)
        LRETR
        .endasmfunc
    
;; End of File
