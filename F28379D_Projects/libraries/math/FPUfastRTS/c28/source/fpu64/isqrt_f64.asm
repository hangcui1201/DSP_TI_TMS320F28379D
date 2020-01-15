;;#############################################################################
;;! \file source/fpu64/isqrt_f64.asm
;;!
;;! \brief  Inverse Square Root function for the C28x + FPU64
;;! \author Vishal Coelho   
;;! \date   12/24/2015
;;
;; DESCRIPTION:
;;
;;   This function computes a 64-bit floating point (1.0)/sqrt(X). This
;;   function is not part of the normal RTS library.
;;
;; FUNCTIONS:
;;
;;  float64 isqrt (float64 X) 
;;  
;; ASSUMPTIONS:
;;
;; ALGORITHM:
;;
;;    Ye    = Estimate(1/sqrt(X));
;;    Ye'   = Ye*(1.5 - Ye*Ye*X*0.5)
;;    Ye''  = Ye'*(1.5 - Ye'*Ye'*X*0.5)
;;    Ye''' = Ye''*(1.5 - Ye''*Ye''*X*0.5)
;;    Y     = Ye'''*(1.5 - Ye'''*Ye'''*X*0.5)
;;
;;  Group:            C2000
;;  Target Family:    C28x+FPU64
;;
;;#############################################################################
;; $TI Release: C28x Floating Point Unit Library V2.01.00.00 $
;; $Release Date: May 27, 2019 $
;; $Copyright: Copyright (C) 2019 Texas Instruments Incorporated -
;;             http://www.ti.com/ ALL RIGHTS RESERVED $
;;#############################################################################


;; the includes
    .cdecls C, LIST, "fastrts.h"

;;*****************************************************************************
;; Register Usage:
;;   R0 : X,Y, the argument and the result
;;   R1 :  Ye, first estimate of 1/sqrt(X)(all successive estimates Ye',...)
;;   R2 : X*0.5
;;   R3 : 1.5 - Ye*Ye*X*0.5 (all successive estimates Ye', Ye'' ..)
;;*****************************************************************************
    .page
    .if __TI_EABI__
    .asg        isqrt, _isqrtl
    .endif
    .global     _isqrtl
    .sect       ".text"
_isqrtl:        .asmfunc
    .if CONVERT_F32_TO_F64 == 1
    F32TOF64    R0, R0H          ; convert argument to double precision
    .endif
    EISQRTF64   R1, R0           ; *|R1 = Ye = Estimate(1/sqrt(X))
    NOP                          ; 1|
    MPYF64      R2, R0, #0.5     ; *| R2 = X*0.5
    RPTB        #_isqrtl_loop, #2 ; run loop 3 times
    MPYF64      R3, R1, R1       ; 1|*| R3 = Ye*Ye
    NOP                          ; 2|1|
    NOP                          ;   2|
    MPYF64      R3, R3, R2       ; *| R3 = Ye*Ye*X*0.5
    NOP                          ; 1|
    NOP                          ; 2|
    SUBF64      R3, #1.5, R3     ; *| R3 = 1.5 - Ye*Ye*X*0.5
    NOP                          ; 1|
    NOP                          ; 2|
    MPYF64      R1, R1, R3       ; *| R1 = Ye = Ye*(1.5 - Ye*Ye*X*0.5)
    NOP                          ; 1|
    NOP                          ; 2|
_isqrtl_loop:
    MPYF64      R3, R1, R2       ; *| R3 = Ye'''*X*0.5
    NOP                          ; 1|
    NOP                          ; 2|
    MPYF64      R3, R1, R3       ; *| R3 = Ye'''*Ye'''*X*0.5
    NOP                          ; 1|
    NOP                          ; 2|
    SUBF64      R3, #1.5, R3     ; *| R3 = 1.5 - Ye'''*Ye'''*X*0.5
    NOP                          ; 1|
    NOP                          ; 2|
    MPYF64      R0, R1, R3       ; *  | R0 = Ye'''*(1.5 - Ye'''*Ye'''*X*0.5)
    LRETR                        ; 1,2|
    .endasmfunc

;;*****************************************************************************
;; This function will run the function above taking the address of the input  
;; and output as arguments                                                    
;;                                                                            
;; Register Usage:                                                            
;;   XAR4 : points to the destination argument                                
;;   XAR5 : points to the source argument                                     
;;*****************************************************************************
    .if __TI_EABI__
    .asg    run_isqrt, _run_isqrt
    .endif
    .global _run_isqrt
    .sect   ".text"
_run_isqrt: .asmfunc
    MOV32   R0L, *+XAR5[0]
    MOV32   R0H, *+XAR5[2]
    LCR     #_isqrtl
    MOV32   *+XAR4[0], R0L
    MOV32   *+XAR4[2], R0H
    LRETR
    .endasmfunc
;; End of File
