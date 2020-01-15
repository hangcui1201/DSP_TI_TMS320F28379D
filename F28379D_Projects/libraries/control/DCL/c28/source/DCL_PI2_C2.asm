; DCL_PI2_C2.asm - Series PI controller with double integrator
;
; Copyright (C) 2019 Texas Instruments Incorporated - http://www.ti.com/
; ALL RIGHTS RESERVED 

   	  .if $defined(__TI_EABI__)
		.if __TI_EABI__
		.asg	DCL_runPI2_C2, _DCL_runPI2_C2
		.endif
      .endif

   		.global	_DCL_runPI2_C2

		.sect	"dclfuncs"

; C prototype: float DCL_runPI2_C2(PI2 *p, float rk, float yk)
; argument 1 = *p : 32-bit PI2 structure address [XAR4]
; argument 2 = rk : 32-bit floating-point reference [R0H]
; argument 3 = yk : 32-bit floating-point feedback [R1H]
; return = uk : 32-bit floating-point [R0H]

		.align	2

_DCL_runPI2_C2:
		.asmfunc
		SUBF32		R2H, R0H, R1H				; R2H = v1
		MOV32   	R1H, *XAR4++				; R1H = Kpa
		MPYF32		R0H, R1H, R2H				; R0H = v2
||		MOV32   	R1H, *XAR4++				; R1H = KiT
		MPYF32		R2H, R1H, R2H				; R2H = v3
		MOV32   	R1H, *+XAR4[6]				; R1H = i12
		MPYF32		R2H, R1H, R2H				; R2H = v4
		MOV32   	R3H, *XAR4					; R3H = i6
		ADDF32		R2H, R2H, R3H				; R2H = v5
		MOV32   	R3H, *+XAR4[2]				; R3H = i9
		MPYF32		R1H, R1H, R2H				; R1H = v7
		MOV32   	*XAR4++, R2H				; save i6
		ADDF32		R2H, R1H, R3H				; R2H = v8
		NOP
		MOV32   	*XAR4++, R2H				; save i9
		ADDF32		R0H, R0H, R2H				; R0H = v10
		ZERO		R1H							; R1H = 0.0f
		ADDF32		R2H, R1H, #1.0				; R2H = 1.0f
		MOV32		R3H, *+XAR4[2]				; R3H = Umaxa
		MINF32		R0H, R3H					; R0H = sat+
||		MOV32		R2H, R1H					; R2H = v11
		MOV32		R3H, *+XAR4[4]				; R3H = Umina
		MAXF32		R0H, R3H					; R0H = uk
||		MOV32		R2H, R1H					; R2H = v11
		MOV32		*XAR4, R2H					; save i12
		LRETR									; return call
		.endasmfunc

		.end

; end of file
