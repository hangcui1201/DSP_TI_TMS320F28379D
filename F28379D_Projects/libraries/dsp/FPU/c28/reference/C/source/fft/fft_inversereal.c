//#############################################################################
//! \file   reference/C/source/$FILENAME$
//! \brief  Inverse Real Fast Fourier Transform
//! \author Vishal Coelho 
//! \date   10-Nov-2015
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
DSP_FILENUM(34)

//*****************************************************************************
// FFT_runIRFFT()
//*****************************************************************************
void FFT_runIRFFT(FFTHandle hnd)
{    
    // Locals
    uint16_t  N;
    fsize_t *temp;
    
    // Run the pack function
    FFT_pack(hnd);
    
    // The output of the pack is in the io2 buffer, the inverse complex FFTHandle
    // expects its input in the io buffer, we exchange the pointers
    temp = FFT_getIOBufferPtr(hnd);
    FFT_setIOBufferPtr(hnd, FFT_getIOBuffer2Ptr(hnd));
    FFT_setIOBuffer2Ptr(hnd, temp);

    // bit reverse the input - you do not need to set the size to N/2 
    // for the bitreverse operation, it will query the FFT type and do
    // the right thing
    hnd->bitrev(hnd);
    // run an N/2 point inverse complex FFT on the packed 
    // data
    N = FFT_getSize(hnd);
    FFT_setSize(hnd, N/2);
    if(FFT_getType(hnd) == REAL_RADIX_2)
    {
        FFT_runICFFT2(hnd);
    }
    else if (FFT_getType(hnd) == REAL_RADIX_4)
    {
        FFT_runICFFT4(hnd);
    }
    else
    {
        DSP_ASSERT(0U); // FFT Type is undefined
    }

    // Set the size back to its original
    FFT_setSize(hnd, N);

}

// End of File
