; DCL_PID_C4.asm - Parallel PID controller
;
; Copyright (C) 2019 Texas Instruments Incorporated - http://www.ti.com/
; ALL RIGHTS RESERVED 

   	  .if $defined(__TI_EABI__)
		.if __TI_EABI__
		.asg	DCL_runPID_C4, _DCL_runPID_C4
		.endif
      .endif

FASTCR_PID_C4	.set	0		; set to 1 to enable shadowed context save/restore

   		.global	_DCL_runPID_C4

		.sect	"dclfuncs"

; 11/14/2017: [RP] added XAR1 to context save

; C prototype: float DCL_runPID_C4(DCL_PID *p, float32_t rk, float32_t yk, float32_t lk)
; argument 1 = *p : 32-bit PID structure address [XAR4]
; argument 2 = rk : 32-bit floating-point reference [R0H]
; argument 3 = yk : 32-bit floating-point feedback [R1H]
; argument 4 = lk : 32-bit floating-point saturation input [R2H]
; return = uk : 32-bit floating-point [R0H]

		.align	2

_DCL_runPID_C4:
		.asmfunc
; context save
		MOVL		*SP++, XAR1
	.if FASTCR_PID_C4 = 0
		MOV32   	*SP++, R4H
		MOV32   	*SP++, R5H
		MOV32   	*SP++, R6H
	.else
		SAVE
	.endif

; servo error
		SUBF32		R1H, R0H, R1H				; R1H = ek = rk - yk

; derivative path
		MOV32		R3H, *+XAR4[4]				; R3H = Kda
		MOV			AR0, #8						; AR0 = 8
		MPYF32		R5H, R1H, R3H				; R5H = Kda * ek
||		MOV32		R4H, *+XAR4[AR0]			; R4H = c1a
		MOV			AR0, #0xC					; AR0 = 12
		MPYF32		R3H, R4H, R5H				; R3H = v1 = Kda * ek * c1a
||		MOV32		R6H, *+XAR4[AR0]			; R6H = d2
		MOV			AR1, #0xE					; AR1 = 14
		SUBF32		R4H, R3H, R6H				; R4H = v1 - d2
		MOV32		R5H, *+XAR4[AR1]			; R5H = d3
		SUBF32		R4H, R4H, R5H				; R4H = v4 = v1 - d2 - d3
||		MOV32		*+XAR4[AR0], R3H			; save d2
		MOV			AR0, #0xA					; AR0 = 10
		MOV32		R6H, *+XAR4[AR0]			; R6H = c2a
		MPYF32		R5H, R6H, R4H				; R5H = d3 = c2a * v4
		MOV			AR0, #0x12					; AR0 = 18
		MOV32		*+XAR4[AR1], R5H			; save d3

; integral path
		MOV32		R3H, *+XAR4[2]				; R3H = Kia
		MPYF32		R5H, R1H, R3H				; R5H = v7
		MOV32		R6H, *+XAR4[AR0] 			; R6H = i14
		MPYF32		R5H, R6H, R5H				; R5H = v7 * i14
		MOV			AR0, #0x10					; AR0 = 16
		MOV32		R0H, *+XAR4[AR0] 			; R0H = i10
		ADDF32		R5H, R0H, R5H				; R5H = v8

; proportional path
		MOV32		R3H, *+XAR4[0]				; R3H = Kpa
		MPYF32		R6H, R1H, R3H				; R6H = v6

; PID sum
		ADDF32		R4H, R5H, R4H				; R4H = v4 + v8
		MOV32		*+XAR4[AR0], R5H			; save i10
		ADDF32		R1H, R4H, R6H				; R1H = v9

; output saturation
		ZERO		R0H							; R0H = 0.0f
		ADDF32		R6H, R0H, #1.0				; R6H = 1.0f
		MOV			AR1, #0x14					; AR1 = 20
		MOV32		R3H, *+XAR4[AR1]			; R3H = Umaxa
		MINF32		R1H, R3H					; sat v9
||		MOV32		R6H, R0H					; R6H = 0.0f if sat
		MOV			AR1, #0x16					; AR1 = 22
		MOV32		R3H, *+XAR4[AR1]			; R3H = Umina
		MAXF32		R1H, R3H					; sat v9
||		MOV32		R6H, R0H					; R6H = 0.0f if sat = v12
		MPYF32		R3H, R2H, R6H				; R3H = i14
		MOV32		R0H, R1H					; R0H = uk
		MOV			AR0, #0x12					; AR0 = 18
		MOV32		*+XAR4[AR0], R3H			; save i14

; context restore
	.if FASTCR_PID_C4 = 0
		MOV32   	R6H, *--SP, UNC
	    MOV32   	R5H, *--SP, UNC
	    MOV32   	R4H, *--SP, UNC
	.else
		RESTORE
	.endif
	    MOVL		XAR1, *--SP
		LRETR
		.endasmfunc

		.end

; end of file
