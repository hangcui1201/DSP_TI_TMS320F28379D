;;#############################################################################
;;! \file source/fpu64/vector/mpy_DP_CSxCS.asm
;;!
;;! \brief  C-Callable complex multiply of two double precision numbers
;;! \author Vishal Coelho (adapted from SP version by David Alter)
;;! \date   07/13/2016
;;
;; DESCRIPTION: C-Callable complex multiply of two double precision numbers
;;
;; FUNCTIONS:
;;  extern complexf64_t mpy_DP_CSxCS(const complexf64_t *w, 
;;                                   const complexf64_t *x);
;;  
;; PARAMETERS:  complexf64_t *w = pointer to input #1
;;              complexf64_t *x = pointer to input #2
;;
;; RETURNS:    complexf64_t y = complex product
;;
;; BENCHMARK:  28 cycles (including the call and return)
;;             
;; NOTES:
;;   1) The type 'complexf64_t' is defined as
;;
;;      typedef struct {
;;         long double real;
;;         long double imag;
;;      } complexf64_t;
;;   2) Return type is a structure; the compiler allocates space for the 
;;      returned structure and passes its address to the function (implicitly)
;;      in XAR6
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

;; external references

;;*****************************************************************************
;;  complexf64_t mpy_DP_CSxCS(const complexf64_t *w, const complexf64_t *x);
;;
;; C-Callable complex multiply of two double precision numbers
;;
;; Register Usage:
;;   XAR4  : *w, pointer to the first complex input
;;   XAR5  : *x, pointer to the second complex input
;;   
;; Stack Usage:
;;
;;   |_______|<- Stack Pointer                    (SP)
;;   |_______|<- R4H                              (SP-2)
;;   |_______|<- rpc calling function             (SP-4)
;;*****************************************************************************
    .if __TI_EABI__
    .asg mpy_DP_CSxCS, _mpy_DP_CSxCS
    .endif
    
    .page
    .global _mpy_DP_CSxCS
    .sect   ".text"
_mpy_DP_CSxCS:
    .asmfunc
    MOV32   R0L, *+XAR4[0]      ;      R0 = a_re
    MOV32   R0H, *+XAR4[2]      ;      
    MOV32   R2L, *+XAR5[0]      ;      R2 = b_re
    MOV32   R2H, *+XAR5[2]      ;      
    MPYF64  R3, R0, R2          ; *|   R3 = a_re * b_re
 || MOV32   R1L, *+XAR4[4]      ;  |   R1 = a_im
    MOV32   R1H, *+XAR4[6]      ; 1|   
    MOV32   *SP++, R4H          ; 2|   save R4H to the stack
    MPYF64  R2, R1, R2          ; *|   R2 = a_im * b_re
 || MOV32   R4L, *+XAR5[4]      ;  |   R4 = b_im
    MOV32   R4H, *+XAR5[6]      ; 1|   
    NOP                         ; 2|   
    MPYF64  R1, R1, R4          ; *|   R1 = a_im * b_im
    MPYF64  R0, R0, R4          ; 1|*| R0 = a_re * b_im
 || MOV32   R4H, *--SP          ;  | | restore R4H
    NOP                         ; 2|1|
    SUBF64  R3, R3, R1          ; *|2| R3 = (a_re * b_re) - (a_im * b_im)
    ADDF64  R2, R2, R0          ; 1|*| R2 = (a_im * b_re) + (a_re * b_im)
    NOP                         ; 2|1|
    MOV64 R0, R3, UNC               ;  |1| store y[i]
    MOV64 R1, R2, UNC               ;  | | store y[i+1]
    LRETR
    .endasmfunc
  
;; End of File
