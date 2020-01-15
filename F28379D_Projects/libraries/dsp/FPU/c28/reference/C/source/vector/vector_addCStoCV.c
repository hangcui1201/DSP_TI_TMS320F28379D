//#############################################################################
//! \file   reference/C/source/$FILENAME$
//! \brief  Addition of a Complex Scalar to a Complex Vector
//! \author Vishal Coelho 
//! \date   21-Sep-2015
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
DSP_FILENUM(3)

//*****************************************************************************
// VECTOR_addCStoCV
//*****************************************************************************
void VECTOR_addCStoCV(complex_t *y, const complex_t *x,
                      const complex_t c, const uint16_t n)
{
    // Locals
    uint16_t i;
        
    for(i = 0U; i < n; i++)
    {
        y[i].r = x[i].r + c.r;
        y[i].i = x[i].i + c.i;
#ifdef _DEBUG
        // Debugging message
        printf("i=%4d, x=%10.7f+j%10.7f, c=%10.7f+j%10.7f, y=%10.7f+j%10.7f\n", 
               i, x[i].r, x[i].i, c.r, c.i, y[i].r, y[i].i);
#endif
    }
}

// End of File
