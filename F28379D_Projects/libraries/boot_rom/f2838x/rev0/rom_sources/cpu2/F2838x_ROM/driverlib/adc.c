//###########################################################################
//
// FILE:   adc.c
//
// TITLE:  C28x ADC driver.
//
//###########################################################################
// $TI Release:  $
// $Release Date:  $
// $Copyright:  $
//###########################################################################

#include "adc.h"

//*****************************************************************************
//
// Defines for locations of ADC calibration functions in OTP for use in
// ADC_setMode() ONLY. Not intended for use by application code.
//
//*****************************************************************************
// The following functions calibrate the ADC linearity.  Use them in the
// ADC_setMode() function only
#define ADC_calADCAINL          0x0703B4U
#define ADC_calADCBINL          0x0703B2U
#define ADC_calADCCINL          0x0703B0U
#define ADC_calADCDINL          0x0703AEU

// This function looks up the ADC offset trim for a given condition. Use this
// in the ADC_setMode() function only.
#define ADC_getOffsetTrim       0x0703ACU

//*****************************************************************************
//
// A mapping of ADC base address to interrupt number. Not intended for use by
// application code.
//
//*****************************************************************************
static const uint32_t ADC_intMap[4][ADC_NUM_INTERRUPTS + 1U] =
{
    {ADCA_BASE, INT_ADCA1, INT_ADCA2, INT_ADCA3, INT_ADCA4},
    {ADCB_BASE, INT_ADCB1, INT_ADCB2, INT_ADCB3, INT_ADCB4},
    {ADCC_BASE, INT_ADCC1, INT_ADCC2, INT_ADCC3, INT_ADCC4},
    {ADCD_BASE, INT_ADCD1, INT_ADCD2, INT_ADCD3, INT_ADCD4}
};

//*****************************************************************************
//
//! \internal
//! Returns the analog-to-digital converter interrupt number.
//!
//! \param base is the base address of the ADC module.
//! \param adcIntNum is interrupt number within the ADC wrapper.
//!
//! This function returns the interrupt number for the ADC interrupt that
//! corresponds to the base address passed in \e base and the number passed in
//! \e adcIntNum.  \e adcIntNum can take the value \b ADC_INT_NUMBER1,
//! \b ADC_INT_NUMBER2, \b ADC_INT_NUMBER3, \b or ADC_INT_NUMBER4 to express
//! which of the four interrupts of the ADC module should be used.
//!
//! \return Returns an ADC interrupt number or 0 if the interrupt does not
//! exist.
//
//*****************************************************************************
static uint32_t
ADC_getIntNumber(uint32_t base, ADC_IntNumber adcIntNum)
{
    uint16_t index;
    uint16_t intMapRows = sizeof(ADC_intMap) / sizeof(ADC_intMap[0]);

    //
    // Loop through the table that maps ADC base addresses to interrupt
    // numbers.
    //
    for(index = 0U; index < intMapRows; index++)
    {
        //
        // See if this base address matches.
        //
        if(ADC_intMap[index][0U] == base)
        {
            //
            // Return the corresponding interrupt number.
            //
            return(ADC_intMap[index][(uint16_t)adcIntNum + 1U]);
        }
    }

    //
    // The base address could not be found, so return an error.
    //
    return(0U);
}

//*****************************************************************************
//
//! \internal
//! Returns the analog-to-digital converter event interrupt number.
//!
//! \param base base is the base address of the ADC module.
//!
//! This function returns the event interrupt number for the ADC with the base
//! address passed in the \e base parameter.
//!
//! \return Returns an ADC event interrupt number or 0 if the interrupt does not
//! exist.
//
//*****************************************************************************
static uint32_t
ADC_getPPBEventIntNumber(uint32_t base)
{
    uint32_t intNumber;

    //
    // Find the valid interrupt number for this ADC.
    //
    switch (base)
    {
        case ADCA_BASE:
            intNumber = INT_ADCA_EVT;
            break;

        case ADCB_BASE:
            intNumber = INT_ADCB_EVT;
            break;

        case ADCC_BASE:
            intNumber = INT_ADCC_EVT;
            break;

        case ADCD_BASE:
            intNumber = INT_ADCD_EVT;
            break;

        default:
            // Return an error.
            intNumber = 0U;
            break;
    }

    return(intNumber);
}

//*****************************************************************************
//
// ADC_setMode
//
//*****************************************************************************
void
ADC_setMode(uint32_t base, ADC_Resolution resolution,
            ADC_SignalMode signalMode)
{
//    uint16_t offsetIndex;
//    uint16_t offsetTrim;

    EALLOW;

//    switch(base)
//    {
//        case ADCA_BASE:
//            offsetIndex = 0U * 4U;
//            if(*(uint16_t *)ADC_calADCAINL != 0xFFFFU)
//            {
//                // Trim function is programmed into OTP, so call it
//                (*((void (*)(void))ADC_calADCAINL))();
//            }
//            else
//            {
//                // Do nothing, no INL trim function populated
//            }
//            break;
//        case ADCB_BASE:
//            offsetIndex = 1U * 4U;
//            if(*(uint16_t *)ADC_calADCBINL != 0xFFFFU)
//            {
//                // Trim function is programmed into OTP, so call it
//                (*((void (*)(void))ADC_calADCBINL))();
//            }
//            else
//            {
//                // Do nothing, no INL trim function populated
//            }
//            break;
//        case ADCC_BASE:
//            offsetIndex = 2U * 4U;
//            if(*(uint16_t *)ADC_calADCCINL != 0xFFFFU)
//            {
//                // Trim function is programmed into OTP, so call it
//                (*((void (*)(void))ADC_calADCCINL))();
//            }
//            else
//            {
//                // Do nothing, no INL trim function populated
//            }
//            break;
//        case ADCD_BASE:
//            offsetIndex = 3U * 4U;
//            if(*(uint16_t *)ADC_calADCDINL != 0xFFFFU)
//            {
//                // Trim function is programmed into OTP, so call it
//                (*((void (*)(void))ADC_calADCDINL))();
//            }
//            else
//            {
//                // Do nothing, no INL trim function populated
//            }
//            break;
//    }
//
//    // offset trim function is programmed into OTP, so call it
//    if(*(uint16_t *)ADC_getOffsetTrim != 0xFFFFU)
//    {
//        // Calculate the index into OTP table of offset trims and call
//        // function to return the correct offset trim
//        offsetIndex += ((signalMode == ADC_MODE_DIFFERENTIAL) ? 1U : 0U) +
//                       (2U * ((resolution == ADC_RESOLUTION_16BIT) ? 1U : 0U));
//
//        offsetTrim =
//            (*((uint16_t (*)(uint16_t index))ADC_getOffsetTrim))(offsetIndex);
//    }
//    else
//    {
//        // Offset trim function is not populated, so set offset trim to 0
//        offsetTrim = 0U;
//    }

    // Apply the resolution and signalMode to the specified ADC.
    HWREGH(base + ADC_O_CTL2) = (HWREGH(base + ADC_O_CTL2) &
                                 ~(ADC_CTL2_RESOLUTION | ADC_CTL2_SIGNALMODE))|
                                ((uint16_t)resolution | (uint16_t)signalMode);

//    // Also apply the offset trim and, if needed, linearity trim correction.
//    HWREGH(base + ADC_O_OFFTRIM) = offsetTrim;
//    if (resolution == ADC_RESOLUTION_12BIT)
//    {
//        // 12-bit linearity trim workaround
//        HWREG(base + ADC_O_INLTRIM1) &= 0xFFFF0000U;
//        HWREG(base + ADC_O_INLTRIM2) &= 0xFFFF0000U;
//        HWREG(base + ADC_O_INLTRIM4) &= 0xFFFF0000U;
//        HWREG(base + ADC_O_INLTRIM5) &= 0xFFFF0000U;
//    }

    EDIS;
}

//*****************************************************************************
//
// ADC_registerInterrupt
//
//*****************************************************************************
void
ADC_registerInterrupt(uint32_t base, ADC_IntNumber adcIntNum,
                      void (*handler)(void))
{
    uint32_t intNumber;

    //
    // Check the arguments.
    //
    ASSERT(ADC_isBaseValid(base));

    //
    // Determine the interrupt number based on the ADC port.
    //
    intNumber = ADC_getIntNumber(base, adcIntNum);

    ASSERT(intNumber != 0);

    //
    // Register the interrupt handler.
    //
    Interrupt_register(intNumber, handler);

    //
    // Enable the ADC interrupt.
    //
    Interrupt_enable(intNumber);
}

//*****************************************************************************
//
// ADC_unregisterInterrupt
//
//*****************************************************************************
void
ADC_unregisterInterrupt(uint32_t base, ADC_IntNumber adcIntNum)
{
    uint32_t intNumber;

    //
    // Check the arguments.
    //
    ASSERT(ADC_isBaseValid(base));

    //
    // Determine the interrupt number based on the ADC port.
    //
    intNumber = ADC_getIntNumber(base, adcIntNum);

    ASSERT(intNumber != 0);

    //
    // Disable the ADC interrupt.
    //
    Interrupt_disable(intNumber);

    //
    // Register the interrupt handler.
    //
    Interrupt_unregister(intNumber);
}

//*****************************************************************************
//
// ADC_registerPPBEventInterrupt
//
//*****************************************************************************
void
ADC_registerPPBEventInterrupt(uint32_t base, void (*handler)(void))
{
    uint32_t intNumber;

    //
    // Check the arguments.
    //
    ASSERT(ADC_isBaseValid(base));

    //
    // Determine the interrupt number based on the ADC port.
    //
    intNumber = ADC_getPPBEventIntNumber(base);

    ASSERT(intNumber != 0);

    //
    // Register the interrupt handler.
    //
    Interrupt_register(intNumber, handler);

    //
    // Enable the ADC interrupt.
    //
    Interrupt_enable(intNumber);
}

//*****************************************************************************
//
// ADC_unregisterPPBEventInterrupt
//
//*****************************************************************************
void
ADC_unregisterPPBEventInterrupt(uint32_t base)
{
    uint32_t intNumber;

    //
    // Check the arguments.
    //
    ASSERT(ADC_isBaseValid(base));

    //
    // Determine the interrupt number based on the ADC port.
    //
    intNumber = ADC_getPPBEventIntNumber(base);

    ASSERT(intNumber != 0);

    //
    // Disable the ADC interrupt.
    //
    Interrupt_disable(intNumber);

    //
    // Register the interrupt handler.
    //
    Interrupt_unregister(intNumber);
}

//*****************************************************************************
//
// ADC_setPPBTripLimits
//
//*****************************************************************************
void
ADC_setPPBTripLimits(uint32_t base, ADC_PPBNumber ppbNumber,
                     int32_t tripHiLimit, int32_t tripLoLimit)
{
    uint32_t ppbHiOffset;
    uint32_t ppbLoOffset;

    //
    // Check the arguments.
    //
    ASSERT(ADC_isBaseValid(base));
    ASSERT((tripHiLimit <= 65535) && (tripHiLimit >= -65536));
    ASSERT((tripLoLimit <= 65535) && (tripLoLimit >= -65536));

    //
    // Get the offset to the appropriate trip limit registers.
    //
    ppbHiOffset = (ADC_PPBxTRIPHI_STEP * (uint32_t)ppbNumber) +
                  ADC_O_PPB1TRIPHI;
    ppbLoOffset = (ADC_PPBxTRIPLO_STEP * (uint32_t)ppbNumber) +
                  ADC_O_PPB1TRIPLO;

    EALLOW;

    //
    // Set the trip high limit.
    //
    HWREG(base + ppbHiOffset) =
        (HWREG(base + ppbHiOffset) & ~ADC_PPBTRIP_MASK) |
        ((uint32_t)tripHiLimit & ADC_PPBTRIP_MASK);

    //
    // Set the trip low limit.
    //
    HWREG(base + ppbLoOffset) =
        (HWREG(base + ppbLoOffset) & ~ADC_PPBTRIP_MASK) |
        ((uint32_t)tripLoLimit & ADC_PPBTRIP_MASK);

    EDIS;
}
