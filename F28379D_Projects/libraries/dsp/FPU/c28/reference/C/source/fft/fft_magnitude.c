//#############################################################################
//! \file   reference/C/source/$FILENAME$
//! \brief  Fast Fourier Transform Magnitude
//! \author Vishal Coelho 
//! \date   03-Nov-2015
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
DSP_FILENUM(27)

//*****************************************************************************
// FFT_getMagnitude()
//*****************************************************************************
void FFT_getMagnitude(FFTHandle hnd)
{    
    // Locals
    uint16_t i,j,k;
    uint16_t N = FFT_getSize(hnd);
    fsize_t *mag = FFT_getMagBufferPtr(hnd);
    fsize_t *io = FFT_getIOBuffer2Ptr(hnd);

    if(FFT_getType(hnd) == ALT_REAL_RADIX_2)
    {
        i = 0U, j = i;
        mag[0] = fabs_t(io[0]);
#ifdef _DEBUG
        printf("i=%4d, io[i]=%10.7f, mag[i]=%10.7f\n",
            i, io[i], mag[i]);
#endif
      
        for(i = 1U, j = N - 1U; i < (N >> 1U); i++, j--)
        {
            mag[i] = sqrt(io[i]*io[i] + io[j]*io[j]);
#ifdef _DEBUG
            printf("i=%4d, io[i]=%10.7f+j%10.7f, mag[i]=%10.7f\n",
                i, io[i], io[j], mag[i]);
#endif
        }
        i = N >> 1U, j = i;
        mag[(N >> 1U)] = fabs_t(io[(N >> 1U)]);
#ifdef _DEBUG
        printf("i=%4d, io[i]=%10.7f, mag[i]=%10.7f\n",
            i, io[i], mag[i]);
#endif
    }
    else
    {
        for(i = 0U, j = 0U, k = 1U; i < N; i++, j += 2, k += 2)
        {
            mag[i] = sqrt(io[j]*io[j] + io[k]*io[k]);
#ifdef _DEBUG
            printf("i=%4d, io[i]=%10.7f+j%10.7f, mag[i]=%10.7f\n",
                i, io[j], io[k], mag[i]);
#endif
        }
    }
}

// End of File
