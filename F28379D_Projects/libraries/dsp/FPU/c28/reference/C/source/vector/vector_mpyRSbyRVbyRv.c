//#############################################################################
//! \file   reference/C/source/$FILENAME$
//! \brief  Multiplication of a Real Scalar, a Real Vector, and another Real
//! Vector
//! \author Vishal Coelho 
//! \date   30-Sep-2015
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
DSP_FILENUM(15)

//*****************************************************************************
// VECTOR_mpyRSbyRVbyRV
//*****************************************************************************
void VECTOR_mpyRSbyRVbyRV(fsize_t *y, const fsize_t *w, const fsize_t *x,
                      const fsize_t c, const uint16_t n)
{
    //Locals
    uint16_t i;
    
    for(i = 0U; i < n; i++)
    {
        y[i] = c * w[i] * x[i];
    #ifdef _DEBUG
        // Debugging message
        printf("i=%4d, w=%10.7f, x=%10.7f, c=%10.7f, y=%10.7f\n", 
                i, w[i], x[i], c, y[i]);
    #endif
    }
    
}

// End of File
