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
DSP_FILENUM(29)

//*****************************************************************************
// FFT_applyWindow()
//*****************************************************************************
void FFT_applyWindow(FFTHandle hnd)
{    
    // Locals
    uint16_t i, j, k;
    uint16_t N   = FFT_getSize(hnd);
    fsize_t *win = FFT_getWindowTblPtr(hnd);
    fsize_t *io  = FFT_getIOBufferPtr(hnd);
    fsize_t t_r, t_i, w;
    
    if((FFT_getType(hnd) == COMPLEX_RADIX_2) ||
       (FFT_getType(hnd) == COMPLEX_RADIX_4))
    {
        for(i = 0U, j = i, k =j+1; i < (N >> 1); i++, j += 2U, k += 2U)
        {
            t_r   = io[j];
            t_i   = io[k];
            w     = *win;
            io[j] = io[j] * (*win);
            io[k] = io[k] * (*win++);
#ifdef _DEBUG
            printf("i=%4d, io[i]=%10.7f+j%10.7f," 
                   " win=%10.7f, out=(%10.7f+j%10.7f)\n",
                    i, t_r, t_i, w, io[j], io[k]);
#endif
        }
        for(i = (N >> 1), j = N, k =j+1; i < N; i++, j += 2U, k += 2U)
        {
            t_r   = io[j];
            t_i   = io[k];
            io[j] = io[j] * (*--win);
            io[k] = io[k] * (*win);
            w     = *win;
#ifdef _DEBUG
            printf("i=%4d, io[i]=%10.7f+j%10.7f,"
                   " win=%10.7f, out=(%10.7f+j%10.7f)\n",
                    i, t_r, t_i, w, io[j], io[k]);
#endif
        }
    }
    else if ((FFT_getType(hnd) == REAL_RADIX_2) ||
             (FFT_getType(hnd) == REAL_RADIX_4))
    {
        for(i = 0U; i < (N >> 1); i++)
        {
            t_r   = io[i];
            w     = *win;
            io[i] = io[i] * (*win++);
#ifdef _DEBUG
            printf("i=%4d, io[i]=%10.7f, win*io[i]=%10.7f*(%10.7f)\n",
                    i, t_r, w, io[i]);
#endif
        }
        for(i = (N >> 1); i < N; i++)
        {
            t_r   = io[i];
            w     = *win;
            io[i] = io[i] * (*--win);
#ifdef _DEBUG
            printf("i=%4d, io[i]=%10.7f, win*io[i]=%10.7f*(%10.7f)\n",
                    i, t_r, w, io[i]);
#endif
        }
    }
    else
    {
        DSP_ASSERT(0U); //Type is invalid
    }
}

// End of File
