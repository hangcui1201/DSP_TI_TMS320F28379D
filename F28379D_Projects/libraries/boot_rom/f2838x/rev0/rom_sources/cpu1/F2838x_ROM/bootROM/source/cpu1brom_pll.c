//###########################################################################
//
// FILE:    cpu1brom_pll.c
//
// TITLE:   PLL Enable and Power up Functions
//
//###########################################################################
// $TI Release: $
// $Release Date: $
//###########################################################################

//
// Included Files
//
#include "cpu1bootrom.h"

extern uint32_t CPU1BROM_bootStatus;

//
// Function Prototypes
//
bool BROMDCC_verifySingleShotClock(uint32_t base, DCC_Count0ClockSource clk0src,
                                   DCC_Count1ClockSource clk1src, uint32_t dccCounterSeed0,
                                   uint32_t dccCounterSeed1, uint32_t dccValidSeed0);

//
// CPU1BROM_enableSysPLL - Power up and switch to the SYS PLL
//
uint16_t CPU1BROM_enableSysPLL(uint16_t multiplier, uint16_t divider)
{
    uint32_t entryAddress = 0xFFFFFFFFUL;
    uint16_t i, j;
    uint16_t timeout = 512U;
    uint16_t dccCnt0Seed, dccCnt1Seed, dccValid0Seed;
    uint16_t dccStatus = 0U;

    //
    // Setup DCC Values
    //
    dccCnt0Seed = 94U;
    dccCnt1Seed = 100U * multiplier;
    dccValid0Seed = 12U;

    //
    // CPU1 Patch/Escape Point 9
    //
    entryAddress = CPU1BROM_TI_OTP_ESCAPE_POINT_9;
    if((entryAddress != 0xFFFFFFFFUL) &&
       (entryAddress != 0x00000000UL))
    {
        //
        // If OTP is programmed, then call OTP patch function
        //
        ((void (*)(void))entryAddress)();
    }

    //
    // Use INTOSC2 (~10 MHz) as the main PLL clock source
    //
    EALLOW;
    HWREGH(CLKCFG_BASE + SYSCTL_O_CLKSRCCTL1) &= ~SYSCTL_CLKSRCCTL1_OSCCLKSRCSEL_M;
    EDIS;

    //
    // Attempt to Lock the PLL five times. This helps ensure a successful start.
    //
    for(i = 0U; i < 5U; i++)
    {
        EALLOW;

        //
        // Turn off PLL and delay for power down
        //
        HWREGH(CLKCFG_BASE + SYSCTL_O_SYSPLLCTL1) &= ~SYSCTL_SYSPLLCTL1_PLLEN;

        //
        // Delay 25 cycles
        //
        asm(" MOV    @T,#25 ");
        asm(" RPT    @T \
              || NOP ");

        //
        // Write multiplier
        //
        HWREGH(CLKCFG_BASE + SYSCTL_O_SYSPLLMULT) = multiplier;

        //
        // Enable the sys PLL
        //
        HWREGH(CLKCFG_BASE + SYSCTL_O_SYSPLLCTL1) |= SYSCTL_SYSPLLCTL1_PLLEN;

        EDIS;

        //
        // Set time out to 512 cycles
        //
        j = timeout;

        //
        // Wait for the SYSPLL lock counter
        //
        while(((HWREGH(CLKCFG_BASE + SYSCTL_O_SYSPLLSTS) &
                SYSCTL_SYSPLLSTS_LOCKS) == 0U) && (j != 0U))
        {
            j--;
        }

        //
        // Padding lock time before taking DCC measurement by 512 cycles
        //
        j = timeout;
        while(j != 0U)
        {
            j--;
        }

        //
        // Using DCC to verify the PLL clock
        //
        SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_DCC0);
        dccStatus = BROMDCC_verifySingleShotClock(DCC0_BASE,
                                                  (DCC_Count0ClockSource)DCC_COUNT0SRC_INTOSC2,
                                                  (DCC_Count1ClockSource)DCC_COUNT1SRC_PLL,
                                                  dccCnt0Seed, dccCnt1Seed, dccValid0Seed);
        SysCtl_disablePeripheral(SYSCTL_PERIPH_CLK_DCC0);

        //
        // Break the Loop since PLL is running correctly
        //
        if(dccStatus != 0U)
        {
            break;
        }
    }

    //
    // If DCC failed to verify PLL clock is running correctly, return error
    //
    if(dccStatus == 0U)
    {
        //
        // Update boot status indicating failure
        //
        CPU1BROM_bootStatus |= CPU1_BOOTROM_PLL_FAILED_TO_ENABLE;

        //
        // Turn off PLL and delay for power down
        //
        EALLOW;
        HWREGH(CLKCFG_BASE + SYSCTL_O_SYSPLLCTL1) &= ~SYSCTL_SYSPLLCTL1_PLLEN;
        EDIS;

        //
        // Delay 25 cycles
        //
        asm(" MOV    @T,#25 ");
        asm(" RPT    @T \
              || NOP ");

        return(BROM_PLL_ENABLE_ERROR);
    }

    //
    // Convert divider value to value required for register
    //
    if(divider == 2U)
    {
        divider = 1U;
    }
    else if(divider == 4U)
    {
        divider = 2U;
    }
    else if(divider == 6U)
    {
        divider = 3U;
    }
    else // divider == 1
    {
        divider = 0U;
    }

    EALLOW;

    //
    // Set PLLSYSCLKDIV
    //
    HWREGH(CLKCFG_BASE + SYSCTL_O_SYSCLKDIVSEL) = ((HWREGH(CLKCFG_BASE + SYSCTL_O_SYSCLKDIVSEL) &
                                                    ~SYSCTL_SYSCLKDIVSEL_PLLSYSCLKDIV_M) | divider);

    //
    // Turn on PLL clock
    //
    HWREGH(CLKCFG_BASE + SYSCTL_O_SYSPLLCTL1) |= SYSCTL_SYSPLLCTL1_PLLCLKEN;

    //
    // Delay 25 cycles
    //
    asm(" MOV    @T,#25 ");
    asm(" RPT    @T \
          || NOP ");

    EDIS;

    return(BROM_PLL_ENABLE_SUCCESS);
}

//
// CPU1BROM_enableAuxPLL - Power up and switch to the Aux PLL
//
uint16_t CPU1BROM_enableAuxPLL(uint16_t multiplier, uint16_t divider)
{
    uint32_t entryAddress = 0xFFFFFFFFUL;
    uint16_t i, j;
    uint16_t timeout = 512U;
    uint16_t dccCnt0Seed, dccCnt1Seed, dccValid0Seed;
    uint16_t dccStatus = 0U;

    //
    // Setup DCC Values
    //
    dccCnt0Seed = 94U;
    dccCnt1Seed = 100U * multiplier;
    dccValid0Seed = 12U;

    //
    // CPU1 Patch/Escape Point 9
    //
    entryAddress = CPU1BROM_TI_OTP_ESCAPE_POINT_9;
    if((entryAddress != 0xFFFFFFFFUL) &&
       (entryAddress != 0x00000000UL))
    {
        //
        // If OTP is programmed, then call OTP patch function
        //
        ((void (*)(void))entryAddress)();
    }

    //
    // Use XTAL (20 MHz) as the aux PLL clock source
    //
    EALLOW;
    HWREGH(CLKCFG_BASE + SYSCTL_O_CLKSRCCTL2) &= ~SYSCTL_CLKSRCCTL2_AUXOSCCLKSRCSEL_M;
    HWREGH(CLKCFG_BASE + SYSCTL_O_CLKSRCCTL2) |= 1U;
    EDIS;

    //
    // Lock the PLL five times. This helps ensure a successful start.
    //
    for(i = 0U; i < 5U; i++)
    {
        EALLOW;

        //
        // Turn off AUXPLL and delay for it to power down.
        //
        HWREGH(CLKCFG_BASE + SYSCTL_O_AUXPLLCTL1) &= ~SYSCTL_AUXPLLCTL1_PLLEN;

        //
        // Delay 25 cycles
        //
        asm(" MOV    @T,#25 ");
        asm(" RPT    @T \
              || NOP ");

        //
        // Write multiplier
        //
        HWREGH(CLKCFG_BASE + SYSCTL_O_AUXPLLMULT) = multiplier;

        //
        // Enable AUXPLL
        //
        HWREGH(CLKCFG_BASE + SYSCTL_O_AUXPLLCTL1) |= SYSCTL_AUXPLLCTL1_PLLEN;

        EDIS;

        //
        // set time out to 512 cycles
        //
        j = timeout;

        //
        // Wait for the AUXPLL lock counter
        //
        while(((HWREGH(CLKCFG_BASE + SYSCTL_O_AUXPLLSTS) &
                SYSCTL_AUXPLLSTS_LOCKS) != 1U)  && (j != 0U))
        {
            j--;
        }

        //
        // Padding lock time before taking DCC measurement by 512 cycles
        //
        j = timeout;
        while(j != 0U)
        {
            j--;
        }

        //
        // Using DCC to verify the PLL clock
        //
        SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_DCC0);
        dccStatus = BROMDCC_verifySingleShotClock(DCC0_BASE,
                                                  (DCC_Count0ClockSource)DCC_COUNT0SRC_XTAL,
                                                  (DCC_Count1ClockSource)DCC_COUNT1SRC_AUXPLL,
                                                  dccCnt0Seed, dccCnt1Seed, dccValid0Seed);
        SysCtl_disablePeripheral(SYSCTL_PERIPH_CLK_DCC0);

        //
        // Break the Loop since PLL is running correctly
        //
        if(dccStatus != 0U)
        {
            break;
        }
    }

    //
    // If DCC failed to verify PLL clock is running correctly, return error
    //
    if(dccStatus == 0U)
    {
        //
        // Update boot status indicating failure
        //
        CPU1BROM_bootStatus |= CPU1_BOOTROM_PLL_FAILED_TO_ENABLE;

        //
        // Turn off AUXPLL and delay for it to power down.
        //
        EALLOW;
        HWREGH(CLKCFG_BASE + SYSCTL_O_AUXPLLCTL1) &= ~SYSCTL_AUXPLLCTL1_PLLEN;
        EDIS;

        //
        // Delay 25 cycles
        //
        asm(" MOV    @T,#25 ");
        asm(" RPT    @T \
              || NOP ");

        return(BROM_PLL_ENABLE_ERROR);
    }

    //
    // Convert divider value to value required for register
    //
    if(divider == 2U)
    {
        divider = 1U;
    }
    else if(divider == 4U)
    {
        divider = 2U;
    }
    else if(divider == 6U)
    {
        divider = 6U;
    }
    else if(divider == 8U)
    {
        divider = 3U;
    }
    else // divider == 1
    {
        divider = 0U;
    }

    EALLOW;

    //
    // Set AUXPLLDIV
    //
    HWREGH(CLKCFG_BASE + SYSCTL_O_AUXCLKDIVSEL) = ((HWREGH(CLKCFG_BASE + SYSCTL_O_AUXCLKDIVSEL) &
                                                    ~SYSCTL_AUXCLKDIVSEL_AUXPLLDIV_M) | divider);

    //
    // Turn on aux PLL clock
    //
    HWREGH(CLKCFG_BASE + SYSCTL_O_AUXPLLCTL1) |= SYSCTL_AUXPLLCTL1_PLLCLKEN;

    //
    // Delay 25 cycles
    //
    asm(" MOV    @T,#25 ");
    asm(" RPT    @T \
          || NOP ");

    EDIS;

    return(BROM_PLL_ENABLE_SUCCESS);
}

bool BROMDCC_verifySingleShotClock(uint32_t base, DCC_Count0ClockSource clk0src,
                                   DCC_Count1ClockSource clk1src, uint32_t dccCounterSeed0,
                                   uint32_t dccCounterSeed1, uint32_t dccValidSeed0)
{
    uint16_t j = dccCounterSeed1;

    //
    // Clear DONE and ERROR flags
    //
    EALLOW;
    HWREGH(DCC0_BASE + DCC_O_STATUS) = 3U;
    EDIS;

    //
    // Disable DCC
    //
    DCC_disableModule(DCC0_BASE);

    //
    // Disable Error Signal
    //
    DCC_disableErrorSignal(DCC0_BASE);

    //
    // Disable Done Signal
    //
    DCC_disableDoneSignal(DCC0_BASE);

    //
    // Configure Clock Source0 to whatever set as a clock source for PLL
    //
    DCC_setCounter0ClkSource(DCC0_BASE, clk0src);

    //
    // Configure Clock Source1 to PLL
    //
    DCC_setCounter1ClkSource(DCC0_BASE, clk1src);

    //
    // Configure COUNTER-0, COUNTER-1 & Valid Window
    //
    DCC_setCounterSeeds(DCC0_BASE, dccCounterSeed0, dccValidSeed0,
                        dccCounterSeed1);

    //
    // Enable Single Shot mode
    //
    DCC_enableSingleShotMode(DCC0_BASE, DCC_MODE_COUNTER_ZERO);

    //
    // Enable Error Signal
    //
    DCC_enableErrorSignal(DCC0_BASE);

    //
    // Enable Done Signal
    //
    DCC_enableDoneSignal(DCC0_BASE);

    //
    // Enable DCC to start counting
    //
    DCC_enableModule(DCC0_BASE);

    //
    // Wait until Error or Done Flag is generated or timeout
    //
    while(((HWREGH(DCC0_BASE + DCC_O_STATUS) &
           (DCC_STATUS_ERR | DCC_STATUS_DONE)) == 0U) && (j != 0U))
    {
       j--;
    }

    //
    // Returns true if DCC completes without error
    //
    return((HWREGH(DCC0_BASE + DCC_O_STATUS) &
            (DCC_STATUS_ERR | DCC_STATUS_DONE)) == DCC_STATUS_DONE);

}


//
// End of File
//
