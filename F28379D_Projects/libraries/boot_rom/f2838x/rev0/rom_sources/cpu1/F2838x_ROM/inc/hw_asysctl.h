//###########################################################################
//
// FILE:    hw_asysctl.h
//
// TITLE:   Definitions for the ASYSCTL registers.
//
//###########################################################################
// $TI Release:  $
// $Release Date:  $
// $Copyright:  $
//###########################################################################

#ifndef HW_ASYSCTL_H
#define HW_ASYSCTL_H

//*****************************************************************************
//
// The following are defines for the ASYSCTL register offsets
//
//*****************************************************************************
#define ASYSCTL_O_INTOSC1TRIM     0x20U        // Internal Oscillator 1 Trim
                                               // Register
#define ASYSCTL_O_INTOSC2TRIM     0x22U        // Internal Oscillator 2 Trim
                                               // Register
#define ASYSCTL_O_INTERNALTESTCTL  0x24U        // INTERNALTEST Node Control
                                               // Register
#define ASYSCTL_O_TSNSCTL         0x26U        // Temperature Sensor Control
                                               // Register
#define ASYSCTL_O_ANAREFCTL       0x27U        // Analog Reference Control
                                               // Register
#define ASYSCTL_O_VMONCTL         0x28U        // Voltage Monitor Control
                                               // Register
#define ASYSCTL_O_VMONSTS         0x29U        // Voltage Monitor Status
                                               // Register
#define ASYSCTL_O_VMONCLR         0x2AU        // Voltage Monitor Clear
                                               // Register
#define ASYSCTL_O_VREGCTL         0x2BU        // Voltage Regulator Control
                                               // Register
#define ASYSCTL_O_LOCK            0x2EU        // Lock Register
#define ASYSCTL_O_INTOSC1CSR      0x30U        // Internal Oscillator 1 Control
                                               // and Status Register
#define ASYSCTL_O_INTOSC2CSR      0x31U        // Internal Oscillator 2 Control
                                               // and Status Register
#define ASYSCTL_O_TSNSCFG         0x32U        // Temperature Sensor Config
                                               // Register
#define ASYSCTL_O_OSCREFTRIM      0x34U        // Internal Oscillator Reference
                                               // Trim Register
#define ASYSCTL_O_ANAREFTRIMA     0x36U        // Analog Reference Trim A
                                               // Register
#define ASYSCTL_O_ANAREFTRIMB     0x38U        // Analog Reference Trim B
                                               // Register
#define ASYSCTL_O_ANAREFTRIMC     0x3AU        // Analog Reference Trim C
                                               // Register
#define ASYSCTL_O_ANAREFTRIMD     0x3CU        // Analog Reference Trim D
                                               // Register
#define ASYSCTL_O_PMMREFTRIM      0x3EU        // Power Management Module
                                               // Reference Trim Register
#define ASYSCTL_O_PMMVREGTRIM     0x40U        // Power Management Module VREG
                                               // Trim Register
#define ASYSCTL_O_PMMVMONTRIM     0x42U        // Power Management Module VMON
                                               // Trim Register
#define ASYSCTL_O_PMMCSR          0x44U        // Power Management Module
                                               // Control and Status Register
#define ASYSCTL_O_SYSAPLLCONFIG1  0xC0U        // APLL Module (SYSPLL Instance)
                                               // CONFIG1 Register
#define ASYSCTL_O_SYSAPLLCONFIG2  0xC1U        // APLL Module (SYSPLL Instance)
                                               // CONFIG2 Register
#define ASYSCTL_O_SYSAPLLCONFIG3  0xC2U        // APLL Module (SYSPLL Instance)
                                               // CONFIG3 Register
#define ASYSCTL_O_SYSAPLLCONFIG4  0xC3U        // APLL Module (SYSPLL Instance)
                                               // CONFIG4 Register
#define ASYSCTL_O_SYSAPLLCONFIG5  0xC4U        // APLL Module (SYSPLL Instance)
                                               // CONFIG5 Register
#define ASYSCTL_O_SYSAPLLCONFIG7  0xC6U        // APLL Module (SYSPLL Instance)
                                               // CONFIG7 Register
#define ASYSCTL_O_SYSAPLLCONFIG8  0xC7U        // APLL Module (SYSPLL Instance)
                                               // CONFIG8 Register
#define ASYSCTL_O_SYSAPLLCONFIG9  0xC8U        // APLL Module (SYSPLL Instance)
                                               // CONFIG9 Register
#define ASYSCTL_O_SYSAPLLCONFIG10  0xC9U        // APLL Module (SYSPLL Instance)
                                               // CONFIG10 Register
#define ASYSCTL_O_SYSAPLLDIGSTATUS1  0xCAU        // APLL Module (SYSPLL Instance)
                                               // DIGSTATUS1 Register
#define ASYSCTL_O_SYSAPLLDIGSTATUS2  0xCCU        // APLL Module (SYSPLL Instance)
                                               // DIGSTATUS2 Register
#define ASYSCTL_O_SYSAPLLDIGSTATUS3  0xCEU        // APLL Module (SYSPLL Instance)
                                               // DIGSTATUS3 Register
#define ASYSCTL_O_SYSAPLLSPAREIN  0xD6U        // APLL Module (SYSPLL Instance)
                                               // SPAREIN Register
#define ASYSCTL_O_SYSAPLLSPAREOUT  0xD7U        // APLL Module (SYSPLL Instance)
                                               // SPAREOUT Register
#define ASYSCTL_O_AUXAPLLCONFIG1  0xD8U        // APLL Module (AUXPLL Instance)
                                               // CONFIG1 Register
#define ASYSCTL_O_AUXAPLLCONFIG2  0xD9U        // APLL Module (AUXPLL Instance)
                                               // CONFIG2 Register
#define ASYSCTL_O_AUXAPLLCONFIG3  0xDAU        // APLL Module (AUXPLL Instance)
                                               // CONFIG3 Register
#define ASYSCTL_O_AUXAPLLCONFIG4  0xDBU        // APLL Module (AUXPLL Instance)
                                               // CONFIG4 Register
#define ASYSCTL_O_AUXAPLLCONFIG5  0xDCU        // APLL Module (AUXPLL Instance)
                                               // CONFIG5 Register
#define ASYSCTL_O_AUXAPLLCONFIG7  0xDEU        // APLL Module (AUXPLL Instance)
                                               // CONFIG7 Register
#define ASYSCTL_O_AUXAPLLCONFIG8  0xDFU        // APLL Module (AUXPLL Instance)
                                               // CONFIG8 Register
#define ASYSCTL_O_AUXAPLLCONFIG9  0xE0U        // APLL Module (AUXPLL Instance)
                                               // CONFIG9 Register
#define ASYSCTL_O_AUXAPLLCONFIG10  0xE1U        // APLL Module (AUXPLL Instance)
                                               // CONFIG10 Register
#define ASYSCTL_O_AUXAPLLDIGSTATUS1  0xE2U        // APLL Module (AUXPLL Instance)
                                               // DIGSTATUS1 Register
#define ASYSCTL_O_AUXAPLLDIGSTATUS2  0xE4U        // APLL Module (AUXPLL Instance)
                                               // DIGSTATUS2 Register
#define ASYSCTL_O_AUXAPLLDIGSTATUS3  0xE6U        // APLL Module (AUXPLL Instance)
                                               // DIGSTATUS3 Register
#define ASYSCTL_O_AUXAPLLSPAREIN  0xEEU        // APLL Module (AUXPLL Instance)
                                               // SPAREIN Register
#define ASYSCTL_O_AUXAPLLSPAREOUT  0xEFU        // APLL Module (AUXPLL Instance)
                                               // SPAREOUT Register
#define ASYSCTL_O_APLLREFTRIM     0xF0U        // APLL Module Reference Trim
                                               // Register
#define ASYSCTL_O_SYSAPLLLDOTRIM  0xF1U        // APLL Module (SYSPLL) LDO
                                               // trim.
#define ASYSCTL_O_SYSAPLLOSCTRIM  0xF2U        // APLL Module (SYSPLL) OSC
                                               // trim.
#define ASYSCTL_O_AUXAPLLLDOTRIM  0xF3U        // APLL Module (AUXPLL) LDO
                                               // trim.
#define ASYSCTL_O_AUXAPLLOSCTRIM  0xF4U        // APLL Module (AUXPLL) OSC
                                               // trim.
#define ASYSCTL_O_APLLREFCONFIG   0xF8U        // APLL Module Reference Config
                                               // Register
#define ASYSCTL_O_PLLSEL          0xFBU        // PLL Select Register.
#define ASYSCTL_O_APLLLOCK        0xFEU        // APLL Config and Trim Lock
                                               // Register.

//*****************************************************************************
//
// The following are defines for the bit fields in the INTOSC1TRIM register
//
//*****************************************************************************
#define ASYSCTL_INTOSC1TRIM_VALFINETRIM_S  0U
#define ASYSCTL_INTOSC1TRIM_VALFINETRIM_M  0xFFFU       // Oscillator Value Fine Trim
                                               // Bits
#define ASYSCTL_INTOSC1TRIM_SLOPETRIM_S  16U
#define ASYSCTL_INTOSC1TRIM_SLOPETRIM_M  0xFF0000U    // Oscillator Slope Trim Bits

//*****************************************************************************
//
// The following are defines for the bit fields in the INTOSC2TRIM register
//
//*****************************************************************************
#define ASYSCTL_INTOSC2TRIM_VALFINETRIM_S  0U
#define ASYSCTL_INTOSC2TRIM_VALFINETRIM_M  0xFFFU       // Oscillator Value Fine Trim
                                               // Bits
#define ASYSCTL_INTOSC2TRIM_SLOPETRIM_S  16U
#define ASYSCTL_INTOSC2TRIM_SLOPETRIM_M  0xFF0000U    // Oscillator Slope Trim Bits

//*****************************************************************************
//
// The following are defines for the bit fields in the INTERNALTESTCTL register
//
//*****************************************************************************
#define ASYSCTL_INTERNALTESTCTL_TESTSEL_S  0U
#define ASYSCTL_INTERNALTESTCTL_TESTSEL_M  0x1FU        // Test Select
#define ASYSCTL_INTERNALTESTCTL_KEY_S  16U
#define ASYSCTL_INTERNALTESTCTL_KEY_M  0xFFFF0000U  // Write Key

//*****************************************************************************
//
// The following are defines for the bit fields in the TSNSCTL register
//
//*****************************************************************************
#define ASYSCTL_TSNSCTL_ENABLE    0x1U         // Temperature Sensor Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the ANAREFCTL register
//
//*****************************************************************************
#define ASYSCTL_ANAREFCTL_ANAREFASEL  0x1U         // Analog Reference A Select
#define ASYSCTL_ANAREFCTL_ANAREFBSEL  0x2U         // Analog Reference B Select
#define ASYSCTL_ANAREFCTL_ANAREFCSEL  0x4U         // Analog Reference C Select
#define ASYSCTL_ANAREFCTL_ANAREFDSEL  0x8U         // Analog Reference D Select

//*****************************************************************************
//
// The following are defines for the bit fields in the VMONCTL register
//
//*****************************************************************************
#define ASYSCTL_VMONCTL_OVMONENZ  0x1U         // Over Voltage Monitor Enable
                                               // Low
#define ASYSCTL_VMONCTL_OVFNMIEN  0x2U         // Over Voltage Fault NMI Enable
#define ASYSCTL_VMONCTL_VMON2ENZ  0x4U         // Voltage Monitor 2 Enable Low

//*****************************************************************************
//
// The following are defines for the bit fields in the VMONSTS register
//
//*****************************************************************************
#define ASYSCTL_VMONSTS_OVF       0x1U         // Over Voltage Fault
#define ASYSCTL_VMONSTS_VMON2FLT  0x2U         // Voltage Monitor 2 Fault
#define ASYSCTL_VMONSTS_VMON2STS  0x4U         // Voltage Monitor 2 Status

//*****************************************************************************
//
// The following are defines for the bit fields in the VMONCLR register
//
//*****************************************************************************
#define ASYSCTL_VMONCLR_OVF       0x1U         // Over Voltage Fault Clear
#define ASYSCTL_VMONCLR_VMON2FLT  0x2U         // Voltage Monitor 2 Fault Clear

//*****************************************************************************
//
// The following are defines for the bit fields in the VREGCTL register
//
//*****************************************************************************
#define ASYSCTL_VREGCTL_VREG2ENZ  0x1U         // Voltage Regulator 2 Enable
                                               // Active Low
#define ASYSCTL_VREGCTL_VSINKENZ  0x2U         // Voltage Sink Regulator Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the LOCK register
//
//*****************************************************************************
#define ASYSCTL_LOCK_INTOSC1TRIM  0x1U         // Internal Oscillator 1 Trim
                                               // Register Lock
#define ASYSCTL_LOCK_INTOSC2TRIM  0x2U         // Internal Oscillator 2 Trim
                                               // Register Lock
#define ASYSCTL_LOCK_INTERNALTESTCTL  0x4U         // Internal Test Node Control
                                               // Register Lock
#define ASYSCTL_LOCK_TSNSCTL      0x8U         // Temperature Sensor Control
                                               // Register Lock
#define ASYSCTL_LOCK_ANAREFCTL    0x10U        // Analog Reference Control
                                               // Register Lock
#define ASYSCTL_LOCK_VMONCTL      0x20U        // Voltage Monitor Control
                                               // Register Lock
#define ASYSCTL_LOCK_VREGCTL      0x40U        // Voltage Regulator Control
                                               // Register Lock
#define ASYSCTL_LOCK_INTOSC1CSR   0x80000U     // Internal Oscillator 1 Control
                                               // and Status Register Lock
#define ASYSCTL_LOCK_INTOSC2CSR   0x100000U    // Internal Oscillator 2 Control
                                               // and Status Register Lock
#define ASYSCTL_LOCK_TSNSCFG      0x200000U    // Temperature Sensor Config
                                               // Register Lock
#define ASYSCTL_LOCK_OSCREFTRIM   0x400000U    // Oscillator Reference Trim
                                               // Register Lock
#define ASYSCTL_LOCK_ANAREFTRIMA  0x800000U    // Analog Reference A Trim
                                               // Register Lock
#define ASYSCTL_LOCK_ANAREFTRIMB  0x1000000U   // Analog Reference B Trim
                                               // Register Lock
#define ASYSCTL_LOCK_ANAREFTRIMC  0x2000000U   // Analog Reference C Trim
                                               // Register Lock
#define ASYSCTL_LOCK_ANAREFTRIMD  0x4000000U   // Analog Reference D Trim
                                               // Register Lock
#define ASYSCTL_LOCK_PMMREFTRIM   0x8000000U   // Power Management Module
                                               // Reference Trim Register Lock
#define ASYSCTL_LOCK_PMMVREGTRIM  0x10000000U  // Power Management Module VREG
                                               // Trim Register Lock
#define ASYSCTL_LOCK_PMMVMONTRIM  0x20000000U  // Power Management Module VMON
                                               // Trim Register Lock
#define ASYSCTL_LOCK_PMMCSR       0x40000000U  // Power Management Module
                                               // Control and Status Register Lock

//*****************************************************************************
//
// The following are defines for the bit fields in the INTOSC1CSR register
//
//*****************************************************************************
#define ASYSCTL_INTOSC1CSR_SELOSCA  0x1U         // Select OSC-A for measurement
#define ASYSCTL_INTOSC1CSR_EN16MHZ  0x2U         // Enable 16MHz mode
#define ASYSCTL_INTOSC1CSR_DISABLESLOPETRIM  0x4U         // Disable slopetrim
#define ASYSCTL_INTOSC1CSR_DISABLEPSRFIL  0x8U         // Disable PSR filter in IGEN
#define ASYSCTL_INTOSC1CSR_DISABLECASCODE  0x10U        // Disable cascoding at IGEN
                                               // output current arm
#define ASYSCTL_INTOSC1CSR_IGENIBIASPROG  0x20U        // IGEN amp bias current
                                               // programmability
#define ASYSCTL_INTOSC1CSR_COMPIBIASPROG  0x40U        // Comparator bias
                                               // programmability
#define ASYSCTL_INTOSC1CSR_ICHARGE2PAD  0x80U        // Bring the charging current to
                                               // TESTANA1
#define ASYSCTL_INTOSC1CSR_MEASVFBHI  0x100U       // Measure VFB_HI voltage at
                                               // TESTANA0
#define ASYSCTL_INTOSC1CSR_MEASVFBLO  0x200U       // Measure VFB_LO voltage at
                                               // TESTANA0
#define ASYSCTL_INTOSC1CSR_MEASAMPOUT  0x400U       // Measure IGEN amp output
                                               // voltage at TESTANA0
#define ASYSCTL_INTOSC1CSR_PDNOSC  0x800U       // Power down both oscillators

//*****************************************************************************
//
// The following are defines for the bit fields in the INTOSC2CSR register
//
//*****************************************************************************
#define ASYSCTL_INTOSC2CSR_SELOSCB  0x1U         // Select OSC-B for measurement
#define ASYSCTL_INTOSC2CSR_MEASVREF  0x2U         // Measure VREF from reference
                                               // at TESTANA0
#define ASYSCTL_INTOSC2CSR_MEASPTATHI  0x4U         // Measure voltage PTAT_HIGH at
                                               // TESTANA0
#define ASYSCTL_INTOSC2CSR_MEASPTATLO  0x8U         // Measure voltage PTAT_LO at
                                               // TESTANA0
#define ASYSCTL_INTOSC2CSR_MEASZTCRTOP  0x10U        // Measure ZTCR top node for
                                               // ZCTR characterization at TESTANA0
#define ASYSCTL_INTOSC2CSR_MEASZTCRGND  0x20U        // Measure ZTCR GND node for
                                               // ZCTR characterization at TESTANA0
#define ASYSCTL_INTOSC2CSR_IREFTRIM  0x40U        // Bring out current from BG for
                                               // IREFTRIM to TESTANA1
#define ASYSCTL_INTOSC2CSR_TMBGSTARTUP  0x80U        // Bandgap testmode
#define ASYSCTL_INTOSC2CSR_EXTVREF  0x100U       // Use external reference at
                                               // TESTANA0
#define ASYSCTL_INTOSC2CSR_EXTIREF  0x200U       // Use external current through
                                               // TESTANA1
#define ASYSCTL_INTOSC2CSR_SPARE10  0x400U       // Spare10
#define ASYSCTL_INTOSC2CSR_SPARE11  0x800U       // Spare11

//*****************************************************************************
//
// The following are defines for the bit fields in the TSNSCFG register
//
//*****************************************************************************
#define ASYSCTL_TSNSCFG_BGINP     0x1U         // BGINP or buffer1 input sense
                                               // on testana0
#define ASYSCTL_TSNSCFG_BGINM     0x2U         // BGINM or buffer2 input sense
                                               // on testana1
#define ASYSCTL_TSNSCFG_VBUF1     0x4U         // buffer1 output sense on
                                               // testana0
#define ASYSCTL_TSNSCFG_VBUF2     0x8U         // buffer2 output sense on
                                               // testana1
#define ASYSCTL_TSNSCFG_TSOUT     0x10U        // Tempsensor output sense on
                                               // testana0
#define ASYSCTL_TSNSCFG_BGINMFLT  0x20U        // sense for BGINM or buffer2 
                                               // input after filter on testana1
#define ASYSCTL_TSNSCFG_BGINPFLT  0x40U        // sense for BGINP or buffer1
                                               // input after filter on testana0
#define ASYSCTL_TSNSCFG_SPARE15_7_S  7U
#define ASYSCTL_TSNSCFG_SPARE15_7_M  0xFF80U      // spare15_7

//*****************************************************************************
//
// The following are defines for the bit fields in the OSCREFTRIM register
//
//*****************************************************************************
#define ASYSCTL_OSCREFTRIM_BGVALTRIM_S  0U
#define ASYSCTL_OSCREFTRIM_BGVALTRIM_M  0x3FU        // Bandgap Value Trim
#define ASYSCTL_OSCREFTRIM_BGSLOPETRIM_S  6U
#define ASYSCTL_OSCREFTRIM_BGSLOPETRIM_M  0x7C0U       // Bandgap Slope Trim
#define ASYSCTL_OSCREFTRIM_IREFTRIM_S  11U
#define ASYSCTL_OSCREFTRIM_IREFTRIM_M  0xF800U      // Reference Current Trim
#define ASYSCTL_OSCREFTRIM_COARSETRIM_S  16U
#define ASYSCTL_OSCREFTRIM_COARSETRIM_M  0x3FF0000U   // Coarse Frequency Trim

//*****************************************************************************
//
// The following are defines for the bit fields in the ANAREFTRIMA register
//
//*****************************************************************************
#define ASYSCTL_ANAREFTRIMA_BGVALTRIM_S  0U
#define ASYSCTL_ANAREFTRIMA_BGVALTRIM_M  0x3FU        // Bandgap Value Trim
#define ASYSCTL_ANAREFTRIMA_BGSLOPETRIM_S  6U
#define ASYSCTL_ANAREFTRIMA_BGSLOPETRIM_M  0x7C0U       // Bandgap Slope Trim
#define ASYSCTL_ANAREFTRIMA_IREFTRIM_S  11U
#define ASYSCTL_ANAREFTRIMA_IREFTRIM_M  0xF800U      // Reference Current Trim
#define ASYSCTL_ANAREFTRIMA_CONFIG_S  16U
#define ASYSCTL_ANAREFTRIMA_CONFIG_M  0xFF0000U    // Configuration Bits

//*****************************************************************************
//
// The following are defines for the bit fields in the ANAREFTRIMB register
//
//*****************************************************************************
#define ASYSCTL_ANAREFTRIMB_BGVALTRIM_S  0U
#define ASYSCTL_ANAREFTRIMB_BGVALTRIM_M  0x3FU        // Bandgap Value Trim
#define ASYSCTL_ANAREFTRIMB_BGSLOPETRIM_S  6U
#define ASYSCTL_ANAREFTRIMB_BGSLOPETRIM_M  0x7C0U       // Bandgap Slope Trim
#define ASYSCTL_ANAREFTRIMB_IREFTRIM_S  11U
#define ASYSCTL_ANAREFTRIMB_IREFTRIM_M  0xF800U      // Reference Current Trim
#define ASYSCTL_ANAREFTRIMB_CONFIG_S  16U
#define ASYSCTL_ANAREFTRIMB_CONFIG_M  0xFF0000U    // Configuration Bits

//*****************************************************************************
//
// The following are defines for the bit fields in the ANAREFTRIMC register
//
//*****************************************************************************
#define ASYSCTL_ANAREFTRIMC_BGVALTRIM_S  0U
#define ASYSCTL_ANAREFTRIMC_BGVALTRIM_M  0x3FU        // Bandgap Value Trim
#define ASYSCTL_ANAREFTRIMC_BGSLOPETRIM_S  6U
#define ASYSCTL_ANAREFTRIMC_BGSLOPETRIM_M  0x7C0U       // Bandgap Slope Trim
#define ASYSCTL_ANAREFTRIMC_IREFTRIM_S  11U
#define ASYSCTL_ANAREFTRIMC_IREFTRIM_M  0xF800U      // Reference Current Trim
#define ASYSCTL_ANAREFTRIMC_CONFIG_S  16U
#define ASYSCTL_ANAREFTRIMC_CONFIG_M  0xFF0000U    // Configuration Bits

//*****************************************************************************
//
// The following are defines for the bit fields in the ANAREFTRIMD register
//
//*****************************************************************************
#define ASYSCTL_ANAREFTRIMD_BGVALTRIM_S  0U
#define ASYSCTL_ANAREFTRIMD_BGVALTRIM_M  0x3FU        // Bandgap Value Trim
#define ASYSCTL_ANAREFTRIMD_BGSLOPETRIM_S  6U
#define ASYSCTL_ANAREFTRIMD_BGSLOPETRIM_M  0x7C0U       // Bandgap Slope Trim
#define ASYSCTL_ANAREFTRIMD_IREFTRIM_S  11U
#define ASYSCTL_ANAREFTRIMD_IREFTRIM_M  0xF800U      // Reference Current Trim
#define ASYSCTL_ANAREFTRIMD_CONFIG_S  16U
#define ASYSCTL_ANAREFTRIMD_CONFIG_M  0xFF0000U    // Configuration Bits

//*****************************************************************************
//
// The following are defines for the bit fields in the PMMREFTRIM register
//
//*****************************************************************************
#define ASYSCTL_PMMREFTRIM_BGVALTRIM_S  0U
#define ASYSCTL_PMMREFTRIM_BGVALTRIM_M  0x3FU        // Bandgap Value Trim
#define ASYSCTL_PMMREFTRIM_BGSLOPETRIM_S  6U
#define ASYSCTL_PMMREFTRIM_BGSLOPETRIM_M  0x7C0U       // Bandgap Slope Trim
#define ASYSCTL_PMMREFTRIM_IREFTRIM_S  11U
#define ASYSCTL_PMMREFTRIM_IREFTRIM_M  0xF800U      // Reference Current Trim

//*****************************************************************************
//
// The following are defines for the bit fields in the PMMVREGTRIM register
//
//*****************************************************************************
#define ASYSCTL_PMMVREGTRIM_VREGTRIM_S  0U
#define ASYSCTL_PMMVREGTRIM_VREGTRIM_M  0xFFU        // Core VDD Voltage Regulator
                                               // Trim
#define ASYSCTL_PMMVREGTRIM_VSINKTRIM_S  16U
#define ASYSCTL_PMMVREGTRIM_VSINKTRIM_M  0xF0000U     // Voltage Sink Regulator Trim

//*****************************************************************************
//
// The following are defines for the bit fields in the PMMVMONTRIM register
//
//*****************************************************************************
#define ASYSCTL_PMMVMONTRIM_VDDIOMONTRIM_S  0U
#define ASYSCTL_PMMVMONTRIM_VDDIOMONTRIM_M  0xFU         // VDDIO 3.3V Monitor Trim
#define ASYSCTL_PMMVMONTRIM_VDDMONTRIM_S  4U
#define ASYSCTL_PMMVMONTRIM_VDDMONTRIM_M  0xF0U        // VDD 1.2V Monitor Trim
#define ASYSCTL_PMMVMONTRIM_VDD2MONTRIM_S  8U
#define ASYSCTL_PMMVMONTRIM_VDD2MONTRIM_M  0xF00U       // VDD2 1.8V Monitor Trim
#define ASYSCTL_PMMVMONTRIM_VDDOVFMONTRIM_S  12U
#define ASYSCTL_PMMVMONTRIM_VDDOVFMONTRIM_M  0xF000U      // VDD 1.2V Overvoltage Monitor
                                               // Trim

//*****************************************************************************
//
// The following are defines for the bit fields in the PMMCSR register
//
//*****************************************************************************
#define ASYSCTL_PMMCSR_PDNREFSYS  0x1U         // REFSYS can be power downed by
                                               // making this bit HIGH
#define ASYSCTL_PMMCSR_SPARE1     0x2U         // Spare1
#define ASYSCTL_PMMCSR_ENCHOPPER  0x4U         // When set High enables the
                                               // chopping for Band gap reference
#define ASYSCTL_PMMCSR_SELCHOPPERPHASE  0x8U         // Chopper Switches
                                               // Configuration Bit
#define ASYSCTL_PMMCSR_VREFEXT    0x10U        // External VREF option. Provide
                                               // external 0.7V on TESTANA0
#define ASYSCTL_PMMCSR_VREF0P7    0x20U        // Trim bit
#define ASYSCTL_PMMCSR_VREF1P2    0x40U        // Debug mode
#define ASYSCTL_PMMCSR_VDDSENSE   0x80U        // VREG Output for Measurement
#define ASYSCTL_PMMCSR_BGUP       0x100U       // Band gap up signal is brought
                                               // out through anamux on
                                               // TESTANA0
#define ASYSCTL_PMMCSR_VDD1P8VSENSE  0x200U       // VREG2 Output for Measurement
#define ASYSCTL_PMMCSR_IREFEXT    0x400U       // External IREF option to be
                                               // provided on TESTANA1
#define ASYSCTL_PMMCSR_IREFTRIM   0x800U       // Internal 40uA IREF line
                                               // brought out for trimming on
                                               // TESTANA1
#define ASYSCTL_PMMCSR_SPARE12    0x1000U      // Spare12
#define ASYSCTL_PMMCSR_SPARE13    0x2000U      // Spare13
#define ASYSCTL_PMMCSR_SPARE14    0x4000U      // Spare14
#define ASYSCTL_PMMCSR_XRS        0x8000U      // When High PMMLC goes to
                                               // default TRIM and PROG configuration
#define ASYSCTL_PMMCSR_DISMASK    0x10000U     // Masking can be disabled by
                                               // setting this bit HIGH
#define ASYSCTL_PMMCSR_DISVREGINRUSH  0x20000U     // Disable mode for internal
                                               // current limit of VREG
#define ASYSCTL_PMMCSR_VREGIBIASPROG_S  18U
#define ASYSCTL_PMMCSR_VREGIBIASPROG_M  0xC0000U     // Programmability bits to
                                               // control the bias current of VREG
#define ASYSCTL_PMMCSR_VREGINRUSHPROG_S  20U
#define ASYSCTL_PMMCSR_VREGINRUSHPROG_M  0x300000U    // Inrush current limit of VREG
                                               // control
#define ASYSCTL_PMMCSR_VREGCUTAMPGAIN  0x400000U    // Programmability to control
                                               // the gain of the VREG amp
#define ASYSCTL_PMMCSR_VSINKFILTPROG  0x800000U    // Filter cut-off frequency
                                               // control
#define ASYSCTL_PMMCSR_VREGADDCAP  0x1000000U   // Programmability to control
                                               // the compensation cap in VREG
#define ASYSCTL_PMMCSR_STATUSMUXSEL_S  25U
#define ASYSCTL_PMMCSR_STATUSMUXSEL_M  0x6000000U   // Select lines for internal mux
                                               // on PMMSTATUS lines
#define ASYSCTL_PMMCSR_CONTCLK    0x8000000U   // The internal clock is always
                                               // running, when this bit is HIGH
#define ASYSCTL_PMMCSR_PMMSTATUS_S  28U
#define ASYSCTL_PMMCSR_PMMSTATUS_M  0xF0000000U  // Status bits from the PMM

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSAPLLCONFIG1 register
//
//*****************************************************************************
#define ASYSCTL_SYSAPLLCONFIG1_CP_CTRL_S  0U
#define ASYSCTL_SYSAPLLCONFIG1_CP_CTRL_M  0xFU         // Charge Pump Control
#define ASYSCTL_SYSAPLLCONFIG1_PFD_CLR  0x10U        // To open the feedback loop
#define ASYSCTL_SYSAPLLCONFIG1_HI_BW  0x20U        // Increases the Chargepump
                                               // current by 60%
#define ASYSCTL_SYSAPLLCONFIG1_CP_DAC_S  6U
#define ASYSCTL_SYSAPLLCONFIG1_CP_DAC_M  0x3C0U       // CP DAC
#define ASYSCTL_SYSAPLLCONFIG1_C1_DAC_S  10U
#define ASYSCTL_SYSAPLLCONFIG1_C1_DAC_M  0x7C00U      // Cap DAC (Zero Capacitor)
#define ASYSCTL_SYSAPLLCONFIG1_OSC_SEL  0x8000U      // Source of clock for loop
                                               // bandwidth calculation

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSAPLLCONFIG2 register
//
//*****************************************************************************
#define ASYSCTL_SYSAPLLCONFIG2_PU_DEL_SEL_S  0U
#define ASYSCTL_SYSAPLLCONFIG2_PU_DEL_SEL_M  0x3U         // Cold power up delay counter
                                               // for Mdiv_ack
#define ASYSCTL_SYSAPLLCONFIG2_RES_TRIM_S  2U
#define ASYSCTL_SYSAPLLCONFIG2_RES_TRIM_M  0x1CU        // Resistor Trim code generated
                                               // from R-unit
#define ASYSCTL_SYSAPLLCONFIG2_INT_N_EXT  0x20U        // Internal LBW state machine or
                                               // ext control
#define ASYSCTL_SYSAPLLCONFIG2_DIS_OUTPUT  0x40U        // Disables the output clock
#define ASYSCTL_SYSAPLLCONFIG2_PWDN_MDIV  0x80U        // Turns-off feedback divider
#define ASYSCTL_SYSAPLLCONFIG2_DLY_CTRL_S  8U
#define ASYSCTL_SYSAPLLCONFIG2_DLY_CTRL_M  0x300U       // Controls ref_clock delay
#define ASYSCTL_SYSAPLLCONFIG2_GM_RES_TRIM_S  10U
#define ASYSCTL_SYSAPLLCONFIG2_GM_RES_TRIM_M  0x1C00U      // detailed config in other doc
#define ASYSCTL_SYSAPLLCONFIG2_SPARE  0x2000U      // Spare bit
#define ASYSCTL_SYSAPLLCONFIG2_LPF_C_CTRL  0x4000U      // 0=default,1= 1pF less
#define ASYSCTL_SYSAPLLCONFIG2_VCO_RANGE_TEST  0x8000U      // Enables control of all bits
                                               // of MDIV, REFDIV and ODIV.

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSAPLLCONFIG3 register
//
//*****************************************************************************
#define ASYSCTL_SYSAPLLCONFIG3_LIMP_CTRL_S  0U
#define ASYSCTL_SYSAPLLCONFIG3_LIMP_CTRL_M  0xFU         // config limp mode frequency
#define ASYSCTL_SYSAPLLCONFIG3_LOCK_IND_CLR  0x10U        // 0=on, 1=off
#define ASYSCTL_SYSAPLLCONFIG3_LOCK_IND_CTRL_S  5U
#define ASYSCTL_SYSAPLLCONFIG3_LOCK_IND_CTRL_M  0x1E0U       // 1:0 for sensitivity, 3:2 for
                                               // counter time
#define ASYSCTL_SYSAPLLCONFIG3_OSC_FORCE_ON  0x200U       // Force on internal osc for
                                               // trim
#define ASYSCTL_SYSAPLLCONFIG3_VCO_DAC_EXT_SEL  0x800U       // 0=auto, 1=manual code
#define ASYSCTL_SYSAPLLCONFIG3_VCO_DAC_EXT_S  12U
#define ASYSCTL_SYSAPLLCONFIG3_VCO_DAC_EXT_M  0x7000U      // manual VCO DAC code
#define ASYSCTL_SYSAPLLCONFIG3_SPARE  0x8000U      // Spare

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSAPLLCONFIG4 register
//
//*****************************************************************************
#define ASYSCTL_SYSAPLLCONFIG4_LOCK_FILTER_COUNT_S  0U
#define ASYSCTL_SYSAPLLCONFIG4_LOCK_FILTER_COUNT_M  0x3FU        // define how many cycles of no
                                               // updn_div2 flip before flag
                                               // lock
#define ASYSCTL_SYSAPLLCONFIG4_SLIP_FILTER_BASE_S  6U
#define ASYSCTL_SYSAPLLCONFIG4_SLIP_FILTER_BASE_M  0xFC0U       // Define out of how many cycles
                                               // we can define slip
#define ASYSCTL_SYSAPLLCONFIG4_LDO_LOAD_ALWAYSON_S  12U
#define ASYSCTL_SYSAPLLCONFIG4_LDO_LOAD_ALWAYSON_M  0x3000U      // 1=intentional load always on
                                               // to improve stability
#define ASYSCTL_SYSAPLLCONFIG4_LDO_OK_FORCE_H_S  14U
#define ASYSCTL_SYSAPLLCONFIG4_LDO_OK_FORCE_H_M  0xC000U      // To force LDO_OK signal=1

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSAPLLCONFIG5 register
//
//*****************************************************************************
#define ASYSCTL_SYSAPLLCONFIG5_LOCK_IND_IP_DIS  0x1U         // Externally shut down dig part
                                               // of lock_ind
#define ASYSCTL_SYSAPLLCONFIG5_LOCK_IND_SLIP_QUALITY_S  1U
#define ASYSCTL_SYSAPLLCONFIG5_LOCK_IND_SLIP_QUALITY_M  0x7EU        // Define cycles of updn_div2
                                               // flip before flag slip
#define ASYSCTL_SYSAPLLCONFIG5_SPARE_S  7U
#define ASYSCTL_SYSAPLLCONFIG5_SPARE_M  0x780U       // Spare
#define ASYSCTL_SYSAPLLCONFIG5_OBS_MUX_SEL_S  11U
#define ASYSCTL_SYSAPLLCONFIG5_OBS_MUX_SEL_M  0x1800U      // Observation mux select
//#define ASYSCTL_SYSAPLLCONFIG5_SPARE_S  13U
//#define ASYSCTL_SYSAPLLCONFIG5_SPARE_M  0xE000U      // Spare

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSAPLLCONFIG7 register
//
//*****************************************************************************
#define ASYSCTL_SYSAPLLCONFIG7_SEL_UPDN_BY2  0x1U         // Sel UPDN_DIV2 from CLK_AUX
#define ASYSCTL_SYSAPLLCONFIG7_ANA_TEST_MUX_SEL_S  1U
#define ASYSCTL_SYSAPLLCONFIG7_ANA_TEST_MUX_SEL_M  0x6U         // Analog test Mux select
#define ASYSCTL_SYSAPLLCONFIG7_CLK_AUX_EN  0x8U         // Enable CLKAUX
#define ASYSCTL_SYSAPLLCONFIG7_CLK_AUX_DIV_S  4U
#define ASYSCTL_SYSAPLLCONFIG7_CLK_AUX_DIV_M  0xF0U        // 4 bit Q-divider for CLKAUX
#define ASYSCTL_SYSAPLLCONFIG7_CLK_AUX_MUX_SEL_S  8U
#define ASYSCTL_SYSAPLLCONFIG7_CLK_AUX_MUX_SEL_M  0x300U       // CLKAUX MuxSelect
#define ASYSCTL_SYSAPLLCONFIG7_BIAS_SEL  0x400U       // Bias current Select
#define ASYSCTL_SYSAPLLCONFIG7_CP_VCO_TEST_S  11U
#define ASYSCTL_SYSAPLLCONFIG7_CP_VCO_TEST_M  0x1800U      // DFT LDO Enable
#define ASYSCTL_SYSAPLLCONFIG7_VCO_FREERUN  0x2000U      // Free running VCO mode
#define ASYSCTL_SYSAPLLCONFIG7_EN_ATB_BUF  0x4000U      // Enable ATB BUF
#define ASYSCTL_SYSAPLLCONFIG7_EN_ATB_UNBUF  0x8000U      // Enable ATB UNBUF

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSAPLLCONFIG8 register
//
//*****************************************************************************
#define ASYSCTL_SYSAPLLCONFIG8_DFT_LDO_EN_S  0U
#define ASYSCTL_SYSAPLLCONFIG8_DFT_LDO_EN_M  0x3U         // DFT LDO Enable
#define ASYSCTL_SYSAPLLCONFIG8_LDO_CONFIG_S  2U
#define ASYSCTL_SYSAPLLCONFIG8_LDO_CONFIG_M  0xFCU        // LDO Config bits

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSAPLLCONFIG9 register
//
//*****************************************************************************
#define ASYSCTL_SYSAPLLCONFIG9_APLL_LOCK_FILTER_S  0U
#define ASYSCTL_SYSAPLLCONFIG9_APLL_LOCK_FILTER_M  0x1FU        // APLL_LOCK_FILTER Value
#define ASYSCTL_SYSAPLLCONFIG9_APLL_LOCK_SLIP_FILTER_S  5U
#define ASYSCTL_SYSAPLLCONFIG9_APLL_LOCK_SLIP_FILTER_M  0x3E0U       // APLL_LOCK_SLIP_FILTER Value
#define ASYSCTL_SYSAPLLCONFIG9_SUMMARY_LOCK_CNTR_VALUE_S  10U
#define ASYSCTL_SYSAPLLCONFIG9_SUMMARY_LOCK_CNTR_VALUE_M  0xC00U       // SUMMARY_LOCK_CNTR_VALUE Value

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSAPLLCONFIG10 register
//
//*****************************************************************************
#define ASYSCTL_SYSAPLLCONFIG10_LDO_LO_COMP_EN  0x1U         // LDO_LO_COMP_EN Value
#define ASYSCTL_SYSAPLLCONFIG10_APLL_LOCK_MASK  0x2U         // APLL_LOCK_MASK Value
#define ASYSCTL_SYSAPLLCONFIG10_SUMMARY_LOCK_MASK  0x4U         // SUMMARY_LOCK_MASK Value
#define ASYSCTL_SYSAPLLCONFIG10_SLIP_UNMASK  0x8U         // SLIP_UNMASK Value
#define ASYSCTL_SYSAPLLCONFIG10_PLLEN_UNMASK  0x10U        // PLLEN_UNMASK Value

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSAPLLDIGSTATUS1 register
//
//*****************************************************************************
#define ASYSCTL_SYSAPLLDIGSTATUS1_CP_STATUS_S  0U
#define ASYSCTL_SYSAPLLDIGSTATUS1_CP_STATUS_M  0xFU         // Charge-pump control loop
                                               // value
#define ASYSCTL_SYSAPLLDIGSTATUS1_CAP_STATUS_S  4U
#define ASYSCTL_SYSAPLLDIGSTATUS1_CAP_STATUS_M  0x1F0U       // Capacitor control loop value
#define ASYSCTL_SYSAPLLDIGSTATUS1_OSC_STATUS_S  9U
#define ASYSCTL_SYSAPLLDIGSTATUS1_OSC_STATUS_M  0x600U       // Internal oscillator current
                                               // value
#define ASYSCTL_SYSAPLLDIGSTATUS1_INT_CLRZ  0x800U       // Internal digital CLRz signal
#define ASYSCTL_SYSAPLLDIGSTATUS1_SSC_ACK  0x1000U      // SSC ACK
#define ASYSCTL_SYSAPLLDIGSTATUS1_Q_DIV_UPDATE_REQ_R  0x2000U      // Q_div_update_req_r
#define ASYSCTL_SYSAPLLDIGSTATUS1_SPARE_S  14U
#define ASYSCTL_SYSAPLLDIGSTATUS1_SPARE_M  0xC000U      // Spare
#define ASYSCTL_SYSAPLLDIGSTATUS1_LOCK_IND_DEBUG_S  16U
#define ASYSCTL_SYSAPLLDIGSTATUS1_LOCK_IND_DEBUG_M  0xFF0000U    // Lock_ind_debug
#define ASYSCTL_SYSAPLLDIGSTATUS1_SPARE_BITS_S  24U
#define ASYSCTL_SYSAPLLDIGSTATUS1_SPARE_BITS_M  0xFF000000U  // Spare Bits

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSAPLLDIGSTATUS2 register
//
//*****************************************************************************
#define ASYSCTL_SYSAPLLDIGSTATUS2_LOCK_TIME_ACC_S  0U
#define ASYSCTL_SYSAPLLDIGSTATUS2_LOCK_TIME_ACC_M  0xFFFFU      // Lock time accumulator
#define ASYSCTL_SYSAPLLDIGSTATUS2_SLIP_INCIDENCE_CNT_S  16U
#define ASYSCTL_SYSAPLLDIGSTATUS2_SLIP_INCIDENCE_CNT_M  0xFF0000U    // Slip count

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSAPLLDIGSTATUS3 register
//
//*****************************************************************************
#define ASYSCTL_SYSAPLLDIGSTATUS3_LDO_OK_S  0U
#define ASYSCTL_SYSAPLLDIGSTATUS3_LDO_OK_M  0x7U         // LDO_OK Status
#define ASYSCTL_SYSAPLLDIGSTATUS3_LDO_LO_S  3U
#define ASYSCTL_SYSAPLLDIGSTATUS3_LDO_LO_M  0x38U        // LDO_LO Status
#define ASYSCTL_SYSAPLLDIGSTATUS3_LBW_CAL_RDY  0x40U        // LBW_CAL_RDY Status
#define ASYSCTL_SYSAPLLDIGSTATUS3_APLL_LOCK_RAW  0x80U        // APLL_LOCK_RAW Status
#define ASYSCTL_SYSAPLLDIGSTATUS3_APLL_LOCK_QUAL  0x100U       // APLL_LOCK_QUAL Status
#define ASYSCTL_SYSAPLLDIGSTATUS3_APLL_LOCK_SUMMARY  0x200U       // APLL_LOCK_SUMMARY Status

//*****************************************************************************
//
// The following are defines for the bit fields in the AUXAPLLCONFIG1 register
//
//*****************************************************************************
#define ASYSCTL_AUXAPLLCONFIG1_CP_CTRL_S  0U
#define ASYSCTL_AUXAPLLCONFIG1_CP_CTRL_M  0xFU         // Charge Pump Control
#define ASYSCTL_AUXAPLLCONFIG1_PFD_CLR  0x10U        // To open the feedback loop
#define ASYSCTL_AUXAPLLCONFIG1_HI_BW  0x20U        // Increases the Chargepump
                                               // current by 60%
#define ASYSCTL_AUXAPLLCONFIG1_CP_DAC_S  6U
#define ASYSCTL_AUXAPLLCONFIG1_CP_DAC_M  0x3C0U       // CP DAC
#define ASYSCTL_AUXAPLLCONFIG1_C1_DAC_S  10U
#define ASYSCTL_AUXAPLLCONFIG1_C1_DAC_M  0x7C00U      // Cap DAC (Zero Capacitor)
#define ASYSCTL_AUXAPLLCONFIG1_OSC_SEL  0x8000U      // Source of clock for loop
                                               // bandwidth calculation

//*****************************************************************************
//
// The following are defines for the bit fields in the AUXAPLLCONFIG2 register
//
//*****************************************************************************
#define ASYSCTL_AUXAPLLCONFIG2_PU_DEL_SEL_S  0U
#define ASYSCTL_AUXAPLLCONFIG2_PU_DEL_SEL_M  0x3U         // Cold power up delay counter
                                               // for Mdiv_ack
#define ASYSCTL_AUXAPLLCONFIG2_RES_TRIM_S  2U
#define ASYSCTL_AUXAPLLCONFIG2_RES_TRIM_M  0x1CU        // Resistor Trim code generated
                                               // from R-unit
#define ASYSCTL_AUXAPLLCONFIG2_INT_N_EXT  0x20U        // Internal LBW state machine or
                                               // ext control
#define ASYSCTL_AUXAPLLCONFIG2_DIS_OUTPUT  0x40U        // Disables the output clock
#define ASYSCTL_AUXAPLLCONFIG2_PWDN_MDIV  0x80U        // Turns-off feedback divider
#define ASYSCTL_AUXAPLLCONFIG2_DLY_CTRL_S  8U
#define ASYSCTL_AUXAPLLCONFIG2_DLY_CTRL_M  0x300U       // Controls ref_clock delay
#define ASYSCTL_AUXAPLLCONFIG2_GM_RES_TRIM_S  10U
#define ASYSCTL_AUXAPLLCONFIG2_GM_RES_TRIM_M  0x1C00U      // detailed config in other doc
#define ASYSCTL_AUXAPLLCONFIG2_SPARE  0x2000U      // Spare bit
#define ASYSCTL_AUXAPLLCONFIG2_LPF_C_CTRL  0x4000U      // 0=default,1= 1pF less
#define ASYSCTL_AUXAPLLCONFIG2_VCO_RANGE_TEST  0x8000U      // Enables control of all bits
                                               // of MDIV, REFDIV and ODIV.

//*****************************************************************************
//
// The following are defines for the bit fields in the AUXAPLLCONFIG3 register
//
//*****************************************************************************
#define ASYSCTL_AUXAPLLCONFIG3_LIMP_CTRL_S  0U
#define ASYSCTL_AUXAPLLCONFIG3_LIMP_CTRL_M  0xFU         // config limp mode frequency
#define ASYSCTL_AUXAPLLCONFIG3_LOCK_IND_CLR  0x10U        // 0=on, 1=off
#define ASYSCTL_AUXAPLLCONFIG3_LOCK_IND_CTRL_S  5U
#define ASYSCTL_AUXAPLLCONFIG3_LOCK_IND_CTRL_M  0x1E0U       // 1:0 for sensitivity, 3:2 for
                                               // counter time
#define ASYSCTL_AUXAPLLCONFIG3_OSC_FORCE_ON  0x200U       // Force on internal osc for
                                               // trim
#define ASYSCTL_AUXAPLLCONFIG3_VCO_DAC_EXT_SEL  0x800U       // 0=auto, 1=manual code
#define ASYSCTL_AUXAPLLCONFIG3_VCO_DAC_EXT_S  12U
#define ASYSCTL_AUXAPLLCONFIG3_VCO_DAC_EXT_M  0x7000U      // manual VCO DAC code
#define ASYSCTL_AUXAPLLCONFIG3_SPARE  0x8000U      // Spare

//*****************************************************************************
//
// The following are defines for the bit fields in the AUXAPLLCONFIG4 register
//
//*****************************************************************************
#define ASYSCTL_AUXAPLLCONFIG4_LOCK_FILTER_COUNT_S  0U
#define ASYSCTL_AUXAPLLCONFIG4_LOCK_FILTER_COUNT_M  0x3FU        // define how many cycles of no
                                               // updn_div2 flip before flag
                                               // lock
#define ASYSCTL_AUXAPLLCONFIG4_SLIP_FILTER_BASE_S  6U
#define ASYSCTL_AUXAPLLCONFIG4_SLIP_FILTER_BASE_M  0xFC0U       // Define out of how many cycles
                                               // we can define slip
#define ASYSCTL_AUXAPLLCONFIG4_LDO_LOAD_ALWAYSON_S  12U
#define ASYSCTL_AUXAPLLCONFIG4_LDO_LOAD_ALWAYSON_M  0x3000U      // 1=intentional load always on
                                               // to improve stability
#define ASYSCTL_AUXAPLLCONFIG4_LDO_OK_FORCE_H_S  14U
#define ASYSCTL_AUXAPLLCONFIG4_LDO_OK_FORCE_H_M  0xC000U      // To force LDO_OK signal=1

//*****************************************************************************
//
// The following are defines for the bit fields in the AUXAPLLCONFIG5 register
//
//*****************************************************************************
#define ASYSCTL_AUXAPLLCONFIG5_LOCK_IND_IP_DIS  0x1U         // Externally shut down dig part
                                               // of lock_ind
#define ASYSCTL_AUXAPLLCONFIG5_LOCK_IND_SLIP_QUALITY_S  1U
#define ASYSCTL_AUXAPLLCONFIG5_LOCK_IND_SLIP_QUALITY_M  0x7EU        // Define cycles of updn_div2
                                               // flip before flag slip
#define ASYSCTL_AUXAPLLCONFIG5_SPARE_S  7U
#define ASYSCTL_AUXAPLLCONFIG5_SPARE_M  0x780U       // Spare
#define ASYSCTL_AUXAPLLCONFIG5_OBS_MUX_SEL_S  11U
#define ASYSCTL_AUXAPLLCONFIG5_OBS_MUX_SEL_M  0x1800U      // Observation mux select
//#define ASYSCTL_AUXAPLLCONFIG5_SPARE_S  13U
//#define ASYSCTL_AUXAPLLCONFIG5_SPARE_M  0xE000U      // Spare

//*****************************************************************************
//
// The following are defines for the bit fields in the AUXAPLLCONFIG7 register
//
//*****************************************************************************
#define ASYSCTL_AUXAPLLCONFIG7_SEL_UPDN_BY2  0x1U         // Sel UPDN_DIV2 from CLK_AUX
#define ASYSCTL_AUXAPLLCONFIG7_ANA_TEST_MUX_SEL_S  1U
#define ASYSCTL_AUXAPLLCONFIG7_ANA_TEST_MUX_SEL_M  0x6U         // Analog test Mux select
#define ASYSCTL_AUXAPLLCONFIG7_CLK_AUX_EN  0x8U         // Enable CLKAUX
#define ASYSCTL_AUXAPLLCONFIG7_CLK_AUX_DIV_S  4U
#define ASYSCTL_AUXAPLLCONFIG7_CLK_AUX_DIV_M  0xF0U        // 4 bit Q-divider for CLKAUX
#define ASYSCTL_AUXAPLLCONFIG7_CLK_AUX_MUX_SEL_S  8U
#define ASYSCTL_AUXAPLLCONFIG7_CLK_AUX_MUX_SEL_M  0x300U       // CLKAUX MuxSelect
#define ASYSCTL_AUXAPLLCONFIG7_BIAS_SEL  0x400U       // Bias current Select
#define ASYSCTL_AUXAPLLCONFIG7_CP_VCO_TEST_S  11U
#define ASYSCTL_AUXAPLLCONFIG7_CP_VCO_TEST_M  0x1800U      // DFT LDO Enable
#define ASYSCTL_AUXAPLLCONFIG7_VCO_FREERUN  0x2000U      // Free running VCO mode
#define ASYSCTL_AUXAPLLCONFIG7_EN_ATB_BUF  0x4000U      // Enable ATB BUF
#define ASYSCTL_AUXAPLLCONFIG7_EN_ATB_UNBUF  0x8000U      // Enable ATB UNBUF

//*****************************************************************************
//
// The following are defines for the bit fields in the AUXAPLLCONFIG8 register
//
//*****************************************************************************
#define ASYSCTL_AUXAPLLCONFIG8_DFT_LDO_EN_S  0U
#define ASYSCTL_AUXAPLLCONFIG8_DFT_LDO_EN_M  0x3U         // DFT LDO Enable
#define ASYSCTL_AUXAPLLCONFIG8_LDO_CONFIG_S  2U
#define ASYSCTL_AUXAPLLCONFIG8_LDO_CONFIG_M  0xFCU        // LDO Config bits

//*****************************************************************************
//
// The following are defines for the bit fields in the AUXAPLLCONFIG9 register
//
//*****************************************************************************
#define ASYSCTL_AUXAPLLCONFIG9_APLL_LOCK_FILTER_S  0U
#define ASYSCTL_AUXAPLLCONFIG9_APLL_LOCK_FILTER_M  0x1FU        // APLL_LOCK_FILTER Value
#define ASYSCTL_AUXAPLLCONFIG9_APLL_LOCK_SLIP_FILTER_S  5U
#define ASYSCTL_AUXAPLLCONFIG9_APLL_LOCK_SLIP_FILTER_M  0x3E0U       // APLL_LOCK_SLIP_FILTER Value
#define ASYSCTL_AUXAPLLCONFIG9_SUMMARY_LOCK_CNTR_VALUE_S  10U
#define ASYSCTL_AUXAPLLCONFIG9_SUMMARY_LOCK_CNTR_VALUE_M  0xC00U       // SUMMARY_LOCK_CNTR_VALUE Value

//*****************************************************************************
//
// The following are defines for the bit fields in the AUXAPLLCONFIG10 register
//
//*****************************************************************************
#define ASYSCTL_AUXAPLLCONFIG10_LDO_LO_COMP_EN  0x1U         // LDO_LO_COMP_EN Value
#define ASYSCTL_AUXAPLLCONFIG10_APLL_LOCK_MASK  0x2U         // APLL_LOCK_MASK Value
#define ASYSCTL_AUXAPLLCONFIG10_SUMMARY_LOCK_MASK  0x4U         // SUMMARY_LOCK_MASK Value
#define ASYSCTL_AUXAPLLCONFIG10_SLIP_UNMASK  0x8U         // SLIP_UNMASK Value
#define ASYSCTL_AUXAPLLCONFIG10_PLLEN_UNMASK  0x10U        // PLLEN_UNMASK Value

//*****************************************************************************
//
// The following are defines for the bit fields in the AUXAPLLDIGSTATUS1 register
//
//*****************************************************************************
#define ASYSCTL_AUXAPLLDIGSTATUS1_CP_STATUS_S  0U
#define ASYSCTL_AUXAPLLDIGSTATUS1_CP_STATUS_M  0xFU         // Charge-pump control loop
                                               // value
#define ASYSCTL_AUXAPLLDIGSTATUS1_CAP_STATUS_S  4U
#define ASYSCTL_AUXAPLLDIGSTATUS1_CAP_STATUS_M  0x1F0U       // Capacitor control loop value
#define ASYSCTL_AUXAPLLDIGSTATUS1_OSC_STATUS_S  9U
#define ASYSCTL_AUXAPLLDIGSTATUS1_OSC_STATUS_M  0x600U       // Internal oscillator current
                                               // value
#define ASYSCTL_AUXAPLLDIGSTATUS1_INT_CLRZ  0x800U       // Internal digital CLRz signal
#define ASYSCTL_AUXAPLLDIGSTATUS1_SSC_ACK  0x1000U      // SSC ACK
#define ASYSCTL_AUXAPLLDIGSTATUS1_Q_DIV_UPDATE_REQ_R  0x2000U      // Q_div_update_req_r
#define ASYSCTL_AUXAPLLDIGSTATUS1_SPARE_S  14U
#define ASYSCTL_AUXAPLLDIGSTATUS1_SPARE_M  0xC000U      // Spare
#define ASYSCTL_AUXAPLLDIGSTATUS1_LOCK_IND_DEBUG_S  16U
#define ASYSCTL_AUXAPLLDIGSTATUS1_LOCK_IND_DEBUG_M  0xFF0000U    // Lock_ind_debug
#define ASYSCTL_AUXAPLLDIGSTATUS1_SPARE_BITS_S  24U
#define ASYSCTL_AUXAPLLDIGSTATUS1_SPARE_BITS_M  0xFF000000U  // Spare Bits

//*****************************************************************************
//
// The following are defines for the bit fields in the AUXAPLLDIGSTATUS2 register
//
//*****************************************************************************
#define ASYSCTL_AUXAPLLDIGSTATUS2_LOCK_TIME_ACC_S  0U
#define ASYSCTL_AUXAPLLDIGSTATUS2_LOCK_TIME_ACC_M  0xFFFFU      // Lock time accumulator
#define ASYSCTL_AUXAPLLDIGSTATUS2_SLIP_INCIDENCE_CNT_S  16U
#define ASYSCTL_AUXAPLLDIGSTATUS2_SLIP_INCIDENCE_CNT_M  0xFF0000U    // Slip count

//*****************************************************************************
//
// The following are defines for the bit fields in the AUXAPLLDIGSTATUS3 register
//
//*****************************************************************************
#define ASYSCTL_AUXAPLLDIGSTATUS3_LDO_OK_S  0U
#define ASYSCTL_AUXAPLLDIGSTATUS3_LDO_OK_M  0x7U         // LDO_OK Status
#define ASYSCTL_AUXAPLLDIGSTATUS3_LDO_LO_S  3U
#define ASYSCTL_AUXAPLLDIGSTATUS3_LDO_LO_M  0x38U        // LDO_LO Status
#define ASYSCTL_AUXAPLLDIGSTATUS3_LBW_CAL_RDY  0x40U        // LBW_CAL_RDY Status
#define ASYSCTL_AUXAPLLDIGSTATUS3_APLL_LOCK_RAW  0x80U        // APLL_LOCK_RAW Status
#define ASYSCTL_AUXAPLLDIGSTATUS3_APLL_LOCK_QUAL  0x100U       // APLL_LOCK_QUAL Status
#define ASYSCTL_AUXAPLLDIGSTATUS3_APLL_LOCK_SUMMARY  0x200U       // APLL_LOCK_SUMMARY Status

//*****************************************************************************
//
// The following are defines for the bit fields in the APLLREFTRIM register
//
//*****************************************************************************
#define ASYSCTL_APLLREFTRIM_BGVALTRIM_S  0U
#define ASYSCTL_APLLREFTRIM_BGVALTRIM_M  0x3FU        // Bandgap Value Trim
#define ASYSCTL_APLLREFTRIM_BGSLOPETRIM_S  6U
#define ASYSCTL_APLLREFTRIM_BGSLOPETRIM_M  0x7C0U       // Bandgap Slope Trim
#define ASYSCTL_APLLREFTRIM_IREFTRIM_S  11U
#define ASYSCTL_APLLREFTRIM_IREFTRIM_M  0xF800U      // Reference Current Trim

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSAPLLLDOTRIM register
//
//*****************************************************************************
#define ASYSCTL_SYSAPLLLDOTRIM_PROG_VDD_1P5V_S  0U
#define ASYSCTL_SYSAPLLLDOTRIM_PROG_VDD_1P5V_M  0xFU         // 1.5V LDO trim
#define ASYSCTL_SYSAPLLLDOTRIM_PROG_VDD_1P2V_S  4U
#define ASYSCTL_SYSAPLLLDOTRIM_PROG_VDD_1P2V_M  0xF0U        // 1.5V LDO trim

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSAPLLOSCTRIM register
//
//*****************************************************************************
#define ASYSCTL_SYSAPLLOSCTRIM_OSC_FREQ_S  0U
#define ASYSCTL_SYSAPLLOSCTRIM_OSC_FREQ_M  0x7U         // Internal oscillation
                                               // frequency options

//*****************************************************************************
//
// The following are defines for the bit fields in the AUXAPLLLDOTRIM register
//
//*****************************************************************************
#define ASYSCTL_AUXAPLLLDOTRIM_PROG_VDD_1P5V_S  0U
#define ASYSCTL_AUXAPLLLDOTRIM_PROG_VDD_1P5V_M  0xFU         // 1.5V LDO trim
#define ASYSCTL_AUXAPLLLDOTRIM_PROG_VDD_1P2V_S  4U
#define ASYSCTL_AUXAPLLLDOTRIM_PROG_VDD_1P2V_M  0xF0U        // 1.5V LDO trim

//*****************************************************************************
//
// The following are defines for the bit fields in the AUXAPLLOSCTRIM register
//
//*****************************************************************************
#define ASYSCTL_AUXAPLLOSCTRIM_OSC_FREQ_S  0U
#define ASYSCTL_AUXAPLLOSCTRIM_OSC_FREQ_M  0x7U         // Internal oscillation
                                               // frequency options

//*****************************************************************************
//
// The following are defines for the bit fields in the PLLSEL register
//
//*****************************************************************************
#define ASYSCTL_PLLSEL_SEL        0x1U         // Selects between APLL and
                                               // TCIPLL

//*****************************************************************************
//
// The following are defines for the bit fields in the APLLLOCK register
//
//*****************************************************************************
#define ASYSCTL_APLLLOCK_SYSAPLLCONFIG1  0x1U         // SYSAPLLCONFIG1 Register Lock
                                               // bit
#define ASYSCTL_APLLLOCK_SYSAPLLCONFIG2  0x2U         // SYSAPLLCONFIG2 Register Lock
                                               // bit
#define ASYSCTL_APLLLOCK_SYSAPLLCONFIG3  0x4U         // SYSAPLLCONFIG3 Register Lock
                                               // bit
#define ASYSCTL_APLLLOCK_SYSAPLLCONFIG4  0x8U         // SYSAPLLCONFIG4 Register Lock
                                               // bit
#define ASYSCTL_APLLLOCK_SYSAPLLCONFIG5  0x10U        // SYSAPLLCONFIG5 Register Lock
                                               // bit
#define ASYSCTL_APLLLOCK_SYSAPLLCONFIG6  0x20U        // SYSAPLLCONFIG6 Register Lock
                                               // bit
#define ASYSCTL_APLLLOCK_SYSAPLLCONFIG7  0x40U        // SYSAPLLCONFIG7 Register Lock
                                               // bit
#define ASYSCTL_APLLLOCK_SYSAPLLCONFIG8  0x80U        // SYSAPLLCONFIG8 Register Lock
                                               // bit
#define ASYSCTL_APLLLOCK_SYSAPLLCONFIG9  0x100U       // SYSAPLLCONFIG9 Register Lock
                                               // bit
#define ASYSCTL_APLLLOCK_SYSAPLLCONFIG10  0x200U       // SYSAPLLCONFIG10 Register Lock
                                               // bit
#define ASYSCTL_APLLLOCK_SYSAPLLLDOTRIM  0x400U       // SYSAPLLLDOTRIM Register Lock
                                               // bit
#define ASYSCTL_APLLLOCK_SYSAPLLOSCTRIM  0x800U       // SYSAPLLOSCTRIM Register Lock
                                               // bit
#define ASYSCTL_APLLLOCK_APLLREFTRIM  0x1000U      // APLLREFTRIM Register Lock bit
#define ASYSCTL_APLLLOCK_PLLSEL   0x2000U      // PLLSEL Register Lock bit
#define ASYSCTL_APLLLOCK_SYSAPLLSPAREIN  0x8000U      // SYSAPLLSPAREIN Register Lock
                                               // bit
#define ASYSCTL_APLLLOCK_AUXAPLLCONFIG1  0x10000U     // AUXAPLLCONFIG1 Register Lock
                                               // bit
#define ASYSCTL_APLLLOCK_AUXAPLLCONFIG2  0x20000U     // AUXAPLLCONFIG2 Register Lock
                                               // bit
#define ASYSCTL_APLLLOCK_AUXAPLLCONFIG3  0x40000U     // AUXAPLLCONFIG3 Register Lock
                                               // bit
#define ASYSCTL_APLLLOCK_AUXAPLLCONFIG4  0x80000U     // AUXAPLLCONFIG4 Register Lock
                                               // bit
#define ASYSCTL_APLLLOCK_AUXAPLLCONFIG5  0x100000U    // AUXAPLLCONFIG5 Register Lock
                                               // bit
#define ASYSCTL_APLLLOCK_AUXAPLLCONFIG6  0x200000U    // AUXAPLLCONFIG6 Register Lock
                                               // bit
#define ASYSCTL_APLLLOCK_AUXAPLLCONFIG7  0x400000U    // AUXAPLLCONFIG7 Register Lock
                                               // bit
#define ASYSCTL_APLLLOCK_AUXAPLLCONFIG8  0x800000U    // AUXAPLLCONFIG8 Register Lock
                                               // bit
#define ASYSCTL_APLLLOCK_AUXAPLLCONFIG9  0x1000000U   // AUXAPLLCONFIG9 Register Lock
                                               // bit
#define ASYSCTL_APLLLOCK_AUXAPLLCONFIG10  0x2000000U   // AUXAPLLCONFIG10 Register Lock
                                               // bit
#define ASYSCTL_APLLLOCK_AUXAPLLLDOTRIM  0x4000000U   // AUXAPLLLDOTRIM Register Lock
                                               // bit
#define ASYSCTL_APLLLOCK_AUXAPLLOSCTRIM  0x8000000U   // AUXAPLLOSCTRIM Register Lock
                                               // bit
#define ASYSCTL_APLLLOCK_APLLREFCONFIG  0x40000000U  // APLLREFCONFIG Register Lock
                                               // bit
#define ASYSCTL_APLLLOCK_AUXAPLLSPAREIN  0x80000000U  // AUXAPLLSPAREIN Register Lock
                                               // bit
#endif
