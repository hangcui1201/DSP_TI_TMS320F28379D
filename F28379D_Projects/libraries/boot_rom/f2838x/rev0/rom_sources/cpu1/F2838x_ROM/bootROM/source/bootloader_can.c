//###########################################################################
//
// FILE:    bootloader_can.c
//
// TITLE:   CAN Bootloader
//
// Functions involved in running CAN bootloader
//
// ---------------------------------------------------
// |Opt No.|  BOOTDEF      |  CANTXA    |  CANRXA    |
// ---------------------------------------------------
// |  0    |  0x02(default)|  37        |  36        |
// |  1    |  0x22         |  71        |  70        |
// |  2    |  0x42         |  63        |  62        |
// |  3    |  0x62         |  19        |  18        |
// |  4    |  0x82         |  4         |  5         |
// |  5    |  0xA2         |  31        |  30        |
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
#include "inc/hw_memmap.h"
#include "inc/hw_sysctl.h"
#include "inc/hw_can.h"
#include "inc/hw_gpio.h"
#include "../include/bootloader_can_timing.h"

//
// Defines
//
#define SELECT_EXTERNAL_OSC    0x1UL
#define CLOCK_DIVIDER_1        0x0U
#define CAN_DISABLE_PARITY     0x5UL
#define CAN_ENABLE_PARITY      0xAUL
#define CAN_11_BIT_ID_S        18U
#define CAN_RX_MSG_ID          0x1UL
#define CAN_TX_MSG_ID          0x2UL
#define CAN_MSG_OBJ_1          0x1U
#define CAN_MSG_OBJ_2          0x2U
#define CAN_DLC_SIZE           0x2U

//
// CAN bit timing settings for running CAN at 100kbps with a 20MHz crystal
//
// See CAN timing header for these values

//
// Function Prototypes
//
static void DCAN_Boot_GPIO(uint32_t bootMode);
static void DCAN_Boot_Init(uint32_t btrReg, uint16_t switchToXTAL);
static uint16_t DCAN_GetWordData(void);
static void DCAN_SendWordData(uint16_t data);
static void DCAN_ParseReservedWords(void);

//
// DCAN_Boot - Run the CAN bootloader setup with the specified GPIOs for the
//             requested CAN boot mode
//
uint32_t DCAN_Boot(uint32_t bootMode, uint32_t bitTimingRegValue,
                   uint16_t switchToXTAL)
{
    uint32_t entryAddress = 0xFFFFFFFFUL;

    //
    // CPU1 Patch/Escape Point 10
    //
    entryAddress = CPU1BROM_TI_OTP_ESCAPE_POINT_10;
    if((entryAddress != 0xFFFFFFFFUL) &&
       (entryAddress != 0x00000000UL))
    {
        //
        // If OTP is programmed, then call OTP patch function
        //
        ((void (*)(void))entryAddress)();
    }

    //
    // If CAN-A is not enabled or X1 isn't saturated for XTAL use,
    // bypass the boot loader
    //
    if(((HWREG(DEVCFG_BASE + SYSCTL_O_DC11) & SYSCTL_DC11_CAN_A) == 0U) ||
       ((HWREGH(CLKCFG_BASE + SYSCTL_O_X1CNT) & SYSCTL_X1CNT_X1CNT_M) != SYSCTL_X1CNT_X1CNT_M))
    {
       return(FLASH_ENTRY_POINT);
    }

    //
    // Assign the CAN data reader function to the global
    // function pointer for loading data.
    //
    GetWordData = &DCAN_GetWordData;

    //
    // Set up the GPIO mux for the chosen pinout
    //
    DCAN_Boot_GPIO(bootMode);

    //
    // Set up the CAN to receive data. Pass the user-provided bit timing
    // register value if one was provided, otherwise pass the default for
    // 100 kbps with a 20 MHz crystal.
    //
    if(bitTimingRegValue == 0U)
    {
        bitTimingRegValue = CAN_CALC_BTRREG;
    }
    DCAN_Boot_Init(bitTimingRegValue, switchToXTAL);

    //
    // CPU1 Patch/Escape Point 10
    //
    entryAddress = CPU1BROM_TI_OTP_ESCAPE_POINT_10;
    if((entryAddress != 0xFFFFFFFFUL) &&
       (entryAddress != 0x00000000UL))
    {
        //
        // If OTP is programmed, then call OTP patch function
        //
        ((void (*)(void))entryAddress)();
    }

    //
    // Testing Only: Send two tests frames if the boot mode says so
    //
    if(bootMode >= CAN_BOOT_SENDTEST)
    {
        DCAN_SendWordData(0x0320U);
        DCAN_SendWordData(0xf280U);
    }

    //
    // The first data word should be a valid key. If it's not,
    // bypass the bootloader.
    //
    if(DCAN_GetWordData() != 0x08AAU)
    {
        return FLASH_ENTRY_POINT;
    }

    //
    // Use the shared utility functions to load the data.
    //
    DCAN_ParseReservedWords();
    entryAddress = GetLongData();
    CopyData();

    return entryAddress;
}

//
// DCAN_Boot_GPIO - Configure the peripheral mux to connect CAN-A to the
//                  chosen GPIOs
//
static void DCAN_Boot_GPIO(uint32_t bootMode)
{
    uint16_t gpioTx;
    uint16_t gpioRx;
    uint32_t gpioTxPinConfig;
    uint32_t gpioRxPinConfig;

    //
    // Unlock the GPIO configuration registers
    //
    GPIO_unlockPortConfig(GPIO_PORT_A,0xFFFFFFFFUL);
    GPIO_unlockPortConfig(GPIO_PORT_B,0xFFFFFFFFUL);
    GPIO_unlockPortConfig(GPIO_PORT_C,0xFFFFFFFFUL);

    //
    // Decode the GPIO selection, then set up the mux and configure the inputs
    // for asynchronous qualification.
    //
    switch (bootMode)
    {
        case CAN_BOOT:
        case CAN_BOOT_SENDTEST:
        default:
            //
            // GPIO37 = CANATX
            // GPIO36 = CANARX
            //
            gpioTx = 37;
            gpioRx = 36;
            gpioTxPinConfig = GPIO_37_CANTXA;
            gpioRxPinConfig = GPIO_36_CANRXA;
            break;

        case CAN_BOOT_ALT1:
        case CAN_BOOT_ALT1_SENDTEST:
            //
            // GPIO71 = CANATX
            // GPIO70 = CANARX
            //
            gpioTx = 71;
            gpioRx = 70;
            gpioTxPinConfig = GPIO_71_CANTXA;
            gpioRxPinConfig = GPIO_70_CANRXA;

            break;

        case CAN_BOOT_ALT2:
        case CAN_BOOT_ALT2_SENDTEST:
            //
            // GPIO63 = CANATX
            // GPIO62 = CANARX
            //
            gpioTx = 63;
            gpioRx = 62;
            gpioTxPinConfig = GPIO_63_CANTXA;
            gpioRxPinConfig = GPIO_62_CANRXA;

            break;

        case CAN_BOOT_ALT3:
        case CAN_BOOT_ALT3_SENDTEST:
            //
            // GPIO19 = CANATX
            // GPIO18 = CANARX
            //
            gpioTx = 19;
            gpioRx = 18;
            gpioTxPinConfig = GPIO_19_CANTXA;
            gpioRxPinConfig = GPIO_18_CANRXA;

            break;

        case CAN_BOOT_ALT4:
        case CAN_BOOT_ALT4_SENDTEST:
            //
            // GPIO4 = CANATX
            // GPIO5 = CANARX
            //
            gpioTx = 4;
            gpioRx = 5;
            gpioTxPinConfig = GPIO_4_CANTXA;
            gpioRxPinConfig = GPIO_5_CANRXA;

            break;

        case CAN_BOOT_ALT5:
        case CAN_BOOT_ALT5_SENDTEST:
            //
            // GPIO31 = CANATX
            // GPIO30 = CANARX
            //
            gpioTx = 31;
            gpioRx = 30;
            gpioTxPinConfig = GPIO_31_CANTXA;
            gpioRxPinConfig = GPIO_30_CANRXA;

            break;
    }

    //
    // Enable pull up on GPIOs pins
    //
    GPIO_setPadConfig(gpioTx,GPIO_PIN_TYPE_PULLUP);
    GPIO_setPadConfig(gpioRx,GPIO_PIN_TYPE_PULLUP);

    //
    // Set GPIO configuration for CAN
    //
    GPIO_setPinConfig(gpioTxPinConfig);
    GPIO_setPinConfig(gpioRxPinConfig);

    //
    // Configure GPIOs as async pins
    //
    GPIO_setQualificationMode(gpioTx,GPIO_QUAL_ASYNC);
    GPIO_setQualificationMode(gpioRx,GPIO_QUAL_ASYNC);
}

//
// DCAN_Boot_Init - Initialize the CAN-A module and configure its bit clock
//                  and message objects
//
static void DCAN_Boot_Init(uint32_t btrReg, uint16_t switchToXTAL)
{
    //
    // Select XTAL for CAN clock
    //
    EALLOW;
    if(switchToXTAL == CAN_BOOT_USE_XTAL)
    {
        HWREG(CLKCFG_BASE + SYSCTL_O_CLKSRCCTL2) |= (1U << SYSCTL_CLKSRCCTL2_CANABCLKSEL_S);
    }

    //
    // Turn on the clock to the DCAN-A module
    //
    HWREG(CPUSYS_BASE + SYSCTL_O_PCLKCR10) |= SYSCTL_PCLKCR10_CAN_A;
    EDIS;

    //
    // Put the CAN module into initialization mode, then issue a software reset
    // via the self-clearing SWR bit.
    //
    HWREG_BP(CANA_BASE + CAN_O_CTL) = (CAN_DISABLE_PARITY << CAN_CTL_PMD_S) |
                                      CAN_CTL_INIT;
    asm(" RPT #16 || NOP");
    EALLOW;
    HWREG_BP(CANA_BASE + CAN_O_CTL) |= CAN_CTL_SWR;
    EDIS;
    asm(" RPT #16 || NOP");

    //
    // Initialize the CAN message RAM
    //
    HWREG_BP(CANA_BASE + CAN_O_RAM_INIT) = CAN_RAM_INIT_CAN_RAM_INIT |
                                           CAN_RAM_INIT_KEY;
    while((HWREG_BP(CANA_BASE + CAN_O_RAM_INIT) & CAN_RAM_INIT_RAM_INIT_DONE) !=
          CAN_RAM_INIT_RAM_INIT_DONE)
    {
    }

    //
    // Enable config register access, set up the bit timing, and make sure
    // parity stays enabled.
    //
    HWREG_BP(CANA_BASE + CAN_O_CTL) = (CAN_ENABLE_PARITY << CAN_CTL_PMD_S) |
                                      CAN_CTL_CCE | CAN_CTL_INIT;
    HWREG_BP(CANA_BASE + CAN_O_BTR) = btrReg;

    //
    // Set up a receive message object via interface 1, then transfer it to the
    // message RAM.
    //
    HWREG_BP(CANA_BASE + CAN_O_IF1ARB) = CAN_IF1ARB_MSGVAL | (CAN_RX_MSG_ID << CAN_11_BIT_ID_S);
    HWREG_BP(CANA_BASE + CAN_O_IF1MCTL) = CAN_IF1MCTL_EOB | CAN_DLC_SIZE;
    HWREG_BP(CANA_BASE + CAN_O_IF1MSK) = (uint32_t)(CAN_IF1MSK_MSK_M |
                                                    CAN_IF1MSK_MDIR |
                                                    CAN_IF1MSK_MXTD);
    HWREG_BP(CANA_BASE + CAN_O_IF1CMD) = (uint32_t)(CAN_IF1CMD_DIR |
                                                 CAN_IF1CMD_MASK |
                                                 CAN_IF1CMD_ARB |
                                                 CAN_IF1CMD_CONTROL |
                                                 CAN_IF1CMD_CLRINTPND |
                                                 CAN_MSG_OBJ_1);

    while((HWREGH(CANA_BASE + CAN_O_IF1CMD) & CAN_IF1CMD_BUSY) == CAN_IF1CMD_BUSY)
    {
    }

    //
    // Set up a transmit object via interface 2 for debug, then transfer it to
    // the message RAM.
    //
    HWREG_BP(CANA_BASE + CAN_O_IF2ARB) = CAN_IF2ARB_MSGVAL | CAN_IF2ARB_DIR |
                                         (CAN_TX_MSG_ID << CAN_11_BIT_ID_S);
    HWREG_BP(CANA_BASE + CAN_O_IF2MCTL) = CAN_IF2MCTL_EOB | CAN_DLC_SIZE;
    HWREG_BP(CANA_BASE + CAN_O_IF2MSK) = (uint32_t)(CAN_IF2MSK_MSK_M |
                                                    CAN_IF2MSK_MDIR |
                                                    CAN_IF2MSK_MXTD);
    HWREG_BP(CANA_BASE + CAN_O_IF2CMD) = (uint32_t)(CAN_IF2CMD_DIR |
                                                 CAN_IF2CMD_MASK |
                                                 CAN_IF2CMD_ARB |
                                                 CAN_IF2CMD_CONTROL |
                                                 CAN_IF2CMD_CLRINTPND |
                                                 CAN_MSG_OBJ_2);

    while((HWREGH(CANA_BASE + CAN_O_IF2CMD) & CAN_IF2CMD_BUSY) == CAN_IF2CMD_BUSY)
    {
    }

    //
    // Leave initialization mode and disable timing register access and
    // automatic retransmission.
    //
    HWREGH(CANA_BASE + CAN_O_CTL) &= ~(CAN_CTL_CCE | CAN_CTL_INIT);
}

//
// DCAN_GetWordData - Read 16 bits from an incoming DCAN message sent to ID #1.
//                    If no message has been received, wait for one to arrive.
//
static uint16_t DCAN_GetWordData(void)
{
    //
    // Wait for a new CAN message to be received in mailbox 1
    //
    while((HWREG_BP(CANA_BASE + CAN_O_NDAT_21) & CAN_MSG_OBJ_1) != CAN_MSG_OBJ_1)
    {
    }

    //
    // Read the message object via IF1 and return the data
    //
    HWREG_BP(CANA_BASE + CAN_O_IF1CMD) = (uint32_t)(CAN_IF1CMD_TXRQST |
                                                 CAN_IF1CMD_DATA_A |
                                                 CAN_IF1CMD_DATA_B |
                                                 CAN_MSG_OBJ_1);

    asm(" RPT #2 || NOP");

    while((HWREGH(CANA_BASE + CAN_O_IF1CMD) & CAN_IF1CMD_BUSY) == CAN_IF1CMD_BUSY)
    {
    }

    return(HWREGH(CANA_BASE + CAN_O_IF1DATA));
}

//
// DCAN_SendWordData - Send a CAN message to ID #2 for external testing and
//                     data rate measurement. Wait for the transmission to
//                     complete.
//
static void DCAN_SendWordData(uint16_t data)
{
    HWREG_BP(CANA_BASE + CAN_O_IF2DATA) = data;
    HWREG_BP(CANA_BASE + CAN_O_IF2CMD) = (uint32_t)(CAN_IF2CMD_DIR |
                                                    CAN_IF2CMD_TXRQST |
                                                    CAN_IF2CMD_DATA_A |
                                                    CAN_IF2CMD_DATA_B |
                                                    CAN_MSG_OBJ_2);

    asm(" RPT #255 || NOP");

    while((HWREGH(CANA_BASE + CAN_O_IF2CMD) & CAN_IF2CMD_BUSY) == CAN_IF2CMD_BUSY)
    {
    }

    while((HWREGH(CANA_BASE + CAN_O_TXRQ_21) & CAN_MSG_OBJ_2) == CAN_MSG_OBJ_2)
    {
    }
}

//
// DCAN_ParseReservedWords - Parse the eight reserved words and check whether
//                           there's a new bit timing register value in the
//                           first pair.
//
static void DCAN_ParseReservedWords(void)
{
    uint32_t newBtrReg;
    uint16_t word;

    //
    // Read the new bit timing value, LSW first
    //
    newBtrReg = (uint32_t)DCAN_GetWordData();
    newBtrReg |= (uint32_t)DCAN_GetWordData() << 16UL;

    //
    // Skip the rest of the reserved words
    //
    for(word = 3U; word <= 8U; word++)
    {
        (void)DCAN_GetWordData();
    }

    //
    // If a new bit timing value was received, switch to the new settings
    //
    if(newBtrReg != 0x00000000UL)
    {
        DCAN_Boot_Init(newBtrReg, 0U);
    }
}

//
// End of File
//
