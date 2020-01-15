//###########################################################################
//
// FILE:    cmbrom_ipc.c
//
// TITLE:   CM IPC Functions
//
// CM IPC functions used to communicate to and from CPU1
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

//
// CMBROM_setIPCBootStatus - Set IPCBOOTSTS for CPU1 to read status info
//
void CMBROM_setIPCBootStatus(void)
{
	HWREG(IPC_CMTOCPU1_BASE + IPC_O_CMTOCPU1IPCBOOTSTS) = CMBROM_bootStatus;
}

//
// CMBROM_sendErrorIPC - Send IPC command to CPU1 when error occurs
//
uint32_t CMBROM_sendErrorIPC(uint32_t errorCommand, uint32_t address)
{
    //
    // Important: Don't use local variables in this function
    //

    //
    // Don't send IPC command if previous IPC hasn't been addressed.
    // (IPC Flags 0 not cleared by CPU1)
    //
    if((HWREG(IPC_CMTOCPU1_BASE + IPC_O_CMTOCPU1IPCFLG) & IPC_CMTOCPU1IPCFLG_IPC0) == IPC_CMTOCPU1IPCFLG_IPC0)
    {
        return(CM_IPC_FAILURE);
    }

    //
    // Set IPC command with error and IPC address (if applicable)
    //
    HWREG(IPC_CMTOCPU1_BASE + IPC_O_CMTOCPU1IPCSENDCOM) = errorCommand;
    HWREG(IPC_CMTOCPU1_BASE + IPC_O_CMTOCPU1IPCSENDADDR) = address;

    //
    // Set IPC Flags 0
    //
    HWREG(IPC_CMTOCPU1_BASE + IPC_O_CMTOCPU1IPCSET) = IPC_CMTOCPU1IPCSET_IPC0;

    return(CM_IPC_SUCCESS);
}

//
// End of file
//
