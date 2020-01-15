//###########################################################################
//
// FILE:    cpu2brom_ipc.c
//
// TITLE:   CPU2 IPC Functions
//
// CPU2 IPC functions used to communicate to and from CPU1
//
//###########################################################################
// $TI Release:  $
// $Release Date:  $
//###########################################################################

//
// Included Files
//
#include "cpu2bootrom.h"

//
// Globals
//
extern uint32_t CPU2BROM_bootStatus;

//
// CPU2BROM_setIPCBootStatus - Set IPCBOOTSTS for CPU1 to read status info
//
void CPU2BROM_setIPCBootStatus(void)
{
    HWREG(IPC_CPU2TOCPU1_BASE + IPC_O_CPU2TOCPU1IPCBOOTSTS) = CPU2BROM_bootStatus;
}

//
// CPU2BROM_sendErrorIPC - Send IPC command to CPU1 when error occurs
//
uint32_t CPU2BROM_sendErrorIPC(uint32_t errorCommand, uint32_t address)
{
    //
    // Important: Don't use local variables in this function
    //

    //
    // Don't send IPC command if previous IPC hasn't been addressed.
    // (IPC Flags 0 not cleared by CPU1)
    //
    if((HWREG(IPC_CPU2TOCPU1_BASE + IPC_O_CPU2TOCPU1IPCFLG) & IPC_CPU2TOCPU1IPCFLG_IPC0) == IPC_CPU2TOCPU1IPCFLG_IPC0)
    {
        return(CPU2_IPC_FAILURE);
    }

    //
    // Set IPC command with error and IPC address (if applicable)
    //
    HWREG(IPC_CPU2TOCPU1_BASE + IPC_O_CPU2TOCPU1IPCSENDCOM) = errorCommand;
    HWREG(IPC_CPU2TOCPU1_BASE + IPC_O_CPU2TOCPU1IPCSENDADDR) = address;

    //
    // Set IPC Flags 0
    //
    HWREG(IPC_CPU2TOCPU1_BASE + IPC_O_CPU2TOCPU1IPCSET) = IPC_CPU2TOCPU1IPCSET_IPC0;

    return(CPU2_IPC_SUCCESS);
}

//
// End of file
//
