/*
//###########################################################################
//
// FILE:    F2838x_cm_boot_rom_lnk.cmd
//
// TITLE:   CM boot rom linker command file
//
//
//###########################################################################
// $TI Release:  $
// $Release Date:  $
//###########################################################################
*/

//
// Required for EABI retention of unreferenced sections
//
--retain '(.CMVersion)'
--retain '(.test_signature1)'
--retain '(.CKSUMLOC)'
--retain '(.BOOT_CKSUMLOC)'
--retain '(.bootrom_func)'
--retain '(.checksumfuncs)'

MEMORY
{
    //
    // ROM Memories
    //
    VECS                   : origin = 0x000000, length = 0x000140
    VERSION                : origin = 0x000140, length = 0x000004
    BOOT_CHECKSUM          : origin = 0x000144, length = 0x000084
    CHECKSUM               : origin = 0x0001C8, length = 0x000084
    BOOT                   : origin = 0x00024C, length = 0x003DCC//, fill = 0xFFFF
    INTERRUPT_HANDLERS     : origin = 0x004018, length = 0x000204

    RESERVED               : origin = 0x00421C, length = 0x00B9E0//, fill = 0xFFFF

    CRCTABLE_ROM           : origin = 0x00FBFC, length = 0x000400
    ROM_SIGNATURE          : origin = 0x00FFFC, length = 0x000004

    //
    // RAM Memories
    //
    CM_BROM_STATUS         : origin = 0x20000000, length = 0x000004
    CM_BROM_BOOTMODE       : origin = 0x20000004, length = 0x000004
    BSS                    : origin = 0x20000008, length = 0x000004
    STACK                  : origin = 0x2000000C, length = 0x0007F4
}

SECTIONS
{
    GROUP : load = INTERRUPT_HANDLERS
    {
        CMBROM_NMI_HANDLER
        CMBROM_HARDFAULT_HANDLER
        CMBROM_DEFAULT_HANDLER
    }

    .test_signature1:       load = ROM_SIGNATURE
    .bootrom_func:          load = CRCTABLE_ROM //Will come from secure CRC lib
    .InitBoot:              load = BOOT
    .text:                  load = BOOT
    .checksumfuncs:         load = BOOT, ALIGN(2)
    .Isr:                   load = BOOT
    .BootVecs:              load = VECS
    .BOOT_CKSUMLOC:         load = BOOT_CHECKSUM, ALIGN(2)
    .CKSUMLOC:              load = CHECKSUM, ALIGN(2)
    .CMVersion:             load = VERSION
    .stack:                 load = STACK
    .bss:                   load = BSS
    .const:                 load = BOOT, ALIGN(2)
    .cinit:                 load = BOOT, ALIGN(2)
    .switch:                load = BOOT, ALIGN(2)
    BootStatusVariable:     load = CM_BROM_STATUS
    UserBootModeVariable:   load = CM_BROM_BOOTMODE
}

