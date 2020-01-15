//#############################################################################
//! \file   reference/C/source/$FILENAME$
//! \brief  Fast Fourier Transform Phase
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
DSP_FILENUM(28)

//*****************************************************************************
// FFT_getPhase()
//*****************************************************************************
void FFT_getPhase(FFTHandle hnd)
{    
    // Locals
    uint16_t i,j,k;
    uint16_t N     = FFT_getSize(hnd);
    fsize_t *phase = FFT_getPhaseBufferPtr(hnd);
    fsize_t *io    = FFT_getIOBuffer2Ptr(hnd);

    if(FFT_getType(hnd) == ALT_REAL_RADIX_2)
    {
        i = 0U, j = i;
        phase[0] = atan2(0U, io[0]);
#ifdef _DEBUG
        printf("i=%4d, io[i]=%10.7f, phase[i]=%10.7f\n",
            i, io[i], phase[i]);
#endif
        for(i = 1U, j = N - 1U; i < (N >> 1U); i++, j--)
        {
            phase[i] = atan2(io[j], io[i]);
#ifdef _DEBUG
            printf("i=%4d, io[i]=%10.7f+j%10.7f, phase[i]=%10.7f\n",
                i, io[i], io[j], phase[i]);
#endif
        } 
        i = N >> 1U, j = i;
        phase[N >> 1U] = atan2(0U, io[N >> 1U]);
#ifdef _DEBUG
        printf("i=%4d, io[i]=%10.7f, phase[i]=%10.7f\n",
            i, io[i], phase[i]);
#endif
    }
    else
    {
        for(i = 0U, j = 0U, k = 1U; i < N; i++, j += 2, k += 2)
        {
            phase[i] = atan2(io[k], io[j]);
#ifdef _DEBUG
            printf("i=%4d, io[i]=%10.7f+j%10.7f, phase[i]=%10.7f\n",
                i, io[j], io[k], phase[i]);
#endif
        }
    }
}

// End of File
