//###########################################################################
//
// FILE:   gcrc.h
//
// TITLE:  Driver for the GCRC module.
//
//###########################################################################
// $TI Release:  $
// $Release Date:  $
// $Copyright: $
//###########################################################################

#ifndef GCRC_H
#define GCRC_H

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
//! \addtogroup gcrc_api GCRC
//! @{
//
//*****************************************************************************

#include <stdbool.h>
#include <stdint.h>
#include "debug.h"
#include "inc_cm/hw_memmap.h"
#include "inc_cm/hw_types.h"
#include "inc_cm/hw_gcrc.h"

//*****************************************************************************
//
// Defines for the API.
//
//*****************************************************************************
//*****************************************************************************
//
// GCRC endianness values that can be passed to GCRC_setDataEndianness()
// Endianness applies to word and half word writes.
//
//*****************************************************************************
#define GCRC_ENDIANNESS_LITTLE  0x00000000U //!< Little Endian
#define GCRC_ENDIANNESS_BIG     0x00000040U //!< Big Endian

//*****************************************************************************
//
// GCRC data types that can be passed as datatype param to GCRC_setDataType()
// and datasize param to GCRC_writeData()
//
//*****************************************************************************
#define GCRC_DATATYPE_8BIT      0x00000000U //!< Byte data type
#define GCRC_DATATYPE_16BIT     0x00000100U //!< 16-bit data type
#define GCRC_DATATYPE_32BIT     0x00000200U //!< 32 bit data type

//*****************************************************************************
//
// GCRC configuration for fixed polynomial path
//
//*****************************************************************************
#define GCRC_FIXEDPATH_POLY        0x04c11db7U            //!< 32 bit polynomial
#define GCRC_FIXEDPATH_POLYSIZE    0x00000020U            //!< 32 bit polynomial
#define GCRC_FIXEDPATH_ENDIANNESS  GCRC_ENDIANNESS_LITTLE //!< Little Endian
#define GCRC_FIXEDPATH_BITREVERSE  0U                     //!< No bit reversal
#define GCRC_FIXEDPATH_DATATYPE    GCRC_DATATYPE_32BIT    //!< 32 bit datatype
#define GCRC_FIXEDPATH_DATAMASK    0U                     //!< No masking

#define GCRC_POLYSIZE_MAXVALUE     0x20U //!< Max value possible for POLYSIZE
                                         //!< field in CRCCTRL register

//*****************************************************************************
//
// API Function prototypes
//
//*****************************************************************************
//*****************************************************************************
//
//! \internal
//! Checks GCRC base address.
//!
//! \param base is the base address of the GCRC instance used.
//!
//! This function determines if GCRC module base address is valid.
//!
//! \return Returns \b true if the base address is valid and \b false
//! otherwise.
//
//*****************************************************************************
#ifdef DEBUG
static inline bool
GCRC_isBaseValid(uint32_t base)
{
    return(base == GCRC_BASE);
}
#endif

//*****************************************************************************
//
//! Sets the generator polynomial.
//!
//! \param base is the base address of the GCRC instance used
//! \param poly is the generator polynomial
//! \param polySize is the order of the polynomial (1 - 32)
//!
//! This function sets the generator polynomial for computing CRC.
//!
//! \return None.
//
//*****************************************************************************
static inline void
GCRC_setPolynomial(uint32_t base, uint32_t poly, uint32_t polySize)
{
    //
    // Check the arguments
    //
    ASSERT(GCRC_isBaseValid(base));
    ASSERT((polySize != 0U) && (polySize <= GCRC_POLYSIZE_MAXVALUE));

    //
    // Set the polynomial size
    //
    HWREG(base + GCRC_O_CRCCTRL) = (polySize << GCRC_CRCCTRL_POLYSIZE_S) |
                                   (HWREG(base + GCRC_O_CRCCTRL) &
                                    ~(uint32_t)GCRC_CRCCTRL_POLYSIZE_M);

    //
    // Set the polynomial
    //
    HWREG(base + GCRC_O_CRCPOLY) = poly;
}

//*****************************************************************************
//
//! Sets the endianness of the data.
//!
//! \param base is the base address of the GCRC instance used
//! \param endianness is the data endianness. Use macros
//!                      GCRC_ENDIANNESS_LITTLE or GCRC_ENDIANNESS_BIG
//!
//! This function sets the endianness of the data.
//!
//! \return None.
//
//*****************************************************************************
static inline void
GCRC_setDataEndianness(uint32_t base, uint32_t endianness)
{
    //
    // Check the arguments
    //
    ASSERT(GCRC_isBaseValid(base));
    ASSERT((endianness == GCRC_ENDIANNESS_LITTLE) ||
           (endianness == GCRC_ENDIANNESS_BIG));

    //
    // Set the endianness in the control register
    //
    HWREG(base + GCRC_O_CRCCTRL) = (HWREG(base + GCRC_O_CRCCTRL) &
                                    ~(uint32_t)GCRC_CRCCTRL_ENDIANNESS) |
                                   endianness;

}

//*****************************************************************************
//
//! Sets the datatype of the data.
//!
//! \param base is the base address of the GCRC instance used
//! \param dataType is the data type of the input data. Use macros
//!                 GCRC_DATATYPE_8BIT, GCRC_DATATYPE_16BIT, GCRC_DATATYPE_32BIT
//!
//! This function set the data type of the element of the data array,
//! on which CRC is to be computed..
//!
//! \return None.
//
//*****************************************************************************
static inline void
GCRC_setDataType(uint32_t base, uint32_t dataType)
{
    //
    // Check the arguments
    //
    ASSERT(GCRC_isBaseValid(base));
    ASSERT((dataType == GCRC_DATATYPE_8BIT)  ||
           (dataType == GCRC_DATATYPE_16BIT) ||
           (dataType == GCRC_DATATYPE_32BIT));

    //
    // Set the data type in the control register
    //
    HWREG(base + GCRC_O_CRCCTRL) = (HWREG(base + GCRC_O_CRCCTRL) &
                                    ~(uint32_t)GCRC_CRCCTRL_DATATYPE_M) |
                                    dataType;
}

//*****************************************************************************
//
//! Enable/Disable bit reverse feature.
//!
//! \param base is the base address of the GCRC instance used
//! \param enable : TRUE if bit reverse needs to be enabled.
//!               : FALSE if bit reverse needs to be disabled
//!
//! This function enables/disables the bit reverse of the input data
//!
//! \return None.
//
//*****************************************************************************
static inline void
GCRC_enableBitReverse(uint32_t base, bool enable)
{
    //
    // Check the arguments
    //
    ASSERT(GCRC_isBaseValid(base));

    if(enable)
    {
        //
        // Set the bit reverse bit in control register
        //
        HWREG(base + GCRC_O_CRCCTRL) |= GCRC_CRCCTRL_BITREVERSE;
    }
    else
    {
        //
        // Clear the bit reverse bit in the control register
        //
        HWREG(base + GCRC_O_CRCCTRL) &= ~GCRC_CRCCTRL_BITREVERSE;
    }

}

//*****************************************************************************
//
//! Sets the data mask for the input data.
//!
//! \param base is the base address of the GCRC instance used
//! \param dataMask is the number of bits to be masked.
//!
//! This function set the data mask for the input data.
//! For example, dataMask equals 0x3, 3 most significant bits of data will
//! be masked.
//!
//! \return None.
//
//*****************************************************************************
static inline void
GCRC_setDataMask(uint32_t base, uint32_t dataMask)
{
#ifdef DEBUG
    uint32_t dataType = HWREG(base + GCRC_O_CRCCTRL) & GCRC_CRCCTRL_DATATYPE_M;
#endif
    //
    // Check the arguments
    //
    ASSERT(GCRC_isBaseValid(base));
    ASSERT(((dataType == GCRC_DATATYPE_8BIT)  && (dataMask < 8U))  ||
           ((dataType == GCRC_DATATYPE_16BIT) && (dataMask < 16U)) ||
           ((dataType == GCRC_DATATYPE_32BIT) && (dataMask < 32U)));

    //
    // Set the DATAMASK register
    //
    HWREG(base + GCRC_O_CRCDATAMASK) = dataMask;
}

//*****************************************************************************
//
//! Sets the seed value.
//!
//! \param base is the base address of the GCRC instance used
//! \param value is the seed value that needs to be set.
//!
//! This function sets the seed value for CRC computation.
//!
//! \return None.
//
//*****************************************************************************
static inline void
GCRC_setSeedValue(uint32_t base, uint32_t value)
{
    //
    // Check the arguments
    //
    ASSERT(GCRC_isBaseValid(base));

    //
    // Set the DATAOUT register with seed value
    //
    HWREG(base + GCRC_O_CRCDATAOUT) = value;
}


//*****************************************************************************
//
//! Reads the computed CRC value.
//!
//! \param base is the base address of the GCRC instance used
//!
//! This function read the computed CRC value.
//!
//! \note Reads from CRCDATAOUT register will be stalled if CRC engine is
//! busy computing CRC
//!
//! \return None.
//
//*****************************************************************************
static inline uint32_t
GCRC_readResult(uint32_t base)
{
    //
    // Check the arguments
    //
    ASSERT(GCRC_isBaseValid(base));

    return(HWREG(base + GCRC_O_CRCDATAOUT));
}

//*****************************************************************************
//
//! Reads the transformed data
//!
//! \param base is the base address of the GCRC instance used
//!
//! This function returns the data value as seen by the core CRC engine after
//! endianess, bit reversal and masking transformation
//!
//! \return None.
//
//*****************************************************************************
static inline uint32_t
GCRC_getTransData(uint32_t base)
{
    //
    // Check the arguments
    //
    ASSERT(GCRC_isBaseValid(base));

    return(HWREG(base + GCRC_O_CRCDATATRANS));
}

//*****************************************************************************
//
//! Sets the fixed polynomial data path.
//!
//! \param base is the base address of the GCRC instance used
//!
//! This function sets the fixed polynomial data path which computes
//! the CRC in a single cycle.
//!
//! \note Only 32-bit writes. Byte and halfword accesses would take the
//!  generic CRC data path.
//!
//! \return None.
//
//*****************************************************************************
extern void
GCRC_setFixedPolynomialDataPath(uint32_t base);


//*****************************************************************************
//
//! Writes the input data.
//!
//! \param base is the base address of the GCRC instance used
//! \param data is value that needs to be written.
//! \param dataSize is the size of the data. Use macros GCRC_DATATYPE_8BIT,
//!                 GCRC_DATATYPE_16BIT, GCRC_DATATYPE_32BIT
//!
//! This function writes the input data for the CRC computation.
//!
//! \note Writes to CRCDATAIN register will be stalled if CRC engine is
//! busy computing CRC
//!
//! \return None.
//
//*****************************************************************************
extern void
GCRC_writeData(uint32_t base, uint32_t data, uint32_t dataSize);

//*****************************************************************************
//
//! Computes CRC on the input data array.
//!
//! \param base is the base address of the GCRC instance used
//! \param pData is pointer to the data array
//! \param dataType is the data type of the input data. Use macros
//!                 GCRC_DATATYPE_8BIT, GCRC_DATATYPE_16BIT, GCRC_DATATYPE_32BIT
//! \param dataCount is the total number of data items in the array
//! \param seedVal is the seed value
//!
//! This function is used to compute CRC on the given array of data.
//!
//! \note Writes to CRCDATAIN register and reads from CRCDATAOUT register
//! will be stalled if CRC engine is busy computing CRC
//!
//! \return Returns the computed CRC value.
//
//*****************************************************************************
extern uint32_t
GCRC_compute(uint32_t base, void* pData, uint32_t dataType,
             uint32_t dataCount, uint32_t seedVal);

//*****************************************************************************
//
//! Computes CRC on the input data array.
//!
//! \param base is the base address of the GCRC instance used
//! \param pData is pointer to the data array
//! \param dataType is the data type of the input data. Use macros
//!                 GCRC_DATATYPE_8BIT, GCRC_DATATYPE_16BIT, GCRC_DATATYPE_32BIT
//! \param dataCount is the total number of data items in the array
//! \param seedVal is the seed value
//!
//! This function is used to compute CRC on the given array of data. This
//! function writes the data one by one to register. It does not use the
//! endianness feature of the IP. Use GCRC_compute for faster computation.
//!
//! \note Writes to CRCDATAIN register and reads from CRCDATAOUT register
//! will be stalled if CRC engine is busy computing CRC
//!
//! \return Returns the computed CRC value.
//
//*****************************************************************************
extern uint32_t
GCRC_compute_pc1(uint32_t base, void* pData, uint32_t dataType,
                 uint32_t dataCount, uint32_t seedVal);


//*****************************************************************************
//
// Close the Doxygen group.
//! @}
//
//*****************************************************************************

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif // GCRC_H
