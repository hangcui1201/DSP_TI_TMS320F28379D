//###########################################################################
//
// FILE:   ipc.c
//
// TITLE:  C28x IPC driver.
//
//###########################################################################
// $TI Release:  $
// $Release Date:  $
// $Copyright:  $
//###########################################################################

#include "ipc.h"

//
// Macros internal to the IPC driver
//
#define IPC_REG_BOOTSTS_OFFSET             0x40U

#define IPC_CPU1_TO_CPU2_MSGRAM_CPU1VIEW   0x0003A000U
#define IPC_CPU1_TO_CPU2_MSGRAM_CPU2VIEW   0x0003A000U

#define IPC_CPU1_TO_CM_MSGRAM_CPU1VIEW     0x00039000U
#define IPC_CPU1_TO_CM_MSGRAM_CMVIEW       0x20080000U

#define IPC_CPU2_TO_CPU1_MSGRAM_CPU2VIEW   0x0003B000U
#define IPC_CPU2_TO_CPU1_MSGRAM_CPU1VIEW   0x0003B000U

#define IPC_CPU2_TO_CM_MSGRAM_CPU2VIEW     0x00039000U
#define IPC_CPU2_TO_CM_MSGRAM_CMVIEW       0x20084000U

#define IPC_CM_TO_CPU1_MSGRAM_CMVIEW       0x20082000U
#define IPC_CM_TO_CPU1_MSGRAM_CPU1VIEW     0x00038000U

#define IPC_CM_TO_CPU2_MSGRAM_CMVIEW       0x20086000U
#define IPC_CM_TO_CPU2_MSGRAM_CPU2VIEW     0x00038000U

#define IPC_ADDR_OFFSET_NOCHANGE           2U
#define IPC_ADDR_OFFSET_MUL2               4U
#define IPC_ADDR_OFFSET_DIV2               1U

#define IPC_ADDR_OFFSET_CORR(addr, corr)  (((addr) * (corr)) / 2U)

#if IPC_MSGQ_SUPPORT == 1U
//
// Global Circular Buffer Definitions
//

#pragma DATA_SECTION(IPC_CM_To_CPU1_PutBuffer,   "MSGRAM_CM_TO_CPU1")
#pragma DATA_SECTION(IPC_CM_To_CPU1_GetBuffer,   "MSGRAM_CPU1_TO_CM")
#pragma DATA_SECTION(IPC_CM_To_CPU2_PutBuffer,   "MSGRAM_CM_TO_CPU2")
#pragma DATA_SECTION(IPC_CM_To_CPU2_GetBuffer,   "MSGRAM_CPU2_TO_CM")

IPC_PutBuffer_t IPC_CM_To_CPU1_PutBuffer;
IPC_GetBuffer_t IPC_CM_To_CPU1_GetBuffer;
IPC_PutBuffer_t IPC_CM_To_CPU2_PutBuffer;
IPC_GetBuffer_t IPC_CM_To_CPU2_GetBuffer;
#endif

const IPC_Instance_t IPC_Instance[IPC_TOTAL_NUM] = {

     /* IPC_CM_L_CPU1_R */
     {
      .IPC_Flag_Ctr_Reg   = (volatile IPC_Flag_Ctr_Reg_t *) IPC_CMTOCPU1_BASE,
      .IPC_SendCmd_Reg    = (volatile IPC_SendCmd_Reg_t *)
                            (IPC_CMTOCPU1_BASE + IPC_O_CMTOCPU1IPCSENDCOM),
      .IPC_RecvCmd_Reg    = (volatile IPC_RecvCmd_Reg_t *)
                            (IPC_CMTOCPU1_BASE + IPC_O_CPU1TOCMIPCRECVCOM),
      .IPC_Boot_Pump_Reg  = (volatile IPC_Boot_Pump_Reg_t *)
                            (IPC_CMTOCPU1_BASE + IPC_REG_BOOTSTS_OFFSET),
      .IPC_IntNum         = {INT_IPC_CPU1TOCM_0, INT_IPC_CPU1TOCM_1,
                             INT_IPC_CPU1TOCM_2, INT_IPC_CPU1TOCM_3,
                             INT_IPC_CPU1TOCM_4, INT_IPC_CPU1TOCM_5,
                             INT_IPC_CPU1TOCM_6, INT_IPC_CPU1TOCM_7},
      .IPC_MsgRam_LtoR    = IPC_CM_TO_CPU1_MSGRAM_CMVIEW,
      .IPC_MsgRam_RtoL    = IPC_CPU1_TO_CM_MSGRAM_CMVIEW,
      .IPC_Offset_Corr    = IPC_ADDR_OFFSET_MUL2
#if IPC_MSGQ_SUPPORT == 1U
      ,
      .IPC_PutBuffer      = &IPC_CM_To_CPU1_PutBuffer,
      .IPC_GetBuffer      = &IPC_CM_To_CPU1_GetBuffer
#endif
     },

     /* IPC_CM_L_CPU2_R */
     {
      .IPC_Flag_Ctr_Reg   = (volatile IPC_Flag_Ctr_Reg_t *) IPC_CMTOCPU2_BASE,
      .IPC_SendCmd_Reg    = (volatile IPC_SendCmd_Reg_t *)
                            (IPC_CMTOCPU2_BASE + IPC_O_CMTOCPU2IPCSENDCOM),
      .IPC_RecvCmd_Reg    = (volatile IPC_RecvCmd_Reg_t *)
                            (IPC_CMTOCPU2_BASE + IPC_O_CPU2TOCMIPCRECVCOM),
      .IPC_Boot_Pump_Reg  = (volatile IPC_Boot_Pump_Reg_t *)
                            (IPC_CMTOCPU2_BASE + IPC_REG_BOOTSTS_OFFSET),
      .IPC_IntNum         = {INT_IPC_CPU2TOCM_0, INT_IPC_CPU2TOCM_1,
                             INT_IPC_CPU2TOCM_2, INT_IPC_CPU2TOCM_3,
                             INT_IPC_CPU2TOCM_4, INT_IPC_CPU2TOCM_5,
                             INT_IPC_CPU2TOCM_6, INT_IPC_CPU2TOCM_7},
      .IPC_MsgRam_LtoR    = IPC_CM_TO_CPU2_MSGRAM_CMVIEW,
      .IPC_MsgRam_RtoL    = IPC_CPU2_TO_CM_MSGRAM_CMVIEW,
      .IPC_Offset_Corr    = IPC_ADDR_OFFSET_MUL2
#if IPC_MSGQ_SUPPORT == 1U
      ,
      .IPC_PutBuffer      = &IPC_CM_To_CPU2_PutBuffer,
      .IPC_GetBuffer      = &IPC_CM_To_CPU2_GetBuffer
#endif
},
};

//*****************************************************************************
//
// IPC_sendCommand
//
//*****************************************************************************
bool IPC_sendCommand(IPC_Type_t ipcType, uint32_t flags, bool addrCorrEnable,
                     uint32_t command, uint32_t addr, uint32_t data)
{
    bool ret;

    //
    // Check whether the flags are not busy
    //
    if((IPC_Instance[ipcType].IPC_Flag_Ctr_Reg->IPC_FLG & flags) == 0U)
    {
        ret = true;

        if(addrCorrEnable)
        {
            //
            // Update the command registers. ADDR register holds the offset
            // from the base address of the MSG RAM
            //
            IPC_Instance[ipcType].IPC_SendCmd_Reg->IPC_SENDCOM  = command;
            IPC_Instance[ipcType].IPC_SendCmd_Reg->IPC_SENDDATA = data;
            IPC_Instance[ipcType].IPC_SendCmd_Reg->IPC_SENDADDR =
                            addr - IPC_Instance[ipcType].IPC_MsgRam_LtoR;
        }
        else
        {
            //
            // Update the command registers. addr param remains as is.
            //
            IPC_Instance[ipcType].IPC_SendCmd_Reg->IPC_SENDCOM  = command;
            IPC_Instance[ipcType].IPC_SendCmd_Reg->IPC_SENDDATA = data;
            IPC_Instance[ipcType].IPC_SendCmd_Reg->IPC_SENDADDR = addr;
        }

        //
        // Set the flags to indicate the remote core
        //
        IPC_Instance[ipcType].IPC_Flag_Ctr_Reg->IPC_SET = flags;
    }
    else
    {
        ret = false;
    }

    return(ret);
}

//*****************************************************************************
//
// IPC_readCommand
//
//*****************************************************************************
bool IPC_readCommand(IPC_Type_t ipcType, uint32_t flags, bool addrCorrEnable,
                     uint32_t* command, uint32_t* addr, uint32_t* data)
{
    bool ret;
    uint32_t addrReg;

    //
    // Check whether the flags are not empty
    //
    if((IPC_Instance[ipcType].IPC_Flag_Ctr_Reg->IPC_STS & flags) != 0U)
    {
        ret = true;

        //
        // Read the command registers
        //
        *command   = IPC_Instance[ipcType].IPC_RecvCmd_Reg->IPC_RECVCOM;
        addrReg    = IPC_Instance[ipcType].IPC_RecvCmd_Reg->IPC_RECVADDR;
        *data      = IPC_Instance[ipcType].IPC_RecvCmd_Reg->IPC_RECVDATA;

        if(addrCorrEnable)
        {
            //
            // Calculate the address form the offset
            //
            *addr = IPC_Instance[ipcType].IPC_MsgRam_RtoL +
                    IPC_ADDR_OFFSET_CORR(addrReg,
                                    IPC_Instance[ipcType].IPC_Offset_Corr);

        }
        else
        {
            *addr = addrReg;
        }

    }
    else
    {
        ret = false;
    }

    return(ret);
}


//*****************************************************************************
//
// IPC_registerInterrupt
//
//*****************************************************************************
void IPC_registerInterrupt(IPC_Type_t ipcType, uint32_t ipcInt,
                           void (*pfnHandler)(void))
{
    // Check for arguments

    ASSERT(ipcInt <= IPC_INT7);

    //
    // Get the corresponding interrupt number
    //
    uint32_t intNum = IPC_Instance[ipcType].IPC_IntNum[ipcInt];

    //
    // Register the interrupt handler
    //

    Interrupt_registerHandler(intNum, pfnHandler);

    //
    // Enable the interrupt
    //
    Interrupt_enable(intNum);
}

//*****************************************************************************
//
// IPC_unregisterInterrupt
//
//*****************************************************************************
void IPC_unregisterInterrupt(IPC_Type_t ipcType, uint32_t ipcInt)
{
    // Check for arguments

    ASSERT(ipcInt <= IPC_INT7);

    //
    // Get the corresponding interrupt number
    //
    uint32_t intNum = IPC_Instance[ipcType].IPC_IntNum[ipcInt];

    //
    // Disable the interrupt.
    //
    Interrupt_disable(intNum);

    //
    // Unregister the interrupt handler.
    //

    Interrupt_unregisterHandler(intNum);
}

#if IPC_MSGQ_SUPPORT == 1U
//*****************************************************************************
//
// IPCinitMessageQueue
//
//*****************************************************************************
void IPC_initMessageQueue(IPC_Type_t ipcType,
                         volatile IPC_MessageQueue_t *msgQueue,
                         uint32_t ipcInt_L, uint32_t ipcInt_R)
{
    // Check for arguments
    ASSERT(msgQueue != NULL);
    ASSERT(ipcInt_L < NUM_IPC_INTERRUPTS);
    ASSERT(ipcInt_R < NUM_IPC_INTERRUPTS);

    IPC_PutBuffer_t *PutBuffer = IPC_Instance[ipcType].IPC_PutBuffer;
    IPC_GetBuffer_t *GetBuffer = IPC_Instance[ipcType].IPC_GetBuffer;

    //
    // L->R Put Buffer and Index Initialization
    //
    msgQueue->PutBuffer     = PutBuffer->Buffer[ipcInt_R];
    msgQueue->PutWriteIndex = &(PutBuffer->PutWriteIndex[ipcInt_R]);
    msgQueue->GetReadIndex  = &(PutBuffer->GetReadIndex[ipcInt_L]);
    msgQueue->PutFlag       = (uint32_t)1U << ipcInt_R;

    //
    // L->R Get Buffer and Index Initialization
    //
    msgQueue->GetBuffer     = GetBuffer->Buffer[ipcInt_L];
    msgQueue->GetWriteIndex = &(GetBuffer->GetWriteIndex[ipcInt_L]);
    msgQueue->PutReadIndex  = &(GetBuffer->PutReadIndex[ipcInt_R]);

    //
    // Initialize PutBuffer WriteIndex = 0 and GetBuffer ReadIndex = 0
    //
    *(msgQueue->PutWriteIndex) = 0U;
    *(msgQueue->GetReadIndex)  = 0U;
}

//*****************************************************************************
//
// IPC_sendMessageToQueue
//
//*****************************************************************************
bool IPC_sendMessageToQueue(IPC_Type_t ipcType,
                           volatile IPC_MessageQueue_t *msgQueue,
                           bool addrCorrEnable, IPC_Message_t *msg, bool block)
{
    // Check for arguments
    ASSERT(msgQueue != NULL);
    ASSERT(msg != NULL);

    uint16_t writeIndex;
    uint16_t readIndex;
    uint16_t ret = true;

    writeIndex = *(msgQueue->PutWriteIndex);
    readIndex  = *(msgQueue->PutReadIndex);

    //
    // Wait until Put Buffer slot is free
    //
    while (((writeIndex + 1U) & MAX_BUFFER_INDEX) == readIndex)
    {
        //
        // If designated as a "Blocking" function, and Put buffer is full,
        // return immediately with fail status.
        //
        if (!block)
        {
            ret = false;
            break;
        }

        readIndex = *(msgQueue->PutReadIndex);
    }

    if (ret != false)
    {
        //
        // When slot is free, Write Message to PutBuffer, update PutWriteIndex,
        // and set the CPU IPC INT Flag
        //
        msgQueue->PutBuffer[writeIndex] = *msg;

        if(addrCorrEnable)
        {
            msgQueue->PutBuffer[writeIndex].address -=
                IPC_Instance[ipcType].IPC_MsgRam_LtoR;
        }

        writeIndex = (writeIndex + 1U) & MAX_BUFFER_INDEX;
        *(msgQueue->PutWriteIndex) = writeIndex;

        IPC_setFlagLtoR(ipcType, msgQueue->PutFlag);
    }

    return ret;
}

//*****************************************************************************
//
// IPC_readMessageFromQueue
//
//*****************************************************************************
bool IPC_readMessageFromQueue(IPC_Type_t ipcType,
                            volatile IPC_MessageQueue_t *msgQueue,
                            bool addrCorrEnable, IPC_Message_t *msg, bool block)
{
    // Check for arguments
    ASSERT(msgQueue != NULL);
    ASSERT(msg != NULL);

    uint16_t writeIndex;
    uint16_t readIndex;
    uint16_t ret = true;

    writeIndex = *(msgQueue->GetWriteIndex);
    readIndex  = *(msgQueue->GetReadIndex);

    //
    // Loop while GetBuffer is empty
    //
    while (writeIndex == readIndex)
    {
        //
        // If designated as a "Blocking" function, and Get buffer is empty,
        // return immediately with fail status.
        //
        if (!block)
        {
            ret = false;
            break;
        }

        writeIndex = *(msgQueue->GetWriteIndex);
    }

    if (ret != false)
    {
        //
        // If there is a message in GetBuffer, Read Message and update
        // the ReadIndex
        //
        *msg = msgQueue->GetBuffer[readIndex];
        if(addrCorrEnable)
        {
            msg->address = IPC_Instance[ipcType].IPC_MsgRam_RtoL +
                           IPC_ADDR_OFFSET_CORR(msg->address,
                                        IPC_Instance[ipcType].IPC_Offset_Corr);
        }

        readIndex = (readIndex + 1U) & MAX_BUFFER_INDEX;
        *(msgQueue->GetReadIndex) = readIndex;
    }

    return ret;
}
#endif
