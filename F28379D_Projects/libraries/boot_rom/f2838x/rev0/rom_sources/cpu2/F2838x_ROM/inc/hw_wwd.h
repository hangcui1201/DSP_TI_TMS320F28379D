//###########################################################################
//
// FILE:    hw_wwd.h
//
// TITLE:   Definitions for the SYSCTL registers.
//
//###########################################################################
// $TI Release:  $
// $Release Date:  $
// $Copyright:  $
//###########################################################################

#ifndef HW_WWD_H
#define HW_WWD_H

//*****************************************************************************
//
// The following are defines for the SYSCTL register offsets
//
//*****************************************************************************
#define SYSCTL_O_SCSR             0x22U        // System Control & Status
                                               // Register
#define SYSCTL_O_WDCNTR           0x23U        // Watchdog Counter Register
#define SYSCTL_O_WDKEY            0x25U        // Watchdog Reset Key Register
#define SYSCTL_O_WDCR             0x29U        // Watchdog Control Register
#define SYSCTL_O_WDWCR            0x2AU        // Watchdog Windowed Control
                                               // Register

//*****************************************************************************
//
// The following are defines for the bit fields in the SCSR register
//
//*****************************************************************************
#define SYSCTL_SCSR_WDOVERRIDE    0x1U         // WD Override for WDDIS bit
#define SYSCTL_SCSR_WDENINT       0x2U         // WD Interrupt Enable
#define SYSCTL_SCSR_WDINTS        0x4U         // WD Interrupt Status

//*****************************************************************************
//
// The following are defines for the bit fields in the WDCNTR register
//
//*****************************************************************************
#define SYSCTL_WDCNTR_WDCNTR_S    0U
#define SYSCTL_WDCNTR_WDCNTR_M    0xFFU        // WD Counter

//*****************************************************************************
//
// The following are defines for the bit fields in the WDKEY register
//
//*****************************************************************************
#define SYSCTL_WDKEY_WDKEY_S      0U
#define SYSCTL_WDKEY_WDKEY_M      0xFFU        // WD KEY

//*****************************************************************************
//
// The following are defines for the bit fields in the WDCR register
//
//*****************************************************************************
#define SYSCTL_WDCR_WDPS_S        0U
#define SYSCTL_WDCR_WDPS_M        0x7U         // WD Clock Prescalar
#define SYSCTL_WDCR_WDCHK_S       3U
#define SYSCTL_WDCR_WDCHK_M       0x38U        // WD Check Bits
#define SYSCTL_WDCR_WDDIS         0x40U        // WD Disable
#define SYSCTL_WDCR_WDFLG         0x80U        // WD Reset Status Flag
#define SYSCTL_WDCR_WDPRECLKDIV_S  8U
#define SYSCTL_WDCR_WDPRECLKDIV_M  0xF00U       // WD Pre Clock Divider

//*****************************************************************************
//
// The following are defines for the bit fields in the WDWCR register
//
//*****************************************************************************
#define SYSCTL_WDWCR_MIN_S        0U
#define SYSCTL_WDWCR_MIN_M        0xFFU        // WD Min Threshold setting for
                                               // Windowed Watchdog
                                               // functionality
#define SYSCTL_WDWCR_FIRSTKEY     0x100U       // First Key Detect Flag
#endif
