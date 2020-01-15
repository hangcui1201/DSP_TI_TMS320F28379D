//#############################################################################
//! \file   reference/C/source/$FILENAME$
//! \brief  Multiplication of a Real Vector and a Complex Vector
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
DSP_FILENUM(16)

//*****************************************************************************
// VECTOR_mpyRVbyCV
//*****************************************************************************
void VECTOR_mpyRVbyCV(complex_t *y, const complex_t *w,
                      const fsize_t *x, const uint16_t n)
{
    //Locals
    uint16_t i;
    
    for(i = 0U; i < n; i++)
    {
        y[i].r = w[i].r*x[i];
        y[i].i = w[i].i*x[i];
    #ifdef _DEBUG
        // Debugging message
        printf("i=%4d, w=%10.7f+j%10.7f, x=%10.7f, y=%10.7f+j%10.7f\n", 
               i, w[i].r, w[i].i, x[i], y[i].r, y[i].i);
    #endif
    }
    
}

// End of File
