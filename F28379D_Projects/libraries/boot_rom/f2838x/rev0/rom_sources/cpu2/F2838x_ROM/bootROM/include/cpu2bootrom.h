//###########################################################################
//
// FILE:   cpu2bootrom.h
//
// TITLE:  CPU2 BootROM Definitions.
//
//###########################################################################
// $TI Release: $
// $Release Date: $
//###########################################################################

#ifndef CPU2_BOOTROM_H_
#define CPU2_BOOTROM_H_

//
// Included Files
//
#include <stdint.h>
#include "hw_types.h"
#include "hw_memmap.h"
#include "hw_sysctl.h"
#include "hw_ipc.h"
#include "sysctl.h"
#include "cpu.h"
#include "flash.h"
#include "pin_map.h"
#include "gpio.h"

//
// Read IPCBOOTMODE Boot Mode Bit Field
//
#define HWREAD_IPCBOOTMODE_BOOTMODE    (HWREG(IPC_CPU2TOCPU1_BASE + IPC_O_CPU1TOCPU2IPCBOOTMODE) & 0xFFU)
#define HWREAD_IPCBOOTMODE_DEVICE_FREQ ((HWREG(IPC_CPU2TOCPU1_BASE + IPC_O_CPU1TOCPU2IPCBOOTMODE) & 0xFF00UL) >> 0x8U)
#define HWREAD_IPCBOOTMODE_COPY_LENGTH ((HWREG(IPC_CPU2TOCPU1_BASE + IPC_O_CPU1TOCPU2IPCBOOTMODE) & 0xF0000UL) >> 0x10U)
#define HWREAD_IPCBOOTMODE_KEY         ((HWREG(IPC_CPU2TOCPU1_BASE + IPC_O_CPU1TOCPU2IPCBOOTMODE) & 0xFF000000UL) >> 0x18U)
#define IPCBOOTMODE_KEY                0x5AU
#define IPCBOOTMODE_COPY_LENGTH_MAX    0xAU   //1000 words
#define IPCBOOTMODE_DEVICE_FREQ_MIN    0xAU   //10MHz
#define IPCBOOTMODE_DEVICE_FREQ_MAX    0xD2U  //210MHz

//
// CPU2 Boot States
//
#define CPU2BROM_READBOOTMODE              0xA5F0U
#define CPU2BROM_WAITFORCOMMAND            0xA5F3U
#define CPU2BROM_RUNBOOTMODE               0xA5FCU
#define CPU2BROM_BRANCHTOAPPLICATION       0xA5F9U

//
// Boot Mode Options
//

//
// Wait Boot Option
//
#define WAIT_FOR_COMMAND                  0x0U
#define CPU2BROM_RETURN_TO_WAITFORCOMMAND 0xFFFFFFFFUL

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
#define RAM_BOOT                        0x05U    //Start of M0 RAM

//
// Secure Flash Boot Options
//
#define SECURE_FLASH_BOOT               0x0AU    //Start of BANK 0 Sector 0
#define SECURE_FLASH_BOOT_ALT1          0x2AU    //Start of BANK 0 Sector 4
#define SECURE_FLASH_BOOT_ALT2          0x4AU    //Start of BANK 0 Sector 8
#define SECURE_FLASH_BOOT_ALT3          0x6AU    //Start of BANK 0 Sector 13
#define SECURE_FLASH_BOOT_PASS          0x00U
#define SECURE_FLASH_BOOT_FAIL          0xFFFFFFFFUL

//
// User OTP Boot Option
//
#define USER_OTP_BOOT                   0x0BU

//
// CPU1-to-CPU2 IPC Msg Copy to RAM and Boot
//
#define IPC_MSG_COPY_BOOT               0x0CU    //Copies to M1RAM
#define IPC_MSG_COPY_BOOT_MIN_LENGTH    0x0U
#define IPC_MSG_COPY_BOOT_MAX_LENGTH    0xAU

//
// Fixed Boot Entry Points (Addresses)
//

//
// Flash (secure and unsecure) Entry Points
//
#define FLASH_ENTRY_POINT               0x080000UL    //BANK0 Sector 0
#define FLASH_ENTRY_POINT_ALT1          0x088000UL    //BANK0 Sector 4
#define FLASH_ENTRY_POINT_ALT2          0x0A8000UL    //BANK0 sector 8
#define FLASH_ENTRY_POINT_ALT3          0x0BE000UL    //BANK0 sector 13

//
// RAM Boot: M0 RAM Entry Point
//
#define M0RAM_ENTRY_POINT               0x000000UL    //M0 start address

//
// IPC Message Copy Boot
// CPU1-to-CPU2 Message RAM 1 Address
// M1 RAM Entry Point
//
#define CPU1_TO_CPU2_MESSAGE_RAM        0x03A400UL    // CPU1TOCPU2MSGRAM1 start address
#define M1RAM_ENTRY_POINT               0x000400UL    //M1 start address

//
// User OTP Entry Point
//
#define USER_OTP_ENTRY_POINT            0x078000UL

//
// CPU2 Boot ROM Boot Status Bit Fields
//
#define CPU2_BOOTROM_BOOTSTS_MASK                    0x000000FFUL
#define CPU2_BOOTROM_BOOTSTS_SYSTEM_START_BOOT       0x00000001UL
#define CPU2_BOOTROM_BOOTSTS_IN_FLASH_BOOT           0x00000002UL
#define CPU2_BOOTROM_BOOTSTS_IN_SECURE_FLASH_BOOT    0x00000003UL
#define CPU2_BOOTROM_BOOTSTS_IN_IPC_MSG_RAM_BOOT     0x00000004UL
#define CPU2_BOOTROM_BOOTSTS_IN_RAM_BOOT             0x00000005UL
#define CPU2_BOOTROM_BOOTSTS_IN_OTP_BOOT             0x00000006UL
#define CPU2_BOOTROM_BOOTSTS_IN_WAIT_BOOT            0x00000007UL
#define CPU2_BOOTROM_BOOTSTS_WAITING_FOR_FLAG        0x00000008UL

//
// CPU2 Boot ROM Health Status Bit Fields
//
#define CPU2_BOOTROM_HEALTH_STATUS_MASK              0xFFFFFF00UL

#define CPU2_BOOTROM_RESC_HANDLED                    0x00001000UL
#define CPU2_BOOTROM_HANDLED_XRSN                    0x00002000UL
#define CPU2_BOOTROM_HANDLED_POR                     0x00004000UL
#define CPU2_BOOTROM_HANDLED_HWBIST                  0x00008000UL

#define CPU2_BOOTROM_RAM_INIT_COMPLETE               0x00020000UL
#define CPU2_BOOTROM_GOT_AN_INVALID_IPC_BOOT_VALUE   0x00040000UL
#define CPU2_BOOTROM_MSG_RAM_COPY_LENGTH_INVALID     0x00080000UL

#define CPU2_BOOTROM_FAILED_SECURE_FLASH_CMAC        0x00200000UL
#define CPU2_BOOTROM_GOT_AN_ERAD_NMI                 0x00400000UL
#define CPU2_BOOTROM_GOT_ITRAP                       0x00800000UL
#define CPU2_BOOTROM_GOT_A_PIE_MISMATCH              0x01000000UL
#define CPU2_BOOTROM_GOT_A_RL_NMI                    0x02000000UL
#define CPU2_BOOTROM_GOT_A_PIE_VECTOR_NMI            0x04000000UL
#define CPU2_BOOTROM_GOT_A_HWBIST_NMI                0x08000000UL
#define CPU2_BOOTROM_GOT_A_FLASH_UNCERR_NMI          0x10000000UL
#define CPU2_BOOTROM_GOT_A_RAM_UNCERR_NMI            0x20000000UL
#define CPU2_BOOTROM_GOT_A_MCLK_NMI                  0x40000000UL

#define CPU2_BOOTROM_BOOT_COMPLETE                   0x80000000UL

//
// CPU2 to CPU1 Error IPC Commands
//
#define CPU2TOCPU1_BOOTROM_COMMAND_ILLEGAL           0x00000000UL
#define CPU2TOCPU1_BOOTROM_BOOT_CMD_INVALID          0xFFFFFFFFUL
#define CPU2TOCPU1_BOOTROM_IN_ITRAP                  0xFFFFFFFEUL
#define CPU2TOCPU1_BOOTROM_NMI                       0xFFFFFFFAUL
#define CPU2TOCPU1_BOOTROM_FAILED_CMAC               0xFFFFFFF9UL

//
// Boot Escape/Patch Point OTP Addresses
//
#define OTP_BOOT_ESCAPE_TABLE_END       0x703ECUL

#define CPU2BROM_TI_OTP_ESCAPE_POINT_15   (HWREG((OTP_BOOT_ESCAPE_TABLE_END)-28U))
#define CPU2BROM_TI_OTP_ESCAPE_POINT_14   (HWREG((OTP_BOOT_ESCAPE_TABLE_END)-26U))
#define CPU2BROM_TI_OTP_ESCAPE_POINT_13   (HWREG((OTP_BOOT_ESCAPE_TABLE_END)-24U))
#define CPU2BROM_TI_OTP_ESCAPE_POINT_12   (HWREG((OTP_BOOT_ESCAPE_TABLE_END)-22U))
#define CPU2BROM_TI_OTP_ESCAPE_POINT_11   (HWREG((OTP_BOOT_ESCAPE_TABLE_END)-20U))
#define CPU2BROM_TI_OTP_ESCAPE_POINT_10   (HWREG((OTP_BOOT_ESCAPE_TABLE_END)-18U))
#define CPU2BROM_TI_OTP_ESCAPE_POINT_9    (HWREG((OTP_BOOT_ESCAPE_TABLE_END)-16U))
#define CPU2BROM_TI_OTP_ESCAPE_POINT_8    (HWREG((OTP_BOOT_ESCAPE_TABLE_END)-14U))
#define CPU2BROM_TI_OTP_ESCAPE_POINT_7    (HWREG((OTP_BOOT_ESCAPE_TABLE_END)-12U))
#define CPU2BROM_TI_OTP_ESCAPE_POINT_6    (HWREG((OTP_BOOT_ESCAPE_TABLE_END)-10U))
#define CPU2BROM_TI_OTP_ESCAPE_POINT_5    (HWREG((OTP_BOOT_ESCAPE_TABLE_END)-8U))
#define CPU2BROM_TI_OTP_ESCAPE_POINT_4    (HWREG((OTP_BOOT_ESCAPE_TABLE_END)-6U))
#define CPU2BROM_TI_OTP_ESCAPE_POINT_3    (HWREG((OTP_BOOT_ESCAPE_TABLE_END)-4U))
#define CPU2BROM_TI_OTP_ESCAPE_POINT_2    (HWREG((OTP_BOOT_ESCAPE_TABLE_END)-2U))
#define CPU2BROM_TI_OTP_ESCAPE_POINT_1    (HWREG((OTP_BOOT_ESCAPE_TABLE_END)-0U))

//
// Flash Configuration
//
#define CPU2_FLASH_PSLEEP_25MHZ_TIMEOUT_VALUE        63U        //Loop = ~28 cycles @ 25MHz (Loop timeout value = (70us * freq)/28)
#define CPU2_FLASH_PSLEEP_50MHZ_TIMEOUT_VALUE        90U        //Loop = ~28 cycles @ 50MHz (Loop timeout value = (50us * freq)/28)
#define CPU2_FLASH_PSLEEP_100MHZ_TIMEOUT_VALUE       179U       //Loop = ~28 cycles @ 100MHz(Loop timeout value = (50us * freq)/28)
#define CPU2_FLASH_PSLEEP_150MHZ_TIMEOUT_VALUE       268U       //Loop = ~28 cycles @ 150MHz(Loop timeout value = (50us * freq)/28)
#define CPU2_FLASH_PSLEEP_210MHZ_TIMEOUT_VALUE       375U       //Loop = ~28 cycles @ 210MHz(Loop timeout value = (50us * freq)/28)
#define CPU2_FLASH_PSLEEP_25MHZ_VALUE                (0x138U * 2U)
#define CPU2_FLASH_PSLEEP_50MHZ_VALUE                (0x271U * 2U)
#define CPU2_FLASH_PSLEEP_100MHZ_VALUE               (0x4E2U * 2U)
#define CPU2_FLASH_PSLEEP_150MHZ_VALUE               (0x753U * 2U)
#define CPU2_FLASH_PSLEEP_210MHZ_VALUE               (0xA41U * 2U)
#define CPU2_FLASH_DEFAULT_PSLEEP                    (0xA41U * 2U)
#define CPU2_FLASH_DEFAULT_RWAIT                     0x3U

//
// Misc
//
#define CPU2_IPC_SUCCESS                             0x0U
#define CPU2_IPC_FAILURE                             0x1U
#define CPU2_NO_IPC_MSG                              0x0U
#define NO_ADDRESS_DATA                              0x0U

//
// Function prototypes
//
extern __interrupt void CPU2BROM_itrapISR(void);
extern __interrupt void CPU2BROM_nmiHandler(void);
extern __interrupt void CPU2BROM_pieVectorMismatchHandler(void);

extern uint32_t CPU2BROM_sendErrorIPC(uint32_t errorCommand, uint32_t address);
extern uint32_t CPU2BROM_startSystemBoot(void);
extern void CPU2BROM_setupDeviceSystems(void);
extern void CPU2BROM_verifyBootCommand(void);
extern void CPU2BROM_performCopyToRAM(uint32_t entryAddress, uint16_t copyLength);

extern void CPU2BROM_setIPCBootStatus(void);

extern uint32_t CPU2BROM_calculateCMAC(volatile uint32_t startAddress,
                                       volatile uint32_t endAddress,
                                       volatile uint32_t signatureAddress);

#endif //CPU2_BOOTROM_H_

//
// End of file
//
