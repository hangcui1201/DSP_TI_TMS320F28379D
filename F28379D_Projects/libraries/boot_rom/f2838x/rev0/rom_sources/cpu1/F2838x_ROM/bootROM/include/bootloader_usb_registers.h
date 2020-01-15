//###########################################################################
//
// FILE:   bootloader_usb_registers.h
//
// TITLE:  USB boot loader register definitions and helper macros
//
//###########################################################################
// $TI Release: $
// $Release Date: $
//###########################################################################

#ifndef USB_REGS_H_
#define USB_REGS_H_

//
//Register read/write helper functions, mostly to provide 8-bit reads on C28x
//
#define USB0_BASE               0x00040000UL

//
//Register offsets
//
#define USB_O_FADDR             0x00000000U  // USB Device Functional Address
#define USB_O_POWER             0x00000001U  // USB Power
#define USB_O_TXIS              0x00000002U  // USB Transmit Interrupt Status
#define USB_O_RXIS              0x00000004U  // USB Receive Interrupt Status
#define USB_O_TXIE              0x00000006U  // USB Transmit Interrupt Enable
#define USB_O_RXIE              0x00000008U  // USB Receive Interrupt Enable
#define USB_O_IS                0x0000000AU  // USB General Interrupt Status
#define USB_O_IE                0x0000000BU  // USB Interrupt Enable
#define USB_O_FRAME             0x0000000CU  // USB Frame Value
#define USB_O_EPIDX             0x0000000EU  // USB Endpoint Index
#define USB_O_TEST              0x0000000FU  // USB Test Mode

#define USB_O_FIFO0             0x00000020U  // USB FIFO Endpoint 0
#define USB_O_FIFO1             0x00000024U  // USB FIFO Endpoint 1
#define USB_O_FIFO2             0x00000028U  // USB FIFO Endpoint 2
#define USB_O_FIFO3             0x0000002CU  // USB FIFO Endpoint 3

#define USB_O_DEVCTL            0x00000060U  // USB Device Control
#define USB_O_TXFIFOSZ          0x00000062U  // USB Transmit Dynamic FIFO Sizing
#define USB_O_RXFIFOSZ          0x00000063U  // USB Receive Dynamic FIFO Sizing
#define USB_O_TXFIFOADD         0x00000064U  // USB Transmit FIFO Start Address
#define USB_O_RXFIFOADD         0x00000066U  // USB Receive FIFO Start Address
#define USB_O_CONTIM            0x0000007AU  // USB Connect Timing
#define USB_O_FSEOF             0x0000007DU  // USB Full-Speed Last Transaction to End of Frame Timing
#define USB_O_LSEOF             0x0000007EU  // USB Low-Speed Last Transaction to End of Frame Timing

#define USB_O_TXFUNCADDR0       0x00000080U  // USB Transmit Functional Address Endpoint 0
#define USB_O_TXHUBADDR0        0x00000082U  // USB Transmit Hub Address Endpoint 0
#define USB_O_TXHUBPORT0        0x00000083U  // USB Transmit Hub Port Endpoint 0
#define USB_O_TXFUNCADDR1       0x00000088U  // USB Transmit Functional Address Endpoint 1
#define USB_O_TXHUBADDR1        0x0000008AU  // USB Transmit Hub Address Endpont 1
#define USB_O_TXHUBPORT1        0x0000008BU  // USB Transmit Hub Port Endpoint 1
#define USB_O_RXFUNCADDR1       0x0000008CU  // USB Receive Functional Address Endpoint 1
#define USB_O_RXHUBADDR1        0x0000008EU  // USB Receive Hub Address Endpoint 1
#define USB_O_RXHUBPORT1        0x0000008FU  // USB Receive Hub Port Endpoint 1
#define USB_O_TXFUNCADDR2       0x00000090U  // USB Transmit Functional Address Endpoint 2
#define USB_O_TXHUBADDR2        0x00000092U  // USB Transmit Hub Address Endpoint 2
#define USB_O_TXHUBPORT2        0x00000093U  // USB Transmit Hub Port Endpoint 2
#define USB_O_RXFUNCADDR2       0x00000094U  // USB Receive Functional Address Endpoint 2
#define USB_O_RXHUBADDR2        0x00000096U  // USB Receive Hub Address Endpoint 2
#define USB_O_RXHUBPORT2        0x00000097U  // USB Receive Hub Port Endpoint 2
#define USB_O_TXFUNCADDR3       0x00000098U  // USB Transmit Functional Address Endpoint 3
#define USB_O_TXHUBADDR3        0x0000009AU  // USB Transmit Hub Address Endpoint 3
#define USB_O_TXHUBPORT3        0x0000009BU  // USB Transmit Hub Port Endpoint 3
#define USB_O_RXFUNCADDR3       0x0000009CU  // USB Receive Functional Address Endpoint 3
#define USB_O_RXHUBADDR3        0x0000009EU  // USB Receive Hub Address Endpoint 3
#define USB_O_RXHUBPORT3        0x0000009FU  // USB Receive Hub Port Endpoint 3

#define USB_O_CSRL0             0x00000102U  // USB Control and Status Endpoint 0 Low
#define USB_O_CSRH0             0x00000103U  // USB Control and Status Endpoint 0 High
#define USB_O_COUNT0            0x00000108U  // USB Receive Byte Count Endpoint 0
#define USB_O_TYPE0             0x0000010AU  // USB Type Endpoint 0
#define USB_O_NAKLMT            0x0000010BU  // USB NAK Limit
#define USB_O_TXMAXP1           0x00000110U  // USB Maximum Transmit Data Endpoint 1
#define USB_O_TXCSRL1           0x00000112U  // USB Transmit Control and Status Endpoint 1 Low
#define USB_O_TXCSRH1           0x00000113U  // USB Transmit Control and Status Endpoint 1 High
#define USB_O_RXMAXP1           0x00000114U  // USB Maximum Receive Data Endpoint 1
#define USB_O_RXCSRL1           0x00000116U  // USB Receive Control and Status Endpoint 1 Low
#define USB_O_RXCSRH1           0x00000117U  // USB Receive Control and Status Endpoint 1 High
#define USB_O_RXCOUNT1          0x00000118U  // USB Receive Byte Count Endpoint 1
#define USB_O_TXTYPE1           0x0000011AU  // USB Host Transmit Configure Type Endpoint 1
#define USB_O_TXINTERVAL1       0x0000011BU  // USB Host Transmit Interval Endpoint 1
#define USB_O_RXTYPE1           0x0000011CU  // USB Host Configure Receive Type Endpoint 1
#define USB_O_RXINTERVAL1       0x0000011DU  // USB Host Receive Polling Interval Endpoint 1
#define USB_O_TXMAXP2           0x00000120U  // USB Maximum Transmit Data Endpoint 2
#define USB_O_TXCSRL2           0x00000122U  // USB Transmit Control and Status Endpoint 2 Low
#define USB_O_TXCSRH2           0x00000123U  // USB Transmit Control and Status Endpoint 2 High
#define USB_O_RXMAXP2           0x00000124U  // USB Maximum Receive Data Endpoint 2
#define USB_O_RXCSRL2           0x00000126U  // USB Receive Control and Status Endpoint 2 Low
#define USB_O_RXCSRH2           0x00000127U  // USB Receive Control and Status Endpoint 2 High
#define USB_O_RXCOUNT2          0x00000128U  // USB Receive Byte Count Endpoint 2
#define USB_O_TXTYPE2           0x0000012AU  // USB Host Transmit Configure Type Endpoint 2
#define USB_O_TXINTERVAL2       0x0000012BU  // USB Host Transmit Interval Endpoint 2
#define USB_O_RXTYPE2           0x0000012CU  // USB Host Configure Receive Type Endpoint 2
#define USB_O_RXINTERVAL2       0x0000012DU  // USB Host Receive Polling Interval Endpoint 2
#define USB_O_TXMAXP3           0x00000130U  // USB Maximum Transmit Data Endpoint 3
#define USB_O_TXCSRL3           0x00000132U  // USB Transmit Control and Status Endpoint 3 Low
#define USB_O_TXCSRH3           0x00000133U  // USB Transmit Control and Status Endpoint 3 High
#define USB_O_RXMAXP3           0x00000134U  // USB Maximum Receive Data Endpoint 3
#define USB_O_RXCSRL3           0x00000136U  // USB Receive Control and Status Endpoint 3 Low
#define USB_O_RXCSRH3           0x00000137U  // USB Receive Control and Status Endpoint 3 High
#define USB_O_RXCOUNT3          0x00000138U  // USB Receive Byte Count Endpoint 3
#define USB_O_TXTYPE3           0x0000013AU  // USB Host Transmit Configure Type Endpoint 3
#define USB_O_TXINTERVAL3       0x0000013BU  // USB Host Transmit Interval Endpoint 3
#define USB_O_RXTYPE3           0x0000013CU  // USB Host Configure Receive Type Endpoint 3
#define USB_O_RXINTERVAL3       0x0000013DU  // USB Host Receive Polling Interval Endpoint 3
#define USB_O_RQPKTCOUNT1       0x00000304U  // USB Request Packet Count in Block Transfer Endpoint 1
#define USB_O_RQPKTCOUNT2       0x00000308U  // USB Request Packet Count in Block Transfer Endpoint 2
#define USB_O_RQPKTCOUNT3       0x0000030CU  // USB Request Packet Count in Block Transfer Endpoint 3

#define USB_O_RXDPKTBUFDIS      0x00000340U  // USB Receive Double Packet Buffer Disable
#define USB_O_TXDPKTBUFDIS      0x00000342U  // USB Transmit Double Packet Buffer Disable
#define USB_O_EPC               0x00000400U  // USB External Power Control
#define USB_O_EPCRIS            0x00000404U  // USB External Power Control Raw Interrupt Status
#define USB_O_EPCIM             0x00000408U  // USB External Power Control Interrupt Mask
#define USB_O_EPCISC            0x0000040CU  // USB External Power Control Interrupt Status and Clear
#define USB_O_DRRIS             0x00000410U  // USB Device RESUME Raw Interrupt Status
#define USB_O_DRIM              0x00000414U  // USB Device RESUME Interrupt Mask
#define USB_O_DRISC             0x00000418U  // USB Device RESUME Interrupt Status and Clear
#define USB_O_GPCS              0x0000041CU  // USB General-Purpose Control and Status
#define USB_O_IDVISC            0x0000444CU  // USB ID Valid Detect Interrupt status and clear
#define USB_O_DMASEL            0x00000450U  // USB DMA Select

//
//Bit definitions for USB_O_POWER
//
#define USB_POWER_ISOUP         0x00000080U  // Isochronous Update
#define USB_POWER_SOFTCONN      0x00000040U  // Soft Connect/Disconnect
#define USB_POWER_RESET         0x00000008U  // RESET Signaling
#define USB_POWER_RESUME        0x00000004U  // RESUME Signaling
#define USB_POWER_SUSPEND       0x00000002U  // SUSPEND Mode
#define USB_POWER_PWRDNPHY      0x00000001U  // Power Down PHY

//
//Bit definitions for USB_O_IE
//
#define USB_IE_VBUSERR          0x00000080U  // Enable VBUS Error Interrupt
#define USB_IE_SESREQ           0x00000040U  // Enable Session Request
#define USB_IE_DISCON           0x00000020U  // Enable Disconnect Interrupt
#define USB_IE_CONN             0x00000010U  // Enable Connect Interrupt
#define USB_IE_SOF              0x00000008U  // Enable Start-of-Frame Interrupt
#define USB_IE_RESET            0x00000004U  // Enable RESET Interrupt
#define USB_IE_RESUME           0x00000002U  // Enable RESUME Interrupt
#define USB_IE_SUSPND           0x00000001U  // Enable SUSPEND Interrupt

//
//Bit definitions for USB_O_CSRL0
//
#define USB_CSRL0_RXRDY         0x01U        // Received packet is ready
#define USB_CSRL0_TXRDY         0x02U        // Transmit FIFO is ready for transmission
#define USB_CSRL0_STALLED       0x04U        // Stall handshake has been sent
#define USB_CSRL0_DATAEND       0x08U        // Set to indicate no more TX/RX data
#define USB_CSRL0_SETEND        0x10U        // Control transfer ended prematurely
#define USB_CSRL0_STALL         0x20U        // Send a stall
#define USB_CSRL0_RXRDYC        0x40U        // Clear the RXRDY bit
#define USB_CSRL0_SETENDC       0x80U        // Clear the SETEND bit

#endif //USB_REGS_H_

//
// End of file
//
