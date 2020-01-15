//#############################################################################
//! \file   reference/C/source/$FILENAME$
//! \brief  Inverse Square Root
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
FASTRTS_FILENUM(5)


#if USE_FPU64 == 1
#define A0            ( 1.5)
#define A1            ( 0.5)
#else //USE_FPU32 == 1
#define A0            ( 1.5F)
#define A1            ( 0.5F)
#endif //USE_FPU64 == 1
//*****************************************************************************
// FastRTS_isqrt
//*****************************************************************************
fsize_t FastRTS_isqrt(const fsize_t x)
{
    // Locals
    fsize_t xn;
    
    // Calculate the estimate of the inverse square root
    // NOTE: this is a call to the sqrt of the std C library, and is therefore
    // a very accurate estimate ...need to replace this with an algorithm to
    // give the rough 1/sqrt(x)
    xn = 1/sqrt(x);
    // Do the newton raphson iterations, 2 for single precision, 4 for 
    // double precision. Each iteration improves precision quadratically
    // i.e. each time you do it you double the number of accurate bits
    xn = xn*(A0 - xn*xn*x*A1);
    xn = xn*(A0 - xn*xn*x*A1);
#if USE_FPU64 == 1
    xn = xn*(A0 - xn*xn*x*A1);
    xn = xn*(A0 - xn*xn*x*A1);
#endif //USE_FPU64 == 1
#ifdef _DEBUG
    // Debugging message
    printf("x=%f, res=%f\n", x, xn);
#endif
    return(xn);
}

// End of File
