//###########################################################################
//
// FILE:    cpu2brom_system_boot.c
//
// TITLE:   CPU2 System Boot
//
// CPU2 System Initialization and associated functions
//
//###########################################################################
// $TI Release: $
// $Release Date:  $
//###########################################################################

//
// Included Files
//
#include "cpu2bootrom.h"

//
// Globals
//
#pragma DATA_SECTION(CPU2BROM_bootMode, "UserBootModeVariable");
uint32_t CPU2BROM_bootMode;

#pragma DATA_SECTION(CPU2BROM_bootStatus, "BootStatusVariable");
uint32_t CPU2BROM_bootStatus;

extern uint32_t CPU2BROM_itrapAddress;

//
// Function Prototypes
//
void CPU2BROM_waitForCommand(void);
uint32_t CPU2BROM_runSelectedBootMode(void);
uint32_t CPU2BROM_verifySecureFlash(uint32_t entryAddress);

//
// CPU2BROM_verifyBootCommand - Verify that the IPCBOOTMODE values for key,
//                              IPC message RAM copy length, and device
//                              frequency are set appropriately.
//
//                              If values are invalid, IPC is sent to CPU1 and
//                              CPU2 waits for reset.
//
void CPU2BROM_verifyBootCommand(void)
{
    //
    // Important: Don't use local variables in this function
    //

    //
    // Wait for CPU1 to set flag 0 to signal the IPCBOOTMODE is ready.
    // Set status to indicate CPU2 is waiting and clear after IPCFLG set.
    //
    HWREG(IPC_CPU2TOCPU1_BASE + IPC_O_CPU2TOCPU1IPCBOOTSTS) = CPU2_BOOTROM_BOOTSTS_WAITING_FOR_FLAG;
    while((HWREG(IPC_CPU2TOCPU1_BASE + IPC_O_CPU1TOCPU2IPCSTS) & IPC_CPU1TOCPU2IPCSTS_IPC0) != IPC_CPU1TOCPU2IPCSTS_IPC0);
    HWREG(IPC_CPU2TOCPU1_BASE + IPC_O_CPU2TOCPU1IPCBOOTSTS) = 0x0UL;

    //
    // ACK CPU1 Flag
    //
    HWREG(IPC_CPU2TOCPU1_BASE + IPC_O_CPU2TOCPU1IPCACK) |= IPC_CPU2TOCPU1IPCACK_IPC0;

    //
    // Check the IPCBOOTMODE Key, IPC message copy length, and device frequency
    //
    if((HWREAD_IPCBOOTMODE_KEY != IPCBOOTMODE_KEY) ||
       (HWREAD_IPCBOOTMODE_COPY_LENGTH > IPCBOOTMODE_COPY_LENGTH_MAX) ||
       (HWREAD_IPCBOOTMODE_DEVICE_FREQ > IPCBOOTMODE_DEVICE_FREQ_MAX) ||
       (HWREAD_IPCBOOTMODE_DEVICE_FREQ < IPCBOOTMODE_DEVICE_FREQ_MIN))
    {
        //
        // IPCBOOTMODE Values aren't correct, send IPC to CPU1, and
        // wait for CPU1 to reset CPU2
        //

        //
        // Set IPC command with error and IPC address (if applicable)
        //
        HWREG(IPC_CPU2TOCPU1_BASE + IPC_O_CPU2TOCPU1IPCSENDCOM) = CPU2TOCPU1_BOOTROM_BOOT_CMD_INVALID;
        HWREG(IPC_CPU2TOCPU1_BASE + IPC_O_CPU2TOCPU1IPCSENDADDR) = NO_ADDRESS_DATA;

        //
        // Set IPC Flags 0
        //
        HWREG(IPC_CPU2TOCPU1_BASE + IPC_O_CPU2TOCPU1IPCSET) = IPC_CPU2TOCPU1IPCSET_IPC0;

        while(1)
        {
        }
    }
}


//
// CPU2BROM_setupDeviceSystems - Setup flash configurations and power up
//
void CPU2BROM_setupDeviceSystems(void)
{
    uint32_t entryAddress = 0xFFFFFFFFUL;
    uint16_t flashPowerUpTimeOut;
    uint16_t flashPSLEEP;
    uint16_t flashRWAIT;
    uint16_t deviceClockFrequency = 0x0U;
    
    //
    // Get device frequency (MHz)
    //
    deviceClockFrequency = (uint16_t)HWREAD_IPCBOOTMODE_DEVICE_FREQ;

    //
    // Set flash power up values
    //
    if(deviceClockFrequency > 150U)
    {
        //
        // Set flash timeout variable
        //
        flashPowerUpTimeOut = CPU2_FLASH_PSLEEP_210MHZ_TIMEOUT_VALUE;

        //
        // Set flash PSLEEP
        //
        flashPSLEEP = CPU2_FLASH_PSLEEP_210MHZ_VALUE;

        //
        // Set flash wait state to 3 (for frequencies greater than 150MHz)
        //
        flashRWAIT = 0x3U;
    }
    else if(deviceClockFrequency > 100U)
    {
        //
        // Set flash timeout variable
        //
        flashPowerUpTimeOut = CPU2_FLASH_PSLEEP_150MHZ_TIMEOUT_VALUE;

        //
        // Set flash PSLEEP
        //
        flashPSLEEP = CPU2_FLASH_PSLEEP_150MHZ_VALUE;

        //
        // Set flash wait state to 2 (for frequencies between 101MHz and 150MHz)
        //
        flashRWAIT = 0x2U;
    }
    else if(deviceClockFrequency > 50U)
    {
        //
        // Set flash timeout variable
        //
        flashPowerUpTimeOut = CPU2_FLASH_PSLEEP_100MHZ_TIMEOUT_VALUE;

        //
        // Set flash PSLEEP
        //
        flashPSLEEP = CPU2_FLASH_PSLEEP_100MHZ_VALUE;

        //
        // Set flash wait state to 1 (for frequencies between 51MHz and 100MHz)
        //
        flashRWAIT = 0x1U;
    }
    else if(deviceClockFrequency > 25U)
    {
        //
        // Set flash timeout variable
        //
        flashPowerUpTimeOut = CPU2_FLASH_PSLEEP_50MHZ_TIMEOUT_VALUE;

        //
        // Set flash PSLEEP
        //
        flashPSLEEP = CPU2_FLASH_PSLEEP_50MHZ_VALUE;

        //
        // Set flash wait state to 0 (for frequencies less than 50MHz)
        //
        flashRWAIT = 0x0U;
    }
    else
    {
        //
        // Less than or equal to 25MHz
        //

        //
        // Set flash timeout variable
        //
        flashPowerUpTimeOut = CPU2_FLASH_PSLEEP_25MHZ_TIMEOUT_VALUE;

        //
        // Set flash PSLEEP
        //
        flashPSLEEP = CPU2_FLASH_PSLEEP_25MHZ_VALUE;

        //
        // Set flash wait state to 0 (for frequencies less than 50MHz)
        //
        flashRWAIT = 0x0U;
    }

    //
    // Set flash PSLEEP
    //
    Flash_setPumpWakeupTime(FLASH0CTRL_BASE, flashPSLEEP);

    //
    // Set flash wait state
    //
    Flash_setWaitstates(FLASH0CTRL_BASE, flashRWAIT);

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
        // If ready status is never set, a timeout
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
    // Adjust the PSLEEP back to default reset value
    //
    Flash_setPumpWakeupTime(FLASH0CTRL_BASE, CPU2_FLASH_DEFAULT_PSLEEP);

    //
    // Set back the Flash wait states
    //
    Flash_setWaitstates(FLASH0CTRL_BASE, CPU2_FLASH_DEFAULT_RWAIT);

    //
    // CPU2 Patch/Escape Point 2
    //
    entryAddress = CPU2BROM_TI_OTP_ESCAPE_POINT_2;
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
// CPU2BROM_startSystemBoot - CPU2 System Initialization procedure and boot
//                            selection
//
uint32_t CPU2BROM_startSystemBoot(void)
{
    uint32_t entryAddress = 0xFFFFFFFFUL;
    uint32_t bootEntryAddress = 0xFFFFFFFFUL;
    uint16_t bootState = CPU2BROM_READBOOTMODE;

    //
    // Init boot mode selection
    //
    CPU2BROM_bootMode = 0xFFFFFFFFUL;

    //
    // Update boot status - Boot has started
    //
    CPU2BROM_bootStatus = CPU2_BOOTROM_BOOTSTS_SYSTEM_START_BOOT;

    //
    // Update CPU2 boot health status for CPU1
    //
    CPU2BROM_setIPCBootStatus();

    //
    // Initialize iTrap address
    //
    CPU2BROM_itrapAddress = 0xFFFFFFFFUL;

    //
    // CPU2 Patch/Escape Point 4
    //
    entryAddress = CPU2BROM_TI_OTP_ESCAPE_POINT_4;
    if((entryAddress != 0xFFFFFFFFUL) &&
       (entryAddress != 0x00000000UL))
    {
        //
        // If OTP is programmed, then call OTP patch function
        //
        ((void (*)(void))entryAddress)();
    }

    //
    // Enable NMI
    //
    EALLOW;
    HWREGH(NMI_BASE + NMI_O_CFG) = NMI_CFG_NMIE;
    EDIS;

    //
    // CPU2 Patch/Escape Point 5
    //
    entryAddress = CPU2BROM_TI_OTP_ESCAPE_POINT_5;
    if((entryAddress != 0xFFFFFFFFUL) &&
       (entryAddress != 0x00000000UL))
    {
        //
        // If OTP is programmed, then call OTP patch function
        //
        ((void (*)(void))entryAddress)();
    }

    //
    // Update status that RAM init is complete.
    //
    // Clear RESC bits so that bootROM would not go into
    // a unwanted reset handling if it got reset for some reason
    //
    if((HWREG(CPUSYS_BASE + SYSCTL_O_RESC) & ((uint32_t)SYSCTL_RESC_POR)) ==
       SYSCTL_RESC_POR)
    {
        //
        // Update boot status - RAM Init complete
        //
        CPU2BROM_bootStatus |= CPU2_BOOTROM_RAM_INIT_COMPLETE;

        //
        // Clear POR and XRSn
        //
        SysCtl_clearResetCause(SYSCTL_RESC_POR | SYSCTL_RESC_XRSN);
        CPU2BROM_bootStatus |= ((uint32_t)CPU2_BOOTROM_HANDLED_XRSN |
                                (uint32_t)CPU2_BOOTROM_HANDLED_POR);
    }

    //
    // Clear only XRS
    //
    if((HWREG(CPUSYS_BASE + SYSCTL_O_RESC) & ((uint32_t)SYSCTL_RESC_XRSN)) ==
       SYSCTL_RESC_XRSN)
    {
        SysCtl_clearResetCause(SYSCTL_RESC_XRSN);
        CPU2BROM_bootStatus |= (uint32_t)CPU2_BOOTROM_HANDLED_XRSN;
    }

    //
    // Update boot status - Reset cause clearing complete
    //
    CPU2BROM_bootStatus |= CPU2_BOOTROM_RESC_HANDLED;

    //
    // Update CPU2 boot health status for CPU1
    //
    CPU2BROM_setIPCBootStatus();

    //
    // CPU2 Patch/Escape Point 6
    //
    entryAddress = CPU2BROM_TI_OTP_ESCAPE_POINT_6;
    if((entryAddress != 0xFFFFFFFFUL) &&
       (entryAddress != 0x00000000UL))
    {
        //
        // If OTP is programmed, then call OTP patch function
        //
        ((void (*)(void))entryAddress)();
    }

    //
    // CPU2 Boot State Machine
    //
    while(1)
    {
        switch(bootState)
        {
            case CPU2BROM_READBOOTMODE:
                //
                // Get boot mode selected
                //
                CPU2BROM_bootMode = HWREAD_IPCBOOTMODE_BOOTMODE;

                //
                // Go to wait for command mode or run specified boot mode
                //
                if(CPU2BROM_bootMode == WAIT_FOR_COMMAND)
                {
                    bootState = CPU2BROM_WAITFORCOMMAND;
                }
                else
                {
                    bootState = CPU2BROM_RUNBOOTMODE;
                }
                break;
            case CPU2BROM_WAITFORCOMMAND:
                //
                // Enter wait loop until CPU1 sets IPCFLG0
                //
                CPU2BROM_waitForCommand();

                //
                // Go read requested boot mode
                //
                bootState = CPU2BROM_READBOOTMODE;
                break;
            case CPU2BROM_RUNBOOTMODE:
                //
                // Run selected boot mode
                // Returns - Either return to wait or branch to app states
                //
                bootEntryAddress = CPU2BROM_runSelectedBootMode();

                if(bootEntryAddress == CPU2BROM_RETURN_TO_WAITFORCOMMAND)
                {
                    bootState = CPU2BROM_WAITFORCOMMAND;
                }
                else
                {
                    bootState = CPU2BROM_BRANCHTOAPPLICATION;
                }
                break;
            default:
                //
                // Should never get here - Return to wait-for-command
                //
                bootState = CPU2BROM_WAITFORCOMMAND;
                break;
        }

        if(bootState == CPU2BROM_BRANCHTOAPPLICATION)
        {
            break;
        }
    }

    //
    // CPU2 Patch/Escape Point 11
    //
    entryAddress = CPU2BROM_TI_OTP_ESCAPE_POINT_11;
    if((entryAddress != 0xFFFFFFFFUL) &&
       (entryAddress != 0x00000000UL))
    {
        //
        // If OTP is programmed, then call OTP patch function
        //
        ((void (*)(void))entryAddress)();
    }

    //
    // Update boot status - Boot Complete
    //
    CPU2BROM_bootStatus |= CPU2_BOOTROM_BOOT_COMPLETE;

    //
    // Update CPU2 boot health status for CPU1
    //
    CPU2BROM_setIPCBootStatus();

    //
    // Enable Watchdog and branch to address
    //
    SysCtl_enableWatchdog();
    return(bootEntryAddress);
}

//
// CPU2BROM_runSelectedBootMode - Run specified boot process for boot mode
//
uint32_t CPU2BROM_runSelectedBootMode(void)
{
    uint32_t entryAddress = 0xFFFFFFFFUL;

    //
    // Update boot status - Clear boot start before setting boot mode status
    //
    CPU2BROM_bootStatus &= ~CPU2_BOOTROM_BOOTSTS_MASK;

    //
    // Clear previous status errors
    //
    CPU2BROM_bootStatus &= ~(CPU2_BOOTROM_FAILED_SECURE_FLASH_CMAC |
                             CPU2_BOOTROM_GOT_AN_INVALID_IPC_BOOT_VALUE |
                             CPU2_BOOTROM_MSG_RAM_COPY_LENGTH_INVALID);

    //
    // CPU2 Patch/Escape Point 7
    //
    entryAddress = CPU2BROM_TI_OTP_ESCAPE_POINT_7;
    if((entryAddress != 0xFFFFFFFFUL) &&
       (entryAddress != 0x00000000UL))
    {
        //
        // If OTP is programmed, then call OTP patch function
        //
        ((void (*)(void))entryAddress)();
    }

    //
    // Run selected boot mode
    //
    switch(CPU2BROM_bootMode)
    {
        case WAIT_FOR_COMMAND:
            entryAddress = CPU2BROM_RETURN_TO_WAITFORCOMMAND;
            break;

        case FLASH_BOOT:
            entryAddress = FLASH_ENTRY_POINT;
            CPU2BROM_bootStatus |= CPU2_BOOTROM_BOOTSTS_IN_FLASH_BOOT;
            break;

        case FLASH_BOOT_ALT1:
            entryAddress = FLASH_ENTRY_POINT_ALT1;
            CPU2BROM_bootStatus |= CPU2_BOOTROM_BOOTSTS_IN_FLASH_BOOT;
            break;

        case FLASH_BOOT_ALT2:
            entryAddress = FLASH_ENTRY_POINT_ALT2;
            CPU2BROM_bootStatus |= CPU2_BOOTROM_BOOTSTS_IN_FLASH_BOOT;
            break;

        case FLASH_BOOT_ALT3:
            entryAddress = FLASH_ENTRY_POINT_ALT3;
            CPU2BROM_bootStatus |= CPU2_BOOTROM_BOOTSTS_IN_FLASH_BOOT;
            break;

        case SECURE_FLASH_BOOT:
            entryAddress = FLASH_ENTRY_POINT;
            CPU2BROM_bootStatus |= CPU2_BOOTROM_BOOTSTS_IN_SECURE_FLASH_BOOT;
            //
            // Calculate CMAC and verify flash status based on CMAC.
            //
            if(CPU2BROM_verifySecureFlash(entryAddress) == SECURE_FLASH_BOOT_FAIL)
            {
                //
                // On CMAC failure, return to wait-for-command loop
                //
                entryAddress = CPU2BROM_RETURN_TO_WAITFORCOMMAND;
            }
            break;

        case SECURE_FLASH_BOOT_ALT1:
            entryAddress = FLASH_ENTRY_POINT_ALT1;
            CPU2BROM_bootStatus |= CPU2_BOOTROM_BOOTSTS_IN_SECURE_FLASH_BOOT;
            //
            // Calculate CMAC and verify flash status based on CMAC.
            //
            if(CPU2BROM_verifySecureFlash(entryAddress) == SECURE_FLASH_BOOT_FAIL)
            {
                //
                // On CMAC failure, return to wait-for-command loop
                //
                entryAddress = CPU2BROM_RETURN_TO_WAITFORCOMMAND;
            }
            break;

        case SECURE_FLASH_BOOT_ALT2:
            entryAddress = FLASH_ENTRY_POINT_ALT2;
            CPU2BROM_bootStatus |= CPU2_BOOTROM_BOOTSTS_IN_SECURE_FLASH_BOOT;
            //
            // Calculate CMAC and verify flash status based on CMAC.
            //
            if(CPU2BROM_verifySecureFlash(entryAddress) == SECURE_FLASH_BOOT_FAIL)
            {
                //
                // On CMAC failure, return to wait-for-command loop
                //
                entryAddress = CPU2BROM_RETURN_TO_WAITFORCOMMAND;
            }
            break;

        case SECURE_FLASH_BOOT_ALT3:
            entryAddress = FLASH_ENTRY_POINT_ALT3;
            CPU2BROM_bootStatus |= CPU2_BOOTROM_BOOTSTS_IN_SECURE_FLASH_BOOT;
            //
            // Calculate CMAC and verify flash status based on CMAC.
            //
            if(CPU2BROM_verifySecureFlash(entryAddress) == SECURE_FLASH_BOOT_FAIL)
            {
                //
                // On CMAC failure, return to wait-for-command loop
                //
                entryAddress = CPU2BROM_RETURN_TO_WAITFORCOMMAND;
            }
            break;

        case RAM_BOOT:
            entryAddress = M0RAM_ENTRY_POINT;
            CPU2BROM_bootStatus |= CPU2_BOOTROM_BOOTSTS_IN_RAM_BOOT;
            break;

        case USER_OTP_BOOT:
            entryAddress = USER_OTP_ENTRY_POINT;
            CPU2BROM_bootStatus |= CPU2_BOOTROM_BOOTSTS_IN_OTP_BOOT;
            break;

        case IPC_MSG_COPY_BOOT:
            entryAddress = M1RAM_ENTRY_POINT;
            CPU2BROM_bootStatus |= CPU2_BOOTROM_BOOTSTS_IN_IPC_MSG_RAM_BOOT;

            //
            // Determine if IPC MSG RAM Copy length is valid before running
            // boot mode
            //
            if((HWREAD_IPCBOOTMODE_COPY_LENGTH > IPC_MSG_COPY_BOOT_MIN_LENGTH) &&
               (HWREAD_IPCBOOTMODE_COPY_LENGTH <= IPC_MSG_COPY_BOOT_MAX_LENGTH))
            {
                //
                // Copy from CPU1-to-CPU2 Message RAM 1 to M1RAM
                //
                CPU2BROM_performCopyToRAM(entryAddress,
                                          (uint16_t)HWREAD_IPCBOOTMODE_COPY_LENGTH);
            }
            else
            {
                //
                // Copy length set incorrectly, notify CPU1 and return to
                // wait-for-command mode
                //
                (void)CPU2BROM_sendErrorIPC(CPU2TOCPU1_BOOTROM_BOOT_CMD_INVALID,
                                            NO_ADDRESS_DATA);
                CPU2BROM_bootStatus |= CPU2_BOOTROM_MSG_RAM_COPY_LENGTH_INVALID;

                entryAddress = CPU2BROM_RETURN_TO_WAITFORCOMMAND;
            }
            break;

        default:
            //
            // Incorrect value - Notify CPU1 and return to wait-for-command mode
            //
            entryAddress = CPU2BROM_RETURN_TO_WAITFORCOMMAND;
            (void)CPU2BROM_sendErrorIPC(CPU2TOCPU1_BOOTROM_BOOT_CMD_INVALID,
                                        NO_ADDRESS_DATA);
            CPU2BROM_bootStatus |= CPU2_BOOTROM_GOT_AN_INVALID_IPC_BOOT_VALUE;
            break;
    }

    //
    // Update latest CPU2 boot status for CPU1
    //
    CPU2BROM_setIPCBootStatus();

    return(entryAddress);
}

//
// CPU2BROM_waitForCommand - Loop indefinitely until CPU1 sets IPCFLG0
//
void CPU2BROM_waitForCommand(void)
{
    uint32_t entryAddress = 0xFFFFFFFFUL;

    //
    // Update boot status - Clear boot start before setting boot mode status
    //
    CPU2BROM_bootStatus &= ~CPU2_BOOTROM_BOOTSTS_MASK;
    CPU2BROM_bootStatus |= CPU2_BOOTROM_BOOTSTS_IN_WAIT_BOOT;
    CPU2BROM_setIPCBootStatus();

    //
    // CPU2 Patch/Escape Point 8
    //
    entryAddress = CPU2BROM_TI_OTP_ESCAPE_POINT_8;
    if((entryAddress != 0xFFFFFFFFUL) &&
       (entryAddress != 0x00000000UL))
    {
        //
        // If OTP is programmed, then call OTP patch function
        //
        ((void (*)(void))entryAddress)();
    }

    while(1)
    {
        //
        // Wait for CPU1 to set flag 0 to signal the IPCBOOTMODE is ready
        //
        if((HWREG(IPC_CPU2TOCPU1_BASE + IPC_O_CPU1TOCPU2IPCSTS) & IPC_CPU1TOCPU2IPCSTS_IPC0) == IPC_CPU1TOCPU2IPCSTS_IPC0)
        {
            //
            // ACK CPU1 Flag
            //
            HWREG(IPC_CPU2TOCPU1_BASE + IPC_O_CPU2TOCPU1IPCACK) |= IPC_CPU2TOCPU1IPCACK_IPC0;

            break;
        }
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
// If the CMAC calculation fails, this  function sends an IPC message
// notifying CPU1 and returns .
//
// Return -
//         0x00000000UL  - secure flash is verified and ready to be booted
//         0xFFFFFFFFUL  - secure flash failed to verify
//
uint32_t CPU2BROM_verifySecureFlash(uint32_t entryAddress)
{
    uint32_t escapeEntryAddress = 0xFFFFFFFFUL;

    //
    // CPU2 Patch/Escape Point 9
    //
    escapeEntryAddress = CPU2BROM_TI_OTP_ESCAPE_POINT_9;
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
    //if(CPU2BROM_calculateCMAC(entryAddress, (entryAddress + HWREG(entryAddress - 0xA)),(entryAddress - 0x8)) != 0x0U)

    //
    // DEBUG ONLY - Using embedded golden sig test vectors/cases (1 to 4)
    //
    //if(CPU2BROM_calculateCMAC(entryAddress, (entryAddress + HWREG(entryAddress - 0x2)),(entryAddress + HWREG(entryAddress - 0x4))) != 0x0U)


    if(CPU2BROM_calculateCMAC(entryAddress, (entryAddress + 0x2000U),
                              (entryAddress + 0x2U)) != 0x0U)
    {
        //
        // CMAC failed, send IPC to CPU1
        //
        (void)CPU2BROM_sendErrorIPC(CPU2TOCPU1_BOOTROM_FAILED_CMAC, NO_ADDRESS_DATA);
        CPU2BROM_bootStatus |= CPU2_BOOTROM_FAILED_SECURE_FLASH_CMAC;

        return(SECURE_FLASH_BOOT_FAIL);
    }
    else
    {
        //
        // CMAC passed
        //
        return(SECURE_FLASH_BOOT_PASS);
    }
}

//
// End of file
//

