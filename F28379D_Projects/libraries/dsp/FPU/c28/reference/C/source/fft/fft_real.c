//#############################################################################
//! \file   reference/C/source/$FILENAME$
//! \brief  Real Fast Fourier Transform
//! \author Vishal Coelho 
//! \date   23-Oct-2015
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
DSP_FILENUM(26)

//*****************************************************************************
// FFT_runRFFT()
//*****************************************************************************
void FFT_runRFFT(FFTHandle hnd)
{    
    // Treat the real N-point input data as an N/2 point complex vector
    // and run a complex FFT on it
    uint16_t N = FFT_getSize(hnd);
    FFT_setSize(hnd, N/2);
    if(FFT_getType(hnd) == REAL_RADIX_2)
    {
        FFT_runCFFT2(hnd);
    }
    else if (FFT_getType(hnd) == REAL_RADIX_4)
    {
        FFT_runCFFT4(hnd);
    }
    else
    {
        DSP_ASSERT(0U); // FFT Type is undefined
    }
    
    // Run the unpack function
    FFT_setSize(hnd, N);
    FFT_unpack(hnd);
}

// End of File
