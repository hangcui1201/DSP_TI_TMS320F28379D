//#############################################################################
//! \file   reference/C/source/$FILENAME$
//! \brief  CORDIC Rotation Mode Kernel
//! \author Vishal Coelho 
//! \date   11-Nov-2016
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
FASTRTS_FILENUM(25)

//*****************************************************************************
// FastRTS_CORDIC_rotationKernel
//*****************************************************************************
void FastRTS_CORDIC_rotationKernel(hnd_CORDIC_t hc)
{
    // Locals
    uint16_t i;
    isize_t x_i         = FastRTS_CORDIC_getx_i(hc);
    isize_t y_i         = FastRTS_CORDIC_gety_i(hc);
    isize_t z_i         = FastRTS_CORDIC_getz_i(hc);
    const fsize_t *p_at = FastRTS_CORDIC_getAtanTblPtr(hc);
    uint16_t N          = FastRTS_CORDIC_getN(hc);
    isize_t x_n, y_n;
    fsize_t at;
    
    for (i = 0U; i < N; i++)
    {
        at = GET_TBL_HEX_VAL(p_at, i);
        if(z_i >= 0)
        {
            // Rotate counter clockwise to meet desired theta
            x_n = x_i - (y_i >> i);
            y_n = y_i + (x_i >> i);
            z_i = z_i -  FTOIQMAX(at);
        }
        else
        {
            // Rotate clockwise to meet desired theta
            x_n = x_i + (y_i >> i);
            y_n = y_i - (x_i >> i);
            z_i = z_i +  FTOIQMAX(at);
        }
        // Set the x, y for the next iteration
        x_i = x_n;
        y_i = y_n;

#ifdef _DEBUG
        printf("Iteration = %d, x_i=%20.17f, y_i=%20.17f,"
               " z_i=%20.17f t_i=%20.17f\n",
               i, IQMAXTOF(x_i), IQMAXTOF(y_i), IQMAXTOF(z_i), at);
#endif // _DEBUG
    }
    // Set the object x_i, y_i, z_i
    FastRTS_CORDIC_setx_i(hc, x_n);
    FastRTS_CORDIC_sety_i(hc, y_n);
    FastRTS_CORDIC_setz_i(hc, z_i);
}

// End of File
