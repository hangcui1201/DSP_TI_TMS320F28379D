//#############################################################################
//! \file   reference/C/source/$FILENAME$
//! \brief  Arctangent-2 (CORDIC)
//! \author Vishal Coelho 
//! \date   14-Nov-2016
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
#include "fastrts_cordic.h"
#include "fastrts_assert.h"
//*****************************************************************************
// defines
//*****************************************************************************
FASTRTS_FILENUM(27)

//*****************************************************************************
// FastRTS_CORDIC_atan2
//*****************************************************************************
fsize_t FastRTS_CORDIC_atan2(const fsize_t y, const fsize_t x)
{
    // Locals
    uint16_t i;
    CORDIC_t cordic;
    hnd_CORDIC_t h_cordic = &cordic;
    
    isize_t x_n, y_n;
    
    // All values are in IQMAX format
    isize_t x_i;
    isize_t y_i;
    isize_t z_i = 0;
    
    // Calculate theta for current x, y by first bring the arguments
    // in the first quadrant - the ratio lies well within the decomposable
    // angle limit
    if(fabs_t(x) < fabs_t(y))
    {
        x_i = FTOIQMAX(fabs_t(y));
        y_i = FTOIQMAX(fabs_t(x));
    }       
    else // fabs_t(x) >= fabs_t(y)   
    {       
        x_i = FTOIQMAX(fabs_t(x));
        y_i = FTOIQMAX(fabs_t(y));
    }
    
    
#ifdef _DEBUG
    printf("-------------------------x=%20.17f, y=%20.17f---------------------"
           "------------------------\n"
           "Starting point x_0 = %20.17f, y_0 = %20.17f, z_0 = %20.17f\n",
           x, y, IQMAXTOF(x_i), IQMAXTOF(y_i), IQMAXTOF(z_i));
#endif // _DEBUG

    // Set the object parameters
    FastRTS_CORDIC_setx_i(h_cordic, x_i);
    FastRTS_CORDIC_sety_i(h_cordic, y_i);
    FastRTS_CORDIC_setz_i(h_cordic, z_i);
    FastRTS_CORDIC_setN(h_cordic, MAX_CORDIC_ITERATIONS);
    FastRTS_CORDIC_setAtanTblPtr(h_cordic, FastRTS_CORDIC_atanTbl);
    FastRTS_CORDIC_setScaleTblPtr(h_cordic, FastRTS_CORDIC_scaleTbl);
    FastRTS_CORDIC_setRunKernelPtr(h_cordic, 
                                (v_pfn_v)FastRTS_CORDIC_vectoringKernel);
    
    // Call the CORDIC kernel
    h_cordic->runKernel(h_cordic);

    // Get the values of x_i, y_i, z_i computed by the kernel
    x_i = FastRTS_CORDIC_getx_i(h_cordic);
    y_i = FastRTS_CORDIC_gety_i(h_cordic);
    z_i = FastRTS_CORDIC_getz_i(h_cordic);
    
    if((x >= 0.0) && (fabs_t(x) >= fabs_t(y)))
    {
        // First Quadrant (upto pi/4)
        // calculated arctan(|y|/|x|)
        // z_i = z_i;
    }

   if((x >= 0.0) && (fabs_t(x) < fabs_t(y)))
   {
        // First Quadrant (pi/4 to pi/2)
        // calculated arctan(|x|/|y|)
        // identitiy: arctan(y/x) = pi/2 - arctan(|x|/|y|)
        z_i = FTOIQMAX(PI_O_2) - z_i;
   }

    if ((x < 0.0) && (fabs_t(x) < fabs_t(y)))
    {
        // Second quadrant (pi/2 to 3pi/4) (x <0 && |y| > |x|)
        // calculated arctan(|x|/|y|)
        // identitiy: arctan(y/x) = pi/2 - arctan(-|x|/|y|)
        //                        = pi/2 - -arctan(|x|/|y|)
        //                        = pi/2 + arctan(|x|/|y|)
        z_i = FTOIQMAX(PI_O_2) + z_i;
    }
    if ((x < 0.0) && (fabs_t(x) >= fabs_t(y)))
    {
        // Second quadrant (3pi/4 to pi) (x <0 && |y| <= |x|)
        // calculated arctan(|y|/|x|)
        // identitiy: arctan(y/-x) = -arctan(|y|/|x|)
        // We want to represent angles in the range [0,pi] as
        // positive, so we use this instead
        // identitiy: arctan(y/-x) = pi - arctan(|y|/|x|)
        z_i = FTOIQMAX(PI) - z_i;
    }
    if ( y < 0.0 ) 
    {
        // Third and Fourth quadrants
        z_i = -z_i;
    }

#ifdef _DEBUG
    printf("------------------------atan2(%20.17f, %20.17f)=%20.17f----------"
           "-------------\n\n", 
           y, x, IQMAXTOF(z_i));
#endif // _DEBUG

    return(IQMAXTOF(z_i));
}

// End of File
