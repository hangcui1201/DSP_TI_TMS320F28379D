//#############################################################################
//! \file   reference/C/source/$FILENAME$
//! \brief  Division
//! \author Vishal Coelho 
//! \date   24-Aug-2015
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
FASTRTS_FILENUM(6)


#if USE_FPU64 == 1
#define A0            ( 2.0)
#else //USE_FPU32 == 1
#define A0            ( 2.0F)
#endif //USE_FPU64 == 1
//*****************************************************************************
// FastRTS_div
//*****************************************************************************
fsize_t FastRTS_div(const fsize_t num, const fsize_t den)
{
    // Locals
    fsize_t xn, res;
    
    // Calculate the estimate of 1/den
    // NOTE: this is a call to the division routine of the std C library, 
    // and is therefore a very accurate estimate ...need to replace this 
    // with an algorithm to give the rough 1/den
    xn = 1/den;
    // Do the newton raphson iterations, 2 for single precision, 4 for 
    // double precision. Each iteration improves precision quadratically
    // i.e. each time you do it you double the number of accurate bits
    xn = xn*(A0 - xn*den);
    xn = xn*(A0 - xn*den);
#if USE_FPU64 == 1
    xn = xn*(A0 - xn*den);
    xn = xn*(A0 - xn*den);
#endif //USE_FPU64 == 1
    // Get the final result (num/den) by multiplying the estimate of the 
    // inverse with num
    res = num * xn;
#ifdef _DEBUG
    // Debugging message
    printf("num=%f, den=%f, res=%f\n", num, den, res);
#endif
    return(res);
}

// End of File
