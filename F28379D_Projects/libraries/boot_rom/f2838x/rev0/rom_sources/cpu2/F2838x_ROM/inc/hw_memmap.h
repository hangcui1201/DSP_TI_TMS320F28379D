//###########################################################################
//
// FILE:    hw_memmap.h
//
// TITLE:   Macros defining the memory map of the C28x.
//
//###########################################################################
// $TI Release:  $
// $Release Date:  $
// $Copyright:  $
//###########################################################################

#ifndef HW_MEMMAP_H
#define HW_MEMMAP_H

//*****************************************************************************
//
// The following are defines for the base address of the memories and
// peripherals.
//
//*****************************************************************************
#define CPUTIMER0_BASE              0x00000C00U // CPU Timer 0 Registers
#define CPUTIMER1_BASE              0x00000C08U // CPU Timer 1 Registers
#define CPUTIMER2_BASE              0x00000C10U // CPU Timer 2 Registers
#define PIECTRL_BASE                0x00000CE0U // PIE Registers
#define PIEVECTTABLE_BASE           0x00000D00U // PIE Vector Table
#define DMA_BASE                    0x00001000U // DMA Control Registers
#define DMA_CH1_BASE                0x00001020U // DMA Channel Registers
#define DMA_CH2_BASE                0x00001040U // DMA Channel Registers
#define DMA_CH3_BASE                0x00001060U // DMA Channel Registers
#define DMA_CH4_BASE                0x00001080U // DMA Channel Registers
#define DMA_CH5_BASE                0x000010A0U // DMA Channel Registers
#define DMA_CH6_BASE                0x000010C0U // DMA Channel Registers
#define CLA1_BASE                   0x00001400U // CPU1.CLA1 Registers
#define EPWM1_BASE                  0x00004000U // EPWM1
#define EPWM2_BASE                  0x00004100U // EPWM2
#define EPWM3_BASE                  0x00004200U // EPWM3
#define EPWM4_BASE                  0x00004300U // EPWM4
#define EPWM5_BASE                  0x00004400U // EPWM5
#define EPWM6_BASE                  0x00004500U // EPWM6
#define EPWM7_BASE                  0x00004600U // EPWM7
#define EPWM8_BASE                  0x00004700U // EPWM8
#define EPWM9_BASE                  0x00004800U // EPWM9
#define EPWM10_BASE                 0x00004900U // EPWM10
#define EPWM11_BASE                 0x00004A00U // EPWM11
#define EPWM12_BASE                 0x00004B00U // EPWM12
#define EPWM13_BASE                 0x00004C00U // EPWM13
#define EPWM14_BASE                 0x00004D00U // EPWM14
#define EPWM15_BASE                 0x00004E00U // EPWM15
#define EPWM16_BASE                 0x00004F00U // EPWM16
#define ECAP1_BASE                  0x00005200U // ECAP1
#define ECAP2_BASE                  0x00005240U // ECAP2
#define ECAP3_BASE                  0x00005280U // ECAP3
#define ECAP4_BASE                  0x000052C0U // ECAP4
#define ECAP5_BASE                  0x00005300U // ECAP5
#define ECAP6_BASE                  0x00005340U // ECAP6
#define ECAP7_BASE                  0x00005380U // ECAP7
#define HRCAP6_BASE                 0x00005360U //HRCAP6 Registers
#define HRCAP7_BASE                 0x000053A0U //HRCAP7 Registers
#define EQEP1_BASE                  0x00005100U // EQEP1
#define EQEP2_BASE                  0x00005140U // EQEP2
#define EQEP3_BASE                  0x00005180U // EQEP3
#define DACA_BASE                   0x00005C00U // BUFDACA
#define DACB_BASE                   0x00005C10U // BUFDACB
#define DACC_BASE                   0x00005C20U // BUFDACC
#define CMPSS1_BASE                 0x00005C80U // CMPSS1
#define CMPSS2_BASE                 0x00005CA0U // CMPSS2
#define CMPSS3_BASE                 0x00005CC0U // CMPSS3
#define CMPSS4_BASE                 0x00005CE0U // CMPSS4
#define CMPSS5_BASE                 0x00005D00U // CMPSS5
#define CMPSS6_BASE                 0x00005D20U // CMPSS6
#define CMPSS7_BASE                 0x00005D40U // CMPSS7
#define CMPSS8_BASE                 0x00005D60U // CMPSS8
#define SDFM1_BASE                  0x00005E00U // SDFM-1 Configuration Registers
#define SDFM2_BASE                  0x00005E80U // SDFM-2 Configuration Registers
#define MCBSPA_BASE                 0x00006000U // McBSP A Registers
#define MCBSPB_BASE                 0x00006040U // McBSP B Registers
#define SPIA_BASE                   0x00006100U // SPI A Registers
#define SPIB_BASE                   0x00006110U // SPI B Registers
#define SPIC_BASE                   0x00006120U // SPI C Registers
#define SPID_BASE                   0x00006130U // SPI D Registers
#define FSITXA_BASE                 0x00006600U // FSITX A Configuration Registers
#define FSIRXA_BASE                 0x00006680U // FSIRX AConfiguration Registers
#define FSITXB_BASE                 0x00006700U // FSITX B Configuration Registers
#define FSIRXB_BASE                 0x00006780U // FSIRX B Configuration Registers
#define FSIRXC_BASE                 0x00006880U // FSIRX C Configuration Registers
#define FSIRXD_BASE                 0x00006980U // FSIRX D Configuration Registers
#define FSIRXE_BASE                 0x00006A80U // FSIRX E Configuration Registers
#define FSIRXF_BASE                 0x00006B80U // FSIRX F Configuration Registers
#define FSIRXG_BASE                 0x00006C80U // FSIRX G Configuration Registers
#define FSIRXH_BASE                 0x00006D80U // FSIRX H Configuration Registers
#define WD_BASE                     0x00007000U // Watchdog Registers
#define NMI_BASE                    0x00007060U // NMI Registers
#define SCIA_BASE                   0x00007200U // SCI A Registers
#define SCIB_BASE                   0x00007210U // SCI B Registers
#define SCIC_BASE                   0x00007220U // SCI C Registers
#define SCID_BASE                   0x00007230U // SCI D Registers
#define I2CA_BASE                   0x00007300U // I2C A Registers
#define I2CB_BASE                   0x00007340U // I2C B Registers
#define EMIF1_BASE                  0x00047000U // EMIF-1 Configuration Registers
#define EMIF2_BASE                  0x00047800U // EMIF-2 Configuration Registers
#define SYNCSOC_BASE                0x00007940U // SYNC SOC registers 
#define CLBXBAR_BASE                0x00007A40U // CLB XBAR Configuration Registers
#define CANA_BASE                   0x00048000U // CAN-A Registers
#define CANB_BASE                   0x0004A000U // CAN-B Registers
#define MCANA_BASE                  0x0005C600U // MCAN-A Registers
#define DEVCFG_BASE                 0x0005D000U // Device Configuration Registers
#define CLKCFG_BASE                 0x0005D200U // Clock Configuration Registers
#define CPUSYS_BASE                 0x0005D300U // CPU System Configuration Registers
#define ROMPREFETCH_BASE            0x0005F588U // ROM Prefetch Control
#define DMACLASRCSEL_BASE           0x00007980U // DMA CLA Triggers Source Select Registers
#define PERIPHAC_BASE               0x0005D500U // Peripheral Master Access Registers
#define ANALOGSUBSYS_BASE           0x0005D700U // Analog System Control Registers
#define DCC0_BASE                   0x0005E700U // Dual Clk Comparator-0 Registers
#define DCC1_BASE                   0x0005E740U // Dual Clk Comparator-1 Registers
#define DCC2_BASE                   0x0005E780U // Dual Clk Comparator-2 Registers
#define CMCONF_BASE                 0x0005DC00U // CM configuration Registers
#define SYSSTAT_BASE                0x0005D400U // System Status Registers
#define MEMCFG_BASE                 0x0005F400U // RAM Configuration Registers
#define EMIF1CONFIG_BASE            0x0005F4C0U // EMIF1 Configuration Registers
#define EMIF2CONFIG_BASE            0x0005F4E0U // EMIF2 Configuration Registers
#define ACCESSPROTECTION_BASE       0x0005F500U // Access protection registers
#define MEMORYERROR_BASE            0x0005F540U // Memory error registers
#define ROMWAITSTATE_BASE           0x0005F580U // ROM Wait State Control
#define FLASH0CTRL_BASE             0x0005F800U // Flash control registers
#define FLASH0ECC_BASE              0x0005FB00U // Flash ECC error log registers
#define GPIOCTRL_BASE               0x00007C00U // GPIO 0 to 31 Mux A Configuration Registers
#define GPIODATA_BASE               0x00007F00U // GPIO 0 to 31 Mux A Data Registers
#define GPIODATAREAD_BASE           0x00007F80U // GPIO 0 to 31 Mux A Data Read Registers
#define INPUTXBAR_BASE              0x00007900U // GPIO Mux GPTRIP Input Select Registers
#define INPUTXBAR2_BASE             0x00007960U // Input X-BAR2 Registers
#define XBAR_BASE                   0x00007920U // X-Bar Registers
#define EPWMXBAR_BASE               0x00007A00U // EPWM XBAR Configuration Registers
#define OUTPUTXBAR_BASE             0x00007A80U // Output X-BAR Configuration Registers
#define OUTPUTXBAR2_BASE            0x00007BC0U // Output X-BAR2 Configuration Registers
#define XINT_BASE                   0x00007070U // Interrupt Control Counter Registers

#define  IPC_CPU1TOCM_BASE       0x0005CE40U
#define  IPC_CPU2TOCM_BASE       0x0005CE40U
#define  IPC_CPU1TOCPU2_BASE      0x0005CE00U
#define  IPC_CPU2TOCPU1_BASE      0x0005CE00U

#define  CMTOCPU1MSGRAM0_BASE       0x00038000U
#define  CMTOCPU1MSGRAM1_BASE       0x00038400U
#define  CPU1TOCMSGRAM0_BASE        0x00039000U
#define  CPU1TOCMSGRAM1_BASE        0x00039400U
#define  CPU1TOCPU2MSGRAM0_BASE     0x0003A000U
#define  CPU1TOCPU2MSGRAM1_BASE     0x0003A400U
#define  CPU2TOCPU1MSGRAM0_BASE     0x0003B000U
#define  CPU2TOCPU1MSGRAM1_BASE     0x0003B400U

#define ADCA_BASE                   0x00007400U // ADCA Configuration Registers
#define ADCB_BASE                   0x00007480U // ADCB Configuration Registers
#define ADCC_BASE                   0x00007500U // ADCC Configuration Registers
#define ADCD_BASE                   0x00007580U // ADCD Configuration Registers
#define ADCARESULT_BASE             0x00000B00U // ADCA Result Registers
#define ADCBRESULT_BASE             0x00000B20U // ADCB Result Registers
#define ADCCRESULT_BASE             0x00000B40U // ADCC Result Registers
#define ADCDRESULT_BASE             0x00000B60U // ADCD Result Registers
#define BGCRC_CPU_BASE              0x00006340U //BGCRC CPU Registers
#define BGCRC_CLA1_BASE             0x00006380U //BGCRC CLA1 Registers
#define BGCRC_CLA2_BASE             0x000063C0U //BGCRC CLA2 Registers
#define DCSM_Z1OTP_BASE             0x00078000U // Zone 1 DCSM OTP
#define DCSM_Z2OTP_BASE             0x00078200U // Zone 2 DCSM OTP
#define DCSM_Z1_BASE                0x0005F000U // Zone 1 DCSM Registers
#define DCSM_Z2_BASE                0x0005F080U // Zone 2 DCSM Registers
#define DCSMCOMMON_BASE             0x0005F0C0U // Security Registers
#define PMBUSA_BASE                 0x00006400U //PMBUSA Registers
#define ECATSS_BASE                 0x00057E00U //Ethercat Sub-System Registers
#define ECATSS_CONFIG_BASE          0x00057F00U //Ethercat Sub-System configuration Registers

#endif // HW_MEMMAP_H

