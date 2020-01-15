;;###########################################################################
;;
;; FILE:    cpu2brom_init_boot.asm
;;
;; TITLE:   CPU2 Boot Initialization and Exit routines.
;;
;; Functions:
;;
;;     InitBoot
;;     ExitBoot
;;
;;###########################################################################
;; $TI Release: $
;; $Release Date: $
;;###########################################################################

;
; Globals
;
    .global InitBoot
    .global ExitBoot
    .def    ExitBoot
    .ref    CPU2BROM_startSystemBoot    ; Declared in cpu2brom_system_boot
    .ref    CPU2BROM_setupDeviceSystems ; Declared in cpu2brom_system_boot
    .ref    CPU2BROM_verifyBootCommand  ; Declared in cpu2brom_system_boot
    .ref    CPU2BROM_bootStatus         ; Declared in cpu2brom_system_boot
    
;
; Test Signature
;
     .sect ".test_signature1"
     .long   0xFFFFFF81                          ;~(*(0x3FFFFE)) - used for production testing

;
; CPU2 Boot Revision and release date
;
    .sect ".CPU2Version"
    .global cpu2brom_version
cpu2brom_version:
    .word 0x0100                                 ; CPU2 Boot ROM Version v1.0
    .word 0x0418                                 ; Month/Year: (ex: 0x0418 = 4/18 = April 2018)
    
;
; Function: InitBoot
;
; This function performs the initial boot routine
; for the CPU2 boot ROM.
;
; This module performs the following actions:
;
;     1) Initializes the stack pointer
;     2) Sets the device for C28x operating mode
;     3) Setup device systems
;     4) Run RAM initialization and call the main boot function
;
    .sect ".InitBoot"
InitBoot:

;
; Initialize the stack pointer.
;
__stack:    .usect ".stack",0
    MOV     SP, #__stack                         ;Initialize the stack pointer

;
; Initialize the device for running in C28x mode.
;
    C28OBJ                                       ;Select C28x object mode
    C28ADDR                                      ;Select C27x/C28x addressing
    C28MAP                                       ;Set blocks M0/M1 for C28x mode
    CLRC    PAGE0                                ;Always use stack addressing mode
    MOVW    DP, #0                               ;Initialize DP to point to the low 64 K
    CLRC    OVM                                  ;Clear overflow mode bit
;
; Set Product Mode shift to 0
;
    SPM     0

;
; Check for HWBIST as reset cause and handle accordingly
;
cpu2brom_hwbist_reset_check:
;
; if((CpuSysRegs.RESC.bit.HWBIST & 0x1) == 1) then check CSTCRET
;
    MOVW    DP, #0x174e                          ;Set DP to CpuSysRegs.RESC
    AND     AL, @0x0, #0x20                      ;Load ACC with (CpuSysRegs.RESC & 0x20) which is HWBIST RESC bit
    LSR     AL, 5                                ;Right shift ACC (HWBIST RESC bit) value by 5
    TBIT    @AL, #0x0                            ;Check bit 0 of ACC value (HWBIST RESC)
    SBF     cpu2brom_hwbist_reset_done, NTC      ;Branch if reset bit not set

;
; CPU2 Patch/Escape Point 1
;    
	MOVL         XAR4, #0x703ECU                 ;Load CPU2BROM_TI_OTP_ESCAPE_POINT_1 OTP address
	MOVL         XAR5, *+XAR4[0]
;
;   if((EntryAddr != 0xFFFFFFFF) && (EntryAddr != 0x00000000))
;
	MOVB         ACC, #0
	SUBB         ACC, #1
	CMPL         ACC, XAR5
	SBF          cpu2brom_hwbist_reset_no_escape, EQ
	MOVL         ACC, XAR5
	SBF          cpu2brom_hwbist_reset_no_escape, EQ
	LCR          *XAR5                           ; ((void (*)(void))EntryAddr)();

;
; if((HwbistRegs.CSTCRET.all != 0)) then branch to address
;
cpu2brom_hwbist_reset_no_escape:
    EALLOW
    MOVW    DP, #0x1780                          ;Set DP to HwbistRegs
    MOVL    ACC, @0x34                           ;Load HwbistRegs.CSTCRET.all
    EDIS
    SBF     cpu2brom_hwbist_reset_done, EQ       ;Branch if CSTCRET is ZERO
    MOVW    DP, #0x1738
    MOVW    @0x20, #0x8001                       ;CPU2TOCPU1BOOTSTS - Update lower boot status (set boot start, HWBIST handled)
    MOVW    @0x21, #0x8000                       ;CPU2TOCPU1BOOTSTS - Update upper boot status (boot complete)
    MOVW    DP, #0                               ;CPU2BROM_bootStatus DP in M0RAM
    MOVW    @0x2, #0x8001                        ;CPU2 M0RAM - Update lower boot status (set boot start, HWBIST handled)
    MOVW    @0x3, #0x8000                        ;CPU2 M0RAM - Update upper boot status (boot complete)
    MOVL    XAR5, ACC                            ;Set CSTCRET value as return address
    SPM     #0
    LCR     *XAR5                                ;Branch to address

;
; Reset cause isn't from HWBIST or CSTCRET is zero
;
cpu2brom_hwbist_reset_done:

;
; Disable watchdog
;
cpu2brom_disable_wdog:
    EALLOW
    MOVW    DP, #0x1c0                           ;Set DP to Watchdog Register
    MOVB    @0x29, #0x68, UNC                    ;Disable Watchdog
    EDIS

;
; Check IPCBOOTMODE for valid values
; Note: Make sure RAM isn't accessed in this function since RAM isn't
;       initialized and available yet
;    
    LCR     CPU2BROM_verifyBootCommand
    
;
; Check if reset cause is from POR or XRS
;
    MOVW    DP, #0x174e                          ;Set DP to CpuSysRegs.RESC
    MOVL    ACC, @0x0                            ;Load ACC with CpuSysRegs.RESC
    MOV     AH, #0x0                             ;Clear upper 16-bit of ACC
    ANDB    AL, #0x3                             ;Mask to only include POR and XRS RESC bits
    TEST    ACC
    SBF     stack_init, EQ                       ;Branch if ACC is zero (Not a POR or XRS reset) to stack init,
                                                 ;else continue on with device setup/config

;
; For POR/XRS only - initialize 32 locations of M0 RAM can be used for stack
;
    MOV     AL, #0x20                            ;Load value for initializing 32 locations
    MOV     AH, #0
por_xrs_ram_zero_loop:
    MOV     *SP++, #0                            ;Write zeros to all 32 locations
    SUBB    ACC, #1
    BF      por_xrs_ram_zero_loop,GEQ
    MOV     SP, #__stack                         ;Re-Initialize the stack pointer

;
; For POR/XRS only - Setup Device Systems - Power up flash
;
    LCR     CPU2BROM_setupDeviceSystems

;
; RAM Initialization
;
cpu2brom_perform_ram_inits:
;
; Check if reset cause is from POR
; if((CpuSysRegs.RESC & 0x1) == 1)
;
    MOVW    DP, #0x174e                          ;Set DP to CpuSysRegs.RESC
    MOVL    ACC, @0x0                            ;Load ACC with CpuSysRegs.RESC
    MOV     AH, #0x0                             ;Clear upper 16-bit of ACC
    ANDB    AL, #0x1                             ;Mask to only include POR RESC bits
    TEST    ACC
    SBF     stack_init, EQ                       ;Branch if ACC is zero (Not a POR reset) to stack init,
                                                 ;else continue on with RAM init

;
; POR Only - Initialize All RAMS (split into two groups)
;
; Group 1 - LS0-LS7, D0-D1
; Group 2 - M0,M1, MSG RAMs
;
    EALLOW

    MOVW    DP, #0x17d0                          ;Set DP to MemCfgRegs    
    
;
; Group 1 - LS0-LS7, D0-D1
;    

;
;   MemCfgRegs.LSxINIT.all = 0x00FF (RAMS LS0 - LS7)
;
    MOVB    ACC, #0xFF
    MOVL    @0x32, ACC                           ;Write 0xFF to MemCfgRegs.LSxINIT.all
 
;
;   MemCfgRegs.DxINIT.all = 0x000C (RAMs D0, D1)
;
    MOVB    ACC, #0xC
    MOVL    @0x12, ACC                           ;Write 0xC to MemCfgRegs.DxINIT.all

;
;   RAM Initialization delay - Wait for all RAM inits to complete
;                              (Largest is 4KB)
;    
    MOV     @T,#1056                             ;Wait 1024 + 32(=buffer)cycles
    RPT     @T
    ||NOP  
 
;
; Group 2 - M0,M1, MSG RAMs
;    
    
;
;   MemCfgRegs.DxINIT.all = 0x0003 (RAMs M0, M1)
;
    MOVB    ACC, #0x3
    MOVL    @0x12, ACC                           ;Write 0x3 to MemCfgRegs.DxINIT.all

;
;   MemCfgRegs.MSGxINIT.all = 0x03FF (RAMS CPU/CPU2 MSG0/1, CPU/CLA1/2 MSG, CLA1/DMA MSG, CPU/CM MSG0/1)
;
    MOVW    DP, #0x17d1                          ;Set DP to MemCfgRegs.GSxLOCK
    MOV     ACC, #0x3FF
    MOVL    @0x32, ACC                           ;Write 0x03FF to MemCfgRegs.MSGxINIT.all
    EDIS      
    
;
;   RAM Initialization delay - Wait for all RAM inits to complete
;                              (Largest is 2KB)
;
    MOV     @T,#544                             ;Wait 512 + 32(=buffer)cycles
    RPT     @T
    ||NOP

;
; CPU2 Patch/Escape Point 3
;    
	MOVL         XAR4, #0x703E8                 ;Load CPU2BROM_TI_OTP_ESCAPE_POINT_3 OTP address
	MOVL         XAR5, *+XAR4[0]
;
;   if((EntryAddr != 0xFFFFFFFF) && (EntryAddr != 0x00000000))
;
	MOVB         ACC, #0
	SUBB         ACC, #1
	CMPL         ACC, XAR5
	SBF          continue_to_system_boot, EQ
	MOVL         ACC, XAR5
	SBF          continue_to_system_boot, EQ
	LCR          *XAR5                           ; ((void (*)(void))EntryAddr)();    
    
;
;   Once All RAM init is complete, skip stack init and continue execution
;
continue_to_system_boot:
    SB      cpu2brom_perform_ram_inits_complete, UNC

;
; Not POR or XRS - Initialize the stack used for boot to zero
;
stack_init:
    MOV     AL, #0x150                           ;Size of stack
    MOV     AH, #0
stack_ram_zero_loop:
    MOV     *SP++, #0                            ;Zero out RAM for stack
    SUBB    ACC, #1
    BF      stack_ram_zero_loop, GEQ
stack_ram_init_done:
    MOV     SP, #__stack                         ;Re-Initialize the stack pointer

;
; RAM Init or Stack Init is complete, prepare to begin system initialization
;
cpu2brom_perform_ram_inits_complete:
    MOVW    DP,#0                                ;Initialize DP to point to the low 64 K
    CLRC    OVM                                  ;Clear overflow mode bit
    SPM     0                                    ;Set Product Mode shift to 0
;
; Branch to system initialization to run final initializations and execute boot mode
;
    LCR    CPU2BROM_startSystemBoot

;
; Function: ExitBoot
;
; This module cleans up after boot
;
; 1) Make sure the stack is re-initialized.
; 2) Push 0 onto the stack so RPC will be
;    0 after using LRETR to jump to the
;    entry point
; 2) Load RPC with the entry point
; 3) Clear all XARn registers
; 4) Clear ACC, P and XT registers
; 5) LRETR - this will also clear the RPC
;    register since 0 was on the stack
;
ExitBoot:
;
;   Insure that the stack is re-initialized
;
    MOV     SP,#__stack

;
; Clear the bottom of the stack.  This will endup
; in RPC when we are finished
;
    MOV     *SP++,#0
    MOV     *SP++,#0

;
; Load RPC with the entry point as determined
; by the boot mode.  This address will be returned
; in the ACC register.
;
    PUSH    ACC
    POP     RPC

;
; Put registers back in their reset state.
;
; Clear all the XARn, ACC, XT, and P and DP
; registers
;
; NOTE: Leave the device in C28x operating mode
;       (OBJMODE = 1, AMODE = 0)
;
    ZAPA
    MOVL    XT,ACC
    MOVZ    AR0,AL
    MOVZ    AR1,AL
    MOVZ    AR2,AL
    MOVZ    AR3,AL
    MOVZ    AR4,AL
    MOVZ    AR5,AL
    MOVZ    AR6,AL
    MOVZ    AR7,AL
    MOVW    DP, #0

;
;   Restore ST0 and ST1.  Note OBJMODE is
;   the only bit not restored to its reset state.
;   OBJMODE is left set for C28x object operating
;   mode.
;
;  ST0 = 0x0000     ST1 = 0x0A0B
;  15:10 OVC = 0    15:13      ARP = 0
;   9: 7  PM = 0       12       XF = 0
;      6   V = 0       11  M0M1MAP = 1
;      5   N = 0       10  reserved
;      4   Z = 0        9  OBJMODE = 1
;      3   C = 0        8    AMODE = 0
;      2  TC = 0        7 IDLESTAT = 0
;      1 OVM = 0        6   EALLOW = 0
;      0 SXM = 0        5     LOOP = 0
;                       4      SPA = 0
;                       3     VMAP = 1
;                       2    PAGE0 = 0
;                       1     DBGM = 1
;                       0     INTM = 1
;
    MOV     *SP++,#0
    MOV     *SP++,#0x0A0B
    POP     ST1
    POP     ST0

;
;   Jump to the EntryAddr as defined by the
;   boot mode selected and continue execution
;
    LRETR

;
; End of file.
;
