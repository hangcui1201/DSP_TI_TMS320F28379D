//###########################################################################
//
// FILE:   bootloader_usb_structs.h
//
// TITLE:  USB boot loader descriptor structure definitions
//
//###########################################################################
// $TI Release: $
// $Release Date: $
//###########################################################################

#ifndef USB_STRUCTS_H_
#define USB_STRUCTS_H_

//
// Included Files
//
#include "cpu1bootrom.h"


//Descriptor types
#define USB_DTYPE_DEVICE        0x01U
#define USB_DTYPE_CONFIG        0x02U
#define USB_DTYPE_STRING        0x03U
#define USB_DTYPE_INTERFACE     0x04U
#define USB_DTYPE_ENDPOINT      0x05U
#define USB_DTYPE_DEVICE_QUAL   0x06U
#define USB_DTYPE_OSPEED_CONF   0x07U
#define USB_DTYPE_INTERFACE_PWR 0x08U

//
// Device descriptor
//
typedef struct
{
    uint16_t bDescriptorType_bLength;            //[7:0]  Descriptor length in bytes (18 for device)
                                                 //[15:8] Descriptor type (0x01 for device)
    uint16_t bcdUSB;                             //USB specification number -- 0x0110 for low/full speed
    uint16_t bDeviceSubClass_bDeviceClass;       //[7:0]  Subclass code
                                                 //[15:8] Class code -- 0x00 for interface-specific, 0xFF for vendor-specific
    uint16_t bMaxPacketSize_bDeviceProtocol;     //[7:0]  Protocol code
                                                 //[15:8] Maximum packet size for EP0 (64 for Soprano)
    uint16_t idVendor;                           //Vendor ID code -- 0x1CBE for TI
    uint16_t idProduct;                          //Product ID code -- assigned by manufacturer
    uint16_t bcdDevice;                          //Device release number
    uint16_t iProduct_iManufacturer;             //[7:0]  Index of manufacturer string descriptor
                                                 //[15:8] Index of product string descriptor
    uint16_t bNumConfigurations_iSerialNumber;   //[7:0]  Index of serial number string descriptor
                                                 //[15:8] Number of possible configurations
} sUsbDeviceDescriptor;

//
// Configuration descriptor
//
typedef struct
{
    uint16_t bDescriptorType_bLength;            //[7:0]  Descriptor length in bytes (9+1 for configuration)
                                                 //[15:8] Descriptor type (0x02 for configuration)
    uint16_t wTotalLength;                       //Total length of config, interface, and endpoint descriptors
    uint16_t bConfigurationValue_bNumInterfaces; //[7:0]  Number of interfaces in this descriptor
                                                 //[15:8] ID number of this configuration
    uint16_t bmAttributes_iConfiguration;        //[7:0]  Index of configuration string descriptor
                                                 //[15]   Reserved, set to 1
                                                 //[14]   Self-powered
                                                 //[13]   Remote wake-up
                                                 //[12:8] Reserved, set to 0
    uint16_t padding_bMaxPower;                  //[7:0]  Max power consumption in 2mA units
                                                 //[15:8] Unused -- only present for alignment
} sUsbConfigDescriptor;

//
// Interface descriptor
//
typedef struct
{
    uint16_t bDescriptorType_bLength;               //[7:0]  Descriptor length in bytes (9+1 for interface)
                                                    //[15:8] Descriptor type (0x04 for interface)
    uint16_t bAlternateSetting_bInterfaceNumber;    //[7:0]  Alternate interface number for SetInterface
                                                    //[15:8] ID number of this interface
    uint16_t bInterfaceClass_bNumEndpoints;         //[7:0]  Number of endpoints used by this interface
                                                    //[15:8] Interface-specific class code
    uint16_t bInterfaceProtocol_bInterfaceSubclass; //[7:0]  Interface-specific subclass code
                                                    //[15:8] Interface-specific protocol code
    uint16_t padding_iInterface;                    //[7:0]  Index of interface string descriptor
                                                    //[15:8] Unused -- only present for alignment
} sUsbInterfaceDescriptor;

//
// Endpoint descriptor
//
typedef struct
{
    uint16_t bDescriptorType_bLength;               //[7:0]  Descriptor length in bytes (7+1 for endpoint)
                                                    //[15:8] Descriptor type (0x05 for interface)
    struct
    {
        //bEndpointAddress
        uint16_t endpointNumber   : 4;           //Endpoint number
        uint16_t rsvd1            : 3;           //Reserved -- set to 0
        uint16_t direction        : 1;           //0: OUT, 1: IN (ignored for control endpoints)

        //bmAttributes
        uint16_t transferType     : 2;           //0x0: Control, 0x1: Isochronous, 0x2: Bulk, 0x3: Interrupt
        uint16_t syncMode         : 2;           //Synchronization mode (isochronous only)
        uint16_t usageType        : 2;           //Usage type (isochronous only)
        uint16_t rsvd2            : 2;           //Reserved
    } bmAttributes_bEndpointAddress;

    uint16_t wMaxPacketSize;                     //Maximum packet size this endpoint can send or receive
    uint16_t padding_bInterval;                  //[7:0]  Interval for polling data transfers (ignored for bulk and control)
                                                 //[15:0] Unused -- only present for alignment
} sUsbEndpointDescriptor;

//
// String descriptor
//
typedef struct
{
    uint16_t bDescriptorType_bLength;            //[7:0]  Descriptor length in bytes (2+L for string)
                                                 //[15:8] Descriptor type (0x03 for string)
    const char *bString;                         //Pointer to the actual string
} sUsbStringDescriptor;

//
// Standard control request identifiers
//
#define USB_REQ_GET_STATUS       0x00U
#define USB_REQ_CLEAR_FEATURE    0x01U
#define USB_REQ_SET_FEATURE      0x03U
#define USB_REQ_SET_ADDRESS      0x05U
#define USB_REQ_GET_DESCRIPTOR   0x06U
#define USB_REQ_SET_DESCRIPTOR   0x07U
#define USB_REQ_GET_CONFIG       0x08U
#define USB_REQ_SET_CONFIG       0x09U
#define USB_REQ_GET_INTERFACE    0x0AU
#define USB_REQ_SET_INTERFACE    0x0BU

//
// Control request types
//
#define USB_REQTYPE_STD          0x0U
#define USB_REQTYPE_CLASS        0x1U
#define USB_REQTYPE_VENDOR       0x2U

//
// Control request recipients
//
#define USB_REQREC_DEVICE        0x0U
#define USB_REQREC_INTERFACE     0x1U
#define USB_REQREC_ENDPOINT      0x2U
#define USB_REQREC_OTHER         0x3U

//
// Control request data packet format (received from host during enumeration)
//
typedef struct
{
    struct
    {
        uint16_t recipient   : 5;    //[4:0]  Recipient (0: device, 1: interface, 2: endpoint, 3: other)
        uint16_t reqType     : 2;    //[6:5]  Request type (00: standard, 01: class-specific, 10: vendor-specific)
        uint16_t dataDir     : 1;    //[7]    Direction of data flow (0: OUT, 1: IN)
        uint16_t bRequest    : 8;    //[15:8] Request identifier
    } bmRequestType_bRequest;
    uint16_t wValue;                 //Extra request-specific information
    uint16_t wIndex;                 //Extra request-specific information
    uint16_t wLength;                //Max number of bytes expected in the follow-up data packet (0: no data packet)
} sUsbRequestPacket;

//
// Implementations for use in the control request handler
//
extern const sUsbDeviceDescriptor loaderDeviceDescriptor;
extern const sUsbStringDescriptor langDescriptor;
extern const sUsbStringDescriptor mfgDescriptor;
extern const sUsbStringDescriptor prodDescriptor;
extern const sUsbStringDescriptor serialDescriptor;
extern const sUsbStringDescriptor loaderStringDescriptor;
extern const sUsbStringDescriptor * const stringDescriptors[];

//
// Function prototypes
//
void CombineUsbDescriptors(uint16_t *buffer);


#endif //USB_STRUCTS_H_

//
// End of file
//
