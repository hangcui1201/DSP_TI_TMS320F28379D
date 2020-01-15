//#############################################################################
//! \file   reference/C/source/$FILENAME$
//! \brief  exponent
//! \author Vishal Coelho 
//! \date   04-Jan-2017
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
FASTRTS_FILENUM(28)

//*****************************************************************************
// FastRTS_exp
//*****************************************************************************
fsize_t FastRTS_exp(const fsize_t x)
{
    // Locals
    fsize_t x_a    = fabs_t(x);
    // Separate the integer and fractional portion of the input
    isize_t x_i    = (isize_t)floor(x_a);
    fsize_t x_f    = x_a - floor(x_a);
    // Get e^integer(x) from the table
    fsize_t e_intx = FastRTS_expTable[x_i];
    // Calculate e^(fraction) by using the Taylor series expansion for
    // exponents
    //   x
    // e   = 1 + x*(1+x/2*(1+x/3*(1+x/4*(1+x/5*(1+x/6*(1+x/7)+...)))))
    // 
    fsize_t e_fracx = 1 + x_f*(1 + x_f*FPUINV2  *
                              (1 + x_f*FPUINV3  *
                              (1 + x_f*FPUINV4  *
                              (1 + x_f*FPUINV5  *
                              (1 + x_f*FPUINV6  *
#if USE_FPU32 == 1                              
                              (1 + x_f*FPUINV7))))));
#else  //USE_FPU64 == 1 
                              (1 + x_f*FPUINV7  *
                              (1 + x_f*FPUINV8  *
                              (1 + x_f*FPUINV9  *
                              (1 + x_f*FPUINV10 *
                              (1 + x_f*FPUINV11 *
                              (1 + x_f*FPUINV12 *
                              (1 + x_f*FPUINV13 *
                              (1 + x_f*FPUINV14)))))))))))));
#endif //USE_FPU32 == 1 
                    
    //  The result,  e^{x} = e^{integer}*e^{fraction}
    fsize_t e_x = e_intx * e_fracx;
    
    // If x was negative, calculate the inverse of the result
    if(x < 0.0)
    {
        e_x = 1/e_x;
    }

#ifdef _DEBUG
    // Debugging message
    printf("x=%f, x_i=%d, x_f=%f, e_intx=%e, e_fracx=%f, e_x=%e\n", 
           x, x_i, x_f, e_intx, e_fracx, e_x);
#endif
    return(e_x);
}

// End of File
