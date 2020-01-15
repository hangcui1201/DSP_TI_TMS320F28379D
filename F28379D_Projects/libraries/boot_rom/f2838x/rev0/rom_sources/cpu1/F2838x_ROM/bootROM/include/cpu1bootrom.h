//###########################################################################
//
// FILE:   cpu1bootrom.h
//
// TITLE:  CPU1 BootROM Definitions.
//
//###########################################################################
// $TI Release: $
// $Release Date: $
//###########################################################################

#ifndef CPU1_BOOTROM_H_
#define CPU1_BOOTROM_H_

//
// Included Files
//
#include <stdint.h>
#include "hw_types.h"
#include "hw_memmap.h"
#include "hw_sysctl.h"
#include "hw_sci.h"
#include "hw_i2c.h"
#include "hw_memcfg.h"
#include "hw_asysctl.h"
#include "hw_dcsm.h"
#include "sysctl.h"
#include "cpu.h"
#include "flash.h"
#include "pin_map.h"
#include "gpio.h"
#include "sci.h"
#include "spi.h"
#include "i2c.h"
#include "can.h"
#include "pbist.h"
#include "dcc.h"

//
// BootROM System Clock (10MHz)
//
#define BOOTROM_SYSCLK      10000000UL

//
// Flash Configurations
//
#define CPU1_FLASH_15MHZ_PSLEEP        (0xE1U * 2)
#define CPU1_FLASH_15MHZ_RWAIT         0x1U
#define CPU1_FLASH_DEFAULT_PSLEEP      (0xA41U * 2)
#define CPU1_FLASH_DEFAULT_RWAIT       0x3U
#define CPU1_FLASH_15MHZ_TIMEOUT_VALUE 91U        //Loop ~28cycles (Freq = 15MHz)
                                                  //(Loop timeout value = (170us * freq)/28cycles)

//
// DCx Registers
//
#define BROM_SYSCTL_O_DC6   0x1CU
#define BROM_SYSCTL_O_DC13  0x2AU
#define BROM_SYSCTL_O_DC16  0x30U
#define BROM_SYSCTL_O_DC23  0x3EU


//
// Emulation Boot Defines
//

//
// Emulation Boot Configuration Registers (Emulates DCSM OTP registers)
//
#define EMU_BOOTPIN_CONFIG  0xD00U   //Equivalent to Z1 DCSM GPREG1
#define EMU_BOOT_GPREG2     0xD02U   //Equivalent to Z1 DCSM GPREG2
#define EMU_BOOTDEF_LOW     0xD04U   //Equivalent to Z1 DCSM GPREG3
#define EMU_BOOTDEF_HIGH    0xD06U   //Equivalent to Z1 DCSM GPREG4

//
// Get key to validate Emulation BOOTPIN_CONFIG
//
#define EMU_BOOTPIN_CONFIG_KEY          ((HWREG(EMU_BOOTPIN_CONFIG) & (uint32_t)0xFF000000UL) >> 24U)

//
// Emulation macros to extract boot definition from BOOTDEF table at
// specified index
//
#define EMU_BOOTDEF_L(x)                ((HWREG(EMU_BOOTDEF_LOW)  & ((uint32_t)0xFFU << (8U*x))) >> (8U*x))
#define EMU_BOOTDEF_H(x)                ((HWREG(EMU_BOOTDEF_HIGH) & ((uint32_t)0xFFU << (8U*x))) >> (8U*x))


//
// Standalone Boot Defines
//

//
// DCSM OTP Boot Configuration Registers
//
#define Z1_OTP_BOOTPIN_CONFIG           (DCSM_Z1_BASE + (uint32_t)DCSM_O_Z1_GPREG1)
#define Z1_OTP_BOOT_GPREG2              (DCSM_Z1_BASE + (uint32_t)DCSM_O_Z1_GPREG2)
#define Z1_OTP_BOOTDEF_LOW              (DCSM_Z1_BASE + (uint32_t)DCSM_O_Z1_GPREG3)
#define Z1_OTP_BOOTDEF_HIGH             (DCSM_Z1_BASE + (uint32_t)DCSM_O_Z1_GPREG4)
#define Z2_OTP_BOOTPIN_CONFIG           (DCSM_Z2_BASE + (uint32_t)DCSM_O_Z2_GPREG1)
#define Z2_OTP_BOOT_GPREG2              (DCSM_Z2_BASE + (uint32_t)DCSM_O_Z2_GPREG2)
#define Z2_OTP_BOOTDEF_LOW              (DCSM_Z2_BASE + (uint32_t)DCSM_O_Z2_GPREG3)
#define Z2_OTP_BOOTDEF_HIGH             (DCSM_Z2_BASE + (uint32_t)DCSM_O_Z2_GPREG4)

//
// GPREG2 Defines - Get Key and Get PBIST enable status
//
#define HWREAD_Z1_OTP_BOOT_GPREG2_KEY          ((HWREG(Z1_OTP_BOOT_GPREG2) & (uint32_t)0xFF000000UL) >> 24U)
#define HWREAD_Z1_OTP_BOOT_GPREG2_PBIST_CONFIG ((HWREG(Z1_OTP_BOOT_GPREG2) & (uint32_t)0x000000F0UL) >> 4U)
#define HWREAD_Z2_OTP_BOOT_GPREG2_KEY          ((HWREG(Z2_OTP_BOOT_GPREG2) & (uint32_t)0xFF000000UL) >> 24U)
#define HWREAD_Z2_OTP_BOOT_GPREG2_PBIST_CONFIG ((HWREG(Z2_OTP_BOOT_GPREG2) & (uint32_t)0x000000F0UL) >> 4U)
#define GPREG2_KEY                             0x5AU
#define GPREG2_PBIST_PLL_ENABLE_HIGH_SPEED     0x0UL
#define GPREG2_PBIST_PLL_ENABLE_MED_SPEED      0xCUL
#define GPREG2_PBIST_PLL_ENABLE_LOW_SPEED      0x3UL
#define GPREG2_PBIST_PLL_DISABLED              0x9UL
#define PBIST_CHECKSUM_SUCCESS                 0x0U

//
// Get key to validate Z1 OTP BOOTPIN_CONFIG
//
#define HWREAD_Z1_OTP_BOOTPIN_CONFIG_KEY       ((HWREG(Z1_OTP_BOOTPIN_CONFIG) & (uint32_t)0xFF000000UL) >> 24U)
#define HWREAD_Z2_OTP_BOOTPIN_CONFIG_KEY       ((HWREG(Z2_OTP_BOOTPIN_CONFIG) & (uint32_t)0xFF000000UL) >> 24U)

//
// Standalone macros to extract boot definition from BOOTDEF table at
// specified index
//
#define HWREAD_Z1_OTP_BOOTDEF_L(x)             ((HWREG(Z1_OTP_BOOTDEF_LOW)  & ((uint32_t)0xFFUL << (8U*(x)))) >> (8U*(x)))
#define HWREAD_Z1_OTP_BOOTDEF_H(x)             ((HWREG(Z1_OTP_BOOTDEF_HIGH) & ((uint32_t)0xFFUL << (8U*(x)))) >> (8U*(x)))
#define HWREAD_Z2_OTP_BOOTDEF_L(x)             ((HWREG(Z2_OTP_BOOTDEF_LOW)  & ((uint32_t)0xFFUL << (8U*(x)))) >> (8U*(x)))
#define HWREAD_Z2_OTP_BOOTDEF_H(x)             ((HWREG(Z2_OTP_BOOTDEF_HIGH) & ((uint32_t)0xFFUL << (8U*(x)))) >> (8U*(x)))


//
// Boot Pin and Boot Mode Options
//

//
// Default Boot Mode Select Pins
//
#define FACTORY_DEFAULT_BMSP0           84U  //GPIO84
#define FACTORY_DEFAULT_BMSP1           72U  //GPIO72

//
// Parallel IO Boot Options
//
#define PARALLEL_BOOT                   0x00U

//
// SCI Boot Options
//
#define SCI_BOOT                        0x01U    //GPIO29, 28
#define SCI_BOOT_ALT1                   0x21U    //GPIO84, 85
#define SCI_BOOT_ALT2                   0x41U    //GPIO36, 35
#define SCI_BOOT_ALT3                   0x61U    //GPIO42, 43
#define SCI_BOOT_ALT4                   0x81U    //GPIO65, 64
#define SCI_BOOT_ALT5                   0xA1U    //GPIO135, 136
#define SCI_BOOT_ALT6                   0xC1U    //GPIO8, 9

//
// CAN Boot Options
//
#define CAN_BOOT                        0x02U    //GPIO37, 36
#define CAN_BOOT_ALT1                   0x22U    //GPIO71, 70
#define CAN_BOOT_ALT2                   0x42U    //GPIO63, 62
#define CAN_BOOT_ALT3                   0x62U    //GPIO19, 18
#define CAN_BOOT_ALT4                   0x82U    //GPIO4, 5
#define CAN_BOOT_ALT5                   0xA2U    //GPIO31, 30

#define CAN_BOOT_SENDTEST               0xC2U    //GPIO37, 36
#define CAN_BOOT_ALT1_SENDTEST          0xD2U    //GPIO71, 70
#define CAN_BOOT_ALT2_SENDTEST          0xE2U    //GPIO63, 62
#define CAN_BOOT_ALT3_SENDTEST          0xF2U    //GPIO19, 18
#define CAN_BOOT_ALT4_SENDTEST          0x2F2U   //GPIO4, 5
#define CAN_BOOT_ALT5_SENDTEST          0x3F2U   //GPIO31, 30

//
// Flash Boot Options
//
#define FLASH_BOOT                      0x03U    //Start of BANK 0 Sector 0
#define FLASH_BOOT_ALT1                 0x23U    //Start of BANK 0 Sector 4
#define FLASH_BOOT_ALT2                 0x43U    //Start of BANK 0 Sector 8
#define FLASH_BOOT_ALT3                 0x63U    //Start of BANK 0 Sector 13

//
// Wait Boot Options
//
#define WAIT_BOOT                       0x04U    //Wait mode with WDOG enabled
#define WAIT_BOOT_ALT1                  0x24U    //Wait mode with WDOG disabled

//
// RAM Boot Options
//
#define RAM_BOOT                        0x05U    //Start of M0 RAM

//
// SPI Boot Options
//
#define SPI_MASTER_BOOT                 0x06U    //GPIO58-61
#define SPI_MASTER_BOOT_ALT1            0x26U    //GPIO16-19
#define SPI_MASTER_BOOT_ALT2            0x46U    //GPIO32-35
#define SPI_MASTER_BOOT_ALT3            0x66U    //GPIO16,17,56,57
#define SPI_MASTER_BOOT_ALT4            0x86U    //GPIO54-57

//
// I2C Boot Options
//
#define I2C_MASTER_BOOT                 0x07U    //GPIO91,92
#define I2C_MASTER_BOOT_ALT1            0x27U    //GPIO32,33
#define I2C_MASTER_BOOT_ALT2            0x47U    //GPIO42,43
#define I2C_MASTER_BOOT_ALT3            0x67U    //GPIO0,1
#define I2C_MASTER_BOOT_ALT4            0x87U    //GPIO104,105

//
// USB Boot Options
//
#define USB_BOOT                        0x09U    //GPIO42,43

//
// Secure Flash Boot Options
//
#define SECURE_FLASH_BOOT               0x0AU    //Start of BANK 0 Sector 0
#define SECURE_FLASH_BOOT_ALT1          0x2AU    //Start of BANK 0 Sector 4
#define SECURE_FLASH_BOOT_ALT2          0x4AU    //Start of BANK 0 Sector 8
#define SECURE_FLASH_BOOT_ALT3          0x6AU    //Start of BANK 0 Sector 13


//
// Fixed Boot Entry Points (Addresses)
//

//
// Flash (secure and unsecured) Entry Points
//
#define FLASH_ENTRY_POINT               0x080000UL    //BANK0 Sector 0
#define FLASH_ENTRY_POINT_ALT1          0x088000UL    //BANK0 Sector 4
#define FLASH_ENTRY_POINT_ALT2          0x0A8000UL    //BANK0 sector 8
#define FLASH_ENTRY_POINT_ALT3          0x0BE000UL    //BANK0 sector 13

//
// RAM Entry Point
//
#define RAM_ENTRY_POINT                 0x000000UL    //M0 start address


//
// CPU1 Boot ROM Status Bit Fields
//
#define CPU1_BOOTROM_BOOTSTS_BOOT_MASK               0x000000FFUL

#define CPU1_BOOTROM_BOOTSTS_SYSTEM_START_BOOT       0x00000001UL
#define CPU1_BOOTROM_BOOTSTS_IN_FLASH_BOOT           0x00000002UL
#define CPU1_BOOTROM_BOOTSTS_IN_SECURE_FLASH_BOOT    0x00000003UL
#define CPU1_BOOTROM_BOOTSTS_IN_PARALLEL_BOOT        0x00000004UL
#define CPU1_BOOTROM_BOOTSTS_IN_RAM_BOOT             0x00000005UL
#define CPU1_BOOTROM_BOOTSTS_IN_SCI_BOOT             0x00000006UL
#define CPU1_BOOTROM_BOOTSTS_IN_SPI_BOOT             0x00000007UL
#define CPU1_BOOTROM_BOOTSTS_IN_I2C_BOOT             0x00000008UL
#define CPU1_BOOTROM_BOOTSTS_IN_CAN_BOOT             0x00000009UL
#define CPU1_BOOTROM_BOOTSTS_IN_USB_BOOT             0x0000000AUL
#define CPU1_BOOTROM_BOOTSTS_IN_WAIT_BOOT            0x0000000BUL

#define CPU1_BOOTROM_RESC_HANDLED                    0x00001000UL
#define CPU1_BOOTROM_HANDLED_XRSN                    0x00002000UL
#define CPU1_BOOTROM_HANDLED_POR                     0x00004000UL
#define CPU1_BOOTROM_HANDLED_HWBIST                  0x00008000UL

#define CPU1_BOOTROM_DCSM_INIT_COMPLETE              0x00010000UL
#define CPU1_BOOTROM_RAM_INIT_COMPLETE               0x00020000UL
#define CPU1_BOOTROM_POR_MEM_TEST_COMPLETE           0x00040000UL
#define CPU1_BOOTROM_PLL_FAILED_TO_ENABLE            0x00080000UL

#define CPU1_BOOTROM_GOT_A_MCAN_NMI                  0x00100000UL
#define CPU1_BOOTROM_GOT_AN_ECAT_NMI                 0x00200000UL
#define CPU1_BOOTROM_GOT_AN_ERAD_NMI                 0x00400000UL
#define CPU1_BOOTROM_GOT_ITRAP                       0x00800000UL
#define CPU1_BOOTROM_GOT_A_PIE_MISMATCH              0x01000000UL
#define CPU1_BOOTROM_GOT_A_RL_NMI                    0x02000000UL
#define CPU1_BOOTROM_GOT_A_PIE_VECTOR_NMI            0x04000000UL
#define CPU1_BOOTROM_GOT_A_HWBIST_NMI                0x08000000UL
#define CPU1_BOOTROM_GOT_A_FLASH_UNCERR_NMI          0x10000000UL
#define CPU1_BOOTROM_GOT_A_RAM_UNCERR_NMI            0x20000000UL
#define CPU1_BOOTROM_GOT_A_MCLK_NMI                  0x40000000UL

#define CPU1_BOOTROM_BOOT_COMPLETE                   0x80000000UL


//
// Device Configuration OTP Registers
//
#define HWREAD_TI_OTP_PARTID_L          (HWREG(0x70212UL))
#define HWREAD_TI_OTP_PARTID_H          (HWREG(0x70214UL))

#define HWREAD_TI_OTP_REG_DC00          (HWREGH(0x70218UL))
#define HWREAD_TI_OTP_REG_DC11          (HWREGH(0x70219UL))
#define HWREAD_TI_OTP_REG_DC19          (HWREGH(0x7021AUL))
#define HWREAD_TI_OTP_REG_DC20          (HWREGH(0x7021BUL))
#define HWREAD_TI_OTP_REG_DC21          (HWREGH(0x7021CUL))
#define HWREAD_TI_OTP_REG_DC26          (HWREGH(0x7021DUL))

#define HWREAD_TI_OTP_REG_PERCNF1       (HWREGH(0x7021EUL))

#define HWREAD_TI_OTP_CPU1ROM_DC1       (HWREGH(0x7021FUL))
#define HWREAD_TI_OTP_CPU1ROM_DC2       (HWREGH(0x70220UL))
#define HWREAD_TI_OTP_CPU2ROM_DC1       (HWREGH(0x70221UL))
#define HWREAD_TI_OTP_CPU2ROM_DC2       (HWREGH(0x70222UL))

#define BROM_DCX_ALWAYS_ENABLED         0xFFFFFFFFUL
#define BROM_DCX_ENABLE_HIGH            0xFFFF0000UL

//
// OTP Keys
//
#define TI_OTP_KEY                      0x5A5AU

//
// PMM Trim - Analog Subsystem Register Offsets
//
// Refer to hw_asysctl.h

//
// PMM OTP Trim Values
//
#define HWREAD_TI_OTP_PMM_TRIM_KEY             (HWREGH(0x70233UL))
#define HWREAD_TI_OTP_PMM_TRIM_BASE_ADDRESS    (HWREG(0x7023EUL))
#define HWREAD_TI_OTP_PMM_REF_TRIM_VALUE       (HWREGH(HWREAD_TI_OTP_PMM_TRIM_BASE_ADDRESS))
#define HWREAD_TI_OTP_PMM_VREG_TRIM_VALUE      (HWREGH(HWREAD_TI_OTP_PMM_TRIM_BASE_ADDRESS + 0x1UL))
#define HWREAD_TI_OTP_PMM_VSINK_TRIM_VALUE     (HWREGH(HWREAD_TI_OTP_PMM_TRIM_BASE_ADDRESS + 0x2UL))
#define HWREAD_TI_OTP_PMM_VMON_TRIM_VALUE      (HWREGH(HWREAD_TI_OTP_PMM_TRIM_BASE_ADDRESS + 0x3UL))

//
// Internal Oscillator Trim - Analog Subsystem Register Offsets
//
// Refer to hw_asysctl.h

//
// Internal Oscillator OTP Trim Values
//
#define HWREAD_TI_OTP_INTOSC_TRIM_KEY          (HWREGH(0x70232UL))
#define HWREAD_TI_OTP_INTOSC_BASE_ADDRESS      (HWREG(0x7023CUL))

#define HWREAD_TI_OTP_OSC_REF_TRIM_VALUE       (HWREGH(HWREAD_TI_OTP_INTOSC_BASE_ADDRESS))
#define HWREAD_TI_OTP_INTOSC1_TRIM_VALUE       (HWREG(HWREAD_TI_OTP_INTOSC_BASE_ADDRESS + 0x1U))
#define HWREAD_TI_OTP_INTOSC2_TRIM_VALUE       (HWREG(HWREAD_TI_OTP_INTOSC_BASE_ADDRESS + 0x3U))

//
// PLL Selection - Analog Subsystem Register Offset
//
// Refer to hw_asysctl.h

//
// PLL Selection (OTP)
//
#define HWREAD_TI_OTP_PLLSEL_KEY               (HWREGH(0x70235UL))
#define HWREAD_TI_OTP_PLLSEL_ADDRESS           (HWREG(0x70242UL))
#define HWREAD_TI_OTP_PLLSEL_VALUE             (HWREGH(HWREAD_TI_OTP_PLLSEL_ADDRESS))

//
// APLL Trim - Analog Subsystem Register Offsets
//
// Refer to hw_asysctl.h

//
// APLL OTP Trim Values
//
#define HWREAD_TI_OTP_APLL_TRIM_KEY            (HWREGH(0x70234UL))
#define HWREAD_TI_OTP_APLLREF_TRIM_ADDRESS     (HWREG(0x70240UL))
#define TI_OTP_APLL_SYS_TRIM_ADDRESS           (HWREAD_TI_OTP_APLLREF_TRIM_ADDRESS + 0x1U)
#define TI_OTP_APLL_AUX_TRIM_ADDRESS           (HWREAD_TI_OTP_APLLREF_TRIM_ADDRESS + 0x2U)
#define HWREAD_TI_OTP_APLLREF_TRIM_VALUE       (HWREGH(HWREAD_TI_OTP_APLLREF_TRIM_ADDRESS))
#define HWREAD_TI_OTP_APLL_SYS_TRIM_VALUE      (HWREGH(TI_OTP_APLL_SYS_TRIM_ADDRESS))
#define HWREAD_TI_OTP_APLL_AUX_TRIM_VALUE      (HWREGH(TI_OTP_APLL_AUX_TRIM_ADDRESS))

//
// APLL OTP Trim Masks/Shifts
//
#define TI_OTP_APLL_OSC_FREQ_MASK       0x700U
#define TI_OTP_APLL_OSC_FREQ_SHIFT      0x8U
#define TI_OTP_APLL_OSC_VDD_MASK        0xFFU

//
// APLL Lock - Analog Subsystem Register Offset
//
// Refer to hw_asysctl.h

//
// APLL Lock (OTP)
//
#define HWREAD_TI_OTP_APLLLOCK_KEY             (HWREGH(0x70236UL))
#define HWREAD_TI_OTP_APLLLOCK_ADDRESS         (HWREG(0x70244UL))
#define HWREAD_TI_OTP_APLLLOCK_VALUE           (HWREGH(HWREAD_TI_OTP_APLLLOCK_ADDRESS))

//
// APLL Configurations - Analog Subsystem Register Offset
//
#define BROM_ASYSCTL_O_SYSAPLLCONFIG6         0xC5U
#define BROM_ASYSCTL_O_AUXAPLLCONFIG6         0xDDU


//
// APLL Configurations (Both SYS and AUX) (OTP)
//
#define HWREAD_TI_OTP_APLLCONFIG_KEY           (HWREGH(0x70237UL))
#define HWREAD_TI_OTP_APLLCONFIG_BASE_ADDRESS  (HWREG(0x70246UL))
#define HWREAD_TI_OTP_APLLCONFIG1_VALUE        (HWREGH(HWREAD_TI_OTP_APLLCONFIG_BASE_ADDRESS))
#define HWREAD_TI_OTP_APLLCONFIG2_VALUE        (HWREGH(HWREAD_TI_OTP_APLLCONFIG_BASE_ADDRESS + 1U))
#define HWREAD_TI_OTP_APLLCONFIG3_VALUE        (HWREGH(HWREAD_TI_OTP_APLLCONFIG_BASE_ADDRESS + 2U))
#define HWREAD_TI_OTP_APLLCONFIG4_VALUE        (HWREGH(HWREAD_TI_OTP_APLLCONFIG_BASE_ADDRESS + 3U))
#define HWREAD_TI_OTP_APLLCONFIG5_VALUE        (HWREGH(HWREAD_TI_OTP_APLLCONFIG_BASE_ADDRESS + 4U))
#define HWREAD_TI_OTP_APLLCONFIG6_VALUE        (HWREGH(HWREAD_TI_OTP_APLLCONFIG_BASE_ADDRESS + 5U))
#define HWREAD_TI_OTP_APLLCONFIG7_VALUE        (HWREGH(HWREAD_TI_OTP_APLLCONFIG_BASE_ADDRESS + 6U))
#define HWREAD_TI_OTP_APLLCONFIG8_VALUE        (HWREGH(HWREAD_TI_OTP_APLLCONFIG_BASE_ADDRESS + 7U))
#define HWREAD_TI_OTP_APLLCONFIG9_VALUE        (HWREGH(HWREAD_TI_OTP_APLLCONFIG_BASE_ADDRESS + 8U))
#define HWREAD_TI_OTP_APLLCONFIG10_VALUE       (HWREGH(HWREAD_TI_OTP_APLLCONFIG_BASE_ADDRESS + 9U))

//
// Device Cal OTP Location and Function Call
//
#define HWREAD_TI_OTP_DEVCAL_KEY        (HWREGH(0x70238UL))
#define HWREAD_DEVICE_CAL_LOCATION      (HWREG(0x70248UL))
#define CBROM_DEVCAL                    ((void (*)(void))HWREAD_DEVICE_CAL_LOCATION)

//
// OTP Version/CPU ID value (Used as OTP access to power up flash)
//
#define HWREAD_OTP_VERSION_FOR_BOOT     (HWREGH(0x70223UL))

//
// Boot Escape/Patch Point OTP Addresses
//
#define OTP_BOOT_ESCAPE_TABLE_END          0x703ECUL

#define CPU1BROM_TI_OTP_ESCAPE_POINT_15   (HWREG((OTP_BOOT_ESCAPE_TABLE_END)-28))
#define CPU1BROM_TI_OTP_ESCAPE_POINT_14   (HWREG((OTP_BOOT_ESCAPE_TABLE_END)-26))
#define CPU1BROM_TI_OTP_ESCAPE_POINT_13   (HWREG((OTP_BOOT_ESCAPE_TABLE_END)-24))
#define CPU1BROM_TI_OTP_ESCAPE_POINT_12   (HWREG((OTP_BOOT_ESCAPE_TABLE_END)-22))
#define CPU1BROM_TI_OTP_ESCAPE_POINT_11   (HWREG((OTP_BOOT_ESCAPE_TABLE_END)-20))
#define CPU1BROM_TI_OTP_ESCAPE_POINT_10   (HWREG((OTP_BOOT_ESCAPE_TABLE_END)-18))
#define CPU1BROM_TI_OTP_ESCAPE_POINT_9    (HWREG((OTP_BOOT_ESCAPE_TABLE_END)-16))
#define CPU1BROM_TI_OTP_ESCAPE_POINT_8    (HWREG((OTP_BOOT_ESCAPE_TABLE_END)-14))
#define CPU1BROM_TI_OTP_ESCAPE_POINT_7    (HWREG((OTP_BOOT_ESCAPE_TABLE_END)-12))
#define CPU1BROM_TI_OTP_ESCAPE_POINT_6    (HWREG((OTP_BOOT_ESCAPE_TABLE_END)-10))
#define CPU1BROM_TI_OTP_ESCAPE_POINT_5    (HWREG((OTP_BOOT_ESCAPE_TABLE_END)-8))
#define CPU1BROM_TI_OTP_ESCAPE_POINT_4    (HWREG((OTP_BOOT_ESCAPE_TABLE_END)-6))
#define CPU1BROM_TI_OTP_ESCAPE_POINT_3    (HWREG((OTP_BOOT_ESCAPE_TABLE_END)-4))
#define CPU1BROM_TI_OTP_ESCAPE_POINT_2    (HWREG((OTP_BOOT_ESCAPE_TABLE_END)-2))
#define CPU1BROM_TI_OTP_ESCAPE_POINT_1    (HWREG((OTP_BOOT_ESCAPE_TABLE_END)-0))

//
// Boot Selection Defines
//

#define CPU1_ALL_BMSP_DISABLED_MASK     0x00FFFFFFUL
#define CPU1_PIN_CONFIG_MASK            0xFFU
#define CPU1_BMSP_DISABLED              0xFFU

#define CPU1_INVALID_GPIO42             42U //USB0DM
#define CPU1_INVALID_GPIO43             43U //USB0DP
#define CPU1_GPIO169                    169U
#define CPU1_GPIO254                    254U

//
// Miscellaneous Boot Defines
//
#define ERROR                           1U
#define NO_ERROR                        0U
#define BROM_EIGHT_BIT_HEADER           0x08AAU
#define BOOTPIN_CONFIG_STANDALONE_KEY   0xA5U
#define BOOTPIN_CONFIG_KEY              0x5AU
#define FLASH_NOT_PROGRAMMED            0x1U
#define FLASH_IS_PROGRAMMED             0x0U
#define RAM_GSX_NOT_DONE                0x0U
#define CAN_BOOT_DEFAULT_BIT_TIMING     0x0U
#define CAN_BOOT_USE_XTAL               0x1U
#define USB_BOOT_ENABLE_PIE_INIT        0x1U
#define BROM_PLL_ENABLE_ERROR           0xFFFFU
#define BROM_PLL_ENABLE_SUCCESS         0x0U
#define BROM_CMCLKCTL_MASK              0xFU

//
// Globals
//
typedef uint16_t (*uint16fptr)();
extern  uint16fptr GetWordData;

//
// Function prototypes
//
extern void CPU1BROM_initDCSM(void);

extern __interrupt void CPU1BROM_itrapISR(void);
extern __interrupt void CPU1BROM_nmiHandler(void);
extern void CPU1BROM_enablePIEinBoot(void);

extern uint32_t GetLongData(void);
extern void CopyData(void);
extern void ReadReservedFn(void);
extern uint16_t CPU1BROM_enableSysPLL(uint16_t multiplier, uint16_t divider);
extern uint16_t CPU1BROM_enableAuxPLL(uint16_t multiplier, uint16_t divider);
extern uint32_t PBIST_PORMemoryTest(void);

extern uint32_t I2C_Boot(uint32_t  bootMode);
extern uint32_t SCI_Boot(uint32_t  bootMode);
extern uint32_t USB_Boot(uint32_t  bootMode, uint16_t enablePIEInit);
extern uint32_t SPI_Boot(uint32_t  bootMode);
extern uint32_t DCAN_Boot(uint32_t bootMode, uint32_t bitTimingRegValue, uint16_t switchToXTAL);
extern uint32_t Parallel_Boot(void);

extern uint32_t CPU1BROM_selectBootMode(void);

extern uint32_t CPU1BROM_calculateCMAC(volatile uint32_t startAddress,
                                       volatile uint32_t endAddress,
                                       volatile uint32_t signatureAddress);

#endif //CPU1_BOOTROM_H_

//
// End of file
//
