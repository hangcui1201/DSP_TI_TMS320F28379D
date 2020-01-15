;;#############################################################################
;;! \file source/fpu32/exp_f32.asm
;;!
;;! \brief  Fast single precision exponent for the C28x + FPU32
;;! \author Vishal Coelho   
;;! \date   01/19/2017
;;
;; DESCRIPTION:
;;
;;   This function computes the 32-bit floating point exp(x)
;;
;; FUNCTIONS:
;;
;;   This funciton will be called whenever the standard C library function
;;   exp() is called.
;;   
;;   float32 X,Y;
;;   ...
;;   <X initalized>
;;   ...
;;   Y = expf(X); 
;;  
;; ASSUMPTIONS:
;;
;; ALGORITHM:
;;
;; 1. calculate the absolute of x, |x|
;; 2. Separate the integer and fractional portion of the input
;; 3. Get e^integer(x) from the table
;; 4. Calculate e^(fraction) by using the Taylor series expansion for
;;    exponents
;;      x
;;    e   = 1 + x*(1+x/2*(1+x/3*(1+x/4*(1+x/5*(1+x/6*(1+x/7)+...)))))
;;    
;; 5. The result,  $e^{x} = e^{integer}*e^{fraction}$
;; 6. If x was negative, calculate the inverse of the result
;;
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


;; external references
    .if __TI_EABI__
    .asg    expf, _exp
    .asg    FPU32expTable, _FPU32expTable
    .asg    FPU32expTableCoeff, _FPU32expTableCoeff
    .endif
    
    .ref    _FPU32expTable
    .ref    _FPU32expTableCoeff
    
;;*****************************************************************************
;; Register Usage:
;;   XAR0: pointer to the lookup table        | R0H : x, argument
;;   XAR1: pointer to the exp coeffs          | R1H : x_f
;;   XAR2: storing the lookup tabe index      | R2H :
;;                                            | R3H :
;;                                            | R4H : x_i, index into lookup table
;;
;; Stack Usage:
;;
;;   |_______|<- Stack Pointer                    (SP)
;;   |_______|<- R4H                              (SP-2)
;;   |_______|<- rpc calling function             (SP-4)
;;
;;*****************************************************************************
    .page
    .global _exp
    .sect   ".text"
    .if (__TI_EABI__ = 0)
    ; For TI COFF double and float are the same size, so expf() and 
    ; exp() should be the same function
    .global _expf
_expf:
    .endif
_exp:   .asmfunc
;;-----------------------------------------------------------------------------
;; Context Save
;;-----------------------------------------------------------------------------
    MOV32   	*SP++,R4H
;;-----------------------------------------------------------------------------
;; The algorithm
;;-----------------------------------------------------------------------------
	MOV32		R4H, R0H			;      R4H = x   (may set ZF, NF)
    TESTTF      LT                  ;      (x < 0.0)? TF = 1: TF = 0
    ABSF32      R4H, R0H            ;      R4H = |x|
    FRACF32     R1H, R4H            ; *|   R1H = frac(|x|) or x_f
    MOVL        XAR1, #_FPU32expTableCoeff
                                    ; 1|   XAR1 -> FPU32expTableCoeff[0]
    MOV32       R2H, *XAR1++        ;      R2H = 1/7
    MPYF32      R2H, R2H, R1H       ; *|   R2H = x_f/7
 || MOV32       R3H, *XAR1++        ;  |   R3H = 1/6
    MPYF32      R3H, R1H, R3H       ; 1|*| R3H = x_f/6
 || MOV32       R0H, *XAR1++        ;  | | R0H = 1/5
    ADDF32      R2H, #1.0, R2H      ; *|1| R2H = 1+x_f/7
    MPYF32      R4H, #2.0, R4H      ; 1|*| R4H = 2*x_i
    MPYF32      R2H, R3H, R2H       ; *|1| R2H = x_f/6*(1+x_f/7)
    MPYF32      R0H, R1H, R0H       ; 1|*| R0H = x_f/5
 || MOV32       R3H, *XAR1++        ;  | | R3H = 1/4
    ADDF32      R2H, #1.0, R2H      ; *|1| R2H = 1+x_f/6*(1+x_f/7)  
    F32TOI32    R4H, R4H            ; 1|*| R4H = 2*x_i
    MPYF32      R2H, R0H, R2H       ; *|1| R2H = x_f/5*(1+x_f/6*(1+x_f/7))
    MPYF32      R3H, R1H, R3H       ; 1|*| R3H = x_f/4
 || MOV32       R0H, *XAR1++        ;  | | R0H = 1/3
    ADDF32      R2H, #1.0, R2H      ; *|1| R2H = 1+x_f/5*(1+x_f/6*(1+x_f/7))
    MOV32       XAR2, R4H            ; 1|   XAR2 = sizeof(float)*x_i
    MOVL        XAR0, #_FPU32expTable   ; 1|   XAR0 -> FPU32expTable[0]
    ; R2H = x_f/4*(1+x_f/5*(1+x_f/6*(1+x_f/7)))
    MPYF32      R2H, R3H, R2H       ; *|   
    MPYF32      R0H, R1H, R0H       ; 1|*| R0H = x_f/3
    ; R2H = 1+x_f/4*(1+x_f/5*(1+x_f/6*(1+x_f/7)))
    ADDF32      R2H, #1.0, R2H      ; *|1| 
    MOV32       R3H, *XAR1++        ; 1|   R3H = 1/2
    ;  R2H = x_f/3*(1+x_f/4*(1+x_f/5*(1+x_f/6*(1+x_f/7))))
    MPYF32      R2H, R0H, R2H       ; *|
    MPYF32      R3H, R1H, R3H       ; 1|*| R3H = x_f/2
    ; R2H = 1+x_f/3*(1+x_f/4*(1+x_f/5*(1+x_f/6*(1+x_f/7))))
    MOVL        ACC, XAR0                  ; *|1|
    ADDF32      R2H, #1.0, R2H      ; *|1| 
    ADDL         ACC, @XAR2  ; 1|   ACC->FPU32expTable[x_i]
    ; R2H = x_f/2*(1+x_f/3*(1+x_f/4*(1+x_f/5*(1+x_f/6*(1+x_f/7)))))
    MPYF32      R2H, R3H, R2H       ; *|   
    MOVL        XAR0, ACC           ; 1|   XAR0->FPU32expTable[x_i]
    ; R2H = 1+x_f/2*(1+x_f/3*(1+x_f/4*(1+x_f/5*(1+x_f/6*(1+x_f/7)))))
    ADDF32      R2H, #1.0, R2H      ; *|
    MOV32       R4H, *--SP          ; 1|   restore R4H
    ; R2H = x_f*(1+x_f/2*(1+x_f/3*(1+x_f/4*(1+x_f/5*(1+x_f/6*(1+x_f/7))))))
    MPYF32      R2H, R1H, R2H       ; *|
    MOV32       R1H, *XAR0          ; 1|   R1H = FPU32expTable[x_i]
    ; R2H = 1+x_f*(1+x_f/2*(1+x_f/3*(1+x_f/4*(1+x_f/5*(1+x_f/6*(1+x_f/7))))))
    ADDF32      R2H, #1.0, R2H      ; *|
    NOP                             ; 1|
    MPYF32      R2H, R1H, R2H       ; *|   R2H = e^x =  e^(x_i)*e^(x_f)
    NOP                             ; 1|   
    EINVF32     R1H, R2H            ; *|   R1H = Ye = 1/e^x
    NOP                             ; 1|   
    MPYF32      R3H, R1H, R2H       ; *|   R3H = Ye*e^x
    NOP                             ; 1|   
    SUBF32      R3H, #2.0, R3H      ; *|   R3H = 2.0 - Ye*e^x
    NOP                             ; 1|   
    MPYF32      R1H, R1H, R3H       ; *|   R1H = Yee = Ye*(2.0 - Ye*e^x)
    NOP                             ; 1|   
    MPYF32      R3H, R1H, R2H       ; *|   R3H = Yee*e^x
    NOP                             ; 1|   
    SUBF32      R3H, #2.0, R3H      ; *|   R3H = 2.0 - Yee*e^x
    NOP                             ; 1|   
    MPYF32      R0H, R1H, R3H       ; *|   R0H = Yeee = Yee*(2.0-Yee*e^x)
    NOP                             ; 1|
    MOV32       R0H, R2H, NTF       ;  |   R0H = e^x if TF = 0
    LRETR
    .endasmfunc

    
;; End of File
