//###########################################################################
//
// FILE:   cpu.h
//
// TITLE:  Useful C28x CPU defines.
//
//###########################################################################
// $TI Release:  $
// $Release Date:  $
// $Copyright:  $
//###########################################################################

#ifndef CPU_H
#define CPU_H

//*****************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
//*****************************************************************************
#ifdef __cplusplus
extern "C"
{
#endif

#include "stdint.h"

//
// External reference to the interrupt flag register (IFR) register
//
#ifndef __TMS320C28XX_CLA__
extern __cregister volatile uint16_t IFR;
#endif

//
// External reference to the interrupt enable register (IER) register
//
#ifndef __TMS320C28XX_CLA__
extern __cregister volatile uint16_t IER;
#endif

//
// Define to enable interrupts
//
#ifndef EINT
#define EINT   __asm(" clrc INTM")
#endif

//
// Define to disable interrupts
//
#ifndef DINT
#define DINT   __asm(" setc INTM")
#endif

//
// Define to enable debug events
//
#ifndef ERTM
#define ERTM   __asm(" clrc DBGM")
#endif

//
// Define to disable debug events
//
#ifndef DRTM
#define DRTM   __asm(" setc DBGM")
#endif

//
// Define to allow writes to protected registers
//
#ifndef EALLOW
#ifndef __TMS320C28XX_CLA__
#if __TI_COMPILER_VERSION__ >= 15004000
#define EALLOW __eallow()
#else
#define EALLOW __asm(" EALLOW")
#endif // __TI_COMPILER_VERSION__ >= 15004000
#else
#define EALLOW __meallow()
#endif // __TMS320C28XX_CLA__
#endif // EALLOW

//
// Define to disable writes to protected registers
//
#ifndef EDIS
#ifndef __TMS320C28XX_CLA__
#if __TI_COMPILER_VERSION__ >= 15004000
#define EDIS   __edis()
#else
#define EDIS   __asm(" EDIS")
#endif // __TI_COMPILER_VERSION__ >= 15004000
#else
#define EDIS   __medis()
#endif // __TMS320C28XX_CLA__
#endif // EDIS

//
// Define for emulation stop
//
#ifndef ESTOP0
#define ESTOP0 __asm(" ESTOP0")
#endif

//
// Define for emulation stop
//
#ifndef ESTOP1
#define ESTOP1 __asm(" ESTOP1")
#endif

//
// Define for no operation
//
#ifndef NOP
#define NOP    __asm(" NOP")
#endif

//
// Define for putting processor into a low-power mode
//
#ifndef IDLE
#define IDLE   __asm(" IDLE")
#endif

//*****************************************************************************
//
// Extern compiler intrinsic prototypes. See compiler User's Guide for details.
//
//*****************************************************************************
extern void __eallow(void);
extern void __edis(void);

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif // CPU_H
