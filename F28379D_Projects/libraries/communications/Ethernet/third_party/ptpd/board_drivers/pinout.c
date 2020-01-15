//###########################################################################
//
// FILE:   pinout.c
//
// TITLE:  pinout for f2838x device.
//
//###########################################################################
// $TI Release: $
// $Release Date: $
// $Copyright: $
//###########################################################################

#include <stdint.h>
#include "board_drivers/pinout.h"

//*****************************************************************************
//
// Error handling function to be called when an ASSERT is violated
//
//*****************************************************************************
void __error__(char *filename, uint32_t line)
{
    //
    // An ASSERT condition was evaluated as false. You can use the filename and
    // line parameters to determine what went wrong.
    //
    __asm("   bkpt #0");
}

//*****************************************************************************
//
// Close the Doxygen group.
//! @}
//
//*****************************************************************************
