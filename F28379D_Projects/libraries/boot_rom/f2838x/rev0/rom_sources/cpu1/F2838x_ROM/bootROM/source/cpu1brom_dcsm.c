//###########################################################################
//
// FILE:    cpu1brom_dcsm.c
//
// TITLE:   DCSM Initialization
//
//###########################################################################
// $TI Release:  $
// $Release Date: $
//###########################################################################

//
// Included Files
//
#include "cpu1bootrom.h"
#include "dcsm_otp.h"

//
// Globals
//
uint32_t Z1_ZSB;
uint32_t Z2_ZSB;
uint32_t z1_key1;
uint32_t z2_key1;

const uint32_t dcsm_default_keys_z1[] = {
        0x4d7fffff,         //Z1-ZSB0-CSMPSWD1
        0x5f7fffff,         //Z1-ZSB1-CSMPSWD1
        0x1dffffff,         //Z1-ZSB2-CSMPSWD1
        0xaf7fffff,         //Z1-ZSB3-CSMPSWD1
        0x1bffffff,         //Z1-ZSB4-CSMPSWD1
        0x17ffffff,         //Z1-ZSB5-CSMPSWD1
        0xbd7fffff,         //Z1-ZSB6-CSMPSWD1
        0x9f7fffff,         //Z1-ZSB7-CSMPSWD1
        0x2bffffff,         //Z1-ZSB8-CSMPSWD1
        0x27ffffff,         //Z1-ZSB9-CSMPSWD1
        0x7b7fffff,         //Z1-ZSB10-CSMPSWD1
        0xc9ffffff,         //Z1-ZSB11-CSMPSWD1
        0x7d7fffff,         //Z1-ZSB12-CSMPSWD1
        0x6f7fffff,         //Z1-ZSB13-CSMPSWD1
        0x33ffffff          //Z1-ZSB14-CSMPSWD1
};

const uint32_t dcsm_default_keys_z2[] = {
        0x1f7fffff,         //Z2-ZSB0-CSMPSWD1
        0xe57fffff,         //Z2-ZSB1-CSMPSWD1
        0x4fffffff,         //Z2-ZSB2-CSMPSWD1
        0xe37fffff,         //Z2-ZSB3-CSMPSWD1
        0x57ffffff,         //Z2-ZSB4-CSMPSWD1
        0x5bffffff,         //Z2-ZSB5-CSMPSWD1
        0xf17fffff,         //Z2-ZSB6-CSMPSWD1
        0x3b7fffff,         //Z2-ZSB7-CSMPSWD1
        0x8fffffff,         //Z2-ZSB8-CSMPSWD1
        0x6bffffff,         //Z2-ZSB9-CSMPSWD1
        0x377fffff,         //Z2-ZSB10-CSMPSWD1
        0x9bffffff,         //Z2-ZSB11-CSMPSWD1
        0x2f7fffff,         //Z2-ZSB12-CSMPSWD1
        0xcb7fffff,         //Z2-ZSB13-CSMPSWD1
        0x97ffffff          //Z2-ZSB14-CSMPSWD1
};

//
// Function Prototypes
//
uint32_t Gather_Z1_ZSB(void);
uint32_t Gather_Z2_ZSB(void);
void InitDCSM(void);

//
// CPU1BROM_initDCSM - This function initializes code security module, until this
//                     function is executed all access to RAM and JTAG is blocked.
//
void CPU1BROM_initDCSM(void)
{
    Z1_ZSB = 0x0;
    Z2_ZSB = 0x0;
    z1_key1 = 0;
    z2_key1 = 0;

    EALLOW;

    HWREG(DCSM_Z1OTP_BASE + DCSM_O_Z1OTP_LINKPOINTER1); //Zone 1 Contents
    HWREG(DCSM_Z1OTP_BASE + DCSM_O_Z1OTP_LINKPOINTER2);
    HWREG(DCSM_Z1OTP_BASE + DCSM_O_Z1OTP_LINKPOINTER3);

    HWREG(DCSM_Z2OTP_BASE + DCSM_O_Z2OTP_LINKPOINTER1); //Zone 2 Contents
    HWREG(DCSM_Z2OTP_BASE + DCSM_O_Z2OTP_LINKPOINTER2);
    HWREG(DCSM_Z2OTP_BASE + DCSM_O_Z2OTP_LINKPOINTER3);

    HWREG(TIOTP1_SECDC);    // TI OTP SECDC register read

    //
    // OTPSECLOCK and other boot related register reads from
    // Zone 1 and Zone 2 of USER OTP
    //
    HWREG(DCSM_Z1OTP_BASE + DCSM_O_Z1OTP_JLM_ENABLE);
    HWREG(DCSM_Z1OTP_BASE + DCSM_O_Z1OTP_PSWDLOCK);
    HWREG(DCSM_Z1OTP_BASE + DCSM_O_Z1OTP_CRCLOCK);
    HWREG(DCSM_Z1OTP_BASE + DCSM_O_Z1OTP_GPREG1);
    HWREG(DCSM_Z1OTP_BASE + DCSM_O_Z1OTP_GPREG2);
    HWREG(DCSM_Z1OTP_BASE + DCSM_O_Z1OTP_GPREG3);
    HWREG(DCSM_Z1OTP_BASE + DCSM_O_Z1OTP_GPREG4);
    HWREG(DCSM_Z1OTP_BASE + DCSM_O_Z1OTP_JTAGPSWDH0);
    HWREG(DCSM_Z1OTP_BASE + DCSM_O_Z1OTP_JTAGPSWDH1);

    HWREG(DCSM_Z2OTP_BASE + DCSM_O_Z2OTP_PSWDLOCK);
    HWREG(DCSM_Z2OTP_BASE + DCSM_O_Z2OTP_CRCLOCK);
    HWREG(DCSM_Z2OTP_BASE + DCSM_O_Z2OTP_GPREG1);
    HWREG(DCSM_Z2OTP_BASE + DCSM_O_Z2OTP_GPREG2);
    HWREG(DCSM_Z2OTP_BASE + DCSM_O_Z2OTP_GPREG3);
    HWREG(DCSM_Z2OTP_BASE + DCSM_O_Z2OTP_GPREG4);

    Z1_ZSB = Gather_Z1_ZSB();   //Gather ZSB of ZONE1 from BANK0
    Z2_ZSB = Gather_Z2_ZSB();   //Gather ZSB of ZONE2 from BANK0

    //
    // Zone 1 ZSB
    //
    HWREG(Z1_ZSB + DCSM_O_Zx_GRABSECT1);    // Zone Select Block contents
    HWREG(Z1_ZSB + DCSM_O_Zx_GRABSECT2);
    HWREG(Z1_ZSB + DCSM_O_Zx_GRABSECT3);
    HWREG(Z1_ZSB + DCSM_O_Zx_GRABRAM1);
    HWREG(Z1_ZSB + DCSM_O_Zx_GRABRAM2);
    HWREG(Z1_ZSB + DCSM_O_Zx_GRABRAM3);
    HWREG(Z1_ZSB + DCSM_O_Zx_EXEONLYSECT1);
    HWREG(Z1_ZSB + DCSM_O_Zx_EXEONLYSECT2);
    HWREG(Z1_ZSB + DCSM_O_Zx_EXEONLYRAM1);
    HWREG(Z1_ZSB + DCSM_O_Z1_JTAGPSWDL0);
    HWREG(Z1_ZSB + DCSM_O_Z1_JTAGPSWDL1);

    //
    // Zone 2 ZSB
    //
    HWREG(Z2_ZSB + DCSM_O_Zx_GRABSECT1);    // Zone Select Block contents
    HWREG(Z2_ZSB + DCSM_O_Zx_GRABSECT2);
    HWREG(Z2_ZSB + DCSM_O_Zx_GRABSECT3);
    HWREG(Z2_ZSB + DCSM_O_Zx_GRABRAM1);
    HWREG(Z2_ZSB + DCSM_O_Zx_GRABRAM2);
    HWREG(Z2_ZSB + DCSM_O_Zx_GRABRAM3);
    HWREG(Z2_ZSB + DCSM_O_Zx_EXEONLYSECT1);
    HWREG(Z2_ZSB + DCSM_O_Zx_EXEONLYSECT2);
    HWREG(Z2_ZSB + DCSM_O_Zx_EXEONLYRAM1);

    //
    // BLOCKED State --> LOCKED State
    //
    HWREG(Z1_ZSB + DCSM_O_Zx_CSMPSWD0);
    HWREG(Z1_ZSB + DCSM_O_Zx_CSMPSWD1);
    HWREG(Z1_ZSB + DCSM_O_Zx_CSMPSWD2);
    HWREG(Z1_ZSB + DCSM_O_Zx_CSMPSWD3);

    HWREG(Z2_ZSB + DCSM_O_Zx_CSMPSWD0);
    HWREG(Z2_ZSB + DCSM_O_Zx_CSMPSWD1);
    HWREG(Z2_ZSB + DCSM_O_Zx_CSMPSWD2);
    HWREG(Z2_ZSB + DCSM_O_Zx_CSMPSWD3);

    if((HWREG(DCSM_Z1_BASE + DCSM_O_Z1_CR) & DCSM_Z1_CR_UNSECURE) == 0)
    {
        //LOCKED State --> ARMED State
        HWREG(DCSM_Z1_BASE + DCSM_O_Z1_CSMKEY0) = 0xFFFFFFFF;   //Zone 1 CSMKEY Loads
        HWREG(DCSM_Z1_BASE + DCSM_O_Z1_CSMKEY1) = (uint32_t) z1_key1;
        HWREG(DCSM_Z1_BASE + DCSM_O_Z1_CSMKEY2) = 0xFFFFFFFF;
        HWREG(DCSM_Z1_BASE + DCSM_O_Z1_CSMKEY3) = 0xFFFFFFFF;
    }

    if((HWREG(DCSM_Z2_BASE + DCSM_O_Z2_CR) & DCSM_Z2_CR_UNSECURE) == 0)
    {
        HWREG(DCSM_Z2_BASE + DCSM_O_Z2_CSMKEY0) = 0xFFFFFFFF;   //Zone 2 CSMKEY Loads
        HWREG(DCSM_Z2_BASE + DCSM_O_Z2_CSMKEY1) = (uint32_t) z2_key1;
        HWREG(DCSM_Z2_BASE + DCSM_O_Z2_CSMKEY2) = 0xFFFFFFFF;
        HWREG(DCSM_Z2_BASE + DCSM_O_Z2_CSMKEY3) = 0xFFFFFFFF;
    }

    EDIS;
}

//
// Gather_Z1_ZSB
//
uint32_t Gather_Z1_ZSB(void)
{
    uint32_t linkPointer;
    uint32_t ZSBBase; // base address of the ZSB
    int32_t bitPos = 13;
    int32_t zeroFound = 0;

    linkPointer = HWREG(DCSM_Z1_BASE + DCSM_O_Z1_LINKPOINTER);
    linkPointer = linkPointer << 18; // Bits 31 - 14 as most-significant 0 are
                                     //invalid LinkPointer options

    while((zeroFound == 0) && (bitPos > -1))
    {
        if((linkPointer & 0x80000000U) == 0U)
        {
            zeroFound = 1;
            ZSBBase = (DCSM_Z1OTP_BASE + (((uint32_t)bitPos + 2U) * 0x20));
        }
        else
        {
            bitPos--;
            linkPointer = linkPointer << 1;
        }
    }

    if(zeroFound == 0)
    {
        ZSBBase = (DCSM_Z1OTP_BASE + 0X20);
    }

    z1_key1 = dcsm_default_keys_z1[bitPos+1];

    return ZSBBase;
}

//
// Gather_Z2_ZSB
//
uint32_t Gather_Z2_ZSB(void)
{
    uint32_t linkPointer;
    uint32_t ZSBBase; // base address of the ZSB
    int32_t bitPos = 13;
    int32_t zeroFound = 0;

    linkPointer = HWREG(DCSM_Z2_BASE + DCSM_O_Z2_LINKPOINTER);
    linkPointer = linkPointer << 18; // Bits 31 - 14 as most-significant 0 are
                                     //invalid LinkPointer options

    while((zeroFound == 0) && (bitPos > -1))
    {
        if((linkPointer & 0x80000000U) == 0U)
        {
            zeroFound = 1;
            ZSBBase = (DCSM_Z2OTP_BASE + (((uint32_t)bitPos + 2U) * 0x20));
        }
        else
        {
            bitPos--;
            linkPointer = linkPointer << 1;
        }
    }

    if(zeroFound == 0)
    {
        ZSBBase = (DCSM_Z2OTP_BASE + 0X20);
    }

    z2_key1 = dcsm_default_keys_z2[bitPos+1];

    return ZSBBase;
}

//
// End of File
//
