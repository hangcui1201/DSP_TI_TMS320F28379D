//###########################################################################
//
// FILE:   bootloader_usb_support_funcs.h
//
// TITLE:  USB boot loader support definitions
//
//###########################################################################
// $TI Release: $
// $Release Date: $
//###########################################################################

#ifndef USB_BOOT_FUNCS_H_
#define USB_BOOT_FUNCS_H_

//
// Included Files
//
#include "cpu1bootrom.h"
#include "bootloader_usb_registers.h"
#include "bootloader_usb_structs.h"

//
//Truth and falsehood
//
#ifndef true
#define true    1U
#endif

#ifndef false
#define false   0U
#endif

//
//Max packet size for endpoint 0
//
#define EP0_MAX_PACKET_SIZE 64U

//
//USB endpoint state enum
//
typedef enum
{
    USB_STATE_IDLE,      //Waiting for a request from the host controller
    USB_STATE_TX,        //Sending data to the host due to an IN request
    USB_STATE_RX,        //Receiving data from the host due to an OUT request
    USB_STATE_STALL,     //Waiting for the host to acknowledge a stall condition
    USB_STATE_STATUS     //Waiting for the host to acknowledge completion of an IN or OUT request
} eEndpointState;

//
// DATAEND selector enum
//
typedef enum
{
    USB_MORE_DATA,      //Do not set the DATAEND bit
    USB_END_DATA        //Set the DATAEND bit
} eDataEnd;

//
// Function prototypes
//
interrupt void UsbIntHandler(void);
static void UsbEndpoint0StateMachine(void);
static eEndpointState HandleControlRequest(const sUsbRequestPacket *req);
static void CopyStringDescriptor(const sUsbStringDescriptor *strDesc, uint16_t *buffer);
void ResetUsbDriver(void);

void TxDataEp0(const uint16_t *data, uint16_t length8, eDataEnd dataEnd);
uint16_t RxDataEp0(uint16_t *data);
static void StallEp0(void);
void AckEp0(eDataEnd dataEnd);

uint16_t RxDataEp1(uint16_t *data);
void AckEp1(void);


#endif //USB_BOOT_FUNCS_H_

//
// End of file
//
