//###########################################################################
//
// FILE:    cpu1brom_system_boot.c
//
// TITLE:   CPU1 System Boot
//
// CPU1 System Initialization and associated functions
//
//###########################################################################
// $TI Release: $
// $Release Date:  $
//###########################################################################

//
// Included Files
//
#include "cpu1bootrom.h"

//
// Globals
//
#pragma DATA_SECTION(CPU1BROM_bootMode, "UserBootModeVariable");
uint32_t CPU1BROM_bootMode;

#pragma DATA_SECTION(CPU1BROM_pbistStatus, "PBISTStatusVariable");
uint32_t CPU1BROM_pbistStatus;

uint32_t CPU1BROM_flashSingleBitError_lowAddress;
uint32_t CPU1BROM_flashSingleBitError_highAddress;

#pragma DATA_SECTION(CPU1BROM_bootStatus, "BootStatusVariable");
uint32_t CPU1BROM_bootStatus;

extern uint32_t CPU1BROM_itrapAddress;

volatile uint16_t CPU1BROM_nmiStatus;

//
// Function Prototypes
//
void CPU1BROM_verifySecureFlash(uint32_t entryAddress);
void CPU1BROM_setPMMTrims(void);
void CPU1BROM_setIntOscTrims(void);
void CPU1BROM_configureAPLL(void);
void CPU1BROM_setupDeviceSystems(void);
void CPU1BROM_performDeviceConfiguration(void);
uint32_t CPU1BROM_startSystemBoot(void);
void CPU1BROM_enableUnbondedGpioPullups(void);
extern unsigned short verify_pbist_checksum_onROM(void);

//
// CPU1BROM_setPMMTrims - Write PMM trims from OTP to analog registers
//
void CPU1BROM_setPMMTrims(void)
{
    //
    // Check PMM Trim key and return if not set
    //
    if(HWREAD_TI_OTP_PMM_TRIM_KEY != TI_OTP_KEY)
    {
        return;
    }

    //
    // Must trim in order REF->VREG->VMON
    //
    EALLOW;
    HWREGH(ANALOGSUBSYS_BASE + ASYSCTL_O_PMMREFTRIM) = HWREAD_TI_OTP_PMM_REF_TRIM_VALUE;
    HWREG(ANALOGSUBSYS_BASE + ASYSCTL_O_PMMVREGTRIM) = (((uint32_t)HWREAD_TI_OTP_PMM_VSINK_TRIM_VALUE << 16U) |
                                                         HWREAD_TI_OTP_PMM_VREG_TRIM_VALUE);
    HWREGH(ANALOGSUBSYS_BASE + ASYSCTL_O_PMMVMONTRIM) = HWREAD_TI_OTP_PMM_VMON_TRIM_VALUE;
    EDIS;

    //
    // Calculate the Count for 75 uS at 10MHz +/- 5% MHz efuse trimmed clock,
    // with buffer which is 1225, This would result in 82uS blank window
    //
    asm(" MOV    @T,#1225 ");
    asm(" RPT    @T \
            ||NOP ");
}

//
// CPU1BROM_setIntOscTrims - Write internal oscillator 1 and 2 trims from OTP
//                           to analog registers
//
void CPU1BROM_setIntOscTrims(void)
{
    //
    // Check OSC Trim key and return if not set
    //
    if(HWREAD_TI_OTP_INTOSC_TRIM_KEY != TI_OTP_KEY)
    {
        return;
    }

    EALLOW;

    //
    // Trim order: OSCREF -> INTOSC1 -> INTOSC2
    //
    HWREGH(ANALOGSUBSYS_BASE + ASYSCTL_O_OSCREFTRIM) = HWREAD_TI_OTP_OSC_REF_TRIM_VALUE;
    HWREG(ANALOGSUBSYS_BASE + ASYSCTL_O_INTOSC1TRIM) = HWREAD_TI_OTP_INTOSC1_TRIM_VALUE;
    HWREG(ANALOGSUBSYS_BASE + ASYSCTL_O_INTOSC2TRIM) = HWREAD_TI_OTP_INTOSC2_TRIM_VALUE;

    EDIS;

    //
    // calculate the Count for 12 uS at 10MHz +/- 7% MHz efuse trimmed clock, 
    // with buffer this will result in 16uS blank window
    //
    asm(" MOV    @T,#178 ");
    asm(" RPT    @T \
          || NOP ");
}

//
// CPU1BROM_configureAPLL() - Write A-PLL trims from OTP to APLL registers
//                            and set APLL analog configuration registers
//
void CPU1BROM_configureAPLL(void)
{
    EALLOW;

    //
    // Check APLL Trim key and trim APLL if set
    //
    if(HWREAD_TI_OTP_APLL_TRIM_KEY == TI_OTP_KEY)
    {
        HWREGH(ANALOGSUBSYS_BASE + ASYSCTL_O_APLLREFTRIM) = HWREAD_TI_OTP_APLLREF_TRIM_VALUE;

        HWREGH(ANALOGSUBSYS_BASE + ASYSCTL_O_SYSAPLLLDOTRIM) = HWREAD_TI_OTP_APLL_SYS_TRIM_VALUE & TI_OTP_APLL_OSC_VDD_MASK;
        HWREGH(ANALOGSUBSYS_BASE + ASYSCTL_O_SYSAPLLOSCTRIM) = ((HWREAD_TI_OTP_APLL_SYS_TRIM_VALUE &
                                                                TI_OTP_APLL_OSC_FREQ_MASK) >> TI_OTP_APLL_OSC_FREQ_SHIFT);

        HWREGH(ANALOGSUBSYS_BASE + ASYSCTL_O_AUXAPLLLDOTRIM) = HWREAD_TI_OTP_APLL_AUX_TRIM_VALUE & TI_OTP_APLL_OSC_VDD_MASK;
        HWREGH(ANALOGSUBSYS_BASE + ASYSCTL_O_AUXAPLLOSCTRIM) = ((HWREAD_TI_OTP_APLL_AUX_TRIM_VALUE &
                                                                TI_OTP_APLL_OSC_FREQ_MASK) >> TI_OTP_APLL_OSC_FREQ_SHIFT);
    }

    //
    // Configure APLL when key is set
    //
    if(HWREAD_TI_OTP_APLLCONFIG_KEY == TI_OTP_KEY)
    {
        HWREGH(ANALOGSUBSYS_BASE + ASYSCTL_O_SYSAPLLCONFIG1) = HWREAD_TI_OTP_APLLCONFIG1_VALUE;
        HWREGH(ANALOGSUBSYS_BASE + ASYSCTL_O_AUXAPLLCONFIG1) = HWREAD_TI_OTP_APLLCONFIG1_VALUE;

        HWREGH(ANALOGSUBSYS_BASE + ASYSCTL_O_SYSAPLLCONFIG2) = HWREAD_TI_OTP_APLLCONFIG2_VALUE;
        HWREGH(ANALOGSUBSYS_BASE + ASYSCTL_O_AUXAPLLCONFIG2) = HWREAD_TI_OTP_APLLCONFIG2_VALUE;

        HWREGH(ANALOGSUBSYS_BASE + ASYSCTL_O_SYSAPLLCONFIG3) = HWREAD_TI_OTP_APLLCONFIG3_VALUE;
        HWREGH(ANALOGSUBSYS_BASE + ASYSCTL_O_AUXAPLLCONFIG3) = HWREAD_TI_OTP_APLLCONFIG3_VALUE;

        HWREGH(ANALOGSUBSYS_BASE + ASYSCTL_O_SYSAPLLCONFIG4) = HWREAD_TI_OTP_APLLCONFIG4_VALUE;
        HWREGH(ANALOGSUBSYS_BASE + ASYSCTL_O_AUXAPLLCONFIG4) = HWREAD_TI_OTP_APLLCONFIG4_VALUE;

        HWREGH(ANALOGSUBSYS_BASE + ASYSCTL_O_SYSAPLLCONFIG5) = HWREAD_TI_OTP_APLLCONFIG5_VALUE;
        HWREGH(ANALOGSUBSYS_BASE + ASYSCTL_O_AUXAPLLCONFIG5) = HWREAD_TI_OTP_APLLCONFIG5_VALUE;

        HWREGH(ANALOGSUBSYS_BASE + BROM_ASYSCTL_O_SYSAPLLCONFIG6) = HWREAD_TI_OTP_APLLCONFIG6_VALUE;
        HWREGH(ANALOGSUBSYS_BASE + BROM_ASYSCTL_O_AUXAPLLCONFIG6) = HWREAD_TI_OTP_APLLCONFIG6_VALUE;

        HWREGH(ANALOGSUBSYS_BASE + ASYSCTL_O_SYSAPLLCONFIG7) = HWREAD_TI_OTP_APLLCONFIG7_VALUE;
        HWREGH(ANALOGSUBSYS_BASE + ASYSCTL_O_AUXAPLLCONFIG7) = HWREAD_TI_OTP_APLLCONFIG7_VALUE;

        HWREGH(ANALOGSUBSYS_BASE + ASYSCTL_O_SYSAPLLCONFIG8) = HWREAD_TI_OTP_APLLCONFIG8_VALUE;
        HWREGH(ANALOGSUBSYS_BASE + ASYSCTL_O_AUXAPLLCONFIG8) = HWREAD_TI_OTP_APLLCONFIG8_VALUE;

        HWREGH(ANALOGSUBSYS_BASE + ASYSCTL_O_SYSAPLLCONFIG9) = HWREAD_TI_OTP_APLLCONFIG9_VALUE;
        HWREGH(ANALOGSUBSYS_BASE + ASYSCTL_O_AUXAPLLCONFIG9) = HWREAD_TI_OTP_APLLCONFIG9_VALUE;

        HWREGH(ANALOGSUBSYS_BASE + ASYSCTL_O_SYSAPLLCONFIG10) = HWREAD_TI_OTP_APLLCONFIG10_VALUE;
        HWREGH(ANALOGSUBSYS_BASE + ASYSCTL_O_AUXAPLLCONFIG10) = HWREAD_TI_OTP_APLLCONFIG10_VALUE;
    }

    EDIS;
}

//
// CPU1BROM_setupDeviceSystems - Adjust dividers, setup flash
//                               configurations, flash power up,
//                               and trim PMM/INTOSC/APLL
//
void CPU1BROM_setupDeviceSystems(void)
{
    uint32_t entryAddress;  
    uint16_t flashPowerUpTimeOut;
    
    //
    // Set the divider to /1 before waking up flash
    // (Optimization tip - Could divider setting before M0 partial
    //  stack initialization)
    //
    EALLOW;
    HWREG(CLKCFG_BASE + SYSCTL_O_SYSCLKDIVSEL) = 0x0U;
    EDIS;

    //
    // Set flash PSLEEP
    // (45us pump wakeup = PSLEEP * (1/10MHz) * 2)
    // (30us pump wakeup = PSLEEP * (1/15MHz) * 2)
    //
    Flash_setPumpWakeupTime(FLASH0CTRL_BASE, CPU1_FLASH_15MHZ_PSLEEP);

    //
    // Set flash wait state
    //
    Flash_setWaitstates(FLASH0CTRL_BASE, CPU1_FLASH_15MHZ_RWAIT);

    //
    // Set flash timeout variable
    //
    flashPowerUpTimeOut = CPU1_FLASH_15MHZ_TIMEOUT_VALUE;

    //
    // Set flash bank power modes to active
    //
    Flash_setPumpPowerMode(FLASH0CTRL_BASE, FLASH_PUMP_PWR_ACTIVE);
    Flash_setBankPowerMode(FLASH0CTRL_BASE, FLASH_BANK, FLASH_BANK_PWR_ACTIVE);

    //
    // Wait until Flash Bank and Pump are ready
    //
    while((HWREGH(FLASH0CTRL_BASE + FLASH_O_FBPRDY) & (FLASH_FBPRDY_PUMPRDY | FLASH_FBPRDY_BANKRDY)) !=
          (FLASH_FBPRDY_PUMPRDY | FLASH_FBPRDY_BANKRDY))
    {
        //
        // If ready status is never set (should take ~83us), timeout at 170us
        // will break loop and continue with boot
        //
        if(flashPowerUpTimeOut == 0U)
        {
            break;
        }
        else
        {
            asm(" nop");

            flashPowerUpTimeOut-=1U;
        }
    }

    //
    // Read OTP revision to as check that flash powered up correctly
    //
    HWREAD_OTP_VERSION_FOR_BOOT;

    //
    // Trim PMM
    //
    CPU1BROM_setPMMTrims();

    //
    // Trim INTOSC
    //
    CPU1BROM_setIntOscTrims();

    //
    // Select PLL (APLL or TCI) when key is set
    //
    if(HWREAD_TI_OTP_PLLSEL_KEY == TI_OTP_KEY)
    {
        EALLOW;
        HWREGH(ANALOGSUBSYS_BASE + ASYSCTL_O_PLLSEL) = HWREAD_TI_OTP_PLLSEL_VALUE;
        EDIS;
    }
    
    //
    // CPU1 Patch/Escape Point 6
    //
    entryAddress = CPU1BROM_TI_OTP_ESCAPE_POINT_6;
    if((entryAddress != 0xFFFFFFFFUL) &&
       (entryAddress != 0x00000000UL))
    {
        //
        // If OTP is programmed, then call OTP patch function
        //
        ((void (*)(void))entryAddress)();
    }

    //
    // Configure A-PLL (Trim, Analog Register Config)
    //
    CPU1BROM_configureAPLL();
    
    //
    // Lock APLL Configuration when key is set
    //
    if(HWREAD_TI_OTP_APLLLOCK_KEY == TI_OTP_KEY)
    {
        EALLOW;
        HWREG(ANALOGSUBSYS_BASE + ASYSCTL_O_APLLLOCK) = (((uint32_t)HWREAD_TI_OTP_APLLLOCK_VALUE << 16U) |
                                                         HWREAD_TI_OTP_APLLLOCK_VALUE);
        EDIS;
    }

    //
    // Adjust the PSLEEP for 210MHz
    //
    Flash_setPumpWakeupTime(FLASH0CTRL_BASE, CPU1_FLASH_DEFAULT_PSLEEP);

    //
    // Set Flash wait states for 210MHz
    //
    Flash_setWaitstates(FLASH0CTRL_BASE, CPU1_FLASH_DEFAULT_RWAIT);
    
    //
    // CPU1 Patch/Escape Point 6
    //
    entryAddress = CPU1BROM_TI_OTP_ESCAPE_POINT_6;
    if((entryAddress != 0xFFFFFFFFUL) &&
       (entryAddress != 0x00000000UL))
    {
        //
        // If OTP is programmed, then call OTP patch function
        //
        ((void (*)(void))entryAddress)();
    }
}

//
// CPU1BROM_performDeviceConfiguration - Set device configuration registers 
//                                       from OTP
//
void CPU1BROM_performDeviceConfiguration(void)
{
    uint32_t entryAddress;

    EALLOW;

    //
    // Set PARTIDL
    //
    HWREG(DEVCFG_BASE + SYSCTL_O_PARTIDL) = HWREAD_TI_OTP_PARTID_L;
    HWREG(DEVCFG_BASE + SYSCTL_O_PARTIDH) = HWREAD_TI_OTP_PARTID_H;

    //
    // DCx - Always Enabled
    //
    HWREG(DEVCFG_BASE + SYSCTL_O_DC1) = BROM_DCX_ALWAYS_ENABLED;
    HWREG(DEVCFG_BASE + SYSCTL_O_DC2) = BROM_DCX_ALWAYS_ENABLED;
    HWREG(DEVCFG_BASE + SYSCTL_O_DC3) = BROM_DCX_ALWAYS_ENABLED;
    HWREG(DEVCFG_BASE + SYSCTL_O_DC4) = BROM_DCX_ALWAYS_ENABLED;
    HWREG(DEVCFG_BASE + SYSCTL_O_DC5) = BROM_DCX_ALWAYS_ENABLED;
    HWREG(DEVCFG_BASE + BROM_SYSCTL_O_DC6) = BROM_DCX_ALWAYS_ENABLED;
    HWREG(DEVCFG_BASE + SYSCTL_O_DC7) = BROM_DCX_ALWAYS_ENABLED;
    HWREG(DEVCFG_BASE + SYSCTL_O_DC8) = BROM_DCX_ALWAYS_ENABLED;
    HWREG(DEVCFG_BASE + SYSCTL_O_DC9) = BROM_DCX_ALWAYS_ENABLED;
    HWREG(DEVCFG_BASE + SYSCTL_O_DC10) = BROM_DCX_ALWAYS_ENABLED;
    HWREG(DEVCFG_BASE + SYSCTL_O_DC12) = BROM_DCX_ALWAYS_ENABLED;
    HWREG(DEVCFG_BASE + BROM_SYSCTL_O_DC13) = BROM_DCX_ALWAYS_ENABLED;
    HWREG(DEVCFG_BASE + SYSCTL_O_DC14) = BROM_DCX_ALWAYS_ENABLED;
    HWREG(DEVCFG_BASE + SYSCTL_O_DC15) = BROM_DCX_ALWAYS_ENABLED;
    HWREG(DEVCFG_BASE + BROM_SYSCTL_O_DC16) = BROM_DCX_ALWAYS_ENABLED;
    HWREG(DEVCFG_BASE + SYSCTL_O_DC17) = BROM_DCX_ALWAYS_ENABLED;
    HWREG(DEVCFG_BASE + SYSCTL_O_DC18) = BROM_DCX_ALWAYS_ENABLED;
    HWREG(DEVCFG_BASE + SYSCTL_O_DC22) = BROM_DCX_ALWAYS_ENABLED;
    HWREG(DEVCFG_BASE + BROM_SYSCTL_O_DC23) = BROM_DCX_ALWAYS_ENABLED;
    HWREG(DEVCFG_BASE + SYSCTL_O_DC24) = BROM_DCX_ALWAYS_ENABLED;
    HWREG(DEVCFG_BASE + SYSCTL_O_DC25) = BROM_DCX_ALWAYS_ENABLED;
    HWREG(DEVCFG_BASE + SYSCTL_O_DC27) = BROM_DCX_ALWAYS_ENABLED;

    HWREG(DEVCFG_BASE + SYSCTL_O_CPU1ROM_DC3) = BROM_DCX_ALWAYS_ENABLED;
    HWREG(DEVCFG_BASE + SYSCTL_O_CPU1ROM_DC4) = BROM_DCX_ALWAYS_ENABLED;

    HWREG(DEVCFG_BASE + SYSCTL_O_CPU2ROM_DC3) = BROM_DCX_ALWAYS_ENABLED;
    HWREG(DEVCFG_BASE + SYSCTL_O_CPU2ROM_DC4) = BROM_DCX_ALWAYS_ENABLED;

    //
    // DCx - Configurable
    //
    HWREG(DEVCFG_BASE + SYSCTL_O_DC0) = BROM_DCX_ENABLE_HIGH | HWREAD_TI_OTP_REG_DC00;
    HWREG(DEVCFG_BASE + SYSCTL_O_DC11) = BROM_DCX_ENABLE_HIGH | HWREAD_TI_OTP_REG_DC11;
    HWREG(DEVCFG_BASE + SYSCTL_O_DC19) = BROM_DCX_ENABLE_HIGH | HWREAD_TI_OTP_REG_DC19;
    HWREG(DEVCFG_BASE + SYSCTL_O_DC20) = BROM_DCX_ENABLE_HIGH | HWREAD_TI_OTP_REG_DC20;
    HWREG(DEVCFG_BASE + SYSCTL_O_DC21) = BROM_DCX_ENABLE_HIGH | HWREAD_TI_OTP_REG_DC21;
    HWREG(DEVCFG_BASE + SYSCTL_O_DC26) = BROM_DCX_ENABLE_HIGH | HWREAD_TI_OTP_REG_DC26;
    HWREG(DEVCFG_BASE + SYSCTL_O_PERCNF1) = BROM_DCX_ENABLE_HIGH | HWREAD_TI_OTP_REG_PERCNF1;
    HWREG(DEVCFG_BASE + SYSCTL_O_CPU1ROM_DC1) = BROM_DCX_ENABLE_HIGH | HWREAD_TI_OTP_CPU1ROM_DC1;
    HWREG(DEVCFG_BASE + SYSCTL_O_CPU1ROM_DC2) = BROM_DCX_ENABLE_HIGH | HWREAD_TI_OTP_CPU1ROM_DC2;
    HWREG(DEVCFG_BASE + SYSCTL_O_CPU2ROM_DC1) = BROM_DCX_ENABLE_HIGH | HWREAD_TI_OTP_CPU2ROM_DC1;
    HWREG(DEVCFG_BASE + SYSCTL_O_CPU2ROM_DC2) = BROM_DCX_ENABLE_HIGH | HWREAD_TI_OTP_CPU2ROM_DC2;

    //
    // CPU1 Patch/Escape Point 7
    //
    entryAddress = CPU1BROM_TI_OTP_ESCAPE_POINT_7;
    if((entryAddress != 0xFFFFFFFFUL) &&
       (entryAddress != 0x00000000UL))
    {
        //
        // If OTP is programmed, then call OTP patch function
        //
        ((void (*)(void))entryAddress)();
    }    
    
    //
    // Lock DCx registers
    //
    HWREGH(DEVCFG_BASE + SYSCTL_O_DEVCFGLOCK2) |= SYSCTL_DEVCFGLOCK2_DC_PERCNF_PARTID;

    EDIS;
}

//
// CPU1BROM_enableUnbondedPullupsOn176Pin - Enable pullups for the unbonded
//                                          GPIOs on the 176 package.
//
// These below GPIOs are available on the package.
// GPIOs     Grp Bits
// 95        C   31
// 96-98     D   2:0
// 100-127   D   31:4
// 128-132   E   4:0
// 134-159   E   31:6
// 160-168   F   8:0
//
static inline void CPU1BROM_enableUnbondedPullupsOn176Pin(void)
{
    //
    // Write 0 to unbonded pin in order to pull-up.
    // if an available pin is already pulled-up, then the pin stays pulled-up.
    // Logical AND with 0 does both of these.
    //
    EALLOW;
    HWREG(GPIOCTRL_BASE + GPIO_O_GPCPUD) &= 0x7FFFFFFFU;    //95
    HWREG(GPIOCTRL_BASE + GPIO_O_GPDPUD) &= 0x00000008U;    //96-98,100-127 
    HWREG(GPIOCTRL_BASE + GPIO_O_GPEPUD) &= 0x00000020U;    //128-132,134-159  
    HWREG(GPIOCTRL_BASE + GPIO_O_GPFPUD) &= 0xFFFFFE00U;    //160-168     
    EDIS;
}

//
// CPU1BROM_enableUnbondedGpioPullups - Enable unbonded IO pullups for
//                                      device packages
//
void CPU1BROM_enableUnbondedGpioPullups(void)
{
    //
    // Get package pin count
    //
    uint32_t pin_count = (uint32_t)((uint32_t)(HWREAD_TI_OTP_PARTID_L & 0x00000700UL) >> 8U);

    //
    // 6 = 176 pin package
    // 7 = 337 pin package
    //
    if(pin_count == 6U)
    {
        CPU1BROM_enableUnbondedPullupsOn176Pin();
    }
    else
    {
        //
        // 337 pin package - No action
        //
    }
}

//
// CPU1BROM_startSystemBoot - CPU1 System Initialization procedure and boot
//                            selection
//
uint32_t CPU1BROM_startSystemBoot(void)
{
    uint32_t entryAddress = 0xFFFFFFFFUL;

    //
    // On POR or XRS reset, init boot status variable
    // (Status is non-volatile on any other reset and up to user to clear)
    //
    if((HWREG(CPUSYS_BASE + SYSCTL_O_RESC) & 
        (SYSCTL_RESC_POR | SYSCTL_RESC_XRSN)) != 0U)
    {
        CPU1BROM_bootStatus = 0U;
    }

    //
    // On POR - Init PBIST status
    // (Retain status on any other reset)
    //
    if((HWREG(CPUSYS_BASE + SYSCTL_O_RESC) &
        SYSCTL_RESC_POR) == SYSCTL_RESC_POR)
    {
        CPU1BROM_pbistStatus = 0U;
    }

    //
    // Init boot mode selection
    //
    CPU1BROM_bootMode = 0xFFFFFFFFUL;

    //
    // Update boot status - Boot has started
    //
    CPU1BROM_bootStatus |= CPU1_BOOTROM_BOOTSTS_SYSTEM_START_BOOT;

    //
    // Initialize iTrap address
    //
    CPU1BROM_itrapAddress = 0xFFFFFFFFUL;

    //
    // Initialize NMI Status
    //
    CPU1BROM_nmiStatus = 0U;

    //
    // CPU1 Patch/Escape Point 2
    //
    entryAddress = CPU1BROM_TI_OTP_ESCAPE_POINT_2;
    if((entryAddress != 0xFFFFFFFFUL) &&
       (entryAddress != 0x00000000UL))
    {
        //
        // If OTP is programmed, then call OTP patch function
        //
        ((void (*)(void))entryAddress)();
    }

    //
    // Enable writing to the EALLOW protected registers
    //
    EALLOW;
       
    //
    // Enable NMI
    //
    HWREGH(NMI_BASE + NMI_O_CFG) = NMI_CFG_NMIE;

    //
    // Disable writing to the EALLOW protected registers
    //
    EDIS;

    //
    // Initialize DCSM
    //
    CPU1BROM_initDCSM();

    //
    // Capture any single bit errors after DCSM init
    // If the below addresses are valid then user has to
    // debug these further
    //
    CPU1BROM_flashSingleBitError_lowAddress =
            Flash_getSingleBitErrorAddressLow(FLASH0ECC_BASE);
    CPU1BROM_flashSingleBitError_highAddress =
            Flash_getSingleBitErrorAddressHigh(FLASH0ECC_BASE);
            
    //
    // Update boot status - DCSM init is complete
    //
    CPU1BROM_bootStatus |= CPU1_BOOTROM_DCSM_INIT_COMPLETE;

    //
    // CPU1 Patch/Escape Point 2
    //
    entryAddress = CPU1BROM_TI_OTP_ESCAPE_POINT_2;
    if((entryAddress != 0xFFFFFFFFUL) &&
       (entryAddress != 0x00000000UL))
    {
        //
        // If OTP is programmed, then call OTP patch function
        //
        ((void (*)(void))entryAddress)();
    }

    //
    // On POR only - Check Z2 or Z1 GPREG2 key to determine
    // whether to run PBIST memory test
    // (Z2 takes priority when programmed)
    //
    if((HWREG(CPUSYS_BASE + SYSCTL_O_RESC) & ((uint32_t)SYSCTL_RESC_POR)) ==
       SYSCTL_RESC_POR)
    {
        //
        // Z2 OTP - Check for Key
        //
        if(HWREAD_Z2_OTP_BOOT_GPREG2_KEY == GPREG2_KEY)
        {
            //
            // CPU1 Patch/Escape Point 3
            //
            entryAddress = CPU1BROM_TI_OTP_ESCAPE_POINT_3;
            if((entryAddress != 0xFFFFFFFFUL) &&
               (entryAddress != 0x00000000UL))
            {
                //
                // If OTP is programmed, then call OTP patch function
                //
                ((void (*)(void))entryAddress)();
            }

            //
            // Call Boot ROM checksum routine to check CRC on bootROM (unsecure ROM only)
            // If checksum fails - skip PBIST and continue to boot.
            // Call PBIST only if user has asked for it to RUN.
            //
            if((HWREAD_Z2_OTP_BOOT_GPREG2_PBIST_CONFIG == GPREG2_PBIST_PLL_ENABLE_HIGH_SPEED) ||
               (HWREAD_Z2_OTP_BOOT_GPREG2_PBIST_CONFIG == GPREG2_PBIST_PLL_ENABLE_MED_SPEED) ||
               (HWREAD_Z2_OTP_BOOT_GPREG2_PBIST_CONFIG == GPREG2_PBIST_PLL_ENABLE_LOW_SPEED) ||
               (HWREAD_Z2_OTP_BOOT_GPREG2_PBIST_CONFIG == GPREG2_PBIST_PLL_DISABLED))
            {
                uint16_t pllStatus = BROM_PLL_ENABLE_SUCCESS;

                //
                // Check GS RAMs to verify they have completed initialization, else
                // wait ~1500 cycles to guarantee RAM init is complete
                //
                if(HWREG(MEMCFG_BASE + MEMCFG_O_GSXINITDONE) == RAM_GSX_NOT_DONE)
                {
                    asm(" MOV    @T,#0x5DC ");
                    asm(" RPT    @T \
                          || NOP ");
                }

                //
                // Lock PLL based on GPREG2 configuration
                //
                if(HWREAD_Z2_OTP_BOOT_GPREG2_PBIST_CONFIG == GPREG2_PBIST_PLL_ENABLE_HIGH_SPEED)
                {
                    //
                    // 110MHz SYSPLL and use to clock CM
                    //
                    uint16_t multiplier = 44U;
                    uint16_t divider = 4U;
                    pllStatus = CPU1BROM_enableSysPLL(multiplier, divider);
                }
                else if(HWREAD_Z2_OTP_BOOT_GPREG2_PBIST_CONFIG == GPREG2_PBIST_PLL_ENABLE_MED_SPEED)
                {
                    //
                    // 80MHz SYSPLL and use to clock CM
                    //
                    uint16_t multiplier = 32U;
                    uint16_t divider = 4U;
                    pllStatus = CPU1BROM_enableSysPLL(multiplier, divider);
                }
                else if(HWREAD_Z2_OTP_BOOT_GPREG2_PBIST_CONFIG == GPREG2_PBIST_PLL_ENABLE_LOW_SPEED)
                {
                    //
                    // 60MHz SYSPLL and use to clock CM
                    //
                    uint16_t multiplier = 24U;
                    uint16_t divider = 4U;
                    pllStatus = CPU1BROM_enableSysPLL(multiplier, divider);
                }
                else //if(HWREAD_Z2_OTP_BOOT_GPREG2_PBIST_CONFIG == GPREG2_PBIST_PLL_DISABLED)
                {
                    //
                    // No PLL
                    //
                }

                //
                // Enable CM clock to run off SYSCLK /1
                //
                EALLOW;
                HWREGH(CLKCFG_BASE + SYSCTL_O_CMCLKCTL) = ((HWREGH(CLKCFG_BASE + SYSCTL_O_CMCLKCTL) &
                                                            ~BROM_CMCLKCTL_MASK) | 1U);
                EDIS;

                //
                // Skip PBIST if configured to use PLL and PLL enable fails
                // do ROM checksum here, if fail - skip below
                //
                if((pllStatus == BROM_PLL_ENABLE_SUCCESS) &&
                   (verify_pbist_checksum_onROM() == PBIST_CHECKSUM_SUCCESS))
                {
                    //
                    // PBIST Memory Test
                    //
                    CPU1BROM_pbistStatus = PBIST_PORMemoryTest();

                    //
                    // PBIST function return here using RPC and reinitialize RPC
                    //
                    asm(" .ref ExitPBISTLoc");
                    asm(" PUSH XAR7");
                    asm(" MOVL XAR7, #ExitPBISTLoc");
                    asm(" PUSH XAR7");
                    asm(" POP RPC");
                    asm(" POP XAR7");

                    //
                    // Reinitialize Variables lost during PBIST RAMINIT
                    //
                    CPU1BROM_bootMode = 0xFFFFFFFFUL;
                    CPU1BROM_itrapAddress = 0xFFFFFFFFUL;

                    //
                    // Set boot status
                    //
                    CPU1BROM_bootStatus = (CPU1_BOOTROM_BOOTSTS_SYSTEM_START_BOOT |
                                           CPU1_BOOTROM_DCSM_INIT_COMPLETE |
                                           CPU1_BOOTROM_RAM_INIT_COMPLETE |
                                           CPU1_BOOTROM_POR_MEM_TEST_COMPLETE);

                    //
                    // Re-init the single bit error address status.
                    //
                    CPU1BROM_flashSingleBitError_lowAddress =
                            Flash_getSingleBitErrorAddressLow(FLASH0ECC_BASE);
                    CPU1BROM_flashSingleBitError_highAddress =
                            Flash_getSingleBitErrorAddressHigh(FLASH0ECC_BASE);
                }

                //
                // Disable and power down PLL
                //

                //
                // Turn off PLL clock
                //
                EALLOW;
                HWREGH(CLKCFG_BASE + SYSCTL_O_SYSPLLCTL1) &= ~SYSCTL_SYSPLLCTL1_PLLCLKEN;

                //
                // Delay 25 cycles
                //
                asm(" MOV    @T,#25 ");
                asm(" RPT    @T \
                      || NOP ");

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

                HWREGH(CLKCFG_BASE + SYSCTL_O_CMCLKCTL) = ((HWREGH(CLKCFG_BASE + SYSCTL_O_CMCLKCTL) &
                                                            ~BROM_CMCLKCTL_MASK) | 0x6U);
                EDIS;
            }
        }
        else
        {
            //
            // Z1 OTP - Check for key
            //
            if(HWREAD_Z1_OTP_BOOT_GPREG2_KEY == GPREG2_KEY)
            {
                //
                // CPU1 Patch/Escape Point 3
                //
                entryAddress = CPU1BROM_TI_OTP_ESCAPE_POINT_3;
                if((entryAddress != 0xFFFFFFFFUL) &&
                   (entryAddress != 0x00000000UL))
                {
                    //
                    // If OTP is programmed, then call OTP patch function
                    //
                    ((void (*)(void))entryAddress)();
                }

                //
                // Call Boot ROM checksum routine to check CRC on bootROM (unsecure ROM only)
                // If checksum fails - skip PBIST and continue to boot.
                // Call PBIST only if user has asked for it to RUN.
                //
                if((HWREAD_Z1_OTP_BOOT_GPREG2_PBIST_CONFIG == GPREG2_PBIST_PLL_ENABLE_HIGH_SPEED) ||
                   (HWREAD_Z1_OTP_BOOT_GPREG2_PBIST_CONFIG == GPREG2_PBIST_PLL_ENABLE_MED_SPEED) ||
                   (HWREAD_Z1_OTP_BOOT_GPREG2_PBIST_CONFIG == GPREG2_PBIST_PLL_ENABLE_LOW_SPEED) ||
                   (HWREAD_Z1_OTP_BOOT_GPREG2_PBIST_CONFIG == GPREG2_PBIST_PLL_DISABLED))
                {
                    uint16_t pllStatus = BROM_PLL_ENABLE_SUCCESS;

                    //
                    // Check GS RAMs to verify they have completed initialization, else
                    // wait ~1500 cycles to guarantee RAM init is complete
                    //
                    if(HWREG(MEMCFG_BASE + MEMCFG_O_GSXINITDONE) == RAM_GSX_NOT_DONE)
                    {
                        asm(" MOV    @T,#0x5DC ");
                        asm(" RPT    @T \
                              || NOP ");
                    }

                    //
                    // Lock PLL based on GPREG2 configuration
                    //
                    if(HWREAD_Z1_OTP_BOOT_GPREG2_PBIST_CONFIG == GPREG2_PBIST_PLL_ENABLE_HIGH_SPEED)
                    {
                        //
                        // 110MHz SYSPLL and use to clock CM
                        //
                        uint16_t multiplier = 44U;
                        uint16_t divider = 4U;
                        pllStatus = CPU1BROM_enableSysPLL(multiplier, divider);
                    }
                    else if(HWREAD_Z1_OTP_BOOT_GPREG2_PBIST_CONFIG == GPREG2_PBIST_PLL_ENABLE_MED_SPEED)
                    {
                        //
                        // 80MHz SYSPLL and use to clock CM
                        //
                        uint16_t multiplier = 32U;
                        uint16_t divider = 4U;
                        pllStatus = CPU1BROM_enableSysPLL(multiplier, divider);
                    }
                    else if(HWREAD_Z1_OTP_BOOT_GPREG2_PBIST_CONFIG == GPREG2_PBIST_PLL_ENABLE_LOW_SPEED)
                    {
                        //
                        // 60MHz SYSPLL and use to clock CM
                        //
                        uint16_t multiplier = 24U;
                        uint16_t divider = 4U;
                        pllStatus = CPU1BROM_enableSysPLL(multiplier, divider);
                    }
                    else //if(HWREAD_Z1_OTP_BOOT_GPREG2_PBIST_CONFIG == GPREG2_PBIST_PLL_DISABLED)
                    {
                        //
                        // No PLL
                        //
                    }

                    //
                    // Enable CM clock to run off SYSCLK /1
                    //
                    EALLOW;
                    HWREGH(CLKCFG_BASE + SYSCTL_O_CMCLKCTL) = ((HWREGH(CLKCFG_BASE + SYSCTL_O_CMCLKCTL) &
                                                                ~BROM_CMCLKCTL_MASK) | 1U);
                    EDIS;

                    //
                    // Skip PBIST if configured to use PLL and PLL enable fails
                    // do ROM checksum here, if fail - skip below
                    //
                    if((pllStatus == BROM_PLL_ENABLE_SUCCESS) &&
                       (verify_pbist_checksum_onROM() == PBIST_CHECKSUM_SUCCESS))
                    {
                        //
                        // PBIST Memory Test
                        //
                        CPU1BROM_pbistStatus = PBIST_PORMemoryTest();

                        //
                        // PBIST function return here using RPC and reinitialize RPC
                        //
                        asm(" .ref ExitPBISTLoc");
                        asm(" PUSH XAR7");
                        asm(" MOVL XAR7, #ExitPBISTLoc");
                        asm(" PUSH XAR7");
                        asm(" POP RPC");
                        asm(" POP XAR7");

                        //
                        // Reinitialize Variables lost during PBIST RAMINIT
                        //
                        CPU1BROM_bootMode = 0xFFFFFFFFUL;
                        CPU1BROM_itrapAddress = 0xFFFFFFFFUL;

                        //
                        // Set boot status
                        //
                        CPU1BROM_bootStatus = (CPU1_BOOTROM_BOOTSTS_SYSTEM_START_BOOT |
                                               CPU1_BOOTROM_DCSM_INIT_COMPLETE |
                                               CPU1_BOOTROM_RAM_INIT_COMPLETE |
                                               CPU1_BOOTROM_POR_MEM_TEST_COMPLETE);

                        //
                        // Re-init the single bit error address status.
                        //
                        CPU1BROM_flashSingleBitError_lowAddress =
                                Flash_getSingleBitErrorAddressLow(FLASH0ECC_BASE);
                        CPU1BROM_flashSingleBitError_highAddress =
                                Flash_getSingleBitErrorAddressHigh(FLASH0ECC_BASE);
                    }

                    //
                    // Disable and power down PLL
                    //

                    //
                    // Turn off PLL clock
                    //
                    EALLOW;
                    HWREGH(CLKCFG_BASE + SYSCTL_O_SYSPLLCTL1) &= ~SYSCTL_SYSPLLCTL1_PLLCLKEN;

                    //
                    // Delay 25 cycles
                    //
                    asm(" MOV    @T,#25 ");
                    asm(" RPT    @T \
                          || NOP ");

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

                    HWREGH(CLKCFG_BASE + SYSCTL_O_CMCLKCTL) = ((HWREGH(CLKCFG_BASE + SYSCTL_O_CMCLKCTL) &
                                                                ~BROM_CMCLKCTL_MASK) | 0x6U);
                    EDIS;
                }
            }
        }
    }

    //
    // CPU1 Patch/Escape Point 3
    //
    entryAddress = CPU1BROM_TI_OTP_ESCAPE_POINT_3;
    if((entryAddress != 0xFFFFFFFFUL) &&
       (entryAddress != 0x00000000UL))
    {
        //
        // If OTP is programmed, then call OTP patch function
        //
        ((void (*)(void))entryAddress)();
    }

    //
    // Enable unbonded GPIO pullups
    //
    CPU1BROM_enableUnbondedGpioPullups();

    //
    // Perform Analog device calibration
    //
    if(HWREAD_TI_OTP_DEVCAL_KEY == TI_OTP_KEY)
    {
        (*CBROM_DEVCAL)();
    }

    //
    // On POR 
    //  - Handle POR/XRSn RESC bits so that bootROM would not go into
    //    a unwanted reset handling if it got reset for some reason    
    //  - Check if RAM init is complete, and update boot status.
    //
    if((HWREG(CPUSYS_BASE + SYSCTL_O_RESC) & ((uint32_t)SYSCTL_RESC_POR)) == 
       SYSCTL_RESC_POR)
    {        
        //
        // Clear POR and XRSn
        //
        SysCtl_clearResetCause(SYSCTL_RESC_POR | SYSCTL_RESC_XRSN);
        CPU1BROM_bootStatus |= (uint32_t)((uint32_t)CPU1_BOOTROM_HANDLED_XRSN | 
                                          (uint32_t)CPU1_BOOTROM_HANDLED_POR);
        
        //
        // Check GS RAMs to verify they have completed initialization
        //
        if(HWREG(MEMCFG_BASE + MEMCFG_O_GSXINITDONE) != RAM_GSX_NOT_DONE)
        {
            //
            // Update boot status - RAM Init complete
            //
            CPU1BROM_bootStatus |= CPU1_BOOTROM_RAM_INIT_COMPLETE; 
        }       
    }

    //
    // On XRS - Clear RESC bits so that bootROM would not go into
    // a unwanted reset handling if it got reset for some reason
    //
    if((HWREG(CPUSYS_BASE + SYSCTL_O_RESC) & ((uint32_t)SYSCTL_RESC_XRSN)) == 
       SYSCTL_RESC_XRSN)
    {
        SysCtl_clearResetCause(SYSCTL_RESC_XRSN);
        CPU1BROM_bootStatus |= (uint32_t)(CPU1_BOOTROM_HANDLED_XRSN);
    }

    //
    // Update boot status - Reset cause clearing complete
    //
    CPU1BROM_bootStatus |= CPU1_BOOTROM_RESC_HANDLED;

    //
    // CPU1 Patch/Escape Point 4
    //
    entryAddress = CPU1BROM_TI_OTP_ESCAPE_POINT_4;
    if((entryAddress != 0xFFFFFFFFUL) &&
       (entryAddress != 0x00000000UL))
    {
        //
        // If OTP is programmed, then call OTP patch function
        //
        ((void (*)(void))entryAddress)();
    }

    //
    // Get boot mode selected
    //
    CPU1BROM_bootMode = CPU1BROM_selectBootMode();

    //
    // CPU1 Patch/Escape Point 4
    //
    entryAddress = CPU1BROM_TI_OTP_ESCAPE_POINT_4;
    if((entryAddress != 0xFFFFFFFFUL) &&
       (entryAddress != 0x00000000UL))
    {
        //
        // If OTP is programmed, then call OTP patch function
        //
        ((void (*)(void))entryAddress)();
    }

    //
    // Update boot status - Clear booting status field before setting boot mode status
    //
    CPU1BROM_bootStatus &= ~CPU1_BOOTROM_BOOTSTS_BOOT_MASK;

    //
    // Run selected boot mode
    //
    switch(CPU1BROM_bootMode)
    {
        case FLASH_BOOT:
            entryAddress = FLASH_ENTRY_POINT;
            CPU1BROM_bootStatus |= CPU1_BOOTROM_BOOTSTS_IN_FLASH_BOOT;
            break;

        case FLASH_BOOT_ALT1:
            entryAddress = FLASH_ENTRY_POINT_ALT1;
            CPU1BROM_bootStatus |= CPU1_BOOTROM_BOOTSTS_IN_FLASH_BOOT;
            break;

        case FLASH_BOOT_ALT2:
            entryAddress = FLASH_ENTRY_POINT_ALT2;
            CPU1BROM_bootStatus |= CPU1_BOOTROM_BOOTSTS_IN_FLASH_BOOT;
            break;

        case FLASH_BOOT_ALT3:
            entryAddress = FLASH_ENTRY_POINT_ALT3;
            CPU1BROM_bootStatus |= CPU1_BOOTROM_BOOTSTS_IN_FLASH_BOOT;
            break;

        case SECURE_FLASH_BOOT:
            entryAddress = FLASH_ENTRY_POINT;
            CPU1BROM_bootStatus |= CPU1_BOOTROM_BOOTSTS_IN_SECURE_FLASH_BOOT;
            CPU1BROM_verifySecureFlash(entryAddress);
            break;

        case SECURE_FLASH_BOOT_ALT1:
            entryAddress = FLASH_ENTRY_POINT_ALT1;
            CPU1BROM_bootStatus |= CPU1_BOOTROM_BOOTSTS_IN_SECURE_FLASH_BOOT;
            CPU1BROM_verifySecureFlash(entryAddress);
            break;

        case SECURE_FLASH_BOOT_ALT2:
            entryAddress = FLASH_ENTRY_POINT_ALT2;
            CPU1BROM_bootStatus |= CPU1_BOOTROM_BOOTSTS_IN_SECURE_FLASH_BOOT;
            CPU1BROM_verifySecureFlash(entryAddress);
            break;

        case SECURE_FLASH_BOOT_ALT3:
            entryAddress = FLASH_ENTRY_POINT_ALT3;
            CPU1BROM_bootStatus |= CPU1_BOOTROM_BOOTSTS_IN_SECURE_FLASH_BOOT;
            CPU1BROM_verifySecureFlash(entryAddress);
            break;

        case RAM_BOOT:
            entryAddress = RAM_ENTRY_POINT;
            CPU1BROM_bootStatus |= CPU1_BOOTROM_BOOTSTS_IN_RAM_BOOT;
            break;

        case WAIT_BOOT:
        case WAIT_BOOT_ALT1:
            CPU1BROM_bootStatus |= CPU1_BOOTROM_BOOTSTS_IN_WAIT_BOOT;
            break;

        case PARALLEL_BOOT:
            CPU1BROM_bootStatus |= CPU1_BOOTROM_BOOTSTS_IN_PARALLEL_BOOT;
            entryAddress = Parallel_Boot();
            break;

        case SCI_BOOT:
        case SCI_BOOT_ALT1:
        case SCI_BOOT_ALT2:
        case SCI_BOOT_ALT3:
        case SCI_BOOT_ALT4:
        case SCI_BOOT_ALT5:
        case SCI_BOOT_ALT6:
            CPU1BROM_bootStatus |= CPU1_BOOTROM_BOOTSTS_IN_SCI_BOOT;
            entryAddress = SCI_Boot(CPU1BROM_bootMode);
            break;

        case CAN_BOOT:
        case CAN_BOOT_ALT1:
        case CAN_BOOT_ALT2:
        case CAN_BOOT_ALT3:
        case CAN_BOOT_ALT4:
        case CAN_BOOT_ALT5:
        case CAN_BOOT_SENDTEST:
        case CAN_BOOT_ALT1_SENDTEST:
        case CAN_BOOT_ALT2_SENDTEST:
        case CAN_BOOT_ALT3_SENDTEST:
        case CAN_BOOT_ALT4_SENDTEST:
        case CAN_BOOT_ALT5_SENDTEST:
            CPU1BROM_bootStatus |= CPU1_BOOTROM_BOOTSTS_IN_CAN_BOOT;
            entryAddress = DCAN_Boot(CPU1BROM_bootMode,
                                     CAN_BOOT_DEFAULT_BIT_TIMING,
                                     CAN_BOOT_USE_XTAL);
            break;

        case SPI_MASTER_BOOT:
        case SPI_MASTER_BOOT_ALT1:
        case SPI_MASTER_BOOT_ALT2:
        case SPI_MASTER_BOOT_ALT3:
        case SPI_MASTER_BOOT_ALT4:
            CPU1BROM_bootStatus |= CPU1_BOOTROM_BOOTSTS_IN_SPI_BOOT;
            entryAddress = SPI_Boot(CPU1BROM_bootMode);
            break;

        case I2C_MASTER_BOOT:
        case I2C_MASTER_BOOT_ALT1:
        case I2C_MASTER_BOOT_ALT2:
        case I2C_MASTER_BOOT_ALT3:
        case I2C_MASTER_BOOT_ALT4:
            CPU1BROM_bootStatus |= CPU1_BOOTROM_BOOTSTS_IN_I2C_BOOT;
            entryAddress = I2C_Boot(CPU1BROM_bootMode);
            break;

        case USB_BOOT:
            CPU1BROM_bootStatus |= CPU1_BOOTROM_BOOTSTS_IN_USB_BOOT;
            entryAddress = USB_Boot(CPU1BROM_bootMode,
                                    USB_BOOT_ENABLE_PIE_INIT);
            break;

        default:
            //
            // Check if debugger is connected
            //
            if(((uint32_t)HWREG(CPUSYS_BASE + SYSCTL_O_RESC) &
                (uint32_t)SYSCTL_RESC_TRSTN_PIN_STATUS) == SYSCTL_RESC_TRSTN_PIN_STATUS)
            {
                //
                // CPU1 Patch/Escape Point 5
                //
                entryAddress = CPU1BROM_TI_OTP_ESCAPE_POINT_5;
                if((entryAddress != 0xFFFFFFFFUL) &&
                   (entryAddress != 0x00000000UL))
                {
                    //
                    // If OTP is programmed, then call OTP patch function
                    //
                    ((void (*)(void))entryAddress)();
                }
                CPU1BROM_bootMode = WAIT_BOOT;
                CPU1BROM_bootStatus |= CPU1_BOOTROM_BOOTSTS_IN_WAIT_BOOT;
            }
            else
            {
                //
                // CPU5 Patch/Escape Point 5
                //
                entryAddress = CPU1BROM_TI_OTP_ESCAPE_POINT_5;
                if((entryAddress != 0xFFFFFFFFUL) &&
                   (entryAddress != 0x00000000UL))
                {
                    //
                    // If OTP is programmed, then call OTP patch function
                    //
                    ((void (*)(void))entryAddress)();
                }

                CPU1BROM_bootMode = FLASH_BOOT;
                entryAddress = FLASH_ENTRY_POINT;
                CPU1BROM_bootStatus |= CPU1_BOOTROM_BOOTSTS_IN_FLASH_BOOT;
            }
            break;
    }
    //
    // Update boot status - Boot Complete
    //
    CPU1BROM_bootStatus |= CPU1_BOOTROM_BOOT_COMPLETE;

    //
    // Enter specified wait boot or enable watchdog, then branch to address
    //
    if(CPU1BROM_bootMode == WAIT_BOOT)
    {
        SysCtl_enableWatchdog();
        for(;;)
        {
        }
    }
    else if(CPU1BROM_bootMode == WAIT_BOOT_ALT1)
    {
        for(;;)
        {
        }
    }
    else
    {
        SysCtl_enableWatchdog();
        return(entryAddress);
    }
}

//
// Verify Secure Flash for Boot
//
// Param - entryAddress is the flash memory entry address that 
//         will be branched to
//
// This function runs the secure flash verification procedure.  
// A CMAC calculation is run on  the 16KB of  flash, starting at the 
// entry address provided. If the CMAC calculation passes, this function  
// returns and the boot process continues to branch to entry point. 
// If the CMAC calculation fails, this  function either halts debugger
// or enables watchdog to reset device.
//
// Return - None
//
void CPU1BROM_verifySecureFlash(uint32_t entryAddress)
{
    uint32_t escapeEntryAddress = 0xFFFFFFFFUL;

    //
    // CPU1 Patch/Escape Point 9
    //
    escapeEntryAddress = CPU1BROM_TI_OTP_ESCAPE_POINT_9;
    if((escapeEntryAddress != 0xFFFFFFFFUL) &&
       (escapeEntryAddress != 0x00000000UL))
    {
        //
        // If OTP is programmed, then call OTP patch function
        //
        ((void (*)(void))escapeEntryAddress)();
    }    
    
    //
    // Calculate CMAC 
    // - Calculation starts at entryAddress
    // - End address of calculation is entryAddress + 16KB (8192 words)
    //   (CMAC is calculated from start address to (end address - 1)
    // - Golden CMAC signature is always stored at entryAddress + 2 words
    //   (Signature will be considered all 1s in calculation)
    //       

    //
    // DEBUG ONLY - Using standard test vectors/cases (1 to 10)
    //
    //if(CPU1BROM_calculateCMAC(entryAddress, (entryAddress + HWREG(entryAddress - 0xA)),(entryAddress - 0x8)) != 0x0U)

    //
    // DEBUG ONLY - Using embedded golden sig test vectors/cases (1 to 4)
    //
    //if(CPU1BROM_calculateCMAC(entryAddress, (entryAddress + HWREG(entryAddress - 0x2)),(entryAddress + HWREG(entryAddress - 0x4))) != 0x0U)

    if(CPU1BROM_calculateCMAC(entryAddress, (entryAddress + 0x2000U),
                              (entryAddress + 0x2U)) != 0x0U)
    {
        //
        // CMAC failed, halt if using debugger, else reset device
        //
        asm("   ESTOP0");

        SysCtl_enableWatchdog();
    	for(;;)
    	{
    	}
    }

    //
    // CMAC passed, return and boot to flash
    //
}

//
// End of file
//

