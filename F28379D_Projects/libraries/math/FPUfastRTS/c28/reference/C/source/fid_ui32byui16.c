//#############################################################################
//! \file   reference/C/source/$FILENAME$
//! \brief  Division: unsigned int (32-bit) / unsigned short (16-bit)
//! \author Vishal Coelho (adapted from original by Prasanth V.)
//! \date   15-Apr-2016
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
FASTRTS_FILENUM(20)

//*****************************************************************************
// FID_ui32byui16
//*****************************************************************************
void FID_ui32byui16(const uint32_t num, const uint16_t den, 
                           uint32_t *p_quo, uint16_t *p_rem)
{
    int16_t i;
    static int16_t iter = 1;

    // R3H = denominator
    R3.H.ui32 = den;
    // R1H = numerator
    R1.H.ui32 = num;
    
    ZERO(&R2);
    for(i = 0; i < 8; i++)
    {
        SUBC4UI32 (&R3.H, &R1.H, &R2.H, &status_flag);
    }
    
    *p_rem = (R2.H.ui32);
    *p_quo = (R1.H.ui32);
    
#ifdef _DEBUG
    printf("#%4u: %11u / %11u -> Q = %11u, R = %11u\n", 
            iter, num, den, *p_quo, *p_rem);
#endif //_DEBUG

    iter++;
}

// End of File
