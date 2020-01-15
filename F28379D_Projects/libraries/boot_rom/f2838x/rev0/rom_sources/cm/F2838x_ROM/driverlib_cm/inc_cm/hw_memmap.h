//###########################################################################
//
// FILE:    hw_memmap.h
//
// TITLE:   Macros defining the memory map of the CM4.
//
//###########################################################################
// $Copyright:
// Copyright (C) 2016 Texas Instruments Incorporated - http://www.ti.com/
//
// Redistribution and use in source and binary forms, with or without 
// modification, are permitted provided that the following conditions 
// are met:
// 
//   Redistributions of source code must retain the above copyright 
//   notice, this list of conditions and the following disclaimer.
// 
//   Redistributions in binary form must reproduce the above copyright
//   notice, this list of conditions and the following disclaimer in the 
//   documentation and/or other materials provided with the   
//   distribution.
// 
//   Neither the name of Texas Instruments Incorporated nor the names of
//   its contributors may be used to endorse or promote products derived
//   from this software without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// $
//###########################################################################

#ifndef HW_MEMMAP_H
#define HW_MEMMAP_H

#define WD_BASE                     0x40080000U // Windowed Watchdog Registers
#define NMI_BASE                    0x40081000U // CMNMI Registers
#define CMSYSCTL_BASE               0x400FC000U // CMSystem Config Registers
#define NVIC_BASE                   0xE000E000U // NVIC Registers
#define UDMA_BASE                   0x400FF000U // uDMA Registers
#define UART0_BASE                  0x4000C000U // UART0 Registers
#define SSI0_BASE                   0x40008000U // SSI0 Registers
#define I2C0_BASE                   0x40020000U // I2C0 Registers
#define GCRC_BASE                   0x40040000U // GCRC Registers
#define AES_BASE                    0x4004A000U // AES IP Registers
#define AESW_BASE                   0x4004AC00U // AES Wrapper Registers
#define EMAC_BASE                   0x400C0000U //EMAC
#define EMAC_SS_BASE                0x400C2000U //EMACSS
#define MCAN0_BASE                  0x40078000U //MCAN0
#define CMMEMCFG_BASE               0x400FE000U // CM Mem Init & Test Registers
#define CMMEMORYERROR_BASE          0x400FE400U // CM Error Log Registers
#define CMMEMORYDIAGERROR_BASE      0x400FE800U // CM Diag Error Log Registers
#define C1RAM_BASE                  0x1FFFC000U // C1RAM
#define C0RAM_BASE                  0x1FFFE000U // C0RAM
#define S0RAM_BASE                  0x20000000U // S0RAM
#define S1RAM_BASE                  0x20004000U // S1RAM
#define S2RAM_BASE                  0x20008000U // S2RAM
#define S3RAM_BASE                  0x2000C000U // S3RAM
#define S4RAM_BASE                  0x20010000U // S4RAM
#define CPU1TOCMMSGRAM0_BASE        0x20080000U // CPU1TOCMMSGRAM0
#define CPU1TOCMMSGRAM1_BASE        0x20080800U // CPU1TOCMMSGRAM1
#define CMTOCPU1MSGRAM0_BASE        0x20082000U // CMTOCPU1MSGRAM0
#define CMTOCPU1MSGRAM1_BASE        0x20082800U // CMTOCPU1MSGRAM1
#define CPU2TOCMMSGRAM0_BASE        0x20084000U // CPU2TOCMMSGRAM0
#define CPU2TOCMMSGRAM1_BASE        0x20084800U // CPU2TOCMMSGRAM1
#define CMTOCPU2MSGRAM0_BASE        0x20086000U // CMTOCPU2MSGRAM0
#define CMTOCPU2MSGRAM1_BASE        0x20086800U // CMTOCPU2MSGRAM1
#define DMPU_BASE                   0x400CC000U // uDMA MPU Registers
#define EMPU_BASE                   0x400CD000U // Ethernet MPU Registers
#define CANA_BASE                   0x40070000U // CAN-A Registers
#define CANB_BASE                   0x40074000U // CAN-B Registers
#define IPC_CMTOCPU1_BASE           0x400FD000U
#define IPC_CMTOCPU2_BASE           0x400FD080U
#define DCSM_Z1_BASE                0x40085000U // Zone 1 DCSM Registers
#define DCSM_Z2_BASE                0x40085100U // Zone 2 DCSM Registers
#define DCSMCOMMON_BASE             0x40085180U // Security Registers
#define ECAT_SS_BASE                0x400AFC00U // Ethercat Sub-System Registers
#define ECAT_SS_CONFIG_BASE         0x400AFE00U // Ethercat Sub-System configuration Registers
#define GPIODATA_BASE               0x40083000U // GPIO Data Registers
#define GPIODATAREAD_BASE           0x40083100U // GPIO Data Registers 
#define CPUTIMER0_BASE              0x40084000U // CPUTIMER0 Registers
#define CPUTIMER1_BASE              0x40084010U // CPUTIMER1 Registers
#define CPUTIMER2_BASE              0x40084020U // CPUTIMER2 Registers
#define FLASH0CTRL_BASE             0x400FA000U // Flash control registers
#define FLASH0ECC_BASE              0x400FA600U // Flash ECC error log registers

#endif // HW_MEMMAP_H

