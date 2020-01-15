//#############################################################################
//! \file   reference/C/source/$FILENAME$
//! \brief  Multiply-and-Accumulate of a Real Vector and a Complex Vector
//! \author Vishal Coelho 
//! \date   28-Sep-2015
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
#include "vector.h"
#include <math.h>

//*****************************************************************************
// defines
//*****************************************************************************
DSP_FILENUM(6)

//*****************************************************************************
// VECTOR_macRVbyCV
//*****************************************************************************
complex_t VECTOR_macRVbyCV(const complex_t *w, const fsize_t *x,
                      const uint16_t n)
{
    // Locals
    uint16_t i;
    complex_t y = {(fsize_t)0.0, (fsize_t)0.0};
        
    for(i = 0U; i < n; i++)
    {
        y.r += (x[i] * w[i].r);
        y.i += (x[i] * w[i].i);
#ifdef _DEBUG
        // Debugging message
        printf("i=%4d, w=%10.7f+j%10.7f, x=%10.7f\n",
               i, w[i].r, w[i].i, x[i]);
#endif
    }
#ifdef _DEBUG
    printf("y=%10.7f+j%10.7f\n", y.r, y.i);
#endif
    return(y);
}

// End of File
