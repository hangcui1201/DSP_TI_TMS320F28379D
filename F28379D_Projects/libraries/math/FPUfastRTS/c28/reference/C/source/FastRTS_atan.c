//#############################################################################
//! \file   reference/C/source/$FILENAME$
//! \brief  Arctangent
//! \author Vishal Coelho 
//! \date   26-Aug-2015
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
#include "fastrts.h"
#include "fastrts_assert.h"
//*****************************************************************************
// defines
//*****************************************************************************
FASTRTS_FILENUM(7)

//*****************************************************************************
// FastRTS_atan
//*****************************************************************************
fsize_t FastRTS_atan(const fsize_t x, const fsize_t *tbl)
{
    // Locals
    int32_t k;
    fsize_t r, a0, a1, a2, res;
    
    // Reduce the xument to the range [-1,1]
    if((fsize_t)1.0 >= fabs_t(x))
    {
        r = fabs_t(x)/(fsize_t)1.0;
    }
    else //(fsize_t)1.0 < fabs_t(x)
    {
        r = (fsize_t)1.0/fabs_t(x);
    }
    
    // Calculate the index into the lookup table, the table 
    // is a set of 3-tuples
    k = (uint16_t)(r * ARCTAN2_TBLSIZE);
    k = k * 3U;
    // Get the coefficients
    a0 = tbl[k++];
    a1 = tbl[k++];
    a2 = tbl[k++];
    // Calculate the arctangent for the first quadrant
    // 0 to +pi/4 (x > 0 && |x| <= 1.0)
    res = a0 + r*(a1 + a2*r);
    
    if((fsize_t)1.0 < fabs_t(x))
    {
        // if the argument lies in the first quadrant
        // +pi/4 to +pi/2, then we would have calculated
        // arctan(1/|x|). We can use the identity
        // arctan(x) = pi/2 - arctan(1/|x|)
        res = PI_O_2 - res;
    }

    if(x < (fsize_t)0.0)
    {
        // if the argument lies in the second quadrant
        // we use the identity arctan(-|x|) = -arctan(|x|).
        res = - res;
    }
#ifdef _DEBUG
    // Debugging message
    printf("x=%f, r=%f, k=%d, a0=%f, a1=%f, a2=%f, res=%f\n", 
           x, r, k, a0, a1, a2, res);
#endif
    return(res);
}

// End of File
