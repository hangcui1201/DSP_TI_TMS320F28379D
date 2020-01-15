//#############################################################################
//! \file   reference/C/source/$FILENAME$
//! \brief  Fast Fourier Transform Windowing
//! \author Vishal Coelho 
//! \date   04-Nov-2015
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
#include "fft.h"
#include <math.h>

//*****************************************************************************
// defines
//*****************************************************************************
DSP_FILENUM(30)

//*****************************************************************************
// FFT_bitReverseIndex()
//*****************************************************************************
uint32_t FFT_bitReverseIndex(uint32_t idx, uint16_t nbits)
{    
    // Locals
    // exchange every adjacent bit
    idx = ((idx & 0xAAAAAAAA) >> 1)  | ((idx & 0x55555555) << 1);
    // exchange every bit pair       
    idx = ((idx & 0xCCCCCCCC) >> 2)  | ((idx & 0x33333333) << 2);
    // exchange every nibble         
    idx = ((idx & 0xF0F0F0F0) >> 4)  | ((idx & 0x0F0F0F0F) << 4);
    // exchange every byte           
    idx = ((idx & 0xFF00FF00) >> 8)  | ((idx & 0x00FF00FF) << 8);
    // exchange every word
    idx = ((idx & 0xFFFF0000) >> 16) | ((idx & 0x0000FFFF) << 16);
    // Shift right to get only nbits
    idx >>= (32 - nbits);
    
    return(idx);    
}

// End of File
