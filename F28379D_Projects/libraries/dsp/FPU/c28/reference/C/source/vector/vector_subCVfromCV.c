//#############################################################################
//! \file   reference/C/source/$FILENAME$
//! \brief  Subtraction of a Complex Vector and another Complex Vector
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
DSP_FILENUM(21)

//*****************************************************************************
// VECTOR_subCVfromCV
//*****************************************************************************
void VECTOR_subCVfromCV(complex_t *y, const complex_t *w, const complex_t *x,
                        const uint16_t n)
{
    // locals 
    uint16_t i;
    
    for(i = 0U; i < n; i++)
    {
        y[i].r = w[i].r -x[i].r;
        y[i].i = w[i].i -x[i].i;
    #ifdef _DEBUG
        // Debugging message
        printf("w=%10.7f+j%10.7f, x=%10.7f+j%10.7f, y=%10.7f+j%10.7f\n", 
                w[i].r, w[i].i, x[i].r, x[i].i, y[i].r, y[i].i);
    #endif
    }
}

// End of File
