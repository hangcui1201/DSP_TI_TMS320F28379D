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
DSP_FILENUM(31)

//*****************************************************************************
// FFT_bitReverseInput()
//*****************************************************************************
void FFT_bitReverseInput(FFTHandle hnd)
{    
   // Locals
    uint16_t i, bri, j, brj, k, brk;
    uint16_t N     = FFT_getSize(hnd);
    uint16_t nbits;
    fsize_t t_r, t_i;
    fsize_t *io    = FFT_getIOBufferPtr(hnd);
    
#ifdef _DEBUG
    printf("Bit Reversal of array of %d values\n", N);
#endif    
    if((FFT_getType(hnd) == COMPLEX_RADIX_2) ||
       (FFT_getType(hnd) == COMPLEX_RADIX_4) ||
       (FFT_getType(hnd) == ALT_REAL_RADIX_2))
    {
        // Do nothing
    }
    else if ((FFT_getType(hnd) == REAL_RADIX_2) ||
             (FFT_getType(hnd) == REAL_RADIX_4))
    {
        N = N >> 1; // must treat real input as N/2 complex and then bit-rev
    }
    else 
    {
        DSP_ASSERT(0U); //Type is invalid
    }   
    nbits = log2(N);
#ifdef _DEBUG
    printf("Each %d-bit index is reversed \n", nbits);
#endif  

    if(FFT_getType(hnd) == ALT_REAL_RADIX_2)
    {
        for(i = 0U; i < N; i++)
        {
            bri = FFT_bitReverseIndex(i, nbits);
            
            if(i < bri)
            {
                // Exhcange
                t_i       = io[i];
                io[i]     = io[bri];
                io[bri]   = t_i;
#ifdef _DEBUG
            printf("    Reversing i=%4d, br_i=%4d\n", i, bri);
#endif
            }
            else
            {
#ifdef _DEBUG
            printf("Not Reversing i=%4d, br_i=%4d\n", i, bri);
#endif            
            }
        }
    }
    else
    {
        for(i = 0U, j = i, k =j+1; i < N; i++, j += 2U, k += 2U)
        {
            bri = FFT_bitReverseIndex(i, nbits);
            brj = bri << 1; // accounts for the complex size
            brk = brj + 1;        
            
            if(i < bri)
            {
                // Exhcange
                t_r       = io[j];
                t_i       = io[k];
                io[j]     = io[brj];
                io[k]     = io[brk];
                io[brj]   = t_r;
                io[brk]   = t_i;
#ifdef _DEBUG
            printf("    Reversing i=%4d, br_i=%4d\n", j, brj);
#endif
            }
            else
            {
#ifdef _DEBUG
            printf("Not Reversing i=%4d, br_i=%4d\n", j, brj);
#endif            
            }
        }
    }
}

// End of File
