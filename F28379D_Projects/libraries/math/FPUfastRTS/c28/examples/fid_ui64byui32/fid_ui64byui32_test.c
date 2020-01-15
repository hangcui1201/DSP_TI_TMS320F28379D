//#############################################################################
//
//! \file   fid_ui64byui32_test.c
//!
//! \brief  Runs the FID_ui64byui32 routine
//! \author Vishal Coelho
//! \date   Apr 07, 2016
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
#include "fpu64/fid.h"
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
uint32_t tolerance = 0;

uint64_t test_output_quo[TEST_SIZE], test_error_quo[TEST_SIZE];
uint32_t test_output_rem[TEST_SIZE], test_error_rem[TEST_SIZE];
reg64_t num_rem;
reg64_t den_quo;
//*****************************************************************************
// the function definitions
//*****************************************************************************
void FastRTS_runTest(void)
{
    // Locals
    uint16_t i;

    for(i = 0U; i < TEST_SIZE; i++)
    {
        den_quo.ui64   = 0;
    	num_rem.ui64   = test_dividend[i];
    	den_quo.L.ui32 = test_divisor[i];

    	FID_ui64byui32(&num_rem.ui64, &den_quo.ui64);

    	test_output_quo[i]   = den_quo.ui64;
    	test_output_rem[i]   = num_rem.L.ui32;

    	if(FID_Example_calcError((uint64_t *)&den_quo.ui64,
    	                (uint64_t *)&test_quotient[i],
						(uint64_t *)&test_error_quo[i],
    	                &tolerance,
						ERRORTYPE_UI64) != -1)
        {
    		pass++;
        }
        else
        {
            fail++;
        }

        if(FID_Example_calcError((uint32_t *)&num_rem.L.ui32,
            	                (uint32_t *)&test_remainder[i],
        						(uint32_t *)&test_error_rem[i],
            	                &tolerance,
        						ERRORTYPE_UI32) != -1)
        {
    		pass++;
        }
        else
        {
            fail++;
        }
    }
}

// End of File
