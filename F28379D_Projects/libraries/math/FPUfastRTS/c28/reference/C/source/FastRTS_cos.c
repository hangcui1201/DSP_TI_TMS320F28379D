//#############################################################################
//! \file   reference/C/source/$FILENAME$
//! \brief  Cosine
//! \author Vishal Coelho 
//! \date   19-Aug-2015
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
#include "fastrts.h"
#include "fastrts_assert.h"
//*****************************************************************************
// defines
//*****************************************************************************
FASTRTS_FILENUM(1)

#if USE_FPU64 == 1
#define A0            (-1.0)
#define A1            (-0.5)
#define A2            (0.166666666666667)
#else //USE_FPU32 == 1
#define A0            (-1.0F)
#define A1            (-0.5F)
#define A2            (0.166666666666667F)
#endif //USE_FPU64 == 1
//*****************************************************************************
// FastRTS_cos
//*****************************************************************************
fsize_t FastRTS_cos(const fsize_t theta, const fsize_t *tbl)
{
    // Locals
    int32_t k;
    fsize_t x, kf, res;
    const fsize_t *S = &tbl[0];
    const fsize_t *C = &tbl[SINCOS_TBLSIZE/4U];
    
    // Calculate the floating point index into the table
    kf = theta * RAD_ISTEP;
    // Calculate the signed integer index into the table
    k = (int32_t)(kf);
    // Calculate the fractional portion of theta that lies
    // between two table indices
    x = (kf - k) * RAD_STEP;
    // Negative values must wrap around and access the table from the end
    k = k & (SINCOS_TBLSIZE - 1U);
    // The cosine is given by the Taylor Series Expansion of the cosine
    res = C[k] + x*(A0*S[k] + x*(A1*C[k] + A2*x*S[k]));
#ifdef _DEBUG
    // Debugging message
    printf("theta=%f, kf=%f, k=%d, x=%f, C[k]=%f, S[k]=%f, res=%f\n", 
           theta, kf, k, x, C[k], S[k], res);
#endif
    return(res);
}

// End of File
