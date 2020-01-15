//#############################################################################
//
//! \file   fastrts_atan2.c
//!
//! \brief  Runs the atan2 routine
//! \author Vishal Coelho
//! \date   Mar 4, 2016
//
//  Group:          C2000
//  Target Device:  TMS320F28004x
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
#include "fastrts_examples_setup.h"
#include "fastrts.h"
#include "fpu.h"

//*****************************************************************************
// the defines
//*****************************************************************************
#define TEST_SIZE   (256U)
//*****************************************************************************
// the globals
//*****************************************************************************
// The global pass, fail values
uint16_t pass = 0U, fail = 0U;
// The absolute error between the result and expected values
float64_t tolerance = 1.0e-7;
// There should be at most 10 bits of error in the mantissa
uint64_t toleranceLSBMantissa = (1 << 9);

float64_t test_output[TEST_SIZE];
float64_t test_error[TEST_SIZE];
//*****************************************************************************
// the function definitions
//*****************************************************************************
void FastRTS_runTest(void)
{
    // Locals
    uint16_t i, j;
    float64u_t in_y, in_x, out, gold, errld, errulp;

    for(i = 0U, j = 0U; i < TEST_SIZE; i++, j = j + 2)
    {
        out.f64  = DBL_MAX;
        in_y.f64   = test_input[j];
        in_x.f64   = test_input[j+1];
#if COMPILER_FPU64_SUPPORT == 1
        out.f64  = atan2(in_y.f64, in_x.f64);
#else
       run_atan2(&out, &in_y, &in_x);
#endif //
        test_output[i] = out.f64;
        gold.f64 = test_golden[i];

        if((FastRTS_Example_calcError((float64_t *)&out,
                (float64_t *)&gold,
                (float64_t *)&errld,
                (uint64_t *)&errulp,
                &tolerance,
                toleranceLSBMantissa)) != -1)
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
