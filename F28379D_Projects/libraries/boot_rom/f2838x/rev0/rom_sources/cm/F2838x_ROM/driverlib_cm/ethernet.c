//
// TITLE:  CM Subsystem Ethernet driver.
//
//###########################################################################
// $TI Release:  $
// $Release Date:  $
// $Copyright:  $
//  Version History Details:
//      24- Mar- 17: Initial Version 
//      9 - Jun- 17: 1588(PTP) Support Added
//      1- Aug-17  : Multichannel, Multibuffer, Threshold mode 
//                   MDIO Support Added,Other Bug Fixes
//      20-Sep-2017   : VLAN Support Added
//                     MDIO BugFixes,SA insertion and 
//                     CRC Pad configurability in TX
//      11- Oct-2017 Added Support for Programming Watchdog,RevMII
//      21- Nov- 2017 Early Tx and Rx buffer Handling, L3, L4 Filter support
//                    More doxygen comments and code cleanup,Fixes
//###########################################################################

#include "ethernet.h"
#include "sysctl.h"

//Change this define for Changing No of packets used by this driver
#define ETHERNET_NO_OF_RX_PACKETS   4U 
//Change this define for changing Packet buffer length
#define ETHERNET_MAX_PACKET_LENGTH 1538U    
#define ETHERNET_DMA_BURST_LENGTH   32U


#define ETHERNET_DEBUG  1U
#ifdef ETHERNET_DEBUG
// 
//These variables are for debug purpose
// Number of Time the Tx Packet Free Callback was called
uint32_t Ethernet_numTxPktFreeCallback=0U;
//Number of Times Rx Callback while handling RX packets
uint32_t Ethernet_numRxCallback=0U;
//Number of time Get packet buffer callback was called
uint32_t Ethernet_numGetPacketBufferCallback =0U ;
//Number of times Tx Completion ISR was called
uint32_t Ethernet_txInterruptCount =0U;
//Number of times Rx Completion ISR was called
uint32_t Ethernet_rxInterruptCount=0U;
//Number of Receive Context Descriptors received
uint32_t Ethernet_rxContextTimeStamp=0U;
//Number of times Misc Interrupt ISR was called
uint32_t Ethernet_genericInterruptCount =0U;
//Number of times Early Rx interrupt is received
uint32_t Ethernet_earlyRxInterruptCount =0U ;
//Number of times Early Tx interrupt is received
uint32_t Ethernet_earlyTxInterruptCount =0U;
//Number of times RX Generic interrupt is received for completion
uint32_t Ethernet_genericRxCompletionInterruptCount =0U ;
//Number of PHY Status change interrupt from RevMII block
uint32_t Ethernet_phyLinkStatusChangeInterruptCount =0U;
#endif
//Global Book keeping structure of the EMAC driver
Ethernet_Device     Ethernet_device_struct;
//Packet descriptor that we will use for sending the packet to driver
Ethernet_Pkt_Desc   Ethernet_pktDescriptorRX;

//
//We are defining the RxBuffer if the upper layer provides packets
//This can be removed 
uint8_t Ethernet_rxBuffer[ETHERNET_NO_OF_RX_PACKETS * \
                          ETHERNET_MAX_PACKET_LENGTH];
                          
//
// Internal function Declarations
//

//
//These are internal functions called by the Low Level Driver
//while implementing the APIs described above
//
//*************************************************************************
//! Ethernet_addPacketsIntoTxQueue()
//! @internal 
//! Arguments:
//! channelDescPtr - Pointer to the Channel Descriptor  Structure
//! to which the Packets should be Enqueued
//! Description:
//! There are two Queues maintained in the driver for each channel
//! 1. Wait Queue where the packets are queued up for software
//! 2. The Desc Queue is one from where it is submitted to Hardware
//! If the DMA Engine can service packets it picks up the packets from 
//! Desc Queue
//! This API scans through the Wait Queue and submits to Desc Queue for
//! hardware processing of the Tx Packets. This function prepares the Transmit 
//! descriptors for the EQOS DMA Engine
//! Returns none
//************************************************************************

void Ethernet_addPacketsIntoTxQueue(Ethernet_DescCh *channelDescPtr);
//*************************************************************************
//! Ethernet_removePacketsFromTxQueue()
//! @internal 
//! Arguments:
//! channelDescPtr - Pointer to the Channel Descriptor  Structure
//! from which the Packet has to be Dequeued
//! Description:
//! This function is called from the Transmit completion ISR to 
//! remove a packet from Desc Queue and call the Callback function registered
//! by the higher layer to signal the Transmit Completion
//! After calling the callback if there are packets pending in WaitQueue to be 
//! transmitted this routine submits them to the DescQueue and prepare
//!
//! Returns none
//************************************************************************

void Ethernet_removePacketsFromTxQueue(Ethernet_DescCh *channelDescPtr,
                                       Ethernet_CompletionMode completionMode);


//***********************************************************************
//! Ethernet_addPacketsIntoRxQueue
//! @internal
//! Arguments:
//! channelDescPtr - Pointer to Channel Descriptor Structure 
//! to which the Receive buffer has to be enqueued
//! This function calls the higher layer callback function to get the buffers 
//! for receive from application and queues them up in Desc Queue
//! For the Receive channels the Wait queue is not used only the Desc Queue
//! is used by the driver
//! Return: none
//***********************************************************************


void Ethernet_addPacketsIntoRxQueue(Ethernet_DescCh *channelDescPtr);

//**********************************************************************
//! Ethernet_removePacketsFromRxQueue()
//! @internal
//! channelDescPtr - Receive channel Desctiptor Pointer from which the 
//! Packet has to be Defines
//! completionMode
//! Descrition:
//! This function is called from the Receive Completion Interrupt Handler
//! This fills the PacketDescriptor Structure for handing over the packet 
//! And fills with the received packet details
//! Calls the Receive Packet Callback function provided by higher layer
//! Return: None
//**********************************************************************
void Ethernet_removePacketsFromRxQueue(Ethernet_DescCh *channelDescPtr, 
                            Ethernet_CompletionMode completionMode);


//*************************************************************************
//!
//! Ethernet_performPushPacketQueueChain()
//! @internal
//! Arguments: 
//! pktQueuePtr - Queue to which the packets has to be pushed
//! firstPktHdrPtr - Pointer to first packet
//! lastPktHdrPtr - Pointer to the last packet
//! Count - no of Packets to be pushed to Queue
//! Returns: none
//! Description:
//! This function is used by the Ethernet_sendPacket() API to push a chain of 
//! Packets to the Queue
//! ************************************************************************
static void Ethernet_performPushPacketQueueChain(
        Ethernet_PKT_Queue_T *pktQueuePtr, \
        Ethernet_Pkt_Desc *firstPktHdrPtr, \
        Ethernet_Pkt_Desc *lastPktHdrPtr, \
        uint32_t Count);
        
//**************************************************************************
//! Ethernet_performPopOnPacketQueue()
//! @internal 
//! Arguments: 
//! pktQueuePtr - Pointer to the Packet Queue
//! Description:
//! This function Dequeues a packet from Queue. This function is called in both 
//! Tx and Rx Paths. This function returns the element at the head of Queue
//! Return: Pointer to the packet that is popped
//***************************************************************************
static Ethernet_Pkt_Desc *Ethernet_performPopOnPacketQueue( \
                    Ethernet_PKT_Queue_T *pktQueuePtr);


/** ==========================================================================
 *  @n@b Ethernet_returnTopOfPacketQueue()
 *
 *  @b Description
 *  @n Return Front element of a queue
 *
 *  @b Arguments
 *  @verbatim
        pktQueuePtr      pointer to packet queue
    @endverbatim
 *
 *  <b> Return Value </b>  Pointer to EMAC packet
 *
 *  <b> Pre Condition </b>
 *  @n  None
 *
 *  <b> Post Condition </b>
 *  @n  None
 *
 *  @b Example
 *  @verbatim
        ETHERNET_PKT_QUEUE_T *pktQueuePtr;
        ETHERNET_returnTopOfPacketQueue( pktQueuePtr );
    @endverbatim
 * ============================================================================
 */
static Ethernet_Pkt_Desc *Ethernet_returnTopOfPacketQueue( \
            Ethernet_PKT_Queue_T *pktQueuePtr);

                    
//***************************************************************************
//! Ethernet_performPushOnPacketQueue ()
//! @ internal
//! This function does a Enqueue on Packet Queue 
//! It does an enqueue which adds a packet to the Rear of the queue 
//! This is called in both Tx and Rx Paths
//! Return: None
//***************************************************************************
static void Ethernet_performPushOnPacketQueue(Ethernet_PKT_Queue_T *pq,\
        Ethernet_Pkt_Desc *pPktHdr);

//**************************************************************************
//!    Ethernet_resetModule()
//! @Internal
//! Arguments:
//! baseAddress - Base Address of EQOS module in the device
//! This function does a Soft Reset of the EQOS core and waits till the soft 
//! Reset is complete
//! Return - None    
//*************************************************************************** 
void Ethernet_resetModule(uint32_t baseAddress);


//***************************************************************************
// Ethernet_enableDmaInterrupt()
//!  This internal function helps to program
//! DMA_CH0_INTERRUPT_ENABLE register of the EQOS Module
//! Arguments:
//! baseAddress - Base Address of the EQOS Ethernet modules
//! channelNum - Channel number which has to be programmed 0 or 1
//! flags - Flags of the Register
//! Returns none
//**************************************************************************
void Ethernet_enableDmaInterrupt(uint32_t baseAddress, \
            uint32_t channelNum, uint32_t flags);

void Ethernet_enableMACInterrupt(
                                uint32_t base,
                                uint32_t flags);
            
            
            
//**************************************************************************
//! Ethernet_setMTLTxQueueOpMode ()
//! This internal function is used to program the MTL_OPERATION_MODE 
//! register 
//! Arguments:
//! baseAddress - baseAddress of the EQOS module
//! txSchedulingAlgoritm - Tx Scheduling Algorithm
//!     ETHERNET_MTL_OPERATON_MODE_SCHALG_WRR  
//!     ETHERNET_MTL_OPERATON_MODE_SCHALG_WFQ  
//!     ETHERNET_MTL_OPERATON_MODE_SCHALG_DWRR
//!     ETHERNET_MTL_OPERATON_MODE_SCHALG_STRICT_PRIORITY
//! rxAribtrationAlgorithm: Rx Arbitration Algorithm
//!     ETHERNET_MTL_OPERATION_MODE_RAA_SP   
//!     ETHERNET_MTL_OPERATION_MODE_RAA_WSP   
//************************************************************************

            
void Ethernet_setMTLOpmode(uint32_t base,
        uint32_t txSchedulingAlgoritm,
        uint32_t rxAribtrationAlgorithm);
        
//**************************************************************************
//! Ethernet_setMTLTxQueueOpMode ()
//! This internal function is used to program the MTL_TXQ0_OPERATION_MODE 
//! register of the given channel
//! Arguments:
//! baseAddress - baseAddress of the EQOS module
//! queueNum - Queue Number 0 or 1
//! threshold_val - Threshold Value can be any of the following value
//!     ETHERNET_MTL_TXQ0_OPERATION_MODE_TTC_32  
//!     ETHERNET_MTL_TXQ0_OPERATION_MODE_TTC_64  
//!     ETHERNET_MTL_TXQ0_OPERATION_MODE_TTC_96
//!     ETHERNET_MTL_TXQ0_OPERATION_MODE_TTC_128
//!     ETHERNET_MTL_TXQ0_OPERATION_MODE_TTC_192
//!     ETHERNET_MTL_TXQ0_OPERATION_MODE_TTC_256
//!     ETHERNET_MTL_TXQ0_OPERATION_MODE_TTC_384
//!     ETHERNET_MTL_TXQ0_OPERATION_MODE_TTC_512 
//! queue_size:
//!     Size fo the Tx Queue
//!     can be any of the following values
//!     ETHERNET_MTL_Q_OP_MODE_QSIZE_256   
//!     ETHERNET_MTL_Q_OP_MODE_QSIZE_512   
//!     ETHERNET_MTL_Q_OP_MODE_QSIZE_768   
//!     ETHERNET_MTL_Q_OP_MODE_QSIZE_1024  
//!     ETHERNET_MTL_Q_OP_MODE_QSIZE_1280  
//!     ETHERNET_MTL_Q_OP_MODE_QSIZE_1536  
//!     ETHERNET_MTL_Q_OP_MODE_QSIZE_1792  
//!     ETHERNET_MTL_Q_OP_MODE_QSIZE_2048  
//!     ETHERNET_MTL_Q_OP_MODE_QSIZE_4096  
//! storeForward
//!      1 for Store and Forward Mode
//!      0 for Threshold Mode
//************************************************************************
void Ethernet_setMTLTxQueueOpMode(uint32_t baseAddress,uint32_t queueNum,\
        uint32_t threshold_val,uint32_t queue_size,uint32_t storeForward);
        
//*************************************************************************
//! Ethernet_setMTLRxQueueOpMode
//! Arguments:
//! baseAddress - baseAddress of the EQOS module
//! queueNum - can be 0 or 1 
//! threshold_val - 
//!    can be any of the following values:
//!     ETHERNET_MTL_Q_OP_MODE_QSIZE_256  
//!     ETHERNET_MTL_Q_OP_MODE_QSIZE_512  
//!     ETHERNET_MTL_Q_OP_MODE_QSIZE_768  
//!     ETHERNET_MTL_Q_OP_MODE_QSIZE_1024 
//!     ETHERNET_MTL_Q_OP_MODE_QSIZE_1280 
//!     ETHERNET_MTL_Q_OP_MODE_QSIZE_1536 
//!     ETHERNET_MTL_Q_OP_MODE_QSIZE_1792 
//!     ETHERNET_MTL_Q_OP_MODE_QSIZE_2048 
//!     ETHERNET_MTL_Q_OP_MODE_QSIZE_4096 
//! QueueSize 
//!     can be 
//!     ETHERNET_DMA_CHx_RX_CONTROL_RBSZ_1K 1024U
//!     ETHERNET_DMA_CHx_RX_CONTROL_RBSZ_2K 2048U
//! storeForward
//!     1 for Store and Forward moe
//!     0 for Threshold
//! Retuns: None
//**************************************************************************

void Ethernet_setMTLRxQueueOpMode(uint32_t baseAddress,uint32_t queueNum,\
            uint32_t threshold_val,uint32_t queue_size,uint32_t storeForward);
            
//*************************************************************************
// Ethernet_writeTxDescListAddress
//! @internal function:
// params: 
//! baseAddress: Base Address of EQOS module
//! channelNum : 0 or 1, the channel number of the register to be configured 
//! write_data : pointer to the Descriptor
//! Function to write to DMA_CHx_TXDESC_LIST_ADDRESS register
//! This configures the beginning of the Tx Descriptor ring
//! Returns : none
//*************************************************************************

void Ethernet_writeTxDescListAddress(uint32_t baseAddress,\
            uint32_t channelNum, Ethernet_EQOS_descriptor* write_data);
            
//*************************************************************************
// Ethernet_writeTxDescTailPointer
//! @internal function:
// params: 
//! baseAddress: Base Address of EQOS module
//! channelNum : 0 or 1, the channel number of the register to be configured 
//! write_data : pointer to the Descriptor
//! Function to write to DMA_CHx_TXDESC_TAIL_POINTER register
//! This configures the end of Tx Descriptor Ring
//! Returns : none
//*************************************************************************

void Ethernet_writeTxDescTailPointer(uint32_t baseAddress, \
        uint32_t channelNum, Ethernet_EQOS_descriptor* write_data);
            
//*************************************************************************
// Ethernet_writeRxDescListAddress
//! @internal function:
// params: 
//! baseAddress: Base Address of EQOS module
//! channelNum : 0 or 1, the channel number of the register to be configured 
//! write_data : pointer to the Descriptor
//! Function to write to DMA_CHx_RXDESC_LIST_ADDRESS register
//! This configures the beginning of Rx Descriptor Ring
//! Returns : none
//*************************************************************************
       
void Ethernet_writeRxDescListAddress(uint32_t baseAddress, \
        uint32_t channelNum, Ethernet_EQOS_descriptor* write_data);
        
//*************************************************************************
// Ethernet_writeRxDescTailPointer
//! @internal function:
// params: 
//! baseAddress: Base Address of EQOS module
//! channelNum : 0 or 1, the channel number of the register to be configured 
//! write_data : pointer to the Descriptor
//! Function to write to DMA_CHx_RXDESC_TAIL_POINTER register
//! This configures the beginning of Rx Descriptor Ring
//! Returns : none
//*************************************************************************

void Ethernet_writeRxDescTailPointer(uint32_t baseAddress, \
        uint32_t channelNum, Ethernet_EQOS_descriptor* write_data);
        
//*************************************************************************
// Ethernet_writeTxDMAControl
//! @internal function:
// params: 
//! baseAddress: Base Address of EQOS module
//! channelNum : 0 or 1, the channel number of the register to be configured 
//! burst_Length: Burst Length of the Transfers
//! Function to write to DMA_CHx_TX_CONTROL register
//! This configures the end of Rx Descriptor Ring
//! Returns : none
//*************************************************************************

void Ethernet_writeTxDMAControl(uint32_t baseAddress,\
            uint32_t channelNum,int burst_Length, uint8_t earlyTransmitInterruptEnable );
            
//*************************************************************************
// Ethernet_writeRxDMAControl
//! @internal function:
// params: 
//! baseAddress: Base Address of EQOS module
//! channelNum : 0 or 1, the channel number of the register to be configured 
//! burst_Length: Burst Length of the Transfers
//! dmaBufferSize : 
//!         ETHERNET_DMA_CHx_RX_CONTROL_RBSZ_1K 
//!         ETHERNET_DMA_CHx_RX_CONTROL_RBSZ_2K
//! Function to write to DMA_CHx_RX_CONTROL register
//! 
//! Returns : none
//*************************************************************************

void Ethernet_writeRxDMAControl(uint32_t baseAddress,uint32_t channelNum,\
            int burst_Length,uint32_t dmaBufferSize,uint8_t earlyReceiveInterruptEnable);

//*************************************************************************
// Ethernet_setTxDescRingLength
//! @internal function:
// params: 
//! baseAddress: Base Address of EQOS module
//! channelNum : 0 or 1, the channel number of the register to be configured 
//! ringLength : Length of Descriptor Ring
//! Function to write to DMA_CH0_TXDESC_RING_LENGTH register
//! This configures the length of Tx Descriptor Ring 
//! The function subtracts by 1 before programming
//! Returns : none
//*************************************************************************

            
void Ethernet_setTxDescRingLength(uint32_t baseAddress, uint32_t channelNum,\
            uint32_t ringLength);
            

//*************************************************************************
// Ethernet_setRxDescRingLength
//! @internal function:
// params: 
//! baseAddress: Base Address of EQOS module
//! channelNum : 0 or 1, the channel number of the register to be configured 
//! ringLength : Length of Descriptor Ring
//! Function to write to DMA_CH0_RXDESC_RING_LENGTH register
//! This configures the length of Rx Descriptor Ring 
//! The function subtracts by 1 before programming
//! Returns : none
//*************************************************************************

void Ethernet_setRxDescRingLength(uint32_t baseAddress, uint32_t channelNum,\
            uint32_t ringLength);
            
//*************************************************************************
// Ethernet_setMACAddr
//! @internal function:
// params: 
//! base: Base Address of EQOS module
//! instanceNum : 0-3 , the intance of MAC address register to be programmed
//! MacAddr High : Higher two bytes of MAC address in the lower two bytes
//! Higher 16 bits are ignored
//! MacAddrLow : Lower 4 bytes of the MAC address 
//! channelNum DMA Channel number to which this is mapped
//! Function to prgram the MAC Address
//! Returns : none
//************************************************************************
void Ethernet_setMACAddr(uint32_t base, uint8_t instanceNum,\
        uint32_t MACAddrHigh, uint32_t MACAddrLow,uint8_t channelNum);
        
//*************************************************************************
// Ethernet_initTxChannel
//! @internal function:
// params: 
//! chInfo : Pointer to the Channel info Structure  for the channel to be init
//! Returns : none
//! Initializes tehe Tx Channel and makes it ready for transmit
//************************************************************************

static uint32_t Ethernet_initTxChannel(Ethernet_ChInfo *chInfo);

//*************************************************************************
// Ethernet_initRxChannel
//! @internal function:
// params: 
//! chInfo : Pointer to the Channel info Structure  for the channel to be init
//! Returns : none
//! Initializes tehe Rx Channel and makes it ready for transmit
//************************************************************************

static uint32_t Ethernet_initRxChannel(Ethernet_ChInfo *chInfo);

//*************************************************************************
// Ethernet_enableMACRxQ
//! @internal function:
// params: 
//! base - Base Address
//! QueueNumber - queueNumber to be enabled
//! Returns : none
//! Initializes the Rx Queue at MAC
//************************************************************************

void Ethernet_enableMACRxQ(uint32_t base,\
                                            uint32_t queueNumber);



//Wrapper Substem Routines
void Ethernet_setSSControlStatus(uint32_t base, uint32_t phyTypeSel, \
        uint32_t LoopbackModeClkSel, uint32_t ClkSourceSelect, \
        uint32_t FlowControlEnable);

void Ethernet_configureRevMIIAddress(uint32_t subSystembase,
                               uint8_t localPHYAddress,
                               uint8_t remotePHYAddress);

void Ethernet_setFixedInnerVLANParams(uint32_t base,
                                                        uint16_t vlanTag,
                                                        uint8_t vlanTagControl,
                                                        uint8_t vlanType
                                                        );

void Ethernet_setFixedOuterVLANParams(uint32_t base,
                                                        uint16_t vlanTag,
                                                        uint8_t vlanTagControl,
                                                        uint8_t vlanType
                                                        );
void Ethernet_setVLANPerfectFilter(
                                                                                   uint32_t base,
                                                                                   uint8_t filterId,
                                                                                   uint16_t vlanId,
                                                                                   uint8_t vlanEnable,
                                                                                   uint8_t vlanFilterMode,
                                                                                   uint8_t vlanTypeComparisonEnable,
                                                                                   uint8_t vlanType,
                                                                                   uint8_t innerVLANEnabled,
                                                                                   uint8_t dmaChannelEnable,
                                                                                   uint8_t channelNum);

void Ethernet_setMACPacketFilter(uint32_t base,
                                                      uint32_t flags);

void Ethernet_clearDMAChannelInterrupt(
    uint32_t base,
    uint32_t channelNum,
    uint32_t flags);

void Ethernet_setDMAMode(
    uint32_t base, \
    Ethernet_dmaMode dmaMode);

void Ethernet_setMACConfiguration(uint32_t base,\
        uint32_t flags);


void Ethernet_clearMACConfiguration(uint32_t base, \
                    uint32_t flags);

uint32_t Ethernet_configureL3L4Filter(uint32_t base, 
                                                                    Ethernet_L3_L4_FilterParams filterParams);

void Ethernet_configureIPv6FilterAddress(uint32_t base, 
                                                                                                                uint8_t filterid,
                                                                                                                uint32_t word0,
                                                                                                                 uint32_t word1, 
                                                                                                                 uint32_t word2, 
                                                                                                                 uint32_t word3);

void Ethernet_configureIPv4FilterSourceAddress
                    (uint32_t base, 
                      uint8_t filterid, 
                      uint32_t address);

void Ethernet_configureIPv4FilterDestinationAddress
            (uint32_t base,
            uint8_t filterid, 
            uint32_t address);

void Ethernet_configureLayer4FilterDstAddress(
                        uint32_t base,
                        uint8_t filterid,
                        uint16_t dstAddress);

void Ethernet_configureLayer4FilterSrcAddress(
            uint32_t base,
            uint8_t filterid,
            uint16_t srcAddress);

void Ethernet_configureL3L4FilterControl(
                uint32_t base, 
                 uint8_t filterid,
                 uint32_t flags);

uint16_t Ethernet_getRxERICount(uint32_t base, uint32_t channelNum);


//
//External Function Definitions
//        
        
        
        
Ethernet_InitConfig* Ethernet_initInterface(
                                           Ethernet_InitInterfaceConfig interfaceConfig
                                            )
{
    
    memset(&Ethernet_device_struct,0,sizeof(Ethernet_Device));
    Ethernet_device_struct.baseAddresses.ss_base = interfaceConfig.ssbase;
    Ethernet_device_struct.baseAddresses.eqos_base = interfaceConfig.eqos_base;
    
    //Enable the Clocks for Ethernet Module in the Clock tree
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_ENET);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_UDMA);

    //PHY interface mode has to be set in Wrapper before the 
    //EQOS module is released out of reset 
    
    HWREG(Ethernet_device_struct.baseAddresses.ss_base + ETHERNETSS_O_CTRLSTS)\
                        =(((ETHERNETSS_CTRLSTS_WRITE_KEY_VALUE << \
                        ETHERNETSS_CTRLSTS_WRITE_KEY_S)& \
                        ETHERNETSS_CTRLSTS_WRITE_KEY_M) \
                        | (interfaceConfig.phyMode \
                        <<  ETHERNETSS_CTRLSTS_PHY_INTF_SEL_S)
                        | (interfaceConfig.clockSel\
                        <<ETHERNETSS_CTRLSTS_CLK_SRC_SEL_S));

    //RevMII address is latched on reset of the EQOS module
    // so configure before releasing reset for EQOS module
    if(interfaceConfig.phyMode == ETHERNETSS_PHY_INTF_SEL_REVMII)
    {
        Ethernet_configureRevMIIAddress(EMAC_SS_BASE,\
                                interfaceConfig.localPhyAddress,\
                                interfaceConfig.remotePhyAddress);
     }
    
    SysCtl_resetPeripheral(SYSCTL_PERIPH_RES_ENET);
   
    Ethernet_resetModule(Ethernet_device_struct.baseAddresses.eqos_base);
   
    
    Ethernet_device_struct.rxBuffIndex = 0U;

    // Return the pointer to Init initConfig structure that should be used by 
    // the application to provide the Initial configuration in the Open call
    //It can be built with Ethernet_BuildInitConfigAPI
    return &Ethernet_device_struct.initConfig;
}

void Ethernet_getInitConfig(Ethernet_InitConfig *configPtr)
{

    uint32_t i;
    //EMAC Subsystem Wrappter Settings 
    configPtr->emacSSConfig.clkSrcSel = \
                ETHERNETSS_CTRLSTS_CLK_SRC_SEL_EXTERNAL;
    configPtr->emacSSConfig.flowControlEn = \
                ETHERNETSS_CTRLSTS_FLOW_CTRL_EN_DISABLED;
    configPtr->emacSSConfig.LoopBackModeClkSel =  \
        ETHERNETSS_CTRLSTS_LMCLKSEL_NORMAL;
    configPtr->emacSSConfig.phyIntfSel = ETHERNETSS_CTRLSTS_PHY_INTF_SEL_GMII;
    //DMA Settings //1:1 Ratio
    configPtr->priorityRatio=ETHERNET_DMA_OPERATION_MODE_PR_TX1_RX1; 
    configPtr->transmitArbitrationAlgorithm = \
                    ETHERNET_DMA_OPERATION_MODE_DA_ROUND_ROBIN;
                    
    //MTL Operation Settings
    configPtr->txSchedulingAlgoritm = \
                            ETHERNET_MTL_OPERATON_MODE_SCHALG_STRICT_PRIORITY;
    //Strict Priority
    configPtr->receiveArbitrationAlgorithm = \
                            ETHERNET_MTL_OPERATION_MODE_RAA_SP; 

    //MAC Configuration Settings
    configPtr->linkMode = ETHERNET_MAC_CONFIGURATION_DM_FULL_DUPLEX;
    configPtr->loopbackMode = ETHERNET_MAC_CONFIGURATION_LM_LOOPBACK_DISABLED;
    
    
    //MAC Filter Configuration Seetings 
    configPtr->macFilterConfig.promiscuousMode    =   ETHERNET_DISABLE;
    configPtr->macFilterConfig.hashUnicast            =   ETHERNET_DISABLE;
    configPtr->macFilterConfig.hashMulticast      =   ETHERNET_DISABLE;
    configPtr->macFilterConfig.daInverseFilter        =   ETHERNET_DISABLE;
    configPtr->macFilterConfig.passAllMulticast       =   ETHERNET_DISABLE;
    configPtr->macFilterConfig.disableBroadCastPackets = ETHERNET_DISABLE;
    configPtr->macFilterConfig.passControlPackets =  
                        ETHERNET_MAC_PACKET_FILTER_PCF_FILTER_ALL_CTRL;
    configPtr->macFilterConfig.saInverseFilter    =       ETHERNET_DISABLE;
    configPtr->macFilterConfig.saFilterEnable =       ETHERNET_DISABLE;
    configPtr->macFilterConfig.hashPerfectFilter  =       ETHERNET_DISABLE;
    configPtr->macFilterConfig.vlanFilterEnable =         ETHERNET_DISABLE;
    configPtr->macFilterConfig.l3L4FilterEnable =         ETHERNET_DISABLE;
    configPtr->macFilterConfig.dropNonTCP =            ETHERNET_DISABLE;
    configPtr->macFilterConfig.receiveAll =           ETHERNET_ENABLE;

    /*
    Assign number of Packets for Buffer Allocation
    These values should be changed as per application needs
    Ideally the buffers should be provided by the upper layer
    But here we maintain packet buffer for Receive path
    TX Path is provided by Application

    */
    
    configPtr->noofPacketsRxBuffer        =   ETHERNET_NO_OF_RX_PACKETS;
    configPtr->maxPacketLengthRxBuffer = ETHERNET_MAX_PACKET_LENGTH;

    /*Tx and RX DMA Burst Length*/

    //Max Packet Size
    configPtr->pktMTU = ETHERNET_MAX_PACKET_LENGTH;
    configPtr->numChannels = MAX_NUM_DMA_CHANNELS;
    /*Init of TX DMA Channels*/
    for(i=0;i<configPtr->numChannels;i++)
    {
        configPtr->chInfo[ETHERNET_CH_DIR_TX][i].burstLength = \
                            ETHERNET_DMA_BURST_LENGTH;
        configPtr->chInfo[ETHERNET_CH_DIR_TX][i].queueThreshold = \
                            ETHERNET_MTL_TXQ0_OPERATION_MODE_TTC_32;
        configPtr->chInfo[ETHERNET_CH_DIR_TX][i].dmaQueueSize =  \
                            ETHERNET_MTL_Q_OP_MODE_QSIZE_512; 
        configPtr->chInfo[ETHERNET_CH_DIR_TX][i].storeNForward = \
                            ETHERNET_MTL_TXQ_OPMODE_TSF_ENABLE ;
        configPtr->chInfo[ETHERNET_CH_DIR_TX][i].chDir = ETHERNET_CH_DIR_TX;
        configPtr->chInfo[ETHERNET_CH_DIR_TX][i].numBD = \
                            EQOS_DESCRIPTORS_NUM_TX_PER_CHANNEL;
        configPtr->chInfo[ETHERNET_CH_DIR_TX][i].chNum = i;
    }
    /*Init of Rx DMA Channels*/ 
    for(i=0;i<configPtr->numChannels;i++)
    {
        configPtr->chInfo[ETHERNET_CH_DIR_RX][i].burstLength = \
                            ETHERNET_DMA_BURST_LENGTH;
        configPtr->chInfo[ETHERNET_CH_DIR_RX][i].queueThreshold = \
                            ETHERNET_MTL_RXQ0_OPERATION_MODE_RTC_32;
        configPtr->chInfo[ETHERNET_CH_DIR_RX][i].dmaQueueSize = \
                            ETHERNET_MTL_Q_OP_MODE_QSIZE_2048;
        configPtr->chInfo[ETHERNET_CH_DIR_RX][i].dmaBufferSize = \
                            ETHERNET_DMA_CHx_RX_CONTROL_RBSZ_2K;
        configPtr->chInfo[ETHERNET_CH_DIR_RX][i].storeNForward =\
                            ETHERNET_MTL_RX_Q_OP_MODE_RSF_ENABLE ;
        configPtr->chInfo[ETHERNET_CH_DIR_RX][i].chDir = ETHERNET_CH_DIR_RX;
        configPtr->chInfo[ETHERNET_CH_DIR_RX][i].numBD = \
                            EQOS_DESCRIPTORS_NUM_RX_PER_CHANNEL;
        configPtr->chInfo[ETHERNET_CH_DIR_RX][i].chNum = i;
    }
    //PerCh interrupts are not routed to sbd_intr 
    configPtr->dmaMode.InterruptMode = ETHERNET_DMA_MODE_INTM_MODE1;
    
    //RX Get Buffer Callback
    configPtr->pfcbGetPacket = &Ethernet_getPacketBuffer;
     // Tx Packet completion callback
    configPtr->pfcbFreePacket = &Ethernet_releaseTxPacketBuffer;
     // Rx Packet Completion callback
     configPtr->pfcbRxPacket = &Ethernet_receivePacketCallback;
    
    
}

uint32_t Ethernet_sendPacket(Handle hEMAC, Ethernet_Pkt_Desc *pktPtr)
{
    Ethernet_Device *devicePtr;
    uint32_t          fragcnt,pktlen;
    Ethernet_Pkt_Desc        *pktLastPtr;
    Ethernet_DescCh     *channelDescPtr;
    Ethernet_DmaObj *dmaObj;
    Ethernet_ChInfo*   txChan;
    
    devicePtr = (Ethernet_Device *)hEMAC;

    if(!devicePtr || devicePtr->devMagic != ETHERNET_DRV_DEVMAGIC)
        return ETHERNET_ERR_INVALID_HANDLE;
    if(!pktPtr)
        return ETHERNET_ERR_INVALID_PARAM;

    /* Do some packet validation */
    if (!(pktPtr->flags & ETHERNET_PKT_FLAG_SOP))
        return (ETHERNET_ERR_BAD_PACKET);

    if (pktPtr->pktLength > devicePtr->pktMTU)
        return (ETHERNET_ERR_BAD_PACKET);

    /* Count the number of frags in this packet */
    fragcnt = 1;
    pktlen  = pktPtr->pktLength;

    pktLastPtr = pktPtr;
    while (!(pktLastPtr->flags & ETHERNET_PKT_FLAG_EOP))
    {
        if (!pktLastPtr->nextPacketDesc)
            return (ETHERNET_ERR_INVALID_PARAM);
        pktlen -= pktLastPtr->bufferLength;
        pktLastPtr = pktLastPtr->nextPacketDesc;
        fragcnt++;

        /* At this point we can't have another SOP */
        if (pktLastPtr->flags & ETHERNET_PKT_FLAG_SOP)
            return (ETHERNET_ERR_BAD_PACKET);
    }


    /* Make sure pktLength and validLength agree */
    if (pktlen != pktLastPtr->bufferLength)
        return (ETHERNET_ERR_BAD_PACKET);

    /* The final packet frag must be the last in the list */
    if (pktLastPtr->nextPacketDesc)
        return (ETHERNET_ERR_BAD_PACKET);

    /* The frag count must be correct */
    if (fragcnt != pktPtr->numPktFrags)
        return (ETHERNET_ERR_BAD_PACKET);

    
    dmaObj  = &devicePtr->dmaObj;
    txChan  = \
    &devicePtr->initConfig.chInfo[ETHERNET_CH_DIR_TX][pktPtr->pktChannel];
    /* Get a local pointer to the descriptor channel */
    channelDescPtr = &(dmaObj->txDma[pktPtr->pktChannel]);
    channelDescPtr->chInfo = txChan;

    /* Make sure this packet does not have too many frags to fit */
    if (fragcnt > channelDescPtr->descMax)
        return (ETHERNET_ERR_BAD_PACKET);

    /*
     * Queue and packet and service transmitter
     */

    Ethernet_performPushPacketQueueChain(&channelDescPtr->waitQueue, pktPtr, \
                            pktLastPtr, fragcnt);
    Ethernet_addPacketsIntoTxQueue(channelDescPtr);
    
    

    //HWREG(Ethernet_device_struct.baseAddresses.eqos_base+ \
    //        ETHERNET_O_DMA_CH0_TX_CONTROL + (ETHERNET_CHANNEL_OFFSET*0)) \
    //            |=ETHERNET_DMA_CH0_TX_CONTROL_ST ;
  

    
   
    return ETHERNET_RET_SUCCESS;

}

interrupt void Ethernet_transmitISR(void)
{

    Ethernet_TxChDesc *txChan;

    
        if(HWREG(Ethernet_device_struct.baseAddresses.eqos_base + \
        ETHERNET_O_DMA_CH0_STATUS) & ETHERNET_DMA_CH0_STATUS_TI)
        {
            txChan = &Ethernet_device_struct.dmaObj.txDma[ETHERNET_DMA_CHANNEL_NUM_0];
            Ethernet_removePacketsFromTxQueue(txChan,
                ETHERNET_COMPLETION_NORMAL);
            
            //Clear the interrupt at Module 
            Ethernet_clearDMAChannelInterrupt(\
            Ethernet_device_struct.baseAddresses.eqos_base,\
            ETHERNET_DMA_CHANNEL_NUM_0,
            ETHERNET_DMA_CH0_STATUS_TI
            );
                    
        }
    
        
        if(HWREG(Ethernet_device_struct.baseAddresses.eqos_base + \
        ETHERNET_CHANNEL_OFFSET + \
        ETHERNET_O_DMA_CH0_STATUS) & ETHERNET_DMA_CH0_STATUS_TI)
        {
            txChan = &Ethernet_device_struct.dmaObj.txDma[1];
            Ethernet_removePacketsFromTxQueue(txChan,
                        ETHERNET_COMPLETION_NORMAL);
            
           //Clear the interrupt at module 
           Ethernet_clearDMAChannelInterrupt(\
            Ethernet_device_struct.baseAddresses.eqos_base,\
            ETHERNET_DMA_CHANNEL_NUM_1,
            ETHERNET_DMA_CH0_STATUS_TI
            );
        
        }
    
        
#ifdef ETHERNET_DEBUG   
    Ethernet_txInterruptCount++;
#endif
}

interrupt void Ethernet_receiveISR(void)
{
    //Call the callback function
    //It is expected to replenish the Buffer for the packet just received

    Ethernet_RxChDesc *rxChan;

    
        if(HWREG(Ethernet_device_struct.baseAddresses.eqos_base + \
        ETHERNET_O_DMA_CH0_STATUS) & ETHERNET_DMA_CH0_STATUS_RI)
        {
            rxChan = &Ethernet_device_struct.dmaObj.rxDma[ETHERNET_DMA_CHANNEL_NUM_0];
            Ethernet_removePacketsFromRxQueue(rxChan,
                        ETHERNET_COMPLETION_NORMAL);
                        Ethernet_clearDMAChannelInterrupt(\
            Ethernet_device_struct.baseAddresses.eqos_base,\
            ETHERNET_DMA_CHANNEL_NUM_0,
            ETHERNET_DMA_CH0_STATUS_RI
            );
        }
        
            
        if(HWREG(Ethernet_device_struct.baseAddresses.eqos_base + \
        ETHERNET_CHANNEL_OFFSET + \
        ETHERNET_O_DMA_CH0_STATUS) & ETHERNET_DMA_CH0_STATUS_RI)
        {
            rxChan = &Ethernet_device_struct.dmaObj.rxDma[ETHERNET_DMA_CHANNEL_NUM_1];
            Ethernet_removePacketsFromRxQueue(rxChan,
                    ETHERNET_COMPLETION_NORMAL);
                    
            Ethernet_clearDMAChannelInterrupt(\
            Ethernet_device_struct.baseAddresses.eqos_base,\
            ETHERNET_DMA_CHANNEL_NUM_1,
            ETHERNET_DMA_CH0_STATUS_RI
            );
        }
        
        
    
#ifdef ETHERNET_DEBUG   
    Ethernet_rxInterruptCount++;
#endif
}

/* 
* This is a Generic Interrupt Service Routine
* Handler for sbd_intr 
* Currently it handles the Early Transmit and Early Receive
* Interrupts. This assumes the INTM interrupt mode 1
* 
**
*/
interrupt void Ethernet_genericISR(void)
{
    Ethernet_RxChDesc *rxChan;
    Ethernet_TxChDesc *txChan;
#ifdef ETHERNET_DEBUG
    Ethernet_genericInterruptCount++;
#endif
    uint16_t revmiiIntStatus;

        if(HWREG(Ethernet_device_struct.baseAddresses.eqos_base + \
        ETHERNET_O_DMA_CH0_STATUS) & ETHERNET_DMA_CH0_STATUS_ETI)
        {
            //Early Tx Interrupt
             txChan = &Ethernet_device_struct.dmaObj.txDma[ETHERNET_DMA_CHANNEL_NUM_0];
              Ethernet_removePacketsFromTxQueue(txChan,
                ETHERNET_COMPLETION_EARLY);
            Ethernet_clearDMAChannelInterrupt(   
            Ethernet_device_struct.baseAddresses.eqos_base,\
            ETHERNET_DMA_CHANNEL_NUM_0,
            ETHERNET_DMA_CH0_STATUS_ETI|ETHERNET_DMA_CH0_STATUS_AIS);
#ifdef ETHERNET_DEBUG            
            Ethernet_earlyTxInterruptCount++;            
#endif
        }
    
    
   
        if(HWREG(Ethernet_device_struct.baseAddresses.eqos_base + \
        ETHERNET_O_DMA_CH0_STATUS) & ETHERNET_DMA_CH0_STATUS_ERI)
        {
              //Early Rx Interrupt  
              //Remove the packet from queue and notify to application
              rxChan = &Ethernet_device_struct.dmaObj.rxDma[ETHERNET_DMA_CHANNEL_NUM_0];
              Ethernet_removePacketsFromRxQueue(rxChan,
                      ETHERNET_COMPLETION_EARLY);

            Ethernet_clearDMAChannelInterrupt(   
            Ethernet_device_struct.baseAddresses.eqos_base,\
            ETHERNET_DMA_CHANNEL_NUM_0,
            ETHERNET_DMA_CH0_STATUS_ERI|ETHERNET_DMA_CH0_STATUS_NIS); 
            
#ifdef ETHERNET_DEBUG
            Ethernet_earlyRxInterruptCount++;            
#endif
            
        }
        else if (HWREG(Ethernet_device_struct.baseAddresses.eqos_base + \
        ETHERNET_O_DMA_CH0_STATUS) & ETHERNET_DMA_CH0_STATUS_RI)
        {
            //Receive Interrupt    
            
            //In some cases towards the end of the Buffer the Early receive 
            //Notification might be cleared
            //Handle it only in Per Channel interrupt 
            
#ifdef ETHERNET_DEBUG
            Ethernet_genericRxCompletionInterruptCount++;
#endif            
            Ethernet_clearDMAChannelInterrupt(   
            Ethernet_device_struct.baseAddresses.eqos_base,\
            ETHERNET_DMA_CHANNEL_NUM_0,
            ETHERNET_DMA_CH0_STATUS_NIS);            
          
        }
    
    
    //Channel1 interrupts and ETI interrupt
     else if(HWREG(Ethernet_device_struct.baseAddresses.eqos_base + \
        ETHERNET_O_DMA_CH1_STATUS) & ETHERNET_DMA_CH1_STATUS_ETI)
        {
             txChan = &Ethernet_device_struct.dmaObj.txDma[ETHERNET_DMA_CHANNEL_NUM_1];
              Ethernet_removePacketsFromTxQueue(txChan,
                ETHERNET_COMPLETION_EARLY);
            Ethernet_clearDMAChannelInterrupt(   
            Ethernet_device_struct.baseAddresses.eqos_base,\
            ETHERNET_DMA_CHANNEL_NUM_1,
            ETHERNET_DMA_CH1_STATUS_ETI|ETHERNET_DMA_CH1_STATUS_AIS);
#ifdef ETHERNET_DEBUG            
            Ethernet_earlyTxInterruptCount++;            
#endif
        }
    
        
        //Channel1 ERI
        else if(HWREG(Ethernet_device_struct.baseAddresses.eqos_base + \
        ETHERNET_O_DMA_CH1_STATUS) & ETHERNET_DMA_CH1_STATUS_ERI)
        {
            
              //Remove the packet from queue and notify to application
              rxChan = &Ethernet_device_struct.dmaObj.rxDma[ETHERNET_DMA_CHANNEL_NUM_1];
              Ethernet_removePacketsFromRxQueue(rxChan,
                      ETHERNET_COMPLETION_EARLY);

            Ethernet_clearDMAChannelInterrupt(   
            Ethernet_device_struct.baseAddresses.eqos_base,\
            ETHERNET_DMA_CHANNEL_NUM_1,
            ETHERNET_DMA_CH1_STATUS_ERI|ETHERNET_DMA_CH1_STATUS_NIS); 
            
#ifdef ETHERNET_DEBUG
            Ethernet_earlyRxInterruptCount++;            
#endif
            
        }
        //Channel 1 RI
        else if (HWREG(Ethernet_device_struct.baseAddresses.eqos_base + \
        ETHERNET_O_DMA_CH1_STATUS) & ETHERNET_DMA_CH1_STATUS_RI)
        {
              
            
            //In some cases towards the end of the Buffer the Early receive 
            //Notification might be cleared
            //Handle it only in Perchannel interrupt 
            
#ifdef ETHERNET_DEBUG
            Ethernet_genericRxCompletionInterruptCount++;
#endif            
            Ethernet_clearDMAChannelInterrupt(   
            Ethernet_device_struct.baseAddresses.eqos_base,\
            ETHERNET_DMA_CHANNEL_NUM_1,
            ETHERNET_DMA_CH1_STATUS_NIS);            
          
        }
        else
            {
            //Check for RevMII link status change interrupt
               revmiiIntStatus =  Ethernet_readPHYRegister(Ethernet_device_struct.baseAddresses.eqos_base,
                                                                ETHERNET_REVMII_INTERRUPT_STATUS_MASK);//Read RevMII Interrupt Status Mask Register
               if(revmiiIntStatus& ETHERNET_REVMII_INTERRUPT_STATUS_MASK_LSI_M)
                {
                    //Clear the interrupt by writing to LSI field of RevMII Interrupt
                    //Status Mask Register
                    revmiiIntStatus &=  ETHERNET_REVMII_INTERRUPT_STATUS_MASK_LSI_M;
#ifdef ETHERNET_DEBUG                    
                    Ethernet_phyLinkStatusChangeInterruptCount++;
#endif
                    Ethernet_writePHYRegister(Ethernet_device_struct.baseAddresses.eqos_base,
                                                            ETHERNET_REVMII_INTERRUPT_STATUS_MASK,
                                                            revmiiIntStatus);
                }
                                                                
            }
    
    
}

uint32_t Ethernet_getStatistics(Handle hEMAC, \
                                Ethernet_statistics *statisticsPtr)
{
    uint32_t i;
    volatile uint32_t *regAddrPtr;
    uint32_t *statAddrPtr;
    uint32_t statval;
    Ethernet_Device *devicePtr;
    devicePtr = (Ethernet_Device *)hEMAC;

    if(!devicePtr || devicePtr->devMagic != ETHERNET_DRV_DEVMAGIC)
        return ETHERNET_ERR_INVALID_HANDLE;
    
    regAddrPtr = (uint32_t *)(devicePtr->baseAddresses.eqos_base + \
            ETHERNET_O_TX_OCTET_COUNT_GOOD_BAD);
    statAddrPtr = (uint32_t *)statisticsPtr;
    
    for (i = 0; i < ETHERNET_NUMSTATS; i++) 
    {
            statval = *regAddrPtr;
            *regAddrPtr++ = statval;
            statval += *statAddrPtr;
            *statAddrPtr++ = statval;
    }
    return ETHERNET_RET_SUCCESS;

}
uint32_t Ethernet_getHandle(Handle handleApplication, \
    Ethernet_InitConfig *ethernetInitConfigPtr,Handle *ethernetHandlePtr)
{

    uint32_t i;

    //Do validation of inputs

    if(!ethernetInitConfigPtr)
    {
        return ETHERNET_ERR_INVALID_PARAM;
    }
    

    Ethernet_device_struct.descs = \
        (Ethernet_EQOS_descriptor*) malloc(EQOS_DESCTIPTORS_NUM * \
        sizeof(Ethernet_EQOS_descriptor));
    memset(Ethernet_device_struct.descs,0U,\
    EQOS_DESCTIPTORS_NUM * sizeof(Ethernet_EQOS_descriptor));
    
    Ethernet_device_struct.txDesc = Ethernet_device_struct.descs;
    Ethernet_device_struct.rxDesc = Ethernet_device_struct.descs + \
            EQOS_DESCRIPTORS_NUM_TX ;

    Ethernet_device_struct.rxBuffer = Ethernet_rxBuffer;



   Ethernet_setMACConfiguration(Ethernet_device_struct.baseAddresses.eqos_base ,\
           ethernetInitConfigPtr->linkMode << ETHERNET_MAC_CONFIGURATION_DM_S 
          |ethernetInitConfigPtr->loopbackMode << ETHERNET_MAC_CONFIGURATION_LM_S
          );

    
    
    HWREG(Ethernet_device_struct.baseAddresses.eqos_base + \
        ETHERNET_O_DMA_SYSBUS_MODE ) |= \
        ETHERNET_DMA_SYSBUS_MODE_FB; //Fixed Burst Length DMA

    /* This fixes the RX and TX DMA Channels to have the same Burst length
     Change here for different Burst Length experiments*/
    
    
   
    
    for(i=0;i<ethernetInitConfigPtr->numChannels;i++) //TBD
    {
     /*TBD Make all these per channel based InitConfig Structure inputs based*/
        
        
        Ethernet_initTxChannel(
             &Ethernet_device_struct.initConfig.chInfo[ETHERNET_CH_DIR_TX][i]);  
    
        Ethernet_writeTxDescTailPointer(\
                Ethernet_device_struct.baseAddresses.eqos_base, \
                 i,
                 (Ethernet_device_struct.txDesc + 1U + \
                 EQOS_DESCRIPTORS_NUM_TX_PER_CHANNEL * i  ));
    
        Ethernet_initRxChannel(
            &Ethernet_device_struct.initConfig.chInfo[ETHERNET_CH_DIR_RX][i]);
        
        Ethernet_writeRxDescTailPointer( \
            Ethernet_device_struct.baseAddresses.eqos_base,\
            i, \
            (Ethernet_device_struct.rxDesc + \
            (EQOS_DESCRIPTORS_NUM_RX_PER_CHANNEL * (i+1U))));    
            
        Ethernet_enableDmaInterrupt(
                                Ethernet_device_struct.baseAddresses.eqos_base,
                                 i,
                                ETHERNET_DMA_CH0_INTERRUPT_ENABLE_NIE\
                              |ETHERNET_DMA_CH0_INTERRUPT_ENABLE_TIE\
                              |ETHERNET_DMA_CH0_INTERRUPT_ENABLE_RIE 
                                );
     }
    Ethernet_setMTLOpmode(Ethernet_device_struct.baseAddresses.eqos_base, \
                         ethernetInitConfigPtr->txSchedulingAlgoritm ,
                         ethernetInitConfigPtr->receiveArbitrationAlgorithm
                         );
                         
    Ethernet_setDMAMode(Ethernet_device_struct.baseAddresses.eqos_base,
                        ethernetInitConfigPtr->dmaMode);
     
    
    //Configure the MAC Address

    //for(i=0;i<ethernetInitConfigPtr->totalNumMacAddrs;i++)
    //{
//      Ethernet_setMACAddr(Ethernet_device_struct.baseAddresses.eqos_base, \
    //           i,
// ethernetInitConfigPtr->MacAddr[i].Addr[0] << 8 | \
//ethernetInitConfigPtr->MacAddr[i].Addr[1], \
//              (uint32_t) ethernetInitConfigPtr->MacAddr[i].Addr[2]);
    //}
    Ethernet_setMACAddr(Ethernet_device_struct.baseAddresses.eqos_base, \
                                0U,
                                0x00000506U, \
                                0x01020304U,
                                ETHERNET_CHANNEL_0);

    Ethernet_device_struct.pktMTU = ethernetInitConfigPtr->pktMTU;

    
    Ethernet_setMACConfiguration(Ethernet_device_struct.baseAddresses.eqos_base \
         ,ethernetInitConfigPtr->linkMode << ETHERNET_MAC_CONFIGURATION_DM_S |\
        ethernetInitConfigPtr->loopbackMode<<ETHERNET_MAC_CONFIGURATION_LM_S
        );
     Ethernet_setMACConfiguration(Ethernet_device_struct.baseAddresses.eqos_base,
                ETHERNET_MAC_CONFIGURATION_TE);
/*  This was inside Inside Tx Init Channel
    Ethernet_setMTLTxQueueOpMode(Ethernet_device_struct.baseAddresses.eqos_base, \
                        chInfo->chNum,          \
                        chInfo->QueueThreshold,
                        chInfo->dmaQueueSize,
                        chInfo->storeNForward);
    */
    
    // MDIO Configurations 
    Ethernet_configureMDIO(Ethernet_device_struct.baseAddresses.eqos_base,
                            1U,0U,0U);
    Ethernet_configurePHYAddress(Ethernet_device_struct.baseAddresses.eqos_base,
                                  0U);
    
    //TBD RX Channel mapping
    
    
        
    Interrupt_enableInProcessor();
    Interrupt_registerHandler(ETHERNET_TX_INTR_CH0, Ethernet_transmitISR);
    Interrupt_registerHandler(ETHERNET_TX_INTR_CH1, Ethernet_transmitISR);
    Interrupt_registerHandler(ETHERNET_RX_INTR_CH0, Ethernet_receiveISR);
    Interrupt_registerHandler(ETHERNET_RX_INTR_CH1, Ethernet_receiveISR);
    Interrupt_registerHandler(ETHERNET_GENERIC_INTERRUPT,\
                    Ethernet_genericISR);
      Interrupt_enable(ETHERNET_TX_INTR_CH0);
      Interrupt_enable(ETHERNET_TX_INTR_CH1);
      Interrupt_enable(ETHERNET_RX_INTR_CH0);
      Interrupt_enable(ETHERNET_RX_INTR_CH1);
      Interrupt_enable(ETHERNET_GENERIC_INTERRUPT);
    
//EMACCSSConfig Structure and call Ethernet_setSSControlStatus();
//EMACSSConfig Structure and configure MAC_Configuration DM
//EMACTxDMAControlWrite
//EMACRxDMAControlWrite based on channel parameters
//Tx and Rx Desc RingLength Register
//Ethernet_MACAddressConfig
// DMA initConfig where?
// DMA Queue initConfig EMACMTLRXQueueOpMode Ethernet_setMTLTxQueueOpMode
// Enable RX queue
//Enable Tx and RX Interrrupts
  Ethernet_device_struct.devMagic = ETHERNET_DRV_DEVMAGIC;
  *ethernetHandlePtr = &Ethernet_device_struct;
    return ETHERNET_RET_SUCCESS;
}

uint32_t Ethernet_setConfig(Handle hEMAC, \
            Ethernet_setConfigParam setParam, \
            void *buffPtr, \
            uint32_t size)
{
//StatisticsEnable
//PTP Config?
//    Ethernet_ConfigurePTP(hEMAC, (Ethernet_PtpConfig *)bufPtr);


//Offload Engines
//.....IPC IP Checksum Offload in MAC_Configuration
//MAC_Configuration Jumbo Packet Enable 
//MAC_Configuration Support for 2K Packets
//MAC_Configuration GPSLCE and MAC_Ext_Configuration register
//MAC_Configuration IPG non default value
//MAC_Configuration SARC for Source Address Insertion Replacement Control
//MAC_Configuration Loopback Mode enable
//MAC_Configuration Preamble Length 
//DMA Configuration Split Header Support
    Ethernet_vlanConfig *vlanConfig;
    Ethernet_doubleVLANConfig *dvlanConfig;
    Ethernet_VLAN_Perfect_FilterParams *vlanPerfectParams;
    Ethernet_L3_L4_FilterParams *l3l4FilterParams;

    switch(setParam)
    {
        case ETHERNET_SET_CONFIG_VLAN_TX_OUTER:
            
            vlanConfig = (Ethernet_vlanConfig*)buffPtr;
            Ethernet_setFixedOuterVLANParams(Ethernet_device_struct.baseAddresses.eqos_base,
                                                                       vlanConfig->vlan_tag,
                                                                       vlanConfig->vlanTagControl,
                                                                       vlanConfig->vlanType);
            break;
            
        case ETHERNET_SET_CONFIG_VLAN_TX_INNER:
            
             vlanConfig = (Ethernet_vlanConfig*)buffPtr;
            Ethernet_setFixedInnerVLANParams(Ethernet_device_struct.baseAddresses.eqos_base,
                                                                       vlanConfig->vlan_tag,
                                                                       vlanConfig->vlanTagControl,
                                                                       vlanConfig->vlanType);
            break;
            
        case ETHERNET_SET_CONFIG_VLAN_TX_DOUBLE_VLAN:
            
             dvlanConfig=  (Ethernet_doubleVLANConfig*)buffPtr;
            //Configure Outer VLAN Parameters
            Ethernet_setFixedOuterVLANParams(Ethernet_device_struct.baseAddresses.eqos_base,
                                                                       dvlanConfig->outerVLANConfig.vlan_tag,
                                                                       dvlanConfig->outerVLANConfig.vlanTagControl,
                                                                       dvlanConfig->outerVLANConfig.vlanType);

            //Configure Inner VLAN Parameters
            Ethernet_setFixedInnerVLANParams(Ethernet_device_struct.baseAddresses.eqos_base,
                                                           dvlanConfig->innerVLANConfig.vlan_tag,
                                                           dvlanConfig->innerVLANConfig.vlanTagControl,
                                                           dvlanConfig->innerVLANConfig.vlanType);
            break;
            
        case ETHERNET_SET_CONFIG_FILTER_VLAN_PERFECT:
            vlanPerfectParams = (Ethernet_VLAN_Perfect_FilterParams*)buffPtr;
            Ethernet_setVLANPerfectFilter(\
                        Ethernet_device_struct.baseAddresses.eqos_base,
                      vlanPerfectParams->filterid,
                      vlanPerfectParams->vlanid,
                      vlanPerfectParams->vlanEnableDisable,
                      vlanPerfectParams->vlanFilterMode,
                      vlanPerfectParams->vlanPerfectTypeComparisonDisable,
                      vlanPerfectParams->vlanType,
                      vlanPerfectParams->innerVLANEnabled,
                      vlanPerfectParams->dmaChannelEnable,
                      vlanPerfectParams->dmaChannelNum);
            //Enable VLAN Tag Filtering
            Ethernet_setMACPacketFilter(\
                    Ethernet_device_struct.baseAddresses.eqos_base,
                    ETHERNET_MAC_PACKET_FILTER_VTFE
                    );
            break;
        case ETHERNET_SET_CONFIG_FILTER_L3_L4:
            l3l4FilterParams = (Ethernet_L3_L4_FilterParams *)buffPtr;
            Ethernet_configureL3L4Filter(Ethernet_device_struct.baseAddresses.eqos_base,
                                                                    *l3l4FilterParams);
            break;
                
        default:
            break;
    }  
   
    return 0;
}

/*
 * TODO: This api is only configuring the PTP related stuff and that too very
 * blatantly. Need to refine this api to call apt sub-routines.
 * Still to be implemented
 */
uint32_t Ethernet_ConfigurePTP(Handle hEMAC)
{
    return 0;
}

void Ethernet_clearHandle(Handle *phEMAC)
{
//Disable Tx and Rx DMA
//Turn off the Tx and RX
//Deregister the ISR
}
void Ethernet_clearStatistics(Handle *ethernetHandlePtr)
{
}
void Ethernet_addPacketsIntoTxQueue(Ethernet_DescCh *channelDescPtr)
{
        Ethernet_EQOS_descriptor      *descPtr;
        Ethernet_Pkt_Desc      *pktPtr;
        uint32_t          numPktFrags;

    
        if (channelDescPtr->dmaInProgress)
        {
            return;
        }
        // descWrite is in initialized to 0xffffffff to indicate 1st time 
        //tx enqueue, starting point 
        if (channelDescPtr->descWrite == (Ethernet_EQOS_descriptor*)0xffffffffU)
        {
            channelDescPtr->descWrite = channelDescPtr->descFirst;
        }
        

        /* Try to post any waiting packets */
        while (channelDescPtr->waitQueue.count)
        {
            /* See if we have enough room for a new packet */
            pktPtr = channelDescPtr->waitQueue.head;
            if (!pktPtr)
            {
                return;
            }
            else
            {
                numPktFrags = pktPtr->numPktFrags;
            }
            /* If we don't have room, break out */
            if((numPktFrags+channelDescPtr->descCount)\
             > channelDescPtr->descMax)
            {
                break;
            }
    
            /* The next packet will fit, post it. */
            while (numPktFrags)
            {
                /* Pop the next frag off the wait queue */
                pktPtr = Ethernet_performPopOnPacketQueue( \
                            &channelDescPtr->waitQueue);
    
                /* Assign the pointer to "this" desc */
                descPtr = channelDescPtr->descWrite;
    
               
                /* Move the write pointer and bump count */
                if (channelDescPtr->descWrite == channelDescPtr->descLast)
                    channelDescPtr->descWrite = channelDescPtr->descFirst;
                else
                    channelDescPtr->descWrite++;
    

                descPtr->des0  = (uint32_t)(pktPtr->dataBuffer + \
                            pktPtr->dataOffset);
                //IOC Set for interrupt completion which is needed for 
                //Dequeueing the packet
                descPtr->des2 = \
                pktPtr->validLength|ETHERNET_TX_DESC_IOC|ETHERNET_TX_DESC_TTSE; 
                
    
                if (pktPtr->flags & ETHERNET_PKT_FLAG_SOP) 
                    descPtr->des3 = ((pktPtr->flags \
                                & (ETHERNET_PKT_FLAG_SOP|ETHERNET_PKT_FLAG_EOP))\
                                |pktPtr->pktLength
                                |ETHERNET_DESC_OWNER\
                     |(((pktPtr->flags & ETHERNET_PKT_FLAG_SAIC) >>  \
                        ETHERNET_PKT_FLAG_SAIC_S) <<ETHERNET_TX_DESC_SAIC_S)\
                        |(((pktPtr->flags &ETHERNET_PKT_FLAG_CPC)>>\
                        ETHERNET_PKT_FLAG_CPC_S) <<ETHERNET_TX_DESC_CPC_S ));
                else
                    descPtr->des3 = (pktPtr->flags&ETHERNET_PKT_FLAG_EOP) \
                                           |ETHERNET_DESC_OWNER;
    

                
                Ethernet_performPushOnPacketQueue(&channelDescPtr->descQueue,\
                                                pktPtr);
                channelDescPtr->descCount++;
                numPktFrags--;
    
                channelDescPtr->dmaInProgress = 1U;
                HWREG(channelDescPtr->devicePtr->baseAddresses.eqos_base+ \
                ETHERNET_O_DMA_CH0_TX_CONTROL+\
                (ETHERNET_CHANNEL_OFFSET*channelDescPtr->chInfo->chNum))\
                |= ETHERNET_DMA_CH0_TX_CONTROL_ST;
        
                Ethernet_writeTxDescTailPointer( \
                        channelDescPtr->devicePtr->baseAddresses.eqos_base,\
                    channelDescPtr->chInfo->chNum,\
                            (Ethernet_EQOS_descriptor*)(descPtr+1U));
            }
        }
}
void Ethernet_removePacketsFromTxQueue
                                    (Ethernet_DescCh *channelDescPtr,
                                    Ethernet_CompletionMode earlyFlag)
{
        Ethernet_Pkt_Desc      *pktPtr = 0U;



    
        /* Start with Desciptor Ack pointer */

          /* we now own the packet meaning its been transferred to the port */
        pktPtr = Ethernet_performPopOnPacketQueue(&channelDescPtr->descQueue);
        if (pktPtr)
        {
           pktPtr->flags |= ETHERNET_INTERRUPT_FLAG_TRANSMIT;
           if(earlyFlag == ETHERNET_COMPLETION_EARLY)
            {
                pktPtr->flags |= ETHERNET_INTERRUPT_FLAG_EARLY;
            }
            pktPtr->timeStampLow = channelDescPtr->descRead->des0;
            pktPtr->timeStampHigh = channelDescPtr->descRead->des1;
           (channelDescPtr->devicePtr->initConfig.pfcbFreePacket)\
            (channelDescPtr->devicePtr->handleApplication[0U],\
            pktPtr);
            channelDescPtr->descCount--;
            if (channelDescPtr->descRead == channelDescPtr->descLast)
                  channelDescPtr->descRead = channelDescPtr->descFirst;
            else
                  channelDescPtr->descRead++;
        }
         channelDescPtr->dmaInProgress = 0U;
        /* Try to post any waiting TX packets */
        if ((channelDescPtr->waitQueue.count) \
            && (channelDescPtr->dmaInProgress == 0U))
        {
            Ethernet_addPacketsIntoTxQueue(channelDescPtr);
        }



}
void Ethernet_addPacketsIntoRxQueue(Ethernet_DescCh *channelDescPtr)
{
        Ethernet_Pkt_Desc           *pktPtr;
        Ethernet_EQOS_descriptor    *descPtr;

    

    
        /* Fill RX Packets Until Full */
        while (channelDescPtr->descCount < channelDescPtr->descMax)
        {
            /* Get a buffer from the application */
            pktPtr = (*Ethernet_device_struct.initConfig.pfcbGetPacket)();
    
            /* If no more buffers are available, break out of loop */
            if (!pktPtr)
                break;
    
            /* Fill in the descriptor for this buffer */
            descPtr = channelDescPtr->descWrite;
    
            /* Move the write pointer and bump count */
            if (channelDescPtr->descWrite == channelDescPtr->descLast)
                channelDescPtr->descWrite = channelDescPtr->descFirst;
            else
                channelDescPtr->descWrite++;
            channelDescPtr->descCount++;
    
            /* Supply buffer pointer with application supplied offset */
            //descPtr->pNext   = 0;
            descPtr->des0= (uint32_t)(pktPtr->dataBuffer + pktPtr->dataOffset);
            descPtr->des1 = 0U; //We are not using 64 bit addresses
            descPtr->des2 = 0U;//Not using Buffer 2 Address 
            descPtr->des3 = ETHERNET_DESC_OWNER|ETHERNET_RX_DESC_IOC\
                |ETHERNET_RX_DESC_BUF1_VALID;
    
    
            /* Push the packet buffer on the local descriptor queue */
            
            Ethernet_performPushOnPacketQueue(&channelDescPtr->descQueue, \
                    pktPtr);
        }

}

void Ethernet_removePacketsFromRxQueue(Ethernet_DescCh *channelDescPtr,
    Ethernet_CompletionMode earlyFlag)
{
    Ethernet_Pkt_Desc    *pktPtr = 0U;
    Ethernet_Pkt_Desc    *unusedPktPtr = 0U ;
    Ethernet_Pkt_Desc    *newPktPtr = 0U;

    Ethernet_EQOS_descriptor   *descNewRxLastPtr=0U;


    uint32_t      PktFlgLen;
    uint8_t       contextTStampAvailable;

    contextTStampAvailable=0U;


    /*
     * Pop & Free Buffers 'till the last Descriptor
     * One thing we know for sure is that all the decriptors from
     * the read pointer to pDescAsk are linked to each other via
     * their pNext field.
    */
    //while (channelDescPtr->descCount)
    if(earlyFlag == ETHERNET_COMPLETION_EARLY)
        {
            pktPtr = Ethernet_returnTopOfPacketQueue( &channelDescPtr->descQueue);

            ASSERT(NULL != pktPtr);
            
            pktPtr->bufferLength = channelDescPtr->chInfo->burstLength;
            pktPtr->pktChannel = channelDescPtr->chInfo->chNum;
            pktPtr->numPktFrags = Ethernet_getRxERICount(\
                                                Ethernet_device_struct.baseAddresses.eqos_base,
                                               channelDescPtr->chInfo->chNum);
            
            pktPtr->flags |= ETHERNET_INTERRUPT_FLAG_RECEIVE;
            
            if(earlyFlag == ETHERNET_COMPLETION_EARLY)
            {
                pktPtr->flags |= ETHERNET_INTERRUPT_FLAG_EARLY;
            }
                    /* Pass the packet to the application */ 
            newPktPtr = (*Ethernet_device_struct.initConfig.pfcbRxPacket)\
                    (channelDescPtr->devicePtr->handleApplication[0],pktPtr);
        }
        else
         {
   
                /* Get the status of this descriptor */
                PktFlgLen = channelDescPtr->descRead->des3;
                
                if(channelDescPtr->descRead->des1 & \
                (1U<< ETHERNET_RX_NORMAL_DESC_RDES1_TSA_LBIT_POS))
                    contextTStampAvailable=1U;

                /* Bit 16,17 and 18 indicate the port number(ingress)
                 * Passcrc bit is always set in the received packets.
                 *Clear it before putting the \
                 * packet in receive queue */
                PktFlgLen = PktFlgLen & 0x0BFFFFFFU;

                /* Check the ownership of the packet */
                if (!(PktFlgLen & ETHERNET_DESC_OWNER))
                {
                    /* Recover the buffer and free it */
                    pktPtr = Ethernet_performPopOnPacketQueue(\
                        &channelDescPtr->descQueue);
                    if (pktPtr)
                    {
                        /* Fill in the necessary packet header fields */
                        pktPtr->flags = PktFlgLen & 0xFFFF8000U;
                    //Payload Length is Least 14 bits in Receive Descriptor Writeback
                        pktPtr->validLength = pktPtr->pktLength = PktFlgLen & 0x7FFFU; 
                        pktPtr->pktChannel = channelDescPtr->chInfo->chNum;
                        pktPtr->numPktFrags = 1U;
                        pktPtr->flags |= ETHERNET_INTERRUPT_FLAG_RECEIVE;
                        
                        pktPtr->flags &= ~ETHERNET_INTERRUPT_FLAG_EARLY;
                        if(earlyFlag == ETHERNET_COMPLETION_EARLY)
                        {
                            pktPtr->flags |= ETHERNET_INTERRUPT_FLAG_EARLY;
                        }
                        
                        if(contextTStampAvailable)
                        {
                            //Read the Next Descriptor to read the time stamp
                             /* Move the read pointer and decrement count */
                            if (channelDescPtr->descRead == channelDescPtr->descLast)
                                channelDescPtr->descRead = channelDescPtr->descFirst;
                            else
                                channelDescPtr->descRead++;
                            channelDescPtr->descCount--;
                            
                            if(channelDescPtr->descRead->des3 & 
                              (1 << ETHERNET_RX_CONTEXT_DESC_RDES3_CTXT_HBIT_POS))
                              {  
                                pktPtr->timeStampLow = channelDescPtr->descRead->des0;
                                pktPtr->timeStampHigh = channelDescPtr->descRead->des1;
                                
                                unusedPktPtr = Ethernet_performPopOnPacketQueue(\
                                        &channelDescPtr->descQueue);
                               
                               /* If the Context Descriptor has come 
                                the Queued up Buffer would have been unused by the DMA
                                Hence reuse that buffer */
                                
                                
#ifdef ETHERNET_DEBUG
                                Ethernet_rxContextTimeStamp++;
#endif                        
                                /* Update the Rx Descriptor ring with that buffer */
                                
                                /* Supply buffer pointer with application supplied offset */
                                descNewRxLastPtr = channelDescPtr->descWrite;
                                descNewRxLastPtr->des0  =(uint32_t)(unusedPktPtr->dataBuffer + \
                                                         unusedPktPtr->dataOffset);
                                descNewRxLastPtr->des1 = 0U;
                                descNewRxLastPtr->des2 = 0U; 
                                descNewRxLastPtr->des3= ETHERNET_DESC_OWNER \
                                                        |ETHERNET_RX_DESC_IOC\
                                                        |ETHERNET_RX_DESC_BUF1_VALID;
                                                        
                                 /* Push the packet buffer again on 
                                the local descriptor queue */
                                Ethernet_performPushOnPacketQueue(\
                                        &channelDescPtr->descQueue,\
                                        unusedPktPtr);
                                
                                /* Move the write pointer and bump count */
                                if( channelDescPtr->descWrite == channelDescPtr->descLast )
                                    channelDescPtr->descWrite = channelDescPtr->descFirst;
                                else
                                    channelDescPtr->descWrite++;
                                channelDescPtr->descCount++;

                             
                              }
                            contextTStampAvailable = 0U;

                        }

                        /* Pass the packet to the application */ 
                    newPktPtr = (*Ethernet_device_struct.initConfig.pfcbRxPacket)\
                            (channelDescPtr->devicePtr->handleApplication[0],pktPtr);
                            
                    /* Move the read pointer and decrement count */
                        if (channelDescPtr->descRead == channelDescPtr->descLast)
                            channelDescPtr->descRead = channelDescPtr->descFirst;
                        else
                            channelDescPtr->descRead++;
                        channelDescPtr->descCount--;
                    }
         }
      }             
        /* See if we got a replacement packet */
        if(newPktPtr)
        {
            /* We know we can immediately queue this packet */

            /* Fill in the descriptor for this buffer */
            descNewRxLastPtr = channelDescPtr->descWrite;

            /* Move the write pointer and bump count */
            if( channelDescPtr->descWrite == channelDescPtr->descLast )
                channelDescPtr->descWrite = channelDescPtr->descFirst;
            else
                channelDescPtr->descWrite++;
            channelDescPtr->descCount++;

            /* Supply buffer pointer with application supplied offset */
            descNewRxLastPtr->des0   =(uint32_t)(newPktPtr->dataBuffer + \
                                     newPktPtr->dataOffset);
            descNewRxLastPtr->des1 = 0U;
            descNewRxLastPtr->des2 = 0U; 
            descNewRxLastPtr->des3= ETHERNET_DESC_OWNER \
                                    |ETHERNET_RX_DESC_IOC\
                                    |ETHERNET_RX_DESC_BUF1_VALID;

            /* Push the packet buffer on the local descriptor queue */
            Ethernet_performPushOnPacketQueue(&channelDescPtr->descQueue,\
                                               newPktPtr);
        }
      
}


void Ethernet_shutdownInterface(void)
{
    
    free(Ethernet_device_struct.descs);
    free(Ethernet_device_struct.rxBuffer);

    //Turn off Clocks to the EMAC
}

/*These Routines are functions that touch the EQOS Controller Registers */
void Ethernet_resetModule(uint32_t base)
{
    //DMA Initialization
    HWREG(base + ETHERNET_O_DMA_MODE)  =  ETHERNET_DMA_MODE_SWR;
    //Wait till the Soft Reset is done
    while(HWREG(base + ETHERNET_O_DMA_MODE) &  ETHERNET_DMA_MODE_SWR == \
        ETHERNET_DMA_MODE_SWR);
}   
//**************************************************************************
//! Ethernet_setMTLTxQueueOpMode ()
//! This internal function is used to program the MTL_OPERATION_MODE 
//! register 
//! Arguments:
//! baseAddress - baseAddress of the EQOS module
//! txSchedulingAlgoritm - Tx Scheduling Algorithm
//!     ETHERNET_MTL_OPERATON_MODE_SCHALG_WRR  
//!     ETHERNET_MTL_OPERATON_MODE_SCHALG_WFQ  
//!     ETHERNET_MTL_OPERATON_MODE_SCHALG_DWRR
//!     ETHERNET_MTL_OPERATON_MODE_SCHALG_STRICT_PRIORITY
//! rxAribtrationAlgorithm: Rx Arbitration Algorithm
//!     ETHERNET_MTL_OPERATION_MODE_RAA_SP   
//!     ETHERNET_MTL_OPERATION_MODE_RAA_WSP   
//************************************************************************

void Ethernet_setMTLOpmode(uint32_t base,
        uint32_t txSchedulingAlgoritm,
        uint32_t rxAribtrationAlgorithm)
{
        HWREG(base + ETHERNET_O_MTL_OPERATION_MODE) \
            = txSchedulingAlgoritm << ETHERNET_MTL_OPERATION_MODE_SCHALG_S \
            |rxAribtrationAlgorithm << ETHERNET_MTL_OPERATION_MODE_RAA_S;
            
}
        
void Ethernet_setMTLTxQueueOpMode(uint32_t base,
        uint32_t queueNum,
        uint32_t threshold_val,
        uint32_t queue_size,uint32_t storeForward)
{
    HWREG(base+ (queueNum*ETHERNET_QUEUE_OFFSET) + \
            ETHERNET_O_MTL_TXQ0_OPERATION_MODE) \
            = threshold_val << ETHERNET_MTL_TXQ0_OPERATION_MODE_TTC_S \
            |queue_size << ETHERNET_MTL_TXQ0_OPERATION_MODE_TQS_S \
            | storeForward << ETHERNET_MTL_TXQ0_OPERATION_MODE_TSF_S \
            |ETHERNET_MTL_TXQ0_OPERATION_MODE_TXQ_ENABLED<< \
            ETHERNET_MTL_TXQ0_OPERATION_MODE_TXQEN_S ;
}   

void Ethernet_setMTLRxQueueOpMode(
    uint32_t base, \
    uint32_t queueNum, \
    uint32_t threshold_val,\
    uint32_t queue_size,
    uint32_t storeForward)
{
    HWREG(base+ (queueNum*ETHERNET_QUEUE_OFFSET) + \
    ETHERNET_O_MTL_RXQ0_OPERATION_MODE) \
    =threshold_val << ETHERNET_MTL_RXQ0_OPERATION_MODE_RTC_S \
    |queue_size << ETHERNET_MTL_RXQ0_OPERATION_MODE_RQS_S  \
    |storeForward << ETHERNET_MTL_RXQ0_OPERATION_MODE_RSF_S;
                                                                                    
}

void Ethernet_setDMAMode(
    uint32_t base, \
    Ethernet_dmaMode dmaMode)
{

    //
    // This is one-shot approach for the above solution.
    //
    HWREG(base + ETHERNET_O_DMA_MODE ) = *((uint32_t *) (&dmaMode));//*dmaModePtr;


    //
    // You don't need to typecast. If you assign directly, it should work. I checked it
    // with an online compiler. But, here it didn't work for me. Probably it's the compiler
    // issue here.
    // TODO: Go to your chrome, I have a small snippet for your reference. Remove this line.
    //
    //HWREG(base + ETHERNET_O_DMA_MODE ) = (uint32_t)dmaMode;
}
           

//
//Interrupt Enable related routines
//
void Ethernet_enableDmaInterrupt( \
          uint32_t base,\
        uint32_t channelNum, \
        uint32_t flags)
{
    HWREG(base+ (channelNum*ETHERNET_CHANNEL_OFFSET) + \
    ETHERNET_O_DMA_CH0_INTERRUPT_ENABLE) |= flags;
}
void Ethernet_enableMACInterrupt(
    uint32_t base,
    uint32_t flags)
{
    HWREG(base+  \
        ETHERNET_O_MAC_INTERRUPT_ENABLE) |= flags;
}
void Ethernet_clearDMAChannelInterrupt(
    uint32_t base,
    uint32_t channelNum,
    uint32_t flags)
{
    HWREG(base+ (channelNum*ETHERNET_CHANNEL_OFFSET) + \
    ETHERNET_O_DMA_CH0_STATUS) = flags;
}
    
void Ethernet_writeTxDescListAddress( \
    uint32_t base, \
    uint32_t channelNum,\
    Ethernet_EQOS_descriptor* write_data)
{
    HWREG(base+ (channelNum*ETHERNET_CHANNEL_OFFSET) + \
    ETHERNET_O_DMA_CH0_TXDESC_LIST_ADDRESS) = (uint32_t)write_data;
}
void Ethernet_writeTxDescTailPointer( \
        uint32_t base, \
        uint32_t channelNum, \
        Ethernet_EQOS_descriptor* write_data)
{
    HWREG(base+ (channelNum*ETHERNET_CHANNEL_OFFSET) \
        + ETHERNET_O_DMA_CH0_TXDESC_TAIL_POINTER) = \
        (uint32_t)write_data;
}
void Ethernet_writeRxDescListAddress( \
    uint32_t base, \
    uint32_t channelNum, \
    Ethernet_EQOS_descriptor *write_data)
{
    HWREG(base+ (channelNum*ETHERNET_CHANNEL_OFFSET) + \
    ETHERNET_O_DMA_CH0_RXDESC_LIST_ADDRESS) \
    =(uint32_t)write_data;
}
void Ethernet_writeRxDescTailPointer(
    uint32_t base,  \
    uint32_t channelNum, \
    Ethernet_EQOS_descriptor*write_data)
{
    HWREG(base+ channelNum*(ETHERNET_CHANNEL_OFFSET) \
    + ETHERNET_O_DMA_CH0_RXDESC_TAIL_POINTER) \
    = (uint32_t)write_data;
    
}


//Subsystem Routines
void Ethernet_setSSControlStatus( \
    uint32_t base, \
    uint32_t phyTypeSel,\
    uint32_t LoopbackModeClkSrcSel, \
    uint32_t ClkSourceSelect, \
    uint32_t FlowControlEnable)
{
    HWREG(base + ETHERNETSS_O_CTRLSTS) =  \
        phyTypeSel << ETHERNETSS_CTRLSTS_PHY_INTF_SEL_S \
        |LoopbackModeClkSrcSel << ETHERNETSS_CTRLSTS_CLK_LM_S \
        |ClkSourceSelect << ETHERNETSS_CTRLSTS_CLK_SRC_SEL_S \
        |FlowControlEnable <<ETHERNETSS_CTRLSTS_FLOW_CTRL_EN_S ;
}

void Ethernet_writeTxDMAControl(
    uint32_t base, \
    uint32_t channelNum, \
    int burst_Length,
    uint8_t earlyTransmitInterruptEnable)
{
    
    if(burst_Length > 32)
    {
        //Turn on 8xPBL
        HWREG(base + ETHERNET_O_DMA_CH0_CONTROL+ \
        (ETHERNET_CHANNEL_OFFSET*channelNum)) |= ETHERNET_DMA_CH0_CONTROL_PBLX8;
        //Divide the burst length by 8 and store in the TX PBL field
        HWREG(base + ETHERNET_O_DMA_CH0_TX_CONTROL+ \
            (ETHERNET_CHANNEL_OFFSET*channelNum)) |= \
                ((burst_Length/8U) <<  ETHERNET_DMA_CH0_TX_CONTROL_TXPBL_S) ;
    }
    else
    {
        //Turn OFF 8xPBL
        HWREG(base + ETHERNET_O_DMA_CH0_CONTROL+ \
        (ETHERNET_CHANNEL_OFFSET*channelNum))\
        &= ~ETHERNET_DMA_CH0_CONTROL_PBLX8;
        
        HWREG(base + ETHERNET_O_DMA_CH0_TX_CONTROL + \
            (ETHERNET_CHANNEL_OFFSET*channelNum)) |= \
            (burst_Length <<  ETHERNET_DMA_CH0_TX_CONTROL_TXPBL_S );
    }

    HWREG(base + ETHERNET_O_DMA_CH0_TX_CONTROL + \
               (ETHERNET_CHANNEL_OFFSET*channelNum)) |= \
               (earlyTransmitInterruptEnable <<  ETHERNET_DMA_CH0_TX_CONTROL_ETIC_S );

    
}

void Ethernet_enableMACRxQ(uint32_t base,\
                                            uint32_t queueNumber)
{
    if(queueNumber == ETHERNET_DMA_CHANNEL_NUM_0)
        {
            HWREG(base+ ETHERNET_O_MAC_RXQ_CTRL0) |= \
            ETHERNET_MAC_RXQ_CONTROL_RXQEN_ENABLED_GENERIC << \
            ETHERNET_MAC_RXQ_CTRL0_RXQ0EN_S;
        }
    else if (queueNumber ==ETHERNET_DMA_CHANNEL_NUM_1)
        {
            HWREG(base+ ETHERNET_O_MAC_RXQ_CTRL0) |= \
            ETHERNET_MAC_RXQ_CONTROL_RXQEN_ENABLED_GENERIC << \
            ETHERNET_MAC_RXQ_CTRL0_RXQ1EN_S;
        
        }
}
void Ethernet_enableRxDMAReception(uint32_t base,\
                                                                                                uint8_t channelNum)
{

    HWREG(base+ \
        ETHERNET_O_DMA_CH0_RX_CONTROL+ \
        (ETHERNET_CHANNEL_OFFSET* channelNum)) |= \
            ETHERNET_DMA_CH0_RX_CONTROL_SR;
}

void Ethernet_setDMARxQueueMode(uint32_t base,
                                                       Ethernet_RxDMAQueueMode mode,
                                                       Ethernet_channelNum channelNum,
                                                       Ethernet_channelNum mappedChannel
                                                       )
{

    if(mode == ETHERNET_RX_DMA_QUEUE_DYNAMIC )
    {
        HWREG(base+ \
            ETHERNET_O_MTL_RXQ_DMA_MAP0) |= \
                    ETHERNET_RX_DMA_QUEUE_DYNAMIC << \
                     ( ETHERNET_MTL_RXQ_DMA_MAP0_DDMACH_S * (channelNum+1));
    }
    else
    {
        //Clear the DDMACH which configures the channel in Static mode
        //to be mapped with the channel number provided
        HWREG(base+ \
                ETHERNET_O_MTL_RXQ_DMA_MAP0) &= \
                            ~(ETHERNET_RX_DMA_QUEUE_DYNAMIC <<
                           ( ETHERNET_MTL_RXQ_DMA_MAP0_QDMACH_S * channelNum));

        HWREG(base+ \
                ETHERNET_O_MTL_RXQ_DMA_MAP0) |= (mappedChannel <<
                           ( ETHERNET_MTL_RXQ_DMA_MAP0_QDMACH_S * channelNum));

    }
}

void Ethernet_setMultiQueueRxQueueControl(uint32_t base,
                                                                    Ethernet_RxQControl rxqControl)
{
    HWREG(base+ \
        ETHERNET_O_MAC_RXQ_CTRL1) = *((uint32_t *)&rxqControl);
}


void Ethernet_writeRxDMAControl(
     uint32_t base,\
     uint32_t channelNum,\
     int burst_Length,\
     uint32_t dmaBufferSize,
     uint8_t earlyReceiveInterruptEnable)
{
    
    if(burst_Length > 32U)
    {
        //Turn on 8xPBL
        HWREG(base + ETHERNET_O_DMA_CH0_CONTROL + \
        (ETHERNET_CHANNEL_OFFSET*channelNum)) 
        |= ETHERNET_DMA_CH0_CONTROL_PBLX8;
        
        //Divide the burst length by 8 and store in the TX PBL field
        HWREG(base + ETHERNET_O_DMA_CH0_RX_CONTROL+ \
        (ETHERNET_CHANNEL_OFFSET*channelNum)) 
        |=  ((burst_Length/8U )<<  ETHERNET_DMA_CH0_RX_CONTROL_RXPBL_S ) \
        |dmaBufferSize<< ETHERNET_DMA_CH0_RX_CONTROL_RBSZ_S;  
        //Hard coding 256 byte RX buffer size
    }
    else
    {
        //Turn OFF 8xPBL
        HWREG(base + ETHERNET_O_DMA_CH0_CONTROL+ \
        (ETHERNET_CHANNEL_OFFSET*channelNum)) \
        &= ~ETHERNET_DMA_CH0_CONTROL_PBLX8;
        
        HWREG(base + ETHERNET_O_DMA_CH0_RX_CONTROL+ \
        (ETHERNET_CHANNEL_OFFSET*channelNum)) \
        |= burst_Length <<  ETHERNET_DMA_CH0_RX_CONTROL_RXPBL_S \
        |dmaBufferSize<< ETHERNET_DMA_CH0_RX_CONTROL_RBSZ_S;  
        //Hard coding 256 byte RX buffer size
            //TBD make it parameter
    }

         HWREG(base + ETHERNET_O_DMA_CH0_RX_CONTROL+ \
        (ETHERNET_CHANNEL_OFFSET*channelNum)) \
        |= earlyReceiveInterruptEnable<<  ETHERNET_DMA_CH0_TX_CONTROL_ERIC_S ;
    
    
}

uint16_t Ethernet_getRxERICount(uint32_t base, uint32_t channelNum)
{

    uint16_t earlyInterruptCount;
    earlyInterruptCount = HWREG(base + ETHERNET_O_DMA_CH0_MISS_FRAME_CNT+ \
                                                    (ETHERNET_CHANNEL_OFFSET*channelNum)) 
                                                    & ETHERNET_DMA_CH0_MISS_FRAME_CNT_MFC_M ;
    return earlyInterruptCount;
}


void Ethernet_setTxDescRingLength(
        uint32_t base, 
        uint32_t channelNum,
        uint32_t ringLength)
{
//Higher layer software is expected to give the number of descriptors 
// the EQOS module expects x-1 to be programmed if descriptor length is X
    HWREG(base + ETHERNET_O_DMA_CH0_TXDESC_RING_LENGTH+ \
    (ETHERNET_CHANNEL_OFFSET*channelNum)) \
    |= (ringLength-1U);

}
void Ethernet_setRxDescRingLength(
    uint32_t base,
    uint32_t channelNum,
    uint32_t ringLength)
{
    //Higher layer software is expected to give the number of descriptors 
    // the EQOS module expects x-1 to be programmed if descriptor length is X

    HWREG(base + ETHERNET_O_DMA_CH0_RXDESC_RING_LENGTH+ \
    (ETHERNET_CHANNEL_OFFSET*channelNum))\
    |= (ringLength-1U);

}




void Ethernet_setMACAddr(
    uint32_t base, 
    uint8_t instanceNum,
    uint32_t MACAddrHigh,
    uint32_t MACAddrLow,
    Ethernet_channelNum channelNumber)
{
      HWREG(base + ETHERNET_O_MAC_ADDRESS0_HIGH + instanceNum*0x8U) = \
            MACAddrHigh |ETHERNET_MAC_ADDRESS0_HIGH_AE |\
            channelNumber << ETHERNET_MAC_ADDRESS0_HIGH_DCS_S;
      HWREG(base + ETHERNET_O_MAC_ADDRESS0_LOW + instanceNum*0x8U) = \
            MACAddrLow;
}


/** ==========================================================================
 *  @n@b Ethernet_performPushPacketQueueChain()
 *
 *  @b Description
 *  @n Push a desc buffer chain onto a queue
 *
 *  @b Arguments
 *  @verbatim
        pktQueuePtr              pointer to packet queue
        firstPktHdrPtr    pointer to the first element of the EMAC Packet.
        lastPktHdrPtr     pointer to the last element of the EMAC Packet.
        Count           count of elements to push
    @endverbatim
 *
 *
 *  <b> Return Value </b>  None
 *
 *  <b> Pre Condition </b>
 *  @n  None
 *
 *  <b> Post Condition </b>
 *  @n  A chain of descriptor buffers are added to the Queue
 *
 *  @b Example
 *  @verbatim
        ETHERNET_PKT_QUEUE_T *pktQueuePtr;
        ETHERNET_PKT_DESC_T *firstPktHdrPtr, *lastPktHdrPtr;
        uint32_t Count;

        Ethernet_performPushPacketQueueChain( pktQueuePtr, firstPktHdrPtr, 
        lastPktHdrPtr, Count );
    @endverbatim
 * ============================================================================
 */
static void Ethernet_performPushPacketQueueChain( \
        Ethernet_PKT_Queue_T *pktQueuePtr, \
        Ethernet_Pkt_Desc *firstPktHdrPtr, \
        Ethernet_Pkt_Desc *lastPktHdrPtr, \
        uint32_t Count)
{
    lastPktHdrPtr->nextPacketDesc = 0U;

    if (!pktQueuePtr->head)
    {
        // Queue is empty - Initialize it with this packet chain
        pktQueuePtr->head = firstPktHdrPtr;
        pktQueuePtr->tail = lastPktHdrPtr;
    }
    else
    {
        // Queue is not empty - Push onto END
        pktQueuePtr->tail->nextPacketDesc = firstPktHdrPtr;
        pktQueuePtr->tail        = lastPktHdrPtr;
    }
    pktQueuePtr->count += Count;
}


/** ==========================================================================
 *  @n@b Ethernet_performPopOnPacketQueue()
 *
 *  @b Description
 *  @n Pop a desc buffer off a queue
 *
 *  @b Arguments
 *  @verbatim
        pktQueuePtr      pointer to packet queue
    @endverbatim
 *
 *  <b> Return Value </b>  Pointer to EMAC packet
 *
 *  <b> Pre Condition </b>
 *  @n  None
 *
 *  <b> Post Condition </b>
 *  @n  Descriptor buffer from the Queue is removed
 *
 *  @b Example
 *  @verbatim
        ETHERNET_PKT_QUEUE_T *pktQueuePtr;
        ETHERNET_performPopOnPacketQueue( pktQueuePtr );
    @endverbatim
 * ============================================================================
 */
static Ethernet_Pkt_Desc *Ethernet_performPopOnPacketQueue( \
            Ethernet_PKT_Queue_T *pktQueuePtr)
{
    Ethernet_Pkt_Desc *pktDescHdrPtr;

    pktDescHdrPtr = pktQueuePtr->head;

    if (pktDescHdrPtr)
    {
        pktQueuePtr->head = pktDescHdrPtr->nextPacketDesc;
        pktQueuePtr->count--;
        //pktDescHdrPtr->pPrev = pktDescHdrPtr->nextPacketDesc = 0;
    }

    return (pktDescHdrPtr);
}

/** ==========================================================================
 *  @n@b Ethernet_returnTopOfPacketQueue()
 *
 *  @b Description
 *  @n Return Front element of a queue
 *
 *  @b Arguments
 *  @verbatim
        pktQueuePtr      pointer to packet queue
    @endverbatim
 *
 *  <b> Return Value </b>  Pointer to EMAC packet
 *
 *  <b> Pre Condition </b>
 *  @n  None
 *
 *  <b> Post Condition </b>
 *  @n  None
 *
 *  @b Example
 *  @verbatim
        ETHERNET_PKT_QUEUE_T *pktQueuePtr;
        ETHERNET_returnTopOfPacketQueue( pktQueuePtr );
    @endverbatim
 * ============================================================================
 */
static Ethernet_Pkt_Desc *Ethernet_returnTopOfPacketQueue( \
            Ethernet_PKT_Queue_T *pktQueuePtr)
{
    
    return (pktQueuePtr->head);
}

/** ==========================================================================
 *  @n@b Ethernet_performPushOnPacketQueue()
 *
 *  @b Description
 *  @n Push a desc buffer onto a queue
 *
 *  @b Arguments
 *  @verbatim
        pktQueuePtr      pointer to packet queue
        pktDescHdrPtr pointer to the EMAC packet
    @endverbatim
 *
 *
 *  <b> Return Value </b>  None
 *
 *  <b> Pre Condition </b>
 *  @n  None
 *
 *  <b> Post Condition </b>
 *  @n  Descriptor buffer from the Queue is added
 *
 *  @b Example
 *  @verbatim
        ETHERNET_PKT_QUEUE_T *pktQueuePtr;
        ETHERNET_PKT_DESC_T *pktDescHdrPtr

        Ethernet_performPushOnPacketQueue( pktQueuePtr, pktDescHdrPtr );
    @endverbatim
 * ============================================================================
 */
static void Ethernet_performPushOnPacketQueue( \
        Ethernet_PKT_Queue_T *pktQueuePtr, \
        Ethernet_Pkt_Desc *pktDescHdrPtr)
{
    pktDescHdrPtr->nextPacketDesc = 0U;

    if (!pktQueuePtr->head)
    {
        // Queue is empty - Initialize it with this one packet
        pktQueuePtr->head = pktDescHdrPtr;
        pktQueuePtr->tail = pktDescHdrPtr;
    }
    else
    {
        // Queue is not empty - Push onto END
        pktQueuePtr->tail->nextPacketDesc = pktDescHdrPtr;
        pktQueuePtr->tail        = pktDescHdrPtr;
    }
    pktQueuePtr->count++;
}
static uint32_t Ethernet_initTxChannel(Ethernet_ChInfo *chInfo)
{
    Ethernet_DmaObj* dmaObj = &Ethernet_device_struct.dmaObj;
    Ethernet_TxChDesc* txChan = &dmaObj->txDma[chInfo->chNum];
    Ethernet_EQOS_descriptor *descPtr;

    descPtr= Ethernet_device_struct.txDesc + (chInfo->chNum * chInfo->numBD);
        /* zero init the book keeping structure */
    memset(txChan, 0U, sizeof(Ethernet_TxChDesc));
    txChan->chInfo = chInfo;
    txChan->devicePtr = &Ethernet_device_struct;
    txChan->descMax = chInfo->numBD;
    txChan->descFirst = descPtr;
    txChan->descRead = descPtr;
    txChan->descWrite = (Ethernet_EQOS_descriptor *) (0xffffffffU);
        txChan->descLast = (Ethernet_EQOS_descriptor *)(descPtr+(chInfo->numBD -1U));
    txChan->dmaInProgress = 0U;
    dmaObj->chIsInit[ETHERNET_CH_DIR_TX][chInfo->chNum] = true;
    Ethernet_writeTxDescListAddress(\
                Ethernet_device_struct.baseAddresses.eqos_base, \
               chInfo->chNum , \
               (Ethernet_device_struct.txDesc + \
               (chInfo->chNum * EQOS_DESCRIPTORS_NUM_TX_PER_CHANNEL )));

    if(chInfo->storeNForward ==ETHERNET_MTL_TXQ_OPMODE_TSF_DISABLE)
    {
        //if it is Threshold mode then Enable Early Transmit interrupt
        Ethernet_writeTxDMAControl(Ethernet_device_struct.baseAddresses.eqos_base,\
                                    chInfo->chNum, \
                                    chInfo->burstLength,
                                    ETHERNET_DMA_CH0_TX_CONTROL_ETIC_ENABLE);
     }
    else
     {
        Ethernet_writeTxDMAControl(Ethernet_device_struct.baseAddresses.eqos_base,\
                                    chInfo->chNum, \
                                    chInfo->burstLength,
                                   ETHERNET_DMA_CH0_TX_CONTROL_ETIC_DISABLE );
      }
        
    Ethernet_setTxDescRingLength(\
                Ethernet_device_struct.baseAddresses.eqos_base,
                chInfo->chNum,
                chInfo->numBD
                );
    
    
     Ethernet_setMTLTxQueueOpMode(\
            Ethernet_device_struct.baseAddresses.eqos_base, \
            chInfo->chNum,         \
            chInfo->queueThreshold,
            chInfo->dmaQueueSize,
            chInfo->storeNForward);
    
    return ETHERNET_RET_SUCCESS;

}
static uint32_t Ethernet_initRxChannel(Ethernet_ChInfo *chInfo)
{
    Ethernet_DmaObj *       dmaObj = &Ethernet_device_struct.dmaObj;
    Ethernet_RxChDesc* rxChan = &dmaObj->rxDma[chInfo->chNum];
    Ethernet_EQOS_descriptor       *descPtr;
    //Ethernet_Pkt_Desc*        pktPtr;

    /* zero init the book keeping structure */
    memset(rxChan, 0U, sizeof(Ethernet_RxChDesc));

    /* store pointer to channel info structure */
    rxChan->chInfo = chInfo;

    /*
     * Setup Receive Buffers
     */
    /*
     * We give the first descriptors to RX. The rest of the descriptors
     * will be divided evenly among the TX channels. Odds are this
     * will leave TX with a very large number of TX descriptors, but
     * we'll only use what we need (driven from the application send
     * requests). The RX descriptors are always kept fully populated.
     */

    /* Pointer to first descriptor to use on RX */

     descPtr = Ethernet_device_struct.rxDesc + (chInfo->chNum*chInfo->numBD);

    /* Init the Rx channel */
    rxChan->devicePtr         = &Ethernet_device_struct;
    rxChan->descMax    = chInfo->numBD;
    rxChan->descFirst = descPtr;
    rxChan->descLast  = descPtr + (chInfo->numBD - 1U);
    rxChan->descRead  = descPtr;
    rxChan->descWrite = descPtr;
    rxChan->dmaInProgress = 0U;
    Ethernet_writeRxDescListAddress(
                    Ethernet_device_struct.baseAddresses.eqos_base,
                    chInfo->chNum,\
                    Ethernet_device_struct.rxDesc \
                    + chInfo->chNum * EQOS_DESCRIPTORS_NUM_RX_PER_CHANNEL);

   if(chInfo->storeNForward == ETHERNET_MTL_RX_Q_OP_MODE_RSF_DISABLE)
    {
    
        Ethernet_writeRxDMAControl(Ethernet_device_struct.baseAddresses.eqos_base,\
                                    chInfo->chNum, \
                                    chInfo->burstLength,
                                    chInfo->dmaBufferSize,
                                    ETHERNET_DMA_CH0_RX_CONTROL_ERIC_ENABLE);
    }
   else
    {
     Ethernet_writeRxDMAControl(Ethernet_device_struct.baseAddresses.eqos_base,\
                                    chInfo->chNum, \
                                    chInfo->burstLength,
                                    chInfo->dmaBufferSize,
                                    ETHERNET_DMA_CH0_RX_CONTROL_ERIC_DISABLE);
    }
        
    Ethernet_setRxDescRingLength( \
                Ethernet_device_struct.baseAddresses.eqos_base,
                chInfo->chNum,
                chInfo->numBD
                );
    Ethernet_setMTLRxQueueOpMode(
            Ethernet_device_struct.baseAddresses.eqos_base,\
            chInfo->chNum,\
            chInfo->queueThreshold, \
            chInfo->dmaQueueSize, \
            chInfo->storeNForward);
        /* Fill the descriptor table */
    Ethernet_addPacketsIntoRxQueue(rxChan);  
    Ethernet_enableMACRxQ(Ethernet_device_struct.baseAddresses.eqos_base,
                                                chInfo->chNum);
          
    Ethernet_enableRxDMAReception(Ethernet_device_struct.baseAddresses.eqos_base ,\
                                                               chInfo->chNum);

            
    Ethernet_setMACConfiguration(Ethernet_device_struct.baseAddresses.eqos_base , \
                                                        ETHERNET_MAC_CONFIGURATION_RE);
    
    if (rxChan->descCount < (chInfo->numBD))
    {
        /* Free all RX descriptors */
        //while ((pktPtr = Ethernet_performPopOnPacketQueue( \
        //&rxChan->descQueue)))
    //(*Ethernet_LOCAL_DEVICE->initConfig.pfcbFreePacket)\
    (Ethernet_LOCAL_DEVICE->handleApplication[0U], pktPtr);

        /* Return the error condition */
        return (ETHERNET_ERR_INVALID_PARAM);
    }
       
        dmaObj->chIsInit[ETHERNET_CH_DIR_RX][chInfo->chNum] = true;

    return 0;

}

/* This function is a callback function called by the LLD to 
Get a Packet Buffer. Has to return a ETHERNET_Pkt_Desc Structure filled
User or upper level stack can rewrite this API for their own use case
*/
Ethernet_Pkt_Desc* Ethernet_getPacketBuffer(void)
{
    uint8_t *ptrBuffer;
#ifdef ETHERNET_DEBUG
    Ethernet_numGetPacketBufferCallback++;
#endif
    Ethernet_pktDescriptorRX.bufferLength       = ETHERNET_MAX_PACKET_LENGTH;
    ptrBuffer =  Ethernet_device_struct.rxBuffer + \
               (ETHERNET_MAX_PACKET_LENGTH*Ethernet_device_struct.rxBuffIndex);
        //Wrap around
    Ethernet_device_struct.rxBuffIndex  = \
     (++Ethernet_device_struct.rxBuffIndex)%ETHERNET_NO_OF_RX_PACKETS; 
     
    Ethernet_pktDescriptorRX.dataBuffer         = ptrBuffer;
    Ethernet_pktDescriptorRX.dataOffset         = 0U; //Usable from Address 0 
    return (&Ethernet_pktDescriptorRX);
}


void Ethernet_releaseTxPacketBuffer(
        Handle handleApplication, 
        Ethernet_Pkt_Desc *pPacket)
{
#ifdef ETHERNET_DEBUG
    Ethernet_numTxPktFreeCallback++;
#endif
}

Ethernet_Pkt_Desc* Ethernet_receivePacketCallback(
    Handle handleApplication,
    Ethernet_Pkt_Desc *pPacket)
{
#ifdef ETHERNET_DEBUG
    Ethernet_numRxCallback++;
#endif
//
// This is a placeholder for Application specific handling
// We are replenishing the buffer received with another buffer
//
    return  Ethernet_getPacketBuffer();
}

//**********************************************************************
//
// Ethernet_setConfigTimestampPTP().
//
//**********************************************************************
void Ethernet_setConfigTimestampPTP(uint32_t base, uint32_t config,
                                    uint32_t subSecondInc)
{
    //
    // Parameter sanity check.
    //
    ASSERT(EMAC_BASE == base);

    //
    // Ensure that the PTP module clock is enabled.
    // TODO: Is there a similar clock in PTP for us ?
    //HWREG(ui32Base + EMAC_O_CC) |= EMAC_CC_PTPCEN;

    //
    // Write the subsecond increment value.
    // TODO: When is the sub nano second inc significant?
    //
    HWREG(base + ETHERNET_O_MAC_SUB_SECOND_INCREMENT) =
            ((subSecondInc << ETHERNET_MAC_SUB_SECOND_INCREMENT_SSINC_S) &
             ETHERNET_MAC_SUB_SECOND_INCREMENT_SSINC_M);

    //
    // Set the timestamp configuration.
    //
    HWREG(base + ETHERNET_O_MAC_TIMESTAMP_CONTROL) = config;
}

//**********************************************************************
//
// Ethernet_setConfigTimestampPTP().
//
//**********************************************************************
uint32_t Ethernet_getConfigTimestampPTP(uint32_t base, uint32_t *subSecondInc)
{
    //
    // Parameter sanity check.
    //
    ASSERT(EMAC_BASE == base);
    ASSERT(subSecondInc);

    //
    // Read the current subsecond increment value.
    //
    *subSecondInc = (HWREG(base + ETHERNET_O_MAC_SUB_SECOND_INCREMENT) &
                     ETHERNET_MAC_SUB_SECOND_INCREMENT_SSINC_M) >>
                    ETHERNET_MAC_SUB_SECOND_INCREMENT_SSINC_S;
    //
    // Return the current timestamp configuration.
    //
    return(HWREG(base + ETHERNET_O_MAC_TIMESTAMP_CONTROL));
}

//**********************************************************************
//
// Ethernet_enableSysTimePTP().
//
//**********************************************************************
void Ethernet_enableSysTimePTP(uint32_t base)
{
    //
    // Parameter sanity check.
    //
    ASSERT(EMAC_BASE == base);

    //
    // Enable IEEE 1588 timestamping.
    //
    HWREG(base + ETHERNET_O_MAC_TIMESTAMP_CONTROL) |=
                                         ETHERNET_MAC_TIMESTAMP_CONTROL_TSENA;

    //
    // If necessary, initialize the timestamping system.  This bit self-clears
    // once the system time is loaded.  Only do this if initialization is not
    // currently ongoing.
    //
    if(!(HWREG(base + ETHERNET_O_MAC_TIMESTAMP_CONTROL) &
         ETHERNET_MAC_TIMESTAMP_CONTROL_TSINIT))
    {
        HWREG(base + ETHERNET_O_MAC_TIMESTAMP_CONTROL) |=
                                        ETHERNET_MAC_TIMESTAMP_CONTROL_TSINIT;
    }
}

//**********************************************************************
//
// Ethernet_disableSysTimePTP().
//
//**********************************************************************
void Ethernet_disableSysTimePTP(uint32_t base)
{
    //
    // Parameter sanity check.
    //
    ASSERT(EMAC_BASE == base);

    //
    // Disable IEEE 1588 timestamping.
    //
    HWREG(base + ETHERNET_O_MAC_TIMESTAMP_CONTROL) &=
                                        ~ETHERNET_MAC_TIMESTAMP_CONTROL_TSENA;
}

//**********************************************************************
//
// Ethernet_setSysTimePTP().
//
//**********************************************************************
void Ethernet_setSysTimePTP(uint32_t base, uint32_t seconds,
                            uint32_t subSeconds)
{
    //
    // Parameter sanity check.
    //
    ASSERT(EMAC_BASE == base);

    //
    // Write the new time to the system time update registers.
    // TODO: Take care of the bit 31 in the nanoseconds update register.
    //
    HWREG(base + ETHERNET_O_MAC_SYSTEM_TIME_SECONDS_UPDATE) = seconds;
    HWREG(base + ETHERNET_O_MAC_SYSTEM_TIME_NANOSECONDS_UPDATE) = subSeconds;

    //
    // Wait for any previous update to complete.
    //
    while(HWREG(base + ETHERNET_O_MAC_TIMESTAMP_CONTROL) &
          ETHERNET_MAC_TIMESTAMP_CONTROL_TSINIT)
    {
        //
        // Spin for a while.
        //
    }

    //
    // Force the system clock to reset.
    //
    HWREG(base + ETHERNET_O_MAC_TIMESTAMP_CONTROL) |=
                                       ETHERNET_MAC_TIMESTAMP_CONTROL_TSINIT;
}

//**********************************************************************
//
// Ethernet_getSysTimePTP().
//
//**********************************************************************
void Ethernet_getSysTimePTP(uint32_t base, uint32_t *seconds,
                            uint32_t *subSeconds)
{
    //
    // Parameter sanity check.
    //
    ASSERT(EMAC_BASE == base);
    ASSERT(seconds);
    ASSERT(subSeconds);

    //
    // Read the two-part system time from the seconds and nanoseconds
    // registers.  We do this in a way that should guard against us reading
    // the registers across a nanosecond wrap.
    //
    do
    {
        *seconds = HWREG(base + ETHERNET_O_MAC_SYSTEM_TIME_SECONDS);
        *subSeconds = HWREG(base + ETHERNET_O_MAC_SYSTEM_TIME_NANOSECONDS);
    }
    while(*subSeconds > HWREG(base + ETHERNET_O_MAC_SYSTEM_TIME_NANOSECONDS));
}

//**********************************************************************
//
// Ethernet_updateSysTimePTP().
//
//**********************************************************************
void Ethernet_updateSysTimePTP(uint32_t base, uint32_t seconds,
                               uint32_t subSeconds, bool addSub)
{
    //
    // Parameter sanity check.
    //
    ASSERT(EMAC_BASE == base);

    //
    // Write the new time to the system time update registers.
    //
    HWREG(base + ETHERNET_O_MAC_SYSTEM_TIME_SECONDS_UPDATE) = seconds;
    HWREG(base + ETHERNET_O_MAC_SYSTEM_TIME_NANOSECONDS_UPDATE) =
         ((subSeconds & ETHERNET_MAC_SYSTEM_TIME_NANOSECONDS_UPDATE_TSSS_M) <<
          ETHERNET_MAC_SYSTEM_TIME_NANOSECONDS_UPDATE_TSSS_S) |
         (addSub ? 0 : ETHERNET_MAC_SYSTEM_TIME_NANOSECONDS_UPDATE_ADDSUB);

    //
    // Wait for any previous update to complete.
    //
    while(HWREG(base + ETHERNET_O_MAC_TIMESTAMP_CONTROL) &
          ETHERNET_MAC_TIMESTAMP_CONTROL_TSUPDT)
    {
        //
        // Spin for a while.
        //
    }

    //
    // Force the system clock to update by the value provided.
    //
    HWREG(base + ETHERNET_O_MAC_TIMESTAMP_CONTROL) |=
                                        ETHERNET_MAC_TIMESTAMP_CONTROL_TSUPDT;
}

//**********************************************************************
//
// Ethernet_getDepthAuxSnapshotFIFO().
//
//**********************************************************************
uint32_t Ethernet_getDepthAuxSnapshotFIFO(uint32_t base)
{
    //
    // Parameter sanity check
    //
    ASSERT(EMAC_BASE == base);

    return ((HWREG(base + ETHERNET_O_MAC_TIMESTAMP_STATUS) &
             ETHERNET_MAC_TIMESTAMP_STATUS_ATSNS_M) >>
            ETHERNET_MAC_TIMESTAMP_STATUS_ATSNS_S);
}

//**********************************************************************
//
// Ethernet_setTimestampSWTrigger().
//
//**********************************************************************
void Ethernet_setTimestampSWTrigger(uint32_t base, uint32_t trigSelect)
{
    //
    // Parameter sanity check
    //
    ASSERT(EMAC_SS_BASE == base);
    ASSERT(ETHERNETSS_PTPTSSWTRIG_PTP_AUX_TS_SW_TRIG1 >= trigSelect);


    switch(trigSelect)
    {
    case ETHERNETSS_PTPTSSWTRIG_PTP_AUX_TS_SW_TRIG0:
        HWREG(base + ETHERNETSS_O_PTPTSSWTRIG0) =
                                   ETHERNETSS_PTPTSSWTRIG0_PTP_AUX_TS_SW_TRIG0;
        break;
    case ETHERNETSS_PTPTSSWTRIG_PTP_AUX_TS_SW_TRIG1:
        HWREG(base + ETHERNETSS_O_PTPTSSWTRIG1) =
                                   ETHERNETSS_PTPTSSWTRIG1_PTP_AUX_TS_SW_TRIG1;
        break;
    default:

        //
        // Wrong PTP SW Trig select.
        break;
        //
    }

    //
    // Triggering might not be captured if the FIFO is full.
    // Return state info to indicate the same.
    //
    if(Ethernet_getDepthAuxSnapshotFIFO(base) <
       ETHERNET_MAC_AUX_TIMESTAMP_FIFO_DEPTH)
    {
        //
        // TODO: Return status info like FIFO_FULL
        //
    }
}

//**********************************************************************
//
// Ethernet_configAuxTimestampTrigger().
//
//**********************************************************************
void Ethernet_configAuxTimestampTrigger(uint32_t base, uint32_t trigSelect,
                                        uint32_t trigValue)
{
    //
    // Parameter sanity check
    //
    ASSERT(EMAC_SS_BASE == base);
    ASSERT(ETHERNETSS_PTPTSTRIGSEL_AUX_TRIG_SEL_MAX_VALUE >= trigValue);
    ASSERT(ETHERNETSS_PTPTSTRIGSEL_AUX_TRIG_SEL1 >= trigSelect);

    //
    // TODO : Decide what to do with the magic number.
    //          Should it be provided with the the arguments?
    //
    switch(trigSelect)
    {
    case ETHERNETSS_PTPTSTRIGSEL_AUX_TRIG_SEL0:
        HWREG(base + ETHERNETSS_O_PTPTSTRIGSEL0) =
              ((ETHERNETSS_CTRLSTS_WRITE_KEY_VALUE <<\
              ETHERNETSS_PTPTSTRIGSEL0_WRITE_KEY_S) &
               ETHERNETSS_PTPTSTRIGSEL0_WRITE_KEY_M) |
              ((trigValue << ETHERNETSS_PTPTSTRIGSEL0_PTP_AUX_TS_TRIG_SEL0_S) &
               ETHERNETSS_PTPTSTRIGSEL0_PTP_AUX_TS_TRIG_SEL0_M);
        break;
    case ETHERNETSS_PTPTSTRIGSEL_AUX_TRIG_SEL1:
        HWREG(base + ETHERNETSS_O_PTPTSTRIGSEL1) =
              ((ETHERNETSS_CTRLSTS_WRITE_KEY_VALUE <<\
              ETHERNETSS_PTPTSTRIGSEL1_WRITE_KEY_S) &
               ETHERNETSS_PTPTSTRIGSEL1_WRITE_KEY_M) |
              ((trigValue & ETHERNETSS_PTPTSTRIGSEL1_PTP_AUX_TS_TRIG_SEL1_S) <<
               ETHERNETSS_PTPTSTRIGSEL1_PTP_AUX_TS_TRIG_SEL1_M);
        break;
    default:

        //
        // Wrong Timestamp TRIG select.
        //
        break;
    }
}

//**********************************************************************
//
// Ethernet_clearAuxSnapshotFIFO().
//
//**********************************************************************
void Ethernet_clearAuxSnapshotFIFO(uint32_t base)
{
    //
    // Parameter sanity check
    //
    ASSERT(EMAC_BASE == base);

    //
    // TODO : value is 1 and if 1 is programmed, the FIFO is cleared,
    //          Not sure how.
    //
    HWREG(base + ETHERNET_O_MAC_AUXILIARY_CONTROL) |=
                                          ETHERNET_MAC_AUXILIARY_CONTROL_ATSFC;
}

//**********************************************************************
//
// Ethernet_disableAuxSnapshot().
//
//**********************************************************************
void Ethernet_disableAuxSnapshot(uint32_t base, uint32_t trigInstance)
{
    uint32_t val;

    //
    // Parameter sanity check
    //
    ASSERT(EMAC_BASE == base);
    ASSERT((trigInstance & (ETHERNET_MAC_AUXILIARY_CONTROL_ATSEN0 |
                            ETHERNET_MAC_AUXILIARY_CONTROL_ATSEN1)) > 0U);

    val = HWREG(base + ETHERNET_O_MAC_AUXILIARY_CONTROL);

    //
    // Write 0 to already reset bit will not make any difference.
    //
    val &= ~trigInstance;

    HWREG(base + ETHERNET_O_MAC_AUXILIARY_CONTROL) |= val;
}

//**********************************************************************
//
// Ethernet_enableAuxSnapshot().
//
//**********************************************************************
void Ethernet_enableAuxSnapshot(uint32_t base, uint32_t trigInstance)
{
    uint32_t val;

    //
    // Parameter sanity check
    //
    ASSERT(EMAC_BASE == base);
    ASSERT((trigInstance & (ETHERNET_MAC_AUXILIARY_CONTROL_ATSEN0 |
                            ETHERNET_MAC_AUXILIARY_CONTROL_ATSEN1)) > 0U);

    val = HWREG(base + ETHERNET_O_MAC_AUXILIARY_CONTROL);

    //
    // Writing 1 to already set bit will not make any difference.
    //
    val |= trigInstance;

    HWREG(base + ETHERNET_O_MAC_AUXILIARY_CONTROL) = val;
}




//**********************************************************************
//
// Ethernet_dequeueAuxSnapshotFIFO().
//
//**********************************************************************
void Ethernet_dequeueAuxSnapshotFIFO(uint32_t base, uint32_t *seconds,
                                     uint32_t *nanoSeconds)
{


    //
    // Parameter sanity check
    //
    ASSERT(EMAC_BASE == base);

    //
    // Return the snapshots if FIFO is not empty.
    // TODO: return a status to indicate FIFO_EMPTY
    //
    if(Ethernet_getDepthAuxSnapshotFIFO(base) > 0U)
    {
        *seconds = HWREG(base + ETHERNET_O_MAC_AUXILIARY_TIMESTAMP_SECONDS);
        *nanoSeconds = HWREG(base + ETHERNET_O_MAC_AUXILIARY_TIMESTAMP_NANOSECONDS);
    }
}

//**********************************************************************
//
// Ethernet_getAuxSnapshot().
//
//**********************************************************************
void Ethernet_getAuxSnapshotTrigId(uint32_t base, uint32_t *id)
{
    //
    // Parameter sanity check
    //
    ASSERT(EMAC_BASE == base);

    //
    // Trigger Identifier is only valid if the FIFO is not empty.
    // TODO: Confirm that the id and last aux remain programmed.
    //
    if(Ethernet_getDepthAuxSnapshotFIFO(base) > 0U)
    {
       *id = (HWREG(base + ETHERNET_O_MAC_TIMESTAMP_STATUS) &
             ETHERNET_MAC_TIMESTAMP_STATUS_ATSSTN_M) >>
            ETHERNET_MAC_TIMESTAMP_STATUS_ATSSTN_S;
    }
}

//**********************************************************************
//
// Ethernet_selectTargetInterruptOrPulsePPS().
//
//**********************************************************************
void Ethernet_selectTargetInterruptOrPulsePPS(uint32_t base,
                                              uint32_t target)
{
    //
    // Parameter sanity check
    //
    ASSERT(EMAC_BASE == base);

    //
    // Program the target
    //
    HWREG(base + ETHERNET_O_MAC_PPS_CONTROL) |=
                            (target << ETHERNET_MAC_PPS_CONTROL_TRGTMODSEL_S);
}

//**********************************************************************
//
// Ethernet_setFixedModePPS().
//
//**********************************************************************
void Ethernet_setFixedModePPS(uint32_t base,
                              uint32_t freq)
{
    bool rollover;

    //
    // Parameter sanity check
    //
    ASSERT(EMAC_BASE == base);
    ASSERT(freq <= ETHERNET_MAC_PPS_CONTROL_PPSCTRL_PPS_OUTPUT_32768HZ);

    //
    // Program the fixed mode
    //
    HWREG(base + ETHERNET_O_MAC_PPS_CONTROL) |=
                            (ETHERNET_MAC_PPS_CONTROL_PPSEN0_PPS_FIXED_MODE <<
                             ETHERNET_MAC_PPS_CONTROL_PPSEN0);

    //
    // Is the clock running in digital or binary rollover mode?
    //
    rollover = (HWREG(base + ETHERNET_O_MAC_TIMESTAMP_CONTROL) &
                ETHERNET_MAC_TIMESTAMP_CONTROL_TSCTRLSSR) ? true : false;

    //
    // Weed out some unsupported frequencies.  The hardware can't produce a
    // 1Hz output when we are in binary rollover mode and can't produce a
    // 32KHz output when we are digital rollover mode.
    //
    ASSERT(rollover ||
           (freq != ETHERNET_MAC_PPS_CONTROL_PPSCTRL_PPS_OUTPUT_1HZ));
    ASSERT(!rollover ||
           (freq != ETHERNET_MAC_PPS_CONTROL_PPSCTRL_PPS_OUTPUT_32768HZ));

    //
    // Adjust the supplied frequency if we are currently in binary rollover
    // mode where the control value generates an output that is twice as fast
    // as in digital rollover mode.
    //
    if((freq != ETHERNET_MAC_PPS_CONTROL_PPSCTRL_PPS_OUTPUT_SINGLE_PULSE) &&
       (!rollover))
    {
        freq--;
    }


    //
    // Program the intended frequency.
    //
    HWREG(base + ETHERNET_O_MAC_PPS_CONTROL) |= \
        (freq << ETHERNET_MAC_PPS_CONTROL_PPSCTRL_PPSCMD_S);
}

//**********************************************************************
//
// Ethernet_setFlexibleModePPS().
//
//**********************************************************************
void Ethernet_setFlexibleModePPS(uint32_t base)
{
    //
    // Parameter sanity check
    //
    ASSERT(EMAC_BASE == base);

    //
    // Program flexible mode configuration
    //
    HWREG(base + ETHERNET_O_MAC_PPS_CONTROL) |=
                          (ETHERNET_MAC_PPS_CONTROL_PPSEN0_PPS_FLEXIBLE_MODE <<
                           ETHERNET_MAC_PPS_CONTROL_PPSEN0);
}

//**********************************************************************
//
// Ethernet_configurePPS().
//
//**********************************************************************
void Ethernet_configurePPS(uint32_t base,
                     uint32_t target,
                     uint32_t mode,
                     uint32_t fixedFreq)
{
    switch(target)
    {
    //
    // Target Interrupt only. No further configuration needed.
    //
    case ETHERNET_MAC_PPS_CONTROL_TRGTMODSEL_INTERRUPT:

        Ethernet_selectTargetInterruptOrPulsePPS(base, target);
     break;

    //
    //  Target Pulse only and Pulse-Interrupt both.
    //  Further configuration for Fixed mode and Flexible mode needed.
    //
    case ETHERNET_MAC_PPS_CONTROL_TRGTMODSEL_PULSE:
    case ETHERNET_MAC_PPS_CONTROL_TRGTMODSEL_INTERRUPT_PULSE:

     //
     // Set target as pulse-only or pulse-interrupt.
     //
        Ethernet_selectTargetInterruptOrPulsePPS(base, target);

     //
     // Set the pulse mode.
     //
     switch(mode)
     {
     case ETHERNET_MAC_PPS_CONTROL_PPSEN0_PPS_FIXED_MODE:

         Ethernet_setFixedModePPS(base,fixedFreq);
         break;

     case ETHERNET_MAC_PPS_CONTROL_PPSEN0_PPS_FLEXIBLE_MODE:

         Ethernet_setFlexibleModePPS(base);
         break;

     default:

         //
         // Erroneous Mode configuration
         //
         break;
     }


    default:

     //
     // Erroneous Target configuration.
     //
        break;
    }
}

//**********************************************************************
//
// Ethernet_setTargetTimePPS().
//
//**********************************************************************
void
Ethernet_setTargetTimePPS(uint32_t base, uint32_t ppsNum,
                          uint32_t seconds, uint32_t subSeconds)
{
    //
    // Parameter sanity check
    //
    ASSERT(EMAC_BASE == base);
    ASSERT(ETHERNET_MAC_PPS_OUT_NUM >= ppsNum);

    //
    // Wait for any previous write to complete.
    //
    while(HWREG(base + ETHERNET_MAC_PPS_TARGET_TIME_NANOSECONDS +
                (ppsNum * 0x10U)) &
          ETHERNET_MAC_PPS_TARGET_TIME_NANOSECONDS_TRGTBUSY)
    {
        //
        // Wait a bit.
        //
    }

    //
    // Program the seconds and subseconds.
    //
    HWREG(base + ETHERNET_MAC_PPS_TARGET_TIME_NANOSECONDS +
          (ppsNum*(0x10U))) = subSeconds;
    HWREG(base + ETHERNET_MAC_PPS_TARGET_TIME_SECONDS +
          (ppsNum*(0x10U))) = seconds;

}

//**********************************************************************
//
// Ethernet_setPeriodPPS().
//
//**********************************************************************
void Ethernet_setPeriodPPS(uint32_t base,
                           uint32_t ppsNum,
                           uint32_t width,
                           uint32_t interval)
{
    //
    // Parameter sanity check
    //
    ASSERT(EMAC_BASE == base);
    ASSERT(ETHERNET_MAC_PPS_OUT_NUM >= ppsNum);

    //
    // Write the desired interval and width.
    //
    HWREG(base + ETHERNET_MAC_PPS_WIDTH + (ppsNum*(0x10U))) = width;
    HWREG(base + ETHERNET_MAC_PPS_INTERVAL + (ppsNum*(0x10U))) = interval;
}

//**********************************************************************
//
// Ethernet_setPeriodPPS().
//
//**********************************************************************
void Ethernet_setCmdPPS(uint32_t base,
                        uint32_t ppsNum,
                        uint32_t ppsCmd)
{
    //
    // Parameter sanity check
    //
    ASSERT(EMAC_BASE == base);
    ASSERT(ETHERNET_MAC_PPS_OUT_NUM >= ppsNum);
    ASSERT(ETHERNET_MAC_PPS_CONTROL_PPSCMD_COMMAND_CANCEL_STOP >= ppsCmd);


    //
    // Wait for any previous command to execute.
    //
    while(HWREG(base + ETHERNET_O_MAC_PPS_CONTROL) &
          ETHERNET_MAC_PPS_CONTROL_PPSCTRL_PPSCMD_M)
    {
        //
        // Wait a bit.
        //
    }

    //
    // Write the command to the PPS control register.
    //
    HWREG(base + ETHERNET_O_MAC_PPS_CONTROL) |= ppsCmd << ((ppsNum) * 8U);
}

//MDIO Related functions

                              
void Ethernet_configureMDIO(uint32_t base, 
                            uint32_t clockHigh,
                            uint32_t clockRange,
                            uint32_t clause45Enable
                            )
{
    HWREG(base+ ETHERNET_O_MAC_MDIO_ADDRESS) = 
                clockRange<<ETHERNET_MAC_MDIO_ADDRESS_CR_S\
                | clockHigh << ETHERNET_MDIO_ADDRESS_HIGHCLK_ENABLE_S \
                | clause45Enable << ETHERNET_MDIO_ADDRESS_C45E_S;
}

void Ethernet_configurePHYAddress(uint32_t base,
                                  uint8_t phyAddr)
{
    HWREG(base + ETHERNET_O_MAC_MDIO_ADDRESS) |= \
                        (phyAddr << ETHERNET_MAC_MDIO_ADDRESS_PA_S);
        
}

uint8_t Ethernet_getPHYMode(uint32_t base)
{
    uint8_t clause45enable;
    clause45enable = (HWREG(base+\
                      ETHERNET_O_MAC_MDIO_ADDRESS) \
                      & ETHERNET_MAC_MDIO_ADDRESS_C45E)\
                      >> ETHERNET_MDIO_ADDRESS_C45E_S;
    return clause45enable;
}                    
                                     
 
uint16_t Ethernet_readPHYRegister(uint32_t base,
                                 uint16_t regAddress)
{
    //If this is a Clause45 PHY or Clause 22 PHY
    if(Ethernet_getPHYMode(base))
    {
        //Clause 45 PHY
        HWREG(base + ETHERNET_O_MAC_MDIO_DATA) = \
                regAddress << ETHERNET_MAC_MDIO_DATA_RA_S;
    }
    else
    {
        //Clause 22 PHY
        HWREG(base+ ETHERNET_O_MAC_MDIO_ADDRESS) |= \
                regAddress << ETHERNET_MAC_MDIO_ADDRESS_RDA_S;
    }
    
    //Set the command as Read 
    HWREG(base+ ETHERNET_O_MAC_MDIO_ADDRESS) |= \
                ETHERNET_MAC_MDIO_ADDRESS_GOC_READ << \
                ETHERNET_MAC_MDIO_ADDRESS_GOC_0_S;
                
    //Send the command to the PHY
    
    HWREG(base + ETHERNET_O_MAC_MDIO_ADDRESS) |= \
                ETHERNET_MAC_MDIO_ADDRESS_GB ; 
    
    //Wait till the GMII Busy is cleared by Module
    while(HWREG(base + ETHERNET_O_MAC_MDIO_ADDRESS) &
          ETHERNET_MAC_MDIO_ADDRESS_GB);
     
    return (HWREG(base + ETHERNET_O_MAC_MDIO_DATA) & \
        ETHERNET_MAC_MDIO_DATA_GD_M);
        
    
} 

void Ethernet_writePHYRegister(uint32_t base,
                               uint8_t regAddress,
                               uint16_t writeData)
{
     if(Ethernet_getPHYMode(base))
    {
        //Clause 45 PHY
        HWREG(base + ETHERNET_O_MAC_MDIO_DATA) = \
                regAddress << ETHERNET_MAC_MDIO_DATA_RA_S;
    }
    else
    {
        //Clause 22 PHY
        HWREG(base+ ETHERNET_O_MAC_MDIO_ADDRESS) |= \
                regAddress << ETHERNET_MAC_MDIO_ADDRESS_RDA_S;
    }
    
   
   HWREG(base + ETHERNET_O_MAC_MDIO_DATA) = writeData ;
   
   //Clearing GOC_0 and GOC_1
   HWREG(base+ ETHERNET_O_MAC_MDIO_ADDRESS) &=\
   ~(ETHERNET_MAC_MDIO_ADDRESS_GOC_1 | ETHERNET_MAC_MDIO_ADDRESS_GOC_0);
   
       //Set the command as Write 
    HWREG(base+ ETHERNET_O_MAC_MDIO_ADDRESS) |= \
                ETHERNET_MAC_MDIO_ADDRESS_GOC_WRITE << \
                ETHERNET_MAC_MDIO_ADDRESS_GOC_0_S;
    
    //Send the command to the PHY
    
    HWREG(base + ETHERNET_O_MAC_MDIO_ADDRESS) |= \
                ETHERNET_MAC_MDIO_ADDRESS_GB ; 
                
        //Wait till the GMII Busy is cleared by Module
    while(HWREG(base + ETHERNET_O_MAC_MDIO_ADDRESS) &
          ETHERNET_MAC_MDIO_ADDRESS_GB);            
}

void Ethernet_configureRevMIIAddress(uint32_t subSystembase,
                               uint8_t localPHYAddress,
                               uint8_t remotePHYAddress)
{


HWREG( subSystembase+ ETHERNETSS_O_REVMII_CTRL)\
                       =(((ETHERNETSS_CTRLSTS_WRITE_KEY_VALUE  <<\
                       ETHERNETSS_REVMII_CTRL_WRITE_KEY_S) & \
                       ETHERNETSS_REVMII_CTRL_WRITE_KEY_M) \
                       | (localPHYAddress \
                       <<  ETHERNETSS_REVMII_CTRL_REVMII_CORE_PHY_ADDR_S)
                       | (remotePHYAddress\
                       <<ETHERNETSS_REVMII_CTRL_REVMII_REMOTE_PHY_ADDR_S));

}
//VLAN Related Routines
//
//Function used to Set Register based VLAN Inclusion
//For Outer VLAN
//

void Ethernet_setFixedOuterVLANParams(uint32_t base,
                                                        uint16_t vlanTag,
                                                        uint8_t vlanTagControl,
                                                        uint8_t vlanType
                                                        )
{

//Clear the VLTI Field

    HWREG(base + ETHERNET_O_MAC_VLAN_INCL) &= ~ETHERNET_MAC_VLAN_INCL_VLTI;
 
//Program with the provided parameters

    HWREG(base + ETHERNET_O_MAC_VLAN_INCL)
           =  (((vlanTag << ETHERNET_MAC_VLAN_INCL_VLT_S)  &\
                ETHERNET_MAC_VLAN_INCL_VLT_M )\
                |(ETHERNET_MAC_VLAN_INCL_VLP_STATIC << \
                ETHERNET_MAC_VLAN_INCL_VLP_S)\
                | ((vlanTagControl << ETHERNET_MAC_VLAN_INCL_VLC_S) &\
                ETHERNET_MAC_VLAN_INCL_VLC_M)\
                |((vlanType << ETHERNET_MAC_VLAN_INCL_CSVL_S) &\
                ETHERNET_MAC_VLAN_INCL_CSVL));
}

//
//Function used to Set Register based VLAN Inclusion
//For Inner VLAN
//
void Ethernet_setFixedInnerVLANParams(uint32_t base,
                                                        uint16_t vlanTag,
                                                        uint8_t vlanTagControl,
                                                        uint8_t vlanType
                                                        )
{
    //Clear the VLTI Field
    
        HWREG(base + ETHERNET_O_MAC_INNER_VLAN_INCL) &= ~ETHERNET_MAC_INNER_VLAN_INCL_VLTI;
     
    //Program with the provided parameters

    HWREG(base + ETHERNET_O_MAC_INNER_VLAN_INCL)
           =  (((vlanTag << ETHERNET_MAC_INNER_VLAN_INCL_VLT_S)  &\
                ETHERNET_MAC_INNER_VLAN_INCL_VLT_M )\
                |(ETHERNET_MAC_VLAN_INCL_VLP_STATIC << \
                ETHERNET_MAC_INNER_VLAN_INCL_VLP_S)\
                | ((vlanTagControl << ETHERNET_MAC_INNER_VLAN_INCL_VLC_S) &\
                ETHERNET_MAC_INNER_VLAN_INCL_VLC_M)\
                |((vlanType << ETHERNET_MAC_INNER_VLAN_INCL_CSVL_S) &\
                ETHERNET_MAC_INNER_VLAN_INCL_CSVL));
}

//
//Routine to Set Outer VLAN in Descriptor based inclusion
//
void Ethernet_setOuterVLANTagSourceDynamic(uint32_t base)
{
    //Set the VLTI Bit to select Context Descriptor source
    HWREG(base + ETHERNET_O_MAC_VLAN_INCL) = ETHERNET_MAC_VLAN_INCL_VLTI;
    
  //Also clear the VLP field to make the VLAN Tag control picked 
  //from the context Descriptor
      HWREG(base + ETHERNET_O_MAC_VLAN_INCL) &= ~ETHERNET_MAC_VLAN_INCL_VLP;
}
//
//Routine to Set Inner VLAN in Descriptor based inclusion
//

void Ethernet_setInnerVLANTagSourceDynamic(uint32_t base)
{
    //Set the VLTI Bit to select Context Descriptor source
    HWREG(base + ETHERNET_O_MAC_INNER_VLAN_INCL) = ETHERNET_MAC_INNER_VLAN_INCL_VLTI;
    
    //Also clear the VLP field to make the VLAN Tag control picked 
    //from the context Descriptor
    HWREG(base + ETHERNET_O_MAC_INNER_VLAN_INCL) &= ~ETHERNET_MAC_INNER_VLAN_INCL_VLP;
}



 void Ethernet_setVLANPerfectFilter(
                                                                                    uint32_t base,
                                                                                    uint8_t filterId,
                                                                                    uint16_t vlanId,
                                                                                    uint8_t vlanEnable,
                                                                                    uint8_t vlanFilterMode,
                                                                                    uint8_t vlanTypeComparisonEnable,
                                                                                    uint8_t vlanType,
                                                                                    uint8_t innerVLANEnabled,
                                                                                    uint8_t dmaChannelEnable,
                                                                                    uint8_t channelNum)
{

//First Write Filter configuration in to VLAN Tag Data Register 
     HWREG(base + ETHERNET_O_MAC_VLAN_TAG_DATA)
                =  (((vlanId << ETHERNET_MAC_VLAN_TAG_DATA_DATA_15_0_S)\
                    &ETHERNET_MAC_VLAN_TAG_DATA_DATA_15_0_M )\
                   |((vlanEnable<< ETHERNET_MAC_VLAN_TAG_DATA_DATA_16_S ) \
                   &  ETHERNET_MAC_VLAN_TAG_DATA_DATA_16) \
                   |(( vlanFilterMode<< ETHERNET_MAC_VLAN_TAG_DATA_DATA_17_S) \
                   & ETHERNET_MAC_VLAN_TAG_DATA_DATA_17) \
                   |((vlanTypeComparisonEnable << \
                   ETHERNET_MAC_VLAN_TAG_DATA_DATA_18_S )\
                   &ETHERNET_MAC_VLAN_TAG_DATA_DATA_18) \
                   |((vlanType << ETHERNET_MAC_VLAN_TAG_DATA_DATA_19_S)
                   &ETHERNET_MAC_VLAN_TAG_DATA_DATA_19)\
                   |((innerVLANEnabled << \
                   ETHERNET_MAC_VLAN_TAG_DATA_DATA_20_S )\
                   &ETHERNET_MAC_VLAN_TAG_DATA_DATA_20)\
                   |((dmaChannelEnable  << \
                   ETHERNET_MAC_VLAN_TAG_DATA_DATA_24_S) \
                   &ETHERNET_MAC_VLAN_TAG_DATA_DATA_24)\
                   |((channelNum <<ETHERNET_MAC_VLAN_TAG_DATA_DATA_25_S )\
                   &ETHERNET_MAC_VLAN_TAG_DATA_DATA_25));
                   
 //Program the offset of the filter      
                   
 HWREG(base + ETHERNET_O_MAC_VLAN_TAG_CTRL) \
                    |=    ((filterId<<ETHERNET_MAC_VLAN_TAG_CTRL_OFS_S) \
                               &  ETHERNET_MAC_VLAN_TAG_CTRL_OFS_M) ;

 //Set the Command Type to Write
 HWREG(base + ETHERNET_O_MAC_VLAN_TAG_CTRL) &= ~ETHERNET_MAC_VLAN_TAG_CTRL_CT;

//Give the command to Write
  HWREG(base + ETHERNET_O_MAC_VLAN_TAG_CTRL) |= \
                                                                    ETHERNET_MAC_VLAN_TAG_CTRL_OB;

  //Wait for the write to get over
    while((HWREG(base + ETHERNET_O_MAC_VLAN_TAG_CTRL) & \
        ETHERNET_MAC_VLAN_TAG_CTRL_OB) == ETHERNET_MAC_VLAN_TAG_CTRL_OB);
                             
}
void Ethernet_setMACPacketFilter(uint32_t base,
                                                      uint32_t flags)
{
    HWREG(base+ETHERNET_O_MAC_PACKET_FILTER) |= flags;
}

void Ethernet_clearMACPacketFilter(uint32_t base,
                                                        uint32_t flags)
{
    HWREG(base +ETHERNET_O_MAC_PACKET_FILTER ) &= \
                        ~flags;
}

void Ethernet_setProgrammableWDTimeout(uint32_t base,
                                                                    uint8_t timeout)
{
    HWREG(base + ETHERNET_O_MAC_WATCHDOG_TIMEOUT) &=\
        ~ETHERNET_MAC_WATCHDOG_TIMEOUT_WTO_M;
    HWREG(base + ETHERNET_O_MAC_WATCHDOG_TIMEOUT) |=\
        (timeout|ETHERNET_MAC_WATCHDOG_TIMEOUT_PWE);
}

void Ethernet_setMACConfiguration(uint32_t base,uint32_t flags)
{
    HWREG(base + ETHERNET_O_MAC_CONFIGURATION) |= flags;
}
void Ethernet_clearMACConfiguration(uint32_t base, uint32_t flags)
{
    HWREG(base + ETHERNET_O_MAC_CONFIGURATION) &= flags;

}

uint32_t Ethernet_configureL3L4Filter(uint32_t base, 
                                                                    Ethernet_L3_L4_FilterParams filterParams)
{
    Ethernet_L3_L4_Control  l3l4Control;
    if (filterParams.layer3IPSrcAddressMatchEnable || filterParams.layer3IPDestAddressMatchEnable)
    {
    //Check for IPV6
            if(filterParams.layer3ProtocolSel)
            {
                if(filterParams.layer3IPDestAddressMatchEnable && filterParams.layer3IPSrcAddressMatchEnable)
                 {
                        //
                        //Both Source and Destination Filtering not possible for IPv6 in EQOS
                        //There is only one 128 bit address configuration possible
                        return ETHERNET_ERR_INVALID_PARAM;
                   }
                else
                {
                    Ethernet_configureIPv6FilterAddress(base,
                                                                               filterParams.filterid,
                                                                               filterParams.layer3Address0,
                                                                               filterParams.layer3Address1,
                                                                               filterParams.layer3Address2,
                                                                               filterParams.layer3Address3
                                                                               );
                
                    
                }
                    
            }
            else
            {
                //IPv4 Filter
                if(filterParams.layer3IPSrcAddressMatchEnable)
                {
                    Ethernet_configureIPv4FilterSourceAddress(base,
                                                                                            filterParams.filterid,
                                                                                            filterParams.layer3Address0);
                 }
                if(filterParams.layer3IPDestAddressMatchEnable)
                {
                    Ethernet_configureIPv4FilterDestinationAddress(base,
                                                                                           filterParams.filterid,
                                                                                           filterParams.layer3Address1);
                 }
            }
            
    
    }
    if(filterParams.layer4SourcePortMatchEnable)
    {
    //Program L4
         Ethernet_configureLayer4FilterSrcAddress(base,
                                                                    filterParams.filterid,
                                                                    filterParams.layer4SourcePort
                                                                    );
    }
    if(filterParams.layer4DestinationPortMatchEnable)
    {
         Ethernet_configureLayer4FilterDstAddress(base,
                                                                        filterParams.filterid,
                                                                        filterParams.layer4DestinationPort
                                                                        );
    }
    //Program L3L4Filter control register structure
    memset(&l3l4Control,0,sizeof(Ethernet_L3_L4_Control));

    //There are no bit Shift and Mask Values so better to
    //in the xml file it is better to use structures to achieve
    //the programming easily
    
    if(filterParams.layer3ProtocolSel)
        l3l4Control.L3PEN |= ETHERNET_MAC_L3_L4_CONTROL0_L3PEN0_ENABLE;
    if(filterParams.layer3IPSrcAddressMatchEnable)
        l3l4Control.L3SAM = ETHERNET_MAC_L3_L4_CONTROL0_L3SAM0_ENABLE;
    if(filterParams.layer3IPDestAddressMatchEnable)
        l3l4Control.L3DAM = ETHERNET_MAC_L3_L4_CONTROL0_L3DAM0_ENABLE;
    //For IPv4 Packets you can program both Layer3 and 
    if(!filterParams.layer3ProtocolSel)
    {
        l3l4Control.L3HSBM = filterParams.layer3SrcHigherBitsMask; 
        l3l4Control.L3HDBM= filterParams.layer3DestHigherBitsMask;
    }
    else
     {
        //For IPv6 Packets it is only one bit field
        //Lower 5 bits will go into HSBM register
        if(filterParams.layer3IPSrcAddressMatchEnable)
        {
            l3l4Control.L3HSBM = filterParams.layer3SrcHigherBitsMask & 0x1FU;
            l3l4Control.L3HDBM= ((filterParams.layer3SrcHigherBitsMask & 0x60U) >> 5U);
        }
        else if(filterParams.layer3IPDestAddressMatchEnable)
        {
            l3l4Control.L3HSBM = filterParams.layer3DestHigherBitsMask & 0x1FU;
            l3l4Control.L3HDBM= ((filterParams.layer3DestHigherBitsMask & 0x60U) >> 5U);
        }
       
        
      }
    if(filterParams.layer4ProtocolSel)
        l3l4Control.L4PEN = ETHERNET_MAC_L3_L4_CONTROL0_L4PEN0_ENABLE;
    if(filterParams.layer4SourcePortMatchEnable)
        l3l4Control.L4SPM =ETHERNET_MAC_L3_L4_CONTROL0_L4SPM0_ENABLE;
    if(filterParams.layer4DestinationPortMatchEnable)
        l3l4Control.L4DPM = ETHERNET_MAC_L3_L4_CONTROL0_L4DPM0_ENABLE;
    if(filterParams.dmaChannelEnable)
        l3l4Control.DMACHEN = ETHERNET_MAC_L3_L4_CONTROL0_DMCHEN0_ENABLE;
    l3l4Control.DMACHN = filterParams.dmaChannelNum;

    Ethernet_configureL3L4FilterControl(base,filterParams.filterid,*(uint32_t*)&l3l4Control);
        
    return ETHERNET_RET_SUCCESS;
    
}

void Ethernet_configureIPv6FilterAddress(uint32_t base, 
                                                                                                                uint8_t filterid,
                                                                                                                uint32_t word0,
                                                                                                                 uint32_t word1, 
                                                                                                                 uint32_t word2, 
                                                                                                                 uint32_t word3)
{
    HWREG(base + (ETHERNET_O_MAC_LAYER3_ADDR0_REG0 + filterid * 0x30U)) =word0;
    HWREG(base + (ETHERNET_O_MAC_LAYER3_ADDR1_REG0 + filterid * 0x30U)) =word1;
    HWREG(base + (ETHERNET_O_MAC_LAYER3_ADDR2_REG0 + filterid * 0x30U)) =word2;
    HWREG(base + (ETHERNET_O_MAC_LAYER3_ADDR3_REG0 + filterid * 0x30U)) =word3;
}

void Ethernet_configureIPv4FilterSourceAddress
                    (uint32_t base, 
                      uint8_t filterid, 
                      uint32_t address)
{
    //
    //Address 0 Register configures the Source addres filter 
    HWREG(base + (ETHERNET_O_MAC_LAYER3_ADDR0_REG0 + filterid * 0x30U)) =address;
}
void Ethernet_configureIPv4FilterDestinationAddress
            (uint32_t base,
            uint8_t filterid, 
            uint32_t address)
{
    //
    //Address 1 Register configures the Destination addres filter 
    HWREG(base + (ETHERNET_O_MAC_LAYER3_ADDR1_REG0 + filterid * 0x30U)) =address;
}

void Ethernet_configureLayer4FilterSrcAddress(
            uint32_t base,
            uint8_t filterid,
            uint16_t srcAddress)
{
    HWREG(base+(ETHERNET_O_MAC_LAYER4_ADDRESS0 + filterid *0x30U)) |= 
                srcAddress <<ETHERNET_MAC_LAYER4_ADDRESS0_L4SP0_S ;
                                                                                                                                        
}
void Ethernet_configureLayer4FilterDstAddress(
                        uint32_t base,
                        uint8_t filterid,
                        uint16_t dstAddress)
{
    HWREG(base+(ETHERNET_O_MAC_LAYER4_ADDRESS0 + filterid *0x30U))|= \
                dstAddress<<ETHERNET_MAC_LAYER4_ADDRESS0_L4DP0_S;
}

void Ethernet_configureL3L4FilterControl(
                uint32_t base, 
                 uint8_t filterid,
                 uint32_t flags)
{
    HWREG(base+(ETHERNET_O_MAC_L3_L4_CONTROL0 + filterid *0x30U)) = flags;
}
                            
