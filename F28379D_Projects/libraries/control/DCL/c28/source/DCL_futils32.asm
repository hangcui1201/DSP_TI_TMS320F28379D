; DCL_futils32.asm - fixed point function utilities for C28x
;
; Copyright (C) 2019 Texas Instruments Incorporated - http://www.ti.com/
; ALL RIGHTS RESERVED

   	  .if $defined(__TI_EABI__)
        .if __TI_EABI__
        .asg    DCL_fupdatePID32, _DCL_fupdatePID32
        .asg    DCL_fupdatePI32, _DCL_fupdatePI32
        .endif
      .endif

        .sect   "dcl32funcs"

;--- PID32 ---------------------------------------------------------------------

        .global _DCL_fupdatePID32

        .align  2

; C prototype: void DCL_fupdatePID32(DCL_PID32 *p)
; argument 1 = *p : 32-bit DCL_PID32 structure address [XAR4]
; return = void

_DCL_fupdatePID32:
        .asmfunc
        PUSH        ST0                 ; save flags
        PUSH        XAR0                ; save XAR0
        PUSH        XAR7                ; save XAR7
        PUSH        ST1                 ; preserve INTM
        MOVL        XAR7, @XAR4         ; XAR7 = &p
        ADDB        XAR7, #24           ; XAR7 = &CSS
        MOVL        XAR0, *XAR7         ; XAR0 = &tpt
        MOVL        ACC, *+XAR0[4]      ; ACC = CSS.sts
        AND         ACC, #1             ; mask bit 0
        BF          PID32_EXIT, EQ      ; skip if zero
        TCLR        *+XAR0[4], #0       ; clear STS_UPDATE_PENDING flag
        MOVL        XAR0, XAR7          ; XAR0 = &CSS
        SUBB        XAR0, #2            ; XAR0 = &SPS
        MOVL        XAR7, *XAR0         ; XAR7 = &Kp
        SETC        INTM                ; block interrupts
        RPT         #9                  ; repeat 10 times
||      PREAD       *XAR4++, *XAR7      ; SPS copy
        ADDB        XAR4, #8            ; XAR4 = &Umax
        ADDB        XAR7, #12           ; XAR7 = &SPS.Umax
        MOVL        ACC, *XAR7++        ; SPS.Umax -> ACC
        MOVL        *XAR4++, ACC        ; update Umax
        MOVL        ACC, *XAR7          ; SPS.Umin -> ACC
        MOVL        *XAR4, ACC          ; update Umin
PID32_EXIT:
        POP         ST1                 ; restore INTM
        POP         XAR7                ; restore XAR7
        POP         XAR0                ; restore XAR0
        POP         ST0                 ; restore flags
        LRETR
        .endasmfunc

;--- PI32 ----------------------------------------------------------------------

        .global _DCL_fupdatePI32

        .align  2

; C prototype: void DCL_fupdatePI32(DCL_PI32 *p)
; argument 1 = *p : 32-bit DCL_PI32 structure address [XAR4]
; return = void

_DCL_fupdatePI32:
        .asmfunc
        PUSH        ST0                 ; save flags
        PUSH        XAR0                ; save XAR0
        PUSH        XAR7                ; save XAR7
        PUSH        ST1                 ; preserve INTM
        MOVL        XAR7, @XAR4         ; XAR7 = &p
        ADDB        XAR7, #14           ; XAR7 = &CSS
        MOVL        XAR0, *XAR7         ; XAR0 = &tpt
        MOVL        ACC, *+XAR0[4]      ; ACC = CSS.sts
        AND         ACC, #1             ; mask bit 0
        BF          PI32_EXIT, EQ         ; skip if zero
        TCLR        *+XAR0[4], #0       ; clear STS_UPDATE_PENDING flag
        MOVL        XAR0, XAR7          ; XAR0 = &CSS
        SUBB        XAR0, #2            ; XAR0 = &SPS
        MOVL        XAR7, *XAR0         ; XAR7 = &Kp
        SETC        INTM                ; block interrupts
        MOVL        ACC, *XAR7++        ; SPS.Kp -> ACC
        MOVL        *XAR4++, ACC        ; update KpUmax
        MOVL        ACC, *XAR7++        ; SPS.Ki -> ACC
        MOVL        *XAR4++, ACC        ; update Ki
        ADDB        XAR4, #4            ; XAR4 = &Umax
        MOVL        ACC, *XAR7++        ; SPS.Umax -> ACC
        MOVL        *XAR4++, ACC        ; update Umax
        MOVL        ACC, *XAR7          ; SPS.Umin -> ACC
        MOVL        *XAR4, ACC          ; update Umin
PI32_EXIT:
        POP         ST1                 ; restore INTM
        POP         XAR7                ; restore XAR7
        POP         XAR0                ; restore XAR0
        POP         ST0                 ; restore flags
        LRETR
        .endasmfunc

;-----------------------------------------------------------------------------

        .end

; end of file
