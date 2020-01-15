//###########################################################################
//
// FILE:   hw_types.h
//
// TITLE:  Type definitions used in driverlib functions.
//
//###########################################################################
// $TI Release:  $
// $Release Date:  $
// $Copyright:  $
//###########################################################################

#ifndef HW_TYPES_H
#define HW_TYPES_H

//*****************************************************************************
//
// Macros for hardware access
//
//*****************************************************************************
#define HWREG(x)                                                              \
        (*((volatile uint32_t *)(x)))
#define HWREG_BP(x)                                                           \
        __byte_peripheral_32((uint32_t *)(x))
#define HWREGH(x)                                                             \
        (*((volatile uint16_t *)(x)))
#define HWREGB(x)                                                             \
        __byte((int16_t *)(x),0)

//*****************************************************************************
//
// SUCCESS and FAILURE for API return value
//
//*****************************************************************************
#define STATUS_S_SUCCESS    (0)
#define STATUS_E_FAILURE    (-1)

//****************************************************************************
//
// For checking NULL pointers
//
//****************************************************************************
#define NULL ((void *)0x0)

//*****************************************************************************
//
// 32-bit float type
//
//*****************************************************************************
typedef float               float32_t;

//*****************************************************************************
//
// 64-bit float type
//
//*****************************************************************************
typedef long double         float64_t;

//*****************************************************************************
//
// Extern compiler intrinsic prototypes. See compiler User's Guide for details.
// These are provided to satisfy static analysis tools. The #ifndef is required
// because the '&' is for a C++-style reference, and although it is the correct
// prototype, it will not build in C code.
//
//*****************************************************************************
#if(defined(__TMS320C28XX__) || defined(__TMS320C28XX_CLA__))
#else
extern int16_t &__byte(int16_t *array, uint16_t byte_index);
extern uint32_t &__byte_peripheral_32(uint32_t *x);
#endif

#endif // HW_TYPES_H
