//#############################################################################
//! \file   reference/C/source/$FILENAME$
//! \brief  Division: double (64-bit) / double (64-bit)
//! \author Vishal Coelho
//! \date   15-Apr-2016
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
#include "fid.h"
#include "fastrts_assert.h"
//*****************************************************************************
// defines
//*****************************************************************************
FASTRTS_FILENUM(22)

//*****************************************************************************
// FID_f64byf64
//*****************************************************************************
void FID_f64byf64(const double num, const double den, 
                        double *p_quo)
{
    int16_t i;
    static int16_t iter = 1;

    // R3 = denominator
    R3.f64 = den;
    // R1 = numerator
    R2.f64 = num;
    
    // extract the sign and exponent of the quotient
    PREDIVF64(&R0.H, &R2, &R1, &R3, &status_flag);    

    for(i = 0; i < 19; i++)
    {
        SUBC3F64 (&R2, &R1, &R3, &status_flag);
    }
    
    // Round and re-insert the sign and exponent of the quotient
    POSTDIVF64(&R1, &R0.H, &status_flag);
    
    // Save the quotient
    *p_quo = R1.f64;
    
#ifdef _DEBUG
    printf("#%4u: %20e / %20e -> Q = %20e\n", iter, num, den, *p_quo);
#endif //_DEBUG

    iter++;
}


// End of File
