//#############################################################################
//! \file   reference/C/source/$FILENAME$
//! \brief  Finite Impulse Response Filter
//! \author Vishal Coelho 
//! \date   08-Oct-2015
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
#include "filter.h"
#include <math.h>

//*****************************************************************************
// defines
//*****************************************************************************
DSP_FILENUM(22)

//*****************************************************************************
// FILTER_runFIR()
//*****************************************************************************
void FILTER_runFIR(FIRHandle hnd)
{
    // Locals
    uint16_t i;
    fsize_t *c  = FIR_getCoefficientsPtr(hnd);
    fsize_t *d  = FIR_getDelayLinePtr(hnd);
    fsize_t  o  = (fsize_t)0.0;
    
    for(i = FIR_getnTaps(hnd) - 1U; i > 0U ; i--)
    {
        // Shift the delay line to the right
        d[i] = d[i-1U];
        // Multiply coefficients with the delay line and accumulate
        o = o + c[i] * d[i];
    }
	// Get the input into start of the delay line
    d[0] = FIR_getInput(hnd);
    // Do the final multiply-and-accumulate
    o = o + c[0]*d[0];
    // Write to the object
    FIR_setOutput(hnd, o);
#ifdef _DEBUG
    printf("output = %10.7f \n", FIR_getOutput(hnd));
#endif
}

// End of File
