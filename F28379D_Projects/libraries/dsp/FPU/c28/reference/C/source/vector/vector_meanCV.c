//#############################################################################
//! \file   reference/C/source/$FILENAME$
//! \brief  Mean of Real and Imaginary Parts of a Complex Vector
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
DSP_FILENUM(8)

//*****************************************************************************
// VECTOR_meanCV
//*****************************************************************************
complex_t VECTOR_meanCV(const complex_t *x, const uint16_t n)
{
    // Locals
    uint16_t i;
    complex_t m = {(fsize_t)0.0, (fsize_t)0.0};
    fsize_t ONE_O_N = 1/(fsize_t)n;
    
    for(i = 0U; i < n; i++)
    {
        m.r += x[i].r;
        m.i += x[i].i;
#ifdef _DEBUG
        // Debugging message
        printf("i=%4d, x=%10.7f+j%10.7f\n", i, x[i].r, x[i].i);
#endif    
    }
    m.r *= ONE_O_N;
    m.i *= ONE_O_N;
#ifdef _DEBUG
    // Debugging message
    printf("m=%10.7f+j%10.7f\n", m.r, m.i);
#endif  
    return(m);
}

// End of File
