//###########################################################################
//
// FILE:   cmbootrom.h
//
// TITLE:  CM BootROM Definitions.
//
//###########################################################################
// $TI Release: $
// $Release Date: $
//###########################################################################

#ifndef CM_BOOTROM_H_
#define CM_BOOTROM_H_

//
// Included Files
//
#include <stdint.h>
#include "hw_nvic.h"
#include "hw_types.h"
#include "hw_memmap.h"
#include "hw_sysctl.h"
#include "hw_nmi.h"
#include "sysctl.h"
#include "hw_ipc.h"
#include "flash.h"

//
// Init Boot Defines
//
#define CM_SYSCTL_RESC_REG             (CMSYSCTL_BASE + SYSCTL_O_CMRESC)

//
// Read IPCBOOTMODE Bit Fields
//
#define HWREAD_IPCBOOTMODE_BOOTMODE     (HWREG(IPC_CMTOCPU1_BASE + IPC_O_CPU1TOCMIPCBOOTMODE) & 0xFFU)
#define HWREAD_IPCBOOTMODE_DEVICE_FREQ  ((HWREG(IPC_CMTOCPU1_BASE + IPC_O_CPU1TOCMIPCBOOTMODE) & 0xFF00U) >> 0x8U)
#define HWREAD_IPCBOOTMODE_COPY_LENGTH  ((HWREG(IPC_CMTOCPU1_BASE + IPC_O_CPU1TOCMIPCBOOTMODE) & 0xF0000UL) >> 0x10U)
#define HWREAD_IPCBOOTMODE_KEY          ((HWREG(IPC_CMTOCPU1_BASE + IPC_O_CPU1TOCMIPCBOOTMODE) & 0xFF000000UL) >> 0x18U)
#define IPCBOOTMODE_KEY                 0x5AU
#define IPCBOOTMODE_COPY_LENGTH_MAX     0xAU   //Represents 1000 words
#define IPCBOOTMODE_DEVICE_FREQ_MIN     0xAU   //Represents 10MHz
#define IPCBOOTMODE_DEVICE_FREQ_MAX     0x7DU  //Represents 125MHz

//
// CM Boot States
//
#define CMBROM_READBOOTMODE             0xA5F0U
#define CMBROM_WAITFORCOMMAND           0xA5F3U
#define CMBROM_RUNBOOTMODE              0xA5FCU
#define CMBROM_BRANCHTOAPPLICATION      0xA5F9U

//
// Boot Mode Options
//

//
// Wait Boot Option
//
#define WAIT_FOR_COMMAND                0x0U
#define CMBROM_RETURN_TO_WAITFORCOMMAND 0xFFFFFFFFUL

//
// Flash Boot Options
//
#define FLASH_BOOT                      0x03U    //Start of BANK 0 Sector 0
#define FLASH_BOOT_ALT1                 0x23U    //Start of BANK 0 Sector 4
#define FLASH_BOOT_ALT2                 0x43U    //Start of BANK 0 Sector 8
#define FLASH_BOOT_ALT3                 0x63U    //Start of BANK 0 Sector 13

//
// RAM Boot Options
//
#define RAM_BOOT                        0x05U    //Start of S0 RAM

//
// Secure Flash Boot Options
//
#define SECURE_FLASH_BOOT               0x0AU    //Start of BANK 0 Sector 0
#define SECURE_FLASH_BOOT_ALT1          0x2AU    //Start of BANK 0 Sector 4
#define SECURE_FLASH_BOOT_ALT2          0x4AU    //Start of BANK 0 Sector 8
#define SECURE_FLASH_BOOT_ALT3          0x6AU    //Start of BANK 0 Sector 13
#define SECURE_FLASH_BOOT_PASS          0x0U
#define SECURE_FLASH_BOOT_FAIL          0xFFFFFFFFUL

//
// User OTP Boot Option
//
#define USER_OTP_BOOT                   0x0BU

//
// CPU1-to-CM IPC Msg Copy to RAM and Boot
//
#define IPC_MSG_COPY_BOOT               0x0CU   //Copies to S0RAM
#define IPC_MSG_COPY_BOOT_MIN_LENGTH    0x0U
#define IPC_MSG_COPY_BOOT_MAX_LENGTH    0xAU

//
// Fixed Boot Entry Points (Addresses)
//

//
// Flash (secure and unsecure) Entry Points
//
#define FLASH_ENTRY_POINT               0x00200000UL    //BANK0 Sector 0
#define FLASH_ENTRY_POINT_ALT1          0x00210000UL    //BANK0 Sector 4
#define FLASH_ENTRY_POINT_ALT2          0x00250000UL    //BANK0 sector 8
#define FLASH_ENTRY_POINT_ALT3          0x0027C000UL    //BANK0 sector 13

//
// S0 RAM Entry Point
//
#define S0RAM_ENTRY_POINT               (S0RAM_BASE + 0x800UL)  //S0 start address + 2KB offset to avoid stack

//
// CPU1-to-CM Message RAM 1 Address
//
#define CPU1_TO_CM_MESSAGE_RAM          CPU1TOCMMSGRAM1_BASE

//
// User OTP Entry Point
//
#define USER_OTP_ENTRY_POINT            0x003C0000UL

//
// CM Boot ROM Boot Status Bit Fields
//
#define CM_BOOTROM_BOOTSTS_MASK                    0x000000FFUL
#define CM_BOOTROM_BOOTSTS_SYSTEM_START_BOOT       0x00000001UL
#define CM_BOOTROM_BOOTSTS_IN_FLASH_BOOT           0x00000002UL
#define CM_BOOTROM_BOOTSTS_IN_SECURE_FLASH_BOOT    0x00000003UL
#define CM_BOOTROM_BOOTSTS_IN_IPC_MSG_RAM_BOOT     0x00000004UL
#define CM_BOOTROM_BOOTSTS_IN_RAM_BOOT             0x00000005UL
#define CM_BOOTROM_BOOTSTS_IN_OTP_BOOT             0x00000006UL
#define CM_BOOTROM_BOOTSTS_IN_WAIT_BOOT            0x00000007UL
#define CM_BOOTROM_BOOTSTS_WAITING_FOR_FLAG        0x00000008UL

//
// CM Boot ROM Health Status Bit Fields
//
#define CM_BOOTROM_HEALTH_STATUS_MASK              0xFFFFFF00UL
#define CM_BOOTROM_RESC_HANDLED                    0x00001000UL
#define CM_BOOTROM_HANDLED_POR                     0x00004000UL

#define CM_BOOTROM_RAM_INIT_COMPLETE               0x00020000UL
#define CM_BOOTROM_GOT_AN_INVALID_IPC_BOOT_VALUE   0x00040000UL
#define CM_BOOTROM_MSG_RAM_COPY_LENGTH_INVALID     0x00080000UL
                                                             
#define CM_BOOTROM_FAILED_SECURE_FLASH_CMAC        0x00200000UL
#define CM_BOOTROM_GOT_UNASSIGNED_INTERRUPT        0x00400000UL
#define CM_BOOTROM_GOT_HARD_FAULT                  0x00800000UL

#define CM_BOOTROM_GOT_A_ECAT_NMI                  0x02000000UL
#define CM_BOOTROM_GOT_A_WWD_NMI                   0x04000000UL
#define CM_BOOTROM_GOT_A_MCAN_UNCERR_NMI           0x08000000UL
#define CM_BOOTROM_GOT_A_FLASH_UNCERR_NMI          0x10000000UL
#define CM_BOOTROM_GOT_A_RAM_UNCERR_NMI            0x20000000UL
#define CM_BOOTROM_GOT_A_MCLK_NMI                  0x40000000UL
                                                             
#define CM_BOOTROM_BOOT_COMPLETE                   0x80000000UL

//
// CM to CPU1 Error IPC Commands
//
#define CMTOCPU1_BOOTROM_COMMAND_ILLEGAL           0x00000000UL
#define CMTOCPU1_BOOTROM_BOOT_CMD_INVALID          0xFFFFFFFFUL
#define CMTOCPU1_BOOTROM_HARD_FAULT                0xFFFFFFFEUL
#define CMTOCPU1_BOOTROM_UNASSIGNED_INTERRUPT      0xFFFFFFFBUL
#define CMTOCPU1_BOOTROM_NMI                       0xFFFFFFFAUL
#define CMTOCPU1_BOOTROM_FAILED_CMAC               0xFFFFFFF9UL

//
// Boot Escape/Patch Point OTP Addresses
//
#define OTP_BOOT_ESCAPE_TABLE_END		0x3807D8UL

#define CMBROM_TI_OTP_ESCAPE_POINT_15   (HWREG((OTP_BOOT_ESCAPE_TABLE_END)-56))
#define CMBROM_TI_OTP_ESCAPE_POINT_14   (HWREG((OTP_BOOT_ESCAPE_TABLE_END)-52))
#define CMBROM_TI_OTP_ESCAPE_POINT_13   (HWREG((OTP_BOOT_ESCAPE_TABLE_END)-48))
#define CMBROM_TI_OTP_ESCAPE_POINT_12   (HWREG((OTP_BOOT_ESCAPE_TABLE_END)-44))
#define CMBROM_TI_OTP_ESCAPE_POINT_11   (HWREG((OTP_BOOT_ESCAPE_TABLE_END)-40))
#define CMBROM_TI_OTP_ESCAPE_POINT_10   (HWREG((OTP_BOOT_ESCAPE_TABLE_END)-36))
#define CMBROM_TI_OTP_ESCAPE_POINT_9    (HWREG((OTP_BOOT_ESCAPE_TABLE_END)-32))
#define CMBROM_TI_OTP_ESCAPE_POINT_8    (HWREG((OTP_BOOT_ESCAPE_TABLE_END)-28))
#define CMBROM_TI_OTP_ESCAPE_POINT_7    (HWREG((OTP_BOOT_ESCAPE_TABLE_END)-24))
#define CMBROM_TI_OTP_ESCAPE_POINT_6    (HWREG((OTP_BOOT_ESCAPE_TABLE_END)-20))
#define CMBROM_TI_OTP_ESCAPE_POINT_5    (HWREG((OTP_BOOT_ESCAPE_TABLE_END)-16))
#define CMBROM_TI_OTP_ESCAPE_POINT_4    (HWREG((OTP_BOOT_ESCAPE_TABLE_END)-12))
#define CMBROM_TI_OTP_ESCAPE_POINT_3    (HWREG((OTP_BOOT_ESCAPE_TABLE_END)-8))
#define CMBROM_TI_OTP_ESCAPE_POINT_2    (HWREG((OTP_BOOT_ESCAPE_TABLE_END)-4))
#define CMBROM_TI_OTP_ESCAPE_POINT_1    (HWREG((OTP_BOOT_ESCAPE_TABLE_END)-0))

//
// Flash Configuration
//
#define CM_FLASH_PSLEEP_25MHZ_TIMEOUT_VALUE        73U        //Loop = ~24 cycles @ 25MHz (Loop timeout value = (70us * freq)/28)
#define CM_FLASH_PSLEEP_50MHZ_TIMEOUT_VALUE        104U       //Loop = ~24 cycles @ 50MHz (Loop timeout value = (50us * freq)/28)
#define CM_FLASH_PSLEEP_100MHZ_TIMEOUT_VALUE       208U       //Loop = ~24 cycles @ 100MHz(Loop timeout value = (50us * freq)/28)
#define CM_FLASH_PSLEEP_125MHZ_TIMEOUT_VALUE       260U       //Loop = ~24 cycles @ 125MHz(Loop timeout value = (50us * freq)/28)
#define CM_FLASH_PSLEEP_25MHZ_VALUE                (0x138U * 2U)
#define CM_FLASH_PSLEEP_50MHZ_VALUE                (0x271U * 2U)
#define CM_FLASH_PSLEEP_100MHZ_VALUE               (0x4E2U * 2U)
#define CM_FLASH_PSLEEP_125MHZ_VALUE               (0x61AU * 2U)
#define CM_FLASH_DEFAULT_PSLEEP                    (0x61AU * 2U)
#define CM_FLASH_DEFAULT_RWAIT                     0x2U

//
// Misc
//
#define CM_IPC_SUCCESS                             0x0U
#define CM_IPC_FAILURE                             0x1U
#define CM_NO_IPC_MSG                              0x0U
#define NO_ADDRESS_DATA                            0x0U
#define CM_NMI_CLEAR_KEY                           0x56740000UL
#define CM_NMI_ENABLE_KEY                          0x67890000UL

//
// Function prototypes
//
extern __interrupt void CMBROM_nmiHandler(void);
extern __interrupt void CMBROM_hardFaultISR(void);
extern __interrupt void CMBROM_defaultHandler(void);
extern void CMBROM_verifyBootCommand(void);
extern void CMBROM_setupDeviceSystems(void);

extern uint32_t CMBROM_startSystemBoot(void);
extern uint16_t CMBROM_selectBootMode(void);
extern void CMBROM_performCopyToRAM(uint32_t entryAddress, uint16_t copyLength);

extern uint32_t CMBROM_sendErrorIPC(uint32_t errorCommand, uint32_t address);
extern void CMBROM_setIPCBootStatus(void);

extern uint32_t CMBROM_calculateCMAC(volatile uint32_t startAddress,
                                     volatile uint32_t endAddress,
                                     volatile uint32_t signatureAddress);

#endif //CM_BOOTROM_H_

//
// End of file
//
