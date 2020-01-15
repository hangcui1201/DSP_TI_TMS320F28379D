;;###########################################################################
;;
;; FILE:    cpu1brom_utility_funcs.asm
;;
;; TITLE:   Boot Rom C callable assembly utility functions.
;;
;; Utility functions written in assembly used as part of boot.
;;
;;###########################################################################
;; $TI Release: $
;; $Release Date:  $
;;###########################################################################
    .global load_itrap_address

;
; Function: _load_itrap_address
; C-calling convention: load_itrap_address (unsigned long *itrapaddress)
; Parameter is stored in XAR4
;
; Function loads the address where the ITRAP occurred stored from the stack and
; into the address pointed to by the itrapaddress pointer.
; The stack location where the ITRAP return address is stored on the stack will
; change according to compiler optimizations, The below value is without any
; optimizations - if the code uses optimizations please re-check the below value
;
load_itrap_address:
    MOVL ACC, *-SP[30];   ; load ITRAP address location on stack into ACC
    MOVL *XAR4, ACC       ; return ITRAP address back to calling function
    LRETR

;//
;// End of file.
;//
