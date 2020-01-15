//###########################################################################
//
// FILE:    bootloader_parallel.c
//
// TITLE:   Parallel Port I/O bootloader
//
// Functions involved in running Parallel I/O bootloader
//
// ------------------------------------------------------------------
// |Opt No.|  BOOTDEF      |  Dx GPIO       |  DSP Ctrl | Host Ctrl |
// ------------------------------------------------------------------
// |  0    |  0x00         | 89,90,58-62,88 |  91       |  92       |
// ------------------------------------------------------------------
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
// Defines
//
#define HOST_CTRL_GPIO   92U  // GPIO92 is the host control signal
                              // (will be configured as input pin)
#define DSP_CTRL_GPIO    91U  // GPIO91 is the DSP's control signal
                              // (will be configured as output pin)

#define PARALLEL_GPIO58  0x04000000UL
#define PARALLEL_GPIO59  0x08000000UL
#define PARALLEL_GPIO60  0x10000000UL
#define PARALLEL_GPIO61  0x20000000UL
#define PARALLEL_GPIO62  0x40000000UL
#define PARALLEL_GPIO88  0x01000000UL
#define PARALLEL_GPIO89  0x02000000UL
#define PARALLEL_GPIO90  0x04000000UL
#define PARALLEL_GPIO92  0x10000000UL

//
// Function Prototypes
//
uint16_t Parallel_GetWordData_8bit(void);
void Parallel_GPIOSelect(void);
uint16_t Parallel_readPortData(void);

//
// Parallel_Boot - This module is the main Parallel boot routine. It will load
//                 code via GP I/Os. This boot mode accepts 8-bit data. 8-bit
//                 data is expected to be the order LSB followed by MSB.
//
//                 This function returns a entry point address back
//                 to the system initialization routine which in turn calls
//                 the ExitBoot routine.
//
uint32_t Parallel_Boot(void)
{
    uint32_t entryAddress;
    uint16_t wordData;

    //
    // Setup for Parallel boot
    //
    Parallel_GPIOSelect();

    //
    // CPU1 Patch/Escape Point 12
    //
    entryAddress = CPU1BROM_TI_OTP_ESCAPE_POINT_12;
    if((entryAddress != 0xFFFFFFFFUL) &&
       (entryAddress != 0x00000000UL))
    {
        //
        // If OTP is programmed, then call OTP patch function
        //
        ((void (*)(void))entryAddress)();
    }

    //
    // Check for the key value. This version only
    // supports 8-bit data.
    //
    GetWordData = Parallel_GetWordData_8bit;
    wordData = GetWordData();

    if(wordData != BROM_EIGHT_BIT_HEADER)
    {
       return FLASH_ENTRY_POINT;
    }

    //
    // Read and discard the reserved words
    //
    ReadReservedFn();

    //
    // Get the entry point address
    //
    entryAddress = GetLongData();

    //
    // Load the data
    //
    CopyData();

    return entryAddress;
}

//
// Parallel_GetWordData_8bit - The 8-bit function is used if the input stream is
//                             an 8-bit input stream and the upper 8-bits of the
//                             GPIO port are ignored.  In the 8-bit case the
//                             first fetches the LSB and then the MSB from the
//                             GPIO port. These two bytes are then put together
//                             to form a single 16-bit word that is then passed
//                             back to the host. Note that in this case, the
//                             input stream from the host is in the order LSB
//                             followed by MSB
//
uint16_t Parallel_GetWordData_8bit(void)
{
    uint16_t wordData;

    //
    // This routine tells the host that the DSP is ready to
    // receive data.  The DSP then waits for the host to
    // signal that data is ready on the GP I/O port.
    //
    GPIO_writePin(DSP_CTRL_GPIO, 0U);
    while(GPIO_readPin(HOST_CTRL_GPIO) != 0U){}

    //
    // Get LSB
    //
    wordData = Parallel_readPortData();

    //
    // This routine tells the host that the DSP has received
    // the data.  The DSP then waits for the host to acknowledge
    // the receipt before continuing.
    //
    GPIO_writePin(DSP_CTRL_GPIO, 1U);
    while(GPIO_readPin(HOST_CTRL_GPIO) != 1U){}

    //
    // Fetch the MSB.
    //
    wordData = wordData & 0x00FFU;

    //
    // This routine tells the host that the DSP is ready to
    // receive data.  The DSP then waits for the host to
    // signal that data is ready on the GP I/O port.
    //
    GPIO_writePin(DSP_CTRL_GPIO, 0U);
    while(GPIO_readPin(HOST_CTRL_GPIO) != 0U){}

    wordData |= (Parallel_readPortData() << 8U);

    //
    // This routine tells the host that the DSP has received
    // the data.  The DSP then waits for the host to acknowledge
    // the receipt before continuing.
    //
    GPIO_writePin(DSP_CTRL_GPIO, 1U);
    while(GPIO_readPin(HOST_CTRL_GPIO) != 1U){}

    return wordData;
}

//
// Parallel_GPIOSelect - Configure the GPIOs used for Parallel IO bootloader
//
void Parallel_GPIOSelect(void)
{
    //
    // Enable Pullups on GPIO88,89,90,58-62
    //
    EALLOW;
    HWREG(GPIOCTRL_BASE + GPIO_O_GPBPUD) &= ~(PARALLEL_GPIO58 |
                                              PARALLEL_GPIO59 |
                                              PARALLEL_GPIO60 |
                                              PARALLEL_GPIO61 |
                                              PARALLEL_GPIO62);
    HWREG(GPIOCTRL_BASE + GPIO_O_GPCPUD) &= ~(PARALLEL_GPIO88 |
                                              PARALLEL_GPIO89 |
                                              PARALLEL_GPIO90);
    EDIS;

    //
    // Configure GPIO89,90,58-62,88,91,92 as GPIO
    //
    GPIO_setPinConfig(GPIO_89_GPIO89);
    GPIO_setPinConfig(GPIO_90_GPIO90);
    GPIO_setPinConfig(GPIO_58_GPIO58);
    GPIO_setPinConfig(GPIO_59_GPIO59);
    GPIO_setPinConfig(GPIO_60_GPIO60);
    GPIO_setPinConfig(GPIO_61_GPIO61);
    GPIO_setPinConfig(GPIO_62_GPIO62);
    GPIO_setPinConfig(GPIO_88_GPIO88);
    GPIO_setPinConfig(GPIO_91_GPIO91);
    GPIO_setPinConfig(GPIO_92_GPIO92);

    //
    // HOST_CTRL_GPIO is an input control from the Host
    // to the DSP Ack/Rdy
    // - may require an external pull-up
    //
    // DSP_CTRL_GPIO is an output from the DSP Ack/Rdy
    // - may require an external pull-up for host to correctly
    //   read "1" initially.
    //
    // DSP_CTRL_GPIO set to 1 initially
    // 0 = input   1 = output
    //

    //
    // Configure GPIO88,89,90,92,58-62 as input
    //
    EALLOW;
    HWREG(GPIOCTRL_BASE + GPIO_O_GPBDIR) &= ~(PARALLEL_GPIO58 |
                                              PARALLEL_GPIO59 |
                                              PARALLEL_GPIO60 |
                                              PARALLEL_GPIO61 |
                                              PARALLEL_GPIO62);
    HWREG(GPIOCTRL_BASE + GPIO_O_GPCDIR) &= ~(PARALLEL_GPIO88 |
                                              PARALLEL_GPIO89 |
                                              PARALLEL_GPIO90 |
                                              PARALLEL_GPIO92);
    EDIS;

    //
    // Configure GPIO91 as output
    //
    GPIO_setDirectionMode(DSP_CTRL_GPIO, GPIO_DIR_MODE_OUT);
}

//
// Parallel_readPortData - Read the GPIO port data
//
uint16_t Parallel_readPortData(void)
{
    uint16_t data;

    data = (uint16_t)((GPIO_readPortData(GPIO_PORT_B) &
                       (PARALLEL_GPIO58 | PARALLEL_GPIO59 | PARALLEL_GPIO60 |
                        PARALLEL_GPIO61 | PARALLEL_GPIO62)) >> 24U);
    data |= (uint16_t)((GPIO_readPortData(GPIO_PORT_C) & PARALLEL_GPIO88) >> 17U);
    data |= (uint16_t)((GPIO_readPortData(GPIO_PORT_C) &
                        (PARALLEL_GPIO89|PARALLEL_GPIO90)) >> 25U);

    return(data);
}

//
// End of File
//
