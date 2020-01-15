//###########################################################################
//
// FILE:   ethercat_slave_cm_hal.h
//
// TITLE:  CM EtherCAT HAL Driver.
//
// This contains the macros and prototypes for the CM HAL APIs required by
// EtherCAT stack as well as HAL PDI test application.
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

#ifndef ETHERCAT_SLAVE_CM_HAL_H
#define ETHERCAT_SLAVE_CM_HAL_H

//*****************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
//*****************************************************************************
#ifdef __cplusplus
extern "C"
{
#endif

//*****************************************************************************
//
//! \addtogroup esc_cm_hal_api ESC CM HAL
//! @{
//
//*****************************************************************************

//
// Included Files
//
#include "cm.h"
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#ifdef ETHERCAT_STACK
#include "ecat_def.h"
#endif // ETHERCAT_STACK

//
// ESC Registers Base Address
//
#define ESC_BASE             0x400A0000UL

//
// ESC Register Offsets
//
#define ESC_O_DL_STATUS      0x0110U
#define ESC_O_PDI_CONTROL    0x0140U
#define ESC_O_AL_EVENTMASK   0x0204U
#define ESC_O_EEPROM_STATUS  0x0502U

//
// ESC Register Masks
//
#define ESC_DL_STATUS_EEPROMLOAD_M     0x1U
#define ESC_EEPROM_STATUS_EEPROMLOAD_M 0x1000U

//
// Defines for Success and Failure returns during hardware initialization
//
#define ESC_HW_INIT_SUCCESS  0x0U
#define ESC_HW_INIT_FAIL     0xFFFFU

//
// Typedef for ESC Memory Address Access Size
//
typedef uint8_t ESCMEM_ADDR;

//
// Defines to EEPROM Loaded Status
//
#define ESC_EEPROM_SUCCESS    0x0U
#define ESC_EEPROM_NOT_LOADED 0xFFFFU
#define ESC_EEPROM_LOAD_ERROR 0xFFFEU

//
// Defines for EtherCAT LED GPIOs (controlCARD)
//
#define ESC_RUN_LED_GPIO      146U
#define ESC_ERR_LED_GPIO      145U

#ifdef PDI_HAL_TEST
//
// ESC PDI Control ASYNC Value
//
#define ESC_PDI_CONTROL_ASYNC16 0x8U

//
// ESC PDI RAM Start and End Address Offsets
//
#define ESC_PDI_RAM_START_ADDRESS_OFFSET 0x1000U
#define ESC_PDI_RAM_END_ADDRESS_OFFSET   0x4FFFU

//
// Defines for controlCARD LED GPIOs
//
#define CCARD_LED_1_GPIO     31U
#define CCARD_LED_2_GPIO     34U

//
// HAL Test Application Defines
//
#define ESC_HAL_TEST_DEBUG_REGS_LENGTH   20U
#define ESC_HAL_TEST_BLOCK_LENGTH        40U

//
// Read/Write Block Test Status
//
#define ESC_HAL_BLOCK_TEST_PASS 0x0U
#define ESC_HAL_BLOCK_TEST_FAIL 0xFFFFU

//
// HAL Test Application Structure
//
typedef struct
{
    uint16_t address;
    uint16_t data;
} ESC_DebugRegisters;

//
// Extern CM HAL Delay Function
//
extern void HAL_performDelay(void);

#endif // PDI_HAL_TEST

//
// Enable and Disable Global Interrupts
//
extern uint32_t _disable_IRQ();
extern uint32_t _enable_IRQ();

//
// Stack Functions
//
#ifdef ETHERCAT_STACK
extern void Sync0_Isr(void);
extern void PDI_Isr(void);
extern void Sync1_Isr(void);
#endif // ETHERCAT_STACK

//
// HAL function prototypes
//

//*****************************************************************************
//
//! Gets the Current Timer Value
//!
//! This function returns the current timer counter value from the CPU timer.
//!
//! \return Returns the 1's compliment of the timer counter register value
//
//*****************************************************************************
extern uint32_t ESC_getTimer(void);

//*****************************************************************************
//
//! Clears the Timer Value
//!
//! This function resets the timer counter.
//!
//! \return None
//
//*****************************************************************************
extern void ESC_clearTimer(void);

//*****************************************************************************
//
//! Get the Timer Increment Value
//!
//! This function returns a constant value of 125000UL for the timer increment
//! value as the CPU timer is configured to run at 125MHz.
//!
//! \return Returns a constant value depending on the max frequency of the
//! CPU timer
//
//*****************************************************************************
extern uint32_t ESC_timerIncPerMilliSec(void);

//*****************************************************************************
//
//! Reads the ESC Data into Local Buffer
//!
//! \param pData is the pointer to the local destination buffer.
//!        (Type of pointer depends on the host controller architecture,
//!         detailed in ecat_def.h or the Slave Stack Code Tool)
//! \param address is the EtherCAT slave controller offset address which
//!        specifies the offset within the ESC memory area in bytes.
//!        (Only valid addresses are used depending on ESC 8 bit, 16 bit, or
//!         32 bit access specified in ecat_def.h or the Slave Stack Code Tool)
//! \param len is the access size in bytes
//!
//! This function is used to access the ESC registers and the DPRAM area. The
//! function reads the requested number of bytes from the ESC address and copies
//! the data into the data buffer specified.
//!
//! \return None
//
//*****************************************************************************
extern void ESC_readBlockISR(ESCMEM_ADDR *pData, uint16_t address,
                             uint16_t len);

//*****************************************************************************
//
//! Reads the ESC Data into Local Buffer with Interrupts Disabled
//!
//! \param pData is the pointer to the local destination buffer.
//!        (Type of pointer depends on the host controller architecture,
//!         detailed in ecat_def.h or the Slave Stack Code Tool)
//! \param address is the EtherCAT slave controller offset address which
//!        specifies the offset within the ESC memory area in bytes.
//!        (Only valid addresses are used depending on ESC 8 bit, 16 bit, or
//!         32 bit access specified in ecat_def.h or the Slave Stack Code Tool)
//! \param len is the access size in bytes
//!
//! This function is used to access the ESC registers and the DPRAM area with
//! interrupts disabled. The function disables interrupts, reads the requested
//! number of bytes from the ESC address, copies the data into the data buffer
//! specified, and re-enables interrupts.
//!
//! \return None
//
//*****************************************************************************
extern void ESC_readBlock(ESCMEM_ADDR *pData, uint16_t address,
                          uint16_t len);

//*****************************************************************************
//
//! Reads two 16-bit words from ESC Memory
//!
//! \param address is the EtherCAT slave controller offset address in bytes.
//!        This must be a valid 32-bit aligned address boundary.
//!
//! This function reads two 16-bit words from the specified ESC address.
//!
//! \return Returns two 16-bit words
//
//*****************************************************************************
extern uint32_t ESC_readDWordISR(uint16_t address);

//*****************************************************************************
//
//! Reads two 16-bit words from ESC Memory with interrupts disabled
//!
//! \param address is the EtherCAT slave controller offset address in bytes.
//!        This must be a valid 32-bit aligned address boundary.
//!
//! This function disables interrupts, then reads two 16-bit words from the
//! specified ESC address, and re-enables interrupts.
//!
//! \return Returns two 16-bit words
//
//*****************************************************************************
extern uint32_t ESC_readDWord(uint16_t address);

//*****************************************************************************
//
//! Reads one 16-bit word from ESC Memory
//!
//! \param address is the EtherCAT slave controller offset address in bytes.
//!        This must be a valid 16-bit aligned address boundary.
//!
//! This function reads one 16-bit word from the specified ESC address.
//!
//! \return Returns 16-bit word value
//
//*****************************************************************************
extern uint16_t ESC_readWordISR(uint16_t address);

//*****************************************************************************
//
//! Reads one 16-bit word from ESC Memory with interrupts disabled
//!
//! \param address is the EtherCAT slave controller offset address in bytes.
//!        This must be a valid 16-bit aligned address boundary.
//!
//! This function disables interrupts, reads one 16-bit word from the specified
//! ESC address, and re-enables interrupts.
//!
//! \return Returns 16-bit word value
//
//*****************************************************************************
extern uint16_t ESC_readWord(uint16_t address);

//*****************************************************************************
//
//! Reads one byte from ESC Memory
//!
//! \param address is the EtherCAT slave controller offset address in bytes.
//!
//! This function reads one byte from the specified ESC address.
//!
//! \return Returns byte value
//
//*****************************************************************************
extern uint8_t ESC_readByteISR(uint16_t address);

//*****************************************************************************
//
//! Reads one byte from ESC Memory with interrupts disabled
//!
//! \param address is the EtherCAT slave controller offset address in bytes.
//!
//! This function disables interrupts, reads one byte from the specified ESC
//! address, and re-enables interrupts.
//!
//! \return Returns byte value
//
//*****************************************************************************
extern uint8_t ESC_readByte(uint16_t address);

//*****************************************************************************
//
//! Writes the Local Buffer Data into the ESC Memory
//!
//! \param pData is the pointer to the local source buffer.
//!        (Type of pointer depends on the host controller architecture,
//!         detailed in ecat_def.h or the Slave Stack Code Tool)
//! \param address is the EtherCAT slave controller offset address which
//!        specifies the offset within the ESC memory area in bytes.
//!        (Only valid addresses are used depending on ESC 8 bit, 16 bit, or
//!         32 bit access specified in ecat_def.h or the Slave Stack Code Tool)
//! \param len is the access size in bytes
//!
//! This function writes the requested number of bytes from the data buffer and
//! into the specified ESC addresses.
//!
//! \return None
//
//*****************************************************************************
extern void ESC_writeBlockISR(ESCMEM_ADDR *pData, uint16_t address,
                              uint16_t len);

//*****************************************************************************
//
//! Writes the Local Buffer Data into the ESC Memory with interrupts disabled
//!
//! \param pData is the pointer to the local source buffer.
//!        (Type of pointer depends on the host controller architecture,
//!         detailed in ecat_def.h or the Slave Stack Code Tool)
//! \param address is the EtherCAT slave controller offset address which
//!        specifies the offset within the ESC memory area in bytes.
//!        (Only valid addresses are used depending on ESC 8 bit, 16 bit, or
//!         32 bit access specified in ecat_def.h or the Slave Stack Code Tool)
//! \param len is the access size in bytes
//!
//! This function disables interrupts, writes the requested number of bytes
//! from the data buffer into the specified ESC addresses, and re-enables
//! interrupts.
//!
//! \return None
//
//*****************************************************************************
extern void ESC_writeBlock(ESCMEM_ADDR *pData, uint16_t address,
                           uint16_t len);

//*****************************************************************************
//
//! Writes two 16-bit words into ESC Memory
//!
//! \param dWordValue is the local 32-bit variable which contains the value
//!        that needs to be written.
//! \param address is the EtherCAT slave controller offset address in bytes.
//!        This must be a valid 32-bit aligned address boundary.
//!
//! This function writes two 16-bit words from \e dWordValue to the ESC
//! address.
//!
//! \return None
//
//*****************************************************************************
extern void ESC_writeDWordISR(uint32_t dWordValue, uint16_t address);

//*****************************************************************************
//
//! Writes two 16-bit words into ESC Memory with interrupts disabled
//!
//! \param dWordValue is the local 32-bit variable which contains the value
//!        that needs to be written.
//! \param address is the EtherCAT slave controller offset address in bytes.
//!        This must be a valid 32-bit aligned address boundary.
//!
//! This function disables interrupts, writes two 16-bit words from
//! \e dWordValue to the ESC address, and re-enables interrupts.
//!
//! \return None
//
//*****************************************************************************
extern void ESC_writeDWord(uint32_t dWordValue, uint16_t address);

//*****************************************************************************
//
//! Writes one 16-bit word into ESC Memory
//!
//! \param wordValue is the local 16-bit variable which contains the value to
//!        be written.
//! \param address is the EtherCAT slave controller offset address in bytes.
//!        This must be a valid 16-bit aligned address boundary.
//!
//! This function writes one 16-bit word from \e wordValue into the specified
//! ESC address.
//!
//! \return None
//
//*****************************************************************************
extern void ESC_writeWordISR(uint16_t wordValue, uint16_t address);

//*****************************************************************************
//
//! Writes one 16-bit word into ESC Memory with interrupts disabled
//!
//! \param wordValue is the local 16-bit variable which contains the value to
//!        be written.
//! \param address is the EtherCAT slave controller offset address in bytes.
//!        This must be a valid 16-bit aligned address boundary.
//!
//! This function disables interrupts, writes one 16-bit word from \e wordValue
//! into the specified ESC address, and re-enables interrupts.
//!
//! \return None
//
//*****************************************************************************
extern void ESC_writeWord(uint16_t wordValue, uint16_t address);

//*****************************************************************************
//
//! Write one byte into ESC Memory
//!
//! \param byteValue is the local 8-bit variable which contains the value to
//!        be written.
//! \param address is the EtherCAT slave controller offset address in bytes.
//!
//! This function writes one byte from \e byteValue into the specified ESC
//! address.
//!
//! \return None
//
//*****************************************************************************
extern void ESC_writeByteISR(uint8_t byteValue, uint16_t address);

//*****************************************************************************
//
//! Write one byte into ESC Memory with interrupts disabled
//!
//! \param byteValue is the local 8-bit variable which contains the value to
//!        be written.
//! \param address is the EtherCAT slave controller offset address in bytes.
//!
//! This function disables interrupts, writes one byte from \e byteValue into
//! the specified ESC address, and re-enables interrupts.
//!
//! \return None
//
//*****************************************************************************
extern void ESC_writeByte(uint8_t byteValue, uint16_t address);

//*****************************************************************************
//
//! Updates the EtherCAT Run and Error LEDs
//!
//! \param runLed is the EtherCAT run LED state
//! \param errLed is the EtherCAT error LED state
//!
//! This function updates the EtherCAT run and error LEDS (or EtherCAT status
//! LED).
//!
//! \note This is configured to use the LED GPIOs for the controlCARD.
//!
//! \return None
//
//*****************************************************************************
extern void ESC_setLed(uint8_t runLed, uint8_t errLed);

#ifdef PDI_HAL_TEST
//*****************************************************************************
//
//! Setup and run tests on the PDI Interface
//!
//! This function is optional for the non-HAL API Test application use cases
//! and is available for applications or users to perform a test of the PDI
//! interface. The function reads the PDI control registers, initializes an
//! array of registers that needs to be read from ESC and also performs read
//! write tests on all of the RAM in ESC using the HAL API.
//!
//! \note This function is only relevant for the HAL API Test application.
//!
//! \return None.
//
//*****************************************************************************
extern void ESC_setupPDITestInterface(void);

//*****************************************************************************
//
//! Reloads local RAM with ESC register Values
//!
//! This function is optional for the non-HAL API Test application use cases
//! and is available for applications or users to perform a load of pre-set ESC
//! registers in a loop by using PDI interface.
//!
//! \note This function is only relevant for the HAL API Test application.
//!
//! \return None.
//
//*****************************************************************************
extern void ESC_debugUpdateESCRegLogs(void);

//*****************************************************************************
//
//! Adds ESC Register Address to be read to RAM for Debug
//!
//! \param address is the ESC register or memory address that needs to be read
//!
//! This function is optional for the non-HAL API Test application use cases
//! and is available for applications or users to add a register to the pre-set
//! array of registers that are ready by the ESC_debugUpdateESCRegLogs()
//! function using the PDI interface.
//!
//! \note Only 16-bit reads are provided by the reference code.
//!
//! \note This function is only relevant for the HAL API Test application.
//!
//! \return None.
//
//*****************************************************************************
extern void ESC_debugAddESCRegsAddress(uint16_t address);

//*****************************************************************************
//
//! Initializes ESC Register Read Log Array
//!
//! This function is optional for the non-HAL API Test application use cases
//! and is available for applications or users to and initializes the registers
//! read log array to default 0xFFFF. This is called once during init time or
//! user can call it after every update to reset the previous read values in
//! the array.
//!
//! \note This function is only relevant for the HAL API Test application.
//!
//! \return None.
//
//*****************************************************************************
extern void ESC_debugInitESCRegLogs(void);

//*****************************************************************************
//
//! Signal Pass Status on ControlCARD LEDs
//!
//! This function provides a PASS signature on the LED GPIOs when the tests
//! complete successfully.
//!
//! \note This function is tied to the controlCARD as in the GPIOs used as
//!          per the controlCARD hardware design.
//!
//! \note This function is only relevant for the HAL API Test application.
//!
//! \return None.
//
//*****************************************************************************
extern void ESC_signalPass(void);

//*****************************************************************************
//
//! Signal Fail Status on ControlCARD LEDs
//!
//! This function provides a FAIL signature on the LED GPIOs when the tests
//! complete successfully.
//!
//! \note This function is tied to the controlCARD as in the GPIOs used as
//!          per the controlCARD hardware design.
//!
//! \note This function is only relevant for the HAL API Test application.
//!
//! \return None.
//
//*****************************************************************************
extern void ESC_signalFail(void);

//*****************************************************************************
//
//! Sets up the ControlCARD GPIOs for LEDs
//!
//! This function sets up the LED GPIOs that are used to signal the PASS/FAIL
//! conditions.
//!
//! \note This function is tied to the controlCARD as in the GPIOs used as
//!          per the controlCARD hardware design.
//!
//! \note This function is only relevant for the HAL API Test application.
//!
//! \return None.
//
//*****************************************************************************
extern void ESC_passFailSignalSetup(void);

#endif // PDI_HAL_TEST

//*****************************************************************************
//
//! Checks if EEPROM was Loaded
//!
//! This function checks if the EEPROM load happened properly or not. The
//! function reads the EEPROM LOADED register bit in the DL register as no
//! proper EEPROM loaded IO signal is available. Recommended to be called by
//! applications during start up and after an EEPROM reload happens.
//!
//! \note ESC RAM access via PDI is blocked until EEPROM happens correctly.
//!
//! \return Returns \b ESC_EEPROM_SUCCESS if EEPROM loaded successfully,
//! \b ESC_EEPROM_NOT_LOADED if EEPROM not loaded as per the ESC DL register
//! status, and \b ESC_EEPROM_LOAD_ERROR if EEPROM ESC control status register
//! indicates that EEPROM is not loaded and device information not available.
//
//*****************************************************************************
extern uint16_t ESC_loadedCheckEEPROM(void);

//*****************************************************************************
//
//! Reset the ESC
//!
//! This function resets the ESC peripheral.
//!
//! \return None.
//
//*****************************************************************************
extern void ESC_resetESC(void);

//*****************************************************************************
//
//! Hold ESC in Reset
//!
//! This function holds the ESC peripheral in reset.
//!
//! \return None.
//
//*****************************************************************************
extern void ESC_holdESCInReset(void);

//*****************************************************************************
//
//! Release ESC from Reset
//!
//! This function de-activates the ESC peripheral reset signal and brings ESC
//! out of reset.
//!
//! \return None.
//
//*****************************************************************************
extern void ESC_releaseESCReset(void);

//*****************************************************************************
//
//! Initializes the Device for EtherCAT
//!
//! This function initializes the host controller, interrupts, SYNC signals,
//! PDI, and other necessary peripherals.
//!
//! \return Returns \b ESC_HW_INIT_SUCCESS if initialization was successful and
//! \b ESC_HW_INIT_FAIL if an error occurred during initialization
//
//*****************************************************************************
extern uint16_t ESC_initHW(void);

//*****************************************************************************
//
//! Releases the Device Resources
//!
//! This function releases the allocated device resources.
//!
//! \note Implementation of this function is left to the end user and
//! currently performs no action.
//!
//! \return None
//
//*****************************************************************************
extern void ESC_releaseHW(void);

//*****************************************************************************
//
//! Application Layer Handler
//!
//! This function is the interrupt handler for EtherCAT application/PDI
//! interrupts.
//!
//! \return None
//
//*****************************************************************************
__interrupt void ESC_applicationLayerHandler(void);

//*****************************************************************************
//
//! Application Sync 0 Handler
//!
//! This function is the interrupt handler for EtherCAT SYNC0 interrupts.
//!
//! \return None
//
//*****************************************************************************
__interrupt void ESC_applicationSync0Handler(void);

//*****************************************************************************
//
//! Application Sync 1 Handler
//!
//! This function is the interrupt handler for EtherCAT SYNC1 interrupts.
//!
//! \return None
//
//*****************************************************************************
__interrupt void ESC_applicationSync1Handler(void);

//*****************************************************************************
//
// Close the Doxygen group.
//! @}
//
//*****************************************************************************

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif //  ETHERCAT_SLAVE_CM_HAL_H

//
// End of File
//
