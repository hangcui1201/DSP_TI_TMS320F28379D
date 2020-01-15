//###########################################################################
//
// FILE:   cpu.h
//
// TITLE:  Instruction wrappers for special CPU instructions needed by the
//         drivers.
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

//*****************************************************************************
//
//! \addtogroup cpu_api
//! @{
//
//*****************************************************************************
#include <stdint.h>

//
// Define for no operation
//
#ifndef NOP
#define NOP    __asm(" NOP")
#endif

//*****************************************************************************
//
//! Returns the state of FAULTMASK register on entry and disable all
//! interrupts except NMI.
//!
//! \param None
//!
//! This function is wrapper function for the CPSID instruction. It returns
//! the state of FAULTMASK on entry and disable all interrupts except NMI.
//!
//! \return Returns the state of FAULTMASK register.
//
//*****************************************************************************
static inline uint32_t
CPU_setFAULTMASK(void)
{
    //
    // Disable interrupts and return previous FAULTMASK.
    //
    return(_disable_interrupts());
}

//*****************************************************************************
//
//! Returns the state of FAULTMASK register
//!
//! \param None
//!
//! This function is wrapper function for returning the state of FAULTMASK
//! register(indicating whether interrupts except NMI are enabled or disabled).
//!
//! \return Returns the state of FAULTMASK register.
//
//*****************************************************************************
static inline uint32_t
CPU_getFAULTMASK(void)
{
    //
    // Read FAULTMASK register.
    //
    __asm("    mrs     r0, FAULTMASK\n"
          "    bx      lr\n");

    //
    // The following keeps the compiler happy, because it wants to see a
    // return value from this function.  It will generate code to return
    // a zero.  However, the real return is the "bx lr" above, so the
    // return(0) is never executed and the function returns with the value
    // you expect in R0.
    //
    return(0U);
}

//*****************************************************************************
//
//! Returns the state of FAULTMASK register and enable the interrupts
//!
//! \param None
//!
//! This function is wrapper function for returning the state of FAULTMASK
//! register and enabling the interrupts.
//!
//! \return Returns the state of FAULTMASK register.
//
//*****************************************************************************
static inline uint32_t
CPU_clearFAULTMASK(void)
{
    //
    // Enable interrupts and return previous FAULTMASK status.
    //
    return(_enable_interrupts());
}

//*****************************************************************************
//
//! Returns the state of PRIMASK register on entry and disable interrupts
//!
//! \param None
//!
//! This function is wrapper function for the CPSID instruction. It returns
//! the state of PRIMASK on entry and disable interrupts.
//!
//! \return Returns the state of PRIMASK register.
//
//*****************************************************************************
static inline uint32_t
CPU_setPRIMASK(void)
{
    //
    // Read PRIMASK and Disable interrupts.
    //
    return(_disable_IRQ());
}

//*****************************************************************************
//
//! Returns the state of PRIMASK register
//!
//! \param None
//!
//! This function is wrapper function for returning the state of PRIMASK
//! register(indicating whether interrupts are enabled or disabled).
//!
//! \return Returns the state of PRIMASK register.
//
//*****************************************************************************
static inline uint32_t
CPU_getPRIMASK(void)
{
    //
    // Return PRIMASK register status.
    //
    return(__get_PRIMASK());
}

//*****************************************************************************
//
//! Returns the state of PRIMASK register and enable the interrupts
//!
//! \param None
//!
//! This function is wrapper function for returning the state of PRIMASK
//! register and enabling the interrupts.
//!
//! \return Returns the state of PRIMASK register.
//
//*****************************************************************************
static inline uint32_t
CPU_clearPRIMASK(void)
{
    //
    // Enable interrupts and return previous PRIMASK setting.
    //
    return(_enable_IRQ());
}

//*****************************************************************************
//
//! Wrapper function for the WFI instruction
//!
//! \param None
//!
//! This function is wrapper function for the WFI instruction.
//!
//! \return None
//
//*****************************************************************************
static inline void
CPU_wfi(void)
{
    //
    // Wait for the next interrupt.
    //
    __asm("    wfi\n");
}

//*****************************************************************************
//
//! Writes the BASEPRI register
//!
//! \param None
//!
//! This function is wrapper function for writing the BASEPRI register. MSB
//! 3-bits are enabled for setting the priority and non-implemented low-order
//! bits read as zero and ignore writes. To set the base priority of 0x2U,
//! the param \e basePriority to be passed should be 0x20U.
//!
//! \return None.
//
//*****************************************************************************
static inline void
CPU_setBASEPRI(uint32_t basePriority)
{
    //
    // Set the BASEPRI register
    //
    _set_interrupt_priority(basePriority);
}

//*****************************************************************************
//
//! Returns the state of BASEPRI register
//!
//! \param None
//!
//! This function is wrapper function for reading the BASEPRI register.
//!
//! \return Returns the state of BASEPRI register
//
//*****************************************************************************
static inline uint32_t
CPU_getBASEPRI(void)
{
    //
    // Read BASEPRI register.
    //
    __asm("    mrs     r0, BASEPRI\n"
          "    bx      lr\n");

    //
    // The following keeps the compiler happy, because it wants to see a
    // return value from this function.  It will generate code to return
    // a zero.  However, the real return is the "bx lr" above, so the
    // return(0) is never executed and the function returns with the value
    // you expect in R0.
    //
    return(0U);
}

//*****************************************************************************
//
// Extern compiler intrinsic prototypes. See compiler User's Guide for details.
//
//*****************************************************************************
extern uint32_t __get_PRIMASK(void);
extern uint32_t _disable_interrupts(void);
extern uint32_t _enable_interrupts();
extern uint32_t _disable_IRQ();
extern uint32_t _enable_IRQ();
extern uint32_t _set_interrupt_priority(uint32_t priority);

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

#endif // CPU_H
