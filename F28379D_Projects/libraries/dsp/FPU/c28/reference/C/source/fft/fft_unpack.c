//#############################################################################
//! \file   reference/C/source/$FILENAME$
//! \brief  Unpack
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
DSP_FILENUM(25)

#define ONE_O_TWO   ((fsize_t)0.5)
//*****************************************************************************
// FFT_unpack()
//*****************************************************************************
void FFT_unpack(FFTHandle hnd)
{
    // Locals
    uint16_t i, k, N_o_two_m_k, N_m_k;
    
    uint16_t in_sep, p_sin, p_cos;
    uint16_t curr_stage, n_groups, n_bflys, bfly;
    fsize_t Zr, Zi, Zcr, Zci, IA, RS, RA, IS, S, C;
    fsize_t *tf          = FFT_getTwiddlePtr(hnd);
    fsize_t *Z           = FFT_getIOBufferPtr(hnd);
    fsize_t *F           = FFT_getIOBuffer2Ptr(hnd);
    uint16_t N           = FFT_getSize(hnd);
    uint16_t tblsize     = FFT_getTfTblSize(hnd);
    uint16_t tf_sep      = tblsize/4U;
    uint16_t skipfactor  = tblsize/N;

    FFT_setSkipFactor(hnd, skipfactor);
    // p_cos, p_sin are not used in the calculation 
    // for F(0) and F(N/2) since its a trivial calculation 
    // but it is necessary to update these pointers before 
    // running the F(1) calculation
    p_sin = 0U;
    p_cos = p_sin + tf_sep;
#ifdef _DEBUG
    printf("******************Unpack******************\n");   
    printf("N =%4d, tf_sep=%4d, skip factor=%4d \n",N, tf_sep, skipfactor);
    printf("******************************************\n");
#endif  

    // F(0)
    F[0]   = Z[0] + Z[1]; // Re(Z(0)) + Im(Z(0))
    F[1]   = (fsize_t)0.0;
#ifdef _DEBUG
        printf("k=   0, F(k)=%10.7f+j%10.7f\n", F[0], F[1]);
#endif
    // F(N/2)
    i     = N/2;
    k     = i*2U; 
    F[k]  = Z[0] - Z[1]; // F(N/2) = Re(Z(0))-Im(Z(0))
    F[k+1]= (fsize_t)0.0;
#ifdef _DEBUG
    printf("k=%4d, F(k)=%10.7f+j%10.7f\n", N/2, F[k], F[k+1]);
#endif
    // setup twiddle pointer for next butterfly
    p_sin = p_sin + skipfactor;
    p_cos = p_sin + tf_sep;
    
    // F(k) for k = 1 to N/2 - 1 and k = N/2+1 to N-1
    for (i = 1U; i <= (N/2 - 1U); i++)
    {
        // Convert index to account for size of complex data
        k           = i*2U;
        N_o_two_m_k = (N/2 - i)*2U; 
        N_m_k       = (N - i)*2U;
        Zr     = Z[k];
        Zi     = Z[k+1];
        Zcr    = Z[N_o_two_m_k];
        Zci    = Z[N_o_two_m_k + 1];
        S      = -tf[p_sin];
        C      =  tf[p_cos];
        DSP_ASSERT(((C*C+S*S)-1.0) < 1e-14);
        IA     = Zi + Zci; // Imaginarys add
        RS     = Zr - Zcr; // Reals subtract
        RA     = Zr + Zcr; // Reals add
        IS     = Zi - Zci; // Imaginarys subtract
        F[k]   = ONE_O_TWO*(RA + C*IA + S*RS);
        F[k+1] = ONE_O_TWO*(IS - C*RS + S*IA);
        // F(N-k) = F*(k)
        F[N_m_k]     =  F[k];
        F[N_m_k + 1] = -F[k+1];
#ifdef _DEBUG
        printf("k=%4d, Zr+jZi=%10.7f+j%10.7f, "
               "Zcr+jZci=%10.7f+j%10.7f, "
               "F(k)=%10.7f+j%10.7f, "
               "F(N-k)=%10.7f+j%10.7f\n",         
                i, Zr, Zi, Zcr, Zci, F[k], F[k+1], F[N_m_k], F[N_m_k+1]);
#endif
        // setup twiddle pointer for next butterfly
        p_sin = p_sin + skipfactor;
        p_cos = p_sin + tf_sep;
    }

}

// End of File
