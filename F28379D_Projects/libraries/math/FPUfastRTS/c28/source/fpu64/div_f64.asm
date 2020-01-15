;;#############################################################################
;;! \file source/fpu64/div_f64.asm
;;!
;;! \brief  Fast double precision division for the C28x + FPU64
;;! \author Vishal Coelho   
;;! \date   01/04/2016
;;
;; DESCRIPTION:
;;
;;   This function computes the 64-bit floating point division of A/B
;;
;; FUNCTIONS:
;;
;;   This funciton (FD$$DIV) will be called when 64-bit floating point 
;;   division is performed.  That is:
;;   
;;   float64 A,B,Y;
;;   ...
;;   <A & B initalized>
;;   ...
;;   Y = A/B;  // Call to FD$$DIV
;;  
;; ASSUMPTIONS:
;;
;; ALGORITHM:
;;
;;   Ye     = Estimate(1/B);
;;   Ye'    = Ye*(2.0 - Ye*B)
;;   Ye''   = Ye'*(2.0 - Ye'*B)
;;   Ye'''  = Ye''*(2.0 - Ye''*B)
;;   Ye'''' = Ye'''*(2.0 - Ye'''*B)
;;   Y      = A*Ye''''
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
;;    R0 : A, the dividend
;;    R1 : B, the divisor
;;    R2 : Ye, first estimate of 1/B (all successive estimates Ye', Ye'' ...)
;;    R3 : 2.0 - Ye*B (all successive estimates Ye', Ye'' ...)
;;*****************************************************************************
    .page
    .global FD$$DIV
    .sect   ".text"
    .if __TI_EABI__
    .asg    __c28xabi_div, FD$$DIV
    .endif
FD$$DIV:    .asmfunc
    .if CONVERT_F32_TO_F64 == 1
    F32TOF64    R0, R0H           ; convert A to double precision
    F32TOF64    R1, R1H           ; convert B to double precision
    .endif                        
    EINVF64     R2, R1            ; *| R2 = Ye = Estimate(1/B)
    NOP                           ; 1|
    CMPF64      R0, #0.0          ; if A == 0, set ZF, NF
    RPTB        #FD$$DIV_loop, #2 ; run loop 3 times
    MPYF64      R3, R2, R1        ; *| R3 = Ye*B
    NOP                           ; 1|
    NOP                           ; 2|
    SUBF64      R3, #2.0, R3      ; *| R3 = 2.0 - Ye*B       
    NOP                           ; 1|
    NOP                           ; 2|
    MPYF64      R2, R2, R3        ; *| R2 = Ye = Ye*(2.0 - Ye*B)
    NOP                           ; 1|
    NOP                           ; 2|
FD$$DIV_loop:    
;;-----------------------------------------------------------------------------
;; if ZERO_BY_ZERO_EQ_ZERO == 1, then  0.0/0.0 = 0.0
;; if ZERO_BY_ZERO_EQ_INF  == 1, then  0.0/0.0 = Infinity
;;-----------------------------------------------------------------------------
    .if ZERO_BY_ZERO_EQ_INF == 1
    MOV64       R2, R0, EQ        ; If A == 0.0, Ye''' = 0.0
    .endif 
    MPYF64      R3, R2, R1        ; *| R3 = Ye'''*B
    CMPF64      R1, #0.0          ; 1| if B == 0, set ZF, NF
    NOP                           ; 2|
    SUBF64      R3, #2.0, R3      ; *| R3 = 2.0 - Ye'''*B
    NEGF64      R0, R0, EQ        ; 1| Fixes sign for A/0.0
    NOP                           ; 2|
    MPYF64      R2, R2, R3        ; *| R2 = Ye'''' = Ye'''*(2.0 - Ye'''*B)
    NOP                           ; 1|
    NOP                           ; 2|
    MPYF64      R0, R0, R2        ; *  | R0 = Y = A*Ye'''' = A/B
    LRETR                         ; 1,2|
    .endasmfunc

    
;;*****************************************************************************
;; This function will run the function above taking the address of the input  
;; and output as arguments                                                    
;;                                                                            
;; Register Usage:                                                            
;;   XAR4 : points to the destination argument                                
;;   XAR5 : points to the source argument A
;;   XAR6 : points to the source argument B
;;
;; Stack Usage:
;;
;;   |_______|
;;   |_______|<- Stack Pointer        (SP) 
;;   |_______|<- rpc calling function (SP-2)
;;   |_______|<- Argument pointer B   (SP-4)
;;

;;*****************************************************************************
    .if __TI_EABI__
    .asg run_div, _run_div
    .endif
    .global _run_div
    .sect   ".text"
_run_div:   .asmfunc
    .asg    *-SP[4], PTR_TO_ARG_B
    MOV32   R0L, *+XAR5[0]
    MOV32   R0H, *+XAR5[2]
    MOVL    XAR6, PTR_TO_ARG_B
    MOV32   R1L, *+XAR6[0]
    MOV32   R1H, *+XAR6[2]
    LCR     #FD$$DIV
    MOV32   *+XAR4[0], R0L
    MOV32   *+XAR4[2], R0H
    LRETR
    .unasg  PTR_TO_ARG_B
    .endasmfunc
;; End of File
