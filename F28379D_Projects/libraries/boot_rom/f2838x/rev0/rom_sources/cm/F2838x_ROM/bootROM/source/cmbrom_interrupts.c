//###########################################################################
//
// FILE:    cmbrom_interrupts.c
//
// TITLE:   CM Boot ROM interrupt handlers
//
// Interrupt handlers to handle hard fault, NMI, and unexpected interrupts
//
//###########################################################################
// $TI Release:  $
// $Release Date:  $
//###########################################################################

//
// Included Files
//
#include "cmbootrom.h"

//
// Globals
//
extern uint32_t CMBROM_bootStatus;
uint32_t CMBROM_nmiStatus;

//
// CMBROM_nmiHandler - Function to handle NMI interrupts during CM boot
//
#pragma CODE_SECTION(CMBROM_nmiHandler, "CMBROM_NMI_HANDLER")
__interrupt void CMBROM_nmiHandler(void)
{
    uint32_t entryAddress = 0xFFFFFFFFUL;

    //
    // CM Patch/Escape Point 9
    //
    entryAddress = CMBROM_TI_OTP_ESCAPE_POINT_9;
    if((entryAddress != 0xFFFFFFFFUL) &&
       (entryAddress != 0x00000000UL))
    {
        entryAddress |= 0x1U;  // BLX instruction result in a UsageFault exception
                               // if bit[0] of Rm is 0, where Rm holds the branch
                               // address.
        //
        // If OTP is programmed, then call OTP patch function
        //
        ((void (*)(void))entryAddress)();
    }

    //
    // Check to see if NMI is triggered
    //    
    CMBROM_nmiStatus = HWREG(NMI_BASE + NMI_O_CMNMIFLG);
    do
    {
        //
        // Check for Clock Fail NMI
        //
        if((CMBROM_nmiStatus & NMI_CMNMIFLG_CLOCKFAIL) == NMI_CMNMIFLG_CLOCKFAIL)
        {
            //
            // Update boot status
            //            
            CMBROM_bootStatus |= CM_BOOTROM_GOT_A_MCLK_NMI;
            
            //
            // Clear NMI flag
            //
            HWREG(NMI_BASE + NMI_O_CMNMIFLGCLR) = (CM_NMI_CLEAR_KEY |
                                                   NMI_CMNMIFLGCLR_CLOCKFAIL);
        }
        //
        // Check for RAM/ROM (includes parity error) Uncorrectable Error NMI
        //
        if((CMBROM_nmiStatus & NMI_CMNMIFLG_MEMUNCERR) == NMI_CMNMIFLG_MEMUNCERR)
        {
            //
            // Update boot status
            //
            CMBROM_bootStatus |= CM_BOOTROM_GOT_A_RAM_UNCERR_NMI;

            //
            // Clear NMI flag
            //
            HWREG(NMI_BASE + NMI_O_CMNMIFLGCLR) = (CM_NMI_CLEAR_KEY |
                                                   NMI_CMNMIFLGCLR_MEMUNCERR);
        }
        //
        // Check for Flash Uncorrectable Error NMI
        //
        if((CMBROM_nmiStatus & NMI_CMNMIFLG_FLUNCERR) == NMI_CMNMIFLG_FLUNCERR)
        {
            //
            // Update boot status
            //
            CMBROM_bootStatus |= CM_BOOTROM_GOT_A_FLASH_UNCERR_NMI;

            //
            // Clear NMI flag
            //
            HWREG(NMI_BASE + NMI_O_CMNMIFLGCLR) = (CM_NMI_CLEAR_KEY |
                                                   NMI_CMNMIFLGCLR_FLUNCERR);
        }
        //
        // Check for MCAN NMI
        //
        if((CMBROM_nmiStatus & NMI_CMNMIFLG_MCANUNCERR) == NMI_CMNMIFLG_MCANUNCERR)
        {
            //
            // Update boot status
            //
            CMBROM_bootStatus |= CM_BOOTROM_GOT_A_MCAN_UNCERR_NMI;

            //
            // Clear NMI flag
            //
            HWREG(NMI_BASE + NMI_O_CMNMIFLGCLR) = (CM_NMI_CLEAR_KEY |
                                                   NMI_CMNMIFLG_MCANUNCERR);
        }
        //
        // Check for WWDNMI
        //
        if((CMBROM_nmiStatus & NMI_CMNMIFLG_WWDNMI) == NMI_CMNMIFLG_WWDNMI)
        {
            //
            // Update boot status
            //
            CMBROM_bootStatus |= CM_BOOTROM_GOT_A_WWD_NMI;

            //
            // Clear NMI flag
            //
            HWREG(NMI_BASE + NMI_O_CMNMIFLGCLR) = (CM_NMI_CLEAR_KEY |
                                                   NMI_CMNMIFLG_WWDNMI);
        }
        //
        // Check for ECAT NMI
        //
        if((CMBROM_nmiStatus & NMI_CMNMIFLG_ECATNMI) == NMI_CMNMIFLG_ECATNMI)
        {
            //
            // Update boot status
            //
            CMBROM_bootStatus |= CM_BOOTROM_GOT_A_ECAT_NMI;

            //
            // Clear NMI flag
            //
            HWREG(NMI_BASE + NMI_O_CMNMIFLGCLR) = (CM_NMI_CLEAR_KEY |
                                                   NMI_CMNMIFLG_ECATNMI);
        }
               
        //
        // Clear Global NMI flag
        //
        CMBROM_nmiStatus &= ~(NMI_CMNMIFLG_NMIINT);     
        
        HWREG(NMI_BASE + NMI_O_CMNMIFLGCLR) = (CM_NMI_CLEAR_KEY |
                                               NMI_CMNMIFLGCLR_NMIINT);
        
        //
        // Read NMI status to determine if more NMIs present
        //
        CMBROM_nmiStatus = HWREG(NMI_BASE + NMI_O_CMNMIFLG);   

    }while((CMBROM_nmiStatus & NMI_CMNMIFLG_NMIINT) == NMI_CMNMIFLG_NMIINT);

    //
    // Update boot status
    //
    CMBROM_setIPCBootStatus();

    //
    // Send Error IPC to CPU1
    //
    (void)CMBROM_sendErrorIPC(CMTOCPU1_BOOTROM_NMI,
                              NO_ADDRESS_DATA);

    //
    // Wait to be reset by CPU1
    //
    while(1)
    {
    }
}

//
// CMBROM_hardFaultISR - Function to handle any hard fault interrupts
//
#pragma CODE_SECTION(CMBROM_hardFaultISR, "CMBROM_HARDFAULT_HANDLER")
__interrupt void CMBROM_hardFaultISR(void)
{
    //
    // Update boot status
    //    
    CMBROM_bootStatus |= CM_BOOTROM_GOT_HARD_FAULT;

    //
    // Update boot status health and send IPC to CPU1
    //
    CMBROM_setIPCBootStatus();
    (void)CMBROM_sendErrorIPC(CMTOCPU1_BOOTROM_HARD_FAULT,
                              NO_ADDRESS_DATA);
    
    //
    // Wait for CPU1 to reset CM
    //    
    while(1)
    {
    }
}

//
// CMBROM_defaultHandler - Default interrupt handler for any unassigned interrupts
//
#pragma CODE_SECTION(CMBROM_defaultHandler, "CMBROM_DEFAULT_HANDLER")
__interrupt void CMBROM_defaultHandler(void)
{
    //
    // Update boot status
    //
    CMBROM_bootStatus |= CM_BOOTROM_GOT_UNASSIGNED_INTERRUPT;

    //
    // Update boot status health and send IPC to CPU1 with
    // active exception number
    //
    CMBROM_setIPCBootStatus();
    (void)CMBROM_sendErrorIPC(CMTOCPU1_BOOTROM_UNASSIGNED_INTERRUPT,
                              (HWREGH(NVIC_BASE + NVIC_O_ICSR) &
                               NVIC_ICSR_VECTACTIVE_M));

    //
    // Wait for CPU1 to reset CM
    //
    while(1)
    {
    }
}


//
// End of file
//
