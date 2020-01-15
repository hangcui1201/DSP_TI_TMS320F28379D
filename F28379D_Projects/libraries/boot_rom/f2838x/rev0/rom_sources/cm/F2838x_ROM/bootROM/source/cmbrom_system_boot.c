//###########################################################################
//
// FILE:    cmbrom_system_boot.c
//
// TITLE:   CM System Boot
//
// CM System Initialization and associated functions
//
//###########################################################################
// $TI Release: $
// $Release Date:  $
//###########################################################################

//
// Included Files
//
#include "cmbootrom.h"

//
// Globals
//
#pragma DATA_SECTION(CMBROM_bootMode, "UserBootModeVariable");
uint32_t CMBROM_bootMode;

#pragma DATA_SECTION(CMBROM_bootStatus, "BootStatusVariable");
uint32_t CMBROM_bootStatus;

//
// Function Prototypes
//
void CMBROM_waitForCommand(void);
uint32_t CMBROM_runSelectedBootMode(void);
uint32_t CMBROM_verifySecureFlash(uint32_t entryAddress);

//
// CMBROM_verifyBootCommand - Verify that the IPCBOOTMODE values for key,
//                            IPC message RAM copy length, and device
//                            frequency are set appropriately.
//
//                            If values are invalid, IPC is sent to CPU1 and
//                            CM waits for reset.
//
void CMBROM_verifyBootCommand(void)
{
    //
    // Important: Don't use local variables in this function
    //

    //
    // Wait for CPU1 to set flag 0 to signal the IPCBOOTMODE is ready.
    // Set status to indicate CM is waiting and clear after IPCFLG set.
    //
    HWREG(IPC_CMTOCPU1_BASE + IPC_O_CMTOCPU1IPCBOOTSTS) = CM_BOOTROM_BOOTSTS_WAITING_FOR_FLAG;
    while((HWREG(IPC_CMTOCPU1_BASE + IPC_O_CPU1TOCMIPCSTS) & IPC_CPU1TOCMIPCSTS_IPC0) != IPC_CPU1TOCMIPCSTS_IPC0);
    HWREG(IPC_CMTOCPU1_BASE + IPC_O_CMTOCPU1IPCBOOTSTS) = 0x0UL;

    //
    // ACK CPU1 Flag
    //
    HWREG(IPC_CMTOCPU1_BASE + IPC_O_CMTOCPU1IPCACK) |= IPC_CMTOCPU1IPCACK_IPC0;


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
        // wait for CPU1 to reset CM
        //

        //
        // Set IPC command with error and IPC address (if applicable)
        //
        HWREG(IPC_CMTOCPU1_BASE + IPC_O_CMTOCPU1IPCSENDCOM) = CMTOCPU1_BOOTROM_BOOT_CMD_INVALID;
        HWREG(IPC_CMTOCPU1_BASE + IPC_O_CMTOCPU1IPCSENDADDR) = NO_ADDRESS_DATA;

        //
        // Set IPC Flags 0
        //
        HWREG(IPC_CMTOCPU1_BASE + IPC_O_CMTOCPU1IPCSET) = IPC_CMTOCPU1IPCSET_IPC0;

        while(1)
        {
        }
    }
}

//
// CMBROM_setupDeviceSystems - Setup flash configurations and power up
//
void CMBROM_setupDeviceSystems(void)
{
    uint32_t entryAddress = 0xFFFFFFFFUL;
    uint16_t deviceClockFrequency = 0x0U;
    uint16_t flashPSLEEP;
    uint16_t flashRWAIT;
    uint16_t flashPowerUpTimeOut;
    
    //
    // Get device clock frequency (MHz)
    //
    deviceClockFrequency = HWREAD_IPCBOOTMODE_DEVICE_FREQ;
    
    //
    // Set flash power up values
    //
    if(deviceClockFrequency > 100U)
    {
        //
        // Set flash timeout variable
        //
        flashPowerUpTimeOut = CM_FLASH_PSLEEP_125MHZ_TIMEOUT_VALUE;

        //
        // Set flash PSLEEP
        //
        flashPSLEEP = CM_FLASH_PSLEEP_125MHZ_VALUE;

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
        flashPowerUpTimeOut = CM_FLASH_PSLEEP_100MHZ_TIMEOUT_VALUE;

        //
        // Set flash PSLEEP
        //
        flashPSLEEP = CM_FLASH_PSLEEP_100MHZ_VALUE;

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
        flashPowerUpTimeOut = CM_FLASH_PSLEEP_50MHZ_TIMEOUT_VALUE;

        //
        // Set flash PSLEEP
        //
        flashPSLEEP = CM_FLASH_PSLEEP_50MHZ_VALUE;

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
        flashPowerUpTimeOut = CM_FLASH_PSLEEP_25MHZ_TIMEOUT_VALUE;

        //
        // Set flash PSLEEP
        //
        flashPSLEEP = CM_FLASH_PSLEEP_25MHZ_VALUE;

        //
        // Set flash wait state to 0 (for frequencies less than 50MHz)
        //
        flashRWAIT = 0x0U;
    }

    //
    // Unlock Flash control register
    //
    Flash_unlockCtrlRegisters(FLASH0CTRL_BASE);

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
            __asm(" nop");

            flashPowerUpTimeOut-=1U;
        }
    }

    //
    // Adjust the PSLEEP back to default reset value
    //
    Flash_setPumpWakeupTime(FLASH0CTRL_BASE, CM_FLASH_DEFAULT_PSLEEP);

    //
    // Set back the Flash wait states
    //
    Flash_setWaitstates(FLASH0CTRL_BASE, CM_FLASH_DEFAULT_RWAIT);

    //
    // CM Patch/Escape Point 1
    //
    entryAddress = CMBROM_TI_OTP_ESCAPE_POINT_1;
    if((entryAddress != 0xFFFFFFFFUL) &&
       (entryAddress != 0x00000000UL))
    {
        entryAddress |= 0x1U;  // BLX instruction result in a UsageFault exception
                               // if bit[0] of Rm is 0, where Rm holds the branch
                               // address.
        //
        // If OTP is programmed, then call OTP patch function
        //
        ((void (*)(void))entryAddress)();
    }
}

//
// CMBROM_startSystemBoot - CM System Initialization procedure and boot 
//                          selection
//
uint32_t CMBROM_startSystemBoot(void)
{
    uint32_t entryAddress = 0xFFFFFFFFUL;
    uint32_t bootEntryAddress = 0xFFFFFFFFUL;
    uint16_t bootState = CMBROM_READBOOTMODE;

    //
    // Init boot mode selection
    //
    CMBROM_bootMode = 0xFFFFFFFFUL;

    //
    // Update boot status - Boot has started
    //
    CMBROM_bootStatus = CM_BOOTROM_BOOTSTS_SYSTEM_START_BOOT;

    //
    // Update CM boot health status for CPU1
    //
    CMBROM_setIPCBootStatus();

    //
    // CM Patch/Escape Point 3
    //
    entryAddress = CMBROM_TI_OTP_ESCAPE_POINT_3;
    if((entryAddress != 0xFFFFFFFFUL) &&
       (entryAddress != 0x00000000UL))
    {
        entryAddress |= 0x1U;  // BLX instruction result in a UsageFault exception
                               // if bit[0] of Rm is 0, where Rm holds the branch
                               // address.
        //
        // If OTP is programmed, then call OTP patch function
        //
        ((void (*)(void))entryAddress)();
    }

    //
    // Enable NMI
    //
    HWREG(NMI_BASE + NMI_O_CMNMICFG) = CM_NMI_ENABLE_KEY | NMI_CMNMICFG_NMIE;

    //
    // CM Patch/Escape Point 4
    //
    entryAddress = CMBROM_TI_OTP_ESCAPE_POINT_4;
    if((entryAddress != 0xFFFFFFFFUL) &&
       (entryAddress != 0x00000000UL))
    {
        entryAddress |= 0x1U;  // BLX instruction result in a UsageFault exception
                               // if bit[0] of Rm is 0, where Rm holds the branch
                               // address.
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
    if((HWREG(CMSYSCTL_BASE + SYSCTL_O_CMRESC) &
        ((uint32_t)SYSCTL_CMRESC_POR)) == SYSCTL_CMRESC_POR)
    {
        //
        // Update boot status - RAM Init complete
        //
        CMBROM_bootStatus |= CM_BOOTROM_RAM_INIT_COMPLETE;        
        
        //
        // Clear POR and XRSn
        //
        SysCtl_clearResetCause(SYSCTL_CMRESC_POR);
        CMBROM_bootStatus |= ((uint32_t)CM_BOOTROM_HANDLED_POR);
    }

    //
    // Update boot status - Reset cause clearing complete
    //
    CMBROM_bootStatus |= CM_BOOTROM_RESC_HANDLED;
    
    //
    // Update CM boot health status for CPU1
    //
    CMBROM_setIPCBootStatus();    

    //
    // CM Patch/Escape Point 5
    //
    entryAddress = CMBROM_TI_OTP_ESCAPE_POINT_5;
    if((entryAddress != 0xFFFFFFFFUL) &&
       (entryAddress != 0x00000000UL))
    {
        entryAddress |= 0x1U;  // BLX instruction result in a UsageFault exception
                               // if bit[0] of Rm is 0, where Rm holds the branch
                               // address.
        //
        // If OTP is programmed, then call OTP patch function
        //
        ((void (*)(void))entryAddress)();
    }

    //
    // CM Boot State Machine
    //
    while(1)
    {
        switch(bootState)
        {
            case CMBROM_READBOOTMODE:
                //
                // Get boot mode selected
                //
                CMBROM_bootMode = HWREAD_IPCBOOTMODE_BOOTMODE;
                
                //
                // Go to wait for command mode or run specified boot mode
                //
                if(CMBROM_bootMode == WAIT_FOR_COMMAND)
                {
                    bootState = CMBROM_WAITFORCOMMAND;
                }
                else
                {
                    bootState = CMBROM_RUNBOOTMODE;
                }
                break;
            case CMBROM_WAITFORCOMMAND:
                //
                // Enter wait loop until CPU1 sets IPCFLG0
                //
                CMBROM_waitForCommand();
                
                //
                // Go read requested boot mode
                //
                bootState = CMBROM_READBOOTMODE;
                break;
            case CMBROM_RUNBOOTMODE:
                //
                // Run selected boot mode 
                // Returns - Either return to wait or branch to app states
                //
                bootEntryAddress = CMBROM_runSelectedBootMode();
                
                if(bootEntryAddress == CMBROM_RETURN_TO_WAITFORCOMMAND)
                {
                    bootState = CMBROM_WAITFORCOMMAND;
                }
                else
                {
                    bootState = CMBROM_BRANCHTOAPPLICATION;
                }
                break;
            default:
                //
                // Should never get here - Return to wait-for-command
                //
                bootState = CMBROM_WAITFORCOMMAND;            
                break;
        }
        
        if(bootState == CMBROM_BRANCHTOAPPLICATION)
        {
            break;
        }
    }
    
    //
    // CM Patch/Escape Point 10
    //
    entryAddress = CMBROM_TI_OTP_ESCAPE_POINT_10;
    if((entryAddress != 0xFFFFFFFFUL) &&
       (entryAddress != 0x00000000UL))
    {
        entryAddress |= 0x1U;  // BLX instruction result in a UsageFault exception
                               // if bit[0] of Rm is 0, where Rm holds the branch
                               // address.
        //
        // If OTP is programmed, then call OTP patch function
        //
        ((void (*)(void))entryAddress)();
    }

    //
    // Update boot status - Boot Complete
    //
    CMBROM_bootStatus |= CM_BOOTROM_BOOT_COMPLETE;

    //
    // Update CM boot health status for CPU1
    //
    CMBROM_setIPCBootStatus();
    
    //
    // Branch to application
    //
    bootEntryAddress |= 0x1U;  // BLX instruction result in a UsageFault exception
                               // if bit[0] of Rm is 0, where Rm holds the branch
                               // address.
    ((void (*)(void))bootEntryAddress)();
    
    //
    // Enable Watchdog
    //
    SysCtl_enableWatchdog();

    //
    // Should never be reached - if so, CM should be reset by watchdog
    //
    while(1)
    {
    }
}

//
// CMBROM_runSelectedBootMode - Run specified boot process for boot mode
//
uint32_t CMBROM_runSelectedBootMode(void)
{
    uint32_t entryAddress = 0xFFFFFFFFUL;    
    
    //
    // Update boot status - Clear boot start before setting boot mode status
    //
    CMBROM_bootStatus &= ~CM_BOOTROM_BOOTSTS_MASK;   
    
    //
    // Clear previous status errors
    //
    CMBROM_bootStatus &= ~(CM_BOOTROM_FAILED_SECURE_FLASH_CMAC | 
                           CM_BOOTROM_GOT_AN_INVALID_IPC_BOOT_VALUE |
                           CM_BOOTROM_MSG_RAM_COPY_LENGTH_INVALID);
    
    //
    // CM Patch/Escape Point 6
    //
    entryAddress = CMBROM_TI_OTP_ESCAPE_POINT_6;
    if((entryAddress != 0xFFFFFFFFUL) &&
       (entryAddress != 0x00000000UL))
    {
        entryAddress |= 0x1U;  // BLX instruction result in a UsageFault exception
                               // if bit[0] of Rm is 0, where Rm holds the branch
                               // address.
        //
        // If OTP is programmed, then call OTP patch function
        //
        ((void (*)(void))entryAddress)();
    }

    //
    // Run selected boot mode
    //
    switch(CMBROM_bootMode)
    {
        case WAIT_FOR_COMMAND:
            entryAddress = CMBROM_RETURN_TO_WAITFORCOMMAND;
            break;

        case FLASH_BOOT:
            entryAddress = FLASH_ENTRY_POINT;
            CMBROM_bootStatus |= CM_BOOTROM_BOOTSTS_IN_FLASH_BOOT;
            break;

        case FLASH_BOOT_ALT1:
            entryAddress = FLASH_ENTRY_POINT_ALT1;
            CMBROM_bootStatus |= CM_BOOTROM_BOOTSTS_IN_FLASH_BOOT;
            break;

        case FLASH_BOOT_ALT2:
            entryAddress = FLASH_ENTRY_POINT_ALT2;
            CMBROM_bootStatus |= CM_BOOTROM_BOOTSTS_IN_FLASH_BOOT;
            break;

        case FLASH_BOOT_ALT3:
            entryAddress = FLASH_ENTRY_POINT_ALT3;
            CMBROM_bootStatus |= CM_BOOTROM_BOOTSTS_IN_FLASH_BOOT;
            break;

        case SECURE_FLASH_BOOT:
            entryAddress = FLASH_ENTRY_POINT;
            CMBROM_bootStatus |= CM_BOOTROM_BOOTSTS_IN_SECURE_FLASH_BOOT;
            //
            // Calculate CMAC and verify flash status based on CMAC. 
            //            
            if(CMBROM_verifySecureFlash(entryAddress) == SECURE_FLASH_BOOT_FAIL)
            {
                //
                // On CMAC failure, return to wait-for-command loop
                //
                entryAddress = CMBROM_RETURN_TO_WAITFORCOMMAND;
            }
            break;

        case SECURE_FLASH_BOOT_ALT1:
            entryAddress = FLASH_ENTRY_POINT_ALT1;
            CMBROM_bootStatus |= CM_BOOTROM_BOOTSTS_IN_SECURE_FLASH_BOOT;
            //
            // Calculate CMAC and verify flash status based on CMAC. 
            //            
            if(CMBROM_verifySecureFlash(entryAddress) == SECURE_FLASH_BOOT_FAIL)
            {
                //
                // On CMAC failure, return to wait-for-command loop
                //
                entryAddress = CMBROM_RETURN_TO_WAITFORCOMMAND;
            }
            break;

        case SECURE_FLASH_BOOT_ALT2:
            entryAddress = FLASH_ENTRY_POINT_ALT2;
            CMBROM_bootStatus |= CM_BOOTROM_BOOTSTS_IN_SECURE_FLASH_BOOT;
            //
            // Calculate CMAC and verify flash status based on CMAC. 
            //            
            if(CMBROM_verifySecureFlash(entryAddress) == SECURE_FLASH_BOOT_FAIL)
            {
                //
                // On CMAC failure, return to wait-for-command loop
                //
                entryAddress = CMBROM_RETURN_TO_WAITFORCOMMAND;
            }
            break;

        case SECURE_FLASH_BOOT_ALT3:
            entryAddress = FLASH_ENTRY_POINT_ALT3;
            CMBROM_bootStatus |= CM_BOOTROM_BOOTSTS_IN_SECURE_FLASH_BOOT;
            //
            // Calculate CMAC and verify flash status based on CMAC. 
            //
            if(CMBROM_verifySecureFlash(entryAddress) == SECURE_FLASH_BOOT_FAIL)
            {
                //
                // On CMAC failure, return to wait-for-command loop
                //
                entryAddress = CMBROM_RETURN_TO_WAITFORCOMMAND;
            }
            break;            

        case RAM_BOOT:
            entryAddress = S0RAM_ENTRY_POINT;
            CMBROM_bootStatus |= CM_BOOTROM_BOOTSTS_IN_RAM_BOOT;
            break;

        case USER_OTP_BOOT:
            entryAddress = USER_OTP_ENTRY_POINT;
            CMBROM_bootStatus |= CM_BOOTROM_BOOTSTS_IN_OTP_BOOT;
            break;
            
        case IPC_MSG_COPY_BOOT:
            entryAddress = S0RAM_ENTRY_POINT;
            CMBROM_bootStatus |= CM_BOOTROM_BOOTSTS_IN_IPC_MSG_RAM_BOOT;

            //
            // Determine if IPC MSG RAM Copy length is valid before running 
            // boot mode
            //
            if((HWREAD_IPCBOOTMODE_COPY_LENGTH > IPC_MSG_COPY_BOOT_MIN_LENGTH) && 
               (HWREAD_IPCBOOTMODE_COPY_LENGTH <= IPC_MSG_COPY_BOOT_MAX_LENGTH))
            {
                //
                // Copy from CPU1-to-CM Message RAM 1 to S0RAM
                //
                CMBROM_performCopyToRAM(entryAddress, 
                                        HWREAD_IPCBOOTMODE_COPY_LENGTH);
            }
            else
            {
                //
                // Copy length set incorrectly, notify CPU1 and return to 
                // wait-for-command mode
                //
                (void)CMBROM_sendErrorIPC(CMTOCPU1_BOOTROM_BOOT_CMD_INVALID,
                                          NO_ADDRESS_DATA);
                CMBROM_bootStatus |= CM_BOOTROM_MSG_RAM_COPY_LENGTH_INVALID;

                entryAddress = CMBROM_RETURN_TO_WAITFORCOMMAND;
            }
            break;
            
        default:
            //
            // Incorrect value - Notify CPU1 and return to wait-for-command mode
            //
            entryAddress = CMBROM_RETURN_TO_WAITFORCOMMAND;
            (void)CMBROM_sendErrorIPC(CMTOCPU1_BOOTROM_BOOT_CMD_INVALID,
                                      NO_ADDRESS_DATA);
            CMBROM_bootStatus |= CM_BOOTROM_GOT_AN_INVALID_IPC_BOOT_VALUE;
            break;
    }
    
    //
    // Update latest CM boot status for CPU1
    //
    CMBROM_setIPCBootStatus();
    
    return(entryAddress);    
}

//
// CMBROM_waitForCommand - Loop indefinitely until CPU1 sets IPCFLG0
//
void CMBROM_waitForCommand(void)
{
    uint32_t entryAddress = 0xFFFFFFFFUL;

    //
    // Update boot status - Clear boot start before setting boot mode status
    //
    CMBROM_bootStatus &= ~CM_BOOTROM_BOOTSTS_MASK;  
    CMBROM_bootStatus |= CM_BOOTROM_BOOTSTS_IN_WAIT_BOOT;
    CMBROM_setIPCBootStatus();

    //
    // CM Patch/Escape Point 7
    //
    entryAddress = CMBROM_TI_OTP_ESCAPE_POINT_7;
    if((entryAddress != 0xFFFFFFFFUL) &&
       (entryAddress != 0x00000000UL))
    {
        entryAddress |= 0x1U;  // BLX instruction result in a UsageFault exception
                               // if bit[0] of Rm is 0, where Rm holds the branch
                               // address.
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
        if((HWREG(IPC_CMTOCPU1_BASE + IPC_O_CPU1TOCMIPCSTS) & IPC_CPU1TOCMIPCSTS_IPC0) == IPC_CPU1TOCMIPCSTS_IPC0)
        {
            //
            // ACK CPU1 Flag
            //
            HWREG(IPC_CMTOCPU1_BASE + IPC_O_CMTOCPU1IPCACK) |= IPC_CMTOCPU1IPCACK_IPC0;

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

uint32_t CMBROM_verifySecureFlash(uint32_t entryAddress)
{
    uint32_t escapeEntryAddress = 0xFFFFFFFFUL;

    //
    // CM Patch/Escape Point 8
    //
    escapeEntryAddress = CMBROM_TI_OTP_ESCAPE_POINT_8;
    if((escapeEntryAddress != 0xFFFFFFFFUL) &&
       (escapeEntryAddress != 0x00000000UL))
    {
        escapeEntryAddress |= 0x1U;  // BLX instruction result in a UsageFault exception
                                     // if bit[0] of Rm is 0, where Rm holds the branch
                                     // address.
        //
        // If OTP is programmed, then call OTP patch function
        //
        ((void (*)(void))escapeEntryAddress)();
    }
    
    //
    // Calculate CMAC on entry pointer address + 16KB
    //

    //
    // Calculate CMAC 
    // - Calculation starts at entryAddress
    // - End address of calculation is entryAddress + 16KB (16384 bytes)
    //   (CMAC is calculated from start address to (end address - 3)
    // - Golden CMAC signature is always stored at entryAddress + 4 bytes
    //   (Signature will be considered all 1s in calculation)
    //    

    //
    // DEBUG ONLY - Using standard test vectors/cases (1 to 10)
    //
    //if(CMBROM_calculateCMAC(entryAddress, (entryAddress + HWREG(entryAddress - 0x14)),(entryAddress - 0x10)) != 0x0U)

    //
    // DEBUG ONLY - Using embedded golden sig test vectors/cases (1 to 4)
    //
    //if(CMBROM_calculateCMAC(entryAddress, (entryAddress + HWREG(entryAddress - 0x4)),(entryAddress + HWREG(entryAddress - 0x8))) != 0x0U)

    if(CMBROM_calculateCMAC(entryAddress, (entryAddress + 0x4000U),(entryAddress + 0x4U)) != 0x0U)
    {
        //
        // CMAC failed, send IPC to CPU1
        //
        (void)CMBROM_sendErrorIPC(CMTOCPU1_BOOTROM_FAILED_CMAC, NO_ADDRESS_DATA);
        CMBROM_bootStatus |= CM_BOOTROM_FAILED_SECURE_FLASH_CMAC;

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

