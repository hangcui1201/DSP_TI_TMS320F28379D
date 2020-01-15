//#############################################################################
//
//! \file   dsp_mac_SP_i16RVxCV.c
//!
//! \brief  Runs the single precision Multiply-and-Accumulate rotuine, of a 
//!         Real Vector (integer) and a Complex Vector
//! \author Vishal Coelho
//! \date   Sep 16, 2016
//
//  Group:          C2000
//  Target Device:  TMS320f2838x
//
// The input and golden files were obtained by running the following commands
// at the MATLAB command prompt
//      N = 64;
//      A = int16(randi([intmin('int16'), intmax('int16')],1,N));
//      S_A = sprintf('%6d, %6d, %6d, %6d, \n', A);
//      B = rand(1,N)+1i.*rand(1,N);
//      C = sum(single(A).*B);
//      D = [real(B); imag(B)];
//      S_D = sprintf('%13.10fF, %13.10fF, %13.10fF, %13.10fF, \n', D);
//      E = reshape(D, 1, 128);
//      F = [real(C), imag(C)];
//      S_F = sprintf('%13.10fF, %13.10fF, \n', F);
// Write the contents of "S_A" followed by "S_E" (in separate vectors)to 
// input.c and "S_F" to golden.c
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
float tolerance = 4.0e-3;

//<<VC160916: cant check ulp error as this only applies to
// fixed point representation of the same set of numbers
//
// a tolerance of 4.0e-3 represented in IEEE754 format is
// 1.024*2^-8, so the mantissa is roughly accurate to 8 bits
// Therefore, there may be error in the 32-8 = 24 LSbs
// uint32_t toleranceLSBMantissa = (1UL << 24);
//
// VC160916>>

extern int16_t test_input2[];

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
	uint16_t i;
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
    result = mac_SP_i16RVxCV((complex_float *)&test_input[0U], 
                 (int16_t *)&test_input2[0U], TEST_SIZE);

    test_output[0U] = result.dat[0];
    test_output[1U] = result.dat[1];

    for(i = 0U; i < 2U; i++)
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
