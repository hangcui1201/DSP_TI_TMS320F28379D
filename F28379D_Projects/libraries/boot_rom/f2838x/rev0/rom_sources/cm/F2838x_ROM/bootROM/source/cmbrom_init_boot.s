;;###########################################################################
;;
;; FILE:    cmbrom_init_boot.s
;;
;; TITLE:   Boot loader startup code for CM
;;
;;###########################################################################
;; $TI Release:  $
;; $Release Date:  $
;;###########################################################################

;
; Included Files
;
   .cdecls C, NOLIST, WARN 
   %{
        #include "cmbootrom.h"
   %}

;
; Globals
;
    .global CM_resetISR, CM_performDelay
    .ref CMBROM_startSystemBoot     ; Declared in cmbrom_system_boot
    .ref CMBROM_verifyBootCommand   ; Declared in cmbrom_system_boot
    .ref CMBROM_setupDeviceSystems  ; Declared in cmbrom_system_boot
    
;
; Put the assembler into the correct configuration.
;
    .thumb

;
; Test Signature
;
    .sect    ".test_signature1"      ; The 1's complement of the value at the first address of ROM
    .word    0xDFFFF7FF              ;~(*(0x00000000)) - used for production testing           

;
; CM Boot Revision and Release date
;    
    .sect ".CMVersion"
    .global    cmbrom_version 
cmbrom_version:        
    .short     0x0100                ; CM Boot ROM Version v1.0
    .short     0x0418                ; Month/Year: (ex: 0x0418 = 4/18 = April 2018)    

;
; This portion of the file goes into the text section.
;
    .text

;
; Function: CM_resetISR 
;
; The reset handler, which gets called when the processor starts.
;
    .thumbfunc CM_resetISR
    .def    CM_resetISR
CM_resetISR: .asmfunc

;
; Disable Watchdog (On reset, WDOVERRIDE is 1 allowing setting of WDDIS)
; 0x4008000CU = WDCR register
;
    movw    r0, #0x000C
    movt    r0, #0x4008
    movw    r1, #0x0068
    str     r1, [r0], #0

;
; Check IPCBOOTMODE for valid values
; Note: Make sure RAM isn't accessed in this function since RAM isn't 
;       initialized and available yet
;
    bl CMBROM_verifyBootCommand
    
;
; Read SysCtl.CMRESC and check if VECTRESET
;
    movw    r0, #(CM_SYSCTL_RESC_REG & 0xffff)
    movt    r0, #(CM_SYSCTL_RESC_REG >> 16)
    ldr     r1, [r0], #0   
    LSR     r1, r1, #16       ; Move upper word to lower word
    TST     r1, #0x0001       ; Test if VECTRESET is set
    bne     skip_device_setup ; Skip device setup (flash power up, RAM init) on VECTRESET  
  
;
; Zero fill the first 64 bytes of S0RAM stack (0x200007C0 - 0x20000800) to use before RAM init or stack init.
; (Doesn't clear 0x20000800)
;
    movw    r0, #0x07c0
    movt    r0, #0x2000 
    movw    r1, #0x0040
    movt    r1, #0x0000
    movs    r2, #0x00000000
small_stack_zero_loop:
    str     r2, [r0], #4
    subs    r1, r1, #4
    bne     small_stack_zero_loop
    
;
; Set SP to the top of the allocated stack
;
    mov     sp, r0    
    
;
; Setup Device Systems - Power up flash
;
    bl CMBROM_setupDeviceSystems

;
; Read SysCtl.CMRESC and check if POR
;
    movw    r0, #(CM_SYSCTL_RESC_REG & 0xffff)
    movt    r0, #(CM_SYSCTL_RESC_REG >> 16)
    ldr     r1, [r0], #0
    TST     r1, #SYSCTL_CMRESC_POR     ; Test if bit 1 (POR) is set
    beq     skip_ram_init              ; Branch if POR not set

;
; POR Only - Peform RAM init (Split into two groups)
;
; Group 1 - S0-S3
; Group 2 - C0-C1, MSG RAMs, E0
;    

;
; Group 1 - S0-S3
;
; SxInit address = 0x400FE048
;    
    movw    r0, #0xE048
    movt    r0, #0x400F
    movw    r1, #0x000F        ; S0,S1,S2,S3
    str     r1, [r0], #0

;
; Delay 4128 cycles (4096 cycles + 32 buffer) for Sx RAMS (16KB each) to complete
;
    movw    r0, #0x0560
    bl      CM_performDelay
    
;
; Group 2 - C0-C1, E0, MSG RAMs
;
; CxInit address = 0x400FE008
; ExInit address = 0x400FE048
; CMMSGxInit address = 0x400FE028
;   
    movw    r0, #0xE008
    movt    r0, #0x400F
    movw    r1, #0x0003        ; C0, C1
    str     r1, [r0], #0

    movw    r0, #0xE048
    movt    r0, #0x400F
    movw    r1, #0x0010        ; E0
    str     r1, [r0], #0    

    movw    r0, #0xE028
    movt    r0, #0x400F
    movw    r1, #0x000F        ; CMTOCPU1MSGRAM0/1, CMTOCPU2MSGRAM0/1
    str     r1, [r0], #0

;
; Delay 4128 cycles (4096 cycles + 32 buffer) for Ex RAM (16KB) to complete
;
    movw    r0, #0x0560
    bl      CM_performDelay
  
;
; CM Patch/Escape Point 2
; 
    movw    r0, #0x07D4
    movt    r0, #0x0038 
    ldr     r1, [r0], #0    ; r1 contains address specified at OTP escape point
    
    movw    r0, #0xFFFF
    movt    r0, #0xFFFF
    
    cmp     r0, r1
    beq     continue_booting 
    
    movw    r0, #0x0
    movt    r0, #0x0  
    
    cmp     r0, r1
    beq     continue_booting
    
    ORR     r1, #0x1         ; Make sure thumb mode bit is set
    blx     r1              ; ((void (*)(void))EntryAddr)();


continue_booting:    
    b       skip_stack_init
    
skip_device_setup:
skip_ram_init:

;
; Non-POR Reset: Zero fill ~2 KB of S0RAM for stack (0x2000000C-0x20000800)
; (Doesn't clear 0x20000800)
;
    movw    r0, #0x000C
    movt    r0, #0x2000 
    movw    r1, #0x07F4
    movt    r1, #0x0000
    movs    r2, #0x00000000
stack_zero_loop:
    str     r2, [r0], #4
    subs    r1, r1, #4
    bne     stack_zero_loop

skip_stack_init:

;
; Set SP to top of the allocated stack
;
    movw    r0, #0x0800
    movt    r0, #0x2000 
    mov     sp, r0
    
;
; Branch to system initialization to run final initializations and execute boot mode
;    
    b       CMBROM_startSystemBoot

error_loop:
    b    error_loop    
    .endasmfunc
    
   
;
; Function: CM_performDelay
;
; Provides a small delay.  The loop below takes 3 cycles/loop.
;
    .thumbfunc CM_performDelay
    .def CM_performDelay
CM_performDelay: .asmfunc
    subs    r0, #1
    bne     CM_performDelay
    bx      lr
    .endasmfunc

;
; End of file
;
    .end
