//#############################################################################
//
//! \file   dsp_mpy_DP_CSxCS.c
//!
//! \brief  Multiplication of Two Complex Double Precision Numbers
//! \author Vishal Coelho
//! \date   Jul 21, 2016
//
//  Group:          C2000
//  Target Device:  TMS320f2838x
//
// The input and golden files were obtained by running the MATLAB script, 
// FPU_DSP_runVectorRoutines.m (under reference/MATLAB), at the MATLAB command 
// line as follows
// "
//   FPU_DSP_runVectorRoutines('mpyCSbyCS', 64, 'TYPE_DOUBLE', 'FTYPE_C');
// "
// Please note that this script generates the input data using random values 
// ranging from -pi to pi so it may not be possible to generate the exact 
// same set of inputs and outputs given in this example.
// Also note the second set of complex scalars is tacked on to the end of the 
// first set in the input file
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
#include "fpu64/vector.h"
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
float64_t tolerance = 1.0e-10;
// The second set of complex scalars is tacked on to the end of the 
// first set
float64_t *test_input2 = &test_input[2U*TEST_SIZE];

float64_t test_output[2U*TEST_SIZE];
float64_t test_error[2U*TEST_SIZE];
//*****************************************************************************
// the function definitions
//*****************************************************************************
void DSP_runTest(void)
{
    // Locals
    uint16_t i;
    float64u_t out, gold, errld;


    //Clear out the output and error arrays
    memset(test_output, 0U, (2U*TEST_SIZE)*sizeof(float64_t));
    memset(test_error, 0U, (2U*TEST_SIZE)*sizeof(float64_t));


    for(i = 0U; i < TEST_SIZE; i++)
    {
        // Call the calculation routine
        ((complexf64_t *)test_output)[i] = mpy_DP_CSxCS(
                        &((const complexf64_t *)test_input)[i], 
                        &((const complexf64_t *)test_input2)[i]);
    }              
    
    // Compute the error
    for(i = 0U; i < 2U*TEST_SIZE; i++)
    {
        out.f64  = test_output[i];
        gold.f64 = test_golden[i];

        // Calculation of error and comparison with tolerance
                errld.f64 = fabsf(out.f64 - gold.f64);
                       if(errld.f64 < tolerance)
                               {
                                   pass++;
                               }
                               else
                               {
                                   fail++;
                               }
                test_error[i] = errld.f64;
     }

}

// End of File
