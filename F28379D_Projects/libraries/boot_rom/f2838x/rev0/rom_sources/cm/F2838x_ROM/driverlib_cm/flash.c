//###########################################################################
//
// FILE:   flash.c
//
// TITLE:  CM Flash driver.
//
//###########################################################################
// $TI Release:  $
// $Release Date:  $
// $Copyright:  $
//###########################################################################

#include "flash.h"

//#ifndef __cplusplus
//#pragma CODE_SECTION(Flash_initModule, ".TI.ramfunc");
//#endif

//*****************************************************************************
//
// Flash_initModule
//
//*****************************************************************************
#ifdef __cplusplus
#pragma CODE_SECTION(".TI.ramfunc");
#endif
void
Flash_initModule(uint32_t ctrlBase, uint32_t eccBase, uint16_t waitstates)
{
    volatile uint32_t count;
    //
    // Check the arguments.
    //
    ASSERT(Flash_isCtrlBaseValid(ctrlBase));
    ASSERT(Flash_isECCBaseValid(eccBase));
    ASSERT(waitstates <= 0xFU);

    //
    // Unlock to enable the writes to the flash control and ECC registers.
    //
    Flash_unlockCtrlRegisters(ctrlBase);
    Flash_unlockECCRegisters(eccBase);

    //
    // Set the bank fallback power mode to active.
    //
    Flash_setBankPowerMode(ctrlBase, FLASH_BANK, FLASH_BANK_PWR_ACTIVE);

    //
    // Power up flash bank and pump and this also sets the fall back mode of
    // flash and pump as active
    //
    Flash_setPumpPowerMode(ctrlBase, FLASH_PUMP_PWR_ACTIVE);

    //
    // Disable cache and prefetch mechanism before changing wait states
    //
    Flash_disableDataCache(ctrlBase);
    Flash_disableProgramCache(ctrlBase);

    //
    // Set waitstates according to frequency.
    //
    Flash_setWaitstates(ctrlBase, waitstates);

    //
    // Enable cache and prefetch mechanism to improve performance of code
    // executed from flash.
    //
    Flash_enableDataCache(ctrlBase);
    Flash_enableProgramCache(ctrlBase);

    //
    // At reset, ECC is enabled.  If it is disabled by application software and
    // if application again wants to enable ECC.
    //
    Flash_enableECC(eccBase);

    //
    // Force a pipeline flush to ensure that the write to the last register
    // configured occurs before returning.
    //
    for(count = 0U; count < 8U; count++)
    {
        NOP;
    }
}

//*****************************************************************************
//
// Flash_powerDown
//
//*****************************************************************************
void
Flash_powerDown(uint32_t ctrlBase)
{
    //
    // Check the arguments.
    //
    ASSERT(Flash_isCtrlBaseValid(ctrlBase));

    //
    // Unlock to enable the writes to the flash control registers.
    //
    Flash_unlockCtrlRegisters(ctrlBase);

    //
    // Power down the flash bank.
    //
    Flash_setBankPowerMode(ctrlBase, FLASH_BANK, FLASH_BANK_PWR_SLEEP);

    //
    // Power down the flash pump.
    //
    Flash_setPumpPowerMode(ctrlBase, FLASH_PUMP_PWR_SLEEP);
}
