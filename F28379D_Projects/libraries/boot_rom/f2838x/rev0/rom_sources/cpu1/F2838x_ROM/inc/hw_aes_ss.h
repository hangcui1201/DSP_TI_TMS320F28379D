//###########################################################################
//
// FILE:    hw_aes_ss.h
//
// TITLE:   Definitions for the AES_SS registers.
//
//###########################################################################
// $TI Release:  $
// $Release Date:  $
// $Copyright:  $
//###########################################################################

#ifndef HW_AES_SS_H
#define HW_AES_SS_H

//*****************************************************************************
//
// The following are defines for the AES_SS register offsets
//
//*****************************************************************************
#define AES_SS_O_AESDMAINTEN      0x0U         // DMA Done Interrupt enable
                                               // register
#define AES_SS_O_AESDMASTATUS     0x2U         // DMA Done Interrupt status
                                               // register
#define AES_SS_O_AESDMASTATUSCLR  0x4U         // DMA Done Interrupt status
                                               // clear register

//*****************************************************************************
//
// The following are defines for the bit fields in the AESDMAINTEN register
//
//*****************************************************************************
#define AES_SS_AESDMAINTEN_DMADONECTXIN  0x1U         // Enable bit for DMADONECTXIN
#define AES_SS_AESDMAINTEN_DMADONEDIN  0x2U         // Enable bit for DMADONEDIN
#define AES_SS_AESDMAINTEN_DMADONEDOUT  0x4U         // Enable bit for DMADONEDOUT
#define AES_SS_AESDMAINTEN_DMADONECTXOUT  0x8U         // Enable bit for DMADONECTXOUT

//*****************************************************************************
//
// The following are defines for the bit fields in the AESDMASTATUS register
//
//*****************************************************************************
#define AES_SS_AESDMASTATUS_DMADONECTXIN  0x1U         // Status bit for DMADONECTXIN
#define AES_SS_AESDMASTATUS_DMADONEDIN  0x2U         // Status bit for DMADONEDIN
#define AES_SS_AESDMASTATUS_DMADONEDOUT  0x4U         // Status bit for DMADONEDOUT
#define AES_SS_AESDMASTATUS_DMADONECTXOUT  0x8U         // Status bit for DMADONECTXOUT

//*****************************************************************************
//
// The following are defines for the bit fields in the AESDMASTATUSCLR register
//
//*****************************************************************************
#define AES_SS_AESDMASTATUSCLR_DMADONECTXIN  0x1U         // Clear bit for
                                               // AESDMASTSTAUS.DMADONECTXIN
#define AES_SS_AESDMASTATUSCLR_DMADONEDIN  0x2U         // Clear bit for
                                               // AESDMASTSTAUS.DMADONEDIN
#define AES_SS_AESDMASTATUSCLR_DMADONEDOUT  0x4U         // Clear bit for
                                               // AESDMASTSTAUS.DMADONEDOUT
#define AES_SS_AESDMASTATUSCLR_DMADONECTXOUT  0x8U         // Clear bit for
                                               // AESDMASTSTAUS.DMADONECTXOUT
#endif
