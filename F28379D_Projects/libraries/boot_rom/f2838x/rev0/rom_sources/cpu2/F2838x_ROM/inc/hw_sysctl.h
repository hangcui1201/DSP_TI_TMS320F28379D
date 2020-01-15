//###########################################################################
//
// FILE:    hw_sysctl.h
//
// TITLE:   Definitions for the SYSCTL registers.
//
//###########################################################################
// $TI Release:  $
// $Release Date:  $
// $Copyright:  $
//###########################################################################

#ifndef HW_SYSCTL_H
#define HW_SYSCTL_H

//*****************************************************************************
//
// The following are defines for the SYSCTL register offsets
//
//*****************************************************************************
#define SYSCTL_O_CLKSEM           0x0U         // Clock Control Semaphore
                                               // Register
#define SYSCTL_O_CLKCFGLOCK1      0x2U         // Lock bit for CLKCFG registers
#define SYSCTL_O_CLKSRCCTL1       0x8U         // Clock Source Control
                                               // register-1
#define SYSCTL_O_CLKSRCCTL2       0xAU         // Clock Source Control
                                               // register-2
#define SYSCTL_O_CLKSRCCTL3       0xCU         // Clock Source Control
                                               // register-3
#define SYSCTL_O_SYSPLLCTL1       0xEU         // SYSPLL Control register-1
#define SYSCTL_O_SYSPLLCTL2       0x10U        // SYSPLL Control register-2
#define SYSCTL_O_SYSPLLCTL3       0x12U        // SYSPLL Control register-3
#define SYSCTL_O_SYSPLLMULT       0x14U        // SYSPLL Multiplier register
#define SYSCTL_O_SYSPLLSTS        0x16U        // SYSPLL Status register
#define SYSCTL_O_AUXPLLCTL1       0x18U        // AUXPLL Control register-1
#define SYSCTL_O_AUXPLLMULT       0x1EU        // AUXPLL Multiplier register
#define SYSCTL_O_AUXPLLSTS        0x20U        // AUXPLL Status register
#define SYSCTL_O_SYSCLKDIVSEL     0x22U        // System Clock Divider Select
                                               // register
#define SYSCTL_O_AUXCLKDIVSEL     0x24U        // Auxillary Clock Divider
                                               // Select register
#define SYSCTL_O_PERCLKDIVSEL     0x26U        // Peripheral Clock Divider
                                               // Selet register
#define SYSCTL_O_XCLKOUTDIVSEL    0x28U        // XCLKOUT Divider Select
                                               // register
#define SYSCTL_O_CLBCLKCTL        0x2AU        // CLB Clocking Control Register
#define SYSCTL_O_LOSPCP           0x2CU        // Low Speed Clock Source
                                               // Prescalar
#define SYSCTL_O_MCDCR            0x2EU        // Missing Clock Detect Control
                                               // Register
#define SYSCTL_O_X1CNT            0x30U        // 10-bit Counter on X1 Clock
#define SYSCTL_O_XTALCR           0x32U        // XTAL Control Register
#define SYSCTL_O_PLLTEST          0x34U        // PLL Test Register
#define SYSCTL_O_ETHERCATCLKCTL   0x36U        // ETHERCATCLKCTL
#define SYSCTL_O_CMCLKCTL         0x38U        // CMCLKCTL
#define SYSCTL_O_CPUSYSLOCK1      0x0U         // Lock bit for CPUSYS registers
#define SYSCTL_O_CPUSYSLOCK2      0x2U         // Lock bit for CPUSYS registers
#define SYSCTL_O_PIEVERRADDR      0xAU         // PIE Vector Fetch Error
                                               // Address register
#define SYSCTL_O_ETHERCATCTL      0xCU         // ETHERCAT control register.
#define SYSCTL_O_PCLKCR0          0x22U        // Peripheral Clock Gating
                                               // Registers
#define SYSCTL_O_PCLKCR1          0x24U        // Peripheral Clock Gating
                                               // Registers
#define SYSCTL_O_PCLKCR2          0x26U        // Peripheral Clock Gating
                                               // Registers
#define SYSCTL_O_PCLKCR3          0x28U        // Peripheral Clock Gating
                                               // Registers
#define SYSCTL_O_PCLKCR4          0x2AU        // Peripheral Clock Gating
                                               // Registers
#define SYSCTL_O_PCLKCR6          0x2EU        // Peripheral Clock Gating
                                               // Registers
#define SYSCTL_O_PCLKCR7          0x30U        // Peripheral Clock Gating
                                               // Registers
#define SYSCTL_O_PCLKCR8          0x32U        // Peripheral Clock Gating
                                               // Registers
#define SYSCTL_O_PCLKCR9          0x34U        // Peripheral Clock Gating
                                               // Registers
#define SYSCTL_O_PCLKCR10         0x36U        // Peripheral Clock Gating
                                               // Registers
#define SYSCTL_O_PCLKCR11         0x38U        // Peripheral Clock Gating
                                               // Registers
#define SYSCTL_O_PCLKCR13         0x3CU        // Peripheral Clock Gating
                                               // Registers
#define SYSCTL_O_PCLKCR14         0x3EU        // Peripheral Clock Gating
                                               // Registers
#define SYSCTL_O_PCLKCR16         0x42U        // Peripheral Clock Gating
                                               // Registers
#define SYSCTL_O_PCLKCR17         0x44U        // Peripheral Clock Gating
                                               // Registers
#define SYSCTL_O_PCLKCR18         0x46U        // Peripheral Clock Gating
                                               // Registers
#define SYSCTL_O_PCLKCR20         0x4AU        // Peripheral Clock Gating
                                               // Registers
#define SYSCTL_O_PCLKCR21         0x4CU        // Peripheral Clock Gating
                                               // Registers
#define SYSCTL_O_PCLKCR22         0x4EU        // Peripheral Clock Gating
                                               // Registers
#define SYSCTL_O_PCLKCR23         0x50U        // Peripheral Clock Gating
                                               // Registers
#define SYSCTL_O_SIMRESET         0x70U        // Simulated Reset Register
#define SYSCTL_O_CCR              0x72U        // Core Control register (not
                                               // documented for users)
#define SYSCTL_O_SECMSEL          0x74U        // Secondary Master Select
                                               // register for common peripherals:
                                               // Selects between CLA & DMA
#define SYSCTL_O_LPMCR            0x76U        // LPM Control Register
#define SYSCTL_O_GPIOLPMSEL0      0x78U        // GPIO LPM Wakeup select
                                               // registers
#define SYSCTL_O_GPIOLPMSEL1      0x7AU        // GPIO LPM Wakeup select
                                               // registers
#define SYSCTL_O_TMR2CLKCTL       0x7CU        // Timer2 Clock Measurement
                                               // functionality control register
#define SYSCTL_O_RESCCLR          0x7EU        // Reset Cause Clear Register
#define SYSCTL_O_RESC             0x80U        // Reset Cause register
#define SYSCTL_O_MCANWAKESTATUS   0x98U        // MCAN Wake Status Register
#define SYSCTL_O_MCANWAKESTATUSCLR  0x9AU        // MCAN Wake Status Clear
#define SYSCTL_O_CLKSTOPREQ       0x9CU        // Peripheral Clock Stop Request
                                               // Register
#define SYSCTL_O_CLKSTOPACK       0x9EU        // Peripheral Clock Stop
                                               // Ackonwledge Register
#define SYSCTL_O_CLA1TASKSRCSELLOCK  0x0U         // CLA1 Task Trigger Source
                                               // Select Lock Register
#define SYSCTL_O_DMACHSRCSELLOCK  0x4U         // DMA Channel Triger Source
                                               // Select Lock Register
#define SYSCTL_O_CLA1TASKSRCSEL1  0x6U         // CLA1 Task Trigger Source
                                               // Select Register-1
#define SYSCTL_O_CLA1TASKSRCSEL2  0x8U         // CLA1 Task Trigger Source
                                               // Select Register-2
#define SYSCTL_O_DMACHSRCSEL1     0x16U        // DMA Channel Trigger Source
                                               // Select Register-1
#define SYSCTL_O_DMACHSRCSEL2     0x18U        // DMA Channel Trigger Source
                                               // Select Register-2
#define SYSCTL_O_DEVCFGLOCK1      0x0U         // Lock bit for DEVCFG registers
#define SYSCTL_O_DEVCFGLOCK2      0x2U         // Lock bit for DEVCFG registers
#define SYSCTL_O_PARTIDL          0x8U         // Lower 32-bit of Device PART
                                               // Identification Number
#define SYSCTL_O_PARTIDH          0xAU         // Upper 32-bit of Device PART
                                               // Identification Number
#define SYSCTL_O_REVID            0xCU         // Device Revision Number
#define SYSCTL_O_DC0              0x10U        // Device Capability: Device
                                               // Information
#define SYSCTL_O_DC1              0x12U        // Device Capability: Processing
                                               // Block Customization
#define SYSCTL_O_DC2              0x14U        // Device Capability: EMIF
                                               // Customization
#define SYSCTL_O_DC3              0x16U        // Device Capability: Peripheral
                                               // Customization
#define SYSCTL_O_DC4              0x18U        // Device Capability: Peripheral
                                               // Customization
#define SYSCTL_O_DC5              0x1AU        // Device Capability: Peripheral
                                               // Customization
#define SYSCTL_O_DC7              0x1EU        // Device Capability: Peripheral
                                               // Customization
#define SYSCTL_O_DC8              0x20U        // Device Capability: Peripheral
                                               // Customization
#define SYSCTL_O_DC9              0x22U        // Device Capability: Peripheral
                                               // Customization
#define SYSCTL_O_DC10             0x24U        // Device Capability: Peripheral
                                               // Customization
#define SYSCTL_O_DC11             0x26U        // Device Capability: Peripheral
                                               // Customization
#define SYSCTL_O_DC12             0x28U        // Device Capability: Peripheral
                                               // Customization
#define SYSCTL_O_DC14             0x2CU        // Device Capability: Analog
                                               // Modules Customization
#define SYSCTL_O_DC15             0x2EU        // Device Capability: Analog
                                               // Modules Customization
#define SYSCTL_O_DC17             0x32U        // Device Capability: Analog
                                               // Modules Customization
#define SYSCTL_O_DC18             0x34U        // Device Capability: Lx.1 SRAM
                                               // Customization
#define SYSCTL_O_DC19             0x36U        // Device Capability: Lx.2 SRAM
                                               // Customization
#define SYSCTL_O_DC20             0x38U        // Device Capability: GSx SRAM
                                               // Customization
#define SYSCTL_O_DC21             0x3AU        // Device Capability: CLB
#define SYSCTL_O_DC22             0x3CU        // Device Capability: FSI
#define SYSCTL_O_DC24             0x40U        // Device Capability: PMBUS
#define SYSCTL_O_DC25             0x42U        // Device Capability: DCC
#define SYSCTL_O_DC26             0x44U        // Device Capability: ETHERCAT
#define SYSCTL_O_DC27             0x46U        // Device Capability: CRC
                                               // modules
#define SYSCTL_O_PERCNF1          0x60U        // Peripheral Configuration
                                               // register
#define SYSCTL_O_FUSEERR          0x74U        // e-Fuse error Status register
#define SYSCTL_O_DIEID0           0x76U        // DIE ID Register Bits 31:0
#define SYSCTL_O_DIEID1           0x78U        // DIE ID Register Bits 63:32
#define SYSCTL_O_DIEID2           0x7AU        // DIE ID Register Bits 95:64
#define SYSCTL_O_DIEID3           0x7CU        // DIE ID Register Bits 127:96
#define SYSCTL_O_SOFTPRES0        0x82U        // Processing Block Software
                                               // Reset register
#define SYSCTL_O_SOFTPRES1        0x84U        // EMIF Software Reset register
#define SYSCTL_O_SOFTPRES2        0x86U        // Peripheral Software Reset
                                               // register
#define SYSCTL_O_SOFTPRES3        0x88U        // Peripheral Software Reset
                                               // register
#define SYSCTL_O_SOFTPRES4        0x8AU        // Peripheral Software Reset
                                               // register
#define SYSCTL_O_SOFTPRES6        0x8EU        // Peripheral Software Reset
                                               // register
#define SYSCTL_O_SOFTPRES7        0x90U        // Peripheral Software Reset
                                               // register
#define SYSCTL_O_SOFTPRES8        0x92U        // Peripheral Software Reset
                                               // register
#define SYSCTL_O_SOFTPRES9        0x94U        // Peripheral Software Reset
                                               // register
#define SYSCTL_O_SOFTPRES10       0x96U        // Peripheral Software Reset
                                               // register
#define SYSCTL_O_SOFTPRES11       0x98U        // Peripheral Software Reset
                                               // register
#define SYSCTL_O_SOFTPRES13       0x9CU        // Peripheral Software Reset
                                               // register
#define SYSCTL_O_SOFTPRES14       0x9EU        // Peripheral Software Reset
                                               // register
#define SYSCTL_O_SOFTPRES16       0xA2U        // Peripheral Software Reset
                                               // register
#define SYSCTL_O_SOFTPRES17       0xA4U        // Reserved Peripheral Software
                                               // Reset register
#define SYSCTL_O_SOFTPRES18       0xA6U        // Reserved Peripheral Software
                                               // Reset register
#define SYSCTL_O_SOFTPRES20       0xAAU        // Peripheral Software Reset
                                               // register
#define SYSCTL_O_SOFTPRES21       0xACU        // Peripheral Software Reset
                                               // register
#define SYSCTL_O_SOFTPRES23       0xB0U        // Peripheral Software Reset
                                               // register
#define SYSCTL_O_CPUSEL0          0xD6U        // CPU Select register for
                                               // common peripherals
#define SYSCTL_O_CPUSEL1          0xD8U        // CPU Select register for
                                               // common peripherals
#define SYSCTL_O_CPUSEL2          0xDAU        // CPU Select register for
                                               // common peripherals
#define SYSCTL_O_CPUSEL4          0xDEU        // CPU Select register for
                                               // common peripherals
#define SYSCTL_O_CPUSEL5          0xE0U        // CPU Select register for
                                               // common peripherals
#define SYSCTL_O_CPUSEL6          0xE2U        // CPU Select register for
                                               // common peripherals
#define SYSCTL_O_CPUSEL7          0xE4U        // CPU Select register for
                                               // common peripherals
#define SYSCTL_O_CPUSEL8          0xE6U        // CPU Select register for
                                               // common peripherals
#define SYSCTL_O_CPUSEL9          0xE8U        // CPU Select register for
                                               // common peripherals
#define SYSCTL_O_CPUSEL11         0xECU        // CPU Select register for
                                               // common peripherals
#define SYSCTL_O_CPUSEL12         0xEEU        // CPU Select register for
                                               // common peripherals
#define SYSCTL_O_CPUSEL14         0xF2U        // CPU Select register for
                                               // common peripherals
#define SYSCTL_O_CPUSEL15         0xF4U        // CPU Select register for
                                               // common peripherals
#define SYSCTL_O_CPUSEL16         0xF6U        // CPU Select register for
                                               // common peripherals
#define SYSCTL_O_CPUSEL18         0xFAU        // CPU Select register for
                                               // common peripherals
#define SYSCTL_O_CPUSEL25         0x108U       // CPU Select register for
                                               // common peripherals
#define SYSCTL_O_CPU2RESCTL       0x122U       // CPU2 Reset Control Register
#define SYSCTL_O_RSTSTAT          0x124U       // Reset Status register for
                                               // secondary C28x CPUs
#define SYSCTL_O_LPMSTAT          0x125U       // LPM Status Register for
                                               // secondary C28x CPUs
#define SYSCTL_O_CPU1ROM_DC1      0x140U       // Device Capabiity registers
                                               // for ROM
#define SYSCTL_O_CPU1ROM_DC2      0x142U       // Device Capabiity registers
                                               // for ROM
#define SYSCTL_O_CPU1ROM_DC3      0x144U       // Device Capabiity registers
                                               // for ROM
#define SYSCTL_O_CPU1ROM_DC4      0x146U       // Device Capabiity registers
                                               // for ROM
#define SYSCTL_O_CPU2ROM_DC1      0x150U       // Device Capabiity registers
                                               // for ROM
#define SYSCTL_O_CPU2ROM_DC2      0x152U       // Device Capabiity registers
                                               // for ROM
#define SYSCTL_O_CPU2ROM_DC3      0x154U       // Device Capabiity registers
                                               // for ROM
#define SYSCTL_O_CPU2ROM_DC4      0x156U       // Device Capabiity registers
                                               // for ROM
#define SYSCTL_O_BANKSEL          0x184U       // Configures the bank to
                                               // programmed by CPU1.
#define SYSCTL_O_USBTYPE          0x19AU       // Configures USB Type for the
                                               // device
#define SYSCTL_O_ECAPTYPE         0x19BU       // Configures ECAP Type for the
                                               // device
#define SYSCTL_O_SDFMTYPE         0x19CU       // Configures SDFM Type for the
                                               // device
#define SYSCTL_O_MEMMAPTYPE       0x19EU       // Configures Memory Map Type
                                               // for the device
#define SYSCTL_O_ADCA_AC          0x0U         // ADCA Master Access Control
                                               // Register
#define SYSCTL_O_ADCB_AC          0x2U         // ADCB Master Access Control
                                               // Register
#define SYSCTL_O_ADCC_AC          0x4U         // ADCC Master Access Control
                                               // Register
#define SYSCTL_O_ADCD_AC          0x6U         // ADCD Master Access Control
                                               // Register
#define SYSCTL_O_CMPSS1_AC        0x10U        // CMPSS1 Master Access Control
                                               // Register
#define SYSCTL_O_CMPSS2_AC        0x12U        // CMPSS2 Master Access Control
                                               // Register
#define SYSCTL_O_CMPSS3_AC        0x14U        // CMPSS3 Master Access Control
                                               // Register
#define SYSCTL_O_CMPSS4_AC        0x16U        // CMPSS4 Master Access Control
                                               // Register
#define SYSCTL_O_CMPSS5_AC        0x18U        // CMPSS5 Master Access Control
                                               // Register
#define SYSCTL_O_CMPSS6_AC        0x1AU        // CMPSS6 Master Access Control
                                               // Register
#define SYSCTL_O_CMPSS7_AC        0x1CU        // CMPSS7 Master Access Control
                                               // Register
#define SYSCTL_O_CMPSS8_AC        0x1EU        // CMPSS8 Master Access Control
                                               // Register
#define SYSCTL_O_DACA_AC          0x28U        // DACA Master Access Control
                                               // Register
#define SYSCTL_O_DACB_AC          0x2AU        // DACB Master Access Control
                                               // Register
#define SYSCTL_O_DACC_AC          0x2CU        // DACC Master Access Control
                                               // Register
#define SYSCTL_O_EPWM1_AC         0x48U        // EPWM1 Master Access Control
                                               // Register
#define SYSCTL_O_EPWM2_AC         0x4AU        // EPWM2 Master Access Control
                                               // Register
#define SYSCTL_O_EPWM3_AC         0x4CU        // EPWM3 Master Access Control
                                               // Register
#define SYSCTL_O_EPWM4_AC         0x4EU        // EPWM4 Master Access Control
                                               // Register
#define SYSCTL_O_EPWM5_AC         0x50U        // EPWM5 Master Access Control
                                               // Register
#define SYSCTL_O_EPWM6_AC         0x52U        // EPWM6 Master Access Control
                                               // Register
#define SYSCTL_O_EPWM7_AC         0x54U        // EPWM7 Master Access Control
                                               // Register
#define SYSCTL_O_EPWM8_AC         0x56U        // EPWM8 Master Access Control
                                               // Register
#define SYSCTL_O_EPWM9_AC         0x58U        // EPWM9 Master Access Control
                                               // Register
#define SYSCTL_O_EPWM10_AC        0x5AU        // EPWM10 Master Access Control
                                               // Register
#define SYSCTL_O_EPWM11_AC        0x5CU        // EPWM11 Master Access Control
                                               // Register
#define SYSCTL_O_EPWM12_AC        0x5EU        // EPWM12 Master Access Control
                                               // Register
#define SYSCTL_O_EPWM13_AC        0x60U        // EPWM13 Master Access Control
                                               // Register
#define SYSCTL_O_EPWM14_AC        0x62U        // EPWM14 Master Access Control
                                               // Register
#define SYSCTL_O_EPWM15_AC        0x64U        // EPWM15 Master Access Control
                                               // Register
#define SYSCTL_O_EPWM16_AC        0x66U        // EPWM16 Master Access Control
                                               // Register
#define SYSCTL_O_EQEP1_AC         0x70U        // EQEP1 Master Access Control
                                               // Register
#define SYSCTL_O_EQEP2_AC         0x72U        // EQEP2 Master Access Control
                                               // Register
#define SYSCTL_O_EQEP3_AC         0x74U        // EQEP3 Master Access Control
                                               // Register
#define SYSCTL_O_ECAP1_AC         0x80U        // ECAP1 Master Access Control
                                               // Register
#define SYSCTL_O_ECAP2_AC         0x82U        // ECAP2 Master Access Control
                                               // Register
#define SYSCTL_O_ECAP3_AC         0x84U        // ECAP3 Master Access Control
                                               // Register
#define SYSCTL_O_ECAP4_AC         0x86U        // ECAP4 Master Access Control
                                               // Register
#define SYSCTL_O_ECAP5_AC         0x88U        // ECAP5 Master Access Control
                                               // Register
#define SYSCTL_O_ECAP6_AC         0x8AU        // ECAP6 Master Access Control
                                               // Register
#define SYSCTL_O_ECAP7_AC         0x8CU        // ECAP7 Master Access Control
                                               // Register
#define SYSCTL_O_SDFM1_AC         0xA8U        // SDFM1 Master Access Control
                                               // Register
#define SYSCTL_O_SDFM2_AC         0xAAU        // SDFM2 Master Access Control
                                               // Register
#define SYSCTL_O_CLB1_AC          0xB0U        // CLB1 Master Access Control
                                               // Register
#define SYSCTL_O_CLB2_AC          0xB2U        // CLB2 Master Access Control
                                               // Register
#define SYSCTL_O_CLB3_AC          0xB4U        // CLB3 Master Access Control
                                               // Register
#define SYSCTL_O_CLB4_AC          0xB6U        // CLB4 Master Access Control
                                               // Register
#define SYSCTL_O_CLB5_AC          0xB8U        // CLB5 Master Access Control
                                               // Register
#define SYSCTL_O_CLB6_AC          0xBAU        // CLB6 Master Access Control
                                               // Register
#define SYSCTL_O_CLB7_AC          0xBCU        // CLB7 Master Access Control
                                               // Register
#define SYSCTL_O_CLB8_AC          0xBEU        // CLB8 Master Access Control
                                               // Register
#define SYSCTL_O_SPIA_AC          0x110U       // SPIA Master Access Control
                                               // Register
#define SYSCTL_O_SPIB_AC          0x112U       // SPIB Master Access Control
                                               // Register
#define SYSCTL_O_SPIC_AC          0x114U       // SPIC Master Access Control
                                               // Register
#define SYSCTL_O_SPID_AC          0x116U       // SPID Master Access Control
                                               // Register
#define SYSCTL_O_PMBUS_A_AC       0x130U       // PMBUSA Master Access Control
                                               // Register
#define SYSCTL_O_CAN_A_AC         0x140U       // CAN_A Master Access Control
                                               // Register
#define SYSCTL_O_CAN_B_AC         0x142U       // CAN_B Master Access Control
                                               // Register
#define SYSCTL_O_MCBSPA_AC        0x150U       // MCBSPA Master Access Control
                                               // Register
#define SYSCTL_O_MCBSPB_AC        0x152U       // MCBSPB Master Access Control
                                               // Register
#define SYSCTL_O_USBA_AC          0x180U       // USBA Master Access Control
                                               // Register
#define SYSCTL_O_HRPWM_AC         0x1A8U       // HRPWM Master Access Control
                                               // Register
#define SYSCTL_O_ETHERCAT_AC      0x1AAU       // ETHERCAT Master Access
                                               // Control Register
#define SYSCTL_O_FSIATX_AC        0x1B0U       // FSIATX Master Access Control
                                               // Register
#define SYSCTL_O_FSIARX_AC        0x1B2U       // FSIARX Master Access Control
                                               // Register
#define SYSCTL_O_FSIBTX_AC        0x1B4U       // FSIBTX Master Access Control
                                               // Register
#define SYSCTL_O_FSIBRX_AC        0x1B6U       // FSIBRX Master Access Control
                                               // Register
#define SYSCTL_O_FSICRX_AC        0x1BAU       // FSICRX Master Access Control
                                               // Register
#define SYSCTL_O_FSIDRX_AC        0x1BEU       // FSIDRX Master Access Control
                                               // Register
#define SYSCTL_O_FSIERX_AC        0x1C2U       // FSIERX Master Access Control
                                               // Register
#define SYSCTL_O_FSIFRX_AC        0x1C6U       // FSIFRX Master Access Control
                                               // Register
#define SYSCTL_O_FSIGRX_AC        0x1CAU       // FSIGRX Master Access Control
                                               // Register
#define SYSCTL_O_FSIHRX_AC        0x1CEU       // FSIHRX Master Access Control
                                               // Register
#define SYSCTL_O_PERIPH_AC_LOCK   0x1FEU       // Lock Register to stop Write
                                               // access to peripheral Access
                                               // register.
#define SYSCTL_O_CMRESCTL         0x0U         // CM Reset Control Register
#define SYSCTL_O_CMTOCPU1NMICTL   0x2U         // CM To CPU1 NMI Control
                                               // register
#define SYSCTL_O_CMTOCPU1INTCTL   0x4U         // CM To CPU1 interrupt Control
                                               // register
#define SYSCTL_O_PALLOCATE0       0x20U        // CM Peripheral Allocation
                                               // Register.
#define SYSCTL_O_CM_CONF_REGS_LOCK  0x3FEU       // CM Configuration Registers
                                               // Lock
#define SYSCTL_O_CM_STATUS_INT_FLG  0x0U         // Status of interrupts due to
                                               // multiple sources of Cortex-M4
                                               // reset.
#define SYSCTL_O_CM_STATUS_INT_CLR  0x2U         // CM_STATUS_INT_FLG clear
                                               // register
#define SYSCTL_O_CM_STATUS_INT_SET  0x4U         // CM_STATUS_INT_FLG set
                                               // register
#define SYSCTL_O_CM_STATUS_MASK   0x6U         // CM_STATUS_MASK register
#define SYSCTL_O_SYS_ERR_INT_FLG  0x10U        // Status of interrupts due to
                                               // multiple different errors in
                                               // the system.
#define SYSCTL_O_SYS_ERR_INT_CLR  0x12U        // SYS_ERR_INT_FLG clear
                                               // register
#define SYSCTL_O_SYS_ERR_INT_SET  0x14U        // SYS_ERR_INT_FLG set register
#define SYSCTL_O_SYS_ERR_MASK     0x16U        // SYS_ERR_MASK register
#define SYSCTL_O_VMTSEL           0x0U         // VMT Select Register
#define SYSCTL_O_VMTSIGEN         0x2U         // VMTSIGEN Register
#define SYSCTL_O_SPARE_MMR1       0x4U         // SPARE_MMR1 Register
#define SYSCTL_O_SPARE_MMR2       0x6U         // SPARE_MMR2 Register
#define SYSCTL_O_SPARE_MMR3       0x8U         // SPARE_MMR3 Register
#define SYSCTL_O_SPARE_MMR4       0xAU         // SPARE_MMR4 Register
#define SYSCTL_O_SPARE_MMR5       0xCU         // SPARE_MMR5 Register
#define SYSCTL_O_SPARE_MMR6       0xEU         // SPARE_MMR6 Register
#define SYSCTL_O_SPARE_MMR7       0x10U        // SPARE_MMR7 Register
#define SYSCTL_O_ECAPTESTMUX0     0x12U        // ECAPTESTMUX0 Register
#define SYSCTL_O_ECAPTESTMUX1     0x14U        // ECAPTESTMUX1 Register
#define SYSCTL_O_ECAPTESTMUX2     0x16U        // ECAPTESTMUX2 Register
#define SYSCTL_O_SYNCSELECT       0x0U         // Sync Input and Output Select
                                               // Register
#define SYSCTL_O_ADCSOCOUTSELECT  0x2U         // External ADC (Off Chip) SOC
                                               // Select Register
#define SYSCTL_O_SYNCSOCLOCK      0x4U         // SYNCSEL and EXTADCSOC Select
                                               // Lock register

//*****************************************************************************
//
// The following are defines for the bit fields in the CLKSEM register
//
//*****************************************************************************
#define SYSCTL_CLKSEM_SEM_S       0U
#define SYSCTL_CLKSEM_SEM_M       0x3U         // Semaphore for CLKCFG
                                               // Ownership by CPU1 or CPU2
#define SYSCTL_CLKSEM_KEY_S       16U
#define SYSCTL_CLKSEM_KEY_M       0xFFFF0000U  // Key Qualifier for writes to
                                               // this register

//*****************************************************************************
//
// The following are defines for the bit fields in the CLKCFGLOCK1 register
//
//*****************************************************************************
#define SYSCTL_CLKCFGLOCK1_CLKSRCCTL1  0x1U         // Lock bit for CLKSRCCTL1
                                               // register
#define SYSCTL_CLKCFGLOCK1_CLKSRCCTL2  0x2U         // Lock bit for CLKSRCCTL2
                                               // register
#define SYSCTL_CLKCFGLOCK1_CLKSRCCTL3  0x4U         // Lock bit for CLKSRCCTL3
                                               // register
#define SYSCTL_CLKCFGLOCK1_SYSPLLCTL1  0x8U         // Lock bit for SYSPLLCTL1
                                               // register
#define SYSCTL_CLKCFGLOCK1_SYSPLLCTL2  0x10U        // Lock bit for SYSPLLCTL2
                                               // register
#define SYSCTL_CLKCFGLOCK1_SYSPLLCTL3  0x20U        // Lock bit for SYSPLLCTL3
                                               // register
#define SYSCTL_CLKCFGLOCK1_SYSPLLMULT  0x40U        // Lock bit for SYSPLLMULT
                                               // register
#define SYSCTL_CLKCFGLOCK1_AUXPLLCTL1  0x80U        // Lock bit for AUXPLLCTL1
                                               // register
#define SYSCTL_CLKCFGLOCK1_AUXPLLMULT  0x400U       // Lock bit for AUXPLLMULT
                                               // register
#define SYSCTL_CLKCFGLOCK1_SYSCLKDIVSEL  0x800U       // Lock bit for SYSCLKDIVSEL
                                               // register
#define SYSCTL_CLKCFGLOCK1_AUXCLKDIVSEL  0x1000U      // Lock bit for AUXCLKDIVSEL
                                               // register
#define SYSCTL_CLKCFGLOCK1_PERCLKDIVSEL  0x2000U      // Lock bit for PERCLKDIVSEL
                                               // register
#define SYSCTL_CLKCFGLOCK1_CLBCLKCTL  0x4000U      // Lock bit for CLBCLKCTL
                                               // register
#define SYSCTL_CLKCFGLOCK1_LOSPCP  0x8000U      // Lock bit for LOSPCP register
#define SYSCTL_CLKCFGLOCK1_XTALCR  0x10000U     // Lock bit for XTALCR register
#define SYSCTL_CLKCFGLOCK1_ETHERCATCLKCTL  0x20000U     // Lock bit for ETHERCATCLKCTL
                                               // register
#define SYSCTL_CLKCFGLOCK1_CMCLKCTL  0x40000U     // Lock bit for CMCLKCTL
                                               // register

//*****************************************************************************
//
// The following are defines for the bit fields in the CLKSRCCTL1 register
//
//*****************************************************************************
#define SYSCTL_CLKSRCCTL1_OSCCLKSRCSEL_S  0U
#define SYSCTL_CLKSRCCTL1_OSCCLKSRCSEL_M  0x3U         // OSCCLK Source Select Bit
#define SYSCTL_CLKSRCCTL1_INTOSC2OFF  0x8U         // Internal Oscillator 2 Off Bit
#define SYSCTL_CLKSRCCTL1_XTALOFF  0x10U        // Crystal (External) Oscillator
                                               // Off Bit
#define SYSCTL_CLKSRCCTL1_WDHALTI  0x20U        // Watchdog HALT Mode Ignore Bit

//*****************************************************************************
//
// The following are defines for the bit fields in the CLKSRCCTL2 register
//
//*****************************************************************************
#define SYSCTL_CLKSRCCTL2_AUXOSCCLKSRCSEL_S  0U
#define SYSCTL_CLKSRCCTL2_AUXOSCCLKSRCSEL_M  0x3U         // AUXOSCCLK Source Select Bit
#define SYSCTL_CLKSRCCTL2_CANABCLKSEL_S  2U
#define SYSCTL_CLKSRCCTL2_CANABCLKSEL_M  0xCU         // CANA Clock Source Select Bit
#define SYSCTL_CLKSRCCTL2_CANBBCLKSEL_S  4U
#define SYSCTL_CLKSRCCTL2_CANBBCLKSEL_M  0x30U        // CANB Clock Source Select Bit
#define SYSCTL_CLKSRCCTL2_MCANABITCLKSEL_S  10U
#define SYSCTL_CLKSRCCTL2_MCANABITCLKSEL_M  0xC00U       // MCAN (global) Bit-Clock
                                               // Source Select Bit

//*****************************************************************************
//
// The following are defines for the bit fields in the CLKSRCCTL3 register
//
//*****************************************************************************
#define SYSCTL_CLKSRCCTL3_XCLKOUTSEL_S  0U
#define SYSCTL_CLKSRCCTL3_XCLKOUTSEL_M  0xFU         // XCLKOUT Source Select Bit

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSPLLCTL1 register
//
//*****************************************************************************
#define SYSCTL_SYSPLLCTL1_PLLEN   0x1U         // SYSPLL enable/disable bit
#define SYSCTL_SYSPLLCTL1_PLLCLKEN  0x2U         // SYSPLL bypassed or included
                                               // in the PLLSYSCLK path
#define SYSCTL_SYSPLLCTL1_VCO_PWDN  0x4U         // Initiate the APLL power down
                                               // sequence enable.

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSPLLCTL2 register
//
//*****************************************************************************
#define SYSCTL_SYSPLLCTL2_SSEN    0x1U         // SYSPLL Spread Spectrum
                                               // Modulation enable/disable Bit
#define SYSCTL_SYSPLLCTL2_SPREADINGRATE_S  1U
#define SYSCTL_SYSPLLCTL2_SPREADINGRATE_M  0x1FFEU      // SYSPLL Spread Spectrum
                                               // Modulation frequency Configuration

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSPLLCTL3 register
//
//*****************************************************************************
#define SYSCTL_SYSPLLCTL3_SPR_FAMOUNT_S  0U
#define SYSCTL_SYSPLLCTL3_SPR_FAMOUNT_M  0x7FFFU      // SYSPLL Modulation Depth
                                               // (fractional value)
#define SYSCTL_SYSPLLCTL3_SPR_IAMOUNT_S  15U
#define SYSCTL_SYSPLLCTL3_SPR_IAMOUNT_M  0x3FF8000U   // SYSPLL Modulation Depth
                                               // (Integer value)

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSPLLMULT register
//
//*****************************************************************************
#define SYSCTL_SYSPLLMULT_IMULT_S  0U
#define SYSCTL_SYSPLLMULT_IMULT_M  0x7FU        // SYSPLL Integer Multiplier
#define SYSCTL_SYSPLLMULT_FMULT_S  8U
#define SYSCTL_SYSPLLMULT_FMULT_M  0x300U       // SYSPLL Fractional Multiplier
#define SYSCTL_SYSPLLMULT_ODIV_S  16U
#define SYSCTL_SYSPLLMULT_ODIV_M  0x70000U     // Output Clock Divider
#define SYSCTL_SYSPLLMULT_REFDIV_S  26U
#define SYSCTL_SYSPLLMULT_REFDIV_M  0x3C000000U  // Reference Clock Divider

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSPLLSTS register
//
//*****************************************************************************
#define SYSCTL_SYSPLLSTS_LOCKS    0x1U         // SYSPLL Lock Status Bit
#define SYSCTL_SYSPLLSTS_SLIPS    0x2U         // SYSPLL Slip Status Bit

//*****************************************************************************
//
// The following are defines for the bit fields in the AUXPLLCTL1 register
//
//*****************************************************************************
#define SYSCTL_AUXPLLCTL1_PLLEN   0x1U         // AUXPLL enable/disable bit
#define SYSCTL_AUXPLLCTL1_PLLCLKEN  0x2U         // AUXPLL bypassed or included
                                               // in the AUXPLLCLK path
#define SYSCTL_AUXPLLCTL1_VCO_PWDN  0x4U         // Initiate the APLL power down
                                               // sequence enable.

//*****************************************************************************
//
// The following are defines for the bit fields in the AUXPLLMULT register
//
//*****************************************************************************
#define SYSCTL_AUXPLLMULT_IMULT_S  0U
#define SYSCTL_AUXPLLMULT_IMULT_M  0x7FU        // AUXPLL Integer Multiplier
#define SYSCTL_AUXPLLMULT_FMULT_S  8U
#define SYSCTL_AUXPLLMULT_FMULT_M  0x300U       // AUXPLL Fractional Multiplier
#define SYSCTL_AUXPLLMULT_ODIV_S  16U
#define SYSCTL_AUXPLLMULT_ODIV_M  0x70000U     // AUXPLL Output Clock Divider
#define SYSCTL_AUXPLLMULT_REFDIV_S  26U
#define SYSCTL_AUXPLLMULT_REFDIV_M  0x3C000000U  // AUXPLL Reference Clock
                                               // Divider

//*****************************************************************************
//
// The following are defines for the bit fields in the AUXPLLSTS register
//
//*****************************************************************************
#define SYSCTL_AUXPLLSTS_LOCKS    0x1U         // AUXPLL Lock Status Bit
#define SYSCTL_AUXPLLSTS_SLIPS    0x2U         // AUXPLL Slip Status Bit

//*****************************************************************************
//
// The following are defines for the bit fields in the SYSCLKDIVSEL register
//
//*****************************************************************************
#define SYSCTL_SYSCLKDIVSEL_PLLSYSCLKDIV_S  0U
#define SYSCTL_SYSCLKDIVSEL_PLLSYSCLKDIV_M  0x3FU        // PLLSYSCLK Divide Select

//*****************************************************************************
//
// The following are defines for the bit fields in the AUXCLKDIVSEL register
//
//*****************************************************************************
#define SYSCTL_AUXCLKDIVSEL_AUXPLLDIV_S  0U
#define SYSCTL_AUXCLKDIVSEL_AUXPLLDIV_M  0x7U         // AUXPLLCLK Divide Select
#define SYSCTL_AUXCLKDIVSEL_MCANCLKDIV_S  8U
#define SYSCTL_AUXCLKDIVSEL_MCANCLKDIV_M  0x1F00U      // Divider between CANFD Source
                                               // Clock and CANFD Bit CLK

//*****************************************************************************
//
// The following are defines for the bit fields in the PERCLKDIVSEL register
//
//*****************************************************************************
#define SYSCTL_PERCLKDIVSEL_EPWMCLKDIV_S  0U
#define SYSCTL_PERCLKDIVSEL_EPWMCLKDIV_M  0x3U         // EPWM Clock Divide Select
#define SYSCTL_PERCLKDIVSEL_EMIF1CLKDIV  0x10U        // EMIF1  Clock Divide Select
#define SYSCTL_PERCLKDIVSEL_EMIF2CLKDIV  0x40U        // EMIF2 Clock Divide Select

//*****************************************************************************
//
// The following are defines for the bit fields in the XCLKOUTDIVSEL register
//
//*****************************************************************************
#define SYSCTL_XCLKOUTDIVSEL_XCLKOUTDIV_S  0U
#define SYSCTL_XCLKOUTDIVSEL_XCLKOUTDIV_M  0x3U         // XCLKOUT Divide Select

//*****************************************************************************
//
// The following are defines for the bit fields in the CLBCLKCTL register
//
//*****************************************************************************
#define SYSCTL_CLBCLKCTL_CLBCLKDIV_S  0U
#define SYSCTL_CLBCLKCTL_CLBCLKDIV_M  0x7U         // CLB clock divider
                                               // configuration.
#define SYSCTL_CLBCLKCTL_TILECLKDIV  0x10U        // CLB Tile clock divider
                                               // configuration.
#define SYSCTL_CLBCLKCTL_CLKMODECLB1  0x10000U     // Clock mode of CLB1
#define SYSCTL_CLBCLKCTL_CLKMODECLB2  0x20000U     // Clock mode of CLB2
#define SYSCTL_CLBCLKCTL_CLKMODECLB3  0x40000U     // Clock mode of CLB3
#define SYSCTL_CLBCLKCTL_CLKMODECLB4  0x80000U     // Clock mode of CLB4
#define SYSCTL_CLBCLKCTL_CLKMODECLB5  0x100000U    // Clock mode of CLB5
#define SYSCTL_CLBCLKCTL_CLKMODECLB6  0x200000U    // Clock mode of CLB6
#define SYSCTL_CLBCLKCTL_CLKMODECLB7  0x400000U    // Clock mode of CLB7
#define SYSCTL_CLBCLKCTL_CLKMODECLB8  0x800000U    // Clock mode of CLB8

//*****************************************************************************
//
// The following are defines for the bit fields in the LOSPCP register
//
//*****************************************************************************
#define SYSCTL_LOSPCP_LSPCLKDIV_S  0U
#define SYSCTL_LOSPCP_LSPCLKDIV_M  0x7U         // LSPCLK Divide Select

//*****************************************************************************
//
// The following are defines for the bit fields in the MCDCR register
//
//*****************************************************************************
#define SYSCTL_MCDCR_MCLKSTS      0x1U         // Missing Clock Status Bit
#define SYSCTL_MCDCR_MCLKCLR      0x2U         // Missing Clock Clear Bit
#define SYSCTL_MCDCR_MCLKOFF      0x4U         // Missing Clock Detect Off Bit
#define SYSCTL_MCDCR_OSCOFF       0x8U         // Oscillator Clock Off Bit

//*****************************************************************************
//
// The following are defines for the bit fields in the X1CNT register
//
//*****************************************************************************
#define SYSCTL_X1CNT_X1CNT_S      0U
#define SYSCTL_X1CNT_X1CNT_M      0x3FFU       // X1 Counter
#define SYSCTL_X1CNT_CLR          0x10000U     // X1 Counter Clear

//*****************************************************************************
//
// The following are defines for the bit fields in the XTALCR register
//
//*****************************************************************************
#define SYSCTL_XTALCR_OSCOFF      0x1U         // XTAL Oscillator powered-down
#define SYSCTL_XTALCR_SE          0x2U         // XTAL Oscilator in
                                               // Single-Ended mode
#define SYSCTL_XTALCR_SWH         0x4U         // XTAL Oscilator Operation
                                               // range

//*****************************************************************************
//
// The following are defines for the bit fields in the PLLTEST register
//
//*****************************************************************************
#define SYSCTL_PLLTEST_OVERRIDE   0x1U         // PLL Control Test Override
#define SYSCTL_PLLTEST_PWRDN      0x2U         // PLL Control Test Override
#define SYSCTL_PLLTEST_RESET      0x4U         // PLL Control Test Override
#define SYSCTL_PLLTEST_LOAD       0x8U         // PLL Control Test Override
#define SYSCTL_PLLTEST_CLRZ       0x10U        // PLL Control Test Override
#define SYSCTL_PLLTEST_PWRDNZ     0x20U        // PLL Control Test Override
#define SYSCTL_PLLTEST_PWRDNZ_LDO  0x40U        // PLL Control Test Override
#define SYSCTL_PLLTEST_OVERRIDE_AUXPLL  0x100U       // Auxillary PLL Control Test
                                               // Override
#define SYSCTL_PLLTEST_PWRDN_AUXPLL  0x200U       // Auxillary PLL Control Test
                                               // Override
#define SYSCTL_PLLTEST_RESET_AUXPLL  0x400U       // Auxillary PLL Control Test
                                               // Override
#define SYSCTL_PLLTEST_LOAD_AUXPLL  0x800U       // Auxillary PLL Control Test
                                               // Override
#define SYSCTL_PLLTEST_CLRZ_AUXPLL  0x1000U      // Auxillary PLL Control Test
                                               // Override
#define SYSCTL_PLLTEST_PWRDNZ_AUXPLL  0x2000U      // Auxillary PLL Control Test
                                               // Override
#define SYSCTL_PLLTEST_PWRDNZ_LDO_AUXPLL  0x4000U      // Auxillary PLL Control Test
                                               // Override
#define SYSCTL_PLLTEST_KEY_S      16U
#define SYSCTL_PLLTEST_KEY_M      0xFFFF0000U  // Write Key for this register

//*****************************************************************************
//
// The following are defines for the bit fields in the ETHERCATCLKCTL register
//
//*****************************************************************************
#define SYSCTL_ETHERCATCLKCTL_DIVSRCSEL  0x1U         // Clock source select for the
                                               // etherCAT clock divider.
#define SYSCTL_ETHERCATCLKCTL_ECATDIV_S  1U
#define SYSCTL_ETHERCATCLKCTL_ECATDIV_M  0xEU         // etherCAT clock divider
                                               // configuration.
#define SYSCTL_ETHERCATCLKCTL_PHYCLKEN  0x100U       // etherCAT PHY clock enable

//*****************************************************************************
//
// The following are defines for the bit fields in the CMCLKCTL register
//
//*****************************************************************************
#define SYSCTL_CMCLKCTL_CMDIVSRCSEL  0x1U         // Clock source select for the
                                               // CM clock divider.
#define SYSCTL_CMCLKCTL_CMCLKDIV_S  1U
#define SYSCTL_CMCLKCTL_CMCLKDIV_M  0xEU         // CM clock divider
                                               // configuration.
#define SYSCTL_CMCLKCTL_ETHDIVSRCSEL  0x10U        // Clock source select for the
                                               // etherNET clock divider.
#define SYSCTL_CMCLKCTL_ETHDIV_S  5U
#define SYSCTL_CMCLKCTL_ETHDIV_M  0xE0U        // Ethernet clock divider
                                               // configuration

//*****************************************************************************
//
// The following are defines for the bit fields in the CPUSYSLOCK1 register
//
//*****************************************************************************
#define SYSCTL_CPUSYSLOCK1_PIEVERRADDR  0x4U         // Lock bit for PIEVERRADDR
                                               // Register
#define SYSCTL_CPUSYSLOCK1_PCLKCR0  0x8U         // Lock bit for PCLKCR0 Register
#define SYSCTL_CPUSYSLOCK1_PCLKCR1  0x10U        // Lock bit for PCLKCR1 Register
#define SYSCTL_CPUSYSLOCK1_PCLKCR2  0x20U        // Lock bit for PCLKCR2 Register
#define SYSCTL_CPUSYSLOCK1_PCLKCR3  0x40U        // Lock bit for PCLKCR3 Register
#define SYSCTL_CPUSYSLOCK1_PCLKCR4  0x80U        // Lock bit for PCLKCR4 Register
#define SYSCTL_CPUSYSLOCK1_PCLKCR6  0x200U       // Lock bit for PCLKCR6 Register
#define SYSCTL_CPUSYSLOCK1_PCLKCR7  0x400U       // Lock bit for PCLKCR7 Register
#define SYSCTL_CPUSYSLOCK1_PCLKCR8  0x800U       // Lock bit for PCLKCR8 Register
#define SYSCTL_CPUSYSLOCK1_PCLKCR9  0x1000U      // Lock bit for PCLKCR9 Register
#define SYSCTL_CPUSYSLOCK1_PCLKCR10  0x2000U      // Lock bit for PCLKCR10
                                               // Register
#define SYSCTL_CPUSYSLOCK1_PCLKCR11  0x4000U      // Lock bit for PCLKCR11
                                               // Register
#define SYSCTL_CPUSYSLOCK1_PCLKCR13  0x10000U     // Lock bit for PCLKCR13
                                               // Register
#define SYSCTL_CPUSYSLOCK1_PCLKCR14  0x20000U     // Lock bit for PCLKCR14
                                               // Register
#define SYSCTL_CPUSYSLOCK1_PCLKCR16  0x80000U     // Lock bit for PCLKCR16
                                               // Register
#define SYSCTL_CPUSYSLOCK1_SECMSEL  0x100000U    // Lock bit for SECMSEL Register
#define SYSCTL_CPUSYSLOCK1_LPMCR  0x200000U    // Lock bit for LPMCR Register
#define SYSCTL_CPUSYSLOCK1_GPIOLPMSEL0  0x400000U    // Lock bit for GPIOLPMSEL0
                                               // Register
#define SYSCTL_CPUSYSLOCK1_GPIOLPMSEL1  0x800000U    // Lock bit for GPIOLPMSEL1
                                               // Register
#define SYSCTL_CPUSYSLOCK1_PCLKCR17  0x1000000U   // Lock bit for PCLKCR17
                                               // Register
#define SYSCTL_CPUSYSLOCK1_PCLKCR18  0x2000000U   // Lock bit for PCLKCR18
                                               // Register
#define SYSCTL_CPUSYSLOCK1_PCLKCR20  0x8000000U   // Lock bit for PCLKCR20
                                               // Register
#define SYSCTL_CPUSYSLOCK1_PCLKCR21  0x10000000U  // Lock bit for PCLKCR21
                                               // Register
#define SYSCTL_CPUSYSLOCK1_PCLKCR22  0x20000000U  // Lock bit for PCLKCR22
                                               // Register
#define SYSCTL_CPUSYSLOCK1_PCLKCR23  0x40000000U  // Lock bit for PCLKCR23
                                               // Register

//*****************************************************************************
//
// The following are defines for the bit fields in the CPUSYSLOCK2 register
//
//*****************************************************************************
#define SYSCTL_CPUSYSLOCK2_ETHERCATCTL  0x1U         // Lock bit for ETHERCATCTL
                                               // register

//*****************************************************************************
//
// The following are defines for the bit fields in the PIEVERRADDR register
//
//*****************************************************************************
#define SYSCTL_PIEVERRADDR_ADDR_S  0U
#define SYSCTL_PIEVERRADDR_ADDR_M  0x3FFFFFU    // PIE Vector Fetch Error
                                               // Handler Routine Address

//*****************************************************************************
//
// The following are defines for the bit fields in the ETHERCATCTL register
//
//*****************************************************************************
#define SYSCTL_ETHERCATCTL_I2CLOOPBACK  0x1U         // Loopback I2C port of etherCAT
                                               // IP to I2C_A.

//*****************************************************************************
//
// The following are defines for the bit fields in the PCLKCR0 register
//
//*****************************************************************************
#define SYSCTL_PCLKCR0_CLA1       0x1U         // CLA1 Clock Enable Bit
#define SYSCTL_PCLKCR0_DMA        0x4U         // DMA Clock Enable bit
#define SYSCTL_PCLKCR0_CPUTIMER0  0x8U         // CPUTIMER0 Clock Enable bit
#define SYSCTL_PCLKCR0_CPUTIMER1  0x10U        // CPUTIMER1 Clock Enable bit
#define SYSCTL_PCLKCR0_CPUTIMER2  0x20U        // CPUTIMER2 Clock Enable bit
#define SYSCTL_PCLKCR0_CPUBGCRC   0x2000U      // CPUBGCRC Clock Enable Bit
#define SYSCTL_PCLKCR0_CLA1BGCRC  0x4000U      // CLA1BGCRC Clock Enable Bit
#define SYSCTL_PCLKCR0_HRCAL      0x10000U     // HRCAL Clock Enable Bit
#define SYSCTL_PCLKCR0_TBCLKSYNC  0x40000U     // EPWM Time Base Clock sync
#define SYSCTL_PCLKCR0_GTBCLKSYNC  0x80000U     // EPWM Time Base Clock Global
                                               // sync
#define SYSCTL_PCLKCR0_ERAD       0x1000000U   // ERAD module clock enable

//*****************************************************************************
//
// The following are defines for the bit fields in the PCLKCR1 register
//
//*****************************************************************************
#define SYSCTL_PCLKCR1_EMIF1      0x1U         // EMIF1 Clock Enable bit
#define SYSCTL_PCLKCR1_EMIF2      0x2U         // EMIF2 Clock Enable bit

//*****************************************************************************
//
// The following are defines for the bit fields in the PCLKCR2 register
//
//*****************************************************************************
#define SYSCTL_PCLKCR2_EPWM1      0x1U         // EPWM1 Clock Enable bit
#define SYSCTL_PCLKCR2_EPWM2      0x2U         // EPWM2 Clock Enable bit
#define SYSCTL_PCLKCR2_EPWM3      0x4U         // EPWM3 Clock Enable bit
#define SYSCTL_PCLKCR2_EPWM4      0x8U         // EPWM4 Clock Enable bit
#define SYSCTL_PCLKCR2_EPWM5      0x10U        // EPWM5 Clock Enable bit
#define SYSCTL_PCLKCR2_EPWM6      0x20U        // EPWM6 Clock Enable bit
#define SYSCTL_PCLKCR2_EPWM7      0x40U        // EPWM7 Clock Enable bit
#define SYSCTL_PCLKCR2_EPWM8      0x80U        // EPWM8 Clock Enable bit
#define SYSCTL_PCLKCR2_EPWM9      0x100U       // EPWM9 Clock Enable bit
#define SYSCTL_PCLKCR2_EPWM10     0x200U       // EPWM10 Clock Enable bit
#define SYSCTL_PCLKCR2_EPWM11     0x400U       // EPWM11 Clock Enable bit
#define SYSCTL_PCLKCR2_EPWM12     0x800U       // EPWM12 Clock Enable bit
#define SYSCTL_PCLKCR2_EPWM13     0x1000U      // EPWM13 Clock Enable bit
#define SYSCTL_PCLKCR2_EPWM14     0x2000U      // EPWM14 Clock Enable bit
#define SYSCTL_PCLKCR2_EPWM15     0x4000U      // EPWM15 Clock Enable bit
#define SYSCTL_PCLKCR2_EPWM16     0x8000U      // EPWM16 Clock Enable bit

//*****************************************************************************
//
// The following are defines for the bit fields in the PCLKCR3 register
//
//*****************************************************************************
#define SYSCTL_PCLKCR3_ECAP1      0x1U         // ECAP1 Clock Enable bit
#define SYSCTL_PCLKCR3_ECAP2      0x2U         // ECAP2 Clock Enable bit
#define SYSCTL_PCLKCR3_ECAP3      0x4U         // ECAP3 Clock Enable bit
#define SYSCTL_PCLKCR3_ECAP4      0x8U         // ECAP4 Clock Enable bit
#define SYSCTL_PCLKCR3_ECAP5      0x10U        // ECAP5 Clock Enable bit
#define SYSCTL_PCLKCR3_ECAP6      0x20U        // ECAP6 Clock Enable bit
#define SYSCTL_PCLKCR3_ECAP7      0x40U        // ECAP7 Clock Enable bit

//*****************************************************************************
//
// The following are defines for the bit fields in the PCLKCR4 register
//
//*****************************************************************************
#define SYSCTL_PCLKCR4_EQEP1      0x1U         // EQEP1 Clock Enable bit
#define SYSCTL_PCLKCR4_EQEP2      0x2U         // EQEP2 Clock Enable bit
#define SYSCTL_PCLKCR4_EQEP3      0x4U         // EQEP3 Clock Enable bit

//*****************************************************************************
//
// The following are defines for the bit fields in the PCLKCR6 register
//
//*****************************************************************************
#define SYSCTL_PCLKCR6_SD1        0x1U         // SD1 Clock Enable bit
#define SYSCTL_PCLKCR6_SD2        0x2U         // SD2 Clock Enable bit

//*****************************************************************************
//
// The following are defines for the bit fields in the PCLKCR7 register
//
//*****************************************************************************
#define SYSCTL_PCLKCR7_SCI_A      0x1U         // SCI_A Clock Enable bit
#define SYSCTL_PCLKCR7_SCI_B      0x2U         // SCI_B Clock Enable bit
#define SYSCTL_PCLKCR7_SCI_C      0x4U         // SCI_C Clock Enable bit
#define SYSCTL_PCLKCR7_SCI_D      0x8U         // SCI_D Clock Enable bit

//*****************************************************************************
//
// The following are defines for the bit fields in the PCLKCR8 register
//
//*****************************************************************************
#define SYSCTL_PCLKCR8_SPI_A      0x1U         // SPI_A Clock Enable bit
#define SYSCTL_PCLKCR8_SPI_B      0x2U         // SPI_B Clock Enable bit
#define SYSCTL_PCLKCR8_SPI_C      0x4U         // SPI_C Clock Enable bit
#define SYSCTL_PCLKCR8_SPI_D      0x8U         // SPI_D Clock Enable bit

//*****************************************************************************
//
// The following are defines for the bit fields in the PCLKCR9 register
//
//*****************************************************************************
#define SYSCTL_PCLKCR9_I2C_A      0x1U         // I2C_A Clock Enable bit
#define SYSCTL_PCLKCR9_I2C_B      0x2U         // I2C_B Clock Enable bit

//*****************************************************************************
//
// The following are defines for the bit fields in the PCLKCR10 register
//
//*****************************************************************************
#define SYSCTL_PCLKCR10_CAN_A     0x1U         // CAN_A Clock Enable bit
#define SYSCTL_PCLKCR10_CAN_B     0x2U         // CAN_B Clock Enable bit
#define SYSCTL_PCLKCR10_MCAN_A    0x10U        // MCAN_A Clock Enable bit

//*****************************************************************************
//
// The following are defines for the bit fields in the PCLKCR11 register
//
//*****************************************************************************
#define SYSCTL_PCLKCR11_MCBSP_A   0x1U         // McBSP_A Clock Enable bit
#define SYSCTL_PCLKCR11_MCBSP_B   0x2U         // McBSP_B Clock Enable bit
#define SYSCTL_PCLKCR11_USB_A     0x10000U     // USB_A Clock Enable bit

//*****************************************************************************
//
// The following are defines for the bit fields in the PCLKCR13 register
//
//*****************************************************************************
#define SYSCTL_PCLKCR13_ADC_A     0x1U         // ADC_A Clock Enable bit
#define SYSCTL_PCLKCR13_ADC_B     0x2U         // ADC_B Clock Enable bit
#define SYSCTL_PCLKCR13_ADC_C     0x4U         // ADC_C Clock Enable bit
#define SYSCTL_PCLKCR13_ADC_D     0x8U         // ADC_D Clock Enable bit

//*****************************************************************************
//
// The following are defines for the bit fields in the PCLKCR14 register
//
//*****************************************************************************
#define SYSCTL_PCLKCR14_CMPSS1    0x1U         // CMPSS1 Clock Enable bit
#define SYSCTL_PCLKCR14_CMPSS2    0x2U         // CMPSS2 Clock Enable bit
#define SYSCTL_PCLKCR14_CMPSS3    0x4U         // CMPSS3 Clock Enable bit
#define SYSCTL_PCLKCR14_CMPSS4    0x8U         // CMPSS4 Clock Enable bit
#define SYSCTL_PCLKCR14_CMPSS5    0x10U        // CMPSS5 Clock Enable bit
#define SYSCTL_PCLKCR14_CMPSS6    0x20U        // CMPSS6 Clock Enable bit
#define SYSCTL_PCLKCR14_CMPSS7    0x40U        // CMPSS7 Clock Enable bit
#define SYSCTL_PCLKCR14_CMPSS8    0x80U        // CMPSS8 Clock Enable bit

//*****************************************************************************
//
// The following are defines for the bit fields in the PCLKCR16 register
//
//*****************************************************************************
#define SYSCTL_PCLKCR16_DAC_A     0x10000U     // Buffered_DAC12_1 Clock Enable
                                               // Bit
#define SYSCTL_PCLKCR16_DAC_B     0x20000U     // Buffered_DAC12_2 Clock Enable
                                               // Bit
#define SYSCTL_PCLKCR16_DAC_C     0x40000U     // Buffered_DAC12_3 Clock Enable
                                               // Bit

//*****************************************************************************
//
// The following are defines for the bit fields in the PCLKCR17 register
//
//*****************************************************************************
#define SYSCTL_PCLKCR17_CLB1      0x1U         // CLB1 Clock Enable bit
#define SYSCTL_PCLKCR17_CLB2      0x2U         // CLB2 Clock Enable bit
#define SYSCTL_PCLKCR17_CLB3      0x4U         // CLB3 Clock Enable bit
#define SYSCTL_PCLKCR17_CLB4      0x8U         // CLB4 Clock Enable bit
#define SYSCTL_PCLKCR17_CLB5      0x10U        // CLB5 Clock Enable bit
#define SYSCTL_PCLKCR17_CLB6      0x20U        // CLB6 Clock Enable bit
#define SYSCTL_PCLKCR17_CLB7      0x40U        // CLB7 Clock Enable bit
#define SYSCTL_PCLKCR17_CLB8      0x80U        // CLB8 Clock Enable bit

//*****************************************************************************
//
// The following are defines for the bit fields in the PCLKCR18 register
//
//*****************************************************************************
#define SYSCTL_PCLKCR18_FSITX_A   0x1U         // FSITX_A Clock Enable bit
#define SYSCTL_PCLKCR18_FSITX_B   0x2U         // FSITX_B Clock Enable bit
#define SYSCTL_PCLKCR18_FSIRX_A   0x10000U     // FSIRX_A Clock Enable bit
#define SYSCTL_PCLKCR18_FSIRX_B   0x20000U     // FSIRX_B Clock Enable bit
#define SYSCTL_PCLKCR18_FSIRX_C   0x40000U     // FSIRX_C Clock Enable bit
#define SYSCTL_PCLKCR18_FSIRX_D   0x80000U     // FSIRX_D Clock Enable bit
#define SYSCTL_PCLKCR18_FSIRX_E   0x100000U    // FSIRX_E Clock Enable bit
#define SYSCTL_PCLKCR18_FSIRX_F   0x200000U    // FSIRX_F Clock Enable bit
#define SYSCTL_PCLKCR18_FSIRX_G   0x400000U    // FSIRX_G Clock Enable bit
#define SYSCTL_PCLKCR18_FSIRX_H   0x800000U    // FSIRX_H Clock Enable bit

//*****************************************************************************
//
// The following are defines for the bit fields in the PCLKCR20 register
//
//*****************************************************************************
#define SYSCTL_PCLKCR20_PMBUS_A   0x1U         // PMBUS_A Clock Enable bit

//*****************************************************************************
//
// The following are defines for the bit fields in the PCLKCR21 register
//
//*****************************************************************************
#define SYSCTL_PCLKCR21_DCC0      0x1U         // DCC0 Clock Enable Bit
#define SYSCTL_PCLKCR21_DCC1      0x2U         // DCC1 Clock Enable Bit
#define SYSCTL_PCLKCR21_DCC2      0x4U         // DCC2 Clock Enable Bit

//*****************************************************************************
//
// The following are defines for the bit fields in the PCLKCR22 register
//
//*****************************************************************************
#define SYSCTL_PCLKCR22_PBISTCLK  0x1U         // PBISTCLK Clock Enable Bit

//*****************************************************************************
//
// The following are defines for the bit fields in the PCLKCR23 register
//
//*****************************************************************************
#define SYSCTL_PCLKCR23_ETHERCAT  0x1U         // ETHERCAT Clock Enable Bit

//*****************************************************************************
//
// The following are defines for the bit fields in the SIMRESET register
//
//*****************************************************************************
#define SYSCTL_SIMRESET_CPU1RSN   0x1U         // Generates a reset to CPU
#define SYSCTL_SIMRESET_XRSN      0x2U         // Generates a simulated XRSn
#define SYSCTL_SIMRESET_KEY_S     16U
#define SYSCTL_SIMRESET_KEY_M     0xFFFF0000U  // Key value

//*****************************************************************************
//
// The following are defines for the bit fields in the CCR register
//
//*****************************************************************************
#define SYSCTL_CCR_VMAPS          0x1U         // C28x cores VMAPS signal
                                               // status
#define SYSCTL_CCR_MONPRIV        0x2U         // C28x MONPRIV input signal
                                               // enable bit
#define SYSCTL_CCR_ENPROT         0x4U         // C28x ENPROT input signal
                                               // value

//*****************************************************************************
//
// The following are defines for the bit fields in the SECMSEL register
//
//*****************************************************************************
#define SYSCTL_SECMSEL_PF1SEL_S   0U
#define SYSCTL_SECMSEL_PF1SEL_M   0x3U         // Secondary Master Select for
                                               // VBUS32_1 Bridge
#define SYSCTL_SECMSEL_PF2SEL_S   2U
#define SYSCTL_SECMSEL_PF2SEL_M   0xCU         // Secondary Master Select for
                                               // VBUS32_2 Bridge

//*****************************************************************************
//
// The following are defines for the bit fields in the LPMCR register
//
//*****************************************************************************
#define SYSCTL_LPMCR_LPM_S        0U
#define SYSCTL_LPMCR_LPM_M        0x3U         // Low Power Mode setting
#define SYSCTL_LPMCR_QUALSTDBY_S  2U
#define SYSCTL_LPMCR_QUALSTDBY_M  0xFCU        // STANDBY Wakeup Pin
                                               // Qualification Setting
#define SYSCTL_LPMCR_WDINTE       0x8000U      // Enable for WDINT wakeup from
                                               // STANDBY

//*****************************************************************************
//
// The following are defines for the bit fields in the GPIOLPMSEL0 register
//
//*****************************************************************************
#define SYSCTL_GPIOLPMSEL0_GPIO0  0x1U         // GPIO0 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO1  0x2U         // GPIO1 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO2  0x4U         // GPIO2 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO3  0x8U         // GPIO3 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO4  0x10U        // GPIO4 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO5  0x20U        // GPIO5 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO6  0x40U        // GPIO6 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO7  0x80U        // GPIO7 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO8  0x100U       // GPIO8 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO9  0x200U       // GPIO9 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO10  0x400U       // GPIO10 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO11  0x800U       // GPIO11 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO12  0x1000U      // GPIO12 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO13  0x2000U      // GPIO13 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO14  0x4000U      // GPIO14 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO15  0x8000U      // GPIO15 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO16  0x10000U     // GPIO16 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO17  0x20000U     // GPIO17 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO18  0x40000U     // GPIO18 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO19  0x80000U     // GPIO19 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO20  0x100000U    // GPIO20 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO21  0x200000U    // GPIO21 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO22  0x400000U    // GPIO22 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO23  0x800000U    // GPIO23 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO24  0x1000000U   // GPIO24 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO25  0x2000000U   // GPIO25 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO26  0x4000000U   // GPIO26 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO27  0x8000000U   // GPIO27 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO28  0x10000000U  // GPIO28 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO29  0x20000000U  // GPIO29 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO30  0x40000000U  // GPIO30 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO31  0x80000000U  // GPIO31 Enable for LPM Wakeup

//*****************************************************************************
//
// The following are defines for the bit fields in the GPIOLPMSEL1 register
//
//*****************************************************************************
#define SYSCTL_GPIOLPMSEL1_GPIO32  0x1U         // GPIO32 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO33  0x2U         // GPIO33 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO34  0x4U         // GPIO34 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO35  0x8U         // GPIO35 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO36  0x10U        // GPIO36 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO37  0x20U        // GPIO37 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO38  0x40U        // GPIO38 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO39  0x80U        // GPIO39 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO40  0x100U       // GPIO40 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO41  0x200U       // GPIO41 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO42  0x400U       // GPIO42 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO43  0x800U       // GPIO43 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO44  0x1000U      // GPIO44 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO45  0x2000U      // GPIO45 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO46  0x4000U      // GPIO46 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO47  0x8000U      // GPIO47 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO48  0x10000U     // GPIO48 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO49  0x20000U     // GPIO49 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO50  0x40000U     // GPIO50 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO51  0x80000U     // GPIO51 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO52  0x100000U    // GPIO52 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO53  0x200000U    // GPIO53 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO54  0x400000U    // GPIO54 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO55  0x800000U    // GPIO55 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO56  0x1000000U   // GPIO56 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO57  0x2000000U   // GPIO57 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO58  0x4000000U   // GPIO58 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO59  0x8000000U   // GPIO59 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO60  0x10000000U  // GPIO60 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO61  0x20000000U  // GPIO61 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO62  0x40000000U  // GPIO62 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO63  0x80000000U  // GPIO63 Enable for LPM Wakeup

//*****************************************************************************
//
// The following are defines for the bit fields in the TMR2CLKCTL register
//
//*****************************************************************************
#define SYSCTL_TMR2CLKCTL_TMR2CLKSRCSEL_S  0U
#define SYSCTL_TMR2CLKCTL_TMR2CLKSRCSEL_M  0x7U         // CPU Timer 2 Clock Source
                                               // Select Bit
#define SYSCTL_TMR2CLKCTL_TMR2CLKPRESCALE_S  3U
#define SYSCTL_TMR2CLKCTL_TMR2CLKPRESCALE_M  0x38U        // CPU Timer 2 Clock Pre-Scale
                                               // Value

//*****************************************************************************
//
// The following are defines for the bit fields in the RESCCLR register
//
//*****************************************************************************
#define SYSCTL_RESCCLR_POR        0x1U         // POR Reset Cause Indication
                                               // Bit
#define SYSCTL_RESCCLR_XRSN       0x2U         // XRSn Reset Cause Indication
                                               // Bit
#define SYSCTL_RESCCLR_WDRSN      0x4U         // WDRSn Reset Cause Indication
                                               // Bit
#define SYSCTL_RESCCLR_NMIWDRSN   0x8U         // NMIWDRSn Reset Cause
                                               // Indication Bit
#define SYSCTL_RESCCLR_HWBISTN    0x20U        // HWBISTn Reset Cause
                                               // Indication Bit
#define SYSCTL_RESCCLR_SCCRESETN  0x100U       // SCCRESETn Reset Cause
                                               // Indication Bit
#define SYSCTL_RESCCLR_ECAT_RESET_OUT  0x200U       // ECAT_RESET_OUT Reset Cause
                                               // Indication Bit
#define SYSCTL_RESCCLR_SIMRESET_CPU1RSN  0x400U       // SIMRESET_CPU1RSn Reset Cause
                                               // Indication Bit
#define SYSCTL_RESCCLR_SIMRESET_XRSN  0x800U       // SIMRESET_XRSn Reset Cause
                                               // Indication Bit

//*****************************************************************************
//
// The following are defines for the bit fields in the RESC register
//
//*****************************************************************************
#define SYSCTL_RESC_POR           0x1U         // POR Reset Cause Indication
                                               // Bit
#define SYSCTL_RESC_XRSN          0x2U         // XRSn Reset Cause Indication
                                               // Bit
#define SYSCTL_RESC_WDRSN         0x4U         // WDRSn Reset Cause Indication
                                               // Bit
#define SYSCTL_RESC_NMIWDRSN      0x8U         // NMIWDRSn Reset Cause
                                               // Indication Bit
#define SYSCTL_RESC_HWBISTN       0x20U        // HWBISTn Reset Cause
                                               // Indication Bit
#define SYSCTL_RESC_SCCRESETN     0x100U       // SCCRESETn Reset Cause
                                               // Indication Bit
#define SYSCTL_RESC_ECAT_RESET_OUT  0x200U       // ECAT_RESET_OUT Reset Cause
                                               // Indication Bit
#define SYSCTL_RESC_SIMRESET_CPU1RSN  0x400U       // SIMRESET_CPU1RSn Reset Cause
                                               // Indication Bit
#define SYSCTL_RESC_SIMRESET_XRSN  0x800U       // SIMRESET_XRSn Reset Cause
                                               // Indication Bit
#define SYSCTL_RESC_XRSN_PIN_STATUS  0x40000000U  // XRSN Pin Status
#define SYSCTL_RESC_TRSTN_PIN_STATUS  0x80000000U  // TRSTn Status

//*****************************************************************************
//
// The following are defines for the bit fields in the MCANWAKESTATUS register
//
//*****************************************************************************
#define SYSCTL_MCANWAKESTATUS_WAKE  0x1U         // MCAN Wake Status

//*****************************************************************************
//
// The following are defines for the bit fields in the MCANWAKESTATUSCLR register
//
//*****************************************************************************
#define SYSCTL_MCANWAKESTATUSCLR_WAKE  0x1U         // Cear bit for
                                               // MCANWAKESTATUS.WAKE bit

//*****************************************************************************
//
// The following are defines for the bit fields in the CLKSTOPREQ register
//
//*****************************************************************************
#define SYSCTL_CLKSTOPREQ_MCAN_A  0x100U       // MCAN_A Clock Stop Request Bit
#define SYSCTL_CLKSTOPREQ_KEY_S   16U
#define SYSCTL_CLKSTOPREQ_KEY_M   0xFFFF0000U  // Key field

//*****************************************************************************
//
// The following are defines for the bit fields in the CLKSTOPACK register
//
//*****************************************************************************
#define SYSCTL_CLKSTOPACK_MCAN_A  0x100U       // MCAN_A Clock Stop Ack Bit

//*****************************************************************************
//
// The following are defines for the bit fields in the CLA1TASKSRCSELLOCK register
//
//*****************************************************************************
#define SYSCTL_CLA1TASKSRCSELLOCK_CLA1TASKSRCSEL1  0x1U         // CLA1TASKSRCSEL1 Register Lock
                                               // bit
#define SYSCTL_CLA1TASKSRCSELLOCK_CLA1TASKSRCSEL2  0x2U         // CLA1TASKSRCSEL2 Register Lock
                                               // bit

//*****************************************************************************
//
// The following are defines for the bit fields in the DMACHSRCSELLOCK register
//
//*****************************************************************************
#define SYSCTL_DMACHSRCSELLOCK_DMACHSRCSEL1  0x1U         // DMACHSRCSEL1 Register Lock
                                               // bit
#define SYSCTL_DMACHSRCSELLOCK_DMACHSRCSEL2  0x2U         // DMACHSRCSEL2 Register Lock
                                               // bit

//*****************************************************************************
//
// The following are defines for the bit fields in the CLA1TASKSRCSEL1 register
//
//*****************************************************************************
#define SYSCTL_CLA1TASKSRCSEL1_TASK1_S  0U
#define SYSCTL_CLA1TASKSRCSEL1_TASK1_M  0xFFU        // Selects the Trigger Source
                                               // for TASK1 of CLA1
#define SYSCTL_CLA1TASKSRCSEL1_TASK2_S  8U
#define SYSCTL_CLA1TASKSRCSEL1_TASK2_M  0xFF00U      // Selects the Trigger Source
                                               // for TASK2 of CLA1
#define SYSCTL_CLA1TASKSRCSEL1_TASK3_S  16U
#define SYSCTL_CLA1TASKSRCSEL1_TASK3_M  0xFF0000U    // Selects the Trigger Source
                                               // for TASK3 of CLA1
#define SYSCTL_CLA1TASKSRCSEL1_TASK4_S  24U
#define SYSCTL_CLA1TASKSRCSEL1_TASK4_M  0xFF000000U  // Selects the Trigger Source
                                               // for TASK4 of CLA1

//*****************************************************************************
//
// The following are defines for the bit fields in the CLA1TASKSRCSEL2 register
//
//*****************************************************************************
#define SYSCTL_CLA1TASKSRCSEL2_TASK5_S  0U
#define SYSCTL_CLA1TASKSRCSEL2_TASK5_M  0xFFU        // Selects the Trigger Source
                                               // for TASK5 of CLA1
#define SYSCTL_CLA1TASKSRCSEL2_TASK6_S  8U
#define SYSCTL_CLA1TASKSRCSEL2_TASK6_M  0xFF00U      // Selects the Trigger Source
                                               // for TASK6 of CLA1
#define SYSCTL_CLA1TASKSRCSEL2_TASK7_S  16U
#define SYSCTL_CLA1TASKSRCSEL2_TASK7_M  0xFF0000U    // Selects the Trigger Source
                                               // for TASK7 of CLA1
#define SYSCTL_CLA1TASKSRCSEL2_TASK8_S  24U
#define SYSCTL_CLA1TASKSRCSEL2_TASK8_M  0xFF000000U  // Selects the Trigger Source
                                               // for TASK8 of CLA1

//*****************************************************************************
//
// The following are defines for the bit fields in the DMACHSRCSEL1 register
//
//*****************************************************************************
#define SYSCTL_DMACHSRCSEL1_CH1_S  0U
#define SYSCTL_DMACHSRCSEL1_CH1_M  0xFFU        // Selects the Trigger and Sync
                                               // Source CH1 of DMA
#define SYSCTL_DMACHSRCSEL1_CH2_S  8U
#define SYSCTL_DMACHSRCSEL1_CH2_M  0xFF00U      // Selects the Trigger and Sync
                                               // Source CH2 of DMA
#define SYSCTL_DMACHSRCSEL1_CH3_S  16U
#define SYSCTL_DMACHSRCSEL1_CH3_M  0xFF0000U    // Selects the Trigger and Sync
                                               // Source CH3 of DMA
#define SYSCTL_DMACHSRCSEL1_CH4_S  24U
#define SYSCTL_DMACHSRCSEL1_CH4_M  0xFF000000U  // Selects the Trigger and Sync
                                               // Source CH4 of DMA

//*****************************************************************************
//
// The following are defines for the bit fields in the DMACHSRCSEL2 register
//
//*****************************************************************************
#define SYSCTL_DMACHSRCSEL2_CH5_S  0U
#define SYSCTL_DMACHSRCSEL2_CH5_M  0xFFU        // Selects the Trigger and Sync
                                               // Source CH5 of DMA
#define SYSCTL_DMACHSRCSEL2_CH6_S  8U
#define SYSCTL_DMACHSRCSEL2_CH6_M  0xFF00U      // Selects the Trigger and Sync
                                               // Source CH6 of DMA

//*****************************************************************************
//
// The following are defines for the bit fields in the DEVCFGLOCK1 register
//
//*****************************************************************************
#define SYSCTL_DEVCFGLOCK1_CPUSEL0  0x1U         // Lock bit for CPUSEL0 register
#define SYSCTL_DEVCFGLOCK1_CPUSEL1  0x2U         // Lock bit for CPUSEL1 register
#define SYSCTL_DEVCFGLOCK1_CPUSEL2  0x4U         // Lock bit for CPUSEL2 register
#define SYSCTL_DEVCFGLOCK1_CPUSEL4  0x10U        // Lock bit for CPUSEL4 register
#define SYSCTL_DEVCFGLOCK1_CPUSEL5  0x20U        // Lock bit for CPUSEL5 register
#define SYSCTL_DEVCFGLOCK1_CPUSEL6  0x40U        // Lock bit for CPUSEL6 register
#define SYSCTL_DEVCFGLOCK1_CPUSEL7  0x80U        // Lock bit for CPUSEL7 register
#define SYSCTL_DEVCFGLOCK1_CPUSEL8  0x100U       // Lock bit for CPUSEL8 register
#define SYSCTL_DEVCFGLOCK1_CPUSEL9  0x200U       // Lock bit for CPUSEL9 register
#define SYSCTL_DEVCFGLOCK1_CPUSEL11  0x800U       // Lock bit for CPUSEL11
                                               // register
#define SYSCTL_DEVCFGLOCK1_CPUSEL12  0x1000U      // Lock bit for CPUSEL12
                                               // register
#define SYSCTL_DEVCFGLOCK1_CPUSEL14  0x4000U      // Lock bit for CPUSEL14
                                               // register
#define SYSCTL_DEVCFGLOCK1_CPUSEL15  0x8000U      // Lock bit for CPUSEL15
                                               // register
#define SYSCTL_DEVCFGLOCK1_CPUSEL16  0x10000U     // Lock bit for CPUSEL16
                                               // register
#define SYSCTL_DEVCFGLOCK1_CPUSEL18  0x40000U     // Lock bit for CPUSEL18
                                               // register
#define SYSCTL_DEVCFGLOCK1_CPUSEL25  0x2000000U   // Lock bit for CPUSEL25
                                               // register

//*****************************************************************************
//
// The following are defines for the bit fields in the DEVCFGLOCK2 register
//
//*****************************************************************************
#define SYSCTL_DEVCFGLOCK2_DC_PERCNF_PARTID  0x1U         // Lock bit for DCx, PARTID and
                                               // PERCNFx registers
#define SYSCTL_DEVCFGLOCK2_BANKSEL  0x2U         // Lock bit for BANKSEL register

//*****************************************************************************
//
// The following are defines for the bit fields in the PARTIDL register
//
//*****************************************************************************
#define SYSCTL_PARTIDL_TEMPERATURE_S  0U
#define SYSCTL_PARTIDL_TEMPERATURE_M  0x7U         // Temperature Rating
#define SYSCTL_PARTIDL_PACKAGE_S  3U
#define SYSCTL_PARTIDL_PACKAGE_M  0x18U        // Device Package
#define SYSCTL_PARTIDL_QUAL_S     6U
#define SYSCTL_PARTIDL_QUAL_M     0xC0U        // Qualification Status
#define SYSCTL_PARTIDL_PIN_COUNT_S  8U
#define SYSCTL_PARTIDL_PIN_COUNT_M  0x700U       // Device Pin Count
#define SYSCTL_PARTIDL_INSTASPIN_S  13U
#define SYSCTL_PARTIDL_INSTASPIN_M  0x6000U      // Motorware feature set
#define SYSCTL_PARTIDL_FLASH_SIZE_S  16U
#define SYSCTL_PARTIDL_FLASH_SIZE_M  0xFF0000U    // Flash size in KB
#define SYSCTL_PARTIDL_PARTID_FORMAT_REVISION_S  28U
#define SYSCTL_PARTIDL_PARTID_FORMAT_REVISION_M  0xF0000000U  // Revision of the PARTID format

//*****************************************************************************
//
// The following are defines for the bit fields in the PARTIDH register
//
//*****************************************************************************
#define SYSCTL_PARTIDH_FAMILY_S   8U
#define SYSCTL_PARTIDH_FAMILY_M   0xFF00U      // Device family
#define SYSCTL_PARTIDH_PARTNO_S   16U
#define SYSCTL_PARTIDH_PARTNO_M   0xFF0000U    // Device part number
#define SYSCTL_PARTIDH_DEVICE_CLASS_ID_S  24U
#define SYSCTL_PARTIDH_DEVICE_CLASS_ID_M  0xFF000000U  // Device class ID

//*****************************************************************************
//
// The following are defines for the bit fields in the REVID register
//
//*****************************************************************************
#define SYSCTL_REVID_REVID_S      0U
#define SYSCTL_REVID_REVID_M      0xFFFFU      // Device Revision ID. This is
                                               // specific to the Device

//*****************************************************************************
//
// The following are defines for the bit fields in the DC0 register
//
//*****************************************************************************
#define SYSCTL_DC0_SINGLE_CORE    0x1U         // Single Core vs Dual Core
#define SYSCTL_DC0_CM             0x2U         // CM capability enable.

//*****************************************************************************
//
// The following are defines for the bit fields in the DC1 register
//
//*****************************************************************************
#define SYSCTL_DC1_CPU1_FPU_TMU   0x1U         // CPU1+FPU1+TMU1 enable-disable
                                               // bit
#define SYSCTL_DC1_CPU2_FPU_TMU   0x2U         // CPU2+FPU2+TMU2 enable-disable
                                               // bit
#define SYSCTL_DC1_CPU1_CLA1      0x40U        // CPU1.CLA1 enable/disable bit
#define SYSCTL_DC1_CPU2_CLA1      0x100U       // CPU2.CLA1 enable/disable bit

//*****************************************************************************
//
// The following are defines for the bit fields in the DC2 register
//
//*****************************************************************************
#define SYSCTL_DC2_EMIF1          0x1U         // EMIF1 enable/disable bit
#define SYSCTL_DC2_EMIF2          0x2U         // EMIF2 enable/disable bit

//*****************************************************************************
//
// The following are defines for the bit fields in the DC3 register
//
//*****************************************************************************
#define SYSCTL_DC3_EPWM1          0x1U         // EPWM1 enable/disable bit
#define SYSCTL_DC3_EPWM2          0x2U         // EPWM2 enable/disable bit
#define SYSCTL_DC3_EPWM3          0x4U         // EPWM3 enable/disable bit
#define SYSCTL_DC3_EPWM4          0x8U         // EPWM4 enable/disable bit
#define SYSCTL_DC3_EPWM5          0x10U        // EPWM5 enable/disable bit
#define SYSCTL_DC3_EPWM6          0x20U        // EPWM6 enable/disable bit
#define SYSCTL_DC3_EPWM7          0x40U        // EPWM7 enable/disable bit
#define SYSCTL_DC3_EPWM8          0x80U        // EPWM8 enable/disable bit
#define SYSCTL_DC3_EPWM9          0x100U       // EPWM9 enable/disable bit
#define SYSCTL_DC3_EPWM10         0x200U       // EPWM10 enable/disable bit
#define SYSCTL_DC3_EPWM11         0x400U       // EPWM11 enable/disable bit
#define SYSCTL_DC3_EPWM12         0x800U       // EPWM12 enable/disable bit
#define SYSCTL_DC3_EPWM13         0x1000U      // EPWM13 enable/disable bit
#define SYSCTL_DC3_EPWM14         0x2000U      // EPWM14 enable/disable bit
#define SYSCTL_DC3_EPWM15         0x4000U      // EPWM15 enable/disable bit
#define SYSCTL_DC3_EPWM16         0x8000U      // EPWM16 enable/disable bit

//*****************************************************************************
//
// The following are defines for the bit fields in the DC4 register
//
//*****************************************************************************
#define SYSCTL_DC4_ECAP1          0x1U         // ECAP1 enable/disable bit
#define SYSCTL_DC4_ECAP2          0x2U         // ECAP2 enable/disable bit
#define SYSCTL_DC4_ECAP3          0x4U         // ECAP3 enable/disable bit
#define SYSCTL_DC4_ECAP4          0x8U         // ECAP4 enable/disable bit
#define SYSCTL_DC4_ECAP5          0x10U        // ECAP5 enable/disable bit
#define SYSCTL_DC4_ECAP6          0x20U        // ECAP6 enable/disable bit
#define SYSCTL_DC4_ECAP7          0x40U        // ECAP7 enable/disable bit

//*****************************************************************************
//
// The following are defines for the bit fields in the DC5 register
//
//*****************************************************************************
#define SYSCTL_DC5_EQEP1          0x1U         // EQEP1 enable/disable bit
#define SYSCTL_DC5_EQEP2          0x2U         // EQEP2 enable/disable bit
#define SYSCTL_DC5_EQEP3          0x4U         // EQEP3 enable/disable bit

//*****************************************************************************
//
// The following are defines for the bit fields in the DC7 register
//
//*****************************************************************************
#define SYSCTL_DC7_SD1            0x1U         // SD1 enable/disable bit
#define SYSCTL_DC7_SD2            0x2U         // SD2 enable/disable bit

//*****************************************************************************
//
// The following are defines for the bit fields in the DC8 register
//
//*****************************************************************************
#define SYSCTL_DC8_SCI_A          0x1U         // SCI_A enable/disable bit
#define SYSCTL_DC8_SCI_B          0x2U         // SCI_B enable/disable bit
#define SYSCTL_DC8_SCI_C          0x4U         // SCI_C enable/disable bit
#define SYSCTL_DC8_SCI_D          0x8U         // SCI_D enable/disable bit

//*****************************************************************************
//
// The following are defines for the bit fields in the DC9 register
//
//*****************************************************************************
#define SYSCTL_DC9_SPI_A          0x1U         // SPI_A enable/disable bit
#define SYSCTL_DC9_SPI_B          0x2U         // SPI_B enable/disable bit
#define SYSCTL_DC9_SPI_C          0x4U         // SPI_C enable/disable bit
#define SYSCTL_DC9_SPI_D          0x8U         // SPI_D enable/disable bit

//*****************************************************************************
//
// The following are defines for the bit fields in the DC10 register
//
//*****************************************************************************
#define SYSCTL_DC10_I2C_A         0x1U         // I2C_A enable/disable bit
#define SYSCTL_DC10_I2C_B         0x2U         // I2C_B enable/disable bit

//*****************************************************************************
//
// The following are defines for the bit fields in the DC11 register
//
//*****************************************************************************
#define SYSCTL_DC11_CAN_A         0x1U         // CAN_A enable/disable bit
#define SYSCTL_DC11_CAN_B         0x2U         // CAN_B enable/disable bit
#define SYSCTL_DC11_MCAN_A        0x10U        // MCAN_A enable/disable bit
#define SYSCTL_DC11_CANFD_A       0x100U       // CANFD_A enable/disable bit

//*****************************************************************************
//
// The following are defines for the bit fields in the DC12 register
//
//*****************************************************************************
#define SYSCTL_DC12_MCBSP_A       0x1U         // McBSP_A enable/disable bit
#define SYSCTL_DC12_MCBSP_B       0x2U         // McBSP_B enable/disable bit
#define SYSCTL_DC12_USB_A_S       16U
#define SYSCTL_DC12_USB_A_M       0x30000U     // Decides the capability of the
                                               // USB_A Module

//*****************************************************************************
//
// The following are defines for the bit fields in the DC14 register
//
//*****************************************************************************
#define SYSCTL_DC14_ADC_A         0x1U         // ADC_A enable/disable bit
#define SYSCTL_DC14_ADC_B         0x2U         // ADC_B enable/disable bit
#define SYSCTL_DC14_ADC_C         0x4U         // ADC_C enable/disable bit
#define SYSCTL_DC14_ADC_D         0x8U         // ADC_D enable/disable bit

//*****************************************************************************
//
// The following are defines for the bit fields in the DC15 register
//
//*****************************************************************************
#define SYSCTL_DC15_CMPSS1        0x1U         // CMPSS1 enable/disable bit
#define SYSCTL_DC15_CMPSS2        0x2U         // CMPSS2 enable/disable bit
#define SYSCTL_DC15_CMPSS3        0x4U         // CMPSS3 enable/disable bit
#define SYSCTL_DC15_CMPSS4        0x8U         // CMPSS4 enable/disable bit
#define SYSCTL_DC15_CMPSS5        0x10U        // CMPSS5 enable/disable bit
#define SYSCTL_DC15_CMPSS6        0x20U        // CMPSS6 enable/disable bit
#define SYSCTL_DC15_CMPSS7        0x40U        // CMPSS7 enable/disable bit
#define SYSCTL_DC15_CMPSS8        0x80U        // CMPSS8 enable/disable bit

//*****************************************************************************
//
// The following are defines for the bit fields in the DC17 register
//
//*****************************************************************************
#define SYSCTL_DC17_DAC_A         0x10000U     // Buffered-DAC12-1
                                               // enable/disable bit
#define SYSCTL_DC17_DAC_B         0x20000U     // Buffered-DAC12-2
                                               // enable/disable bit
#define SYSCTL_DC17_DAC_C         0x40000U     // Buffered-DAC12-3
                                               // enable/disable bit

//*****************************************************************************
//
// The following are defines for the bit fields in the DC18 register
//
//*****************************************************************************
#define SYSCTL_DC18_LS0_1         0x1U         // LS0_1 enable/disable
                                               // bit[[br]](Associated with CPU1)
#define SYSCTL_DC18_LS1_1         0x2U         // LS1_1 enable/disable
                                               // bit[[br]](Associated with CPU1)
#define SYSCTL_DC18_LS2_1         0x4U         // LS2_1 enable/disable
                                               // bit[[br]](Associated with CPU1)
#define SYSCTL_DC18_LS3_1         0x8U         // LS3_1 enable/disable
                                               // bit[[br]](Associated with CPU1)
#define SYSCTL_DC18_LS4_1         0x10U        // LS4_1 enable/disable
                                               // bit[[br]](Associated with CPU1)
#define SYSCTL_DC18_LS5_1         0x20U        // LS5_1 enable/disable
                                               // bit[[br]](Associated with CPU1)
#define SYSCTL_DC18_LS6_1         0x40U        // LS6_1 enable/disable
                                               // bit[[br]](Associated with CPU1)
#define SYSCTL_DC18_LS7_1         0x80U        // LS7_1 enable/disable
                                               // bit[[br]](Associated with CPU1)

//*****************************************************************************
//
// The following are defines for the bit fields in the DC19 register
//
//*****************************************************************************
#define SYSCTL_DC19_LS0_2         0x1U         // LS0_2 enable/disable
                                               // bit[[br]](Associated with CPU2)
#define SYSCTL_DC19_LS1_2         0x2U         // LS1_2 enable/disable
                                               // bit[[br]](Associated with CPU2)
#define SYSCTL_DC19_LS2_2         0x4U         // LS2_2 enable/disable
                                               // bit[[br]](Associated with CPU2)
#define SYSCTL_DC19_LS3_2         0x8U         // LS3_2 enable/disable
                                               // bit[[br]](Associated with CPU2)
#define SYSCTL_DC19_LS4_2         0x10U        // LS4_2 enable/disable
                                               // bit[[br]](Associated with CPU2)
#define SYSCTL_DC19_LS5_2         0x20U        // LS5_2 enable/disable
                                               // bit[[br]](Associated with CPU2)
#define SYSCTL_DC19_LS6_2         0x40U        // LS6_2 enable/disable
                                               // bit[[br]](Associated with CPU2)
#define SYSCTL_DC19_LS7_2         0x80U        // LS7_2 enable/disable
                                               // bit[[br]](Associated with CPU2)

//*****************************************************************************
//
// The following are defines for the bit fields in the DC20 register
//
//*****************************************************************************
#define SYSCTL_DC20_GS0           0x1U         // GS0 enable/disable bit
#define SYSCTL_DC20_GS1           0x2U         // GS1 enable/disable bit
#define SYSCTL_DC20_GS2           0x4U         // GS2 enable/disable bit
#define SYSCTL_DC20_GS3           0x8U         // GS3 enable/disable bit
#define SYSCTL_DC20_GS4           0x10U        // GS4 enable/disable bit
#define SYSCTL_DC20_GS5           0x20U        // GS5 enable/disable bit
#define SYSCTL_DC20_GS6           0x40U        // GS6 enable/disable bit
#define SYSCTL_DC20_GS7           0x80U        // GS7 enable/disable bit
#define SYSCTL_DC20_GS8           0x100U       // GS8 enable/disable bit
#define SYSCTL_DC20_GS9           0x200U       // GS9 enable/disable bit
#define SYSCTL_DC20_GS10          0x400U       // GS10 enable/disable bit
#define SYSCTL_DC20_GS11          0x800U       // GS11 enable/disable bit
#define SYSCTL_DC20_GS12          0x1000U      // GS12 enable/disable bit
#define SYSCTL_DC20_GS13          0x2000U      // GS13 enable/disable bit
#define SYSCTL_DC20_GS14          0x4000U      // GS14 enable/disable bit
#define SYSCTL_DC20_GS15          0x8000U      // GS15 enable/disable bit

//*****************************************************************************
//
// The following are defines for the bit fields in the DC21 register
//
//*****************************************************************************
#define SYSCTL_DC21_CLB1          0x1U         // CLB1
#define SYSCTL_DC21_CLB2          0x2U         // CLB2
#define SYSCTL_DC21_CLB3          0x4U         // CLB3
#define SYSCTL_DC21_CLB4          0x8U         // CLB4
#define SYSCTL_DC21_CLB5          0x10U        // CLB5
#define SYSCTL_DC21_CLB6          0x20U        // CLB6
#define SYSCTL_DC21_CLB7          0x40U        // CLB5
#define SYSCTL_DC21_CLB8          0x80U        // CLB8

//*****************************************************************************
//
// The following are defines for the bit fields in the DC22 register
//
//*****************************************************************************
#define SYSCTL_DC22_FSITX_A       0x1U         // FSITX_A
#define SYSCTL_DC22_FSITX_B       0x2U         // FSITX_B
#define SYSCTL_DC22_FSIRX_A       0x10000U     // FSIRX_A
#define SYSCTL_DC22_FSIRX_B       0x20000U     // FSIRX_B
#define SYSCTL_DC22_FSIRX_C       0x40000U     // FSIRX_C
#define SYSCTL_DC22_FSIRX_D       0x80000U     // FSIRX_D
#define SYSCTL_DC22_FSIRX_E       0x100000U    // FSIRX_E
#define SYSCTL_DC22_FSIRX_F       0x200000U    // FSIRX_F
#define SYSCTL_DC22_FSIRX_G       0x400000U    // FSIRX_G
#define SYSCTL_DC22_FSIRX_H       0x800000U    // FSIRX_H

//*****************************************************************************
//
// The following are defines for the bit fields in the DC24 register
//
//*****************************************************************************
#define SYSCTL_DC24_PMBUS_A       0x1U         // PMBUS_A

//*****************************************************************************
//
// The following are defines for the bit fields in the DC25 register
//
//*****************************************************************************
#define SYSCTL_DC25_DCC0          0x1U         // DCC0
#define SYSCTL_DC25_DCC1          0x2U         // DCC1
#define SYSCTL_DC25_DCC2          0x4U         // DCC2

//*****************************************************************************
//
// The following are defines for the bit fields in the DC26 register
//
//*****************************************************************************
#define SYSCTL_DC26_ETHERCAT      0x1U         // ETHERCAT
#define SYSCTL_DC26_ETHERNET      0x2U         // ETHERNET

//*****************************************************************************
//
// The following are defines for the bit fields in the DC27 register
//
//*****************************************************************************
#define SYSCTL_DC27_CPU1BGCRC     0x1U         // CPU1BGCRC
#define SYSCTL_DC27_CPU1CLA1BGCRC  0x2U         // CPU1CLA1BGCRC
#define SYSCTL_DC27_CPU2BGCRC     0x8U         // CPU2BGCRC
#define SYSCTL_DC27_CPU2CLA1BGCRC  0x10U        // CPU2CLA1BGCRC

//*****************************************************************************
//
// The following are defines for the bit fields in the PERCNF1 register
//
//*****************************************************************************
#define SYSCTL_PERCNF1_ADC_A_MODE  0x1U         // ADC Wrapper-1 mode setting
                                               // bit
#define SYSCTL_PERCNF1_ADC_B_MODE  0x2U         // ADC Wrapper-2 mode setting
                                               // bit
#define SYSCTL_PERCNF1_ADC_C_MODE  0x4U         // ADC Wrapper-3 mode setting
                                               // bit
#define SYSCTL_PERCNF1_ADC_D_MODE  0x8U         // ADC Wrapper-4 mode setting
                                               // bit
#define SYSCTL_PERCNF1_USB_A_PHY  0x10000U     // USB_A_PHY enable/disable bit

//*****************************************************************************
//
// The following are defines for the bit fields in the FUSEERR register
//
//*****************************************************************************
#define SYSCTL_FUSEERR_ALERR_S    0U
#define SYSCTL_FUSEERR_ALERR_M    0x1FU        // Efuse Autoload Error Status
#define SYSCTL_FUSEERR_ERR        0x20U        // Efuse Self Test Error Status

//*****************************************************************************
//
// The following are defines for the bit fields in the SOFTPRES0 register
//
//*****************************************************************************
#define SYSCTL_SOFTPRES0_CPU1_CLA1  0x1U         // CPU1_CLA1 software reset bit
#define SYSCTL_SOFTPRES0_CPU2_CLA1  0x4U         // CPU2_CLA1 software reset bit
#define SYSCTL_SOFTPRES0_CPUBGCRC  0x2000U      // CPUBGCRC Module reset bit
#define SYSCTL_SOFTPRES0_CLA1BGCRC  0x4000U      // CLA1BGCRC Module reset bit
#define SYSCTL_SOFTPRES0_ERAD     0x1000000U   // ERAD Module reset bit

//*****************************************************************************
//
// The following are defines for the bit fields in the SOFTPRES1 register
//
//*****************************************************************************
#define SYSCTL_SOFTPRES1_EMIF1    0x1U         // EMIF1 software reset bit
#define SYSCTL_SOFTPRES1_EMIF2    0x2U         // EMIF2 software reset bit

//*****************************************************************************
//
// The following are defines for the bit fields in the SOFTPRES2 register
//
//*****************************************************************************
#define SYSCTL_SOFTPRES2_EPWM1    0x1U         // EPWM1 software reset bit
#define SYSCTL_SOFTPRES2_EPWM2    0x2U         // EPWM2 software reset bit
#define SYSCTL_SOFTPRES2_EPWM3    0x4U         // EPWM3 software reset bit
#define SYSCTL_SOFTPRES2_EPWM4    0x8U         // EPWM4 software reset bit
#define SYSCTL_SOFTPRES2_EPWM5    0x10U        // EPWM5 software reset bit
#define SYSCTL_SOFTPRES2_EPWM6    0x20U        // EPWM6 software reset bit
#define SYSCTL_SOFTPRES2_EPWM7    0x40U        // EPWM7 software reset bit
#define SYSCTL_SOFTPRES2_EPWM8    0x80U        // EPWM8 software reset bit
#define SYSCTL_SOFTPRES2_EPWM9    0x100U       // EPWM9 software reset bit
#define SYSCTL_SOFTPRES2_EPWM10   0x200U       // EPWM10 software reset bit
#define SYSCTL_SOFTPRES2_EPWM11   0x400U       // EPWM11 software reset bit
#define SYSCTL_SOFTPRES2_EPWM12   0x800U       // EPWM12 software reset bit
#define SYSCTL_SOFTPRES2_EPWM13   0x1000U      // EPWM13 software reset bit
#define SYSCTL_SOFTPRES2_EPWM14   0x2000U      // EPWM14 software reset bit
#define SYSCTL_SOFTPRES2_EPWM15   0x4000U      // EPWM15 software reset bit
#define SYSCTL_SOFTPRES2_EPWM16   0x8000U      // EPWM16 software reset bit

//*****************************************************************************
//
// The following are defines for the bit fields in the SOFTPRES3 register
//
//*****************************************************************************
#define SYSCTL_SOFTPRES3_ECAP1    0x1U         // ECAP1 software reset bit
#define SYSCTL_SOFTPRES3_ECAP2    0x2U         // ECAP2 software reset bit
#define SYSCTL_SOFTPRES3_ECAP3    0x4U         // ECAP3 software reset bit
#define SYSCTL_SOFTPRES3_ECAP4    0x8U         // ECAP4 software reset bit
#define SYSCTL_SOFTPRES3_ECAP5    0x10U        // ECAP5 software reset bit
#define SYSCTL_SOFTPRES3_ECAP6    0x20U        // ECAP6 software reset bit
#define SYSCTL_SOFTPRES3_ECAP7    0x40U        // ECAP7 software reset bit

//*****************************************************************************
//
// The following are defines for the bit fields in the SOFTPRES4 register
//
//*****************************************************************************
#define SYSCTL_SOFTPRES4_EQEP1    0x1U         // EQEP1 software reset bit
#define SYSCTL_SOFTPRES4_EQEP2    0x2U         // EQEP2 software reset bit
#define SYSCTL_SOFTPRES4_EQEP3    0x4U         // EQEP3 software reset bit

//*****************************************************************************
//
// The following are defines for the bit fields in the SOFTPRES6 register
//
//*****************************************************************************
#define SYSCTL_SOFTPRES6_SD1      0x1U         // SD1 software reset bit
#define SYSCTL_SOFTPRES6_SD2      0x2U         // SD2 software reset bit

//*****************************************************************************
//
// The following are defines for the bit fields in the SOFTPRES7 register
//
//*****************************************************************************
#define SYSCTL_SOFTPRES7_SCI_A    0x1U         // SCI_A software reset bit
#define SYSCTL_SOFTPRES7_SCI_B    0x2U         // SCI_B software reset bit
#define SYSCTL_SOFTPRES7_SCI_C    0x4U         // SCI_C software reset bit
#define SYSCTL_SOFTPRES7_SCI_D    0x8U         // SCI_D software reset bit

//*****************************************************************************
//
// The following are defines for the bit fields in the SOFTPRES8 register
//
//*****************************************************************************
#define SYSCTL_SOFTPRES8_SPI_A    0x1U         // SPI_A software reset bit
#define SYSCTL_SOFTPRES8_SPI_B    0x2U         // SPI_B software reset bit
#define SYSCTL_SOFTPRES8_SPI_C    0x4U         // SPI_C software reset bit
#define SYSCTL_SOFTPRES8_SPI_D    0x8U         // SPI_D software reset bit

//*****************************************************************************
//
// The following are defines for the bit fields in the SOFTPRES9 register
//
//*****************************************************************************
#define SYSCTL_SOFTPRES9_I2C_A    0x1U         // I2C_A software reset bit
#define SYSCTL_SOFTPRES9_I2C_B    0x2U         // I2C_B software reset bit

//*****************************************************************************
//
// The following are defines for the bit fields in the SOFTPRES10 register
//
//*****************************************************************************
#define SYSCTL_SOFTPRES10_CAN_A   0x1U         // CAN_A software reset bit
#define SYSCTL_SOFTPRES10_CAN_B   0x2U         // CAN_B software reset bit
#define SYSCTL_SOFTPRES10_MCAN_A  0x10U        // MCAN_A software reset bit

//*****************************************************************************
//
// The following are defines for the bit fields in the SOFTPRES11 register
//
//*****************************************************************************
#define SYSCTL_SOFTPRES11_MCBSP_A  0x1U         // McBSP_A software reset bit
#define SYSCTL_SOFTPRES11_MCBSP_B  0x2U         // McBSP_B software reset bit
#define SYSCTL_SOFTPRES11_USB_A   0x10000U     // USB_A software reset bit

//*****************************************************************************
//
// The following are defines for the bit fields in the SOFTPRES13 register
//
//*****************************************************************************
#define SYSCTL_SOFTPRES13_ADC_A   0x1U         // ADC_A software reset bit
#define SYSCTL_SOFTPRES13_ADC_B   0x2U         // ADC_B software reset bit
#define SYSCTL_SOFTPRES13_ADC_C   0x4U         // ADC_C software reset bit
#define SYSCTL_SOFTPRES13_ADC_D   0x8U         // ADC_D software reset bit

//*****************************************************************************
//
// The following are defines for the bit fields in the SOFTPRES14 register
//
//*****************************************************************************
#define SYSCTL_SOFTPRES14_CMPSS1  0x1U         // CMPSS1 software reset bit
#define SYSCTL_SOFTPRES14_CMPSS2  0x2U         // CMPSS2 software reset bit
#define SYSCTL_SOFTPRES14_CMPSS3  0x4U         // CMPSS3 software reset bit
#define SYSCTL_SOFTPRES14_CMPSS4  0x8U         // CMPSS4 software reset bit
#define SYSCTL_SOFTPRES14_CMPSS5  0x10U        // CMPSS5 software reset bit
#define SYSCTL_SOFTPRES14_CMPSS6  0x20U        // CMPSS6 software reset bit
#define SYSCTL_SOFTPRES14_CMPSS7  0x40U        // CMPSS7 software reset bit
#define SYSCTL_SOFTPRES14_CMPSS8  0x80U        // CMPSS8 software reset bit

//*****************************************************************************
//
// The following are defines for the bit fields in the SOFTPRES16 register
//
//*****************************************************************************
#define SYSCTL_SOFTPRES16_DAC_A   0x10000U     // Buffered_DAC12_1 software
                                               // reset bit
#define SYSCTL_SOFTPRES16_DAC_B   0x20000U     // Buffered_DAC12_2 software
                                               // reset bit
#define SYSCTL_SOFTPRES16_DAC_C   0x40000U     // Buffered_DAC12_3 software
                                               // reset bit

//*****************************************************************************
//
// The following are defines for the bit fields in the SOFTPRES17 register
//
//*****************************************************************************
#define SYSCTL_SOFTPRES17_CLB1    0x1U         // CLB1 software reset bit
#define SYSCTL_SOFTPRES17_CLB2    0x2U         // CLB2 software reset bit
#define SYSCTL_SOFTPRES17_CLB3    0x4U         // CLB3 software reset bit
#define SYSCTL_SOFTPRES17_CLB4    0x8U         // CLB4 software reset bit
#define SYSCTL_SOFTPRES17_CLB5    0x10U        // CLB5 software reset bit
#define SYSCTL_SOFTPRES17_CLB6    0x20U        // CLB6 software reset bit
#define SYSCTL_SOFTPRES17_CLB7    0x40U        // CLB7 software reset bit
#define SYSCTL_SOFTPRES17_CLB8    0x80U        // CLB8 software reset bit

//*****************************************************************************
//
// The following are defines for the bit fields in the SOFTPRES18 register
//
//*****************************************************************************
#define SYSCTL_SOFTPRES18_FSITX_A  0x1U         // FSITX_A software reset bit
#define SYSCTL_SOFTPRES18_FSITX_B  0x2U         // FSITX_B software reset bit
#define SYSCTL_SOFTPRES18_FSIRX_A  0x10000U     // FSIRX_A software reset bit
#define SYSCTL_SOFTPRES18_FSIRX_B  0x20000U     // FSIRX_B software reset bit
#define SYSCTL_SOFTPRES18_FSIRX_C  0x40000U     // FSIRX_C software reset bit
#define SYSCTL_SOFTPRES18_FSIRX_D  0x80000U     // FSIRX_D software reset bit
#define SYSCTL_SOFTPRES18_FSIRX_E  0x100000U    // FSIRX_E software reset bit
#define SYSCTL_SOFTPRES18_FSIRX_F  0x200000U    // FSIRX_F software reset bit
#define SYSCTL_SOFTPRES18_FSIRX_G  0x400000U    // FSIRX_G software reset bit
#define SYSCTL_SOFTPRES18_FSIRX_H  0x800000U    // FSIRX_H software reset bit

//*****************************************************************************
//
// The following are defines for the bit fields in the SOFTPRES20 register
//
//*****************************************************************************
#define SYSCTL_SOFTPRES20_PMBUS_A  0x1U         // PMBUS_A software reset bit

//*****************************************************************************
//
// The following are defines for the bit fields in the SOFTPRES21 register
//
//*****************************************************************************
#define SYSCTL_SOFTPRES21_DCC0    0x1U         // DCC0 Module reset bit
#define SYSCTL_SOFTPRES21_DCC1    0x2U         // DCC1 Module reset bit
#define SYSCTL_SOFTPRES21_DCC2    0x4U         // DCC2 Module reset bit

//*****************************************************************************
//
// The following are defines for the bit fields in the SOFTPRES23 register
//
//*****************************************************************************
#define SYSCTL_SOFTPRES23_ETHERCAT  0x1U         // ETHERCAT Module reset bit

//*****************************************************************************
//
// The following are defines for the bit fields in the CPUSEL0 register
//
//*****************************************************************************
#define SYSCTL_CPUSEL0_EPWM1      0x1U         // EPWM1 CPU select bit
#define SYSCTL_CPUSEL0_EPWM2      0x2U         // EPWM2 CPU select bit
#define SYSCTL_CPUSEL0_EPWM3      0x4U         // EPWM3 CPU select bit
#define SYSCTL_CPUSEL0_EPWM4      0x8U         // EPWM4 CPU select bit
#define SYSCTL_CPUSEL0_EPWM5      0x10U        // EPWM5 CPU select bit
#define SYSCTL_CPUSEL0_EPWM6      0x20U        // EPWM6 CPU select bit
#define SYSCTL_CPUSEL0_EPWM7      0x40U        // EPWM7 CPU select bit
#define SYSCTL_CPUSEL0_EPWM8      0x80U        // EPWM8 CPU select bit
#define SYSCTL_CPUSEL0_EPWM9      0x100U       // EPWM9 CPU select bit
#define SYSCTL_CPUSEL0_EPWM10     0x200U       // EPWM10 CPU select bit
#define SYSCTL_CPUSEL0_EPWM11     0x400U       // EPWM11 CPU select bit
#define SYSCTL_CPUSEL0_EPWM12     0x800U       // EPWM12 CPU select bit
#define SYSCTL_CPUSEL0_EPWM13     0x1000U      // EPWM13 CPU select bit
#define SYSCTL_CPUSEL0_EPWM14     0x2000U      // EPWM14 CPU select bit
#define SYSCTL_CPUSEL0_EPWM15     0x4000U      // EPWM15 CPU select bit
#define SYSCTL_CPUSEL0_EPWM16     0x8000U      // EPWM16 CPU select bit

//*****************************************************************************
//
// The following are defines for the bit fields in the CPUSEL1 register
//
//*****************************************************************************
#define SYSCTL_CPUSEL1_ECAP1      0x1U         // ECAP1 CPU select bit
#define SYSCTL_CPUSEL1_ECAP2      0x2U         // ECAP2 CPU select bit
#define SYSCTL_CPUSEL1_ECAP3      0x4U         // ECAP3 CPU select bit
#define SYSCTL_CPUSEL1_ECAP4      0x8U         // ECAP4 CPU select bit
#define SYSCTL_CPUSEL1_ECAP5      0x10U        // ECAP5 CPU select bit
#define SYSCTL_CPUSEL1_ECAP6      0x20U        // ECAP6 CPU select bit
#define SYSCTL_CPUSEL1_ECAP7      0x40U        // ECAP7 CPU select bit

//*****************************************************************************
//
// The following are defines for the bit fields in the CPUSEL2 register
//
//*****************************************************************************
#define SYSCTL_CPUSEL2_EQEP1      0x1U         // EQEP1 CPU select bit
#define SYSCTL_CPUSEL2_EQEP2      0x2U         // EQEP2 CPU select bit
#define SYSCTL_CPUSEL2_EQEP3      0x4U         // EQEP3 CPU select bit

//*****************************************************************************
//
// The following are defines for the bit fields in the CPUSEL4 register
//
//*****************************************************************************
#define SYSCTL_CPUSEL4_SD1        0x1U         // SD1 CPU select bit
#define SYSCTL_CPUSEL4_SD2        0x2U         // SD2 CPU select bit

//*****************************************************************************
//
// The following are defines for the bit fields in the CPUSEL5 register
//
//*****************************************************************************
#define SYSCTL_CPUSEL5_SCI_A      0x1U         // SCI_A CPU select bit
#define SYSCTL_CPUSEL5_SCI_B      0x2U         // SCI_B CPU select bit
#define SYSCTL_CPUSEL5_SCI_C      0x4U         // SCI_C CPU select bit
#define SYSCTL_CPUSEL5_SCI_D      0x8U         // SCI_D CPU select bit

//*****************************************************************************
//
// The following are defines for the bit fields in the CPUSEL6 register
//
//*****************************************************************************
#define SYSCTL_CPUSEL6_SPI_A      0x1U         // SPI_A CPU select bit
#define SYSCTL_CPUSEL6_SPI_B      0x2U         // SPI_B CPU select bit
#define SYSCTL_CPUSEL6_SPI_C      0x4U         // SPI_C CPU select bit
#define SYSCTL_CPUSEL6_SPI_D      0x8U         // SPI_D CPU select bit

//*****************************************************************************
//
// The following are defines for the bit fields in the CPUSEL7 register
//
//*****************************************************************************
#define SYSCTL_CPUSEL7_I2C_A      0x1U         // I2C_A CPU select bit
#define SYSCTL_CPUSEL7_I2C_B      0x2U         // I2C_B CPU select bit

//*****************************************************************************
//
// The following are defines for the bit fields in the CPUSEL8 register
//
//*****************************************************************************
#define SYSCTL_CPUSEL8_CAN_A      0x1U         // CAN_A CPU select bit
#define SYSCTL_CPUSEL8_CAN_B      0x2U         // CAN_B CPU select bit

//*****************************************************************************
//
// The following are defines for the bit fields in the CPUSEL9 register
//
//*****************************************************************************
#define SYSCTL_CPUSEL9_MCBSP_A    0x1U         // McBSP_A CPU select bit
#define SYSCTL_CPUSEL9_MCBSP_B    0x2U         // McBSP_B CPU select bit

//*****************************************************************************
//
// The following are defines for the bit fields in the CPUSEL11 register
//
//*****************************************************************************
#define SYSCTL_CPUSEL11_ADC_A     0x1U         // ADC_A CPU select bit
#define SYSCTL_CPUSEL11_ADC_B     0x2U         // ADC_B CPU select bit
#define SYSCTL_CPUSEL11_ADC_C     0x4U         // ADC_C CPU select bit
#define SYSCTL_CPUSEL11_ADC_D     0x8U         // ADC_D CPU select bit

//*****************************************************************************
//
// The following are defines for the bit fields in the CPUSEL12 register
//
//*****************************************************************************
#define SYSCTL_CPUSEL12_CMPSS1    0x1U         // CMPSS1 CPU select bit
#define SYSCTL_CPUSEL12_CMPSS2    0x2U         // CMPSS2 CPU select bit
#define SYSCTL_CPUSEL12_CMPSS3    0x4U         // CMPSS3 CPU select bit
#define SYSCTL_CPUSEL12_CMPSS4    0x8U         // CMPSS4 CPU select bit
#define SYSCTL_CPUSEL12_CMPSS5    0x10U        // CMPSS5 CPU select bit
#define SYSCTL_CPUSEL12_CMPSS6    0x20U        // CMPSS6 CPU select bit
#define SYSCTL_CPUSEL12_CMPSS7    0x40U        // CMPSS7 CPU select bit
#define SYSCTL_CPUSEL12_CMPSS8    0x80U        // CMPSS8 CPU select bit

//*****************************************************************************
//
// The following are defines for the bit fields in the CPUSEL14 register
//
//*****************************************************************************
#define SYSCTL_CPUSEL14_DAC_A     0x10000U     // Buffered_DAC12_1 CPU select
                                               // bit
#define SYSCTL_CPUSEL14_DAC_B     0x20000U     // Buffered_DAC12_2 CPU select
                                               // bit
#define SYSCTL_CPUSEL14_DAC_C     0x40000U     // Buffered_DAC12_3 CPU select
                                               // bit

//*****************************************************************************
//
// The following are defines for the bit fields in the CPUSEL15 register
//
//*****************************************************************************
#define SYSCTL_CPUSEL15_CLB1      0x1U         // CLB1 CPU select bit
#define SYSCTL_CPUSEL15_CLB2      0x2U         // CLB2 CPU select bit
#define SYSCTL_CPUSEL15_CLB3      0x4U         // CLB3 CPU select bit
#define SYSCTL_CPUSEL15_CLB4      0x8U         // CLB4 CPU select bit
#define SYSCTL_CPUSEL15_CLB5      0x10U        // CLB5 CPU select bit
#define SYSCTL_CPUSEL15_CLB6      0x20U        // CLB6 CPU select bit
#define SYSCTL_CPUSEL15_CLB7      0x40U        // CLB7 CPU select bit
#define SYSCTL_CPUSEL15_CLB8      0x80U        // CLB8 CPU select bit

//*****************************************************************************
//
// The following are defines for the bit fields in the CPUSEL16 register
//
//*****************************************************************************
#define SYSCTL_CPUSEL16_FSITX_A   0x1U         // FSITX_A CPU select bit
#define SYSCTL_CPUSEL16_FSITX_B   0x2U         // FSITX_B CPU select bit
#define SYSCTL_CPUSEL16_FSIRX_A   0x10000U     // FSIRX_A CPU select bit
#define SYSCTL_CPUSEL16_FSIRX_B   0x20000U     // FSIRX_B CPU select bit
#define SYSCTL_CPUSEL16_FSIRX_C   0x40000U     // FSIRX_C CPU select bit
#define SYSCTL_CPUSEL16_FSIRX_D   0x80000U     // FSIRX_D CPU select bit
#define SYSCTL_CPUSEL16_FSIRX_E   0x100000U    // FSIRX_E CPU select bit
#define SYSCTL_CPUSEL16_FSIRX_F   0x200000U    // FSIRX_F CPU select bit
#define SYSCTL_CPUSEL16_FSIRX_G   0x400000U    // FSIRX_G CPU select bit
#define SYSCTL_CPUSEL16_FSIRX_H   0x800000U    // FSIRX_H CPU select bit

//*****************************************************************************
//
// The following are defines for the bit fields in the CPUSEL18 register
//
//*****************************************************************************
#define SYSCTL_CPUSEL18_PMBUS_A   0x1U         // PMBUS_A CPU select bit

//*****************************************************************************
//
// The following are defines for the bit fields in the CPUSEL25 register
//
//*****************************************************************************
#define SYSCTL_CPUSEL25_HRCAL_A   0x1U         // HRCAL CPU select bit

//*****************************************************************************
//
// The following are defines for the bit fields in the CPU2RESCTL register
//
//*****************************************************************************
#define SYSCTL_CPU2RESCTL_RESET   0x1U         // CPU2 Reset Control bit
#define SYSCTL_CPU2RESCTL_KEY_S   16U
#define SYSCTL_CPU2RESCTL_KEY_M   0xFFFF0000U  // Key Qualifier for writes to
                                               // this register

//*****************************************************************************
//
// The following are defines for the bit fields in the RSTSTAT register
//
//*****************************************************************************
#define SYSCTL_RSTSTAT_CPU2RES    0x1U         // CPU2 Reset Status bit
#define SYSCTL_RSTSTAT_CPU2NMIWDRST  0x2U         // Tells whether a CPU2.NMIWD
                                               // reset was issued to CPU2 or not
#define SYSCTL_RSTSTAT_CPU2HWBISTRST_S  2U
#define SYSCTL_RSTSTAT_CPU2HWBISTRST_M  0xCU         // Tells whether a HWBIST reset
                                               // was issued to CPU2 or not

//*****************************************************************************
//
// The following are defines for the bit fields in the LPMSTAT register
//
//*****************************************************************************
#define SYSCTL_LPMSTAT_CPU2LPMSTAT_S  0U
#define SYSCTL_LPMSTAT_CPU2LPMSTAT_M  0x3U         // CPU2 LPM Status

//*****************************************************************************
//
// The following are defines for the bit fields in the CPU1ROM_DC1 register
//
//*****************************************************************************
#define SYSCTL_CPU1ROM_DC1_ROM_DIS_START_ADDR_S  0U
#define SYSCTL_CPU1ROM_DC1_ROM_DIS_START_ADDR_M  0x1FFU       // Start Address of  disabled
                                               // Secure ROM
#define SYSCTL_CPU1ROM_DC1_ROM_DIS_SIZE_INV_S  9U
#define SYSCTL_CPU1ROM_DC1_ROM_DIS_SIZE_INV_M  0xFE00U      // Size(Inverted) of ROM section
                                               // disabled

//*****************************************************************************
//
// The following are defines for the bit fields in the CPU1ROM_DC2 register
//
//*****************************************************************************
#define SYSCTL_CPU1ROM_DC2_ROM_DIS_START_ADDR_S  0U
#define SYSCTL_CPU1ROM_DC2_ROM_DIS_START_ADDR_M  0x1FFU       // Start Address of  disabled
                                               // Secure ROM
#define SYSCTL_CPU1ROM_DC2_ROM_DIS_SIZE_INV_S  9U
#define SYSCTL_CPU1ROM_DC2_ROM_DIS_SIZE_INV_M  0xFE00U      // Size(Inverted) of ROM section
                                               // disabled

//*****************************************************************************
//
// The following are defines for the bit fields in the CPU1ROM_DC3 register
//
//*****************************************************************************
#define SYSCTL_CPU1ROM_DC3_ROM_DIS_START_ADDR_S  0U
#define SYSCTL_CPU1ROM_DC3_ROM_DIS_START_ADDR_M  0x1FFU       // Start Address of  disabled
                                               // Secure ROM
#define SYSCTL_CPU1ROM_DC3_ROM_DIS_SIZE_INV_S  9U
#define SYSCTL_CPU1ROM_DC3_ROM_DIS_SIZE_INV_M  0xFE00U      // Size(Inverted) of ROM section
                                               // disabled

//*****************************************************************************
//
// The following are defines for the bit fields in the CPU1ROM_DC4 register
//
//*****************************************************************************
#define SYSCTL_CPU1ROM_DC4_ROM_DIS_START_ADDR_S  0U
#define SYSCTL_CPU1ROM_DC4_ROM_DIS_START_ADDR_M  0x1FFU       // Start Address of  disabled
                                               // Secure ROM
#define SYSCTL_CPU1ROM_DC4_ROM_DIS_SIZE_INV_S  9U
#define SYSCTL_CPU1ROM_DC4_ROM_DIS_SIZE_INV_M  0xFE00U      // Size(Inverted) of ROM section
                                               // disabled

//*****************************************************************************
//
// The following are defines for the bit fields in the CPU2ROM_DC1 register
//
//*****************************************************************************
#define SYSCTL_CPU2ROM_DC1_ROM_DIS_START_ADDR_S  0U
#define SYSCTL_CPU2ROM_DC1_ROM_DIS_START_ADDR_M  0x1FFU       // Start Address of  disabled
                                               // Secure ROM
#define SYSCTL_CPU2ROM_DC1_ROM_DIS_SIZE_INV_S  9U
#define SYSCTL_CPU2ROM_DC1_ROM_DIS_SIZE_INV_M  0xFE00U      // Size(Inverted) of ROM section
                                               // disabled

//*****************************************************************************
//
// The following are defines for the bit fields in the CPU2ROM_DC2 register
//
//*****************************************************************************
#define SYSCTL_CPU2ROM_DC2_ROM_DIS_START_ADDR_S  0U
#define SYSCTL_CPU2ROM_DC2_ROM_DIS_START_ADDR_M  0x1FFU       // Start Address of  disabled
                                               // Secure ROM
#define SYSCTL_CPU2ROM_DC2_ROM_DIS_SIZE_INV_S  9U
#define SYSCTL_CPU2ROM_DC2_ROM_DIS_SIZE_INV_M  0xFE00U      // Size(Inverted) of ROM section
                                               // disabled

//*****************************************************************************
//
// The following are defines for the bit fields in the CPU2ROM_DC3 register
//
//*****************************************************************************
#define SYSCTL_CPU2ROM_DC3_ROM_DIS_START_ADDR_S  0U
#define SYSCTL_CPU2ROM_DC3_ROM_DIS_START_ADDR_M  0x1FFU       // Start Address of  disabled
                                               // Secure ROM
#define SYSCTL_CPU2ROM_DC3_ROM_DIS_SIZE_INV_S  9U
#define SYSCTL_CPU2ROM_DC3_ROM_DIS_SIZE_INV_M  0xFE00U      // Size(Inverted) of ROM section
                                               // disabled

//*****************************************************************************
//
// The following are defines for the bit fields in the CPU2ROM_DC4 register
//
//*****************************************************************************
#define SYSCTL_CPU2ROM_DC4_ROM_DIS_START_ADDR_S  0U
#define SYSCTL_CPU2ROM_DC4_ROM_DIS_START_ADDR_M  0x1FFU       // Start Address of  disabled
                                               // Secure ROM
#define SYSCTL_CPU2ROM_DC4_ROM_DIS_SIZE_INV_S  9U
#define SYSCTL_CPU2ROM_DC4_ROM_DIS_SIZE_INV_M  0xFE00U      // Size(Inverted) of ROM section
                                               // disabled

//*****************************************************************************
//
// The following are defines for the bit fields in the BANKSEL register
//
//*****************************************************************************
#define SYSCTL_BANKSEL_SEL_S      0U
#define SYSCTL_BANKSEL_SEL_M      0x3U         // Selects the BANK to be
                                               // programmed by CPU1 FMC.

//*****************************************************************************
//
// The following are defines for the bit fields in the USBTYPE register
//
//*****************************************************************************
#define SYSCTL_USBTYPE_TYPE_S     0U
#define SYSCTL_USBTYPE_TYPE_M     0x3U         // Configure USB type
#define SYSCTL_USBTYPE_LOCK       0x8000U      // Lock bit

//*****************************************************************************
//
// The following are defines for the bit fields in the ECAPTYPE register
//
//*****************************************************************************
#define SYSCTL_ECAPTYPE_TYPE_S    0U
#define SYSCTL_ECAPTYPE_TYPE_M    0x3U         // Configure ECAP type
#define SYSCTL_ECAPTYPE_LOCK      0x8000U      // Lock bit

//*****************************************************************************
//
// The following are defines for the bit fields in the SDFMTYPE register
//
//*****************************************************************************
#define SYSCTL_SDFMTYPE_TYPE_S    0U
#define SYSCTL_SDFMTYPE_TYPE_M    0x3U         // Configure SDFM type
#define SYSCTL_SDFMTYPE_LOCK      0x8000U      // Lock bit

//*****************************************************************************
//
// The following are defines for the bit fields in the MEMMAPTYPE register
//
//*****************************************************************************
#define SYSCTL_MEMMAPTYPE_TYPE_S  0U
#define SYSCTL_MEMMAPTYPE_TYPE_M  0x3U         // Configures system specific
                                               // features related to memory map.
#define SYSCTL_MEMMAPTYPE_LOCK    0x8000U      // Lock bit

//*****************************************************************************
//
// The following are defines for the bit fields in the ADCA_AC register
//
//*****************************************************************************
#define SYSCTL_ADCA_AC_CPUX_ACC_S  0U
#define SYSCTL_ADCA_AC_CPUX_ACC_M  0x3U         // CPU1 Access conditions to
                                               // peripheral
#define SYSCTL_ADCA_AC_CLA1_ACC_S  2U
#define SYSCTL_ADCA_AC_CLA1_ACC_M  0xCU         // CLA1 Access Conditions to
                                               // Peripheral
#define SYSCTL_ADCA_AC_DMA1_ACC_S  4U
#define SYSCTL_ADCA_AC_DMA1_ACC_M  0x30U        // DMA1 Access Conditions to
                                               // Peripheral

//*****************************************************************************
//
// The following are defines for the bit fields in the ADCB_AC register
//
//*****************************************************************************
#define SYSCTL_ADCB_AC_CPUX_ACC_S  0U
#define SYSCTL_ADCB_AC_CPUX_ACC_M  0x3U         // CPUx Access conditions to
                                               // peripheral
#define SYSCTL_ADCB_AC_CLA1_ACC_S  2U
#define SYSCTL_ADCB_AC_CLA1_ACC_M  0xCU         // CLA1 Access Conditions to
                                               // Peripheral
#define SYSCTL_ADCB_AC_DMA1_ACC_S  4U
#define SYSCTL_ADCB_AC_DMA1_ACC_M  0x30U        // DMA1 Access Conditions to
                                               // Peripheral

//*****************************************************************************
//
// The following are defines for the bit fields in the ADCC_AC register
//
//*****************************************************************************
#define SYSCTL_ADCC_AC_CPUX_ACC_S  0U
#define SYSCTL_ADCC_AC_CPUX_ACC_M  0x3U         // CPUx Access conditions to
                                               // peripheral
#define SYSCTL_ADCC_AC_CLA1_ACC_S  2U
#define SYSCTL_ADCC_AC_CLA1_ACC_M  0xCU         // CLA1 Access Conditions to
                                               // Peripheral
#define SYSCTL_ADCC_AC_DMA1_ACC_S  4U
#define SYSCTL_ADCC_AC_DMA1_ACC_M  0x30U        // DMA1 Access Conditions to
                                               // Peripheral

//*****************************************************************************
//
// The following are defines for the bit fields in the ADCD_AC register
//
//*****************************************************************************
#define SYSCTL_ADCD_AC_CPUX_ACC_S  0U
#define SYSCTL_ADCD_AC_CPUX_ACC_M  0x3U         // CPUx Access conditions to
                                               // peripheral
#define SYSCTL_ADCD_AC_CLA1_ACC_S  2U
#define SYSCTL_ADCD_AC_CLA1_ACC_M  0xCU         // CLA1 Access Conditions to
                                               // Peripheral
#define SYSCTL_ADCD_AC_DMA1_ACC_S  4U
#define SYSCTL_ADCD_AC_DMA1_ACC_M  0x30U        // DMA1 Access Conditions to
                                               // Peripheral

//*****************************************************************************
//
// The following are defines for the bit fields in the CMPSS1_AC register
//
//*****************************************************************************
#define SYSCTL_CMPSS1_AC_CPUX_ACC_S  0U
#define SYSCTL_CMPSS1_AC_CPUX_ACC_M  0x3U         // CPUx Access conditions to
                                               // peripheral
#define SYSCTL_CMPSS1_AC_CLA1_ACC_S  2U
#define SYSCTL_CMPSS1_AC_CLA1_ACC_M  0xCU         // CLA1 Access Conditions to
                                               // Peripheral
#define SYSCTL_CMPSS1_AC_DMA1_ACC_S  4U
#define SYSCTL_CMPSS1_AC_DMA1_ACC_M  0x30U        // DMA1 Access Conditions to
                                               // Peripheral

//*****************************************************************************
//
// The following are defines for the bit fields in the CMPSS2_AC register
//
//*****************************************************************************
#define SYSCTL_CMPSS2_AC_CPUX_ACC_S  0U
#define SYSCTL_CMPSS2_AC_CPUX_ACC_M  0x3U         // CPUx Access conditions to
                                               // peripheral
#define SYSCTL_CMPSS2_AC_CLA1_ACC_S  2U
#define SYSCTL_CMPSS2_AC_CLA1_ACC_M  0xCU         // CLA1 Access Conditions to
                                               // Peripheral
#define SYSCTL_CMPSS2_AC_DMA1_ACC_S  4U
#define SYSCTL_CMPSS2_AC_DMA1_ACC_M  0x30U        // DMA1 Access Conditions to
                                               // Peripheral

//*****************************************************************************
//
// The following are defines for the bit fields in the CMPSS3_AC register
//
//*****************************************************************************
#define SYSCTL_CMPSS3_AC_CPUX_ACC_S  0U
#define SYSCTL_CMPSS3_AC_CPUX_ACC_M  0x3U         // CPUx Access conditions to
                                               // peripheral
#define SYSCTL_CMPSS3_AC_CLA1_ACC_S  2U
#define SYSCTL_CMPSS3_AC_CLA1_ACC_M  0xCU         // CLA1 Access Conditions to
                                               // Peripheral
#define SYSCTL_CMPSS3_AC_DMA1_ACC_S  4U
#define SYSCTL_CMPSS3_AC_DMA1_ACC_M  0x30U        // DMA1 Access Conditions to
                                               // Peripheral

//*****************************************************************************
//
// The following are defines for the bit fields in the CMPSS4_AC register
//
//*****************************************************************************
#define SYSCTL_CMPSS4_AC_CPUX_ACC_S  0U
#define SYSCTL_CMPSS4_AC_CPUX_ACC_M  0x3U         // CPUx Access conditions to
                                               // peripheral
#define SYSCTL_CMPSS4_AC_CLA1_ACC_S  2U
#define SYSCTL_CMPSS4_AC_CLA1_ACC_M  0xCU         // CLA1 Access Conditions to
                                               // Peripheral
#define SYSCTL_CMPSS4_AC_DMA1_ACC_S  4U
#define SYSCTL_CMPSS4_AC_DMA1_ACC_M  0x30U        // DMA1 Access Conditions to
                                               // Peripheral

//*****************************************************************************
//
// The following are defines for the bit fields in the CMPSS5_AC register
//
//*****************************************************************************
#define SYSCTL_CMPSS5_AC_CPUX_ACC_S  0U
#define SYSCTL_CMPSS5_AC_CPUX_ACC_M  0x3U         // CPUx Access conditions to
                                               // peripheral
#define SYSCTL_CMPSS5_AC_CLA1_ACC_S  2U
#define SYSCTL_CMPSS5_AC_CLA1_ACC_M  0xCU         // CLA1 Access Conditions to
                                               // Peripheral
#define SYSCTL_CMPSS5_AC_DMA1_ACC_S  4U
#define SYSCTL_CMPSS5_AC_DMA1_ACC_M  0x30U        // DMA1 Access Conditions to
                                               // Peripheral

//*****************************************************************************
//
// The following are defines for the bit fields in the CMPSS6_AC register
//
//*****************************************************************************
#define SYSCTL_CMPSS6_AC_CPUX_ACC_S  0U
#define SYSCTL_CMPSS6_AC_CPUX_ACC_M  0x3U         // CPUx Access conditions to
                                               // peripheral
#define SYSCTL_CMPSS6_AC_CLA1_ACC_S  2U
#define SYSCTL_CMPSS6_AC_CLA1_ACC_M  0xCU         // CLA1 Access Conditions to
                                               // Peripheral
#define SYSCTL_CMPSS6_AC_DMA1_ACC_S  4U
#define SYSCTL_CMPSS6_AC_DMA1_ACC_M  0x30U        // DMA1 Access Conditions to
                                               // Peripheral

//*****************************************************************************
//
// The following are defines for the bit fields in the CMPSS7_AC register
//
//*****************************************************************************
#define SYSCTL_CMPSS7_AC_CPUX_ACC_S  0U
#define SYSCTL_CMPSS7_AC_CPUX_ACC_M  0x3U         // CPUx Access conditions to
                                               // peripheral
#define SYSCTL_CMPSS7_AC_CLA1_ACC_S  2U
#define SYSCTL_CMPSS7_AC_CLA1_ACC_M  0xCU         // CLA1 Access Conditions to
                                               // Peripheral
#define SYSCTL_CMPSS7_AC_DMA1_ACC_S  4U
#define SYSCTL_CMPSS7_AC_DMA1_ACC_M  0x30U        // DMA1 Access Conditions to
                                               // Peripheral

//*****************************************************************************
//
// The following are defines for the bit fields in the CMPSS8_AC register
//
//*****************************************************************************
#define SYSCTL_CMPSS8_AC_CPUX_ACC_S  0U
#define SYSCTL_CMPSS8_AC_CPUX_ACC_M  0x3U         // CPUx Access conditions to
                                               // peripheral
#define SYSCTL_CMPSS8_AC_CLA1_ACC_S  2U
#define SYSCTL_CMPSS8_AC_CLA1_ACC_M  0xCU         // CLA1 Access Conditions to
                                               // Peripheral
#define SYSCTL_CMPSS8_AC_DMA1_ACC_S  4U
#define SYSCTL_CMPSS8_AC_DMA1_ACC_M  0x30U        // DMA1 Access Conditions to
                                               // Peripheral

//*****************************************************************************
//
// The following are defines for the bit fields in the DACA_AC register
//
//*****************************************************************************
#define SYSCTL_DACA_AC_CPUX_ACC_S  0U
#define SYSCTL_DACA_AC_CPUX_ACC_M  0x3U         // CPUx Access conditions to
                                               // peripheral
#define SYSCTL_DACA_AC_CLA1_ACC_S  2U
#define SYSCTL_DACA_AC_CLA1_ACC_M  0xCU         // CLA1 Access Conditions to
                                               // Peripheral
#define SYSCTL_DACA_AC_DMA1_ACC_S  4U
#define SYSCTL_DACA_AC_DMA1_ACC_M  0x30U        // DMA1 Access Conditions to
                                               // Peripheral

//*****************************************************************************
//
// The following are defines for the bit fields in the DACB_AC register
//
//*****************************************************************************
#define SYSCTL_DACB_AC_CPUX_ACC_S  0U
#define SYSCTL_DACB_AC_CPUX_ACC_M  0x3U         // CPUx Access conditions to
                                               // peripheral
#define SYSCTL_DACB_AC_CLA1_ACC_S  2U
#define SYSCTL_DACB_AC_CLA1_ACC_M  0xCU         // CLA1 Access Conditions to
                                               // Peripheral
#define SYSCTL_DACB_AC_DMA1_ACC_S  4U
#define SYSCTL_DACB_AC_DMA1_ACC_M  0x30U        // DMA1 Access Conditions to
                                               // Peripheral

//*****************************************************************************
//
// The following are defines for the bit fields in the DACC_AC register
//
//*****************************************************************************
#define SYSCTL_DACC_AC_CPUX_ACC_S  0U
#define SYSCTL_DACC_AC_CPUX_ACC_M  0x3U         // CPUx Access conditions to
                                               // peripheral
#define SYSCTL_DACC_AC_CLA1_ACC_S  2U
#define SYSCTL_DACC_AC_CLA1_ACC_M  0xCU         // CLA1 Access Conditions to
                                               // Peripheral
#define SYSCTL_DACC_AC_DMA1_ACC_S  4U
#define SYSCTL_DACC_AC_DMA1_ACC_M  0x30U        // DMA1 Access Conditions to
                                               // Peripheral

//*****************************************************************************
//
// The following are defines for the bit fields in the EPWM1_AC register
//
//*****************************************************************************
#define SYSCTL_EPWM1_AC_CPUX_ACC_S  0U
#define SYSCTL_EPWM1_AC_CPUX_ACC_M  0x3U         // CPUx Access conditions to
                                               // peripheral
#define SYSCTL_EPWM1_AC_CLA1_ACC_S  2U
#define SYSCTL_EPWM1_AC_CLA1_ACC_M  0xCU         // CLA1 Access Conditions to
                                               // Peripheral
#define SYSCTL_EPWM1_AC_DMA1_ACC_S  4U
#define SYSCTL_EPWM1_AC_DMA1_ACC_M  0x30U        // DMA1 Access Conditions to
                                               // Peripheral

//*****************************************************************************
//
// The following are defines for the bit fields in the EPWM2_AC register
//
//*****************************************************************************
#define SYSCTL_EPWM2_AC_CPUX_ACC_S  0U
#define SYSCTL_EPWM2_AC_CPUX_ACC_M  0x3U         // CPUx Access conditions to
                                               // peripheral
#define SYSCTL_EPWM2_AC_CLA1_ACC_S  2U
#define SYSCTL_EPWM2_AC_CLA1_ACC_M  0xCU         // CLA1 Access Conditions to
                                               // Peripheral
#define SYSCTL_EPWM2_AC_DMA1_ACC_S  4U
#define SYSCTL_EPWM2_AC_DMA1_ACC_M  0x30U        // DMA1 Access Conditions to
                                               // Peripheral

//*****************************************************************************
//
// The following are defines for the bit fields in the EPWM3_AC register
//
//*****************************************************************************
#define SYSCTL_EPWM3_AC_CPUX_ACC_S  0U
#define SYSCTL_EPWM3_AC_CPUX_ACC_M  0x3U         // CPUx Access conditions to
                                               // peripheral
#define SYSCTL_EPWM3_AC_CLA1_ACC_S  2U
#define SYSCTL_EPWM3_AC_CLA1_ACC_M  0xCU         // CLA1 Access Conditions to
                                               // Peripheral
#define SYSCTL_EPWM3_AC_DMA1_ACC_S  4U
#define SYSCTL_EPWM3_AC_DMA1_ACC_M  0x30U        // DMA1 Access Conditions to
                                               // Peripheral

//*****************************************************************************
//
// The following are defines for the bit fields in the EPWM4_AC register
//
//*****************************************************************************
#define SYSCTL_EPWM4_AC_CPUX_ACC_S  0U
#define SYSCTL_EPWM4_AC_CPUX_ACC_M  0x3U         // CPUx Access conditions to
                                               // peripheral
#define SYSCTL_EPWM4_AC_CLA1_ACC_S  2U
#define SYSCTL_EPWM4_AC_CLA1_ACC_M  0xCU         // CLA1 Access Conditions to
                                               // Peripheral
#define SYSCTL_EPWM4_AC_DMA1_ACC_S  4U
#define SYSCTL_EPWM4_AC_DMA1_ACC_M  0x30U        // DMA1 Access Conditions to
                                               // Peripheral

//*****************************************************************************
//
// The following are defines for the bit fields in the EPWM5_AC register
//
//*****************************************************************************
#define SYSCTL_EPWM5_AC_CPUX_ACC_S  0U
#define SYSCTL_EPWM5_AC_CPUX_ACC_M  0x3U         // CPUx Access conditions to
                                               // peripheral
#define SYSCTL_EPWM5_AC_CLA1_ACC_S  2U
#define SYSCTL_EPWM5_AC_CLA1_ACC_M  0xCU         // CLA1 Access Conditions to
                                               // Peripheral
#define SYSCTL_EPWM5_AC_DMA1_ACC_S  4U
#define SYSCTL_EPWM5_AC_DMA1_ACC_M  0x30U        // DMA1 Access Conditions to
                                               // Peripheral

//*****************************************************************************
//
// The following are defines for the bit fields in the EPWM6_AC register
//
//*****************************************************************************
#define SYSCTL_EPWM6_AC_CPUX_ACC_S  0U
#define SYSCTL_EPWM6_AC_CPUX_ACC_M  0x3U         // CPUx Access conditions to
                                               // peripheral
#define SYSCTL_EPWM6_AC_CLA1_ACC_S  2U
#define SYSCTL_EPWM6_AC_CLA1_ACC_M  0xCU         // CLA1 Access Conditions to
                                               // Peripheral
#define SYSCTL_EPWM6_AC_DMA1_ACC_S  4U
#define SYSCTL_EPWM6_AC_DMA1_ACC_M  0x30U        // DMA1 Access Conditions to
                                               // Peripheral

//*****************************************************************************
//
// The following are defines for the bit fields in the EPWM7_AC register
//
//*****************************************************************************
#define SYSCTL_EPWM7_AC_CPUX_ACC_S  0U
#define SYSCTL_EPWM7_AC_CPUX_ACC_M  0x3U         // CPUx Access conditions to
                                               // peripheral
#define SYSCTL_EPWM7_AC_CLA1_ACC_S  2U
#define SYSCTL_EPWM7_AC_CLA1_ACC_M  0xCU         // CLA1 Access Conditions to
                                               // Peripheral
#define SYSCTL_EPWM7_AC_DMA1_ACC_S  4U
#define SYSCTL_EPWM7_AC_DMA1_ACC_M  0x30U        // DMA1 Access Conditions to
                                               // Peripheral

//*****************************************************************************
//
// The following are defines for the bit fields in the EPWM8_AC register
//
//*****************************************************************************
#define SYSCTL_EPWM8_AC_CPUX_ACC_S  0U
#define SYSCTL_EPWM8_AC_CPUX_ACC_M  0x3U         // CPUx Access conditions to
                                               // peripheral
#define SYSCTL_EPWM8_AC_CLA1_ACC_S  2U
#define SYSCTL_EPWM8_AC_CLA1_ACC_M  0xCU         // CLA1 Access Conditions to
                                               // Peripheral
#define SYSCTL_EPWM8_AC_DMA1_ACC_S  4U
#define SYSCTL_EPWM8_AC_DMA1_ACC_M  0x30U        // DMA1 Access Conditions to
                                               // Peripheral

//*****************************************************************************
//
// The following are defines for the bit fields in the EPWM9_AC register
//
//*****************************************************************************
#define SYSCTL_EPWM9_AC_CPUX_ACC_S  0U
#define SYSCTL_EPWM9_AC_CPUX_ACC_M  0x3U         // CPUx Access conditions to
                                               // peripheral
#define SYSCTL_EPWM9_AC_CLA1_ACC_S  2U
#define SYSCTL_EPWM9_AC_CLA1_ACC_M  0xCU         // CLA1 Access Conditions to
                                               // Peripheral
#define SYSCTL_EPWM9_AC_DMA1_ACC_S  4U
#define SYSCTL_EPWM9_AC_DMA1_ACC_M  0x30U        // DMA1 Access Conditions to
                                               // Peripheral

//*****************************************************************************
//
// The following are defines for the bit fields in the EPWM10_AC register
//
//*****************************************************************************
#define SYSCTL_EPWM10_AC_CPUX_ACC_S  0U
#define SYSCTL_EPWM10_AC_CPUX_ACC_M  0x3U         // CPUx Access conditions to
                                               // peripheral
#define SYSCTL_EPWM10_AC_CLA1_ACC_S  2U
#define SYSCTL_EPWM10_AC_CLA1_ACC_M  0xCU         // CLA1 Access Conditions to
                                               // Peripheral
#define SYSCTL_EPWM10_AC_DMA1_ACC_S  4U
#define SYSCTL_EPWM10_AC_DMA1_ACC_M  0x30U        // DMA1 Access Conditions to
                                               // Peripheral

//*****************************************************************************
//
// The following are defines for the bit fields in the EPWM11_AC register
//
//*****************************************************************************
#define SYSCTL_EPWM11_AC_CPUX_ACC_S  0U
#define SYSCTL_EPWM11_AC_CPUX_ACC_M  0x3U         // CPUx Access conditions to
                                               // peripheral
#define SYSCTL_EPWM11_AC_CLA1_ACC_S  2U
#define SYSCTL_EPWM11_AC_CLA1_ACC_M  0xCU         // CLA1 Access Conditions to
                                               // Peripheral
#define SYSCTL_EPWM11_AC_DMA1_ACC_S  4U
#define SYSCTL_EPWM11_AC_DMA1_ACC_M  0x30U        // DMA1 Access Conditions to
                                               // Peripheral

//*****************************************************************************
//
// The following are defines for the bit fields in the EPWM12_AC register
//
//*****************************************************************************
#define SYSCTL_EPWM12_AC_CPUX_ACC_S  0U
#define SYSCTL_EPWM12_AC_CPUX_ACC_M  0x3U         // CPUx Access conditions to
                                               // peripheral
#define SYSCTL_EPWM12_AC_CLA1_ACC_S  2U
#define SYSCTL_EPWM12_AC_CLA1_ACC_M  0xCU         // CLA1 Access Conditions to
                                               // Peripheral
#define SYSCTL_EPWM12_AC_DMA1_ACC_S  4U
#define SYSCTL_EPWM12_AC_DMA1_ACC_M  0x30U        // DMA1 Access Conditions to
                                               // Peripheral

//*****************************************************************************
//
// The following are defines for the bit fields in the EPWM13_AC register
//
//*****************************************************************************
#define SYSCTL_EPWM13_AC_CPUX_ACC_S  0U
#define SYSCTL_EPWM13_AC_CPUX_ACC_M  0x3U         // CPUx Access conditions to
                                               // peripheral
#define SYSCTL_EPWM13_AC_CLA1_ACC_S  2U
#define SYSCTL_EPWM13_AC_CLA1_ACC_M  0xCU         // CLA1 Access Conditions to
                                               // Peripheral
#define SYSCTL_EPWM13_AC_DMA1_ACC_S  4U
#define SYSCTL_EPWM13_AC_DMA1_ACC_M  0x30U        // DMA1 Access Conditions to
                                               // Peripheral

//*****************************************************************************
//
// The following are defines for the bit fields in the EPWM14_AC register
//
//*****************************************************************************
#define SYSCTL_EPWM14_AC_CPUX_ACC_S  0U
#define SYSCTL_EPWM14_AC_CPUX_ACC_M  0x3U         // CPUx Access conditions to
                                               // peripheral
#define SYSCTL_EPWM14_AC_CLA1_ACC_S  2U
#define SYSCTL_EPWM14_AC_CLA1_ACC_M  0xCU         // CLA1 Access Conditions to
                                               // Peripheral
#define SYSCTL_EPWM14_AC_DMA1_ACC_S  4U
#define SYSCTL_EPWM14_AC_DMA1_ACC_M  0x30U        // DMA1 Access Conditions to
                                               // Peripheral

//*****************************************************************************
//
// The following are defines for the bit fields in the EPWM15_AC register
//
//*****************************************************************************
#define SYSCTL_EPWM15_AC_CPUX_ACC_S  0U
#define SYSCTL_EPWM15_AC_CPUX_ACC_M  0x3U         // CPUx Access conditions to
                                               // peripheral
#define SYSCTL_EPWM15_AC_CLA1_ACC_S  2U
#define SYSCTL_EPWM15_AC_CLA1_ACC_M  0xCU         // CLA1 Access Conditions to
                                               // Peripheral
#define SYSCTL_EPWM15_AC_DMA1_ACC_S  4U
#define SYSCTL_EPWM15_AC_DMA1_ACC_M  0x30U        // DMA1 Access Conditions to
                                               // Peripheral

//*****************************************************************************
//
// The following are defines for the bit fields in the EPWM16_AC register
//
//*****************************************************************************
#define SYSCTL_EPWM16_AC_CPUX_ACC_S  0U
#define SYSCTL_EPWM16_AC_CPUX_ACC_M  0x3U         // CPUx Access conditions to
                                               // peripheral
#define SYSCTL_EPWM16_AC_CLA1_ACC_S  2U
#define SYSCTL_EPWM16_AC_CLA1_ACC_M  0xCU         // CLA1 Access Conditions to
                                               // Peripheral
#define SYSCTL_EPWM16_AC_DMA1_ACC_S  4U
#define SYSCTL_EPWM16_AC_DMA1_ACC_M  0x30U        // DMA1 Access Conditions to
                                               // Peripheral

//*****************************************************************************
//
// The following are defines for the bit fields in the EQEP1_AC register
//
//*****************************************************************************
#define SYSCTL_EQEP1_AC_CPUX_ACC_S  0U
#define SYSCTL_EQEP1_AC_CPUX_ACC_M  0x3U         // CPUx Access conditions to
                                               // peripheral
#define SYSCTL_EQEP1_AC_CLA1_ACC_S  2U
#define SYSCTL_EQEP1_AC_CLA1_ACC_M  0xCU         // CLA1 Access Conditions to
                                               // Peripheral
#define SYSCTL_EQEP1_AC_DMA1_ACC_S  4U
#define SYSCTL_EQEP1_AC_DMA1_ACC_M  0x30U        // DMA1 Access Conditions to
                                               // Peripheral

//*****************************************************************************
//
// The following are defines for the bit fields in the EQEP2_AC register
//
//*****************************************************************************
#define SYSCTL_EQEP2_AC_CPUX_ACC_S  0U
#define SYSCTL_EQEP2_AC_CPUX_ACC_M  0x3U         // CPUx Access conditions to
                                               // peripheral
#define SYSCTL_EQEP2_AC_CLA1_ACC_S  2U
#define SYSCTL_EQEP2_AC_CLA1_ACC_M  0xCU         // CLA1 Access Conditions to
                                               // Peripheral
#define SYSCTL_EQEP2_AC_DMA1_ACC_S  4U
#define SYSCTL_EQEP2_AC_DMA1_ACC_M  0x30U        // DMA1 Access Conditions to
                                               // Peripheral

//*****************************************************************************
//
// The following are defines for the bit fields in the EQEP3_AC register
//
//*****************************************************************************
#define SYSCTL_EQEP3_AC_CPUX_ACC_S  0U
#define SYSCTL_EQEP3_AC_CPUX_ACC_M  0x3U         // CPUx Access conditions to
                                               // peripheral
#define SYSCTL_EQEP3_AC_CLA1_ACC_S  2U
#define SYSCTL_EQEP3_AC_CLA1_ACC_M  0xCU         // CLA1 Access Conditions to
                                               // Peripheral
#define SYSCTL_EQEP3_AC_DMA1_ACC_S  4U
#define SYSCTL_EQEP3_AC_DMA1_ACC_M  0x30U        // DMA1 Access Conditions to
                                               // Peripheral

//*****************************************************************************
//
// The following are defines for the bit fields in the ECAP1_AC register
//
//*****************************************************************************
#define SYSCTL_ECAP1_AC_CPUX_ACC_S  0U
#define SYSCTL_ECAP1_AC_CPUX_ACC_M  0x3U         // CPUx Access conditions to
                                               // peripheral
#define SYSCTL_ECAP1_AC_CLA1_ACC_S  2U
#define SYSCTL_ECAP1_AC_CLA1_ACC_M  0xCU         // CLA1 Access Conditions to
                                               // Peripheral
#define SYSCTL_ECAP1_AC_DMA1_ACC_S  4U
#define SYSCTL_ECAP1_AC_DMA1_ACC_M  0x30U        // DMA1 Access Conditions to
                                               // Peripheral

//*****************************************************************************
//
// The following are defines for the bit fields in the ECAP2_AC register
//
//*****************************************************************************
#define SYSCTL_ECAP2_AC_CPUX_ACC_S  0U
#define SYSCTL_ECAP2_AC_CPUX_ACC_M  0x3U         // CPUx Access conditions to
                                               // peripheral
#define SYSCTL_ECAP2_AC_CLA1_ACC_S  2U
#define SYSCTL_ECAP2_AC_CLA1_ACC_M  0xCU         // CLA1 Access Conditions to
                                               // Peripheral
#define SYSCTL_ECAP2_AC_DMA1_ACC_S  4U
#define SYSCTL_ECAP2_AC_DMA1_ACC_M  0x30U        // DMA1 Access Conditions to
                                               // Peripheral

//*****************************************************************************
//
// The following are defines for the bit fields in the ECAP3_AC register
//
//*****************************************************************************
#define SYSCTL_ECAP3_AC_CPUX_ACC_S  0U
#define SYSCTL_ECAP3_AC_CPUX_ACC_M  0x3U         // CPUx Access conditions to
                                               // peripheral
#define SYSCTL_ECAP3_AC_CLA1_ACC_S  2U
#define SYSCTL_ECAP3_AC_CLA1_ACC_M  0xCU         // CLA1 Access Conditions to
                                               // Peripheral
#define SYSCTL_ECAP3_AC_DMA1_ACC_S  4U
#define SYSCTL_ECAP3_AC_DMA1_ACC_M  0x30U        // DMA1 Access Conditions to
                                               // Peripheral

//*****************************************************************************
//
// The following are defines for the bit fields in the ECAP4_AC register
//
//*****************************************************************************
#define SYSCTL_ECAP4_AC_CPUX_ACC_S  0U
#define SYSCTL_ECAP4_AC_CPUX_ACC_M  0x3U         // CPUx Access conditions to
                                               // peripheral
#define SYSCTL_ECAP4_AC_CLA1_ACC_S  2U
#define SYSCTL_ECAP4_AC_CLA1_ACC_M  0xCU         // CLA1 Access Conditions to
                                               // Peripheral
#define SYSCTL_ECAP4_AC_DMA1_ACC_S  4U
#define SYSCTL_ECAP4_AC_DMA1_ACC_M  0x30U        // DMA1 Access Conditions to
                                               // Peripheral

//*****************************************************************************
//
// The following are defines for the bit fields in the ECAP5_AC register
//
//*****************************************************************************
#define SYSCTL_ECAP5_AC_CPUX_ACC_S  0U
#define SYSCTL_ECAP5_AC_CPUX_ACC_M  0x3U         // CPUx Access conditions to
                                               // peripheral
#define SYSCTL_ECAP5_AC_CLA1_ACC_S  2U
#define SYSCTL_ECAP5_AC_CLA1_ACC_M  0xCU         // CLA1 Access Conditions to
                                               // Peripheral
#define SYSCTL_ECAP5_AC_DMA1_ACC_S  4U
#define SYSCTL_ECAP5_AC_DMA1_ACC_M  0x30U        // DMA1 Access Conditions to
                                               // Peripheral

//*****************************************************************************
//
// The following are defines for the bit fields in the ECAP6_AC register
//
//*****************************************************************************
#define SYSCTL_ECAP6_AC_CPUX_ACC_S  0U
#define SYSCTL_ECAP6_AC_CPUX_ACC_M  0x3U         // CPUx Access conditions to
                                               // peripheral
#define SYSCTL_ECAP6_AC_CLA1_ACC_S  2U
#define SYSCTL_ECAP6_AC_CLA1_ACC_M  0xCU         // CLA1 Access Conditions to
                                               // Peripheral
#define SYSCTL_ECAP6_AC_DMA1_ACC_S  4U
#define SYSCTL_ECAP6_AC_DMA1_ACC_M  0x30U        // DMA1 Access Conditions to
                                               // Peripheral

//*****************************************************************************
//
// The following are defines for the bit fields in the ECAP7_AC register
//
//*****************************************************************************
#define SYSCTL_ECAP7_AC_CPUX_ACC_S  0U
#define SYSCTL_ECAP7_AC_CPUX_ACC_M  0x3U         // CPUx Access conditions to
                                               // peripheral
#define SYSCTL_ECAP7_AC_CLA1_ACC_S  2U
#define SYSCTL_ECAP7_AC_CLA1_ACC_M  0xCU         // CLA1 Access Conditions to
                                               // Peripheral
#define SYSCTL_ECAP7_AC_DMA1_ACC_S  4U
#define SYSCTL_ECAP7_AC_DMA1_ACC_M  0x30U        // DMA1 Access Conditions to
                                               // Peripheral

//*****************************************************************************
//
// The following are defines for the bit fields in the SDFM1_AC register
//
//*****************************************************************************
#define SYSCTL_SDFM1_AC_CPUX_ACC_S  0U
#define SYSCTL_SDFM1_AC_CPUX_ACC_M  0x3U         // CPUx Access conditions to
                                               // peripheral
#define SYSCTL_SDFM1_AC_CLA1_ACC_S  2U
#define SYSCTL_SDFM1_AC_CLA1_ACC_M  0xCU         // CLA1 Access Conditions to
                                               // Peripheral
#define SYSCTL_SDFM1_AC_DMA1_ACC_S  4U
#define SYSCTL_SDFM1_AC_DMA1_ACC_M  0x30U        // DMA1 Access Conditions to
                                               // Peripheral

//*****************************************************************************
//
// The following are defines for the bit fields in the SDFM2_AC register
//
//*****************************************************************************
#define SYSCTL_SDFM2_AC_CPUX_ACC_S  0U
#define SYSCTL_SDFM2_AC_CPUX_ACC_M  0x3U         // CPUx Access conditions to
                                               // peripheral
#define SYSCTL_SDFM2_AC_CLA1_ACC_S  2U
#define SYSCTL_SDFM2_AC_CLA1_ACC_M  0xCU         // CLA1 Access Conditions to
                                               // Peripheral
#define SYSCTL_SDFM2_AC_DMA1_ACC_S  4U
#define SYSCTL_SDFM2_AC_DMA1_ACC_M  0x30U        // DMA1 Access Conditions to
                                               // Peripheral

//*****************************************************************************
//
// The following are defines for the bit fields in the CLB1_AC register
//
//*****************************************************************************
#define SYSCTL_CLB1_AC_CPUX_ACC_S  0U
#define SYSCTL_CLB1_AC_CPUX_ACC_M  0x3U         // CPUx Access conditions to
                                               // peripheral
#define SYSCTL_CLB1_AC_CLA1_ACC_S  2U
#define SYSCTL_CLB1_AC_CLA1_ACC_M  0xCU         // CLA1 Access Conditions to
                                               // Peripheral

//*****************************************************************************
//
// The following are defines for the bit fields in the CLB2_AC register
//
//*****************************************************************************
#define SYSCTL_CLB2_AC_CPUX_ACC_S  0U
#define SYSCTL_CLB2_AC_CPUX_ACC_M  0x3U         // CPUx Access conditions to
                                               // peripheral
#define SYSCTL_CLB2_AC_CLA1_ACC_S  2U
#define SYSCTL_CLB2_AC_CLA1_ACC_M  0xCU         // CLA1 Access Conditions to
                                               // Peripheral

//*****************************************************************************
//
// The following are defines for the bit fields in the CLB3_AC register
//
//*****************************************************************************
#define SYSCTL_CLB3_AC_CPUX_ACC_S  0U
#define SYSCTL_CLB3_AC_CPUX_ACC_M  0x3U         // CPUx Access conditions to
                                               // peripheral
#define SYSCTL_CLB3_AC_CLA1_ACC_S  2U
#define SYSCTL_CLB3_AC_CLA1_ACC_M  0xCU         // CLA1 Access Conditions to
                                               // Peripheral

//*****************************************************************************
//
// The following are defines for the bit fields in the CLB4_AC register
//
//*****************************************************************************
#define SYSCTL_CLB4_AC_CPUX_ACC_S  0U
#define SYSCTL_CLB4_AC_CPUX_ACC_M  0x3U         // CPUx Access conditions to
                                               // peripheral
#define SYSCTL_CLB4_AC_CLA1_ACC_S  2U
#define SYSCTL_CLB4_AC_CLA1_ACC_M  0xCU         // CLA1 Access Conditions to
                                               // Peripheral

//*****************************************************************************
//
// The following are defines for the bit fields in the CLB5_AC register
//
//*****************************************************************************
#define SYSCTL_CLB5_AC_CPUX_ACC_S  0U
#define SYSCTL_CLB5_AC_CPUX_ACC_M  0x3U         // CPUx Access conditions to
                                               // peripheral
#define SYSCTL_CLB5_AC_CLA1_ACC_S  2U
#define SYSCTL_CLB5_AC_CLA1_ACC_M  0xCU         // CLA1 Access Conditions to
                                               // Peripheral

//*****************************************************************************
//
// The following are defines for the bit fields in the CLB6_AC register
//
//*****************************************************************************
#define SYSCTL_CLB6_AC_CPUX_ACC_S  0U
#define SYSCTL_CLB6_AC_CPUX_ACC_M  0x3U         // CPUx Access conditions to
                                               // peripheral
#define SYSCTL_CLB6_AC_CLA1_ACC_S  2U
#define SYSCTL_CLB6_AC_CLA1_ACC_M  0xCU         // CLA1 Access Conditions to
                                               // Peripheral

//*****************************************************************************
//
// The following are defines for the bit fields in the CLB7_AC register
//
//*****************************************************************************
#define SYSCTL_CLB7_AC_CPUX_ACC_S  0U
#define SYSCTL_CLB7_AC_CPUX_ACC_M  0x3U         // CPUx Access conditions to
                                               // peripheral
#define SYSCTL_CLB7_AC_CLA1_ACC_S  2U
#define SYSCTL_CLB7_AC_CLA1_ACC_M  0xCU         // CLA1 Access Conditions to
                                               // Peripheral

//*****************************************************************************
//
// The following are defines for the bit fields in the CLB8_AC register
//
//*****************************************************************************
#define SYSCTL_CLB8_AC_CPUX_ACC_S  0U
#define SYSCTL_CLB8_AC_CPUX_ACC_M  0x3U         // CPUx Access conditions to
                                               // peripheral
#define SYSCTL_CLB8_AC_CLA1_ACC_S  2U
#define SYSCTL_CLB8_AC_CLA1_ACC_M  0xCU         // CLA1 Access Conditions to
                                               // Peripheral

//*****************************************************************************
//
// The following are defines for the bit fields in the SPIA_AC register
//
//*****************************************************************************
#define SYSCTL_SPIA_AC_CPUX_ACC_S  0U
#define SYSCTL_SPIA_AC_CPUX_ACC_M  0x3U         // CPUx Access conditions to
                                               // peripheral
#define SYSCTL_SPIA_AC_CLA1_ACC_S  2U
#define SYSCTL_SPIA_AC_CLA1_ACC_M  0xCU         // CLA1 Access Conditions to
                                               // Peripheral
#define SYSCTL_SPIA_AC_DMA1_ACC_S  4U
#define SYSCTL_SPIA_AC_DMA1_ACC_M  0x30U        // DMA1 Access Conditions to
                                               // Peripheral

//*****************************************************************************
//
// The following are defines for the bit fields in the SPIB_AC register
//
//*****************************************************************************
#define SYSCTL_SPIB_AC_CPUX_ACC_S  0U
#define SYSCTL_SPIB_AC_CPUX_ACC_M  0x3U         // CPUx Access conditions to
                                               // peripheral
#define SYSCTL_SPIB_AC_CLA1_ACC_S  2U
#define SYSCTL_SPIB_AC_CLA1_ACC_M  0xCU         // CLA1 Access Conditions to
                                               // Peripheral
#define SYSCTL_SPIB_AC_DMA1_ACC_S  4U
#define SYSCTL_SPIB_AC_DMA1_ACC_M  0x30U        // DMA1 Access Conditions to
                                               // Peripheral

//*****************************************************************************
//
// The following are defines for the bit fields in the SPIC_AC register
//
//*****************************************************************************
#define SYSCTL_SPIC_AC_CPUX_ACC_S  0U
#define SYSCTL_SPIC_AC_CPUX_ACC_M  0x3U         // CPUx Access conditions to
                                               // peripheral
#define SYSCTL_SPIC_AC_CLA1_ACC_S  2U
#define SYSCTL_SPIC_AC_CLA1_ACC_M  0xCU         // CLA1 Access Conditions to
                                               // Peripheral
#define SYSCTL_SPIC_AC_DMA1_ACC_S  4U
#define SYSCTL_SPIC_AC_DMA1_ACC_M  0x30U        // DMA1 Access Conditions to
                                               // Peripheral

//*****************************************************************************
//
// The following are defines for the bit fields in the SPID_AC register
//
//*****************************************************************************
#define SYSCTL_SPID_AC_CPUX_ACC_S  0U
#define SYSCTL_SPID_AC_CPUX_ACC_M  0x3U         // CPUx Access conditions to
                                               // peripheral
#define SYSCTL_SPID_AC_CLA1_ACC_S  2U
#define SYSCTL_SPID_AC_CLA1_ACC_M  0xCU         // CLA1 Access Conditions to
                                               // Peripheral
#define SYSCTL_SPID_AC_DMA1_ACC_S  4U
#define SYSCTL_SPID_AC_DMA1_ACC_M  0x30U        // DMA1 Access Conditions to
                                               // Peripheral

//*****************************************************************************
//
// The following are defines for the bit fields in the PMBUS_A_AC register
//
//*****************************************************************************
#define SYSCTL_PMBUS_A_AC_CPUX_ACC_S  0U
#define SYSCTL_PMBUS_A_AC_CPUX_ACC_M  0x3U         // CPUx Access conditions to
                                               // peripheral
#define SYSCTL_PMBUS_A_AC_CLA1_ACC_S  2U
#define SYSCTL_PMBUS_A_AC_CLA1_ACC_M  0xCU         // CLA1 Access Conditions to
                                               // Peripheral
#define SYSCTL_PMBUS_A_AC_DMA1_ACC_S  4U
#define SYSCTL_PMBUS_A_AC_DMA1_ACC_M  0x30U        // DMA1 Access Conditions to
                                               // Peripheral

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_A_AC register
//
//*****************************************************************************
#define SYSCTL_CAN_A_AC_CPUX_ACC_S  0U
#define SYSCTL_CAN_A_AC_CPUX_ACC_M  0x3U         // CPUx Access conditions to
                                               // peripheral
#define SYSCTL_CAN_A_AC_DMA1_ACC_S  4U
#define SYSCTL_CAN_A_AC_DMA1_ACC_M  0x30U        // DMA1 Access Conditions to
                                               // Peripheral

//*****************************************************************************
//
// The following are defines for the bit fields in the CAN_B_AC register
//
//*****************************************************************************
#define SYSCTL_CAN_B_AC_CPUX_ACC_S  0U
#define SYSCTL_CAN_B_AC_CPUX_ACC_M  0x3U         // CPUx Access conditions to
                                               // peripheral
#define SYSCTL_CAN_B_AC_DMA1_ACC_S  4U
#define SYSCTL_CAN_B_AC_DMA1_ACC_M  0x30U        // DMA1 Access Conditions to
                                               // Peripheral

//*****************************************************************************
//
// The following are defines for the bit fields in the MCBSPA_AC register
//
//*****************************************************************************
#define SYSCTL_MCBSPA_AC_CPUX_ACC_S  0U
#define SYSCTL_MCBSPA_AC_CPUX_ACC_M  0x3U         // CPUx Access conditions to
                                               // peripheral
#define SYSCTL_MCBSPA_AC_CLA1_ACC_S  2U
#define SYSCTL_MCBSPA_AC_CLA1_ACC_M  0xCU         // CLA1 Access Conditions to
                                               // Peripheral
#define SYSCTL_MCBSPA_AC_DMA1_ACC_S  4U
#define SYSCTL_MCBSPA_AC_DMA1_ACC_M  0x30U        // DMA1 Access Conditions to
                                               // Peripheral

//*****************************************************************************
//
// The following are defines for the bit fields in the MCBSPB_AC register
//
//*****************************************************************************
#define SYSCTL_MCBSPB_AC_CPUX_ACC_S  0U
#define SYSCTL_MCBSPB_AC_CPUX_ACC_M  0x3U         // CPUx Access conditions to
                                               // peripheral
#define SYSCTL_MCBSPB_AC_CLA1_ACC_S  2U
#define SYSCTL_MCBSPB_AC_CLA1_ACC_M  0xCU         // CLA1 Access Conditions to
                                               // Peripheral
#define SYSCTL_MCBSPB_AC_DMA1_ACC_S  4U
#define SYSCTL_MCBSPB_AC_DMA1_ACC_M  0x30U        // DMA1 Access Conditions to
                                               // Peripheral

//*****************************************************************************
//
// The following are defines for the bit fields in the USBA_AC register
//
//*****************************************************************************
#define SYSCTL_USBA_AC_CPUX_ACC_S  0U
#define SYSCTL_USBA_AC_CPUX_ACC_M  0x3U         // CPUx Access conditions to
                                               // peripheral
#define SYSCTL_USBA_AC_DMA1_ACC_S  4U
#define SYSCTL_USBA_AC_DMA1_ACC_M  0x30U        // DMA1 Access Conditions to
                                               // Peripheral

//*****************************************************************************
//
// The following are defines for the bit fields in the HRPWM_AC register
//
//*****************************************************************************
#define SYSCTL_HRPWM_AC_CPUX_ACC_S  0U
#define SYSCTL_HRPWM_AC_CPUX_ACC_M  0x3U         // CPUx Access conditions to
                                               // peripheral
#define SYSCTL_HRPWM_AC_CLA1_ACC_S  2U
#define SYSCTL_HRPWM_AC_CLA1_ACC_M  0xCU         // CLA1 Access Conditions to
                                               // Peripheral
#define SYSCTL_HRPWM_AC_DMA1_ACC_S  4U
#define SYSCTL_HRPWM_AC_DMA1_ACC_M  0x30U        // DMA1 Access Conditions to
                                               // Peripheral

//*****************************************************************************
//
// The following are defines for the bit fields in the ETHERCAT_AC register
//
//*****************************************************************************
#define SYSCTL_ETHERCAT_AC_CPU1_ACC_S  0U
#define SYSCTL_ETHERCAT_AC_CPU1_ACC_M  0x3U         // CPU1 Access conditions to
                                               // peripheral
#define SYSCTL_ETHERCAT_AC_DMA1_ACC_S  4U
#define SYSCTL_ETHERCAT_AC_DMA1_ACC_M  0x30U        // DMA1 Access Conditions to
                                               // Peripheral

//*****************************************************************************
//
// The following are defines for the bit fields in the FSIATX_AC register
//
//*****************************************************************************
#define SYSCTL_FSIATX_AC_CPUX_ACC_S  0U
#define SYSCTL_FSIATX_AC_CPUX_ACC_M  0x3U         // CPUx Access conditions to
                                               // peripheral
#define SYSCTL_FSIATX_AC_CLA1_ACC_S  2U
#define SYSCTL_FSIATX_AC_CLA1_ACC_M  0xCU         // CLA1 Access Conditions to
                                               // Peripheral
#define SYSCTL_FSIATX_AC_DMA1_ACC_S  4U
#define SYSCTL_FSIATX_AC_DMA1_ACC_M  0x30U        // DMA1 Access Conditions to
                                               // Peripheral

//*****************************************************************************
//
// The following are defines for the bit fields in the FSIARX_AC register
//
//*****************************************************************************
#define SYSCTL_FSIARX_AC_CPUX_ACC_S  0U
#define SYSCTL_FSIARX_AC_CPUX_ACC_M  0x3U         // CPUx Access conditions to
                                               // peripheral
#define SYSCTL_FSIARX_AC_CLA1_ACC_S  2U
#define SYSCTL_FSIARX_AC_CLA1_ACC_M  0xCU         // CLA1 Access Conditions to
                                               // Peripheral
#define SYSCTL_FSIARX_AC_DMA1_ACC_S  4U
#define SYSCTL_FSIARX_AC_DMA1_ACC_M  0x30U        // DMA1 Access Conditions to
                                               // Peripheral

//*****************************************************************************
//
// The following are defines for the bit fields in the FSIBTX_AC register
//
//*****************************************************************************
#define SYSCTL_FSIBTX_AC_CPUX_ACC_S  0U
#define SYSCTL_FSIBTX_AC_CPUX_ACC_M  0x3U         // CPUx Access conditions to
                                               // peripheral
#define SYSCTL_FSIBTX_AC_CLA1_ACC_S  2U
#define SYSCTL_FSIBTX_AC_CLA1_ACC_M  0xCU         // CLA1 Access Conditions to
                                               // Peripheral
#define SYSCTL_FSIBTX_AC_DMA1_ACC_S  4U
#define SYSCTL_FSIBTX_AC_DMA1_ACC_M  0x30U        // DMA1 Access Conditions to
                                               // Peripheral

//*****************************************************************************
//
// The following are defines for the bit fields in the FSIBRX_AC register
//
//*****************************************************************************
#define SYSCTL_FSIBRX_AC_CPUX_ACC_S  0U
#define SYSCTL_FSIBRX_AC_CPUX_ACC_M  0x3U         // CPUx Access conditions to
                                               // peripheral
#define SYSCTL_FSIBRX_AC_CLA1_ACC_S  2U
#define SYSCTL_FSIBRX_AC_CLA1_ACC_M  0xCU         // CLA1 Access Conditions to
                                               // Peripheral
#define SYSCTL_FSIBRX_AC_DMA1_ACC_S  4U
#define SYSCTL_FSIBRX_AC_DMA1_ACC_M  0x30U        // DMA1 Access Conditions to
                                               // Peripheral

//*****************************************************************************
//
// The following are defines for the bit fields in the FSICRX_AC register
//
//*****************************************************************************
#define SYSCTL_FSICRX_AC_CPUX_ACC_S  0U
#define SYSCTL_FSICRX_AC_CPUX_ACC_M  0x3U         // CPUx Access conditions to
                                               // peripheral
#define SYSCTL_FSICRX_AC_CLA1_ACC_S  2U
#define SYSCTL_FSICRX_AC_CLA1_ACC_M  0xCU         // CLA1 Access Conditions to
                                               // Peripheral
#define SYSCTL_FSICRX_AC_DMA1_ACC_S  4U
#define SYSCTL_FSICRX_AC_DMA1_ACC_M  0x30U        // DMA1 Access Conditions to
                                               // Peripheral

//*****************************************************************************
//
// The following are defines for the bit fields in the FSIDRX_AC register
//
//*****************************************************************************
#define SYSCTL_FSIDRX_AC_CPUX_ACC_S  0U
#define SYSCTL_FSIDRX_AC_CPUX_ACC_M  0x3U         // CPUx Access conditions to
                                               // peripheral
#define SYSCTL_FSIDRX_AC_CLA1_ACC_S  2U
#define SYSCTL_FSIDRX_AC_CLA1_ACC_M  0xCU         // CLA1 Access Conditions to
                                               // Peripheral
#define SYSCTL_FSIDRX_AC_DMA1_ACC_S  4U
#define SYSCTL_FSIDRX_AC_DMA1_ACC_M  0x30U        // DMA1 Access Conditions to
                                               // Peripheral

//*****************************************************************************
//
// The following are defines for the bit fields in the FSIERX_AC register
//
//*****************************************************************************
#define SYSCTL_FSIERX_AC_CPUX_ACC_S  0U
#define SYSCTL_FSIERX_AC_CPUX_ACC_M  0x3U         // CPUx Access conditions to
                                               // peripheral
#define SYSCTL_FSIERX_AC_CLA1_ACC_S  2U
#define SYSCTL_FSIERX_AC_CLA1_ACC_M  0xCU         // CLA1 Access Conditions to
                                               // Peripheral
#define SYSCTL_FSIERX_AC_DMA1_ACC_S  4U
#define SYSCTL_FSIERX_AC_DMA1_ACC_M  0x30U        // DMA1 Access Conditions to
                                               // Peripheral

//*****************************************************************************
//
// The following are defines for the bit fields in the FSIFRX_AC register
//
//*****************************************************************************
#define SYSCTL_FSIFRX_AC_CPUX_ACC_S  0U
#define SYSCTL_FSIFRX_AC_CPUX_ACC_M  0x3U         // CPUx Access conditions to
                                               // peripheral
#define SYSCTL_FSIFRX_AC_CLA1_ACC_S  2U
#define SYSCTL_FSIFRX_AC_CLA1_ACC_M  0xCU         // CLA1 Access Conditions to
                                               // Peripheral
#define SYSCTL_FSIFRX_AC_DMA1_ACC_S  4U
#define SYSCTL_FSIFRX_AC_DMA1_ACC_M  0x30U        // DMA1 Access Conditions to
                                               // Peripheral

//*****************************************************************************
//
// The following are defines for the bit fields in the FSIGRX_AC register
//
//*****************************************************************************
#define SYSCTL_FSIGRX_AC_CPUX_ACC_S  0U
#define SYSCTL_FSIGRX_AC_CPUX_ACC_M  0x3U         // CPUx Access conditions to
                                               // peripheral
#define SYSCTL_FSIGRX_AC_CLA1_ACC_S  2U
#define SYSCTL_FSIGRX_AC_CLA1_ACC_M  0xCU         // CLA1 Access Conditions to
                                               // Peripheral
#define SYSCTL_FSIGRX_AC_DMA1_ACC_S  4U
#define SYSCTL_FSIGRX_AC_DMA1_ACC_M  0x30U        // DMA1 Access Conditions to
                                               // Peripheral

//*****************************************************************************
//
// The following are defines for the bit fields in the FSIHRX_AC register
//
//*****************************************************************************
#define SYSCTL_FSIHRX_AC_CPUX_ACC_S  0U
#define SYSCTL_FSIHRX_AC_CPUX_ACC_M  0x3U         // CPUx Access conditions to
                                               // peripheral
#define SYSCTL_FSIHRX_AC_CLA1_ACC_S  2U
#define SYSCTL_FSIHRX_AC_CLA1_ACC_M  0xCU         // CLA1 Access Conditions to
                                               // Peripheral
#define SYSCTL_FSIHRX_AC_DMA1_ACC_S  4U
#define SYSCTL_FSIHRX_AC_DMA1_ACC_M  0x30U        // DMA1 Access Conditions to
                                               // Peripheral

//*****************************************************************************
//
// The following are defines for the bit fields in the PERIPH_AC_LOCK register
//
//*****************************************************************************
#define SYSCTL_PERIPH_AC_LOCK_LOCK_AC_WR  0x1U         // Lock control for Access
                                               // control registers write.

//*****************************************************************************
//
// The following are defines for the bit fields in the CMRESCTL register
//
//*****************************************************************************
#define SYSCTL_CMRESCTL_RESET     0x1U         // Software reset to CM
#define SYSCTL_CMRESCTL_RESETSTS  0x2U         // CM Reset status
#define SYSCTL_CMRESCTL_KEY_S     16U
#define SYSCTL_CMRESCTL_KEY_M     0xFFFF0000U  // Key value

//*****************************************************************************
//
// The following are defines for the bit fields in the CMTOCPU1NMICTL register
//
//*****************************************************************************
#define SYSCTL_CMTOCPU1NMICTL_CMNMIWDRST  0x4U         // CMNMIWDRST NMI enable bit,
                                               // enables nmi generation to C28x

//*****************************************************************************
//
// The following are defines for the bit fields in the CMTOCPU1INTCTL register
//
//*****************************************************************************
#define SYSCTL_CMTOCPU1INTCTL_VECTRESET  0x1U         // VECTRESET Interrupt enable
                                               // bit, enables interrupt to C28x
#define SYSCTL_CMTOCPU1INTCTL_SYSRESETREQ  0x2U         // SYSRESETREQ Interrupt enable
                                               // bit, enables interrupt to C28x
#define SYSCTL_CMTOCPU1INTCTL_CMNMIWDRST  0x4U         // CMNMIWDRST Interrupt enable
                                               // bit, enables interrupt to C28x

//*****************************************************************************
//
// The following are defines for the bit fields in the PALLOCATE0 register
//
//*****************************************************************************
#define SYSCTL_PALLOCATE0_USB_A   0x1U         // Allocate USB_A to CM
#define SYSCTL_PALLOCATE0_ETHERCAT  0x2U         // Allocate ETHERCAT to CM
#define SYSCTL_PALLOCATE0_CAN_A   0x4U         // Allocate CANA to CM
#define SYSCTL_PALLOCATE0_CAN_B   0x8U         // Allocate CANB to CM
#define SYSCTL_PALLOCATE0_MCAN_A  0x10U        // Allocate MCANA to CM

//*****************************************************************************
//
// The following are defines for the bit fields in the CM_CONF_REGS_LOCK register
//
//*****************************************************************************
#define SYSCTL_CM_CONF_REGS_LOCK_LOCK  0x1U         // Lock one time CM
                                               // configuration registers.

//*****************************************************************************
//
// The following are defines for the bit fields in the CM_STATUS_INT_FLG register
//
//*****************************************************************************
#define SYSCTL_CM_STATUS_INT_FLG_GINT  0x1U         // Global Interrupt flag
#define SYSCTL_CM_STATUS_INT_FLG_CMNMIWDRST  0x2U         // CMNMIWDRST caused a reset of
                                               // CM
#define SYSCTL_CM_STATUS_INT_FLG_CMSYSRESETREQ  0x4U         // CMSYSRESETREQ caused a reset
                                               // of CM
#define SYSCTL_CM_STATUS_INT_FLG_CMVECTRESET  0x8U         // CMVECTRESET caused a reset of
                                               // CM

//*****************************************************************************
//
// The following are defines for the bit fields in the CM_STATUS_INT_CLR register
//
//*****************************************************************************
#define SYSCTL_CM_STATUS_INT_CLR_GINT  0x1U         // Global Interrupt flag Clear
                                               // bit
#define SYSCTL_CM_STATUS_INT_CLR_CMNMIWDRST  0x2U         // CMNMIWDRST interrupt flag
                                               // clear bit
#define SYSCTL_CM_STATUS_INT_CLR_CMSYSRESETREQ  0x4U         // CMSYSRESETREQ interrupt flag
                                               // clear bit
#define SYSCTL_CM_STATUS_INT_CLR_CMVECTRESET  0x8U         // CMVECTRESET interrupt flag
                                               // clear bit

//*****************************************************************************
//
// The following are defines for the bit fields in the CM_STATUS_INT_SET register
//
//*****************************************************************************
#define SYSCTL_CM_STATUS_INT_SET_CMNMIWDRST  0x2U         // CMNMIWDRST interrupt flag set
                                               // bit
#define SYSCTL_CM_STATUS_INT_SET_CMSYSRESETREQ  0x4U         // CMSYSRESETREQ interrupt flag
                                               // set bit
#define SYSCTL_CM_STATUS_INT_SET_CMVECTRESET  0x8U         // CMVECTRESET interrupt flag
                                               // set bit
#define SYSCTL_CM_STATUS_INT_SET_KEY_S  16U
#define SYSCTL_CM_STATUS_INT_SET_KEY_M  0xFFFF0000U  // KEY field

//*****************************************************************************
//
// The following are defines for the bit fields in the CM_STATUS_MASK register
//
//*****************************************************************************
#define SYSCTL_CM_STATUS_MASK_CMNMIWDRST  0x2U         // CMNMIWDRST flag mask bit
#define SYSCTL_CM_STATUS_MASK_CMSYSRESETREQ  0x4U         // CMSYSRESETREQ interrupt flag
                                               // set bit
#define SYSCTL_CM_STATUS_MASK_CMVECTRESET  0x8U         // CMVECTRESET interrupt flag
                                               // set bit
#define SYSCTL_CM_STATUS_MASK_KEY_S  16U
#define SYSCTL_CM_STATUS_MASK_KEY_M  0xFFFF0000U  // KEY field

//*****************************************************************************
//
// The following are defines for the bit fields in the SYS_ERR_INT_FLG register
//
//*****************************************************************************
#define SYSCTL_SYS_ERR_INT_FLG_GINT  0x1U         // Global Interrupt flag
#define SYSCTL_SYS_ERR_INT_FLG_EMIF_ERR  0x2U         // EMIF error event flag
#define SYSCTL_SYS_ERR_INT_FLG_RAM_CORRECTABLE_ERR  0x4U         // RAM correctable error flag
#define SYSCTL_SYS_ERR_INT_FLG_FLASH_CORRECTABLE_ERR  0x8U         // FLASH correctable error flag
#define SYSCTL_SYS_ERR_INT_FLG_RAM_ACC_VIOL  0x10U        // A RAM access vioation flag.
#define SYSCTL_SYS_ERR_INT_FLG_SYS_PLL_SLIP  0x20U        // System PLL Slip event flag.
#define SYSCTL_SYS_ERR_INT_FLG_AUX_PLL_SLIP  0x40U        // Auxillary PLL Slip event
                                               // flag.
#define SYSCTL_SYS_ERR_INT_FLG_DCC0  0x80U        // DCC0 Interrupt flag.
#define SYSCTL_SYS_ERR_INT_FLG_DCC1  0x100U       // DCC1 Interrupt flag.
#define SYSCTL_SYS_ERR_INT_FLG_DCC2  0x200U       // DCC2 Interrupt flag.

//*****************************************************************************
//
// The following are defines for the bit fields in the SYS_ERR_INT_CLR register
//
//*****************************************************************************
#define SYSCTL_SYS_ERR_INT_CLR_GINT  0x1U         // Global Interrupt flag Clear
                                               // bit
#define SYSCTL_SYS_ERR_INT_CLR_EMIF_ERR  0x2U         // EMIF_ERR interrupt flag clear
                                               // bit
#define SYSCTL_SYS_ERR_INT_CLR_RAM_CORRECTABLE_ERR  0x4U         // RAM_CORRECTABLE_ERR interrupt
                                               // flag clear bit
#define SYSCTL_SYS_ERR_INT_CLR_FLASH_CORRECTABLE_ERR  0x8U         // FLASH_CORRECTABLE_ERR
                                               // interrupt flag clear bit
#define SYSCTL_SYS_ERR_INT_CLR_RAM_ACC_VIOL  0x10U        // RAM_ACC_VIOL interrupt flag
                                               // clear bit
#define SYSCTL_SYS_ERR_INT_CLR_SYS_PLL_SLIP  0x20U        // SYS_PLL_SLIP interrupt flag
                                               // clear bit
#define SYSCTL_SYS_ERR_INT_CLR_AUX_PLL_SLIP  0x40U        // AUX_PLL_SLIP interrupt flag
                                               // clear bit
#define SYSCTL_SYS_ERR_INT_CLR_DCC0  0x80U        // DCC0 interrupt flag clear bit
#define SYSCTL_SYS_ERR_INT_CLR_DCC1  0x100U       // DCC1 interrupt flag clear bit
#define SYSCTL_SYS_ERR_INT_CLR_DCC2  0x200U       // DCC2 interrupt flag clear bit

//*****************************************************************************
//
// The following are defines for the bit fields in the SYS_ERR_INT_SET register
//
//*****************************************************************************
#define SYSCTL_SYS_ERR_INT_SET_EMIF_ERR  0x2U         // Reserved
#define SYSCTL_SYS_ERR_INT_SET_RAM_CORRECTABLE_ERR  0x4U         // RAM_CORRECTABLE_ERR interrupt
                                               // flag set bit
#define SYSCTL_SYS_ERR_INT_SET_FLASH_CORRECTABLE_ERR  0x8U         // FLASH_CORRECTABLE_ERR
                                               // interrupt flag set bit
#define SYSCTL_SYS_ERR_INT_SET_RAM_ACC_VIOL  0x10U        // RAM_ACC_VIOL interrupt flag
                                               // set bit
#define SYSCTL_SYS_ERR_INT_SET_SYS_PLL_SLIP  0x20U        // SYS_PLL_SLIP interrupt flag
                                               // set bit
#define SYSCTL_SYS_ERR_INT_SET_AUX_PLL_SLIP  0x40U        // AUX_PLL_SLIP interrupt flag
                                               // set bit
#define SYSCTL_SYS_ERR_INT_SET_DCC0  0x80U        // DCC0 interrupt flag set bit
#define SYSCTL_SYS_ERR_INT_SET_DCC1  0x100U       // DCC1 interrupt flag set bit
#define SYSCTL_SYS_ERR_INT_SET_DCC2  0x200U       // DCC2 interrupt flag set bit
#define SYSCTL_SYS_ERR_INT_SET_KEY_S  16U
#define SYSCTL_SYS_ERR_INT_SET_KEY_M  0xFFFF0000U  // KEY field

//*****************************************************************************
//
// The following are defines for the bit fields in the SYS_ERR_MASK register
//
//*****************************************************************************
#define SYSCTL_SYS_ERR_MASK_EMIF_ERR  0x2U         // Reserved
#define SYSCTL_SYS_ERR_MASK_RAM_CORRECTABLE_ERR  0x4U         // RAM_CORRECTABLE_ERR flag mask
                                               // bit
#define SYSCTL_SYS_ERR_MASK_FLASH_CORRECTABLE_ERR  0x8U         // FLASH_CORRECTABLE_ERR flag
                                               // mask bit
#define SYSCTL_SYS_ERR_MASK_RAM_ACC_VIOL  0x10U        // RAM_ACC_VIOL flag mask bit
#define SYSCTL_SYS_ERR_MASK_SYS_PLL_SLIP  0x20U        // SYS_PLL_SLIP flag mask bit
#define SYSCTL_SYS_ERR_MASK_AUX_PLL_SLIP  0x40U        // AUX_PLL_SLIP flag mask bit
#define SYSCTL_SYS_ERR_MASK_DCC0  0x80U        // DCC0 flag mask bit
#define SYSCTL_SYS_ERR_MASK_DCC1  0x100U       // DCC1 flag mask bit
#define SYSCTL_SYS_ERR_MASK_DCC2  0x200U       // DCC2 flag mask bit
#define SYSCTL_SYS_ERR_MASK_KEY_S  16U
#define SYSCTL_SYS_ERR_MASK_KEY_M  0xFFFF0000U  // KEY field

//*****************************************************************************
//
// The following are defines for the bit fields in the VMTSEL register
//
//*****************************************************************************
#define SYSCTL_VMTSEL_ENABLE      0x1U         // VMT Mode Enable
#define SYSCTL_VMTSEL_MODESEL_S   1U
#define SYSCTL_VMTSEL_MODESEL_M   0xEU         // VMT Mode Select
#define SYSCTL_VMTSEL_KEY_S       16U
#define SYSCTL_VMTSEL_KEY_M       0xFFFF0000U  // KEY field

//*****************************************************************************
//
// The following are defines for the bit fields in the VMTSIGEN register
//
//*****************************************************************************
#define SYSCTL_VMTSIGEN_VMTSIG0EN  0x1U         // VMTSIG0 Enable bit
#define SYSCTL_VMTSIGEN_VMTSIG1EN  0x2U         // VMTSIG1 Enable bit
#define SYSCTL_VMTSIGEN_VMTSIG2EN  0x4U         // VMTSIG2 Enable bit
#define SYSCTL_VMTSIGEN_VMTSIG3EN  0x8U         // VMTSIG3 Enable bit
#define SYSCTL_VMTSIGEN_VMTSIG4EN  0x10U        // VMTSIG4 Enable bit
#define SYSCTL_VMTSIGEN_VMTSIG5EN  0x20U        // VMTSIG5 Enable bit
#define SYSCTL_VMTSIGEN_VMTSIG6EN  0x40U        // VMTSIG6 Enable bit
#define SYSCTL_VMTSIGEN_VMTSIG7EN  0x80U        // VMTSIG7 Enable bit
#define SYSCTL_VMTSIGEN_VMTSIG8EN  0x100U       // VMTSIG8 Enable bit
#define SYSCTL_VMTSIGEN_VMTSIG9EN  0x200U       // VMTSIG9 Enable bit
#define SYSCTL_VMTSIGEN_VMTSIG10EN  0x400U       // VMTSIG10 Enable bit
#define SYSCTL_VMTSIGEN_VMTSIG11EN  0x800U       // VMTSIG11 Enable bit
#define SYSCTL_VMTSIGEN_VMTSIG12EN  0x1000U      // VMTSIG12 Enable bit
#define SYSCTL_VMTSIGEN_VMTSIG13EN  0x2000U      // VMTSIG13 Enable bit
#define SYSCTL_VMTSIGEN_VMTSIG14EN  0x4000U      // VMTSIG14 Enable bit
#define SYSCTL_VMTSIGEN_VMTSIG15EN  0x8000U      // VMTSIG15 Enable bit
#define SYSCTL_VMTSIGEN_VMTSIG16EN  0x10000U     // VMTSIG16 Enable bit
#define SYSCTL_VMTSIGEN_VMTSIG17EN  0x20000U     // VMTSIG17 Enable bit
#define SYSCTL_VMTSIGEN_VMTSIG18EN  0x40000U     // VMTSIG18 Enable bit
#define SYSCTL_VMTSIGEN_VMTSIG19EN  0x80000U     // VMTSIG19 Enable bit
#define SYSCTL_VMTSIGEN_VMTSIG20EN  0x100000U    // VMTSIG20 Enable bit
#define SYSCTL_VMTSIGEN_VMTSIG21EN  0x200000U    // VMTSIG21 Enable bit
#define SYSCTL_VMTSIGEN_VMTSIG22EN  0x400000U    // VMTSIG22 Enable bit
#define SYSCTL_VMTSIGEN_VMTSIG23EN  0x800000U    // VMTSIG23 Enable bit
#define SYSCTL_VMTSIGEN_VMTSIG24EN  0x1000000U   // VMTSIG24 Enable bit
#define SYSCTL_VMTSIGEN_VMTSIG25EN  0x2000000U   // VMTSIG25 Enable bit
#define SYSCTL_VMTSIGEN_VMTSIG26EN  0x4000000U   // VMTSIG26 Enable bit
#define SYSCTL_VMTSIGEN_VMTSIG27EN  0x8000000U   // VMTSIG27 Enable bit
#define SYSCTL_VMTSIGEN_VMTSIG28EN  0x10000000U  // VMTSIG28 Enable bit
#define SYSCTL_VMTSIGEN_VMTSIG29EN  0x20000000U  // VMTSIG29 Enable bit
#define SYSCTL_VMTSIGEN_VMTSIG30EN  0x40000000U  // VMTSIG30 Enable bit
#define SYSCTL_VMTSIGEN_VMTSIG31EN  0x80000000U  // VMTSIG31 Enable bit

//*****************************************************************************
//
// The following are defines for the bit fields in the ECAPTESTMUX0 register
//
//*****************************************************************************
#define SYSCTL_ECAPTESTMUX0_ECAP1TESTMUXSEL_S  0U
#define SYSCTL_ECAPTESTMUX0_ECAP1TESTMUXSEL_M  0x1FU        // ECAP1TESTMUX Select
#define SYSCTL_ECAPTESTMUX0_ECAP2TESTMUXSEL_S  5U
#define SYSCTL_ECAPTESTMUX0_ECAP2TESTMUXSEL_M  0x3E0U       // ECAP2TESTMUX Select
#define SYSCTL_ECAPTESTMUX0_ECAP3TESTMUXSEL_S  10U
#define SYSCTL_ECAPTESTMUX0_ECAP3TESTMUXSEL_M  0x7C00U      // ECAP3TESTMUX Select
#define SYSCTL_ECAPTESTMUX0_KEY_S  16U
#define SYSCTL_ECAPTESTMUX0_KEY_M  0xFFFF0000U  // KEY field

//*****************************************************************************
//
// The following are defines for the bit fields in the ECAPTESTMUX1 register
//
//*****************************************************************************
#define SYSCTL_ECAPTESTMUX1_ECAP4TESTMUXSEL_S  0U
#define SYSCTL_ECAPTESTMUX1_ECAP4TESTMUXSEL_M  0x1FU        // ECAP4TESTMUX Select
#define SYSCTL_ECAPTESTMUX1_ECAP5TESTMUXSEL_S  5U
#define SYSCTL_ECAPTESTMUX1_ECAP5TESTMUXSEL_M  0x3E0U       // ECAP5TESTMUX Select
#define SYSCTL_ECAPTESTMUX1_ECAP6TESTMUXSEL_S  10U
#define SYSCTL_ECAPTESTMUX1_ECAP6TESTMUXSEL_M  0x7C00U      // ECAP6TESTMUX Select
#define SYSCTL_ECAPTESTMUX1_KEY_S  16U
#define SYSCTL_ECAPTESTMUX1_KEY_M  0xFFFF0000U  // KEY field

//*****************************************************************************
//
// The following are defines for the bit fields in the ECAPTESTMUX2 register
//
//*****************************************************************************
#define SYSCTL_ECAPTESTMUX2_ECAP7TESTMUXSEL_S  0U
#define SYSCTL_ECAPTESTMUX2_ECAP7TESTMUXSEL_M  0x1FU        // ECAP7TESTMUX Select
#define SYSCTL_ECAPTESTMUX2_ECAP8TESTMUXSEL_S  5U
#define SYSCTL_ECAPTESTMUX2_ECAP8TESTMUXSEL_M  0x3E0U       // ECAP8TESTMUX Select
#define SYSCTL_ECAPTESTMUX2_KEY_S  16U
#define SYSCTL_ECAPTESTMUX2_KEY_M  0xFFFF0000U  // KEY field

//*****************************************************************************
//
// The following are defines for the bit fields in the SYNCSELECT register
//
//*****************************************************************************
#define SYSCTL_SYNCSELECT_SYNCOUT_S  24U
#define SYSCTL_SYNCSELECT_SYNCOUT_M  0x1F000000U  // Select Syncout Source

//*****************************************************************************
//
// The following are defines for the bit fields in the ADCSOCOUTSELECT register
//
//*****************************************************************************
#define SYSCTL_ADCSOCOUTSELECT_PWM1SOCAEN  0x1U         // PWM1SOCAEN Enable for
                                               // ADCSOCAOn
#define SYSCTL_ADCSOCOUTSELECT_PWM2SOCAEN  0x2U         // PWM2SOCAEN Enable for
                                               // ADCSOCAOn
#define SYSCTL_ADCSOCOUTSELECT_PWM3SOCAEN  0x4U         // PWM3SOCAEN Enable for
                                               // ADCSOCAOn
#define SYSCTL_ADCSOCOUTSELECT_PWM4SOCAEN  0x8U         // PWM4SOCAEN Enable for
                                               // ADCSOCAOn
#define SYSCTL_ADCSOCOUTSELECT_PWM5SOCAEN  0x10U        // PWM5SOCAEN Enable for
                                               // ADCSOCAOn
#define SYSCTL_ADCSOCOUTSELECT_PWM6SOCAEN  0x20U        // PWM6SOCAEN Enable for
                                               // ADCSOCAOn
#define SYSCTL_ADCSOCOUTSELECT_PWM7SOCAEN  0x40U        // PWM7SOCAEN Enable for
                                               // ADCSOCAOn
#define SYSCTL_ADCSOCOUTSELECT_PWM8SOCAEN  0x80U        // PWM8SOCAEN Enable for
                                               // ADCSOCAOn
#define SYSCTL_ADCSOCOUTSELECT_PWM9SOCAEN  0x100U       // PWM9SOCAEN Enable for
                                               // ADCSOCAOn
#define SYSCTL_ADCSOCOUTSELECT_PWM10SOCAEN  0x200U       // PWM10SOCAEN Enable for
                                               // ADCSOCAOn
#define SYSCTL_ADCSOCOUTSELECT_PWM11SOCAEN  0x400U       // PWM11SOCAEN Enable for
                                               // ADCSOCAOn
#define SYSCTL_ADCSOCOUTSELECT_PWM12SOCAEN  0x800U       // PWM12SOCAEN Enable for
                                               // ADCSOCAOn
#define SYSCTL_ADCSOCOUTSELECT_PWM13SOCAEN  0x1000U      // PWM13SOCAEN Enable for
                                               // ADCSOCAOn
#define SYSCTL_ADCSOCOUTSELECT_PWM14SOCAEN  0x2000U      // PWM14SOCAEN Enable for
                                               // ADCSOCAOn
#define SYSCTL_ADCSOCOUTSELECT_PWM15SOCAEN  0x4000U      // PWM15SOCAEN Enable for
                                               // ADCSOCAOn
#define SYSCTL_ADCSOCOUTSELECT_PWM16SOCAEN  0x8000U      // PWM16SOCAEN Enable for
                                               // ADCSOCAOn
#define SYSCTL_ADCSOCOUTSELECT_PWM1SOCBEN  0x10000U     // PWM1SOCBEN Enable for
                                               // ADCSOCBOn
#define SYSCTL_ADCSOCOUTSELECT_PWM2SOCBEN  0x20000U     // PWM2SOCBEN Enable for
                                               // ADCSOCBOn
#define SYSCTL_ADCSOCOUTSELECT_PWM3SOCBEN  0x40000U     // PWM3SOCBEN Enable for
                                               // ADCSOCBOn
#define SYSCTL_ADCSOCOUTSELECT_PWM4SOCBEN  0x80000U     // PWM4SOCBEN Enable for
                                               // ADCSOCBOn
#define SYSCTL_ADCSOCOUTSELECT_PWM5SOCBEN  0x100000U    // PWM5SOCBEN Enable for
                                               // ADCSOCBOn
#define SYSCTL_ADCSOCOUTSELECT_PWM6SOCBEN  0x200000U    // PWM6SOCBEN Enable for
                                               // ADCSOCBOn
#define SYSCTL_ADCSOCOUTSELECT_PWM7SOCBEN  0x400000U    // PWM7SOCBEN Enable for
                                               // ADCSOCBOn
#define SYSCTL_ADCSOCOUTSELECT_PWM8SOCBEN  0x800000U    // PWM8SOCBEN Enable for
                                               // ADCSOCBOn
#define SYSCTL_ADCSOCOUTSELECT_PWM9SOCBEN  0x1000000U   // PWM9SOCBEN Enable for
                                               // ADCSOCBOn
#define SYSCTL_ADCSOCOUTSELECT_PWM10SOCBEN  0x2000000U   // PWM10SOCBEN Enable for
                                               // ADCSOCBOn
#define SYSCTL_ADCSOCOUTSELECT_PWM11SOCBEN  0x4000000U   // PWM11SOCBEN Enable for
                                               // ADCSOCBOn
#define SYSCTL_ADCSOCOUTSELECT_PWM12SOCBEN  0x8000000U   // PWM12SOCBEN Enable for
                                               // ADCSOCBOn
#define SYSCTL_ADCSOCOUTSELECT_PWM13SOCBEN  0x10000000U  // PWM13SOCBEN Enable for
                                               // ADCSOCBOn
#define SYSCTL_ADCSOCOUTSELECT_PWM14SOCBEN  0x20000000U  // PWM14SOCBEN Enable for
                                               // ADCSOCBOn
#define SYSCTL_ADCSOCOUTSELECT_PWM15SOCBEN  0x40000000U  // PWM15SOCBEN Enable for
                                               // ADCSOCBOn
#define SYSCTL_ADCSOCOUTSELECT_PWM16SOCBEN  0x80000000U  // PWM16SOCBEN Enable for
                                               // ADCSOCBOn

//*****************************************************************************
//
// The following are defines for the bit fields in the SYNCSOCLOCK register
//
//*****************************************************************************
#define SYSCTL_SYNCSOCLOCK_SYNCSELECT  0x1U         // SYNCSEL Register Lock bit
#define SYSCTL_SYNCSOCLOCK_ADCSOCOUTSELECT  0x2U         // ADCSOCOUTSELECT Register Lock
                                               // bit
#endif
