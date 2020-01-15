//#############################################################################
//! \file   reference/C/source/$FILENAME$
//! \brief  Pack
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
DSP_FILENUM(33)

#define ONE_O_TWO   ((fsize_t)0.5)
//*****************************************************************************
// FFT_pack()
//*****************************************************************************
void FFT_pack(FFTHandle hnd)
{
    // Locals
    uint16_t i, k, N_o_two_m_k, N_m_k;
    
    uint16_t in_sep, p_sin, p_cos;
    uint16_t curr_stage, n_groups, n_bflys, bfly;
    fsize_t Fr, Fi, Fcr, Fci, IA, RS, RA, IS, S, C;
    fsize_t *tf          = FFT_getTwiddlePtr(hnd);
    fsize_t *F           = FFT_getIOBufferPtr(hnd);
    fsize_t *Z           = FFT_getIOBuffer2Ptr(hnd);
    uint16_t N           = FFT_getSize(hnd);
    uint16_t tblsize     = FFT_getTfTblSize(hnd);
    uint16_t tf_sep      = tblsize/4U;
    uint16_t skipfactor  = tblsize/N;

    FFT_setSkipFactor(hnd, skipfactor);

    p_sin = 0U;
    p_cos = p_sin + tf_sep;
#ifdef _DEBUG
    printf("******************Pack********************\n");   
    printf("N =%4d, tf_sep=%4d, skip factor=%4d \n",N, tf_sep, skipfactor);
    printf("******************************************\n");
#endif  

    // F(k) for k = 0 to N/2 - 1
    for (i = 0U; i <= (N/2 - 1U); i++)
    {
        // Convert index to account for size of complex data
        k           = i*2U;
        N_o_two_m_k = (N/2 - i)*2U; 
        Fr     = F[k];
        Fi     = F[k+1];
        Fcr    = F[N_o_two_m_k];
        Fci    = F[N_o_two_m_k + 1];
        S      =  tf[p_sin];
        C      =  tf[p_cos];
        DSP_ASSERT(((C*C+S*S)-1.0) < 1e-14);
        IA     = Fi + Fci; // Imaginarys add
        RS     = Fr - Fcr; // Reals subtract
        RA     = Fr + Fcr; // Reals add
        IS     = Fi - Fci; // Imaginarys subtract
        Z[k]   = ONE_O_TWO*(RA - C*IA - S*RS);
        Z[k+1] = ONE_O_TWO*(IS + C*RS - S*IA);
#ifdef _DEBUG
        printf("k=%4d, Fr+jFi=%10.7f+j%10.7f, "
               "Fcr+jFci=%10.7f+j%10.7f, "
               "Z(k)=%10.7f+j%10.7f\n",         
                i, Fr, Fi, Fcr, Fci, Z[k], Z[k+1]);
#endif
        // setup twiddle pointer for next butterfly
        p_sin = p_sin + skipfactor;
        p_cos = p_sin + tf_sep;
    }

}

// End of File
