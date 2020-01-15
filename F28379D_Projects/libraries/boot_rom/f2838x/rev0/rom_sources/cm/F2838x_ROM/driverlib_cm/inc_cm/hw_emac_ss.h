//###########################################################################
//
// FILE:    emac_ss_hw.h
//
// TITLE:   Definitions for the EMAC_SS registers.
//
//###########################################################################
// $TI Release:  $
// $Release Date:  $
// $Copyright:  $
//###########################################################################

#ifndef EMAC_SS_HW_H
#define EMAC_SS_HW_H

//*****************************************************************************
//
// The following are defines for the EMAC_SS register offsets
//
//*****************************************************************************
#define ETHERNETSS_O_IPREVNUM  0x0U         // IP Revision Number
#define ETHERNETSS_O_CTRLSTS  0x4U         // Control Register
#define ETHERNETSS_O_PTPTSTRIGSEL0  0x8U         // PTP Trigger-0 select
#define ETHERNETSS_O_PTPTSTRIGSEL1  0xCU         // PTP Trigger-1 select
#define ETHERNETSS_O_PTPTSSWTRIG0  0x10U         // PTP SW Trigger-0
#define ETHERNETSS_O_PTPTSSWTRIG1  0x14U         // PTP SW Trigger-1
#define ETHERNETSS_O_PTPPPSR0  0x18U         // PTP PPS-0 Read
#define ETHERNETSS_O_PTPPPSR1  0x1CU         // PTP PPS-1 Read
#define ETHERNETSS_O_PTP_TSRL  0x20U        // PTP timestamp read lower 32
                                               // bits
#define ETHERNETSS_O_PTP_TSRH  0x24U        // PTP timestamp read upper 32
                                               // bits
#define ETHERNETSS_O_PTP_TSWL  0x28U        // External Timestamp write
                                               // lower 32 bits
#define ETHERNETSS_O_PTP_TSWH  0x2CU        // External Timestamp write
                                               // upper 32 bits
#define ETHERNETSS_O_REVMII_CTRL  0x30U        // RevMII Phy Address controls

//*****************************************************************************
//
// The following are defines for the bit fields in the EMACSS_IPREVNUM register
//
//*****************************************************************************
#define ETHERNETSS_IPREVNUM_IP_REV_MINOR_S  0U
#define ETHERNETSS_IPREVNUM_IP_REV_MINOR_M  0xFU         // Minor IP Revision Number
#define ETHERNETSS_IPREVNUM_IP_REV_MAJOR_S  4U
#define ETHERNETSS_IPREVNUM_IP_REV_MAJOR_M  0xF0U        // Major IP Revision Number

//*****************************************************************************
//
// The following are defines for the bit fields in the EMACSS_CTRLSTS register
//
//*****************************************************************************
#define ETHERNETSS_CTRLSTS_PHY_INTF_SEL_S  0U
#define ETHERNETSS_CTRLSTS_PHY_INTF_SEL_M  0x7U         // PHY Type Selection
#define ETHERNETSS_CTRLSTS_CLK_LM  0x10U        // MII Loop-back mode clock
                                               // select
#define ETHERNETSS_CTRLSTS_CLK_SRC_SEL  0x80U        // Internal Clock Selection
#define ETHERNETSS_CTRLSTS_FLOW_CTRL_EN_S  8U
#define ETHERNETSS_CTRLSTS_FLOW_CTRL_EN_M  0x300U       // Back-pressure enable per
                                               // receive queue.
#define ETHERNETSS_CTRLSTS_WRITE_KEY_S  16U
#define ETHERNETSS_CTRLSTS_WRITE_KEY_M  0xFF0000U    // Key to enable writing lock

//*****************************************************************************
//
// The following are defines for the bit fields in the EMACSS_PTPTSTRIGSEL0 register
//
//*****************************************************************************
#define ETHERNETSS_PTPTSTRIGSEL0_PTP_AUX_TS_TRIG_SEL0_S  0U
#define ETHERNETSS_PTPTSTRIGSEL0_PTP_AUX_TS_TRIG_SEL0_M  0x1FU        // Trigger select for Auxillary
                                               // TS capture - 0
#define ETHERNETSS_PTPTSTRIGSEL0_WRITE_KEY_S  16U
#define ETHERNETSS_PTPTSTRIGSEL0_WRITE_KEY_M  0xFF0000U    // Key to enable writing lock

//*****************************************************************************
//
// The following are defines for the bit fields in the EMACSS_PTPTSTRIGSEL1 register
//
//*****************************************************************************
#define ETHERNETSS_PTPTSTRIGSEL1_PTP_AUX_TS_TRIG_SEL1_S  0U
#define ETHERNETSS_PTPTSTRIGSEL1_PTP_AUX_TS_TRIG_SEL1_M  0x1FU        // Trigger select for Auxillary
                                               // TS capture - 1
#define ETHERNETSS_PTPTSTRIGSEL1_WRITE_KEY_S  16U
#define ETHERNETSS_PTPTSTRIGSEL1_WRITE_KEY_M  0xFF0000U    // Key to enable writing lock

//*****************************************************************************
//
// The following are defines for the bit fields in the EMACSS_PTPTSSWTRIG0 register
//
//*****************************************************************************
#define ETHERNETSS_PTPTSSWTRIG0_PTP_AUX_TS_SW_TRIG0  0x1U         // SW trigger for AUX TS capture
                                               // for trigger-0

//*****************************************************************************
//
// The following are defines for the bit fields in the EMACSS_PTPTSSWTRIG1 register
//
//*****************************************************************************
#define ETHERNETSS_PTPTSSWTRIG1_PTP_AUX_TS_SW_TRIG1  0x1U         // SW trigger for AUX TS capture
                                               // for trigger-1

//*****************************************************************************
//
// The following are defines for the bit fields in the EMACSS_PTPPPSR0 register
//
//*****************************************************************************
#define ETHERNETSS_PTPPPSR0_PTP_PPS_R0  0x1U         // Registered value of Pulse Per
                                               // Second-0

//*****************************************************************************
//
// The following are defines for the bit fields in the EMACSS_PTPPPSR1 register
//
//*****************************************************************************
#define ETHERNETSS_PTPPPSR1_PTP_PPS_R1  0x1U         // Registered value of Pulse Per
                                               // Second-1

//*****************************************************************************
//
// The following are defines for the bit fields in the EMACSS_REVMII_CTRL register
//
//*****************************************************************************
#define ETHERNETSS_REVMII_CTRL_REVMII_CORE_PHY_ADDR_S  0U
#define ETHERNETSS_REVMII_CTRL_REVMII_CORE_PHY_ADDR_M  0x1FU        // RevMII Core Register Space
                                               // offset
#define ETHERNETSS_REVMII_CTRL_REVMII_REMOTE_PHY_ADDR_S  8U
#define ETHERNETSS_REVMII_CTRL_REVMII_REMOTE_PHY_ADDR_M  0x1F00U      // RevMII Remote Register Space
                                               // offset
#define ETHERNETSS_REVMII_CTRL_WRITE_KEY_S  16U
#define ETHERNETSS_REVMII_CTRL_WRITE_KEY_M  0xFF0000U    // Key to enable writing lock
#endif
