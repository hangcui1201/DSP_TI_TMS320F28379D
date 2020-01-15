//###########################################################################
//
// FILE:    hw_cputimer.h
//
// TITLE:   Definitions for the CPUTIMER registers.
//
//###########################################################################
// $TI Release:  $
// $Release Date:  $
// $Copyright:  $
//###########################################################################

#ifndef HW_CPUTIMER_H
#define HW_CPUTIMER_H

//*****************************************************************************
//
// The following are defines for the CPUTIMER register offsets
//
//*****************************************************************************
#define CPUTIMER_O_TIM            0x0U         // Timer counter register
#define CPUTIMER_O_PRD            0x4U         // Timer period register
#define CPUTIMER_O_TCR            0x8U         // Timer control register
#define CPUTIMER_O_TPR            0xCU         // Timer prescaler register

//*****************************************************************************
//
// The following are defines for the bit fields in the TCR register
//
//*****************************************************************************
#define CPUTIMER_TCR_TSS          0x10U        // Timer Stop Status
#define CPUTIMER_TCR_TRB          0x20U        // Timer Reload Bit
#define CPUTIMER_TCR_SOFT         0x400U       // SOFT stop enable
#define CPUTIMER_TCR_FREE         0x800U       // Free run enable
#define CPUTIMER_TCR_TIE          0x4000U      // Timer Interrupt Enable
#define CPUTIMER_TCR_TIF          0x8000U      // Timer Intrerrupt Flag

//*****************************************************************************
//
// The following are defines for the bit fields in the TPR register
//
//*****************************************************************************
#define CPUTIMER_TPR_TDDRL_S      0U
#define CPUTIMER_TPR_TDDRL_M      0xFFU        // Timer Divide Down Register
                                               // Low
#define CPUTIMER_TPR_PSCL_S       8U
#define CPUTIMER_TPR_PSCL_M       0xFF00U      // Prescaler Counter low
#define CPUTIMER_TPR_TDDRH_S      16U
#define CPUTIMER_TPR_TDDRH_M      0xFF0000U    // Timer Divide Down Register
                                               // High
#define CPUTIMER_TPR_PSCH_S       24U
#define CPUTIMER_TPR_PSCH_M       0xFF000000U  // Prescaler Counter high
#endif
