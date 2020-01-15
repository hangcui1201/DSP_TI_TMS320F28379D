//#############################################################################
//
//! \file   dsp_mac_SP_CVxCV.c
//!
//! \brief  Runs the single precision complex vector MAC routine
//! \author Vishal Coelho
//! \date   Jul 18, 2016
//
//  Group:          C2000
//  Target Device:  TMS320f2838x
//
// The input and golden files were obtained by running the MATLAB script, 
// FPU_DSP_runVectorRoutines.m (under reference/MATLAB), at the MATLAB command 
// line as follows
// "
//   FPU_DSP_runVectorRoutines('macCVbyCV', 64, 'TYPE_FLOAT', 'FTYPE_C');
// "
// Please note that this script generates the input data using random values 
// ranging from -pi to pi so it may not be possible to generate the exact 
// same set of inputs and outputs given in this example.
// Also note the second complex vector is tacked on to the end of the first 
// vector in the input file
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
float tolerance = 1.0e-5;

//<<VC160916: cant check ulp error as this only applies to
// fixed point representation of the same set of numbers
//
// a tolerance of 1.0e-5 represented in IEEE754 format is
// 1.31072*2^-17, so the mantissa is roughly accurate to 17 bits
// Therefore, there may be error in the 32-17 = 15 LSbs
// uint32_t toleranceLSBMantissa = (1UL << 15);
//
// VC160916>>

// The second complex vector is tacked on to the end of the first complex 
// vector 
const float *test_input2 = &test_input[2U*TEST_SIZE];

#ifdef __TI_EABI__
#ifdef __cplusplus
#pragma DATA_SECTION(".bss:output")
#else
#pragma DATA_SECTION(test_output, ".bss:output")
#endif // __cplusplus
#else
#ifdef __cplusplus
#pragma DATA_SECTION(".ebss:output")
#else
#pragma DATA_SECTION(test_output, ".ebss:output")
#endif // __cplusplus
#endif //__TI_EABI__
float test_output[2U];
float test_error[2U];
//*****************************************************************************
// the function definitions
//*****************************************************************************
void DSP_runTest(void)
{
    // Locals
    complex_float result;
    float32u_t out, gold, err;

    //<<VC160916: cant check ulp error as this only applies to
    // fixed point representation of the same set of numbers
    //
    //float32u_t errulp;
    //
    // VC160916>>

    result.dat[0] = FLT_MAX;
    result.dat[1] = FLT_MAX;

    // Call the calculation routine
    result = mac_SP_CVxCV((complex_float *)&test_input[0U], 
                 (complex_float *)&test_input2[0U], TEST_SIZE);

    test_output[0U] = result.dat[0];
    test_output[1U] = result.dat[1];

    out.f32    = test_output[0U];
    gold.f32   = test_golden[0U];
    err.f32    = fabsf(out.f32 - gold.f32);
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
    test_error[0U] = err.f32;

    out.f32    = test_output[1U];
    gold.f32   = test_golden[1U];
    err.f32    = fabsf(out.f32 - gold.f32);
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
    test_error[1U] = err.f32;
}

// End of File
