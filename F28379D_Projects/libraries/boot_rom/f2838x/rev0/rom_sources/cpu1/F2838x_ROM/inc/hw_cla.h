//###########################################################################
//
// FILE:    hw_cla.h
//
// TITLE:   Definitions for the CLA registers.
//
//###########################################################################
// $TI Release:  $
// $Release Date:  $
// $Copyright:  $
//###########################################################################

#ifndef HW_CLA_H
#define HW_CLA_H

//*****************************************************************************
//
// The following are defines for the CLA register offsets
//
//*****************************************************************************
#define CLA_O_MHWADBGCAP          0x0U         // CLA Hardware Accelerator
                                               // Debug Capabilities Register
#define CLA_O_MHWADBGCTL          0x2U         // CLA Hardware Accelerator
                                               // Debug Control Register
#define CLA_O_DBG_INDRCT_CAP      0xAU         // CLA Hardware Accelerator
                                               // Indirect access capabilities
                                               // register
#define CLA_O_DBG_INDRCT_CTRL     0xCU         // CLA Hardware Accelerator
                                               // Indirect access control register
#define CLA_O_DBG_INDRCT_ADDR     0xEU         // CLA Hardware Accelerator
                                               // Indirect access address register
#define CLA_O_DBG_INDRCT_DATA     0x12U        // CLA Hardware Accelerator
                                               // Indirect access data register
#define CLA_O_DBG_HWBP_0_CNTL     0x20U        // CLA hardware breakpoint 0
                                               // control register
#define CLA_O_DBG_HWBP_0_ADDR     0x22U        // CLA hardware breakpoint 0
                                               // address register
#define CLA_O_DBG_HWBP_0_AMASK    0x26U        // CLA hardware breakpoint 0
                                               // address mask register
#define CLA_O_DBG_HWBP_1_CNTL     0x40U        // CLA hardware breakpoint 1
                                               // control register
#define CLA_O_DBG_HWBP_1_ADDR     0x42U        // CLA hardware breakpoint 1
                                               // address register
#define CLA_O_DBG_HWBP_1_AMASK    0x46U        // CLA hardware breakpoint 1
                                               // address mask register
#define CLA_O_MVECT1              0x0U         // Task Interrupt Vector
#define CLA_O_MVECT2              0x1U         // Task Interrupt Vector
#define CLA_O_MVECT3              0x2U         // Task Interrupt Vector
#define CLA_O_MVECT4              0x3U         // Task Interrupt Vector
#define CLA_O_MVECT5              0x4U         // Task Interrupt Vector
#define CLA_O_MVECT6              0x5U         // Task Interrupt Vector
#define CLA_O_MVECT7              0x6U         // Task Interrupt Vector
#define CLA_O_MVECT8              0x7U         // Task Interrupt Vector
#define CLA_O_MCTL                0x10U        // Control Register
#define CLA_O_MMEMCFG             0x11U        // Memory Configuration Register
#define CLA_O_MPISRCSEL1          0x14U        // Peripheral Interrupt Source
                                               // Select 1 Register
#define CLA_O_MPISRCSEL2          0x16U        // Peripheral Interrupt Source
                                               // Select 2 Register
#define CLA_O_MVECTBGRNDACTIVE    0x1BU        // Active register for
                                               // MVECTBGRND.
#define CLA_O_SOFTINTEN           0x1CU        // CLA Software Interrupt Enable
                                               // Register
#define CLA_O_MSTSBGRND           0x1DU        // Status register for the back
                                               // ground task.
#define CLA_O_MCTLBGRND           0x1EU        // Control register for the back
                                               // ground task.
#define CLA_O_MVECTBGRND          0x1FU        // Vector for the back ground
                                               // task.
#define CLA_O_MIFR                0x20U        // Interrupt Flag Register
#define CLA_O_MIOVF               0x21U        // Interrupt Overflow Flag
                                               // Register
#define CLA_O_MIFRC               0x22U        // Interrupt Force Register
#define CLA_O_MICLR               0x23U        // Interrupt Flag Clear Register
#define CLA_O_MICLROVF            0x24U        // Interrupt Overflow Flag Clear
                                               // Register
#define CLA_O_MIER                0x25U        // Interrupt Enable Register
#define CLA_O_MIRUN               0x26U        // Interrupt Run Status Register
#define CLA_O_MPC                 0x28U        // CLA Program Counter
#define CLA_O_MAR0                0x2AU        // CLA Auxiliary Register 0
#define CLA_O_MAR1                0x2BU        // CLA Auxiliary Register 1
#define CLA_O_MSTF                0x2EU        // CLA Floating-Point Status
                                               // Register
#define CLA_O_MR0                 0x30U        // CLA Floating-Point Result
                                               // Register 0
#define CLA_O_MR1                 0x34U        // CLA Floating-Point Result
                                               // Register 1
#define CLA_O_MR2                 0x38U        // CLA Floating-Point Result
                                               // Register 2
#define CLA_O_MR3                 0x3CU        // CLA Floating-Point Result
                                               // Register 3
#define CLA_O_MDEBUGCTL           0x40U        // CLA Debug Control Register
#define CLA_O_MDEBUGSS            0x41U        // CLA Debug Step Register
#define CLA_O_MPSACTL             0x42U        // CLA PSA Control Register
#define CLA_O_MPSA1               0x44U        // CLA PSA1 Register
#define CLA_O_MPSA2               0x46U        // CLA PSA2 Register
#define CLA_O_SOFTINTFRC          0xE2U        // CLA Software Interrupt Force
                                               // Register

//*****************************************************************************
//
// The following are defines for the bit fields in the _MHWADBGCAP register
//
//*****************************************************************************
#define CLA_MHWADBGCAP_REV_MIN_S  0U
#define CLA_MHWADBGCAP_REV_MIN_M  0xFU         // Minor Revision
#define CLA_MHWADBGCAP_REV_MAJ_S  4U
#define CLA_MHWADBGCAP_REV_MAJ_M  0xF0U        // Major Revision
#define CLA_MHWADBGCAP_NUM_BPS_S  8U
#define CLA_MHWADBGCAP_NUM_BPS_M  0xF00U       // The number of HWBP modules
                                               // implemented
#define CLA_MHWADBGCAP_NUM_WPS_S  12U
#define CLA_MHWADBGCAP_NUM_WPS_M  0xF000U      // The number of HWWP modules
                                               // implemented
#define CLA_MHWADBGCAP_NUM_CTRS_S  16U
#define CLA_MHWADBGCAP_NUM_CTRS_M  0xF0000U     // The number of counters
                                               // implemented
#define CLA_MHWADBGCAP_TRIG_CHNS_S  20U
#define CLA_MHWADBGCAP_TRIG_CHNS_M  0x300000U    // Number of trigger channels
                                               // supported
#define CLA_MHWADBGCAP_TRIG_INPUT  0x400000U    // Trigger input support
#define CLA_MHWADBGCAP_TRIG_OUTPUT  0x800000U    // Trigger output support
#define CLA_MHWADBGCAP_SYS_EXE_REQ  0x1000000U   // Whether HWA Core Execution
                                               // status and control is supported
#define CLA_MHWADBGCAP_DBG_RESET_SUP  0x2000000U   // HWA Core reset is supported.
#define CLA_MHWADBGCAP_DBG_SWBP_SUP  0x4000000U   // SWBP is supported by the HWA
                                               // instruction set.
#define CLA_MHWADBGCAP_DBG_INDIRECT_SUP  0x8000000U   // Supports an indirect access
                                               // port.
#define CLA_MHWADBGCAP_DBG_INT_STEP_SUP  0x40000000U  // Supports interrupt blocking
                                               // in debug mode

//*****************************************************************************
//
// The following are defines for the bit fields in the _MHWADBGCTL register
//
//*****************************************************************************
#define CLA_MHWADBGCTL_DBG_HALT   0x1U         // Debug Halt Bit
#define CLA_MHWADBGCTL_DBG_RESTART  0x2U         // Debug Restart Status
#define CLA_MHWADBGCTL_DBG_SINGLESTEP_EN  0x4U         // Singlestep enable
#define CLA_MHWADBGCTL_DBG_SWBP_EN  0x8U         // Software Breakpoint Enable
#define CLA_MHWADBGCTL_DBG_WPBP_EN  0x10U        // Watchpoint/Breakpoint Enable
#define CLA_MHWADBGCTL_DBG_EXE_STAT  0x80U        // Debug Execution Status
#define CLA_MHWADBGCTL_DBG_HALT_SWBP  0x100U       // Halted due to a software
                                               // breakpoint
#define CLA_MHWADBGCTL_DBG_HALT_BPWP  0x200U       // Halted due to a hardware
                                               // breakpoint
#define CLA_MHWADBGCTL_DBG_HALT_STEP  0x400U       // Execution halted due to a
                                               // step command
#define CLA_MHWADBGCTL_DBG_HALT_USER  0x800U       // Execution halted due to a
                                               // software breakpoint
#define CLA_MHWADBGCTL_DBG_RESET_REQ  0x2000000U   // CLA softreset
#define CLA_MHWADBGCTL_DBG_RESET_OCC  0x4000000U   // CLA softreset status bit
#define CLA_MHWADBGCTL_DBG_INT_STEP_IN  0x10000000U  // Enable stepping into pending
                                               // interrupts

//*****************************************************************************
//
// The following are defines for the bit fields in the _DBG_INDRCT_CAP register
//
//*****************************************************************************
#define CLA_DBG_INDRCT_CAP_PAGE0_ADDR_SIZE_S  0U
#define CLA_DBG_INDRCT_CAP_PAGE0_ADDR_SIZE_M  0x3U         // Address bus size for page 0
#define CLA_DBG_INDRCT_CAP_PAGE0_DATA_SIZE_S  2U
#define CLA_DBG_INDRCT_CAP_PAGE0_DATA_SIZE_M  0xCU         // Address bus size for page 0
#define CLA_DBG_INDRCT_CAP_PAGE1_ADDR_SIZE_S  4U
#define CLA_DBG_INDRCT_CAP_PAGE1_ADDR_SIZE_M  0x30U        // Address bus size for page 0
#define CLA_DBG_INDRCT_CAP_PAGE1_DATA_SIZE_S  6U
#define CLA_DBG_INDRCT_CAP_PAGE1_DATA_SIZE_M  0xC0U        // Address bus size for page 0

//*****************************************************************************
//
// The following are defines for the bit fields in the _DBG_INDRCT_CTRL register
//
//*****************************************************************************
#define CLA_DBG_INDRCT_CTRL_MEM_RW  0x1U         // R/W Control for next accesses
#define CLA_DBG_INDRCT_CTRL_MEM_ADDR_INC  0x2U         // Auto increment address on
                                               // each access
#define CLA_DBG_INDRCT_CTRL_MEM_PRIORITY  0x4U         // Determines if debug access
                                               // will be forced or wait
#define CLA_DBG_INDRCT_CTRL_MEM_PAGE_S  4U
#define CLA_DBG_INDRCT_CTRL_MEM_PAGE_M  0xF0U        // Page designator for the next
                                               // access
#define CLA_DBG_INDRCT_CTRL_MEM_ACC_SIZE_S  8U
#define CLA_DBG_INDRCT_CTRL_MEM_ACC_SIZE_M  0x700U       // Access size (in bytes) of the
                                               // transaction
#define CLA_DBG_INDRCT_CTRL_MEM_PORT_STAT_S  16U
#define CLA_DBG_INDRCT_CTRL_MEM_PORT_STAT_M  0x30000U     // Memory Port Status
#define CLA_DBG_INDRCT_CTRL_MEM_ERR_OVERRUN  0x40000U     // Indicates the state of the
                                               // access port
#define CLA_DBG_INDRCT_CTRL_MEM_BUS_STAT  0x80000U     // Memory Bus Status
#define CLA_DBG_INDRCT_CTRL_MEM_ERR_CODE_S  20U
#define CLA_DBG_INDRCT_CTRL_MEM_ERR_CODE_M  0xF00000U    // Indicates the bus error code
                                               // returned for a transaction
#define CLA_DBG_INDRCT_CTRL_MEM_RESET_PORT  0x40000000U  // Resets the port to the
                                               // initial state

//*****************************************************************************
//
// The following are defines for the bit fields in the _DBG_INDRCT_ADDR register
//
//*****************************************************************************
#define CLA_DBG_INDRCT_ADDR_ADDR_S  0U
#define CLA_DBG_INDRCT_ADDR_ADDR_M  0xFFFFU      // Address for indirect access

//*****************************************************************************
//
// The following are defines for the bit fields in the _DBG_HWBP_0_CNTL register
//
//*****************************************************************************
#define CLA_DBG_HWBP_0_CNTL_ENABLE  0x1U         // Debug Halt Bit
#define CLA_DBG_HWBP_0_CNTL_HALT  0x2U         // Halted due to
#define CLA_DBG_HWBP_0_CNTL_TRIGGERED  0x4U         // HWBP0 triggerred.

//*****************************************************************************
//
// The following are defines for the bit fields in the _DBG_HWBP_0_ADDR register
//
//*****************************************************************************
#define CLA_DBG_HWBP_0_ADDR_ADDR_S  0U
#define CLA_DBG_HWBP_0_ADDR_ADDR_M  0xFFFFU      // Breakpoint 0 address
                                               // register.

//*****************************************************************************
//
// The following are defines for the bit fields in the _DBG_HWBP_0_AMASK register
//
//*****************************************************************************
#define CLA_DBG_HWBP_0_AMASK_AMASK_S  0U
#define CLA_DBG_HWBP_0_AMASK_AMASK_M  0xFFFFU      // Breakpoint 0 address mask
                                               // register.

//*****************************************************************************
//
// The following are defines for the bit fields in the _DBG_HWBP_1_CNTL register
//
//*****************************************************************************
#define CLA_DBG_HWBP_1_CNTL_ENABLE  0x1U         // Debug Halt Bit
#define CLA_DBG_HWBP_1_CNTL_HALT  0x2U         // Halted due to
#define CLA_DBG_HWBP_1_CNTL_TRIGGERED  0x4U         // HWBP0 triggerred.

//*****************************************************************************
//
// The following are defines for the bit fields in the _DBG_HWBP_1_ADDR register
//
//*****************************************************************************
#define CLA_DBG_HWBP_1_ADDR_ADDR_S  0U
#define CLA_DBG_HWBP_1_ADDR_ADDR_M  0xFFFFU      // Breakpoint 1 address
                                               // register.

//*****************************************************************************
//
// The following are defines for the bit fields in the _DBG_HWBP_1_AMASK register
//
//*****************************************************************************
#define CLA_DBG_HWBP_1_AMASK_AMASK_S  0U
#define CLA_DBG_HWBP_1_AMASK_AMASK_M  0xFFFFU      // Breakpoint 1 address mask
                                               // register.

//*****************************************************************************
//
// The following are defines for the bit fields in the MCTL register
//
//*****************************************************************************
#define CLA_MCTL_HARDRESET        0x1U         // Hard Reset
#define CLA_MCTL_SOFTRESET        0x2U         // Soft Reset
#define CLA_MCTL_IACKE            0x4U         // IACK enable

//*****************************************************************************
//
// The following are defines for the bit fields in the MMEMCFG register
//
//*****************************************************************************
#define CLA_MMEMCFG_PROGE         0x1U         // CLA Program Space Enable
#define CLA_MMEMCFG_RAMNE_S       4U
#define CLA_MMEMCFG_RAMNE_M       0x70U        // CLA Data RAM Enable Bits
#define CLA_MMEMCFG_RAMNCPUE_S    8U
#define CLA_MMEMCFG_RAMNCPUE_M    0x700U       // CLA Data RAM CPU Access
                                               // Enable Bits

//*****************************************************************************
//
// The following are defines for the bit fields in the MPISRCSEL1 register
//
//*****************************************************************************
#define CLA_MPISRCSEL1_PERINT1SEL_S  0U
#define CLA_MPISRCSEL1_PERINT1SEL_M  0xFU         // Task 1 Peripheral Interrupt
                                               // Input Select
#define CLA_MPISRCSEL1_PERINT2SEL_S  4U
#define CLA_MPISRCSEL1_PERINT2SEL_M  0xF0U        // Task 2 Peripheral Interrupt
                                               // Input Select
#define CLA_MPISRCSEL1_PERINT3SEL_S  8U
#define CLA_MPISRCSEL1_PERINT3SEL_M  0xF00U       // Task 3 Peripheral Interrupt
                                               // Input Select
#define CLA_MPISRCSEL1_PERINT4SEL_S  12U
#define CLA_MPISRCSEL1_PERINT4SEL_M  0xF000U      // Task 4 Peripheral Interrupt
                                               // Input Select
#define CLA_MPISRCSEL1_PERINT5SEL_S  16U
#define CLA_MPISRCSEL1_PERINT5SEL_M  0xF0000U     // Task 5 Peripheral Interrupt
                                               // Input Select
#define CLA_MPISRCSEL1_PERINT64SEL_S  20U
#define CLA_MPISRCSEL1_PERINT64SEL_M  0xF00000U    // Task 6 Peripheral Interrupt
                                               // Input Select
#define CLA_MPISRCSEL1_PERINT7SEL_S  24U
#define CLA_MPISRCSEL1_PERINT7SEL_M  0xF000000U   // Task 7 Peripheral Interrupt
                                               // Input Select
#define CLA_MPISRCSEL1_PERINT8SEL_S  28U
#define CLA_MPISRCSEL1_PERINT8SEL_M  0xF0000000U  // Task n Peripheral Interrupt
                                               // Input Select

//*****************************************************************************
//
// The following are defines for the bit fields in the MPISRCSEL2 register
//
//*****************************************************************************
#define CLA_MPISRCSEL2_PERINT9SEL_S  0U
#define CLA_MPISRCSEL2_PERINT9SEL_M  0xFU         // Task 9 Peripheral Interrupt
                                               // Input Select
#define CLA_MPISRCSEL2_PERINT10SEL_S  4U
#define CLA_MPISRCSEL2_PERINT10SEL_M  0xF0U        // Task 10 Peripheral Interrupt
                                               // Input Select
#define CLA_MPISRCSEL2_PERINT11SEL_S  8U
#define CLA_MPISRCSEL2_PERINT11SEL_M  0xF00U       // Task 11 Peripheral Interrupt
                                               // Input Select
#define CLA_MPISRCSEL2_PERINT12SEL_S  12U
#define CLA_MPISRCSEL2_PERINT12SEL_M  0xF000U      // Task 12 Peripheral Interrupt
                                               // Input Select
#define CLA_MPISRCSEL2_PERINT13SEL_S  16U
#define CLA_MPISRCSEL2_PERINT13SEL_M  0xF0000U     // Task 13 Peripheral Interrupt
                                               // Input Select
#define CLA_MPISRCSEL2_PERINT14SEL_S  20U
#define CLA_MPISRCSEL2_PERINT14SEL_M  0xF00000U    // Task 14 Peripheral Interrupt
                                               // Input Select
#define CLA_MPISRCSEL2_PERINT15SEL_S  24U
#define CLA_MPISRCSEL2_PERINT15SEL_M  0xF000000U   // Task 15 Peripheral Interrupt
                                               // Input Select
#define CLA_MPISRCSEL2_PERINT16SEL_S  28U
#define CLA_MPISRCSEL2_PERINT16SEL_M  0xF0000000U  // Task 16 Peripheral Interrupt
                                               // Input Select

//*****************************************************************************
//
// The following are defines for the bit fields in the SOFTINTEN register
//
//*****************************************************************************
#define CLA_SOFTINTEN_TASK1       0x1U         // Configure Software Interrupt
                                               // or End of Task interrupt.
#define CLA_SOFTINTEN_TASK2       0x2U         // Configure Software Interrupt
                                               // or End of Task interrupt.
#define CLA_SOFTINTEN_TASK3       0x4U         // Configure Software Interrupt
                                               // or End of Task interrupt.
#define CLA_SOFTINTEN_TASK4       0x8U         // Configure Software Interrupt
                                               // or End of Task interrupt.
#define CLA_SOFTINTEN_TASK5       0x10U        // Configure Software Interrupt
                                               // or End of Task interrupt.
#define CLA_SOFTINTEN_TASK6       0x20U        // Configure Software Interrupt
                                               // or End of Task interrupt.
#define CLA_SOFTINTEN_TASK7       0x40U        // Configure Software Interrupt
                                               // or End of Task interrupt.
#define CLA_SOFTINTEN_TASK8       0x80U        // Configure Software Interrupt
                                               // or End of Task interrupt.

//*****************************************************************************
//
// The following are defines for the bit fields in the _MSTSBGRND register
//
//*****************************************************************************
#define CLA_MSTSBGRND_RUN         0x1U         // Background task run status
                                               // bit.
#define CLA_MSTSBGRND_BGINTM      0x2U         // Indicates whether background
                                               // task can be interrupted.
#define CLA_MSTSBGRND_BGOVF       0x4U         // background task harware
                                               // trigger overflow.

//*****************************************************************************
//
// The following are defines for the bit fields in the _MCTLBGRND register
//
//*****************************************************************************
#define CLA_MCTLBGRND_BGSTART     0x1U         // Background task start bit
#define CLA_MCTLBGRND_TRIGEN      0x2U         // Background task hardware
                                               // trigger enable
#define CLA_MCTLBGRND_BGEN        0x8000U      // Enable background task

//*****************************************************************************
//
// The following are defines for the bit fields in the MIFR register
//
//*****************************************************************************
#define CLA_MIFR_INT1             0x1U         // Task 1 Interrupt Flag
#define CLA_MIFR_INT2             0x2U         // Task 2 Interrupt Flag
#define CLA_MIFR_INT3             0x4U         // Task 3 Interrupt Flag
#define CLA_MIFR_INT4             0x8U         // Task 4 Interrupt Flag
#define CLA_MIFR_INT5             0x10U        // Task 5 Interrupt Flag
#define CLA_MIFR_INT6             0x20U        // Task 6 Interrupt Flag
#define CLA_MIFR_INT7             0x40U        // Task 7 Interrupt Flag
#define CLA_MIFR_INT8             0x80U        // Task 8 Interrupt Flag

//*****************************************************************************
//
// The following are defines for the bit fields in the MIOVF register
//
//*****************************************************************************
#define CLA_MIOVF_INT1            0x1U         // Task 1 Interrupt Overflow
                                               // Flag
#define CLA_MIOVF_INT2            0x2U         // Task 2 Interrupt Overflow
                                               // Flag
#define CLA_MIOVF_INT3            0x4U         // Task 3 Interrupt Overflow
                                               // Flag
#define CLA_MIOVF_INT4            0x8U         // Task 4 Interrupt Overflow
                                               // Flag
#define CLA_MIOVF_INT5            0x10U        // Task 5 Interrupt Overflow
                                               // Flag
#define CLA_MIOVF_INT6            0x20U        // Task 6 Interrupt Overflow
                                               // Flag
#define CLA_MIOVF_INT7            0x40U        // Task 7 Interrupt Overflow
                                               // Flag
#define CLA_MIOVF_INT8            0x80U        // Task 8 Interrupt Overflow
                                               // Flag

//*****************************************************************************
//
// The following are defines for the bit fields in the MIFRC register
//
//*****************************************************************************
#define CLA_MIFRC_INT1            0x1U         // Task 1 Interrupt Force
#define CLA_MIFRC_INT2            0x2U         // Task 2 Interrupt Force
#define CLA_MIFRC_INT3            0x4U         // Task 3 Interrupt Force
#define CLA_MIFRC_INT4            0x8U         // Task 4 Interrupt Force
#define CLA_MIFRC_INT5            0x10U        // Task 5 Interrupt Force
#define CLA_MIFRC_INT6            0x20U        // Task 6 Interrupt Force
#define CLA_MIFRC_INT7            0x40U        // Task 7 Interrupt Force
#define CLA_MIFRC_INT8            0x80U        // Task 8 Interrupt Force

//*****************************************************************************
//
// The following are defines for the bit fields in the MICLR register
//
//*****************************************************************************
#define CLA_MICLR_INT1            0x1U         // Task 1 Interrupt Flag Clear
#define CLA_MICLR_INT2            0x2U         // Task 2 Interrupt Flag Clear
#define CLA_MICLR_INT3            0x4U         // Task 3 Interrupt Flag Clear
#define CLA_MICLR_INT4            0x8U         // Task 4 Interrupt Flag Clear
#define CLA_MICLR_INT5            0x10U        // Task 5 Interrupt Flag Clear
#define CLA_MICLR_INT6            0x20U        // Task 6 Interrupt Flag Clear
#define CLA_MICLR_INT7            0x40U        // Task 7 Interrupt Flag Clear
#define CLA_MICLR_INT8            0x80U        // Task 8 Interrupt Flag Clear

//*****************************************************************************
//
// The following are defines for the bit fields in the MICLROVF register
//
//*****************************************************************************
#define CLA_MICLROVF_INT1         0x1U         // Task 1 Interrupt Overflow
                                               // Flag Clear
#define CLA_MICLROVF_INT2         0x2U         // Task 2 Interrupt Overflow
                                               // Flag Clear
#define CLA_MICLROVF_INT3         0x4U         // Task 3 Interrupt Overflow
                                               // Flag Clear
#define CLA_MICLROVF_INT4         0x8U         // Task 4 Interrupt Overflow
                                               // Flag Clear
#define CLA_MICLROVF_INT5         0x10U        // Task 5 Interrupt Overflow
                                               // Flag Clear
#define CLA_MICLROVF_INT6         0x20U        // Task 6 Interrupt Overflow
                                               // Flag Clear
#define CLA_MICLROVF_INT7         0x40U        // Task 7 Interrupt Overflow
                                               // Flag Clear
#define CLA_MICLROVF_INT8         0x80U        // Task 8 Interrupt Overflow
                                               // Flag Clear

//*****************************************************************************
//
// The following are defines for the bit fields in the MIER register
//
//*****************************************************************************
#define CLA_MIER_INT1             0x1U         // Task 1 Interrupt Enable
#define CLA_MIER_INT2             0x2U         // Task 2 Interrupt Enable
#define CLA_MIER_INT3             0x4U         // Task 3 Interrupt Enable
#define CLA_MIER_INT4             0x8U         // Task 4 Interrupt Enable
#define CLA_MIER_INT5             0x10U        // Task 5 Interrupt Enable
#define CLA_MIER_INT6             0x20U        // Task 6 Interrupt Enable
#define CLA_MIER_INT7             0x40U        // Task 7 Interrupt Enable
#define CLA_MIER_INT8             0x80U        // Task 8 Interrupt Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the MIRUN register
//
//*****************************************************************************
#define CLA_MIRUN_INT1            0x1U         // Task 1 Run Status
#define CLA_MIRUN_INT2            0x2U         // Task 2 Run Status
#define CLA_MIRUN_INT3            0x4U         // Task 3 Run Status
#define CLA_MIRUN_INT4            0x8U         // Task 4 Run Status
#define CLA_MIRUN_INT5            0x10U        // Task 5 Run Status
#define CLA_MIRUN_INT6            0x20U        // Task 6 Run Status
#define CLA_MIRUN_INT7            0x40U        // Task 7 Run Status
#define CLA_MIRUN_INT8            0x80U        // Task 8 Run Status

//*****************************************************************************
//
// The following are defines for the bit fields in the _MSTF register
//
//*****************************************************************************
#define CLA_MSTF_LVF              0x1U         // Latched Overflow Flag
#define CLA_MSTF_LUF              0x2U         // Latched Underflow Flag
#define CLA_MSTF_NF               0x4U         // Negative Float Flag
#define CLA_MSTF_ZF               0x8U         // Zero Float Flag
#define CLA_MSTF_TF               0x40U        // Test Flag
#define CLA_MSTF_RNDF32           0x200U       // Round 32-bit Floating-Point
                                               // Mode
#define CLA_MSTF_MEALLOW          0x800U       // MEALLOW Status
#define CLA_MSTF_RPC_S            12U
#define CLA_MSTF_RPC_M            0xFFFF000U   // Return PC

//*****************************************************************************
//
// The following are defines for the bit fields in the _MDEBUGCTL register
//
//*****************************************************************************
#define CLA_MDEBUGCTL_ONESHOT     0x1U         // One Shot Mode Bit
#define CLA_MDEBUGCTL_SSE         0x2U         // Single Step Enable Bit
#define CLA_MDEBUGCTL_DEBUGSTOP   0x4U         // Debug stop bit

//*****************************************************************************
//
// The following are defines for the bit fields in the _MDEBUGSS register
//
//*****************************************************************************
#define CLA_MDEBUGSS_SS           0x1U         // Single Step Command Bit
#define CLA_MDEBUGSS_RUN          0x2U         // Run Bit

//*****************************************************************************
//
// The following are defines for the bit fields in the _MPSACTL register
//
//*****************************************************************************
#define CLA_MPSACTL_MPABSTART     0x1U         // Start logging PAB onto PSA1
#define CLA_MPSACTL_MPABCYC       0x2U         // PAB logging into PSA1 is on
                                               // every cycle or when PAB
                                               // changes.
#define CLA_MPSACTL_MDWDBSTART    0x4U         // Start logging DWDB onto PSA2
#define CLA_MPSACTL_MDWDBCYC      0x8U         // DWDB logging into PSA2 is on
                                               // every cycle.
#define CLA_MPSACTL_MPSA1CLEAR    0x10U        // PSA1 clear
#define CLA_MPSACTL_MPSA2CLEAR    0x20U        // PSA2 Clear
#define CLA_MPSACTL_MPSA2CFG_S    6U
#define CLA_MPSACTL_MPSA2CFG_M    0xC0U        // PSA2 Polynomial Configuration

//*****************************************************************************
//
// The following are defines for the bit fields in the SOFTINTFRC register
//
//*****************************************************************************
#define CLA_SOFTINTFRC_TASK1      0x1U         // Force CLA software interrupt
                                               // for the corresponding task.
#define CLA_SOFTINTFRC_TASK2      0x2U         // Force CLA software interrupt
                                               // for the corresponding task.
#define CLA_SOFTINTFRC_TASK3      0x4U         // Force CLA software interrupt
                                               // for the corresponding task.
#define CLA_SOFTINTFRC_TASK4      0x8U         // Force CLA software interrupt
                                               // for the corresponding task.
#define CLA_SOFTINTFRC_TASK5      0x10U        // Force CLA software interrupt
                                               // for the corresponding task.
#define CLA_SOFTINTFRC_TASK6      0x20U        // Force CLA software interrupt
                                               // for the corresponding task.
#define CLA_SOFTINTFRC_TASK7      0x40U        // Force CLA software interrupt
                                               // for the corresponding task.
#define CLA_SOFTINTFRC_TASK8      0x80U        // Force CLA software interrupt
                                               // for the corresponding task.
#endif
