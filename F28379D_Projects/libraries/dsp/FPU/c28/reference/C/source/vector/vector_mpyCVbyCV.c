//#############################################################################
//! \file   reference/C/source/$FILENAME$
//! \brief  Complex Multiply of Two Complex Vectors
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
DSP_FILENUM(12)

//*****************************************************************************
// VECTOR_mpyCVbyCV
//*****************************************************************************
void VECTOR_mpyCVbyCV(complex_t *y, const complex_t *w,
                      const complex_t *x, const uint16_t n)
{
    //Locals
    uint16_t i;
    
    for(i = 0U; i < n; i++)
    {
        y[i].r = w[i].r*x[i].r - w[i].i*x[i].i;
        y[i].i = w[i].r*x[i].i + w[i].i*x[i].r;
    #ifdef _DEBUG
        // Debugging message
        printf("i=%4d, w=%10.7f+j%10.7f, x=%10.7f+j%10.7f, y=%10.7f+j%10.7f\n",
               i, x[i].r, x[i].i, w[i].r, w[i].i, y[i].r, y[i].i);
    #endif
    }
    
}

// End of File
