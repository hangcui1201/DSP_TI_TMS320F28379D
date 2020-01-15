;;#############################################################################
;;! \file source/vector/mpy_SP_CSxCS.asm
;;!
;;! \brief C-Callable complex multiply of two floating point numbers
;;! \author David M. Alter
;;! \date   07/20/11
;;
;; HISTORY:
;;   07/20/11 - original (D. Alter)
;;
;; DESCRIPTION: C-Callable complex multiply of two floating point numbers
;;
;; FUNCTION: 
;;   extern complex_float mpy_SP_CSxCS(const complex_float w, 
;;                                     const complex_float x);
;;
;; USAGE:       y = mpy_SP_CSxCS(w,x);
;;
;; PARAMETERS:  complex_float w = input #1
;;              complex_float x = input #2
;;
;; RETURNS:     complex_float y = result
;;
;; BENCHMARK:   19 cycles (including the call and return for COFF)
;;              17 cycles (including the call and return for EABI)
;; NOTES:
;;   1) This is a highly optimized function.  The order of the instructions
;;      is very important.
;;   2) The restore of Save-on-entry register R4H is hidden in a parallel
;;      instruction after its last use.
;;   3) The input and return value is of type 'complex_float':
;;
;;      typedef struct {
;;         float32 dat[2];
;;      } complex_float;
;;
;;      Element dat[0] is the real part, dat[1] is the imag part.
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
        .if __TI_EABI__
        .asg mpy_SP_CSxCS, _mpy_SP_CSxCS
        .endif
    
        .global _mpy_SP_CSxCS
        .text

_mpy_SP_CSxCS:
;Save the utilized save on entry registers
        MOV32       *SP++, R4H      ;save R4H on stack

;Optimally load the input values and do the math
        .if         !__TI_EABI__
        MOV32       R0H, *+XAR4[0]  ;R0H = w_re
        MOV32       R2H, *+XAR5[0]  ;R2H = x_re

        MPYF32      R4H, R0H, R2H   ;R4H = w_re * x_re
        || MOV32    R1H, *+XAR4[2]  ;R1H = w_im

        MPYF32      R2H, R1H, R2H   ;R2H = w_im * x_re
        || MOV32    R3H, *+XAR5[2]  ;R4H = x_im
        .else
        MPYF32      R4H, R0H, R2H   ;R4H = w_re * x_re
        MPYF32      R2H, R1H, R2H   ;R2H = w_im * x_re
        .endif

        MPYF32      R1H, R1H, R3H   ;R1H = w_im * x_im

        MPYF32      R0H, R0H, R3H   ;R0H = w_re * x_im

        SUBF32      R3H, R4H, R1H   ;R3H = (w_re * x_re) - (w_im * x_im)
        || MOV32    R4H, *--SP      ;restore R4H from stack
        ADDF32      R2H, R2H, R0H   ;R2H = (w_im * x_re) + (w_re * x_im)

;Store the return value
        .if         __TI_EABI__
        MOV32       R0H, R3H        ;store real part of return value
        MOV32       R1H, R2H        ;store imag part of return value
        .else
        MOV32       *+XAR6[0], R3H  ;store real part of return value
        MOV32       *+XAR6[2], R2H  ;store imag part of return value
        .endif

;Finish up
        LRETR                       ;return

;end of function mpy_SP_CSxCS()
;*********************************************************************
       .end
;;#############################################################################
;;  End of File
;;#############################################################################
