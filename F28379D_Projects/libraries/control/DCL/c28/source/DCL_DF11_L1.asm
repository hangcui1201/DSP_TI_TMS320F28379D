; DCL_DF11_L1.asm - Full Direct Form 1 implementation in first order
;
; Copyright (C) 2019 Texas Instruments Incorporated - http://www.ti.com/
; ALL RIGHTS RESERVED 

   	  .if $defined(__TI_EABI__)
		.if __TI_EABI__
		.asg	DCL_runDF11_L1, _DCL_runDF11_L1
		.endif
      .endif

		.global _DCL_runDF11_L1
		.def 	__cla_DCL_DF11_L1_sp

SIZEOF_LFRAME		.set	2
LFRAME_MR3			.set	0

		.align 	2
__cla_DCL_DF11_L1_sp	.usect ".scratchpad:Cla1Prog:_DCL_DF11_L1_LSECT", SIZEOF_LFRAME, 0, 1
		.asg	 __cla_DCL_DF11_L1_sp, LFRAME
		.sect 	"Cla1Prog:_DCL_DF11_L1_LSECT"

; C prototype: float DCL_runDF11_L1(DCL_DF11 *p, float32_t ek);
; argument 1 = *p : 32-bit structure address [MAR0]
; argument 2 = ek : 32-bit floating-point [MR0]
; return = uk : 32-bit floating-point [MR0]

_DCL_runDF11_L1:
		MMOV32		@LFRAME + LFRAME_MR3, MR3 		; save MR3
		MNOP										; MAR0 read stall
		MNOP										; MAR0 read stall
		MMOV32		MR1, *MAR0[2]++					; MR1 = b0
		MMPYF32		MR2, MR0, MR1					; MR2 = v2
||		MMOV32		MR3, *MAR0[4]++					; MR3 = b1
		MMOV32		MR1, *MAR0						; MR1 = d1
		MMPYF32		MR3, MR1, MR3					; MR3 = v3
		MMOV32		*MAR0[-2]++, MR0				; save d1
		MADDF32		MR0, MR2, MR3					; MR0 = v2+v3
||		MMOV32		MR3, *MAR0[4]++					; MR3 = a1
		MMOV32		MR2, *MAR0						; MR2 = d2
		MMPYF32		MR1, MR2, MR3					; MR1 = v6
		MNOP										; delay slot
		MSUBF32		MR0, MR0, MR1					; MR0 = v5
		MRCNDD		UNC								; return call
		MMOV32		*MAR0, MR0						; save d2
		MNOP										; delay slot
		MMOV32		MR3, @LFRAME + LFRAME_MR3		; restore MR3
		.unasg		LFRAME

; end of file
