//#############################################################################
//! \file   reference/C/source/$FILENAME$
//! \brief  Index of Maximum Value of a Real Array
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
DSP_FILENUM(7)

//*****************************************************************************
// VECTOR_maxidxRV
//*****************************************************************************
uint16_t VECTOR_maxidxRV(const fsize_t *x, const uint16_t n)
{
    // Locals
    uint16_t i, idx = 0U;
    fsize_t max = (fsize_t)0.0;
    
    for(i = 0U; i < n; i++)
    {
        
        if(x[i] > max)
        {
            max = x[i];
            idx = i;
        }
#ifdef _DEBUG
        // Debugging message
        printf("i=%4d, x[i]=%10.7f\n", i, x[i]);
#endif
    }
#ifdef _DEBUG
    // Debugging message
    printf("max_idx=%4d, max_val=%10.7f\n", idx, max);
#endif    
    return(idx);
}

// End of File
