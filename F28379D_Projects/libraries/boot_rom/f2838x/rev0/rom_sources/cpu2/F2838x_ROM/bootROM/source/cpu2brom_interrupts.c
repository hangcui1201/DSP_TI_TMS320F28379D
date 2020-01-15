//###########################################################################
//
// FILE:    cpu2brom_interrupts.c
//
// TITLE:   CPU2 Boot ROM interrupt handlers
//
// Interrupt handlers to handle itrap, NMI, and PIE vector interrupts
//
//###########################################################################
// $TI Release: $
// $Release Date: $
//###########################################################################

//
// Included Files
//
#include "cpu2bootrom.h"

//
// Globals
//
extern uint32_t CPU2BROM_bootStatus;
uint16_t CPU2BROM_nmiStatus;
uint32_t CPU2BROM_itrapAddress;

//
// Function Prototypes
//
void load_itrap_address (uint32_t *itrapaddress);

//
// CPU2BROM_pieVectorMismatchHandler - Function to handle PIE vector mismatch
//                                     during CPU2 Boot
//
#pragma CODE_SECTION(CPU2BROM_pieVectorMismatchHandler, "CPU2BROM_PIE_MISMATCH_HANDLER")
__interrupt void CPU2BROM_pieVectorMismatchHandler(void)
{
    uint32_t entryAddress = 0xFFFFFFFFUL;

    //
    // Update boot status
    //
    CPU2BROM_bootStatus |= CPU2_BOOTROM_GOT_A_PIE_MISMATCH;

    //
    // Update CPU2 boot health status for CPU1
    //
    CPU2BROM_setIPCBootStatus();

    //
    // Get the pie vector fetch error handler address to determine action
    //
    EALLOW;
    entryAddress = HWREG(CPUSYS_BASE + SYSCTL_O_PIEVERRADDR);
    EDIS;

    if((entryAddress != (uint32_t)0x003FFFFFU))
    {
        //
        // Address isn't the default reset value, call error handler routine
        //
        ((void (*)(void))entryAddress)();
    }
    else
    {
        //
        // CPU1 should have received NMI
        //

        //
        // Call NMI handler and wait for CPU1 to reset CPU2
        //
        CPU2BROM_nmiHandler();
    }
}

//
// CPU2BROM_nmiHandler - Function to handle NMI interrupts during CPU1 boot
//
__interrupt void CPU2BROM_nmiHandler(void)
{
    uint32_t entryAddress;

    //
    // CPU2 Patch/Escape Point 10
    //
    entryAddress = CPU2BROM_TI_OTP_ESCAPE_POINT_10;
    if((entryAddress != 0xFFFFFFFFUL) &&
       (entryAddress != 0x00000000UL))
    {
        //
        // If OTP is programmed, then call OTP patch function
        //
        ((void (*)(void))entryAddress)();
    }

    //
    // Check to see if NMI is triggered
    //
    CPU2BROM_nmiStatus = HWREGH(NMI_BASE + NMI_O_FLG);
    do
    {
        //
        // Check for Clock Fail NMI
        //
        if((CPU2BROM_nmiStatus & NMI_FLG_CLOCKFAIL) == NMI_FLG_CLOCKFAIL)
        {
            //
            // Update boot status
            //
            CPU2BROM_bootStatus |= CPU2_BOOTROM_GOT_A_MCLK_NMI;

            //
            // Clear Clock Fail flag
            //
            EALLOW;
            HWREGH(NMI_BASE + NMI_O_FLGCLR) = NMI_FLG_CLOCKFAIL;
            EDIS;
        }
        //
        // Check for CPU2 HWBIST Error NMI
        //
        if((CPU2BROM_nmiStatus & NMI_FLG_CPU2HWBISTERR) == NMI_FLG_CPU2HWBISTERR)
        {
            //
            // Update boot status
            //
            CPU2BROM_bootStatus |= CPU2_BOOTROM_GOT_A_HWBIST_NMI;

            //
            // Clear HWBIST Error Flag
            //
            EALLOW;
            HWREGH(NMI_BASE + NMI_O_FLGCLR) = NMI_FLG_CPU2HWBISTERR;
            EDIS;
        }
        //
        // Check for Configurable Logic NMI
        //
        if((CPU2BROM_nmiStatus & NMI_FLG_RLNMI) == NMI_FLG_RLNMI)
        {
            //
            // Update boot status
            //
            CPU2BROM_bootStatus |= CPU2_BOOTROM_GOT_A_RL_NMI;

            //
            // Clear Configurable Logic Error Flag
            //
            EALLOW;
            HWREGH(NMI_BASE + NMI_O_FLGCLR) = NMI_FLG_RLNMI;
            EDIS;
        }
        //
        // Check for ERAD NMI
        //
        if((CPU2BROM_nmiStatus & NMI_FLG_ERADNMI) == NMI_FLG_ERADNMI)
        {
            //
            // Update boot status
            //
            CPU2BROM_bootStatus |= CPU2_BOOTROM_GOT_AN_ERAD_NMI;

            //
            // Clear Configurable Logic Error Flag
            //
            EALLOW;
            HWREGH(NMI_BASE + NMI_O_FLGCLR) = NMI_FLG_ERADNMI;
            EDIS;
        }
        //
        // Check for Pie Vector Fetch NMI
        //
        if((CPU2BROM_nmiStatus & NMI_FLG_PIEVECTERR) == NMI_FLG_PIEVECTERR)
        {
            //
            // Update boot status
            //
            CPU2BROM_bootStatus |= CPU2_BOOTROM_GOT_A_PIE_VECTOR_NMI;

            //
            // Clear Pie Vector Fetch Error Flag
            //
            EALLOW;
            HWREGH(NMI_BASE + NMI_O_FLGCLR) = NMI_FLG_PIEVECTERR;
            EDIS;
        }
        //
        // Check for RAM Uncorrectable Error NMI (includes parity error)
        //
        if((CPU2BROM_nmiStatus & NMI_FLG_RAMUNCERR) == NMI_FLG_RAMUNCERR)
        {
            //
            // Update boot status
            //
            CPU2BROM_bootStatus |= CPU2_BOOTROM_GOT_A_RAM_UNCERR_NMI;

            //
            // Clear RAM Uncorrectable error flag
            //
            EALLOW;
            HWREGH(NMI_BASE + NMI_O_FLGCLR) = NMI_FLG_RAMUNCERR;
            EDIS;
        }
        //
        // Check for Flash Uncorrectable Error NMI
        //
        if((CPU2BROM_nmiStatus & NMI_FLG_FLUNCERR) == NMI_FLG_FLUNCERR)
        {
            //
            // Update boot status
            //
            CPU2BROM_bootStatus |= CPU2_BOOTROM_GOT_A_FLASH_UNCERR_NMI;

            //
            // Clear RAM Uncorrectable error flag
            //
            EALLOW;
            HWREGH(NMI_BASE + NMI_O_FLGCLR) = NMI_FLG_FLUNCERR;
            EDIS;
        }

        //
        // Clear Global NMI flag
        //
        CPU2BROM_nmiStatus &= ~(NMI_FLG_NMIINT);

        EALLOW;
        HWREGH(NMI_BASE + NMI_O_FLGCLR) = NMI_FLG_NMIINT;
        EDIS;

        //
        // Read NMI status to determine if more NMIs present
        //
        CPU2BROM_nmiStatus = HWREGH(NMI_BASE + NMI_O_FLG);

    }while((CPU2BROM_nmiStatus & NMI_FLG_NMIINT) == NMI_FLG_NMIINT);

    //
    // Update CPU2 boot health status for CPU1
    //
    CPU2BROM_setIPCBootStatus();

    //
    // Send Error IPC to CPU1
    //
    (void)CPU2BROM_sendErrorIPC(CPU2TOCPU1_BOOTROM_NMI,
                                NO_ADDRESS_DATA);

    //
    // Wait to be reset by CPU1
    //
    while(1)
    {
    }
}

//
// CPU2BROM_itrapISR - Function called whenever an illegal interrupt occurs
//                     on CPU1
//
__interrupt void CPU2BROM_itrapISR(void)
{
    //
    // Update boot status
    //
    CPU2BROM_bootStatus |= CPU2_BOOTROM_GOT_ITRAP;

    //
    // Check if RAM is accessible at this point
    // (Read back previously written value)
    //
    if((CPU2BROM_bootStatus & CPU2_BOOTROM_GOT_ITRAP) != CPU2_BOOTROM_GOT_ITRAP)
    {
        //
        // RAM isn't accessible - Don't perform any function calls
        //

        //
        // Update boot status for CPU1
        //
        HWREG(IPC_CPU2TOCPU1_BASE + IPC_O_CPU2TOCPU1IPCBOOTSTS) =  ((HWREG(IPC_CPU2TOCPU1_BASE + IPC_O_CPU2TOCPU1IPCBOOTSTS)) |
                                                                     CPU2_BOOTROM_GOT_ITRAP);

        //
        // Wait for CPU1 to be ready for IPC, send IPC, and wait in loop
        //
        while((HWREG(IPC_CPU2TOCPU1_BASE + IPC_O_CPU2TOCPU1IPCFLG) &
               IPC_CPU2TOCPU1IPCFLG_IPC0) == IPC_CPU2TOCPU1IPCFLG_IPC0)
        {
        }

        HWREG(IPC_CPU2TOCPU1_BASE + IPC_O_CPU2TOCPU1IPCSENDCOM) = CPU2TOCPU1_BOOTROM_IN_ITRAP;
        HWREG(IPC_CPU2TOCPU1_BASE + IPC_O_CPU2TOCPU1IPCSENDADDR) = NO_ADDRESS_DATA;

        HWREG(IPC_CPU2TOCPU1_BASE + IPC_O_CPU2TOCPU1IPCSET) = IPC_CPU2TOCPU1IPCSET_IPC0;

        while(1)
        {
        }
    }

    //
    // RAM is still accessible
    //

    //
    // Update CPU2 boot status health
    //
    CPU2BROM_setIPCBootStatus();

    //
    // Clear global address variable. Accessing the global variable locally
    // sets the DP pointer for the below inlined assembly function
    // (load_itrap_address)
    //
    CPU2BROM_itrapAddress = 0xFFFFFFFFUL;

    //
    // Get the iTrap address (return address from interrupt) stored in stack.
    // This particular return address stored in stack will change according to
    // compiler optimizations.
    //
    load_itrap_address(&CPU2BROM_itrapAddress);

    //
    // Return address from interrupt will be a PC location where an illegal
    // instruction is executed, so adjust address by 1
    //
    CPU2BROM_itrapAddress -= 1U;

    //
    // Send IPC to CPU1
    //
    (void)CPU2BROM_sendErrorIPC(CPU2TOCPU1_BOOTROM_IN_ITRAP,
                                CPU2BROM_itrapAddress);

    //
    // Wait for CPU1 to reset CPU2
    //
    while(1)
    {
    }
}

//
// End of File
//
