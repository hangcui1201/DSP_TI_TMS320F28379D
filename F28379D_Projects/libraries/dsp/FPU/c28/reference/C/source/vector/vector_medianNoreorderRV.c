//#############################################################################
//! \file   reference/C/source/$FILENAME$
//! \brief  Median of a Real Valued Array of Floats (Preserved Inputs)
//! \author David Alter
//! \date   28-Sep-2015 (original code written 08/28/12)
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
#include "vector.h"
#include <string.h>
#include <math.h>

//*****************************************************************************
// defines
//*****************************************************************************
DSP_FILENUM(9)
#define        K    256         // WARNING: K must be at least as large as N.

//*****************************************************************************
// VECTOR_medianNoreorderRV
// Median of a real valued array of floats. Input array is preserved.
// Notes:
// 1) This function simply makes a local copy of the input array, and then
//    calls VECTOR_medianRV() using the copy.
// 2) The length of the copy of the input array is allocated at compile time
//    by the constant 'K' defined in the code.  If the passed parameter N
//    is greater than K, memory corruption will result.  A better way to do
//    this is to dynamically allocate the copy array at run time using
//    malloc().  This is work for the future. 
//
//*****************************************************************************
fsize_t VECTOR_medianNoreorderRV(const fsize_t *x, uint16_t n)
{
    fsize_t x_copy[K], m;

    // Make a copy of the input array
    memcpy(x_copy, x, n*sizeof(fsize_t));     
    // Call VECTOR_medianRV()
    m = VECTOR_medianRV(x_copy, n);   
    return(m);
}

// End of File
