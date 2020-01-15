//###########################################################################
//
// FILE:    cpu1brom_pbist.c
//
// TITLE:   pbist code for CPU1-Core
//
//
//
//###########################################################################
// $TI Release: $
// $Release Date: $
//###########################################################################

//
// Included Files
//
#include "pbist.h"

//
// Enable Peripherals PCLKCR0-CLA,PCLKCR10-DCAN/MCAN, PCLKR11 - USB and
// PCLKCR22-PBIST.
//
#define PBIST_ENABLE_ALL_PERIPHERAL_CLOCKS() \
            { \
                HWREG(SYSCTL_PCLKCR0)  = 0x1UL; \
                HWREG(SYSCTL_PCLKCR10) = 0x13UL; \
                HWREG(SYSCTL_PCLKCR11) = 0x10000UL; \
                HWREG(SYSCTL_PCLKCR22) = 0x1UL; \
                HWREG(SYSCTL_PCLKCR23) = 0x1UL; \
            }

//
// Disable peripherals PCLKCR0-CLA,PCLKCR10-DCAN/MCAN, PCLKR11 - USB and
// PCLKCR22-PBIST.
//
#define PBIST_DISABLE_PERIPHERAL_CLOCKS() \
            { \
                HWREG(SYSCTL_PCLKCR0)  = 0x0UL; \
                HWREG(SYSCTL_PCLKCR10) = 0x0UL; \
                HWREG(SYSCTL_PCLKCR11) = 0x0UL; \
                HWREG(SYSCTL_PCLKCR22) = 0x0UL; \
                HWREG(SYSCTL_PCLKCR23) = 0x0UL; \
            }
//
// Soft reset peripherals.
// 12-DUMMY to provide enough cycles so that Softpres can take effect
// In the beginning, PBIST_ACTIVE = 1 except USB all will be mapped to CPU1
// to ensure that USB is getting reset, make PBIST_ACTIVE = 0 so that it will
// be mapped to CPU1.
//
#define PBIST_SOFT_RESET_PERIPHERALS() \
            { \
                HWREG(SYSCTL_SOFTPRES0)  = 0xFUL; \
                HWREG(SYSCTL_SOFTPRES10) = 0xFFUL; \
                HWREG(SYSCTL_SOFTPRES23) = 0xFFFFFFUL; \
                asm(" RPT #14 || NOP");\
                HWREG(SYSCTL_SOFTPRES0)  = 0x0UL; \
                HWREG(SYSCTL_SOFTPRES10) = 0x0UL; \
                HWREG(SYSCTL_SOFTPRES23) = 0x0UL; \
                asm(" RPT #14 || NOP");\
                HWREG(PBIST_PACT) = 0x0UL;\
                asm(" RPT #20 || NOP");\
                HWREG(SYSCTL_SOFTPRES11) = 0xFFFFFFUL; \
                asm(" RPT #14 || NOP");\
                HWREG(SYSCTL_SOFTPRES11) = 0x0UL; \
                HWREGH(PBIST_PIE12_IFR) = 0x0U;\
            }

#define PBIST_RAM_INIT() \
                { \
                    EALLOW; \
                    HWREG(PBIST_MEMCFG_DXINT) = 0xFUL; \
                    HWREG(PBIST_MEMCFG_LSXINT) = 0xFFUL; \
                    HWREG(PBIST_MEMCFG_GSXINT) = 0xFFFFUL; \
                    HWREG(PBIST_MEMCFG_MSGXINT) = 0x3FFUL; \
                    EDIS; \
                    asm(" MOV @T,#2080"); \
                    asm(" RPT @T"); \
                    asm(" ||NOP"); \
                }

//*****************************************************************************
//
// PBIST_PORMemoryTest - Test Memory on Power on Reset via PBIST controller
//
//*****************************************************************************
uint32_t PBIST_PORMemoryTest(void)
{
    register uint32_t count_alwaysfail  = 1000UL;
    register uint32_t count_flushout    = 2500UL;
    register uint32_t count_memory_test = 150000UL;

    //
    // Disable interrupts.
    //
    DINT;
    DRTM;

    //
    // Enable necessary peripheral clocks.
    //
    EALLOW;
    PBIST_ENABLE_ALL_PERIPHERAL_CLOCKS();

    //
    // PBIST Test 1. Configuring PBIST for all fail test.
    // Performing March 13n test on TMU ROM.
    //
    HWREGH(PBIST_PIE12_IER) = 0U;
    HWREG(PBIST_PACT) = 0x1UL;
    HWREG(PBIST_OVERRIDE) = 0x9UL;
    HWREG(PBIST_DLRT) = 0x10UL;

    HWREG(PBIST_RINFOL) =  PBIST_RINFOL_ROM_MEM_GROUP;
    HWREG(PBIST_RINFOU) = 0x0UL;
    HWREG(PBIST_ALGO)   = PBIST_ALGO_TMU_ROM_FAIL_ALGO;
    HWREG(PBIST_OVERRIDE) = 0x0UL;
    HWREG(PBIST_DLRT) = 0x14UL;
    EDIS;

    //
    // 1500 clock cycles are taken for PBIST to start testing and report the
    // first fail and PBIST to trigger an interrupt. Count gets decremented every
    // 16 cycles according to following loop structure. A safe value for
    // count would be decimal  of 750.
    //
    while (HWREGH(PBIST_PIE12_IFR) != 0x8U)
    {
        count_alwaysfail--;
        if(count_alwaysfail == 0x0UL)
        {
            //
            // PBIST controller has timed-out. Return an error.
            //
            EALLOW;
            PBIST_SOFT_RESET_PERIPHERALS();
            PBIST_DISABLE_PERIPHERAL_CLOCKS();
            EDIS;
            PBIST_RAM_INIT();
            return(PBIST_ALWAYSFAIL_TIMEOUT_ERROR);
        }
    }

    //
    // Check if there is an error.
    //
    if((HWREG(PBIST_FAIL_STATUS_0) == 0UL) &&
       (HWREG(PBIST_FAIL_STATUS_1) == 0UL))
    {
        EALLOW;
        PBIST_SOFT_RESET_PERIPHERALS();
        PBIST_DISABLE_PERIPHERAL_CLOCKS();
        EDIS;
        PBIST_RAM_INIT();
        return(PBIST_ALWAYSFAIL_INCORRECT_OPERATION);
    }

    EALLOW;
    HWREGH(PBIST_PIE12_IFR) = 0x0U;
    HWREG(PBIST_DLRT) = 0x16UL;
    HWREG(PBIST_STR) = 0x1UL;
    EDIS;

    //
    //PBIST second interrupt.
    //
    while(HWREGH(PBIST_PIE12_IFR) != 0x8U)
    {
        count_flushout--;
        if(count_flushout == 0UL)
        {
            EALLOW;
            PBIST_SOFT_RESET_PERIPHERALS();
            PBIST_DISABLE_PERIPHERAL_CLOCKS();
            EDIS;
            PBIST_RAM_INIT();
            return(PBIST_DOUBLEINT_TIMEOUT_ERROR);
        }
    }

    //
    // PBIST Test 2. Configuring PBIST to test all memories
    // including 200 MHz RAMs, 150 MHz ROMs, and 125 MHz CM RAMs.
    //
    EALLOW;
    HWREGH(PBIST_PIE12_IFR) = 0x0U;
    HWREG(PBIST_DLRT)      = 0x0UL;
    HWREG(PBIST_OVERRIDE)  = 0x9UL;
    HWREG(PBIST_DLRT)      = 0x10UL;
    HWREG(PBIST_RINFOL) = 0xFFFFFFFFUL;
    HWREG(PBIST_RINFOU) = 0xFFFFFFFFUL;

    HWREG(PBIST_ALGO) = PBIST_ALGO_ALL_MEM;
    HWREG(PBIST_OVERRIDE) = 0x1UL;
    HWREG(PBIST_DLRT) = 0x214UL;
    EDIS;

    while(HWREGH(PBIST_PIE12_IFR) != 0x8U)
    {
        count_memory_test--;
        if(count_memory_test == 0x0UL)
        {
            EALLOW;
            PBIST_SOFT_RESET_PERIPHERALS();
            PBIST_DISABLE_PERIPHERAL_CLOCKS();
            EDIS;
            PBIST_RAM_INIT();
            return(PBIST_MEMORYTEST_TIMEOUT_ERROR);
        }
    }

    //
    // Check if there is an error.
    //
    if((HWREG(PBIST_FAIL_STATUS_0) == 1UL) ||
       (HWREG(PBIST_FAIL_STATUS_1) == 1UL))
    {
        EALLOW;
        PBIST_SOFT_RESET_PERIPHERALS();
        PBIST_DISABLE_PERIPHERAL_CLOCKS();
        EDIS;
        PBIST_RAM_INIT();
        return(PBIST_MEMORY_TEST_FAIL_ERROR);
    }

    //
    // Tests have passed and return from function.
    //
    EALLOW;
    PBIST_SOFT_RESET_PERIPHERALS();
    PBIST_DISABLE_PERIPHERAL_CLOCKS();
    EDIS;
    PBIST_RAM_INIT();
    return(PBIST_MEMORY_TEST_PASS);
}

//
// End of File
//
