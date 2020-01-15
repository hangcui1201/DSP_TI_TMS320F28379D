//###########################################################################
//
// FILE:   gcrc.c
//
// TITLE:  Driver for the GCRC module.
//
//###########################################################################
// $TI Release:  $
// $Release Date:  $
// $Copyright:  $
//###########################################################################

#include "gcrc.h"


//*****************************************************************************
//
// GCRC_setFixedPolynomialDataPath()
//
//*****************************************************************************
void
GCRC_setFixedPolynomialDataPath(uint32_t base)
{
    //
    // Check the arguments
    //
    ASSERT(GCRC_isBaseValid(base));

    //
    // Set the polynomial size, Endianness, dataType and Bitreverse fields
    //
    HWREG(base + GCRC_O_CRCCTRL) = ((uint32_t)GCRC_FIXEDPATH_POLYSIZE <<
                                    GCRC_CRCCTRL_POLYSIZE_S) |
                                   GCRC_FIXEDPATH_ENDIANNESS |
                                   GCRC_FIXEDPATH_DATATYPE   |
                                   GCRC_FIXEDPATH_BITREVERSE;

    //
    // Set the 32-bit polynomial
    //
    HWREG(base + GCRC_O_CRCPOLY) = GCRC_FIXEDPATH_POLY;

    //
    // Disable data masking
    //
    HWREG(base + GCRC_O_CRCDATAMASK) = GCRC_FIXEDPATH_DATAMASK;
}

//*****************************************************************************
//
// GCRC_writeData()
//
//*****************************************************************************
void
GCRC_writeData(uint32_t base, uint32_t data, uint32_t dataSize)
{
    //
    // Check the arguments
    //
    ASSERT(GCRC_isBaseValid(base));
    ASSERT((dataSize == GCRC_DATATYPE_8BIT)  ||
           (dataSize == GCRC_DATATYPE_16BIT) ||
           (dataSize == GCRC_DATATYPE_32BIT));

    if(dataSize == GCRC_DATATYPE_8BIT)
    {
        //
        // Perform a 8-bit write
        //
        HWREGB(base + GCRC_O_CRCDATAIN) = (uint8_t)data;
    }
    else if(dataSize == GCRC_DATATYPE_16BIT)
    {
        //
        // Perform a 16-bit write
        //
        HWREGH(base + GCRC_O_CRCDATAIN) = (uint16_t)data;
    }
    else
    {   //
        // Perform a 32-bit write
        //
        HWREG(base + GCRC_O_CRCDATAIN) = data;
    }
}

//*****************************************************************************
//
// GCRC_compute()
//
//*****************************************************************************
uint32_t
GCRC_compute(uint32_t base, void* pData, uint32_t dataType,
             uint32_t dataCount, uint32_t seedVal)
{
    bool bigEndian;
    uint32_t count;

    //
    // Check the arguments
    //
    ASSERT(GCRC_isBaseValid(base));

    //
    // Configure the data type
    //
    GCRC_setDataType(base, dataType);

    //
    // Set the seed Value
    //
    GCRC_setSeedValue(base, seedVal);

    //
    // Check the endianness.
    // If data is stored in little endian format, pData points to the LSB.
    // If data is stored in big endian format, pData points to MSB.
    //
    bigEndian = (HWREG(GCRC_BASE + GCRC_O_CRCCTRL) &
                 GCRC_CRCCTRL_ENDIANNESS) == GCRC_ENDIANNESS_BIG;

    count = dataCount;

    switch(dataType)
    {
        case GCRC_DATATYPE_8BIT:
        {
            //
            // Check for 32-bit alignment. For big endian data, check whether
            // the start address is aligned. For a little endian data, check
            // whether the address next to last address is aligned
            //
            uint32_t *addr;
            uint8_t  *addr8 =  bigEndian ? (uint8_t*)pData :
                                           (uint8_t*)pData + count;

            while(((uint32_t)addr8 & 0x3U) != 0U)
            {
                if(bigEndian)
                {
                    HWREGB(base + GCRC_O_CRCDATAIN) = *addr8;
                    addr8 = addr8 + 1U;
                    count--;
                }
                else
                {
                    addr8 = addr8 - 1U;
                    HWREGB(base + GCRC_O_CRCDATAIN) = *addr8;
                    count--;
                }
            }

            //
            // addr8 is now a 32-bit aligned address. Do 32-bit writes for
            // faster execution
            //
            addr = bigEndian ? (uint32_t *)addr8 : (uint32_t *)(addr8 - 4U);

            while(count >= 4U)
            {
                HWREG(base + GCRC_O_CRCDATAIN) = *addr;
                addr = bigEndian ? addr + 1U : addr - 1U;
                count -= 4U;
            }

            //
            // Fill in the last unaligned data if any
            //
            addr8 = bigEndian ? (uint8_t *)addr : (uint8_t *)addr + 3U;

            while(count > 0U)
            {
                HWREGB(base + GCRC_O_CRCDATAIN) = *addr8;
                addr8 = bigEndian ? addr8 + 1U : addr8 - 1U;
                count--;
            }
            break;
        }

        case GCRC_DATATYPE_16BIT:
        {
            //
            // Check for 32-bit alignment. For big endian data, check whether
            // the start address is aligned. For a little endian data, check
            // whether the second last address is aligned
            //
            uint32_t *addr;
            uint16_t *addr16 = bigEndian ? (uint16_t*)pData :
                                           (uint16_t*)pData + count - 2U;

            if(((uint32_t)addr16 & 0x3U) != 0U)
            {
                if(bigEndian)
                {
                    HWREGH(base + GCRC_O_CRCDATAIN) = *addr16;
                    addr16 = addr16 + 1U;
                }
                else
                {
                    HWREGH(base + GCRC_O_CRCDATAIN) = *(addr16 + 1U);
                    addr16 = addr16 - 1U;
                }
                count--;
            }

            //
            // addr16 is now a 32-bit aligned address. Do 32-bit writes for
            // faster execution
            //
            addr = (uint32_t *)addr16;

            while(count >= 2U)
            {
                HWREG(base + GCRC_O_CRCDATAIN) = *addr;
                addr = bigEndian ? addr + 1U : addr - 1U;
                count -= 2U;
            }

            //
            // Fill in the last unaligned data if any
            //
            if(count > 0U)
            {
                addr16 = bigEndian ? (uint16_t *)addr :
                                     (uint16_t *)addr + 1U;
                HWREGH(base + GCRC_O_CRCDATAIN) = *addr16;
            }
            break;
        }

        case GCRC_DATATYPE_32BIT:
        {
            uint32_t* addr;
            if(bigEndian)
            {
                addr = (uint32_t*)pData;
                while(count > 0U)
                {
                    HWREG(base + GCRC_O_CRCDATAIN) = *addr;
                    addr = addr + 1U;
                    count--;
                }
            }
            else
            {
                addr = (uint32_t*)pData + count - 1U;
                while(count > 0U)
                {
                    HWREG(base + GCRC_O_CRCDATAIN) = *addr;
                    addr = addr - 1U;
                    count--;
                }
            }
            break;
        }

        default:
            //
            // Empty
            //
            break;
    }
    //
    // Return the final CRC value
    //
    return(HWREG(base + GCRC_O_CRCDATAOUT));
}


//*****************************************************************************
//
// GCRC_compute_pc1()
//
//*****************************************************************************
uint32_t
GCRC_compute_pc1(uint32_t base, void* pData, uint32_t dataType,
                 uint32_t dataCount, uint32_t seedVal)
{
    bool bigEndian;
    uint32_t count;

    //
    // Check the arguments
    //
    ASSERT(GCRC_isBaseValid(base));

    //
    // Configure the data type
    //
    GCRC_setDataType(base, dataType);

    //
    // Set the seed Value
    //
    GCRC_setSeedValue(base, seedVal);

    //
    // Check the endianness.
    // If data is stored in little endian format, pData points to the LSB.
    // If data is stored in big endian format, pData points to MSB.
    //
    bigEndian = (HWREG(GCRC_BASE + GCRC_O_CRCCTRL) &
                 GCRC_CRCCTRL_ENDIANNESS) == GCRC_ENDIANNESS_BIG;

    count = dataCount;

    switch(dataType)
    {
        case GCRC_DATATYPE_8BIT:
        {
            uint8_t* addr8;
            if(bigEndian)
            {
                addr8 = (uint8_t*)pData;
                while(count > 0U)
                {
                    HWREGB(base + GCRC_O_CRCDATAIN) = *addr8;
                    addr8 = addr8 + 1U;
                    count--;
                }
            }
            else
            {
                addr8 = (uint8_t*)pData + count - 1U;
                while(count > 0U)
                {
                    HWREGB(base + GCRC_O_CRCDATAIN) = *addr8;
                    addr8 = addr8 - 1U;
                    count--;
                }
            }
            break;
        }

        case GCRC_DATATYPE_16BIT:
        {
            uint16_t* addr16;
            if(bigEndian)
            {
                addr16 = (uint16_t*)pData;
                while(count > 0U)
                {
                    HWREGH(base + GCRC_O_CRCDATAIN) = *addr16;
                    addr16 = addr16 + 1U;
                    count--;
                }
            }
            else
            {
                addr16 = (uint16_t*)pData + count - 1U;
                while(count > 0U)
                {
                    HWREGH(base + GCRC_O_CRCDATAIN) = *addr16;
                    addr16 = addr16 - 1U;
                    count--;
                }
            }
            break;
        }

        case GCRC_DATATYPE_32BIT:
        {
            uint32_t* addr;
            if(bigEndian)
            {
                addr = (uint32_t*)pData;
                while(count > 0U)
                {
                    HWREG(base + GCRC_O_CRCDATAIN) = *addr;
                    addr = addr + 1U;
                    count--;
                }
            }
            else
            {
                addr = (uint32_t*)pData + count - 1U;
                while(count > 0U)
                {
                    HWREG(base + GCRC_O_CRCDATAIN) = *addr;
                    addr = addr - 1U;
                    count--;
                }
            }
            break;
        }

        default:
            //
            // Empty
            //
            break;
    }
    //
    // Return the final CRC value
    //
    return(HWREG(base + GCRC_O_CRCDATAOUT));
}


