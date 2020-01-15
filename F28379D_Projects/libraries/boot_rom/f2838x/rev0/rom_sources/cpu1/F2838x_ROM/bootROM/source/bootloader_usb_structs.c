//###########################################################################
//
// FILE:    bootloader_usb_structs.c
//
// TITLE:   CPU1 USB Bootloader - Descriptor Implementations
//
// Functions for USB bootloader descriptors
//
//###########################################################################
// $TI Release: $
// $Release Date: $
//###########################################################################

//
// Included Files
//
#include "bootloader_usb_structs.h"

//
// Globals
//
const char langID = (char)0x0409U;    //US English
const char manufacturerString[] = "Texas Instruments";
const char productString[] = "TMS320F2838x USB Boot Loader";
const char serialString[] = "2";
const char loaderString[] = "C2000-BOOT";

const sUsbDeviceDescriptor loaderDeviceDescriptor =
{
    ((USB_DTYPE_DEVICE<<8U) | (2U*sizeof(sUsbDeviceDescriptor))),
    0x0110U,
    ((0x00U<<8U) | 0xFFU),
    ((64U<<8U) | 0x00U),
    0x1CBEU,
    0x00FFU,
    0x0001U,
    ((2U<<8U) | 1U),
    ((1U<<8U) | 3U)
};

//
// Configuration, interface, and functional descriptors for the loader.
// The wTotalLength must be set in software based on the total set of
// descriptors sent to the host.
//
const sUsbConfigDescriptor loaderConfigDescriptor =
{
    ((USB_DTYPE_CONFIG<<8U) | ((2U*sizeof(sUsbConfigDescriptor)) - 1U)),
    0U,
    ((1U<<8U) | 1U),
    ((0xC0U<<8U) | 0U),
    150U
};

const sUsbInterfaceDescriptor loaderInterfaceDescriptor =
{
    ((USB_DTYPE_INTERFACE<<8U) | ((2U*sizeof(sUsbInterfaceDescriptor)) - 1U)),
    ((0U<<8U) | 0U),
    ((0xFFU<<8U) | 1U),
    ((0x00U<<8U) | 0x00U),
    4U
};

const sUsbEndpointDescriptor loaderEndpointDescriptor =
{
    ((USB_DTYPE_ENDPOINT<<8U) | ((2U*sizeof(sUsbEndpointDescriptor)) - 1U)),
    {
        1U, 0U, 0U,        //Endpoint 1, OUT type
        2U, 0U, 0U, 0U     //Bulk mode transfers
    },
    64U,                //Max packet size in bytes (64 is max for bulk transfers)
    0U
};

//
// String descriptor structures. Each consists of a header followed by a
// pointer to the actual string. The full descriptor must be constructed
// at run-time by copying the header and the string into a temporary buffer.
//
const sUsbStringDescriptor langDescriptor =
{
    ((USB_DTYPE_STRING<<8U) | (2U + (2U*sizeof(langID)))),
    &langID
};

const sUsbStringDescriptor mfgDescriptor =
{
    ((USB_DTYPE_STRING<<8U) | (2U + (2U*sizeof(manufacturerString)))),
    manufacturerString
};

const sUsbStringDescriptor prodDescriptor =
{
    ((USB_DTYPE_STRING<<8U) | (2U + (2U*sizeof(productString)))),
    productString
};

const sUsbStringDescriptor serialDescriptor =
{
    ((USB_DTYPE_STRING<<8U) | (2U + (2U*sizeof(serialString)))),
    serialString
};

const sUsbStringDescriptor loaderStringDescriptor =
{
    ((USB_DTYPE_STRING<<8U) | (2U + (2U*sizeof(loaderString)))),
    loaderString
};

//
// String descriptor array. Used to provide indexing for descriptor requests.
// This needs to be a constant array of constant pointers to keep it out of
// the .cinit section.
//
const sUsbStringDescriptor * const stringDescriptors[] =
{
    &langDescriptor,
    &mfgDescriptor,
    &prodDescriptor,
    &serialDescriptor,
    &loaderStringDescriptor
};

//
// CombineUsbDescriptors - Combine the configuration, interface, and functional
//                         descriptors into a single block, stripping out the
//                         16-bit alignment padding in the process.
//
void CombineUsbDescriptors(uint16_t *buffer)
{
    uint16_t b, d, byteLength;

    b = 0U;
    d = 0U;
    byteLength = loaderConfigDescriptor.bDescriptorType_bLength & 0xFFU;

    while(byteLength--)
    {
        __byte((int *)buffer, b) = __byte((int *)&loaderConfigDescriptor, d);
        b += 1U;
        d += 1U;
    }

    d = 0U;
    byteLength = loaderInterfaceDescriptor.bDescriptorType_bLength & 0xFFU;

    while(byteLength--)
    {
        __byte((int *)buffer, b) = __byte((int *)&loaderInterfaceDescriptor, d);
        b += 1U;
        d += 1U;
    }

    d = 0U;
    byteLength = loaderEndpointDescriptor.bDescriptorType_bLength & 0xFFU;

    while(byteLength--)
    {
        __byte((int *)buffer, b) = __byte((int *)&loaderEndpointDescriptor, d);
        b += 1U;
        d += 1U;
    }

    //
    // Set wTotalLength
    //
    buffer[1] = (loaderConfigDescriptor.bDescriptorType_bLength & 0xFFU) +
                (loaderInterfaceDescriptor.bDescriptorType_bLength & 0xFFU) +
                (loaderEndpointDescriptor.bDescriptorType_bLength & 0xFFU);
}

//
// End of file
//

