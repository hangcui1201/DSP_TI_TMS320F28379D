//###########################################################################
//
// FILE:    dcsm_otp.h
//
// TITLE:   DCSM Init Header
//
//###########################################################################
// $TI Release: $
// $Release Date:  $
//###########################################################################

#ifndef DCSM_OTP_H_
#define DCSM_OTP_H_

//TI_OTP Definitions

#define SECDC_OTP_TI                    0xFFFFFFE8u //C28SL,ECSL enabled and FASTSPIN applicable

//USER OTP Definitions

// USER OTP BANK 1
//Zone 1: Header

#define B0_Z1_LINKPOINTER1              0x00003FFFu
#define B0_Z1_LINKPOINTER2              0x00003FFFu
#define B0_Z1_LINKPOINTER3              0x00003FFFu
#define Z1_JLM_ENABLE                   0xFFFF000Fu
#define Z1_GPREG1                       0xFFFFFFFFu
#define Z1_GPREG2                       0xFFFFFFFFu
#define Z1_GPREG3                       0xFFFFFFFFu
#define Z1_GPREG4                       0xFFFFFFFFu
#define Z1_PSWDLOCK                     0xFB7FFFFFu
#define Z1_CRCLOCK                      0x7FFFFFFFu
#define JTAGPSWDH0                      0x4BFFFFFFu
#define JTAGPSWDH1                      0x3FFFFFFFu
#define CMAC_KEY0                       0xFFFFFFFFu
#define CMAC_KEY1                       0xFFFFFFFFu
#define CMAC_KEY2                       0xFFFFFFFFu
#define CMAC_KEY3                       0xFFFFFFFFu

//Zone 1: Zone Select Block

//ZONE SELECT BLOCK 0
#define ZSB0_Z1_CSMPSWD0                0xFFFFFFFFu
#define ZSB0_Z1_CSMPSWD1                0x4D7FFFFFu
#define ZSB0_Z1_CSMPSWD2                0xFFFFFFFFu
#define ZSB0_Z1_CSMPSWD3                0xFFFFFFFFu
#define ZSB0_Z1_GRABSECT1               0xFFFFFFFFu
#define ZSB0_Z1_GRABSECT2               0xFFFFFFFFu
#define ZSB0_Z1_GRABSECT3               0xFFFFFFFFu
#define ZSB0_Z1_GRABRAM1                0xFFFFFFFFu
#define ZSB0_Z1_GRABRAM2                0xFFFFFFFFu
#define ZSB0_Z1_GRABRAM3                0xFFFFFFFFu
#define ZSB0_Z1_EXEONLYSECT1            0xFFFFFFFFu
#define ZSB0_Z1_EXEONLYSECT2            0xFFFFFFFFu
#define ZSB0_Z1_EXEONLYRAM1             0xFFFFFFFFu
#define ZSB0_JTAGPSWDL0                 0xFFFFFFFFu
#define ZSB0_JTAGPSWDL1                 0x2BFFFFFFu


//ZONE SELECT BLOCK 1
#define ZSB1_Z1_CSMPSWD0                0xFFFFFFFFu
#define ZSB1_Z1_CSMPSWD1                0x5F7FFFFFu
#define ZSB1_Z1_CSMPSWD2                0xFFFFFFFFu
#define ZSB1_Z1_CSMPSWD3                0xFFFFFFFFu
#define ZSB1_Z1_GRABSECT1               0xFFFFFFFFu
#define ZSB1_Z1_GRABSECT2               0xFFFFFFFFu
#define ZSB1_Z1_GRABSECT3               0xFFFFFFFFu
#define ZSB1_Z1_GRABRAM1                0xFFFFFFFFu
#define ZSB1_Z1_GRABRAM2                0xFFFFFFFFu
#define ZSB1_Z1_GRABRAM3                0xFFFFFFFFu
#define ZSB1_Z1_EXEONLYSECT1            0xFFFFFFFFu
#define ZSB1_Z1_EXEONLYSECT2            0xFFFFFFFFu
#define ZSB1_Z1_EXEONLYRAM1             0xFFFFFFFFu
#define ZSB1_JTAGPSWDL0                 0xFFFFFFFFu
#define ZSB1_JTAGPSWDL1                 0x27FFFFFFu

//ZONE SELECT BLOCK 2
#define ZSB2_Z1_CSMPSWD0                0xFFFFFFFFu
#define ZSB2_Z1_CSMPSWD1                0x1DFFFFFFu
#define ZSB2_Z1_CSMPSWD2                0xFFFFFFFFu
#define ZSB2_Z1_CSMPSWD3                0xFFFFFFFFu
#define ZSB2_Z1_GRABSECT1               0xFFFFFFFFu
#define ZSB2_Z1_GRABSECT2               0xFFFFFFFFu
#define ZSB2_Z1_GRABSECT3               0xFFFFFFFFu
#define ZSB2_Z1_GRABRAM1                0xFFFFFFFFu
#define ZSB2_Z1_GRABRAM2                0xFFFFFFFFu
#define ZSB2_Z1_GRABRAM3                0xFFFFFFFFu
#define ZSB2_Z1_EXEONLYSECT1            0xFFFFFFFFu
#define ZSB2_Z1_EXEONLYSECT2            0xFFFFFFFFu
#define ZSB2_Z1_EXEONLYRAM1             0xFFFFFFFFu
#define ZSB2_JTAGPSWDL0                 0xFFFFFFFFu
#define ZSB2_JTAGPSWDL1                 0x7B7FFFFFu

//ZONE SELECT BLOCK 3
#define ZSB3_Z1_CSMPSWD0                0xFFFFFFFFu
#define ZSB3_Z1_CSMPSWD1                0xAF7FFFFFu
#define ZSB3_Z1_CSMPSWD2                0xFFFFFFFFu
#define ZSB3_Z1_CSMPSWD3                0xFFFFFFFFu
#define ZSB3_Z1_GRABSECT1               0xFFFFFFFFu
#define ZSB3_Z1_GRABSECT2               0xFFFFFFFFu
#define ZSB3_Z1_GRABSECT3               0xFFFFFFFFu
#define ZSB3_Z1_GRABRAM1                0xFFFFFFFFu
#define ZSB3_Z1_GRABRAM2                0xFFFFFFFFu
#define ZSB3_Z1_GRABRAM3                0xFFFFFFFFu
#define ZSB3_Z1_EXEONLYSECT1            0xFFFFFFFFu
#define ZSB3_Z1_EXEONLYSECT2            0xFFFFFFFFu
#define ZSB3_Z1_EXEONLYRAM1             0xFFFFFFFFu
#define ZSB3_JTAGPSWDL0                 0xFFFFFFFFu
#define ZSB3_JTAGPSWDL1                 0xC9FFFFFFu

//ZONE SELECT BLOCK 4
#define ZSB4_Z1_CSMPSWD0                0xFFFFFFFFu
#define ZSB4_Z1_CSMPSWD1                0x1BFFFFFFu
#define ZSB4_Z1_CSMPSWD2                0xFFFFFFFFu
#define ZSB4_Z1_CSMPSWD3                0xFFFFFFFFu
#define ZSB4_Z1_GRABSECT1               0xFFFFFFFFu
#define ZSB4_Z1_GRABSECT2               0xFFFFFFFFu
#define ZSB4_Z1_GRABSECT3               0xFFFFFFFFu
#define ZSB4_Z1_GRABRAM1                0xFFFFFFFFu
#define ZSB4_Z1_GRABRAM2                0xFFFFFFFFu
#define ZSB4_Z1_GRABRAM3                0xFFFFFFFFu
#define ZSB4_Z1_EXEONLYSECT1            0xFFFFFFFFu
#define ZSB4_Z1_EXEONLYSECT2            0xFFFFFFFFu
#define ZSB4_Z1_EXEONLYRAM1             0xFFFFFFFFu
#define ZSB4_JTAGPSWDL0                 0xFFFFFFFFu
#define ZSB4_JTAGPSWDL1                 0x7D7FFFFFu

//ZONE SELECT BLOCK 5
#define ZSB5_Z1_CSMPSWD0                0xFFFFFFFFu
#define ZSB5_Z1_CSMPSWD1                0x17FFFFFFu
#define ZSB5_Z1_CSMPSWD2                0xFFFFFFFFu
#define ZSB5_Z1_CSMPSWD3                0xFFFFFFFFu
#define ZSB5_Z1_GRABSECT1               0xFFFFFFFFu
#define ZSB5_Z1_GRABSECT2               0xFFFFFFFFu
#define ZSB5_Z1_GRABSECT3               0xFFFFFFFFu
#define ZSB5_Z1_GRABRAM1                0xFFFFFFFFu
#define ZSB5_Z1_GRABRAM2                0xFFFFFFFFu
#define ZSB5_Z1_GRABRAM3                0xFFFFFFFFu
#define ZSB5_Z1_EXEONLYSECT1            0xFFFFFFFFu
#define ZSB5_Z1_EXEONLYSECT2            0xFFFFFFFFu
#define ZSB5_Z1_EXEONLYRAM1             0xFFFFFFFFu
#define ZSB5_JTAGPSWDL0                 0xFFFFFFFFu
#define ZSB5_JTAGPSWDL1                 0x6F7FFFFFu

//ZONE SELECT BLOCK 6
#define ZSB6_Z1_CSMPSWD0                0xFFFFFFFFu
#define ZSB6_Z1_CSMPSWD1                0xBD7FFFFFu
#define ZSB6_Z1_CSMPSWD2                0xFFFFFFFFu
#define ZSB6_Z1_CSMPSWD3                0xFFFFFFFFu
#define ZSB6_Z1_GRABSECT1               0xFFFFFFFFu
#define ZSB6_Z1_GRABSECT2               0xFFFFFFFFu
#define ZSB6_Z1_GRABSECT3               0xFFFFFFFFu
#define ZSB6_Z1_GRABRAM1                0xFFFFFFFFu
#define ZSB6_Z1_GRABRAM2                0xFFFFFFFFu
#define ZSB6_Z1_GRABRAM3                0xFFFFFFFFu
#define ZSB6_Z1_EXEONLYSECT1            0xFFFFFFFFu
#define ZSB6_Z1_EXEONLYSECT2            0xFFFFFFFFu
#define ZSB6_Z1_EXEONLYRAM1             0xFFFFFFFFu
#define ZSB6_JTAGPSWDL0                 0xFFFFFFFFu
#define ZSB6_JTAGPSWDL1                 0x33FFFFFFu

//ZONE SELECT BLOCK 7
#define ZSB7_Z1_CSMPSWD0                0xFFFFFFFFu
#define ZSB7_Z1_CSMPSWD1                0x9F7FFFFFu
#define ZSB7_Z1_CSMPSWD2                0xFFFFFFFFu
#define ZSB7_Z1_CSMPSWD3                0xFFFFFFFFu
#define ZSB7_Z1_GRABSECT1               0xFFFFFFFFu
#define ZSB7_Z1_GRABSECT2               0xFFFFFFFFu
#define ZSB7_Z1_GRABSECT3               0xFFFFFFFFu
#define ZSB7_Z1_GRABRAM1                0xFFFFFFFFu
#define ZSB7_Z1_GRABRAM2                0xFFFFFFFFu
#define ZSB7_Z1_GRABRAM3                0xFFFFFFFFu
#define ZSB7_Z1_EXEONLYSECT1            0xFFFFFFFFu
#define ZSB7_Z1_EXEONLYSECT2            0xFFFFFFFFu
#define ZSB7_Z1_EXEONLYRAM1             0xFFFFFFFFu
#define ZSB7_JTAGPSWDL0                 0xFFFFFFFFu
#define ZSB7_JTAGPSWDL1                 0x0FFFFFFFu

//ZONE SELECT BLOCK 8
#define ZSB8_Z1_CSMPSWD0                0xFFFFFFFFu
#define ZSB8_Z1_CSMPSWD1                0x2BFFFFFFu
#define ZSB8_Z1_CSMPSWD2                0xFFFFFFFFu
#define ZSB8_Z1_CSMPSWD3                0xFFFFFFFFu
#define ZSB8_Z1_GRABSECT1               0xFFFFFFFFu
#define ZSB8_Z1_GRABSECT2               0xFFFFFFFFu
#define ZSB8_Z1_GRABSECT3               0xFFFFFFFFu
#define ZSB8_Z1_GRABRAM1                0xFFFFFFFFu
#define ZSB8_Z1_GRABRAM2                0xFFFFFFFFu
#define ZSB8_Z1_GRABRAM3                0xFFFFFFFFu
#define ZSB8_Z1_EXEONLYSECT1            0xFFFFFFFFu
#define ZSB8_Z1_EXEONLYSECT2            0xFFFFFFFFu
#define ZSB8_Z1_EXEONLYRAM1             0xFFFFFFFFu
#define ZSB8_JTAGPSWDL0                 0xFFFFFFFFu
#define ZSB8_JTAGPSWDL1                 0xBB7FFFFFu

//ZONE SELECT BLOCK 9
#define ZSB9_Z1_CSMPSWD0                0xFFFFFFFFu
#define ZSB9_Z1_CSMPSWD1                0x27FFFFFFu
#define ZSB9_Z1_CSMPSWD2                0xFFFFFFFFu
#define ZSB9_Z1_CSMPSWD3                0xFFFFFFFFu
#define ZSB9_Z1_GRABSECT1               0xFFFFFFFFu
#define ZSB9_Z1_GRABSECT2               0xFFFFFFFFu
#define ZSB9_Z1_GRABSECT3               0xFFFFFFFFu
#define ZSB9_Z1_GRABRAM1                0xFFFFFFFFu
#define ZSB9_Z1_GRABRAM2                0xFFFFFFFFu
#define ZSB9_Z1_GRABRAM3                0xFFFFFFFFu
#define ZSB9_Z1_EXEONLYSECT1            0xFFFFFFFFu
#define ZSB9_Z1_EXEONLYSECT2            0xFFFFFFFFu
#define ZSB9_Z1_EXEONLYRAM1             0xFFFFFFFFu
#define ZSB9_JTAGPSWDL0                 0xFFFFFFFFu
#define ZSB9_JTAGPSWDL1                 0x5F7FFFFFu

//ZONE SELECT BLOCK 10
#define ZSB10_Z1_CSMPSWD0               0xFFFFFFFFu
#define ZSB10_Z1_CSMPSWD1               0x7B7FFFFFu
#define ZSB10_Z1_CSMPSWD2               0xFFFFFFFFu
#define ZSB10_Z1_CSMPSWD3               0xFFFFFFFFu
#define ZSB10_Z1_GRABSECT1              0xFFFFFFFFu
#define ZSB10_Z1_GRABSECT2              0xFFFFFFFFu
#define ZSB10_Z1_GRABSECT3              0xFFFFFFFFu
#define ZSB10_Z1_GRABRAM1               0xFFFFFFFFu
#define ZSB10_Z1_GRABRAM2               0xFFFFFFFFu
#define ZSB10_Z1_GRABRAM3               0xFFFFFFFFu
#define ZSB10_Z1_EXEONLYSECT1           0xFFFFFFFFu
#define ZSB10_Z1_EXEONLYSECT2           0xFFFFFFFFu
#define ZSB10_Z1_EXEONLYRAM1            0xFFFFFFFFu
#define ZSB10_JTAGPSWDL0                0xFFFFFFFFu
#define ZSB10_JTAGPSWDL1                0x1DFFFFFFu

//ZONE SELECT BLOCK 11
#define ZSB11_Z1_CSMPSWD0               0xFFFFFFFFu
#define ZSB11_Z1_CSMPSWD1               0xC9FFFFFFu
#define ZSB11_Z1_CSMPSWD2               0xFFFFFFFFu
#define ZSB11_Z1_CSMPSWD3               0xFFFFFFFFu
#define ZSB11_Z1_GRABSECT1              0xFFFFFFFFu
#define ZSB11_Z1_GRABSECT2              0xFFFFFFFFu
#define ZSB11_Z1_GRABSECT3              0xFFFFFFFFu
#define ZSB11_Z1_GRABRAM1               0xFFFFFFFFu
#define ZSB11_Z1_GRABRAM2               0xFFFFFFFFu
#define ZSB11_Z1_GRABRAM3               0xFFFFFFFFu
#define ZSB11_Z1_EXEONLYSECT1           0xFFFFFFFFu
#define ZSB11_Z1_EXEONLYSECT2           0xFFFFFFFFu
#define ZSB11_Z1_EXEONLYRAM1            0xFFFFFFFFu
#define ZSB11_JTAGPSWDL0                0xFFFFFFFFu
#define ZSB11_JTAGPSWDL1                0xAF7FFFFFu

//ZONE SELECT BLOCK 12
#define ZSB12_Z1_CSMPSWD0               0xFFFFFFFFu
#define ZSB12_Z1_CSMPSWD1               0x7D7FFFFFu
#define ZSB12_Z1_CSMPSWD2               0xFFFFFFFFu
#define ZSB12_Z1_CSMPSWD3               0xFFFFFFFFu
#define ZSB12_Z1_GRABSECT1              0xFFFFFFFFu
#define ZSB12_Z1_GRABSECT2              0xFFFFFFFFu
#define ZSB12_Z1_GRABSECT3              0xFFFFFFFFu
#define ZSB12_Z1_GRABRAM1               0xFFFFFFFFu
#define ZSB12_Z1_GRABRAM2               0xFFFFFFFFu
#define ZSB12_Z1_GRABRAM3               0xFFFFFFFFu
#define ZSB12_Z1_EXEONLYSECT1           0xFFFFFFFFu
#define ZSB12_Z1_EXEONLYSECT2           0xFFFFFFFFu
#define ZSB12_Z1_EXEONLYRAM1            0xFFFFFFFFu
#define ZSB12_JTAGPSWDL0                0xFFFFFFFFu
#define ZSB12_JTAGPSWDL1                0x1BFFFFFFu

//ZONE SELECT BLOCK 13
#define ZSB13_Z1_CSMPSWD0               0xFFFFFFFFu
#define ZSB13_Z1_CSMPSWD1               0x6F7FFFFFu
#define ZSB13_Z1_CSMPSWD2               0xFFFFFFFFu
#define ZSB13_Z1_CSMPSWD3               0xFFFFFFFFu
#define ZSB13_Z1_GRABSECT1              0xFFFFFFFFu
#define ZSB13_Z1_GRABSECT2              0xFFFFFFFFu
#define ZSB13_Z1_GRABSECT3              0xFFFFFFFFu
#define ZSB13_Z1_GRABRAM1               0xFFFFFFFFu
#define ZSB13_Z1_GRABRAM2               0xFFFFFFFFu
#define ZSB13_Z1_GRABRAM3               0xFFFFFFFFu
#define ZSB13_Z1_EXEONLYSECT1           0xFFFFFFFFu
#define ZSB13_Z1_EXEONLYSECT2           0xFFFFFFFFu
#define ZSB13_Z1_EXEONLYRAM1            0xFFFFFFFFu
#define ZSB13_JTAGPSWDL0                0xFFFFFFFFu
#define ZSB13_JTAGPSWDL1                0x17FFFFFFu

//ZONE SELECT BLOCK 14
#define ZSB14_Z1_CSMPSWD0               0xFFFFFFFFu
#define ZSB14_Z1_CSMPSWD1               0x33FFFFFFu
#define ZSB14_Z1_CSMPSWD2               0xFFFFFFFFu
#define ZSB14_Z1_CSMPSWD3               0xFFFFFFFFu
#define ZSB14_Z1_GRABSECT1              0xFFFFFFFFu
#define ZSB14_Z1_GRABSECT2              0xFFFFFFFFu
#define ZSB14_Z1_GRABSECT3              0xFFFFFFFFu
#define ZSB14_Z1_GRABRAM1               0xFFFFFFFFu
#define ZSB14_Z1_GRABRAM2               0xFFFFFFFFu
#define ZSB14_Z1_GRABRAM3               0xFFFFFFFFu
#define ZSB14_Z1_EXEONLYSECT1           0xFFFFFFFFu
#define ZSB14_Z1_EXEONLYSECT2           0xFFFFFFFFu
#define ZSB14_Z1_EXEONLYRAM1            0xFFFFFFFFu
#define ZSB14_JTAGPSWDL0                0xFFFFFFFFu
#define ZSB14_JTAGPSWDL1                0xBD7FFFFFu


//Zone 2: Header

#define B0_Z2_LINKPOINTER1              0x00003FFFu
#define B0_Z2_LINKPOINTER2              0x00003FFFu
#define B0_Z2_LINKPOINTER3              0x00003FFFu
#define Z2_GPREG1                       0xFFFFFFFFu
#define Z2_GPREG2                       0xFFFFFFFFu
#define Z2_GPREG3                       0xFFFFFFFFu
#define Z2_GPREG4                       0xFFFFFFFFu
#define Z2_PSWDLOCK                     0x1F7FFFFFu
#define Z2_CRCLOCK                      0x3FFFFFFFu

//Zone 2: Zone Select Block

//ZONE SELECT BLOCK 0
#define ZSB0_Z2_CSMPSWD0                0xFFFFFFFFu
#define ZSB0_Z2_CSMPSWD1                0x1F7FFFFFu
#define ZSB0_Z2_CSMPSWD2                0xFFFFFFFFu
#define ZSB0_Z2_CSMPSWD3                0xFFFFFFFFu
#define ZSB0_Z2_GRABSECT1               0xFFFFFFFFu
#define ZSB0_Z2_GRABSECT2               0xFFFFFFFFu
#define ZSB0_Z2_GRABSECT3               0xFFFFFFFFu
#define ZSB0_Z2_GRABRAM1                0xFFFFFFFFu
#define ZSB0_Z2_GRABRAM2                0xFFFFFFFFu
#define ZSB0_Z2_GRABRAM3                0xFFFFFFFFu
#define ZSB0_Z2_EXEONLYSECT1            0xFFFFFFFFu
#define ZSB0_Z2_EXEONLYSECT2            0xFFFFFFFFu
#define ZSB0_Z2_EXEONLYRAM1             0xFFFFFFFFu

//ZONE SELECT BLOCK 1
#define ZSB1_Z2_CSMPSWD0                0xFFFFFFFFu
#define ZSB1_Z2_CSMPSWD1                0xE57FFFFFu
#define ZSB1_Z2_CSMPSWD2                0xFFFFFFFFu
#define ZSB1_Z2_CSMPSWD3                0xFFFFFFFFu
#define ZSB1_Z2_GRABSECT1               0xFFFFFFFFu
#define ZSB1_Z2_GRABSECT2               0xFFFFFFFFu
#define ZSB1_Z2_GRABSECT3               0xFFFFFFFFu
#define ZSB1_Z2_GRABRAM1                0xFFFFFFFFu
#define ZSB1_Z2_GRABRAM2                0xFFFFFFFFu
#define ZSB1_Z2_GRABRAM3                0xFFFFFFFFu
#define ZSB1_Z2_EXEONLYSECT1            0xFFFFFFFFu
#define ZSB1_Z2_EXEONLYSECT2            0xFFFFFFFFu
#define ZSB1_Z2_EXEONLYRAM1             0xFFFFFFFFu

//ZONE SELECT BLOCK 2
#define ZSB2_Z2_CSMPSWD0                0xFFFFFFFFu
#define ZSB2_Z2_CSMPSWD1                0x4FFFFFFFu
#define ZSB2_Z2_CSMPSWD2                0xFFFFFFFFu
#define ZSB2_Z2_CSMPSWD3                0xFFFFFFFFu
#define ZSB2_Z2_GRABSECT1               0xFFFFFFFFu
#define ZSB2_Z2_GRABSECT2               0xFFFFFFFFu
#define ZSB2_Z2_GRABSECT3               0xFFFFFFFFu
#define ZSB2_Z2_GRABRAM1                0xFFFFFFFFu
#define ZSB2_Z2_GRABRAM2                0xFFFFFFFFu
#define ZSB2_Z2_GRABRAM3                0xFFFFFFFFu
#define ZSB2_Z2_EXEONLYSECT1            0xFFFFFFFFu
#define ZSB2_Z2_EXEONLYSECT2            0xFFFFFFFFu
#define ZSB2_Z2_EXEONLYRAM1             0xFFFFFFFFu

//ZONE SELECT BLOCK 3
#define ZSB3_Z2_CSMPSWD0                0xFFFFFFFFu
#define ZSB3_Z2_CSMPSWD1                0xE37FFFFFu
#define ZSB3_Z2_CSMPSWD2                0xFFFFFFFFu
#define ZSB3_Z2_CSMPSWD3                0xFFFFFFFFu
#define ZSB3_Z2_GRABSECT1               0xFFFFFFFFu
#define ZSB3_Z2_GRABSECT2               0xFFFFFFFFu
#define ZSB3_Z2_GRABSECT3               0xFFFFFFFFu
#define ZSB3_Z2_GRABRAM1                0xFFFFFFFFu
#define ZSB3_Z2_GRABRAM2                0xFFFFFFFFu
#define ZSB3_Z2_GRABRAM3                0xFFFFFFFFu
#define ZSB3_Z2_EXEONLYSECT1            0xFFFFFFFFu
#define ZSB3_Z2_EXEONLYSECT2            0xFFFFFFFFu
#define ZSB3_Z2_EXEONLYRAM1             0xFFFFFFFFu

//ZONE SELECT BLOCK 4
#define ZSB4_Z2_CSMPSWD0                0xFFFFFFFFu
#define ZSB4_Z2_CSMPSWD1                0x57FFFFFFu
#define ZSB4_Z2_CSMPSWD2                0xFFFFFFFFu
#define ZSB4_Z2_CSMPSWD3                0xFFFFFFFFu
#define ZSB4_Z2_GRABSECT1               0xFFFFFFFFu
#define ZSB4_Z2_GRABSECT2               0xFFFFFFFFu
#define ZSB4_Z2_GRABSECT3               0xFFFFFFFFu
#define ZSB4_Z2_GRABRAM1                0xFFFFFFFFu
#define ZSB4_Z2_GRABRAM2                0xFFFFFFFFu
#define ZSB4_Z2_GRABRAM3                0xFFFFFFFFu
#define ZSB4_Z2_EXEONLYSECT1            0xFFFFFFFFu
#define ZSB4_Z2_EXEONLYSECT2            0xFFFFFFFFu
#define ZSB4_Z2_EXEONLYRAM1             0xFFFFFFFFu

//ZONE SELECT BLOCK 5
#define ZSB5_Z2_CSMPSWD0                0xFFFFFFFFu
#define ZSB5_Z2_CSMPSWD1                0x5BFFFFFFu
#define ZSB5_Z2_CSMPSWD2                0xFFFFFFFFu
#define ZSB5_Z2_CSMPSWD3                0xFFFFFFFFu
#define ZSB5_Z2_GRABSECT1               0xFFFFFFFFu
#define ZSB5_Z2_GRABSECT2               0xFFFFFFFFu
#define ZSB5_Z2_GRABSECT3               0xFFFFFFFFu
#define ZSB5_Z2_GRABRAM1                0xFFFFFFFFu
#define ZSB5_Z2_GRABRAM2                0xFFFFFFFFu
#define ZSB5_Z2_GRABRAM3                0xFFFFFFFFu
#define ZSB5_Z2_EXEONLYSECT1            0xFFFFFFFFu
#define ZSB5_Z2_EXEONLYSECT2            0xFFFFFFFFu
#define ZSB5_Z2_EXEONLYRAM1             0xFFFFFFFFu

//ZONE SELECT BLOCK 6
#define ZSB6_Z2_CSMPSWD0                0xFFFFFFFFu
#define ZSB6_Z2_CSMPSWD1                0xF17FFFFFu
#define ZSB6_Z2_CSMPSWD2                0xFFFFFFFFu
#define ZSB6_Z2_CSMPSWD3                0xFFFFFFFFu
#define ZSB6_Z2_GRABSECT1               0xFFFFFFFFu
#define ZSB6_Z2_GRABSECT2               0xFFFFFFFFu
#define ZSB6_Z2_GRABSECT3               0xFFFFFFFFu
#define ZSB6_Z2_GRABRAM1                0xFFFFFFFFu
#define ZSB6_Z2_GRABRAM2                0xFFFFFFFFu
#define ZSB6_Z2_GRABRAM3                0xFFFFFFFFu
#define ZSB6_Z2_EXEONLYSECT1            0xFFFFFFFFu
#define ZSB6_Z2_EXEONLYSECT2            0xFFFFFFFFu
#define ZSB6_Z2_EXEONLYRAM1             0xFFFFFFFFu

//ZONE SELECT BLOCK 7
#define ZSB7_Z2_CSMPSWD0                0xFFFFFFFFu
#define ZSB7_Z2_CSMPSWD1                0x3B7FFFFFu
#define ZSB7_Z2_CSMPSWD2                0xFFFFFFFFu
#define ZSB7_Z2_CSMPSWD3                0xFFFFFFFFu
#define ZSB7_Z2_GRABSECT1               0xFFFFFFFFu
#define ZSB7_Z2_GRABSECT2               0xFFFFFFFFu
#define ZSB7_Z2_GRABSECT3               0xFFFFFFFFu
#define ZSB7_Z2_GRABRAM1                0xFFFFFFFFu
#define ZSB7_Z2_GRABRAM2                0xFFFFFFFFu
#define ZSB7_Z2_GRABRAM3                0xFFFFFFFFu
#define ZSB7_Z2_EXEONLYSECT1            0xFFFFFFFFu
#define ZSB7_Z2_EXEONLYSECT2            0xFFFFFFFFu
#define ZSB7_Z2_EXEONLYRAM1             0xFFFFFFFFu

//ZONE SELECT BLOCK 8
#define ZSB8_Z2_CSMPSWD0                0xFFFFFFFFu
#define ZSB8_Z2_CSMPSWD1                0x8FFFFFFFu
#define ZSB8_Z2_CSMPSWD2                0xFFFFFFFFu
#define ZSB8_Z2_CSMPSWD3                0xFFFFFFFFu
#define ZSB8_Z2_GRABSECT1               0xFFFFFFFFu
#define ZSB8_Z2_GRABSECT2               0xFFFFFFFFu
#define ZSB8_Z2_GRABSECT3               0xFFFFFFFFu
#define ZSB8_Z2_GRABRAM1                0xFFFFFFFFu
#define ZSB8_Z2_GRABRAM2                0xFFFFFFFFu
#define ZSB8_Z2_GRABRAM3                0xFFFFFFFFu
#define ZSB8_Z2_EXEONLYSECT1            0xFFFFFFFFu
#define ZSB8_Z2_EXEONLYSECT2            0xFFFFFFFFu
#define ZSB8_Z2_EXEONLYRAM1             0xFFFFFFFFu

//ZONE SELECT BLOCK 9
#define ZSB9_Z2_CSMPSWD0                0xFFFFFFFFu
#define ZSB9_Z2_CSMPSWD1                0x6BFFFFFFu
#define ZSB9_Z2_CSMPSWD2                0xFFFFFFFFu
#define ZSB9_Z2_CSMPSWD3                0xFFFFFFFFu
#define ZSB9_Z2_GRABSECT1               0xFFFFFFFFu
#define ZSB9_Z2_GRABSECT2               0xFFFFFFFFu
#define ZSB9_Z2_GRABSECT3               0xFFFFFFFFu
#define ZSB9_Z2_GRABRAM1                0xFFFFFFFFu
#define ZSB9_Z2_GRABRAM2                0xFFFFFFFFu
#define ZSB9_Z2_GRABRAM3                0xFFFFFFFFu
#define ZSB9_Z2_EXEONLYSECT1            0xFFFFFFFFu
#define ZSB9_Z2_EXEONLYSECT2            0xFFFFFFFFu
#define ZSB9_Z2_EXEONLYRAM1             0xFFFFFFFFu

//ZONE SELECT BLOCK 10
#define ZSB10_Z2_CSMPSWD0               0xFFFFFFFFu
#define ZSB10_Z2_CSMPSWD1               0x377FFFFFu
#define ZSB10_Z2_CSMPSWD2               0xFFFFFFFFu
#define ZSB10_Z2_CSMPSWD3               0xFFFFFFFFu
#define ZSB10_Z2_GRABSECT1              0xFFFFFFFFu
#define ZSB10_Z2_GRABSECT2              0xFFFFFFFFu
#define ZSB10_Z2_GRABSECT3              0xFFFFFFFFu
#define ZSB10_Z2_GRABRAM1               0xFFFFFFFFu
#define ZSB10_Z2_GRABRAM2               0xFFFFFFFFu
#define ZSB10_Z2_GRABRAM3               0xFFFFFFFFu
#define ZSB10_Z2_EXEONLYSECT1           0xFFFFFFFFu
#define ZSB10_Z2_EXEONLYSECT2           0xFFFFFFFFu
#define ZSB10_Z2_EXEONLYRAM1            0xFFFFFFFFu

//ZONE SELECT BLOCK 11
#define ZSB11_Z2_CSMPSWD0               0xFFFFFFFFu
#define ZSB11_Z2_CSMPSWD1               0x9BFFFFFFu
#define ZSB11_Z2_CSMPSWD2               0xFFFFFFFFu
#define ZSB11_Z2_CSMPSWD3               0xFFFFFFFFu
#define ZSB11_Z2_GRABSECT1              0xFFFFFFFFu
#define ZSB11_Z2_GRABSECT2              0xFFFFFFFFu
#define ZSB11_Z2_GRABSECT3              0xFFFFFFFFu
#define ZSB11_Z2_GRABRAM1               0xFFFFFFFFu
#define ZSB11_Z2_GRABRAM2               0xFFFFFFFFu
#define ZSB11_Z2_GRABRAM3               0xFFFFFFFFu
#define ZSB11_Z2_EXEONLYSECT1           0xFFFFFFFFu
#define ZSB11_Z2_EXEONLYSECT2           0xFFFFFFFFu
#define ZSB11_Z2_EXEONLYRAM1            0xFFFFFFFFu

//ZONE SELECT BLOCK 12
#define ZSB12_Z2_CSMPSWD0               0xFFFFFFFFu
#define ZSB12_Z2_CSMPSWD1               0x2F7FFFFFu
#define ZSB12_Z2_CSMPSWD2               0xFFFFFFFFu
#define ZSB12_Z2_CSMPSWD3               0xFFFFFFFFu
#define ZSB12_Z2_GRABSECT1              0xFFFFFFFFu
#define ZSB12_Z2_GRABSECT2              0xFFFFFFFFu
#define ZSB12_Z2_GRABSECT3              0xFFFFFFFFu
#define ZSB12_Z2_GRABRAM1               0xFFFFFFFFu
#define ZSB12_Z2_GRABRAM2               0xFFFFFFFFu
#define ZSB12_Z2_GRABRAM3               0xFFFFFFFFu
#define ZSB12_Z2_EXEONLYSECT1           0xFFFFFFFFu
#define ZSB12_Z2_EXEONLYSECT2           0xFFFFFFFFu
#define ZSB12_Z2_EXEONLYRAM1            0xFFFFFFFFu

//ZONE SELECT BLOCK 13
#define ZSB13_Z2_CSMPSWD0               0xFFFFFFFFu
#define ZSB13_Z2_CSMPSWD1               0xCB7FFFFFu
#define ZSB13_Z2_CSMPSWD2               0xFFFFFFFFu
#define ZSB13_Z2_CSMPSWD3               0xFFFFFFFFu
#define ZSB13_Z2_GRABSECT1              0xFFFFFFFFu
#define ZSB13_Z2_GRABSECT2              0xFFFFFFFFu
#define ZSB13_Z2_GRABSECT3              0xFFFFFFFFu
#define ZSB13_Z2_GRABRAM1               0xFFFFFFFFu
#define ZSB13_Z2_GRABRAM2               0xFFFFFFFFu
#define ZSB13_Z2_GRABRAM3               0xFFFFFFFFu
#define ZSB13_Z2_EXEONLYSECT1           0xFFFFFFFFu
#define ZSB13_Z2_EXEONLYSECT2           0xFFFFFFFFu
#define ZSB13_Z2_EXEONLYRAM1            0xFFFFFFFFu

//ZONE SELECT BLOCK 14
#define ZSB14_Z2_CSMPSWD0               0xFFFFFFFFu
#define ZSB14_Z2_CSMPSWD1               0x97FFFFFFu
#define ZSB14_Z2_CSMPSWD2               0xFFFFFFFFu
#define ZSB14_Z2_CSMPSWD3               0xFFFFFFFFu
#define ZSB14_Z2_GRABSECT1              0xFFFFFFFFu
#define ZSB14_Z2_GRABSECT2              0xFFFFFFFFu
#define ZSB14_Z2_GRABSECT3              0xFFFFFFFFu
#define ZSB14_Z2_GRABRAM1               0xFFFFFFFFu
#define ZSB14_Z2_GRABRAM2               0xFFFFFFFFu
#define ZSB14_Z2_GRABRAM3               0xFFFFFFFFu
#define ZSB14_Z2_EXEONLYSECT1           0xFFFFFFFFu
#define ZSB14_Z2_EXEONLYSECT2           0xFFFFFFFFu
#define ZSB14_Z2_EXEONLYRAM1            0xFFFFFFFFu


#define TIOTP1_SECDC                    0x000703F0u     // TI OTP SECDC Location

//DCSM ZSB Offsets
#define ZSB0                            0x20u
#define ZSB1                            0x40u
#define ZSB2                            0x60u
#define ZSB3                            0x80u
#define ZSB4                            0xA0u
#define ZSB5                            0xC0u
#define ZSB6                            0xE0u
#define ZSB7                            0x100u
#define ZSB8                            0x120u
#define ZSB9                            0x140u
#define ZSB10                           0x160u
#define ZSB11                           0x180u
#define ZSB12                           0x1A0u
#define ZSB13                           0x1C0u
#define ZSB14                           0x1E0u

#define LS0_START           0x00008000      // Local Shared Memories between CLA and CPU
#define LS1_START           0x00008800      // Local Shared Memories between CLA and CPU
#define LS2_START           0x00009000      // Local Shared Memories between CLA and CPU
#define LS3_START           0x00009800      // Local Shared Memories between CLA and CPU
#define LS4_START           0x0000A000      // Local Shared Memories between CLA and CPU
#define LS5_START           0x0000A800      // Local Shared Memories between CLA and CPU
#define LS6_START           0x0000B000      // Local Shared Memories between CLA and CPU
#define LS7_START           0x0000B800      // Local Shared Memories between CLA and CPU

#define D0_START            0x0000C000      // Dedicated Memory for CPU
#define D1_START            0x0000C800      // Dedicated Memory for CPU

#define GS0_START           0x0000D000      // Global Shared Memories
#define GS1_START           0x0000E000      // Global Shared Memories
#define GS2_START           0x0000F000      // Global Shared Memories
#define GS3_START           0x00010000      // Global Shared Memories
#define GS4_START           0x00011000      // Global Shared Memories
#define GS5_START           0x00012000      // Global Shared Memories
#define GS6_START           0x00013000      // Global Shared Memories
#define GS7_START           0x00014000      // Global Shared Memories
#define GS8_START           0x00015000      // Global Shared Memories
#define GS9_START           0x00016000      // Global Shared Memories
#define GS10_START          0x00017000      // Global Shared Memories
#define GS11_START          0x00018000      // Global Shared Memories
#define GS12_START          0x00019000      // Global Shared Memories
#define GS13_START          0x0001A000      // Global Shared Memories
#define GS14_START          0x0001B000      // Global Shared Memories
#define GS15_START          0x0001C000      // Global Shared Memories

#define M0_START            0x00000000      // CPU M0 Memory
#define M1_START            0x00000400      // CPU M1 Memory

#define LS0_END             0x000087FF      // Local Shared Memories between CLA and CPU
#define LS1_END             0x00008FFF      // Local Shared Memories between CLA and CPU
#define LS2_END             0x000097FF      // Local Shared Memories between CLA and CPU
#define LS3_END             0x00009FFF      // Local Shared Memories between CLA and CPU
#define LS4_END             0x0000A7FF      // Local Shared Memories between CLA and CPU
#define LS5_END             0x0000AFFF      // Local Shared Memories between CLA and CPU
#define LS6_END             0x0000B7FF      // Local Shared Memories between CLA and CPU
#define LS7_END             0x0000BFFF      // Local Shared Memories between CLA and CPU

#define D0_END              0x0000C7FF      // Dedicated Memory for CPU
#define D1_END              0x0000CFFF      // Dedicated Memory for CPU

#define GS0_END             0x0000DFFF      // Global Shared Memories
#define GS1_END             0x0000EFFF      // Global Shared Memories
#define GS2_END             0x0000FFFF      // Global Shared Memories
#define GS3_END             0x00010FFF      // Global Shared Memories
#define GS4_END             0x00011FFF      // Global Shared Memories
#define GS5_END             0x00012FFF      // Global Shared Memories
#define GS6_END             0x00013FFF      // Global Shared Memories
#define GS7_END             0x00014FFF      // Global Shared Memories
#define GS8_END             0x00015FFF      // Global Shared Memories
#define GS9_END             0x00016FFF      // Global Shared Memories
#define GS10_END            0x00017FFF      // Global Shared Memories
#define GS11_END            0x00018FFF      // Global Shared Memories
#define GS12_END            0x00019FFF      // Global Shared Memories
#define GS13_END            0x0001AFFF      // Global Shared Memories
#define GS14_END            0x0001BFFF      // Global Shared Memories
#define GS15_END            0x0001CFFF      // Global Shared Memories

#define M0_END              0x000003FF      // CPU M0 Memory
#define M1_END              0x000007FF      // CPU M1 Memory

//DCSM ZSB Content Offsets
#define DCSM_O_Zx_CSMPSWD0              0x0
#define DCSM_O_Zx_CSMPSWD1              0x2
#define DCSM_O_Zx_CSMPSWD2              0x4
#define DCSM_O_Zx_CSMPSWD3              0x6
#define DCSM_O_Zx_GRABSECT1             0x8
#define DCSM_O_Zx_GRABSECT2             0xA
#define DCSM_O_Zx_GRABSECT3             0xC
#define DCSM_O_Zx_GRABRAM1              0xE
#define DCSM_O_Zx_GRABRAM2              0x10
#define DCSM_O_Zx_GRABRAM3              0x12
#define DCSM_O_Zx_EXEONLYSECT1          0x14
#define DCSM_O_Zx_EXEONLYSECT2          0x16
#define DCSM_O_Zx_EXEONLYRAM1           0x18
#define DCSM_O_Z1_JTAGPSWDL0            0x1C
#define DCSM_O_Z1_JTAGPSWDL1            0x1E

#define ZONE1_CSMKEY0   0xFFFFFFFF
#define ZONE1_CSMKEY1   0x4D7FFFFF
#define ZONE1_CSMKEY2   0xFFFFFFFF
#define ZONE1_CSMKEY3   0xFFFFFFFF
#define ZONE2_CSMKEY0   0xFFFFFFFF
#define ZONE2_CSMKEY1   0x1F7FFFFF
#define ZONE2_CSMKEY2   0xFFFFFFFF
#define ZONE2_CSMKEY3   0xFFFFFFFF

#define SYSCTL_WD_CHKBITS       0x0028U

#endif /*  DCSM_OTP_H_  */



