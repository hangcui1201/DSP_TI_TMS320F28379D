//###########################################################################
//
// FILE:    bootloader_shared_funcs.c
//
// TITLE:   Bootloader shared functions
//
// Shared Functions:
//
//     void CopyData(void)
//     uint32_t GetLongData(void)
//     void ReadReservedFn(void)
//
//###########################################################################
// $TI Release: $
// $Release Date: $
//###########################################################################

//
// Included Files
//
#include "cpu1bootrom.h"

//
// Globals
//
uint16fptr GetWordData; // GetWordData is a pointer to the function that
                        // interfaces to the peripheral. Each loader assigns
                        // this pointer to it's particular GetWordData function.

//
// CopyData - This routine copies multiple blocks of data from the host
//            to the specified RAM locations.  There is no error
//            checking on any of the destination addresses.
//            That is because it is assumed all addresses and block size
//            values are correct.
//
//            Multiple blocks of data are copied until a block
//            size of 00 00 is encountered.
//
void CopyData(void)
{
    struct HEADER {
        uint32_t DestAddr;        
        uint16_t BlockSize;
    } BlockHeader;

    uint16_t wordData;
    uint16_t i;

    //
    // Get the size in words of the first block
    //
    BlockHeader.BlockSize = (*GetWordData)();

    //
    // While the block size is > 0 copy the data
    // to the DestAddr.  There is no error checking
    // as it is assumed the DestAddr is a valid
    // memory location
    //
    while(BlockHeader.BlockSize != (uint16_t)0x0000U)
    {
        BlockHeader.DestAddr = GetLongData();

        for(i = 1; i <= BlockHeader.BlockSize; i++)
        {
            wordData = (*GetWordData)();
            *(uint16_t *)BlockHeader.DestAddr = wordData;
            BlockHeader.DestAddr+=1U;
        }

        //
        // Get the size of the next block
        //
        BlockHeader.BlockSize = (*GetWordData)();
    }

    return;
}

//
// GetLongData - This routine fetches a 32-bit value from the peripheral
//               input stream.
//
uint32_t GetLongData(void)
{
    uint32_t longData;

    //
    // Fetch the upper 1/2 of the 32-bit value
    //
    longData = ((uint32_t)((*GetWordData)()) << 16U);

    //
    // Fetch the lower 1/2 of the 32-bit value
    //
    longData |= (uint32_t)(*GetWordData)();

    return longData;
}

//
// ReadReservedFn - This function reads 8 reserved words in the header.
//                  None of these reserved words are used by the
//                  this boot loader at this time, they may be used in
//                  future devices for enhancements. Loaders that use
//                  these words use their own read function.
//
void ReadReservedFn(void)
{
    uint16_t i;

    //
    // Read and discard the 8 reserved words.
    //
    for(i = 1U; i <= 8U; i++)
    {
       (void)GetWordData();
    }

    return;
}

//
// End of File
//
