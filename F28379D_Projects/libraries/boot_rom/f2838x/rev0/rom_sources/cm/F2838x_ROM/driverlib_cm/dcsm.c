//#############################################################################
//
// FILE:   dcsm.c
//
// TITLE:  C28x Driver for the DCSM security module.
//
//#############################################################################
// $TI Release:  $
// $Release Date:  $
// $Copyright:  $
//#############################################################################

#include "dcsm.h"

//*****************************************************************************
//
// DCSM_writeZone1CSM
//
//*****************************************************************************
void
DCSM_writeZone1CSM(const DCSM_CSMPasswordKey * const psCMDKey)
{
    //
    // Check the arguments.
    //
    ASSERT(psCMDKey != NULL);

    HWREG(DCSM_Z1_BASE + DCSM_O_Z1_CSMKEY0) = psCMDKey->csmKey0;
    HWREG(DCSM_Z1_BASE + DCSM_O_Z1_CSMKEY1) = psCMDKey->csmKey1;
    HWREG(DCSM_Z1_BASE + DCSM_O_Z1_CSMKEY2) = psCMDKey->csmKey2;
    HWREG(DCSM_Z1_BASE + DCSM_O_Z1_CSMKEY3) = psCMDKey->csmKey3;

}

//*****************************************************************************
//
// DCSM_writeZone2CSM
//
//*****************************************************************************
void
DCSM_writeZone2CSM(const DCSM_CSMPasswordKey * const psCMDKey)
{
    //
    // Check the arguments.
    //
    ASSERT(psCMDKey != NULL);

    HWREG(DCSM_Z2_BASE + DCSM_O_Z2_CSMKEY0) = psCMDKey->csmKey0;
    HWREG(DCSM_Z2_BASE + DCSM_O_Z2_CSMKEY1) = psCMDKey->csmKey1;
    HWREG(DCSM_Z2_BASE + DCSM_O_Z2_CSMKEY2) = psCMDKey->csmKey2;
    HWREG(DCSM_Z2_BASE + DCSM_O_Z2_CSMKEY3) = psCMDKey->csmKey3;

}
//*****************************************************************************
//
// DCSM_getZone1FlashEXEStatus
//
//*****************************************************************************
DCSM_EXEOnlyStatus
DCSM_getZone1FlashEXEStatus(DCSM_Sector sector, DCSM_CPUSel cpuInst)
{
    uint16_t regValue;
    uint32_t regintValue;
    DCSM_EXEOnlyStatus status;

    //
    // Check if sector belongs to this zone
    //
    if(DCSM_getFlashSectorZone(sector, cpuInst) != DCSM_MEMORY_ZONE1)
    {
        status = DCSM_INCORRECT_ZONE;
    }
    else
    {
        //
        // Get the EXE status register
        //
    if(cpuInst == DCSM_CPUSEL_CPU1)
    {
        regintValue = ((HWREG(DCSM_Z1_BASE +
                                     DCSM_O_Z1_EXEONLYSECT1R)) &
                              DCSM_EXEONLYSECTR_M);

        regValue = (uint16_t)regintValue;
     }
     else if(cpuInst == DCSM_CPUSEL_CM)
     {
        regintValue = ((HWREG(DCSM_Z1_BASE + DCSM_O_Z1_EXEONLYSECT1R))
                         >> DCSM_EXEONLYSECTR_S);

        regValue = (uint16_t)regintValue;
     }
    else
    {
        regValue = (HWREGH(DCSM_Z1_BASE + DCSM_O_Z1_EXEONLYSECT2R));

    }

        //
        // Get the EXE status of the Flash Sector
        //
        status = (DCSM_EXEOnlyStatus)((regValue >> (uint16_t)sector) &
                                    (uint16_t)0x01U);
    }
    return(status);
}

//*****************************************************************************
//
// DCSM_getZone1RAMEXEStatus
//
//*****************************************************************************
DCSM_EXEOnlyStatus
DCSM_getZone1RAMEXEStatus(DCSM_RAMModule module, DCSM_CPUSel cpuInst)
{
    DCSM_EXEOnlyStatus status;
    DCSM_RAMModule moduleCM = (DCSM_RAMModule)0U;

    ASSERT(cpuInst <= DCSM_CPUSEL_CPU2);

    if((cpuInst == DCSM_CPUSEL_CPU1) || (cpuInst == DCSM_CPUSEL_CPU2))
        ASSERT(module < DCSM_C28_RAM_END);

    if(cpuInst == DCSM_CPUSEL_CM)
    {
        ASSERT((module > DCSM_C28_RAM_END) &&
               (module < DCSM_CM_RAM_END));

        moduleCM  = (DCSM_RAMModule)(module - (DCSM_C28_RAM_END + 1U));
    }

    //
    // Check if module belongs to this zone
    //
    if(DCSM_getRAMZone(module, cpuInst) != DCSM_MEMORY_ZONE1)
    {
        status = DCSM_INCORRECT_ZONE;
    }
    else
    {
        //
        // Get the EXE status of the RAM Module
        //
    if(cpuInst == DCSM_CPUSEL_CPU1)
    {
        status = (DCSM_EXEOnlyStatus)((HWREGH(DCSM_Z1_BASE +
                                       DCSM_O_Z1_EXEONLYRAM1R) >>
                                       (uint16_t)module) & (uint16_t)0x01U);
    }
    else if(cpuInst == DCSM_CPUSEL_CM)
    {
        status = (DCSM_EXEOnlyStatus)(((uint32_t)HWREG(DCSM_Z1_BASE +
                                        DCSM_O_Z1_EXEONLYRAM1R) >>
                                       (DCSM_Z1_EXEONLYRAM1R_CM +
                                       (uint16_t)moduleCM)) &
                                       (uint32_t)0x01U);
    }
    else
    {
        status = (DCSM_EXEOnlyStatus)((HWREG(DCSM_Z1_BASE +
                                        DCSM_O_Z1_EXEONLYRAM1R) >>
                                       (DCSM_Z1_EXEONLYRAM1R_CPU2 -
                                       (uint16_t)module)) &
                                       (uint16_t)0x01U);
    }

    }
    return(status);
}

//*****************************************************************************
//
// DCSM_getZone2FlashEXEStatus
//
//*****************************************************************************
DCSM_EXEOnlyStatus
DCSM_getZone2FlashEXEStatus(DCSM_Sector sector, DCSM_CPUSel cpuInst)
{
    uint16_t regValue;
    uint32_t regintValue;
    DCSM_EXEOnlyStatus status;

    //
    // Check if sector belongs to this zone
    //
    if(DCSM_getFlashSectorZone(sector, cpuInst) != DCSM_MEMORY_ZONE2)
    {
        status = DCSM_INCORRECT_ZONE;
    }
    else
    {
        //
        // Get the EXE status register
        //
    if(cpuInst == DCSM_CPUSEL_CPU1)
     {
         regintValue = ((HWREG(DCSM_Z2_BASE +
                                      DCSM_O_Z2_EXEONLYSECT1R)) &
                               DCSM_EXEONLYSECTR_M);

         regValue = (uint16_t)regintValue;
      }
    else if(cpuInst == DCSM_CPUSEL_CM)
     {
         regintValue = ((HWREG(DCSM_Z2_BASE + DCSM_O_Z2_EXEONLYSECT1R))
                         >> DCSM_EXEONLYSECTR_S);

         regValue = (uint16_t)regintValue;
      }
    else
      {
        regValue = HWREGH(DCSM_Z2_BASE + DCSM_O_Z2_EXEONLYSECT2R);

      }

        //
        // Get the EXE status of the Flash Sector
        //
        status = (DCSM_EXEOnlyStatus)((regValue >> (uint16_t)sector) &
                                    (uint16_t)0x01U);
    }

    return(status);
}

//*****************************************************************************
//
// DCSM_getZone2RAMEXEStatus
//
//*****************************************************************************
DCSM_EXEOnlyStatus
DCSM_getZone2RAMEXEStatus(DCSM_RAMModule module, DCSM_CPUSel cpuInst)
{
    DCSM_EXEOnlyStatus status;
    DCSM_RAMModule moduleCM = (DCSM_RAMModule)0U;

    ASSERT(cpuInst <= DCSM_CPUSEL_CPU2);

    if((cpuInst == DCSM_CPUSEL_CPU1) || (cpuInst == DCSM_CPUSEL_CPU2))
        ASSERT(module < DCSM_C28_RAM_END);

    if(cpuInst == DCSM_CPUSEL_CM)
    {
        ASSERT((module > DCSM_C28_RAM_END) &&
               (module < DCSM_CM_RAM_END));

        moduleCM  = (DCSM_RAMModule)(module - (DCSM_C28_RAM_END + 1U));
    }

    //
    // Check if module belongs to this zone
    //
    if(DCSM_getRAMZone(module, cpuInst) != DCSM_MEMORY_ZONE2)
    {
        status = DCSM_INCORRECT_ZONE;
    }
    else
    {
        //
        // Get the EXE status of the RAM Module
        //
    if(cpuInst == DCSM_CPUSEL_CPU1)
    {
        status = (DCSM_EXEOnlyStatus)((HWREGH(DCSM_Z2_BASE +
                                       DCSM_O_Z2_EXEONLYRAM1R) >>
                                       (uint16_t)module) & (uint16_t)0x01U);
    }
    else if(cpuInst == DCSM_CPUSEL_CM)
    {
        status = (DCSM_EXEOnlyStatus)((HWREG(DCSM_Z2_BASE +
                                        DCSM_O_Z2_EXEONLYRAM1R) >>
                                       (DCSM_Z2_EXEONLYRAM1R_CM +
                                       (uint16_t)moduleCM)) &
                                       (uint16_t)0x01U);
    }
    else
    {
        status = (DCSM_EXEOnlyStatus)((HWREG(DCSM_Z2_BASE +
                                        DCSM_O_Z2_EXEONLYRAM1R) >>
                                       (DCSM_Z2_EXEONLYRAM1R_CPU2 -
                                        (uint16_t)module)) &
                                       (uint16_t)0x01U);
    }
    }
    return(status);
}

//*****************************************************************************
//
// DCSM_claimZoneSemaphore
//
//*****************************************************************************
bool
DCSM_claimZoneSemaphore(DCSM_SemaphoreZone zone)
{
    //
    // FLSEM register address.
    //
    uint32_t regAddress = DCSMCOMMON_BASE + DCSM_O_FLSEM;

    //
    // Write 0xA5 to the key and write the zone that is attempting to claim the
    // Flash Pump Semaphore to the semaphore bits.
    //
    HWREGH(regAddress) = ((uint16_t)FLSEM_KEY << DCSM_FLSEM_KEY_S) |
                         (uint16_t)zone;

    //
    // If the calling function was unable to claim the zone semaphore, then
    // return false
    //
    return(((HWREGH(regAddress) & DCSM_FLSEM_SEM_M) == (uint16_t)zone) ?
             true : false);
}

//*****************************************************************************
//
// DCSM_releaseZoneSemaphore
//
//*****************************************************************************
bool
DCSM_releaseZoneSemaphore(void)
{
    //
    // FLSEM register address.
    //
    uint32_t regAddress = DCSMCOMMON_BASE + DCSM_O_FLSEM;

    //
    // Write 0xA5 to the key and write the zone that is attempting to claim the
    // Flash Pump Semaphore to the semaphore bits.
    //
    HWREGH(regAddress) = ((uint16_t)FLSEM_KEY << DCSM_FLSEM_KEY_S);

    //
    // If the calling function was unable to release the zone semaphore, then
    // return false
    //
    return(((HWREGH(regAddress) & DCSM_FLSEM_SEM_M) == 0x0U) ? true : false);
}
