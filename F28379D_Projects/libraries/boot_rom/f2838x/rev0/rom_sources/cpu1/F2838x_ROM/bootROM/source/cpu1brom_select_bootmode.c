//###########################################################################
//
// FILE:    cpu1brom_select_bootmode.c
//
// TITLE:   CPU1 Boot Mode selection routines
//
// This includes functions to select the boot mode (standalone or emulation)
// and decode the boot pins.
//
//###########################################################################
// $TI Release: $
// $Release Date: $
//###########################################################################

//
// Included Files
//
#include "cpu1bootrom.h"

//
// Function Prototypes
//
uint32_t CPU1BROM_getStandaloneBootMode(void);
uint32_t CPU1BROM_getEmulationBootMode(void);
uint16_t CPU1BROM_decodeBootPins(uint32_t pinConfig);
uint16_t CPU1BROM_isFlashProgrammed(void);

//
// CPU1BROM_isFlashProgrammed - Checks if flash is programmed at flash entry
//                              option 0 (bank 0 sector 0)
//
//                              Returns 0 if programmed, else returns 1 if not
//
uint16_t CPU1BROM_isFlashProgrammed(void)
{
    if(HWREG(FLASH_ENTRY_POINT) == 0xFFFFFFFFUL)
    {
        //
        // Flash isn't programmed
        //
        return(FLASH_NOT_PROGRAMMED);
    }
    else
    {
        //
        // Flash is programmed
        //
        return(FLASH_IS_PROGRAMMED);
    }
}

//
// CPU1BROM_decodeBootPins - Decode boot mode table index from boot mode
//                           select pins
//
uint16_t CPU1BROM_decodeBootPins(uint32_t pinConfig)
{
    uint32_t bootPin0 = 0U;
    uint32_t bootPin1 = 0U;
    uint32_t bootPin2 = 0U;
    uint16_t bootTableIndex = 0U;

    //
    // Check if all boot pins disabled (zero pin config), else decode GPIOs
    //
    if((uint32_t)(pinConfig & CPU1_ALL_BMSP_DISABLED_MASK) == 
       CPU1_ALL_BMSP_DISABLED_MASK)
    {
        //
        // Zero pin config scenario - Table index always zero
        //
        return 0U;
    }
    else
    {
        bootPin0 = (pinConfig & CPU1_PIN_CONFIG_MASK);
        bootPin1 = ((pinConfig >> 8U) & CPU1_PIN_CONFIG_MASK);
        bootPin2 = ((((uint32_t)pinConfig) >> 16U) & CPU1_PIN_CONFIG_MASK);
    }

    //
    // Reset BMSP if assigned to unaccepted GPIO
    //
    if((bootPin0 == CPU1_INVALID_GPIO42) || (bootPin0 == CPU1_INVALID_GPIO43) ||
       ((bootPin0 >= CPU1_GPIO169) && (bootPin0 <= CPU1_GPIO254)))
    {
        bootPin0 = FACTORY_DEFAULT_BMSP0;
    }

    if((bootPin1 == CPU1_INVALID_GPIO42) || (bootPin1 == CPU1_INVALID_GPIO43) ||
       ((bootPin1 >= CPU1_GPIO169) && (bootPin1 <= CPU1_GPIO254)))
    {
        bootPin1 = FACTORY_DEFAULT_BMSP1;
    }

    if((bootPin2 == CPU1_INVALID_GPIO42) || (bootPin2 == CPU1_INVALID_GPIO43) ||
       ((bootPin2 >= CPU1_GPIO169) && (bootPin2 <= CPU1_GPIO254)))
    {
        bootPin2 = CPU1_BMSP_DISABLED;
    }

    //
    // Set GPIO qualification of 6 samples for each BMSP
    // and wait 30 clock cycles to get accurate sample window
    //
    if(bootPin0 != CPU1_BMSP_DISABLED)
    {
        GPIO_setQualificationMode(bootPin0, GPIO_QUAL_6SAMPLE);
    }
    if(bootPin1 != CPU1_BMSP_DISABLED)
    {
        GPIO_setQualificationMode(bootPin1, GPIO_QUAL_6SAMPLE);
    }
    if(bootPin2 != CPU1_BMSP_DISABLED)
    {
        GPIO_setQualificationMode(bootPin2, GPIO_QUAL_6SAMPLE);
    }
    asm(" MOV    @T,#30 ");
    asm(" RPT    @T \
            ||NOP ");

    //
    // Check if any of the pins are disabled, else read the GPIO state
    //
    if(bootPin2 == CPU1_BMSP_DISABLED)
    {
        bootTableIndex = 0x0U;
    }
    else
    {
        bootTableIndex = (uint16_t)GPIO_readPin(bootPin2) << 2U;
    }

    if(bootPin1 == CPU1_BMSP_DISABLED)
    {
        bootTableIndex &= 0xFDU; // zero out bit 1
    }
    else
    {
        bootTableIndex &= 0xFDU;
        bootTableIndex |= (uint16_t)GPIO_readPin(bootPin1) << 1U;
    }

    if(bootPin0 == CPU1_BMSP_DISABLED)
    {
        bootTableIndex &= 0xFEU; // zero out bit 0
    }
    else
    {
        bootTableIndex &= 0xFEU;
        bootTableIndex |= (uint16_t)GPIO_readPin(bootPin0);
    }

    //
    // Remove GPIO qualification for each BMSP
    //
    if(bootPin0 != CPU1_BMSP_DISABLED)
    {
        GPIO_setQualificationMode(bootPin0, GPIO_QUAL_SYNC);
    }
    if(bootPin1 != CPU1_BMSP_DISABLED)
    {
        GPIO_setQualificationMode(bootPin1, GPIO_QUAL_SYNC);
    }
    if(bootPin2 != CPU1_BMSP_DISABLED)
    {
        GPIO_setQualificationMode(bootPin2, GPIO_QUAL_SYNC);
    }

    return(bootTableIndex & 0x7U);
}

//
// Get the Boot Mode Configured for Standalone Boot
//
// Param - None
//
// This function reads the OTP key and bootpin config locations to determine the 
// boot mode to return. 
//
// Return - Boot Mode Value
//
uint32_t CPU1BROM_getStandaloneBootMode(void)
{
    uint32_t bootMode = 0U;
    uint16_t bootTableIndex = 0U;
    uint32_t entryAddress = 0xFFFFFFFFUL;

    //
    // Check whether to use Z2 OTP for boot configuration settings. 
    // Else use Z1 or un-programmed, default settings
    //
    if(HWREAD_Z2_OTP_BOOTPIN_CONFIG_KEY != BOOTPIN_CONFIG_KEY)
    {
        //
        // Check if Z1 OTP key is set or not
        //
        if(HWREAD_Z1_OTP_BOOTPIN_CONFIG_KEY != BOOTPIN_CONFIG_KEY)
        {
            //
            // Bad Z2 and Z1 OTP Key
            //
            
            //
            // Decode boot mode from default boot mode select pins
            //
            bootMode |= GPIO_readPin(FACTORY_DEFAULT_BMSP1) << 1U;
            bootMode |= GPIO_readPin(FACTORY_DEFAULT_BMSP0);
            
            // 
            // If boot mode is set to flash boot, check if flash is programmed.
            // If flash isn't programmed, switch boot mode to USB
            //
            bootMode &= 0x3U;

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
            // When booting to unprogrammed flash, switch boot mode to USB
            //
            if(bootMode == FLASH_BOOT)
            {
                if(CPU1BROM_isFlashProgrammed() == FLASH_NOT_PROGRAMMED)
                {
                    bootMode = USB_BOOT;
                }
            }

            return(bootMode);
        }
        else
        {
            //
            // Use Z1 OTP Boot Configurations
            //
            
            //
            // Decode boot mode from OTP BOOTPIN configuration
            //
            bootTableIndex = CPU1BROM_decodeBootPins(HWREG(Z1_OTP_BOOTPIN_CONFIG));

            if(bootTableIndex < 4U)
            {
                //
                // Decode boot index (lower BOOTDEF table 0 to 3)
                //
                bootMode = HWREAD_Z1_OTP_BOOTDEF_L((uint32_t)bootTableIndex);
            }
            else if((3U < bootTableIndex) && (bootTableIndex < 8U))
            {
                //
                // Decode boot index (lower BOOTDEF table 4 to 7)
                //
                bootMode = HWREAD_Z1_OTP_BOOTDEF_H((uint32_t)bootTableIndex);
            }
            else
            {
                //
                // Incorrect boot table index, pause execution when connected to
                // debugger. Set boot mode to "flash".
                //
                asm("   ESTOP0");
                bootMode = FLASH_BOOT;
            }
        }     
    }
    else
    {
        //
        // Use Z2 OTP Boot Configurations
        //
        
        //
        // Decode boot mode from OTP BOOTPIN configuration
        //
        bootTableIndex = CPU1BROM_decodeBootPins(HWREG(Z2_OTP_BOOTPIN_CONFIG));

        if(bootTableIndex < 4U)
        {
            //
            // Decode boot index (lower BOOTDEF table 0 to 3)
            //
            bootMode = HWREAD_Z2_OTP_BOOTDEF_L((uint32_t)bootTableIndex);
        }
        else if((3U < bootTableIndex) && (bootTableIndex < 8U))
        {
            //
            // Decode boot index (lower BOOTDEF table 4 to 7)
            //
            bootMode = HWREAD_Z2_OTP_BOOTDEF_H((uint32_t)bootTableIndex);
        }
        else
        {
            //
            // Incorrect boot table index, pause execution when connected to
            // debugger. Set boot mode to "flash".
            //
            asm("   ESTOP0");
            bootMode = FLASH_BOOT;
        }        
    }
    
    return(bootMode);
}

//
// Get the Boot Mode Configured for Emulation Boot
//
// Param - None
//
// This function reads the emulation key and bootpin config locations to 
// determine the boot mode to return. 
//
// Return - Boot Mode Value
//
uint32_t CPU1BROM_getEmulationBootMode(void)
{
    uint32_t bootMode = 0U;
    uint16_t bootTableIndex = 0U;

    if(EMU_BOOTPIN_CONFIG_KEY == BOOTPIN_CONFIG_STANDALONE_KEY)
    {
        //
        // Emu BOOTPIN Config Key is 0xA5, emulation standalone/true boot flow
        //
        bootMode = CPU1BROM_getStandaloneBootMode();
    }
    else if(EMU_BOOTPIN_CONFIG_KEY != BOOTPIN_CONFIG_KEY)
    {
        //
        // Invalid Emu BOOTPIN config key (not 0x5A or 0xA5),
        // set boot mode to "wait boot"
        //
        bootMode = WAIT_BOOT;
    }
    else
    {
        //
        // EMU Key is Valid (0x5A)
        // Decode boot mode from EMU BOOTPIN configuration
        //
        bootTableIndex = CPU1BROM_decodeBootPins(HWREG(EMU_BOOTPIN_CONFIG));

        if(bootTableIndex < 4U)
        {
            //
            // Decode boot index (lower BOOTDEF table 0 to 3)
            //
            bootMode = EMU_BOOTDEF_L((uint32_t)bootTableIndex);
        }
        else if((3U < bootTableIndex) && (bootTableIndex < 8U))
        {
            //
            // Decode boot index (lower BOOTDEF table 4 to 7)
            //
            bootMode = EMU_BOOTDEF_H((uint32_t)bootTableIndex);
        }
        else
        {
            //
            // Incorrect boot table index, pause execution when connected to
            // debugger. Set boot mode to "wait boot".
            //
            asm("   ESTOP0");
            bootMode = WAIT_BOOT;
        }
    }

    return(bootMode);
}

//
// Select the Boot Mode based on Emulation or Standalone
//
// Param - None
//
// This function reads the debugger status and determines whether to get boot 
// mode through emulation or standalone process
//
// Return - Boot Mode Value
//
uint32_t CPU1BROM_selectBootMode(void)
{
    uint32_t bootMode;

    EALLOW;

    if(((uint32_t)HWREG(CPUSYS_BASE + SYSCTL_O_RESC) & 
        (uint32_t)SYSCTL_RESC_TRSTN_PIN_STATUS) == SYSCTL_RESC_TRSTN_PIN_STATUS)
    {
        //
        // Run emulation boot flow when debugger connected.
        //
        bootMode = CPU1BROM_getEmulationBootMode();
    }
    else
    {
        //
        // Run standalone/true boot flow when debugger isn't connected.
        //
        bootMode = CPU1BROM_getStandaloneBootMode();
    }

    EDIS;

    return(bootMode);
}

//
// End of File
//
