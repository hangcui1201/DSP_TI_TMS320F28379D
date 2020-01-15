//#############################################################################
//! \file   reference/C/source/$FILENAME$
//! \brief  Division: unsigned long (64-bit) / unsigned long (64-bit)
//! \author Vishal Coelho (adapted from original by Prasanth V.)
//! \date   11-Apr-2016
//! 
//
//  Group:            C2000
//  Target Family:    $DEVICE$
//
//#############################################################################
// $TI Release: $
// $Release Date: $
// $Copyright: $
//#############################################################################


//*****************************************************************************
// the includes
//*****************************************************************************
#include "fid.h"
#include "fastrts_assert.h"
//*****************************************************************************
// defines
//*****************************************************************************
FASTRTS_FILENUM(15)

//*****************************************************************************
// FID_ui64byui64
//*****************************************************************************
void FID_ui64byui64(const uint64_t num, const uint64_t den, 
                           uint64_t *p_quo, uint64_t *p_rem)
{
    int16_t i;
    static int16_t iter = 1;

    // R3 = denominator
    R3.ui64 = den;
    // R1 = numerator
    R1.ui64 = num;
    // R2 = 0
    ZERO(&R2);
    // run the restoring division
    for(i = 0; i < 32; i++)
    {
        SUBC2UI64 (&R3, &R1, &R2, &status_flag);
    }
    
    *p_rem = (R2.ui64);
    *p_quo = (R1.ui64);
    
#ifdef _DEBUG
    printf("#%4u: %20lu / %20lu -> Q = %20lu, R = %20lu\n", 
            iter, num, den, *p_quo, *p_rem);
#endif //_DEBUG

    iter++;
}

// End of File
