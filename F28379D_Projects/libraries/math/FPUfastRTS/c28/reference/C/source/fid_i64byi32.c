//#############################################################################
//! \file   reference/C/source/$FILENAME$
//! \brief  Division: signed long (64-bit) / signed int (32-bit)
//! \author Vishal Coelho (adapted from original by Prasanth V.)
//! \date   11-Apr-2016
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
#include "fid.h"
#include "fastrts_assert.h"
//*****************************************************************************
// defines
//*****************************************************************************
FASTRTS_FILENUM(13)

//*****************************************************************************
// FID_i64byi32_t
//*****************************************************************************
void FID_i64byi32_t(const int64_t num, const int32_t den, 
                       int64_t *p_quo, int32_t *p_rem)
{
    int16_t i;
    static int16_t iter = 1;

    // R3H = denominator
    R3.H.i32 = den;
    // R1 = numerator
    R1.i64 = num;
    
    // Take the absolute value of the numerator and denominator 
    // flag.TF = sign(num) ^ sign(den)
    // flag.NI = sign(num)
    // Zero out R2.H
    ABSI64DIV32(&R3.H, &R1, &R2.H, &status_flag);
    
    
    // run the restoring division on the upper dword
    for(i = 0; i < 8; i++)
    {
        SUBC4UI32 (&R3.H, &R1.H, &R2.H, &status_flag);
    }
    // swap the upper and lower dwords of the numerator
    SWAPI64(&R1);
    // run the restoring division on the upper dword
    for(i = 0; i < 8; i++)
    {
        SUBC4UI32 (&R3.H, &R1.H, &R2.H, &status_flag);
    }
    // restore the numerator
    SWAPI64(&R1);
    
    // if flag.TF == 1, quotient = -quotient
    // if flag.NI == 1, remainder = -remainder
    NEGI64DIV32(&R1, &R2.H, &status_flag);
    
    *p_rem = (R2.H.i32);
    *p_quo = (R1.i64);
    
#ifdef _DEBUG
    printf("#%4u: %11ld / %11d -> Q = %11ld, R = %11d\n", 
            iter, num, den, *p_quo, *p_rem);
#endif //_DEBUG

    iter++;
}

//*****************************************************************************
// FID_i64byi32_m
//*****************************************************************************
void FID_i64byi32_m(const int64_t num, const int32_t den, 
                       int64_t *p_quo, int32_t *p_rem)
{
    int16_t i;
    static int16_t iter = 1;

    // R3H = denominator
    R3.H.i32 = den;
    // R1 = numerator
    R1.i64 = num;
    
    // Take the absolute value of the numerator and denominator 
    // flag.TF = sign(num) ^ sign(den)
    // flag.NI = sign(num)
    // Zero out R2.H
    ABSI64DIV32(&R3.H, &R1, &R2.H, &status_flag);
    
    
    // run the restoring division on the upper dword
    for(i = 0; i < 8; i++)
    {
        SUBC4UI32 (&R3.H, &R1.H, &R2.H, &status_flag);
    }
    // swap the upper and lower dwords of the numerator
    SWAPI64(&R1);
    // run the restoring division on the upper dword
    for(i = 0; i < 8; i++)
    {
        SUBC4UI32 (&R3.H, &R1.H, &R2.H, &status_flag);
    }
    // restore the numerator
    SWAPI64(&R1);
    
    
    // if flag.TF == 1 and flag.ZI == 0, quotient += 1, 
    //                                   remainder = divisor - remainder
    // if flag.TF == 1, quotient = -quotient
    // if flag.NI ^ flag.TF == 1, remainder = -remainder
    MNEGI64DIV32(&R3.H, &R1, &R2.H, &status_flag);
    
    *p_rem = (R2.H.i32);
    *p_quo = (R1.i64);
    
#ifdef _DEBUG
    printf("#%4u: %11ld / %11d -> Q = %11ld, R = %11d\n", 
            iter, num, den, *p_quo, *p_rem);
#endif //_DEBUG

    iter++;
}


//*****************************************************************************
// FID_i64byi32_e
//*****************************************************************************
void FID_i64byi32_e(const int64_t num, const int32_t den, 
                       int64_t *p_quo, int32_t *p_rem)
{
    int16_t i;
    static int16_t iter = 1;

    // R3H = denominator
    R3.H.i32 = den;
    // R1 = numerator
    R1.i64 = num;
    
    // Take the absolute value of the numerator and denominator 
    // flag.TF = sign(num) ^ sign(den)
    // flag.NI = sign(num)
    // Zero out R2.H
    ABSI64DIV32(&R3.H, &R1, &R2.H, &status_flag);
    
    
    // run the restoring division on the upper dword
    for(i = 0; i < 8; i++)
    {
        SUBC4UI32 (&R3.H, &R1.H, &R2.H, &status_flag);
    }
    // swap the upper and lower dwords of the numerator
    SWAPI64(&R1);
    // run the restoring division on the upper dword
    for(i = 0; i < 8; i++)
    {
        SUBC4UI32 (&R3.H, &R1.H, &R2.H, &status_flag);
    }
    // restore the numerator
    SWAPI64(&R1);
    
    // if flag.NI == 1 and flag.ZI == 0, quotient += 1, 
    //                                   remainder = divisor - remainder
    // if flag.TF == 1, quotient = -quotient
    ENEGI64DIV32(&R3.H, &R1, &R2.H, &status_flag);
    
    *p_rem = (R2.H.i32);
    *p_quo = (R1.i64);
    
#ifdef _DEBUG
    printf("#%4u: %11ld / %11d -> Q = %11ld, R = %11d\n", 
            iter, num, den, *p_quo, *p_rem);
#endif //_DEBUG

    iter++;
}

// End of File
