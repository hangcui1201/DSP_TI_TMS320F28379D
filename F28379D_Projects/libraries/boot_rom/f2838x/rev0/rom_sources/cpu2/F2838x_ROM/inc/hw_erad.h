//###########################################################################
//
// FILE:    hw_erad.h
//
// TITLE:   Definitions for the ERAD registers.
//
//###########################################################################
// $TI Release:  $
// $Release Date:  $
// $Copyright:  $
//###########################################################################

#ifndef HW_ERAD_H
#define HW_ERAD_H

//*****************************************************************************
//
// The following are defines for the ERAD register offsets
//
//*****************************************************************************
#define ERAD_O_GLBL_EVENT_STAT    0x0U         // GLBL_EVENT_STAT
#define ERAD_O_GLBL_HALT_STAT     0x2U         // GLBL_HALT_STAT
#define ERAD_O_GLBL_ENABLE        0x4U         // GLBL_MODULE_ENABLE
#define ERAD_O_CTM_GLBL_RESET     0x6U         // CTM_GLBL_RESET
#define ERAD_O_GLBL_NMI_CTL       0x8U         // GLBL_NMI_CNTL
#define ERAD_O_GLBL_OWNER         0xAU         // GLBL_OWNER
#define ERAD_O_GLBL_BC_EVENT_AND_MASK_LOW  0xCU         // GLBL_BC_EVENT_AND_MASK_LOW
#define ERAD_O_GLBL_BC_EVENT_AND_MASK_HIGH  0xDU         // GLBL_BC_EVENT_AND_MASK_HIGH
#define ERAD_O_GLBL_BC_EVENT_OR_MASK_LOW  0xEU         // GLBL_BC_EVENT_OR_MASK_LOW
#define ERAD_O_GLBL_BC_EVENT_OR_MASK_HIGH  0xFU         // GLBL_BC_EVENT_OR_MASK_HIGH
#define ERAD_O_GLBL_AND_EVENT_INT_MASK  0x10U        // GLBL_AND_EVENT_INT_MASK
#define ERAD_O_GLBL_OR_EVENT_INT_MASK  0x12U        // GLBL_OR_EVENT_INT_MASK
#define ERAD_O_HWBP_MASK_LOW1     0x0U         // HWBP_MASK_LOW1
#define ERAD_O_HWBP_MASK_HIGH1    0x1U         // HWBP_MASK_HIGH1
#define ERAD_O_HWBP_REF_LOW1      0x2U         // HWBP_REF_LOW1
#define ERAD_O_HWBP_REF_HIGH1     0x3U         // HWBP_REF_HIGH1
#define ERAD_O_HWBP_CLEAR1        0x4U         // HWBP_CLEAR1
#define ERAD_O_HWBP_CNTL1         0x6U         // HWBP_CNTL1
#define ERAD_O_HWBP_STATUS1       0x7U         // HWBP_STATUS1
#define ERAD_O_HWBP_MASK_LOW2     0x8U         // HWBP_MASK_LOW2
#define ERAD_O_HWBP_MASK_HIGH2    0x9U         // HWBP_MASK_HIGH2
#define ERAD_O_HWBP_REF_LOW2      0xAU         // HWBP_REF_LOW2
#define ERAD_O_HWBP_REF_HIGH2     0xBU         // HWBP_REF_HIGH2
#define ERAD_O_HWBP_CLEAR2        0xCU         // HWBP_CLEAR2
#define ERAD_O_HWBP_CNTL2         0xEU         // HWBP_CNTL2
#define ERAD_O_HWBP_STATUS2       0xFU         // HWBP_STATUS2
#define ERAD_O_HWBP_MASK_LOW3     0x10U        // HWBP_MASK_LOW3
#define ERAD_O_HWBP_MASK_HIGH3    0x11U        // HWBP_MASK_HIGH3
#define ERAD_O_HWBP_REF_LOW3      0x12U        // HWBP_REF_LOW3
#define ERAD_O_HWBP_REF_HIGH3     0x13U        // HWBP_REF_HIGH3
#define ERAD_O_HWBP_CLEAR3        0x14U        // HWBP_CLEAR3
#define ERAD_O_HWBP_CNTL3         0x16U        // HWBP_CNTL3
#define ERAD_O_HWBP_STATUS3       0x17U        // HWBP_STATUS3
#define ERAD_O_HWBP_MASK_LOW4     0x18U        // HWBP_MASK_LOW4
#define ERAD_O_HWBP_MASK_HIGH4    0x19U        // HWBP_MASK_HIGH4
#define ERAD_O_HWBP_REF_LOW4      0x1AU        // HWBP_REF_LOW4
#define ERAD_O_HWBP_REF_HIGH4     0x1BU        // HWBP_REF_HIGH4
#define ERAD_O_HWBP_CLEAR4        0x1CU        // HWBP_CLEAR4
#define ERAD_O_HWBP_CNTL4         0x1EU        // HWBP_CNTL4
#define ERAD_O_HWBP_STATUS4       0x1FU        // HWBP_STATUS4
#define ERAD_O_HWBP_MASK_LOW5     0x20U        // HWBP_MASK_LOW5
#define ERAD_O_HWBP_MASK_HIGH5    0x21U        // HWBP_MASK_HIGH5
#define ERAD_O_HWBP_REF_LOW5      0x22U        // HWBP_REF_LOW5
#define ERAD_O_HWBP_REF_HIGH5     0x23U        // HWBP_REF_HIGH5
#define ERAD_O_HWBP_CLEAR5        0x24U        // HWBP_CLEAR5
#define ERAD_O_HWBP_CNTL5         0x26U        // HWBP_CNTL5
#define ERAD_O_HWBP_STATUS5       0x27U        // HWBP_STATUS5
#define ERAD_O_HWBP_MASK_LOW6     0x28U        // HWBP_MASK_LOW6
#define ERAD_O_HWBP_MASK_HIGH6    0x29U        // HWBP_MASK_HIGH6
#define ERAD_O_HWBP_REF_LOW6      0x2AU        // HWBP_REF_LOW6
#define ERAD_O_HWBP_REF_HIGH6     0x2BU        // HWBP_REF_HIGH6
#define ERAD_O_HWBP_CLEAR6        0x2CU        // HWBP_CLEAR6
#define ERAD_O_HWBP_CNTL6         0x2EU        // HWBP_CNTL6
#define ERAD_O_HWBP_STATUS6       0x2FU        // HWBP_STATUS6
#define ERAD_O_HWBP_MASK_LOW7     0x30U        // HWBP_MASK_LOW7
#define ERAD_O_HWBP_MASK_HIGH7    0x31U        // HWBP_MASK_HIGH7
#define ERAD_O_HWBP_REF_LOW7      0x32U        // HWBP_REF_LOW7
#define ERAD_O_HWBP_REF_HIGH7     0x33U        // HWBP_REF_HIGH7
#define ERAD_O_HWBP_CLEAR7        0x34U        // HWBP_CLEAR7
#define ERAD_O_HWBP_CNTL7         0x36U        // HWBP_CNTL7
#define ERAD_O_HWBP_STATUS7       0x37U        // HWBP_STATUS7
#define ERAD_O_HWBP_MASK_LOW8     0x38U        // HWBP_MASK_LOW8
#define ERAD_O_HWBP_MASK_HIGH8    0x39U        // HWBP_MASK_HIGH8
#define ERAD_O_HWBP_REF_LOW8      0x3AU        // HWBP_REF_LOW8
#define ERAD_O_HWBP_REF_HIGH8     0x3BU        // HWBP_REF_HIGH8
#define ERAD_O_HWBP_CLEAR8        0x3CU        // HWBP_CLEAR8
#define ERAD_O_HWBP_CNTL8         0x3EU        // HWBP_CNTL8
#define ERAD_O_HWBP_STATUS8       0x3FU        // HWBP_STATUS8
#define ERAD_O_CTM_CNTL1          0x0U         // CTM_CNTL1
#define ERAD_O_CTM_STATUS1        0x1U         // CTM_STATUS1
#define ERAD_O_CTM_REF_LOW1       0x2U         // CTM_REF_LOW1
#define ERAD_O_CTM_REF_HIGH1      0x3U         // CTM_REF_HIGH1
#define ERAD_O_CTM_COUNT_LOW1     0x4U         // CTM_COUNT_LOW1
#define ERAD_O_CTM_COUNT_HIGH1    0x5U         // CTM_COUNT_HIGH1
#define ERAD_O_CTM_MAX_COUNT_LOW1  0x6U         // CTM_MAX_COUNT_LOW1
#define ERAD_O_CTM_MAX_COUNT_HIGH1  0x7U         // CTM_MAX_COUNT_HIGH1
#define ERAD_O_CTM_INPUT_SEL1_1   0x8U         // CTM_INPUT_SEL1_1
#define ERAD_O_CTM_CLEAR1         0x9U         // CTM_CLEAR1
#define ERAD_O_CTM_INPUT_SEL1_2   0xAU         // CTM_INPUT_SEL1_2
#define ERAD_O_CTM_INPUT_COND1    0xBU         // CTM_INPUT_COND1
#define ERAD_O_CTM_CNTL2          0x10U        // CTM_CNTL2
#define ERAD_O_CTM_STATUS2        0x11U        // CTM_STATUS2
#define ERAD_O_CTM_REF_LOW2       0x12U        // CTM_REF_LOW2
#define ERAD_O_CTM_REF_HIGH2      0x13U        // CTM_REF_HIGH2
#define ERAD_O_CTM_COUNT_LOW2     0x14U        // CTM_COUNT_LOW2
#define ERAD_O_CTM_COUNT_HIGH2    0x15U        // CTM_COUNT_HIGH2
#define ERAD_O_CTM_MAX_COUNT_LOW2  0x16U        // CTM_MAX_COUNT_LOW2
#define ERAD_O_CTM_MAX_COUNT_HIGH2  0x17U        // CTM_MAX_COUNT_HIGH2
#define ERAD_O_CTM_INPUT_SEL2_1   0x18U        // CTM_INPUT_SEL2_1
#define ERAD_O_CTM_CLEAR2         0x19U        // CTM_CLEAR2
#define ERAD_O_CTM_INPUT_SEL2_2   0x1AU        // CTM_INPUT_SEL2_2
#define ERAD_O_CTM_INPUT_COND2    0x1BU        // CTM_INPUT_COND2
#define ERAD_O_CTM_CNTL3          0x20U        // CTM_CNTL3
#define ERAD_O_CTM_STATUS3        0x21U        // CTM_STATUS3
#define ERAD_O_CTM_REF_LOW3       0x22U        // CTM_REF_LOW3
#define ERAD_O_CTM_REF_HIGH3      0x23U        // CTM_REF_HIGH3
#define ERAD_O_CTM_COUNT_LOW3     0x24U        // CTM_COUNT_LOW3
#define ERAD_O_CTM_COUNT_HIGH3    0x25U        // CTM_COUNT_HIGH3
#define ERAD_O_CTM_MAX_COUNT_LOW3  0x26U        // CTM_MAX_COUNT_LOW3
#define ERAD_O_CTM_MAX_COUNT_HIGH3  0x27U        // CTM_MAX_COUNT_HIGH3
#define ERAD_O_CTM_INPUT_SEL3_1   0x28U        // CTM_INPUT_SEL3_1
#define ERAD_O_CTM_CLEAR3         0x29U        // CTM_CLEAR3
#define ERAD_O_CTM_INPUT_SEL3_2   0x2AU        // CTM_INPUT_SEL3_2
#define ERAD_O_CTM_INPUT_COND3    0x2BU        // CTM_INPUT_COND3
#define ERAD_O_CTM_CNTL4          0x30U        // CTM_CNTL4
#define ERAD_O_CTM_STATUS4        0x31U        // CTM_STATUS4
#define ERAD_O_CTM_REF_LOW4       0x32U        // CTM_REF_LOW4
#define ERAD_O_CTM_REF_HIGH4      0x33U        // CTM_REF_HIGH4
#define ERAD_O_CTM_COUNT_LOW4     0x34U        // CTM_COUNT_LOW4
#define ERAD_O_CTM_COUNT_HIGH4    0x35U        // CTM_COUNT_HIGH4
#define ERAD_O_CTM_MAX_COUNT_LOW4  0x36U        // CTM_MAX_COUNT_LOW4
#define ERAD_O_CTM_MAX_COUNT_HIGH4  0x37U        // CTM_MAX_COUNT_HIGH4
#define ERAD_O_CTM_INPUT_SEL4_1   0x38U        // CTM_INPUT_SEL4_1
#define ERAD_O_CTM_CLEAR4         0x39U        // CTM_CLEAR4
#define ERAD_O_CTM_INPUT_SEL4_2   0x3AU        // CTM_INPUT_SEL4_2
#define ERAD_O_CTM_INPUT_COND4    0x3BU        // CTM_INPUT_COND4
#define ERAD_O_CRC_GLOBAL_CTRL    0x0U         // CRC_GLOBAL_CRTL
#define ERAD_O_CRC_CURRENT_LOW1   0x10U        // CRC_CURRENT_LOW1
#define ERAD_O_CRC_CURRENT_HIGH1  0x11U        // CRC_CURRENT_HIGH1
#define ERAD_O_CRC_SEED_LOW1      0x12U        // CRC_SEED_LOW1
#define ERAD_O_CRC_SEED_HIGH1     0x13U        // CRC_SEED_HIGH1
#define ERAD_O_CRC_QUALIFIER1     0x14U        // CRC_QUALIFIER1
#define ERAD_O_CRC_CURRENT_LOW2   0x20U        // CRC_CURRENT_LOW2
#define ERAD_O_CRC_CURRENT_HIGH2  0x21U        // CRC_CURRENT_HIGH2
#define ERAD_O_CRC_SEED_LOW2      0x22U        // CRC_SEED_LOW2
#define ERAD_O_CRC_SEED_HIGH2     0x23U        // CRC_SEED_HIGH2
#define ERAD_O_CRC_QUALIFIER2     0x24U        // CRC_QUALIFIER2
#define ERAD_O_CRC_CURRENT_LOW3   0x30U        // CRC_CURRENT_LOW3
#define ERAD_O_CRC_CURRENT_HIGH3  0x31U        // CRC_CURRENT_HIGH3
#define ERAD_O_CRC_SEED_LOW3      0x32U        // CRC_SEED_LOW3
#define ERAD_O_CRC_SEED_HIGH3     0x33U        // CRC_SEED_HIGH3
#define ERAD_O_CRC_QUALIFIER3     0x34U        // CRC_QUALIFIER3
#define ERAD_O_CRC_CURRENT_LOW4   0x40U        // CRC_CURRENT_LOW4
#define ERAD_O_CRC_CURRENT_HIGH4  0x41U        // CRC_CURRENT_HIGH4
#define ERAD_O_CRC_SEED_LOW4      0x42U        // CRC_SEED_LOW4
#define ERAD_O_CRC_SEED_HIGH4     0x43U        // CRC_SEED_HIGH4
#define ERAD_O_CRC_QUALIFIER4     0x44U        // CRC_QUALIFIER4
#define ERAD_O_CRC_CURRENT_LOW5   0x50U        // CRC_CURRENT_LOW5
#define ERAD_O_CRC_CURRENT_HIGH5  0x51U        // CRC_CURRENT_HIGH5
#define ERAD_O_CRC_SEED_LOW5      0x52U        // CRC_SEED_LOW5
#define ERAD_O_CRC_SEED_HIGH5     0x53U        // CRC_SEED_HIGH5
#define ERAD_O_CRC_QUALIFIER5     0x54U        // CRC_QUALIFIER5
#define ERAD_O_CRC_CURRENT_LOW6   0x60U        // CRC_CURRENT_LOW6
#define ERAD_O_CRC_CURRENT_HIGH6  0x61U        // CRC_CURRENT_HIGH6
#define ERAD_O_CRC_SEED_LOW6      0x62U        // CRC_SEED_LOW6
#define ERAD_O_CRC_SEED_HIGH6     0x63U        // CRC_SEED_HIGH6
#define ERAD_O_CRC_QUALIFIER6     0x64U        // CRC_QUALIFIER6
#define ERAD_O_CRC_CURRENT_LOW7   0x70U        // CRC_CURRENT_LOW7
#define ERAD_O_CRC_CURRENT_HIGH7  0x71U        // CRC_CURRENT_HIGH7
#define ERAD_O_CRC_SEED_LOW7      0x72U        // CRC_SEED_LOW7
#define ERAD_O_CRC_SEED_HIGH7     0x73U        // CRC_SEED_HIGH7
#define ERAD_O_CRC_QUALIFIER7     0x74U        // CRC_QUALIFIER7
#define ERAD_O_CRC_CURRENT_LOW8   0x80U        // CRC_CURRENT_LOW8
#define ERAD_O_CRC_CURRENT_HIGH8  0x81U        // CRC_CURRENT_HIGH8
#define ERAD_O_CRC_SEED_LOW8      0x82U        // CRC_SEED_LOW8
#define ERAD_O_CRC_SEED_HIGH8     0x83U        // CRC_SEED_HIGH8
#define ERAD_O_CRC_QUALIFIER8     0x84U        // CRC_QUALIFIER8

//*****************************************************************************
//
// The following are defines for the bit fields in the GLBL_EVENT_STAT register
//
//*****************************************************************************
#define ERAD_GLBL_EVENT_STAT_HWBP_EVENT_STATUS_S  0U
#define ERAD_GLBL_EVENT_STAT_HWBP_EVENT_STATUS_M  0xFFU        // Bus Comparator Module Event
                                               // Status
#define ERAD_GLBL_EVENT_STAT_COUNTER_EVENT_STATUS_S  8U
#define ERAD_GLBL_EVENT_STAT_COUNTER_EVENT_STATUS_M  0xF00U       // Counter Module Event Status

//*****************************************************************************
//
// The following are defines for the bit fields in the GLBL_HALT_STAT register
//
//*****************************************************************************
#define ERAD_GLBL_HALT_STAT_HWBP_HALT_STATUS_S  0U
#define ERAD_GLBL_HALT_STAT_HWBP_HALT_STATUS_M  0xFFU        // Bus Comparator Module Halt
                                               // Status
#define ERAD_GLBL_HALT_STAT_COUNTER_HALT_STATUS_S  8U
#define ERAD_GLBL_HALT_STAT_COUNTER_HALT_STATUS_M  0xF00U       // Counter Module Halt Status

//*****************************************************************************
//
// The following are defines for the bit fields in the GLBL_ENABLE register
//
//*****************************************************************************
#define ERAD_GLBL_ENABLE_HWBP_GLOBAL_ENABLE_S  0U
#define ERAD_GLBL_ENABLE_HWBP_GLOBAL_ENABLE_M  0xFFU        // Bus Comparator Module Global
                                               // Enable
#define ERAD_GLBL_ENABLE_COUNTER_GLOBAL_ENABLE_S  8U
#define ERAD_GLBL_ENABLE_COUNTER_GLOBAL_ENABLE_M  0xF00U       // Counter Module Global Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the CTM_GLBL_RESET register
//
//*****************************************************************************
#define ERAD_CTM_GLBL_RESET_COUNTER_GLOBAL_RESET_S  0U
#define ERAD_CTM_GLBL_RESET_COUNTER_GLOBAL_RESET_M  0xFU         // Global Reset for the counters

//*****************************************************************************
//
// The following are defines for the bit fields in the GLBL_NMI_CTL register
//
//*****************************************************************************
#define ERAD_GLBL_NMI_CTL_HWBP_NMI_ENABLE_S  0U
#define ERAD_GLBL_NMI_CTL_HWBP_NMI_ENABLE_M  0xFFU        // NMI enable for the HWBP
                                               // blocks
#define ERAD_GLBL_NMI_CTL_COUNTER_NMI_ENABLE_S  8U
#define ERAD_GLBL_NMI_CTL_COUNTER_NMI_ENABLE_M  0xF00U       // NMI enable for the Counter
                                               // blocks

//*****************************************************************************
//
// The following are defines for the bit fields in the GLBL_OWNER register
//
//*****************************************************************************
#define ERAD_GLBL_OWNER_OWNER_S   0U
#define ERAD_GLBL_OWNER_OWNER_M   0x3U         // Global Ownership Bits

//*****************************************************************************
//
// The following are defines for the bit fields in the GLBL_BC_EVENT_AND_MASK_LOW register
//
//*****************************************************************************
#define ERAD_GLBL_BC_EVENT_AND_MASK_LOW_GLBL_BC_EVENT_AND_MASK1_S  0U
#define ERAD_GLBL_BC_EVENT_AND_MASK_LOW_GLBL_BC_EVENT_AND_MASK1_M  0xFFU        // BusComparator AND Event Mask1
#define ERAD_GLBL_BC_EVENT_AND_MASK_LOW_GLBL_BC_EVENT_AND_MASK2_S  8U
#define ERAD_GLBL_BC_EVENT_AND_MASK_LOW_GLBL_BC_EVENT_AND_MASK2_M  0xFF00U      // BusComparator AND Event Mask2

//*****************************************************************************
//
// The following are defines for the bit fields in the GLBL_BC_EVENT_AND_MASK_HIGH register
//
//*****************************************************************************
#define ERAD_GLBL_BC_EVENT_AND_MASK_HIGH_GLBL_BC_EVENT_AND_MASK3_S  0U
#define ERAD_GLBL_BC_EVENT_AND_MASK_HIGH_GLBL_BC_EVENT_AND_MASK3_M  0xFFU        // BusComparator AND Event Mask3
#define ERAD_GLBL_BC_EVENT_AND_MASK_HIGH_GLBL_BC_EVENT_AND_MASK4_S  8U
#define ERAD_GLBL_BC_EVENT_AND_MASK_HIGH_GLBL_BC_EVENT_AND_MASK4_M  0xFF00U      // BusComparator AND Event Mask4

//*****************************************************************************
//
// The following are defines for the bit fields in the GLBL_BC_EVENT_OR_MASK_LOW register
//
//*****************************************************************************
#define ERAD_GLBL_BC_EVENT_OR_MASK_LOW_GLBL_BC_EVENT_OR_MASK1_S  0U
#define ERAD_GLBL_BC_EVENT_OR_MASK_LOW_GLBL_BC_EVENT_OR_MASK1_M  0xFFU        // BusComparator OR Event Mask1
#define ERAD_GLBL_BC_EVENT_OR_MASK_LOW_GLBL_BC_EVENT_OR_MASK2_S  8U
#define ERAD_GLBL_BC_EVENT_OR_MASK_LOW_GLBL_BC_EVENT_OR_MASK2_M  0xFF00U      // BusComparator OR Event Mask2

//*****************************************************************************
//
// The following are defines for the bit fields in the GLBL_BC_EVENT_OR_MASK_HIGH register
//
//*****************************************************************************
#define ERAD_GLBL_BC_EVENT_OR_MASK_HIGH_GLBL_BC_EVENT_OR_MASK3_S  0U
#define ERAD_GLBL_BC_EVENT_OR_MASK_HIGH_GLBL_BC_EVENT_OR_MASK3_M  0xFFU        // BusComparator OR Event Mask3
#define ERAD_GLBL_BC_EVENT_OR_MASK_HIGH_GLBL_BC_EVENT_OR_MASK4_S  8U
#define ERAD_GLBL_BC_EVENT_OR_MASK_HIGH_GLBL_BC_EVENT_OR_MASK4_M  0xFF00U      // BusComparator OR Event Mask4

//*****************************************************************************
//
// The following are defines for the bit fields in the GLBL_AND_EVENT_INT_MASK register
//
//*****************************************************************************
#define ERAD_GLBL_AND_EVENT_INT_MASK_AND_MASK_RTOSINT_GEN_S  0U
#define ERAD_GLBL_AND_EVENT_INT_MASK_AND_MASK_RTOSINT_GEN_M  0xFU         // RTOSINT generation mask for
                                               // global AND events

//*****************************************************************************
//
// The following are defines for the bit fields in the GLBL_OR_EVENT_INT_MASK register
//
//*****************************************************************************
#define ERAD_GLBL_OR_EVENT_INT_MASK_OR_MASK_RTOSINT_GEN_S  0U
#define ERAD_GLBL_OR_EVENT_INT_MASK_OR_MASK_RTOSINT_GEN_M  0xFU         // RTOSINT generation mask for
                                               // global OR events

//*****************************************************************************
//
// The following are defines for the bit fields in the HWBP_CLEAR1 register
//
//*****************************************************************************
#define ERAD_HWBP_CLEAR1_EVENT_CLR  0x1U         // Event Clear register

//*****************************************************************************
//
// The following are defines for the bit fields in the HWBP_CNTL1 register
//
//*****************************************************************************
#define ERAD_HWBP_CNTL1_BUS_SEL_S  1U
#define ERAD_HWBP_CNTL1_BUS_SEL_M  0x1EU        // Bus select bits
#define ERAD_HWBP_CNTL1_STOP      0x20U        // Stop bit (Halt/No Halt of
                                               // CPU)
#define ERAD_HWBP_CNTL1_RTOSINT   0x40U        // RTOSINT bit
#define ERAD_HWBP_CNTL1_COMP_MODE_S  7U
#define ERAD_HWBP_CNTL1_COMP_MODE_M  0x380U       // Compare mode

//*****************************************************************************
//
// The following are defines for the bit fields in the HWBP_STATUS1 register
//
//*****************************************************************************
#define ERAD_HWBP_STATUS1_EVENT_FIRED  0x1U         // HWBP Event Fired bits
#define ERAD_HWBP_STATUS1_MODULE_ID_S  8U
#define ERAD_HWBP_STATUS1_MODULE_ID_M  0x3F00U      // Identification bits
#define ERAD_HWBP_STATUS1_STATUS_S  14U
#define ERAD_HWBP_STATUS1_STATUS_M  0xC000U      // Status bits

//*****************************************************************************
//
// The following are defines for the bit fields in the HWBP_CLEAR2 register
//
//*****************************************************************************
#define ERAD_HWBP_CLEAR2_EVENT_CLR  0x1U         // Event Clear register

//*****************************************************************************
//
// The following are defines for the bit fields in the HWBP_CNTL2 register
//
//*****************************************************************************
#define ERAD_HWBP_CNTL2_BUS_SEL_S  1U
#define ERAD_HWBP_CNTL2_BUS_SEL_M  0x1EU        // Bus select bits
#define ERAD_HWBP_CNTL2_STOP      0x20U        // Stop bit (Halt/No Halt of
                                               // CPU)
#define ERAD_HWBP_CNTL2_RTOSINT   0x40U        // RTOSINT bit
#define ERAD_HWBP_CNTL2_COMP_MODE_S  7U
#define ERAD_HWBP_CNTL2_COMP_MODE_M  0x380U       // Compare mode

//*****************************************************************************
//
// The following are defines for the bit fields in the HWBP_STATUS2 register
//
//*****************************************************************************
#define ERAD_HWBP_STATUS2_EVENT_FIRED  0x1U         // HWBP Event Fired bits
#define ERAD_HWBP_STATUS2_MODULE_ID_S  8U
#define ERAD_HWBP_STATUS2_MODULE_ID_M  0x3F00U      // Identification bits
#define ERAD_HWBP_STATUS2_STATUS_S  14U
#define ERAD_HWBP_STATUS2_STATUS_M  0xC000U      // Status bits

//*****************************************************************************
//
// The following are defines for the bit fields in the HWBP_CLEAR3 register
//
//*****************************************************************************
#define ERAD_HWBP_CLEAR3_EVENT_CLR  0x1U         // Event Clear register

//*****************************************************************************
//
// The following are defines for the bit fields in the HWBP_CNTL3 register
//
//*****************************************************************************
#define ERAD_HWBP_CNTL3_BUS_SEL_S  1U
#define ERAD_HWBP_CNTL3_BUS_SEL_M  0x1EU        // Bus select bits
#define ERAD_HWBP_CNTL3_STOP      0x20U        // Stop bit (Halt/No Halt of
                                               // CPU)
#define ERAD_HWBP_CNTL3_RTOSINT   0x40U        // RTOSINT bit
#define ERAD_HWBP_CNTL3_COMP_MODE_S  7U
#define ERAD_HWBP_CNTL3_COMP_MODE_M  0x380U       // Compare mode

//*****************************************************************************
//
// The following are defines for the bit fields in the HWBP_STATUS3 register
//
//*****************************************************************************
#define ERAD_HWBP_STATUS3_EVENT_FIRED  0x1U         // HWBP Event Fired bits
#define ERAD_HWBP_STATUS3_MODULE_ID_S  8U
#define ERAD_HWBP_STATUS3_MODULE_ID_M  0x3F00U      // Identification bits
#define ERAD_HWBP_STATUS3_STATUS_S  14U
#define ERAD_HWBP_STATUS3_STATUS_M  0xC000U      // Status bits

//*****************************************************************************
//
// The following are defines for the bit fields in the HWBP_CLEAR4 register
//
//*****************************************************************************
#define ERAD_HWBP_CLEAR4_EVENT_CLR  0x1U         // Event Clear register

//*****************************************************************************
//
// The following are defines for the bit fields in the HWBP_CNTL4 register
//
//*****************************************************************************
#define ERAD_HWBP_CNTL4_BUS_SEL_S  1U
#define ERAD_HWBP_CNTL4_BUS_SEL_M  0x1EU        // Bus select bits
#define ERAD_HWBP_CNTL4_STOP      0x20U        // Stop bit (Halt/No Halt of
                                               // CPU)
#define ERAD_HWBP_CNTL4_RTOSINT   0x40U        // RTOSINT bit
#define ERAD_HWBP_CNTL4_COMP_MODE_S  7U
#define ERAD_HWBP_CNTL4_COMP_MODE_M  0x380U       // Compare mode

//*****************************************************************************
//
// The following are defines for the bit fields in the HWBP_STATUS4 register
//
//*****************************************************************************
#define ERAD_HWBP_STATUS4_EVENT_FIRED  0x1U         // HWBP Event Fired bits
#define ERAD_HWBP_STATUS4_MODULE_ID_S  8U
#define ERAD_HWBP_STATUS4_MODULE_ID_M  0x3F00U      // Identification bits
#define ERAD_HWBP_STATUS4_STATUS_S  14U
#define ERAD_HWBP_STATUS4_STATUS_M  0xC000U      // Status bits

//*****************************************************************************
//
// The following are defines for the bit fields in the HWBP_CLEAR5 register
//
//*****************************************************************************
#define ERAD_HWBP_CLEAR5_EVENT_CLR  0x1U         // Event Clear register

//*****************************************************************************
//
// The following are defines for the bit fields in the HWBP_CNTL5 register
//
//*****************************************************************************
#define ERAD_HWBP_CNTL5_BUS_SEL_S  1U
#define ERAD_HWBP_CNTL5_BUS_SEL_M  0x1EU        // Bus select bits
#define ERAD_HWBP_CNTL5_STOP      0x20U        // Stop bit (Halt/No Halt of
                                               // CPU)
#define ERAD_HWBP_CNTL5_RTOSINT   0x40U        // RTOSINT bit
#define ERAD_HWBP_CNTL5_COMP_MODE_S  7U
#define ERAD_HWBP_CNTL5_COMP_MODE_M  0x380U       // Compare mode

//*****************************************************************************
//
// The following are defines for the bit fields in the HWBP_STATUS5 register
//
//*****************************************************************************
#define ERAD_HWBP_STATUS5_EVENT_FIRED  0x1U         // HWBP Event Fired bits
#define ERAD_HWBP_STATUS5_MODULE_ID_S  8U
#define ERAD_HWBP_STATUS5_MODULE_ID_M  0x3F00U      // Identification bits
#define ERAD_HWBP_STATUS5_STATUS_S  14U
#define ERAD_HWBP_STATUS5_STATUS_M  0xC000U      // Status bits

//*****************************************************************************
//
// The following are defines for the bit fields in the HWBP_CLEAR6 register
//
//*****************************************************************************
#define ERAD_HWBP_CLEAR6_EVENT_CLR  0x1U         // Event Clear register

//*****************************************************************************
//
// The following are defines for the bit fields in the HWBP_CNTL6 register
//
//*****************************************************************************
#define ERAD_HWBP_CNTL6_BUS_SEL_S  1U
#define ERAD_HWBP_CNTL6_BUS_SEL_M  0x1EU        // Bus select bits
#define ERAD_HWBP_CNTL6_STOP      0x20U        // Stop bit (Halt/No Halt of
                                               // CPU)
#define ERAD_HWBP_CNTL6_RTOSINT   0x40U        // RTOSINT bit
#define ERAD_HWBP_CNTL6_COMP_MODE_S  7U
#define ERAD_HWBP_CNTL6_COMP_MODE_M  0x380U       // Compare mode

//*****************************************************************************
//
// The following are defines for the bit fields in the HWBP_STATUS6 register
//
//*****************************************************************************
#define ERAD_HWBP_STATUS6_EVENT_FIRED  0x1U         // HWBP Event Fired bits
#define ERAD_HWBP_STATUS6_MODULE_ID_S  8U
#define ERAD_HWBP_STATUS6_MODULE_ID_M  0x3F00U      // Identification bits
#define ERAD_HWBP_STATUS6_STATUS_S  14U
#define ERAD_HWBP_STATUS6_STATUS_M  0xC000U      // Status bits

//*****************************************************************************
//
// The following are defines for the bit fields in the HWBP_CLEAR7 register
//
//*****************************************************************************
#define ERAD_HWBP_CLEAR7_EVENT_CLR  0x1U         // Event Clear register

//*****************************************************************************
//
// The following are defines for the bit fields in the HWBP_CNTL7 register
//
//*****************************************************************************
#define ERAD_HWBP_CNTL7_BUS_SEL_S  1U
#define ERAD_HWBP_CNTL7_BUS_SEL_M  0x1EU        // Bus select bits
#define ERAD_HWBP_CNTL7_STOP      0x20U        // Stop bit (Halt/No Halt of
                                               // CPU)
#define ERAD_HWBP_CNTL7_RTOSINT   0x40U        // RTOSINT bit
#define ERAD_HWBP_CNTL7_COMP_MODE_S  7U
#define ERAD_HWBP_CNTL7_COMP_MODE_M  0x380U       // Compare mode

//*****************************************************************************
//
// The following are defines for the bit fields in the HWBP_STATUS7 register
//
//*****************************************************************************
#define ERAD_HWBP_STATUS7_EVENT_FIRED  0x1U         // HWBP Event Fired bits
#define ERAD_HWBP_STATUS7_MODULE_ID_S  8U
#define ERAD_HWBP_STATUS7_MODULE_ID_M  0x3F00U      // Identification bits
#define ERAD_HWBP_STATUS7_STATUS_S  14U
#define ERAD_HWBP_STATUS7_STATUS_M  0xC000U      // Status bits

//*****************************************************************************
//
// The following are defines for the bit fields in the HWBP_CLEAR8 register
//
//*****************************************************************************
#define ERAD_HWBP_CLEAR8_EVENT_CLR  0x1U         // Event Clear register

//*****************************************************************************
//
// The following are defines for the bit fields in the HWBP_CNTL8 register
//
//*****************************************************************************
#define ERAD_HWBP_CNTL8_BUS_SEL_S  1U
#define ERAD_HWBP_CNTL8_BUS_SEL_M  0x1EU        // Bus select bits
#define ERAD_HWBP_CNTL8_STOP      0x20U        // Stop bit (Halt/No Halt of
                                               // CPU)
#define ERAD_HWBP_CNTL8_RTOSINT   0x40U        // RTOSINT bit
#define ERAD_HWBP_CNTL8_COMP_MODE_S  7U
#define ERAD_HWBP_CNTL8_COMP_MODE_M  0x380U       // Compare mode

//*****************************************************************************
//
// The following are defines for the bit fields in the HWBP_STATUS8 register
//
//*****************************************************************************
#define ERAD_HWBP_STATUS8_EVENT_FIRED  0x1U         // HWBP Event Fired bits
#define ERAD_HWBP_STATUS8_MODULE_ID_S  8U
#define ERAD_HWBP_STATUS8_MODULE_ID_M  0x3F00U      // Identification bits
#define ERAD_HWBP_STATUS8_STATUS_S  14U
#define ERAD_HWBP_STATUS8_STATUS_M  0xC000U      // Status bits

//*****************************************************************************
//
// The following are defines for the bit fields in the CTM_CNTL1 register
//
//*****************************************************************************
#define ERAD_CTM_CNTL1_START_STOP_MODE  0x4U         // Start_stop mode bit
#define ERAD_CTM_CNTL1_EVENT_MODE  0x8U         // Event mode bit
#define ERAD_CTM_CNTL1_RST_ON_MATCH  0x10U        // Reset_on_match bit
#define ERAD_CTM_CNTL1_STOP       0x40U        // Stop bit (Halt/No Halt of
                                               // CPU)
#define ERAD_CTM_CNTL1_RTOSINT    0x80U        // RTOSINT bit
#define ERAD_CTM_CNTL1_START_STOP_CUMULATIVE  0x100U       // Start stop cumulative bit
#define ERAD_CTM_CNTL1_RST_EN     0x400U       // Enable Reset
#define ERAD_CTM_CNTL1_CNT_INP_SEL_EN  0x800U       // Counter Input Select Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the CTM_STATUS1 register
//
//*****************************************************************************
#define ERAD_CTM_STATUS1_EVENT_FIRED  0x1U         // Counter Event Fired bits
#define ERAD_CTM_STATUS1_OVERFLOW  0x2U         // Counter Overflowed
#define ERAD_CTM_STATUS1_MODULE_ID_S  2U
#define ERAD_CTM_STATUS1_MODULE_ID_M  0xFFCU       // Identification bits
#define ERAD_CTM_STATUS1_STATUS_S  12U
#define ERAD_CTM_STATUS1_STATUS_M  0xF000U      // Status bits

//*****************************************************************************
//
// The following are defines for the bit fields in the CTM_INPUT_SEL1_1 register
//
//*****************************************************************************
#define ERAD_CTM_INPUT_SEL1_1_CNT_INP_SEL_S  0U
#define ERAD_CTM_INPUT_SEL1_1_CNT_INP_SEL_M  0xFFU        // Counter Input Select
#define ERAD_CTM_INPUT_SEL1_1_STA_INP_SEL_S  8U
#define ERAD_CTM_INPUT_SEL1_1_STA_INP_SEL_M  0xFF00U      // Counter Sart Input Select

//*****************************************************************************
//
// The following are defines for the bit fields in the CTM_CLEAR1 register
//
//*****************************************************************************
#define ERAD_CTM_CLEAR1_EVENT_CLEAR  0x1U         // Clear EVENT_FIRED
#define ERAD_CTM_CLEAR1_OVERFLOW_CLEAR  0x2U         // Clear OVERFLOW

//*****************************************************************************
//
// The following are defines for the bit fields in the CTM_INPUT_SEL1_2 register
//
//*****************************************************************************
#define ERAD_CTM_INPUT_SEL1_2_STO_INP_SEL_S  0U
#define ERAD_CTM_INPUT_SEL1_2_STO_INP_SEL_M  0xFFU        // Counter Stop Input Select
#define ERAD_CTM_INPUT_SEL1_2_RST_INP_SEL_S  8U
#define ERAD_CTM_INPUT_SEL1_2_RST_INP_SEL_M  0xFF00U      // Counter Reset input Select

//*****************************************************************************
//
// The following are defines for the bit fields in the CTM_INPUT_COND1 register
//
//*****************************************************************************
#define ERAD_CTM_INPUT_COND1_CTM_INP_INV  0x1U         // Counter Input Invert
#define ERAD_CTM_INPUT_COND1_CTM_INP_SYNCH  0x2U         // Counter input synchronizer
                                               // enable
#define ERAD_CTM_INPUT_COND1_STA_INP_INV  0x10U        // Start input Invert
#define ERAD_CTM_INPUT_COND1_STA_INP_SYNCH  0x20U        // Start input synchronizer
                                               // enable
#define ERAD_CTM_INPUT_COND1_STO_INP_INV  0x100U       // Stop input Invert
#define ERAD_CTM_INPUT_COND1_STO_INP_SYNCH  0x200U       // Stop input synchronizer
                                               // enable
#define ERAD_CTM_INPUT_COND1_RST_INP_INV  0x1000U      // Reset input Invert
#define ERAD_CTM_INPUT_COND1_RST_INP_SYNCH  0x2000U      // Reset input synchronizer
                                               // enable

//*****************************************************************************
//
// The following are defines for the bit fields in the CTM_CNTL2 register
//
//*****************************************************************************
#define ERAD_CTM_CNTL2_START_STOP_MODE  0x4U         // Start_stop mode bit
#define ERAD_CTM_CNTL2_EVENT_MODE  0x8U         // Event mode bit
#define ERAD_CTM_CNTL2_RST_ON_MATCH  0x10U        // Reset_on_match bit
#define ERAD_CTM_CNTL2_STOP       0x40U        // Stop bit (Halt/No Halt of
                                               // CPU)
#define ERAD_CTM_CNTL2_RTOSINT    0x80U        // RTOSINT bit
#define ERAD_CTM_CNTL2_START_STOP_CUMULATIVE  0x100U       // Start stop cumulative bit
#define ERAD_CTM_CNTL2_RST_EN     0x400U       // Enable Reset
#define ERAD_CTM_CNTL2_CNT_INP_SEL_EN  0x800U       // Counter Input Select Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the CTM_STATUS2 register
//
//*****************************************************************************
#define ERAD_CTM_STATUS2_EVENT_FIRED  0x1U         // Counter Event Fired bits
#define ERAD_CTM_STATUS2_OVERFLOW  0x2U         // Counter Overflowed
#define ERAD_CTM_STATUS2_MODULE_ID_S  2U
#define ERAD_CTM_STATUS2_MODULE_ID_M  0xFFCU       // Identification bits
#define ERAD_CTM_STATUS2_STATUS_S  12U
#define ERAD_CTM_STATUS2_STATUS_M  0xF000U      // Status bits

//*****************************************************************************
//
// The following are defines for the bit fields in the CTM_INPUT_SEL2_1 register
//
//*****************************************************************************
#define ERAD_CTM_INPUT_SEL2_1_CNT_INP_SEL_S  0U
#define ERAD_CTM_INPUT_SEL2_1_CNT_INP_SEL_M  0xFFU        // Counter Input Select
#define ERAD_CTM_INPUT_SEL2_1_STA_INP_SEL_S  8U
#define ERAD_CTM_INPUT_SEL2_1_STA_INP_SEL_M  0xFF00U      // Counter Sart Input Select

//*****************************************************************************
//
// The following are defines for the bit fields in the CTM_CLEAR2 register
//
//*****************************************************************************
#define ERAD_CTM_CLEAR2_EVENT_CLEAR  0x1U         // Clear EVENT_FIRED
#define ERAD_CTM_CLEAR2_OVERFLOW_CLEAR  0x2U         // Clear OVERFLOW

//*****************************************************************************
//
// The following are defines for the bit fields in the CTM_INPUT_SEL2_2 register
//
//*****************************************************************************
#define ERAD_CTM_INPUT_SEL2_2_STO_INP_SEL_S  0U
#define ERAD_CTM_INPUT_SEL2_2_STO_INP_SEL_M  0xFFU        // Counter Stop Input Select
#define ERAD_CTM_INPUT_SEL2_2_RST_INP_SEL_S  8U
#define ERAD_CTM_INPUT_SEL2_2_RST_INP_SEL_M  0xFF00U      // Counter Reset input Select

//*****************************************************************************
//
// The following are defines for the bit fields in the CTM_INPUT_COND2 register
//
//*****************************************************************************
#define ERAD_CTM_INPUT_COND2_CTM_INP_INV  0x1U         // Counter Input Invert
#define ERAD_CTM_INPUT_COND2_CTM_INP_SYNCH  0x2U         // Counter input synchronizer
                                               // enable
#define ERAD_CTM_INPUT_COND2_STA_INP_INV  0x10U        // Start input Invert
#define ERAD_CTM_INPUT_COND2_STA_INP_SYNCH  0x20U        // Start input synchronizer
                                               // enable
#define ERAD_CTM_INPUT_COND2_STO_INP_INV  0x100U       // Stop input Invert
#define ERAD_CTM_INPUT_COND2_STO_INP_SYNCH  0x200U       // Stop input synchronizer
                                               // enable
#define ERAD_CTM_INPUT_COND2_RST_INP_INV  0x1000U      // Reset input Invert
#define ERAD_CTM_INPUT_COND2_RST_INP_SYNCH  0x2000U      // Reset input synchronizer
                                               // enable

//*****************************************************************************
//
// The following are defines for the bit fields in the CTM_CNTL3 register
//
//*****************************************************************************
#define ERAD_CTM_CNTL3_START_STOP_MODE  0x4U         // Start_stop mode bit
#define ERAD_CTM_CNTL3_EVENT_MODE  0x8U         // Event mode bit
#define ERAD_CTM_CNTL3_RST_ON_MATCH  0x10U        // Reset_on_match bit
#define ERAD_CTM_CNTL3_STOP       0x40U        // Stop bit (Halt/No Halt of
                                               // CPU)
#define ERAD_CTM_CNTL3_RTOSINT    0x80U        // RTOSINT bit
#define ERAD_CTM_CNTL3_START_STOP_CUMULATIVE  0x100U       // Start stop cumulative bit
#define ERAD_CTM_CNTL3_RST_EN     0x400U       // Enable Reset
#define ERAD_CTM_CNTL3_CNT_INP_SEL_EN  0x800U       // Counter Input Select Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the CTM_STATUS3 register
//
//*****************************************************************************
#define ERAD_CTM_STATUS3_EVENT_FIRED  0x1U         // Counter Event Fired bits
#define ERAD_CTM_STATUS3_OVERFLOW  0x2U         // Counter Overflowed
#define ERAD_CTM_STATUS3_MODULE_ID_S  2U
#define ERAD_CTM_STATUS3_MODULE_ID_M  0xFFCU       // Identification bits
#define ERAD_CTM_STATUS3_STATUS_S  12U
#define ERAD_CTM_STATUS3_STATUS_M  0xF000U      // Status bits

//*****************************************************************************
//
// The following are defines for the bit fields in the CTM_INPUT_SEL3_1 register
//
//*****************************************************************************
#define ERAD_CTM_INPUT_SEL3_1_CNT_INP_SEL_S  0U
#define ERAD_CTM_INPUT_SEL3_1_CNT_INP_SEL_M  0xFFU        // Counter Input Select
#define ERAD_CTM_INPUT_SEL3_1_STA_INP_SEL_S  8U
#define ERAD_CTM_INPUT_SEL3_1_STA_INP_SEL_M  0xFF00U      // Counter Sart Input Select

//*****************************************************************************
//
// The following are defines for the bit fields in the CTM_CLEAR3 register
//
//*****************************************************************************
#define ERAD_CTM_CLEAR3_EVENT_CLEAR  0x1U         // Clear EVENT_FIRED
#define ERAD_CTM_CLEAR3_OVERFLOW_CLEAR  0x2U         // Clear OVERFLOW

//*****************************************************************************
//
// The following are defines for the bit fields in the CTM_INPUT_SEL3_2 register
//
//*****************************************************************************
#define ERAD_CTM_INPUT_SEL3_2_STO_INP_SEL_S  0U
#define ERAD_CTM_INPUT_SEL3_2_STO_INP_SEL_M  0xFFU        // Counter Stop Input Select
#define ERAD_CTM_INPUT_SEL3_2_RST_INP_SEL_S  8U
#define ERAD_CTM_INPUT_SEL3_2_RST_INP_SEL_M  0xFF00U      // Counter Reset input Select

//*****************************************************************************
//
// The following are defines for the bit fields in the CTM_INPUT_COND3 register
//
//*****************************************************************************
#define ERAD_CTM_INPUT_COND3_CTM_INP_INV  0x1U         // Counter Input Invert
#define ERAD_CTM_INPUT_COND3_CTM_INP_SYNCH  0x2U         // Counter input synchronizer
                                               // enable
#define ERAD_CTM_INPUT_COND3_STA_INP_INV  0x10U        // Start input Invert
#define ERAD_CTM_INPUT_COND3_STA_INP_SYNCH  0x20U        // Start input synchronizer
                                               // enable
#define ERAD_CTM_INPUT_COND3_STO_INP_INV  0x100U       // Stop input Invert
#define ERAD_CTM_INPUT_COND3_STO_INP_SYNCH  0x200U       // Stop input synchronizer
                                               // enable
#define ERAD_CTM_INPUT_COND3_RST_INP_INV  0x1000U      // Reset input Invert
#define ERAD_CTM_INPUT_COND3_RST_INP_SYNCH  0x2000U      // Reset input synchronizer
                                               // enable

//*****************************************************************************
//
// The following are defines for the bit fields in the CTM_CNTL4 register
//
//*****************************************************************************
#define ERAD_CTM_CNTL4_START_STOP_MODE  0x4U         // Start_stop mode bit
#define ERAD_CTM_CNTL4_EVENT_MODE  0x8U         // Event mode bit
#define ERAD_CTM_CNTL4_RST_ON_MATCH  0x10U        // Reset_on_match bit
#define ERAD_CTM_CNTL4_STOP       0x40U        // Stop bit (Halt/No Halt of
                                               // CPU)
#define ERAD_CTM_CNTL4_RTOSINT    0x80U        // RTOSINT bit
#define ERAD_CTM_CNTL4_START_STOP_CUMULATIVE  0x100U       // Start stop cumulative bit
#define ERAD_CTM_CNTL4_RST_EN     0x400U       // Enable Reset
#define ERAD_CTM_CNTL4_CNT_INP_SEL_EN  0x800U       // Counter Input Select Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the CTM_STATUS4 register
//
//*****************************************************************************
#define ERAD_CTM_STATUS4_EVENT_FIRED  0x1U         // Counter Event Fired bits
#define ERAD_CTM_STATUS4_OVERFLOW  0x2U         // Counter Overflowed
#define ERAD_CTM_STATUS4_MODULE_ID_S  2U
#define ERAD_CTM_STATUS4_MODULE_ID_M  0xFFCU       // Identification bits
#define ERAD_CTM_STATUS4_STATUS_S  12U
#define ERAD_CTM_STATUS4_STATUS_M  0xF000U      // Status bits

//*****************************************************************************
//
// The following are defines for the bit fields in the CTM_INPUT_SEL4_1 register
//
//*****************************************************************************
#define ERAD_CTM_INPUT_SEL4_1_CNT_INP_SEL_S  0U
#define ERAD_CTM_INPUT_SEL4_1_CNT_INP_SEL_M  0xFFU        // Counter Input Select
#define ERAD_CTM_INPUT_SEL4_1_STA_INP_SEL_S  8U
#define ERAD_CTM_INPUT_SEL4_1_STA_INP_SEL_M  0xFF00U      // Counter Sart Input Select

//*****************************************************************************
//
// The following are defines for the bit fields in the CTM_CLEAR4 register
//
//*****************************************************************************
#define ERAD_CTM_CLEAR4_EVENT_CLEAR  0x1U         // Clear EVENT_FIRED
#define ERAD_CTM_CLEAR4_OVERFLOW_CLEAR  0x2U         // Clear OVERFLOW

//*****************************************************************************
//
// The following are defines for the bit fields in the CTM_INPUT_SEL4_2 register
//
//*****************************************************************************
#define ERAD_CTM_INPUT_SEL4_2_STO_INP_SEL_S  0U
#define ERAD_CTM_INPUT_SEL4_2_STO_INP_SEL_M  0xFFU        // Counter Stop Input Select
#define ERAD_CTM_INPUT_SEL4_2_RST_INP_SEL_S  8U
#define ERAD_CTM_INPUT_SEL4_2_RST_INP_SEL_M  0xFF00U      // Counter Reset input Select

//*****************************************************************************
//
// The following are defines for the bit fields in the CTM_INPUT_COND4 register
//
//*****************************************************************************
#define ERAD_CTM_INPUT_COND4_CTM_INP_INV  0x1U         // Counter Input Invert
#define ERAD_CTM_INPUT_COND4_CTM_INP_SYNCH  0x2U         // Counter input synchronizer
                                               // enable
#define ERAD_CTM_INPUT_COND4_STA_INP_INV  0x10U        // Start input Invert
#define ERAD_CTM_INPUT_COND4_STA_INP_SYNCH  0x20U        // Start input synchronizer
                                               // enable
#define ERAD_CTM_INPUT_COND4_STO_INP_INV  0x100U       // Stop input Invert
#define ERAD_CTM_INPUT_COND4_STO_INP_SYNCH  0x200U       // Stop input synchronizer
                                               // enable
#define ERAD_CTM_INPUT_COND4_RST_INP_INV  0x1000U      // Reset input Invert
#define ERAD_CTM_INPUT_COND4_RST_INP_SYNCH  0x2000U      // Reset input synchronizer
                                               // enable

//*****************************************************************************
//
// The following are defines for the bit fields in the CRC_GLOBAL_CTRL register
//
//*****************************************************************************
#define ERAD_CRC_GLOBAL_CTRL_CRC_INIT_S  0U
#define ERAD_CRC_GLOBAL_CTRL_CRC_INIT_M  0x3FU        // Initialize CRC Module
#define ERAD_CRC_GLOBAL_CTRL_CRC_EN_S  8U
#define ERAD_CRC_GLOBAL_CTRL_CRC_EN_M  0x3F00U      // Enable CRC Module

//*****************************************************************************
//
// The following are defines for the bit fields in the CRC_QUALIFIER1 register
//
//*****************************************************************************
#define ERAD_CRC_QUALIFIER1_CRC_QUALIFIER1_S  0U
#define ERAD_CRC_QUALIFIER1_CRC_QUALIFIER1_M  0x1FU        // CRC Qualifier Register

//*****************************************************************************
//
// The following are defines for the bit fields in the CRC_QUALIFIER2 register
//
//*****************************************************************************
#define ERAD_CRC_QUALIFIER2_CRC_QUALIFIER2_S  0U
#define ERAD_CRC_QUALIFIER2_CRC_QUALIFIER2_M  0x1FU        // CRC Qualifier Register

//*****************************************************************************
//
// The following are defines for the bit fields in the CRC_QUALIFIER3 register
//
//*****************************************************************************
#define ERAD_CRC_QUALIFIER3_CRC_QUALIFIER3_S  0U
#define ERAD_CRC_QUALIFIER3_CRC_QUALIFIER3_M  0x1FU        // CRC Qualifier Register

//*****************************************************************************
//
// The following are defines for the bit fields in the CRC_QUALIFIER4 register
//
//*****************************************************************************
#define ERAD_CRC_QUALIFIER4_CRC_QUALIFIER4_S  0U
#define ERAD_CRC_QUALIFIER4_CRC_QUALIFIER4_M  0x1FU        // CRC Qualifier Register

//*****************************************************************************
//
// The following are defines for the bit fields in the CRC_QUALIFIER5 register
//
//*****************************************************************************
#define ERAD_CRC_QUALIFIER5_CRC_QUALIFIER5_S  0U
#define ERAD_CRC_QUALIFIER5_CRC_QUALIFIER5_M  0x1FU        // CRC Qualifier Register

//*****************************************************************************
//
// The following are defines for the bit fields in the CRC_QUALIFIER6 register
//
//*****************************************************************************
#define ERAD_CRC_QUALIFIER6_CRC_QUALIFIER6_S  0U
#define ERAD_CRC_QUALIFIER6_CRC_QUALIFIER6_M  0x1FU        // CRC Qualifier Register

//*****************************************************************************
//
// The following are defines for the bit fields in the CRC_QUALIFIER7 register
//
//*****************************************************************************
#define ERAD_CRC_QUALIFIER7_CRC_QUALIFIER7_S  0U
#define ERAD_CRC_QUALIFIER7_CRC_QUALIFIER7_M  0x1FU        // CRC Qualifier Register

//*****************************************************************************
//
// The following are defines for the bit fields in the CRC_QUALIFIER8 register
//
//*****************************************************************************
#define ERAD_CRC_QUALIFIER8_CRC_QUALIFIER8_S  0U
#define ERAD_CRC_QUALIFIER8_CRC_QUALIFIER8_M  0x1FU        // CRC Qualifier Register
#endif
