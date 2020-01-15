//#############################################################################
//
//! \file   dsp_rnd_SP_RS.c
//!
//! \brief  Rounding (Unbiased) of a Floating Point Scalar (Single Precision).
//! \author Vishal Coelho
//! \date   Sep 16, 2016
//
//  Group:          C2000
//  Target Device:  TMS320f2838x
//
// The input and golden files were obtained by running the MATLAB script, 
// FPU_DSP_runVectorRoutines.m (under reference/MATLAB), at the MATLAB command 
// line as follows
// "
//   FPU_DSP_runVectorRoutines('roundRS', 64, 'TYPE_FLOAT', 'FTYPE_C');
// "
// Please note that this script generates the input data using random values 
// so it may not be possible to generate the exact same set of inputs and 
// outputs given in this example.
//
//#############################################################################
// $TI Release: C28x Floating Point Unit Library V2.01.00.00 $
// $Release Date: May 27, 2019 $
// $Copyright: Copyright (C) 2019 Texas Instruments Incorporated -
//             http://www.ti.com/ ALL RIGHTS RESERVED $
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
float tolerance = 1.0e-9;


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

    
    //Clear out the output and error arrays
    memset(test_output, 0U, TEST_SIZE*sizeof(float));
    memset(test_error, 0U, TEST_SIZE*sizeof(float));

    for(i = 0U; i < TEST_SIZE; i++)
    {
        // Call the calculation routine
        test_output[i] = rnd_SP_RS(test_input[i]);

    }
    
    for(i = 0U; i < TEST_SIZE; i++)
    {
        out.f32  = test_output[i];
        gold.f32 = test_golden[i];
        err.f32  = fabsf(out.f32 - gold.f32);
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
