; DCL_DF11_C1.asm - Direct Form 1 implementation in first order
;
; Copyright (C) 2019 Texas Instruments Incorporated - http://www.ti.com/
; ALL RIGHTS RESERVED 

   	  .if $defined(__TI_EABI__)
		.if __TI_EABI__
		.asg	DCL_runDF11_C1, _DCL_runDF11_C1
		.endif
      .endif

		.global _DCL_runDF11_C1

		.sect	"dclfuncs"

; C prototype: float DCL_runDF11_C1(DCL_DF11 *p, float32_t ek)
; argument 1 = *p : 32-bit structure address [XAR4]
; argument 2 = ek : 32-bit floating-point input [R0H]
; return = uk : 32-bit floating-point [R0H]

		.align	2

_DCL_runDF11_C1:
		.asmfunc
		MOV32		R1H, *XAR4++			; R1H = b0
		MPYF32		R2H, R0H, R1H			; R2H = v2
||		MOV32		R3H, *XAR4++			; R3H = b1
		MOV32		R1H, *+XAR4[2]			; R1H = d1
		MPYF32		R3H, R1H, R3H			; R3H = v3
		MOV32		*+XAR4[2], R0H			; save e(k)
		ADDF32		R0H, R2H, R3H			; R0H = v2 + v3
||		MOV32		R2H, *+XAR4[4]			; R2H = d2
		MOV32		R3H, *+XAR4[0]			; R3H = a1
		MPYF32		R1H, R2H, R3H			; R1H = v6
		NOP									; delay slot
		SUBF32		R0H, R0H, R1H			; R0H = v5
		NOP									; delay slot
		MOV32		*+XAR4[4], R0H			; save u(k)
		LRETR
		.endasmfunc

		.end

; end of file
