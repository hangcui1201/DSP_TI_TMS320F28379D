//###########################################################################
//
// FILE:   ssi.c
//
// TITLE:  Driver for the SSI module.
//
//###########################################################################
// $TI Release:  $
// $Release Date:  $
// $Copyright:  $
//###########################################################################

#include "ssi.h"


//*****************************************************************************
//
// SSI_setConfig
//
//*****************************************************************************
void SSI_setConfig(uint32_t base, uint32_t ssiClk, uint32_t protocol,
                   uint32_t mode, uint32_t bitRate, uint32_t dataWidth)
{

    uint32_t maxBitRate;
    uint32_t preDiv;
    uint32_t scr;
    uint32_t sph_spo;

    //
    // Check the arguments.
    //
    ASSERT(SSI_isBaseValid(base));
    ASSERT((protocol == SSI_FRF_MOTO_MODE_0) ||
           (protocol == SSI_FRF_MOTO_MODE_1) ||
           (protocol == SSI_FRF_MOTO_MODE_2) ||
           (protocol == SSI_FRF_MOTO_MODE_3) ||
           (protocol == SSI_FRF_TI));
    ASSERT((mode == SSI_MODE_MASTER) ||
           (mode == SSI_MODE_SLAVE));
    ASSERT(((mode == SSI_MODE_MASTER) && (bitRate <= (ssiClk / 2U))) ||
           ((mode != SSI_MODE_MASTER) && (bitRate <= (ssiClk / 12U))));
    ASSERT((ssiClk / bitRate) <= (254U * 256U));
    ASSERT((dataWidth >= 4U) && (dataWidth <= 16U));

    //
    // Set the mode.
    //
    HWREG(base + SSI_O_CR1) = ((mode == SSI_MODE_MASTER) ? 0U : SSI_CR1_MS);

    //
    // Set the clock predivider.
    //
    maxBitRate = ssiClk / bitRate;
    preDiv = 0U;
    do
    {
        preDiv += 2U;
        scr = (maxBitRate / preDiv) - 1U;
    }
    while(scr > 255U);
    HWREG(base + SSI_O_CPSR) = preDiv;

    //
    // Set protocol and clock rate.
    //
    sph_spo = (protocol & 3U) << 6U;
    HWREG(base + SSI_O_CR0) = (scr << 8U) | sph_spo |
                              (protocol & SSI_CR0_FRF_M) |
                              (dataWidth - 1U);
}




//*****************************************************************************
//
// SSI_writeData
//
//*****************************************************************************
void SSI_writeData(uint32_t base, uint32_t data)
{
    //
    // Check the arguments.
    //
    ASSERT(SSI_isBaseValid(base));
    ASSERT((data & (0xFFFFFFFEU << (HWREG(base + SSI_O_CR0) &
                                    SSI_CR0_DSS_M))) == 0U);

    //
    // Wait until there is space.
    //
    while((HWREG(base + SSI_O_SR) & SSI_SR_TNF) == 0U)
    {
    }

    //
    // Write the data to the SSI.
    //
    HWREG(base + SSI_O_DR) = data;
}

//*****************************************************************************
//
// SSI_writeDataNonBlocking
//
//*****************************************************************************
int32_t SSI_writeDataNonBlocking(uint32_t base, uint32_t data)
{
    int32_t retVal;

    //
    // Check the arguments.
    //
    ASSERT(SSI_isBaseValid(base));
    ASSERT((data & (0xFFFFFFFEU << (HWREG(base + SSI_O_CR0) &
                                    SSI_CR0_DSS_M))) == 0U);

    //
    // Check for space to write.
    //
    if((HWREG(base + SSI_O_SR) & SSI_SR_TNF) != 0U)
    {
        HWREG(base + SSI_O_DR) = data;
        retVal = 1;
    }
    else
    {
        retVal = 0;
    }
    return(retVal);
}

//*****************************************************************************
//
// SSI_readData
//
//*****************************************************************************
void SSI_readData(uint32_t base, uint32_t *dataPtr)
{
    //
    // Check the arguments.
    //
    ASSERT(SSI_isBaseValid(base));

    //
    // Wait until there is data to be read.
    //
    while((HWREG(base + SSI_O_SR) & SSI_SR_RNE) == 0U)
    {
    }

    //
    // Read data from SSI.
    //
    *dataPtr = HWREG(base + SSI_O_DR);
}

//*****************************************************************************
//
// SSI_readDataNonBlocking
//
//*****************************************************************************
int32_t SSI_readDataNonBlocking(uint32_t base, uint32_t *dataPtr)
{
    int32_t retVal;

    //
    // Check the arguments.
    //
    ASSERT(SSI_isBaseValid(base));

    //
    // Check for data to read.
    //
    if((HWREG(base + SSI_O_SR) & SSI_SR_RNE) != 0U)
    {
        *dataPtr = HWREG(base + SSI_O_DR);
        retVal = 1;
    }
    else
    {
        retVal = 0;
    }
    return(retVal);
}
