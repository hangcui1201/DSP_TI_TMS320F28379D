//###########################################################################
//
// FILE:   dcc.c
//
// TITLE:  C28x DCC driver.
//
//###########################################################################
// $TI Release:  $
// $Release Date:  $
// $Copyright:  $
//###########################################################################

#include "dcc.h"

//*****************************************************************************
//
// DCC_getRevisionNumber
//
//*****************************************************************************
uint16_t
DCC_getRevisionNumber(uint32_t base, DCC_RevisionNumber identifier)
{
    uint16_t number;

    //
    // Check the arguments.
    //
    ASSERT(DCC_isBaseValid(base));

    //
    //  Get specified revision number or scheme
    //
    if(identifier == DCC_REVISION_MINOR)
    {
        number = (HWREGH(base + DCC_O_REV) & DCC_REV_MINOR_M);
    }
    else if(identifier == DCC_REVISION_CUSTOM)
    {
        number = (HWREGH(base + DCC_O_REV) & DCC_REV_CUSTOM_M) >>
                 DCC_REV_CUSTOM_S;
    }
    else if(identifier == DCC_REVISION_MAJOR)
    {
        number = (HWREGH(base + DCC_O_REV) & DCC_REV_MAJOR_M) >>
                 DCC_REV_MAJOR_S;
    }
    else if(identifier == DCC_REVISION_DESIGN)
    {
        number = (HWREGH(base + DCC_O_REV) & DCC_REV_RTL_M) >>
                 DCC_REV_RTL_S;
    }
    else if(identifier == DCC_REVISION_FUNCTIONAL)
    {
        number = (HWREGH(base + DCC_O_REV + 2U) & (DCC_REG_WORD_MASK >> 4U));
    }
    else
    {
        // Module Scheme
        number = (HWREGH(base + DCC_O_REV + 2U) &
                  (uint16_t)(DCC_REV_SCHEME_M >> 16U)) >> 14U;
    }

    return(number);
}
