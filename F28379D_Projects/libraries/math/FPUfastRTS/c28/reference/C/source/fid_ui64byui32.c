//#############################################################################
//! \file   reference/C/source/$FILENAME$
//! \brief  Division: unsigned long (64-bit) / unsigned int (32-bit)
//! \author Vishal Coelho (adapted from original by Prasanth V.)
//! \date   04-Apr-2016
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
FASTRTS_FILENUM(12)

//*****************************************************************************
// FID_ui64byui32
//*****************************************************************************
void FID_ui64byui32(const uint64_t num, const uint32_t den, 
                           uint64_t *p_quo, uint32_t *p_rem)
{
    int16_t i;
    static int16_t iter = 1;

    ZERO(&R2);
    ZERO(&R3);
    
    // R3H = denominator
    R3.H.ui32 = den;
    // R1 = numerator
    R1.ui64 = num;
    
    // run the restoring division on the upper dword
    for(i = 0; i < 8; i++)
    {
        SUBC4UI32 (&R3.H, &R1.H, &R2.H, &status_flag);
    }
    // swap the upper and lower dwords of the numerator
    SWAPI64(&R1);
    // run the restoring division on the upper dword
    for(i = 0; i < 8; i++)
    {
        SUBC4UI32 (&R3.H, &R1.H, &R2.H, &status_flag);
    }
    // restore the numerator
    SWAPI64(&R1);
    
    *p_rem = (R2.H.ui32);
    *p_quo = (R1.ui64);
    
#ifdef _DEBUG
    printf("#%4u: %11lu / %11u -> Q = %11lu, R = %11u\n", 
            iter, num, den, *p_quo, *p_rem);
#endif //_DEBUG

    iter++;
}

// End of File
