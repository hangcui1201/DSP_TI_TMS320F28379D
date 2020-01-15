//#############################################################################
//! \file   reference/C/source/$FILENAME$
//! \brief  Division: unsigned short (16-bit) / unsigned short (16-bit)
//! \author Vishal Coelho (adapted from original by Prasanth V.)
//! \date   14-Apr-2016
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
FASTRTS_FILENUM(18)

//*****************************************************************************
// FID_ui16byui16
//*****************************************************************************
void FID_ui16byui16(const uint16_t num, const uint16_t den, 
                           uint16_t *p_quo, uint16_t *p_rem)
{
    int16_t i;
    static int16_t iter = 1;

    // R3H = denominator
    R3.H.ui32 = (uint32_t)den;
    // R1H = numerator
    R1.H.ui32 = (uint32_t)(num << 16);
    
    ZERO(&R2);
    for(i = 0; i < 4; i++)
    {
        SUBC4UI32 (&R3.H, &R1.H, &R2.H, &status_flag);
    }
    
    *p_rem = (uint16_t)(R2.H.ui32);
    *p_quo = (uint16_t)(R1.H.ui32);
    
#ifdef _DEBUG
    printf("#%4u: %11u / %11u -> Q = %11u, R = %11u\n", 
            iter, num, den, *p_quo, *p_rem);
#endif //_DEBUG

    iter++;
}

// End of File
