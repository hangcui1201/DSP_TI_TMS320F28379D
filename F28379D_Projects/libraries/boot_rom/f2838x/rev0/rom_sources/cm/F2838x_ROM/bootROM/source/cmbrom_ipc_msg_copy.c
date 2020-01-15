//###########################################################################
//
// FILE:    cmbrom_ipc_msg_copy.c
//
// TITLE:   CM IPC Message Copy to RAM Boot Mode
//
// Function to copy from the CPU1 IPC message RAM into CM S0RAM
//
//###########################################################################
// $TI Release:  $
// $Release Date:  $
//###########################################################################

//
// Included Files
//
#include "cmbootrom.h"

//
// Defines
//
#define IPC_LENGTH_TO_BYTES  (2UL * 100UL)

//
// Globals
//
extern uint32_t CMBROM_bootStatus;

//
// CMBROM_performCopyToRAM - Copy from CPU1-to-CM Message RAM 1 to 
//                           destination RAM
//
//                           copyLength is value that represents 100*x words 
//                           (Ex: 0x2 = 200 words or 400 bytes)
//
void CMBROM_performCopyToRAM(uint32_t entryAddress, uint16_t copyLength)
{
    uint32_t i;
    uint32_t escapeEntryAddress = 0xFFFFFFFFUL;
    uint16_t offset = 0U;
    
    //
    // CM Patch/Escape Point 11
    //
    escapeEntryAddress = CMBROM_TI_OTP_ESCAPE_POINT_11;
    if((escapeEntryAddress != 0xFFFFFFFFUL) &&
       (escapeEntryAddress != 0x00000000UL))
    {
        escapeEntryAddress |= 0x1U;  // BLX instruction result in a UsageFault exception
                                     // if bit[0] of Rm is 0, where Rm holds the branch
                                     // address.
        //
        // If OTP is programmed, then call OTP patch function
        //
        ((void (*)(void))escapeEntryAddress)();
    }

    //
    // Copy from message RAM to destination RAM (adjusting copyLength to words 
    // then x2 for byte addressing)
    //
    for(i = entryAddress; i<(entryAddress + (uint32_t)(IPC_LENGTH_TO_BYTES * copyLength)); i+=4U)
    {
        HWREG(i) = HWREG(CPU1_TO_CM_MESSAGE_RAM + offset);
        offset+=4U;
    }
}

//
// End of file
//
