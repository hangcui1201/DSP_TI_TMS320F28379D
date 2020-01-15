//#############################################################################
//
//! \file   dsp_fastsqrt.c
//!
//! \brief  Demonstrates the Fast Square Root 
//! \author Vishal Coelho
//! \date   Sep 16, 2016
//
//  Group:          C2000
//  Target Device:  TMS320f2838x
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
#include "fpu32/fpu_math.h"

//*****************************************************************************
// the globals
//*****************************************************************************
// The global pass, fail values
uint16_t pass = 0U, fail = 0U;
// The absolute error between the result and expected values
float tolerance = 1.0e-10;
//*****************************************************************************
// the function definitions
//*****************************************************************************
void DSP_runTest(void)
{
    // Locals
    float fInput1, fInput2;
    float fOutput1, fOutput2, fOutput3;

    // Create some test data
    fInput1 = 16777216.0;
    fInput2 = 5184.0;
    
    // Back to Back calls of __ffsqrtf()
    // Expected result: 4096 and 72
    // Declaring the inputs and outputs to the ffsqrt() locally allows the
    // compiler to optimize back-to-back calls to ffsqrt() (when optimization
    // is set to o2) as follows:
    //    MOVIZ     R1H,#19328            ; [CPU_] |96| 
    //    MOVIZ     R0H,#17826            ; [CPU_] |96| 
    //    EISQRTF32 R1H,R1H               ; [CPU_] |96| 
    //    EISQRTF32 R0H,R0H               ; [CPU_] |96| 
    //    MPYF32    R3H,R1H,R1H           ; [CPU_] |96| 
    //    MPYF32    R2H,R0H,R0H           ; [CPU_] |96| 
    //    MPYF32    R3H,R3H,#19200        ; [CPU_] |96| 
    //    MPYF32    R2H,R2H,#17698        ; [CPU_] |96| 
    //    SUBF32    R3H,#16320,R3H        ; [CPU_] |96| 
    //    SUBF32    R2H,#16320,R2H        ; [CPU_] |96| 
    //    MPYF32    R1H,R1H,R3H           ; [CPU_] |96| 
    //    MPYF32    R0H,R0H,R2H           ; [CPU_] |96| 
    //    MPYF32    R2H,R1H,#19200        ; [CPU_] |96| 
    //    MPYF32    R3H,R0H,#17698        ; [CPU_] |96| 
    //    MPYF32    R2H,R1H,R2H           ; [CPU_] |96| 
    //    MPYF32    R3H,R0H,R3H           ; [CPU_] |96| 
    //    SUBF32    R2H,#16320,R2H        ; [CPU_] |96| 
    //    SUBF32    R3H,#16320,R3H        ; [CPU_] |96| 
    //    MPYF32    R1H,R1H,R2H           ; [CPU_] |96| 
    //    MPYF32    R0H,R0H,R3H           ; [CPU_] |96| 
    //    MPYF32    R1H,R1H,#19328        ; [CPU_] |96| 
    //    MPYF32    R0H,R0H,#17826        ; [CPU_] |96| 
    // The compiler will interleave the instructions of the 
    // back-to-back calls, completing both operations in 22 cycles. The 
    // variables will be optimized out and the FPU registers will be used 
    // instead. The user can check this in the disassembly view, or as in the
    // case of this example, the assembly file generated for main.c
    //
    // The __asm(" NOP") intrinsics around the back-to-back calls serve as 
    // boundaries for compiler optimization
    //
    __asm(" NOP");
    fOutput1 = __ffsqrtf(fInput1);
    fOutput2 = __ffsqrtf(fInput2);
    __asm(" NOP");
    
    fOutput3 = fOutput1 + fOutput2;
    
    if(fabsf(fOutput1 - 4096.0) <= tolerance)
    {
        pass++;
    }
    else
    {
        fail++;
    }
    if(fabsf(fOutput2 - 72.0) <= tolerance)
    {
        pass++;
    }
    else
    {
        fail++;
    }
    if(fabsf(fOutput3 - 4168.0) <= tolerance)
    {
        pass++;
    }
    else
    {
        fail++;
    }
}

// End of File
