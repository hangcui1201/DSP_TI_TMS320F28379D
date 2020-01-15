//###########################################################################
//
// FILE:    bootloader_usb.c
//
// TITLE:   CPU1 USB Bootloader
//
// Functions for USB bootloader
//
// ---------------------------------------------------
// |Opt No.|  BOOTDEF      |  USBDM     |  USBDP     |
// ---------------------------------------------------
// |  0    |  0x09         |  42        |  43        |
// ---------------------------------------------------
//
//###########################################################################
// $TI Release: $
// $Release Date: $
//###########################################################################

//
// Included Files
//
#include "cpu1bootrom.h"
#include "bootloader_usb_support_funcs.h"

//
// Defines
//
#define USB_PIE_IER_MASK 0x4000U

//
// Globals
//
extern uint16_t *g_UsbRxBuffer;
extern uint16_t g_UsbRxDataLength;
extern uint16_t g_UsbRxPacketLength;

uint32_t userUSBHandler;
uint16_t userPIEIERStatus;

//
// Function Prototypes
//
void UsbLoaderRev0Fix(void);
uint16_t USB_Boot_Init(uint16_t enablePIEInit);
uint16_t USB_GetWordData(void);

//
// USB_Boot - USB bootloader routine
//
uint32_t USB_Boot(uint32_t bootMode, uint16_t enablePIEInit)
{
    uint32_t bootEntryAddress = FLASH_ENTRY_POINT;
    uint32_t entryAddress = 0xFFFFFFFFUL;
    uint32_t disconnectDelay;
    uint16_t pllStatus;

    //
    // If the USB module is not enabled or X1 isn't saturated for XTAL use,
    // bypass the boot loader
    //
    if(((HWREG(DEVCFG_BASE + SYSCTL_O_DC12) & SYSCTL_DC12_USB_A_M) == 0U) ||
       ((HWREGH(CLKCFG_BASE + SYSCTL_O_X1CNT) & SYSCTL_X1CNT_X1CNT_M) != SYSCTL_X1CNT_X1CNT_M))
    {
        return(FLASH_ENTRY_POINT);
    } 

    //
    // Assign the USB data reader function to the global
    // function pointer for loading data.
    //
    GetWordData = &USB_GetWordData;

    //
    // Set up the USB to receive data
    //
    pllStatus = USB_Boot_Init(enablePIEInit);

    //
    // If issue with enabling PLL, bypass and go to flash boot
    //
    if(pllStatus == BROM_PLL_ENABLE_ERROR)
    {
        return(FLASH_ENTRY_POINT);
    }

    //
    // CPU1 Patch/Escape Point 15
    //
    entryAddress = CPU1BROM_TI_OTP_ESCAPE_POINT_15;
    if((entryAddress != 0xFFFFFFFFUL) &&
       (entryAddress != 0x00000000UL))
    {
        //
        // If OTP is programmed, then call OTP patch function
        //
        ((void (*)(void))entryAddress)();
    }

    //
    // The first data word should be a valid key. If it's not,
    // bypass the bootloader.
    //
    if (USB_GetWordData() != 0x08AAU)
    {
        return(FLASH_ENTRY_POINT);
    }

    //
    // Use the shared utility functions to load the data.
    //
    ReadReservedFn();
    bootEntryAddress = GetLongData();
    CopyData();

    //
    // CPU1 Patch/Escape Point 15
    //
    entryAddress = CPU1BROM_TI_OTP_ESCAPE_POINT_15;
    if((entryAddress != 0xFFFFFFFFUL) &&
       (entryAddress != 0x00000000UL))
    {
        //
        // If OTP is programmed, then call OTP patch function
        //
        ((void (*)(void))entryAddress)();
    }

    //
    // Disconnect from the bus, disable USB interrupts, and
    // reset the USB module. But first, wait for any ongoing
    // transfers to complete.
    //
    for(disconnectDelay = 0U; disconnectDelay < 10000U; disconnectDelay++) 
    {       
    }

    HWREGB(USB0_BASE + USB_O_POWER) &= ~USB_POWER_SOFTCONN;

    //
    // Disable USB interrupts
    //
    Interrupt_disable((uint32_t)INT_USBA);
    
    //
    // Reset USB
    //
    SysCtl_resetPeripheral(SYSCTL_PERIPH_RES_USBA);

    //
    // Bypass and disable the main and aux PLLs
    //
    EALLOW;
    HWREGH(CLKCFG_BASE + SYSCTL_O_SYSPLLCTL1) &= ~SYSCTL_SYSPLLCTL1_PLLCLKEN;
    
    HWREGH(CLKCFG_BASE + SYSCTL_O_SYSPLLCTL1) &= ~SYSCTL_SYSPLLCTL1_PLLEN;
    
    HWREGH(CLKCFG_BASE + SYSCTL_O_AUXPLLCTL1) &= ~SYSCTL_AUXPLLCTL1_PLLCLKEN;
    
    HWREGH(CLKCFG_BASE + SYSCTL_O_AUXPLLCTL1) &= ~SYSCTL_AUXPLLCTL1_PLLEN;
    EDIS;

    //
    // Reset User Handler (when not using Boot PIE Vector Table)
    //
    if(enablePIEInit != USB_BOOT_ENABLE_PIE_INIT)
    {
        //
        // Re-Register User USB Interrupt Handler
        //
        Interrupt_register(INT_USBA, (void (*)(void))userUSBHandler);

        //
        // Restore user USB PIE IER
        //
        HWREGH(PIECTRL_BASE + PIE_O_IER9) |= userPIEIERStatus;
    }

    //
    // CPU1 Patch/Escape Point 15
    //
    entryAddress = CPU1BROM_TI_OTP_ESCAPE_POINT_15;
    if((entryAddress != 0xFFFFFFFFUL) &&
       (entryAddress != 0x00000000UL))
    {
        //
        // If OTP is programmed, then call OTP patch function
        //
        ((void (*)(void))entryAddress)();
    }

    return(bootEntryAddress);
}

//
// USB_Boot_Init - Initialize the USB module
//
uint16_t USB_Boot_Init(uint16_t enablePIEInit)
{
    uint32_t entryAddress = 0xFFFFFFFFUL;
    uint16_t pllStatus;

    //
    // Lock the sys PLL and aux PLL then enable the USB module clock
    //
    // USBCLK = 60MHz (360 MHz / 6), sourced from the external oscillator (XTAL) for precision
    //
    // SYSCLK must be greater than USBCLK / 2, according to Design. SYSPLL = 180MHz (360MHz / 2)
    //
    
    //
    // SYS PLL (INTOSC2 as source)
    // MULT = 36, Divider = /2
    //
    pllStatus = CPU1BROM_enableSysPLL(36U, 2U);

    //
    // If PLL enable error, exit USB initialization
    //
    if(pllStatus == BROM_PLL_ENABLE_ERROR)
    {
        return(pllStatus);
    }

    //
    // AUX PLL (XTAL as source)
    // MULT = 18, Divider = /6
    //
    pllStatus = CPU1BROM_enableAuxPLL(18U, 6U);

    //
    // If PLL enable error, exit USB initialization
    //
    if(pllStatus == BROM_PLL_ENABLE_ERROR)
    {
        return(pllStatus);
    }

    EALLOW;
    
    //
    // Enable the clock to the USB module
    //
    HWREG(CPUSYS_BASE + SYSCTL_O_PCLKCR11) |= SYSCTL_PCLKCR11_USB_A;

    //
    // CPU1 Patch/Escape Point 15
    //
    entryAddress = CPU1BROM_TI_OTP_ESCAPE_POINT_15;
    if((entryAddress != 0xFFFFFFFFUL) &&
       (entryAddress != 0x00000000UL))
    {
        EDIS;
        
        //
        // If OTP is programmed, then call OTP patch function
        //
        ((void (*)(void))entryAddress)();
        
        EALLOW;
    }

    //
    // Connect the PHY to the GPIO pins by setting the GPBAMSEL
    // bits for GPIOs 42 and 43.
    //
    HWREGH(GPIOCTRL_BASE + GPIO_O_GPBAMSEL) |= GPIO_GPBAMSEL_GPIO42;
    
    HWREGH(GPIOCTRL_BASE + GPIO_O_GPBAMSEL) |= GPIO_GPBAMSEL_GPIO43;

    EDIS;

    //
    // Initialize PIE Vector Table
    // (if requested - enabled by default during boot)
    //
    if(enablePIEInit == USB_BOOT_ENABLE_PIE_INIT)
    {
        CPU1BROM_enablePIEinBoot();
    }
    else
    {
        //
        // When not enabling PIE, save user USB handler to restore later
        //
        userUSBHandler = HWREG(((uint32_t)PIEVECTTABLE_BASE +
                               (((INT_USBA & 0xFFFF0000U) >> 16U) * 2U)));

        //
        // Get user USB PIE IER status
        //
        userPIEIERStatus = HWREGH(PIECTRL_BASE + PIE_O_IER9) & USB_PIE_IER_MASK;

        //
        // Disable USB interrupt
        //
        Interrupt_disable((uint32_t)INT_USBA);
    }

    DINT;

    //
    // Register the USB interrupt handler and enable CPU interrupts
    //
    Interrupt_register(INT_USBA, &UsbIntHandler);  
    Interrupt_enable((uint32_t)INT_USBA);

    EINT;

    //
    // CPU1 Patch/Escape Point 15
    //
    entryAddress = CPU1BROM_TI_OTP_ESCAPE_POINT_15;
    if((entryAddress != 0xFFFFFFFFUL) &&
       (entryAddress != 0x00000000UL))
    {
        //
        // If OTP is programmed, then call OTP patch function
        //
        ((void (*)(void))entryAddress)();
    }

    //
    // Reset the USB driver's global variables
    //
    ResetUsbDriver();

    //
    // Force USB device mode by setting DEVMODOTG and DEVMOD
    //
    HWREG(USB0_BASE + USB_O_GPCS) = 0x3U;

    //
    // Clear active interrupts
    //
    HWREGH(USB0_BASE + USB_O_TXIS);
    HWREGH(USB0_BASE + USB_O_RXIS);
    HWREGB(USB0_BASE + USB_O_IS);

    //
    // Set up endpoint 1 for bulk transfers with a 64-byte FIFO
    //
    HWREGB(USB0_BASE + USB_O_EPIDX) = 1U;
    HWREGB(USB0_BASE + USB_O_RXFIFOSZ) = 0x03U;
    HWREGH(USB0_BASE + USB_O_RXFIFOADD) = 0x100U;
    HWREGB(USB0_BASE + USB_O_RXCSRH1) = 0x40U;

    //
    // Enable USB interrupts for EP0 transmit/receive, EP1 receive,
    // disconnection, and reset
    //
    HWREGH(USB0_BASE + USB_O_TXIE) = 0x0001U;
    HWREGH(USB0_BASE + USB_O_RXIE) = 0x0002U;
    HWREGB(USB0_BASE + USB_O_IE) = (USB_IE_DISCON | USB_IE_RESET);

    //
    // Attach the USB PHY to the bus
    //
    HWREGB(USB0_BASE + USB_O_POWER) |= USB_POWER_SOFTCONN;

    return(BROM_PLL_ENABLE_SUCCESS);
}

//
// USB_GetWordData - Read 16 bits from an incoming USB message
//
uint16_t USB_GetWordData(void)
{
    uint16_t retVal;

    //
    // Wait for the USB receive buffer to be refilled
    //
    while(g_UsbRxBuffer == 0U) 
    {
    }

    //
    // Read the next data value, update the buffer pointer and length,
    // and do end-of-packet handling.
    //
    retVal = *g_UsbRxBuffer;
    g_UsbRxBuffer = g_UsbRxBuffer + 1U;
    g_UsbRxPacketLength -= 2U;

    if(g_UsbRxPacketLength == 0U)
    {
        g_UsbRxBuffer = 0U;
        AckEp1();
    }

    return(retVal);
}

//
// End of file
//
