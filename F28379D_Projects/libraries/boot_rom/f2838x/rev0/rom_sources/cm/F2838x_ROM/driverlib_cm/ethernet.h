//###########################################################################
//
// FILE:   Ethernet.h
//
// TITLE:  CM Ethernet driver.
//
//###########################################################################
// $TI Release: $
// $Release Date: $
// $Copyright: $
//###########################################################################

#ifndef __ETHERNET_H__
#define __ETHERNET_H__

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
//! \addtogroup ethernet_api
//! @{
//
//*****************************************************************************

//Include Files
#include <stdint.h>
#include <stdbool.h>
#include "inc_cm/hw_types.h"

#include "inc_cm/hw_emac.h"
#include "inc_cm/hw_emac_ss.h"
#include "interrupt.h"



//These hw_emac.h
// Transmit Store and Forward Shift Value
#define ETHERNET_MTL_TXQ0_OPERATION_MODE_TSF_S  1U         

#define ETHERNET_MAC_CONFIGURATION_DM_S 13U  //Duplex Mode Shift Value
#define ETHERNET_MAC_CONFIGURATION_LM_S 12U


//MAC Packet Filter Register Bit Field Enumerations
#define ETHERNET_MAC_PACKET_FILTER_PCF_FILTER_ALL_CTRL 0U
#define ETHERNET_MAC_PACKET_FILTER_PCF_FWD_ALL_EXCEPTPASS 1U
#define ETHERNET_MAC_PACKET_FILTER_PCF_FWD_ALL_WITHOUT_ADDRESS_FILTER 2U
#define ETHERNET_MAC_PACKET_FILTER_PCF_FWD_ALL_WITH_ADDRESS_FILTER 3U

//MAC Configuration Enumerations
#define ETHERNET_MAC_CONFIGURATION_DM_FULL_DUPLEX 1U
#define ETHERNET_MAC_CONFIGURATION_DM_HALF_DUPLEX 0U

#define ETHERNET_MAC_CONFIGURATION_LM_LOOPBACK_ENABLED 1U
#define ETHERNET_MAC_CONFIGURATION_LM_LOOPBACK_DISABLED 0U

#define ETHERNET_MAC_RXQ_CONTROL_RXQEN_ENABLED_GENERIC 2U

//MAC WatchDog Timeout Enumerations
#define ETHERNET_MAC_WATCHDOG_TIMEOUT_WTO_2KB 0U
#define ETHERNET_MAC_WATCHDOG_TIMEOUT_WTO_3KB 1U
#define ETHERNET_MAC_WATCHDOG_TIMEOUT_WTO_4KB 2U
#define ETHERNET_MAC_WATCHDOG_TIMEOUT_WTO_5KB 3U
#define ETHERNET_MAC_WATCHDOG_TIMEOUT_WTO_6KB 4U
#define ETHERNET_MAC_WATCHDOG_TIMEOUT_WTO_7KB 5U
#define ETHERNET_MAC_WATCHDOG_TIMEOUT_WTO_8KB 6U
#define ETHERNET_MAC_WATCHDOG_TIMEOUT_WTO_9KB 7U
#define ETHERNET_MAC_WATCHDOG_TIMEOUT_WTO_10KB 8U
#define ETHERNET_MAC_WATCHDOG_TIMEOUT_WTO_11KB 9U
#define ETHERNET_MAC_WATCHDOG_TIMEOUT_WTO_12KB 10U
#define ETHERNET_MAC_WATCHDOG_TIMEOUT_WTO_13KB 11U
#define ETHERNET_MAC_WATCHDOG_TIMEOUT_WTO_14KB 12U
#define ETHERNET_MAC_WATCHDOG_TIMEOUT_WTO_15KB 13U
#define ETHERNET_MAC_WATCHDOG_TIMEOUT_WTO_15383 14U
//Value of F for WTO is reserved and hence not defined 



//
//Threshold value defines for Transmit Threshold
//Enumerations for MTL_TXQn_OPMode Register
//These values can be used as an argument for Ethernet_setMTLTxQueueOpMode func
#define ETHERNET_MTL_TXQ0_OPERATION_MODE_TTC_32     0U
#define ETHERNET_MTL_TXQ0_OPERATION_MODE_TTC_64     1U
#define ETHERNET_MTL_TXQ0_OPERATION_MODE_TTC_96     2U
#define ETHERNET_MTL_TXQ0_OPERATION_MODE_TTC_128    3U
#define ETHERNET_MTL_TXQ0_OPERATION_MODE_TTC_192    4U
#define ETHERNET_MTL_TXQ0_OPERATION_MODE_TTC_256    5U
#define ETHERNET_MTL_TXQ0_OPERATION_MODE_TTC_384    6U
#define ETHERNET_MTL_TXQ0_OPERATION_MODE_TTC_512    7U

#define ETHERNET_MTL_TXQ0_OPERATION_MODE_TXQ_DISABLED 0U
#define ETHERNET_MTL_TXQ0_OPERATION_MODE_TXQ_ENABLED 2U

//Enumerations for DMA_Mode Register 

#define ETHERNET_DMA_OPERATION_MODE_PR_TX1_RX1 0U
#define ETHERNET_DMA_OPERATION_MODE_PR_TX2_RX1 1U
#define ETHERNET_DMA_OPERATION_MODE_PR_TX3_RX1 2U
#define ETHERNET_DMA_OPERATION_MODE_PR_TX4_RX1 3U
#define ETHERNET_DMA_OPERATION_MODE_PR_TX5_RX1 4U
#define ETHERNET_DMA_OPERATION_MODE_PR_TX6_RX1 5U
#define ETHERNET_DMA_OPERATION_MODE_PR_TX7_RX1 6U
#define ETHERNET_DMA_OPERATION_MODE_PR_TX8_RX1 7U

#define ETHERNET_MTL_RXQ0_OPERATION_MODE_TXQ_DISABLED 0U
#define ETHERNET_MTL_RXQ0_OPERATION_MODE_TXQ_ENABLED 2U


#define ETHERNET_DMA_OPERATION_MODE_DA_ROUND_ROBIN 0U
#define ETHERNET_DMA_OPERATION_MODE_DA_FIXED_PRIORITY 1U

//MTL OP Mode Register Bit Field Enumerations 
#define ETHERNET_MTL_OPERATON_MODE_SCHALG_WRR 0U
#define ETHERNET_MTL_OPERATON_MODE_SCHALG_WFQ 1U
#define ETHERNET_MTL_OPERATON_MODE_SCHALG_DWRR 2U
#define ETHERNET_MTL_OPERATON_MODE_SCHALG_STRICT_PRIORITY 3U 

#define ETHERNET_MTL_OPERATION_MODE_RAA_SP  0U
#define ETHERNET_MTL_OPERATION_MODE_RAA_WSP 1U

#define ETHERNET_MTL_OPERATION_MODE_RAA_S   2U

#define ETHERNET_MTL_Q_OP_MODE_QSIZE_256    0U
#define ETHERNET_MTL_Q_OP_MODE_QSIZE_512    1U
#define ETHERNET_MTL_Q_OP_MODE_QSIZE_768    2U
#define ETHERNET_MTL_Q_OP_MODE_QSIZE_1024   3U
#define ETHERNET_MTL_Q_OP_MODE_QSIZE_1280   4U
#define ETHERNET_MTL_Q_OP_MODE_QSIZE_1536   5U
#define ETHERNET_MTL_Q_OP_MODE_QSIZE_1792   6U
#define ETHERNET_MTL_Q_OP_MODE_QSIZE_2048  7U
#define ETHERNET_MTL_Q_OP_MODE_QSIZE_4096   15U

//Enumeration for MTL_TxQ0_Operation_Mode Register
#define ETHERNET_MTL_TXQ_OPMODE_TSF_ENABLE 1U
#define ETHERNET_MTL_TXQ_OPMODE_TSF_DISABLE 0U

//Enumeration for MTL_RxQ0_Operation_Mode Register
#define ETHERNET_MTL_RX_Q_OP_MODE_RSF_ENABLE 1U
#define ETHERNET_MTL_RX_Q_OP_MODE_RSF_DISABLE 0U

//Enumerations for MTL_RXQn_OPMode Register
#define ETHERNET_MTL_RXQ0_OPERATION_MODE_RTC_64     0U
#define ETHERNET_MTL_RXQ0_OPERATION_MODE_RTC_32     1U
#define ETHERNET_MTL_RXQ0_OPERATION_MODE_RTC_96     2U
#define ETHERNET_MTL_RXQ0_OPERATION_MODE_RTC_128    3U

#define ETHERNET_MTL_RXQ0_OPERATION_MODE_RSF_S  5U


//Enumeration for DMA_CH(#i)_RX_Control Register
//Received Buffer Size
//Our Configuration has 2bits(since 4 bytes is burst size)
//for the lower bits and Bit 0 is for Enable
//Hence it should be left shift by 3 
#define ETHERNET_DMA_CHx_RX_CONTROL_RBSZ_16     4U
#define ETHERNET_DMA_CHx_RX_CONTROL_RBSZ_32     8U
#define ETHERNET_DMA_CHx_RX_CONTROL_RBSZ_64     16U
#define ETHERNET_DMA_CHx_RX_CONTROL_RBSZ_128    32U
#define ETHERNET_DMA_CHx_RX_CONTROL_RBSZ_256    64U
#define ETHERNET_DMA_CHx_RX_CONTROL_RBSZ_512    128U
#define ETHERNET_DMA_CHx_RX_CONTROL_RBSZ_1K 256U
#define ETHERNET_DMA_CHx_RX_CONTROL_RBSZ_2K 512U

// MAC_PPSx_Target_Time_Nanoseconds Register bit fields
/*
 * TODO : This register can have many instances depending on the
 * instances of the PPS in MAC.
 */
#define ETHERNET_MAC_PPS_TARGET_TIME_SECONDS        0x0B80
#define ETHERNET_MAC_PPS_TARGET_TIME_NANOSECONDS        0x0B84
#define ETHERNET_MAC_PPS_WIDTH      0x0B8C
#define ETHERNET_MAC_PPS_INTERVAL       0x0B88

#define ETHERNET_MAC_PPS_OUT_NUM        0x2U
#define ETHERNET_MAC_PPS_TARGET_TIME_NANOSECONDS_TRGTBUSY       0x80000000

// AUX Timestamp related
#define ETHERNET_MAC_AUX_TIMESTAMP_FIFO_DEPTH   0x4U

// Enumeration for ETHERNETSS_O_PTPTSTRIGSEL0/1 register
#define ETHERNETSS_PTPTSTRIGSEL_AUX_TRIG_SEL0   0x1U
#define ETHERNETSS_PTPTSTRIGSEL_AUX_TRIG_SEL1   0x2U

// Enumeration for EMACSS_PTPTSSWTRIG0/1 register
#define ETHERNETSS_PTPTSSWTRIG_PTP_AUX_TS_SW_TRIG0   0x1U
#define ETHERNETSS_PTPTSSWTRIG_PTP_AUX_TS_SW_TRIG1   0x2U

// Maximum 32 configurations are allowed.
#define ETHERNETSS_PTPTSTRIGSEL_AUX_TRIG_SEL_MAX_VALUE  0x1FU

// MAC_PPS_Control Register bit-fields
#define ETHERNET_MAC_PPS_CONTROL_PPSEN0       0x4U
#define ETHERNET_MAC_PPS_CONTROL_TRGTMODSEL_S       0x5U
#define ETHERNET_MAC_PPS_CONTROL_TRGTMODSEL_M       0x3U

//Enumeration for MAC_PPS_Control Register
#define ETHERNET_MAC_PPS_CONTROL_TRGTMODSEL_INTERRUPT        0x0U
#define ETHERNET_MAC_PPS_CONTROL_TRGTMODSEL_INTERRUPT_PULSE     0x2U
#define ETHERNET_MAC_PPS_CONTROL_TRGTMODSEL_PULSE      0x3U

#define ETHERNET_MAC_PPS_CONTROL_PPSEN0_PPS_FIXED_MODE      0x0U
#define ETHERNET_MAC_PPS_CONTROL_PPSEN0_PPS_FLEXIBLE_MODE       0x1U

#define ETHERNET_MAC_PPS_CONTROL_PPSCTRL_PPS_OUTPUT_SINGLE_PULSE        0x0U
#define ETHERNET_MAC_PPS_CONTROL_PPSCTRL_PPS_OUTPUT_1HZ     0x1U
#define ETHERNET_MAC_PPS_CONTROL_PPSCTRL_PPS_OUTPUT_2HZ     0x2U
#define ETHERNET_MAC_PPS_CONTROL_PPSCTRL_PPS_OUTPUT_4HZ     0x3U
#define ETHERNET_MAC_PPS_CONTROL_PPSCTRL_PPS_OUTPUT_8HZ     0x4U
#define ETHERNET_MAC_PPS_CONTROL_PPSCTRL_PPS_OUTPUT_16HZ    0x5U
#define ETHERNET_MAC_PPS_CONTROL_PPSCTRL_PPS_OUTPUT_32HZ    0x6U
#define ETHERNET_MAC_PPS_CONTROL_PPSCTRL_PPS_OUTPUT_64HZ    0x7U
#define ETHERNET_MAC_PPS_CONTROL_PPSCTRL_PPS_OUTPUT_128HZ       0x8U
#define ETHERNET_MAC_PPS_CONTROL_PPSCTRL_PPS_OUTPUT_256HZ       0x9U
#define ETHERNET_MAC_PPS_CONTROL_PPSCTRL_PPS_OUTPUT_512HZ       0xAU
#define ETHERNET_MAC_PPS_CONTROL_PPSCTRL_PPS_OUTPUT_1024HZ      0xBU
#define ETHERNET_MAC_PPS_CONTROL_PPSCTRL_PPS_OUTPUT_2048HZ      0xCU
#define ETHERNET_MAC_PPS_CONTROL_PPSCTRL_PPS_OUTPUT_4096HZ      0xDU
#define ETHERNET_MAC_PPS_CONTROL_PPSCTRL_PPS_OUTPUT_8192HZ      0xEU
#define ETHERNET_MAC_PPS_CONTROL_PPSCTRL_PPS_OUTPUT_16384HZ     0xFU
#define ETHERNET_MAC_PPS_CONTROL_PPSCTRL_PPS_OUTPUT_32768HZ     0x10U

#define ETHERNET_MAC_PPS_CONTROL_PPSCMD_COMMAND_NONE        0x0U
#define ETHERNET_MAC_PPS_CONTROL_PPSCMD_COMMAND_START_SINGLE    0x1U
#define ETHERNET_MAC_PPS_CONTROL_PPSCMD_COMMAND_START_TRAIN     0x2U
#define ETHERNET_MAC_PPS_CONTROL_PPSCMD_COMMAND_CANCEL_START    0x3U
#define ETHERNET_MAC_PPS_CONTROL_PPSCMD_COMMAND_STOP_AT_TIME    0x4U
#define ETHERNET_MAC_PPS_CONTROL_PPSCMD_COMMAND_STOP_NOW        0x5U
#define ETHERNET_MAC_PPS_CONTROL_PPSCMD_COMMAND_CANCEL_STOP     0x6U

//Enumerations for VLAN Incl Register 

#define ETHERNET_MAC_VLAN_INCL_VLP_S    18U

//Static means the Tag control is provided in the VLC Field
#define ETHERNET_MAC_VLAN_INCL_VLP_STATIC 1
//Dynamic means the VLC field is ignored and uses Context Descriptor
#define ETHERNET_MAC_VLAN_INCL_VLP_DYNAMIC 0

#define ETHERNET_MAC_VLAN_INCL_CSVL_S 19U
#define ETHERNET_MAC_VLAN_INCL_VLTI_S   20U
#define ETHERNET_MAC_VLAN_INCL_CBTI_S 21U
#define ETHERNET_MAC_VLAN_INCL_ADDR_S           24U
#define ETHERNET_MAC_VLAN_INCL_RDWR_S           30U
#define ETHERNET_MAC_VLAN_INCL_BUSY_S          31U


//For MAC_ Inner VLAN Register

#define ETHERNET_MAC_INNER_VLAN_INCL_VLP_S    18U
#define ETHERNET_MAC_INNER_VLAN_INCL_CSVL_S 19U
#define ETHERNET_MAC_INNER_VLAN_INCL_VLTI_S   20U

//For MAC_VLAN_TAG_DATA Register
#define ETHERNET_MAC_VLAN_TAG_DATA_DATA_16_S    16U
#define ETHERNET_MAC_VLAN_TAG_DATA_DATA_17_S    17U
#define ETHERNET_MAC_VLAN_TAG_DATA_DATA_18_S    18U
#define ETHERNET_MAC_VLAN_TAG_DATA_DATA_19_S    19U
#define ETHERNET_MAC_VLAN_TAG_DATA_DATA_20_S    20U
#define ETHERNET_MAC_VLAN_TAG_DATA_DATA_24_S    24U
#define ETHERNET_MAC_VLAN_TAG_DATA_DATA_25_S    25U

//For MAC_VLAN_TAG_Ctrl Register
#define ETHERNET_MAC_VLAN_TAG_CTRL_CT_READ 1U
#define ETHERNET_MAC_VLAN_TAG_CTRL_CT_WRITE 0U



//Enumerations for DMA Mode Register
#define ETHERNET_DMA_MODE_INTM_MODE0    0U
#define ETHERNET_DMA_MODE_INTM_MODE1    1U
#define ETHERNET_DMA_MODE_INTM_MODE2    2U

//Defines for MDIO_ADDRESS register
#define ETHERNET_MDIO_ADDRESS_C45E_S    1U
#define ETHERNET_MDIO_ADDRESS_HIGHCLK_ENABLE_S 11U
#define ETHERNET_MAC_MDIO_ADDRESS_GOC_0_S   2U

#define ETHERNET_MAC_MDIO_ADDRESS_GOC_WRITE             1U
#define ETHERNET_MAC_MDIO_ADDRESS_GOC_READ              3U
#define ETHERNET_MAC_MDIO_ADDRESS_GOC_POSTREAD_INC      2U  

//Defines for MAC_ADDRESS Register
#define ETHERNET_MAC_ADDRESS0_HIGH_DCS_S  16U 

//Defines for MTL_RXQ_DMA_MAP0 register
#define ETHERNET_MTL_RXQ_DMA_MAP0_DDMACH_S 4U
#define ETHERNET_MTL_RXQ_DMA_MAP0_QDMACH_S  8U

//Defines for REVMII Registers
#define ETHERNET_REVMII_PHY_CONTROL 0x0U
#define ETHERNET_REVMII_COMMON_STATUS 0x1U
#define ETHERNET_REVMII_COMMON_EXT_STATUS 0xFU
#define ETHERNET_REVMII_INTERRUPT_STATUS_MASK 0x10U
#define ETHERNET_REVMII_REMOTE_PHY_STATUS 0x11U

//Bit field defines for the REVMII Registers used
//REVMII Interrupt Status Mask Register
#define ETHERNET_REVMII_INTERRUPT_STATUS_MASK_LSI_M 0x100U

//Generic Enable Disable Defines
#define ETHERNET_ENABLE 1U
#define ETHERNET_DISABLE 0U

//hw_emac.h defines ends

//hw_emac_SS.h defines 

#define ETHERNETSS_CTRLSTS_CLK_LM_S 4U
#define ETHERNETSS_CTRLSTS_CLK_SRC_SEL_S 7U

// Enumerations for CTRLSTS Register

#define ETHERNETSS_CTRLSTS_PHY_INTF_SEL_GMII 0U
/* Values 1-3 Reserved*/
#define ETHERNETSS_CTRLSTS_PHY_INTF_SEL_RMII 4U
#define ETHERNETSS_CTRLSTS_PHY_INTF_SEL_REVMII 7U

#define ETHERNETSS_CTRLSTS_LMCLKSEL_NORMAL 0U
#define ETHERNETSS_CTRLSTS_LMCLKSEL_INTERNAL 1U

#define ETHERNETSS_CTRLSTS_CLK_SRC_SEL_EXTERNAL 0U
#define ETHERNETSS_CTRLSTS_CLK_SRC_SEL_INTERNAL 1U

#define ETHERNETSS_CTRLSTS_FLOW_CTRL_EN_ENABLED 3U
#define ETHERNETSS_CTRLSTS_FLOW_CTRL_EN_DISABLED 0U

#define ETHERNETSS_CTRLSTS_WRITE_KEY_VALUE 0xA5U

//hw_emac_SS.h ends 

#define ETHERNET_NUMSTATS 56U 


#define MAX_NUM_DMA_CHANNELS 2U
#define MAX_DMA_DIR 2U 
#define ETHERNET_CH_DIR_TX  0U
#define ETHERNET_CH_DIR_RX  1U
/*EQOS Descriptor related flags*/
/* Interrupt on Completion */
#define ETHERNET_TX_DESC_IOC                0x80000000U 
/*Owner ship Flag in Buffer Descriptor */
#define ETHERNET_DESC_OWNER             0x80000000u
#define ETHERNET_TX_DESC_TTSE           0x40000000u
#define ETHERNET_RX_DESC_IOC            0x40000000u
#define ETHERNET_RX_DESC_BUF1_VALID     0x01000000u  //24th Bit
#define ETHERNET_RX_DESC_BUF2_VALID     0x02000000u //25th Bit

#define ETHERNET_TX_DESC_SAIC_NO_SA_INC  0U
#define ETHERNET_TX_DESC_SAIC_INS_SA         1U
#define ETHERNET_TX_DESC_SAIC_REPL_SA    2U
#define ETHERNET_TX_DESC_SAIC_S             23U
#define ETHERNET_TX_DESC_CPC_S              26U

#define EQOS_DESCRIPTORS_NUM_TX 16U
#define EQOS_DESCRIPTORS_NUM_TX_PER_CHANNEL 8U

#define EQOS_DESCRIPTORS_NUM_RX 16U
#define EQOS_DESCRIPTORS_NUM_RX_PER_CHANNEL 8U   

#define EQOS_DESCTIPTORS_NUM (EQOS_DESCRIPTORS_NUM_TX + \
        EQOS_DESCRIPTORS_NUM_RX)



//Layout of Flags Field in Tx Packet Descriptor
//|31|30|29 |28 |27 |26 |25  |24  |23  |22  |21|20|19|18|17 |16 |
//|x |x |SOP|EOP|CPC|CPC|SAIC|SAIC|VLIC|VLIC|x | x|x |x |CIC|CIC|

#define ETHERNET_PKT_FLAG_SOP_S 29U
#define ETHERNET_PKT_FLAG_EOP_S 28U
#define ETHERNET_PKT_FLAG_CPC_S 26U
#define ETHERNET_PKT_FLAG_SAIC_S 24U
#define ETHERNET_PKT_FLAG_VLIC_S 22U
#define ETHERNET_PKT_FLAG_CIC_S   16U


/**< Start of packet                                           */
#define ETHERNET_PKT_FLAG_SOP              0x20000000u
/**< End of packet                                             */
#define ETHERNET_PKT_FLAG_EOP              0x10000000u
#define ETHERNET_PKT_FLAG_CPC               0x0c000000U
#define ETHERNET_PKT_FLAG_SAIC              0x03000000U
#define ETHERNET_PKT_FLAG_VLIC              0x00C00000U
#define ETHERNET_PKT_FLAG_CIC               0x00030000U

// 
//VLAN Tag Insertion Flags
//
#define ETHERNET_PKT_FLAG_NO_VLAN                   0x00000000U
#define ETHERNET_PKT_FLAG_VLAN_REMOVAL     0x00400000U
#define ETHERNET_PKT_FLAG_VLAN_INSERTION   0x00800000U
#define ETHERNET_PKT_FLAG_VLAN_REPLACE      0x00C00000U

//CRC insertion Control Flags
#define ETHERNET_PKT_FLAG_CRC_PAD_INS               0x00000000U
#define ETHERNET_PKT_FLAG_CRC_INS_NO_PAD        0x04000000U
#define ETHERNET_PKT_FLAG_CRC_PAD_DIS               0x08000000U
#define ETHERNET_PKT_FLAG_CRC_REPL_NO_PAD    0x0C000000U

//SA Insertion Flags
#define ETHERNET_PKT_FLAG_SA_NO_INS                  0x00000000U
#define ETHERNET_PKT_FLAG_SA_INS                          0x01000000U
#define ETHERNET_PKT_FLAG_SA_REPLACE              0x02000000U

//L3 L4 Checksum Control Flags
#define ETHERNET_PKT_FLAG_CS_NO_INS                 0x00000000U
#define ETHERNET_PKT_FLAG_CS_IP_INS                                             0x00010000U
#define ETHERENT_PKT_FLAG_CS_IP_PAYLOAD_INS_NO_PSEUDO 0x00020000U
#define ETHERNET_PKT_FLAG_CS_IP_PAYLOAD_PSEUDO_INS         0x00030000U

#define ETHERNET_NUM_PORTS 1U

#define ETHERNET_DMA_CHANNEL_NUM_0 0U
#define ETHERNET_DMA_CHANNEL_NUM_1 1U

//
#define ETHERNET_RX_NORMAL_DESC_RDES1_TSA_LBIT_POS  0xe
#define ETHERNET_RX_CONTEXT_DESC_RDES3_CTXT_HBIT_POS  0x1e



#define ETHERNET_DRV_DEVMAGIC            0x0acefaceU

#define ETHERNET_ERROR_CODE              (0x2000000u)
#define ETHERNET_ERROR_INFO              (ETHERNET_ERROR_CODE)
#define ETHERNET_ERROR_WARNING           (ETHERNET_ERROR_CODE | 0x10000000u)
#define ETHERNET_ERROR_MINOR             (ETHERNET_ERROR_CODE | 0x20000000u)
#define ETHERNET_ERROR_MAJOR             (ETHERNET_ERROR_CODE | 0x30000000u)
#define ETHERNET_ERROR_CRITICAL          (ETHERNET_ERROR_CODE | 0x40000000u)


#define ETHERNET_ERR_INVALID_HANDLE     (ETHERNET_ERROR_MAJOR + 1u)
#define ETHERNET_ERR_INVALID_PARAM      (ETHERNET_ERROR_MAJOR + 2u)
#define ETHERNET_ERR_BAD_PACKET         (ETHERNET_ERROR_MAJOR + 3u)

#define ETHERNET_RET_SUCCESS    0U

//Interrupt related defines
#define ETHERNET_GENERIC_INTERRUPT      INT_EMAC
#define ETHERNET_TX_INTR_CH0            INT_EMAC_TX0
#define ETHERNET_TX_INTR_CH1            INT_EMAC_TX1
#define ETHERNET_RX_INTR_CH0            INT_EMAC_RX0
#define ETHERNET_RX_INTR_CH1            INT_EMAC_RX1

//
// Define for deriving the offset of channel specific registers
//
#define ETHERNET_CHANNEL_OFFSET        (0x80U)

//
// Define for deriving the offset of Queue specific registers
//

#define ETHERNET_QUEUE_OFFSET          (0x40U)

//
//Define for Signalling Early Rx Completion
//
typedef enum
{
    ETHERNET_COMPLETION_NORMAL        = 0x00U, //!Normal Packet Completion
    ETHERNET_COMPLETION_EARLY         = 0x01U  //!<Master write to slave
} Ethernet_CompletionMode;

//These Flags are used by the LLD during the Interrupt callbacks
//
//Layout of Flags Field in  Completion Callback
//|31|30|29   |28 |27 |26 |25  |24  |23  |22  |21|20|19|18|17 |16 |
//|Tx|Rx|Early|

// To signal Tx, Rx and Early completion
#define ETHERNET_INTERRUPT_FLAG_TRANSMIT 0x80000000
#define ETHERNET_INTERRUPT_FLAG_RECEIVE  0x40000000
#define ETHERNET_INTERRUPT_FLAG_EARLY    0x20000000



//*****************************************************************************
//
//! Statistics Software defines Structure that groups the different
//! RMON Statistics in the Peripheral
//
//*****************************************************************************


typedef struct  {
    //TX Statistics
    uint32_t txOctetCountGoodBad;   //0x714
    uint32_t txPacketCountGoodBad;  //0x718
    uint32_t txBroadcastPacketsGood; //0x71C
    uint32_t txMulticastPacketsGood; //0x720
    uint32_t tx64OctetsPacketsGood;
    uint32_t tx65to127OctetsPacketsGood;
    uint32_t tx128to255OctetsPacketsGood;
    uint32_t tx256to511OctetsPacketsGood;
    uint32_t tx512to1023OctetsPacketsGood;
    uint32_t tx1024toMaxOctetsPacketsGood;
    uint32_t txUnicastPacketsGoodBad;
    uint32_t txMulticastPacketsGoodBad;
    uint32_t txBroadcastPacketsGoodBad;
    uint32_t txUnderFlowErrorPackets;
    uint32_t txSingleCollisionGoodPackets;
    uint32_t txMultipleCollisionGoodPackets;
    uint32_t txDeferredPackets;
    uint32_t txLateCollisionPackets;
    uint32_t txExcessiveCollisionPackets;
    uint32_t txCarrierErrorPackets;
    uint32_t txOctetCountGood;
    uint32_t txPacketCountGood;
    uint32_t txExcessiveDeferralError;
    uint32_t txPausePackets;
    uint32_t txVLANPacketsGood;
    uint32_t txOSizePacketsGood;
    //RX Statistics
    uint32_t rxPacketsCountGoodBad;
    uint32_t rxOctetCountGoodBad;
    uint32_t rxOctetCountGood;
    uint32_t rxBroadcastPacketsGood;
    uint32_t rxMulticastPacketsGood;
    uint32_t rxCRCErrorPackets;
    uint32_t rxAlignmentErrorPackets;
    uint32_t rxRuntErrorPackets;
    uint32_t rxJabberErrorPackets;
    uint32_t rxUnderSizePacketsGood;
    uint32_t rxOverSizePacketsGood;
    uint32_t rx64OctetsPacketsGoodBad;
    uint32_t rx65to127OctetsPacketsGoodBad;
    uint32_t rx128to255OctetsPacketsGoodBad;
    uint32_t rx256to511OctetsPacketsGoodBad;
    uint32_t rx512to1023OctetsPacketsGoodBad;
    uint32_t rx1024toMaxOctetsPacketsGoodBad;
    uint32_t rxUnicastPacketsGood;
    uint32_t rxLengthErrorPackets;
    uint32_t rxOutOfRangeTypePackets;
    uint32_t rxPausePackets;
    uint32_t rxFIFOOverFlowPackets;
    uint32_t rxVLANPacketsGoodBad;
    uint32_t rxWatchDogErrorPackets;
    uint32_t rxReceiveErrorPackets;
    uint32_t rxControlPacketsGood;

    //LPI Related Statistics
    uint32_t txLPIUsecCounter;
    uint32_t txLPITranCounter;
    uint32_t rxLPIUsecCounter;
    uint32_t rxLPITranCounter;
    
    
}Ethernet_statistics;

//*****************************************************************************
//
//! Generic Descriptor Structure definition 
//! that can be used for Transmit,Receive and Context Descriptors
//
//*****************************************************************************


typedef struct  {
    uint32_t des0;
    uint32_t des1;
    uint32_t des2;
    uint32_t des3;
} Ethernet_EQOS_descriptor;

typedef uint32_t Ethernet_PKT_FLAG_T;

//*****************************************************************************
//
//! EMAC Packet Structure, that the application/higher layer
//! uses to Send a packet 
//! and Driver notifies to the higher layer using this structure
//! For Multiple Packets/Buffers this structure is chained
//
//*****************************************************************************

//typedef struct Ethernet_Pkt_Desc_T
typedef struct Ethernet_Pkt_Desc_T

{
    /**< Next descriptor pointer use this if multiple 
     descriptors are chained else keep it 0 */
    struct Ethernet_Pkt_Desc_T*     nextPacketDesc;
    /** < Pointer to the Buffer                                                                             */
    uint8_t*                            dataBuffer;
     /**< Physical Length of this buffer (read only)                         */
    uint32_t                            bufferLength;
        /**< Tx/Rx Channel 0-1 (Valid on SOP only)                           */
    uint32_t                            pktChannel;
    /**< Length of Packet (Valid on SOP only) 
        (same as validLength on single frag Pkt)  */
    uint32_t                            pktLength;
     /**< Packet flags, SOP, EOP                                             */
    Ethernet_PKT_FLAG_T            flags;
         /**< No of frags in packet (SOP only), normally 1                   */
    uint32_t                              numPktFrags;
    /* Data Offset usually set it to Zero can be used if buffer does 
    not start from address 0 of pBuffer*/
    uint32_t                 dataOffset;
    /* No of bytes of packet valid in this buffer*/
    uint32_t                 validLength; 
    /* Thes two fields are filled by the hardware and returned to application
    in the callback 
    */
    uint32_t                  timeStampLow;
    uint32_t                  timeStampHigh;

}Ethernet_Pkt_Desc;

//*****************************************************************************
//
//! MAC Address Structure to by used 
//! by Higher layer to pass MAC address to the Driver
//
//*****************************************************************************

typedef struct  {
    uint8_t channelNum;
    /* Receive Channel number to which the MAC address to be assigned */
    uint8_t addr[6];
    /* MAC address specific to channel */
} Ethernet_MACAddrConfig;

//*****************************************************************************
//
//! EMAC Wrapper Subsystem Configuration used in Initializing the  
//! Configuration during Ethernet_Init
//
//*****************************************************************************



typedef struct  {
    uint8_t         phyIntfSel;
    uint8_t     LoopBackModeClkSel;
    uint8_t     clkSrcSel;
    uint8_t         flowControlEn;
} Ethernet_SubSystemConfig;

//*****************************************************************************
//
//! Filter Coniguration Structure 
//! That maps to MAC Filter Configuration Register of the MAC
//
//*****************************************************************************


typedef struct  {
    uint32_t promiscuousMode:1;
    uint32_t hashUnicast:1;
    uint32_t hashMulticast:1;
    uint32_t daInverseFilter:1;
    uint32_t passAllMulticast:1;
    uint32_t disableBroadCastPackets:1;
    uint32_t passControlPackets:2;
    uint32_t saInverseFilter:1;
    uint32_t saFilterEnable:1;
    uint32_t hashPerfectFilter:1;
    uint32_t reserved1:5;
    uint32_t vlanFilterEnable:1;
    uint32_t reserved2:3;
    uint32_t l3L4FilterEnable:1;
    uint32_t dropNonTCP:1;
    uint32_t reserved3:9;
    uint32_t receiveAll:1;
    
}Ethernet_EQOS_MACFilterConfig;
//*****************************************************************************
//
//! Generic Handle structure  
//! Not used now but for NDK Layer 
//
//*****************************************************************************

typedef void*   Handle;

//*****************************************************************************
//
//! Per Channel Information Structure  
//! Stores the individual channel Parameters 
//
//*****************************************************************************


typedef struct 
{
   uint32_t     chNum;
    /**< Channel Number                                                     */
   uint32_t     chDir;
    /**< Channel Direction                                                  */
   uint32_t     numBD;
    /**< Maximum Number of Buffer Descriptors allocated for this channel    */
   uint32_t     bufSize;
    /**< Buffer size                                                        */
   uint32_t     enableSplitHeader;
    /**< Enables the Split Header Option in the RX Path */
   uint32_t     descriptorSkipLength;
     /** For Configuring Non Contiguous descriptors **/
   uint32_t     storeNForward;
   /** For Storing the flag whether the 
   Store and Forward mode is enabled or not **/
   uint32_t     queueThreshold;
   uint32_t     burstLength;
   uint32_t     dmaQueueSize;
   uint32_t     dmaBufferSize;

}Ethernet_ChInfo;

//
//This structure maps to the bit fields of DMA Mode register of EQOS module
typedef struct {
    uint32_t SoftwareReset:1;
    uint32_t TxRxArbitration:1;
    uint32_t TransmitArbitration:3;
    uint32_t Reserved4:3;
    uint32_t DescriptorPostedWrite:1;
    uint32_t Reserved3:2;
    uint32_t TransmitPriority:1;
    uint32_t PriorityRatio:3;
    uint32_t Reserved2:1;
    uint32_t InterruptMode:2;
    uint32_t Reserved1:14;
}Ethernet_dmaMode;

//*****************************************************************************
//
//! Init Configuration Structure used in Ethernet_Open   
//! An instance of this is stored fully in the Global Book Keeping structure 
//! for Maintaining the Configuration Specified by the Higher Layer/User
//*****************************************************************************

typedef struct 
{
    /**<Link Speed                                                        */
    uint8_t                        linkSpeed;
      /**<Link Mode                                                       */
      uint8_t                      linkMode;
    /**< Total number of MAC addresses to be assigned for 
    all receive channels */
    uint8_t                        totalNumMacAddrs;
    /**< Mac Addresses structure                                            */  
    uint8_t                        loopbackMode;
    Ethernet_MACAddrConfig         *macAddr; //TBD ** in AM43x?
    /*Subsystem Configuration Register */
    Ethernet_SubSystemConfig       emacSSConfig;
    /*DMA Mode Register Settings */
    /*Priority Ratio between Tx and RX */
    uint8_t                        priorityRatio;
    uint8_t                        transmitArbitrationAlgorithm;
    uint8_t                        dmaArbitrationScheme;
    /*MTL Operation Mode Settings*/
    uint8_t                        txSchedulingAlgoritm;
    uint8_t                        receiveArbitrationAlgorithm;

    /* MAC Filter Settings */
    Ethernet_EQOS_MACFilterConfig   macFilterConfig;
    uint32_t                        noofPacketsRxBuffer;
    uint32_t                        maxPacketLengthRxBuffer;
    Ethernet_ChInfo                 chInfo[MAX_DMA_DIR][MAX_NUM_DMA_CHANNELS];
    uint32_t                        numChannels;
    uint32_t                        pktMTU;
    Ethernet_dmaMode                dmaMode;
     /**< Receive packet call back  called when a Packet is Received by the LLD 
     */
    Ethernet_Pkt_Desc*  (*pfcbRxPacket)(Handle handleApplication, \
        Ethernet_Pkt_Desc *pPacket);
     /**< Get packet call back  called by this driver when it needs a packet 
     from Application                                        */
    Ethernet_Pkt_Desc* (*pfcbGetPacket)(void);
       /**< Free packet call back called after the completion of Tx and 
       when the buffer needs to handled back to application */
    void             (*pfcbFreePacket)(Handle handleApplication, \
                        Ethernet_Pkt_Desc *pPacket);

}Ethernet_InitConfig;


typedef enum
{
     ETHERNETSS_PHY_INTF_SEL_MII  = 0U,
        /* Values 1-3 Reserved*/
     ETHERNETSS_PHY_INTF_SEL_RMII = 4U,
     ETHERNETSS_PHY_INTF_SEL_REVMII = 7U
} EthernetSS_phyInterfaceMode;


typedef enum
{
    ETHERNETSS_CLK_SRC_EXTERNAL ,
    ETHERNETSS_CLK_SRC_INTERNAL 
}EthernetSS_clockSelection;
//
//This Structure should be passed to Ethernet_InitInterface API
//
typedef struct 
{
    uint32_t ssbase; //Base Address of Subsystem Wrapper Registers
    uint32_t eqos_base; //Base Address of EQOS Register
    EthernetSS_phyInterfaceMode phyMode; //Physical interface selected
    //Clock Configuration selection for ReVMII/RMII modes
    EthernetSS_clockSelection clockSel;
    uint8_t localPhyAddress; //used in case of RevMII
    uint8_t remotePhyAddress; //used in case of RevMII
                    
}Ethernet_InitInterfaceConfig;

//*****************************************************************************
//
//! Generic Packet Queue Structure - Contains a head and Tail pointer
//! Two instances of such Structure is used in each channel 
//
//*****************************************************************************


typedef struct  {
    /**
     * @brief   Number of packets in queue
     */
    uint32_t                   count;

    /**
     * @brief   Pointer to first packet
     */
    Ethernet_Pkt_Desc          *head;

    /**
     * @brief   Pointer to last packet
     */
    Ethernet_Pkt_Desc          *tail;
} Ethernet_PKT_Queue_T;

//*****************************************************************************
//
//! Forward Declaration of Device Structure see structure Definition below  
//! 
//
//*****************************************************************************

typedef struct _Ethernet_Device Ethernet_Device;

//*****************************************************************************
//
//! Per Channel Channel Descriptor Structure  
//! Maintains two queues one for Wait Queue that is submitted by the USer 
//! Desc Queue that is Queued to the Hardware
//! It also maintains the Descriptor pointers
//*****************************************************************************

typedef struct  {


    Ethernet_Device                *devicePtr;
    Ethernet_PKT_Queue_T           descQueue;
    /**< Packets queued as desc                                             */
    Ethernet_PKT_Queue_T           waitQueue;
    /**< Packets waiting for TX desc                                        */
    Ethernet_ChInfo                *chInfo;
    /**< Channel info                                                       */
    uint32_t                       descMax;
    /**< Max number of desc (buffs)                                         */
    uint32_t                       descCount;
   /**< Current number of desc                                             */
    Ethernet_EQOS_descriptor       *descFirst;
    /**< First desc location                                               */
    Ethernet_EQOS_descriptor       *descLast;
    /**< Last desc location                                                 */  
    Ethernet_EQOS_descriptor       *descRead;
    /**< Location to read next desc                                         */
    Ethernet_EQOS_descriptor       *descWrite;
    /**< Location to write next desc                                        */
    uint32_t                       dmaInProgress;
    /* Flag to indicate DMA transaction is in progress */
} Ethernet_DescCh;

typedef Ethernet_DescCh Ethernet_TxChDesc;
typedef Ethernet_DescCh Ethernet_RxChDesc;

//*****************************************************************************
//
//!DMA Object that combines the  Tx and Rx Channel Descritor Structures  
//!  
//
//*****************************************************************************

typedef struct 
{
    Ethernet_TxChDesc   txDma[MAX_NUM_DMA_CHANNELS];
    Ethernet_RxChDesc  rxDma[MAX_NUM_DMA_CHANNELS];
    bool                        chIsInit[MAX_DMA_DIR][MAX_NUM_DMA_CHANNELS];
}Ethernet_DmaObj;

//*****************************************************************************
//
//! Base Address Definition Structure  
//! Stores the Base Address of the Subsystem and the EQOS module 
//
//*****************************************************************************

typedef struct  {
    uint32_t ss_base;
    uint32_t eqos_base;
 }Ethernet_BaseConfig;

//*****************************************************************************
//
//! Global Book keeping Structure maintained throughout
//!
//
//*****************************************************************************

typedef struct _Ethernet_Device{
    Ethernet_BaseConfig         baseAddresses;
    Ethernet_DmaObj             dmaObj;
    Handle                      handleApplication[ETHERNET_NUM_PORTS];
    /**< Phy number - useful if phy number is discovered                */
    uint32_t                    phyNum;
    Ethernet_EQOS_descriptor    *descs;
    Ethernet_EQOS_descriptor    *txDesc;
    Ethernet_EQOS_descriptor    *rxDesc;
    uint8_t                     *rxBuffer;
    uint8_t                     rxBuffIndex;
    //Maximum Size of Ethernet Packet
    uint32_t                    pktMTU;
    uint32_t                    devMagic;
    Ethernet_InitConfig         initConfig;
}Ethernet_Device;


//
//Define for Signalling Early Rx Completion
//
typedef enum
{
    //When Static it indicates that the routing is based on the 
    //Static configuration configured 
    ETHERNET_RX_DMA_QUEUE_STATIC        = 0x00U,

    //When Dynamic this bit indicates that the packets received in
    //Queue are routed to a particular DMA channel as decided
    //in the MAC Receiver based on the DMA channel number
    //programmed in the L3-L4 filter registers, or the Ethernet DA
    //address.
    ETHERNET_RX_DMA_QUEUE_DYNAMIC    = 0x01U  
} Ethernet_RxDMAQueueMode;

typedef struct {
           uint32_t reserved_0:4;
            uint32_t PTPQ:1;
           uint32_t reserved_1:7;
           uint32_t UPQ:1;
           uint32_t reserved_2:3;
           uint32_t MCBCQ:1;
           uint32_t reserved_3:3;
           uint32_t MCBCQEN:1;
           uint32_t reserved_4:1;
           uint32_t TPQC:1;
           uint32_t reserved_5:9;
} Ethernet_RxQControl;

typedef enum
{
    ETHERNET_CHANNEL_0 ,
    ETHERNET_CHANNEL_1 
} Ethernet_channelNum;

typedef enum
{
    ETHERNET_SET_CONFIG_VLAN_TX_OUTER ,
    ETHERNET_SET_CONFIG_VLAN_TX_INNER,
    ETHERNET_SET_CONFIG_VLAN_TX_CHANNEL_BASED,
    ETHERNET_SET_CONFIG_VLAN_TX_DOUBLE_VLAN,
    ETHERNET_SET_CONFIG_FILTER_VLAN_PERFECT,
    ETHERNET_SET_CONFIG_FILTER_VLAN_HASH,
    ETHERNET_SET_CONFIG_FILTER_VLAN_DVLAN,
    ETHERNET_SET_CONFIG_FILTER_L3_L4
}Ethernet_setConfigParam;

typedef enum
{
   ETHERNET_VLAN_TX_NONE,
   ETHERNET_VLAN_TX_DELETE,
   ETHERNET_VLAN_TX_INSERT,
   ETHERNET_VLAN_TX_REPLACE
}Ethernet_vlanTxTagControl;

typedef enum
{
    ETHERNET_VLAN_TYPE_C ,// CVLAN TYPE 0x8100 Tag
    ETHERNET_VLAN_TYPE_S
}Ethernet_vlanType;

typedef enum
{
    ETHERNET_VLAN_TAG_SOURCE_REG,
    ETHERNET_VLAN_TAG_SOURCE_DESC
}Ethernet_vlanTagSource;
//
//Defines the structure for VLAN Tag Configuration
//Transmit VLAN configuration 
//
typedef struct
{
    //16 bit VLAN ID
    uint16_t vlan_tag;
    //Whether the tag has to inserted/replaced/Deleted
    Ethernet_vlanTxTagControl  vlanTagControl;
    //S-VLAN or C-VLAN Type
    Ethernet_vlanType  vlanType;
}Ethernet_vlanConfig;

//
//Strucutre for Dual VLAN TX configuration
//Defines the two tags 
//
 typedef struct
{
     Ethernet_vlanConfig outerVLANConfig;
     Ethernet_vlanConfig innerVLANConfig;

 }Ethernet_doubleVLANConfig;

//
//Rx Filter Configuration
//
typedef enum
{
    ETHERNET_VLAN_PERFECT_FILTER_DISABLED,
    ETHERNET_VLAN_PERFECT_FILTER_ENABLED
}Ethernet_vlanRxPerfectFilterEnable;

typedef enum 
{
    ETHERNET_VLAN_PERFECT_FILTER_COMPARE_16BITS,
    ETHERNET_VLAN_PERFECT_FILTER_COMPARE_12BITS
}Ethernet_vlanRxPerfectFilterCompareMode;

typedef enum
{
   ETHERNET_VLAN_PERFECT_FILTER_TYPE_COMPARISON_ENABLED,
    ETHERNET_VLAN_PERFECT_FILTER_TYPE_COMPARISON_DISABLED
}Ethernet_vlanRxPerfectFilterTypeComparison;

typedef enum
{
    ETHERNET_VLAN_RX_FILTER_INNER_VLAN_DISABLED,
    ETHERNET_VLAN_RX_FILTER_INNER_VLAN_ENABLED
}Ethernet_vlanRxFilter_InnerVLANEnable;

typedef enum
{
    ETHERNET_DMA_CHANNELNUM_DISABLED,
    ETHERNET_DMA_CHANNELNUM_ENABLED
}Ethernet_DMA_channelEnableDisable;
        
typedef struct
{
    uint8_t filterid;//!<Index of VLAN Filter 0-3
    uint16_t vlanid;//!<VLAN ID to be compared with
    
    Ethernet_vlanRxPerfectFilterEnable vlanEnableDisable;//!<Filter is Enabled or Disabled
    Ethernet_vlanRxPerfectFilterCompareMode vlanFilterMode;//!<12 bit or 16 bit Comparison
    
    Ethernet_vlanRxPerfectFilterTypeComparison  vlanPerfectTypeComparisonDisable;//!<Disable or enable Type comparison 
    //Set if SVLAN comparison Reset for CVLAN
    Ethernet_vlanType vlanType;//!<CVLAN 0x8100 or SVLAN 0x88A8
    Ethernet_vlanRxFilter_InnerVLANEnable innerVLANEnabled;//!<InnerVLAN comparison Enable
    Ethernet_DMA_channelEnableDisable dmaChannelEnable;//!<DMA Channel number enable
    Ethernet_channelNum dmaChannelNum;//!< DMA Channel Num to which matching packets received should be Routed
}Ethernet_VLAN_Perfect_FilterParams;


//*****************************************************************************
//
//! Value that can be passed to Ethernet_setConfig() as the buffPtr
//! parameter.
//! If layer3ProtocolSel is 1(for IPv6) make sure only 
//! either of layer3IPDestAddressMatchEnable or layer3IPSrcAddressMatchEnable
//! is set
//
//*****************************************************************************


typedef struct
{
    uint8_t filterid;//!< Filter number 0-3
    Ethernet_DMA_channelEnableDisable dmaChannelEnable;//!< Channel Num Enabled/Disabled
    Ethernet_channelNum dmaChannelNum; //!< DMA Channel Number where the packets should be destined if passes
    uint8_t layer4DestinationPortMatchEnable; //!< If Set Enables Destination Port Matching for L4
    uint8_t layer4SourcePortMatchEnable; //!< If Set Enables Source Port Matching for L4 
    uint8_t layer4ProtocolSel;//!< 0- TCP 1-UDP
    uint16_t layer4DestinationPort;//!< 16bit Layer 4 Destination Port number to be matched
    uint16_t layer4SourcePort;//!<16bit Layer 4 Port Source Port number to be matched
    //For L3HDBM
     uint8_t layer3ProtocolSel; //!<0- IPv4 1- IPV6
    uint8_t layer3DestHigherBitsMask;//!< Number of Bits to be masked for Layer 3 Destination Address
    uint8_t layer3SrcHigherBitsMask;//!< Number of Bits to be masked for Layer 3 Source Address
    uint8_t layer3IPDestAddressMatchEnable; //!< Enables Comparison of IP Dest Address
    uint8_t layer3IPSrcAddressMatchEnable; //!<Enables Comparison of IP Src Address
    uint32_t layer3Address0; //!< Source Address for IPv4 or Bits[31:0] for IPv6
    uint32_t layer3Address1;//!< Destination Address for IPv4 or Bits[63:32] for IPv6
    uint32_t layer3Address2;//!< Bits[95:64] for IPv6 ,Unused for IPv4
    uint32_t layer3Address3;//!< Bits[127:96] for IPv6 ,Unused for IPv4
    

}Ethernet_L3_L4_FilterParams;

typedef struct {
           uint32_t L3PEN:1;
           uint32_t reserved_0:1;
           uint32_t L3SAM:1;
           uint32_t L3SAIM:1;
           uint32_t L3DAM:1;
           uint32_t L3DAIM:1;
           uint32_t L3HSBM:5;
           uint32_t L3HDBM:5;
           uint32_t L4PEN:1;
           uint32_t reserved_1:1;
           uint32_t L4SPM:1;
           uint32_t L4SPIM:1;
           uint32_t L4DPM:1;
           uint32_t L4DPIM:1;
           uint32_t reserved_2:2;
           uint32_t DMACHN:1;
           uint32_t reserved_3:3;
           uint32_t DMACHEN:1;           
           uint32_t reserved_4:3;
} Ethernet_L3_L4_Control;



//*****************************************************************************
//
//! Ethernet_initInterface
//! Initialise the Ethernet Interface with this API.
//! This is the First API of the Low Level Driver
//! that should be called by application/Higher layer stack.
//! Turns on the Clocks to Ethernet interface.
//! The Module Initialization is done in Ethernet_getHandle API the user must 
//! fill the Parameters for Init in the Struture returned by the API
//! 
//! \param interfaceConfig Configuration Structure to be used for initializing 
//! interface
//! \return Pointer to Init Config Structure to be used in Ethernet_getHandle() API 
//
//*****************************************************************************

extern Ethernet_InitConfig* Ethernet_initInterface( \
                                Ethernet_InitInterfaceConfig    interfaceConfig);
//*****************************************************************************
//
//! Ethernet_getInitConfig()
//! Builds a default Configuration of the Module
//! The Module Initialization is done in Ethernet_getHandle API the user must 
//! fill the Parameters for Init using the Ethernet_InitConfig Struture.
//! This API helps to fill the contents of the Init Config Structure
//! The Ethernet_InitConfig structure variables are populated to a known 
//! good values
//! Higher Layer/User can refer to this implementation for creating a different 
//! Configuration
//! \param pConfig Ethernet_InitConfig structure pointer could be returned 
//! Ethernet_InitInterface() API
//! \returns Nothing 
//
//*****************************************************************************

extern void Ethernet_getInitConfig(Ethernet_InitConfig *pConfig);
//*****************************************************************************
//
//! Ethernet_getHandle must be called before using the interface
//! For Sending and Receiving the Packets over Ethernet
//! Must pass the filled Init Configuration Structure(that is returned by 
//! _initInterface call  
//! This initializes the EQOS ethernet module as per the configuration 
//! structure provided.
//! The Driver moves to initialized state 
//! ready for Sending/Receiving the packets 
//! 
//! \param handleApplication - can be any application specific passed back during 
//! callbacks
//! \param Ethernet_InitConfig - Pointer to the Filled up Init Config Structure
//!  that is provided in _initInterface call
//! \param phEMAC - returns a handle(Pointer to Book Keeping Structure).
//! This must be provided in subsequent calls to SendPacket or other APIs
//! \return ETHERNET_RET_SUCCESS on Success 
//! 
//


//*****************************************************************************

extern uint32_t Ethernet_getHandle(Handle handleApplication,\
        Ethernet_InitConfig *ethernetInitConfigPtr,\
        Handle *ethernetHandlePtr);

//*****************************************************************************
//
//! Configure the Specified aspect of the Ethernet driver 
//! \param hEMAC handle returned by Ethernet_getHandle API
//! \param setParam the parameter to be set can be any of the following values:
//!    - \b ETHERNET_SET_CONFIG_VLAN_TX_OUTER - for setting outer VLAN  TX Parameters 
//!   in case of dual VLAN or single VLAN
//!    - \b ETHERNET_SET_CONFIG_VLAN_TX_INNER - for setting inner VLAN TX Parameters 
//!.    in case of inner VLAN 
//!    - \b ETHERNET_SET_CONFIG_VLAN_TX_DOUBLE_VLAN - configures both Inner and Outer VLAN
//!TX parameters
//!    - \b ETHERNET_SET_CONFIG_FILTER_VLAN_PERFECT - for configuring the VLAN Tag Perfect Filtering
//!    - \b ETHERNET_SET_CONFIG_FILTER_L3_L4 - for configuring L3,L4 Filters
//! \param buffPtr the pointer to the Parameter structure being set
//!    - if setParam is ETHERNET_SET_CONFIG_VLAN_TX_OUTER address of Ethernet_vlanConfig structure
//!    - if setParam is ETHERNET_SET_CONFIG_VLAN_TX_INNER address of Ethernet_vlanConfig structure
//!    - if setParam is ETHERNET_SET_CONFIG_VLAN_TX_DOUBLE_VLAN address of Ethernet_doubleVLANConfig structure
//!    - if setParam is ETHERNET_SET_CONFIG_FILTER_VLAN_PERFECT address of Ethernet_VLAN_Perfect_FilterParams structure
//!    - if setParam is ETHERNET_SET_CONFIG_FILTER_L3_L4 address of Ethernet_L3_L4_FilterParams structure
//! \param size size of the buffer being passed in buffPtr 
//!
//! 
//! \return ETHERNET_RET_SUCCESS in case of Success and other Error code in case of failure
//!
//*****************************************************************************

extern uint32_t Ethernet_setConfig(Handle hEMAC, \
            Ethernet_setConfigParam setParam, \
            void *buffPtr, \
            uint32_t size);

//*****************************************************************************
//
//! Configure PTP Currently not implemented
//!
//*****************************************************************************

extern uint32_t Ethernet_ConfigurePTP(Handle hEMAC);

//*****************************************************************************
//
//! Ethernet_sendPacket
//! This API is to be used to Send Packet(s) over Ethernet
//! This does a non Blocking Send over the Ethernet Interface
//! The Master DMA inbuilt with the module is Programmed to pick up the 
//! Provided buffers
//! and transfer to the Ethernet EQOS module TX FIFO. 
//! The Completion of DMA results in a Per channel DMA completion interrupt, 
//! for which there is a completion ISR
//! The ISR is used to signal the end of packet transmission.
//! The Buffers provided to the LLD over this API 
//! can be reclaimed as part of the TX.
//! The Higher layer has to prepare Packet Descriptors for each Buffer 
//! and chain them if needed
//! The Packet Boundaries can be specified in the flags using 
//! the ETHERNET_PKT_FLAG_SOP and ETHERNET_PKT_FLAG_SOP flags. 
//! If there is a single packet it must use
//! both the flags ORred in the packet flags.
//! On completion of Transmit of a Paket, 
//! the Driver picks up the Submitted Packet from Queue
//! and returns the Packet Structure as an argument to the Callback function.
//! Interrupt callback handling
//! \param   hEMAC- Handle to the EMAC returned in _Open call
//! \param pktPtr - Pointer to the Packet Descriptor structure.
//! If Multiple packets are to be transmitted
//! multiple Descriptors can be chained 
//! and single call to _SendPacket can be done
//! Even if a single packet is split into multiple buffers,
//!  multiple Descriptors to be chained
//! The First Descriptor should have SOP set and EOP should be set in the last 
//! The number of fragments must be specified
//! \return  ETHERNET_RET_SUCCESS on Success  or Error Codes on Failture
//
//*****************************************************************************

extern uint32_t Ethernet_sendPacket(Handle hEMAC, Ethernet_Pkt_Desc *pktPtr);


//*****************************************************************************
// 
//! Ethernet_getStatistics()
//! API To get the RMON Statistics 
//! Combines all the RMON Statistics in a single call 
//! 
//! \param hEMAC - Handle Provided by _Open call
//! \param statisticsPtr- the Pointer to Statistics structure to be filled 
//! \return ETHERNET_RET_SUCCESS on success 
//! 
//*****************************************************************************
extern uint32_t Ethernet_getStatistics(Handle hEMAC, 
                                    Ethernet_statistics *statisticsPtr);
//***************************************************************************
//
//! Ethernet_clearHandle
//! Not implemented Currently
//!
//**************************************************************************
extern void Ethernet_clearHandle(Handle *phEMAC);

//**************************************************************************
//! Ethernet_shutdownInterface()
//! Used to Shutdown the interface - To be implemented
//! No Arguments and Does not Return anything
//**************************************************************************
extern void Ethernet_shutdownInterface(void);

//**************************************************************************
//! Ethernet_clearStatistics()
//! Used to Clear the RMON Statistics - To be implemeted
//! \param phEMAC - Handle provided in Ethernet_getHandle API call
//! \return none
//**************************************************************************

extern void Ethernet_clearStatistics(Handle *ethernetHandlePtr);


//*********************************************************************
//! Ethernet_transmitISR()
//! Transmit Packet Completion Interrupt Service Routine
//! This low level driver currently uses the design where every transmit 
//! packet will have the Interrupt on Completion Set
//! For each packet provided by the application for Transmit the driver
//! forms a Transmit Descriptor which is submitted into the Transmit Ring 
//! of the EQOS module
//! Each packet's Interrupt on Completion flag is Set in the Tx Descriptor
//! For each packet Completion interrupt the ISR sees which channel 
//! has completion interrupt and handles the corresponding Tx Desc Queue 
//! The Packet completion is signalled to the application by calling 
//! the Callback function provided by the application
//! \return None
//************************************************************************ 

extern interrupt void Ethernet_transmitISR(void);


//************************************************************************
//! Ethernet_receiveISR()
//! Receive Packet Completion Interrupt Service Routine
//! for each buffer which is submitted to the EQOS channel Rx Ring
//! the IOC flag in the Received descriptor is set which 
//! results in an interrupt for each packet
//! The ISR pops the packet from Descriptor Queue DescQueue and 
//! calls the Rx Callback function registered by the Hiher layer
//! calls Ethernet_removePacketsFromRxQueue to implement the same
//! \return None
//***********************************************************************
extern interrupt void Ethernet_receiveISR(void);


//
//Application specific Callback functions
//

//****************************************************************************
//!
//! This function is a callback function called by the Driver when it needs 
//! a Packet for Receive Operation. 
//!This can be replaced by the Higher layer stack
//! application while integrating this layer of driver
//!  
//****************************************************************************


extern Ethernet_Pkt_Desc* Ethernet_getPacketBuffer(void);

//****************************************************************************
//!
//! This function is a callback function called by the Driver to handle the
//! Transmit Complete Callback that can be used to reclaim the buffer
//! Placeholder function that can be changed while initializing the Init 
//! Structure
//!  
//****************************************************************************

extern void Ethernet_releaseTxPacketBuffer(Handle handleApplication, \
    Ethernet_Pkt_Desc *pPacket);

//*****************************************************************************
//!
//! This callback function is called by the application 
//! when a Rx packet is available
//! Can be changed by the higher layer stack
//!
//*****************************************************************************
extern Ethernet_Pkt_Desc* Ethernet_receivePacketCallback(
        Handle handleApplication,\
        Ethernet_Pkt_Desc *pPacket);


extern void Ethernet_setConfigTimestampPTP(uint32_t base, uint32_t config,
                                    uint32_t subSecondInc);

extern uint32_t Ethernet_getConfigTimestampPTP(uint32_t base,
                                               uint32_t *subSecondInc);

extern void Ethernet_enableSysTimePTP(uint32_t base);

extern void Ethernet_disableSysTimePTP(uint32_t base);

extern void Ethernet_setSysTimePTP(uint32_t base, uint32_t seconds,
                                   uint32_t subSeconds);

extern void Ethernet_getSysTimePTP(uint32_t base, uint32_t *seconds,
                                   uint32_t *subSeconds);

extern void Ethernet_updateSysTimePTP(uint32_t base, uint32_t seconds,
                                      uint32_t subSeconds, bool addSub);

extern uint32_t Ethernet_getDepthAuxSnapshotFIFO(uint32_t base);

extern void Ethernet_setTimestampSWTrigger(uint32_t base, uint32_t trigSelect);

extern void Ethernet_configAuxTimestampTrigger(uint32_t base,
                                               uint32_t trigSelect,
                                               uint32_t trigValue);

extern void Ethernet_clearAuxSnapshotFIFO(uint32_t base);

extern void Ethernet_disableAuxSnapshot(uint32_t base, uint32_t trigInstance);

extern void Ethernet_enableAuxSnapshot(uint32_t base, uint32_t trigInstance);

extern void Ethernet_dequeueAuxSnapshotFIFO(uint32_t base, uint32_t *seconds,
                                            uint32_t *nanoSeconds);

extern void Ethernet_getAuxSnapshotTrigId(uint32_t base, uint32_t *id);

//*****************************************************************************
//!
//! Sets the action to be triggered when the target system time is reached.
//!
//! \param base is the base address of the controller.
//! \param target is the intended action upon reaching target time.
//!
//*****************************************************************************
extern void Ethernet_selectTargetInterruptOrPulsePPS(uint32_t base,
                                                     uint32_t target);
//*****************************************************************************
//!
//! Sets the PPS output in fixed pulse mode.
//!
//! \param base is the base address of the controller.
//! \param freq is the frequency of the output generated on the PPS pin.
//!
//*****************************************************************************
extern void Ethernet_setFixedModePPS(uint32_t base, uint32_t freq);

//*****************************************************************************
//!
//! Sets the PPS output in flexible/command mode.
//!
//! \param base is the base address of the controller.
//! \param freq is the frequency of the output generated on the PPS pin.
//!
//*****************************************************************************
extern void Ethernet_setFlexibleModePPS(uint32_t base);


//*****************************************************************************
//!
//! Sets the target and mode of PPS in one API.
//! Internally calls Ethernet_setTargetPPS(), Ethernet_setFixedModePPS() and
//! Ethernet_setFlexibleModePPS() to configure the PPS in one shot.
//!
//! \param base is the base address of the controller.
//! \param target is the intended action upon reaching target time.
//! \param mode is the PPS output mode.
//! \param fixedFreq is the frequency of the output generated on the PPS pin.
//!
//*****************************************************************************
extern void Ethernet_configurePPS(uint32_t base, uint32_t target, uint32_t mode,
                      uint32_t fixedFreq);

//*****************************************************************************
//
//! Sets the target system time at which the next PPS interrupt/pulse is
//! generated.
//!
//! \param base is the base address of the controller.
//! \param ppsNum is the instance of the PPS.
//! \param seconds is the second value of the desired target time.
//! \param subSeconds is the subseconds value of the desired target time.
//!
//! This function may be used to schedule an interrupt/PPS at some future time.
//! The time reference for the function is the IEEE 1588 time as returned by
//! TODO .  To generate an interrupt when the system
//! time exceeds a given value, call this function to set the desired time,
//! then EMACTimestampTargetIntEnable() to enable the interrupt.  When the
//! system time increments past the target time, an Ethernet interrupt with
//! status \b EMAC_INT_TIMESTAMP is generated.
//!
//! The accuracy of the interrupt timing depends on the Ethernet timer
//! update frequency and the subsecond increment value currently in use.  The
//! interrupt is generated on the first timer increment that causes the
//! system time to be greater than or equal to the target time set.
//!
//! \return None.
//
//*****************************************************************************
extern void Ethernet_setTargetTimePPS(uint32_t base, uint32_t ppsNum,
                                      uint32_t seconds, uint32_t subSeconds);

//*****************************************************************************
//!
//! Sets the interval and width of the pulse that is to be generated in
//! flexible/command PPS mode.
//!
//! \param base is the base address of the controller.
//! \param ppsNum is the instance of the PPS.
//! \param width is the pulse width.
//! \param interval is the pulse interval.
//!
//*****************************************************************************
extern void Ethernet_setPeriodPPS(uint32_t base, uint32_t ppsNum,
                                  uint32_t width, uint32_t interval);

//*****************************************************************************
//!
//! Programs the command to control the pulse/train start/stop behaviour
//! when PPS flexible/command mode is set.
//!
//! \param base is the base address of the controller.
//! \param ppsNum is the instance of the PPS.
//! \param ppsCmd is the command to be programmed.
//!
//*****************************************************************************
extern void Ethernet_setCmdPPS(uint32_t base, uint32_t ppsNum,
                               uint32_t ppsCmd);
// MDIO Functions

//***************************************************************************
//!
//! Configures the Parameters of MDIO/Station Management Interface
//! The MDIO interface is used to access the external PHY
//! \param base - Base Address of the Ethernet Module
//! \param clockHigh 
//!    - \b 0 - for Lower frequency ranges between 1Mhz to 2.5 Mhz range
//!    - \b 1- for higher frequency ranges 
//! as programmed in clockRange parameter
//!
//! \param clockRange- following are the allowed values
//!    - \b 0-5 with clockHigh 0 configures between 1 Mhz to 2.5 Mhz Range 
//!    - \b  0-7 with clockHigh 1 For higher Frequency ranges, 
//!         refer TRM other values are reserved
//! \param clause45Enable 
//!    - \b 0 -Operates Clause22 Mode
//!    - \b 1 - Operates in Clause45 Mode
//! \return None
//***************************************************************************
extern void Ethernet_configureMDIO(uint32_t base, 
                            uint32_t clockHigh,
                            uint32_t clockRange,
                            uint32_t clause45Enable
                            );

//************************************************************************
//! Configures the Address of PHY which is addressed by this MAC
//! For RevMII Interface mode, this API configures the address of
//! RevMII module as to be programmed from the other MAC
//! \param base Base Address of the Ethernet Module
//! \param phyAddr Address of the PHY
//!         0-31 are valid addresses. Other values are reserved
//! \return None
//***********************************************************************
extern void Ethernet_configurePHYAddress(uint32_t base,
                                  uint8_t phyAddr);
extern uint8_t Ethernet_getPHYMode(uint32_t base);

extern uint16_t Ethernet_readPHYRegister(uint32_t base,
                                 uint16_t regAddress);
extern void Ethernet_writePHYRegister(uint32_t base,
                               uint8_t regAddress,
                               uint16_t writeData);
                               

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
#endif
