;;#############################################################################
;;! \file source/fpu32/div_f32.asm
;;!
;;! \brief  Fast 32-bit floating-point division for the C28x + Floating-Point 
;;!         Unit.
;;! \author N/A
;;! \date   N/A
;;
;; DESCRIPTION:
;;
;;    This function computes a 32-bit floating point division A/B.
;;
;; FUNCTIONS:
;;
;;    This funciton (FS$$DIV) will be called when 32-bit floating point 
;;    division is performed.  That is:
;;    
;;    float32 A,B,Y;
;;    ...
;;    <A & B initalized>
;;    ...
;;    Y = A/B;  // Call to FS$$DIV
;;
;; ASSUMPTIONS:
;; 
;;
;; ALGORITHM:
;;
;;              Ye = Estimate(1/B);
;;              Ye = Ye*(2.0 - Ye*B)
;;              Ye = Ye*(2.0 - Ye*B)
;;              Y  = A*Ye
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
        .global     FS$$DIV
        .text
        .if __TI_EABI__
        .asg    __c28xabi_divf, FS$$DIV
        .endif

FS$$DIV:

        EINVF32     R2H, R1H            ; R2H = Ye = Estimate(1/B)
        CMPF32      R0H, #0.0           ; Check if A == 0
        MPYF32      R3H, R2H, R1H       ; R3H = Ye*B
        NOP
        SUBF32      R3H, #2.0, R3H      ; R3H = 2.0 - Ye*B       
        NOP        
        MPYF32      R2H, R2H, R3H       ; R2H = Ye = Ye*(2.0 - Ye*B)
        NOP
; Next line: if commented out: 0.0/0.0 = 0.0
;            if not commented: 0.0/0.0 = infinity
;       MOV32       R2H, R0H, EQ        ; If A == 0.0, Ye = 0.0
        MPYF32      R3H, R2H, R1H       ; R3H = Ye*B
        CMPF32      R1H, #0.0           ; Check if B == 0.0
        SUBF32      R3H, #2.0, R3H      ; R3H = 2.0 - Ye*B
        NEGF32      R0H, R0H, EQ        ; Fixes sign for A/0.0
        MPYF32      R2H, R2H, R3H       ; R2H = Ye = Ye*(2.0 - Ye*B)
        NOP
        MPYF32      R0H, R0H, R2H       ; R0H = Y = A*Ye = A/B
        LRETR
       	.endasmfunc
    
;; End of File
