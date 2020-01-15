//#############################################################################
//! \file   reference/C/source/$FILENAME$
//! \brief  Multiplication of two Real Matrices
//! \author Vishal Coelho 
//! \date   30-Mar-2017
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
DSP_FILENUM(39)

//*****************************************************************************
// VECTOR_mpyRMbyRM
//*****************************************************************************
void VECTOR_mpyRMbyRM(fsize_t *y, const fsize_t *w, 
                      const fsize_t *x, const uint16_t m, 
                      const uint16_t n, const uint16_t p)
{
    //Locals
    uint16_t i, j, k;
    
    // Row-Major Order (Matrices are stored row by row)
    //
    // for(i = 0U; i < m; i++)
    // {
    //     for(j = 0U; j < p; j++)
    //     {
    //         *(y + i*m + j) = (fsize_t)0.0;
    //         for(k = 0U; k < n; k++)
    //         {
    //             *(y + i*m + j) += *(w + i*n + k) * *(x + k*p + j);
    //         }
    //     #ifdef _DEBUG
    //         // Debugging message
    //         printf("y[%4d][%4d]=%10.7f\n", i, j, *(y + i*m + j));
    //     #endif
    //     }
    // }
    
    // Column-Major Order (Matrices are stored column by column)
    //
    for(i = 0U; i < m; i++)
    {
        for(j = 0U; j < p; j++)
        {
            *(y + i + j*p) = (fsize_t)0.0;
            for(k = 0U; k < n; k++)
            {
                *(y + i + j*p) += *(w + i + k*m) * *(x + j*n + k);
            }
        #ifdef _DEBUG
            // Debugging message
            printf("y[%4d][%4d]=%10.7f\n", i, j, *(y + i*m + j));
        #endif
        }
    }
}

// End of File
