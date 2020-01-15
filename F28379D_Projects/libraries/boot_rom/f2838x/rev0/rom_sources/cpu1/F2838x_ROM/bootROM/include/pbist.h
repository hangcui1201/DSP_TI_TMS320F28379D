//###########################################################################
//
// FILE:   pbist.h
//
// TITLE:  PBIST Definitions
//
//###########################################################################
// $TI Release: $
// $Release Date: $
//###########################################################################

//
// Included Files
//
#include "cpu1bootrom.h"

//*****************************************************************************
//
// Registers and their bits descriptions
//
//*****************************************************************************

//
// RAM INIT registers
//
#define PBIST_MEMCFG_DXINT    (0x5F412UL)
#define PBIST_MEMCFG_LSXINT   (0x5F432UL)
#define PBIST_MEMCFG_GSXINT   (0x5F452UL)
#define PBIST_MEMCFG_MSGXINT  (0x5F472UL)

//
// PBIST register addresses
//
#define PBIST_DLRT              0x5E364 // PBIST Data Logger Register
#define PBIST_STR               0x5E36C // Resume testing
#define PBIST_PACT              0x5E380 // PBIST Activate Register
#define PBIST_OVERRIDE          0x5E388 // PBIST Override Register
#define PBIST_FAIL_STATUS_0     0x5E390 // Fail Status - Port 0
#define PBIST_FAIL_STATUS_1     0x5E394 // Fail Status - Port 1
#define PBIST_ALGO              0x5E3C4 // PBIST Algorithm Register
#define PBIST_RINFOL            0x5E3C8 // RAM Info Mask Register Lower
#define PBIST_RINFOU            0x5E3CC // RAM Info Mask Register Higher

//
// System Device Capability register addresses
//
#define SYSCTL_DC0       (0x0005D000U + 0x10U)  // 0:C28-2 (Mx,Dx,CLAMI0-1,CLADI0-1,PIEI0-1,CPUMSG2-3,CMMSGI0-1), 1: CM4 (CMMSGO2-3, CMMSGI2-CMMSGI3, CX0-3, SX0-9)
#define SYSCTL_DC1       (0x0005D000U + 0x12U)  // 0:C28-1_FPU_TMU, 1:C28-2_FPU_TMU - Will be taken care in algo-group
#define SYSCTL_DC11      (0x0005D000U + 0x26U)  // 0: CAN-A 1: CAN-B 4: MCAN
#define SYSCTL_DC12      (0x0005D000U + 0x28U)  // USB Feature 00--> No USB
#define SYSCTL_DC18      (0x0005D000U + 0x34U)  // C28-1 - LS0 - LS7
#define SYSCTL_DC19      (0x0005D000U + 0x36U)  // C28-2 - LS0 - LS7
#define SYSCTL_DC20      (0x0005D000U + 0x38U)  // GS0 - GS15
#define SYSCTL_DC26      (0x0005D000U + 0x44U)  // ECAT, ENET0-3

//
// Peripheral Clock gating register addresses
//
#define SYSCTL_PCLKCR0   (0x0005D300U + 0x22U)
#define SYSCTL_PCLKCR1   (0x0005D300U + 0x24U)
#define SYSCTL_PCLKCR2   (0x0005D300U + 0x26U)
#define SYSCTL_PCLKCR3   (0x0005D300U + 0x28U)
#define SYSCTL_PCLKCR4   (0x0005D300U + 0x2AU)
#define SYSCTL_PCLKCR5   (0x0005D300U + 0x2CU)
#define SYSCTL_PCLKCR6   (0x0005D300U + 0x2EU)
#define SYSCTL_PCLKCR7   (0x0005D300U + 0x30U)
#define SYSCTL_PCLKCR8   (0x0005D300U + 0x32U)
#define SYSCTL_PCLKCR9   (0x0005D300U + 0x34U)
#define SYSCTL_PCLKCR10  (0x0005D300U + 0x36U)
#define SYSCTL_PCLKCR11  (0x0005D300U + 0x38U)
#define SYSCTL_PCLKCR12  (0x0005D300U + 0x3AU)
#define SYSCTL_PCLKCR13  (0x0005D300U + 0x3CU)
#define SYSCTL_PCLKCR14  (0x0005D300U + 0x3EU)
#define SYSCTL_PCLKCR15  (0x0005D300U + 0x40U)
#define SYSCTL_PCLKCR16  (0x0005D300U + 0x42U)
#define SYSCTL_PCLKCR17  (0x0005D300U + 0x44U)
#define SYSCTL_PCLKCR18  (0x0005D300U + 0x46U)
#define SYSCTL_PCLKCR19  (0x0005D300U + 0x48U)
#define SYSCTL_PCLKCR20  (0x0005D300U + 0x4AU)
#define SYSCTL_PCLKCR21  (0x0005D300U + 0x4CU)
#define SYSCTL_PCLKCR22  (0x0005D300U + 0x4EU)
#define SYSCTL_PCLKCR23  (0x0005D300U + 0x50U)

//
// Peripheral soft reset register addresses
//
#define SYSCTL_SOFTPRES0        (0x0005D000U + 0x82U)
#define SYSCTL_SOFTPRES1        (0x0005D000U + 0x84U)
#define SYSCTL_SOFTPRES2        (0x0005D000U + 0x86U)
#define SYSCTL_SOFTPRES3        (0x0005D000U + 0x88U)
#define SYSCTL_SOFTPRES4        (0x0005D000U + 0x8AU)
#define SYSCTL_SOFTPRES5        (0x0005D000U + 0x8CU)
#define SYSCTL_SOFTPRES6        (0x0005D000U + 0x8EU)
#define SYSCTL_SOFTPRES7        (0x0005D000U + 0x90U)
#define SYSCTL_SOFTPRES8        (0x0005D000U + 0x92U)
#define SYSCTL_SOFTPRES9        (0x0005D000U + 0x94U)
#define SYSCTL_SOFTPRES10       (0x0005D000U + 0x96U)
#define SYSCTL_SOFTPRES11       (0x0005D000U + 0x98U)
#define SYSCTL_SOFTPRES12       (0x0005D000U + 0x9AU)
#define SYSCTL_SOFTPRES13       (0x0005D000U + 0x9CU)
#define SYSCTL_SOFTPRES14       (0x0005D000U + 0x9EU)
#define SYSCTL_SOFTPRES15       (0x0005D000U + 0xA0U)
#define SYSCTL_SOFTPRES16       (0x0005D000U + 0xA2U)
#define SYSCTL_SOFTPRES17       (0x0005D000U + 0xA4U)
#define SYSCTL_SOFTPRES18       (0x0005D000U + 0xA6U)
#define SYSCTL_SOFTPRES19       (0x0005D000U + 0xA8U)
#define SYSCTL_SOFTPRES20       (0x0005D000U + 0xAAU)
#define SYSCTL_SOFTPRES21       (0x0005D000U + 0xACU)
#define SYSCTL_SOFTPRES22       (0x0005D000U + 0xAEU)
#define SYSCTL_SOFTPRES23       (0x0005D000U + 0xB0U)


#define SYSCTL_SYSPLLCTL1   (0x0005D200U + 0x0EU)
#define SYSCTL_SYSPLLMULT   (0x0005D200U + 0x14U)
#define SYSCTL_SYSPLLSTS    (0x0005D200U + 0x16U)
#define SYSCTL_AUXPLLCTL1   (0x0005D200U + 0x18U)
#define SYSCTL_AUXPLLMULT   (0x0005D200U + 0x1EU)
#define SYSCTL_AUXPLLSTS    (0x0005D200U + 0x20U)
#define SYSCTL_SYSCLKDIVSEL     (0x0005D200U + 0x22U)
#define SYSCTL_AUXCLKDIVSEL     (0x0005D200U + 0x24U)
#define SYSCTL_CMCLKCTL     (0x0005D200U + 0x38U)


#define SYSCTL_PALLOCATE0       (0x0005DC00U + 0x20U)
//PBIST GPRREG Configurations
#define FLASH_Z1_GPREG2     (0x0005F00AUL)
#define FLASH_Z2_GPREG2     (0x0005F08AUL)
//#define SYSPLL_CONFIG110  (0x5A000000UL) //SYSPLL1: 110
#define SYSPLL_CONFIG110    (0x5A000000UL) //SYSPLL1: 110 SAL to update
#define SYSPLL_CONFIG080    (0x5A0000C0UL) //SYSPLL1: 080
#define SYSPLL_CONFIG060    (0x5A000030UL) //SYSPLL1: 060
#define SYSPLL_CONFIGBYP    (0x5A000090UL) //SYSPLL1: 010
//
// PBIST pie interrupt register
//
#define PBIST_PIE12_IER         (0x0CE0U + 0x18U)
#define PBIST_PIE12_IFR         (0x0CE0U + 0x19U)

//
// RAM init start and check registers
//
#define RAM_INIT_START          0x0005F412U
#define RAM_INIT_CHECK          0x0005F414U
//
// ALGO register bits description
//
#define PBIST_ALGO_TRIPLE_READ_PBIST_ROM         ((uint32_t)1 << 0)
#define PBIST_ALGO_TRIPLE_READ_SECURE_ROMO0      ((uint32_t)1 << 1)
#define PBIST_ALGO_TRIPLE_READ_SECURE_ROMO1      ((uint32_t)1 << 2)
#define PBIST_ALGO_TRIPLE_READ_SECURE_ROMI0      ((uint32_t)1 << 3)
#define PBIST_ALGO_TRIPLE_READ_SECURE_ROMI1      ((uint32_t)1 << 4)

#define PBIST_ALGO_TRIPLE_READ_BOOT_ROMO1        ((uint32_t)1 << 5)
#define PBIST_ALGO_TRIPLE_READ_BOOT_ROMO2        ((uint32_t)1 << 6)
#define PBIST_ALGO_TRIPLE_READ_BOOT_ROMO3        ((uint32_t)1 << 7)
#define PBIST_ALGO_TRIPLE_READ_BOOT_ROMO4        ((uint32_t)1 << 8)
#define PBIST_ALGO_TRIPLE_READ_BOOT_ROMO5        ((uint32_t)1 << 9)
#define PBIST_ALGO_TRIPLE_READ_BOOT_ROMO6        ((uint32_t)1 << 10)

#define PBIST_ALGO_TRIPLE_READ_BOOT_ROMI1        ((uint32_t)1 << 5)
#define PBIST_ALGO_TRIPLE_READ_BOOT_ROMI2        ((uint32_t)1 << 6)
#define PBIST_ALGO_TRIPLE_READ_BOOT_ROMI3        ((uint32_t)1 << 7)
#define PBIST_ALGO_TRIPLE_READ_BOOT_ROMI4        ((uint32_t)1 << 8)
#define PBIST_ALGO_TRIPLE_READ_BOOT_ROMI5        ((uint32_t)1 << 11)
#define PBIST_ALGO_TRIPLE_READ_BOOT_ROMI6        ((uint32_t)1 << 12)

#define PBIST_ALGO_TRIPLE_READ_CLA_DATA_ROM      ((uint32_t)1 << 13)
#define PBIST_ALGO_TRIPLE_READ_TMU_S1I_ROM       ((uint32_t)1 << 14)
#define PBIST_ALGO_TRIPLE_READ_TMU_S2I_ROM       ((uint32_t)1 << 15)
#define PBIST_ALGO_TRIPLE_READ_TMU_Y0_ROM        ((uint32_t)1 << 16)

#define PBIST_ALGO_TRIPLE_READ_CMBOOT_ROM1       ((uint32_t)1 << 17)
#define PBIST_ALGO_TRIPLE_READ_CMBOOT_ROM2       ((uint32_t)1 << 18)
#define PBIST_ALGO_TRIPLE_READ_HWBIST_ROM0       ((uint32_t)1 << 19)
#define PBIST_ALGO_TRIPLE_READ_HWBIST_ROM1       ((uint32_t)1 << 20)
#define PBIST_ALGO_TRIPLE_READ_HWBIST_ROM2       ((uint32_t)1 << 21)
#define PBIST_ALGO_TRIPLE_READ_HWBIST_ROM3       ((uint32_t)1 << 22)  //Have same signature as the previous ROM

#define PBIST_ALGO_MARCH13N_SINGLE_PORT          ((uint32_t)1 << 23)

//ROM MINFO Values --> The below values are wrong and is not used in the testcase
#define PBIST_MINFO_TRIPLE_READ_CPU1_CLA_DATA_ROM      ((uint32_t)1 << 17)
#define PBIST_MINFO_TRIPLE_READ_CPU2_CLA_DATA_ROM      ((uint32_t)1 << 18)
#define PBIST_MINFO_TRIPLE_READ_CPU1_TMU_S1I_ROM       ((uint32_t)1 << 19)
#define PBIST_MINFO_TRIPLE_READ_CPU2_TMU_S1I_ROM       ((uint32_t)1 << 20)
#define PBIST_MINFO_TRIPLE_READ_CPU1_TMU_S2I_ROM       ((uint32_t)1 << 21)
#define PBIST_MINFO_TRIPLE_READ_CPU2_TMU_S2I_ROM       ((uint32_t)1 << 22)
#define PBIST_MINFO_TRIPLE_READ_CPU1_TMU_Y0_ROM        ((uint32_t)1 << 23)
#define PBIST_MINFO_TRIPLE_READ_CPU2_TMU_Y0_ROM        ((uint32_t)1 << 24)


#define PBIST_MINFO_ECAT_DC_0            ((uint64_t)1 << 31)
#define PBIST_MINFO_CX_DC_0              ((uint64_t)1 << 31)
#define PBIST_MINFO_DX_DC_0              ((uint64_t)1 << 32)
#define PBIST_MINFO_DX_DC_1              ((uint64_t)1 << 33)
#define PBIST_MINFO_ENET_DC_0            ((uint64_t)1 << 34)
#define PBIST_MINFO_GX_DC_1              ((uint64_t)1 << 35)
#define PBIST_MINFO_GX_DC_3              ((uint64_t)1 << 35)
#define PBIST_MINFO_GX_DC_2              ((uint64_t)1 << 36)
#define PBIST_MINFO_GX_DC_0              ((uint64_t)1 << 36)
#define PBIST_MINFO_LX_DC_1              ((uint64_t)1 << 37)
#define PBIST_MINFO_LX_DC_0              ((uint64_t)1 << 37)
#define PBIST_MINFO_LX_DC_3              ((uint64_t)1 << 38)
#define PBIST_MINFO_LX_DC_2              ((uint64_t)1 << 38)
#define PBIST_MINFO_MX_DC_1              ((uint64_t)1 << 39)
#define PBIST_MINFO_MX_DC_0              ((uint64_t)1 << 40)
#define PBIST_MINFO_MCAN_DC_0            ((uint64_t)1 << 41)
#define PBIST_MINFO_CLAM_DC_0            ((uint64_t)1 << 42)
#define PBIST_MINFO_CLAD_DC_1            ((uint64_t)1 << 42)
#define PBIST_MINFO_PIE_DC_0             ((uint64_t)1 << 42)
#define PBIST_MINFO_STOCK_DC_0           ((uint64_t)1 << 42)
#define PBIST_MINFO_FRAME_DC_0           ((uint64_t)1 << 42)
#define PBIST_MINFO_FRAME_DC_1           ((uint64_t)1 << 42)
#define PBIST_MINFO_CMMSG_DC_0           ((uint64_t)1 << 42)
#define PBIST_MINFO_CPUMSG_DC_0          ((uint64_t)1 << 42)
#define PBIST_MINFO_CLAM_DC_1            ((uint64_t)1 << 43)
#define PBIST_MINFO_CLAD_DC_0            ((uint64_t)1 << 43)
#define PBIST_MINFO_PIE_DC_1             ((uint64_t)1 << 43)
#define PBIST_MINFO_CMMSG_DC_1           ((uint64_t)1 << 43)
#define PBIST_MINFO_SX_DC_1              ((uint64_t)1 << 44)
#define PBIST_MINFO_SX_DC_2              ((uint64_t)1 << 44)
#define PBIST_MINFO_SX_DC_0              ((uint64_t)1 << 44)
#define PBIST_MINFO_USB              ((uint64_t)1 << 45)
#define PBIST_MINFO_MCAN2            ((uint64_t)1 << 46)

#define SYSCTL_DC0_C28_2          0x1U
#define SYSCTL_DC0_CM4            0x2U
#define SYSCTL_DC11_MCAN          0x10U
#define SYSCTL_DC12_USB           0x30000U
#define SYSCTL_DC12_NOUSB_FUNC    0x0U
#define SYSCTL_DC26_ECAT          0x1U
#define SYSCTL_DC26_ENET          0x2U

//*****************************************************************************
//
// Defines for returning 32 bit values
//
//*****************************************************************************
#define PBIST_ALWAYSFAIL_TIMEOUT_ERROR       0xFF00FF00U
#define PBIST_ALWAYSFAIL_INCORRECT_OPERATION 0xFF11FF00U
#define PBIST_DOUBLEINT_TIMEOUT_ERROR        0xFF22FF00U
#define PBIST_MEMORYTEST_TIMEOUT_ERROR       0xFF33FF00U
#define PBIST_MEMORY_TEST_FAIL_ERROR         0xFF44FF00U
#define PBIST_MEMORY_RAM210_FAIL_ERROR       0xFF55FF00U
#define PBIST_MEMORY_ROM150_FAIL_ERROR       0xFF66FF00U
#define PBIST_MEMORY_CLA_DATA_FAIL_ERROR     0xFF77FF00U
#define PBIST_MEMORY_TMU_S1I_FAIL_ERROR      0xFF88FF00U
#define PBIST_MEMORY_TMU_S2I_FAIL_ERROR      0xFF99FF00U
#define PBIST_MEMORY_TMU_Y0_FAIL_ERROR       0xFFAAFF00U
#define PBIST_MEMORY_TEST_PASS               0xFFFFFFFFU

//

// SECURE ROM ROM Algo group
#define PBIST_ALGO_C281_SECURE_ROM (PBIST_ALGO_TRIPLE_READ_SECURE_ROMO0 | \
                                    PBIST_ALGO_TRIPLE_READ_SECURE_ROMO1 )

#define PBIST_ALGO_C282_SECURE_ROM (PBIST_ALGO_TRIPLE_READ_SECURE_ROMI0 | \
                                    PBIST_ALGO_TRIPLE_READ_SECURE_ROMI1 )
// BOOT ROM ROM Algo group --> Not testing C281 Bootrom to avoid clock issues
/*
#define PBIST_ALGO_C281BOOT_ROM   ( PBIST_ALGO_TRIPLE_READ_BOOT_ROMO1 | \
                                    PBIST_ALGO_TRIPLE_READ_BOOT_ROMO2 | \
                                    PBIST_ALGO_TRIPLE_READ_BOOT_ROMO3 | \
                                    PBIST_ALGO_TRIPLE_READ_BOOT_ROMO4 )
*/
#define PBIST_ALGO_C281BOOT_ROM   0x0U

#define PBIST_ALGO_C282BOOT_ROM   ( PBIST_ALGO_TRIPLE_READ_BOOT_ROMI1 | \
                                    PBIST_ALGO_TRIPLE_READ_BOOT_ROMI2 | \
                                    PBIST_ALGO_TRIPLE_READ_BOOT_ROMI3 | \
                                    PBIST_ALGO_TRIPLE_READ_BOOT_ROMI4 | \
                                    PBIST_ALGO_TRIPLE_READ_BOOT_ROMI5 | \
                                    PBIST_ALGO_TRIPLE_READ_BOOT_ROMI6 )

#define PBIST_MINFO_CLA_DATA_ROM   ( PBIST_MINFO_TRIPLE_READ_CPU1_CLA_DATA_ROM | \
                                     PBIST_MINFO_TRIPLE_READ_CPU2_CLA_DATA_ROM )

#define PBIST_MINFO_TMU_S1I_ROM   ( PBIST_MINFO_TRIPLE_READ_CPU1_TMU_S1I_ROM | \
                                    PBIST_MINFO_TRIPLE_READ_CPU2_TMU_S1I_ROM )

#define PBIST_MINFO_TMU_S2I_ROM   ( PBIST_MINFO_TRIPLE_READ_CPU1_TMU_S2I_ROM | \
                                    PBIST_MINFO_TRIPLE_READ_CPU2_TMU_S2I_ROM )

#define PBIST_MINFO_TMU_Y0_ROM   ( PBIST_MINFO_TRIPLE_READ_CPU1_TMU_Y0_ROM | \
                                   PBIST_MINFO_TRIPLE_READ_CPU2_TMU_Y0_ROM )

#define PBIST_MINFO_ALL_RAM     (   PBIST_MINFO_ECAT_DC_0   |\
                    PBIST_MINFO_CX_DC_0     |\
                    PBIST_MINFO_DX_DC_0     |\
                    PBIST_MINFO_DX_DC_1     |\
                    PBIST_MINFO_ENET_DC_0   |\
                    PBIST_MINFO_GX_DC_1     |\
                    PBIST_MINFO_GX_DC_3     |\
                    PBIST_MINFO_GX_DC_2     |\
                    PBIST_MINFO_GX_DC_0     |\
                    PBIST_MINFO_LX_DC_1     |\
                    PBIST_MINFO_LX_DC_0     |\
                    PBIST_MINFO_LX_DC_3     |\
                    PBIST_MINFO_LX_DC_2     |\
                    PBIST_MINFO_MX_DC_0     |\
                    PBIST_MINFO_MX_DC_1     |\
                    PBIST_MINFO_MCAN_DC_0   |\
                    PBIST_MINFO_CLAM_DC_0   |\
                    PBIST_MINFO_CLAD_DC_1   |\
                    PBIST_MINFO_PIE_DC_0    |\
                    PBIST_MINFO_STOCK_DC_0  |\
                    PBIST_MINFO_FRAME_DC_0  |\
                    PBIST_MINFO_FRAME_DC_1  |\
                    PBIST_MINFO_CMMSG_DC_0  |\
                    PBIST_MINFO_CPUMSG_DC_0 |\
                    PBIST_MINFO_CLAM_DC_1   |\
                    PBIST_MINFO_CLAD_DC_0   |\
                    PBIST_MINFO_PIE_DC_1    |\
                    PBIST_MINFO_CMMSG_DC_1  |\
                    PBIST_MINFO_SX_DC_1     |\
                    PBIST_MINFO_SX_DC_2     |\
                    PBIST_MINFO_SX_DC_0     |\
                    PBIST_MINFO_USB         |\
                    PBIST_MINFO_MCAN2      )

#define PBIST_ALGO_CLA_DATA_ROM     (PBIST_ALGO_TRIPLE_READ_CLA_DATA_ROM)

#define PBIST_ALGO_TMU_S1I_ROM      PBIST_ALGO_TRIPLE_READ_TMU_S1I_ROM
#define PBIST_ALGO_TMU_S2I_ROM      PBIST_ALGO_TRIPLE_READ_TMU_S2I_ROM
#define PBIST_ALGO_TMU_Y0_ROM       PBIST_ALGO_TRIPLE_READ_TMU_Y0_ROM

#define PBIST_ALGO_CMBOOT_ROM     ( PBIST_ALGO_TRIPLE_READ_CMBOOT_ROM1 | \
                                    PBIST_ALGO_TRIPLE_READ_CMBOOT_ROM2 )

#define PBIST_ALGO_HWBIST_ROM     ( PBIST_ALGO_TRIPLE_READ_HWBIST_ROM0 | \
                                    PBIST_ALGO_TRIPLE_READ_HWBIST_ROM1 | \
                                    PBIST_ALGO_TRIPLE_READ_HWBIST_ROM2 | \
                                    PBIST_ALGO_TRIPLE_READ_HWBIST_ROM3)

#define PBIST_ALGO_ALL_RAM        ( PBIST_ALGO_MARCH13N_SINGLE_PORT )

#define PBIST_ALGO_210_RAM         ( PBIST_ALGO_ALL_RAM )

#define PBIST_ALGO_210_RAM_ROM     ( PBIST_ALGO_210_RAM |\
                     PBIST_ALGO_210_ROM )

#define PBIST_ALGO_ALL_MEM       ( PBIST_ALGO_210_RAM_ROM |\
                     PBIST_ALGO_150_ROM )

//ALL 210 ROMs except CLA/TMU. They are tested separately
#define PBIST_ALGO_210_ROM    (     PBIST_ALGO_TRIPLE_READ_PBIST_ROM |\
                    PBIST_ALGO_CLA_DATA_ROM |\
                    PBIST_ALGO_TMU_S1I_ROM |\
                    PBIST_ALGO_TMU_S2I_ROM |\
                    PBIST_ALGO_TMU_Y0_ROM |\
                    PBIST_ALGO_CMBOOT_ROM )

#define PBIST_ALGO_150_ROM    (     PBIST_ALGO_C281_SECURE_ROM |\
                                    PBIST_ALGO_C282_SECURE_ROM |\
                    PBIST_ALGO_C281BOOT_ROM |\
                    PBIST_ALGO_C282BOOT_ROM |\
                    PBIST_ALGO_HWBIST_ROM )
//
// Definitions related to always-fail portion --> Executing MARCH13n on ROM
#define PBIST_RINFOL_ROM_MEM_GROUP            PBIST_MINFO_TRIPLE_READ_CPU1_TMU_S1I_ROM
#define PBIST_ALGO_TMU_ROM_FAIL_ALGO          PBIST_ALGO_MARCH13N_SINGLE_PORT //ALGO GROUP --> March13n

//
// End of file
//
