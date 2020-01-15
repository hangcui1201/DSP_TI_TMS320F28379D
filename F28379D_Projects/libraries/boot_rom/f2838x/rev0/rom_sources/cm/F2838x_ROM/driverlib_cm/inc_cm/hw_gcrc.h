//###########################################################################
//
// FILE:    hw_gcrc.h
//
// TITLE:   Definitions for the GCRC registers.
//
//###########################################################################
// $TI Release:  $
// $Release Date:  $
// $Copyright:  $
//###########################################################################

#ifndef HW_GCRC_H
#define HW_GCRC_H

//*****************************************************************************
//
// The following are defines for the GCRC register offsets
//
//*****************************************************************************
#define GCRC_O_CRCCTRL            0x0U         // CRC control register
#define GCRC_O_CRCPOLY            0x4U         // CRC polynomial register
#define GCRC_O_CRCDATAMASK        0x8U         // CRC data mask register
#define GCRC_O_CRCDATAIN          0xCU         // CRC DATA input register
#define GCRC_O_CRCDATAOUT         0x10U        // CRC data output register
#define GCRC_O_CRCDATATRANS       0x14U        // CRC data transformed register

//*****************************************************************************
//
// The following are defines for the bit fields in the CRCCTRL register
//
//*****************************************************************************
#define GCRC_CRCCTRL_POLYSIZE_S   0U
#define GCRC_CRCCTRL_POLYSIZE_M   0x3FU        // CRC polynomial order
#define GCRC_CRCCTRL_ENDIANNESS   0x40U        // Defines the endianness of the
                                               // data stream.
#define GCRC_CRCCTRL_BITREVERSE   0x80U        // Enables the DATAIN bus to the
                                               // CRC engine to be bit
                                               // reversed.
#define GCRC_CRCCTRL_DATATYPE_S   8U
#define GCRC_CRCCTRL_DATATYPE_M   0x300U       // Defines the DATATYPE of the
                                               // element of the data array.

//*****************************************************************************
//
// The following are defines for the bit fields in the CRCDATAMASK register
//
//*****************************************************************************
#define GCRC_CRCDATAMASK_DATAMASK_S  0U
#define GCRC_CRCDATAMASK_DATAMASK_M  0x1FU        // Number of bits to be masked
#endif
