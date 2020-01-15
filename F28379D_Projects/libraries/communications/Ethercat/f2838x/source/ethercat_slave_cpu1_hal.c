//###########################################################################
//
// FILE:   ethercat_slave_cpu1_hal.c
//
// TITLE:  C28.CPU1 EtherCAT HAL Driver.
//
//###########################################################################
// $TI Release: F2838x EtherCAT Software v2.00.00.00 $
// $Release Date: Mon May 27 07:11:43 CDT 2019 $
// $Copyright:
// Copyright (C) 2019 Texas Instruments Incorporated - http://www.ti.com/
//
// Redistribution and use in source and binary forms, with or without 
// modification, are permitted provided that the following conditions 
// are met:
// 
//   Redistributions of source code must retain the above copyright 
//   notice, this list of conditions and the following disclaimer.
// 
//   Redistributions in binary form must reproduce the above copyright
//   notice, this list of conditions and the following disclaimer in the 
//   documentation and/or other materials provided with the   
//   distribution.
// 
//   Neither the name of Texas Instruments Incorporated nor the names of
//   its contributors may be used to endorse or promote products derived
//   from this software without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// $
//###########################################################################

//
// Included Files
//
#include "ethercat_slave_cpu1_hal.h"

#ifdef PDI_HAL_TEST

//
// HAL Test Application - Register Debug Structure
//
ESC_DebugRegisters ESC_escRegs[ESC_HAL_TEST_DEBUG_REGS_LENGTH];

//
// HAL Block Data Arrays
//
static uint32_t ESC_writeBlockData[ESC_HAL_TEST_BLOCK_LENGTH / 4U];
static uint32_t ESC_readBlockData[ESC_HAL_TEST_BLOCK_LENGTH / 4U];

#endif // PDI_HAL_TEST

//*****************************************************************************
//
// ESC_getTimer
//
//*****************************************************************************
uint32_t
ESC_getTimer(void)
{
    //
    // Return 1's compliment of the CPU timer
    //
    return(~((uint32_t)CPUTimer_getTimerCount(CPUTIMER0_BASE)));
}

//*****************************************************************************
//
// ESC_clearTimer
//
//*****************************************************************************
void
ESC_clearTimer(void)
{
    //
    // Set the timer period count
    //
    CPUTimer_setPeriod(CPUTIMER0_BASE, 0xFFFFFFFFUL);

    //
    // Reload timer with the period count value
    //
    CPUTimer_reloadTimerCounter(CPUTIMER0_BASE);
}

//*****************************************************************************
//
// ESC_timerIncPerMilliSec
//
//*****************************************************************************
uint32_t
ESC_timerIncPerMilliSec(void)
{
    //
    // Returns value based on core frequency of 200MHz.
    //
    return((uint32_t)200000UL);
}

//*****************************************************************************
//
// ESC_readBlockISR
//
//*****************************************************************************
void
ESC_readBlockISR(ESCMEM_ADDR *pData, uint16_t address, uint16_t len)
{
    //
    // Create pointer to ESC Address
    //
    const void * escSource = (void *)(ESC_BASE + (uint32_t)(address / 2U));

    //
    // Copy ESC data to buffer. Convert lengths to words.
    //
    memcpy(pData, escSource, (size_t)((len + 1U) >> 1U));

    //
    // Determine if length (in bytes) is even or odd
    // (No action on even)
    //
    if((len & 0x1U) == 0x1U)
    {
        //
        // Odd Length
        //

        //
        // Clear extra byte in buffer
        //
        pData[((len - 1U) / 2U)] = (pData[((len - 1U) / 2U)] & ESC_M_LSB);
    }
}

//*****************************************************************************
//
// ESC_readBlock
//
//*****************************************************************************
void
ESC_readBlock(ESCMEM_ADDR *pData, uint16_t address, uint16_t len)
{
    //
    // Disables interrupts
    //
    DINT;

    //
    // Perform copy of ESC data to buffer
    //
    ESC_readBlockISR(pData, address, len);

    //
    // Enable interrupts
    //
    EINT;
}

//*****************************************************************************
//
// ESC_readDWordISR
//
//*****************************************************************************
uint32_t
ESC_readDWordISR(uint16_t address)
{
    //
    // Read 32-bit address from ESC memory
    //
    return(HWREG(ESC_BASE + (address / 2U)));
}

//*****************************************************************************
//
// ESC_readDWord
//
//*****************************************************************************
uint32_t
ESC_readDWord(uint16_t address)
{
    uint32_t dWordValue;

    //
    // Disables interrupts
    //
    DINT;

    //
    // Read 32-bit address from ESC memory
    //
    dWordValue = ESC_readDWordISR(address);

    //
    // Enable interrupts
    //
    EINT;

    //
    // Return value
    //
    return(dWordValue);
}

//*****************************************************************************
//
// ESC_readWordISR
//
//*****************************************************************************
uint16_t
ESC_readWordISR(uint16_t address)
{
    //
    // Read 16-bit address from ESC memory
    //
    return(HWREGH(ESC_BASE + (address / 2U)));
}

//*****************************************************************************
//
// ESC_readWord
//
//*****************************************************************************
uint16_t
ESC_readWord(uint16_t address)
{
    uint16_t wordValue;

    //
    // Disables interrupts
    //
    DINT;

    //
    // Read 16-bit address from ESC memory
    //
    wordValue = ESC_readWordISR(address);

    //
    // Enable interrupts
    //
    EINT;

    //
    // Return value
    //
    return(wordValue);
}

//*****************************************************************************
//
// ESC_writeBlockISR
//
//*****************************************************************************
void
ESC_writeBlockISR(ESCMEM_ADDR *pData, uint16_t address, uint16_t len)
{
    uint16_t wordValue;

    //
    // Create pointer to ESC Address
    //
    void * escDest = (void *)(ESC_BASE + (uint32_t)(address / 2U));

    //
    // Determine if length (in bytes) is even or odd
    //
    if((len & 0x1U) == 0x1U)
    {
        //
        // Odd Length
        //

        //
        // Copy even bytes of buffer data to ESC memory.
        // Convert length to words.
        //
        memcpy(escDest, pData, (size_t)((len - 1U) >> 1U));

        //
        // Read last 16-bit word
        //
        wordValue = ESC_readWordISR(address + (len - 1U));

        //
        // Modify word data and set new data
        //
        wordValue &= ESC_M_MSB;
        wordValue |= (pData[((len - 1U) / 2U)] & ESC_M_LSB);

        //
        // Write modified value to ESC destination
        //
        ESC_writeWordISR(wordValue, (address + (len - 1U)));
    }
    else
    {
        //
        // Even Length
        //

        //
        // Copy buffer data to ESC memory. Convert length to words.
        //
        memcpy(escDest, pData, (size_t)(len >> 1U));
    }
}

//*****************************************************************************
//
// ESC_writeBlock
//
//*****************************************************************************
void
ESC_writeBlock(ESCMEM_ADDR *pData, uint16_t address, uint16_t len)
{
    //
    // Disables interrupts
    //
    DINT;

    //
    // Write data buffer into ESC memory
    //
    ESC_writeBlockISR(pData, address, len);

    //
    // Enable interrupts
    //
    EINT;
}

//*****************************************************************************
//
// ESC_writeDWordISR
//
//*****************************************************************************
void
ESC_writeDWordISR(uint32_t dWordValue, uint16_t address)
{
    //
    // Write two 16-bit words to ESC memory
    //
    HWREG(ESC_BASE + (address / 2U)) = dWordValue;
}

//*****************************************************************************
//
// ESC_writeDWord
//
//*****************************************************************************
void
ESC_writeDWord(uint32_t dWordValue, uint16_t address)
{
    //
    // Disables interrupts
    //
    DINT;

    //
    // Write two 16-words into ESC memory
    //
    ESC_writeDWordISR(dWordValue, address);

    //
    // Enable interrupts
    //
    EINT;
}

//*****************************************************************************
//
// ESC_writeWordISR
//
//*****************************************************************************
void
ESC_writeWordISR(uint16_t wordValue, uint16_t address)
{
    //
    // Write 16-bit word into ESC memory
    //
    HWREGH(ESC_BASE + (address / 2U)) = wordValue;
}

//*****************************************************************************
//
// ESC_writeWord
//
//*****************************************************************************
void
ESC_writeWord(uint16_t wordValue, uint16_t address)
{
    //
    // Disables interrupts
    //
    DINT;

    //
    // Write one 16-word into ESC memory
    //
    ESC_writeWordISR(wordValue, address);

    //
    // Enable interrupts
    //
    EINT;
}

//*****************************************************************************
//
// ESC_setLed
//
//*****************************************************************************
void
ESC_setLed(uint16_t runLed, uint16_t errLed)
{
    //
    // Set/Clear Run LED
    //
    GPIO_writePin(ESC_RUN_LED_GPIO, (uint32_t)(runLed ^ 0x1U));

    //
    // Set/Clear Error LED
    //
    GPIO_writePin(ESC_ERR_LED_GPIO, (uint32_t)(errLed ^ 0x1U));
}

#ifdef PDI_HAL_TEST
//*****************************************************************************
//
// HAL_initWriteBlockData
//
//*****************************************************************************
void HAL_initWriteBlockData(void)
{
    uint16_t i;

    //
    // Initialize write block data array
    //
    for(i = 0U; i < (ESC_HAL_TEST_BLOCK_LENGTH / 4U); i++)
    {
        ESC_writeBlockData[i] = 0x1234ABCDUL;
    }
}

//*****************************************************************************
//
// HAL_clearReadBlockData
//
//*****************************************************************************
void HAL_clearReadBlockData(void)
{
    uint16_t i;

    //
    // Clear read block data array
    //
    for(i = 0U; i < (ESC_HAL_TEST_BLOCK_LENGTH / 4U); i++)
    {
        ESC_readBlockData[i] = 0x0UL;
    }
}

//*****************************************************************************
//
// HAL_testBlockData
//
//*****************************************************************************
uint16_t HAL_testBlockData(uint16_t length)
{
    uint16_t i;
    uint16_t * writeData = (uint16_t *)(&ESC_writeBlockData[0]);
    uint16_t * readData = (uint16_t *)(&ESC_readBlockData[0]);

    //
    // Check if odd length of bytes
    //
    if((length & 0x1U) == 0x1U)
    {
        //
        // Odd Length of Bytes
        //

        //
        // Check that data written and data read match
        //
        for(i = 0U; i < ((length - 1U) / 2U); i++)
        {
            if(*writeData != *readData)
            {
                return(ESC_HAL_BLOCK_TEST_FAIL);
            }

            writeData++;
            readData++;
        }

        //
        // Check last byte
        //
        if(((*writeData) & ESC_M_LSB) != ((*readData) & ESC_M_LSB))
        {
            return(ESC_HAL_BLOCK_TEST_FAIL);
        }
    }
    else
    {
        //
        // Even Length of Bytes
        //

        //
        // Check that data written and data read match
        //
        for(i = 0U; i < (length / 2U); i++)
        {
            if(*writeData != *readData)
            {
                return(ESC_HAL_BLOCK_TEST_FAIL);
            }

            writeData++;
            readData++;
        }
    }

    return(ESC_HAL_BLOCK_TEST_PASS);
}

//*****************************************************************************
//
// ESC_setupPDITestInterface
//
//*****************************************************************************
void
ESC_setupPDITestInterface(void)
{
    uint16_t currentAddress = 0x0U;
    uint32_t doubleWordData = 0x0UL;
    uint16_t wordData = 0x0U;

    //
    // Setup and add various ESC register byte addresses to monitor
    //
    ESC_debugInitESCRegLogs();
    ESC_debugAddESCRegsAddress(0x0U);     // Type, Revision
    ESC_debugAddESCRegsAddress(0x2U);     // Build
    ESC_debugAddESCRegsAddress(0x4U);     // FMMUs, SyncManagers Supported
    ESC_debugAddESCRegsAddress(0x8U);     // ESC Supported Features
    ESC_debugAddESCRegsAddress(0x100U);   // DL Control
    ESC_debugAddESCRegsAddress(0x102U);   // DL Control (Extended)
    ESC_debugAddESCRegsAddress(0x110U);   // DL Status
    ESC_debugAddESCRegsAddress(0x310U);   // Lost Link Counter 1
    ESC_debugAddESCRegsAddress(0x312U);   // Lost Link Counter 2
    ESC_debugAddESCRegsAddress(0x510U);   // MII Control/Status
    ESC_debugAddESCRegsAddress(0x512U);   // PHY Address
    ESC_debugAddESCRegsAddress(0x514U);   // PHY Data
    ESC_debugAddESCRegsAddress(0x516U);   // MII ECAT Access State
    ESC_debugAddESCRegsAddress(0x518U);   // PHY Port Status (1)
    ESC_debugAddESCRegsAddress(0x51AU);   // PHY Port Status (2)
    ESC_debugAddESCRegsAddress(0x1000U);  // First data word of ESC RAM

    //
    // Check that correct PDI type (ASYNC16) is configured
    //
    if((ESC_readWord(ESC_O_PDI_CONTROL) & ESC_PDI_CONTROL_ASYNC16) !=
       ESC_PDI_CONTROL_ASYNC16)
    {
        //
        // PDI not operational or incorrect
        //
        while(1)
        {
            //
            // Toggle Error
            //
            ESC_signalFail();
        }
    }

    //
    // Perform PDI read and write tests for entire ESC PDI RAM range
    //
    for(currentAddress = ESC_PDI_RAM_START_ADDRESS_OFFSET;
        currentAddress <= ESC_PDI_RAM_END_ADDRESS_OFFSET;
        currentAddress += 4U)
    {
        //
        // Read DWord and Write DWord API Tests
        //
        doubleWordData = ESC_readDWord(currentAddress);
        ESC_writeDWord(0xABCD1234UL, currentAddress);
        doubleWordData = ESC_readDWord(currentAddress);

        if(doubleWordData != 0xABCD1234UL)
        {
            while(1)
            {
                //
                // Toggle Error
                //
                ESC_signalFail();
            }
        }

        doubleWordData = ESC_readDWordISR(currentAddress);
        ESC_writeDWordISR(0x1A2B3C4DUL, currentAddress);
        doubleWordData = ESC_readDWordISR(currentAddress);

        if(doubleWordData != 0x1A2B3C4DUL)
        {
            while(1)
            {
                //
                // Toggle Error
                //
                ESC_signalFail();
            }
        }

        //
        // Read Word and Write Word API Tests
        //
        wordData = ESC_readWord(currentAddress);
        ESC_writeWord(0x6789U, currentAddress);
        wordData = ESC_readWord(currentAddress);

        if(wordData != 0x6789U)
        {
            while(1)
            {
                //
                // Toggle Error
                //
                ESC_signalFail();
            }
        }

        wordData = ESC_readWordISR(currentAddress);
        ESC_writeWordISR(0x5A5AU, currentAddress);
        wordData = ESC_readWordISR(currentAddress);

        if(wordData != 0x5A5AU)
        {
            while(1)
            {
                //
                // Toggle Error
                //
                ESC_signalFail();
            }
        }
    }

    //
    // Setup for read/write block API Tests
    //
    HAL_initWriteBlockData();

    //
    // Perform even length write and read block (non-ISR) API Test
    //
    ESC_writeBlock((uint16_t *)(&ESC_writeBlockData[0]),
                   ESC_PDI_RAM_START_ADDRESS_OFFSET,
                   ESC_HAL_TEST_BLOCK_LENGTH);
    ESC_readBlock((uint16_t *)(&ESC_readBlockData[0]),
                  ESC_PDI_RAM_START_ADDRESS_OFFSET,
                  ESC_HAL_TEST_BLOCK_LENGTH);

    if(HAL_testBlockData(ESC_HAL_TEST_BLOCK_LENGTH) != ESC_HAL_BLOCK_TEST_PASS)
    {
        while(1)
        {
            //
            // Toggle Error
            //
            ESC_signalFail();
        }
    }

    HAL_clearReadBlockData();

    //
    // Perform even length write and read block API Test
    //
    ESC_writeBlockISR((uint16_t *)(&ESC_writeBlockData[0]),
                      (ESC_PDI_RAM_START_ADDRESS_OFFSET + 0x1000U),
                      ESC_HAL_TEST_BLOCK_LENGTH);
    ESC_readBlockISR((uint16_t *)(&ESC_readBlockData[0]),
                     (ESC_PDI_RAM_START_ADDRESS_OFFSET + 0x1000U),
                     ESC_HAL_TEST_BLOCK_LENGTH);

    if(HAL_testBlockData(ESC_HAL_TEST_BLOCK_LENGTH) != ESC_HAL_BLOCK_TEST_PASS)
    {
        while(1)
        {
            //
            // Toggle Error
            //
            ESC_signalFail();
        }
    }

    HAL_clearReadBlockData();

    //
    // Perform odd length write and read block (non-ISR) API Test
    //
    ESC_writeBlock((uint16_t *)(&ESC_writeBlockData[0]),
                   (ESC_PDI_RAM_START_ADDRESS_OFFSET + 0x2000U),
                   (ESC_HAL_TEST_BLOCK_LENGTH - 1U));
    ESC_readBlock((uint16_t *)(&ESC_readBlockData[0]),
                  (ESC_PDI_RAM_START_ADDRESS_OFFSET + 0x2000U),
                  (ESC_HAL_TEST_BLOCK_LENGTH - 1U));

    if(HAL_testBlockData((ESC_HAL_TEST_BLOCK_LENGTH - 1U)) !=
       ESC_HAL_BLOCK_TEST_PASS)
    {
        while(1)
        {
            //
            // Toggle Error
            //
            ESC_signalFail();
        }
    }

    HAL_clearReadBlockData();

    //
    // Perform odd length write and read block API Test
    //
    ESC_writeBlockISR((uint16_t *)(&ESC_writeBlockData[0]),
                      (ESC_PDI_RAM_START_ADDRESS_OFFSET + 0x3000U),
                      (ESC_HAL_TEST_BLOCK_LENGTH - 1U));
    ESC_readBlockISR((uint16_t *)(&ESC_readBlockData[0]),
                     (ESC_PDI_RAM_START_ADDRESS_OFFSET + 0x3000U),
                     (ESC_HAL_TEST_BLOCK_LENGTH - 1U));

    if(HAL_testBlockData((ESC_HAL_TEST_BLOCK_LENGTH - 1U)) !=
       ESC_HAL_BLOCK_TEST_PASS)
    {
        while(1)
        {
            //
            // Toggle Error
            //
            ESC_signalFail();
        }
    }

    //
    // Pass
    //
    ESC_signalPass();
}

//*****************************************************************************
//
// ESC_debugUpdateESCRegLogs
//
//*****************************************************************************
void
ESC_debugUpdateESCRegLogs(void)
{
    uint16_t i = 0U;

    //
    // Update ESC register data into debug array
    //
    while(ESC_escRegs[i].address != 0xFFFFU)
    {
        ESC_escRegs[i].data = ESC_readWord(ESC_escRegs[i].address);
        i++;
    }
}

//*****************************************************************************
//
// ESC_debugAddESCRegsAddress
//
//*****************************************************************************
void
ESC_debugAddESCRegsAddress(uint16_t address)
{
    uint16_t i = 0U;

    //
    // Add ESC Register Address to debug array
    //
    for(i = 0U; i < ESC_HAL_TEST_DEBUG_REGS_LENGTH; i++)
    {
        if(ESC_escRegs[i].address == 0xFFFFU)
        {
            //
            // Assign byte address to struct
            //
            ESC_escRegs[i].address = address;
            return;
        }
    }
}

//*****************************************************************************
//
// ESC_debugInitESCRegLogs
//
//*****************************************************************************
void
ESC_debugInitESCRegLogs(void)
{
    uint16_t i = 0U;

    //
    // Initialize ESC register debug array
    //
    for(i = 0U; i < ESC_HAL_TEST_DEBUG_REGS_LENGTH; i++)
    {
        ESC_escRegs[i].address = 0xFFFFU;
        ESC_escRegs[i].data = 0xFFFFU;
    }
}

//*****************************************************************************
//
// ESC_signalPass
//
//*****************************************************************************
void
ESC_signalPass(void)
{
    //
    // Turn on controlCARD LEDs
    //
    GPIO_writePin(CCARD_LED_1_GPIO, 0UL);
    GPIO_writePin(CCARD_LED_2_GPIO, 0UL);
}

//*****************************************************************************
//
// ESC_signalFail
//
//*****************************************************************************
void
ESC_signalFail(void)
{
    //
    // Toggle controlCARD LEDs and delay
    //
    GPIO_togglePin(CCARD_LED_1_GPIO);
    GPIO_togglePin(CCARD_LED_2_GPIO);

    DEVICE_DELAY_US((uint32_t)(500000));
}

//*****************************************************************************
//
// ESC_passFailSignalSetup
//
//*****************************************************************************
void
ESC_passFailSignalSetup(void)
{
    //
    // Set LED GPIOs to output mode
    //
    GPIO_setDirectionMode(CCARD_LED_1_GPIO, GPIO_DIR_MODE_OUT);
    GPIO_setDirectionMode(CCARD_LED_2_GPIO, GPIO_DIR_MODE_OUT);

    //
    // Turn off controlCARD LEDs
    //
    GPIO_writePin(CCARD_LED_1_GPIO, 1UL);
    GPIO_writePin(CCARD_LED_2_GPIO, 1UL);
}
#endif // PDI_HAL_TEST

//*****************************************************************************
//
// ESC_loadedCheckEEPROM
//
//*****************************************************************************
uint16_t
ESC_loadedCheckEEPROM(void)
{
    uint16_t status;

    //
    // Get ESC DL Status register
    //
    status = ESC_readWord(ESC_O_DL_STATUS);

    //
    // Check if EEPROM is loaded
    //
    if((status & ESC_DL_STATUS_EEPROMLOAD_M) == ESC_DL_STATUS_EEPROMLOAD_M)
    {
        //
        // Get ESC EEPROM Status register
        //
        status = ESC_readWord(ESC_O_EEPROM_STATUS);

        //
        // Check if EEPROM is loaded and device information is okay
        //
        if((status & ESC_EEPROM_STATUS_EEPROMLOAD_M) == ESC_EEPROM_SUCCESS)
        {
            return(ESC_EEPROM_SUCCESS);
        }
        else
        {
            return(ESC_EEPROM_LOAD_ERROR);
        }
    }
    else
    {
        //
        // DL Status indicated EEPROM is not loaded
        //
        return(ESC_EEPROM_NOT_LOADED);
    }
}

//*****************************************************************************
//
// ESC_resetESC
//
//*****************************************************************************
void
ESC_resetESC(void)
{
    SysCtl_resetPeripheral(SYSCTL_PERIPH_RES_ECAT);
}

//*****************************************************************************
//
// ESC_holdESCInReset
//
//*****************************************************************************
void
ESC_holdESCInReset(void)
{
    //
    // Put ESC in reset
    //
    EALLOW;
    HWREGH(DEVCFG_BASE + SYSCTL_O_SOFTPRES23) |= SYSCTL_SOFTPRES23_ETHERCAT;
    EDIS;
}

//*****************************************************************************
//
// ESC_releaseESCReset
//
//*****************************************************************************
void
ESC_releaseESCReset(void)
{
    //
    // Release from reset
    //
    EALLOW;
    HWREGH(DEVCFG_BASE + SYSCTL_O_SOFTPRES23) &= (~SYSCTL_SOFTPRES23_ETHERCAT);
    EDIS;
}

//*****************************************************************************
//
// ESC_initHW
//
//*****************************************************************************
uint16_t
ESC_initHW(void)
{
    //
    // Set application-specific timeout for waiting for EEPROM to load
    // and one for waiting for memory initialization
    // (End user can adjust as needed)
    //
    uint16_t eepromTimeOut = 0x1000U;
    uint16_t memoryTimeOut = 0x300U;

    //
    // Disable the watchdog
    //
    SysCtl_disableWatchdog();

#ifdef _FLASH
    //
    // Copy time critical code and flash setup code to RAM. This includes the
    // following functions: Flash_initModule();
    //
    // The RamfuncsLoadStart, RamfuncsLoadSize, and RamfuncsRunStart symbols
    // are created by the linker. Refer to the device .cmd file.
    //
    memcpy(&RamfuncsRunStart, &RamfuncsLoadStart, (size_t)&RamfuncsLoadSize);

    //
    // Call Flash Initialization to setup flash waitstates. This function must
    // reside in RAM.
    //
    Flash_initModule(FLASH0CTRL_BASE, FLASH0ECC_BASE, DEVICE_FLASH_WAITSTATES);
#endif

    //
    // Set up device clock
    //
    SysCtl_setClock(DEVICE_SETCLOCK_CFG);

    //
    // Make sure the LSPCLK divider is set to the default (divide by 4)
    //
    SysCtl_setLowSpeedClock(SYSCTL_LSPCLK_PRESCALE_4);

    //
    // Turn on all peripherals and initialize GPIOs
    //
    Device_enableAllPeripherals();
    Device_initGPIO();

    //
    // Setup AUX Clock for ECAT and CM
    // Configured to 500MHz raw ((20 * 25 IMULT) /1)
    //
    SysCtl_setAuxClock(SYSCTL_AUXPLL_ENABLE | SYSCTL_AUXPLL_OSCSRC_XTAL |
                       SYSCTL_AUXPLL_IMULT(25) | SYSCTL_AUXPLL_FMULT_0 |
                       SYSCTL_AUXPLL_DIV_1);

    //
    // Configure GPIOs for ECAT
    //

    //
    // PHY CLK
    //
    GPIO_setPinConfig(GPIO_154_ECAT_PHY_CLK);

    //
    // PHY Reset
    //
    GPIO_setPinConfig(GPIO_155_ECAT_PHY_RESETN);

    //
    // I2C for EEPROM
    //
    GPIO_setPinConfig(GPIO_150_ECAT_I2C_SDA);
    GPIO_setQualificationMode(150, GPIO_QUAL_ASYNC);
    GPIO_setPadConfig(150, GPIO_PIN_TYPE_PULLUP);
    GPIO_setPinConfig(GPIO_151_ECAT_I2C_SCL);
    GPIO_setQualificationMode(151, GPIO_QUAL_ASYNC);
    GPIO_setPadConfig(151, GPIO_PIN_TYPE_PULLUP);

    //
    // P0 TX and RX DATA
    //
    GPIO_setPinConfig(GPIO_158_ECAT_TX0_DATA0);
    GPIO_setQualificationMode(158, GPIO_QUAL_ASYNC);
    GPIO_setPinConfig(GPIO_159_ECAT_TX0_DATA1);
    GPIO_setQualificationMode(159, GPIO_QUAL_ASYNC);
    GPIO_setPinConfig(GPIO_160_ECAT_TX0_DATA2);
    GPIO_setQualificationMode(160, GPIO_QUAL_ASYNC);
    GPIO_setPinConfig(GPIO_161_ECAT_TX0_DATA3);
    GPIO_setQualificationMode(161, GPIO_QUAL_ASYNC);
    GPIO_setPinConfig(GPIO_165_ECAT_RX0_DATA0);
    GPIO_setQualificationMode(165, GPIO_QUAL_ASYNC);
    GPIO_setPinConfig(GPIO_166_ECAT_RX0_DATA1);
    GPIO_setQualificationMode(166, GPIO_QUAL_ASYNC);
    GPIO_setPinConfig(GPIO_167_ECAT_RX0_DATA2);
    GPIO_setQualificationMode(167, GPIO_QUAL_ASYNC);
    GPIO_setPinConfig(GPIO_168_ECAT_RX0_DATA3);
    GPIO_setQualificationMode(168, GPIO_QUAL_ASYNC);

    //
    // P0 TX Enable, RX DV, RX ERR
    //
    GPIO_setPinConfig(GPIO_156_ECAT_TX0_ENA);
    GPIO_setQualificationMode(156, GPIO_QUAL_ASYNC);
    GPIO_setPinConfig(GPIO_162_ECAT_RX0_DV);
    GPIO_setQualificationMode(162, GPIO_QUAL_ASYNC);
    GPIO_setPinConfig(GPIO_164_ECAT_RX0_ERR);
    GPIO_setPadConfig(164, GPIO_PIN_TYPE_STD);

    //
    // P0 TX and RX Clk
    //
    GPIO_setPinConfig(GPIO_157_ECAT_TX0_CLK);
    GPIO_setQualificationMode(157, GPIO_QUAL_ASYNC);
    GPIO_setPinConfig(GPIO_163_ECAT_RX0_CLK);
    GPIO_setQualificationMode(163, GPIO_QUAL_ASYNC);

    //
    // P0 Linkstatus and Link Active LED
    //
    GPIO_setPinConfig(GPIO_148_ECAT_PHY0_LINKSTATUS);
    GPIO_setPadConfig(148, GPIO_PIN_TYPE_STD);
    GPIO_setPinConfig(GPIO_143_ECAT_LED_LINK0_ACTIVE);
    GPIO_setQualificationMode(143, GPIO_QUAL_ASYNC);
    GPIO_setPadConfig(143, GPIO_PIN_TYPE_INVERT);

    //
    // P0+P1 MDIO CLK and Data
    //
    GPIO_setPinConfig(GPIO_152_ECAT_MDIO_CLK);
    GPIO_setPinConfig(GPIO_153_ECAT_MDIO_DATA);

    //
    // P1 TX and RX DATA
    //
    GPIO_setPinConfig(GPIO_131_ECAT_TX1_DATA0);
    GPIO_setQualificationMode(131, GPIO_QUAL_ASYNC);
    GPIO_setPinConfig(GPIO_132_ECAT_TX1_DATA1);
    GPIO_setQualificationMode(132, GPIO_QUAL_ASYNC);
    GPIO_setPinConfig(GPIO_134_ECAT_TX1_DATA2);
    GPIO_setQualificationMode(134, GPIO_QUAL_ASYNC);
    GPIO_setPinConfig(GPIO_135_ECAT_TX1_DATA3);
    GPIO_setQualificationMode(135, GPIO_QUAL_ASYNC);
    GPIO_setPinConfig(GPIO_139_ECAT_RX1_DATA0);
    GPIO_setQualificationMode(139, GPIO_QUAL_ASYNC);
    GPIO_setPinConfig(GPIO_140_ECAT_RX1_DATA1);
    GPIO_setQualificationMode(140, GPIO_QUAL_ASYNC);
    GPIO_setPinConfig(GPIO_141_ECAT_RX1_DATA2);
    GPIO_setQualificationMode(141, GPIO_QUAL_ASYNC);
    GPIO_setPinConfig(GPIO_142_ECAT_RX1_DATA3);
    GPIO_setQualificationMode(142, GPIO_QUAL_ASYNC);

    //
    // P1 TX Enable, RX DV, RX ERR
    //
    GPIO_setPinConfig(GPIO_129_ECAT_TX1_ENA);
    GPIO_setQualificationMode(129, GPIO_QUAL_ASYNC);
    GPIO_setPinConfig(GPIO_136_ECAT_RX1_DV);
    GPIO_setQualificationMode(136, GPIO_QUAL_ASYNC);
    GPIO_setPinConfig(GPIO_138_ECAT_RX1_ERR);
    GPIO_setPadConfig(138, GPIO_PIN_TYPE_STD);

    //
    // P1 TX and RX Clk
    //
    GPIO_setPinConfig(GPIO_130_ECAT_TX1_CLK);
    GPIO_setQualificationMode(130, GPIO_QUAL_ASYNC);
    GPIO_setPinConfig(GPIO_137_ECAT_RX1_CLK);
    GPIO_setQualificationMode(137, GPIO_QUAL_ASYNC);

    //
    // P1 Linkstatus and Link Active LED
    //
    GPIO_setPinConfig(GPIO_149_ECAT_PHY1_LINKSTATUS);
    GPIO_setPadConfig(149, GPIO_PIN_TYPE_PULLUP);
    GPIO_setPinConfig(GPIO_144_ECAT_LED_LINK1_ACTIVE);
    GPIO_setQualificationMode(144, GPIO_QUAL_ASYNC);
    GPIO_setPadConfig(144, GPIO_PIN_TYPE_INVERT);

    //
    // Sync and Latch
    //
    GPIO_setPinConfig(GPIO_125_ECAT_LATCH0);
    GPIO_setPinConfig(GPIO_126_ECAT_LATCH1);
    GPIO_setPinConfig(GPIO_127_ECAT_SYNC0);
    GPIO_setPinConfig(GPIO_128_ECAT_SYNC1);
    GPIO_setDirectionMode(127, GPIO_DIR_MODE_OUT);
    GPIO_setDirectionMode(128, GPIO_DIR_MODE_OUT);

    //
    // Set GPIO direction for ECAT RUN/ERR LEDs
    //
    GPIO_setDirectionMode(ESC_RUN_LED_GPIO, GPIO_DIR_MODE_OUT);
    GPIO_setDirectionMode(ESC_ERR_LED_GPIO, GPIO_DIR_MODE_OUT);

    //
    // Initialize PIE and clear PIE registers. Disables CPU interrupts.
    //
    Interrupt_initModule();

    //
    // Initialize the PIE vector table with pointers to the shell Interrupt
    // Service Routines (ISR).
    //
    Interrupt_initVectorTable();

    //
    // Register EtherCAT Interrupt Handlers
    //
    Interrupt_register(INT_ECAT, &ESC_applicationLayerHandler);
    Interrupt_register(INT_ECATSYNC0, &ESC_applicationSync0Handler);
    Interrupt_register(INT_ECATSYNC1, &ESC_applicationSync1Handler);

    //
    // Enable ECAT/PDI, Sync0, and Sync1 interrupts in CPU
    //
    Interrupt_enable(INT_ECAT);
    Interrupt_enable(INT_ECATSYNC0);
    Interrupt_enable(INT_ECATSYNC1);

    //
    // Configure and Start timer
    //
    CPUTimer_setPeriod(CPUTIMER0_BASE, 0xFFFFFFFFUL);
    CPUTimer_setPreScaler(CPUTIMER0_BASE, 0U);
    CPUTimer_startTimer(CPUTIMER0_BASE);

#ifdef PDI_HAL_TEST
    //
    // Enable Pass, fail signals
    //
    ESC_passFailSignalSetup();
#endif // PDI_HAL_TEST

    //
    // Aux = 500MHz and use /5 to get 100MHz for ECAT IP
    // (There is a built in /4 to get 25MHz for PHY when using
    //  internal clocking for PHY)
    //
    SysCtl_setECatClk(SYSCTL_ECATCLKOUT_DIV_5, SYSCTL_SOURCE_AUXPLL,
                      ESC_USE_INT_PHY_CLK);

    //
    // Configure EEPROM Size for 16K bits or less
    //
    ESCSS_configureEEPROMSize(ESC_SS_CONFIG_BASE, ESCSS_LESS_THAN_16K);

    //
    // Reset ESC
    //
    ESC_resetESC();

#ifdef PDI_HAL_TEST
    //
    // Enable the debug access
    //
    while((HWREGH(ESC_SS_BASE + ESCSS_O_ACCESS_CTRL) &
           ESCSS_ACCESS_CTRL_ENABLE_DEBUG_ACCESS) !=
          ESCSS_ACCESS_CTRL_ENABLE_DEBUG_ACCESS)
    {
        ESCSS_enableDebugAccess(ESC_SS_BASE);
    }
#endif // PDI_HAL_TEST

    //
    // Initialize ESCSS Memory
    //
    ESCSS_initMemory(ESC_SS_BASE);

    //
    // Wait for ESCSS memory initialization to complete
    //
    if(ESCSS_getMemoryInitDoneStatusBlocking(ESC_SS_BASE, memoryTimeOut) !=
       ESCSS_API_SUCCESS)
    {
        return(ESC_HW_INIT_FAIL);
    }

    //
    // Wait (with time out) for EEPROM to be loaded
    //
    while(ESC_loadedCheckEEPROM() != ESC_EEPROM_SUCCESS)
    {
        eepromTimeOut--;

        //
        // On time out, return fail
        //
        if(eepromTimeOut == 0U)
        {
            return(ESC_HW_INIT_FAIL);
        }
    }

    //
    // Initialize AL Event Mask to zero to prevent ESC interrupts until
    // set during stack state transition to SAFEOP
    //
    ESC_writeDWord(0UL, ESC_O_AL_EVENTMASK);

    //
    // Enable ECAT/PDI, Sync0, and Sync1 interrupts in ESCSS
    //
    ESCSS_setMaskedInterruptStatus(ESC_SS_BASE,
                                   (ESCSS_INTR_MASK_IRQ_MASK |
                                    ESCSS_INTR_MASK_SYNC0_MASK |
                                    ESCSS_INTR_MASK_SYNC1_MASK));

    //
    // Connect ESCSS Sync0/1 signals to respective interrupts in PIE
    //
    ESCSS_configureSync0Connections(ESC_SS_BASE, ESCSS_SYNC0_CONFIG_C28X_PIE_EN,
                                    ESCSS_VALID_KEY_VALUE);
    ESCSS_configureSync1Connections(ESC_SS_BASE, ESCSS_SYNC1_CONFIG_C28X_PIE_EN,
                                    ESCSS_VALID_KEY_VALUE);

    //
    // Enable interrupts to CPU
    //
    EINT;

    return(ESC_HW_INIT_SUCCESS);
}

//*****************************************************************************
//
// ESC_releaseHW
//
//*****************************************************************************
void
ESC_releaseHW(void)
{
    //
    // Intentionally empty - Implementation is left to the end user
    //
}

//*****************************************************************************
//
// ESC_applicationLayerHandler
//
//*****************************************************************************
__interrupt void
ESC_applicationLayerHandler(void)
{
#ifdef ETHERCAT_STACK
#if AL_EVENT_ENABLED
    //
    // When stack is included and application event enabled, call stack PDI ISR
    //
    PDI_Isr();
#endif  // AL_EVENT_ENABLED
#endif  // ETHERCAT_STACK

    //
    // Acknowledge and clear interrupt in ESCSS
    //
    ESCSS_clearRawInterruptStatus(ESC_SS_BASE, ESCSS_INTR_CLR_IRQ_CLR);

    //
    // Acknowledge this interrupt located in PIE group 1
    //
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP1);
}

//*****************************************************************************
//
// ESC_applicationSync0Handler
//
//*****************************************************************************
__interrupt void
ESC_applicationSync0Handler(void)
{
#ifdef ETHERCAT_STACK
#if DC_SUPPORTED
    //
    // When stack is included and DC is enabled, call stack Sync0 ISR
    //
    Sync0_Isr();
#endif  // DC_SUPPORTED
#endif  // ETHERCAT_STACK

    //
    // Acknowledge and clear interrupt in ESCSS
    //
    ESCSS_clearRawInterruptStatus(ESC_SS_BASE, ESCSS_INTR_CLR_SYNC0_CLR);

    //
    // Acknowledge this interrupt located in PIE group 1
    //
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP1);
}

//*****************************************************************************
//
// ESC_applicationSync1Handler
//
//*****************************************************************************
__interrupt void
ESC_applicationSync1Handler(void)
{
#ifdef ETHERCAT_STACK
#if DC_SUPPORTED
    //
    // When stack is included and DC is enabled, call stack Sync1 ISR
    //
    Sync1_Isr();
#endif  // DC_SUPPORTED
#endif  // ETHERCAT_STACK

    //
    // Acknowledge and clear interrupt in ESCSS
    //
    ESCSS_clearRawInterruptStatus(ESC_SS_BASE, ESCSS_INTR_CLR_SYNC1_CLR);

    //
    // Acknowledge this interrupt located in PIE group 5
    //
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP5);
}

//
// End of File
//
