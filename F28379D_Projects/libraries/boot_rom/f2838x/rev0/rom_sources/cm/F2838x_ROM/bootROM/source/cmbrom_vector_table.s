;;###########################################################################
;;
;; FILE:    cmbrom_vector_table.s
;;
;; TITLE:   CM Boot ROM vector table.
;;
;; This section of code populates the vector table in the boot ROM.
;;
;;###########################################################################
;; $TI Release:  $
;; $Release Date:  $
;;###########################################################################

;
; Globals
;
    .global Vectors
    .ref CM_resetISR
    .ref CMBROM_nmiHandler
    .ref CMBROM_hardFaultISR
    .ref CMBROM_defaultHandler

    .sect ".BootVecs"

;
; The minimal vector table for a Cortex-M4 processor.
;
Vectors:
    .word   0x20000800                      ;; Offset 00: Initial stack pointer         -0 = vector no
    .word   CM_resetISR                     ;; Offset 04: Reset handler                 -1
    .word   CMBROM_nmiHandler               ;; Offset 08: NMI handler                   -2
    .word   CMBROM_hardFaultISR             ;; Offset 0C: Hard fault handler            -3
    .word   CMBROM_defaultHandler           ;; Offset 10: MemManage fault handler       -4
    .word   CMBROM_defaultHandler           ;; Offset 14: Bus fault handler             -5
    .word   CMBROM_defaultHandler           ;; Offset 18: Usage fault handler           -6
    .word   0                               ;; Offset 1C: Reserved                      -7
    .word   0                               ;; Offset 20: Reserved                      -8
    .word   0                               ;; Offset 24: Reserved                      -9
    .word   0                               ;; Offset 28: Reserved                      -10
    .word   CMBROM_defaultHandler           ;; Offset 2C: SVCall handler                -11
    .word   CMBROM_defaultHandler           ;; Offset 30: Debug monitor handler         -12
    .word   0                               ;; Offset 34: Reserved                      -13
    .word   CMBROM_defaultHandler           ;; Offset 38: PendSV handler                -14
    .word   CMBROM_defaultHandler           ;; Offset 3C: SysTick handler               -15
    .word   CMBROM_defaultHandler           ;; Offset 40: MCAN INT0                     -16
    .word   CMBROM_defaultHandler           ;; Offset 44: MCAN INT1                     -17
    .word   CMBROM_defaultHandler           ;; Offset 48: MCAN WAKE and TS PLS INT      -18
    .word   CMBROM_defaultHandler           ;; Offset 4C: MCAN ECC CORR LVL INT         -19
    .word   CMBROM_defaultHandler           ;; Offset 50: reserved                      -20
    .word   CMBROM_defaultHandler           ;; Offset 54: ECAT INT                      -21
    .word   CMBROM_defaultHandler           ;; Offset 58: ECAT SYNC0 INT                -22
    .word   CMBROM_defaultHandler           ;; Offset 5C: ECAT SYNC1 INT                -23
    .word   CMBROM_defaultHandler           ;; Offset 60: ECAT RST INT                  -24
    .word   CMBROM_defaultHandler           ;; Offset 64: CANA INT0                     -25
    .word   CMBROM_defaultHandler           ;; Offset 68: CANA INT1                     -26
    .word   CMBROM_defaultHandler           ;; Offset 6C: CANB INT0                     -27
    .word   CMBROM_defaultHandler           ;; Offset 70: CANB INT1                     -28
    .word   CMBROM_defaultHandler           ;; Offset 74: EMAC INT                      -29
    .word   CMBROM_defaultHandler           ;; Offset 78: EMAC TX INT0                  -30
    .word   CMBROM_defaultHandler           ;; Offset 7C: EMAC TX INT1                  -31
    .word   CMBROM_defaultHandler           ;; Offset 80: EMAC RX INT0                  -32
    .word   CMBROM_defaultHandler           ;; Offset 84: EMAC RX INT1                  -33
    .word   CMBROM_defaultHandler           ;; Offset 88: UART0 INT                     -34
    .word   CMBROM_defaultHandler           ;; Offset 8C: reserved                      -35
    .word   CMBROM_defaultHandler           ;; Offset 90: SSI0 INT                      -36
    .word   CMBROM_defaultHandler           ;; Offset 94: reserved                      -37
    .word   CMBROM_defaultHandler           ;; Offset 98: I2C0 INT                      -38
    .word   CMBROM_defaultHandler           ;; Offset 9C: reserved                      -39
    .word   CMBROM_defaultHandler           ;; Offset A0: USB INT                       -40
    .word   CMBROM_defaultHandler           ;; Offset A4: UDMA SW INT                   -41
    .word   CMBROM_defaultHandler           ;; Offset A8: UDMA ERR INT                  -42
    .word   CMBROM_defaultHandler           ;; Offset AC: reserved                      -43
    .word   CMBROM_defaultHandler           ;; Offset B0: reserved                      -44
    .word   CMBROM_defaultHandler           ;; Offset B4: CPU1 to CM IPC INT0           -45
    .word   CMBROM_defaultHandler           ;; Offset B8: CPU1 to CM IPC INT1           -46
    .word   CMBROM_defaultHandler           ;; Offset BC: CPU1 to CM IPC INT2           -47
    .word   CMBROM_defaultHandler           ;; Offset C0: CPU1 to CM IPC INT3           -48
    .word   CMBROM_defaultHandler           ;; Offset C4: CPU1 to CM IPC INT4           -49
    .word   CMBROM_defaultHandler           ;; Offset C8: CPU1 to CM IPC INT5           -50
    .word   CMBROM_defaultHandler           ;; Offset CC: CPU1 to CM IPC INT6           -51
    .word   CMBROM_defaultHandler           ;; Offset D0: CPU1 to CM IPC INT7           -52
    .word   CMBROM_defaultHandler           ;; Offset D4: CPU2 to CM IPC INT0           -53
    .word   CMBROM_defaultHandler           ;; Offset D8: CPU2 to CM IPC INT1           -54
    .word   CMBROM_defaultHandler           ;; Offset DC: CPU2 to CM IPC INT2           -55
    .word   CMBROM_defaultHandler           ;; Offset E0: CPU2 to CM IPC INT3           -56
    .word   CMBROM_defaultHandler           ;; Offset E4: CPU2 to CM IPC INT4           -56
    .word   CMBROM_defaultHandler           ;; Offset E8: CPU2 to CM IPC INT5           -58
    .word   CMBROM_defaultHandler           ;; Offset EC: CPU2 to CM IPC INT6           -59
    .word   CMBROM_defaultHandler           ;; Offset F0: CPU2 to CM IPC INT7           -60
    .word   CMBROM_defaultHandler           ;; Offset F4: FMC INT                       -61
    .word   CMBROM_defaultHandler           ;; Offset F8: FMC Correctable Error INT     -62
    .word   CMBROM_defaultHandler           ;; Offset FC: AES INT                       -63
    .word   CMBROM_defaultHandler           ;; Offset 100: CPU Timer 1                  -64
    .word   CMBROM_defaultHandler           ;; Offset 104: CPU Timer 2                  -65
    .word   CMBROM_defaultHandler           ;; Offset 108: CPU Timer 3                  -66
    .word   CMBROM_defaultHandler           ;; Offset 10C: CM RAM TEST ERROR LOG        -67
    .word   CMBROM_defaultHandler           ;; Offset 110: reserved                     -68
    .word   CMBROM_defaultHandler           ;; Offset 114: reserved                     -69
    .word   CMBROM_defaultHandler           ;; Offset 118: reserved                     -70
    .word   CMBROM_defaultHandler           ;; Offset 11C: reserved                     -71
    .word   CMBROM_defaultHandler           ;; Offset 120: reserved                     -72
    .word   CMBROM_defaultHandler           ;; Offset 124: reserved                     -73
    .word   CMBROM_defaultHandler           ;; Offset 128: reserved                     -74
    .word   CMBROM_defaultHandler           ;; Offset 12C: reserved                     -75
    .word   CMBROM_defaultHandler           ;; Offset 130: reserved                     -76
    .word   CMBROM_defaultHandler           ;; Offset 134: reserved                     -77
    .word   CMBROM_defaultHandler           ;; Offset 138: reserved                     -78
    .word   CMBROM_defaultHandler           ;; Offset 13C: reserved                     -79

;
; End of file
;
    .end