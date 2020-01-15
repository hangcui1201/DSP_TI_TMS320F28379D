//###########################################################################
//
// FILE:   sysctl.h
//
// TITLE:  C28x system control driver.
//
//###########################################################################
// $TI Release: $
// $Release Date: $
// $Copyright: $
//###########################################################################

#ifndef SYSCTL_H
#define SYSCTL_H

//*****************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
//*****************************************************************************
#ifdef __cplusplus
extern "C"
{
#endif

//*****************************************************************************
//
//! \addtogroup sysctl_api SysCtl
//! @{
//
//*****************************************************************************

#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "inc/hw_nmi.h"
#include "inc/hw_wwd.h"
#include "inc/hw_sysctl.h"
#include "inc/hw_types.h"
#include "cpu.h"
#include "debug.h"
#include "interrupt.h"

//*****************************************************************************
//
// Defines for system control functions. Not intended for use by application
// code.
//
//*****************************************************************************
// Shifted pattern for WDCR register's WDCHK field.
#define SYSCTL_WD_CHKBITS       0x0028U

// Keys for WDKEY field. The first enables resets and the second resets.
#define SYSCTL_WD_ENRSTKEY      0x0055U
#define SYSCTL_WD_RSTKEY        0x00AAU

// Values to help decode peripheral parameter
#define SYSCTL_PERIPH_REG_M     0x001FU
#define SYSCTL_PERIPH_REG_S     0x0000U
#define SYSCTL_PERIPH_BIT_M     0x1F00U
#define SYSCTL_PERIPH_BIT_S     0x0008U

//Keys for the System control registers write protection
#define SYSCTL_REG_KEY       0xA5A50000U
#define SYSCTL_CLK_KEY       0x56340000U
#define SYSCTL_PLL_KEY       0XCAFE0000U

//Values to help access shifting of bits
#define SYSCTL_CMCLKCTL_CMDIVSRCSEL_S   0x0U
#define SYSCTL_CMCLKCTL_ETHDIVSRCSEL_S  0X4U
#define SYSCTL_CLBCLKCTL_TILECLKDIV_S   0x4U
#define SYSCTL_SYSPLLCTL2_SSEN_S        0x0U
#define SYSCTL_SYSPLLCTL3_IAMT_S        0x1U
#define SYSCTL_TYPE_LOCK_S              0xFU

//Values to help access multiple register bits
#define SYSCTL_PLLTEST_ALL      (SYSCTL_PLLTEST_OVERRIDE_AUXPLL | \
                                 SYSCTL_PLLTEST_OVERRIDE)

//Enable / disable the ETHERCAT I2C Loopback
#define SYSCTL_ETHERCAT_I2C_LOOPBACK 0x1U

// LPM defines for LPMCR.LPM
#define SYSCTL_LPM_IDLE         0x0000U
#define SYSCTL_LPM_STANDBY      0x0001U
#define SYSCTL_LPM_HALT         0x0002U

//! Bit shift for DAC to configure the CPUSEL register
#define SYSCTL_CPUSEL_DAC_S     0x10U

// Default internal oscillator frequency, 10 MHz
#define SYSCTL_DEFAULT_OSC_FREQ     10000000U


// Boot ROM Booting and Reset Status
#define SYSCTL_BOOT_ROM_STATUS    0x0002U
#define SYSCTL_BOOT_ROM_POR       0x8000U
#define SYSCTL_BOOT_ROM_XRS       0x4000U

//*****************************************************************************
//
// The following are values that can be passed to the SysCtl_setClock() API as
// the config parameter.
//
//*****************************************************************************
//
// System clock divider (SYSDIV)
//
#define SYSCTL_SYSDIV_M     0x00001F80U // Mask for SYSDIV value in config
#define SYSCTL_SYSDIV_S     7U          // Shift for SYSDIV value in config
//! Macro to format system clock divider value. x must be 1 or even values up
//! to 126.
#define SYSCTL_SYSDIV(x)    ((((x) / 2U) << SYSCTL_SYSDIV_S) & SYSCTL_SYSDIV_M)

//
// Integer multiplier (IMULT)
//
#define SYSCTL_IMULT_M      0x0000007FU // Mask for IMULT value in config
#define SYSCTL_IMULT_S      0U          // Shift for IMULT value in config
//! Macro to format integer multiplier value. x is a number from 1 to 127.
//!
#define SYSCTL_IMULT(x)     (((x) << SYSCTL_IMULT_S) & SYSCTL_IMULT_M)

#ifndef DOXYGEN_PDF_IGNORE
//
// Fractional multiplier (FMULT)
//
#define SYSCTL_FMULT_M      0x00006000U // Mask for FMULT value in config
#define SYSCTL_FMULT_S      13U         // Shift for FMULT value in config
#define SYSCTL_FMULT_NONE   0x00000000U //!< No fractional multiplier
#define SYSCTL_FMULT_0      0x00000000U //!< No fractional multiplier
#define SYSCTL_FMULT_1_4    0x00002000U //!< Fractional multiplier of 0.25
#define SYSCTL_FMULT_1_2    0x00004000U //!< Fractional multiplier of 0.50
#define SYSCTL_FMULT_3_4    0x00006000U //!< Fractional multiplier of 0.75

//
// Oscillator source
//
// Also used with the SysCtl_selectOscSource(), SysCtl_turnOnOsc(),
// and SysCtl_turnOffOsc() functions as the oscSource parameter.
//
#define SYSCTL_OSCSRC_M         0x00030000U // Mask for OSCSRC value in config
#define SYSCTL_OSCSRC_S         16U         // Shift for OSCSRC value in config
//! Internal oscillator INTOSC2
#define SYSCTL_OSCSRC_OSC2      0x00000000U
//! External oscillator (XTAL) in crystal mode
#define SYSCTL_OSCSRC_XTAL      0x00010000U
//! External oscillator (XTAL) in single-ended mode
#define SYSCTL_OSCSRC_XTAL_SE   0x00030000U
//! Internal oscillator INTOSC1
#define SYSCTL_OSCSRC_OSC1      0x00020000U

//
// Enable/disable PLL
//
#define SYSCTL_PLL_ENABLE       0x80000000U //!< Enable PLL
#define SYSCTL_PLL_DISABLE      0x00000000U //!< Disable PLL

//
// Number of PLL retries for SW work around
//
#define SYSCTL_PLL_RETRIES              100U    // Number of PLL retries
#define SYSCTL_PLLLOCK_TIMEOUT          2000U   // PLL Lock timeout
#define SYSCTL_DCC_COUNTER0_WINDOW      100U    // DCC Counter0 Window

//*****************************************************************************
//
// The following are values that can be passed to the SysCtl_setAuxClock() API
// as the config parameter.
//
//*****************************************************************************
//
// Auxiliary clock divider (AUXCLKDIV)
//
#define SYSCTL_AUXPLL_DIV_1        0x00000000U //!< Auxiliary PLL divide by 1
#define SYSCTL_AUXPLL_DIV_2        0x00000080U //!< Auxiliary PLL divide by 2
#define SYSCTL_AUXPLL_DIV_4        0x00000100U //!< Auxiliary PLL divide by 4
#define SYSCTL_AUXPLL_DIV_8        0x00000180U //!< Auxiliary PLL divide by 8

//
// Integer multiplier (IMULT)
//
//! Macro to format integer multiplier value. x is a number from 1 to 127.
//!
#define SYSCTL_AUXPLL_IMULT(x)      SYSCTL_IMULT(x)

//
// Fractional multiplier (FMULT)
//
#define SYSCTL_AUXPLL_FMULT_NONE  0x00000000U //!< No fractional multiplier
#define SYSCTL_AUXPLL_FMULT_0     0x00000000U //!< No fractional multiplier
#define SYSCTL_AUXPLL_FMULT_1_4   0x00002000U //!< Fractional multiplier - 0.25
#define SYSCTL_AUXPLL_FMULT_1_2   0x00004000U //!< Fractional multiplier - 0.50
#define SYSCTL_AUXPLL_FMULT_3_4   0x00006000U //!< Fractional multiplier - 0.75

//
// Oscillator source
//
//! Internal oscillator INTOSC2 as auxiliary clock input
#define SYSCTL_AUXPLL_OSCSRC_OSC2       0x00000000U
//! External oscillator (XTAL) as auxiliary clock input
#define SYSCTL_AUXPLL_OSCSRC_XTAL       0x00010000U
//! AUXCLKIN (from GPIO) as auxiliary clock input
#define SYSCTL_AUXPLL_OSCSRC_AUXCLKIN   0x00020000U

//
// Enable/disable PLL
//
#define SYSCTL_AUXPLL_ENABLE    0x80000000U //!< Enable AUXPLL
#define SYSCTL_AUXPLL_DISABLE   0x00000000U //!< Disable AUXPLL

//*****************************************************************************
//
// Values that can be passed to SysCtl_selectSecMaster() as the
// periFrame1Config and periFrame2Config parameters.
//
//*****************************************************************************
//! Configure CLA as the secondary master
#define SYSCTL_SEC_MASTER_CLA                 0x0U
//! Configure DMA as the secondary master
#define SYSCTL_SEC_MASTER_DMA                 0x1U

//*****************************************************************************
//
// Values that can be passed to SysCtl_clearNMIStatus(),
// SysCtl_forceNMIFlags(), SysCtl_isNMIFlagSet(), and
// SysCtl_isNMIShadowFlagSet() as the nmiFlags parameter and returned by
// SysCtl_getNMIFlagStatus() and SysCtl_getNMIShadowFlagStatus().
//
//*****************************************************************************
#define SYSCTL_NMI_NMIINT           0x0001U //!< Non-maskable interrupt
#define SYSCTL_NMI_CLOCKFAIL        0x0002U //!< Clock Failure
#define SYSCTL_NMI_RAMUNCERR        0x0004U //!< Uncorrectable RAM error
#define SYSCTL_NMI_FLUNCERR         0x0008U //!< Uncorrectable Flash error
#define SYSCTL_NMI_CPU1HWBISTERR    0x0010U //!< HW BIST Error NMI Flag
#define SYSCTL_NMI_CPU2HWBISTERR    0x0020U //!<  HW BIST Error NMI Flag
#define SYSCTL_NMI_PIEVECTERR       0x0040U //!<  PIE Vector Fetch Error Flag
#define SYSCTL_NMI_ERADNMI          0x0080U //!<  ERAD Module NMI Flag
#define SYSCTL_NMI_CPU2WDRSN        0x0200U //!< CPU2 WDRSn Reset Indication 
#define SYSCTL_NMI_CPU2NMIWDRSN     0x0400U //!< CPU2 NMIWDRSn Reset Indication
#define SYSCTL_NMI_CMNMIWDRSN       0x1000U //!< CM NMI watch dog has timed out
#define SYSCTL_NMI_ECATNMI          0x2000U //!< NMI from EtherCAT reset out
#define SYSCTL_NMI_CRC_FAIL         0x4000U //!< CRC calculation fail flag
#define SYSCTL_NMI_MCAN_ERR         0x8000U //!< MCAN module generated an ECC

//*****************************************************************************
//
// Values that can be passed to SysCtl_enableCMtoCPUNMI() & 
// SysCtl_enableCMtoCPUInterrupt() as the Flags parameter 
//
//*****************************************************************************

#define SYSCTL_FLAG_CMNMIWDRST       0x0004U //!< CM NMIWD Reset Indication

//*****************************************************************************
//
// Values that can be passed to/returned from SysCtl_getCMInterruptStatus()
// SysCtl_clearCMInterruptStatus() or SysCtl_setCMInterruptStatus() 
// as the intFlags parameter 
//
//*****************************************************************************
#define SYSCTL_STATUS_CMGINT          0x0001U //!< CM Global interrupt
#define SYSCTL_STATUS_CMNMIWDRST      0x0002U //!< CM NMIWD Interrupt
#define SYSCTL_STATUS_CMSYSRESETREQ   0x0004U //!< CM System Reset Interrupt
#define SYSCTL_STATUS_CMVECTRESET     0x0008U //!< CM Vector Reset Interrupt

//*****************************************************************************
//
// Values that can be passed to/returned from SysCtl_getInterruptStatus()
// SysCtl_clearInterruptStatus() or SysCtl_setInterruptStatus() 
// as the intFlags parameter 
//
//*****************************************************************************
#define SYSCTL_STATUS_GINT                   0x0001U //!< Global Interrupt flag
#define SYSCTL_STATUS_EMIF_ERR               0x0002U //!< EMIF error
#define SYSCTL_STATUS_RAM_CORRECTABLE_ERR    0x0004U //!< RAM correctable error
#define SYSCTL_STATUS_FLASH_CORRECTABLE_ERR  0x0008U //!< FLASH correctable err
#define SYSCTL_STATUS_RAM_ACC_VIOL           0x0010U //!< RAM access violation
#define SYSCTL_STATUS_SYS_PLL_SLIP           0x0020U //!< System PLL Slip event
#define SYSCTL_STATUS_AUX_PLL_SLIP           0x0040U //!< Auxillary PLL Slip
#define SYSCTL_STATUS_DCC0                   0x0080U //!< DCC0 Interrupt flag
#define SYSCTL_STATUS_DCC1                   0x0100U //!< DCC1 Interrupt flag
#define SYSCTL_STATUS_DCC2                   0x0200U //!< DCC2 Interrupt flag

//*****************************************************************************
//
// Values that can be passed to/returned from SysCtl_controlCore() & 
// SysCtl_getCoreStatus() as the signal parameter 
//
//*****************************************************************************
#define SYSCTL_C28_VMAPS                    0x0001U //!< VMAPS output signal
#define SYSCTL_C28_MONPRIV                  0x0002U //!< MONPRIV input 
#define SYSCTL_C28_ENPROT                   0x0004U //!< W/R Block Protection 

//*****************************************************************************
//
// The following are values that can be passed to the SysCtl_clearResetCause()
// & SysCtl_simulateReset() 
// API as rstCauses or returned by the SysCtl_getResetCause() API.
//
//*****************************************************************************
#define SYSCTL_CAUSE_POR                 0x00000001U //!< Power-on reset
#define SYSCTL_CAUSE_XRS                 0x00000002U //!< External reset pin
#define SYSCTL_CAUSE_WDRS                0x00000004U //!< Watchdog reset
#define SYSCTL_CAUSE_NMIWDRS             0x00000008U //!< NMI watchdog reset
#define SYSCTL_CAUSE_SCCRESET            0x00000100U //!< SCCRESETn by DCSM
#define SYSCTL_CAUSE_HWBISTN             0x00000020U //!< HWBISTn Reset
#define SYSCTL_CAUSE_ECAT_RESET_OUT      0x00000200U //!< ECAT_RESET_OUT Reset 
#define SYSCTL_CAUSE_SIMRESET_CPU1RSN    0x00000400U //!< SIMRESET_CPU1 Reset
#define SYSCTL_CAUSE_SIMRESET_XRSN       0x00000800U //!< SIMRESET_XRSn Reset
#define SYSCTL_CAUSE_CPU1RSn             0x00000001U //!< CPU1Reset
//*****************************************************************************
//
// The following values define the adcsocSrc parameter for
// SysCtl_enableExtADCSOCSource() and SysCtl_disableExtADCSOCSource().
//
//*****************************************************************************
// ADCSOCAO
#define SYSCTL_ADCSOC_SRC_PWM1SOCA    0x00000001U //!< ePWM1 SOCA for ADCSOCAO
#define SYSCTL_ADCSOC_SRC_PWM2SOCA    0x00000002U //!< ePWM2 SOCA for ADCSOCAO
#define SYSCTL_ADCSOC_SRC_PWM3SOCA    0x00000004U //!< ePWM3 SOCA for ADCSOCAO
#define SYSCTL_ADCSOC_SRC_PWM4SOCA    0x00000008U //!< ePWM4 SOCA for ADCSOCAO
#define SYSCTL_ADCSOC_SRC_PWM5SOCA    0x00000010U //!< ePWM5 SOCA for ADCSOCAO
#define SYSCTL_ADCSOC_SRC_PWM6SOCA    0x00000020U //!< ePWM6 SOCA for ADCSOCAO
#define SYSCTL_ADCSOC_SRC_PWM7SOCA    0x00000040U //!< ePWM7 SOCA for ADCSOCAO
#define SYSCTL_ADCSOC_SRC_PWM8SOCA    0x00000080U //!< ePWM8 SOCA for ADCSOCAO
#define SYSCTL_ADCSOC_SRC_PWM9SOCA    0x00000100U //!< ePWM9 SOCA for ADCSOCAO
#define SYSCTL_ADCSOC_SRC_PWM10SOCA   0x00000200U //!< ePWM10 SOCA for ADCSOCAO
#define SYSCTL_ADCSOC_SRC_PWM11SOCA   0x00000400U //!< ePWM11 SOCA for ADCSOCAO
#define SYSCTL_ADCSOC_SRC_PWM12SOCA   0x00000800U //!< ePWM12 SOCA for ADCSOCAO
#define SYSCTL_ADCSOC_SRC_PWM13SOCA   0x00001000U //!< ePWM13 SOCA for ADCSOCAO
#define SYSCTL_ADCSOC_SRC_PWM14SOCA   0x00002000U //!< ePWM14 SOCA for ADCSOCAO
#define SYSCTL_ADCSOC_SRC_PWM15SOCA   0x00004000U //!< ePWM15 SOCA for ADCSOCAO
#define SYSCTL_ADCSOC_SRC_PWM16SOCA   0x00008000U //!< ePWM16 SOCA for ADCSOCAO

// ADCSOCBO
#define SYSCTL_ADCSOC_SRC_PWM1SOCB    0x00010000U //!< ePWM1 SOCB for ADCSOCBO
#define SYSCTL_ADCSOC_SRC_PWM2SOCB    0x00020000U //!< ePWM2 SOCB for ADCSOCBO
#define SYSCTL_ADCSOC_SRC_PWM3SOCB    0x00040000U //!< ePWM3 SOCB for ADCSOCBO
#define SYSCTL_ADCSOC_SRC_PWM4SOCB    0x00080000U //!< ePWM4 SOCB for ADCSOCBO
#define SYSCTL_ADCSOC_SRC_PWM5SOCB    0x00100000U //!< ePWM5 SOCB for ADCSOCBO
#define SYSCTL_ADCSOC_SRC_PWM6SOCB    0x00200000U //!< ePWM6 SOCB for ADCSOCBO
#define SYSCTL_ADCSOC_SRC_PWM7SOCB    0x00400000U //!< ePWM7 SOCB for ADCSOCBO
#define SYSCTL_ADCSOC_SRC_PWM8SOCB    0x00800000U //!< ePWM8 SOCB for ADCSOCBO
#define SYSCTL_ADCSOC_SRC_PWM9SOCB    0x01000000U //!< ePWM9 SOCB for ADCSOCBO
#define SYSCTL_ADCSOC_SRC_PWM10SOCB   0x02000000U //!< ePWM10 SOCB for ADCSOCBO
#define SYSCTL_ADCSOC_SRC_PWM11SOCB   0x04000000U //!< ePWM11 SOCB for ADCSOCBO
#define SYSCTL_ADCSOC_SRC_PWM12SOCB   0x08000000U //!< ePWM12 SOCB for ADCSOCBO
#define SYSCTL_ADCSOC_SRC_PWM13SOCB   0x10000000U //!< ePWM13 SOCB for ADCSOCBO
#define SYSCTL_ADCSOC_SRC_PWM14SOCB   0x20000000U //!< ePWM14 SOCB for ADCSOCBO
#define SYSCTL_ADCSOC_SRC_PWM15SOCB   0x40000000U //!< ePWM15 SOCB for ADCSOCBO
#define SYSCTL_ADCSOC_SRC_PWM16SOCB   0x80000000U //!< ePWM16 SOCB for ADCSOCBO
#endif

//*****************************************************************************
//
//! The following are values that can be passed to SysCtl_enablePeripheral()
//! and SysCtl_disablePeripheral() as the \e peripheral parameter.
//
//*****************************************************************************
typedef enum
{
    // PCLKCR0
    SYSCTL_PERIPH_CLK_CLA1       = 0x0000,  //!< CLA1 clock
    SYSCTL_PERIPH_CLK_DMA        = 0x0200,  //!< DMA clock
    SYSCTL_PERIPH_CLK_TIMER0     = 0x0300,  //!< CPUTIMER0 clock
    SYSCTL_PERIPH_CLK_TIMER1     = 0x0400,  //!< CPUTIMER1 clock
    SYSCTL_PERIPH_CLK_TIMER2     = 0x0500,  //!< CPUTIMER2 clock
    SYSCTL_PERIPH_CLK_CPUBGCRC   = 0x0D00,  //!< CPUBGCRC clock
    SYSCTL_PERIPH_CLK_CLA1BGCRC  = 0x0E00,  //!< CLA1BGCRC clock
    SYSCTL_PERIPH_CLK_HRCAL      = 0x1000,  //!< HRPWM clock
    SYSCTL_PERIPH_CLK_TBCLKSYNC  = 0x1200,  //!< ePWM time base clock sync
    SYSCTL_PERIPH_CLK_GTBCLKSYNC = 0x1300,  //!< ePWM global time base sync
    SYSCTL_PERIPH_CLK_ERAD       = 0x1800,  //!<  ERAD module clock

    // PCLKCR1
    SYSCTL_PERIPH_CLK_EMIF1      = 0x0001,  //!< EMIF1 clock
    SYSCTL_PERIPH_CLK_EMIF2      = 0x0101,  //!< EMIF2 clock

    // PCLKCR2
    SYSCTL_PERIPH_CLK_EPWM1      = 0x0002,  //!< ePWM1 clock
    SYSCTL_PERIPH_CLK_EPWM2      = 0x0102,  //!< ePWM2 clock
    SYSCTL_PERIPH_CLK_EPWM3      = 0x0202,  //!< ePWM3 clock
    SYSCTL_PERIPH_CLK_EPWM4      = 0x0302,  //!< ePWM4 clock
    SYSCTL_PERIPH_CLK_EPWM5      = 0x0402,  //!< ePWM5 clock
    SYSCTL_PERIPH_CLK_EPWM6      = 0x0502,  //!< ePWM6 clock
    SYSCTL_PERIPH_CLK_EPWM7      = 0x0602,  //!< ePWM7 clock
    SYSCTL_PERIPH_CLK_EPWM8      = 0x0702,  //!< ePWM8 clock
    SYSCTL_PERIPH_CLK_EPWM9      = 0x0802,  //!< ePWM9 clock
    SYSCTL_PERIPH_CLK_EPWM10     = 0x0902,  //!< ePWM10 clock
    SYSCTL_PERIPH_CLK_EPWM11     = 0x0A02,  //!< ePWM11 clock
    SYSCTL_PERIPH_CLK_EPWM12     = 0x0B02,  //!< ePWM12 clock
    SYSCTL_PERIPH_CLK_EPWM13     = 0x0C02,  //!< ePWM13 clock
    SYSCTL_PERIPH_CLK_EPWM14     = 0x0D02,  //!< ePWM14 clock
    SYSCTL_PERIPH_CLK_EPWM15     = 0x0E02,  //!< ePWM15 clock
    SYSCTL_PERIPH_CLK_EPWM16     = 0x0F02,  //!< ePWM16 clock

    // PCLKCR3
    SYSCTL_PERIPH_CLK_ECAP1      = 0x0003,  //!< eCAP1 clock
    SYSCTL_PERIPH_CLK_ECAP2      = 0x0103,  //!< eCAP2 clock
    SYSCTL_PERIPH_CLK_ECAP3      = 0x0203,  //!< eCAP3 clock
    SYSCTL_PERIPH_CLK_ECAP4      = 0x0303,  //!< eCAP4 clock
    SYSCTL_PERIPH_CLK_ECAP5      = 0x0403,  //!< eCAP5 clock
    SYSCTL_PERIPH_CLK_ECAP6      = 0x0503,  //!< eCAP6 clock
    SYSCTL_PERIPH_CLK_ECAP7      = 0x0603,  //!< eCAP7 clock

    // PCLKCR4
    SYSCTL_PERIPH_CLK_EQEP1      = 0x0004,  //!< eQEP1 clock
    SYSCTL_PERIPH_CLK_EQEP2      = 0x0104,  //!< eQEP2 clock
    SYSCTL_PERIPH_CLK_EQEP3      = 0x0204,  //!< eQEP3 clock

    // PCLKCR5
    // Reserved

    // PCLKCR6
    SYSCTL_PERIPH_CLK_SD1        = 0x0006,  //!< SDFM1 clock
    SYSCTL_PERIPH_CLK_SD2        = 0x0106,  //!< SDFM2 clock

    // PCLKCR7
    SYSCTL_PERIPH_CLK_SCIA       = 0x0007,  //!< SCIA clock
    SYSCTL_PERIPH_CLK_SCIB       = 0x0107,  //!< SCIB clock
    SYSCTL_PERIPH_CLK_SCIC       = 0x0207,  //!< SCIC clock
    SYSCTL_PERIPH_CLK_SCID       = 0x0307,  //!< SCID clock

    // PCLKCR8
    SYSCTL_PERIPH_CLK_SPIA       = 0x0008,  //!< SPIA clock
    SYSCTL_PERIPH_CLK_SPIB       = 0x0108,  //!< SPIB clock
    SYSCTL_PERIPH_CLK_SPIC       = 0x0208,  //!< SPIC clock
    SYSCTL_PERIPH_CLK_SPID       = 0x0308,  //!< SPID clock

    // PCLKCR9
    SYSCTL_PERIPH_CLK_I2CA       = 0x0009,  //!< I2CA clock
    SYSCTL_PERIPH_CLK_I2CB       = 0x0109,  //!< I2CB clock

    // PCLKCR10
    SYSCTL_PERIPH_CLK_CANA       = 0x000A,  //!< CANA clock
    SYSCTL_PERIPH_CLK_CANB       = 0x010A,  //!< CANB clock
    SYSCTL_PERIPH_CLK_MCANA      = 0x040A,  //!< MCANA clock

    // PCLKCR11
    SYSCTL_PERIPH_CLK_MCBSPA     = 0x000B,  //!< McBSPA clock
    SYSCTL_PERIPH_CLK_MCBSPB     = 0x010B,  //!< McBSPB clock
    SYSCTL_PERIPH_CLK_USBA       = 0x100B,  //!< USBA clock

    // PCLKCR12

    // PCLKCR13
    SYSCTL_PERIPH_CLK_ADCA       = 0x000D,  //!< ADCA clock
    SYSCTL_PERIPH_CLK_ADCB       = 0x010D,  //!< ADCB clock
    SYSCTL_PERIPH_CLK_ADCC       = 0x020D,  //!< ADCC clock
    SYSCTL_PERIPH_CLK_ADCD       = 0x030D,  //!< ADCD clock

    // PCLKCR14
    SYSCTL_PERIPH_CLK_CMPSS1     = 0x000E,  //!< CMPSS1 clock
    SYSCTL_PERIPH_CLK_CMPSS2     = 0x010E,  //!< CMPSS2 clock
    SYSCTL_PERIPH_CLK_CMPSS3     = 0x020E,  //!< CMPSS3 clock
    SYSCTL_PERIPH_CLK_CMPSS4     = 0x030E,  //!< CMPSS4 clock
    SYSCTL_PERIPH_CLK_CMPSS5     = 0x040E,  //!< CMPSS5 clock
    SYSCTL_PERIPH_CLK_CMPSS6     = 0x050E,  //!< CMPSS6 clock
    SYSCTL_PERIPH_CLK_CMPSS7     = 0x060E,  //!< CMPSS7 clock
    SYSCTL_PERIPH_CLK_CMPSS8     = 0x070E,  //!< CMPSS8 clock

    // PCLKCR15
    // Reserved

    // PCLKCR16
    SYSCTL_PERIPH_CLK_DACA       = 0x1010,  //!< DACA clock
    SYSCTL_PERIPH_CLK_DACB       = 0x1110,  //!< DACB clock
    SYSCTL_PERIPH_CLK_DACC       = 0x1210,  //!< DACC clock

    // PCLKCR17
    SYSCTL_PERIPH_CLK_CLB1       = 0x0011,  //!< CLB1 clock
    SYSCTL_PERIPH_CLK_CLB2       = 0x0111,  //!< CLB2 clock
    SYSCTL_PERIPH_CLK_CLB3       = 0x0211,  //!< CLB3 clock
    SYSCTL_PERIPH_CLK_CLB4       = 0x0311,  //!< CLB4 clock
    SYSCTL_PERIPH_CLK_CLB5       = 0x0411,  //!< CLB5 clock
    SYSCTL_PERIPH_CLK_CLB6       = 0x0511,  //!< CLB6 clock
    SYSCTL_PERIPH_CLK_CLB7       = 0x0611,  //!< CLB7 clock
    SYSCTL_PERIPH_CLK_CLB8       = 0x0711,  //!< CLB8 clock

    // PCLKCR18
    SYSCTL_PERIPH_CLK_FSITXA     = 0x0012,  //!< FSITXA clock
    SYSCTL_PERIPH_CLK_FSITXB     = 0x0112,  //!< FSITXB clock
    SYSCTL_PERIPH_CLK_FSIRXA     = 0x1012,  //!< FSIRXA clock
    SYSCTL_PERIPH_CLK_FSIRXB     = 0x1112,  //!< FSIRXB clock
    SYSCTL_PERIPH_CLK_FSIRXC     = 0x1212,  //!< FSIRXC clock
    SYSCTL_PERIPH_CLK_FSIRXD     = 0x1312,  //!< FSIRXD clock
    SYSCTL_PERIPH_CLK_FSIRXE     = 0x1412,  //!< FSIRXE clock
    SYSCTL_PERIPH_CLK_FSIRXF     = 0x1512,  //!< FSIRXF clock
    SYSCTL_PERIPH_CLK_FSIRXG     = 0x1612,  //!< FSIRXG clock
    SYSCTL_PERIPH_CLK_FSIRXH     = 0x1712,  //!< FSIRXH clock

    // PCLKCR19
    // Reserved

    // PCLKCR20
    SYSCTL_PERIPH_CLK_PMBUSA     = 0x0014,  //!< PMBusA clock

    // PCLKCR21
    SYSCTL_PERIPH_CLK_DCC0       = 0x0015,  //!< DCC0 clock
    SYSCTL_PERIPH_CLK_DCC1       = 0x0115,  //!< DCC1 clock
    SYSCTL_PERIPH_CLK_DCC2       = 0x0215,  //!< DCC2 clock

    // PCLKCR22
    SYSCTL_PERIPH_CLK_PBIST      = 0x0016,  //!< PBIST clock

    // PCLKCR23
    SYSCTL_PERIPH_CLK_ECAT       = 0x0017   //!< Ethercat clock 
} SysCtl_PeripheralPCLOCKCR;
//*****************************************************************************
//
//! The following are values that can be passed to SysCtl_resetPeripheral() as
//! the \e peripheral parameter.
//
//*****************************************************************************
typedef enum
{
    // SOFTPRES0
    SYSCTL_PERIPH_RES_CPU1_CLA1  = 0x0000,  //!< Reset CPU1 CLA1
    SYSCTL_PERIPH_RES_CPU2_CLA1  = 0x0200,  //!< Reset CPU2 CLA1
    SYSCTL_PERIPH_RES_CPUBGCRC   = 0x0D00,  //!< Reset CPUBGCRC
    SYSCTL_PERIPH_RES_CLA1BGCRC  = 0x0E00,  //!< Reset CLA1BGCRC
    SYSCTL_PERIPH_RES_ERAD       = 0x1800,  //!< Reset ERAD

    // SOFTPRES1
    SYSCTL_PERIPH_RES_EMIF1      = 0x0001,  //!< Reset EMIF1
    SYSCTL_PERIPH_RES_EMIF2      = 0x0101,  //!< Reset EMIF2

    // SOFTPRES2
    SYSCTL_PERIPH_RES_EPWM1      = 0x0002,  //!< Reset ePWM1
    SYSCTL_PERIPH_RES_EPWM2      = 0x0102,  //!< Reset ePWM2
    SYSCTL_PERIPH_RES_EPWM3      = 0x0202,  //!< Reset ePWM3
    SYSCTL_PERIPH_RES_EPWM4      = 0x0302,  //!< Reset ePWM4
    SYSCTL_PERIPH_RES_EPWM5      = 0x0402,  //!< Reset ePWM5
    SYSCTL_PERIPH_RES_EPWM6      = 0x0502,  //!< Reset ePWM6
    SYSCTL_PERIPH_RES_EPWM7      = 0x0602,  //!< Reset ePWM7
    SYSCTL_PERIPH_RES_EPWM8      = 0x0702,  //!< Reset ePWM8
    SYSCTL_PERIPH_RES_EPWM9      = 0x0802,  //!< Reset ePWM9
    SYSCTL_PERIPH_RES_EPWM10     = 0x0902,  //!< Reset ePWM10
    SYSCTL_PERIPH_RES_EPWM11     = 0x0A02,  //!< Reset ePWM11
    SYSCTL_PERIPH_RES_EPWM12     = 0x0B02,  //!< Reset ePWM12
    SYSCTL_PERIPH_RES_EPWM13     = 0x0C02,  //!< Reset ePWM13
    SYSCTL_PERIPH_RES_EPWM14     = 0x0D02,  //!< Reset ePWM14
    SYSCTL_PERIPH_RES_EPWM15     = 0x0E02,  //!< Reset ePWM15
    SYSCTL_PERIPH_RES_EPWM16     = 0x0F02,  //!< Reset ePWM16

    // SOFTPRES3
    SYSCTL_PERIPH_RES_ECAP1      = 0x0003,  //!< Reset eCAP1
    SYSCTL_PERIPH_RES_ECAP2      = 0x0103,  //!< Reset eCAP2
    SYSCTL_PERIPH_RES_ECAP3      = 0x0203,  //!< Reset eCAP3
    SYSCTL_PERIPH_RES_ECAP4      = 0x0303,  //!< Reset eCAP4
    SYSCTL_PERIPH_RES_ECAP5      = 0x0403,  //!< Reset eCAP5
    SYSCTL_PERIPH_RES_ECAP6      = 0x0503,  //!< Reset eCAP6
    SYSCTL_PERIPH_RES_ECAP7      = 0x0603,  //!< Reset eCAP7

    // SOFTPRES4
    SYSCTL_PERIPH_RES_EQEP1      = 0x0004,  //!< Reset eQEP1
    SYSCTL_PERIPH_RES_EQEP2      = 0x0104,  //!< Reset eQEP2
    SYSCTL_PERIPH_RES_EQEP3      = 0x0204,  //!< Reset eQEP3

    // SOFTPRES5
    // Reserved

    // SOFTPRES6
    SYSCTL_PERIPH_RES_SD1        = 0x0006,  //!< Reset SDFM1
    SYSCTL_PERIPH_RES_SD2        = 0x0106,  //!< Reset SDFM2

    // SOFTPRES7
    SYSCTL_PERIPH_RES_SCIA       = 0x0007,  //!< Reset SCIA
    SYSCTL_PERIPH_RES_SCIB       = 0x0107,  //!< Reset SCIB
    SYSCTL_PERIPH_RES_SCIC       = 0x0207,  //!< Reset SCIC
    SYSCTL_PERIPH_RES_SCID       = 0x0307,  //!< Reset SCID

    // SOFTPRES8
    SYSCTL_PERIPH_RES_SPIA       = 0x0008,  //!< Reset SPIA
    SYSCTL_PERIPH_RES_SPIB       = 0x0108,  //!< Reset SPIB
    SYSCTL_PERIPH_RES_SPIC       = 0x0208,  //!< Reset SPIC
    SYSCTL_PERIPH_RES_SPID       = 0x0308,  //!< Reset SPID

    // SOFTPRES9
    SYSCTL_PERIPH_RES_I2CA       = 0x0009,  //!< Reset I2CA
    SYSCTL_PERIPH_RES_I2CB       = 0x0109,  //!< Reset I2CB

    // SOFTPRES10
    SYSCTL_PERIPH_RES_CANA       = 0x000A,  //!< Reset CANA
    SYSCTL_PERIPH_RES_CANB       = 0x010A,  //!< Reset CANB
    SYSCTL_PERIPH_RES_MCANA      = 0x040A,  //!< Reset MCANA    

    // SOFTPRES11
    SYSCTL_PERIPH_RES_MCBSPA     = 0x000B,  //!< Reset McBSPA
    SYSCTL_PERIPH_RES_MCBSPB     = 0x010B,  //!< Reset McBSPB
    SYSCTL_PERIPH_RES_USBA       = 0x100B,  //!< Reset USBA

    // SOFTPRES12
    // Reserved

    // SOFTPRES13
    SYSCTL_PERIPH_RES_ADCA       = 0x000D,  //!< Reset ADCA
    SYSCTL_PERIPH_RES_ADCB       = 0x010D,  //!< Reset ADCB
    SYSCTL_PERIPH_RES_ADCC       = 0x020D,  //!< Reset ADCC
    SYSCTL_PERIPH_RES_ADCD       = 0x030D,  //!< Reset ADCD

    // SOFTPRES14
    SYSCTL_PERIPH_RES_CMPSS1     = 0x000E,  //!< Reset CMPSS1
    SYSCTL_PERIPH_RES_CMPSS2     = 0x010E,  //!< Reset CMPSS2
    SYSCTL_PERIPH_RES_CMPSS3     = 0x020E,  //!< Reset CMPSS3
    SYSCTL_PERIPH_RES_CMPSS4     = 0x030E,  //!< Reset CMPSS4
    SYSCTL_PERIPH_RES_CMPSS5     = 0x040E,  //!< Reset CMPSS5
    SYSCTL_PERIPH_RES_CMPSS6     = 0x050E,  //!< Reset CMPSS6
    SYSCTL_PERIPH_RES_CMPSS7     = 0x060E,  //!< Reset CMPSS7
    SYSCTL_PERIPH_RES_CMPSS8     = 0x070E,  //!< Reset CMPSS8

    // SOFTPRES15
    // Reserved

    // SOFTPRES16
    SYSCTL_PERIPH_RES_DACA       = 0x1010,  //!< Reset DACA
    SYSCTL_PERIPH_RES_DACB       = 0x1110,  //!< Reset DACB
    SYSCTL_PERIPH_RES_DACC       = 0x1210,  //!< Reset DACC

    // SOFTPRES17
    SYSCTL_PERIPH_RES_CLB1       = 0x0011,  //!< Reset CLB1
    SYSCTL_PERIPH_RES_CLB2       = 0x0111,  //!< Reset CLB2
    SYSCTL_PERIPH_RES_CLB3       = 0x0211,  //!< Reset CLB3
    SYSCTL_PERIPH_RES_CLB4       = 0x0311,  //!< Reset CLB4
    SYSCTL_PERIPH_RES_CLB5       = 0x0411,   //!< Reset CLB5
    SYSCTL_PERIPH_RES_CLB6       = 0x0511,  //!< Reset CLB6
    SYSCTL_PERIPH_RES_CLB7       = 0x0611,  //!< Reset CLB7
    SYSCTL_PERIPH_RES_CLB8       = 0x0711,  //!< Reset CLB8

    // SOFTPRES18
    SYSCTL_PERIPH_RES_FSITXA     = 0x0012,  //!< Reset FSITXA
    SYSCTL_PERIPH_RES_FSITXB     = 0x0112,  //!< Reset FSITXB
    SYSCTL_PERIPH_RES_FSIRXA     = 0x1012,  //!< Reset FSIRXA
    SYSCTL_PERIPH_RES_FSIRXB     = 0x1112,  //!< Reset FSIRXB
    SYSCTL_PERIPH_RES_FSIRXC     = 0x1212,  //!< Reset FSIRXC
    SYSCTL_PERIPH_RES_FSIRXD     = 0x1312,  //!< Reset FSIRXD
    SYSCTL_PERIPH_RES_FSIRXE     = 0x1412,  //!< Reset FSIRXE
    SYSCTL_PERIPH_RES_FSIRXF     = 0x1512,  //!< Reset FSIRXF
    SYSCTL_PERIPH_RES_FSIRXG     = 0x1612,  //!< Reset FSIRXG
    SYSCTL_PERIPH_RES_FSIRXH     = 0x1712,  //!< Reset FSIRXH
    
    // SOFTPRES20
    SYSCTL_PERIPH_RES_PMBUS_A    = 0x0014,  //!< Reset PMBUSA
    
    // SOFTPRES21
    SYSCTL_PERIPH_RES_DCC0       = 0x0015,  //!< Reset DCC0
    SYSCTL_PERIPH_RES_DCC1       = 0x0115,  //!< Reset DCC1
    SYSCTL_PERIPH_RES_DCC2       = 0x0215,  //!< Reset DCC2
    
    // SOFTPRES23
    SYSCTL_PERIPH_RES_ECAT       = 0x0017   //!< Reset Ethercat

} SysCtl_PeripheralSOFTPRES;

//*****************************************************************************
//
//! The following are values that can be passed to SysCtl_isPeripheralPresent()
//! as the \e peripheral parameter.
//
//*****************************************************************************
typedef enum
{
    // DC0
    SYSCTL_PERIPH_PRESENT_DUAL_CORE    = 0x0000,
    SYSCTL_PERIPH_PRESENT_CM           = 0x0100,

    // DC1
    SYSCTL_PERIPH_PRESENT_CPU1_FPU_TMU = 0x0001,
    SYSCTL_PERIPH_PRESENT_CPU2_FPU_TMU = 0x0101,
    SYSCTL_PERIPH_PRESENT_CPU1_VCU     = 0x0201,
    SYSCTL_PERIPH_PRESENT_CPU2_VCU     = 0x0301,
    SYSCTL_PERIPH_PRESENT_CPU1_CLA1    = 0x0601,
    SYSCTL_PERIPH_PRESENT_CPU2_CLA1    = 0x0801,

    // DC2
    SYSCTL_PERIPH_PRESENT_EMIF1  = 0x0002,
    SYSCTL_PERIPH_PRESENT_EMIF2  = 0x0102,

    // DC3
    SYSCTL_PERIPH_PRESENT_EPWM1  = 0x0003,
    SYSCTL_PERIPH_PRESENT_EPWM2  = 0x0103,
    SYSCTL_PERIPH_PRESENT_EPWM3  = 0x0203,
    SYSCTL_PERIPH_PRESENT_EPWM4  = 0x0303,
    SYSCTL_PERIPH_PRESENT_EPWM5  = 0x0403,
    SYSCTL_PERIPH_PRESENT_EPWM6  = 0x0503,
    SYSCTL_PERIPH_PRESENT_EPWM7  = 0x0603,
    SYSCTL_PERIPH_PRESENT_EPWM8  = 0x0703,
    SYSCTL_PERIPH_PRESENT_EPWM9  = 0x0803,
    SYSCTL_PERIPH_PRESENT_EPWM10 = 0x0903,
    SYSCTL_PERIPH_PRESENT_EPWM11 = 0x0A03,
    SYSCTL_PERIPH_PRESENT_EPWM12 = 0x0B03,
    SYSCTL_PERIPH_PRESENT_EPWM13 = 0x0C03,
    SYSCTL_PERIPH_PRESENT_EPWM14 = 0x0D03,
    SYSCTL_PERIPH_PRESENT_EPWM15 = 0x0E03,
    SYSCTL_PERIPH_PRESENT_EPWM16 = 0x0F03,

    // DC4
    SYSCTL_PERIPH_PRESENT_ECAP1  = 0x0004,
    SYSCTL_PERIPH_PRESENT_ECAP2  = 0x0104,
    SYSCTL_PERIPH_PRESENT_ECAP3  = 0x0204,
    SYSCTL_PERIPH_PRESENT_ECAP4  = 0x0304,
    SYSCTL_PERIPH_PRESENT_ECAP5  = 0x0404,
    SYSCTL_PERIPH_PRESENT_ECAP6  = 0x0504,
    SYSCTL_PERIPH_PRESENT_ECAP7  = 0x0604,

    // DC5
    SYSCTL_PERIPH_PRESENT_EQEP1  = 0x0005,
    SYSCTL_PERIPH_PRESENT_EQEP2  = 0x0105,
    SYSCTL_PERIPH_PRESENT_EQEP3  = 0x0205,

    // DC6
    // Reserved

    // DC7
    SYSCTL_PERIPH_PRESENT_SD1     = 0x0007,
    SYSCTL_PERIPH_PRESENT_SD2     = 0x0107,

    // DC8
    SYSCTL_PERIPH_PRESENT_SCIA    = 0x0008,
    SYSCTL_PERIPH_PRESENT_SCIB    = 0x0108,
    SYSCTL_PERIPH_PRESENT_SCIC    = 0x0208,
    SYSCTL_PERIPH_PRESENT_SCID    = 0x0308,

    // DC9
    SYSCTL_PERIPH_PRESENT_SPIA    = 0x0009,
    SYSCTL_PERIPH_PRESENT_SPIB    = 0x0109,
    SYSCTL_PERIPH_PRESENT_SPIC    = 0x0209,
    SYSCTL_PERIPH_PRESENT_SPID    = 0x0309,

    // DC10
    SYSCTL_PERIPH_PRESENT_I2CA    = 0x000A,
    SYSCTL_PERIPH_PRESENT_I2CB    = 0x010A,

    // DC11
    SYSCTL_PERIPH_PRESENT_CANA    = 0x000B,
    SYSCTL_PERIPH_PRESENT_CANB    = 0x010B,
    SYSCTL_PERIPH_PRESENT_CANFDA  = 0x050B,
    SYSCTL_PERIPH_PRESENT_MCANA   = 0x090B,

    // DC12
    SYSCTL_PERIPH_PRESENT_MCBSPA  = 0x000C,
    SYSCTL_PERIPH_PRESENT_MCBSPB  = 0x010C,
    SYSCTL_PERIPH_PRESENT_USBA    = 0x100C,

    // DC13

    // DC14
    SYSCTL_PERIPH_PRESENT_ADCA    = 0x000E,
    SYSCTL_PERIPH_PRESENT_ADCB    = 0x010E,
    SYSCTL_PERIPH_PRESENT_ADCC    = 0x020E,
    SYSCTL_PERIPH_PRESENT_ADCD    = 0x030E,

    // DC15
    SYSCTL_PERIPH_PRESENT_CMPSS1  = 0x000F,
    SYSCTL_PERIPH_PRESENT_CMPSS2  = 0x010F,
    SYSCTL_PERIPH_PRESENT_CMPSS3  = 0x020F,
    SYSCTL_PERIPH_PRESENT_CMPSS4  = 0x030F,
    SYSCTL_PERIPH_PRESENT_CMPSS5  = 0x040F,
    SYSCTL_PERIPH_PRESENT_CMPSS6  = 0x050F,
    SYSCTL_PERIPH_PRESENT_CMPSS7  = 0x060F,
    SYSCTL_PERIPH_PRESENT_CMPSS8  = 0x070F,

    // DC16
    // Reserved

    // DC17
    SYSCTL_PERIPH_PRESENT_DACA    = 0x1011,
    SYSCTL_PERIPH_PRESENT_DACB    = 0x1111,
    SYSCTL_PERIPH_PRESENT_DACC    = 0x1211,

    // DC18
    SYSCTL_PERIPH_PRESENT_LS0_1   = 0x0012,
    SYSCTL_PERIPH_PRESENT_LS1_1   = 0x0112,
    SYSCTL_PERIPH_PRESENT_LS2_1   = 0x0212,
    SYSCTL_PERIPH_PRESENT_LS3_1   = 0x0312,
    SYSCTL_PERIPH_PRESENT_LS4_1   = 0x0412,
    SYSCTL_PERIPH_PRESENT_LS5_1   = 0x0512,
    SYSCTL_PERIPH_PRESENT_LS6_1   = 0x0612,
    SYSCTL_PERIPH_PRESENT_LS7_1   = 0x0712,

    // DC19
    SYSCTL_PERIPH_PRESENT_LS0_2   = 0x0013,
    SYSCTL_PERIPH_PRESENT_LS1_2   = 0x0113,
    SYSCTL_PERIPH_PRESENT_LS2_2   = 0x0213,
    SYSCTL_PERIPH_PRESENT_LS3_2   = 0x0313,
    SYSCTL_PERIPH_PRESENT_LS4_2   = 0x0413,
    SYSCTL_PERIPH_PRESENT_LS5_2   = 0x0513,
    SYSCTL_PERIPH_PRESENT_LS6_2   = 0x0613,
    SYSCTL_PERIPH_PRESENT_LS7_2   = 0x0713,

    // DC20
    SYSCTL_PERIPH_PRESENT_GS0     = 0x0014,
    SYSCTL_PERIPH_PRESENT_GS1     = 0x0114,
    SYSCTL_PERIPH_PRESENT_GS2     = 0x0214,
    SYSCTL_PERIPH_PRESENT_GS3     = 0x0314,
    SYSCTL_PERIPH_PRESENT_GS4     = 0x0414,
    SYSCTL_PERIPH_PRESENT_GS5     = 0x0514,
    SYSCTL_PERIPH_PRESENT_GS6     = 0x0614,
    SYSCTL_PERIPH_PRESENT_GS7     = 0x0714,
    SYSCTL_PERIPH_PRESENT_GS8     = 0x0814,
    SYSCTL_PERIPH_PRESENT_GS9     = 0x0914,
    SYSCTL_PERIPH_PRESENT_GS10    = 0x0A14,
    SYSCTL_PERIPH_PRESENT_GS11    = 0x0B14,
    SYSCTL_PERIPH_PRESENT_GS12    = 0x0C14,
    SYSCTL_PERIPH_PRESENT_GS13    = 0x0D14,
    SYSCTL_PERIPH_PRESENT_GS14    = 0x0E14,
    SYSCTL_PERIPH_PRESENT_GS15    = 0x0F14,

    //DC21
    SYSCTL_PERIPH_PRESENT_CLB1    = 0x0015,
    SYSCTL_PERIPH_PRESENT_CLB2    = 0x0115,
    SYSCTL_PERIPH_PRESENT_CLB3    = 0x0215,
    SYSCTL_PERIPH_PRESENT_CLB4    = 0x0315,
    SYSCTL_PERIPH_PRESENT_CLB5    = 0x0415,
    SYSCTL_PERIPH_PRESENT_CLB6    = 0x0515,
    SYSCTL_PERIPH_PRESENT_CLB7    = 0x0615,
    SYSCTL_PERIPH_PRESENT_CLB8    = 0x0715,

    //DC22
    SYSCTL_PERIPH_PRESENT_FSITXA  = 0x0016,
    SYSCTL_PERIPH_PRESENT_FSITXB  = 0x0116,
    SYSCTL_PERIPH_PRESENT_FSIRXA  = 0x1016,
    SYSCTL_PERIPH_PRESENT_FSIRXB  = 0x1116,
    SYSCTL_PERIPH_PRESENT_FSIRXC  = 0x1216,
    SYSCTL_PERIPH_PRESENT_FSIRXD  = 0x1316,
    SYSCTL_PERIPH_PRESENT_FSIRXE  = 0x1416,
    SYSCTL_PERIPH_PRESENT_FSIRXF  = 0x1516,
    SYSCTL_PERIPH_PRESENT_FSIRXG  = 0x1616,
    SYSCTL_PERIPH_PRESENT_FSIRXH  = 0x1716,

    //DC24
    SYSCTL_PERIPH_PRESENT_PMBUSA  = 0x0018,

    //DC25
    SYSCTL_PERIPH_PRESENT_DCC0    = 0x0019,
    SYSCTL_PERIPH_PRESENT_DCC1    = 0x0119,
    SYSCTL_PERIPH_PRESENT_DCC2    = 0x0219,

    //DC26
    SYSCTL_PERIPH_PRESENT_ECAT    = 0x001A,
    SYSCTL_PERIPH_PRESENT_ENET    = 0x011A,

    //DC27
    SYSCTL_PERIPH_PRESENT_CPU1BGCRC       = 0x001B,
    SYSCTL_PERIPH_PRESENT_CPU1CLA1BGCRC   = 0x011B,
    SYSCTL_PERIPH_PRESENT_CPU2BGCRC       = 0x031B,
    SYSCTL_PERIPH_PRESENT_CPU2CLA1BGCRC   = 0x041B
    
} SysCtl_PeripheralDC;

//*****************************************************************************
//
//! The following are values that can be passed to
//! SysCtl_selectCPUForPeripheral() & SysCtl_lockCPUSelectRegs() 
//! as the \e peripheral parameter.
//
//*****************************************************************************
typedef enum
{
    //! Configure CPU Select for EPWM
    SYSCTL_CPUSEL0_EPWM      = 0x0U,
    //! Configure CPU Select for ECAP
    SYSCTL_CPUSEL1_ECAP      = 0x1U,
    //! Configure CPU Select for EQEP
    SYSCTL_CPUSEL2_EQEP      = 0x2U,
    //! Configure CPU Select for SD
    SYSCTL_CPUSEL4_SD        = 0x4U,
    //! Configure CPU Select for SCI
    SYSCTL_CPUSEL5_SCI       = 0x5U,
    //! Configure CPU Select for SPI
    SYSCTL_CPUSEL6_SPI       = 0x6U,
    //! Configure CPU Select for I2C
    SYSCTL_CPUSEL7_I2C       = 0x7U,
    //! Configure CPU Select for CAN
    SYSCTL_CPUSEL8_CAN       = 0x8U,
    //! Configure CPU Select for MCBSP
    SYSCTL_CPUSEL9_MCBSP     = 0x9U,
    //! Configure CPU Select for ADC
    SYSCTL_CPUSEL11_ADC      = 0xBU,
    //! Configure CPU Select for CMPSS
    SYSCTL_CPUSEL12_CMPSS    = 0xCU,
    //! Configure CPU Select for DAC
    SYSCTL_CPUSEL14_DAC      = 0xEU,
    //! Configure CPU Select for FSI
    SYSCTL_CPUSEL15_FSI      = 0xFU,
    //! Configure CPU Select for CLB
    SYSCTL_CPUSEL16_CLB      = 0x10U,
    //! Configure CPU Select for PMBUS
    SYSCTL_CPUSEL18_PMBUS    = 0x12U,
    //! Configure CPU Select for HRCAL
    SYSCTL_CPUSEL25_HRCAL    = 0x19U 
} SysCtl_CPUSelPeripheral;

//*****************************************************************************
//
//! The following are values that can be passed to
//! SysCtl_selectCPUForPeripheral() as \e cpuInst parameter.
//
//*****************************************************************************
typedef enum
{
    //! Connect the peripheral (indicated by SysCtl_CPUSelPeripheral) to CPU1
    SYSCTL_CPUSEL_CPU1 = 0x0U,
    //! Connect the peripheral (indicated by SysCtl_CPUSelPeripheral) to CPU2
    SYSCTL_CPUSEL_CPU2 = 0x1U
} SysCtl_CPUSel;

//*****************************************************************************
//
//! The following are values that can be passed to
//! SysCtl_setWatchdogPredivider() as the \e predivider parameter.
//
//*****************************************************************************
typedef enum
{
    SYSCTL_WD_PREDIV_2    = 0x800,  //!< PREDIVCLK = INTOSC1 / 2
    SYSCTL_WD_PREDIV_4    = 0x900,  //!< PREDIVCLK = INTOSC1 / 4
    SYSCTL_WD_PREDIV_8    = 0xA00,  //!< PREDIVCLK = INTOSC1 / 8
    SYSCTL_WD_PREDIV_16   = 0xB00,  //!< PREDIVCLK = INTOSC1 / 16
    SYSCTL_WD_PREDIV_32   = 0xC00,  //!< PREDIVCLK = INTOSC1 / 32
    SYSCTL_WD_PREDIV_64   = 0xD00,  //!< PREDIVCLK = INTOSC1 / 64
    SYSCTL_WD_PREDIV_128  = 0xE00,  //!< PREDIVCLK = INTOSC1 / 128
    SYSCTL_WD_PREDIV_256  = 0xF00,  //!< PREDIVCLK = INTOSC1 / 256
    SYSCTL_WD_PREDIV_512  = 0x000,  //!< PREDIVCLK = INTOSC1 / 512
    SYSCTL_WD_PREDIV_1024 = 0x100,  //!< PREDIVCLK = INTOSC1 / 1024
    SYSCTL_WD_PREDIV_2048 = 0x200,  //!< PREDIVCLK = INTOSC1 / 2048
    SYSCTL_WD_PREDIV_4096 = 0x300   //!< PREDIVCLK = INTOSC1 / 4096
} SysCtl_WDPredivider;

//*****************************************************************************
//
//! The following are values that can be passed to
//! SysCtl_setWatchdogPrescaler() as the \e prescaler parameter.
//
//*****************************************************************************
typedef enum
{
    SYSCTL_WD_PRESCALE_1  = 1,      //!< WDCLK = PREDIVCLK / 1
    SYSCTL_WD_PRESCALE_2  = 2,      //!< WDCLK = PREDIVCLK / 2
    SYSCTL_WD_PRESCALE_4  = 3,      //!< WDCLK = PREDIVCLK / 4
    SYSCTL_WD_PRESCALE_8  = 4,      //!< WDCLK = PREDIVCLK / 8
    SYSCTL_WD_PRESCALE_16 = 5,      //!< WDCLK = PREDIVCLK / 16
    SYSCTL_WD_PRESCALE_32 = 6,      //!< WDCLK = PREDIVCLK / 32
    SYSCTL_WD_PRESCALE_64 = 7       //!< WDCLK = PREDIVCLK / 64
} SysCtl_WDPrescaler;

//*****************************************************************************
//
//! The following are values that can be passed to
//! SysCtl_setWatchdogMode() as the \e prescaler parameter.
//
//*****************************************************************************
typedef enum
{
    //! Watchdog can generate a reset signal
    SYSCTL_WD_MODE_RESET,
    //! Watchdog can generate an interrupt signal; reset signal is disabled
    SYSCTL_WD_MODE_INTERRUPT
} SysCtl_WDMode;

//*****************************************************************************
//
//! The following are values that can be passed to SysCtl_setLowSpeedClock() as
//! the \e prescaler parameter.
//
//*****************************************************************************
typedef enum
{
    SYSCTL_LSPCLK_PRESCALE_1    = 0,    //!< LSPCLK = SYSCLK / 1
    SYSCTL_LSPCLK_PRESCALE_2    = 1,    //!< LSPCLK = SYSCLK / 2
    SYSCTL_LSPCLK_PRESCALE_4    = 2,    //!< LSPCLK = SYSCLK / 4 (default)
    SYSCTL_LSPCLK_PRESCALE_6    = 3,    //!< LSPCLK = SYSCLK / 6
    SYSCTL_LSPCLK_PRESCALE_8    = 4,    //!< LSPCLK = SYSCLK / 8
    SYSCTL_LSPCLK_PRESCALE_10   = 5,    //!< LSPCLK = SYSCLK / 10
    SYSCTL_LSPCLK_PRESCALE_12   = 6,    //!< LSPCLK = SYSCLK / 12
    SYSCTL_LSPCLK_PRESCALE_14   = 7     //!< LSPCLK = SYSCLK / 14
} SysCtl_LSPCLKPrescaler;

//*****************************************************************************
//
//! The following are values that can be passed to SysCtl_setEPWMClockDivider()
//! as the \e divider parameter.
//
//*****************************************************************************
typedef enum
{
    SYSCTL_EPWMCLK_DIV_1,           //!< EPWMCLK = PLLSYSCLK / 1
    SYSCTL_EPWMCLK_DIV_2            //!< EPWMCLK = PLLSYSCLK / 2
} SysCtl_EPWMCLKDivider;

//*****************************************************************************
//
//! The following are values that can be passed to
//! SysCtl_setEMIF1ClockDivider() as the \e divider parameter.
//
//*****************************************************************************
typedef enum
{
    SYSCTL_EMIF1CLK_DIV_1,           //!< EMIF1CLK = PLLSYSCLK / 1
    SYSCTL_EMIF1CLK_DIV_2            //!< EMIF1CLK = PLLSYSCLK / 2
} SysCtl_EMIF1CLKDivider;

//*****************************************************************************
//
//! The following are values that can be passed to
//! SysCtl_setEMIF2ClockDivider() as the \e divider parameter.
//
//*****************************************************************************
typedef enum
{
    SYSCTL_EMIF2CLK_DIV_1,           //!< EMIF2CLK = PLLSYSCLK / 1
    SYSCTL_EMIF2CLK_DIV_2            //!< EMIF2CLK = PLLSYSCLK / 2
} SysCtl_EMIF2CLKDivider;

//*****************************************************************************
//
//! The following are values that can be passed to
//! SysCtl_setPeripheralAccessControl() and SysCtl_getPeripheralAccessControl()
//! as the \e peripheral parameter.
//
//*****************************************************************************
typedef enum
{
    // ADC
    SYSCTL_ACCESS_ADCA            = 0x0,    //!< ADCA access
    SYSCTL_ACCESS_ADCB            = 0x2,    //!< ADCB access
    SYSCTL_ACCESS_ADCC            = 0x4,    //!< ADCC access
    SYSCTL_ACCESS_ADCD            = 0x6,    //!< ADCD access

    // CMPSS
    SYSCTL_ACCESS_CMPSS1          = 0x10,   //!< CMPSS1 access
    SYSCTL_ACCESS_CMPSS2          = 0x12,   //!< CMPSS2 access
    SYSCTL_ACCESS_CMPSS3          = 0x14,   //!< CMPSS3 access
    SYSCTL_ACCESS_CMPSS4          = 0x16,   //!< CMPSS4 access
    SYSCTL_ACCESS_CMPSS5          = 0x18,   //!< CMPSS5 access
    SYSCTL_ACCESS_CMPSS6          = 0x1A,   //!< CMPSS6 access
    SYSCTL_ACCESS_CMPSS7          = 0x1C,   //!< CMPSS7 access
    SYSCTL_ACCESS_CMPSS8          = 0x1E,   //!< CMPSS8 access

    // DAC
    SYSCTL_ACCESS_DACA            = 0x28,   //!< DACA access
    SYSCTL_ACCESS_DACB            = 0x2A,   //!< DACB access
    SYSCTL_ACCESS_DACC            = 0x2C,   //!< DACC access


    // EPWM
    SYSCTL_ACCESS_EPWM1           = 0x48,   //!< ePWM1 access
    SYSCTL_ACCESS_EPWM2           = 0x4A,   //!< ePWM2 access
    SYSCTL_ACCESS_EPWM3           = 0x4C,   //!< ePWM3 access
    SYSCTL_ACCESS_EPWM4           = 0x4E,   //!< ePWM4 access
    SYSCTL_ACCESS_EPWM5           = 0x50,   //!< ePWM5 access
    SYSCTL_ACCESS_EPWM6           = 0x52,   //!< ePWM6 access
    SYSCTL_ACCESS_EPWM7           = 0x54,   //!< ePWM7 access
    SYSCTL_ACCESS_EPWM8           = 0x56,   //!< ePWM8 access
    SYSCTL_ACCESS_EPWM9           = 0x58,   //!< ePWM9 access
    SYSCTL_ACCESS_EPWM10          = 0x5A,   //!< ePWM10 access
    SYSCTL_ACCESS_EPWM11          = 0x5C,   //!< ePWM11 access
    SYSCTL_ACCESS_EPWM12          = 0x5E,   //!< ePWM12 access
    SYSCTL_ACCESS_EPWM13          = 0x60,   //!< ePWM13 access
    SYSCTL_ACCESS_EPWM14          = 0x62,   //!< ePWM14 access
    SYSCTL_ACCESS_EPWM15          = 0x64,   //!< ePWM15 access
    SYSCTL_ACCESS_EPWM16          = 0x66,   //!< ePWM16 access

    // EQEP
    SYSCTL_ACCESS_EQEP1           = 0x70,   //!< eQEP1 access
    SYSCTL_ACCESS_EQEP2           = 0x72,   //!< eQEP2 access
    SYSCTL_ACCESS_EQEP3           = 0x74,   //!< eQEP3 access

    // ECAP
    SYSCTL_ACCESS_ECAP1           = 0x80,   //!< eCAP1 access
    SYSCTL_ACCESS_ECAP2           = 0x82,   //!< eCAP2 access
    SYSCTL_ACCESS_ECAP3           = 0x84,   //!< eCAP3 access
    SYSCTL_ACCESS_ECAP4           = 0x86,   //!< eCAP4 access
    SYSCTL_ACCESS_ECAP5           = 0x88,   //!< eCAP5 access
    SYSCTL_ACCESS_ECAP6           = 0x8A,   //!< eCAP6 access
    SYSCTL_ACCESS_ECAP7           = 0x8C,   //!< eCAP7 access

    // SDFM
    SYSCTL_ACCESS_SDFM1           = 0xA8,   //!< SDFM1 access
    SYSCTL_ACCESS_SDFM2           = 0xAA,   //!< SDFM2 access

    // CLB
    SYSCTL_ACCESS_CLB1            = 0xB0,   //!< CLB1 access
    SYSCTL_ACCESS_CLB2            = 0xB2,   //!< CLB2 access
    SYSCTL_ACCESS_CLB3            = 0xB4,   //!< CLB3 access
    SYSCTL_ACCESS_CLB4            = 0xB6,   //!< CLB4 access
    SYSCTL_ACCESS_CLB5            = 0xB8,   //!< CLB5 access
    SYSCTL_ACCESS_CLB6            = 0xBA,   //!< CLB6 access
    SYSCTL_ACCESS_CLB7            = 0xBC,   //!< CLB7 access
    SYSCTL_ACCESS_CLB8            = 0xBE,   //!< CLB8 access


    // SPI
    SYSCTL_ACCESS_SPIA            = 0x110,  //!< SPIA access
    SYSCTL_ACCESS_SPIB            = 0x112,  //!< SPIB access
    SYSCTL_ACCESS_SPIC            = 0x114,  //!< SPIC access
    SYSCTL_ACCESS_SPID            = 0x116,  //!< SPID access

    // PMBUS
    SYSCTL_ACCESS_PMBUS_A         = 0x130,  //!< PMBusA access

    // CAN
    SYSCTL_ACCESS_CANA            = 0x140,  //!< CANA access
    SYSCTL_ACCESS_CANB            = 0x142,  //!< CANB access
    // MCBSP
    SYSCTL_ACCESS_MCBSPA          = 0x150,  //!< MCBSPA access
    SYSCTL_ACCESS_MCBSPB          = 0x152,  //!< MCBSPB access

    // USBA
    SYSCTL_ACCESS_USBA            = 0x180,  //!< USBA access
    // HRPWM
    SYSCTL_ACCESS_HRPWM_A         = 0x1A8,  //!< HRPWM access

    // ECAT
    SYSCTL_ACCESS_ECAT            = 0x1AA,  //!< ECAT access

    // FSI
    SYSCTL_ACCESS_FSIATX          = 0x1B0,  //!< FSITXA access
    SYSCTL_ACCESS_FSIARX          = 0x1B2,  //!< FSIRXA access
    SYSCTL_ACCESS_FSIBTX          = 0x1B4,  //!< FSITXB access
    SYSCTL_ACCESS_FSIBRX          = 0x1B6,  //!< FSIRXB access
    SYSCTL_ACCESS_FSICRX          = 0x1BA,  //!< FSIRXC access
    SYSCTL_ACCESS_FSIDRX          = 0x1BE,  //!< FSIRXD access
    SYSCTL_ACCESS_FSIERX          = 0x1C2,  //!< FSIRXE access
    SYSCTL_ACCESS_FSIFRX          = 0x1C6,  //!< FSIRXF access
    SYSCTL_ACCESS_FSIGRX          = 0x1CA,  //!< FSIRXG access
    SYSCTL_ACCESS_FSIHRX          = 0x1CE   //!< FSIRXH access
} SysCtl_AccessPeripheral;

//*****************************************************************************
//
//! The following are values that can be passed to
//! SysCtl_setPeripheralAccessControl() and SysCtl_getPeripheralAccessControl()
//! as the \e master parameter.
//
//*****************************************************************************
typedef enum
{
    SYSCTL_ACCESS_CPU1  = 0U,   //!< CPU access to the peripheral
    SYSCTL_ACCESS_CLA1  = 2U,   //!< CLA1 access to the peripheral
    SYSCTL_ACCESS_DMA1  = 4U    //!< DMA access to the peripheral
} SysCtl_AccessMaster;
//*****************************************************************************
//
//! The following are values that can be passed to
//! SysCtl_setPeripheralAccessControl() as the \e permission parameter.
//
//*****************************************************************************
typedef enum
{
    //! Full Access for both read and write.
    SYSCTL_ACCESS_FULL      = 3U,
    //! Protected RD access such that FIFOs. Clear on read, registers are not
    //! changed and no write access.
    SYSCTL_ACCESS_PROTECTED = 2U,
    //! No read or write access.
    SYSCTL_ACCESS_NONE      = 0U
} SysCtl_AccessPermission;

//*****************************************************************************
//
//! The following are values that can be passed to
//! SysCtl_selectClockOutSource() as the \e source parameter.
//
//*****************************************************************************
typedef enum
{
    SYSCTL_CLOCKOUT_PLLSYS     = 0U,   //!< PLL System Clock
    SYSCTL_CLOCKOUT_PLLRAW     = 1U,   //!< PLL Raw Clock
    SYSCTL_CLOCKOUT_SYSCLK     = 2U,   //!< CPU System Clock
    SYSCTL_CLOCKOUT_SYSCLK2    = 3U,   //!< CPU 2 System Clock
    SYSCTL_CLOCKOUT_AUXPLLCLK  = 4U,   //!< Aux PLL Clock
    SYSCTL_CLOCKOUT_INTOSC1    = 5U,   //!< Internal Oscillator 1
    SYSCTL_CLOCKOUT_INTOSC2    = 6U,   //!< Internal Oscillator 2
    SYSCTL_CLOCKOUT_XTALOSC    = 7U,   //!< External Oscillator
    SYSCTL_CLOCKOUT_CMCLK      = 8U,   //!< CMCLK 
    SYSCTL_CLOCKOUT_PUMPOSC    = 9U    //!< PUMPOSC
} SysCtl_ClockOut;

//*****************************************************************************
//
//! The following are values that can be passed to
//! SysCtl_setExternalOscMode() as the \e mode parameter.
//
//*****************************************************************************
typedef enum
{
    SYSCTL_XTALMODE_CRYSTAL = 1U,   //!< XTAL Oscillator Crystal Mode
    SYSCTL_XTALMODE_SINGLE  = 2U    //!< XTAL Oscillator Single-Ended Mode
} SysCtl_ExternalOscMode;


//*****************************************************************************
//
//! The following values define the \e syncSrc parameter for
//! SysCtl_setSyncOutputConfig().
//
//*****************************************************************************
typedef enum
{
  SYSCTL_SYNC_OUT_SRC_EPWM1SYNCOUT  = 0X0U,  //!< EPWM1SYNCOUT --> EXTSYNCOUT
  SYSCTL_SYNC_OUT_SRC_EPWM2SYNCOUT  = 0X1U,  //!< EPWM2SYNCOUT --> EXTSYNCOUT
  SYSCTL_SYNC_OUT_SRC_EPWM3SYNCOUT  = 0X2U,  //!< EPWM3SYNCOUT --> EXTSYNCOUT
  SYSCTL_SYNC_OUT_SRC_EPWM4SYNCOUT  = 0X3U,  //!< EPWM4SYNCOUT --> EXTSYNCOUT
  SYSCTL_SYNC_OUT_SRC_EPWM5SYNCOUT  = 0X4U,  //!< EPWM5SYNCOUT --> EXTSYNCOUT
  SYSCTL_SYNC_OUT_SRC_EPWM6SYNCOUT  = 0X5U,  //!< EPWM6SYNCOUT --> EXTSYNCOUT
  SYSCTL_SYNC_OUT_SRC_EPWM7SYNCOUT  = 0X6U,  //!< EPWM7SYNCOUT --> EXTSYNCOUT
  SYSCTL_SYNC_OUT_SRC_EPWM8SYNCOUT  = 0X7U,  //!< EPWM8SYNCOUT --> EXTSYNCOUT
  SYSCTL_SYNC_OUT_SRC_EPWM9SYNCOUT  = 0X8U,  //!< EPWM9SYNCOUT --> EXTSYNCOUT
  SYSCTL_SYNC_OUT_SRC_EPWM10SYNCOUT = 0X9U,  //!< EPWM10SYNCOUT --> EXTSYNCOUT
  SYSCTL_SYNC_OUT_SRC_EPWM11SYNCOUT = 0XAU,  //!< EPWM11SYNCOUT --> EXTSYNCOUT
  SYSCTL_SYNC_OUT_SRC_EPWM12SYNCOUT = 0XBU,  //!< EPWM12SYNCOUT --> EXTSYNCOUT
  SYSCTL_SYNC_OUT_SRC_EPWM13SYNCOUT = 0XCU,  //!< EPWM13SYNCOUT --> EXTSYNCOUT
  SYSCTL_SYNC_OUT_SRC_EPWM14SYNCOUT = 0XDU,  //!< EPWM14SYNCOUT --> EXTSYNCOUT
  SYSCTL_SYNC_OUT_SRC_EPWM15SYNCOUT = 0XEU,  //!< EPWM15SYNCOUT --> EXTSYNCOUT
  SYSCTL_SYNC_OUT_SRC_EPWM16SYNCOUT = 0XFU,  //!< EPWM16SYNCOUT --> EXTSYNCOUT
  SYSCTL_SYNC_OUT_SRC_ECAP1SYNCOUT  = 0x18,  //!< ECAP1SYNCOUT --> EXTSYNCOUT
  SYSCTL_SYNC_OUT_SRC_ECAP2SYNCOUT  = 0x19,  //!< ECAP2SYNCOUT --> EXTSYNCOUT
  SYSCTL_SYNC_OUT_SRC_ECAP3SYNCOUT  = 0x20,  //!< ECAP3SYNCOUT --> EXTSYNCOUT
  SYSCTL_SYNC_OUT_SRC_ECAP4SYNCOUT  = 0x21,  //!< ECAP4SYNCOUT --> EXTSYNCOUT
  SYSCTL_SYNC_OUT_SRC_ECAP5SYNCOUT  = 0x22,  //!< ECAP5SYNCOUT --> EXTSYNCOUT
  SYSCTL_SYNC_OUT_SRC_ECAP6SYNCOUT  = 0x23,  //!< ECAP6SYNCOUT --> EXTSYNCOUT
  SYSCTL_SYNC_OUT_SRC_ECAP7SYNCOUT  = 0x24   //!< ECAP7SYNCOUT --> EXTSYNCOUT

} SysCtl_SyncOutputSource;

//*****************************************************************************
//
//! The following values define the \e parametric parameter for
//! SysCtl_getDeviceParametric().
//
//*****************************************************************************
typedef enum
{
    SYSCTL_DEVICE_TEMPERATURE,//!< Device Temperature
    SYSCTL_DEVICE_PACKAGE,    //!< Device Package
    SYSCTL_DEVICE_QUAL,       //!< Device Qualification Status
    SYSCTL_DEVICE_PINCOUNT,   //!< Device Pin Count
    SYSCTL_DEVICE_INSTASPIN,  //!< Device InstaSPIN Feature Set
    SYSCTL_DEVICE_FLASH,      //!< Device Flash size (KB)
    SYSCTL_DEVICE_PARTID,     //!< Device Part ID Format Revision
    SYSCTL_DEVICE_FAMILY,     //!< Device Family
    SYSCTL_DEVICE_PARTNO,     //!< Device Part Number
    SYSCTL_DEVICE_CLASSID     //!< Device Class ID
} SysCtl_DeviceParametric;

//*****************************************************************************
//
//! The following are values that can be passed to
//! SysCtl_lockConfigRegs() as the \e master parameter.
//
//*****************************************************************************
typedef enum
{
  SYSCTL_DC_PERCNF_PARTID, //!< Allows/Blocks write to Device config registers
  SYSCTL_BANKSEL           //!< Allows/Blocks write to BANKSEL registers
    
}SysCtl_DeviceConf;

//*****************************************************************************
//
//! The following are values that can be passed to SysCtl_controlCMReset() &
//! SysCtl_CPU2Reset() as the \e master parameter.
//
//*****************************************************************************
typedef enum
{
    SYSCTL_CORE_DEACTIVE,   //!< Core reset is deactivated 
    SYSCTL_CORE_ACTIVE      //!< Core is held in reset 
    
}SysCtl_CoreReset;

//*****************************************************************************
//
//! The following are values that can be passed to
//! SysCtl_configureADCWrapper as the \e peripheral parameter.
//
//*****************************************************************************
typedef enum
{
    // ADC
    SYSCTL_SELECT_ADCA,    //!< ADCA access
    SYSCTL_SELECT_ADCB,    //!< ADCB access
    SYSCTL_SELECT_ADCC,    //!< ADCC access
    SYSCTL_SELECT_ADCD     //!< ADCD access
    
}SysCtl_SelADC;

//*****************************************************************************
//
//! The following are values that can be passed to
//! SysCtl_configureADCWrapper() as the \e prescaler parameter.
//
//*****************************************************************************
typedef enum
{
    //! ADC can operate in 16-bit or 12-bit configurable
    SYSCTL_ADC_MODE_BOTH,
    //! ADC can operate only in 12-bit configurable
    SYSCTL_ADC_MODE_12BIT
    
} SysCtl_ADCMode;

//*****************************************************************************
//
//! The following are values that can be passed to
//! SysCtl_selectbank() as the \e prescaler parameter.
//
//*****************************************************************************
typedef enum
{
    //! CPU1BANK
    SYSCTL_CPU1BANK,
    //! CPU2BANK (CPU1BANK in read mode)
    SYSCTL_CPU2BANK,
    //! CMBANK   (CPU1BANK in read mode)
    SYSCTL_CMBANK   
    
}SysCtl_CPUBank;

//*****************************************************************************
//
//! The following are values that can be passed to SysCtl_configureType()
//! as the \e peripheral parameter.
//
//*****************************************************************************
typedef enum
{
    //!Configure USB Type for the device
    SYSCTL_USBTYPE = 0x0,
    //!Configure ECAP Type for the device
    SYSCTL_ECAPTYPE = 0x1,
    //!Configure SDFM Type for the device
    SYSCTL_SDFMTYPE = 0x2,
    //! Configure MEMMAP Type for the device
    SYSCTL_MEMMAPTYPE = 0x4
    
}SysCtl_SelType;

//*****************************************************************************
//
//! The following are values that can be passed to 
//! SysCtl_isPeripheralClockStopAcked()as the \e peripheral parameter.
//
//*****************************************************************************
typedef enum
{
    // CLKSTOPACK
    SYSCTL_PERIPH_ACK_MCAN_A      = 0x0800U,  //!< MCAN_A clock
    
} SysCtl_PeripheralClkStopAck;

//*****************************************************************************
//
//! The following are values that can be passed to 
//! SysCtl_reqPeripheralClockStop()as the \e peripheral parameter.
//
//*****************************************************************************
typedef enum
{
    //CLKSTOPREQ 
    SYSCTL_PERIPH_REQ_MCAN_A      = 0x0800U,  //!< MCAN_A clock

} SysCtl_PeripheralClkStopReq;

//*****************************************************************************
//
//! The following are values that can be passed to 
//! SysCtl_allocateSharedPeripheral() as the \e peripheral parameter.
//
//*****************************************************************************
typedef enum
{
    SYSCTL_PALLOCATE_USBA,     //!< Allocate USB_A to CM
    SYSCTL_PALLOCATE_ETHERCAT, //!< Allocate ETHERCAT to CM
    SYSCTL_PALLOCATE_CAN_A,    //!< Allocate CAN_A to CM
    SYSCTL_PALLOCATE_CAN_B,    //!< Allocate CAN_B to CM
    SYSCTL_PALLOCATE_MCAN_A,   //!< Allocate MCAN_A to CM
    
}SysCtl_SharedPeripheral;

//*****************************************************************************
//
//! The following are values that can be passed to
//! SysCtl_setXClk() as \e cpuInst parameter.
//
//*****************************************************************************
typedef enum
{
  SYSCTL_XCLKOUT_DIV_1  = 1,      //!<  XCLKOUT =  XCLKOUT / 1
  SYSCTL_XCLKOUT_DIV_2  = 2,      //!<  XCLKOUT =  XCLKOUT / 2
  SYSCTL_XCLKOUT_DIV_4  = 3,      //!<  XCLKOUT =  XCLKOUT / 4
  SYSCTL_XCLKOUT_DIV_8  = 4       //!<  XCLKOUT =  XCLKOUT / 8
  
}SysCtl_XClkDivider;

//*****************************************************************************
//
//! The following are values that can be passed to
//! SysCtl_setCMClk() as \e cpuInst parameter.
//
//*****************************************************************************
typedef enum
{
  SYSCTL_CMCLKOUT_DIV_1,      //!<  CM clock =  CM clock / 1
  SYSCTL_CMCLKOUT_DIV_2,      //!<  CM clock =  CM clock / 2
  SYSCTL_CMCLKOUT_DIV_3,      //!<  CM clock =  CM clock / 3
  SYSCTL_CMCLKOUT_DIV_4,      //!<  CM clock =  CM clock / 4
  SYSCTL_CMCLKOUT_DIV_5,      //!<  CM clock =  CM clock / 5
  SYSCTL_CMCLKOUT_DIV_6,      //!<  CM clock =  CM clock / 6
  SYSCTL_CMCLKOUT_DIV_7,      //!<  CM clock =  CM clock / 7
  SYSCTL_CMCLKOUT_DIV_8       //!<  CM clock =  CM clock / 8
  
}SysCtl_CMClkDivider;

//*****************************************************************************
//
//! The following are values that can be passed to
//! SysCtl_setECatClk() as \e cpuInst parameter.
//
//*****************************************************************************
typedef enum
{
  SYSCTL_ECATCLKOUT_DIV_1,      //!<  ECat clock =  ECat clock / 1
  SYSCTL_ECATCLKOUT_DIV_2,      //!<  ECat clock =  ECat clock / 2
  SYSCTL_ECATCLKOUT_DIV_3,      //!<  ECat clock =  ECat clock / 3
  SYSCTL_ECATCLKOUT_DIV_4,      //!<  ECatclock =  ECat clock / 4
  SYSCTL_ECATCLKOUT_DIV_5,      //!<  ECat clock =  ECat clock / 5
  SYSCTL_ECATCLKOUT_DIV_6,      //!<  ECat clock =  ECat clock / 6
  SYSCTL_ECATCLKOUT_DIV_7,      //!<  ECat clock =  ECat clock / 7
  SYSCTL_ECATCLKOUT_DIV_8       //!<  ECat clock =  ECat clock / 8
  
}SysCtl_ECatClkDivider;

//*****************************************************************************
//
//! The following are values that can be passed to SysCtl_setCMClk() &
//! SysCtl_setECatClk() as \e cpuInst parameter.
//
//*****************************************************************************
typedef enum
{
  //! Auxillary PLL is the source for the clock divider.
  SYSCTL_SOURCE_AUXPLL,
  //! System PLL is the source for the clock divider.
  SYSCTL_SOURCE_SYSPLL
  
}SysCtl_PLLClockSource;

//*****************************************************************************
//
//! The following are values that can be passed to SysCtl_lockClkConfig()
//! as the \e peripheral parameter.
//
//*****************************************************************************
typedef enum
{
    // CLKCFGLOCK1
    SYSCTL_REG_SEL_CLKSRCCTL1       = 0x0000,  //!< CLKSRCCTL1 lock
    SYSCTL_REG_SEL_CLKSRCCTL2       = 0x0100,  //!< CLKSRCCTL2 lock
    SYSCTL_REG_SEL_CLKSRCCTL3       = 0x0200,  //!< CLKSRCCTL3 lock
    SYSCTL_REG_SEL_SYSPLLCTL1       = 0x0300,  //!< SYSPLLCTL1 lock
    SYSCTL_REG_SEL_SYSPLLCTL2       = 0x0400,  //!< SYSPLLCTL2 lock
    SYSCTL_REG_SEL_SYSPLLCTL3       = 0x0500,  //!< SYSPLLCTL3 lock
    SYSCTL_REG_SEL_SYSPLLMULT       = 0x0600,  //!< SYSPLLMULTlock
    SYSCTL_REG_SEL_AUXPLLCTL1       = 0x0700,  //!< AUXPLLCTL1 lock
    SYSCTL_REG_SEL_AUXPLLMULT       = 0x0A00,  //!< AUXPLLMULT lock
    SYSCTL_REG_SEL_SYSCLKDIVSEL     = 0x0B00,  //!< SYSCLKDIVSEL lock
    SYSCTL_REG_SEL_AUXCLKDIVSEL     = 0x0C00,  //!< AUXCLKDIVSEL lock
    SYSCTL_REG_SEL_PERCLKDIVSEL     = 0x0D00,  //!< PERCLKDIVSEL lock
    SYSCTL_REG_SEL_CLBCLKCTL        = 0x0E00,  //!< CLBCLKCTL lock
    SYSCTL_REG_SEL_LOSPCP           = 0x0F00,  //!< LOSPCP lock
    SYSCTL_REG_SEL_XTALCR           = 0x1000,  //!< XTALCR lock
    SYSCTL_REG_SEL_ETHERCATCLKCTL   = 0x1100,  //!< ETHERCATCLKCTL lock
    SYSCTL_REG_SEL_CMCLKCTL         = 0x1200   //!< CMCLKCTL lock
    
} SysCtl_ClkRegSel;

//*****************************************************************************
//
//! The following are values that can be passed to SysCtl_lockSysConfig()
//! as the \e peripheral parameter.
//
//*****************************************************************************
typedef enum
{
    // CPUSYSLOCK1
    SYSCTL_REG_SEL_PIEVERRADDR      = 0x0200,  //!< PIEVERRADDR lock
    SYSCTL_REG_SEL_PCLKCR0          = 0x0300,  //!< PCLKCR0 lock
    SYSCTL_REG_SEL_PCLKCR1          = 0x0400,  //!< PCLKCR1 lock
    SYSCTL_REG_SEL_PCLKCR2          = 0x0500,  //!< PCLKCR2 lock
    SYSCTL_REG_SEL_PCLKCR3          = 0x0600,  //!< PCLKCR3 lock
    SYSCTL_REG_SEL_PCLKCR4          = 0x0700,  //!< PCLKCR4 lock
    SYSCTL_REG_SEL_PCLKCR6          = 0x0900,  //!< PCLKCR6 lock
    SYSCTL_REG_SEL_PCLKCR7          = 0x0A00,  //!< PCLKCR7 lock
    SYSCTL_REG_SEL_PCLKCR8          = 0x0B00,  //!< PCLKCR8 lock
    SYSCTL_REG_SEL_PCLKCR9          = 0x0C00,  //!< PCLKCR9 lock
    SYSCTL_REG_SEL_PCLKCR10         = 0x0D00,  //!< PCLKCR10 lock
    SYSCTL_REG_SEL_PCLKCR11         = 0x0E00,  //!< PCLKCR11 lock
    SYSCTL_REG_SEL_PCLKCR13         = 0x1000,  //!< PCLKCR13 lock
    SYSCTL_REG_SEL_PCLKCR14         = 0x1100,  //!< PCLKCR14 lock
    SYSCTL_REG_SEL_PCLKCR16         = 0x1300,  //!< PCLKCR16 lock
    SYSCTL_REG_SEL_SECMSEL          = 0x1400,  //!< SECMSEL lock
    SYSCTL_REG_SEL_LPMCR            = 0x1500,  //!< LPMCR lock
    SYSCTL_REG_SEL_GPIOLPMSEL0      = 0x1600,  //!< GPIOLPMSEL0 lock
    SYSCTL_REG_SEL_GPIOLPMSEL1      = 0x1700,  //!< GPIOLPMSEL1 lock
    SYSCTL_REG_SEL_PCLKCR17         = 0x1800,  //!< PCLKCR17 lock
    SYSCTL_REG_SEL_PCLKCR18         = 0x1900,  //!< PCLKCR18 lock
    SYSCTL_REG_SEL_PCLKCR20         = 0x1B00,  //!< PCLKCR20 lock
    SYSCTL_REG_SEL_PCLKCR21         = 0x1C00,  //!< PCLKCR21 lock
    SYSCTL_REG_SEL_PCLKCR22         = 0x1D00,  //!< PCLKCR22 lock
    SYSCTL_REG_SEL_PCLKCR23         = 0x1E00,  //!< PCLKCR23 lock

    //CPUSYSLOCK2
    SYSCTL_REG_SEL_ETHERCATCTL      = 0x0001   //!< ETHERCATCTL lock

} SysCtl_CpuRegSel;


//*****************************************************************************
//
//! The following are values that can be passed to
//! SysCtl_setCLBClk() as \e cpuInst parameter.
//
//*****************************************************************************
typedef enum
{
  SYSCTL_CLBCLKOUT_DIV_1,      //!<  CLB clock =  CLB clock / 1
  SYSCTL_CLBCLKOUT_DIV_2,      //!<  CLB clock =  CLB clock / 2
  SYSCTL_CLBCLKOUT_DIV_3,      //!<  CLB clock =  CLB clock / 3
  SYSCTL_CLBCLKOUT_DIV_4,      //!<  CLB clock =  CLB clock / 4
  SYSCTL_CLBCLKOUT_DIV_5,      //!<  CLB clock =  CLB clock / 5
  SYSCTL_CLBCLKOUT_DIV_6,      //!<  CLB clock =  CLB clock / 6
  SYSCTL_CLBCLKOUT_DIV_7,      //!<  CLB clock =  CLB clock / 7
  SYSCTL_CLBCLKOUT_DIV_8       //!<  CLB clock =  CLB clock / 8
  
}SysCtl_CLBClkDivider;

typedef enum
{
  SYSCTL_CLBTCLKOUT_DIV_1,      //!<  CLBTCLKOUT =  CLB clock / 1
  SYSCTL_CLBTCLKOUT_DIV_2       //!<  CLBTCLKOUT =  CLB clock / 2
  
}SysCtl_CLBTClkDivider;

typedef enum
{
  SYSCTL_CLB1  = 0x10,      //!<  CLB 1 instance 
  SYSCTL_CLB2  = 0x11,      //!<  CLB 2 instance 
  SYSCTL_CLB3  = 0x12,      //!<  CLB 3 instance 
  SYSCTL_CLB4  = 0x13,      //!<  CLB 4 instance 
  SYSCTL_CLB5  = 0x14,      //!<  CLB 5 instance 
  SYSCTL_CLB6  = 0x15,      //!<  CLB 6 instance 
  SYSCTL_CLB7  = 0x16,      //!<  CLB 7 instance 
  SYSCTL_CLB8  = 0x17       //!<  CLB 8 instance 
  
}SysCtl_CLBInst;

typedef enum
{
  SYSCTL_CLBCLK_SYNC,       //!<  CLB is synchronous to SYSCLK
  SYSCTL_CLBCLK_ASYNC       //!<  CLB runs of asynchronous clock
  
}SysCtl_CLBClkm;


//*****************************************************************************
//
// Prototypes for the APIs.
//
//*****************************************************************************
//*****************************************************************************
//
//! Resets a peripheral
//!
//! \param peripheral is the peripheral to reset.
//!
//! This function uses the SOFTPRESx registers to reset a specified peripheral.
//! Module registers will be returned to their reset states.
//!
//! \note This includes registers containing trim values.
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_resetPeripheral(SysCtl_PeripheralSOFTPRES peripheral)
{
    uint16_t regIndex;
    uint16_t bitIndex;

    //
    // Decode the peripheral variable.
    //
    regIndex = (uint16_t)2U * ((uint16_t)peripheral &
                               (uint16_t)SYSCTL_PERIPH_REG_M);
    bitIndex = ((uint16_t)peripheral & SYSCTL_PERIPH_BIT_M) >>
               SYSCTL_PERIPH_BIT_S;

    EALLOW;

    //
    // Sets the appropriate reset bit and then clears it.
    //
    HWREG(DEVCFG_BASE + SYSCTL_O_SOFTPRES0 + regIndex) |=
        ((uint32_t)1U << bitIndex);
    HWREG(DEVCFG_BASE + SYSCTL_O_SOFTPRES0 + regIndex) &=
        ~((uint32_t)1U << bitIndex);

    EDIS;
}

//*****************************************************************************
//
//! Enables a peripheral.
//!
//! \param peripheral is the peripheral to enable.
//!
//! Peripherals are enabled with this function.  At power-up, all peripherals
//! are disabled; they must be enabled in order to operate or respond to
//! register reads/writes.
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_enablePeripheral(SysCtl_PeripheralPCLOCKCR peripheral)
{
    uint16_t regIndex;
    uint16_t bitIndex;

    //
    // Decode the peripheral variable.
    //
    regIndex = (uint16_t)2U * ((uint16_t)peripheral &
                               (uint16_t)SYSCTL_PERIPH_REG_M);
    bitIndex = ((uint16_t)peripheral & SYSCTL_PERIPH_BIT_M) >>
               SYSCTL_PERIPH_BIT_S;

    EALLOW;

    //
    // Turn on the module clock.
    //
    HWREG(CPUSYS_BASE + SYSCTL_O_PCLKCR0 + regIndex) |=
        ((uint32_t)1U << bitIndex);
    EDIS;
}

//*****************************************************************************
//
//! Disables a peripheral.
//!
//! \param peripheral is the peripheral to disable.
//!
//! Peripherals are disabled with this function.  Once disabled, they will not
//! operate or respond to register reads/writes.
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_disablePeripheral(SysCtl_PeripheralPCLOCKCR peripheral)
{
    uint16_t regIndex;
    uint16_t bitIndex;

    //
    // Decode the peripheral variable.
    //
    regIndex = (uint16_t)2U * ((uint16_t)peripheral &
                               (uint16_t)SYSCTL_PERIPH_REG_M);
    bitIndex = ((uint16_t)peripheral & SYSCTL_PERIPH_BIT_M) >>
               SYSCTL_PERIPH_BIT_S;

    EALLOW;

    //
    // Turn off the module clock.
    //
    HWREG(CPUSYS_BASE + SYSCTL_O_PCLKCR0 + regIndex) &=
        ~((uint32_t)1U << bitIndex);
    EDIS;
}

//*****************************************************************************
//
//! Determines if a peripheral is present.
//!
//! \param peripheral is the peripheral in question.
//!
//! This function determines if a particular peripheral is present in the
//! device.  Each member of the family has a different peripheral
//! set; this function determines which peripherals are present on this device.
//!
//! \note This function may return \b true for a peripheral that is present on
//! the device but is not usable in any practical way because of the
//! availability of GPIO pins on the package.
//!
//! \return Returns \b true if the specified peripheral is present and \b false
//! if it is not.
//
//*****************************************************************************
static inline bool
SysCtl_isPeripheralPresent(SysCtl_PeripheralDC peripheral)
{
    uint16_t regIndex;
    uint16_t bitIndex;
    bool status = false;

    //
    // Decode the peripheral variable.
    //
    regIndex = (uint16_t)2U * ((uint16_t)peripheral &
                               (uint16_t)SYSCTL_PERIPH_REG_M);
    bitIndex = ((uint16_t)peripheral & SYSCTL_PERIPH_BIT_M) >>
               SYSCTL_PERIPH_BIT_S;
    //
    // Read the appropriate DC register and peripheral bit and return.
    //
    if((HWREG(DEVCFG_BASE + SYSCTL_O_DC0 + regIndex) &
       ((uint32_t)1U << bitIndex)) != 0U)
    {
        status = true;
    }

    return(status);
}

//*****************************************************************************
//
//! Resets the device.
//!
//! This function performs a watchdog reset of the device.
//!
//! \return This function does not return.
//
//*****************************************************************************
static inline void
SysCtl_resetDevice(void)
{
    //
    // Write an incorrect check value to the watchdog control register
    // This will cause a device reset
    //
    EALLOW;

    // Enable the watchdog
    HWREGH(WD_BASE + SYSCTL_O_WDCR) = SYSCTL_WD_CHKBITS;

    // Write a bad check value
    HWREGH(WD_BASE + SYSCTL_O_WDCR) = 0U;

    EDIS;

    //
    // The device should have reset, so this should never be reached.  Just in
    // case, loop forever.
    //
    while(1)
    {
    }
}

//*****************************************************************************
//
//! Gets the reason for a reset.
//!
//! This function will return the reason(s) for a reset.  Since the reset
//! reasons are sticky until either cleared by software or an external reset,
//! multiple reset reasons may be returned if multiple resets have occurred.
//! The reset reason will be a logical OR of
//! - \b SYSCTL_CAUSE_POR - Power-on reset
//! - \b SYSCTL_CAUSE_XRS - External reset pin
//! - \b SYSCTL_CAUSE_WDRS - Watchdog reset
//! - \b SYSCTL_CAUSE_NMIWDRS - NMI watchdog reset
//! - \b SYSCTL_CAUSE_SCCRESET - SCCRESETn reset from DCSM
//! - \b SYSCTL_CAUSE_HWBISTN - HWBISTn reset    
//! - \b SYSCTL_CAUSE_ECAT_RESET_OUT - Ethercat Reset  
//! - \b SYSCTL_CAUSE_SIMRESET_CPU1RSN - SIMRESET from CPU1 
//! - \b SYSCTL_CAUSE_SIMRESET_XRSN - SIMRESET from XRSn
//! - \b SYSCTL_RESC_XRSN_PIN_STATUS - XRSN Pin Status
//! - \b SYSCTL_RESC_TRSTN_PIN_STATUS -TRSTN Pin Status
//!
//! \note If you re-purpose the reserved boot ROM RAM, the POR and XRS reset
//! statuses won't be accurate.
//!
//! \return Returns the reason(s) for a reset.
//
//*****************************************************************************
static inline uint32_t
SysCtl_getResetCause(void)
{
    uint32_t resetCauses;

    //
    // Read CPU reset register
    //
    resetCauses = HWREG(CPUSYS_BASE + SYSCTL_O_RESC) &
                  ((uint32_t)SYSCTL_RESC_POR | (uint32_t)SYSCTL_RESC_XRSN |
                   (uint32_t)SYSCTL_RESC_WDRSN |
                   (uint32_t)SYSCTL_RESC_NMIWDRSN |
                   (uint32_t)SYSCTL_RESC_SCCRESETN
                    |(uint32_t)SYSCTL_RESC_HWBISTN |
                   (uint32_t)SYSCTL_RESC_ECAT_RESET_OUT |
                   (uint32_t)SYSCTL_RESC_SIMRESET_CPU1RSN |
                   (uint32_t)SYSCTL_RESC_SIMRESET_XRSN |
                   (uint32_t)SYSCTL_RESC_XRSN_PIN_STATUS |
                   (uint32_t)SYSCTL_RESC_TRSTN_PIN_STATUS
                   );

    //
    // Set POR and XRS Causes from boot ROM Status
    //
    if((HWREG(SYSCTL_BOOT_ROM_STATUS) & (uint32_t)SYSCTL_BOOT_ROM_POR) ==
       (uint32_t)SYSCTL_BOOT_ROM_POR)
    {
        resetCauses |= SYSCTL_RESC_POR;
    }
    if((HWREG(SYSCTL_BOOT_ROM_STATUS) & (uint32_t)SYSCTL_BOOT_ROM_XRS) ==
       (uint32_t)SYSCTL_BOOT_ROM_XRS)
    {
        resetCauses |= SYSCTL_RESC_XRSN;
    }

    //
    // Return the reset reasons.
    //
    return(resetCauses);
}

//*****************************************************************************
//
//! Clears reset reasons.
//!
//! \param rstCauses are the reset causes to be cleared; must be a logical
//! OR of \b SYSCTL_CAUSE_POR, \b SYSCTL_CAUSE_XRS, \b SYSCTL_CAUSE_WDRS,
//! \b SYSCTL_CAUSE_NMIWDRS, 
//! \b SYSCTL_CAUSE_HWBISTN, 
//! \b SYSCTL_CAUSE_ECAT_RESET_OUT,\b SYSCTL_CAUSE_SIMRESET_CPU1RSN, 
//! \b SYSCTL_CAUSE_SIMRESET_XRSN
//! and/or \b SYSCTL_CAUSE_SCCRESET.
//!
//! This function clears the specified sticky reset reasons.  Once cleared,
//! another reset for the same reason can be detected, and a reset for a
//! different reason can be distinguished (instead of having two reset causes
//! set).  If the reset reason is used by an application, all reset causes
//! should be cleared after they are retrieved with SysCtl_getResetCause().
//!
//! \note Some reset causes are cleared by the boot ROM.
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_clearResetCause(uint32_t rstCauses)
{
    //
    // Clear the given reset reasons.
    //
    HWREG(CPUSYS_BASE + SYSCTL_O_RESCCLR) = rstCauses;
}

//*****************************************************************************
//
//! Sets the low speed peripheral clock rate prescaler.
//!
//! \param prescaler is the LSPCLK rate relative to SYSCLK
//!
//! This function configures the clock rate of the low speed peripherals. The
//! \e prescaler parameter is the value by which the SYSCLK rate is divided to
//! get the LSPCLK rate. For example, a \e prescaler of
//! \b SYSCTL_LSPCLK_PRESCALE_4 will result in a LSPCLK rate that is a quarter
//! of the SYSCLK rate.
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_setLowSpeedClock(SysCtl_LSPCLKPrescaler prescaler)
{
    //
    // Write the divider selection to the appropriate register.
    //
    EALLOW;
    HWREG(CLKCFG_BASE + SYSCTL_O_LOSPCP) =
        (HWREG(CLKCFG_BASE + SYSCTL_O_LOSPCP) & ~SYSCTL_LOSPCP_LSPCLKDIV_M) |
        (uint32_t)prescaler;
    EDIS;
}

//*****************************************************************************
//
//! Sets the ePWM clock divider.
//!
//! \param divider is the value by which PLLSYSCLK is divided
//!
//! This function configures the clock rate of the EPWMCLK. The
//! \e divider parameter is the value by which the SYSCLK rate is divided to
//! get the EPWMCLK rate. For example, \b SYSCTL_EPWMCLK_DIV_2 will select an
//! EPWMCLK rate that is half the PLLSYSCLK rate.
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_setEPWMClockDivider(SysCtl_EPWMCLKDivider divider)
{
    //
    // Write the divider selection to the appropriate register.
    //
    EALLOW;
    HWREGH(CLKCFG_BASE + SYSCTL_O_PERCLKDIVSEL) =
        (HWREGH(CLKCFG_BASE + SYSCTL_O_PERCLKDIVSEL) &
         ~SYSCTL_PERCLKDIVSEL_EPWMCLKDIV_M) | (uint16_t)divider;
    EDIS;
}

//*****************************************************************************
//
//! Sets the EMIF1 clock divider.
//!
//! \param divider is the value by which PLLSYSCLK (or CPU1.SYSCLK on a dual
//! core device) is divided
//!
//! This function configures the clock rate of the EMIF1CLK. The
//! \e divider parameter is the value by which the SYSCLK rate is divided to
//! get the EMIF1CLK rate. For example, \b SYSCTL_EMIF1CLK_DIV_2 will select an
//! EMIF1CLK rate that is half the PLLSYSCLK (or CPU1.SYSCLK on a dual
//! core device) rate.
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_setEMIF1ClockDivider(SysCtl_EMIF1CLKDivider divider)
{
    //
    // Write the divider selection to the appropriate register.
    //
    EALLOW;
    if(divider == SYSCTL_EMIF1CLK_DIV_2)
    {
        HWREGH(CLKCFG_BASE + SYSCTL_O_PERCLKDIVSEL) |=
            SYSCTL_PERCLKDIVSEL_EMIF1CLKDIV;
    }
    else
    {
        HWREGH(CLKCFG_BASE + SYSCTL_O_PERCLKDIVSEL) &=
            ~SYSCTL_PERCLKDIVSEL_EMIF1CLKDIV;
    }
    EDIS;
}

//*****************************************************************************
//
//! Sets the EMIF2 clock divider.
//!
//! \param divider is the value by which PLLSYSCLK (or CPU1.SYSCLK on a dual
//! core device) is divided
//!
//! This function configures the clock rate of the EMIF2CLK. The
//! \e divider parameter is the value by which the SYSCLK rate is divided to
//! get the EMIF2CLK rate. For example, \b SYSCTL_EMIF2CLK_DIV_2 will select an
//! EMIF2CLK rate that is half the PLLSYSCLK (or CPU1.SYSCLK on a dual
//! core device) rate.
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_setEMIF2ClockDivider(SysCtl_EMIF2CLKDivider divider)
{
    //
    // Write the divider selection to the appropriate register.
    //
    EALLOW;
    if(divider == SYSCTL_EMIF2CLK_DIV_2)
    {
        HWREGH(CLKCFG_BASE + SYSCTL_O_PERCLKDIVSEL) |=
            SYSCTL_PERCLKDIVSEL_EMIF2CLKDIV;
    }
    else
    {
        HWREGH(CLKCFG_BASE + SYSCTL_O_PERCLKDIVSEL) &=
            ~SYSCTL_PERCLKDIVSEL_EMIF2CLKDIV;
    }
    EDIS;
}

//*****************************************************************************
//
//! Selects a clock source to mux to an external GPIO pin (XCLKOUT).
//!
//! \param source is the internal clock source to be configured.
//!
//! This function configures the specified clock source to be muxed to an
//! external clock out (XCLKOUT) GPIO pin. The \e source parameter may take a
//! value of one of the following values:
//! - \b SYSCTL_CLOCKOUT_PLLSYS
//! - \b SYSCTL_CLOCKOUT_PLLRAW
//! - \b SYSCTL_CLOCKOUT_SYSCLK
//! - \b SYSCTL_CLOCKOUT_SYSCLK2   
//! - \b SYSCTL_CLOCKOUT_AUXPLLCLK 
//! - \b SYSCTL_CLOCKOUT_INTOSC1
//! - \b SYSCTL_CLOCKOUT_INTOSC2
//! - \b SYSCTL_CLOCKOUT_XTALOSC
//! - \b SYSCTL_CLOCKOUT_CMCLK     
//! - \b SYSCTL_CLOCKOUT_PUMPOSC  
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_selectClockOutSource(SysCtl_ClockOut source)
{
    EALLOW;

    //
    // Clear clock out source
    //
    HWREGH(CLKCFG_BASE + SYSCTL_O_CLKSRCCTL3) &=
        ~SYSCTL_CLKSRCCTL3_XCLKOUTSEL_M;

    //
    // Set clock out source
    //
    HWREGH(CLKCFG_BASE + SYSCTL_O_CLKSRCCTL3) |= (uint16_t)source;

    EDIS;
}

//*****************************************************************************
//
//! Set the external oscillator mode.
//!
//! \param mode is the external oscillator mode to be configured.
//!
//! This function sets the external oscillator mode specified by the \e mode
//! parameter which may take one of two values:
//! - \b SYSCTL_XTALMODE_CRYSTAL - Crystal Mode
//! - \b SYSCTL_XTALMODE_SINGLE  - Single-Ended Mode
//!
//! \note The external oscillator must be powered off before this configuration
//! can be performed.
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_setExternalOscMode(SysCtl_ExternalOscMode mode)
{
    EALLOW;

    switch(mode)
    {
        case SYSCTL_XTALMODE_CRYSTAL:
            // Set mode to Crystal
            HWREG(CLKCFG_BASE + SYSCTL_O_XTALCR) &= ~SYSCTL_XTALCR_SE;
            break;

        case SYSCTL_XTALMODE_SINGLE:
            // Set mode to Single-Ended
            HWREG(CLKCFG_BASE + SYSCTL_O_XTALCR) |= SYSCTL_XTALCR_SE;
            break;

        default:
            // Do nothing. Not a valid mode value.
            break;
    }

    EDIS;
}

//*****************************************************************************
//
//! Gets the external oscillator counter value.
//!
//! This function returns the X1 clock counter value. When the return value
//! reaches 0x3FF, it freezes. Before switching from INTOSC2 to an external
//! oscillator (XTAL), an application should call this function to make sure 
//! the counter is saturated.
//!
//! \return Returns the value of the 10-bit X1 clock counter.
//
//*****************************************************************************
static inline uint16_t
SysCtl_getExternalOscCounterValue(void)
{
    return(HWREGH(CLKCFG_BASE + SYSCTL_O_X1CNT) & SYSCTL_X1CNT_X1CNT_M);
}

//*****************************************************************************
//
//! Clears the external oscillator counter value.
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_clearExternalOscCounterValue(void)
{
    HWREG(CLKCFG_BASE + SYSCTL_O_X1CNT) |= SYSCTL_X1CNT_CLR;
}

//*****************************************************************************
//
//! Turns on the specified oscillator sources.
//!
//! \param oscSource is the oscillator source to be configured.
//!
//! This function turns on the oscillator specified by the \e oscSource
//! parameter which may take a value of  \b SYSCTL_OSCSRC_OSC2 or
//! \b SYSCTL_OSCSRC_XTAL.
//!
//! \note \b SYSCTL_OSCSRC_OSC1 is not a valid value for \e oscSource.
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_turnOnOsc(uint32_t oscSource)
{
    ASSERT((oscSource == SYSCTL_OSCSRC_OSC2) |
           (oscSource == SYSCTL_OSCSRC_XTAL));

    EALLOW;

    switch(oscSource)
    {
        case SYSCTL_OSCSRC_OSC2:
            // Turn on INTOSC2
            HWREGH(CLKCFG_BASE + SYSCTL_O_CLKSRCCTL1) &=
                ~SYSCTL_CLKSRCCTL1_INTOSC2OFF;
            break;

        case SYSCTL_OSCSRC_XTAL:
            // Turn on XTALOSC
            HWREGH(CLKCFG_BASE + SYSCTL_O_CLKSRCCTL1) &=
                ~SYSCTL_CLKSRCCTL1_XTALOFF;
            HWREGH(CLKCFG_BASE + SYSCTL_O_XTALCR) &= ~SYSCTL_XTALCR_OSCOFF;

            break;

        default:
            // Do nothing. Not a valid oscSource value.
            break;
    }

    EDIS;
}

//*****************************************************************************
//
//! Turns off the specified oscillator sources.
//!
//! \param oscSource is the oscillator source to be configured.
//!
//! This function turns off the oscillator specified by the \e oscSource
//! parameter which may take a value of  \b SYSCTL_OSCSRC_OSC2 or
//! \b SYSCTL_OSCSRC_XTAL.
//!
//! \note \b SYSCTL_OSCSRC_OSC1 is not a valid value for \e oscSource.
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_turnOffOsc(uint32_t oscSource)
{
    ASSERT((oscSource == SYSCTL_OSCSRC_OSC2) |
           (oscSource == SYSCTL_OSCSRC_XTAL));

    EALLOW;

    switch(oscSource)
    {
        case SYSCTL_OSCSRC_OSC2:
            // Turn off INTOSC2
            HWREGH(CLKCFG_BASE + SYSCTL_O_CLKSRCCTL1) |=
                SYSCTL_CLKSRCCTL1_INTOSC2OFF;
            break;

        case SYSCTL_OSCSRC_XTAL:
            // Turn off XTALOSC
            HWREGH(CLKCFG_BASE + SYSCTL_O_CLKSRCCTL1) |=
                SYSCTL_CLKSRCCTL1_XTALOFF;
            break;

        default:
            // Do nothing. Not a valid oscSource value.
            break;
    }

    EDIS;
}

//*****************************************************************************
//
//! Enters IDLE mode.
//!
//! This function puts the device into IDLE mode. The CPU clock is gated while
//! all peripheral clocks are left running. Any enabled interrupt will wake the
//! CPU up from IDLE mode.
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_enterIdleMode(void)
{
    EALLOW;

    //
    // Configure the device to go into IDLE mode when IDLE is executed.
    //
    HWREG(CPUSYS_BASE + SYSCTL_O_LPMCR) =
        (HWREG(CPUSYS_BASE + SYSCTL_O_LPMCR) & ~SYSCTL_LPMCR_LPM_M) |
        SYSCTL_LPM_IDLE;

    EDIS;

    IDLE;
}

//*****************************************************************************
//
//! Enters STANDBY mode.
//!
//! This function puts the device into STANDBY mode. This will gate both the
//! CPU clock and any peripheral clocks derived from SYSCLK. The watchdog is
//! left active, and an NMI or an optional watchdog interrupt will wake the
//! CPU subsystem from STANDBY mode.
//!
//! GPIOs may be configured to wake the CPU subsystem. See
//! SysCtl_enableLPMWakeupPin().
//!
//! The CPU will receive an interrupt (WAKEINT) on wakeup.
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_enterStandbyMode(void)
{
    EALLOW;

    //
    // Configure the device to go into STANDBY mode when IDLE is executed.
    //
    HWREG(CPUSYS_BASE + SYSCTL_O_LPMCR) =
        (HWREG(CPUSYS_BASE + SYSCTL_O_LPMCR) & ~SYSCTL_LPMCR_LPM_M) |
        SYSCTL_LPM_STANDBY;

    EDIS;

    IDLE;
}

//*****************************************************************************
//
//! Enters HALT mode.
//!
//! This function puts the device into HALT mode. This will gate almost all
//! systems and clocks and allows for the power-down of oscillators and analog
//! blocks. The watchdog may be left clocked to produce a reset. See
//! SysCtl_enableWatchdogInHalt() to enable this. GPIOs should be
//! configured to wake the CPU subsystem. See SysCtl_enableLPMWakeupPin().
//!
//! Enter HALT mode (dual CPU). Puts CPU2 in IDLE mode first.
//!
//! The CPU will receive an interrupt (WAKEINT) on wakeup.
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_enterHaltMode(void)
{

    #if defined(CPU2)
        EALLOW;
        //
        // Configure the device to go into IDLE mode when IDLE is executed.
        //
        HWREG(CPUSYS_BASE + SYSCTL_O_LPMCR) =
            (HWREG(CPUSYS_BASE + SYSCTL_O_LPMCR) & ~SYSCTL_LPMCR_LPM_M) |
            SYSCTL_LPM_IDLE;

        EDIS;
        asm(" IDLE");
    #elif defined(CPU1)
        EALLOW;

        //
        // Configure the device to go into HALT mode when IDLE is executed.
        //
        HWREG(CPUSYS_BASE + SYSCTL_O_LPMCR) =
            (HWREG(CPUSYS_BASE + SYSCTL_O_LPMCR) & ~SYSCTL_LPMCR_LPM_M) |
            SYSCTL_LPM_HALT;

        HWREGH(CLKCFG_BASE + 
               SYSCTL_O_SYSPLLCTL1) &= ~(SYSCTL_SYSPLLCTL1_PLLCLKEN |
                                         SYSCTL_SYSPLLCTL1_PLLEN);

        EDIS;

        IDLE;
    #endif
    
}

//*****************************************************************************
//
//! Enables a pin to wake up the device from STANDBY 
//! or HALT.
//!
//! \param pin is the identifying number of the pin.
//!
//! This function connects a pin to the LPM circuit, allowing an event on the
//! pin to wake up the device when when it is in STANDBY mode
//! or HALT mode.
//!
//! The pin is specified by its numerical value. For example, GPIO34 is
//! specified by passing 34 as \e pin. Only GPIOs 0 through 63 are capable of
//! being connected to the LPM circuit.
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_enableLPMWakeupPin(uint32_t pin)
{
    uint32_t pinMask;

    //
    // Check the arguments.
    //
    ASSERT(pin <= 63U);

    pinMask = (uint32_t)1U << (uint32_t)(pin % 32U);

    EALLOW;

    if(pin < 32U)
    {
        HWREG(CPUSYS_BASE + SYSCTL_O_GPIOLPMSEL0) |= pinMask;
    }
    else
    {
        HWREG(CPUSYS_BASE + SYSCTL_O_GPIOLPMSEL1) |= pinMask;
    }

    EDIS;
}

//*****************************************************************************
//
//! Disables a pin to wake up the device from STANDBY 
//! or HALT. 
//!
//! \param pin is the identifying number of the pin.
//!
//! This function disconnects a pin to the LPM circuit, disallowing an event on
//! the pin to wake up the device when when it is in STANDBY mode 
//! or HALT mode.
//!
//! The pin is specified by its numerical value. For example, GPIO34 is
//! specified by passing 34 as \e pin. Only GPIOs 0 through 63 are valid.
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_disableLPMWakeupPin(uint32_t pin)
{
    uint32_t pinMask;

    //
    // Check the arguments.
    //
    ASSERT(pin <= 63U);

    pinMask = (uint32_t)1U << (uint32_t)(pin % 32U);

    EALLOW;

    if(pin < 32U)
    {
        HWREG(CPUSYS_BASE + SYSCTL_O_GPIOLPMSEL0) &= ~pinMask;
    }
    else
    {
        HWREG(CPUSYS_BASE + SYSCTL_O_GPIOLPMSEL1) &= ~pinMask;
    }

    EDIS;
}

//*****************************************************************************
//
//! Sets the number of cycles to qualify an input on waking from STANDBY mode.
//!
//! \param cycles is the number of OSCCLK cycles.
//!
//! This function sets the number of OSCCLK clock cycles used to qualify the
//! selected inputs when waking from STANDBY mode. The \e cycles parameter
//! should be passed a cycle count between 2 and 65 cycles inclusive.
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_setStandbyQualificationPeriod(uint16_t cycles)
{
    //
    // Check the arguments.
    //
    ASSERT((cycles >= 2U) && (cycles <= 65U));

    EALLOW;

    HWREGH(CPUSYS_BASE + SYSCTL_O_LPMCR) =
        (HWREGH(CPUSYS_BASE + SYSCTL_O_LPMCR) &
         ~(uint16_t)SYSCTL_LPMCR_QUALSTDBY_M) |
        ((cycles - (uint16_t)2U) << SYSCTL_LPMCR_QUALSTDBY_S);

    EDIS;
}

//*****************************************************************************
//
//! Enable the device to wake from STANDBY mode upon a watchdog interrupt.
//!
//! \note In order to use this option, you must configure the watchdog to
//! generate an interrupt using SysCtl_setWatchdogMode().
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_enableWatchdogStandbyWakeup(void)
{
    EALLOW;

    //
    // Set the bit enables the watchdog to wake up the device from STANDBY.
    //
    HWREGH(CPUSYS_BASE + SYSCTL_O_LPMCR) |= SYSCTL_LPMCR_WDINTE;

    EDIS;
}

//*****************************************************************************
//
//! Disable the device from waking from STANDBY mode upon a watchdog interrupt.
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_disableWatchdogStandbyWakeup(void)
{
    EALLOW;

    //
    // Clear the bit enables the watchdog to wake up the device from STANDBY.
    //
    HWREGH(CPUSYS_BASE + SYSCTL_O_LPMCR) &= ~SYSCTL_LPMCR_WDINTE;

    EDIS;
}

//*****************************************************************************
//
//! Enable the watchdog to run while in HALT mode.
//!
//! This function configures the watchdog to continue to run while in HALT
//! mode. Additionally, INTOSC1 and INTOSC2 are not powered down when the
//! system enters HALT mode. By default the watchdog is gated when the system
//! enters HALT.
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_enableWatchdogInHalt(void)
{
    EALLOW;

    //
    // Set the watchdog HALT mode ignore bit.
    //
    HWREGH(CLKCFG_BASE + SYSCTL_O_CLKSRCCTL1) |= SYSCTL_CLKSRCCTL1_WDHALTI;

    EDIS;
}

//*****************************************************************************
//
//! Disable the watchdog from running while in HALT mode.
//!
//! This function gates the watchdog when the system enters HALT mode. INTOSC1
//! and INTOSC2 will be powered down. This is the default behavior of the
//! device.
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_disableWatchdogInHalt(void)
{
    EALLOW;

    //
    // Clear the watchdog HALT mode ignore bit.
    //
    HWREGH(CLKCFG_BASE + SYSCTL_O_CLKSRCCTL1) &= ~SYSCTL_CLKSRCCTL1_WDHALTI;

    EDIS;
}

//*****************************************************************************
//
//! Configures whether the watchdog generates a reset or an interrupt signal.
//!
//! \param mode is a flag to select the watchdog mode.
//!
//! This function configures the action taken when the watchdog counter reaches
//! its maximum value. When the \e mode parameter is
//! \b SYSCTL_WD_MODE_INTERRUPT, the watchdog is enabled to generate a watchdog
//! interrupt signal and disables the generation of a reset signal. This will
//! allow the watchdog module to wake up the device from IDLE or STANDBY if
//! desired (see SysCtl_enableWatchdogStandbyWakeup()).
//!
//! When the \e mode parameter is \b SYSCTL_WD_MODE_RESET, the watchdog will
//! be put into reset mode and generation of a watchdog interrupt signal will
//! be disabled. This is how the watchdog is configured by default.
//!
//! \note Check the status of the watchdog interrupt using
//! SysCtl_isWatchdogInterruptActive() before calling this function. If the
//! interrupt is still active, switching from interrupt mode to reset mode will
//! immediately reset the device.
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_setWatchdogMode(SysCtl_WDMode mode)
{
    EALLOW;

    //
    // Either set or clear the WDENINT bit to that will determine whether the
    // watchdog will generate a reset signal or an interrupt signal. Take care
    // not to write a 1 to WDOVERRIDE.
    //
    if(mode == SYSCTL_WD_MODE_INTERRUPT)
    {
        HWREGH(WD_BASE + SYSCTL_O_SCSR) = (HWREGH(WD_BASE + SYSCTL_O_SCSR) &
                                           ~SYSCTL_SCSR_WDOVERRIDE) |
                                          SYSCTL_SCSR_WDENINT;
    }
    else
    {
        HWREGH(WD_BASE + SYSCTL_O_SCSR) &= ~(SYSCTL_SCSR_WDENINT |
                                             SYSCTL_SCSR_WDOVERRIDE);
    }

    EDIS;
}

//*****************************************************************************
//
//! Gets the status of the watchdog interrupt signal.
//!
//! This function returns the status of the watchdog interrupt signal. If the
//! interrupt is active, this function will return \b true. If \b false, the
//! interrupt is NOT active.
//!
//! \note Make sure to call this function to ensure that the interrupt is not
//! active before making any changes to the configuration of the watchdog to
//! prevent any unexpected behavior. For instance, switching from interrupt
//! mode to reset mode while the interrupt is active will immediately reset the
//! device.
//!
//! \return \b true if the interrupt is active and \b false if it is not.
//
//*****************************************************************************
static inline bool
SysCtl_isWatchdogInterruptActive(void)
{
    //
    // If the status bit is cleared, the WDINTn signal is active.
    //
    return((HWREGH(WD_BASE + SYSCTL_O_SCSR) & SYSCTL_SCSR_WDINTS) == 0U);
}

//*****************************************************************************
//
//! Disables the watchdog.
//!
//! This function disables the watchdog timer. Note that the watchdog timer is
//! enabled on reset.
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_disableWatchdog(void)
{
    EALLOW;

    //
    // Set the disable bit.
    //
    HWREGH(WD_BASE + SYSCTL_O_WDCR) |= SYSCTL_WD_CHKBITS | SYSCTL_WDCR_WDDIS;

    EDIS;
}

//*****************************************************************************
//
//! Enables the watchdog.
//!
//! This function enables the watchdog timer. Note that the watchdog timer is
//! enabled on reset.
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_enableWatchdog(void)
{
    EALLOW;

    //
    // Clear the disable bit.
    //
    HWREGH(WD_BASE + SYSCTL_O_WDCR) = (HWREGH(WD_BASE + SYSCTL_O_WDCR) &
                                       ~SYSCTL_WDCR_WDDIS) | SYSCTL_WD_CHKBITS;

    EDIS;
}

//*****************************************************************************
//
//! Services the watchdog.
//!
//! This function resets the watchdog.
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_serviceWatchdog(void)
{
    EALLOW;

    //
    // Enable the counter to be reset and then reset it.
    //
    HWREGH(WD_BASE + SYSCTL_O_WDKEY) = SYSCTL_WD_ENRSTKEY;
    HWREGH(WD_BASE + SYSCTL_O_WDKEY) = SYSCTL_WD_RSTKEY;

    EDIS;
}

//*****************************************************************************
//
//! Sets up watchdog clock (WDCLK) pre-divider.
//!
//! \param predivider is the value that configures the pre-divider.
//!
//! This function sets up the watchdog clock (WDCLK) pre-divider. There are two
//! dividers that scale INTOSC1 to WDCLK. The \e predivider parameter divides
//! INTOSC1 down to PREDIVCLK and the prescaler (set by the
//! SysCtl_setWatchdogPrescaler() function) divides PREDIVCLK down to WDCLK.
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_setWatchdogPredivider(SysCtl_WDPredivider predivider)
{
    uint16_t regVal;

    regVal = (uint16_t)predivider | (uint16_t)SYSCTL_WD_CHKBITS;

    EALLOW;

    //
    // Write the predivider to the appropriate register.
    //
    HWREGH(WD_BASE + SYSCTL_O_WDCR) = (HWREGH(WD_BASE + SYSCTL_O_WDCR) &
                                       ~(SYSCTL_WDCR_WDPRECLKDIV_M)) | regVal;

    EDIS;
}

//*****************************************************************************
//
//! Sets up watchdog clock (WDCLK) prescaler.
//!
//! \param prescaler is the value that configures the watchdog clock relative
//! to the value from the pre-divider.
//!
//! This function sets up the watchdog clock (WDCLK) prescaler. There are two
//! dividers that scale INTOSC1 to WDCLK. The predivider (set with the
//! SysCtl_setWatchdogPredivider() function) divides INTOSC1 down to PREDIVCLK
//! and the \e prescaler parameter divides PREDIVCLK down to WDCLK.
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_setWatchdogPrescaler(SysCtl_WDPrescaler prescaler)
{
    uint16_t regVal;

    regVal = (uint16_t)prescaler | (uint16_t)SYSCTL_WD_CHKBITS;

    EALLOW;

    //
    // Write the prescaler to the appropriate register.
    //
    HWREGH(WD_BASE + SYSCTL_O_WDCR) = (HWREGH(WD_BASE + SYSCTL_O_WDCR) &
                                       ~(SYSCTL_WDCR_WDPS_M)) | regVal;

    EDIS;
}

//*****************************************************************************
//
//! Gets the watchdog counter value.
//!
//! \return Returns the current value of the 8-bit watchdog counter. If this
//! count value overflows, a watchdog output pulse is generated.
//
//*****************************************************************************
static inline uint16_t
SysCtl_getWatchdogCounterValue(void)
{
    //
    // Read and return the value of the watchdog counter.
    //
    return(HWREGH(WD_BASE + SYSCTL_O_WDCNTR));
}

//*****************************************************************************
//
//! Gets the watchdog reset status.
//!
//! This function returns the watchdog reset status. If this function returns
//! \b true, that indicates that a watchdog reset generated the last reset
//! condition. Otherwise, it was an external device or power-up reset
//! condition.
//!
//! \return Returns \b true if the watchdog generated the last reset condition.
//
//*****************************************************************************
static inline bool
SysCtl_getWatchdogResetStatus(void)
{
    //
    // Read and return the status of the watchdog reset status flag.
    //
    return((HWREGH(CPUSYS_BASE + SYSCTL_O_RESC) & SYSCTL_RESC_WDRSN) != 0U);
}

//*****************************************************************************
//
//! Clears the watchdog reset status.
//!
//! This function clears the watchdog reset status. To check if it was set
//! first, see SysCtl_getWatchdogResetStatus().
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_clearWatchdogResetStatus(void)
{
    EALLOW;

    //
    // Read and return the status of the watchdog reset status flag.
    //
    HWREGH(CPUSYS_BASE + SYSCTL_O_RESCCLR) = SYSCTL_RESCCLR_WDRSN;

    EDIS;
}

//*****************************************************************************
//
//! Set the minimum threshold value for windowed watchdog
//!
//! \param value is the value to set the window threshold
//!
//! This function sets the minimum threshold value used to define the lower
//! limit of the windowed watchdog functionality.
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_setWatchdogWindowValue(uint16_t value)
{
    EALLOW;

    //
    // Clear the windowed value
    //
    HWREGH(WD_BASE + SYSCTL_O_WDWCR) &= ~SYSCTL_WDWCR_MIN_M;

    //
    // Set the windowed value
    //
    HWREGH(WD_BASE + SYSCTL_O_WDWCR) |= (value & SYSCTL_WDWCR_MIN_M);

    EDIS;
}

//*****************************************************************************
//
//! Gets the status of the watchdog first key detect flag
//!
//! This function gets the status of the watchdog first key detect flag.
//!
//! \return Returns \b true if the watchdog first key detect flag is set,
//! else \b false is returned if not set.
//
//*****************************************************************************
static inline bool
SysCtl_isWatchdogKeyDetected(void)
{
    bool status = false;

    //
    // Check the first key detect flag
    //
    if((HWREGH(WD_BASE + SYSCTL_O_WDWCR) & SYSCTL_WDWCR_FIRSTKEY) != 0U)
    {
        status = true;
    }

    return(status);
}

//*****************************************************************************
//
//! Registers an interrupt handler for the WAKEINT interrupt.
//!
//! \param handler is a pointer to the wakeup interrupt handling function.
//!
//! This function ensures that the interrupt handler specified by
//! \e handler is called when an interrupt is detected from the selected
//! external interrupt.  This function also enables the corresponding
//! interrupt in the interrupt controller.
//!
//! The interrupt source must be enabled using SysCtl_setWatchdogMode(). Note
//! that this interrupt is for both low-power-mode wakeup and watchdog
//! interrupts.
//!
//! \sa Interrupt_register() for important information about registering
//! interrupt handlers.
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_registerWakeupInterrupt(void (*handler)(void))
{
    //
    // Register the interrupt handler.
    //
    Interrupt_register(INT_WAKE, handler);

    //
    // Enable the wakeup interrupt.
    //
    Interrupt_enable(INT_WAKE);
}

//*****************************************************************************
//
//! Unregisters an interrupt handler for the WAKEINT interrupt.
//!
//! This function unregisters the handler to be called when the wakeup
//! interrupt occurs.  This function also masks off the interrupt in
//! the interrupt controller so that the interrupt handler no longer is called.
//!
//! \sa Interrupt_register() for important information about registering
//! interrupt handlers.
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_unregisterWakeupInterrupt(void)
{
    //
    // Disable the interrupt.
    //
    Interrupt_disable(INT_WAKE);

    //
    // Unregister the interrupt handler.
    //
    Interrupt_unregister(INT_WAKE);
}

//*****************************************************************************
//
//! Enable the NMI Global interrupt bit
//!
//! \b Note: This bit should be set after the device security related
//! initialization is complete.
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_enableNMIGlobalInterrupt(void)
{
    EALLOW;

    HWREGH(NMI_BASE + NMI_O_CFG) |= NMI_CFG_NMIE;

    EDIS;
}

//*****************************************************************************
//
//! Read NMI interrupts.
//!
//! Read the current state of NMI interrupt.
//!
//! \return \b true if NMI interrupt is triggered, \b false if not.
//
//*****************************************************************************
static inline bool
SysCtl_getNMIStatus(void)
{
    //
    // Read and return the current value of the NMI flag register, masking out
    // all but the NMI bit.
    //
    return((HWREGH(NMI_BASE + NMI_O_FLG) & NMI_FLG_NMIINT) != 0U);
}

//*****************************************************************************
//
//! Read NMI Flags.
//!
//! Read the current state of individual NMI interrupts
//!
//! \return Value of NMIFLG register. These defines are provided to decode
//! the value:
//! - \b SYSCTL_NMI_NMIINT - Non-maskable interrupt
//! - \b SYSCTL_NMI_CLOCKFAIL - Clock Failure
//! - \b SYSCTL_NMI_RAMUNCERR - Uncorrectable RAM error
//! - \b SYSCTL_NMI_FLUNCERR - Uncorrectable Flash error
//! - \b SYSCTL_NMI_PIEVECTERR - PIE Vector Fetch Error
//! - \b SYSCTL_NMI_CPU2WDRSN - CPU2 WDRSn Reset
//! - \b SYSCTL_NMI_CPU2NMIWDRSN - CPU2 NMIWDRSn Reset
//! - \b SYSCTL_NMI_CPU1HWBISTERR - HW BIST Error NMI Flag
//! - \b SYSCTL_NMI_CPU2HWBISTERR - HW BIST Error NMI Flag
//! - \b SYSCTL_NMI_ERADNMI  - ERAD Module NMI Flag
//! - \b SYSCTL_NMI_CMNMIWDRSN  - CM NMIWDRSn Reset Indication
//! - \b SYSCTL_NMI_ECATNMI   - NMI from EtherCAT reset out
//! - \b SYSCTL_NMI_CRC_FAIL - CRC calculation failed flag
//! - \b SYSCTL_NMI_MCAN_ERR - MCAN module generated an ECC

//
//*****************************************************************************
static inline uint32_t
SysCtl_getNMIFlagStatus(void)
{
    //
    // Read and return the current value of the NMI flag register.
    //
    return(HWREGH(NMI_BASE + NMI_O_FLG));
}

//*****************************************************************************
//
//! Check if the individual NMI interrupts are set.
//!
//! \param nmiFlags Bit mask of the NMI interrupts that user wants to clear.
//! The bit format of this parameter is same as of the NMIFLG register. These
//! defines are provided:
//! - \b SYSCTL_NMI_NMIINT - Non-maskable interrupt
//! - \b SYSCTL_NMI_CLOCKFAIL - Clock Failure
//! - \b SYSCTL_NMI_RAMUNCERR - Uncorrectable RAM error
//! - \b SYSCTL_NMI_FLUNCERR - Uncorrectable Flash error
//! - \b SYSCTL_NMI_PIEVECTERR - PIE vector Fetch error
//! - \b SYSCTL_NMI_CPU2WDRSN - CPU2 WDRSn Reset
//! - \b SYSCTL_NMI_CPU2NMIWDRSN - CPU2 NMIWDRSn Reset
//! - \b SYSCTL_NMI_CPU1HWBISTERR - HW BIST Error NMI Flag
//! - \b SYSCTL_NMI_CPU2HWBISTERR - HW BIST Error NMI Flag
//! - \b SYSCTL_NMI_ERADNMI  - ERAD Module NMI Flag
//! - \b SYSCTL_NMI_CMNMIWDRSN  - CM NMIWDRSn Reset Indication
//! - \b SYSCTL_NMI_ECATNMI   - NMI from EtherCAT reset out
//! - \b SYSCTL_NMI_CRC_FAIL - CRC calculation failed flag
//! - \b SYSCTL_NMI_MCAN_ERR - MCAN module generated an ECC
//!
//! Check if interrupt flags corresponding to the passed in bit mask are
//! asserted.
//!
//! \return \b true if any of the NMI asked for in the parameter bit mask
//! is set. \b false if none of the NMI requested in the parameter bit mask are
//! set.
//
//*****************************************************************************
static inline bool
SysCtl_isNMIFlagSet(uint32_t nmiFlags)
{
    //
    // Check the arguments.
    // Make sure if reserved bits are not set in nmiFlags.
    //
   ASSERT((nmiFlags & ~(SYSCTL_NMI_NMIINT | SYSCTL_NMI_CLOCKFAIL |
                        SYSCTL_NMI_RAMUNCERR | SYSCTL_NMI_FLUNCERR |
                        SYSCTL_NMI_CPU1HWBISTERR | SYSCTL_NMI_CPU2HWBISTERR |
                        SYSCTL_NMI_ECATNMI | SYSCTL_NMI_CRC_FAIL |
                        SYSCTL_NMI_ERADNMI | SYSCTL_NMI_PIEVECTERR | 
                        SYSCTL_NMI_CMNMIWDRSN | SYSCTL_NMI_CPU2WDRSN |
                        SYSCTL_NMI_CPU2NMIWDRSN | SYSCTL_NMI_MCAN_ERR)) == 0);

    //
    // Read the flag register and return true if any of them are set.
    //
    return((HWREGH(NMI_BASE + NMI_O_FLG) & nmiFlags) != 0U);
}

//*****************************************************************************
//
//! Function to clear individual NMI interrupts.
//!
//! \param nmiFlags Bit mask of the NMI interrupts that user wants to clear.
//! The bit format of this parameter is same as of the NMIFLG register. These
//! defines are provided:
//! - \b SYSCTL_NMI_CLOCKFAIL
//! - \b SYSCTL_NMI_RAMUNCERR
//! - \b SYSCTL_NMI_FLUNCERR
//! - \b SYSCTL_NMI_PIEVECTERR
//! - \b SYSCTL_NMI_CPU2WDRSN
//! - \b SYSCTL_NMI_CPU2NMIWDRSN
//! - \b SYSCTL_NMI_CPU1HWBISTERR
//! - \b SYSCTL_NMI_CPU2HWBISTERR 
//! - \b SYSCTL_NMI_ERADNMI 
//! - \b SYSCTL_NMI_CMNMIWDRSN 
//! - \b SYSCTL_NMI_ECATNMI 
//! - \b SYSCTL_NMI_CRC_FAIL
//! - \b SYSCTL_NMI_MCAN_ERR 
//!
//! Clear NMI interrupt flags that correspond with the passed in bit mask.
//!
//! \b Note: The NMI Interrupt flag is always cleared by default and
//! therefore doesn't have to be included in the bit mask.
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_clearNMIStatus(uint32_t nmiFlags)
{
    //
    // Check the arguments.
    // Make sure if reserved bits are not set in nmiFlags.
    //
    ASSERT((nmiFlags & ~(SYSCTL_NMI_NMIINT | SYSCTL_NMI_CLOCKFAIL |
                         SYSCTL_NMI_RAMUNCERR | SYSCTL_NMI_FLUNCERR |
                         SYSCTL_NMI_CPU1HWBISTERR | SYSCTL_NMI_CPU2HWBISTERR |
                         SYSCTL_NMI_ECATNMI | SYSCTL_NMI_CRC_FAIL |
                         SYSCTL_NMI_ERADNMI | SYSCTL_NMI_PIEVECTERR | 
                         SYSCTL_NMI_CMNMIWDRSN | SYSCTL_NMI_CPU2WDRSN |
                         SYSCTL_NMI_CPU2NMIWDRSN | SYSCTL_NMI_MCAN_ERR)) == 0);

    EALLOW;

    //
    // Clear the individual flags as well as NMI Interrupt flag
    //
    HWREGH(NMI_BASE + NMI_O_FLGCLR) = nmiFlags;
    HWREGH(NMI_BASE + NMI_O_FLGCLR) = NMI_FLG_NMIINT;

    EDIS;
}

//*****************************************************************************
//
//! Clear all the NMI Flags that are currently set.
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_clearAllNMIFlags(void)
{
    uint32_t nmiFlags;

    //
    // Read the flag status register and then write to the clear register,
    // clearing all the flags that were returned plus the NMI flag.
    //
    EALLOW;

    nmiFlags = SysCtl_getNMIFlagStatus();
    HWREGH(NMI_BASE + NMI_O_FLGCLR) = nmiFlags;
    HWREGH(NMI_BASE + NMI_O_FLGCLR) = NMI_FLG_NMIINT;

    EDIS;
}

//*****************************************************************************
//
//! Function to force individual NMI interrupt fail flags
//!
//! \param nmiFlags Bit mask of the NMI interrupts that user wants to clear.
//! The bit format of this parameter is same as of the NMIFLG register. These
//! defines are provided:
//! - \b SYSCTL_NMI_CLOCKFAIL
//! - \b SYSCTL_NMI_RAMUNCERR
//! - \b SYSCTL_NMI_FLUNCERR
//! - \b SYSCTL_NMI_PIEVECTERR
//! - \b SYSCTL_NMI_CPU2WDRSN
//! - \b SYSCTL_NMI_CPU2NMIWDRSN
//! - \b SYSCTL_NMI_CPU1HWBISTERR
//! - \b SYSCTL_NMI_CPU2HWBISTERR 
//! - \b SYSCTL_NMI_ERADNMI 
//! - \b SYSCTL_NMI_CMNMIWDRSN
//! - \b SYSCTL_NMI_ECATNMI   
//! - \b SYSCTL_NMI_CRC_FAIL 
//! - \b SYSCTL_NMI_MCAN_ERR 
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_forceNMIFlags(uint32_t nmiFlags)
{
    //
    // Check the arguments.
    // Make sure if reserved bits are not set in nmiFlags.
    //
    ASSERT((nmiFlags & ~(SYSCTL_NMI_NMIINT | SYSCTL_NMI_CLOCKFAIL |
                         SYSCTL_NMI_RAMUNCERR | SYSCTL_NMI_FLUNCERR |
                         SYSCTL_NMI_CPU1HWBISTERR | SYSCTL_NMI_CPU2HWBISTERR |
                         SYSCTL_NMI_ECATNMI | SYSCTL_NMI_CRC_FAIL |
                         SYSCTL_NMI_ERADNMI | SYSCTL_NMI_PIEVECTERR | 
                         SYSCTL_NMI_CMNMIWDRSN | SYSCTL_NMI_CPU2WDRSN |
                         SYSCTL_NMI_CPU2NMIWDRSN | SYSCTL_NMI_MCAN_ERR)) == 0);

    EALLOW;

    //
    // Set the Flags for the individual interrupts in the NMI flag
    // force register
    //
    HWREGH(NMI_BASE + NMI_O_FLGFRC) |= nmiFlags;

    EDIS;
}

//*****************************************************************************
//
//! Gets the NMI watchdog counter value.
//!
//! \b Note: The counter is clocked at the SYSCLKOUT rate.
//!
//! \return Returns the NMI watchdog counter register's current value.
//
//*****************************************************************************
static inline uint16_t
SysCtl_getNMIWatchdogCounter(void)
{
    //
    // Read and return the NMI watchdog counter register's value.
    //
    return(HWREGH(NMI_BASE + NMI_O_WDCNT));
}

//*****************************************************************************
//
//! Sets the NMI watchdog period value.
//!
//! \param wdPeriod is the 16-bit value at which a reset is generated.
//!
//! This function writes to the NMI watchdog period register that holds the
//! value to which the NMI watchdog counter is compared. When the two registers
//! match, a reset is generated. By default, the period is 0xFFFF.
//!
//! \note If a value smaller than the current counter value is passed into the
//! \e wdPeriod parameter, a NMIRSn will be forced.
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_setNMIWatchdogPeriod(uint16_t wdPeriod)
{
    EALLOW;

    //
    // Write to the period register.
    //
    HWREGH(NMI_BASE + NMI_O_WDPRD) = wdPeriod;

    EDIS;
}

//*****************************************************************************
//
//! Gets the NMI watchdog period value.
//!
//! \return Returns the NMI watchdog period register's current value.
//
//*****************************************************************************
static inline uint16_t
SysCtl_getNMIWatchdogPeriod(void)
{
    //
    // Read and return the NMI watchdog period register's value.
    //
    return(HWREGH(NMI_BASE + NMI_O_WDPRD));
}

//*****************************************************************************
//
//! Read NMI Shadow Flags.
//!
//! Read the current state of individual NMI interrupts
//!
//! \return Value of NMISHDFLG register. These defines are provided to decode
//! the value:
//! - \b SYSCTL_NMI_NMIINT - Non-maskable interrupt
//! - \b SYSCTL_NMI_CLOCKFAIL - Clock Failure
//! - \b SYSCTL_NMI_RAMUNCERR - Uncorrectable RAM error
//! - \b SYSCTL_NMI_FLUNCERR - Uncorrectable Flash error
//! - \b SYSCTL_NMI_PIEVECTERR - PIE Vector Fetch Error
//! - \b SYSCTL_NMI_CPU2WDRSN - CPU2 WDRSn Reset
//! - \b SYSCTL_NMI_CPU2NMIWDRSN - CPU2 NMIWDRSn Reset
//! - \b SYSCTL_NMI_CPU1HWBISTERR - HW BIST Error NMI Flag
//! - \b SYSCTL_NMI_CPU2HWBISTERR - HW BIST Error NMI Flag
//! - \b SYSCTL_NMI_ERADNMI  - ERAD Module NMI Flag
//! - \b SYSCTL_NMI_CMNMIWDRSN  - CM NMIWDRSn Reset Indication
//! - \b SYSCTL_NMI_ECATNMI   - NMI from EtherCAT reset out
//! - \b SYSCTL_NMI_CRC_FAIL - CRC calculation failed flag
//! - \b SYSCTL_NMI_MCAN_ERR - MCAN module generated an ECC
//
//*****************************************************************************
static inline uint32_t
SysCtl_getNMIShadowFlagStatus(void)
{
    //
    // Read and return the current value of the NMI shadow flag register.
    //
    return(HWREGH(NMI_BASE + NMI_O_SHDFLG));
}

//*****************************************************************************
//
//! Check if the individual NMI shadow flags are set.
//!
//! \param nmiFlags Bit mask of the NMI interrupts that user wants  to clear.
//! The bit format of this parameter is same as of the NMIFLG register. These
//! defines are provided:
//! - \b SYSCTL_NMI_NMIINT
//! - \b SYSCTL_NMI_CLOCKFAIL
//! - \b SYSCTL_NMI_RAMUNCERR
//! - \b SYSCTL_NMI_FLUNCERR
//! - \b SYSCTL_NMI_PIEVECTERR
//! - \b SYSCTL_NMI_CPU2WDRSN
//! - \b SYSCTL_NMI_CPU2NMIWDRSN
//! - \b SYSCTL_NMI_CPU1HWBISTERR 
//! - \b SYSCTL_NMI_CPU2HWBISTERR
//! - \b SYSCTL_NMI_ERADNMI 
//! - \b SYSCTL_NMI_CMNMIWDRSN 
//! - \b SYSCTL_NMI_ECATNMI   
//! - \b SYSCTL_NMI_CRC_FAIL 
//! - \b SYSCTL_NMI_MCAN_ERR 
//!
//! Check if interrupt flags corresponding to the passed in bit mask are
//! asserted.
//!
//! \return \b true if any of the NMI asked for in the parameter bit mask
//! is set. \b false if none of the NMI requested in the parameter bit mask are
//! set.
//
//*****************************************************************************
static inline bool
SysCtl_isNMIShadowFlagSet(uint32_t nmiFlags)
{
    //
    // Check the arguments.
    // Make sure if reserved bits are not set in nmiFlags.
    //
    ASSERT((nmiFlags & ~(SYSCTL_NMI_NMIINT | SYSCTL_NMI_CLOCKFAIL |
                         SYSCTL_NMI_RAMUNCERR | SYSCTL_NMI_FLUNCERR |
                         SYSCTL_NMI_CPU1HWBISTERR | SYSCTL_NMI_CPU2HWBISTERR |
                         SYSCTL_NMI_ECATNMI | SYSCTL_NMI_CRC_FAIL |
                         SYSCTL_NMI_ERADNMI | SYSCTL_NMI_PIEVECTERR | 
                         SYSCTL_NMI_CMNMIWDRSN | SYSCTL_NMI_CPU2WDRSN |
                         SYSCTL_NMI_CPU2NMIWDRSN | SYSCTL_NMI_MCAN_ERR)) == 0);

    //
    // Read the flag register and return true if any of them are set.
    //
    return((HWREGH(NMI_BASE + NMI_O_SHDFLG) & nmiFlags) != 0U);
}

//*****************************************************************************
//
//! Enable the missing clock detection (MCD) Logic
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_enableMCD(void)
{
    EALLOW;

    HWREGH(CLKCFG_BASE + SYSCTL_O_MCDCR) &= ~(SYSCTL_MCDCR_MCLKOFF);

    EDIS;
}

//*****************************************************************************
//
//! Disable the missing clock detection (MCD) Logic
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_disableMCD(void)
{
    EALLOW;

    HWREGH(CLKCFG_BASE + SYSCTL_O_MCDCR) |= SYSCTL_MCDCR_MCLKOFF;

    EDIS;
}

//*****************************************************************************
//
//! Get the missing clock detection Failure Status
//!
//! \note A failure means the oscillator clock is missing
//!
//! \return Returns \b true if a failure is detected or \b false if a
//! failure isn't detected
//
//*****************************************************************************
static inline bool
SysCtl_isMCDClockFailureDetected(void)
{
  //
  //  Check the status bit to determine failure
  //
  return((HWREGH(CLKCFG_BASE + SYSCTL_O_MCDCR) & SYSCTL_MCDCR_MCLKSTS) != 0U);
}

//*****************************************************************************
//
//! Reset the missing clock detection logic after clock failure
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_resetMCD(void)
{
    EALLOW;

    HWREGH(CLKCFG_BASE + SYSCTL_O_MCDCR) |= SYSCTL_MCDCR_MCLKCLR;

    EDIS;
}

//*****************************************************************************
//
//! Re-connect missing clock detection clock source to stop simulating clock
//! failure
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_connectMCDClockSource(void)
{
    EALLOW;

    HWREGH(CLKCFG_BASE + SYSCTL_O_MCDCR) &= ~(SYSCTL_MCDCR_OSCOFF);

    EDIS;
}

//*****************************************************************************
//
//! Disconnect missing clock detection clock source to simulate clock failure.
//! This is for testing the MCD functionality.
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_disconnectMCDClockSource(void)
{
    EALLOW;

    HWREGH(CLKCFG_BASE + SYSCTL_O_MCDCR) |= SYSCTL_MCDCR_OSCOFF;

    EDIS;
}

//*****************************************************************************
//
//! Lock the Access Control Registers
//!
//! This function locks the access control registers and puts them in a
//! read-only state.
//!
//! \note Only a reset can unlock the access control registers.
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_lockAccessControlRegs(void)
{
    EALLOW;

    HWREGH(PERIPHAC_BASE + SYSCTL_O_PERIPH_AC_LOCK) |=
        SYSCTL_PERIPH_AC_LOCK_LOCK_AC_WR;

    EDIS;
}

//*****************************************************************************
//
//! Set the peripheral access control permissions
//!
//! \param peripheral is the selected peripheral
//! \param master is the selected master (CPU1, CLA1, or DMA1)
//! \param permission is the selected access permissions
//!
//! This function sets the specified peripheral access control permissions for
//! the the specified master (CPU1, CLA1, or DMA1)
//!
//! The \e peripheral parameter can have one enumerated value in the format of
//! \b SYSCTL_ACCESS_X where X is the name of the peripheral instance to be
//! configured such as \b SYSCTL_ACCESS_ADCA.
//!
//! The \e master parameter can have one the following enumerated values:
//! - \b SYSCTL_ACCESS_CPU1 - CPU1 Master
//! - \b SYSCTL_ACCESS_CLA1 - CLA1 Master
//! - \b SYSCTL_ACCESS_DMA1 - DMA1 Master
//!
//! The \e permission parameter can have one the following enumerated values:
//! - \b SYSCTL_ACCESS_FULL      - Full Access for both read and write
//! - \b SYSCTL_ACCESS_PROTECTED - Protected read access such that FIFOs, clear
//!                                on read registers are not changed, and no
//!                                write access
//! - \b SYSCTL_ACCESS_NONE      - No read or write access
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_setPeripheralAccessControl(SysCtl_AccessPeripheral peripheral,
                                  SysCtl_AccessMaster master,
                                  SysCtl_AccessPermission permission)
{
    //
    // Set master permissions for specified peripheral. Each master has
    // two bits dedicated to its permission setting.
    //
    EALLOW;

    HWREGH(PERIPHAC_BASE + (uint16_t)peripheral) =
        (HWREGH(PERIPHAC_BASE + (uint16_t)peripheral) &
         ~(0x3U << (uint16_t)master)) |
        ((uint32_t)permission << (uint16_t)master);

    EDIS;
}

//*****************************************************************************
//
//! Get the peripheral access control permissions
//!
//! \param peripheral is the selected peripheral
//! \param master is the selected master (CPU1, CLA1, or DMA1)
//!
//! This function gets the specified peripheral access control permissions for
//! the the specified master (CPU1, CLA1, or DMA1)
//!
//! The \e peripheral parameter can have one enumerated value in the format of
//! \b SYSCTL_ACCESS_X where X is the name of the peripheral instance to be
//! configured such as \b SYSCTL_ACCESS_ADCA.
//!
//! The \e master parameter can have one the following enumerated values:
//! - \b SYSCTL_ACCESS_CPU1 - CPU1 Master
//! - \b SYSCTL_ACCESS_CLA1 - CLA1 Master
//! - \b SYSCTL_ACCESS_DMA1 - DMA1 Master
//!
//! \return Returns one of the following enumerated permission values:
//! - \b SYSCTL_ACCESS_FULL      - Full Access for both read and write
//! - \b SYSCTL_ACCESS_PROTECTED - Protected read access such that FIFOs, clear
//!                                on read registers are not changed, and no
//!                                write access
//! - \b SYSCTL_ACCESS_NONE      - No read or write access
//
//*****************************************************************************
static inline uint32_t
SysCtl_getPeripheralAccessControl(SysCtl_AccessPeripheral peripheral,
                                  SysCtl_AccessMaster master)
{
    //
    // Read master permissions for specified peripheral. Each master has
    // two bits dedicated to its permission setting.
    //
    return((HWREGH(PERIPHAC_BASE + (uint16_t)peripheral) >> (uint16_t)master) &
           0x3U);
}

//*****************************************************************************
//
//! Configures the sync output source.
//!
//! \param syncSrc is sync output source selection.
//!
//! This function configures the sync output source from the ePWM modules. The
//! \e syncSrc parameter is a value \b SYSCTL_SYNC_OUT_SRC_XXXX, where XXXX is
//! a sync signal coming from an ePWM such as SYSCTL_SYNC_OUT_SRC_EPWM1SYNCOUT
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_setSyncOutputConfig(SysCtl_SyncOutputSource syncSrc)
{
   //
    // Write the sync output source selection to the appropriate register.
    //
    EALLOW;
    HWREG(SYNCSOC_BASE + SYSCTL_O_SYNCSELECT) =
        (HWREG(SYNCSOC_BASE + SYSCTL_O_SYNCSELECT) &
         ~((uint32_t)SYSCTL_SYNCSELECT_SYNCOUT_M)) |
        ((uint32_t)syncSrc << SYSCTL_SYNCSELECT_SYNCOUT_S);
    EDIS;

}
//*****************************************************************************
//
//! Enables ePWM SOC signals to drive an external (off-chip) ADCSOC signal.
//!
//! \param adcsocSrc is a bit field of the selected signals to be enabled
//!
//! This function configures which ePWM SOC signals are enabled as a source for
//! either ADCSOCAO or ADCSOCBO. The \e adcsocSrc parameter takes a logical OR
//! of \b SYSCTL_ADCSOC_SRC_PWMxSOCA/B values that correspond to different
//! signals.
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_enableExtADCSOCSource(uint32_t adcsocSrc)
{
    //
    // Set the bits that correspond to signal to be enabled.
    //
    EALLOW;
    HWREG(SYNCSOC_BASE + SYSCTL_O_ADCSOCOUTSELECT) |= adcsocSrc;
    EDIS;
}

//*****************************************************************************
//
//! Disables ePWM SOC signals from driving an external ADCSOC signal.
//!
//! \param adcsocSrc is a bit field of the selected signals to be disabled
//!
//! This function configures which ePWM SOC signals are disabled as a source
//! for either ADCSOCAO or ADCSOCBO. The \e adcsocSrc parameter takes a logical
//! OR of \b SYSCTL_ADCSOC_SRC_PWMxSOCA/B values that correspond to different
//! signals.
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_disableExtADCSOCSource(uint32_t adcsocSrc)
{
    //
    // Clear the bits that correspond to signal to be disabled.
    //
    EALLOW;
    HWREG(SYNCSOC_BASE + SYSCTL_O_ADCSOCOUTSELECT) &= ~adcsocSrc;
    EDIS;
}

//*****************************************************************************
//
//! Locks the SOC Select of the Trig X-BAR.
//!
//! This function locks the external ADC SOC select of the Trig X-BAR.
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_lockExtADCSOCSelect(void)
{
    //
    // Lock the ADCSOCOUTSELECT bit of the SYNCSOCLOCK register.
    //
    EALLOW;
    HWREG(SYNCSOC_BASE + SYSCTL_O_SYNCSOCLOCK) =
        SYSCTL_SYNCSOCLOCK_ADCSOCOUTSELECT;
    EDIS;
}
//*****************************************************************************
//
//! Configures whether whether the dual ported bridge is connected with DMA or
//! CLA as the secondary master.
//!
//! \param periFrame1Config indicates whether CLA or DMA is configured as
//!                         secondary master on peripheral frame 1.
//! \param periFrame2Config indicates whether CLA or DMA is configured as
//!                         secondary master on peripheral frame 2.
//!
//!  One of the following values can be passed as parameter.
//!       \b SYSCTL_SEC_MASTER_CLA
//!       \b SYSCTL_SEC_MASTER_DMA
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_selectSecMaster(uint16_t periFrame1Config, uint16_t periFrame2Config)
{
    EALLOW;

    HWREG(CPUSYS_BASE + SYSCTL_O_SECMSEL) =
            (((periFrame1Config << SYSCTL_SECMSEL_PF1SEL_S) &
               SYSCTL_SECMSEL_PF1SEL_M) |
             ((periFrame2Config << SYSCTL_SECMSEL_PF2SEL_S) &
                SYSCTL_SECMSEL_PF2SEL_M));

    EDIS;
}
//*****************************************************************************
//
//! Locks the Sync Select of the Trig X-BAR.
//!
//! This function locks Sync Input and Output Select of the Trig X-BAR.
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_lockSyncSelect(void)
{
    //
    // Lock the SYNCSELECT register.
    //
    EALLOW;
    HWREG(SYNCSOC_BASE + SYSCTL_O_SYNCSOCLOCK) = SYSCTL_SYNCSOCLOCK_SYNCSELECT;
    EDIS;
}
//*****************************************************************************
//
//! Configures whether a peripheral is connected to CPU1 or CPU2.
//!
//! \param peripheral is the peripheral for which CPU needs to be configured.
//! \param peripheralInst is the instance for which CPU needs to be configured.
//! \param cpuInst is the CPU to which the peripheral instance need to be
//!                connected.
//!
//! The \e peripheral parameter can have one enumerated value from
//! SysCtl_CPUSelPeripheral
//!
//! The \e peripheralInst parameter is the instance number for example
//! 1 for EPWM1, 2 for EPWM2 so on.For instances which are named with alphabets
//! (instead of numbers) the following convention needs to be followed.
//! 1 for A (SPI_A), 2 for B (SPI_B), 3 for C (SPI_C) so on...
//!
//! The \e cpuInst parameter can have one the following values:
//! - \b SYSCTL_CPUSEL_CPU1 - to connect to CPU1
//! - \b SYSCTL_CPUSEL_CPU2 - to connect to CPU2
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_selectCPUForPeripheral(SysCtl_CPUSelPeripheral peripheral,
                              uint16_t peripheralInst, SysCtl_CPUSel cpuInst)
{
    uint32_t tempValue = 0U;

    if(SYSCTL_CPUSEL14_DAC == peripheral)
    {
        peripheralInst = peripheralInst + SYSCTL_CPUSEL_DAC_S;
    }

    tempValue = HWREG(DEVCFG_BASE + SYSCTL_O_CPUSEL0 + (peripheral * 2)) &
                (~(1 << (peripheralInst - 1)));

    EALLOW;
    HWREG(DEVCFG_BASE + SYSCTL_O_CPUSEL0 + (peripheral * 2)) =
        tempValue | ((uint32_t)cpuInst << (peripheralInst - 1));
    EDIS;
}
//*****************************************************************************
//
//! Get the Device Silicon Revision ID
//!
//! This function returns the silicon revision ID for the device.
//!
//! \return Returns the silicon revision ID value.
//
//*****************************************************************************
static inline uint32_t
SysCtl_getDeviceRevision(void)
{
    //
    // Returns the device silicon revision ID
    //
    return(HWREG(DEVCFG_BASE + SYSCTL_O_REVID));
}

//*****************************************************************************
//
//! Locks the CPU select registers for the peripherals
//!
//! \param peripheral is the peripheral for which CPU needs to be selected.
//!
//! The \e peripheral parameter can have one enumerated value from
//! SysCtl_CPUSelPeripheral
//!
//! \return None.
//
//*****************************************************************************

static inline void
SysCtl_lockCPUSelectRegs(SysCtl_CPUSelPeripheral peripheral)
{
  EALLOW;
  HWREG(DEVCFG_BASE + SYSCTL_O_DEVCFGLOCK1) |= ((uint32_t)1U << peripheral);
  EDIS;
}

//*****************************************************************************
//
//! Configures the ADC mode for the provided ADC
//!
//! \param peripheral is the ADC for which the wrapper mode 
//! needs to be configured.
//! \param mode is the mode of operation for the ADC.
//!
//! The \e peripheral parameter can have one enumerated value from
//! SysCtl_SelADC
//! The \e mode parameter can have one enumerated value from
//! SysCtl_ADCMode
//!
//! \return None.
//
//*****************************************************************************

static inline void
SysCtl_configureADCWrapper(SysCtl_SelADC peripheral , SysCtl_ADCMode mode)
{
  //
  // Configures the ADC wrapper based on the mode
  //
 if(mode == 0x1U)
  {
    HWREG(DEVCFG_BASE + SYSCTL_O_PERCNF1) |=((uint32_t)1U << peripheral);
  }
 else 
  {
    HWREG(DEVCFG_BASE + SYSCTL_O_PERCNF1) &= ~((uint32_t)1U << peripheral);
  }
}

//*****************************************************************************
//
//! Gets the error status of the Efuse
//!
//! The function provides both the Efuse Autoload & the Efuse Self Test
//! Error Status.
//!
//! \return Fuse Error status.
//
//*****************************************************************************

static inline uint16_t
SysCtl_getEfuseError(void) 
{
  return(HWREGH(DEVCFG_BASE + SYSCTL_O_FUSEERR));
}

//*****************************************************************************
//
//! Check if the CPU2 is held in reset or not
//! 
//! Provides the reset status of CPU2 to CPU1
//!
//! \return \b true if CPU2 core is in reset \b false if CPU2 core
//! is out of reset
//
//*****************************************************************************

static inline bool
SysCtl_isCPU2Reset(void)
{
  return((HWREGH(DEVCFG_BASE + SYSCTL_O_RSTSTAT)&
          SYSCTL_RSTSTAT_CPU2RES) == 0U);
}

//*****************************************************************************
//
//! Gets the status/causes of the CPU2 reset.
//!
//! The function provides causes of the CPU2 being in reset / not.
//! This could be either due to the HWBIST or the NMIWD or both.
//!
//! \return Reset cause of CPU2.
//
//*****************************************************************************

static inline uint16_t
SysCtl_getCPU2ResetStatus(void)
{
  return(HWREGH(DEVCFG_BASE + SYSCTL_O_RSTSTAT));
}

//*****************************************************************************
//
//! Clears the CPU2 reset status.
//!
//! This function clears the CPU2 reset status. This could be either due to 
//! the HWBIST or the NMIWD or both.To check if it was set first, see 
//! SysCtl_getCPU2ResetStatus().
//!
//! \return None.
//
//*****************************************************************************

static inline void
SysCtl_clearCPU2ResetStatus(uint32_t rstCauses )
{
  HWREGH(DEVCFG_BASE + SYSCTL_O_RSTSTAT) |= rstCauses;
}
//*****************************************************************************
//
//! Gets the state of the CPU2.
//!
//! The function indicates the power mode of the CPU2. It could be either in
//! ACTIVE , IDLE or STANDBY mode.
//!
//! \return Power mode of CPU2.
//
//*****************************************************************************

static inline uint16_t
SysCtl_getCPU2LPMStatus(void)
{
  return(HWREGH(DEVCFG_BASE + SYSCTL_O_LPMSTAT));
}

//*****************************************************************************
//
//! Selects the BANK to be programmed by CPU1.
//!
//! \param bank is the BANK to be programmed.
//!
//! The \e bank parameter can have one enumerated value from
//! SysCtl_CPUBank
//!
//! \return None.
//
//*****************************************************************************

static inline void
SysCtl_selectbank(SysCtl_CPUBank bank)
{
  EALLOW;
  HWREGH(DEVCFG_BASE + SYSCTL_O_BANKSEL) |= (uint16_t)bank;
  EDIS;
}
//*****************************************************************************
//
//! Gets the Ownership details for clock configuration 
//!
//! A CPU can perform read/writes to any of the CLKCFG registers only
//! if  it owns the semaphore. Otherwise, writes are ignored and reads 
//! will return 0x0.
//! 
//! \note Reads and writes of this ownership register are always 
//! allowed from both CPU1 and CPU2. 
//!
//! \return Clock control Ownership details
//
//*****************************************************************************

static inline uint16_t
SysCtl_getSemOwner(void)
{

  return(HWREGH(CLKCFG_BASE + SYSCTL_O_CLKSEM));
}

//*****************************************************************************
//
//! Sets up XCLK divider.
//!
//! \param divider is the value that configures the divider.
//!
//! This function sets up the XCLK divider. There is only one
//! divider that scales INTOSC1 to XCLK. 
//!
//! The \e divider parameter can have one enumerated value from
//! SysCtl_XClkDivider
//!
//! \return None.
//
//*****************************************************************************

static inline void
SysCtl_setXClk(SysCtl_XClkDivider divider)
{
  //
  // Clears the divider then configures it.
  //
  EALLOW;
  HWREGH(CLKCFG_BASE + 
         SYSCTL_O_XCLKOUTDIVSEL) = (HWREGH(CLKCFG_BASE + 
                                           SYSCTL_O_XCLKOUTDIVSEL) &
                                    ~(SYSCTL_XCLKOUTDIVSEL_XCLKOUTDIV_M)) |
                                    (uint16_t)divider;
  EDIS;
}

//*****************************************************************************
//
//! Sets up CM CLK source & divider.
//!
//! \param divider is the value that configures the divider.
//! \param source is the source for the clock divider
//!
//! This function sets up the CM CLK divider based on the source that 
//! is selected. There is only one divider that scales the "source" to CM CLK. 
//!
//! The \e divider parameter can have one enumerated value from
//! SysCtl_CMClkDivider
//! The \e source parameter can have one enumerated value from
//! SysCtl_PLLClockSource
//!
//! \return None.
//
//*****************************************************************************

static inline void
SysCtl_setCMClk(SysCtl_CMClkDivider divider, SysCtl_PLLClockSource source)
{
  //
  // Clears the divider & the source, then configures it.
  //
  EALLOW;
  HWREGH(CLKCFG_BASE + SYSCTL_O_CMCLKCTL) = (HWREGH(CLKCFG_BASE + 
                                             SYSCTL_O_CMCLKCTL) &
                                           ~(SYSCTL_CMCLKCTL_CMCLKDIV_M | 
                                             SYSCTL_CMCLKCTL_CMDIVSRCSEL)); 

  HWREGH(CLKCFG_BASE + SYSCTL_O_CMCLKCTL) |= ((uint16_t)divider << 
                                             SYSCTL_CMCLKCTL_CMCLKDIV_S)|
                                            ((uint16_t)source <<  
                                             SYSCTL_CMCLKCTL_CMDIVSRCSEL_S);
  EDIS;
}

//*****************************************************************************
//
//! Sets up Ethercat CLK source & divider.
//!
//! \param divider is the value that configures the divider.
//! \param source is the source for the clock divider
//!
//! This function sets up the Ethercat CLK divider based on the source that
//! is selected. There is only one divider that scales the "source" to 
//! Ethercat CLK. 
//!
//! The \e divider parameter can have one enumerated value from
//! SysCtl_ECatClkDivider
//! The \e source parameter can have one enumerated value from
//! SysCtl_PLLClockSource
//!
//! \return None.
//
//*****************************************************************************

static inline void
SysCtl_setECatClk(SysCtl_ECatClkDivider divider, SysCtl_PLLClockSource source)
{
  //
  // Clears the divider & the source, then configures it.
  //
  EALLOW;
  HWREGH(CLKCFG_BASE + SYSCTL_O_CMCLKCTL) = (HWREGH(CLKCFG_BASE + 
                                             SYSCTL_O_CMCLKCTL) &
                                           ~(SYSCTL_CMCLKCTL_ETHDIV_M | 
                                             SYSCTL_CMCLKCTL_ETHDIVSRCSEL)); 

  HWREGH(CLKCFG_BASE + SYSCTL_O_CMCLKCTL) |= ((uint16_t)divider << 
                                             SYSCTL_CMCLKCTL_ETHDIV_S)|
                                            ((uint16_t)source << 
                                             SYSCTL_CMCLKCTL_ETHDIVSRCSEL_S);
  EDIS;
}

//*****************************************************************************
//
//! Enables the Ethercat I2C loopback.
//!
//! This function enables the Ethercat I2C loopback. Note that the Ethercat I2C
//!  loopback is disabled on reset.
//!
//! \return None.
//
//*****************************************************************************

static inline void
SysCtl_enableEthercatI2Cloopback(void)
{
  //
  // Set the I2C loopback enable bit.
  //
  EALLOW;
  HWREGH(CPUSYS_BASE + SYSCTL_O_ETHERCATCTL)|= SYSCTL_ETHERCAT_I2C_LOOPBACK ;
  EDIS;
}

//*****************************************************************************
//
//! Disables the Ethercat I2C loopback.
//!
//! This function disables the Ethercat I2C loopback.Note that the Ethercat I2C
//!  loopback is enabled on reset.
//!
//! \return None.
//
//*****************************************************************************

static inline void
SysCtl_disableEthercatI2Cloopback(void) 
{
  //
  // Clear the I2C loopback enable bit.
  //
  EALLOW;
  HWREGH(CPUSYS_BASE + SYSCTL_O_ETHERCATCTL)&= ~SYSCTL_ETHERCAT_I2C_LOOPBACK ;
  EDIS;

}

//*****************************************************************************
//
//! Gets the PIE Vector Fetch Error Handler Routine Address.
//!
//! The function indicates the address of the PIE Vector Fetch Error
//! handler routine. 
//!
//! \return Error Handler Address.
//! 
//! \note Its the responsibility of user to initialize this register. If this 
//! register is not initialized, a default error handler at address 
//! 0x3fffbe will get executed. 
//
//*****************************************************************************

static inline uint32_t
SysCtl_getPIEVErrAddr(void)
{
  return(HWREG(CPUSYS_BASE + SYSCTL_O_PIEVERRADDR));
}

//*****************************************************************************
//
//! Simulates a reset to the CPU1
//!
//! \param rstCauses is the cause for the reset.
//!
//! The \e rstCauses parameter can be one/ more of these values:
//! SYSCTL_CAUSE_POR or SYSCTL_CAUSE_XRS  
//! 
//! \return None.
//!
//! \note This API exists only on CPU1
//
//*****************************************************************************

static inline void
SysCtl_simulateReset(uint32_t rstCauses)
{
  //Write will succeed only if a matching key value is written 
  //to the KEY field
  //Sets the appropriate reset bit.
  //
  HWREG(CPUSYS_BASE + SYSCTL_O_SIMRESET) |= (rstCauses |
                                            (SYSCTL_REG_KEY &
                                             SYSCTL_SIMRESET_KEY_M));
}
//*****************************************************************************
//
//! Check if the CM is held in reset or not
//! 
//! Provides the reset status of CM to the CPU
//!
//! \return \b true if CM is in reset \b false if CM is out of reset
//
//*****************************************************************************

static inline bool
SysCtl_isCMReset(void)
{
  return((HWREGH(CMCONF_BASE + SYSCTL_O_CMRESCTL)&
          SYSCTL_CMRESCTL_RESETSTS)== 0U);
}

//*****************************************************************************
//
//! Enables the NMI generation to the C28x core
//!
//! \param Flags is the Bit mask of the NMI interrupts that user
//! wants, to generate an NMI to the C28x.
//!
//! The \e Flags parameter can be the value :
//! SYSCTL_FLAG_CMNMIWDRST.  
//! 
//! \return None.
//
//*****************************************************************************

static inline void
SysCtl_enableCMtoCPUNMI (uint32_t Flags)
{
  EALLOW;
  HWREGH(CPUSYS_BASE + SYSCTL_O_CMTOCPU1NMICTL)|= Flags ;
  EDIS;
}

//*****************************************************************************
//
//! Enables the Interrupt generation to the C28x core
//!
//! \param Flags is the Bit mask of the Interrupts that user
//! wants, to generate an Interrupt to the C28x.
//!
//! The \e Flags parameter can be the value :
//! SYSCTL_FLAG_CMNMIWDRST.  
//! 
//! \return None.
//
//*****************************************************************************

static inline void
SysCtl_enableCMtoCPUInterrupt (uint32_t Flags)
{
  EALLOW;
  HWREGH(CPUSYS_BASE + SYSCTL_O_CMTOCPU1INTCTL)|= Flags ;
  EDIS;
}

//*****************************************************************************
//
//! Disables the NMI generation to the C28x core
//!
//! \param Flags is the Bit mask of the NMI interrupts that user
//! wants, to generate an NMI to the C28x.
//!
//! The \e Flags parameter can be the value :
//! SYSCTL_FLAG_CMNMIWDRST.  
//! 
//! \return None.
//
//*****************************************************************************

static inline void
SysCtl_disableCMtoCPUNMI (uint32_t Flags)
{
  EALLOW;
  HWREGH(CPUSYS_BASE + SYSCTL_O_CMTOCPU1NMICTL)&= ~Flags ;
  EDIS;
}

//*****************************************************************************
//
//! Disables the Interrupt generation to the C28x core
//!
//! \param Flags is the Bit mask of the Interrupts that user
//! wants, to generate an Interrupt to the C28x.
//!
//! The \e Flags parameter can be the value :
//! SYSCTL_FLAG_CMNMIWDRST.  
//! 
//! \return None.
//
//*****************************************************************************

static inline void
SysCtl_disableCMtoCPUInterrupt (uint32_t Flags)
{
  EALLOW;
  HWREGH(CPUSYS_BASE + SYSCTL_O_CMTOCPU1INTCTL)&= ~Flags ;
  EDIS;
}

//*****************************************************************************
//
//! Gets the NMI generated on the C28x core
//! 
//! \return the NMI generated to the C28x.  The value can be:
//! SYSCTL_FLAG_CMNMIWDRST.
//
//*****************************************************************************

static inline uint16_t
SysCtl_getCMtoCPUNMI (void)
{
  return(HWREGH(CPUSYS_BASE + SYSCTL_O_CMTOCPU1NMICTL));
}

//*****************************************************************************
//
//! Gets the Interrupt generated on the C28x core
//! 
//! \return the Interrupt generated to the C28x.  The value can be:
//! SYSCTL_FLAG_CMNMIWDRST.
//
//*****************************************************************************

static inline uint16_t
SysCtl_getCMtoCPUInterrupt (void)
{
  return(HWREGH(CPUSYS_BASE + SYSCTL_O_CMTOCPU1INTCTL));
}

//*****************************************************************************
//
//! Configures the CM Peripheral Allocation for shared peripherals.
//!
//! \param peripheral is the peripheral being allocated to CM.
//! \param allocate decides if the peripheral is allocated to the C28x CPU1/2
//! or the CM.
//!
//! The \e peripheral parameter can have one enumerated value from
//! SysCtl_SharedPeripheral
//!
//! The \e allocate parameter can have one of the values from:
//! 0x0U: Peripheral is allocated to C28x CPU1/2, CM accesses to it will 
//! be ignored and interrupts from it will not be generated to CM. 
//! 0x1U: Peripheral is allocated to CM, C28x CPU1/2 accesses to it will 
//! be ignored and interrupts from it will not be generated to C28x CPU1/2.
//!
//! \return None.
//!
//! \note This API must be configured prior to enabling the 
//! peripheral clocks. CPU2 does not have access to this API for MCAN 
//! EtherCAT & USB peripherals.
//
//*****************************************************************************

static inline void
SysCtl_allocateSharedPeripheral(SysCtl_SharedPeripheral peripheral,
                                         uint16_t  allocate)
{
  EALLOW;
  //
  // Allocates the peripheral based on if the C28x or CM need access
  //
  if(allocate != 0x0U)
   {
    HWREG(CMCONF_BASE + SYSCTL_O_PALLOCATE0) |=((uint32_t)1U << peripheral);
   }
  else 
   {
    HWREG(CMCONF_BASE + SYSCTL_O_PALLOCATE0) &= ~((uint32_t)1U << peripheral);
   }
  EDIS;
}

//*****************************************************************************
//
//! Locks the CM configuration registers
//!
//! This function locks the CM configuration registers.
//!
//! \return None.
//
//*****************************************************************************

static inline void
SysCtl_lockCMConfig(void) 
{
  EALLOW;
  HWREG(CMCONF_BASE + 
        SYSCTL_O_CM_CONF_REGS_LOCK) = SYSCTL_CM_CONF_REGS_LOCK_LOCK;
  EDIS;
}

//*****************************************************************************
//
//! Gets the status of interrupts due to multiple sources of Cortex-M4 reset. 
//! 
//! \return the Interrupt generated on reset of the CM.  The values can be 
//! one/ more from:
//! SYSCTL_STATUS_CMGINT , SYSCTL_STATUS_CMNMIWDRST , 
//! SYSCTL_STATUS_CMSYSRESETREQ or SYSCTL_STATUS_CMVECTRESET.
//!
//! \note This API  is present only on CPU1.
//
//*****************************************************************************
static inline uint32_t
SysCtl_getCMInterruptStatus(void)
{
  return(HWREG(SYSSTAT_BASE + SYSCTL_O_CM_STATUS_INT_FLG));
}

//*****************************************************************************
//
//! Clears the interrupts due to multiple sources of Cortex-M4 reset. 
//! 
//! \param intFlags is the interrupt that needs to be cleared.
//!
//! The \e intFlags parameter are the Interrupts generated on reset of the CM
//! that need to be cleared. The values can be one/ more from:
//! SYSCTL_STATUS_CMGINT , SYSCTL_STATUS_CMNMIWDRST , 
//! SYSCTL_STATUS_CMSYSRESETREQ or SYSCTL_STATUS_CMVECTRESET. 
//! 
//! \return None.
//!
//! \note This API  is present only on CPU1.
//
//*****************************************************************************

static inline void
SysCtl_clearCMInterruptStatus(uint32_t intFlags)
{
  HWREGH(SYSSTAT_BASE + SYSCTL_O_CM_STATUS_INT_CLR) |= intFlags;
}

//*****************************************************************************
//
//! Sets the interrupt for the multiple sources of Cortex-M4 reset. 
//! 
//! \param intFlags is the interrupt that needs to be set.
//!
//! The \e intFlags parameter are the Interrupts generated on reset of the CM
//! that need to be set. The values can be one/ more from:
//! SYSCTL_STATUS_CMGINT , SYSCTL_STATUS_CMNMIWDRST , 
//! SYSCTL_STATUS_CMSYSRESETREQ or SYSCTL_STATUS_CMVECTRESET. 
//! 
//! \return None.
//!
//! \note This API  is present only on CPU1.
//
//*****************************************************************************

static inline void
SysCtl_setCMInterruptStatus(uint32_t intFlags) 
{
  EALLOW;
  HWREGH(SYSSTAT_BASE + SYSCTL_O_CM_STATUS_INT_SET) |= intFlags;
  EDIS;
}

//*****************************************************************************
//
//! Gets the status of interrupts due to multiple different 
//! errors in the system.
//! 
//! \return the Interrupt generated on the system. 
//! The values can be one/ more from:
//! SYSCTL_STATUS_GINT
//! SYSCTL_STATUS_EMIF_ERR
//! SYSCTL_STATUS_RAM_CORRECTABLE_ERR
//! SYSCTL_STATUS_FLASH_CORRECTABLE_ERR
//! SYSCTL_STATUS_RAM_ACC_VIOL
//! SYSCTL_STATUS_SYS_PLL_SLIP
//! SYSCTL_STATUS_AUX_PLL_SLIP
//! SYSCTL_STATUS_DCC0
//! SYSCTL_STATUS_DCC1
//! SYSCTL_STATUS_DCC2
//
//*****************************************************************************

static inline uint32_t
SysCtl_getInterruptStatus(void)
{
  return(HWREG(SYSSTAT_BASE + SYSCTL_O_SYS_ERR_INT_FLG));
}
//*****************************************************************************
//
//! Clears the interrupts due to multiple different errors in the system.
//! 
//! \param intFlags is the interrupt that needs to be cleared.
//!
//! The \e intFlags parameter are the Interrupts generated on errors in 
//! the system that need to be cleared. The values can be one or more from:
//! SYSCTL_STATUS_GINT
//! SYSCTL_STATUS_EMIF_ERR
//! SYSCTL_STATUS_RAM_CORRECTABLE_ERR
//! SYSCTL_STATUS_FLASH_CORRECTABLE_ERR
//! SYSCTL_STATUS_RAM_ACC_VIOL
//! SYSCTL_STATUS_SYS_PLL_SLIP
//! SYSCTL_STATUS_AUX_PLL_SLIP
//! SYSCTL_STATUS_DCC0
//! SYSCTL_STATUS_DCC1
//! SYSCTL_STATUS_DCC2
//! 
//! \return None.
//
//*****************************************************************************

static inline void
SysCtl_clearInterruptStatus(uint32_t intFlags)
{
  HWREGH(SYSSTAT_BASE + SYSCTL_O_SYS_ERR_INT_CLR) |= intFlags;
}
//*****************************************************************************
//
//! Sets the interrupts for the multiple different errors in the system. 
//! 
//! \param intFlags is the interrupt that needs to be set.
//!
//! The \e intFlags parameter are the Interrupts that can be set 
//! for the errors in the system. The values can be one/ more from:
//! SYSCTL_STATUS_GINT
//! SYSCTL_STATUS_EMIF_ERR
//! SYSCTL_STATUS_RAM_CORRECTABLE_ERR
//! SYSCTL_STATUS_FLASH_CORRECTABLE_ERR
//! SYSCTL_STATUS_RAM_ACC_VIOL
//! SYSCTL_STATUS_SYS_PLL_SLIP
//! SYSCTL_STATUS_AUX_PLL_SLIP
//! SYSCTL_STATUS_DCC0
//! SYSCTL_STATUS_DCC1
//! SYSCTL_STATUS_DCC2
//! 
//! \return None.
//!
//! \note This API  is present only on CPU1.
//
//*****************************************************************************

static inline void
SysCtl_setInterruptStatus(uint32_t intFlags)
{
  EALLOW;
  HWREGH(SYSSTAT_BASE + SYSCTL_O_SYS_ERR_INT_SET) |= intFlags;
  EDIS;
}

//*****************************************************************************
//
//! Check if the Internal PHY is present or not for the USB module
//! 
//! Provides the UAB module Internal PHY presence
//!
//! \return \b true if Internal USB PHY Module is present \b false if 
//! Internal USB PHY Module is not present
//
//*****************************************************************************
static inline uint32_t
SysCtl_isPresentUSBPHY(void) 
{
  return((HWREG(DEVCFG_BASE + SYSCTL_O_PERCNF1)&
          SYSCTL_PERCNF1_USB_A_PHY)!= 0U);
}


//*****************************************************************************
//
//! Locks the Device configuration registers
//!
//! This function locks the Device configuration registers.
//!
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_lockConfigRegs(SysCtl_DeviceConf regs)
{
  EALLOW;
  HWREG(DEVCFG_BASE + SYSCTL_O_DEVCFGLOCK2) |= ((uint32_t)1U << regs);
  EDIS;
}
//*****************************************************************************
//
//! Sets up CLB CLK dividers & configurations for a particuler CLB.
//!
//! \param divider is the value that configures the clock divider.
//! \param tdivider is the value that configures the tile clock divider.
//! \param inst is the CLB instance that needs clock settings.
//! \param config is the mode for the clock 
//!
//! This function sets up the CLB CLK configurations based on the instance  
//! that is selected. There are 2 dividers that scales the "source" to CLB 
//! CLK. The first one is the divider & the other the tile divider. 
//!
//! The \e divider parameter can have one enumerated value from
//! SysCtl_CLBClkDivider
//! The \e tdivider parameter can have one enumerated value from
//! SysCtl_CLBTClkDivider
//! The \e inst parameter can have one enumerated value from
//! SysCtl_CLBInst
//! The \e config parameter can have one enumerated value from
//! SysCtl_CLBClkm
//!
//! \return None.
//
//*****************************************************************************

static inline void
SysCtl_setCLBClk (SysCtl_CLBClkDivider divider, SysCtl_CLBTClkDivider tdivider,
                        SysCtl_CLBInst inst, SysCtl_CLBClkm config)
{
  EALLOW;
  //
  //clear the CLB clk configurations
  //
  HWREG(CLKCFG_BASE + SYSCTL_O_CLBCLKCTL) = (HWREG(CLKCFG_BASE + 
                                             SYSCTL_O_CLBCLKCTL) &
                                           ~(SYSCTL_CLBCLKCTL_CLBCLKDIV_M | 
                                             SYSCTL_CLBCLKCTL_TILECLKDIV |
                                            (0x1U << inst))); 

  //
  //set the clock configurations for the particular CLB
  //
  HWREG(CLKCFG_BASE + SYSCTL_O_CLBCLKCTL) |= ((uint32_t)divider << 
                                             SYSCTL_CLBCLKCTL_CLBCLKDIV_S)|
                                             ((uint32_t)tdivider << 
                                             SYSCTL_CLBCLKCTL_TILECLKDIV_S)|
                                             ((uint32_t)config  << inst);
  EDIS;
}
//*****************************************************************************
//
//! Configures the SYSPLL Spread Spectrum Modulation(SSM) 
//!
//! \param enable enables/disables the SYSPLL SSM.
//! \param srate configures the SYSPLL SSM spreading rate used to 
//! set the frequency.
//!
//! The \e enable parameter can be either of these values:
//! 0x0U: Spread Spectrum modulation is disabled
//! 0x1U: Modulation is enabled
//!
//! The \e srate parameter can take values satisfying the below formula:
//!
//! modulation frequency = OSCCLK/(2*NS)
//! Where NS = srate +1
//!
//! \return None.
//!
//! \note A value of 1 is added to this srate before it is copied into 
//! the PLL module.
//
//*****************************************************************************

static inline void
SysCtl_configureSSM(uint16_t enable , uint16_t  srate)
{
  EALLOW;
  //
  //clear the configurations
  //
  HWREG(CLKCFG_BASE + 
  SYSCTL_O_SYSPLLCTL2) = (HWREG(CLKCFG_BASE + SYSCTL_O_SYSPLLCTL2) &
                        ~(SYSCTL_SYSPLLCTL2_SPREADINGRATE_M | 
                          SYSCTL_SYSPLLCTL2_SSEN)); 
  
  //
  //set the clock configurations 
  //
  HWREG(CLKCFG_BASE + 
  SYSCTL_O_SYSPLLCTL2) = (enable << SYSCTL_SYSPLLCTL2_SSEN_S)|
                         (srate << SYSCTL_SYSPLLCTL2_SPREADINGRATE_S);
   EDIS;
}
//*****************************************************************************
//
//! Configures the SYSPLL Modulation Depth
//!
//! \param config is the modulation depth in the spread-spectrum mode.
//!
//! The \e config parameter can take values satifying the below formula:
//!
//! Modulation step-size = (NV/SYSPLL Multiplier) x PLL frequency,
//! where NV = (SPR_AMOUNT/32768)
//! 
//! \return None.
//
//*****************************************************************************

static inline void
SysCtl_setModDepth(uint32_t config)
{
  uint32_t modDep;
  EALLOW;

  //
  //Get the modulation depth settings from config
  //
  modDep  = (config >> SYSCTL_SYSPLLCTL3_IAMT_S) &
             SYSCTL_SYSPLLCTL3_SPR_IAMOUNT_M;

  modDep |= (config & SYSCTL_SYSPLLCTL3_SPR_FAMOUNT_M);

 //
 //Write modulation depth 
 //
 HWREG(CLKCFG_BASE + SYSCTL_O_SYSPLLCTL3) |= modDep;
 EDIS;
}

//*****************************************************************************
//
//! Controls the C28x core
//!
//! \param signal is the input signal used to control C28x
//! \param enable enables/disables the control of the C28x by the input signal.
//!
//! The \e signal parameter can be one/ more of these values:
//! SYSCTL_C28_MONPRIV
//! SYSCTL_C28_ENPROT
//!   
//! The \e enable parameter can be either of these values:
//! 0x0U: disable or 0x1U:enable control by the input
//! 
//! \return None.
//
//*****************************************************************************
static inline void
SysCtl_controlCore(uint32_t signal, uint16_t enable)
{
  EALLOW;
  //
  //Based on whether the control of the C28x by an input
  //signal needs to be enabled or disabled.
  //
  if(enable == 1U)
   {
    HWREGH(CLKCFG_BASE + SYSCTL_O_CCR) |= signal;
   }
  else
   {
   HWREGH(CLKCFG_BASE + SYSCTL_O_CCR) &= ~signal;
   }
  EDIS;
}

//*****************************************************************************
//
//! Gets the C28x core configurations
//! 
//! \return the core configuration signals. The values can be:
//! SYSCTL_C28_VMAPS
//! SYSCTL_C28_MONPRIV
//! SYSCTL_C28_ENPROT
//
//*****************************************************************************

static inline uint16_t
SysCtl_getCoreStatus(void)
{
  return(HWREGH(CLKCFG_BASE + SYSCTL_O_CCR));
}

//*****************************************************************************
//
//!  Gets the value of the Peripheral clock Stop register.
//!
//! \return Value of CLKSTOPREQ register.
//
//*****************************************************************************

static inline uint16_t
SysCtl_getPeripheralClockStop(void)
{
  //
  // Read the register and return the value of clk stop Req 
  //
  return(HWREGH(CPUSYS_BASE + SYSCTL_O_CLKSTOPREQ));
}

//*****************************************************************************
//
//!  Check if request to stop the clock to a Peripheral is Acked or Not.
//!
//! \param peripheral is the peripheral which acked the Stop clock Req or not .
//!
//! \return \b true if the peripheral acked the Stop clock Request
//! \b false if peripheral did not ack the Stop clock Request
//
//*****************************************************************************

static inline bool
SysCtl_isPeripheralClockStopAcked(SysCtl_PeripheralClkStopAck peripheral)
{
  uint16_t bitIndex;
  
  //
  // Decode the peripheral variable bits.
  //
  bitIndex = ((uint16_t)peripheral & SYSCTL_PERIPH_BIT_M) >>
              SYSCTL_PERIPH_BIT_S;
  
  //
  // Read the register and return true if the clk stop Req is acked or not.
  //
  return((HWREGH(CPUSYS_BASE + SYSCTL_O_CLKSTOPACK) &
        ((uint32_t)1U << bitIndex)) != 0U);

}

//*****************************************************************************
//
//!  Check if One or more of the error sources triggered
//!
//!  Following are the events/triggers that can indicate an error:
//!1. nmi interrupt on C28x
//!2. Watchdog reset
//!3. Error on a Pie vector fetch
//!4. Efuse error
//!5. nmi interrupt on CM
//! 
//! \return \b true if the error is triggered
//! \b false if the error is not triggered
//
//*****************************************************************************
static inline uint32_t
SysCtl_isErrorTriggered(void)
{
  return((HWREGH(NMI_BASE + NMI_O_ERRORSTS)&
          NMI_ERRORSTS_ERROR)!= 0U);
}

//*****************************************************************************
//
//! Forces an error flag to set to indicate an error being generated.
//!
//! \return None.
//
//*****************************************************************************

static inline void
SysCtl_forceError(void)
{
  EALLOW;
  HWREGH(NMI_BASE + NMI_O_ERRORSTSFRC) |= NMI_ERRORSTSFRC_ERROR;
  EDIS;
}

//*****************************************************************************
//
//! Clears any error flag set due to error generated.
//!
//! \return None.
//
//*****************************************************************************

static inline void
SysCtl_clearError(void)
{
  EALLOW;
  HWREGH(NMI_BASE + NMI_O_ERRORSTSCLR) |= NMI_ERRORSTSCLR_ERROR;
  EDIS;
}

//*****************************************************************************
//
//! Selects the polarity of the error pin
//! 
//! \param pol is the ERROR pin polarity
//!
//! The \e pol parameter can take any of the below values:
//! 0x0U: If an error is already triggered, Error pin will be driven 
//! with a value of 0, else 1.
//! 0x1U: If an error is already triggered, Error pin will be driven 
//! with a value of 1, else 0.
//! 
//! \return None.
//
//*****************************************************************************

static inline void
SysCtl_selectErrPinPolarity(uint16_t pol) 
{
  EALLOW;
  //
  //Configures the error pin polarity based on the provided polarity
  //
  if(pol == 1U)
   {
    HWREGH(NMI_BASE + NMI_O_ERRORCTL) |= NMI_ERRORSTSCLR_ERROR;
   }
  else
   {
   HWREGH(NMI_BASE + NMI_O_ERRORCTL) &= ~NMI_ERRORSTSCLR_ERROR;
   }
  EDIS;
}

//*****************************************************************************
//
//! Locks the Error control registers
//!
//! This function locks the Error configuration registers.
//!
//! \return None.
//!
//! \note The lock register is cleared only on a system reset.
//
//*****************************************************************************

static inline void
SysCtl_lockErrControl(void) 
{
  EALLOW;
  HWREG(NMI_BASE + NMI_O_ERRORLOCK) = NMI_ERRORLOCK_ERRORCTL;
  EDIS;

}
//*****************************************************************************
//
//! Delays for a fixed number of cycles.
//!
//! \param count is the number of delay loop iterations to perform.
//!
//! This function generates a constant length delay using assembly code. The
//! loop takes 5 cycles per iteration plus 9 cycles of overhead.
//!
//! \note If count is equal to zero, the loop will underflow and run for a
//! very long time.
//!
//! \return None.
//
//*****************************************************************************
extern void
SysCtl_delay(uint32_t count);

//*****************************************************************************
//
//! Calculates the system clock frequency (SYSCLK).
//!
//! \param clockInHz is the frequency of the oscillator clock source (OSCCLK).
//!
//! This function determines the frequency of the system clock based on the
//! frequency of the oscillator clock source (from \e clockInHz) and the PLL
//! and clock divider configuration registers.
//!
//! \return Returns the system clock frequency. If a missing clock is detected,
//! the function will return the INTOSC1 frequency. This needs to be
//! corrected and cleared (see SysCtl_resetMCD()) before trying to call this
//! function again.
//
//*****************************************************************************
extern uint32_t
SysCtl_getClock(uint32_t clockInHz);

//*****************************************************************************
//
//! Calculates the system auxiliary clock frequency (AUXPLLCLK).
//!
//! \param clockInHz is the frequency of the oscillator clock source 
//! (AUXOSCCLK).
//!
//! This function determines the frequency of the auxiliary clock based on the
//! frequency of the oscillator clock source (from \e clockInHz) and the AUXPLL
//! and clock divider configuration registers.
//!
//! \return Returns the auxiliary clock frequency.
//
//*****************************************************************************
extern uint32_t
SysCtl_getAuxClock(uint32_t clockInHz);

//*****************************************************************************
//
//! Configures the clocking of the device.
//!
//! \param config is the required configuration of the device clocking.
//!
//! This function configures the clocking of the device.  The input crystal
//! frequency, oscillator to be used, use of the PLL, and the system clock
//! divider are all configured with this function.
//!
//! The \e config parameter is the OR of several different values, many of
//! which are grouped into sets where only one can be chosen.
//!
//! - The system clock divider is chosen with the macro \b SYSCTL_SYSDIV(x)
//!   where x is either 1 or an even value up to 126.
//!
//! - The use of the PLL is chosen with either \b SYSCTL_PLL_ENABLE or
//!   \b SYSCTL_PLL_DISABLE.
//!
//! - The integer multiplier is chosen \b SYSCTL_IMULT(x) where x is a value
//!   from 1 to 127.
//!
//! - The fractional multiplier is chosen with either \b SYSCTL_FMULT_0,
//!   \b SYSCTL_FMULT_1_4, \b SYSCTL_FMULT_1_2, or \b SYSCTL_FMULT_3_4.
//!
//! - The oscillator source chosen with \b SYSCTL_OSCSRC_OSC2,
//!   \b SYSCTL_OSCSRC_XTAL, \b SYSCTL_OSCSRC_XTAL_SE or \b SYSCTL_OSCSRC_OSC1.
//!
//! This function uses the DCC to check that the PLLRAWCLK is running at the
//! expected rate. If you are using the DCC, you must back up its configuration
//! before calling this function and restore it afterward.
//!
//! \note See your device errata for more details about locking the PLL.
//!
//! \return Returns \b false if a missing clock error is detected. This needs
//! to be cleared (see SysCtl_resetMCD()) before trying to call this function
//! again. Also, returns \b false if the PLLRAWCLK is not running and its
//! expected rate after \b SYSCTL_PLL_RETRIES retries. Otherwise, returns
//! \b true.
//
//*****************************************************************************
extern bool
SysCtl_setClock(uint32_t config);

//*****************************************************************************
//
//! Configures the external oscillator for the clocking of the device.
//!
//! This function configures the external oscillator (XTAL) to be used for the
//! clocking of the device in crystal mode. It follows the procedure to turn on
//! the oscillator, wait for it to power up, and select it as the source of the
//! system clock.
//!
//! Please note that this function blocks while it waits for the XTAL to power
//! up. If the XTAL does not manage to power up properly, the function will
//! loop for a long time. It is recommended that you modify this function to
//! add an appropriate timeout and error-handling procedure.
//!
//! \return None.
//
//*****************************************************************************
extern void
SysCtl_selectXTAL(void);

//*****************************************************************************
//
//! Configures the external oscillator for the clocking of the device in
//! single-ended mode.
//!
//! This function configures the external oscillator (XTAL) to be used for the
//! clocking of the device in single-ended mode. It follows the procedure to
//! turn on the oscillator, wait for it to power up, and select it as the
//! source of the system clock.
//!
//! Please note that this function blocks while it waits for the XTAL to power
//! up. If the XTAL does not manage to power up properly, the function will
//! loop for a long time. It is recommended that you modify this function to
//! add an appropriate timeout and error-handling procedure.
//!
//! \return None.
//
//*****************************************************************************
extern void
SysCtl_selectXTALSingleEnded(void);

//*****************************************************************************
//
//! Selects the oscillator to be used for the clocking of the device.
//!
//! \param oscSource is the oscillator source to be configured.
//!
//! This function configures the oscillator to be used in the clocking of the
//! device. The \e oscSource parameter may take a value of
//! \b SYSCTL_OSCSRC_OSC2, \b SYSCTL_OSCSRC_XTAL, \b SYSCTL_OSCSRC_XTAL_SE, or
//! \b SYSCTL_OSCSRC_OSC1.
//!
//! \sa SysCtl_turnOnOsc()
//!
//! \return None.
//
//*****************************************************************************
extern void
SysCtl_selectOscSource(uint32_t oscSource);

//*****************************************************************************
//
//! Calculates the low-speed peripheral clock frequency (LSPCLK).
//!
//! \param clockInHz is the frequency of the oscillator clock source (OSCCLK).
//!
//! This function determines the frequency of the low-speed peripheral clock
//! based on the frequency of the oscillator clock source (from \e clockInHz)
//! and the PLL and clock divider configuration registers.
//!
//! \return Returns the low-speed peripheral clock frequency.
//
//*****************************************************************************
extern uint32_t
SysCtl_getLowSpeedClock(uint32_t clockInHz);

//*****************************************************************************
//
//! Get the device part parametric value
//!
//! \param parametric is the requested device parametric value
//!
//! This function gets the device part parametric value.
//!
//! The \e parametric parameter can have one the following enumerated values:
//! - \b SYSCTL_DEVICE_TEMPERATURE - Device Temperature
//! - \b SYSCTL_DEVICE_PACKAGE - Device Package
//! - \b SYSCTL_DEVICE_QUAL      - Device Qualification Status
//! - \b SYSCTL_DEVICE_PINCOUNT  - Device Pin Count
//! - \b SYSCTL_DEVICE_INSTASPIN - Device InstaSPIN Feature Set
//! - \b SYSCTL_DEVICE_FLASH     - Device Flash size (KB)
//! - \b SYSCTL_DEVICE_PARTID    - Device PARTID Format Revision
//! - \b SYSCTL_DEVICE_FAMILY    - Device Family
//! - \b SYSCTL_DEVICE_PARTNO    - Device Part Number
//! - \b SYSCTL_DEVICE_CLASSID   - Device Class ID
//!
//! \return Returns the specified parametric value.
//
//*****************************************************************************
extern uint16_t
SysCtl_getDeviceParametric(SysCtl_DeviceParametric parametric);

//*****************************************************************************
//
//!  Request to stop the clock to a Peripheral.
//!
//! \param peripheral is the peripheral to which the Stop clock request 
//! is sent.
//! \param enable is the value to be written to the Clk stop request register.
//!  This can take values of either 1U(enable) or 0U(disable).
//!
//! Once set, this bit is cleared either explicitly by passing a 0U to the API
//! or when clock to peripheral is turned on as a result of a wakeup event in
//! hardware
//!
//! \return None.
//
//*****************************************************************************
extern void
SysCtl_requestPeripheralClockStop(SysCtl_PeripheralClkStopReq peripheral,
                                            uint16_t enable);

//*****************************************************************************
//
//! Controls the reset of CPU2 by CPU1
//!
//! \param control is to deactivate / activate the reset to the CPU2.
//!
//! The \e control parameter can be a value from the enumeration
//! SysCtl_CoreReset
//! 
//! \return None.
//
//*****************************************************************************
extern void
SysCtl_controlCPU2Reset(SysCtl_CoreReset control);

//*****************************************************************************
//
//! Configures & locks/unlocks the peripheral type 
//!
//! \param type is the peripheral type that needs to be configured.
//! \param config is the configuration done to the peripheral which is 
//!  dependent on the peripheral type.
//! \param lock is to decide if writes for any further configuration is to 
//!  be allowed or not.
//!
//! The \e type parameter can be a value from the enumeration
//! SysCtl_SelType
//! The \e config parameter can be a value from the ones below:
//! 0x0U : disables the feature for the type.
//! 0x1U : enables the feature for the type. 
//! 
//! For USB : Global interrupt feature is enabled or not
//! For ECAP: ECAP registers are EALLOW protected or not.
//! For SDFM: Data Ready conditions do not generate the SDFMINT.
//! & Each filter generates a separate data ready interrupts.
//! For MEMMAP: Enables remapping SDRAM in lower 64kb of address space or not.
//! 
//! The \e lock parameter can be a value from the ones below:
//! 0x1U : Write for any further configuration is not allowed.
//! 0x0U : Write for any further configuration is allowed.
//! 
//! \return None.
//
//*****************************************************************************
extern void
SysCtl_configureType(SysCtl_SelType type , uint16_t config, uint16_t lock);

//*****************************************************************************
//
//!  Check if writes for any further configuration of peripheral types is to 
//!  be allowed or not.
//!
//! \param type is the peripheral type for which permissions are being checked
//! 
//! \return \b true if Write for any further configuration is not allowed.
//! \b false if Write for any further configuration is allowed.
//
//*****************************************************************************
extern bool
SysCtl_isConfigTypeLocked(SysCtl_SelType type);

//*****************************************************************************
//
//! Sets the owner for clock configuration
//! 
//! \param cpuInst is owner for the clock configuration.
//!
//! The \e cpuInst parameter can be a value from the enumeration
//! SysCtl_CPUSel
//! 
//! \return None.
//
//*****************************************************************************

extern void
SysCtl_setSemOwner (SysCtl_CPUSel cpuInst);

//*****************************************************************************
//
//! Locks the Clock configuration registers
//!
//! \param registerName is clock configuration register which needs to 
//! be locked.
//!
//! The \e registerName parameter can be a value from the enumeration
//! SysCtl_ClkRegSel
//!
//! \return None.
//!
//! \note The register is unlocked only on a system reset.
//
//*****************************************************************************

extern void
SysCtl_lockClkConfig(SysCtl_ClkRegSel registerName);

//*****************************************************************************
//
//! Locks the CPU system configuration registers
//!
//! \param registerName is CPU system configuration register which needs to 
//! be locked.
//!
//! The \e registerName parameter can be a value from the enumeration
//! SysCtl_CpuRegSel
//!
//! \return None.
//!
//! \note The register is unlocked only on a system reset.
//
//*****************************************************************************

extern void
SysCtl_lockSysConfig (SysCtl_CpuRegSel registerName);

//*****************************************************************************
//
//! Controls the reset of CM
//!
//! \param control is to deactivate /activate the reset to the CM.
//!
//! The \e control parameter can be a value from the enumeration
//! SysCtl_CoreReset
//! 
//! \return None.
//!
//! \note This API should activate reset to CM until CM is not in reset.
//
//*****************************************************************************
extern void
SysCtl_controlCMReset(SysCtl_CoreReset control);

//*****************************************************************************
//
//! Controls input to the PLL & AuxPLL
//!
//! \param source is the input to the PLL 
//! \param override controls if the input to the PLL is override or not.
//!
//! The \e source parameter can take one of the values below:
//! 
//! SYSCTL_PLLTEST_OVERRIDE - PWRDN and RESET inputs to the PLL
//! SYSCTL_PLLTEST_PWRDN - PWRDN input
//! SYSCTL_PLLTEST_RESET - RESET input
//! SYSCTL_PLLTEST_LOAD - LOAD input
//! SYSCTL_PLLTEST_CLRZ - CLRZ input
//! SYSCTL_PLLTEST_PWRDNZ - PWRDNZ input
//! SYSCTL_PLLTEST_PWRDNZ_LDO - PWRDNZ_LDO input
//! SYSCTL_PLLTEST_OVERRIDE_AUXPLL - PWRDN and RESET inputs to the PLL
//! SYSCTL_PLLTEST_PWRDN_AUXPLL- PWRDN input
//! SYSCTL_PLLTEST_RESET_AUXPLL -  RESET input
//! SYSCTL_PLLTEST_LOAD_AUXPLL - LOAD input
//! SYSCTL_PLLTEST_CLRZ_AUXPLL - CLRZ input
//! SYSCTL_PLLTEST_PWRDNZ_AUXPLL - PWRDNZ input
//! SYSCTL_PLLTEST_PWRDNZ_LDO_AUXPLL - PWRDNZ_LDO input
//! 
//! The \e override parameter can take one of the values below:
//! SYSCTL_PLLTEST_OVERRIDE: inputs to the PLL are controlled by the 
//! bits in PLLTEST register.
//! SYSCTL_PLLTEST_OVERRIDE_AUXPLL: inputs to the AUXPLL are controlled 
//! by the bits in PLLTEST register.
//! SYSCTL_PLLTEST_ALL :inputs to the PLL & AUXPLL are controlled 
//! by the bits in PLLTEST register.
//! 0x0U : inputs to the PLL controlled by functional circuit
//!
//! \return None.
//
//*****************************************************************************

extern void
SysCtl_controlPLL(uint32_t source, uint16_t override);
//*****************************************************************************
//
// Close the Doxygen group.
//! @}
//
//****************************************************************************

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif // SYSCTL_H
