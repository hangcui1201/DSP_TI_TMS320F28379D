//###########################################################################
//
// FILE:    bootloader_sci.c
//
// TITLE:   SCI Bootloader Routines
//
// Functions involved in running SCI bootloader
//
// ---------------------------------------------------
// |Opt No.|  BOOTDEF      |  SCITXA    |  SCIRXA    |
// ---------------------------------------------------
// |  0    |  0x01(default)|  29        |  28        |
// |  1    |  0x21         |  84        |  85        |
// |  2    |  0x41         |  36        |  35        |
// |  3    |  0x61         |  42        |  43        |
// |  4    |  0x81         |  65        |  64        |
// |  5    |  0xA1         |  135       |  136       |
// |  6    |  0xC1         |  8         |  9         |
// ---------------------------------------------------
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
// Defines
//
#define SCI_DATA_WORD_KEY   0x08AAU
#define DATA_BYTE_S         0x8U

//
// Globals
//
uint16_t SCI_gpioTx;
uint32_t SCI_gpioTxPinConfig;

//
// Function Prototypes
//
uint16_t SCIA_GetWordData(void);
static void SCIBOOT_configure_gpio(uint32_t bootMode);

//
// SCI_Boot - This module is the main SCI boot routine.
//            It will load code via the SCI-A port.
//
//            It will return a entry point address back
//            to the system initialization routine which in turn calls
//            the ExitBoot routine.
//
uint32_t SCI_Boot(uint32_t bootMode)
{
    uint32_t entryAddress;
    uint16_t byteData;

    //
    // CPU1 Patch/Escape Point 13
    //
    entryAddress = CPU1BROM_TI_OTP_ESCAPE_POINT_13;
    if((entryAddress != 0xFFFFFFFFUL) &&
       (entryAddress != 0x00000000UL))
    {
        //
        // If OTP is programmed, then call OTP patch function
        //
        ((void (*)(void))entryAddress)();
    }

    //
    // Check if SCI is enabled on device or not
    //
    if((HWREG(DEVCFG_BASE + SYSCTL_O_DC8) & SYSCTL_DC8_SCI_A) == 0U)
    {
        return(FLASH_ENTRY_POINT);
    }

    //
    // Assign GetWordData to the SCI-A version of the
    // function. GetWordData is a pointer to a function.
    //
    GetWordData = SCIA_GetWordData;

    //
    // Initialize the SCI-A port for communications
    // with the host.
    //

    //
    // Enable the SCI-A clocks
    //
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_SCIA);
    SysCtl_setLowSpeedClock(SYSCTL_LSPCLK_PRESCALE_4);

    EALLOW;
    HWREGH(SCIA_BASE + SCI_O_FFTX) = SCI_FFTX_SCIRST;

    //
    // 1 stop bit, No parity, 8-bit character
    // No loopback
    //
    HWREGH(SCIA_BASE + SCI_O_CCR) = (SCI_CONFIG_WLEN_8 | SCI_CONFIG_STOP_ONE);
    SCI_setParityMode(SCIA_BASE,SCI_CONFIG_PAR_NONE);

    //
    // Enable TX, RX, Use internal SCICLK
    //
    HWREGH(SCIA_BASE + SCI_O_CTL1) = (SCI_CTL1_TXENA | SCI_CTL1_RXENA);

    //
    // Disable RxErr, Sleep, TX Wake,
    // Disable Rx Interrupt, Tx Interrupt
    //
    HWREGB(SCIA_BASE + SCI_O_CTL2) = 0x0U;

    //
    // Relinquish SCI-A from reset and enable TX/RX
    //
    SCI_enableModule(SCIA_BASE);

    EDIS;

    //
    // GPIO INIT
    //
    SCIBOOT_configure_gpio(bootMode);

    //
    // CPU1 Patch/Escape Point 13
    //
    entryAddress = CPU1BROM_TI_OTP_ESCAPE_POINT_13;
    if((entryAddress != 0xFFFFFFFFUL) &&
       (entryAddress != 0x00000000UL))
    {
        //
        // If OTP is programmed, then call OTP patch function
        //
        ((void (*)(void))entryAddress)();
    }

    //
    // Perform autobaud lock with the host.
    // Note that if autobaud never occurs
    // the program will hang in this routine as there
    // is no timeout mechanism included.
    //
    SCI_lockAutobaud(SCIA_BASE);

    //
    // Read data
    //
    byteData = SCI_readCharBlockingNonFIFO(SCIA_BASE);

    //
    // Configure TX pin after autobaud lock
    // (Performed here to allow SCI to double as wait boot)
    //
    GPIO_setPadConfig(SCI_gpioTx,GPIO_PIN_TYPE_PULLUP);
    GPIO_setPinConfig(SCI_gpioTxPinConfig);

    //
    // Write data to request key
    //
    SCI_writeCharNonBlocking(SCIA_BASE,byteData);

    //
    // If the KeyValue was invalid, abort the load
    // and return the flash entry point.
    //
    if(SCIA_GetWordData() != SCI_DATA_WORD_KEY)
    {
        return FLASH_ENTRY_POINT;
    }

    ReadReservedFn();

    entryAddress = GetLongData();

    CopyData();

    return entryAddress;
}

//
// SCIA_GetWordData - This routine fetches two bytes from the SCI-A
//                    port and puts them together to form a single
//                    16-bit value.  It is assumed that the host is
//                    sending the data in the order LSB followed by MSB.
//
uint16_t SCIA_GetWordData(void)
{
    uint16_t wordData;
    uint16_t byteData;

    wordData = 0x0000U;
    byteData = 0x0000U;

    //
    // Fetch the LSB and verify back to the host
    //
    wordData = SCI_readCharBlockingNonFIFO(SCIA_BASE);

    SCI_writeCharNonBlocking(SCIA_BASE,wordData);

    byteData = SCI_readCharBlockingNonFIFO(SCIA_BASE);

    SCI_writeCharNonBlocking(SCIA_BASE,byteData);

    //
    // Form the wordData from the MSB:LSB
    //
    wordData |= (byteData << DATA_BYTE_S);

    return wordData;
}

//
// SCIBOOT_configure_gpio - This function configures the required GPIOs for the
//                          specified SCI boot mode
//
static void SCIBOOT_configure_gpio(uint32_t bootMode)
{
    uint16_t gpioRx = 0;
    uint32_t gpioRxPinConfig = 0;
    SCI_gpioTx = 0U;
    SCI_gpioTxPinConfig = 0U;

    //
    // Unlock the GPIO configuration registers
    //
    GPIO_unlockPortConfig(GPIO_PORT_A,0xFFFFFFFFU);
    GPIO_unlockPortConfig(GPIO_PORT_B,0xFFFFFFFFU);
    GPIO_unlockPortConfig(GPIO_PORT_C,0x00FFFFFFU);

    switch (bootMode)
    {
        case SCI_BOOT:
        default:
            //
            // GPIO29 = SCIATX
            // GPIO28 = SCIARX
            //
            SCI_gpioTx = 29;
            gpioRx = 28;
            SCI_gpioTxPinConfig = GPIO_29_SCITXDA;
            gpioRxPinConfig = GPIO_28_SCIRXDA;
            break;

        case SCI_BOOT_ALT1:
            //
            // GPIO84 = SCIATX
            // GPIO85 = SCIARX
            //
            SCI_gpioTx = 84;
            gpioRx = 85;
            SCI_gpioTxPinConfig = GPIO_84_SCITXDA;
            gpioRxPinConfig = GPIO_85_SCIRXDA;
            break;

        case SCI_BOOT_ALT2:
            //
            // GPIO36 = SCIATX
            // GPIO35 = SCIARX
            //
            SCI_gpioTx = 36;
            gpioRx = 35;
            SCI_gpioTxPinConfig = GPIO_36_SCITXDA;
            gpioRxPinConfig = GPIO_35_SCIRXDA;
            break;

        case SCI_BOOT_ALT3:
            //
            // GPIO42 = SCIATX
            // GPIO43 = SCIARX
            //
            SCI_gpioTx = 42;
            gpioRx = 43;
            SCI_gpioTxPinConfig = GPIO_42_SCITXDA;
            gpioRxPinConfig = GPIO_43_SCIRXDA;
            break;

        case SCI_BOOT_ALT4:
            //
            // GPIO65 = SCIATX
            // GPIO64 = SCIARX
            //
            SCI_gpioTx = 65;
            gpioRx = 64;
            SCI_gpioTxPinConfig = GPIO_65_SCITXDA;
            gpioRxPinConfig = GPIO_64_SCIRXDA;
            break;

        case SCI_BOOT_ALT5:
            //
            // Unlock GPIO Configure Registers
            //
            GPIO_unlockPortConfig(GPIO_PORT_E,0x000000FFU);

            //
            // GPIO135 = SCIATX
            // GPIO136 = SCIARX
            //
            SCI_gpioTx = 135;
            gpioRx = 136;
            SCI_gpioTxPinConfig = GPIO_135_SCITXDA;
            gpioRxPinConfig = GPIO_136_SCIRXDA;
            break;

        case SCI_BOOT_ALT6:
            //
            // GPIO8 = SCIATX
            // GPIO9 = SCIARX
            //
            SCI_gpioTx = 8;
            gpioRx = 9;
            SCI_gpioTxPinConfig = GPIO_8_SCITXDA;
            gpioRxPinConfig = GPIO_9_SCIRXDA;
            break;
    }

    //
    // Configure only the Rx pin so that SCI can receive 'A' for autobaud.
    // Do not configure Tx pin so that SCI can be used as WAIT Boot
    // and only one pin will be driven.
    //

    //
    // Enable pull up on GPIOs pins
    //
    GPIO_setPadConfig(gpioRx,GPIO_PIN_TYPE_PULLUP);

    //
    // Set GPIO configuration for SCI
    //
    GPIO_setPinConfig(gpioRxPinConfig);

    //
    // Configure GPIOs as async pins
    //
    GPIO_setQualificationMode(gpioRx,GPIO_QUAL_ASYNC);
}

//
// End of File
//
