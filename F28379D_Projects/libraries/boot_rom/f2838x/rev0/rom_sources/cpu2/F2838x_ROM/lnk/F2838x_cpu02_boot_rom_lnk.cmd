/*
//###########################################################################
//
// FILE:    F2838x_cpu02_boot_rom_lnk.cmd
//
// TITLE:   CPU2 boot rom linker command file
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
--retain '(.CPU2Version)'

--retain '(FPUfftTables)'
--retain '(FPU64fftTables)'

--retain '(FPUmathTables)'
--retain '(FPU64mathTables)'

--retain '(.test_signature1)'
--retain '(.bootrom_func)'
--retain '(.CKSUMLOC)'
--retain '(.BOOT_CKSUMLOC)'
--retain '(.CKSUMFUNCS)'

MEMORY
{
    //
    // ROM Memories
    //
    ROM_SIGNATURE          : origin = 0x3E8000, length = 0x000002
    AES_TABLES             : origin = 0x3E8002, length = 0x001400
    IQMATH                 : origin = 0x3E9402, length = 0x00166D

    RESERVED_1             : origin = 0x3EAA6F, length = 0x00BED7//, fill = 0xFFFF

    FPU32_FAST_TABLES      : origin = 0x3F6946, length = 0x00081a
    FPU64_FAST_TABLES      : origin = 0x3F7160, length = 0x000D30
    FPU32_TWIDDLE_TABLES   : origin = 0x3F7E90, length = 0x000DF8
    FPU64_TWIDDLE_TABLES   : origin = 0x3F8DD0, length = 0x001BF0
    BOOT                   : origin = 0x3FA9C0, length = 0x003E00//, fill = 0xFFFF
    INTERRUPT_HANDLERS     : origin = 0x3FE7C0, length = 0x000173

    RESERVED_2             : origin = 0x3FE933, length = 0x0000EF//, fill = 0xFFFF

    CPU_FAST_DATA_ROM      : origin = 0x3FEA22, length = 0x000100

    RESERVED_3             : origin = 0x3FEB22, length = 0x00131E//, fill = 0xFFFF

    BOOT_CHECKSUM          : origin = 0x3FFE40, length = 0x000042

    RESERVED_4             : origin = 0x3FFE82, length = 0x00003E//, fill = 0xFFFF

    CHECKSUM               : origin = 0x3FFEC0, length = 0x000042
    RESERVED_5             : origin = 0x3FFF02, length = 0x000030//, fill = 0xFFFF
    CRCTABLE_ROM           : origin = 0x3FFF32, length = 0x000008
    RESERVED_6             : origin = 0x3FFF3A, length = 0x000040//, fill = 0xFFFF
    VERSION                : origin = 0x3FFF7A, length = 0x000002
    RESERVED_7             : origin = 0x3FFF7C, length = 0x000042//, fill = 0xFFFF
    VECS                   : origin = 0x3FFFBE, length = 0x000042

    //
    // RAM Memories
    //
    CPU2_BROM_STATUS       : origin = 0x002, length = 0x000002
    CPU2_BROM_BOOTMODE     : origin = 0x004, length = 0x000002
    BSS                    : origin = 0x008, length = 0x000050
    STACK                  : origin = 0x058, length = 0x000150
    //PIE Control at 0xCE0, length - 0x20
    //PIE Vect Table for USB at 0xD00, length - 0x200
}

SECTIONS
{
    IQmathTables : load = IQMATH
    {
         -l IQmath_fpu32_eabi.lib
    }

    GROUP : load = FPU32_TWIDDLE_TABLES, ALIGN(2)
    {
         FPUfftTables
    }

    GROUP : load = FPU64_TWIDDLE_TABLES, ALIGN(2)
    {
        FPU64fftTables
    }

    GROUP : load = FPU32_FAST_TABLES, ALIGN(2)
    {
        FPUmathTables
    }

    GROUP : load = FPU64_FAST_TABLES, ALIGN(2)
    {
        FPU64mathTables
    }

    GROUP : load = INTERRUPT_HANDLERS
    {
        CPU2BROM_DEFAULT_HANDLER
        CPU2BROM_PIE_MISMATCH_HANDLER
        CPU2BROM_NMI_HANDLER
        CPU2BROM_ITRAP_HANDLER
    }

    .test_signature1:       load = ROM_SIGNATURE
    .bootrom_func:          load = CRCTABLE_ROM
    .InitBoot:              load = BOOT
    .text:                  load = BOOT
    .CKSUMFUNCS:            load = BOOT, ALIGN(2)
    .Isr:                   load = BOOT
    .BootVecs:              load = VECS
    .BOOT_CKSUMLOC:         load = BOOT_CHECKSUM, ALIGN(2)
    .CKSUMLOC:              load = CHECKSUM, ALIGN(2)
    .CPU2Version:           load = VERSION
    .stack:                 load = STACK
    .bss:                   load = BSS
    .const:                 load = BOOT, ALIGN(2)
    .cinit:                 load = BOOT, ALIGN(2)
    .switch:                load = BOOT, ALIGN(2)
    AES_TABLE               load = AES_TABLES, ALIGN(2)
    BootStatusVariable:     load = CPU2_BROM_STATUS
    UserBootModeVariable:   load = CPU2_BROM_BOOTMODE
}

