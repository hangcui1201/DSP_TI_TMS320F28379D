//###########################################################################
//
// FILE:   enet_lwip.c
//
// TITLE:  lwIP based Ethernet Example.
//
//###########################################################################
// $TI Release: $
// $Release Date: $
// $Copyright: $
//###########################################################################

#include <string.h>

#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "inc/hw_nvic.h"
#include "inc/hw_types.h"
#include "inc/hw_sysctl.h"
#include "inc/hw_emac.h"

#include "driverlib_cm/ethernet.h"
#include "driverlib_cm/gpio.h"
#include "driverlib_cm/interrupt.h"

#include "driverlib_cm/sysctl.h"
#include "driverlib_cm/systick.h"

#include "utils/lwiplib.h"
#include "board_drivers/pinout.h"

#include "lwip/apps/httpd.h"
//*****************************************************************************
//
//! \addtogroup master_example_list
//! <h1>Ethernet with lwIP (enet_lwip)</h1>
//!
//! This example application demonstrates the operation of the F2838x
//! microcontroller Ethernet controller using the lwIP TCP/IP Stack. Once
//! programmed, the device sits endlessly waiting for ICMP ping requests. It
//! has a static IP address. To ping the device, the sender has to be in the
//! same network. The stack also supports ARP.
//!
//! For additional details on lwIP, refer to the lwIP web page at:
//! http://savannah.nongnu.org/projects/lwip/
//
//*****************************************************************************

// These are defined by the linker (see device linker command file)
extern unsigned long RamfuncsLoadStart;
extern unsigned long RamfuncsLoadSize;
extern unsigned long RamfuncsRunStart;

//*****************************************************************************
//
// Driver specific initialization code and macro.
//
//*****************************************************************************
#define ETHERNET_NO_OF_RX_PACKETS   8U
#define ETHERNET_MAX_PACKET_LENGTH 500
#define NUM_PACKET_DESC_RX_APPLICATION 8

Ethernet_Handle emac_handle;
Ethernet_InitConfig *pInitCfg;
uint32_t Ethernet_numRxCallbackCustom = 0;
uint32_t releaseTxCount = 0;

uint32_t systickPeriodValue = 15000000;
Ethernet_Pkt_Desc  pktDescriptorRXCustom[NUM_PACKET_DESC_RX_APPLICATION];
extern uint32_t Ethernet_numGetPacketBufferCallback;
extern Ethernet_Device Ethernet_device_struct;
uint8_t Ethernet_rxBuffer[ETHERNET_NO_OF_RX_PACKETS *
                          ETHERNET_MAX_PACKET_LENGTH];

extern Ethernet_Pkt_Desc*
lwIPEthernetIntHandler(Ethernet_Pkt_Desc *pPacket);

//*****************************************************************************
//
// HTTP Webserver related callbacks and definitions.
//
//*****************************************************************************
//
// Currently, this implemented as a pointer to function which is called when
// corresponding query is received by the HTTP webserver daemon. When more
// features are needed to be added, it should be implemented as a separate
// interface.
//
void httpLEDToggle(void);
void(*ledtoggleFuncPtr)(void) = &httpLEDToggle;

//*****************************************************************************
//
// The interrupt handler for the SysTick interrupt.
//
//*****************************************************************************
void
SysTickIntHandler(void)
{
    //
    // Call the lwIP timer handler.
    //
    lwIPTimer(systickPeriodValue);
}

//*****************************************************************************
//
//  This function is a callback function called by the example to
//  get a Packet Buffer. Has to return a ETHERNET_Pkt_Desc Structure.
//  Rewrite this API for custom use case.
//
//*****************************************************************************
Ethernet_Pkt_Desc* Ethernet_getPacketBufferCustom(void)
{
    //
    // Get the next packet descriptor from the descriptor pool
    //
    uint32_t shortIndex = (Ethernet_numGetPacketBufferCallback + 3)
                % NUM_PACKET_DESC_RX_APPLICATION;

    //
    // Increment the book-keeping pointer which acts as a head pointer
    // to the circular array of packet descriptor pool.
    //
    Ethernet_numGetPacketBufferCallback++;

    //
    // Update buffer length information to the newly procured packet
    // descriptor.
    //
    pktDescriptorRXCustom[shortIndex].bufferLength =
                                  ETHERNET_MAX_PACKET_LENGTH;

    //
    // Update the receive buffer address in the packer descriptor.
    //
    pktDescriptorRXCustom[shortIndex].dataBuffer =
                                      &Ethernet_device_struct.rxBuffer [ \
               (ETHERNET_MAX_PACKET_LENGTH*Ethernet_device_struct.rxBuffIndex)];

    //
    // Update the receive buffer pool index.
    //
    Ethernet_device_struct.rxBuffIndex += 1U;
    Ethernet_device_struct.rxBuffIndex  = \
    (Ethernet_device_struct.rxBuffIndex%ETHERNET_NO_OF_RX_PACKETS);

    //
    // Receive buffer is usable from Address 0
    //
    pktDescriptorRXCustom[shortIndex].dataOffset = 0U;

    //
    // Return this new descriptor to the driver.
    //
    return (&(pktDescriptorRXCustom[shortIndex]));
}

//*****************************************************************************
//
//  This is a hook function and called by the driver when it receives a
//  packet. Application is expected to replenish the buffer after consuming it.
//  Has to return a ETHERNET_Pkt_Desc Structure.
//  Rewrite this API for custom use case.
//
//*****************************************************************************
Ethernet_Pkt_Desc* Ethernet_receivePacketCallbackCustom(
        Ethernet_Handle handleApplication,
        Ethernet_Pkt_Desc *pPacket)
{
    //
    // Book-keeping to maintain number of callbacks received.
    //
#ifdef ETHERNET_DEBUG
    Ethernet_numRxCallbackCustom++;
#endif

    //
    // This is a placeholder for Application specific handling
    // We are replenishing the buffer received with another buffer
    //
    return lwIPEthernetIntHandler(pPacket);
}

void Ethernet_releaseTxPacketBufferCustom(
        Ethernet_Handle handleApplication,
        Ethernet_Pkt_Desc *pPacket)
{
    //
    // Once the packet is sent, reuse the packet memory to avoid
    // memory leaks. Call this interrupt handler function which will take care
    // of freeing the memory used by the packet descriptor.
    //
    lwIPEthernetIntHandler(pPacket);

    //
    // Increment the book-keeping counter.
    //
#ifdef ETHERNET_DEBUG
    releaseTxCount++;
#endif
}

void
Ethernet_init(const unsigned char *mac)
{
    Ethernet_InitInterfaceConfig initInterfaceConfig;
    uint32_t macLower;
    uint32_t macHigher;
    uint8_t *temp;

    initInterfaceConfig.ssbase = EMAC_SS_BASE;
    initInterfaceConfig.eqos_base = EMAC_BASE;
    initInterfaceConfig.phyMode = ETHERNET_SS_PHY_INTF_SEL_MII;

    //
    // Assign SoC specific functions for Enabling,Disabling interrupts
    // and for enabling the Peripheral at system level
    //
    initInterfaceConfig.ptrPlatformInterruptDisable =
                                                    &Platform_disableInterrupt;
    initInterfaceConfig.ptrPlatformInterruptEnable =
                                                     &Platform_enableInterrupt;
    initInterfaceConfig.ptrPlatformPeripheralEnable =
                                                    &Platform_enablePeripheral;
    initInterfaceConfig.ptrPlatformPeripheralReset =
                                                     &Platform_resetPeripheral;

    //
    // Assign the peripheral number at the SoC
    //
    initInterfaceConfig.peripheralNum = SYSCTL_PERIPH_CLK_ENET;

    //
    // Assign the default SoC specific interrupt numbers of Ethernet interrupts
    //
    initInterfaceConfig.interruptNum[0] = INT_EMAC;
    initInterfaceConfig.interruptNum[1] = INT_EMAC_TX0;
    initInterfaceConfig.interruptNum[2] = INT_EMAC_TX1;
    initInterfaceConfig.interruptNum[3] = INT_EMAC_RX0;
    initInterfaceConfig.interruptNum[4] = INT_EMAC_RX1;

    pInitCfg = Ethernet_initInterface(initInterfaceConfig);

    Ethernet_getInitConfig(pInitCfg);
    pInitCfg->dmaMode.InterruptMode = ETHERNET_DMA_MODE_INTM_MODE2;

    //
    // Assign the callbacks for Getting packet buffer when needed
    // Releasing the TxPacketBuffer on Transmit interrupt callbacks
    // Receive packet callback on Receive packet completion interrupt
    //
    pInitCfg->pfcbRxPacket = &Ethernet_receivePacketCallbackCustom;
    pInitCfg->pfcbGetPacket = &Ethernet_getPacketBufferCustom;
    pInitCfg->pfcbFreePacket = &Ethernet_releaseTxPacketBufferCustom;

    //
    //Assign the Buffer to be used by the Low level driver for receiving
    //Packets. This should be accessible by the Ethernet DMA
    //
    pInitCfg->rxBuffer = Ethernet_rxBuffer;

    //
    // The Application handle is not used by this application
    // Hence using a dummy value of 1
    //
    Ethernet_getHandle((Ethernet_Handle)1, pInitCfg , &emac_handle);

    //
    //Do global Interrupt Enable
    //
    (void)Interrupt_enableInProcessor();

    //
    //Assign default ISRs
    //
    Interrupt_registerHandler(INT_EMAC_TX0, Ethernet_transmitISR);
    Interrupt_registerHandler(INT_EMAC_RX0, Ethernet_receiveISR);

    //
    //Enable the default interrupt handlers
    //
    Interrupt_enable(INT_EMAC_TX0);
    Interrupt_enable(INT_EMAC_RX0);

    //
    // Convert the mac address string into the 32/16 split variables format
    // that is required by the driver to program into hardware registers.
    // Note: This step is done after the Ethernet_getHandle function because
    //       a dummy MAC address is programmed in that function.
    //
    temp = (uint8_t *)&macLower;
    temp[0] = mac[0];
    temp[1] = mac[1];
    temp[2] = mac[2];
    temp[3] = mac[3];

    temp = (uint8_t *)&macHigher;
    temp[0] = mac[4];
    temp[1] = mac[5];

    //
    // Program the unicast mac address.
    //
    Ethernet_setMACAddr(EMAC_BASE,
                        0,
                        macHigher,
                        macLower,
                        ETHERNET_CHANNEL_0);
}


//*****************************************************************************
//
// This example demonstrates the use of the Ethernet Controller.
//
//*****************************************************************************
int
main(void)
{
    unsigned long ulUser0, ulUser1;
    unsigned char pucMACArray[8];

    //
    // User specific IP Address Configuration.
    // Current implementation works with Static IP address only.
    //
    unsigned long IPAddr = 0xC0A80004;
    unsigned long NetMask = 0xFFFFFF00;
    unsigned long GWAddr = 0x00000000;

    SYSTICK_setPeriod(systickPeriodValue);
    SYSTICK_enableCounter();
    SYSTICK_registerInterruptHandler(SysTickIntHandler);
    SYSTICK_enableInterrupt();

    //
    // Enable processor interrupts.
    //
    Interrupt_enableInProcessor();
        
    // Set user/company specific MAC octets
    // (for this code we are using A8-63-F2-00-00-80)
    // 0x00 MACOCT3 MACOCT2 MACOCT1
    ulUser0 = 0x00F263A8;

    // 0x00 MACOCT6 MACOCT5 MACOCT4
    ulUser1 = 0x00800000;

    //
    // Convert the 24/24 split MAC address from NV ram into a 32/16 split MAC
    // address needed to program the hardware registers, then program the MAC
    // address into the Ethernet Controller registers.
    //
    pucMACArray[0] = ((ulUser0 >>  0) & 0xff);
    pucMACArray[1] = ((ulUser0 >>  8) & 0xff);
    pucMACArray[2] = ((ulUser0 >> 16) & 0xff);
    pucMACArray[3] = ((ulUser1 >>  0) & 0xff);
    pucMACArray[4] = ((ulUser1 >>  8) & 0xff);
    pucMACArray[5] = ((ulUser1 >> 16) & 0xff);

    //
    // Initialize ethernet module.
    //
    Ethernet_init(pucMACArray);

    //
    // Initialze the lwIP library, using DHCP.
    //
    lwIPInit(0, pucMACArray, IPAddr, NetMask, GWAddr, IPADDR_USE_STATIC);

    //
    // Initialize the HTTP webserver daemon.
    //
    httpd_init();

    //
    // Loop forever. All the work is done in interrupt handlers.
    //
    while(1);
}

//*****************************************************************************
//
// Called by lwIP Library. Toggles the led when a command is received by the
// HTTP webserver.
//
//*****************************************************************************
void httpLEDToggle(void)
{
    //
    // Toggle the LED D1 on the control card.
    //
    GPIO_togglePin(DEVICE_GPIO_PIN_LED1);
}


//*****************************************************************************
//
// Called by lwIP Library. Could be used for periodic custom tasks.
//
//*****************************************************************************
void lwIPHostTimerHandler(void)
{

}
