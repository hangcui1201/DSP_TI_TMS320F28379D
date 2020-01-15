//###########################################################################
//
// FILE:   syctick.h
//
// TITLE:  Driver for the Systick module.
//
//###########################################################################
// $TI Release:  $
// $Release Date:  $
// $Copyright: $
//###########################################################################

#ifndef SYSTICK_H
#define SYSTICK_H

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

//*****************************************************************************
//
//! \addtogroup systick_api
//! @{
//
//*****************************************************************************
#include <stdbool.h>
#include <stdint.h>
#include "debug.h"
#include "interrupt.h"
#include "inc_cm/hw_ints.h"
#include "inc_cm/hw_memmap.h"
#include "inc_cm/hw_nvic.h"
#include "inc_cm/hw_types.h"

//*****************************************************************************
//
//! Values that can be passed to SYSTICK_setClockSource() as the
//! \e clkSrc parameter.
//
//*****************************************************************************
typedef enum
{
    SYSTICK_CLOCK_SOURCE_EXTERNAL  = 0x0U, //!< External clock is used
    SYSTICK_CLOCK_SOURCE_INTERNAL  = 0x4U, //!< Internal clock is used
} SYSTICK_ClockSource;

//*****************************************************************************
//
//! Sets the clokc source for SysTick counter.
//!
//! \param clkSrc specifies the clock source type.
//!
//! This function sets the clokc source for SysTick counter. The Systick clock
//! can be set as either internal clock or external. The param clkSrc can
//! take following values:SYSTICK_CLOCK_SOURCE_EXTERNAL and
//! SYSTICK_CLOCK_SOURCE_INTERNAL.
//!
//! \return None.
//
//*****************************************************************************
static inline void
SYSTICK_setClockSource(SYSTICK_ClockSource clkSrc)
{
    //
    // Sets SysTick clock source.
    //
    HWREG(NVIC_BASE + NVIC_O_SYST_CSR) = (HWREG(NVIC_BASE + NVIC_O_SYST_CSR) &
                                          ~NVIC_SYST_CSR_CLKSOURCE) |
                                         (uint32_t)clkSrc;
}

//*****************************************************************************
//
//! Enables the SysTick counter.
//!
//! \param None
//!
//! This function starts the SysTick counter.  If an interrupt handler has been
//! registered, it is called when the SysTick counter rolls over.
//!
//! \note Calling this function causes the SysTick counter to (re)commence
//! counting from its current value.  The counter is not automatically reloaded
//! with the period as specified in a previous call to SysTick_setPeriod(). If
//! an immediate reload is required, the \b NVIC_O_SYST_CVR register must be
//! written to force the reload.  Any write to this register clears the SysTick
//! counter to 0 and causes a reload with the supplied period on the next
//! clock.
//!
//! \return None.
//
//*****************************************************************************
static inline void
SYSTICK_enableCounter(void)
{
    //
    // Enable SysTick Counter.
    //
    HWREG(NVIC_BASE + NVIC_O_SYST_CSR) |= NVIC_SYST_CSR_ENABLE;
}

//*****************************************************************************
//
//! Disables the SysTick counter.
//!
//! \param None
//!
//! This function stops the SysTick counter.  If an interrupt handler has been
//! registered, it is not called until SysTick is restarted.
//!
//! \return None.
//
//*****************************************************************************
static inline void
SYSTICK_disableCounter(void)
{
    //
    // Disable SysTick Counter.
    //
     HWREG(NVIC_BASE + NVIC_O_SYST_CSR) &= ~NVIC_SYST_CSR_ENABLE;
}

//*****************************************************************************
//
//! Sets the period of the SysTick counter.
//!
//! \param period is the number of clock ticks in each period of the
//! SysTick counter and must be between 1 and 16,777,216, inclusive.
//!
//! This function sets the rate at which the SysTick counter wraps, which
//! equates to the number of processor clocks between interrupts.
//!
//! \note Calling this function does not cause the SysTick counter to reload
//! immediately.  If an immediate reload is required, the \b NVIC_O_SYST_CVR
//! register must be written.  Any write to this register clears the SysTick
//! counter to 0 and causes a reload with the \e period supplied here on
//! the next clock after SysTick is enabled.
//!
//! \return None.
//
//*****************************************************************************
static inline void
SYSTICK_setPeriod(uint32_t period)
{
    //
    // Check the arguments.
    //
    ASSERT((period > 0) && (period <= 0x1000000U));

    //
    // Set the period of the SysTick counter.
    //
    HWREG(NVIC_BASE + NVIC_O_SYST_RVR) = period - 1;
}

//*****************************************************************************
//
//! Gets the period of the SysTick counter.
//!
//! \param None
//!
//! This function returns the rate at which the SysTick counter wraps, which
//! equates to the number of processor clocks between interrupts.
//!
//! \return Returns the period of the SysTick counter.
//
//*****************************************************************************
static inline uint32_t
SYSTICK_getPeriod(void)
{
    //
    // Return the period of the SysTick counter.
    //
    return(HWREG(NVIC_BASE + NVIC_O_SYST_RVR) + 1U);
}

//*****************************************************************************
//
//! Gets the current value of the SysTick counter.
//!
//! \param None
//!
//! This function returns the current value of the SysTick counter, which is
//! a value between the period - 1 and zero, inclusive.
//!
//! \return Returns the current value of the SysTick counter.
//
//*****************************************************************************
static inline uint32_t
SYSTICK_getCurrentValue(void)
{
    //
    // Return the current value of the SysTick counter.
    //
    return(HWREG(NVIC_BASE + NVIC_O_SYST_CVR));
}

//*****************************************************************************
//
//! Enables the SysTick interrupt.
//!
//! \param None
//!
//! This function enables the SysTick interrupt, allowing it to be
//! reflected to the processor.
//!
//! \note The SysTick interrupt handler is not required to clear the SysTick
//! interrupt source because it is cleared automatically by the NVIC when the
//! interrupt handler is called.
//!
//! \return None.
//
//*****************************************************************************
static inline void
SYSTICK_enableInterrupt(void)
{
    //
    // Enable the SysTick interrupt.
    //
    Interrupt_enable(FAULT_SYSTICK);
}

//*****************************************************************************
//
//! Disables the SysTick interrupt.
//!
//! \param None
//!
//! This function disables the SysTick interrupt, preventing it from being
//! reflected to the processor.
//!
//! \return None.
//
//*****************************************************************************
static inline void
SYSTICK_disableInterrupt(void)
{
    //
    // Disable the SysTick interrupt.
    //
    Interrupt_disable(FAULT_SYSTICK);
}

//*****************************************************************************
//
//! Registers an interrupt handler for the SysTick interrupt.
//!
//! \param fnHandler is a pointer to the function to be called when the
//! SysTick interrupt occurs.
//!
//! This function registers the handler to be called when a SysTick interrupt
//! occurs.
//!
//! \sa Interrupt_registerHandler() for important information about registering
//! interrupt handlers.
//!
//! \return None.
//
//*****************************************************************************
static inline void
SYSTICK_registerInterruptHandler(void (*fnHandler)(void))
{
    //
    // Register the interrupt handler, returning an error if an error occurs.
    //
    Interrupt_registerHandler(FAULT_SYSTICK, fnHandler);

    //
    // Enable the SysTick interrupt.
    //
    Interrupt_enable(FAULT_SYSTICK);
}

//*****************************************************************************
//
//! Unregisters the interrupt handler for the SysTick interrupt.
//!
//! \param None
//!
//! This function unregisters the handler to be called when a SysTick interrupt
//! occurs.
//!
//! \sa Interrupt_registerHandler() for important information about registering
//! interrupt handlers.
//!
//! \return None.
//
//*****************************************************************************
static inline void
SYSTICK_unregisterInterruptHandler(void)
{
    //
    // Disable the SysTick interrupt.
    //
    Interrupt_disable(FAULT_SYSTICK);

    //
    // Unregister the interrupt handler.
    //
    Interrupt_unregisterHandler(FAULT_SYSTICK);
}

//*****************************************************************************
//
// Close the Doxygen group.
//! @}
//
//*****************************************************************************

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif // SYSTICK_H
