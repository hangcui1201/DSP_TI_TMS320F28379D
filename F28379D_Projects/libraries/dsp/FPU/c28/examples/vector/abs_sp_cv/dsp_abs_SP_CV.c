//#############################################################################
//
//! \file   dsp_abs_SP_CV.c
//!
//! \brief  Finds the magnitude of each entry of a complex vector
//! \author Vishal Coelho
//! \date   16-Sep-2016
//
//  Group:          C2000
//  Target Device:  TMS320f2838x
//
// The input and golden files were obtained by running the MATLAB script, 
// FPU_DSP_runVectorRoutines.m (under reference/MATLAB), at the MATLAB command 
// line as follows
// "
//   FPU_DSP_runVectorRoutines('absCV', 64, 'TYPE_FLOAT', 'FTYPE_C');
// "
// Please note that this script generates the input data using random values 
// ranging from -pi to pi so it may not be possible to generate the exact 
// same set of inputs and outputs given in this example.
//
//#############################################################################
// $TI Release: $
// $Release Date: $
// $Copyright: $
//#############################################################################


//*****************************************************************************
// the includes
//*****************************************************************************
#include "fpu.h"
#include "dsp.h"
#include "dsp_examples_setup.h"
#include "fpu32/fpu_vector.h"
#include <string.h>

//*****************************************************************************
// the defines
//*****************************************************************************
#define TEST_SIZE       (64U)

//*****************************************************************************
// the globals
//*****************************************************************************
// The global pass, fail values
uint16_t pass = 0U, fail = 0U;
// The absolute error between the result and expected values
float tolerance = 1.0e-6;

//<<VC160916: cant check ulp error as this only applies to
// fixed point representation of the same set of numbers
//
// a tolerance of 1.0e-6 represented in IEEE754 format is
// 1.0486*2^-20, so the mantissa is roughly accurate to 20 bits
// Therefore, there may be error in the 32-20 = 12 LSbs
// uint32_t toleranceLSBMantissa = (1UL << 12);
//
// VC160916>>

float test_output[TEST_SIZE];
float test_error[TEST_SIZE];
//*****************************************************************************
// the function definitions
//*****************************************************************************
void DSP_runTest(void)
{
    // Locals
	uint16_t i;
    float32u_t out, gold, err;

    //<<VC160916: cant check ulp error as this only applies to
    // fixed point representation of the same set of numbers
    //
    //float32u_t errulp;
    //
    // VC160916>>

    //Clear out the output and error arrays
    memset(test_output, 0U, TEST_SIZE*sizeof(float));
    memset(test_error, 0U, TEST_SIZE*sizeof(float));

    // Call the calculation routine
    abs_SP_CV(test_output, (const complex_float *)test_input, TEST_SIZE);

    for(i = 0U; i < TEST_SIZE; i++)
    {
        out.f32  = test_output[i];
        gold.f32 = test_golden[i];
        err.f32  = fabsf(out.f32 - gold.f32);
//<<VC160916: cant check ulp error as this only applies to
// fixed point representation of the same set of numbers
//
//        if(out.ui32 >= gold.ui32)
//        {
//            errulp.ui32 = out.ui32 - gold.ui32;
//        }
//        else
//        {
//            errulp.ui32 = gold.ui32 - out.ui32;
//        }
//
//        if((err.f32 < tolerance) &&
//           (errulp.ui32 < toleranceLSBMantissa))
//
// VC160916>>
        if(err.f32 < tolerance)
        {
            pass++;
        }
        else
        {
            fail++;
        }
        test_error[i] = err.f32;
    }

    //Clear out the output and error arrays
    memset(test_output, 0U, TEST_SIZE*sizeof(float));
    memset(test_error, 0U, TEST_SIZE*sizeof(float));

    // Call the more efficient calculation routine for even sized inputs
    abs_SP_CV_2(test_output, (const complex_float *)test_input, TEST_SIZE);

    for(i = 0U; i < TEST_SIZE; i++)
    {
        out.f32  = test_output[i];
        gold.f32 = test_golden[i];
        err.f32  = fabsf(out.f32 - gold.f32);
//<<VC160916: cant check ulp error as this only applies to
// fixed point representation of the same set of numbers
//
//        if(out.ui32 >= gold.ui32)
//        {
//            errulp.ui32 = out.ui32 - gold.ui32;
//        }
//        else
//        {
//            errulp.ui32 = gold.ui32 - out.ui32;
//        }
//
//        if((err.f32 < tolerance) &&
//           (errulp.ui32 < toleranceLSBMantissa))
//
// VC160916>>
        if(err.f32 < tolerance)
        {
            pass++;
        }
        else
        {
            fail++;
        }
        test_error[i] = err.f32;
    }
}

// End of File
