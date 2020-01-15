//#############################################################################
//! \file   reference/C/source/$FILENAME$
//! \brief  Euclidean product of two complex vectors
//! \author Vishal Coelho 
//! \date   18-Jul-2016
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
DSP_FILENUM(38)

//*****************************************************************************
// VECTOR_macCVbyCVC
//*****************************************************************************
complex_t VECTOR_macCVbyCV(const complex_t *w, const complex_t *x,
                      const uint16_t n)
{
    // Locals
    uint16_t i;
    complex_t y = {(fsize_t)0.0, (fsize_t)0.0};
    complex_t t;
        
    for(i = 0U; i < n; i++)
    {
        t.r  = ((w[i].r * x[i].r) - (w[i].i * x[i].i));
        y.r += t.r;
        t.i  = ((w[i].r * x[i].i)+(w[i].i * x[i].r));
        y.i += t.i;
#ifdef _DEBUG
        // Debugging message
        printf("i=%4d, w=%10.7f+j%10.7f, x=%10.7f+j%10.7f, t=%10.7f+j%10.7f\n",
               i, w[i].r, w[i].i, x[i].r, x[i].i, t.r, t.i);
#endif
    }
#ifdef _DEBUG
    printf("y=%10.7f+j%10.7f\n", y.r, y.i);
#endif
    return(y);
}

// End of File
