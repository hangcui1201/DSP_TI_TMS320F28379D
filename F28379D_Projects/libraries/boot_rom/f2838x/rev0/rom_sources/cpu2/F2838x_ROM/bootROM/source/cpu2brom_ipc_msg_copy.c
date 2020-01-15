//###########################################################################
//
// FILE:    cpu2brom_ipc_msg_copy.c
//
// TITLE:   CPU2 IPC Message Copy to RAM Boot Mode
//
// Function to copy from the CPU1 IPC message RAM into CPU2 M0RAM
//
//###########################################################################
// $TI Release:  $
// $Release Date:  $
//###########################################################################

//
// Included Files
//
#include "cpu2bootrom.h"

//
// Defines
//
#define IPC_LENGTH_TO_WORDS  (100UL)


//
// CPU2BROM_performCopyToRAM - Copy from CPU1-to-CPU2 Message RAM 1 to
//                             destination RAM
//                             
//                             copyLength is value that represents 100*x words
//                             (Ex: 0x2 = 200 words)
//
void CPU2BROM_performCopyToRAM(uint32_t entryAddress, uint16_t copyLength)
{
    uint32_t i;
    uint16_t offset = 0U;
    uint32_t escapeEntryAddress = 0xFFFFFFFFUL;

    //
    // CPU2 Patch/Escape Point 12
    //
    escapeEntryAddress = CPU2BROM_TI_OTP_ESCAPE_POINT_12;
    if((escapeEntryAddress != 0xFFFFFFFFUL) &&
       (escapeEntryAddress != 0x00000000UL))
    {
        //
        // If OTP is programmed, then call OTP patch function
        //
        ((void (*)(void))escapeEntryAddress)();
    }
    
    //
    // Copy from message RAM to destination RAM
    // (copyLength is adjusted to represent number of words to copy)
    //
    for(i = entryAddress; i<(entryAddress + (uint32_t)(IPC_LENGTH_TO_WORDS * copyLength)); i+=2U)
    {
        HWREG(i) = HWREG(CPU1_TO_CPU2_MESSAGE_RAM + offset);
        offset+=2U;
    }
}

//
// End of file
//
