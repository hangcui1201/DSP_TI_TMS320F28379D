//###########################################################################
//
// FILE:   gpio.c
//
// TITLE:  C28x GPIO driver.
//
//###########################################################################
// $TI Release:  $
// $Release Date:  $
// $Copyright:  $
//###########################################################################

#include "gpio.h"

//*****************************************************************************
//
// GPIO_setDirectionMode
//
//*****************************************************************************
void
GPIO_setDirectionMode(uint32_t pin, GPIO_Direction pinIO)
{
    volatile uint32_t *gpioBaseAddr;
    uint32_t pinMask;

    //
    // Check the arguments.
    //
    ASSERT(GPIO_isPinValid(pin));

    gpioBaseAddr = (uint32_t *)GPIOCTRL_BASE +
                   ((pin / 32U) * GPIO_CTRL_REGS_STEP);
    pinMask = (uint32_t)1U << (pin % 32U);

    EALLOW;

    //
    // Set the data direction
    //
    if(pinIO == GPIO_DIR_MODE_OUT)
    {
        // Output
        gpioBaseAddr[GPIO_GPxDIR_INDEX] |= pinMask;
    }
    else
    {
        // Input
        gpioBaseAddr[GPIO_GPxDIR_INDEX] &= ~pinMask;
    }

    EDIS;
}

//*****************************************************************************
//
// GPIO_getDirectionMode
//
//*****************************************************************************
GPIO_Direction
GPIO_getDirectionMode(uint32_t pin)
{
    volatile uint32_t *gpioBaseAddr;

    //
    // Check the arguments.
    //
    ASSERT(GPIO_isPinValid(pin));

    gpioBaseAddr = (uint32_t *)GPIOCTRL_BASE +
                   ((pin / 32U) * GPIO_CTRL_REGS_STEP);

    return((GPIO_Direction)((gpioBaseAddr[GPIO_GPxDIR_INDEX] >>
                             (pin % 32U)) & 1U));

}

//*****************************************************************************
//
// GPIO_setInterruptPin
//
//*****************************************************************************
void
GPIO_setInterruptPin(uint32_t pin, GPIO_ExternalIntNum extIntNum)
{
    XBAR_InputNum input;

    //
    // Check the arguments.
    //
    ASSERT(GPIO_isPinValid(pin));

    //
    // Pick the X-BAR input that corresponds to the requested XINT.
    //
    switch(extIntNum)
    {
        case GPIO_INT_XINT1:
            input = XBAR_INPUT4;
            break;

        case GPIO_INT_XINT2:
            input = XBAR_INPUT5;
            break;

        case GPIO_INT_XINT3:
            input = XBAR_INPUT6;
            break;

        case GPIO_INT_XINT4:
            input = XBAR_INPUT13;
            break;

        case GPIO_INT_XINT5:
            input = XBAR_INPUT14;
            break;

        default:
            // Invalid interrupt. Shouldn't happen if enum value is used.
            // XBAR_INPUT1 isn't tied to an XINT, so we'll use it to check for
            // a bad value.
            input = XBAR_INPUT1;
            break;
    }

    if(input != XBAR_INPUT1)
    {
        XBAR_setInputPin(XBAR_INPUT_BASE, input, (uint16_t)pin);
    }
}

//*****************************************************************************
//
// GPIO_setPadConfig
//
//*****************************************************************************
void
GPIO_setPadConfig(uint32_t pin, uint32_t pinType)
{
    volatile uint32_t *gpioBaseAddr;
    uint32_t pinMask;

    //
    // Check the arguments.
    //
    ASSERT(GPIO_isPinValid(pin));

    gpioBaseAddr = (uint32_t *)GPIOCTRL_BASE +
                   ((pin / 32U) * GPIO_CTRL_REGS_STEP);
    pinMask = (uint32_t)1U << (pin % 32U);

    EALLOW;

    // Enable open drain if necessary
    if((pinType & GPIO_PIN_TYPE_OD) != 0U)
    {
        gpioBaseAddr[GPIO_GPxODR_INDEX] |= pinMask;
    }
    else
    {
        gpioBaseAddr[GPIO_GPxODR_INDEX] &= ~pinMask;
    }

    // Enable pull-up if necessary
    if((pinType & GPIO_PIN_TYPE_PULLUP) != 0U)
    {
        gpioBaseAddr[GPIO_GPxPUD_INDEX] &= ~pinMask;
    }
    else
    {
        gpioBaseAddr[GPIO_GPxPUD_INDEX] |= pinMask;
    }

    // Invert polarity if necessary
    if((pinType & GPIO_PIN_TYPE_INVERT) != 0U)
    {
        gpioBaseAddr[GPIO_GPxINV_INDEX] |= pinMask;
    }
    else
    {
        gpioBaseAddr[GPIO_GPxINV_INDEX] &= ~pinMask;
    }

    EDIS;
}

//*****************************************************************************
//
// GPIO_getPadConfig
//
//*****************************************************************************
uint32_t
GPIO_getPadConfig(uint32_t pin)
{
    volatile uint32_t *gpioBaseAddr;
    uint32_t pinMask;
    uint32_t pinTypeRes;

    //
    // Check the arguments.
    //
    ASSERT(GPIO_isPinValid(pin));

    gpioBaseAddr = (uint32_t *)GPIOCTRL_BASE +
                   ((pin / 32U) * GPIO_CTRL_REGS_STEP);
    pinMask = (uint32_t)1U << (pin % 32U);

    pinTypeRes = GPIO_PIN_TYPE_STD;

    // Get open drain value
    if((gpioBaseAddr[GPIO_GPxODR_INDEX] & pinMask) != 0U)
    {
        pinTypeRes |= GPIO_PIN_TYPE_OD;
    }

    // Get pull-up value
    if((gpioBaseAddr[GPIO_GPxPUD_INDEX] & pinMask) == 0U)
    {
        pinTypeRes |= GPIO_PIN_TYPE_PULLUP;
    }

    // Get polarity value
    if((gpioBaseAddr[GPIO_GPxINV_INDEX] & pinMask) != 0U)
    {
        pinTypeRes |= GPIO_PIN_TYPE_INVERT;
    }

    return(pinTypeRes);
}

//*****************************************************************************
//
// GPIO_setQualificationMode
//
//*****************************************************************************
void
GPIO_setQualificationMode(uint32_t pin, GPIO_QualificationMode qualification)
{
    volatile uint32_t *gpioBaseAddr;
    uint32_t qSelIndex;
    uint32_t shiftAmt;

    //
    // Check the arguments.
    //
    ASSERT(GPIO_isPinValid(pin));

    gpioBaseAddr = (uint32_t *)GPIOCTRL_BASE +
                   ((pin / 32U) * GPIO_CTRL_REGS_STEP);
    shiftAmt = (uint32_t)GPIO_GPAQSEL1_GPIO1_S * (pin % 16U);
    qSelIndex = GPIO_GPxQSEL_INDEX + ((pin % 32U) / 16U);

    //
    // Write the input qualification mode to the register.
    //
    EALLOW;

    gpioBaseAddr[qSelIndex] &= ~((uint32_t)GPIO_GPAQSEL1_GPIO0_M << shiftAmt);
    gpioBaseAddr[qSelIndex] |= (uint32_t)qualification << shiftAmt;

    EDIS;
}

//*****************************************************************************
//
// GPIO_getQualificationMode
//
//*****************************************************************************
GPIO_QualificationMode
GPIO_getQualificationMode(uint32_t pin)
{
    volatile uint32_t *gpioBaseAddr;
    uint32_t qSelIndex;
    uint32_t qualRes;
    uint32_t shiftAmt;

    //
    // Check the arguments.
    //
    ASSERT(GPIO_isPinValid(pin));

    gpioBaseAddr = (uint32_t *)GPIOCTRL_BASE +
                   ((pin / 32U) * GPIO_CTRL_REGS_STEP);
    shiftAmt = (uint32_t)GPIO_GPAQSEL1_GPIO1_S * (pin % 16U);
    qSelIndex = GPIO_GPxQSEL_INDEX + ((pin % 32U) / 16U);

    //
    // Read the qualification mode register and shift and mask to get the
    // value for the specified pin.
    //
    qualRes = (gpioBaseAddr[qSelIndex] >> shiftAmt) &
              (uint32_t)GPIO_GPAQSEL1_GPIO0_M;
    return((GPIO_QualificationMode)qualRes);
}

//*****************************************************************************
//
// GPIO_setQualificationPeriod
//
//*****************************************************************************
void
GPIO_setQualificationPeriod(uint32_t pin, uint32_t divider)
{
    volatile uint32_t *gpioBaseAddr;
    uint32_t pinMask, regVal, shiftAmt;

    //
    // Check the arguments.
    //
    ASSERT(GPIO_isPinValid(pin));
    ASSERT((divider >= 1U) && (divider <= 510U));

    shiftAmt = (pin % 32U) & ~((uint32_t)0x7U);
    pinMask = (uint32_t)0xFFU << shiftAmt;

    //
    // Divide divider by two to get the value that needs to go into the field.
    // Then shift it into the right place.
    //
    regVal = (divider / 2U) << shiftAmt;

    //
    // Write the divider parameter into the register.
    //
    gpioBaseAddr = (uint32_t *)GPIOCTRL_BASE +
                   ((pin / 32U) * GPIO_CTRL_REGS_STEP);

    EALLOW;
    gpioBaseAddr[GPIO_GPxCTRL_INDEX] &= ~pinMask;
    gpioBaseAddr[GPIO_GPxCTRL_INDEX] |= regVal;
    EDIS;
}

//*****************************************************************************
//
// GPIO_setMasterCore
//
//*****************************************************************************
void
GPIO_setMasterCore(uint32_t pin, GPIO_CoreSelect core)
{
    volatile uint32_t *gpioBaseAddr;
    uint32_t cSelIndex;
    uint32_t shiftAmt;

    //
    // Check the arguments.
    //
    ASSERT(GPIO_isPinValid(pin));

    gpioBaseAddr = (uint32_t *)GPIOCTRL_BASE +
                   ((pin / 32U) * GPIO_CTRL_REGS_STEP);
    shiftAmt = (uint32_t)GPIO_GPACSEL1_GPIO1_S * (pin % 8U);
    cSelIndex = GPIO_GPxCSEL_INDEX + ((pin % 32U) / 8U);

    //
    // Write the core parameter into the register.
    //
    EALLOW;
    gpioBaseAddr[cSelIndex] &= ~((uint32_t)GPIO_GPACSEL1_GPIO0_M << shiftAmt);
    gpioBaseAddr[cSelIndex] |= (uint32_t)core << shiftAmt;
    EDIS;
}

//*****************************************************************************
//
// GPIO_setAnalogMode
//
//*****************************************************************************
void
GPIO_setAnalogMode(uint32_t pin, GPIO_AnalogMode mode)
{
    volatile uint32_t *gpioBaseAddr;
    uint32_t pinMask;

    //
    // Check the arguments.
    //

    pinMask = (uint32_t)1U << (pin % 32U);
    gpioBaseAddr = (uint32_t *)GPIOCTRL_BASE +
                   ((pin / 32U) * GPIO_CTRL_REGS_STEP);

    EALLOW;

    //
    // Set the analog mode selection.
    //
    if(mode == GPIO_ANALOG_ENABLED)
    {
        // Enable analog mode
        gpioBaseAddr[GPIO_GPxAMSEL_INDEX] |= pinMask;
    }
    else
    {
        // Disable analog mode
        gpioBaseAddr[GPIO_GPxAMSEL_INDEX] &= ~pinMask;
    }

    EDIS;
}

//*****************************************************************************
//
// GPIO_registerInterrupt
//
//*****************************************************************************
void
GPIO_registerInterrupt(GPIO_ExternalIntNum extIntNum, void (*handler)(void))
{
    uint32_t intNum;

    //
    // Clear the enable bit for the specified interrupt
    //
    switch(extIntNum)
    {
        case GPIO_INT_XINT1:
            intNum = INT_XINT1;
            break;

        case GPIO_INT_XINT2:
            intNum = INT_XINT2;
            break;

        case GPIO_INT_XINT3:
            intNum = INT_XINT3;
            break;

        case GPIO_INT_XINT4:
            intNum = INT_XINT4;
            break;

        case GPIO_INT_XINT5:
            intNum = INT_XINT5;
            break;

        default:
            // Invalid interrupt. Shouldn't happen if enum value is used.
            break;
    }

    //
    // Register the interrupt handler.
    //
    Interrupt_register(intNum, handler);

    //
    // Enable the GPIO interrupt.
    //
    Interrupt_enable(intNum);
}

//*****************************************************************************
//
// GPIO_unregisterInterrupt
//
//*****************************************************************************
void
GPIO_unregisterInterrupt(GPIO_ExternalIntNum extIntNum)
{
    uint32_t intNum;

    //
    // Clear the enable bit for the specified interrupt
    //
    switch(extIntNum)
    {
        case GPIO_INT_XINT1:
            intNum = INT_XINT1;
            break;

        case GPIO_INT_XINT2:
            intNum = INT_XINT2;
            break;

        case GPIO_INT_XINT3:
            intNum = INT_XINT3;
            break;

        case GPIO_INT_XINT4:
            intNum = INT_XINT4;
            break;

        case GPIO_INT_XINT5:
            intNum = INT_XINT5;
            break;

        default:
            // Invalid interrupt. Shouldn't happen if enum value is used.
            break;
    }
    //
    // Disable the GPIO interrupt.
    //
    Interrupt_disable(intNum);

    //
    // Unregister the interrupt handler.
    //
    Interrupt_unregister(intNum);
}

//*****************************************************************************
//
// GPIO_setPinConfig
//
//*****************************************************************************
void
GPIO_setPinConfig(uint32_t pinConfig)
{
    uint32_t muxRegAddr;
    uint32_t pinMask, shiftAmt;

    muxRegAddr = (uint32_t)GPIOCTRL_BASE + (pinConfig >> 16);
    shiftAmt = ((pinConfig >> 8) & (uint32_t)0xFFU);
    pinMask = (uint32_t)0x3U << shiftAmt;

    EALLOW;

    //
    // Clear fields in MUX register first to avoid glitches
    //
    HWREG(muxRegAddr) &= ~pinMask;

    //
    // Write value into GMUX register
    //
    HWREG(muxRegAddr + GPIO_MUX_TO_GMUX) =
        (HWREG(muxRegAddr + GPIO_MUX_TO_GMUX) & ~pinMask) |
        (((pinConfig >> 2) & (uint32_t)0x3U) << shiftAmt);

    //
    // Write value into MUX register
    //
    HWREG(muxRegAddr) |= ((pinConfig & (uint32_t)0x3U) << shiftAmt);
    EDIS;
}
