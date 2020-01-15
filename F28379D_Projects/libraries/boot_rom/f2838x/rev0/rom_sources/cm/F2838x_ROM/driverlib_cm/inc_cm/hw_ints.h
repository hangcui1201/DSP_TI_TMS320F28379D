//###########################################################################
//
// FILE:   hw_ints.h
//
// TITLE:  Macros that define the interrupt assignment.
//
//###########################################################################
// $TI Release:  $
// $Release Date:  $
// $Copyright:  $
//###########################################################################

#ifndef HW_INTS_H
#define HW_INTS_H

//*****************************************************************************
// The following are defines for the fault assignments.
//*****************************************************************************
#define FAULT_NMI                      2U   // NMI fault
#define FAULT_HARD                     3U   // Hard fault
#define FAULT_MPU                      4U   // MPU fault
#define FAULT_BUS                      5U   // Bus fault
#define FAULT_USAGE                    6U   // Usage fault
#define FAULT_SVCALL                   11U  // SVCall
#define FAULT_DEBUG                    12U  // Debug monitor
#define FAULT_PENDSV                   14U  // PendSV
#define FAULT_SYSTICK                  15U  // System Tick

//*****************************************************************************
// The following are defines for the interrupt assignments.
//*****************************************************************************
#define INT_MCANSS_0                   16U  // MCANSS_INT[0]
#define INT_MCANSS_1                   17U  // MCANSS_INT[1]
#define INT_MCANSS_WAKE_AND_TS_PLS     18U  // MCANSS_WAKE_AND_TS_PLS_INT
#define INT_MCANSS_ECC_CORR_LVL        19U  // MCANSS_ECC_CORR_LVL_INT
#define INT_ECAT                       21U  // ECATINT
#define INT_ECAT_SYNC0                 22U  // ECATSYNC0INT
#define INT_ECAT_SYNC1                 23U  // ECATSYNC1INT
#define INT_ECAT_RST                   24U  // ECATRSTINT
#define INT_CANA0                      25U  // DCANA Interrupt 0
#define INT_CANA1                      26U  // DCANA Interrupt 1
#define INT_CANB0                      27U  // DCANB Interrupt 0
#define INT_CANB1                      28U  // DCANB Interrupt 1
#define INT_EMAC                       29U  // EMAC_INT
#define INT_EMAC_TX0                   30U  // EMAC_TX_INT[0]
#define INT_EMAC_TX1                   31U  // EMAC_TX_INT[1]
#define INT_EMAC_RX0                   32U  // EMAC_RX_INT[0]
#define INT_EMAC_RX1                   33U  // EMAC_RX_INT[1]
#define INT_UART0                      34U  // UART0INT
#define INT_SSI0                       36U  // SSI0INT
#define INT_I2C0                       38U  // I2C0INT
#define INT_USB                        40U  // USBINT
#define INT_UDMA_SW                    41U  // UDMASWINT
#define INT_UDMA_ERR                   42U  // UDMAERRINT
#define INT_IPC_CPU1TOCM_0             45U  // CPU1TOCMIPCINT0
#define INT_IPC_CPU1TOCM_1             46U  // CPU1TOCMIPCINT1
#define INT_IPC_CPU1TOCM_2             47U  // CPU1TOCMIPCINT2
#define INT_IPC_CPU1TOCM_3             48U  // CPU1TOCMIPCINT3
#define INT_IPC_CPU1TOCM_4             49U  // CPU1TOCMIPCINT4
#define INT_IPC_CPU1TOCM_5             50U  // CPU1TOCMIPCINT5
#define INT_IPC_CPU1TOCM_6             51U  // CPU1TOCMIPCINT6
#define INT_IPC_CPU1TOCM_7             52U  // CPU1TOCMIPCINT7
#define INT_IPC_CPU2TOCM_0             53U  // CPU2TOCMIPCINT0
#define INT_IPC_CPU2TOCM_1             54U  // CPU2TOCMIPCINT1
#define INT_IPC_CPU2TOCM_2             55U  // CPU2TOCMIPCINT2
#define INT_IPC_CPU2TOCM_3             56U  // CPU2TOCMIPCINT3
#define INT_IPC_CPU2TOCM_4             57U  // CPU2TOCMIPCINT4
#define INT_IPC_CPU2TOCM_5             58U  // CPU2TOCMIPCINT5
#define INT_IPC_CPU2TOCM_6             59U  // CPU2TOCMIPCINT6
#define INT_IPC_CPU2TOCM_7             60U  // CPU2TOCMIPCINT7
#define INT_FMC_FSMDONE                61U  // FMC_FSMDONE_INT
#define INT_FMC_CORR                   62U  // FMC_CORR_INT
#define INT_AES                        63U  // AESINT
#define INT_TIMER0                     64U  // TINT0
#define INT_TIMER1                     65U  // TINT1
#define INT_TIMER2                     66U  // TINT2
#define INT_CMRAM_TESTERROR_LOG        67U  // CM_RAM_TESTERROR_LOG

//*****************************************************************************
// The following are defines for the total number of interrupts.
//*****************************************************************************
#define NUM_INTERRUPTS                 80U

//*****************************************************************************
// The following are defines for the total number of priority levels.
//*****************************************************************************
#define NUM_PRIORITY                   8U
#define NUM_PRIORITY_BITS              3U


#endif // HW_INTS_H


