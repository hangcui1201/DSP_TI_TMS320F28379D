/*
 *  Do not modify this file; it is automatically 
 *  generated and any modifications will be overwritten.
 *
 * @(#) xdc-H28
 */

#define __nested__
#define __config__

#include <xdc/std.h>

/*
 * ======== GENERATED SECTIONS ========
 *
 *     MODULE INCLUDES
 *
 *     <module-name> INTERNALS
 *     <module-name> INHERITS
 *     <module-name> VTABLE
 *     <module-name> PATCH TABLE
 *     <module-name> DECLARATIONS
 *     <module-name> OBJECT OFFSETS
 *     <module-name> TEMPLATES
 *     <module-name> INITIALIZERS
 *     <module-name> FUNCTION STUBS
 *     <module-name> PROXY BODY
 *     <module-name> OBJECT DESCRIPTOR
 *     <module-name> VIRTUAL FUNCTIONS
 *     <module-name> SYSTEM FUNCTIONS
 *     <module-name> PRAGMAS
 *
 *     INITIALIZATION ENTRY POINT
 *     PROGRAM GLOBALS
 *     CLINK DIRECTIVES
 */


/*
 * ======== MODULE INCLUDES ========
 */

#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/family/c28/Hwi.h>
#include <ti/sysbios/family/c28/IntrinsicsSupport.h>
#include <ti/sysbios/family/c28/TaskSupport.h>
#include <ti/sysbios/family/c28/Timer.h>
#include <ti/sysbios/family/c28/f2837x/TimestampProvider.h>
#include <ti/sysbios/gates/GateHwi.h>
#include <ti/sysbios/gates/GateMutex.h>
#include <ti/sysbios/hal/Hwi.h>
#include <ti/sysbios/heaps/HeapMem.h>
#include <ti/sysbios/knl/Clock.h>
#include <ti/sysbios/knl/Idle.h>
#include <ti/sysbios/knl/Intrinsics.h>
#include <ti/sysbios/knl/Queue.h>
#include <ti/sysbios/knl/Semaphore.h>
#include <ti/sysbios/knl/Swi.h>
#include <ti/sysbios/knl/Task.h>
#include <xdc/runtime/Assert.h>
#include <xdc/runtime/Core.h>
#include <xdc/runtime/Defaults.h>
#include <xdc/runtime/Diags.h>
#include <xdc/runtime/Error.h>
#include <xdc/runtime/Gate.h>
#include <xdc/runtime/Log.h>
#include <xdc/runtime/LoggerBuf.h>
#include <xdc/runtime/Main.h>
#include <xdc/runtime/Memory.h>
#include <xdc/runtime/Registry.h>
#include <xdc/runtime/Startup.h>
#include <xdc/runtime/SysMin.h>
#include <xdc/runtime/System.h>
#include <xdc/runtime/Text.h>
#include <xdc/runtime/Types.h>

/* suppress 'type qualifier is meaningless on cast type' warning */
#ifdef __ti__
#pragma diag_suppress 193
#endif
#ifdef __IAR_SYSTEMS_ICC__
#pragma diag_suppress=Pe191
#endif

/*
 * ======== ti.sysbios.BIOS INTERNALS ========
 */


/*
 * ======== ti.sysbios.BIOS_RtsGateProxy INTERNALS ========
 */

/* Module__ */
typedef struct ti_sysbios_BIOS_RtsGateProxy_Module__ {
    xdc_runtime_Types_Link link;
} ti_sysbios_BIOS_RtsGateProxy_Module__;

/* Module__root__V */
extern ti_sysbios_BIOS_RtsGateProxy_Module__ ti_sysbios_BIOS_RtsGateProxy_Module__root__V;

/* @@@ ti_sysbios_knl_Queue_Object__ */
typedef struct ti_sysbios_knl_Queue_Object__ {
    ti_sysbios_knl_Queue_Elem elem;
} ti_sysbios_knl_Queue_Object__;

/* @@@ ti_sysbios_knl_Queue_Object2__ */
typedef struct {
    xdc_runtime_Types_InstHdr hdr;
    ti_sysbios_knl_Queue_Object__ obj;
} ti_sysbios_knl_Queue_Object2__;

/* @@@ ti_sysbios_knl_Semaphore_Object__ */
typedef struct ti_sysbios_knl_Semaphore_Object__ {
    ti_sysbios_knl_Event_Handle event;
    xdc_UInt eventId;
    ti_sysbios_knl_Semaphore_Mode mode;
    volatile xdc_UInt16 count;
    ti_sysbios_knl_Queue_Object__ Object_field_pendQ;
} ti_sysbios_knl_Semaphore_Object__;

/* @@@ ti_sysbios_knl_Semaphore_Object2__ */
typedef struct {
    xdc_runtime_Types_InstHdr hdr;
    ti_sysbios_knl_Semaphore_Object__ obj;
} ti_sysbios_knl_Semaphore_Object2__;

/* Object__ */
typedef struct ti_sysbios_gates_GateMutex_Object__ {
    const ti_sysbios_gates_GateMutex_Fxns__ *__fxns;
    ti_sysbios_knl_Task_Handle owner;
    ti_sysbios_knl_Semaphore_Object__ Object_field_sem;
} ti_sysbios_gates_GateMutex_Object__;

/* Object2__ */
typedef struct {
    xdc_runtime_Types_InstHdr hdr;
    ti_sysbios_gates_GateMutex_Object__ obj;
} ti_sysbios_gates_GateMutex_Object2__;

/* Object */
typedef ti_sysbios_gates_GateMutex_Object__ ti_sysbios_BIOS_RtsGateProxy_Object__;

/* Object2__ */
typedef struct {
    xdc_runtime_Types_InstHdr hdr;
    ti_sysbios_BIOS_RtsGateProxy_Object__ obj;
} ti_sysbios_BIOS_RtsGateProxy_Object2__;


/*
 * ======== ti.sysbios.family.c28.Hwi INTERNALS ========
 */

/* Module__ */
typedef struct ti_sysbios_family_c28_Hwi_Module__ {
    xdc_runtime_Types_Link link;
} ti_sysbios_family_c28_Hwi_Module__;

/* Module__root__V */
extern ti_sysbios_family_c28_Hwi_Module__ ti_sysbios_family_c28_Hwi_Module__root__V;

/* Object__ */
typedef struct ti_sysbios_family_c28_Hwi_Object__ {
    const ti_sysbios_family_c28_Hwi_Fxns__ *__fxns;
    xdc_UInt intNum;
    xdc_Bool enableInt;
    xdc_Bool enableAck;
    xdc_Bits16 disableMask;
    xdc_Bits16 restoreMask;
    xdc_Bits16 ierBitMask;
    xdc_UArg arg;
    ti_sysbios_family_c28_Hwi_FuncPtr fxn;
    ti_sysbios_family_c28_Hwi_Irp irp;
    __TA_ti_sysbios_family_c28_Hwi_Instance_State__hookEnv hookEnv;
} ti_sysbios_family_c28_Hwi_Object__;

/* Object2__ */
typedef struct {
    xdc_runtime_Types_InstHdr hdr;
    ti_sysbios_family_c28_Hwi_Object__ obj;
} ti_sysbios_family_c28_Hwi_Object2__;


/*
 * ======== ti.sysbios.family.c28.IntrinsicsSupport INTERNALS ========
 */


/*
 * ======== ti.sysbios.family.c28.TaskSupport INTERNALS ========
 */


/*
 * ======== ti.sysbios.family.c28.Timer INTERNALS ========
 */

/* Module__ */
typedef struct ti_sysbios_family_c28_Timer_Module__ {
    xdc_runtime_Types_Link link;
} ti_sysbios_family_c28_Timer_Module__;

/* Module__root__V */
extern ti_sysbios_family_c28_Timer_Module__ ti_sysbios_family_c28_Timer_Module__root__V;

/* Object__ */
typedef struct ti_sysbios_family_c28_Timer_Object__ {
    const ti_sysbios_family_c28_Timer_Fxns__ *__fxns;
    xdc_Int id;
    ti_sysbios_family_c28_Timer_EmulationMode emulationModeInit;
    ti_sysbios_interfaces_ITimer_RunMode runMode;
    ti_sysbios_interfaces_ITimer_StartMode startMode;
    xdc_UInt32 period;
    ti_sysbios_interfaces_ITimer_PeriodType periodType;
    xdc_UInt16 prescale;
    xdc_UInt intNum;
    xdc_UArg arg;
    ti_sysbios_family_c28_Hwi_FuncPtr tickFxn;
    xdc_runtime_Types_FreqHz extFreq;
    ti_sysbios_family_c28_Hwi_Handle hwi;
} ti_sysbios_family_c28_Timer_Object__;

/* Object2__ */
typedef struct {
    xdc_runtime_Types_InstHdr hdr;
    ti_sysbios_family_c28_Timer_Object__ obj;
} ti_sysbios_family_c28_Timer_Object2__;


/*
 * ======== ti.sysbios.family.c28.f2837x.TimestampProvider INTERNALS ========
 */


/*
 * ======== ti.sysbios.gates.GateHwi INTERNALS ========
 */

/* Module__ */
typedef struct ti_sysbios_gates_GateHwi_Module__ {
    xdc_runtime_Types_Link link;
} ti_sysbios_gates_GateHwi_Module__;

/* Module__root__V */
extern ti_sysbios_gates_GateHwi_Module__ ti_sysbios_gates_GateHwi_Module__root__V;

/* Object__ */
typedef struct ti_sysbios_gates_GateHwi_Object__ {
    const ti_sysbios_gates_GateHwi_Fxns__ *__fxns;
} ti_sysbios_gates_GateHwi_Object__;

/* Object2__ */
typedef struct {
    xdc_runtime_Types_InstHdr hdr;
    ti_sysbios_gates_GateHwi_Object__ obj;
} ti_sysbios_gates_GateHwi_Object2__;


/*
 * ======== ti.sysbios.gates.GateMutex INTERNALS ========
 */

/* Module__ */
typedef struct ti_sysbios_gates_GateMutex_Module__ {
    xdc_runtime_Types_Link link;
} ti_sysbios_gates_GateMutex_Module__;

/* Module__root__V */
extern ti_sysbios_gates_GateMutex_Module__ ti_sysbios_gates_GateMutex_Module__root__V;

/* <-- ti_sysbios_gates_GateMutex_Object */


/*
 * ======== ti.sysbios.hal.Hwi INTERNALS ========
 */

/* Module__ */
typedef struct ti_sysbios_hal_Hwi_Module__ {
    xdc_runtime_Types_Link link;
} ti_sysbios_hal_Hwi_Module__;

/* Module__root__V */
extern ti_sysbios_hal_Hwi_Module__ ti_sysbios_hal_Hwi_Module__root__V;

/* Object__ */
typedef struct ti_sysbios_hal_Hwi_Object__ {
    const ti_sysbios_hal_Hwi_Fxns__ *__fxns;
    ti_sysbios_hal_Hwi_HwiProxy_Handle pi;
} ti_sysbios_hal_Hwi_Object__;

/* Object2__ */
typedef struct {
    xdc_runtime_Types_InstHdr hdr;
    ti_sysbios_hal_Hwi_Object__ obj;
} ti_sysbios_hal_Hwi_Object2__;


/*
 * ======== ti.sysbios.hal.Hwi_HwiProxy INTERNALS ========
 */

/* Module__ */
typedef struct ti_sysbios_hal_Hwi_HwiProxy_Module__ {
    xdc_runtime_Types_Link link;
} ti_sysbios_hal_Hwi_HwiProxy_Module__;

/* Module__root__V */
extern ti_sysbios_hal_Hwi_HwiProxy_Module__ ti_sysbios_hal_Hwi_HwiProxy_Module__root__V;

/* <-- ti_sysbios_family_c28_Hwi_Object */

/* Object */
typedef ti_sysbios_family_c28_Hwi_Object__ ti_sysbios_hal_Hwi_HwiProxy_Object__;

/* Object2__ */
typedef struct {
    xdc_runtime_Types_InstHdr hdr;
    ti_sysbios_hal_Hwi_HwiProxy_Object__ obj;
} ti_sysbios_hal_Hwi_HwiProxy_Object2__;


/*
 * ======== ti.sysbios.heaps.HeapMem INTERNALS ========
 */

/* Module__ */
typedef struct ti_sysbios_heaps_HeapMem_Module__ {
    xdc_runtime_Types_Link link;
} ti_sysbios_heaps_HeapMem_Module__;

/* Module__root__V */
extern ti_sysbios_heaps_HeapMem_Module__ ti_sysbios_heaps_HeapMem_Module__root__V;

/* Object__ */
typedef struct ti_sysbios_heaps_HeapMem_Object__ {
    const ti_sysbios_heaps_HeapMem_Fxns__ *__fxns;
    xdc_runtime_Memory_Size align;
    __TA_ti_sysbios_heaps_HeapMem_Instance_State__buf buf;
    ti_sysbios_heaps_HeapMem_Header head;
    xdc_SizeT minBlockAlign;
} ti_sysbios_heaps_HeapMem_Object__;

/* Object2__ */
typedef struct {
    xdc_runtime_Types_InstHdr hdr;
    ti_sysbios_heaps_HeapMem_Object__ obj;
} ti_sysbios_heaps_HeapMem_Object2__;


/*
 * ======== ti.sysbios.heaps.HeapMem_Module_GateProxy INTERNALS ========
 */

/* Module__ */
typedef struct ti_sysbios_heaps_HeapMem_Module_GateProxy_Module__ {
    xdc_runtime_Types_Link link;
} ti_sysbios_heaps_HeapMem_Module_GateProxy_Module__;

/* Module__root__V */
extern ti_sysbios_heaps_HeapMem_Module_GateProxy_Module__ ti_sysbios_heaps_HeapMem_Module_GateProxy_Module__root__V;

/* <-- ti_sysbios_gates_GateMutex_Object */

/* Object */
typedef ti_sysbios_gates_GateMutex_Object__ ti_sysbios_heaps_HeapMem_Module_GateProxy_Object__;

/* Object2__ */
typedef struct {
    xdc_runtime_Types_InstHdr hdr;
    ti_sysbios_heaps_HeapMem_Module_GateProxy_Object__ obj;
} ti_sysbios_heaps_HeapMem_Module_GateProxy_Object2__;


/*
 * ======== ti.sysbios.knl.Clock INTERNALS ========
 */

/* Module__ */
typedef struct ti_sysbios_knl_Clock_Module__ {
    xdc_runtime_Types_Link link;
} ti_sysbios_knl_Clock_Module__;

/* Module__root__V */
extern ti_sysbios_knl_Clock_Module__ ti_sysbios_knl_Clock_Module__root__V;

/* <-- ti_sysbios_knl_Queue_Object */

/* Object__ */
typedef struct ti_sysbios_knl_Clock_Object__ {
    ti_sysbios_knl_Queue_Elem elem;
    xdc_UInt32 timeout;
    xdc_UInt32 currTimeout;
    xdc_UInt32 period;
    volatile xdc_Bool active;
    ti_sysbios_knl_Clock_FuncPtr fxn;
    xdc_UArg arg;
} ti_sysbios_knl_Clock_Object__;

/* Object2__ */
typedef struct {
    xdc_runtime_Types_InstHdr hdr;
    ti_sysbios_knl_Clock_Object__ obj;
} ti_sysbios_knl_Clock_Object2__;


/*
 * ======== ti.sysbios.knl.Clock_TimerProxy INTERNALS ========
 */

/* Module__ */
typedef struct ti_sysbios_knl_Clock_TimerProxy_Module__ {
    xdc_runtime_Types_Link link;
} ti_sysbios_knl_Clock_TimerProxy_Module__;

/* Module__root__V */
extern ti_sysbios_knl_Clock_TimerProxy_Module__ ti_sysbios_knl_Clock_TimerProxy_Module__root__V;

/* <-- ti_sysbios_family_c28_Timer_Object */

/* Object */
typedef ti_sysbios_family_c28_Timer_Object__ ti_sysbios_knl_Clock_TimerProxy_Object__;

/* Object2__ */
typedef struct {
    xdc_runtime_Types_InstHdr hdr;
    ti_sysbios_knl_Clock_TimerProxy_Object__ obj;
} ti_sysbios_knl_Clock_TimerProxy_Object2__;


/*
 * ======== ti.sysbios.knl.Idle INTERNALS ========
 */


/*
 * ======== ti.sysbios.knl.Intrinsics INTERNALS ========
 */


/*
 * ======== ti.sysbios.knl.Intrinsics_SupportProxy INTERNALS ========
 */


/*
 * ======== ti.sysbios.knl.Queue INTERNALS ========
 */

/* Module__ */
typedef struct ti_sysbios_knl_Queue_Module__ {
    xdc_runtime_Types_Link link;
} ti_sysbios_knl_Queue_Module__;

/* Module__root__V */
extern ti_sysbios_knl_Queue_Module__ ti_sysbios_knl_Queue_Module__root__V;

/* <-- ti_sysbios_knl_Queue_Object */


/*
 * ======== ti.sysbios.knl.Semaphore INTERNALS ========
 */

/* Module__ */
typedef struct ti_sysbios_knl_Semaphore_Module__ {
    xdc_runtime_Types_Link link;
} ti_sysbios_knl_Semaphore_Module__;

/* Module__root__V */
extern ti_sysbios_knl_Semaphore_Module__ ti_sysbios_knl_Semaphore_Module__root__V;

/* <-- ti_sysbios_knl_Semaphore_Object */


/*
 * ======== ti.sysbios.knl.Swi INTERNALS ========
 */

/* Module__ */
typedef struct ti_sysbios_knl_Swi_Module__ {
    xdc_runtime_Types_Link link;
} ti_sysbios_knl_Swi_Module__;

/* Module__root__V */
extern ti_sysbios_knl_Swi_Module__ ti_sysbios_knl_Swi_Module__root__V;

/* Object__ */
typedef struct ti_sysbios_knl_Swi_Object__ {
    ti_sysbios_knl_Queue_Elem qElem;
    ti_sysbios_knl_Swi_FuncPtr fxn;
    xdc_UArg arg0;
    xdc_UArg arg1;
    xdc_UInt priority;
    xdc_UInt mask;
    xdc_Bool posted;
    xdc_UInt initTrigger;
    xdc_UInt trigger;
    ti_sysbios_knl_Queue_Handle readyQ;
    __TA_ti_sysbios_knl_Swi_Instance_State__hookEnv hookEnv;
} ti_sysbios_knl_Swi_Object__;

/* Object2__ */
typedef struct {
    xdc_runtime_Types_InstHdr hdr;
    ti_sysbios_knl_Swi_Object__ obj;
} ti_sysbios_knl_Swi_Object2__;


/*
 * ======== ti.sysbios.knl.Task INTERNALS ========
 */

/* Module__ */
typedef struct ti_sysbios_knl_Task_Module__ {
    xdc_runtime_Types_Link link;
} ti_sysbios_knl_Task_Module__;

/* Module__root__V */
extern ti_sysbios_knl_Task_Module__ ti_sysbios_knl_Task_Module__root__V;

/* <-- ti_sysbios_knl_Queue_Object */

/* Object__ */
typedef struct ti_sysbios_knl_Task_Object__ {
    ti_sysbios_knl_Queue_Elem qElem;
    volatile xdc_Int priority;
    xdc_UInt mask;
    xdc_Ptr context;
    ti_sysbios_knl_Task_Mode mode;
    ti_sysbios_knl_Task_PendElem *pendElem;
    xdc_SizeT stackSize;
    __TA_ti_sysbios_knl_Task_Instance_State__stack stack;
    xdc_runtime_IHeap_Handle stackHeap;
    ti_sysbios_knl_Task_FuncPtr fxn;
    xdc_UArg arg0;
    xdc_UArg arg1;
    xdc_Ptr env;
    __TA_ti_sysbios_knl_Task_Instance_State__hookEnv hookEnv;
    xdc_Bool vitalTaskFlag;
    ti_sysbios_knl_Queue_Handle readyQ;
    xdc_UInt curCoreId;
    xdc_UInt affinity;
    xdc_Bool privileged;
    xdc_Ptr domain;
    xdc_UInt32 checkValue;
    xdc_Ptr tls;
} ti_sysbios_knl_Task_Object__;

/* Object2__ */
typedef struct {
    xdc_runtime_Types_InstHdr hdr;
    ti_sysbios_knl_Task_Object__ obj;
} ti_sysbios_knl_Task_Object2__;


/*
 * ======== ti.sysbios.knl.Task_SupportProxy INTERNALS ========
 */


/*
 * ======== xdc.runtime.Assert INTERNALS ========
 */


/*
 * ======== xdc.runtime.Core INTERNALS ========
 */


/*
 * ======== xdc.runtime.Defaults INTERNALS ========
 */


/*
 * ======== xdc.runtime.Diags INTERNALS ========
 */


/*
 * ======== xdc.runtime.Error INTERNALS ========
 */


/*
 * ======== xdc.runtime.Gate INTERNALS ========
 */


/*
 * ======== xdc.runtime.Log INTERNALS ========
 */


/*
 * ======== xdc.runtime.LoggerBuf INTERNALS ========
 */

/* Module__ */
typedef struct xdc_runtime_LoggerBuf_Module__ {
    xdc_runtime_Types_Link link;
} xdc_runtime_LoggerBuf_Module__;

/* Module__root__V */
extern xdc_runtime_LoggerBuf_Module__ xdc_runtime_LoggerBuf_Module__root__V;

/* Object__ */
typedef struct xdc_runtime_LoggerBuf_Object__ {
    const xdc_runtime_LoggerBuf_Fxns__ *__fxns;
    xdc_runtime_IHeap_Handle bufHeap;
    __TA_xdc_runtime_LoggerBuf_Instance_State__entryArr entryArr;
    xdc_runtime_LoggerBuf_Entry *curEntry;
    xdc_runtime_LoggerBuf_Entry *endEntry;
    xdc_runtime_LoggerBuf_Entry *readEntry;
    xdc_Bits32 serial;
    xdc_UInt16 numEntries;
    xdc_Int8 advance;
    xdc_Bool enabled;
    xdc_Bool flush;
} xdc_runtime_LoggerBuf_Object__;

/* Object2__ */
typedef struct {
    xdc_runtime_Types_InstHdr hdr;
    xdc_runtime_LoggerBuf_Object__ obj;
} xdc_runtime_LoggerBuf_Object2__;


/*
 * ======== xdc.runtime.LoggerBuf_Module_GateProxy INTERNALS ========
 */

/* Module__ */
typedef struct xdc_runtime_LoggerBuf_Module_GateProxy_Module__ {
    xdc_runtime_Types_Link link;
} xdc_runtime_LoggerBuf_Module_GateProxy_Module__;

/* Module__root__V */
extern xdc_runtime_LoggerBuf_Module_GateProxy_Module__ xdc_runtime_LoggerBuf_Module_GateProxy_Module__root__V;

/* <-- ti_sysbios_gates_GateHwi_Object */

/* Object */
typedef ti_sysbios_gates_GateHwi_Object__ xdc_runtime_LoggerBuf_Module_GateProxy_Object__;

/* Object2__ */
typedef struct {
    xdc_runtime_Types_InstHdr hdr;
    xdc_runtime_LoggerBuf_Module_GateProxy_Object__ obj;
} xdc_runtime_LoggerBuf_Module_GateProxy_Object2__;


/*
 * ======== xdc.runtime.LoggerBuf_TimestampProxy INTERNALS ========
 */


/*
 * ======== xdc.runtime.Main INTERNALS ========
 */


/*
 * ======== xdc.runtime.Main_Module_GateProxy INTERNALS ========
 */

/* Module__ */
typedef struct xdc_runtime_Main_Module_GateProxy_Module__ {
    xdc_runtime_Types_Link link;
} xdc_runtime_Main_Module_GateProxy_Module__;

/* Module__root__V */
extern xdc_runtime_Main_Module_GateProxy_Module__ xdc_runtime_Main_Module_GateProxy_Module__root__V;

/* <-- ti_sysbios_gates_GateHwi_Object */

/* Object */
typedef ti_sysbios_gates_GateHwi_Object__ xdc_runtime_Main_Module_GateProxy_Object__;

/* Object2__ */
typedef struct {
    xdc_runtime_Types_InstHdr hdr;
    xdc_runtime_Main_Module_GateProxy_Object__ obj;
} xdc_runtime_Main_Module_GateProxy_Object2__;


/*
 * ======== xdc.runtime.Memory INTERNALS ========
 */


/*
 * ======== xdc.runtime.Memory_HeapProxy INTERNALS ========
 */

/* Module__ */
typedef struct xdc_runtime_Memory_HeapProxy_Module__ {
    xdc_runtime_Types_Link link;
} xdc_runtime_Memory_HeapProxy_Module__;

/* Module__root__V */
extern xdc_runtime_Memory_HeapProxy_Module__ xdc_runtime_Memory_HeapProxy_Module__root__V;

/* <-- ti_sysbios_heaps_HeapMem_Object */

/* Object */
typedef ti_sysbios_heaps_HeapMem_Object__ xdc_runtime_Memory_HeapProxy_Object__;

/* Object2__ */
typedef struct {
    xdc_runtime_Types_InstHdr hdr;
    xdc_runtime_Memory_HeapProxy_Object__ obj;
} xdc_runtime_Memory_HeapProxy_Object2__;


/*
 * ======== xdc.runtime.Registry INTERNALS ========
 */


/*
 * ======== xdc.runtime.Startup INTERNALS ========
 */


/*
 * ======== xdc.runtime.SysMin INTERNALS ========
 */


/*
 * ======== xdc.runtime.System INTERNALS ========
 */


/*
 * ======== xdc.runtime.System_Module_GateProxy INTERNALS ========
 */

/* Module__ */
typedef struct xdc_runtime_System_Module_GateProxy_Module__ {
    xdc_runtime_Types_Link link;
} xdc_runtime_System_Module_GateProxy_Module__;

/* Module__root__V */
extern xdc_runtime_System_Module_GateProxy_Module__ xdc_runtime_System_Module_GateProxy_Module__root__V;

/* <-- ti_sysbios_gates_GateHwi_Object */

/* Object */
typedef ti_sysbios_gates_GateHwi_Object__ xdc_runtime_System_Module_GateProxy_Object__;

/* Object2__ */
typedef struct {
    xdc_runtime_Types_InstHdr hdr;
    xdc_runtime_System_Module_GateProxy_Object__ obj;
} xdc_runtime_System_Module_GateProxy_Object2__;


/*
 * ======== xdc.runtime.System_SupportProxy INTERNALS ========
 */


/*
 * ======== xdc.runtime.Text INTERNALS ========
 */


/*
 * ======== xdc.runtime.Types INTERNALS ========
 */


/*
 * ======== INHERITS ========
 */

#pragma DATA_SECTION(xdc_runtime_ISystemSupport_Interface__BASE__C, ".econst:xdc_runtime_ISystemSupport_Interface__BASE__C");
asm("	.sect \".econst:xdc_runtime_ISystemSupport_Interface__BASE__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_ISystemSupport_Interface__BASE__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_ISystemSupport_Interface__BASE__C\"");
asm("	.clink ");

__FAR__ const xdc_runtime_Types_Base xdc_runtime_ISystemSupport_Interface__BASE__C = {&xdc_runtime_IModule_Interface__BASE__C};

#pragma DATA_SECTION(xdc_runtime_IGateProvider_Interface__BASE__C, ".econst:xdc_runtime_IGateProvider_Interface__BASE__C");
asm("	.sect \".econst:xdc_runtime_IGateProvider_Interface__BASE__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_IGateProvider_Interface__BASE__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_IGateProvider_Interface__BASE__C\"");
asm("	.clink ");

__FAR__ const xdc_runtime_Types_Base xdc_runtime_IGateProvider_Interface__BASE__C = {&xdc_runtime_IModule_Interface__BASE__C};

#pragma DATA_SECTION(xdc_runtime_IModule_Interface__BASE__C, ".econst:xdc_runtime_IModule_Interface__BASE__C");
asm("	.sect \".econst:xdc_runtime_IModule_Interface__BASE__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_IModule_Interface__BASE__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_IModule_Interface__BASE__C\"");
asm("	.clink ");

__FAR__ const xdc_runtime_Types_Base xdc_runtime_IModule_Interface__BASE__C = {NULL};

#pragma DATA_SECTION(xdc_runtime_IFilterLogger_Interface__BASE__C, ".econst:xdc_runtime_IFilterLogger_Interface__BASE__C");
asm("	.sect \".econst:xdc_runtime_IFilterLogger_Interface__BASE__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_IFilterLogger_Interface__BASE__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_IFilterLogger_Interface__BASE__C\"");
asm("	.clink ");

__FAR__ const xdc_runtime_Types_Base xdc_runtime_IFilterLogger_Interface__BASE__C = {&xdc_runtime_ILogger_Interface__BASE__C};

#pragma DATA_SECTION(xdc_runtime_ILogger_Interface__BASE__C, ".econst:xdc_runtime_ILogger_Interface__BASE__C");
asm("	.sect \".econst:xdc_runtime_ILogger_Interface__BASE__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_ILogger_Interface__BASE__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_ILogger_Interface__BASE__C\"");
asm("	.clink ");

__FAR__ const xdc_runtime_Types_Base xdc_runtime_ILogger_Interface__BASE__C = {&xdc_runtime_IModule_Interface__BASE__C};

#pragma DATA_SECTION(xdc_runtime_IHeap_Interface__BASE__C, ".econst:xdc_runtime_IHeap_Interface__BASE__C");
asm("	.sect \".econst:xdc_runtime_IHeap_Interface__BASE__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_IHeap_Interface__BASE__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_IHeap_Interface__BASE__C\"");
asm("	.clink ");

__FAR__ const xdc_runtime_Types_Base xdc_runtime_IHeap_Interface__BASE__C = {&xdc_runtime_IModule_Interface__BASE__C};


/*
 * ======== ti.sysbios.gates.GateHwi VTABLE ========
 */

/* Module__FXNS__C */
#pragma DATA_SECTION(ti_sysbios_gates_GateHwi_Module__FXNS__C, ".econst:ti_sysbios_gates_GateHwi_Module__FXNS__C");
asm("	.sect \".econst:ti_sysbios_gates_GateHwi_Module__FXNS__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_gates_GateHwi_Module__FXNS__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_gates_GateHwi_Module__FXNS__C\"");
asm("	.clink ");

const ti_sysbios_gates_GateHwi_Fxns__ ti_sysbios_gates_GateHwi_Module__FXNS__C = {
    &xdc_runtime_IGateProvider_Interface__BASE__C, /* __base */
    &ti_sysbios_gates_GateHwi_Module__FXNS__C.__sfxns, /* __sysp */
    ti_sysbios_gates_GateHwi_query__E,
    ti_sysbios_gates_GateHwi_enter__E,
    ti_sysbios_gates_GateHwi_leave__E,
    {
        ti_sysbios_gates_GateHwi_Object__create__S,
        ti_sysbios_gates_GateHwi_Object__delete__S,
        ti_sysbios_gates_GateHwi_Handle__label__S,
        0x8023, /* __mid */
    } /* __sfxns */
};


/*
 * ======== ti.sysbios.gates.GateMutex VTABLE ========
 */

/* Module__FXNS__C */
#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_Module__FXNS__C, ".econst:ti_sysbios_gates_GateMutex_Module__FXNS__C");
asm("	.sect \".econst:ti_sysbios_gates_GateMutex_Module__FXNS__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_gates_GateMutex_Module__FXNS__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_gates_GateMutex_Module__FXNS__C\"");
asm("	.clink ");

const ti_sysbios_gates_GateMutex_Fxns__ ti_sysbios_gates_GateMutex_Module__FXNS__C = {
    &xdc_runtime_IGateProvider_Interface__BASE__C, /* __base */
    &ti_sysbios_gates_GateMutex_Module__FXNS__C.__sfxns, /* __sysp */
    ti_sysbios_gates_GateMutex_query__E,
    ti_sysbios_gates_GateMutex_enter__E,
    ti_sysbios_gates_GateMutex_leave__E,
    {
        ti_sysbios_gates_GateMutex_Object__create__S,
        ti_sysbios_gates_GateMutex_Object__delete__S,
        ti_sysbios_gates_GateMutex_Handle__label__S,
        0x8024, /* __mid */
    } /* __sfxns */
};


/*
 * ======== ti.sysbios.heaps.HeapMem VTABLE ========
 */

/* Module__FXNS__C */
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_Module__FXNS__C, ".econst:ti_sysbios_heaps_HeapMem_Module__FXNS__C");
asm("	.sect \".econst:ti_sysbios_heaps_HeapMem_Module__FXNS__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_heaps_HeapMem_Module__FXNS__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_heaps_HeapMem_Module__FXNS__C\"");
asm("	.clink ");

const ti_sysbios_heaps_HeapMem_Fxns__ ti_sysbios_heaps_HeapMem_Module__FXNS__C = {
    &xdc_runtime_IHeap_Interface__BASE__C, /* __base */
    &ti_sysbios_heaps_HeapMem_Module__FXNS__C.__sfxns, /* __sysp */
    ti_sysbios_heaps_HeapMem_alloc__E,
    ti_sysbios_heaps_HeapMem_free__E,
    ti_sysbios_heaps_HeapMem_isBlocking__E,
    ti_sysbios_heaps_HeapMem_getStats__E,
    {
        ti_sysbios_heaps_HeapMem_Object__create__S,
        ti_sysbios_heaps_HeapMem_Object__delete__S,
        ti_sysbios_heaps_HeapMem_Handle__label__S,
        0x8028, /* __mid */
    } /* __sfxns */
};


/*
 * ======== xdc.runtime.LoggerBuf VTABLE ========
 */

/* Module__FXNS__C */
#pragma DATA_SECTION(xdc_runtime_LoggerBuf_Module__FXNS__C, ".econst:xdc_runtime_LoggerBuf_Module__FXNS__C");
asm("	.sect \".econst:xdc_runtime_LoggerBuf_Module__FXNS__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_LoggerBuf_Module__FXNS__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_LoggerBuf_Module__FXNS__C\"");
asm("	.clink ");

const xdc_runtime_LoggerBuf_Fxns__ xdc_runtime_LoggerBuf_Module__FXNS__C = {
    &xdc_runtime_IFilterLogger_Interface__BASE__C, /* __base */
    &xdc_runtime_LoggerBuf_Module__FXNS__C.__sfxns, /* __sysp */
    xdc_runtime_LoggerBuf_enable__E,
    xdc_runtime_LoggerBuf_disable__E,
    xdc_runtime_LoggerBuf_write0__E,
    xdc_runtime_LoggerBuf_write1__E,
    xdc_runtime_LoggerBuf_write2__E,
    xdc_runtime_LoggerBuf_write4__E,
    xdc_runtime_LoggerBuf_write8__E,
    xdc_runtime_LoggerBuf_setFilterLevel__E,
    xdc_runtime_LoggerBuf_getFilterLevel__E,
    {
        xdc_runtime_LoggerBuf_Object__create__S,
        xdc_runtime_LoggerBuf_Object__delete__S,
        xdc_runtime_LoggerBuf_Handle__label__S,
        0x8009, /* __mid */
    } /* __sfxns */
};


/*
 * ======== xdc.runtime.SysMin VTABLE ========
 */

/* Module__FXNS__C */
#pragma DATA_SECTION(xdc_runtime_SysMin_Module__FXNS__C, ".econst:xdc_runtime_SysMin_Module__FXNS__C");
asm("	.sect \".econst:xdc_runtime_SysMin_Module__FXNS__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_SysMin_Module__FXNS__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_SysMin_Module__FXNS__C\"");
asm("	.clink ");

const xdc_runtime_SysMin_Fxns__ xdc_runtime_SysMin_Module__FXNS__C = {
    &xdc_runtime_ISystemSupport_Interface__BASE__C, /* __base */
    &xdc_runtime_SysMin_Module__FXNS__C.__sfxns, /* __sysp */
    xdc_runtime_SysMin_abort__E,
    xdc_runtime_SysMin_exit__E,
    xdc_runtime_SysMin_flush__E,
    xdc_runtime_SysMin_putch__E,
    xdc_runtime_SysMin_ready__E,
    {
        NULL, /* __create */
        NULL, /* __delete */
        NULL, /* __label */
        0x800f, /* __mid */
    } /* __sfxns */
};


/*
 * ======== ti.sysbios.BIOS DECLARATIONS ========
 */

/* Module_State__ */
typedef struct ti_sysbios_BIOS_Module_State__ {
    xdc_runtime_Types_FreqHz cpuFreq;
    xdc_UInt rtsGateCount;
    xdc_IArg rtsGateKey;
    ti_sysbios_BIOS_RtsGateProxy_Handle rtsGate;
    ti_sysbios_BIOS_ThreadType threadType;
    __TA_ti_sysbios_BIOS_Module_State__smpThreadType smpThreadType;
    volatile ti_sysbios_BIOS_StartFuncPtr startFunc;
    volatile ti_sysbios_BIOS_ExitFuncPtr exitFunc;
} ti_sysbios_BIOS_Module_State__;

/* --> ti_sysbios_BIOS_startFunc */
extern xdc_Void ti_sysbios_BIOS_startFunc(xdc_Void);

/* --> ti_sysbios_BIOS_exitFunc */
extern xdc_Void ti_sysbios_BIOS_exitFunc(xdc_Int f_arg0);

/* Module__state__V */
ti_sysbios_BIOS_Module_State__ ti_sysbios_BIOS_Module__state__V;


/*
 * ======== ti.sysbios.BIOS_RtsGateProxy DECLARATIONS ========
 */


/*
 * ======== ti.sysbios.family.c28.Hwi DECLARATIONS ========
 */

/* Object__table__V */
ti_sysbios_family_c28_Hwi_Object__ ti_sysbios_family_c28_Hwi_Object__table__V[1];

/* Module_State__ */
typedef struct ti_sysbios_family_c28_Hwi_Module_State__ {
    xdc_Bits16 ierMask;
    xdc_Char *isrStack;
    xdc_Char *taskSP;
    __TA_ti_sysbios_family_c28_Hwi_Module_State__dispatchTable dispatchTable;
    ti_sysbios_family_c28_Hwi_Irp irp;
    xdc_Bool globalEnable;
    xdc_Bits16 shadowIER;
    xdc_Ptr isrStackBase;
    xdc_Ptr isrStackSize;
} ti_sysbios_family_c28_Hwi_Module_State__;

/* --> ti_sysbios_family_c28_Hwi_Module_State_0_dispatchTable__A */
__T1_ti_sysbios_family_c28_Hwi_Module_State__dispatchTable ti_sysbios_family_c28_Hwi_Module_State_0_dispatchTable__A[224];

/* --> _stack */
extern void* _stack;

/* --> _STACK_SIZE */
extern void* _STACK_SIZE;

/* Module__state__V */
ti_sysbios_family_c28_Hwi_Module_State__ ti_sysbios_family_c28_Hwi_Module__state__V;

/* --> ti_sysbios_knl_Swi_disable__E */
extern xdc_UInt ti_sysbios_knl_Swi_disable__E(xdc_Void);

/* --> ti_sysbios_knl_Swi_restoreHwi__E */
extern xdc_Void ti_sysbios_knl_Swi_restoreHwi__E(xdc_UInt f_arg0);

/* --> ti_sysbios_knl_Task_disable__E */
extern xdc_UInt ti_sysbios_knl_Task_disable__E(xdc_Void);

/* --> ti_sysbios_knl_Task_restoreHwi__E */
extern xdc_Void ti_sysbios_knl_Task_restoreHwi__E(xdc_UInt f_arg0);


/*
 * ======== ti.sysbios.family.c28.IntrinsicsSupport DECLARATIONS ========
 */


/*
 * ======== ti.sysbios.family.c28.TaskSupport DECLARATIONS ========
 */


/*
 * ======== ti.sysbios.family.c28.Timer DECLARATIONS ========
 */

/* Object__table__V */
ti_sysbios_family_c28_Timer_Object__ ti_sysbios_family_c28_Timer_Object__table__V[1];

/* Module_State__ */
typedef struct ti_sysbios_family_c28_Timer_Module_State__ {
    xdc_Char availMask;
    __TA_ti_sysbios_family_c28_Timer_Module_State__staticTimers staticTimers;
} ti_sysbios_family_c28_Timer_Module_State__;

/* Module__state__V */
ti_sysbios_family_c28_Timer_Module_State__ ti_sysbios_family_c28_Timer_Module__state__V;


/*
 * ======== ti.sysbios.family.c28.f2837x.TimestampProvider DECLARATIONS ========
 */


/*
 * ======== ti.sysbios.gates.GateHwi DECLARATIONS ========
 */

/* Object__table__V */
ti_sysbios_gates_GateHwi_Object__ ti_sysbios_gates_GateHwi_Object__table__V[1];


/*
 * ======== ti.sysbios.gates.GateMutex DECLARATIONS ========
 */

/* Object__table__V */
ti_sysbios_gates_GateMutex_Object__ ti_sysbios_gates_GateMutex_Object__table__V[2];


/*
 * ======== ti.sysbios.hal.Hwi DECLARATIONS ========
 */


/*
 * ======== ti.sysbios.hal.Hwi_HwiProxy DECLARATIONS ========
 */


/*
 * ======== ti.sysbios.heaps.HeapMem DECLARATIONS ========
 */

#ifdef __IAR_SYSTEMS_ICC__
    #pragma data_alignment=4
#endif
/* --> ti_sysbios_heaps_HeapMem_Instance_State_0_buf__A */
__T1_ti_sysbios_heaps_HeapMem_Instance_State__buf ti_sysbios_heaps_HeapMem_Instance_State_0_buf__A[2051];
#ifdef __ti__sect
    #pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_Instance_State_0_buf__A, ".ebss:taskStackSection");
#else
#if defined(__GNUC__) && !(defined(__MACH__) && defined(__APPLE__))
__T1_ti_sysbios_heaps_HeapMem_Instance_State__buf ti_sysbios_heaps_HeapMem_Instance_State_0_buf__A[2051] __attribute__ ((section(".ebss:taskStackSection")));
#endif
#endif
#ifdef __ti__align
    #pragma DATA_ALIGN(ti_sysbios_heaps_HeapMem_Instance_State_0_buf__A, 4);
#else
#if defined(__GNUC__)
__T1_ti_sysbios_heaps_HeapMem_Instance_State__buf ti_sysbios_heaps_HeapMem_Instance_State_0_buf__A[2051] __attribute__ ((aligned(4)));
#endif
#endif

/* Object__table__V */
ti_sysbios_heaps_HeapMem_Object__ ti_sysbios_heaps_HeapMem_Object__table__V[1];


/*
 * ======== ti.sysbios.heaps.HeapMem_Module_GateProxy DECLARATIONS ========
 */


/*
 * ======== ti.sysbios.knl.Clock DECLARATIONS ========
 */

/* --> DoEverySecond */
extern xdc_Void DoEverySecond(xdc_UArg f_arg0);

/* Object__table__V */
ti_sysbios_knl_Clock_Object__ ti_sysbios_knl_Clock_Object__table__V[1];

/* Module_State__ */
typedef struct ti_sysbios_knl_Clock_Module_State__ {
    volatile xdc_UInt32 ticks;
    xdc_UInt swiCount;
    ti_sysbios_knl_Clock_TimerProxy_Handle timer;
    ti_sysbios_knl_Swi_Handle swi;
    volatile xdc_UInt numTickSkip;
    xdc_UInt32 nextScheduledTick;
    xdc_UInt32 maxSkippable;
    xdc_Bool inWorkFunc;
    volatile xdc_Bool startDuringWorkFunc;
    xdc_Bool ticking;
    ti_sysbios_knl_Queue_Object__ Object_field_clockQ;
} ti_sysbios_knl_Clock_Module_State__;

/* Module__state__V */
ti_sysbios_knl_Clock_Module_State__ ti_sysbios_knl_Clock_Module__state__V;

/* --> ti_sysbios_knl_Clock_doTick__I */
extern xdc_Void ti_sysbios_knl_Clock_doTick__I(xdc_UArg f_arg0);


/*
 * ======== ti.sysbios.knl.Clock_TimerProxy DECLARATIONS ========
 */


/*
 * ======== ti.sysbios.knl.Idle DECLARATIONS ========
 */

/* --> ti_sysbios_hal_Hwi_checkStack */
extern xdc_Void ti_sysbios_hal_Hwi_checkStack(xdc_Void);

/* --> ti_sysbios_knl_Idle_funcList__A */
const __T1_ti_sysbios_knl_Idle_funcList ti_sysbios_knl_Idle_funcList__A[1];

/* --> ti_sysbios_knl_Idle_coreList__A */
const __T1_ti_sysbios_knl_Idle_coreList ti_sysbios_knl_Idle_coreList__A[1];


/*
 * ======== ti.sysbios.knl.Intrinsics DECLARATIONS ========
 */


/*
 * ======== ti.sysbios.knl.Intrinsics_SupportProxy DECLARATIONS ========
 */


/*
 * ======== ti.sysbios.knl.Queue DECLARATIONS ========
 */


/*
 * ======== ti.sysbios.knl.Semaphore DECLARATIONS ========
 */


/*
 * ======== ti.sysbios.knl.Swi DECLARATIONS ========
 */

/* Object__table__V */
ti_sysbios_knl_Swi_Object__ ti_sysbios_knl_Swi_Object__table__V[1];

/* Module_State__ */
typedef struct ti_sysbios_knl_Swi_Module_State__ {
    volatile xdc_Bool locked;
    xdc_UInt curSet;
    xdc_UInt curTrigger;
    ti_sysbios_knl_Swi_Handle curSwi;
    ti_sysbios_knl_Queue_Handle curQ;
    __TA_ti_sysbios_knl_Swi_Module_State__readyQ readyQ;
    __TA_ti_sysbios_knl_Swi_Module_State__constructedSwis constructedSwis;
} ti_sysbios_knl_Swi_Module_State__;

/* --> ti_sysbios_knl_Swi_Module_State_0_readyQ__A */
__T1_ti_sysbios_knl_Swi_Module_State__readyQ ti_sysbios_knl_Swi_Module_State_0_readyQ__A[16];

/* Module__state__V */
ti_sysbios_knl_Swi_Module_State__ ti_sysbios_knl_Swi_Module__state__V;

/* --> ti_sysbios_knl_Task_disable__E */
extern xdc_UInt ti_sysbios_knl_Task_disable__E(xdc_Void);

/* --> ti_sysbios_knl_Task_restore__E */
extern xdc_Void ti_sysbios_knl_Task_restore__E(xdc_UInt f_arg0);


/*
 * ======== ti.sysbios.knl.Task DECLARATIONS ========
 */

#ifdef __IAR_SYSTEMS_ICC__
    #pragma data_alignment=2
#endif
/* --> ti_sysbios_knl_Task_Instance_State_0_stack__A */
__T1_ti_sysbios_knl_Task_Instance_State__stack ti_sysbios_knl_Task_Instance_State_0_stack__A[256];
#ifdef __ti__sect
    #pragma DATA_SECTION(ti_sysbios_knl_Task_Instance_State_0_stack__A, ".ebss:taskStackSection");
#else
#if defined(__GNUC__) && !(defined(__MACH__) && defined(__APPLE__))
__T1_ti_sysbios_knl_Task_Instance_State__stack ti_sysbios_knl_Task_Instance_State_0_stack__A[256] __attribute__ ((section(".ebss:taskStackSection")));
#endif
#endif
#ifdef __ti__align
    #pragma DATA_ALIGN(ti_sysbios_knl_Task_Instance_State_0_stack__A, 2);
#else
#if defined(__GNUC__)
__T1_ti_sysbios_knl_Task_Instance_State__stack ti_sysbios_knl_Task_Instance_State_0_stack__A[256] __attribute__ ((aligned(2)));
#endif
#endif

/* Object__table__V */
ti_sysbios_knl_Task_Object__ ti_sysbios_knl_Task_Object__table__V[1];

/* Module_State__ */
typedef struct ti_sysbios_knl_Task_Module_State__ {
    volatile xdc_Bool locked;
    volatile xdc_UInt curSet;
    volatile xdc_Bool workFlag;
    xdc_UInt vitalTasks;
    ti_sysbios_knl_Task_Handle curTask;
    ti_sysbios_knl_Queue_Handle curQ;
    __TA_ti_sysbios_knl_Task_Module_State__readyQ readyQ;
    __TA_ti_sysbios_knl_Task_Module_State__smpCurSet smpCurSet;
    __TA_ti_sysbios_knl_Task_Module_State__smpCurMask smpCurMask;
    __TA_ti_sysbios_knl_Task_Module_State__smpCurTask smpCurTask;
    __TA_ti_sysbios_knl_Task_Module_State__smpReadyQ smpReadyQ;
    __TA_ti_sysbios_knl_Task_Module_State__idleTask idleTask;
    __TA_ti_sysbios_knl_Task_Module_State__constructedTasks constructedTasks;
    xdc_Bool curTaskPrivileged;
    ti_sysbios_knl_Queue_Object__ Object_field_inactiveQ;
    ti_sysbios_knl_Queue_Object__ Object_field_terminatedQ;
} ti_sysbios_knl_Task_Module_State__;

/* --> ti_sysbios_knl_Task_Module_State_0_readyQ__A */
__T1_ti_sysbios_knl_Task_Module_State__readyQ ti_sysbios_knl_Task_Module_State_0_readyQ__A[16];

/* --> ti_sysbios_knl_Task_Module_State_0_idleTask__A */
__T1_ti_sysbios_knl_Task_Module_State__idleTask ti_sysbios_knl_Task_Module_State_0_idleTask__A[1];

/* Module__state__V */
ti_sysbios_knl_Task_Module_State__ ti_sysbios_knl_Task_Module__state__V;


/*
 * ======== ti.sysbios.knl.Task_SupportProxy DECLARATIONS ========
 */


/*
 * ======== xdc.runtime.Assert DECLARATIONS ========
 */


/*
 * ======== xdc.runtime.Core DECLARATIONS ========
 */


/*
 * ======== xdc.runtime.Defaults DECLARATIONS ========
 */


/*
 * ======== xdc.runtime.Diags DECLARATIONS ========
 */


/*
 * ======== xdc.runtime.Error DECLARATIONS ========
 */

/* Module_State__ */
typedef struct xdc_runtime_Error_Module_State__ {
    xdc_UInt16 count;
} xdc_runtime_Error_Module_State__;

/* Module__state__V */
xdc_runtime_Error_Module_State__ xdc_runtime_Error_Module__state__V;


/*
 * ======== xdc.runtime.Gate DECLARATIONS ========
 */


/*
 * ======== xdc.runtime.Log DECLARATIONS ========
 */


/*
 * ======== xdc.runtime.LoggerBuf DECLARATIONS ========
 */

/* --> xdc_runtime_LoggerBuf_Instance_State_0_entryArr__A */
__T1_xdc_runtime_LoggerBuf_Instance_State__entryArr xdc_runtime_LoggerBuf_Instance_State_0_entryArr__A[32];

/* Object__table__V */
xdc_runtime_LoggerBuf_Object__ xdc_runtime_LoggerBuf_Object__table__V[1];

/* Module_State__ */
typedef struct xdc_runtime_LoggerBuf_Module_State__ {
    xdc_runtime_Diags_Mask level1;
    xdc_runtime_Diags_Mask level2;
    xdc_runtime_Diags_Mask level3;
} xdc_runtime_LoggerBuf_Module_State__;

/* Module__state__V */
xdc_runtime_LoggerBuf_Module_State__ xdc_runtime_LoggerBuf_Module__state__V;


/*
 * ======== xdc.runtime.LoggerBuf_Module_GateProxy DECLARATIONS ========
 */


/*
 * ======== xdc.runtime.LoggerBuf_TimestampProxy DECLARATIONS ========
 */


/*
 * ======== xdc.runtime.Main DECLARATIONS ========
 */


/*
 * ======== xdc.runtime.Main_Module_GateProxy DECLARATIONS ========
 */


/*
 * ======== xdc.runtime.Memory DECLARATIONS ========
 */

/* Module_State__ */
typedef struct xdc_runtime_Memory_Module_State__ {
    xdc_SizeT maxDefaultTypeAlign;
} xdc_runtime_Memory_Module_State__;

/* Module__state__V */
xdc_runtime_Memory_Module_State__ xdc_runtime_Memory_Module__state__V;


/*
 * ======== xdc.runtime.Memory_HeapProxy DECLARATIONS ========
 */


/*
 * ======== xdc.runtime.Registry DECLARATIONS ========
 */

/* Module_State__ */
typedef struct xdc_runtime_Registry_Module_State__ {
    xdc_runtime_Registry_Desc *listHead;
    xdc_runtime_Types_ModuleId curId;
} xdc_runtime_Registry_Module_State__;

/* Module__state__V */
xdc_runtime_Registry_Module_State__ xdc_runtime_Registry_Module__state__V;


/*
 * ======== xdc.runtime.Startup DECLARATIONS ========
 */

/* Module_State__ */
typedef struct xdc_runtime_Startup_Module_State__ {
    xdc_Int *stateTab;
    xdc_Bool execFlag;
    xdc_Bool rtsDoneFlag;
} xdc_runtime_Startup_Module_State__;

/* Module__state__V */
xdc_runtime_Startup_Module_State__ xdc_runtime_Startup_Module__state__V;

/* --> ti_catalog_c2800_initF2837x_Boot_initStartup */
extern xdc_Void ti_catalog_c2800_initF2837x_Boot_initStartup(xdc_Void);

/* --> ti_sysbios_hal_Hwi_initStack */
extern xdc_Void ti_sysbios_hal_Hwi_initStack(xdc_Void);

/* --> xdc_runtime_Startup_firstFxns__A */
const __T1_xdc_runtime_Startup_firstFxns xdc_runtime_Startup_firstFxns__A[3];

/* --> xdc_runtime_LoggerBuf_Module_startup__E */
extern xdc_Int xdc_runtime_LoggerBuf_Module_startup__E(xdc_Int f_arg0);

/* --> xdc_runtime_System_Module_startup__E */
extern xdc_Int xdc_runtime_System_Module_startup__E(xdc_Int f_arg0);

/* --> xdc_runtime_SysMin_Module_startup__E */
extern xdc_Int xdc_runtime_SysMin_Module_startup__E(xdc_Int f_arg0);

/* --> ti_sysbios_family_c28_Hwi_Module_startup__E */
extern xdc_Int ti_sysbios_family_c28_Hwi_Module_startup__E(xdc_Int f_arg0);

/* --> ti_sysbios_family_c28_Timer_Module_startup__E */
extern xdc_Int ti_sysbios_family_c28_Timer_Module_startup__E(xdc_Int f_arg0);

/* --> ti_sysbios_knl_Clock_Module_startup__E */
extern xdc_Int ti_sysbios_knl_Clock_Module_startup__E(xdc_Int f_arg0);

/* --> ti_sysbios_knl_Swi_Module_startup__E */
extern xdc_Int ti_sysbios_knl_Swi_Module_startup__E(xdc_Int f_arg0);

/* --> ti_sysbios_knl_Task_Module_startup__E */
extern xdc_Int ti_sysbios_knl_Task_Module_startup__E(xdc_Int f_arg0);

/* --> ti_sysbios_hal_Hwi_Module_startup__E */
extern xdc_Int ti_sysbios_hal_Hwi_Module_startup__E(xdc_Int f_arg0);

/* --> xdc_runtime_Startup_sfxnTab__A */
const __T1_xdc_runtime_Startup_sfxnTab xdc_runtime_Startup_sfxnTab__A[9];

/* --> xdc_runtime_Startup_sfxnRts__A */
const __T1_xdc_runtime_Startup_sfxnRts xdc_runtime_Startup_sfxnRts__A[9];


/*
 * ======== xdc.runtime.SysMin DECLARATIONS ========
 */

/* Module_State__ */
typedef struct xdc_runtime_SysMin_Module_State__ {
    __TA_xdc_runtime_SysMin_Module_State__outbuf outbuf;
    xdc_UInt outidx;
    xdc_Bool wrapped;
} xdc_runtime_SysMin_Module_State__;

/* --> xdc_runtime_SysMin_Module_State_0_outbuf__A */
__T1_xdc_runtime_SysMin_Module_State__outbuf xdc_runtime_SysMin_Module_State_0_outbuf__A[512];

/* Module__state__V */
xdc_runtime_SysMin_Module_State__ xdc_runtime_SysMin_Module__state__V;

/* --> xdc_runtime_SysMin_output__I */
extern xdc_Void xdc_runtime_SysMin_output__I(xdc_Char* f_arg0,xdc_UInt f_arg1);


/*
 * ======== xdc.runtime.System DECLARATIONS ========
 */

/* Module_State__ */
typedef struct xdc_runtime_System_Module_State__ {
    __TA_xdc_runtime_System_Module_State__atexitHandlers atexitHandlers;
    xdc_Int numAtexitHandlers;
} xdc_runtime_System_Module_State__;

/* --> xdc_runtime_System_Module_State_0_atexitHandlers__A */
__T1_xdc_runtime_System_Module_State__atexitHandlers xdc_runtime_System_Module_State_0_atexitHandlers__A[4];

/* Module__state__V */
xdc_runtime_System_Module_State__ xdc_runtime_System_Module__state__V;

/* --> xdc_runtime_System_printfExtend__I */
extern xdc_Int xdc_runtime_System_printfExtend__I(xdc_Char** f_arg0,xdc_CString* f_arg1,xdc_VaList* f_arg2,xdc_runtime_System_ParseData* f_arg3);


/*
 * ======== xdc.runtime.System_Module_GateProxy DECLARATIONS ========
 */


/*
 * ======== xdc.runtime.System_SupportProxy DECLARATIONS ========
 */


/*
 * ======== xdc.runtime.Text DECLARATIONS ========
 */

/* Module_State__ */
typedef struct xdc_runtime_Text_Module_State__ {
    xdc_CPtr charBase;
    xdc_CPtr nodeBase;
} xdc_runtime_Text_Module_State__;

/* Module__state__V */
xdc_runtime_Text_Module_State__ xdc_runtime_Text_Module__state__V;

/* --> xdc_runtime_Text_charTab__A */
const __T1_xdc_runtime_Text_charTab xdc_runtime_Text_charTab__A[6056];

/* --> xdc_runtime_Text_nodeTab__A */
const __T1_xdc_runtime_Text_nodeTab xdc_runtime_Text_nodeTab__A[43];


/*
 * ======== xdc.runtime.Types DECLARATIONS ========
 */


/*
 * ======== OBJECT OFFSETS ========
 */

#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_Instance_State_sem__O, ".econst:ti_sysbios_gates_GateMutex_Instance_State_sem__O");
asm("	.sect \".econst:ti_sysbios_gates_GateMutex_Instance_State_sem__O\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_gates_GateMutex_Instance_State_sem__O\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_gates_GateMutex_Instance_State_sem__O\"");
asm("	.clink ");

__FAR__ const xdc_SizeT ti_sysbios_gates_GateMutex_Instance_State_sem__O = offsetof(ti_sysbios_gates_GateMutex_Object__,Object_field_sem);


/*
 * ======== OBJECT OFFSETS ========
 */

#pragma DATA_SECTION(ti_sysbios_knl_Clock_Module_State_clockQ__O, ".econst:ti_sysbios_knl_Clock_Module_State_clockQ__O");
asm("	.sect \".econst:ti_sysbios_knl_Clock_Module_State_clockQ__O\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Clock_Module_State_clockQ__O\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Clock_Module_State_clockQ__O\"");
asm("	.clink ");

__FAR__ const xdc_SizeT ti_sysbios_knl_Clock_Module_State_clockQ__O = offsetof(ti_sysbios_knl_Clock_Module_State__,Object_field_clockQ);


/*
 * ======== OBJECT OFFSETS ========
 */

#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_Instance_State_pendQ__O, ".econst:ti_sysbios_knl_Semaphore_Instance_State_pendQ__O");
asm("	.sect \".econst:ti_sysbios_knl_Semaphore_Instance_State_pendQ__O\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Semaphore_Instance_State_pendQ__O\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Semaphore_Instance_State_pendQ__O\"");
asm("	.clink ");

__FAR__ const xdc_SizeT ti_sysbios_knl_Semaphore_Instance_State_pendQ__O = offsetof(ti_sysbios_knl_Semaphore_Object__,Object_field_pendQ);


/*
 * ======== OBJECT OFFSETS ========
 */

#pragma DATA_SECTION(ti_sysbios_knl_Task_Module_State_inactiveQ__O, ".econst:ti_sysbios_knl_Task_Module_State_inactiveQ__O");
asm("	.sect \".econst:ti_sysbios_knl_Task_Module_State_inactiveQ__O\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Task_Module_State_inactiveQ__O\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Task_Module_State_inactiveQ__O\"");
asm("	.clink ");

__FAR__ const xdc_SizeT ti_sysbios_knl_Task_Module_State_inactiveQ__O = offsetof(ti_sysbios_knl_Task_Module_State__,Object_field_inactiveQ);
#pragma DATA_SECTION(ti_sysbios_knl_Task_Module_State_terminatedQ__O, ".econst:ti_sysbios_knl_Task_Module_State_terminatedQ__O");
asm("	.sect \".econst:ti_sysbios_knl_Task_Module_State_terminatedQ__O\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Task_Module_State_terminatedQ__O\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Task_Module_State_terminatedQ__O\"");
asm("	.clink ");

__FAR__ const xdc_SizeT ti_sysbios_knl_Task_Module_State_terminatedQ__O = offsetof(ti_sysbios_knl_Task_Module_State__,Object_field_terminatedQ);


/*
 * ======== xdc.cfg.Program TEMPLATE ========
 */

/*
 *  ======== __ASM__ ========
 *  Define absolute path prefix for this executable's
 *  configuration generated files.
 */
xdc__META(__ASM__, "@(#)__ASM__ = C:/Github_Repo/DSP_TI_TMS320F28379D/F28379D_Projects/demo_rtos_cpu1/Debug/configPkg/package/cfg/demo_rtos_cpu1_p28FP");

/*
 *  ======== __ISA__ ========
 *  Define the ISA of this executable.  This symbol is used by platform
 *  specific "exec" commands that support more than one ISA; e.g., gdb
 */
xdc__META(__ISA__, "@(#)__ISA__ = 28FP");

/*
 *  ======== __PLAT__ ========
 *  Define the name of the platform that can run this executable.  This
 *  symbol is used by platform independent "exec" commands
 */
xdc__META(__PLAT__, "@(#)__PLAT__ = ti.platforms.tms320x28");

/*
 *  ======== __TARG__ ========
 *  Define the name of the target used to build this executable.
 */
xdc__META(__TARG__, "@(#)__TARG__ = ti.targets.C28_float");

/*
 *  ======== __TRDR__ ========
 *  Define the name of the class that can read/parse this executable.
 */
xdc__META(__TRDR__, "@(#)__TRDR__ = ti.targets.omf.cof.Coff");


/*
 * ======== xdc.cfg.SourceDir TEMPLATE ========
 */



/*
 * ======== xdc.runtime.Diags TEMPLATE ========
 */



/*
 * ======== xdc.runtime.Error TEMPLATE ========
 */


xdc_runtime_Error_Block xdc_runtime_Error_IgnoreBlock = {
    (unsigned short)(~0U), /* unused */
    {
        {0, 0} /* data */
    },
    0,  /* id */
    NULL,  /* msg */
    {
        0,  /* mod */
        NULL,  /* file */
        0   /* line */
    }
};

/*
 *  ======== Error_policyLog ========
 */
Void xdc_runtime_Error_policyLog__I(xdc_runtime_Types_ModuleId mod,
    CString file, Int line, CString msg, IArg arg1, IArg arg2)
{
    /*
     * Log the error, now that we've retrieved the error message.
     *
     * We call Log_put here instead of Log_write so that we can log the
     * caller's module id instead of the Error module's id.
     *
     * In logging this event, we'll use the Error module's mask and logger. We
     * don't have a way to reliably access the caller's diags mask and logger.
     * The caller isn't guaranteed to have a mask on the target, even if they
     * are performing logging.
     */
#undef Module__DGSINCL
#define Module__DGSINCL xdc_runtime_Error_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB xdc_runtime_Error_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK xdc_runtime_Error_Module__diagsMask__C
#undef Module__LOGOBJ
#define Module__LOGOBJ xdc_runtime_Error_Module__loggerObj__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 xdc_runtime_Error_Module__loggerFxn8__C

    if (xdc_runtime_Diags_query(xdc_runtime_Log_L_error)) {
        xdc_runtime_Log_put8(xdc_runtime_Log_L_error, mod, (IArg) file, line,
                 (IArg) msg, arg1, arg2, 0, 0, 0);
    }
}

/*
 * ======== xdc.runtime.Startup TEMPLATE ========
 */

/*
 *  ======== MODULE STARTUP DONE FUNCTIONS ========
 */
/* REQ_TAG(SYSBIOS-953) */
xdc_Bool xdc_runtime_LoggerBuf_Module__startupDone__F(void); /* keep GCC prototype warning quiet */
xdc_Bool xdc_runtime_LoggerBuf_Module__startupDone__F(void) {
    return (xdc_Bool)((&xdc_runtime_Startup_Module__state__V)->stateTab == NULL || (&xdc_runtime_Startup_Module__state__V)->stateTab[0] < 0);
}
xdc_Bool xdc_runtime_System_Module__startupDone__F(void); /* keep GCC prototype warning quiet */
xdc_Bool xdc_runtime_System_Module__startupDone__F(void) {
    return (xdc_Bool)((&xdc_runtime_Startup_Module__state__V)->stateTab == NULL || (&xdc_runtime_Startup_Module__state__V)->stateTab[1] < 0);
}
xdc_Bool xdc_runtime_SysMin_Module__startupDone__F(void); /* keep GCC prototype warning quiet */
xdc_Bool xdc_runtime_SysMin_Module__startupDone__F(void) {
    return (xdc_Bool)((&xdc_runtime_Startup_Module__state__V)->stateTab == NULL || (&xdc_runtime_Startup_Module__state__V)->stateTab[2] < 0);
}
xdc_Bool ti_sysbios_family_c28_Hwi_Module__startupDone__F(void); /* keep GCC prototype warning quiet */
xdc_Bool ti_sysbios_family_c28_Hwi_Module__startupDone__F(void) {
    return (xdc_Bool)((&xdc_runtime_Startup_Module__state__V)->stateTab == NULL || (&xdc_runtime_Startup_Module__state__V)->stateTab[3] < 0);
}
xdc_Bool ti_sysbios_family_c28_Timer_Module__startupDone__F(void); /* keep GCC prototype warning quiet */
xdc_Bool ti_sysbios_family_c28_Timer_Module__startupDone__F(void) {
    return (xdc_Bool)((&xdc_runtime_Startup_Module__state__V)->stateTab == NULL || (&xdc_runtime_Startup_Module__state__V)->stateTab[4] < 0);
}
xdc_Bool ti_sysbios_knl_Clock_Module__startupDone__F(void); /* keep GCC prototype warning quiet */
xdc_Bool ti_sysbios_knl_Clock_Module__startupDone__F(void) {
    return (xdc_Bool)((&xdc_runtime_Startup_Module__state__V)->stateTab == NULL || (&xdc_runtime_Startup_Module__state__V)->stateTab[5] < 0);
}
xdc_Bool ti_sysbios_knl_Swi_Module__startupDone__F(void); /* keep GCC prototype warning quiet */
xdc_Bool ti_sysbios_knl_Swi_Module__startupDone__F(void) {
    return (xdc_Bool)((&xdc_runtime_Startup_Module__state__V)->stateTab == NULL || (&xdc_runtime_Startup_Module__state__V)->stateTab[6] < 0);
}
xdc_Bool ti_sysbios_knl_Task_Module__startupDone__F(void); /* keep GCC prototype warning quiet */
xdc_Bool ti_sysbios_knl_Task_Module__startupDone__F(void) {
    return (xdc_Bool)((&xdc_runtime_Startup_Module__state__V)->stateTab == NULL || (&xdc_runtime_Startup_Module__state__V)->stateTab[7] < 0);
}
xdc_Bool ti_sysbios_hal_Hwi_Module__startupDone__F(void); /* keep GCC prototype warning quiet */
xdc_Bool ti_sysbios_hal_Hwi_Module__startupDone__F(void) {
    return (xdc_Bool)((&xdc_runtime_Startup_Module__state__V)->stateTab == NULL || (&xdc_runtime_Startup_Module__state__V)->stateTab[8] < 0);
}


/*
 * Startup_exec__I is an internal entry point called by target/platform boot
 * code. Boot code is not brought into a partial-link assembly. So, without this
 * pragma, whole program optimizers would otherwise optimize-out this function.
 */
#ifdef __ti__sect
#pragma FUNC_EXT_CALLED(xdc_runtime_Startup_exec__I);
#endif

#ifdef __GNUC__
#if defined(__clang__) && defined(__ti__)
xdc_Void xdc_runtime_Startup_exec__I(void) __attribute__ ((used));
#else
xdc_Void xdc_runtime_Startup_exec__I(void) __attribute__ ((externally_visible));
#endif
#endif

/*
 *  ======== xdc_runtime_Startup_exec__I ========
 *  Initialize all used modules that have startup functions
 */
/* REQ_TAG(SYSBIOS-949) */
xdc_Void xdc_runtime_Startup_exec__I(void)
{
    xdc_Int state[9];
    xdc_runtime_Startup_startModsFxn__C(state, 9);
}

/*
 * ======== xdc.runtime.Reset TEMPLATE ========
 */

/*
 * Startup_reset__I is an internal entry point called by target/platform boot
 * code. Boot code is not brought into a partial-link assembly. So, without this
 * pragma, whole program optimizers would otherwise optimize-out this function.
 */
#ifdef __ti__sect
#pragma FUNC_EXT_CALLED(xdc_runtime_Startup_reset__I);
#endif

#ifdef __GNUC__
#if defined(__clang__) && defined (__ti__)
xdc_Void xdc_runtime_Startup_reset__I(void) __attribute__ ((used));
#else
xdc_Void xdc_runtime_Startup_reset__I(void) __attribute__ ((externally_visible));
#endif
#endif

extern xdc_Void ti_catalog_c2800_initF2837x_Boot_init(void);  /* user defined reset function */

/*
 *  ======== xdc_runtime_Startup_reset__I ========
 *  This function is called by bootstrap initialization code as early as
 *  possible in the startup process.  This function calls all functions in
 *  the Reset.fxns array _as well as_ Startup.resetFxn (if it's non-NULL)
 */
xdc_Void xdc_runtime_Startup_reset__I(void)
{
    ti_catalog_c2800_initF2837x_Boot_init();
}

/*
 * ======== xdc.runtime.System TEMPLATE ========
 */


#include <xdc/std.h>
#include <limits.h>
#include <xdc/runtime/Types.h>

#include <xdc/runtime/System.h>
#include <xdc/runtime/System__internal.h>

/*
 *  ======== System_printfExtend__I ========
 *  This function processes optional extended formats of printf.
 *
 *  It returns the number of characters added to the result.
 *
 *  Precision (maximum string length) is not supported for %$S.
 *
 *  Right-justified (which is default) minimum width is not supported
 *  for %$L, %$S, or %$F.
 */
xdc_Int xdc_runtime_System_printfExtend__I(xdc_Char **pbuf, xdc_CString *pfmt,
    xdc_VaList *pva, xdc_runtime_System_ParseData *parse)
{
    xdc_Int     res;
    xdc_Char    c;
    xdc_Bool    found = FALSE;

    /*
     * Create a local variable 'va' to ensure that the dereference of
     * pva only occurs once.
     */
    va_list va = *pva;

    res = 0;

    c = **pfmt;
    *pfmt = *pfmt + 1;


    if (c == '$') {
        c = **pfmt;
        *pfmt = *pfmt + 1;

        if (c == 'L') {
            xdc_runtime_Types_Label *lab = (parse->aFlag == TRUE) ?
                (xdc_runtime_Types_Label *)xdc_iargToPtr(va_arg(va, xdc_IArg)) :
                (xdc_runtime_Types_Label *)va_arg(va, void *);

            /*
             * Call Text_putLab to write out the label, taking the precision
             * into account.
             */
            res = xdc_runtime_Text_putLab(lab, pbuf, parse->precis);

            /*
             * Set the length to 0 to indicate to 'doPrint' that nothing should
             * be copied from parse.ptr.
             */
            parse->len = 0;

            /* Update the minimum width field. */
            parse->width -= res;

            found = TRUE;
        }

        if (c == 'F') {
            xdc_runtime_Types_Site site;

            /* Retrieve the file name string from the argument list */
            site.file = (parse->aFlag == TRUE) ?
                (xdc_Char *) xdc_iargToPtr(va_arg(va, xdc_IArg)) :
                (xdc_Char *) va_arg(va, xdc_Char *);

            /* Retrieve the line number from the argument list. */
            site.line = (parse->aFlag == TRUE) ?
                (xdc_Int) va_arg(va, xdc_IArg) :
                (xdc_Int) va_arg(va, xdc_Int);

            /*
             * Omit the 'mod' field, set it to 0.
             * '0' is a safe sentinel value - the IDs for named modules are
             * 0x8000 and higher, and the IDs for unnamed modules go from 0x1
             * to 0x7fff.
             */
            site.mod = 0;

            /*
             * Call putSite to format the file and line number.
             * If a precision was specified, it will be used as the maximum
             * string length.
             */
            res = xdc_runtime_Text_putSite(&site, pbuf, parse->precis);

            /*
             * Set the length to 0 to indicate to 'doPrint' that nothing should
             * be copied from parse.ptr.
             */
            parse->len = 0;

            /* Update the minimum width field */
            parse->width -= res;

            found = TRUE;
        }

        if (c == 'S') {
            /* Retrieve the format string from the argument list */
            parse->ptr = (parse->aFlag == TRUE) ?
                (xdc_Char *) xdc_iargToPtr(va_arg(va, xdc_IArg)) :
                (xdc_Char *) va_arg(va, xdc_Char *);

            /* Update pva before passing it to doPrint. */
            *pva = va;

            /* Perform the recursive format. System_doPrint does not advance
             * the buffer pointer, so it has to be done explicitly.
             * System_doPrint guarantees that parse->precis is positive.
             */
            res = xdc_runtime_System_doPrint__I(*pbuf, (xdc_SizeT)parse->precis,
                                                parse->ptr, pva, parse->aFlag);

            if (*pbuf != NULL) {
                if (res >= parse->precis) {
                    /* Not enough space for all characters, only
                     * (parse->precis - 1) and '\0' were printed.
                     */
                    res = parse->precis - 1;
                }
                *pbuf += res;
            }

            /* Update the temporary variable with any changes to *pva */
            va = *pva;

            /*
             * Set the length to 0 to indicate to 'doPrint' that nothing should
             * be copied from parse.ptr
             */
            parse->len = 0;

            /* Update the minimum width field */
            parse->width -= res;

            /* Indicate that we were able to interpret the specifier */
            found = TRUE;
        }

    }

    if (c == 'f') {
        /* support arguments _after_ optional float support */
        if (parse->aFlag == TRUE) {
            (void)va_arg(va, xdc_IArg);
        }
        else {
            (void)va_arg(va, double);
        }
    }

    if (found == FALSE) {
        /* other character (like %) copy to output */
        *(parse->ptr) = c;
        parse->len = 1;
    }

    /*
     * Before returning, we must update the value of pva. We use a label here
     * so that all return points will go through this update.
     * The 'goto end' is here to ensure that there is always a reference to the
     * label (to avoid the compiler complaining).
     */
    goto end;
end:
    *pva = va;
    return (res);
}

/*
 * ======== xdc.runtime.SysMin TEMPLATE ========
 */


#if defined(__ti__)
extern int HOSTwrite(int, const char *, unsigned);
#elif (defined(gnu_targets_STD_) && defined(xdc_target__os_undefined))
extern int _write(int, char *, int);
#define HOSTwrite(x,y,z) _write((int)(x),(char *)(y),(int)(z))
#elif defined(__IAR_SYSTEMS_ICC__)
#include <yfuns.h>
#define HOSTwrite(x,y,z) __write((x),(unsigned char *)(y),(z))
#else
#include <stdio.h>
#endif

/*
 *  ======== SysMin_output__I ========
 *  HOSTWrite only writes a max of N chars at a time. The amount it writes
 *  is returned. This function loops until the entire buffer is written.
 *  Being a static function allows it to conditionally compile out.
 */
xdc_Void xdc_runtime_SysMin_output__I(xdc_Char *buf, xdc_UInt size)
{
#if defined(__ti__) || (defined(gnu_targets_STD_) && defined(xdc_target__os_undefined)) || defined (__IAR_SYSTEMS_ICC__)
    xdc_Int printCount;
    
    while (size != 0) {
        printCount = HOSTwrite(1, buf, size);
        if ((printCount <= 0) || ((xdc_UInt)printCount > size)) {
            break;  /* ensure we never get stuck in an infinite loop */
        }
        size -= printCount;
        buf = buf + printCount;
    }    
#else
    fwrite(buf, 1, size, stdout);
#endif
}

/*
 * ======== xdc.runtime.Text TEMPLATE ========
 */

/*
 *  ======== xdc_runtime_Text_visitRope__I ========
 *  This function is indirectly called within Text.c through
 *  the visitRopeFxn configuration parameter of xdc.runtime.Text.
 */
void xdc_runtime_Text_visitRope__I(xdc_runtime_Text_RopeId rope,
    xdc_runtime_Text_RopeVisitor visFxn, xdc_Ptr visState)
{
    xdc_CString stack[6];
    xdc_runtime_Text_visitRope2__I(rope, visFxn, visState, stack);
}

/*
 * ======== ti.catalog.c2800.initF2837x.Boot TEMPLATE ========
 */

    extern ti_catalog_c2800_initF2837x_Boot_disableWatchdog(xdc_Void);
    extern ti_catalog_c2800_initF2837x_Boot_initSharedRAMs(xdc_UInt sharedRamMask);
    extern ti_catalog_c2800_initF2837x_Boot_configurePllDivs(xdc_UInt iMult, xdc_UInt fMult, xdc_UInt sysDiv, xdc_UInt oscClkSrcVal);
    extern ti_catalog_c2800_initF2837x_Boot_bootCPU2(xdc_Void);
    extern ti_catalog_c2800_initF2837x_Boot_initFlash(xdc_Bool configWaitStates, xdc_UInt waitStates, xdc_Bool enableProgramCache, xdc_Bool enableDataCache);

#if defined(__ti__)
#pragma CODE_SECTION(ti_catalog_c2800_initF2837x_Boot_init, ".text:.bootCodeSection")
#pragma CODE_SECTION(ti_catalog_c2800_initF2837x_Boot_initStartup, ".text:.bootCodeSection")
#pragma CODE_SECTION(ti_catalog_c2800_initF2837x_Boot_limpAbort, ".text:.bootCodeSection")
#endif

/*
 *  ======== ti_catalog_arm_cortexm3_concertoInit_Boot_init ========
 *  Boot initialization run as an xdc.runtime.Reset function.
 */
xdc_Void ti_catalog_c2800_initF2837x_Boot_init(xdc_Void)
{
    ti_catalog_c2800_initF2837x_Boot_configurePllDivs(1, 0, 2, 0);

    ti_catalog_c2800_initF2837x_Boot_initSharedRAMs(0);
}

/*
 *  ======== ti_catalog_c2800_initF2837x_Boot_initStartup ========
 *  Boot initialization run as an xdc.runtime.Startup first function.
 */
xdc_Void ti_catalog_c2800_initF2837x_Boot_initStartup(xdc_Void)
{
    ti_catalog_c2800_initF2837x_Boot_initFlash(1, 0, 1, 1);
}

/*
 *  ======== ti_catalog_c2800_initF2837x_Boot_limpAbort ========
 */
xdc_Void ti_catalog_c2800_initF2837x_Boot_limpAbort(xdc_Void)
{
    extern ti_catalog_c2800_initF2837x_Boot_defaultLimpAbortFunction();
    ti_catalog_c2800_initF2837x_Boot_defaultLimpAbortFunction();
}

/*
 * ======== ti.sysbios.family.c28.Hwi TEMPLATE ========
 */


extern Void _c_int00(Void);
extern Void ti_sysbios_family_c28_Hwi_dispatchTable(Void);
extern Void ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I(Void);

/* Interrupt vector table.  This will be copied to 0xd00 at boot time. */
const UInt32 ti_sysbios_family_c28_Hwi_vectors[] = {
    /* 0 */  (UInt32)_c_int00,
    /* 1 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 2 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 3 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 4 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 5 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 6 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 7 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 8 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 9 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 10 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 11 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 12 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 13 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 14 */  (UInt32)ti_sysbios_family_c28_Hwi_dispatchTable + (3 * (14-1)),
    /* 15 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 16 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 17 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 18 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 19 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 20 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 21 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 22 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 23 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 24 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 25 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 26 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 27 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 28 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 29 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 30 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 31 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 32 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 33 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 34 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 35 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 36 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 37 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 38 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 39 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 40 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 41 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 42 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 43 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 44 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 45 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 46 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 47 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 48 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 49 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 50 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 51 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 52 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 53 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 54 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 55 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 56 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 57 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 58 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 59 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 60 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 61 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 62 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 63 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 64 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 65 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 66 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 67 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 68 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 69 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 70 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 71 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 72 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 73 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 74 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 75 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 76 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 77 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 78 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 79 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 80 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 81 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 82 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 83 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 84 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 85 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 86 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 87 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 88 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 89 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 90 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 91 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 92 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 93 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 94 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 95 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 96 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 97 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 98 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 99 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 100 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 101 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 102 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 103 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 104 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 105 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 106 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 107 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 108 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 109 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 110 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 111 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 112 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 113 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 114 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 115 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 116 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 117 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 118 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 119 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 120 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 121 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 122 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 123 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 124 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 125 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 126 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 127 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 128 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 129 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 130 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 131 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 132 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 133 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 134 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 135 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 136 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 137 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 138 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 139 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 140 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 141 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 142 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 143 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 144 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 145 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 146 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 147 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 148 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 149 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 150 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 151 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 152 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 153 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 154 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 155 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 156 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 157 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 158 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 159 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 160 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 161 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 162 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 163 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 164 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 165 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 166 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 167 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 168 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 169 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 170 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 171 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 172 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 173 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 174 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 175 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 176 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 177 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 178 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 179 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 180 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 181 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 182 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 183 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 184 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 185 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 186 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 187 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 188 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 189 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 190 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 191 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 192 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 193 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 194 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 195 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 196 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 197 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 198 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 199 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 200 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 201 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 202 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 203 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 204 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 205 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 206 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 207 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 208 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 209 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 210 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 211 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 212 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 213 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 214 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 215 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 216 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 217 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 218 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 219 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 220 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 221 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 222 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
    /* 223 */  (UInt32)ti_sysbios_family_c28_Hwi_unPluggedInterrupt__I,
};

extern cregister volatile UInt IER;


/*
 * ======== NON-ZERO LATENCY IMPLEMENTATION ========
 */

/*
 * ======== Hwi_startup ========
 */
Void ti_sysbios_family_c28_Hwi_startup__E()
{
    __enable_interrupts();
}

/*
 * ======== Hwi_disable ========
 */
UInt ti_sysbios_family_c28_Hwi_disable__E()
{
    UInt key;

    key = __disable_interrupts();

    return (key);
}

/*
 *  ======== Hwi_enable ========
 */
UInt ti_sysbios_family_c28_Hwi_enable__E()
{
    UInt key;

    key = __enable_interrupts();

    return (key);
}

/*
 *  ======== Hwi_restore ========
 */

Void ti_sysbios_family_c28_Hwi_restore__E(UInt key)
{
    __restore_interrupts(key);
}

/*
 *  ======== Hwi_disableIER ========
 */
Bits16 ti_sysbios_family_c28_Hwi_disableIER__E(Bits16 mask)
{
    UInt key;
    Bits16 oldIER;

    key = __disable_interrupts();

    oldIER = IER;
    IER &= ~mask;

    __restore_interrupts(key);

    return (oldIER);
}

/*
 *  ======== Hwi_enableIER ========
 */
Bits16 ti_sysbios_family_c28_Hwi_enableIER__E(Bits16 mask)
{
    UInt key;
    Bits16 oldIER;

    key = __disable_interrupts();

    oldIER = IER;
    IER |= mask;

    __restore_interrupts(key);

    return (oldIER);
}

/*
 *  ======== Hwi_restoreIER ========
 */
Bits16 ti_sysbios_family_c28_Hwi_restoreIER__E(Bits16 mask)
{
    UInt key;
    Bits16 oldIER;

    key = __disable_interrupts();

    oldIER = IER;
    IER = mask;

    __restore_interrupts(key);

    return (oldIER);
}


/*
 * ======== ti.sysbios.BIOS TEMPLATE ========
 */


Void ti_sysbios_BIOS_atExitFunc__I(Int stat);

extern Void ti_sysbios_BIOS_registerRTSLock(Void);
extern Void ti_sysbios_family_c28_Timer_startup__E(Void);

Void ti_sysbios_BIOS_startFunc__I(Void)
{
    /*
     *  Check if XDC runtime startup functions have been called. If not, then
     *  call BIOS_linkedWithIncorrectBootLibrary() function. This function
     *  will spin forever.
     */
    if (xdc_runtime_Startup_rtsDone() != TRUE) {
        ti_sysbios_BIOS_linkedWithIncorrectBootLibrary();
    }

    (void)xdc_runtime_System_atexit(
        (xdc_runtime_System_AtexitHandler)ti_sysbios_BIOS_atExitFunc__I);
    ti_sysbios_BIOS_registerRTSLock();
    ti_sysbios_family_c28_Timer_startup__E();
    ti_sysbios_hal_Hwi_startup();
    ti_sysbios_knl_Swi_startup();
    ti_sysbios_knl_Task_startup();
}

#include <_lock.h>

Void ti_sysbios_BIOS_atExitFunc__I(Int notused)
{
    ti_sysbios_knl_Swi_disable();
    (void)ti_sysbios_knl_Task_disable();
    (void)ti_sysbios_BIOS_setThreadType(ti_sysbios_BIOS_ThreadType_Main);

    if ((&ti_sysbios_BIOS_Module__state__V)->rtsGate != NULL) {
        _register_lock(_nop);
        _register_unlock(_nop);
    }
}


/*
 *  ======== BIOS_rtsLock ========
 *  Called by rts _lock() function
 */
Void ti_sysbios_BIOS_rtsLock(Void)
{
    IArg key;

    key = ti_sysbios_BIOS_RtsGateProxy_enter((&ti_sysbios_BIOS_Module__state__V)->rtsGate);
    if ((&ti_sysbios_BIOS_Module__state__V)->rtsGateCount == 0U) {
        (&ti_sysbios_BIOS_Module__state__V)->rtsGateKey = key;
    }
    /* Increment need not be atomic */
    (&ti_sysbios_BIOS_Module__state__V)->rtsGateCount++;
}

/*
 *  ======== BIOS_rtsUnLock ========
 *  Called by rts _unlock() function
 */
Void ti_sysbios_BIOS_rtsUnlock(Void)
{
    xdc_runtime_Assert_isTrue(((&ti_sysbios_BIOS_Module__state__V)->rtsGateCount), NULL);

    (&ti_sysbios_BIOS_Module__state__V)->rtsGateCount--;

    if ((&ti_sysbios_BIOS_Module__state__V)->rtsGateCount == 0U) {
        ti_sysbios_BIOS_RtsGateProxy_leave((&ti_sysbios_BIOS_Module__state__V)->rtsGate, (&ti_sysbios_BIOS_Module__state__V)->rtsGateKey);
    }
}

/*
 *  ======== BIOS_nullFunc ========
 */
Void ti_sysbios_BIOS_nullFunc__I(Void)
{
}

/*
 *  ======== BIOS_registerRTSLock ========
 */
Void ti_sysbios_BIOS_registerRTSLock(Void)
{
    if ((&ti_sysbios_BIOS_Module__state__V)->rtsGate != NULL) {
        _register_lock(ti_sysbios_BIOS_rtsLock);
        _register_unlock(ti_sysbios_BIOS_rtsUnlock);
    }
}

/*
 *  ======== BIOS_removeRTSLock ========
 */
Void ti_sysbios_BIOS_removeRTSLock(Void)
{
    if ((&ti_sysbios_BIOS_Module__state__V)->rtsGate != NULL) {
        _register_lock(ti_sysbios_BIOS_nullFunc);
        _register_unlock(ti_sysbios_BIOS_nullFunc);
    }
}

/*
 *  ======== BIOS_exitFunc ========
 */
Void ti_sysbios_BIOS_exitFunc(Int stat)
{
    /* remove the RTS lock */
    ti_sysbios_BIOS_removeRTSLock();

    /* force thread type to 'Main' */
    (void)ti_sysbios_BIOS_setThreadType(ti_sysbios_BIOS_ThreadType_Main);

    xdc_runtime_System_exit(stat);
}

/*
 *  ======== BIOS_errorRaiseHook ========
 */
Void ti_sysbios_BIOS_errorRaiseHook(xdc_runtime_Error_Block *eb)
{
    /*
     * If this is an Assert thread, defang Gate threadtype check
     */
    if (eb->id == xdc_runtime_Assert_E_assertFailed) {
        /* remove the RTS lock */
        ti_sysbios_BIOS_removeRTSLock();
        /* force thread type to 'Main' */
        ti_sysbios_BIOS_setThreadType(ti_sysbios_BIOS_ThreadType_Main);
    }
    /* Call the installed Error.raiseHook */
    ti_sysbios_BIOS_installedErrorHook(eb);
}

/*
 * ======== ti.sysbios.Build TEMPLATE ========
 */


/*
 * ======== ti.sysbios.knl.Clock TEMPLATE ========
 */

Void ti_sysbios_knl_Clock_doTick__I(UArg arg)
{
    /* update system time */
    (&ti_sysbios_knl_Clock_Module__state__V)->ticks++;

    ti_sysbios_knl_Clock_logTick__E();

    if (ti_sysbios_knl_Queue_empty(ti_sysbios_knl_Clock_Module_State_clockQ())
        == 0U) {
        (&ti_sysbios_knl_Clock_Module__state__V)->swiCount++;

        ti_sysbios_knl_Swi_post((&ti_sysbios_knl_Clock_Module__state__V)->swi);
    }
}

/*
 * ======== ti.sysbios.knl.Task TEMPLATE ========
 */




/*
 * ======== ti.sysbios.rts.MemAlloc TEMPLATE ========
 */



#if defined(__ti__)

#pragma FUNC_EXT_CALLED(malloc);
#pragma FUNC_EXT_CALLED(memalign);
#pragma FUNC_EXT_CALLED(free);
#pragma FUNC_EXT_CALLED(calloc);
#pragma FUNC_EXT_CALLED(realloc);
#pragma FUNC_EXT_CALLED(aligned_alloc);

#define ATTRIBUTE

#elif defined(__IAR_SYSTEMS_ICC__)

#define ATTRIBUTE

#else

#define ATTRIBUTE __attribute__ ((used))

#endif


#include <xdc/std.h>

#include <xdc/runtime/Memory.h>
#include <xdc/runtime/Error.h>

#include <string.h>

#if defined(__GNUC__) && !defined(__ti__)

#include <reent.h>

#endif


/*
 * Header is a union to make sure that the size is a power of 2.
 */
typedef union Header {
    struct {
        Ptr   actualBuf;
        SizeT size;
    } header;
    UArg pad[2];	/* 4 words on 28L, 8 bytes on most others */
} Header;



/*
 *  ======== ti_sysbios_rts_MemAlloc_alloc ========
 */
static Void *ti_sysbios_rts_MemAlloc_alloc(SizeT size)
{
    Header *packet;
    xdc_runtime_Error_Block eb;

    if (size == 0) {
        return (NULL);
    }

    xdc_runtime_Error_init(&eb);

    packet = (Header *)xdc_runtime_Memory_alloc(NULL,
        (SizeT)(size + sizeof(Header)), 0, &eb);

    if (packet == NULL) {
        return (NULL);
    }

    packet->header.actualBuf = (Ptr)packet;
    packet->header.size = size + sizeof(Header);

    return (packet + 1);
}

/*
 *  ======== malloc ========
 */
Void ATTRIBUTE *malloc(SizeT size)
{
    return (ti_sysbios_rts_MemAlloc_alloc(size));
}

/*
 *  ======== memalign ========
 *  mirrors the memalign() function from the TI run-time library
 */
Void ATTRIBUTE *memalign(SizeT alignment, SizeT size)
{
    Header                      *packet;
    Void                        *tmp;
    xdc_runtime_Error_Block     eb;

    /* return NULL if size is 0, or alignment is not a power-of-2 */
    if (size == 0 || (alignment & (alignment - 1))) {
        return (NULL);
    }

    if (alignment < sizeof(Header)) {
        alignment = sizeof(Header);
    }

    xdc_runtime_Error_init(&eb);

    /*
     * Allocate 'align + size' so that we have room for the 'packet'
     * and can return an aligned buffer.
     */
    tmp = xdc_runtime_Memory_alloc(NULL, alignment + size, alignment, &eb);

    if (tmp == NULL) {
        return (NULL);
    }

    packet = (Header *)((char *)tmp + alignment - sizeof(Header));

    packet->header.actualBuf = tmp;
    packet->header.size = size + sizeof(Header);

    return (packet + 1);
}

/*
 *  ======== calloc ========
 */
Void ATTRIBUTE *calloc(SizeT nmemb, SizeT size)
{
    SizeT       nbytes;
    Ptr         retval;

    nbytes = nmemb * size;

    /* return NULL if there's an overflow */
    if (nmemb && size != (nbytes / nmemb)) {
        return (NULL);
    }

    retval = ti_sysbios_rts_MemAlloc_alloc(nbytes);
    if (retval != NULL) {
        (Void)memset(retval, (Int)'\0', nbytes);
    }

    return (retval);
}

/*
 *  ======== free ========
 */
Void ATTRIBUTE free(Void *ptr)
{
    Header      *packet;

    if (ptr != NULL) {
        packet = ((Header *)ptr) - 1;

        xdc_runtime_Memory_free(NULL, (Ptr)packet->header.actualBuf,
            (packet->header.size +
            ((char*)packet - (char*)packet->header.actualBuf)));
    }
}

/*
 *  ======== realloc ========
 */
Void ATTRIBUTE *realloc(Void *ptr, SizeT size)
{
    Ptr         retval;
    Header      *packet;
    SizeT       oldSize;

    if (ptr == NULL) {
        retval = malloc(size);
    }
    else if (size == 0) {
        free(ptr);
        retval = NULL;
    }
    else {
        packet = (Header *)ptr - 1;
        retval = malloc(size);
        if (retval != NULL) {
            oldSize = packet->header.size - sizeof(Header);
            (Void)memcpy(retval, ptr, (size < oldSize) ? size : oldSize);
            free(ptr);
        }
    }

    return (retval);
}

/*
 *  ======== aligned_alloc ========
 */
Void ATTRIBUTE *aligned_alloc(SizeT alignment, SizeT size)
{
    Void *retval;

    retval = memalign(alignment, size);

    return (retval);
}

#if defined(__GNUC__) && !defined(__ti__)

/*
 *  ======== _malloc_r ========
 */
Void ATTRIBUTE *_malloc_r(struct _reent *rptr, SizeT size)
{
    return malloc(size);
}

/*
 *  ======== _calloc_r ========
 */
Void ATTRIBUTE *_calloc_r(struct _reent *rptr, SizeT nmemb, SizeT size)
{
    return calloc(nmemb, size);
}

/*
 *  ======== _free_r ========
 */
Void ATTRIBUTE _free_r(struct _reent *rptr, Void *ptr)
{
    free(ptr);
}

/*
 *  ======== _realloc_r ========
 */
Void ATTRIBUTE *_realloc_r(struct _reent *rptr, Void *ptr, SizeT size)
{
    return realloc(ptr, size);
}

#endif


/*
 * ======== ti.sysbios.BIOS INITIALIZERS ========
 */

/* Module__state__V */
#if defined (__ICCARM__)
#pragma location = ".data_ti_sysbios_BIOS_Module__state__V"
#endif
#if defined(__GNUC__) && !(defined(__MACH__) && defined(__APPLE__))
#ifndef __ti__
ti_sysbios_BIOS_Module_State__ ti_sysbios_BIOS_Module__state__V __attribute__ ((section(".data_ti_sysbios_BIOS_Module__state__V")));
#elif defined(__clang__)
ti_sysbios_BIOS_Module_State__ ti_sysbios_BIOS_Module__state__V __attribute__ ((section(".data:ti_sysbios_BIOS_Module__state__V")));
#endif
#endif
ti_sysbios_BIOS_Module_State__ ti_sysbios_BIOS_Module__state__V = {
    {
        (xdc_Bits32)0x0,  /* hi */
        (xdc_Bits32)0x2625a0,  /* lo */
    },  /* cpuFreq */
    (xdc_UInt)0x0,  /* rtsGateCount */
    ((xdc_IArg)(0x0)),  /* rtsGateKey */
    (ti_sysbios_BIOS_RtsGateProxy_Handle)&ti_sysbios_gates_GateMutex_Object__table__V[1],  /* rtsGate */
    ti_sysbios_BIOS_ThreadType_Main,  /* threadType */
    ((void*)0),  /* smpThreadType */
    ((xdc_Void(*)(xdc_Void))(ti_sysbios_BIOS_startFunc)),  /* startFunc */
    ((xdc_Void(*)(xdc_Int f_arg0))(ti_sysbios_BIOS_exitFunc)),  /* exitFunc */
};

/* Module__diagsEnabled__C */
#pragma DATA_SECTION(ti_sysbios_BIOS_Module__diagsEnabled__C, ".econst:ti_sysbios_BIOS_Module__diagsEnabled__C");
asm("	.sect \".econst:ti_sysbios_BIOS_Module__diagsEnabled__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_BIOS_Module__diagsEnabled__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_BIOS_Module__diagsEnabled__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_BIOS_Module__diagsEnabled ti_sysbios_BIOS_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
#pragma DATA_SECTION(ti_sysbios_BIOS_Module__diagsIncluded__C, ".econst:ti_sysbios_BIOS_Module__diagsIncluded__C");
asm("	.sect \".econst:ti_sysbios_BIOS_Module__diagsIncluded__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_BIOS_Module__diagsIncluded__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_BIOS_Module__diagsIncluded__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_BIOS_Module__diagsIncluded ti_sysbios_BIOS_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
#pragma DATA_SECTION(ti_sysbios_BIOS_Module__diagsMask__C, ".econst:ti_sysbios_BIOS_Module__diagsMask__C");
asm("	.sect \".econst:ti_sysbios_BIOS_Module__diagsMask__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_BIOS_Module__diagsMask__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_BIOS_Module__diagsMask__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_BIOS_Module__diagsMask ti_sysbios_BIOS_Module__diagsMask__C = ((const CT__ti_sysbios_BIOS_Module__diagsMask)NULL);

/* Module__gateObj__C */
#pragma DATA_SECTION(ti_sysbios_BIOS_Module__gateObj__C, ".econst:ti_sysbios_BIOS_Module__gateObj__C");
asm("	.sect \".econst:ti_sysbios_BIOS_Module__gateObj__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_BIOS_Module__gateObj__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_BIOS_Module__gateObj__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_BIOS_Module__gateObj ti_sysbios_BIOS_Module__gateObj__C = ((const CT__ti_sysbios_BIOS_Module__gateObj)NULL);

/* Module__gatePrms__C */
#pragma DATA_SECTION(ti_sysbios_BIOS_Module__gatePrms__C, ".econst:ti_sysbios_BIOS_Module__gatePrms__C");
asm("	.sect \".econst:ti_sysbios_BIOS_Module__gatePrms__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_BIOS_Module__gatePrms__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_BIOS_Module__gatePrms__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_BIOS_Module__gatePrms ti_sysbios_BIOS_Module__gatePrms__C = ((const CT__ti_sysbios_BIOS_Module__gatePrms)NULL);

/* Module__id__C */
#pragma DATA_SECTION(ti_sysbios_BIOS_Module__id__C, ".econst:ti_sysbios_BIOS_Module__id__C");
asm("	.sect \".econst:ti_sysbios_BIOS_Module__id__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_BIOS_Module__id__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_BIOS_Module__id__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_BIOS_Module__id ti_sysbios_BIOS_Module__id__C = (xdc_Bits16)0x8019;

/* Module__loggerDefined__C */
#pragma DATA_SECTION(ti_sysbios_BIOS_Module__loggerDefined__C, ".econst:ti_sysbios_BIOS_Module__loggerDefined__C");
asm("	.sect \".econst:ti_sysbios_BIOS_Module__loggerDefined__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_BIOS_Module__loggerDefined__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_BIOS_Module__loggerDefined__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_BIOS_Module__loggerDefined ti_sysbios_BIOS_Module__loggerDefined__C = 1;

/* Module__loggerObj__C */
#pragma DATA_SECTION(ti_sysbios_BIOS_Module__loggerObj__C, ".econst:ti_sysbios_BIOS_Module__loggerObj__C");
asm("	.sect \".econst:ti_sysbios_BIOS_Module__loggerObj__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_BIOS_Module__loggerObj__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_BIOS_Module__loggerObj__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_BIOS_Module__loggerObj ti_sysbios_BIOS_Module__loggerObj__C = ((const CT__ti_sysbios_BIOS_Module__loggerObj)((void*)(xdc_runtime_ILogger_Handle)&xdc_runtime_LoggerBuf_Object__table__V[0]));

/* Module__loggerFxn0__C */
#pragma DATA_SECTION(ti_sysbios_BIOS_Module__loggerFxn0__C, ".econst:ti_sysbios_BIOS_Module__loggerFxn0__C");
asm("	.sect \".econst:ti_sysbios_BIOS_Module__loggerFxn0__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_BIOS_Module__loggerFxn0__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_BIOS_Module__loggerFxn0__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_BIOS_Module__loggerFxn0 ti_sysbios_BIOS_Module__loggerFxn0__C = ((const CT__ti_sysbios_BIOS_Module__loggerFxn0)(xdc_runtime_LoggerBuf_write0));

/* Module__loggerFxn1__C */
#pragma DATA_SECTION(ti_sysbios_BIOS_Module__loggerFxn1__C, ".econst:ti_sysbios_BIOS_Module__loggerFxn1__C");
asm("	.sect \".econst:ti_sysbios_BIOS_Module__loggerFxn1__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_BIOS_Module__loggerFxn1__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_BIOS_Module__loggerFxn1__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_BIOS_Module__loggerFxn1 ti_sysbios_BIOS_Module__loggerFxn1__C = ((const CT__ti_sysbios_BIOS_Module__loggerFxn1)(xdc_runtime_LoggerBuf_write1));

/* Module__loggerFxn2__C */
#pragma DATA_SECTION(ti_sysbios_BIOS_Module__loggerFxn2__C, ".econst:ti_sysbios_BIOS_Module__loggerFxn2__C");
asm("	.sect \".econst:ti_sysbios_BIOS_Module__loggerFxn2__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_BIOS_Module__loggerFxn2__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_BIOS_Module__loggerFxn2__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_BIOS_Module__loggerFxn2 ti_sysbios_BIOS_Module__loggerFxn2__C = ((const CT__ti_sysbios_BIOS_Module__loggerFxn2)(xdc_runtime_LoggerBuf_write2));

/* Module__loggerFxn4__C */
#pragma DATA_SECTION(ti_sysbios_BIOS_Module__loggerFxn4__C, ".econst:ti_sysbios_BIOS_Module__loggerFxn4__C");
asm("	.sect \".econst:ti_sysbios_BIOS_Module__loggerFxn4__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_BIOS_Module__loggerFxn4__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_BIOS_Module__loggerFxn4__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_BIOS_Module__loggerFxn4 ti_sysbios_BIOS_Module__loggerFxn4__C = ((const CT__ti_sysbios_BIOS_Module__loggerFxn4)(xdc_runtime_LoggerBuf_write4));

/* Module__loggerFxn8__C */
#pragma DATA_SECTION(ti_sysbios_BIOS_Module__loggerFxn8__C, ".econst:ti_sysbios_BIOS_Module__loggerFxn8__C");
asm("	.sect \".econst:ti_sysbios_BIOS_Module__loggerFxn8__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_BIOS_Module__loggerFxn8__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_BIOS_Module__loggerFxn8__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_BIOS_Module__loggerFxn8 ti_sysbios_BIOS_Module__loggerFxn8__C = ((const CT__ti_sysbios_BIOS_Module__loggerFxn8)(xdc_runtime_LoggerBuf_write8));

/* Object__count__C */
#pragma DATA_SECTION(ti_sysbios_BIOS_Object__count__C, ".econst:ti_sysbios_BIOS_Object__count__C");
asm("	.sect \".econst:ti_sysbios_BIOS_Object__count__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_BIOS_Object__count__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_BIOS_Object__count__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_BIOS_Object__count ti_sysbios_BIOS_Object__count__C = 0;

/* Object__heap__C */
#pragma DATA_SECTION(ti_sysbios_BIOS_Object__heap__C, ".econst:ti_sysbios_BIOS_Object__heap__C");
asm("	.sect \".econst:ti_sysbios_BIOS_Object__heap__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_BIOS_Object__heap__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_BIOS_Object__heap__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_BIOS_Object__heap ti_sysbios_BIOS_Object__heap__C = NULL;

/* Object__sizeof__C */
#pragma DATA_SECTION(ti_sysbios_BIOS_Object__sizeof__C, ".econst:ti_sysbios_BIOS_Object__sizeof__C");
asm("	.sect \".econst:ti_sysbios_BIOS_Object__sizeof__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_BIOS_Object__sizeof__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_BIOS_Object__sizeof__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_BIOS_Object__sizeof ti_sysbios_BIOS_Object__sizeof__C = 0;

/* Object__table__C */
#pragma DATA_SECTION(ti_sysbios_BIOS_Object__table__C, ".econst:ti_sysbios_BIOS_Object__table__C");
asm("	.sect \".econst:ti_sysbios_BIOS_Object__table__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_BIOS_Object__table__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_BIOS_Object__table__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_BIOS_Object__table ti_sysbios_BIOS_Object__table__C = NULL;

/* smpEnabled__C */
#pragma DATA_SECTION(ti_sysbios_BIOS_smpEnabled__C, ".econst:ti_sysbios_BIOS_smpEnabled__C");
asm("	.sect \".econst:ti_sysbios_BIOS_smpEnabled__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_BIOS_smpEnabled__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_BIOS_smpEnabled__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_BIOS_smpEnabled ti_sysbios_BIOS_smpEnabled__C = 0;

/* mpeEnabled__C */
#pragma DATA_SECTION(ti_sysbios_BIOS_mpeEnabled__C, ".econst:ti_sysbios_BIOS_mpeEnabled__C");
asm("	.sect \".econst:ti_sysbios_BIOS_mpeEnabled__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_BIOS_mpeEnabled__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_BIOS_mpeEnabled__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_BIOS_mpeEnabled ti_sysbios_BIOS_mpeEnabled__C = 0;

/* cpuFreq__C */
#pragma DATA_SECTION(ti_sysbios_BIOS_cpuFreq__C, ".econst:ti_sysbios_BIOS_cpuFreq__C");
asm("	.sect \".econst:ti_sysbios_BIOS_cpuFreq__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_BIOS_cpuFreq__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_BIOS_cpuFreq__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_BIOS_cpuFreq ti_sysbios_BIOS_cpuFreq__C = {
    (xdc_Bits32)0x0,  /* hi */
    (xdc_Bits32)0x2625a0,  /* lo */
};

/* runtimeCreatesEnabled__C */
#pragma DATA_SECTION(ti_sysbios_BIOS_runtimeCreatesEnabled__C, ".econst:ti_sysbios_BIOS_runtimeCreatesEnabled__C");
asm("	.sect \".econst:ti_sysbios_BIOS_runtimeCreatesEnabled__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_BIOS_runtimeCreatesEnabled__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_BIOS_runtimeCreatesEnabled__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_BIOS_runtimeCreatesEnabled ti_sysbios_BIOS_runtimeCreatesEnabled__C = 1;

/* taskEnabled__C */
#pragma DATA_SECTION(ti_sysbios_BIOS_taskEnabled__C, ".econst:ti_sysbios_BIOS_taskEnabled__C");
asm("	.sect \".econst:ti_sysbios_BIOS_taskEnabled__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_BIOS_taskEnabled__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_BIOS_taskEnabled__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_BIOS_taskEnabled ti_sysbios_BIOS_taskEnabled__C = 1;

/* swiEnabled__C */
#pragma DATA_SECTION(ti_sysbios_BIOS_swiEnabled__C, ".econst:ti_sysbios_BIOS_swiEnabled__C");
asm("	.sect \".econst:ti_sysbios_BIOS_swiEnabled__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_BIOS_swiEnabled__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_BIOS_swiEnabled__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_BIOS_swiEnabled ti_sysbios_BIOS_swiEnabled__C = 1;

/* clockEnabled__C */
#pragma DATA_SECTION(ti_sysbios_BIOS_clockEnabled__C, ".econst:ti_sysbios_BIOS_clockEnabled__C");
asm("	.sect \".econst:ti_sysbios_BIOS_clockEnabled__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_BIOS_clockEnabled__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_BIOS_clockEnabled__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_BIOS_clockEnabled ti_sysbios_BIOS_clockEnabled__C = 1;

/* defaultKernelHeapInstance__C */
#pragma DATA_SECTION(ti_sysbios_BIOS_defaultKernelHeapInstance__C, ".econst:ti_sysbios_BIOS_defaultKernelHeapInstance__C");
asm("	.sect \".econst:ti_sysbios_BIOS_defaultKernelHeapInstance__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_BIOS_defaultKernelHeapInstance__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_BIOS_defaultKernelHeapInstance__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_BIOS_defaultKernelHeapInstance ti_sysbios_BIOS_defaultKernelHeapInstance__C = 0;

/* kernelHeapSize__C */
#pragma DATA_SECTION(ti_sysbios_BIOS_kernelHeapSize__C, ".econst:ti_sysbios_BIOS_kernelHeapSize__C");
asm("	.sect \".econst:ti_sysbios_BIOS_kernelHeapSize__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_BIOS_kernelHeapSize__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_BIOS_kernelHeapSize__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_BIOS_kernelHeapSize ti_sysbios_BIOS_kernelHeapSize__C = (xdc_SizeT)0x1000;

/* kernelHeapSection__C */
#pragma DATA_SECTION(ti_sysbios_BIOS_kernelHeapSection__C, ".econst:ti_sysbios_BIOS_kernelHeapSection__C");
asm("	.sect \".econst:ti_sysbios_BIOS_kernelHeapSection__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_BIOS_kernelHeapSection__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_BIOS_kernelHeapSection__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_BIOS_kernelHeapSection ti_sysbios_BIOS_kernelHeapSection__C = ".kernel_heap";

/* heapSize__C */
#pragma DATA_SECTION(ti_sysbios_BIOS_heapSize__C, ".econst:ti_sysbios_BIOS_heapSize__C");
asm("	.sect \".econst:ti_sysbios_BIOS_heapSize__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_BIOS_heapSize__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_BIOS_heapSize__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_BIOS_heapSize ti_sysbios_BIOS_heapSize__C = (xdc_SizeT)0x800;

/* heapSection__C */
#pragma DATA_SECTION(ti_sysbios_BIOS_heapSection__C, ".econst:ti_sysbios_BIOS_heapSection__C");
asm("	.sect \".econst:ti_sysbios_BIOS_heapSection__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_BIOS_heapSection__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_BIOS_heapSection__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_BIOS_heapSection ti_sysbios_BIOS_heapSection__C = ".ebss:taskStackSection";

/* heapTrackEnabled__C */
#pragma DATA_SECTION(ti_sysbios_BIOS_heapTrackEnabled__C, ".econst:ti_sysbios_BIOS_heapTrackEnabled__C");
asm("	.sect \".econst:ti_sysbios_BIOS_heapTrackEnabled__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_BIOS_heapTrackEnabled__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_BIOS_heapTrackEnabled__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_BIOS_heapTrackEnabled ti_sysbios_BIOS_heapTrackEnabled__C = 0;

/* setupSecureContext__C */
#pragma DATA_SECTION(ti_sysbios_BIOS_setupSecureContext__C, ".econst:ti_sysbios_BIOS_setupSecureContext__C");
asm("	.sect \".econst:ti_sysbios_BIOS_setupSecureContext__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_BIOS_setupSecureContext__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_BIOS_setupSecureContext__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_BIOS_setupSecureContext ti_sysbios_BIOS_setupSecureContext__C = 0;

/* useSK__C */
#pragma DATA_SECTION(ti_sysbios_BIOS_useSK__C, ".econst:ti_sysbios_BIOS_useSK__C");
asm("	.sect \".econst:ti_sysbios_BIOS_useSK__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_BIOS_useSK__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_BIOS_useSK__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_BIOS_useSK ti_sysbios_BIOS_useSK__C = 0;

/* installedErrorHook__C */
#pragma DATA_SECTION(ti_sysbios_BIOS_installedErrorHook__C, ".econst:ti_sysbios_BIOS_installedErrorHook__C");
asm("	.sect \".econst:ti_sysbios_BIOS_installedErrorHook__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_BIOS_installedErrorHook__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_BIOS_installedErrorHook__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_BIOS_installedErrorHook ti_sysbios_BIOS_installedErrorHook__C = ((const CT__ti_sysbios_BIOS_installedErrorHook)(xdc_runtime_Error_print__E));


/*
 * ======== ti.sysbios.BIOS_RtsGateProxy INITIALIZERS ========
 */


/*
 * ======== ti.sysbios.family.c28.Hwi INITIALIZERS ========
 */

/* Object__DESC__C */
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_family_c28_Hwi_Object__DESC__C;

/* Object__PARAMS__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_Hwi_Object__PARAMS__C, ".econst:ti_sysbios_family_c28_Hwi_Object__PARAMS__C");
asm("	.sect \".econst:ti_sysbios_family_c28_Hwi_Object__PARAMS__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_Hwi_Object__PARAMS__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_Hwi_Object__PARAMS__C\"");
asm("	.clink ");

__FAR__ const ti_sysbios_family_c28_Hwi_Params ti_sysbios_family_c28_Hwi_Object__PARAMS__C = {
    sizeof (ti_sysbios_family_c28_Hwi_Params), /* __size */
    NULL, /* __self */
    NULL, /* __fxns */
    (xdc_runtime_IInstance_Params*)&ti_sysbios_family_c28_Hwi_Object__PARAMS__C.__iprms, /* instance */
    ti_sysbios_interfaces_IHwi_MaskingOption_SELF,  /* maskSetting */
    ((xdc_UArg)(0x0)),  /* arg */
    1,  /* enableInt */
    (xdc_Int)(-0x0 - 1),  /* eventId */
    (xdc_Int)0x0,  /* priority */
    (xdc_Bits16)0x0,  /* disableMask */
    (xdc_Bits16)0x0,  /* restoreMask */
    1,  /* enableAck */
    {
        sizeof (xdc_runtime_IInstance_Params), /* __size */
        0,  /* name */
    },  /* instance */
};

/* Module__root__V */
ti_sysbios_family_c28_Hwi_Module__ ti_sysbios_family_c28_Hwi_Module__root__V = {
    {&ti_sysbios_family_c28_Hwi_Module__root__V.link,  /* link.next */
    &ti_sysbios_family_c28_Hwi_Module__root__V.link},  /* link.prev */
};

/* Object__table__V */
ti_sysbios_family_c28_Hwi_Object__ ti_sysbios_family_c28_Hwi_Object__table__V[1] = {
    {/* instance#0 */
        0,
        (xdc_UInt)0xe,  /* intNum */
        1,  /* enableInt */
        1,  /* enableAck */
        (xdc_Bits16)0x2000,  /* disableMask */
        (xdc_Bits16)0x2000,  /* restoreMask */
        (xdc_Bits16)0x2000,  /* ierBitMask */
        ((xdc_UArg)NULL),  /* arg */
        ((xdc_Void(*)(xdc_UArg f_arg0))(ti_sysbios_knl_Clock_doTick__I)),  /* fxn */
        ((xdc_UArg)NULL),  /* irp */
        ((void*)0),  /* hookEnv */
    },
};

/* --> ti_sysbios_family_c28_Hwi_Module_State_0_dispatchTable__A */
__T1_ti_sysbios_family_c28_Hwi_Module_State__dispatchTable ti_sysbios_family_c28_Hwi_Module_State_0_dispatchTable__A[224] = {
    0,  /* [0] */
    0,  /* [1] */
    0,  /* [2] */
    0,  /* [3] */
    0,  /* [4] */
    0,  /* [5] */
    0,  /* [6] */
    0,  /* [7] */
    0,  /* [8] */
    0,  /* [9] */
    0,  /* [10] */
    0,  /* [11] */
    0,  /* [12] */
    0,  /* [13] */
    (ti_sysbios_family_c28_Hwi_Handle)&ti_sysbios_family_c28_Hwi_Object__table__V[0],  /* [14] */
    0,  /* [15] */
    0,  /* [16] */
    0,  /* [17] */
    0,  /* [18] */
    0,  /* [19] */
    0,  /* [20] */
    0,  /* [21] */
    0,  /* [22] */
    0,  /* [23] */
    0,  /* [24] */
    0,  /* [25] */
    0,  /* [26] */
    0,  /* [27] */
    0,  /* [28] */
    0,  /* [29] */
    0,  /* [30] */
    0,  /* [31] */
    0,  /* [32] */
    0,  /* [33] */
    0,  /* [34] */
    0,  /* [35] */
    0,  /* [36] */
    0,  /* [37] */
    0,  /* [38] */
    0,  /* [39] */
    0,  /* [40] */
    0,  /* [41] */
    0,  /* [42] */
    0,  /* [43] */
    0,  /* [44] */
    0,  /* [45] */
    0,  /* [46] */
    0,  /* [47] */
    0,  /* [48] */
    0,  /* [49] */
    0,  /* [50] */
    0,  /* [51] */
    0,  /* [52] */
    0,  /* [53] */
    0,  /* [54] */
    0,  /* [55] */
    0,  /* [56] */
    0,  /* [57] */
    0,  /* [58] */
    0,  /* [59] */
    0,  /* [60] */
    0,  /* [61] */
    0,  /* [62] */
    0,  /* [63] */
    0,  /* [64] */
    0,  /* [65] */
    0,  /* [66] */
    0,  /* [67] */
    0,  /* [68] */
    0,  /* [69] */
    0,  /* [70] */
    0,  /* [71] */
    0,  /* [72] */
    0,  /* [73] */
    0,  /* [74] */
    0,  /* [75] */
    0,  /* [76] */
    0,  /* [77] */
    0,  /* [78] */
    0,  /* [79] */
    0,  /* [80] */
    0,  /* [81] */
    0,  /* [82] */
    0,  /* [83] */
    0,  /* [84] */
    0,  /* [85] */
    0,  /* [86] */
    0,  /* [87] */
    0,  /* [88] */
    0,  /* [89] */
    0,  /* [90] */
    0,  /* [91] */
    0,  /* [92] */
    0,  /* [93] */
    0,  /* [94] */
    0,  /* [95] */
    0,  /* [96] */
    0,  /* [97] */
    0,  /* [98] */
    0,  /* [99] */
    0,  /* [100] */
    0,  /* [101] */
    0,  /* [102] */
    0,  /* [103] */
    0,  /* [104] */
    0,  /* [105] */
    0,  /* [106] */
    0,  /* [107] */
    0,  /* [108] */
    0,  /* [109] */
    0,  /* [110] */
    0,  /* [111] */
    0,  /* [112] */
    0,  /* [113] */
    0,  /* [114] */
    0,  /* [115] */
    0,  /* [116] */
    0,  /* [117] */
    0,  /* [118] */
    0,  /* [119] */
    0,  /* [120] */
    0,  /* [121] */
    0,  /* [122] */
    0,  /* [123] */
    0,  /* [124] */
    0,  /* [125] */
    0,  /* [126] */
    0,  /* [127] */
    0,  /* [128] */
    0,  /* [129] */
    0,  /* [130] */
    0,  /* [131] */
    0,  /* [132] */
    0,  /* [133] */
    0,  /* [134] */
    0,  /* [135] */
    0,  /* [136] */
    0,  /* [137] */
    0,  /* [138] */
    0,  /* [139] */
    0,  /* [140] */
    0,  /* [141] */
    0,  /* [142] */
    0,  /* [143] */
    0,  /* [144] */
    0,  /* [145] */
    0,  /* [146] */
    0,  /* [147] */
    0,  /* [148] */
    0,  /* [149] */
    0,  /* [150] */
    0,  /* [151] */
    0,  /* [152] */
    0,  /* [153] */
    0,  /* [154] */
    0,  /* [155] */
    0,  /* [156] */
    0,  /* [157] */
    0,  /* [158] */
    0,  /* [159] */
    0,  /* [160] */
    0,  /* [161] */
    0,  /* [162] */
    0,  /* [163] */
    0,  /* [164] */
    0,  /* [165] */
    0,  /* [166] */
    0,  /* [167] */
    0,  /* [168] */
    0,  /* [169] */
    0,  /* [170] */
    0,  /* [171] */
    0,  /* [172] */
    0,  /* [173] */
    0,  /* [174] */
    0,  /* [175] */
    0,  /* [176] */
    0,  /* [177] */
    0,  /* [178] */
    0,  /* [179] */
    0,  /* [180] */
    0,  /* [181] */
    0,  /* [182] */
    0,  /* [183] */
    0,  /* [184] */
    0,  /* [185] */
    0,  /* [186] */
    0,  /* [187] */
    0,  /* [188] */
    0,  /* [189] */
    0,  /* [190] */
    0,  /* [191] */
    0,  /* [192] */
    0,  /* [193] */
    0,  /* [194] */
    0,  /* [195] */
    0,  /* [196] */
    0,  /* [197] */
    0,  /* [198] */
    0,  /* [199] */
    0,  /* [200] */
    0,  /* [201] */
    0,  /* [202] */
    0,  /* [203] */
    0,  /* [204] */
    0,  /* [205] */
    0,  /* [206] */
    0,  /* [207] */
    0,  /* [208] */
    0,  /* [209] */
    0,  /* [210] */
    0,  /* [211] */
    0,  /* [212] */
    0,  /* [213] */
    0,  /* [214] */
    0,  /* [215] */
    0,  /* [216] */
    0,  /* [217] */
    0,  /* [218] */
    0,  /* [219] */
    0,  /* [220] */
    0,  /* [221] */
    0,  /* [222] */
    0,  /* [223] */
};

/* Module__state__V */
#if defined (__ICCARM__)
#pragma location = ".data_ti_sysbios_family_c28_Hwi_Module__state__V"
#endif
#if defined(__GNUC__) && !(defined(__MACH__) && defined(__APPLE__))
#ifndef __ti__
ti_sysbios_family_c28_Hwi_Module_State__ ti_sysbios_family_c28_Hwi_Module__state__V __attribute__ ((section(".data_ti_sysbios_family_c28_Hwi_Module__state__V")));
#elif defined(__clang__)
ti_sysbios_family_c28_Hwi_Module_State__ ti_sysbios_family_c28_Hwi_Module__state__V __attribute__ ((section(".data:ti_sysbios_family_c28_Hwi_Module__state__V")));
#endif
#endif
ti_sysbios_family_c28_Hwi_Module_State__ ti_sysbios_family_c28_Hwi_Module__state__V = {
    (xdc_Bits16)0x2000,  /* ierMask */
    ((xdc_Char*)NULL),  /* isrStack */
    ((xdc_Char*)NULL),  /* taskSP */
    ((void*)ti_sysbios_family_c28_Hwi_Module_State_0_dispatchTable__A),  /* dispatchTable */
    ((xdc_UArg)NULL),  /* irp */
    0,  /* globalEnable */
    (xdc_Bits16)0x0,  /* shadowIER */
    ((xdc_Ptr)((void*)&_stack)),  /* isrStackBase */
    ((xdc_Ptr)((void*)&_STACK_SIZE)),  /* isrStackSize */
};

/* Module__diagsEnabled__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_Hwi_Module__diagsEnabled__C, ".econst:ti_sysbios_family_c28_Hwi_Module__diagsEnabled__C");
asm("	.sect \".econst:ti_sysbios_family_c28_Hwi_Module__diagsEnabled__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_Hwi_Module__diagsEnabled__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_Hwi_Module__diagsEnabled__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_Hwi_Module__diagsEnabled ti_sysbios_family_c28_Hwi_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_Hwi_Module__diagsIncluded__C, ".econst:ti_sysbios_family_c28_Hwi_Module__diagsIncluded__C");
asm("	.sect \".econst:ti_sysbios_family_c28_Hwi_Module__diagsIncluded__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_Hwi_Module__diagsIncluded__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_Hwi_Module__diagsIncluded__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_Hwi_Module__diagsIncluded ti_sysbios_family_c28_Hwi_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_Hwi_Module__diagsMask__C, ".econst:ti_sysbios_family_c28_Hwi_Module__diagsMask__C");
asm("	.sect \".econst:ti_sysbios_family_c28_Hwi_Module__diagsMask__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_Hwi_Module__diagsMask__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_Hwi_Module__diagsMask__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_Hwi_Module__diagsMask ti_sysbios_family_c28_Hwi_Module__diagsMask__C = ((const CT__ti_sysbios_family_c28_Hwi_Module__diagsMask)NULL);

/* Module__gateObj__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_Hwi_Module__gateObj__C, ".econst:ti_sysbios_family_c28_Hwi_Module__gateObj__C");
asm("	.sect \".econst:ti_sysbios_family_c28_Hwi_Module__gateObj__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_Hwi_Module__gateObj__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_Hwi_Module__gateObj__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_Hwi_Module__gateObj ti_sysbios_family_c28_Hwi_Module__gateObj__C = ((const CT__ti_sysbios_family_c28_Hwi_Module__gateObj)NULL);

/* Module__gatePrms__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_Hwi_Module__gatePrms__C, ".econst:ti_sysbios_family_c28_Hwi_Module__gatePrms__C");
asm("	.sect \".econst:ti_sysbios_family_c28_Hwi_Module__gatePrms__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_Hwi_Module__gatePrms__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_Hwi_Module__gatePrms__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_Hwi_Module__gatePrms ti_sysbios_family_c28_Hwi_Module__gatePrms__C = ((const CT__ti_sysbios_family_c28_Hwi_Module__gatePrms)NULL);

/* Module__id__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_Hwi_Module__id__C, ".econst:ti_sysbios_family_c28_Hwi_Module__id__C");
asm("	.sect \".econst:ti_sysbios_family_c28_Hwi_Module__id__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_Hwi_Module__id__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_Hwi_Module__id__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_Hwi_Module__id ti_sysbios_family_c28_Hwi_Module__id__C = (xdc_Bits16)0x8015;

/* Module__loggerDefined__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_Hwi_Module__loggerDefined__C, ".econst:ti_sysbios_family_c28_Hwi_Module__loggerDefined__C");
asm("	.sect \".econst:ti_sysbios_family_c28_Hwi_Module__loggerDefined__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_Hwi_Module__loggerDefined__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_Hwi_Module__loggerDefined__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_Hwi_Module__loggerDefined ti_sysbios_family_c28_Hwi_Module__loggerDefined__C = 1;

/* Module__loggerObj__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_Hwi_Module__loggerObj__C, ".econst:ti_sysbios_family_c28_Hwi_Module__loggerObj__C");
asm("	.sect \".econst:ti_sysbios_family_c28_Hwi_Module__loggerObj__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_Hwi_Module__loggerObj__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_Hwi_Module__loggerObj__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_Hwi_Module__loggerObj ti_sysbios_family_c28_Hwi_Module__loggerObj__C = ((const CT__ti_sysbios_family_c28_Hwi_Module__loggerObj)((void*)(xdc_runtime_ILogger_Handle)&xdc_runtime_LoggerBuf_Object__table__V[0]));

/* Module__loggerFxn0__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_Hwi_Module__loggerFxn0__C, ".econst:ti_sysbios_family_c28_Hwi_Module__loggerFxn0__C");
asm("	.sect \".econst:ti_sysbios_family_c28_Hwi_Module__loggerFxn0__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_Hwi_Module__loggerFxn0__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_Hwi_Module__loggerFxn0__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_Hwi_Module__loggerFxn0 ti_sysbios_family_c28_Hwi_Module__loggerFxn0__C = ((const CT__ti_sysbios_family_c28_Hwi_Module__loggerFxn0)(xdc_runtime_LoggerBuf_write0));

/* Module__loggerFxn1__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_Hwi_Module__loggerFxn1__C, ".econst:ti_sysbios_family_c28_Hwi_Module__loggerFxn1__C");
asm("	.sect \".econst:ti_sysbios_family_c28_Hwi_Module__loggerFxn1__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_Hwi_Module__loggerFxn1__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_Hwi_Module__loggerFxn1__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_Hwi_Module__loggerFxn1 ti_sysbios_family_c28_Hwi_Module__loggerFxn1__C = ((const CT__ti_sysbios_family_c28_Hwi_Module__loggerFxn1)(xdc_runtime_LoggerBuf_write1));

/* Module__loggerFxn2__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_Hwi_Module__loggerFxn2__C, ".econst:ti_sysbios_family_c28_Hwi_Module__loggerFxn2__C");
asm("	.sect \".econst:ti_sysbios_family_c28_Hwi_Module__loggerFxn2__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_Hwi_Module__loggerFxn2__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_Hwi_Module__loggerFxn2__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_Hwi_Module__loggerFxn2 ti_sysbios_family_c28_Hwi_Module__loggerFxn2__C = ((const CT__ti_sysbios_family_c28_Hwi_Module__loggerFxn2)(xdc_runtime_LoggerBuf_write2));

/* Module__loggerFxn4__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_Hwi_Module__loggerFxn4__C, ".econst:ti_sysbios_family_c28_Hwi_Module__loggerFxn4__C");
asm("	.sect \".econst:ti_sysbios_family_c28_Hwi_Module__loggerFxn4__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_Hwi_Module__loggerFxn4__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_Hwi_Module__loggerFxn4__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_Hwi_Module__loggerFxn4 ti_sysbios_family_c28_Hwi_Module__loggerFxn4__C = ((const CT__ti_sysbios_family_c28_Hwi_Module__loggerFxn4)(xdc_runtime_LoggerBuf_write4));

/* Module__loggerFxn8__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_Hwi_Module__loggerFxn8__C, ".econst:ti_sysbios_family_c28_Hwi_Module__loggerFxn8__C");
asm("	.sect \".econst:ti_sysbios_family_c28_Hwi_Module__loggerFxn8__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_Hwi_Module__loggerFxn8__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_Hwi_Module__loggerFxn8__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_Hwi_Module__loggerFxn8 ti_sysbios_family_c28_Hwi_Module__loggerFxn8__C = ((const CT__ti_sysbios_family_c28_Hwi_Module__loggerFxn8)(xdc_runtime_LoggerBuf_write8));

/* Object__count__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_Hwi_Object__count__C, ".econst:ti_sysbios_family_c28_Hwi_Object__count__C");
asm("	.sect \".econst:ti_sysbios_family_c28_Hwi_Object__count__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_Hwi_Object__count__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_Hwi_Object__count__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_Hwi_Object__count ti_sysbios_family_c28_Hwi_Object__count__C = 1;

/* Object__heap__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_Hwi_Object__heap__C, ".econst:ti_sysbios_family_c28_Hwi_Object__heap__C");
asm("	.sect \".econst:ti_sysbios_family_c28_Hwi_Object__heap__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_Hwi_Object__heap__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_Hwi_Object__heap__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_Hwi_Object__heap ti_sysbios_family_c28_Hwi_Object__heap__C = NULL;

/* Object__sizeof__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_Hwi_Object__sizeof__C, ".econst:ti_sysbios_family_c28_Hwi_Object__sizeof__C");
asm("	.sect \".econst:ti_sysbios_family_c28_Hwi_Object__sizeof__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_Hwi_Object__sizeof__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_Hwi_Object__sizeof__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_Hwi_Object__sizeof ti_sysbios_family_c28_Hwi_Object__sizeof__C = sizeof(ti_sysbios_family_c28_Hwi_Object__);

/* Object__table__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_Hwi_Object__table__C, ".econst:ti_sysbios_family_c28_Hwi_Object__table__C");
asm("	.sect \".econst:ti_sysbios_family_c28_Hwi_Object__table__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_Hwi_Object__table__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_Hwi_Object__table__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_Hwi_Object__table ti_sysbios_family_c28_Hwi_Object__table__C = ti_sysbios_family_c28_Hwi_Object__table__V;

/* dispatcherAutoNestingSupport__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_Hwi_dispatcherAutoNestingSupport__C, ".econst:ti_sysbios_family_c28_Hwi_dispatcherAutoNestingSupport__C");
asm("	.sect \".econst:ti_sysbios_family_c28_Hwi_dispatcherAutoNestingSupport__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_Hwi_dispatcherAutoNestingSupport__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_Hwi_dispatcherAutoNestingSupport__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_Hwi_dispatcherAutoNestingSupport ti_sysbios_family_c28_Hwi_dispatcherAutoNestingSupport__C = 1;

/* dispatcherSwiSupport__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_Hwi_dispatcherSwiSupport__C, ".econst:ti_sysbios_family_c28_Hwi_dispatcherSwiSupport__C");
asm("	.sect \".econst:ti_sysbios_family_c28_Hwi_dispatcherSwiSupport__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_Hwi_dispatcherSwiSupport__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_Hwi_dispatcherSwiSupport__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_Hwi_dispatcherSwiSupport ti_sysbios_family_c28_Hwi_dispatcherSwiSupport__C = 1;

/* dispatcherTaskSupport__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_Hwi_dispatcherTaskSupport__C, ".econst:ti_sysbios_family_c28_Hwi_dispatcherTaskSupport__C");
asm("	.sect \".econst:ti_sysbios_family_c28_Hwi_dispatcherTaskSupport__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_Hwi_dispatcherTaskSupport__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_Hwi_dispatcherTaskSupport__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_Hwi_dispatcherTaskSupport ti_sysbios_family_c28_Hwi_dispatcherTaskSupport__C = 1;

/* dispatcherIrpTrackingSupport__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_Hwi_dispatcherIrpTrackingSupport__C, ".econst:ti_sysbios_family_c28_Hwi_dispatcherIrpTrackingSupport__C");
asm("	.sect \".econst:ti_sysbios_family_c28_Hwi_dispatcherIrpTrackingSupport__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_Hwi_dispatcherIrpTrackingSupport__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_Hwi_dispatcherIrpTrackingSupport__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_Hwi_dispatcherIrpTrackingSupport ti_sysbios_family_c28_Hwi_dispatcherIrpTrackingSupport__C = 1;

/* NUM_INTERRUPTS_PIE__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_Hwi_NUM_INTERRUPTS_PIE__C, ".econst:ti_sysbios_family_c28_Hwi_NUM_INTERRUPTS_PIE__C");
asm("	.sect \".econst:ti_sysbios_family_c28_Hwi_NUM_INTERRUPTS_PIE__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_Hwi_NUM_INTERRUPTS_PIE__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_Hwi_NUM_INTERRUPTS_PIE__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_Hwi_NUM_INTERRUPTS_PIE ti_sysbios_family_c28_Hwi_NUM_INTERRUPTS_PIE__C = (xdc_Int)0xc0;

/* NUM_INTERRUPTS_ALL__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_Hwi_NUM_INTERRUPTS_ALL__C, ".econst:ti_sysbios_family_c28_Hwi_NUM_INTERRUPTS_ALL__C");
asm("	.sect \".econst:ti_sysbios_family_c28_Hwi_NUM_INTERRUPTS_ALL__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_Hwi_NUM_INTERRUPTS_ALL__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_Hwi_NUM_INTERRUPTS_ALL__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_Hwi_NUM_INTERRUPTS_ALL ti_sysbios_family_c28_Hwi_NUM_INTERRUPTS_ALL__C = (xdc_Int)0xe0;

/* A_badIntNum__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_Hwi_A_badIntNum__C, ".econst:ti_sysbios_family_c28_Hwi_A_badIntNum__C");
asm("	.sect \".econst:ti_sysbios_family_c28_Hwi_A_badIntNum__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_Hwi_A_badIntNum__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_Hwi_A_badIntNum__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_Hwi_A_badIntNum ti_sysbios_family_c28_Hwi_A_badIntNum__C = (((xdc_runtime_Assert_Id)400) << 16 | 16);

/* A_invalidArg__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_Hwi_A_invalidArg__C, ".econst:ti_sysbios_family_c28_Hwi_A_invalidArg__C");
asm("	.sect \".econst:ti_sysbios_family_c28_Hwi_A_invalidArg__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_Hwi_A_invalidArg__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_Hwi_A_invalidArg__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_Hwi_A_invalidArg ti_sysbios_family_c28_Hwi_A_invalidArg__C = (((xdc_runtime_Assert_Id)438) << 16 | 16);

/* A_zeroLatencyConflict__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_Hwi_A_zeroLatencyConflict__C, ".econst:ti_sysbios_family_c28_Hwi_A_zeroLatencyConflict__C");
asm("	.sect \".econst:ti_sysbios_family_c28_Hwi_A_zeroLatencyConflict__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_Hwi_A_zeroLatencyConflict__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_Hwi_A_zeroLatencyConflict__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_Hwi_A_zeroLatencyConflict ti_sysbios_family_c28_Hwi_A_zeroLatencyConflict__C = (((xdc_runtime_Assert_Id)469) << 16 | 16);

/* E_unpluggedInterrupt__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_Hwi_E_unpluggedInterrupt__C, ".econst:ti_sysbios_family_c28_Hwi_E_unpluggedInterrupt__C");
asm("	.sect \".econst:ti_sysbios_family_c28_Hwi_E_unpluggedInterrupt__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_Hwi_E_unpluggedInterrupt__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_Hwi_E_unpluggedInterrupt__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_Hwi_E_unpluggedInterrupt ti_sysbios_family_c28_Hwi_E_unpluggedInterrupt__C = (((xdc_runtime_Error_Id)3815) << 16 | 0U);

/* E_alreadyDefined__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_Hwi_E_alreadyDefined__C, ".econst:ti_sysbios_family_c28_Hwi_E_alreadyDefined__C");
asm("	.sect \".econst:ti_sysbios_family_c28_Hwi_E_alreadyDefined__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_Hwi_E_alreadyDefined__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_Hwi_E_alreadyDefined__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_Hwi_E_alreadyDefined ti_sysbios_family_c28_Hwi_E_alreadyDefined__C = (((xdc_runtime_Error_Id)3875) << 16 | 0U);

/* zeroLatencyIERMask__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_Hwi_zeroLatencyIERMask__C, ".econst:ti_sysbios_family_c28_Hwi_zeroLatencyIERMask__C");
asm("	.sect \".econst:ti_sysbios_family_c28_Hwi_zeroLatencyIERMask__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_Hwi_zeroLatencyIERMask__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_Hwi_zeroLatencyIERMask__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_Hwi_zeroLatencyIERMask ti_sysbios_family_c28_Hwi_zeroLatencyIERMask__C = (xdc_Bits16)0x0;

/* LM_begin__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_Hwi_LM_begin__C, ".econst:ti_sysbios_family_c28_Hwi_LM_begin__C");
asm("	.sect \".econst:ti_sysbios_family_c28_Hwi_LM_begin__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_Hwi_LM_begin__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_Hwi_LM_begin__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_Hwi_LM_begin ti_sysbios_family_c28_Hwi_LM_begin__C = (((xdc_runtime_Log_Event)4801) << 16 | 768);

/* LD_end__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_Hwi_LD_end__C, ".econst:ti_sysbios_family_c28_Hwi_LD_end__C");
asm("	.sect \".econst:ti_sysbios_family_c28_Hwi_LD_end__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_Hwi_LD_end__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_Hwi_LD_end__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_Hwi_LD_end ti_sysbios_family_c28_Hwi_LD_end__C = (((xdc_runtime_Log_Event)4871) << 16 | 512);

/* swiDisable__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_Hwi_swiDisable__C, ".econst:ti_sysbios_family_c28_Hwi_swiDisable__C");
asm("	.sect \".econst:ti_sysbios_family_c28_Hwi_swiDisable__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_Hwi_swiDisable__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_Hwi_swiDisable__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_Hwi_swiDisable ti_sysbios_family_c28_Hwi_swiDisable__C = ((const CT__ti_sysbios_family_c28_Hwi_swiDisable)(ti_sysbios_knl_Swi_disable__E));

/* swiRestoreHwi__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_Hwi_swiRestoreHwi__C, ".econst:ti_sysbios_family_c28_Hwi_swiRestoreHwi__C");
asm("	.sect \".econst:ti_sysbios_family_c28_Hwi_swiRestoreHwi__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_Hwi_swiRestoreHwi__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_Hwi_swiRestoreHwi__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_Hwi_swiRestoreHwi ti_sysbios_family_c28_Hwi_swiRestoreHwi__C = ((const CT__ti_sysbios_family_c28_Hwi_swiRestoreHwi)(ti_sysbios_knl_Swi_restoreHwi__E));

/* taskDisable__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_Hwi_taskDisable__C, ".econst:ti_sysbios_family_c28_Hwi_taskDisable__C");
asm("	.sect \".econst:ti_sysbios_family_c28_Hwi_taskDisable__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_Hwi_taskDisable__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_Hwi_taskDisable__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_Hwi_taskDisable ti_sysbios_family_c28_Hwi_taskDisable__C = ((const CT__ti_sysbios_family_c28_Hwi_taskDisable)(ti_sysbios_knl_Task_disable__E));

/* taskRestoreHwi__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_Hwi_taskRestoreHwi__C, ".econst:ti_sysbios_family_c28_Hwi_taskRestoreHwi__C");
asm("	.sect \".econst:ti_sysbios_family_c28_Hwi_taskRestoreHwi__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_Hwi_taskRestoreHwi__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_Hwi_taskRestoreHwi__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_Hwi_taskRestoreHwi ti_sysbios_family_c28_Hwi_taskRestoreHwi__C = ((const CT__ti_sysbios_family_c28_Hwi_taskRestoreHwi)(ti_sysbios_knl_Task_restoreHwi__E));

/* hooks__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_Hwi_hooks__C, ".econst:ti_sysbios_family_c28_Hwi_hooks__C");
asm("	.sect \".econst:ti_sysbios_family_c28_Hwi_hooks__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_Hwi_hooks__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_Hwi_hooks__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_Hwi_hooks ti_sysbios_family_c28_Hwi_hooks__C = {0, 0};


/*
 * ======== ti.sysbios.family.c28.IntrinsicsSupport INITIALIZERS ========
 */

/* Module__diagsEnabled__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_IntrinsicsSupport_Module__diagsEnabled__C, ".econst:ti_sysbios_family_c28_IntrinsicsSupport_Module__diagsEnabled__C");
asm("	.sect \".econst:ti_sysbios_family_c28_IntrinsicsSupport_Module__diagsEnabled__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_IntrinsicsSupport_Module__diagsEnabled__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_IntrinsicsSupport_Module__diagsEnabled__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_IntrinsicsSupport_Module__diagsEnabled ti_sysbios_family_c28_IntrinsicsSupport_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_IntrinsicsSupport_Module__diagsIncluded__C, ".econst:ti_sysbios_family_c28_IntrinsicsSupport_Module__diagsIncluded__C");
asm("	.sect \".econst:ti_sysbios_family_c28_IntrinsicsSupport_Module__diagsIncluded__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_IntrinsicsSupport_Module__diagsIncluded__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_IntrinsicsSupport_Module__diagsIncluded__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_IntrinsicsSupport_Module__diagsIncluded ti_sysbios_family_c28_IntrinsicsSupport_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_IntrinsicsSupport_Module__diagsMask__C, ".econst:ti_sysbios_family_c28_IntrinsicsSupport_Module__diagsMask__C");
asm("	.sect \".econst:ti_sysbios_family_c28_IntrinsicsSupport_Module__diagsMask__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_IntrinsicsSupport_Module__diagsMask__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_IntrinsicsSupport_Module__diagsMask__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_IntrinsicsSupport_Module__diagsMask ti_sysbios_family_c28_IntrinsicsSupport_Module__diagsMask__C = ((const CT__ti_sysbios_family_c28_IntrinsicsSupport_Module__diagsMask)NULL);

/* Module__gateObj__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_IntrinsicsSupport_Module__gateObj__C, ".econst:ti_sysbios_family_c28_IntrinsicsSupport_Module__gateObj__C");
asm("	.sect \".econst:ti_sysbios_family_c28_IntrinsicsSupport_Module__gateObj__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_IntrinsicsSupport_Module__gateObj__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_IntrinsicsSupport_Module__gateObj__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_IntrinsicsSupport_Module__gateObj ti_sysbios_family_c28_IntrinsicsSupport_Module__gateObj__C = ((const CT__ti_sysbios_family_c28_IntrinsicsSupport_Module__gateObj)NULL);

/* Module__gatePrms__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_IntrinsicsSupport_Module__gatePrms__C, ".econst:ti_sysbios_family_c28_IntrinsicsSupport_Module__gatePrms__C");
asm("	.sect \".econst:ti_sysbios_family_c28_IntrinsicsSupport_Module__gatePrms__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_IntrinsicsSupport_Module__gatePrms__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_IntrinsicsSupport_Module__gatePrms__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_IntrinsicsSupport_Module__gatePrms ti_sysbios_family_c28_IntrinsicsSupport_Module__gatePrms__C = ((const CT__ti_sysbios_family_c28_IntrinsicsSupport_Module__gatePrms)NULL);

/* Module__id__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_IntrinsicsSupport_Module__id__C, ".econst:ti_sysbios_family_c28_IntrinsicsSupport_Module__id__C");
asm("	.sect \".econst:ti_sysbios_family_c28_IntrinsicsSupport_Module__id__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_IntrinsicsSupport_Module__id__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_IntrinsicsSupport_Module__id__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_IntrinsicsSupport_Module__id ti_sysbios_family_c28_IntrinsicsSupport_Module__id__C = (xdc_Bits16)0x8017;

/* Module__loggerDefined__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_IntrinsicsSupport_Module__loggerDefined__C, ".econst:ti_sysbios_family_c28_IntrinsicsSupport_Module__loggerDefined__C");
asm("	.sect \".econst:ti_sysbios_family_c28_IntrinsicsSupport_Module__loggerDefined__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_IntrinsicsSupport_Module__loggerDefined__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_IntrinsicsSupport_Module__loggerDefined__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_IntrinsicsSupport_Module__loggerDefined ti_sysbios_family_c28_IntrinsicsSupport_Module__loggerDefined__C = 1;

/* Module__loggerObj__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_IntrinsicsSupport_Module__loggerObj__C, ".econst:ti_sysbios_family_c28_IntrinsicsSupport_Module__loggerObj__C");
asm("	.sect \".econst:ti_sysbios_family_c28_IntrinsicsSupport_Module__loggerObj__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_IntrinsicsSupport_Module__loggerObj__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_IntrinsicsSupport_Module__loggerObj__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_IntrinsicsSupport_Module__loggerObj ti_sysbios_family_c28_IntrinsicsSupport_Module__loggerObj__C = ((const CT__ti_sysbios_family_c28_IntrinsicsSupport_Module__loggerObj)((void*)(xdc_runtime_ILogger_Handle)&xdc_runtime_LoggerBuf_Object__table__V[0]));

/* Module__loggerFxn0__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_IntrinsicsSupport_Module__loggerFxn0__C, ".econst:ti_sysbios_family_c28_IntrinsicsSupport_Module__loggerFxn0__C");
asm("	.sect \".econst:ti_sysbios_family_c28_IntrinsicsSupport_Module__loggerFxn0__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_IntrinsicsSupport_Module__loggerFxn0__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_IntrinsicsSupport_Module__loggerFxn0__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_IntrinsicsSupport_Module__loggerFxn0 ti_sysbios_family_c28_IntrinsicsSupport_Module__loggerFxn0__C = ((const CT__ti_sysbios_family_c28_IntrinsicsSupport_Module__loggerFxn0)(xdc_runtime_LoggerBuf_write0));

/* Module__loggerFxn1__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_IntrinsicsSupport_Module__loggerFxn1__C, ".econst:ti_sysbios_family_c28_IntrinsicsSupport_Module__loggerFxn1__C");
asm("	.sect \".econst:ti_sysbios_family_c28_IntrinsicsSupport_Module__loggerFxn1__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_IntrinsicsSupport_Module__loggerFxn1__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_IntrinsicsSupport_Module__loggerFxn1__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_IntrinsicsSupport_Module__loggerFxn1 ti_sysbios_family_c28_IntrinsicsSupport_Module__loggerFxn1__C = ((const CT__ti_sysbios_family_c28_IntrinsicsSupport_Module__loggerFxn1)(xdc_runtime_LoggerBuf_write1));

/* Module__loggerFxn2__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_IntrinsicsSupport_Module__loggerFxn2__C, ".econst:ti_sysbios_family_c28_IntrinsicsSupport_Module__loggerFxn2__C");
asm("	.sect \".econst:ti_sysbios_family_c28_IntrinsicsSupport_Module__loggerFxn2__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_IntrinsicsSupport_Module__loggerFxn2__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_IntrinsicsSupport_Module__loggerFxn2__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_IntrinsicsSupport_Module__loggerFxn2 ti_sysbios_family_c28_IntrinsicsSupport_Module__loggerFxn2__C = ((const CT__ti_sysbios_family_c28_IntrinsicsSupport_Module__loggerFxn2)(xdc_runtime_LoggerBuf_write2));

/* Module__loggerFxn4__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_IntrinsicsSupport_Module__loggerFxn4__C, ".econst:ti_sysbios_family_c28_IntrinsicsSupport_Module__loggerFxn4__C");
asm("	.sect \".econst:ti_sysbios_family_c28_IntrinsicsSupport_Module__loggerFxn4__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_IntrinsicsSupport_Module__loggerFxn4__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_IntrinsicsSupport_Module__loggerFxn4__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_IntrinsicsSupport_Module__loggerFxn4 ti_sysbios_family_c28_IntrinsicsSupport_Module__loggerFxn4__C = ((const CT__ti_sysbios_family_c28_IntrinsicsSupport_Module__loggerFxn4)(xdc_runtime_LoggerBuf_write4));

/* Module__loggerFxn8__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_IntrinsicsSupport_Module__loggerFxn8__C, ".econst:ti_sysbios_family_c28_IntrinsicsSupport_Module__loggerFxn8__C");
asm("	.sect \".econst:ti_sysbios_family_c28_IntrinsicsSupport_Module__loggerFxn8__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_IntrinsicsSupport_Module__loggerFxn8__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_IntrinsicsSupport_Module__loggerFxn8__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_IntrinsicsSupport_Module__loggerFxn8 ti_sysbios_family_c28_IntrinsicsSupport_Module__loggerFxn8__C = ((const CT__ti_sysbios_family_c28_IntrinsicsSupport_Module__loggerFxn8)(xdc_runtime_LoggerBuf_write8));

/* Object__count__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_IntrinsicsSupport_Object__count__C, ".econst:ti_sysbios_family_c28_IntrinsicsSupport_Object__count__C");
asm("	.sect \".econst:ti_sysbios_family_c28_IntrinsicsSupport_Object__count__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_IntrinsicsSupport_Object__count__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_IntrinsicsSupport_Object__count__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_IntrinsicsSupport_Object__count ti_sysbios_family_c28_IntrinsicsSupport_Object__count__C = 0;

/* Object__heap__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_IntrinsicsSupport_Object__heap__C, ".econst:ti_sysbios_family_c28_IntrinsicsSupport_Object__heap__C");
asm("	.sect \".econst:ti_sysbios_family_c28_IntrinsicsSupport_Object__heap__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_IntrinsicsSupport_Object__heap__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_IntrinsicsSupport_Object__heap__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_IntrinsicsSupport_Object__heap ti_sysbios_family_c28_IntrinsicsSupport_Object__heap__C = NULL;

/* Object__sizeof__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_IntrinsicsSupport_Object__sizeof__C, ".econst:ti_sysbios_family_c28_IntrinsicsSupport_Object__sizeof__C");
asm("	.sect \".econst:ti_sysbios_family_c28_IntrinsicsSupport_Object__sizeof__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_IntrinsicsSupport_Object__sizeof__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_IntrinsicsSupport_Object__sizeof__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_IntrinsicsSupport_Object__sizeof ti_sysbios_family_c28_IntrinsicsSupport_Object__sizeof__C = 0;

/* Object__table__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_IntrinsicsSupport_Object__table__C, ".econst:ti_sysbios_family_c28_IntrinsicsSupport_Object__table__C");
asm("	.sect \".econst:ti_sysbios_family_c28_IntrinsicsSupport_Object__table__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_IntrinsicsSupport_Object__table__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_IntrinsicsSupport_Object__table__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_IntrinsicsSupport_Object__table ti_sysbios_family_c28_IntrinsicsSupport_Object__table__C = NULL;


/*
 * ======== ti.sysbios.family.c28.TaskSupport INITIALIZERS ========
 */

/* Module__diagsEnabled__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_TaskSupport_Module__diagsEnabled__C, ".econst:ti_sysbios_family_c28_TaskSupport_Module__diagsEnabled__C");
asm("	.sect \".econst:ti_sysbios_family_c28_TaskSupport_Module__diagsEnabled__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_TaskSupport_Module__diagsEnabled__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_TaskSupport_Module__diagsEnabled__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_TaskSupport_Module__diagsEnabled ti_sysbios_family_c28_TaskSupport_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_TaskSupport_Module__diagsIncluded__C, ".econst:ti_sysbios_family_c28_TaskSupport_Module__diagsIncluded__C");
asm("	.sect \".econst:ti_sysbios_family_c28_TaskSupport_Module__diagsIncluded__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_TaskSupport_Module__diagsIncluded__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_TaskSupport_Module__diagsIncluded__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_TaskSupport_Module__diagsIncluded ti_sysbios_family_c28_TaskSupport_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_TaskSupport_Module__diagsMask__C, ".econst:ti_sysbios_family_c28_TaskSupport_Module__diagsMask__C");
asm("	.sect \".econst:ti_sysbios_family_c28_TaskSupport_Module__diagsMask__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_TaskSupport_Module__diagsMask__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_TaskSupport_Module__diagsMask__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_TaskSupport_Module__diagsMask ti_sysbios_family_c28_TaskSupport_Module__diagsMask__C = ((const CT__ti_sysbios_family_c28_TaskSupport_Module__diagsMask)NULL);

/* Module__gateObj__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_TaskSupport_Module__gateObj__C, ".econst:ti_sysbios_family_c28_TaskSupport_Module__gateObj__C");
asm("	.sect \".econst:ti_sysbios_family_c28_TaskSupport_Module__gateObj__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_TaskSupport_Module__gateObj__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_TaskSupport_Module__gateObj__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_TaskSupport_Module__gateObj ti_sysbios_family_c28_TaskSupport_Module__gateObj__C = ((const CT__ti_sysbios_family_c28_TaskSupport_Module__gateObj)NULL);

/* Module__gatePrms__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_TaskSupport_Module__gatePrms__C, ".econst:ti_sysbios_family_c28_TaskSupport_Module__gatePrms__C");
asm("	.sect \".econst:ti_sysbios_family_c28_TaskSupport_Module__gatePrms__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_TaskSupport_Module__gatePrms__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_TaskSupport_Module__gatePrms__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_TaskSupport_Module__gatePrms ti_sysbios_family_c28_TaskSupport_Module__gatePrms__C = ((const CT__ti_sysbios_family_c28_TaskSupport_Module__gatePrms)NULL);

/* Module__id__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_TaskSupport_Module__id__C, ".econst:ti_sysbios_family_c28_TaskSupport_Module__id__C");
asm("	.sect \".econst:ti_sysbios_family_c28_TaskSupport_Module__id__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_TaskSupport_Module__id__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_TaskSupport_Module__id__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_TaskSupport_Module__id ti_sysbios_family_c28_TaskSupport_Module__id__C = (xdc_Bits16)0x8018;

/* Module__loggerDefined__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_TaskSupport_Module__loggerDefined__C, ".econst:ti_sysbios_family_c28_TaskSupport_Module__loggerDefined__C");
asm("	.sect \".econst:ti_sysbios_family_c28_TaskSupport_Module__loggerDefined__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_TaskSupport_Module__loggerDefined__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_TaskSupport_Module__loggerDefined__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_TaskSupport_Module__loggerDefined ti_sysbios_family_c28_TaskSupport_Module__loggerDefined__C = 1;

/* Module__loggerObj__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_TaskSupport_Module__loggerObj__C, ".econst:ti_sysbios_family_c28_TaskSupport_Module__loggerObj__C");
asm("	.sect \".econst:ti_sysbios_family_c28_TaskSupport_Module__loggerObj__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_TaskSupport_Module__loggerObj__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_TaskSupport_Module__loggerObj__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_TaskSupport_Module__loggerObj ti_sysbios_family_c28_TaskSupport_Module__loggerObj__C = ((const CT__ti_sysbios_family_c28_TaskSupport_Module__loggerObj)((void*)(xdc_runtime_ILogger_Handle)&xdc_runtime_LoggerBuf_Object__table__V[0]));

/* Module__loggerFxn0__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_TaskSupport_Module__loggerFxn0__C, ".econst:ti_sysbios_family_c28_TaskSupport_Module__loggerFxn0__C");
asm("	.sect \".econst:ti_sysbios_family_c28_TaskSupport_Module__loggerFxn0__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_TaskSupport_Module__loggerFxn0__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_TaskSupport_Module__loggerFxn0__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_TaskSupport_Module__loggerFxn0 ti_sysbios_family_c28_TaskSupport_Module__loggerFxn0__C = ((const CT__ti_sysbios_family_c28_TaskSupport_Module__loggerFxn0)(xdc_runtime_LoggerBuf_write0));

/* Module__loggerFxn1__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_TaskSupport_Module__loggerFxn1__C, ".econst:ti_sysbios_family_c28_TaskSupport_Module__loggerFxn1__C");
asm("	.sect \".econst:ti_sysbios_family_c28_TaskSupport_Module__loggerFxn1__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_TaskSupport_Module__loggerFxn1__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_TaskSupport_Module__loggerFxn1__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_TaskSupport_Module__loggerFxn1 ti_sysbios_family_c28_TaskSupport_Module__loggerFxn1__C = ((const CT__ti_sysbios_family_c28_TaskSupport_Module__loggerFxn1)(xdc_runtime_LoggerBuf_write1));

/* Module__loggerFxn2__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_TaskSupport_Module__loggerFxn2__C, ".econst:ti_sysbios_family_c28_TaskSupport_Module__loggerFxn2__C");
asm("	.sect \".econst:ti_sysbios_family_c28_TaskSupport_Module__loggerFxn2__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_TaskSupport_Module__loggerFxn2__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_TaskSupport_Module__loggerFxn2__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_TaskSupport_Module__loggerFxn2 ti_sysbios_family_c28_TaskSupport_Module__loggerFxn2__C = ((const CT__ti_sysbios_family_c28_TaskSupport_Module__loggerFxn2)(xdc_runtime_LoggerBuf_write2));

/* Module__loggerFxn4__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_TaskSupport_Module__loggerFxn4__C, ".econst:ti_sysbios_family_c28_TaskSupport_Module__loggerFxn4__C");
asm("	.sect \".econst:ti_sysbios_family_c28_TaskSupport_Module__loggerFxn4__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_TaskSupport_Module__loggerFxn4__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_TaskSupport_Module__loggerFxn4__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_TaskSupport_Module__loggerFxn4 ti_sysbios_family_c28_TaskSupport_Module__loggerFxn4__C = ((const CT__ti_sysbios_family_c28_TaskSupport_Module__loggerFxn4)(xdc_runtime_LoggerBuf_write4));

/* Module__loggerFxn8__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_TaskSupport_Module__loggerFxn8__C, ".econst:ti_sysbios_family_c28_TaskSupport_Module__loggerFxn8__C");
asm("	.sect \".econst:ti_sysbios_family_c28_TaskSupport_Module__loggerFxn8__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_TaskSupport_Module__loggerFxn8__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_TaskSupport_Module__loggerFxn8__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_TaskSupport_Module__loggerFxn8 ti_sysbios_family_c28_TaskSupport_Module__loggerFxn8__C = ((const CT__ti_sysbios_family_c28_TaskSupport_Module__loggerFxn8)(xdc_runtime_LoggerBuf_write8));

/* Object__count__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_TaskSupport_Object__count__C, ".econst:ti_sysbios_family_c28_TaskSupport_Object__count__C");
asm("	.sect \".econst:ti_sysbios_family_c28_TaskSupport_Object__count__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_TaskSupport_Object__count__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_TaskSupport_Object__count__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_TaskSupport_Object__count ti_sysbios_family_c28_TaskSupport_Object__count__C = 0;

/* Object__heap__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_TaskSupport_Object__heap__C, ".econst:ti_sysbios_family_c28_TaskSupport_Object__heap__C");
asm("	.sect \".econst:ti_sysbios_family_c28_TaskSupport_Object__heap__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_TaskSupport_Object__heap__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_TaskSupport_Object__heap__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_TaskSupport_Object__heap ti_sysbios_family_c28_TaskSupport_Object__heap__C = NULL;

/* Object__sizeof__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_TaskSupport_Object__sizeof__C, ".econst:ti_sysbios_family_c28_TaskSupport_Object__sizeof__C");
asm("	.sect \".econst:ti_sysbios_family_c28_TaskSupport_Object__sizeof__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_TaskSupport_Object__sizeof__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_TaskSupport_Object__sizeof__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_TaskSupport_Object__sizeof ti_sysbios_family_c28_TaskSupport_Object__sizeof__C = 0;

/* Object__table__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_TaskSupport_Object__table__C, ".econst:ti_sysbios_family_c28_TaskSupport_Object__table__C");
asm("	.sect \".econst:ti_sysbios_family_c28_TaskSupport_Object__table__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_TaskSupport_Object__table__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_TaskSupport_Object__table__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_TaskSupport_Object__table ti_sysbios_family_c28_TaskSupport_Object__table__C = NULL;

/* defaultStackSize__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_TaskSupport_defaultStackSize__C, ".econst:ti_sysbios_family_c28_TaskSupport_defaultStackSize__C");
asm("	.sect \".econst:ti_sysbios_family_c28_TaskSupport_defaultStackSize__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_TaskSupport_defaultStackSize__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_TaskSupport_defaultStackSize__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_TaskSupport_defaultStackSize ti_sysbios_family_c28_TaskSupport_defaultStackSize__C = (xdc_SizeT)0x100;

/* stackAlignment__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_TaskSupport_stackAlignment__C, ".econst:ti_sysbios_family_c28_TaskSupport_stackAlignment__C");
asm("	.sect \".econst:ti_sysbios_family_c28_TaskSupport_stackAlignment__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_TaskSupport_stackAlignment__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_TaskSupport_stackAlignment__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_TaskSupport_stackAlignment ti_sysbios_family_c28_TaskSupport_stackAlignment__C = (xdc_UInt)0x2;

/* E_invalidStack__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_TaskSupport_E_invalidStack__C, ".econst:ti_sysbios_family_c28_TaskSupport_E_invalidStack__C");
asm("	.sect \".econst:ti_sysbios_family_c28_TaskSupport_E_invalidStack__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_TaskSupport_E_invalidStack__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_TaskSupport_E_invalidStack__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_TaskSupport_E_invalidStack ti_sysbios_family_c28_TaskSupport_E_invalidStack__C = (((xdc_runtime_Error_Id)3962) << 16 | 0U);


/*
 * ======== ti.sysbios.family.c28.Timer INITIALIZERS ========
 */

/* Object__DESC__C */
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_family_c28_Timer_Object__DESC__C;

/* Object__PARAMS__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_Timer_Object__PARAMS__C, ".econst:ti_sysbios_family_c28_Timer_Object__PARAMS__C");
asm("	.sect \".econst:ti_sysbios_family_c28_Timer_Object__PARAMS__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_Timer_Object__PARAMS__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_Timer_Object__PARAMS__C\"");
asm("	.clink ");

__FAR__ const ti_sysbios_family_c28_Timer_Params ti_sysbios_family_c28_Timer_Object__PARAMS__C = {
    sizeof (ti_sysbios_family_c28_Timer_Params), /* __size */
    NULL, /* __self */
    NULL, /* __fxns */
    (xdc_runtime_IInstance_Params*)&ti_sysbios_family_c28_Timer_Object__PARAMS__C.__iprms, /* instance */
    ti_sysbios_interfaces_ITimer_RunMode_CONTINUOUS,  /* runMode */
    ti_sysbios_interfaces_ITimer_StartMode_AUTO,  /* startMode */
    ((xdc_UArg)NULL),  /* arg */
    (xdc_UInt32)0x0,  /* period */
    ti_sysbios_interfaces_ITimer_PeriodType_MICROSECS,  /* periodType */
    {
        (xdc_Bits32)0x0,  /* hi */
        (xdc_Bits32)0x0,  /* lo */
    },  /* extFreq */
    {
        (xdc_UInt)0x0,  /* free */
        (xdc_UInt)0x0,  /* soft */
    },  /* emulationModeInit */
    (xdc_UInt16)0x0,  /* prescale */
    ((ti_sysbios_family_c28_Hwi_Params*)NULL),  /* hwiParams */
    {
        sizeof (xdc_runtime_IInstance_Params), /* __size */
        0,  /* name */
    },  /* instance */
};

/* Module__root__V */
ti_sysbios_family_c28_Timer_Module__ ti_sysbios_family_c28_Timer_Module__root__V = {
    {&ti_sysbios_family_c28_Timer_Module__root__V.link,  /* link.next */
    &ti_sysbios_family_c28_Timer_Module__root__V.link},  /* link.prev */
};

/* Object__table__V */
ti_sysbios_family_c28_Timer_Object__ ti_sysbios_family_c28_Timer_Object__table__V[1] = {
    {/* instance#0 */
        0,
        (xdc_Int)0x2,  /* id */
        {
            (xdc_UInt)0x0,  /* free */
            (xdc_UInt)0x0,  /* soft */
        },  /* emulationModeInit */
        ti_sysbios_interfaces_ITimer_RunMode_CONTINUOUS,  /* runMode */
        ti_sysbios_interfaces_ITimer_StartMode_AUTO,  /* startMode */
        (xdc_UInt32)0x9c4,  /* period */
        ti_sysbios_interfaces_ITimer_PeriodType_COUNTS,  /* periodType */
        (xdc_UInt16)0x0,  /* prescale */
        (xdc_UInt)0xe,  /* intNum */
        ((xdc_UArg)NULL),  /* arg */
        ((xdc_Void(*)(xdc_UArg f_arg0))(ti_sysbios_knl_Clock_doTick__I)),  /* tickFxn */
        {
            (xdc_Bits32)0x0,  /* hi */
            (xdc_Bits32)0x0,  /* lo */
        },  /* extFreq */
        (ti_sysbios_family_c28_Hwi_Handle)&ti_sysbios_family_c28_Hwi_Object__table__V[0],  /* hwi */
    },
};

/* Module__state__V */
#if defined (__ICCARM__)
#pragma location = ".data_ti_sysbios_family_c28_Timer_Module__state__V"
#endif
#if defined(__GNUC__) && !(defined(__MACH__) && defined(__APPLE__))
#ifndef __ti__
ti_sysbios_family_c28_Timer_Module_State__ ti_sysbios_family_c28_Timer_Module__state__V __attribute__ ((section(".data_ti_sysbios_family_c28_Timer_Module__state__V")));
#elif defined(__clang__)
ti_sysbios_family_c28_Timer_Module_State__ ti_sysbios_family_c28_Timer_Module__state__V __attribute__ ((section(".data:ti_sysbios_family_c28_Timer_Module__state__V")));
#endif
#endif
ti_sysbios_family_c28_Timer_Module_State__ ti_sysbios_family_c28_Timer_Module__state__V = {
    (xdc_Char)0x3,  /* availMask */
    {
        0,  /* [0] */
        0,  /* [1] */
        (ti_sysbios_family_c28_Timer_Handle)&ti_sysbios_family_c28_Timer_Object__table__V[0],  /* [2] */
    },  /* staticTimers */
};

/* Module__diagsEnabled__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_Timer_Module__diagsEnabled__C, ".econst:ti_sysbios_family_c28_Timer_Module__diagsEnabled__C");
asm("	.sect \".econst:ti_sysbios_family_c28_Timer_Module__diagsEnabled__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_Timer_Module__diagsEnabled__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_Timer_Module__diagsEnabled__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_Timer_Module__diagsEnabled ti_sysbios_family_c28_Timer_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_Timer_Module__diagsIncluded__C, ".econst:ti_sysbios_family_c28_Timer_Module__diagsIncluded__C");
asm("	.sect \".econst:ti_sysbios_family_c28_Timer_Module__diagsIncluded__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_Timer_Module__diagsIncluded__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_Timer_Module__diagsIncluded__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_Timer_Module__diagsIncluded ti_sysbios_family_c28_Timer_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_Timer_Module__diagsMask__C, ".econst:ti_sysbios_family_c28_Timer_Module__diagsMask__C");
asm("	.sect \".econst:ti_sysbios_family_c28_Timer_Module__diagsMask__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_Timer_Module__diagsMask__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_Timer_Module__diagsMask__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_Timer_Module__diagsMask ti_sysbios_family_c28_Timer_Module__diagsMask__C = ((const CT__ti_sysbios_family_c28_Timer_Module__diagsMask)NULL);

/* Module__gateObj__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_Timer_Module__gateObj__C, ".econst:ti_sysbios_family_c28_Timer_Module__gateObj__C");
asm("	.sect \".econst:ti_sysbios_family_c28_Timer_Module__gateObj__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_Timer_Module__gateObj__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_Timer_Module__gateObj__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_Timer_Module__gateObj ti_sysbios_family_c28_Timer_Module__gateObj__C = ((const CT__ti_sysbios_family_c28_Timer_Module__gateObj)NULL);

/* Module__gatePrms__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_Timer_Module__gatePrms__C, ".econst:ti_sysbios_family_c28_Timer_Module__gatePrms__C");
asm("	.sect \".econst:ti_sysbios_family_c28_Timer_Module__gatePrms__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_Timer_Module__gatePrms__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_Timer_Module__gatePrms__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_Timer_Module__gatePrms ti_sysbios_family_c28_Timer_Module__gatePrms__C = ((const CT__ti_sysbios_family_c28_Timer_Module__gatePrms)NULL);

/* Module__id__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_Timer_Module__id__C, ".econst:ti_sysbios_family_c28_Timer_Module__id__C");
asm("	.sect \".econst:ti_sysbios_family_c28_Timer_Module__id__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_Timer_Module__id__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_Timer_Module__id__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_Timer_Module__id ti_sysbios_family_c28_Timer_Module__id__C = (xdc_Bits16)0x8016;

/* Module__loggerDefined__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_Timer_Module__loggerDefined__C, ".econst:ti_sysbios_family_c28_Timer_Module__loggerDefined__C");
asm("	.sect \".econst:ti_sysbios_family_c28_Timer_Module__loggerDefined__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_Timer_Module__loggerDefined__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_Timer_Module__loggerDefined__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_Timer_Module__loggerDefined ti_sysbios_family_c28_Timer_Module__loggerDefined__C = 1;

/* Module__loggerObj__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_Timer_Module__loggerObj__C, ".econst:ti_sysbios_family_c28_Timer_Module__loggerObj__C");
asm("	.sect \".econst:ti_sysbios_family_c28_Timer_Module__loggerObj__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_Timer_Module__loggerObj__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_Timer_Module__loggerObj__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_Timer_Module__loggerObj ti_sysbios_family_c28_Timer_Module__loggerObj__C = ((const CT__ti_sysbios_family_c28_Timer_Module__loggerObj)((void*)(xdc_runtime_ILogger_Handle)&xdc_runtime_LoggerBuf_Object__table__V[0]));

/* Module__loggerFxn0__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_Timer_Module__loggerFxn0__C, ".econst:ti_sysbios_family_c28_Timer_Module__loggerFxn0__C");
asm("	.sect \".econst:ti_sysbios_family_c28_Timer_Module__loggerFxn0__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_Timer_Module__loggerFxn0__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_Timer_Module__loggerFxn0__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_Timer_Module__loggerFxn0 ti_sysbios_family_c28_Timer_Module__loggerFxn0__C = ((const CT__ti_sysbios_family_c28_Timer_Module__loggerFxn0)(xdc_runtime_LoggerBuf_write0));

/* Module__loggerFxn1__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_Timer_Module__loggerFxn1__C, ".econst:ti_sysbios_family_c28_Timer_Module__loggerFxn1__C");
asm("	.sect \".econst:ti_sysbios_family_c28_Timer_Module__loggerFxn1__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_Timer_Module__loggerFxn1__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_Timer_Module__loggerFxn1__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_Timer_Module__loggerFxn1 ti_sysbios_family_c28_Timer_Module__loggerFxn1__C = ((const CT__ti_sysbios_family_c28_Timer_Module__loggerFxn1)(xdc_runtime_LoggerBuf_write1));

/* Module__loggerFxn2__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_Timer_Module__loggerFxn2__C, ".econst:ti_sysbios_family_c28_Timer_Module__loggerFxn2__C");
asm("	.sect \".econst:ti_sysbios_family_c28_Timer_Module__loggerFxn2__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_Timer_Module__loggerFxn2__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_Timer_Module__loggerFxn2__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_Timer_Module__loggerFxn2 ti_sysbios_family_c28_Timer_Module__loggerFxn2__C = ((const CT__ti_sysbios_family_c28_Timer_Module__loggerFxn2)(xdc_runtime_LoggerBuf_write2));

/* Module__loggerFxn4__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_Timer_Module__loggerFxn4__C, ".econst:ti_sysbios_family_c28_Timer_Module__loggerFxn4__C");
asm("	.sect \".econst:ti_sysbios_family_c28_Timer_Module__loggerFxn4__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_Timer_Module__loggerFxn4__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_Timer_Module__loggerFxn4__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_Timer_Module__loggerFxn4 ti_sysbios_family_c28_Timer_Module__loggerFxn4__C = ((const CT__ti_sysbios_family_c28_Timer_Module__loggerFxn4)(xdc_runtime_LoggerBuf_write4));

/* Module__loggerFxn8__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_Timer_Module__loggerFxn8__C, ".econst:ti_sysbios_family_c28_Timer_Module__loggerFxn8__C");
asm("	.sect \".econst:ti_sysbios_family_c28_Timer_Module__loggerFxn8__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_Timer_Module__loggerFxn8__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_Timer_Module__loggerFxn8__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_Timer_Module__loggerFxn8 ti_sysbios_family_c28_Timer_Module__loggerFxn8__C = ((const CT__ti_sysbios_family_c28_Timer_Module__loggerFxn8)(xdc_runtime_LoggerBuf_write8));

/* Object__count__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_Timer_Object__count__C, ".econst:ti_sysbios_family_c28_Timer_Object__count__C");
asm("	.sect \".econst:ti_sysbios_family_c28_Timer_Object__count__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_Timer_Object__count__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_Timer_Object__count__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_Timer_Object__count ti_sysbios_family_c28_Timer_Object__count__C = 1;

/* Object__heap__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_Timer_Object__heap__C, ".econst:ti_sysbios_family_c28_Timer_Object__heap__C");
asm("	.sect \".econst:ti_sysbios_family_c28_Timer_Object__heap__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_Timer_Object__heap__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_Timer_Object__heap__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_Timer_Object__heap ti_sysbios_family_c28_Timer_Object__heap__C = NULL;

/* Object__sizeof__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_Timer_Object__sizeof__C, ".econst:ti_sysbios_family_c28_Timer_Object__sizeof__C");
asm("	.sect \".econst:ti_sysbios_family_c28_Timer_Object__sizeof__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_Timer_Object__sizeof__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_Timer_Object__sizeof__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_Timer_Object__sizeof ti_sysbios_family_c28_Timer_Object__sizeof__C = sizeof(ti_sysbios_family_c28_Timer_Object__);

/* Object__table__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_Timer_Object__table__C, ".econst:ti_sysbios_family_c28_Timer_Object__table__C");
asm("	.sect \".econst:ti_sysbios_family_c28_Timer_Object__table__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_Timer_Object__table__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_Timer_Object__table__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_Timer_Object__table ti_sysbios_family_c28_Timer_Object__table__C = ti_sysbios_family_c28_Timer_Object__table__V;

/* A_invalidTimer__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_Timer_A_invalidTimer__C, ".econst:ti_sysbios_family_c28_Timer_A_invalidTimer__C");
asm("	.sect \".econst:ti_sysbios_family_c28_Timer_A_invalidTimer__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_Timer_A_invalidTimer__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_Timer_A_invalidTimer__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_Timer_A_invalidTimer ti_sysbios_family_c28_Timer_A_invalidTimer__C = (((xdc_runtime_Assert_Id)528) << 16 | 16);

/* E_notAvailable__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_Timer_E_notAvailable__C, ".econst:ti_sysbios_family_c28_Timer_E_notAvailable__C");
asm("	.sect \".econst:ti_sysbios_family_c28_Timer_E_notAvailable__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_Timer_E_notAvailable__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_Timer_E_notAvailable__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_Timer_E_notAvailable ti_sysbios_family_c28_Timer_E_notAvailable__C = (((xdc_runtime_Error_Id)3923) << 16 | 0U);

/* A_invalidRunMode__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_Timer_A_invalidRunMode__C, ".econst:ti_sysbios_family_c28_Timer_A_invalidRunMode__C");
asm("	.sect \".econst:ti_sysbios_family_c28_Timer_A_invalidRunMode__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_Timer_A_invalidRunMode__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_Timer_A_invalidRunMode__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_Timer_A_invalidRunMode ti_sysbios_family_c28_Timer_A_invalidRunMode__C = (((xdc_runtime_Assert_Id)565) << 16 | 16);

/* A_invalidHwiMask__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_Timer_A_invalidHwiMask__C, ".econst:ti_sysbios_family_c28_Timer_A_invalidHwiMask__C");
asm("	.sect \".econst:ti_sysbios_family_c28_Timer_A_invalidHwiMask__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_Timer_A_invalidHwiMask__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_Timer_A_invalidHwiMask__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_Timer_A_invalidHwiMask ti_sysbios_family_c28_Timer_A_invalidHwiMask__C = (((xdc_runtime_Assert_Id)599) << 16 | 16);

/* E_cannotSupport__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_Timer_E_cannotSupport__C, ".econst:ti_sysbios_family_c28_Timer_E_cannotSupport__C");
asm("	.sect \".econst:ti_sysbios_family_c28_Timer_E_cannotSupport__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_Timer_E_cannotSupport__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_Timer_E_cannotSupport__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_Timer_E_cannotSupport ti_sysbios_family_c28_Timer_E_cannotSupport__C = (((xdc_runtime_Assert_Id)651) << 16 | 16);

/* anyMask__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_Timer_anyMask__C, ".econst:ti_sysbios_family_c28_Timer_anyMask__C");
asm("	.sect \".econst:ti_sysbios_family_c28_Timer_anyMask__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_Timer_anyMask__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_Timer_anyMask__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_Timer_anyMask ti_sysbios_family_c28_Timer_anyMask__C = (xdc_UInt)0x7;

/* startupNeeded__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_Timer_startupNeeded__C, ".econst:ti_sysbios_family_c28_Timer_startupNeeded__C");
asm("	.sect \".econst:ti_sysbios_family_c28_Timer_startupNeeded__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_Timer_startupNeeded__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_Timer_startupNeeded__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_Timer_startupNeeded ti_sysbios_family_c28_Timer_startupNeeded__C = (xdc_UInt)0x1;

/* intNumDef__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_Timer_intNumDef__C, ".econst:ti_sysbios_family_c28_Timer_intNumDef__C");
asm("	.sect \".econst:ti_sysbios_family_c28_Timer_intNumDef__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_Timer_intNumDef__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_Timer_intNumDef__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_Timer_intNumDef ti_sysbios_family_c28_Timer_intNumDef__C = {
    (xdc_UInt8)0x26,  /* [0] */
    (xdc_UInt8)0xd,  /* [1] */
    (xdc_UInt8)0xe,  /* [2] */
};


/*
 * ======== ti.sysbios.family.c28.f2837x.TimestampProvider INITIALIZERS ========
 */

/* Module__diagsEnabled__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_f2837x_TimestampProvider_Module__diagsEnabled__C, ".econst:ti_sysbios_family_c28_f2837x_TimestampProvider_Module__diagsEnabled__C");
asm("	.sect \".econst:ti_sysbios_family_c28_f2837x_TimestampProvider_Module__diagsEnabled__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_f2837x_TimestampProvider_Module__diagsEnabled__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_f2837x_TimestampProvider_Module__diagsEnabled__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_f2837x_TimestampProvider_Module__diagsEnabled ti_sysbios_family_c28_f2837x_TimestampProvider_Module__diagsEnabled__C = (xdc_Bits32)0x10;

/* Module__diagsIncluded__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_f2837x_TimestampProvider_Module__diagsIncluded__C, ".econst:ti_sysbios_family_c28_f2837x_TimestampProvider_Module__diagsIncluded__C");
asm("	.sect \".econst:ti_sysbios_family_c28_f2837x_TimestampProvider_Module__diagsIncluded__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_f2837x_TimestampProvider_Module__diagsIncluded__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_f2837x_TimestampProvider_Module__diagsIncluded__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_f2837x_TimestampProvider_Module__diagsIncluded ti_sysbios_family_c28_f2837x_TimestampProvider_Module__diagsIncluded__C = (xdc_Bits32)0x10;

/* Module__diagsMask__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_f2837x_TimestampProvider_Module__diagsMask__C, ".econst:ti_sysbios_family_c28_f2837x_TimestampProvider_Module__diagsMask__C");
asm("	.sect \".econst:ti_sysbios_family_c28_f2837x_TimestampProvider_Module__diagsMask__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_f2837x_TimestampProvider_Module__diagsMask__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_f2837x_TimestampProvider_Module__diagsMask__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_f2837x_TimestampProvider_Module__diagsMask ti_sysbios_family_c28_f2837x_TimestampProvider_Module__diagsMask__C = ((const CT__ti_sysbios_family_c28_f2837x_TimestampProvider_Module__diagsMask)NULL);

/* Module__gateObj__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_f2837x_TimestampProvider_Module__gateObj__C, ".econst:ti_sysbios_family_c28_f2837x_TimestampProvider_Module__gateObj__C");
asm("	.sect \".econst:ti_sysbios_family_c28_f2837x_TimestampProvider_Module__gateObj__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_f2837x_TimestampProvider_Module__gateObj__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_f2837x_TimestampProvider_Module__gateObj__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_f2837x_TimestampProvider_Module__gateObj ti_sysbios_family_c28_f2837x_TimestampProvider_Module__gateObj__C = ((const CT__ti_sysbios_family_c28_f2837x_TimestampProvider_Module__gateObj)NULL);

/* Module__gatePrms__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_f2837x_TimestampProvider_Module__gatePrms__C, ".econst:ti_sysbios_family_c28_f2837x_TimestampProvider_Module__gatePrms__C");
asm("	.sect \".econst:ti_sysbios_family_c28_f2837x_TimestampProvider_Module__gatePrms__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_f2837x_TimestampProvider_Module__gatePrms__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_f2837x_TimestampProvider_Module__gatePrms__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_f2837x_TimestampProvider_Module__gatePrms ti_sysbios_family_c28_f2837x_TimestampProvider_Module__gatePrms__C = ((const CT__ti_sysbios_family_c28_f2837x_TimestampProvider_Module__gatePrms)NULL);

/* Module__id__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_f2837x_TimestampProvider_Module__id__C, ".econst:ti_sysbios_family_c28_f2837x_TimestampProvider_Module__id__C");
asm("	.sect \".econst:ti_sysbios_family_c28_f2837x_TimestampProvider_Module__id__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_f2837x_TimestampProvider_Module__id__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_f2837x_TimestampProvider_Module__id__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_f2837x_TimestampProvider_Module__id ti_sysbios_family_c28_f2837x_TimestampProvider_Module__id__C = (xdc_Bits16)0x802a;

/* Module__loggerDefined__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_f2837x_TimestampProvider_Module__loggerDefined__C, ".econst:ti_sysbios_family_c28_f2837x_TimestampProvider_Module__loggerDefined__C");
asm("	.sect \".econst:ti_sysbios_family_c28_f2837x_TimestampProvider_Module__loggerDefined__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_f2837x_TimestampProvider_Module__loggerDefined__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_f2837x_TimestampProvider_Module__loggerDefined__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_f2837x_TimestampProvider_Module__loggerDefined ti_sysbios_family_c28_f2837x_TimestampProvider_Module__loggerDefined__C = 1;

/* Module__loggerObj__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_f2837x_TimestampProvider_Module__loggerObj__C, ".econst:ti_sysbios_family_c28_f2837x_TimestampProvider_Module__loggerObj__C");
asm("	.sect \".econst:ti_sysbios_family_c28_f2837x_TimestampProvider_Module__loggerObj__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_f2837x_TimestampProvider_Module__loggerObj__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_f2837x_TimestampProvider_Module__loggerObj__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_f2837x_TimestampProvider_Module__loggerObj ti_sysbios_family_c28_f2837x_TimestampProvider_Module__loggerObj__C = ((const CT__ti_sysbios_family_c28_f2837x_TimestampProvider_Module__loggerObj)((void*)(xdc_runtime_ILogger_Handle)&xdc_runtime_LoggerBuf_Object__table__V[0]));

/* Module__loggerFxn0__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_f2837x_TimestampProvider_Module__loggerFxn0__C, ".econst:ti_sysbios_family_c28_f2837x_TimestampProvider_Module__loggerFxn0__C");
asm("	.sect \".econst:ti_sysbios_family_c28_f2837x_TimestampProvider_Module__loggerFxn0__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_f2837x_TimestampProvider_Module__loggerFxn0__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_f2837x_TimestampProvider_Module__loggerFxn0__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_f2837x_TimestampProvider_Module__loggerFxn0 ti_sysbios_family_c28_f2837x_TimestampProvider_Module__loggerFxn0__C = ((const CT__ti_sysbios_family_c28_f2837x_TimestampProvider_Module__loggerFxn0)(xdc_runtime_LoggerBuf_write0));

/* Module__loggerFxn1__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_f2837x_TimestampProvider_Module__loggerFxn1__C, ".econst:ti_sysbios_family_c28_f2837x_TimestampProvider_Module__loggerFxn1__C");
asm("	.sect \".econst:ti_sysbios_family_c28_f2837x_TimestampProvider_Module__loggerFxn1__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_f2837x_TimestampProvider_Module__loggerFxn1__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_f2837x_TimestampProvider_Module__loggerFxn1__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_f2837x_TimestampProvider_Module__loggerFxn1 ti_sysbios_family_c28_f2837x_TimestampProvider_Module__loggerFxn1__C = ((const CT__ti_sysbios_family_c28_f2837x_TimestampProvider_Module__loggerFxn1)(xdc_runtime_LoggerBuf_write1));

/* Module__loggerFxn2__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_f2837x_TimestampProvider_Module__loggerFxn2__C, ".econst:ti_sysbios_family_c28_f2837x_TimestampProvider_Module__loggerFxn2__C");
asm("	.sect \".econst:ti_sysbios_family_c28_f2837x_TimestampProvider_Module__loggerFxn2__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_f2837x_TimestampProvider_Module__loggerFxn2__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_f2837x_TimestampProvider_Module__loggerFxn2__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_f2837x_TimestampProvider_Module__loggerFxn2 ti_sysbios_family_c28_f2837x_TimestampProvider_Module__loggerFxn2__C = ((const CT__ti_sysbios_family_c28_f2837x_TimestampProvider_Module__loggerFxn2)(xdc_runtime_LoggerBuf_write2));

/* Module__loggerFxn4__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_f2837x_TimestampProvider_Module__loggerFxn4__C, ".econst:ti_sysbios_family_c28_f2837x_TimestampProvider_Module__loggerFxn4__C");
asm("	.sect \".econst:ti_sysbios_family_c28_f2837x_TimestampProvider_Module__loggerFxn4__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_f2837x_TimestampProvider_Module__loggerFxn4__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_f2837x_TimestampProvider_Module__loggerFxn4__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_f2837x_TimestampProvider_Module__loggerFxn4 ti_sysbios_family_c28_f2837x_TimestampProvider_Module__loggerFxn4__C = ((const CT__ti_sysbios_family_c28_f2837x_TimestampProvider_Module__loggerFxn4)(xdc_runtime_LoggerBuf_write4));

/* Module__loggerFxn8__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_f2837x_TimestampProvider_Module__loggerFxn8__C, ".econst:ti_sysbios_family_c28_f2837x_TimestampProvider_Module__loggerFxn8__C");
asm("	.sect \".econst:ti_sysbios_family_c28_f2837x_TimestampProvider_Module__loggerFxn8__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_f2837x_TimestampProvider_Module__loggerFxn8__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_f2837x_TimestampProvider_Module__loggerFxn8__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_f2837x_TimestampProvider_Module__loggerFxn8 ti_sysbios_family_c28_f2837x_TimestampProvider_Module__loggerFxn8__C = ((const CT__ti_sysbios_family_c28_f2837x_TimestampProvider_Module__loggerFxn8)(xdc_runtime_LoggerBuf_write8));

/* Object__count__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_f2837x_TimestampProvider_Object__count__C, ".econst:ti_sysbios_family_c28_f2837x_TimestampProvider_Object__count__C");
asm("	.sect \".econst:ti_sysbios_family_c28_f2837x_TimestampProvider_Object__count__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_f2837x_TimestampProvider_Object__count__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_f2837x_TimestampProvider_Object__count__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_f2837x_TimestampProvider_Object__count ti_sysbios_family_c28_f2837x_TimestampProvider_Object__count__C = 0;

/* Object__heap__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_f2837x_TimestampProvider_Object__heap__C, ".econst:ti_sysbios_family_c28_f2837x_TimestampProvider_Object__heap__C");
asm("	.sect \".econst:ti_sysbios_family_c28_f2837x_TimestampProvider_Object__heap__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_f2837x_TimestampProvider_Object__heap__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_f2837x_TimestampProvider_Object__heap__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_f2837x_TimestampProvider_Object__heap ti_sysbios_family_c28_f2837x_TimestampProvider_Object__heap__C = NULL;

/* Object__sizeof__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_f2837x_TimestampProvider_Object__sizeof__C, ".econst:ti_sysbios_family_c28_f2837x_TimestampProvider_Object__sizeof__C");
asm("	.sect \".econst:ti_sysbios_family_c28_f2837x_TimestampProvider_Object__sizeof__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_f2837x_TimestampProvider_Object__sizeof__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_f2837x_TimestampProvider_Object__sizeof__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_f2837x_TimestampProvider_Object__sizeof ti_sysbios_family_c28_f2837x_TimestampProvider_Object__sizeof__C = 0;

/* Object__table__C */
#pragma DATA_SECTION(ti_sysbios_family_c28_f2837x_TimestampProvider_Object__table__C, ".econst:ti_sysbios_family_c28_f2837x_TimestampProvider_Object__table__C");
asm("	.sect \".econst:ti_sysbios_family_c28_f2837x_TimestampProvider_Object__table__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_f2837x_TimestampProvider_Object__table__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_f2837x_TimestampProvider_Object__table__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_family_c28_f2837x_TimestampProvider_Object__table ti_sysbios_family_c28_f2837x_TimestampProvider_Object__table__C = NULL;


/*
 * ======== ti.sysbios.gates.GateHwi INITIALIZERS ========
 */

/* Object__DESC__C */
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_gates_GateHwi_Object__DESC__C;

/* Object__PARAMS__C */
#pragma DATA_SECTION(ti_sysbios_gates_GateHwi_Object__PARAMS__C, ".econst:ti_sysbios_gates_GateHwi_Object__PARAMS__C");
asm("	.sect \".econst:ti_sysbios_gates_GateHwi_Object__PARAMS__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_gates_GateHwi_Object__PARAMS__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_gates_GateHwi_Object__PARAMS__C\"");
asm("	.clink ");

__FAR__ const ti_sysbios_gates_GateHwi_Params ti_sysbios_gates_GateHwi_Object__PARAMS__C = {
    sizeof (ti_sysbios_gates_GateHwi_Params), /* __size */
    NULL, /* __self */
    NULL, /* __fxns */
    (xdc_runtime_IInstance_Params*)&ti_sysbios_gates_GateHwi_Object__PARAMS__C.__iprms, /* instance */
    {
        sizeof (xdc_runtime_IInstance_Params), /* __size */
        0,  /* name */
    },  /* instance */
};

/* Module__root__V */
ti_sysbios_gates_GateHwi_Module__ ti_sysbios_gates_GateHwi_Module__root__V = {
    {&ti_sysbios_gates_GateHwi_Module__root__V.link,  /* link.next */
    &ti_sysbios_gates_GateHwi_Module__root__V.link},  /* link.prev */
};

/* Object__table__V */
ti_sysbios_gates_GateHwi_Object__ ti_sysbios_gates_GateHwi_Object__table__V[1] = {
    {/* instance#0 */
        &ti_sysbios_gates_GateHwi_Module__FXNS__C,
    },
};

/* Module__diagsEnabled__C */
#pragma DATA_SECTION(ti_sysbios_gates_GateHwi_Module__diagsEnabled__C, ".econst:ti_sysbios_gates_GateHwi_Module__diagsEnabled__C");
asm("	.sect \".econst:ti_sysbios_gates_GateHwi_Module__diagsEnabled__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_gates_GateHwi_Module__diagsEnabled__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_gates_GateHwi_Module__diagsEnabled__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_gates_GateHwi_Module__diagsEnabled ti_sysbios_gates_GateHwi_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
#pragma DATA_SECTION(ti_sysbios_gates_GateHwi_Module__diagsIncluded__C, ".econst:ti_sysbios_gates_GateHwi_Module__diagsIncluded__C");
asm("	.sect \".econst:ti_sysbios_gates_GateHwi_Module__diagsIncluded__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_gates_GateHwi_Module__diagsIncluded__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_gates_GateHwi_Module__diagsIncluded__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_gates_GateHwi_Module__diagsIncluded ti_sysbios_gates_GateHwi_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
#pragma DATA_SECTION(ti_sysbios_gates_GateHwi_Module__diagsMask__C, ".econst:ti_sysbios_gates_GateHwi_Module__diagsMask__C");
asm("	.sect \".econst:ti_sysbios_gates_GateHwi_Module__diagsMask__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_gates_GateHwi_Module__diagsMask__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_gates_GateHwi_Module__diagsMask__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_gates_GateHwi_Module__diagsMask ti_sysbios_gates_GateHwi_Module__diagsMask__C = ((const CT__ti_sysbios_gates_GateHwi_Module__diagsMask)NULL);

/* Module__gateObj__C */
#pragma DATA_SECTION(ti_sysbios_gates_GateHwi_Module__gateObj__C, ".econst:ti_sysbios_gates_GateHwi_Module__gateObj__C");
asm("	.sect \".econst:ti_sysbios_gates_GateHwi_Module__gateObj__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_gates_GateHwi_Module__gateObj__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_gates_GateHwi_Module__gateObj__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_gates_GateHwi_Module__gateObj ti_sysbios_gates_GateHwi_Module__gateObj__C = ((const CT__ti_sysbios_gates_GateHwi_Module__gateObj)NULL);

/* Module__gatePrms__C */
#pragma DATA_SECTION(ti_sysbios_gates_GateHwi_Module__gatePrms__C, ".econst:ti_sysbios_gates_GateHwi_Module__gatePrms__C");
asm("	.sect \".econst:ti_sysbios_gates_GateHwi_Module__gatePrms__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_gates_GateHwi_Module__gatePrms__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_gates_GateHwi_Module__gatePrms__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_gates_GateHwi_Module__gatePrms ti_sysbios_gates_GateHwi_Module__gatePrms__C = ((const CT__ti_sysbios_gates_GateHwi_Module__gatePrms)NULL);

/* Module__id__C */
#pragma DATA_SECTION(ti_sysbios_gates_GateHwi_Module__id__C, ".econst:ti_sysbios_gates_GateHwi_Module__id__C");
asm("	.sect \".econst:ti_sysbios_gates_GateHwi_Module__id__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_gates_GateHwi_Module__id__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_gates_GateHwi_Module__id__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_gates_GateHwi_Module__id ti_sysbios_gates_GateHwi_Module__id__C = (xdc_Bits16)0x8023;

/* Module__loggerDefined__C */
#pragma DATA_SECTION(ti_sysbios_gates_GateHwi_Module__loggerDefined__C, ".econst:ti_sysbios_gates_GateHwi_Module__loggerDefined__C");
asm("	.sect \".econst:ti_sysbios_gates_GateHwi_Module__loggerDefined__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_gates_GateHwi_Module__loggerDefined__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_gates_GateHwi_Module__loggerDefined__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_gates_GateHwi_Module__loggerDefined ti_sysbios_gates_GateHwi_Module__loggerDefined__C = 1;

/* Module__loggerObj__C */
#pragma DATA_SECTION(ti_sysbios_gates_GateHwi_Module__loggerObj__C, ".econst:ti_sysbios_gates_GateHwi_Module__loggerObj__C");
asm("	.sect \".econst:ti_sysbios_gates_GateHwi_Module__loggerObj__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_gates_GateHwi_Module__loggerObj__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_gates_GateHwi_Module__loggerObj__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_gates_GateHwi_Module__loggerObj ti_sysbios_gates_GateHwi_Module__loggerObj__C = ((const CT__ti_sysbios_gates_GateHwi_Module__loggerObj)((void*)(xdc_runtime_ILogger_Handle)&xdc_runtime_LoggerBuf_Object__table__V[0]));

/* Module__loggerFxn0__C */
#pragma DATA_SECTION(ti_sysbios_gates_GateHwi_Module__loggerFxn0__C, ".econst:ti_sysbios_gates_GateHwi_Module__loggerFxn0__C");
asm("	.sect \".econst:ti_sysbios_gates_GateHwi_Module__loggerFxn0__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_gates_GateHwi_Module__loggerFxn0__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_gates_GateHwi_Module__loggerFxn0__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_gates_GateHwi_Module__loggerFxn0 ti_sysbios_gates_GateHwi_Module__loggerFxn0__C = ((const CT__ti_sysbios_gates_GateHwi_Module__loggerFxn0)(xdc_runtime_LoggerBuf_write0));

/* Module__loggerFxn1__C */
#pragma DATA_SECTION(ti_sysbios_gates_GateHwi_Module__loggerFxn1__C, ".econst:ti_sysbios_gates_GateHwi_Module__loggerFxn1__C");
asm("	.sect \".econst:ti_sysbios_gates_GateHwi_Module__loggerFxn1__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_gates_GateHwi_Module__loggerFxn1__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_gates_GateHwi_Module__loggerFxn1__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_gates_GateHwi_Module__loggerFxn1 ti_sysbios_gates_GateHwi_Module__loggerFxn1__C = ((const CT__ti_sysbios_gates_GateHwi_Module__loggerFxn1)(xdc_runtime_LoggerBuf_write1));

/* Module__loggerFxn2__C */
#pragma DATA_SECTION(ti_sysbios_gates_GateHwi_Module__loggerFxn2__C, ".econst:ti_sysbios_gates_GateHwi_Module__loggerFxn2__C");
asm("	.sect \".econst:ti_sysbios_gates_GateHwi_Module__loggerFxn2__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_gates_GateHwi_Module__loggerFxn2__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_gates_GateHwi_Module__loggerFxn2__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_gates_GateHwi_Module__loggerFxn2 ti_sysbios_gates_GateHwi_Module__loggerFxn2__C = ((const CT__ti_sysbios_gates_GateHwi_Module__loggerFxn2)(xdc_runtime_LoggerBuf_write2));

/* Module__loggerFxn4__C */
#pragma DATA_SECTION(ti_sysbios_gates_GateHwi_Module__loggerFxn4__C, ".econst:ti_sysbios_gates_GateHwi_Module__loggerFxn4__C");
asm("	.sect \".econst:ti_sysbios_gates_GateHwi_Module__loggerFxn4__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_gates_GateHwi_Module__loggerFxn4__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_gates_GateHwi_Module__loggerFxn4__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_gates_GateHwi_Module__loggerFxn4 ti_sysbios_gates_GateHwi_Module__loggerFxn4__C = ((const CT__ti_sysbios_gates_GateHwi_Module__loggerFxn4)(xdc_runtime_LoggerBuf_write4));

/* Module__loggerFxn8__C */
#pragma DATA_SECTION(ti_sysbios_gates_GateHwi_Module__loggerFxn8__C, ".econst:ti_sysbios_gates_GateHwi_Module__loggerFxn8__C");
asm("	.sect \".econst:ti_sysbios_gates_GateHwi_Module__loggerFxn8__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_gates_GateHwi_Module__loggerFxn8__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_gates_GateHwi_Module__loggerFxn8__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_gates_GateHwi_Module__loggerFxn8 ti_sysbios_gates_GateHwi_Module__loggerFxn8__C = ((const CT__ti_sysbios_gates_GateHwi_Module__loggerFxn8)(xdc_runtime_LoggerBuf_write8));

/* Object__count__C */
#pragma DATA_SECTION(ti_sysbios_gates_GateHwi_Object__count__C, ".econst:ti_sysbios_gates_GateHwi_Object__count__C");
asm("	.sect \".econst:ti_sysbios_gates_GateHwi_Object__count__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_gates_GateHwi_Object__count__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_gates_GateHwi_Object__count__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_gates_GateHwi_Object__count ti_sysbios_gates_GateHwi_Object__count__C = 1;

/* Object__heap__C */
#pragma DATA_SECTION(ti_sysbios_gates_GateHwi_Object__heap__C, ".econst:ti_sysbios_gates_GateHwi_Object__heap__C");
asm("	.sect \".econst:ti_sysbios_gates_GateHwi_Object__heap__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_gates_GateHwi_Object__heap__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_gates_GateHwi_Object__heap__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_gates_GateHwi_Object__heap ti_sysbios_gates_GateHwi_Object__heap__C = NULL;

/* Object__sizeof__C */
#pragma DATA_SECTION(ti_sysbios_gates_GateHwi_Object__sizeof__C, ".econst:ti_sysbios_gates_GateHwi_Object__sizeof__C");
asm("	.sect \".econst:ti_sysbios_gates_GateHwi_Object__sizeof__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_gates_GateHwi_Object__sizeof__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_gates_GateHwi_Object__sizeof__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_gates_GateHwi_Object__sizeof ti_sysbios_gates_GateHwi_Object__sizeof__C = sizeof(ti_sysbios_gates_GateHwi_Object__);

/* Object__table__C */
#pragma DATA_SECTION(ti_sysbios_gates_GateHwi_Object__table__C, ".econst:ti_sysbios_gates_GateHwi_Object__table__C");
asm("	.sect \".econst:ti_sysbios_gates_GateHwi_Object__table__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_gates_GateHwi_Object__table__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_gates_GateHwi_Object__table__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_gates_GateHwi_Object__table ti_sysbios_gates_GateHwi_Object__table__C = ti_sysbios_gates_GateHwi_Object__table__V;


/*
 * ======== ti.sysbios.gates.GateMutex INITIALIZERS ========
 */

/* Object__DESC__C */
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_gates_GateMutex_Object__DESC__C;

/* Object__PARAMS__C */
#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_Object__PARAMS__C, ".econst:ti_sysbios_gates_GateMutex_Object__PARAMS__C");
asm("	.sect \".econst:ti_sysbios_gates_GateMutex_Object__PARAMS__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_gates_GateMutex_Object__PARAMS__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_gates_GateMutex_Object__PARAMS__C\"");
asm("	.clink ");

__FAR__ const ti_sysbios_gates_GateMutex_Params ti_sysbios_gates_GateMutex_Object__PARAMS__C = {
    sizeof (ti_sysbios_gates_GateMutex_Params), /* __size */
    NULL, /* __self */
    NULL, /* __fxns */
    (xdc_runtime_IInstance_Params*)&ti_sysbios_gates_GateMutex_Object__PARAMS__C.__iprms, /* instance */
    {
        sizeof (xdc_runtime_IInstance_Params), /* __size */
        0,  /* name */
    },  /* instance */
};

/* Module__root__V */
ti_sysbios_gates_GateMutex_Module__ ti_sysbios_gates_GateMutex_Module__root__V = {
    {&ti_sysbios_gates_GateMutex_Module__root__V.link,  /* link.next */
    &ti_sysbios_gates_GateMutex_Module__root__V.link},  /* link.prev */
};

/* Object__table__V */
ti_sysbios_gates_GateMutex_Object__ ti_sysbios_gates_GateMutex_Object__table__V[2] = {
    {/* instance#0 */
        &ti_sysbios_gates_GateMutex_Module__FXNS__C,
        0,  /* owner */
        {
            0,  /* event */
            (xdc_UInt)0x1,  /* eventId */
            ti_sysbios_knl_Semaphore_Mode_COUNTING,  /* mode */
            (xdc_UInt16)0x1,  /* count */
            {
                {
                    ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_gates_GateMutex_Object__table__V[0].Object_field_sem.Object_field_pendQ.elem)),  /* next */
                    ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_gates_GateMutex_Object__table__V[0].Object_field_sem.Object_field_pendQ.elem)),  /* prev */
                },  /* elem */
            },  /* Object_field_pendQ */
        },  /* Object_field_sem */
    },
    {/* instance#1 */
        &ti_sysbios_gates_GateMutex_Module__FXNS__C,
        0,  /* owner */
        {
            0,  /* event */
            (xdc_UInt)0x1,  /* eventId */
            ti_sysbios_knl_Semaphore_Mode_COUNTING,  /* mode */
            (xdc_UInt16)0x1,  /* count */
            {
                {
                    ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_gates_GateMutex_Object__table__V[1].Object_field_sem.Object_field_pendQ.elem)),  /* next */
                    ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_gates_GateMutex_Object__table__V[1].Object_field_sem.Object_field_pendQ.elem)),  /* prev */
                },  /* elem */
            },  /* Object_field_pendQ */
        },  /* Object_field_sem */
    },
};

/* Module__diagsEnabled__C */
#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_Module__diagsEnabled__C, ".econst:ti_sysbios_gates_GateMutex_Module__diagsEnabled__C");
asm("	.sect \".econst:ti_sysbios_gates_GateMutex_Module__diagsEnabled__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_gates_GateMutex_Module__diagsEnabled__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_gates_GateMutex_Module__diagsEnabled__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_gates_GateMutex_Module__diagsEnabled ti_sysbios_gates_GateMutex_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_Module__diagsIncluded__C, ".econst:ti_sysbios_gates_GateMutex_Module__diagsIncluded__C");
asm("	.sect \".econst:ti_sysbios_gates_GateMutex_Module__diagsIncluded__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_gates_GateMutex_Module__diagsIncluded__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_gates_GateMutex_Module__diagsIncluded__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_gates_GateMutex_Module__diagsIncluded ti_sysbios_gates_GateMutex_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_Module__diagsMask__C, ".econst:ti_sysbios_gates_GateMutex_Module__diagsMask__C");
asm("	.sect \".econst:ti_sysbios_gates_GateMutex_Module__diagsMask__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_gates_GateMutex_Module__diagsMask__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_gates_GateMutex_Module__diagsMask__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_gates_GateMutex_Module__diagsMask ti_sysbios_gates_GateMutex_Module__diagsMask__C = ((const CT__ti_sysbios_gates_GateMutex_Module__diagsMask)NULL);

/* Module__gateObj__C */
#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_Module__gateObj__C, ".econst:ti_sysbios_gates_GateMutex_Module__gateObj__C");
asm("	.sect \".econst:ti_sysbios_gates_GateMutex_Module__gateObj__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_gates_GateMutex_Module__gateObj__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_gates_GateMutex_Module__gateObj__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_gates_GateMutex_Module__gateObj ti_sysbios_gates_GateMutex_Module__gateObj__C = ((const CT__ti_sysbios_gates_GateMutex_Module__gateObj)NULL);

/* Module__gatePrms__C */
#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_Module__gatePrms__C, ".econst:ti_sysbios_gates_GateMutex_Module__gatePrms__C");
asm("	.sect \".econst:ti_sysbios_gates_GateMutex_Module__gatePrms__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_gates_GateMutex_Module__gatePrms__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_gates_GateMutex_Module__gatePrms__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_gates_GateMutex_Module__gatePrms ti_sysbios_gates_GateMutex_Module__gatePrms__C = ((const CT__ti_sysbios_gates_GateMutex_Module__gatePrms)NULL);

/* Module__id__C */
#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_Module__id__C, ".econst:ti_sysbios_gates_GateMutex_Module__id__C");
asm("	.sect \".econst:ti_sysbios_gates_GateMutex_Module__id__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_gates_GateMutex_Module__id__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_gates_GateMutex_Module__id__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_gates_GateMutex_Module__id ti_sysbios_gates_GateMutex_Module__id__C = (xdc_Bits16)0x8024;

/* Module__loggerDefined__C */
#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_Module__loggerDefined__C, ".econst:ti_sysbios_gates_GateMutex_Module__loggerDefined__C");
asm("	.sect \".econst:ti_sysbios_gates_GateMutex_Module__loggerDefined__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_gates_GateMutex_Module__loggerDefined__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_gates_GateMutex_Module__loggerDefined__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_gates_GateMutex_Module__loggerDefined ti_sysbios_gates_GateMutex_Module__loggerDefined__C = 1;

/* Module__loggerObj__C */
#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_Module__loggerObj__C, ".econst:ti_sysbios_gates_GateMutex_Module__loggerObj__C");
asm("	.sect \".econst:ti_sysbios_gates_GateMutex_Module__loggerObj__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_gates_GateMutex_Module__loggerObj__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_gates_GateMutex_Module__loggerObj__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_gates_GateMutex_Module__loggerObj ti_sysbios_gates_GateMutex_Module__loggerObj__C = ((const CT__ti_sysbios_gates_GateMutex_Module__loggerObj)((void*)(xdc_runtime_ILogger_Handle)&xdc_runtime_LoggerBuf_Object__table__V[0]));

/* Module__loggerFxn0__C */
#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_Module__loggerFxn0__C, ".econst:ti_sysbios_gates_GateMutex_Module__loggerFxn0__C");
asm("	.sect \".econst:ti_sysbios_gates_GateMutex_Module__loggerFxn0__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_gates_GateMutex_Module__loggerFxn0__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_gates_GateMutex_Module__loggerFxn0__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_gates_GateMutex_Module__loggerFxn0 ti_sysbios_gates_GateMutex_Module__loggerFxn0__C = ((const CT__ti_sysbios_gates_GateMutex_Module__loggerFxn0)(xdc_runtime_LoggerBuf_write0));

/* Module__loggerFxn1__C */
#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_Module__loggerFxn1__C, ".econst:ti_sysbios_gates_GateMutex_Module__loggerFxn1__C");
asm("	.sect \".econst:ti_sysbios_gates_GateMutex_Module__loggerFxn1__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_gates_GateMutex_Module__loggerFxn1__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_gates_GateMutex_Module__loggerFxn1__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_gates_GateMutex_Module__loggerFxn1 ti_sysbios_gates_GateMutex_Module__loggerFxn1__C = ((const CT__ti_sysbios_gates_GateMutex_Module__loggerFxn1)(xdc_runtime_LoggerBuf_write1));

/* Module__loggerFxn2__C */
#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_Module__loggerFxn2__C, ".econst:ti_sysbios_gates_GateMutex_Module__loggerFxn2__C");
asm("	.sect \".econst:ti_sysbios_gates_GateMutex_Module__loggerFxn2__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_gates_GateMutex_Module__loggerFxn2__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_gates_GateMutex_Module__loggerFxn2__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_gates_GateMutex_Module__loggerFxn2 ti_sysbios_gates_GateMutex_Module__loggerFxn2__C = ((const CT__ti_sysbios_gates_GateMutex_Module__loggerFxn2)(xdc_runtime_LoggerBuf_write2));

/* Module__loggerFxn4__C */
#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_Module__loggerFxn4__C, ".econst:ti_sysbios_gates_GateMutex_Module__loggerFxn4__C");
asm("	.sect \".econst:ti_sysbios_gates_GateMutex_Module__loggerFxn4__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_gates_GateMutex_Module__loggerFxn4__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_gates_GateMutex_Module__loggerFxn4__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_gates_GateMutex_Module__loggerFxn4 ti_sysbios_gates_GateMutex_Module__loggerFxn4__C = ((const CT__ti_sysbios_gates_GateMutex_Module__loggerFxn4)(xdc_runtime_LoggerBuf_write4));

/* Module__loggerFxn8__C */
#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_Module__loggerFxn8__C, ".econst:ti_sysbios_gates_GateMutex_Module__loggerFxn8__C");
asm("	.sect \".econst:ti_sysbios_gates_GateMutex_Module__loggerFxn8__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_gates_GateMutex_Module__loggerFxn8__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_gates_GateMutex_Module__loggerFxn8__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_gates_GateMutex_Module__loggerFxn8 ti_sysbios_gates_GateMutex_Module__loggerFxn8__C = ((const CT__ti_sysbios_gates_GateMutex_Module__loggerFxn8)(xdc_runtime_LoggerBuf_write8));

/* Object__count__C */
#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_Object__count__C, ".econst:ti_sysbios_gates_GateMutex_Object__count__C");
asm("	.sect \".econst:ti_sysbios_gates_GateMutex_Object__count__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_gates_GateMutex_Object__count__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_gates_GateMutex_Object__count__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_gates_GateMutex_Object__count ti_sysbios_gates_GateMutex_Object__count__C = 2;

/* Object__heap__C */
#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_Object__heap__C, ".econst:ti_sysbios_gates_GateMutex_Object__heap__C");
asm("	.sect \".econst:ti_sysbios_gates_GateMutex_Object__heap__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_gates_GateMutex_Object__heap__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_gates_GateMutex_Object__heap__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_gates_GateMutex_Object__heap ti_sysbios_gates_GateMutex_Object__heap__C = NULL;

/* Object__sizeof__C */
#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_Object__sizeof__C, ".econst:ti_sysbios_gates_GateMutex_Object__sizeof__C");
asm("	.sect \".econst:ti_sysbios_gates_GateMutex_Object__sizeof__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_gates_GateMutex_Object__sizeof__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_gates_GateMutex_Object__sizeof__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_gates_GateMutex_Object__sizeof ti_sysbios_gates_GateMutex_Object__sizeof__C = sizeof(ti_sysbios_gates_GateMutex_Object__);

/* Object__table__C */
#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_Object__table__C, ".econst:ti_sysbios_gates_GateMutex_Object__table__C");
asm("	.sect \".econst:ti_sysbios_gates_GateMutex_Object__table__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_gates_GateMutex_Object__table__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_gates_GateMutex_Object__table__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_gates_GateMutex_Object__table ti_sysbios_gates_GateMutex_Object__table__C = ti_sysbios_gates_GateMutex_Object__table__V;

/* A_badContext__C */
#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_A_badContext__C, ".econst:ti_sysbios_gates_GateMutex_A_badContext__C");
asm("	.sect \".econst:ti_sysbios_gates_GateMutex_A_badContext__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_gates_GateMutex_A_badContext__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_gates_GateMutex_A_badContext__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_gates_GateMutex_A_badContext ti_sysbios_gates_GateMutex_A_badContext__C = (((xdc_runtime_Assert_Id)2546) << 16 | 16);


/*
 * ======== ti.sysbios.hal.Hwi INITIALIZERS ========
 */

/* Object__DESC__C */
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_hal_Hwi_Object__DESC__C;

/* Object__PARAMS__C */
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_Object__PARAMS__C, ".econst:ti_sysbios_hal_Hwi_Object__PARAMS__C");
asm("	.sect \".econst:ti_sysbios_hal_Hwi_Object__PARAMS__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_hal_Hwi_Object__PARAMS__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_hal_Hwi_Object__PARAMS__C\"");
asm("	.clink ");

__FAR__ const ti_sysbios_hal_Hwi_Params ti_sysbios_hal_Hwi_Object__PARAMS__C = {
    sizeof (ti_sysbios_hal_Hwi_Params), /* __size */
    NULL, /* __self */
    NULL, /* __fxns */
    (xdc_runtime_IInstance_Params*)&ti_sysbios_hal_Hwi_Object__PARAMS__C.__iprms, /* instance */
    ti_sysbios_interfaces_IHwi_MaskingOption_SELF,  /* maskSetting */
    ((xdc_UArg)(0x0)),  /* arg */
    1,  /* enableInt */
    (xdc_Int)(-0x0 - 1),  /* eventId */
    (xdc_Int)(-0x0 - 1),  /* priority */
    {
        sizeof (xdc_runtime_IInstance_Params), /* __size */
        0,  /* name */
    },  /* instance */
};

/* Module__root__V */
ti_sysbios_hal_Hwi_Module__ ti_sysbios_hal_Hwi_Module__root__V = {
    {&ti_sysbios_hal_Hwi_Module__root__V.link,  /* link.next */
    &ti_sysbios_hal_Hwi_Module__root__V.link},  /* link.prev */
};

/* Module__diagsEnabled__C */
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_Module__diagsEnabled__C, ".econst:ti_sysbios_hal_Hwi_Module__diagsEnabled__C");
asm("	.sect \".econst:ti_sysbios_hal_Hwi_Module__diagsEnabled__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_hal_Hwi_Module__diagsEnabled__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_hal_Hwi_Module__diagsEnabled__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_hal_Hwi_Module__diagsEnabled ti_sysbios_hal_Hwi_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_Module__diagsIncluded__C, ".econst:ti_sysbios_hal_Hwi_Module__diagsIncluded__C");
asm("	.sect \".econst:ti_sysbios_hal_Hwi_Module__diagsIncluded__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_hal_Hwi_Module__diagsIncluded__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_hal_Hwi_Module__diagsIncluded__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_hal_Hwi_Module__diagsIncluded ti_sysbios_hal_Hwi_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_Module__diagsMask__C, ".econst:ti_sysbios_hal_Hwi_Module__diagsMask__C");
asm("	.sect \".econst:ti_sysbios_hal_Hwi_Module__diagsMask__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_hal_Hwi_Module__diagsMask__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_hal_Hwi_Module__diagsMask__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_hal_Hwi_Module__diagsMask ti_sysbios_hal_Hwi_Module__diagsMask__C = ((const CT__ti_sysbios_hal_Hwi_Module__diagsMask)NULL);

/* Module__gateObj__C */
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_Module__gateObj__C, ".econst:ti_sysbios_hal_Hwi_Module__gateObj__C");
asm("	.sect \".econst:ti_sysbios_hal_Hwi_Module__gateObj__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_hal_Hwi_Module__gateObj__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_hal_Hwi_Module__gateObj__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_hal_Hwi_Module__gateObj ti_sysbios_hal_Hwi_Module__gateObj__C = ((const CT__ti_sysbios_hal_Hwi_Module__gateObj)NULL);

/* Module__gatePrms__C */
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_Module__gatePrms__C, ".econst:ti_sysbios_hal_Hwi_Module__gatePrms__C");
asm("	.sect \".econst:ti_sysbios_hal_Hwi_Module__gatePrms__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_hal_Hwi_Module__gatePrms__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_hal_Hwi_Module__gatePrms__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_hal_Hwi_Module__gatePrms ti_sysbios_hal_Hwi_Module__gatePrms__C = ((const CT__ti_sysbios_hal_Hwi_Module__gatePrms)NULL);

/* Module__id__C */
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_Module__id__C, ".econst:ti_sysbios_hal_Hwi_Module__id__C");
asm("	.sect \".econst:ti_sysbios_hal_Hwi_Module__id__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_hal_Hwi_Module__id__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_hal_Hwi_Module__id__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_hal_Hwi_Module__id ti_sysbios_hal_Hwi_Module__id__C = (xdc_Bits16)0x8026;

/* Module__loggerDefined__C */
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_Module__loggerDefined__C, ".econst:ti_sysbios_hal_Hwi_Module__loggerDefined__C");
asm("	.sect \".econst:ti_sysbios_hal_Hwi_Module__loggerDefined__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_hal_Hwi_Module__loggerDefined__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_hal_Hwi_Module__loggerDefined__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_hal_Hwi_Module__loggerDefined ti_sysbios_hal_Hwi_Module__loggerDefined__C = 1;

/* Module__loggerObj__C */
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_Module__loggerObj__C, ".econst:ti_sysbios_hal_Hwi_Module__loggerObj__C");
asm("	.sect \".econst:ti_sysbios_hal_Hwi_Module__loggerObj__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_hal_Hwi_Module__loggerObj__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_hal_Hwi_Module__loggerObj__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_hal_Hwi_Module__loggerObj ti_sysbios_hal_Hwi_Module__loggerObj__C = ((const CT__ti_sysbios_hal_Hwi_Module__loggerObj)((void*)(xdc_runtime_ILogger_Handle)&xdc_runtime_LoggerBuf_Object__table__V[0]));

/* Module__loggerFxn0__C */
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_Module__loggerFxn0__C, ".econst:ti_sysbios_hal_Hwi_Module__loggerFxn0__C");
asm("	.sect \".econst:ti_sysbios_hal_Hwi_Module__loggerFxn0__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_hal_Hwi_Module__loggerFxn0__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_hal_Hwi_Module__loggerFxn0__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_hal_Hwi_Module__loggerFxn0 ti_sysbios_hal_Hwi_Module__loggerFxn0__C = ((const CT__ti_sysbios_hal_Hwi_Module__loggerFxn0)(xdc_runtime_LoggerBuf_write0));

/* Module__loggerFxn1__C */
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_Module__loggerFxn1__C, ".econst:ti_sysbios_hal_Hwi_Module__loggerFxn1__C");
asm("	.sect \".econst:ti_sysbios_hal_Hwi_Module__loggerFxn1__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_hal_Hwi_Module__loggerFxn1__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_hal_Hwi_Module__loggerFxn1__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_hal_Hwi_Module__loggerFxn1 ti_sysbios_hal_Hwi_Module__loggerFxn1__C = ((const CT__ti_sysbios_hal_Hwi_Module__loggerFxn1)(xdc_runtime_LoggerBuf_write1));

/* Module__loggerFxn2__C */
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_Module__loggerFxn2__C, ".econst:ti_sysbios_hal_Hwi_Module__loggerFxn2__C");
asm("	.sect \".econst:ti_sysbios_hal_Hwi_Module__loggerFxn2__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_hal_Hwi_Module__loggerFxn2__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_hal_Hwi_Module__loggerFxn2__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_hal_Hwi_Module__loggerFxn2 ti_sysbios_hal_Hwi_Module__loggerFxn2__C = ((const CT__ti_sysbios_hal_Hwi_Module__loggerFxn2)(xdc_runtime_LoggerBuf_write2));

/* Module__loggerFxn4__C */
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_Module__loggerFxn4__C, ".econst:ti_sysbios_hal_Hwi_Module__loggerFxn4__C");
asm("	.sect \".econst:ti_sysbios_hal_Hwi_Module__loggerFxn4__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_hal_Hwi_Module__loggerFxn4__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_hal_Hwi_Module__loggerFxn4__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_hal_Hwi_Module__loggerFxn4 ti_sysbios_hal_Hwi_Module__loggerFxn4__C = ((const CT__ti_sysbios_hal_Hwi_Module__loggerFxn4)(xdc_runtime_LoggerBuf_write4));

/* Module__loggerFxn8__C */
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_Module__loggerFxn8__C, ".econst:ti_sysbios_hal_Hwi_Module__loggerFxn8__C");
asm("	.sect \".econst:ti_sysbios_hal_Hwi_Module__loggerFxn8__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_hal_Hwi_Module__loggerFxn8__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_hal_Hwi_Module__loggerFxn8__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_hal_Hwi_Module__loggerFxn8 ti_sysbios_hal_Hwi_Module__loggerFxn8__C = ((const CT__ti_sysbios_hal_Hwi_Module__loggerFxn8)(xdc_runtime_LoggerBuf_write8));

/* Object__count__C */
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_Object__count__C, ".econst:ti_sysbios_hal_Hwi_Object__count__C");
asm("	.sect \".econst:ti_sysbios_hal_Hwi_Object__count__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_hal_Hwi_Object__count__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_hal_Hwi_Object__count__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_hal_Hwi_Object__count ti_sysbios_hal_Hwi_Object__count__C = 0;

/* Object__heap__C */
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_Object__heap__C, ".econst:ti_sysbios_hal_Hwi_Object__heap__C");
asm("	.sect \".econst:ti_sysbios_hal_Hwi_Object__heap__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_hal_Hwi_Object__heap__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_hal_Hwi_Object__heap__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_hal_Hwi_Object__heap ti_sysbios_hal_Hwi_Object__heap__C = NULL;

/* Object__sizeof__C */
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_Object__sizeof__C, ".econst:ti_sysbios_hal_Hwi_Object__sizeof__C");
asm("	.sect \".econst:ti_sysbios_hal_Hwi_Object__sizeof__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_hal_Hwi_Object__sizeof__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_hal_Hwi_Object__sizeof__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_hal_Hwi_Object__sizeof ti_sysbios_hal_Hwi_Object__sizeof__C = sizeof(ti_sysbios_hal_Hwi_Object__);

/* Object__table__C */
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_Object__table__C, ".econst:ti_sysbios_hal_Hwi_Object__table__C");
asm("	.sect \".econst:ti_sysbios_hal_Hwi_Object__table__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_hal_Hwi_Object__table__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_hal_Hwi_Object__table__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_hal_Hwi_Object__table ti_sysbios_hal_Hwi_Object__table__C = NULL;

/* dispatcherAutoNestingSupport__C */
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_dispatcherAutoNestingSupport__C, ".econst:ti_sysbios_hal_Hwi_dispatcherAutoNestingSupport__C");
asm("	.sect \".econst:ti_sysbios_hal_Hwi_dispatcherAutoNestingSupport__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_hal_Hwi_dispatcherAutoNestingSupport__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_hal_Hwi_dispatcherAutoNestingSupport__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_hal_Hwi_dispatcherAutoNestingSupport ti_sysbios_hal_Hwi_dispatcherAutoNestingSupport__C = 1;

/* dispatcherSwiSupport__C */
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_dispatcherSwiSupport__C, ".econst:ti_sysbios_hal_Hwi_dispatcherSwiSupport__C");
asm("	.sect \".econst:ti_sysbios_hal_Hwi_dispatcherSwiSupport__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_hal_Hwi_dispatcherSwiSupport__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_hal_Hwi_dispatcherSwiSupport__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_hal_Hwi_dispatcherSwiSupport ti_sysbios_hal_Hwi_dispatcherSwiSupport__C = 1;

/* dispatcherTaskSupport__C */
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_dispatcherTaskSupport__C, ".econst:ti_sysbios_hal_Hwi_dispatcherTaskSupport__C");
asm("	.sect \".econst:ti_sysbios_hal_Hwi_dispatcherTaskSupport__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_hal_Hwi_dispatcherTaskSupport__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_hal_Hwi_dispatcherTaskSupport__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_hal_Hwi_dispatcherTaskSupport ti_sysbios_hal_Hwi_dispatcherTaskSupport__C = 1;

/* dispatcherIrpTrackingSupport__C */
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_dispatcherIrpTrackingSupport__C, ".econst:ti_sysbios_hal_Hwi_dispatcherIrpTrackingSupport__C");
asm("	.sect \".econst:ti_sysbios_hal_Hwi_dispatcherIrpTrackingSupport__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_hal_Hwi_dispatcherIrpTrackingSupport__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_hal_Hwi_dispatcherIrpTrackingSupport__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_hal_Hwi_dispatcherIrpTrackingSupport ti_sysbios_hal_Hwi_dispatcherIrpTrackingSupport__C = 1;

/* E_stackOverflow__C */
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_E_stackOverflow__C, ".econst:ti_sysbios_hal_Hwi_E_stackOverflow__C");
asm("	.sect \".econst:ti_sysbios_hal_Hwi_E_stackOverflow__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_hal_Hwi_E_stackOverflow__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_hal_Hwi_E_stackOverflow__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_hal_Hwi_E_stackOverflow ti_sysbios_hal_Hwi_E_stackOverflow__C = (((xdc_runtime_Error_Id)4504) << 16 | 0U);


/*
 * ======== ti.sysbios.hal.Hwi_HwiProxy INITIALIZERS ========
 */


/*
 * ======== ti.sysbios.heaps.HeapMem INITIALIZERS ========
 */

/* Object__DESC__C */
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_heaps_HeapMem_Object__DESC__C;

/* Object__PARAMS__C */
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_Object__PARAMS__C, ".econst:ti_sysbios_heaps_HeapMem_Object__PARAMS__C");
asm("	.sect \".econst:ti_sysbios_heaps_HeapMem_Object__PARAMS__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_heaps_HeapMem_Object__PARAMS__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_heaps_HeapMem_Object__PARAMS__C\"");
asm("	.clink ");

__FAR__ const ti_sysbios_heaps_HeapMem_Params ti_sysbios_heaps_HeapMem_Object__PARAMS__C = {
    sizeof (ti_sysbios_heaps_HeapMem_Params), /* __size */
    NULL, /* __self */
    NULL, /* __fxns */
    (xdc_runtime_IInstance_Params*)&ti_sysbios_heaps_HeapMem_Object__PARAMS__C.__iprms, /* instance */
    (xdc_SizeT)0x0,  /* minBlockAlign */
    ((xdc_Ptr)(0x0)),  /* buf */
    ((xdc_UArg)(0x0)),  /* size */
    {
        sizeof (xdc_runtime_IInstance_Params), /* __size */
        0,  /* name */
    },  /* instance */
};

/* --> ti_sysbios_heaps_HeapMem_Instance_State_0_buf__A */
__T1_ti_sysbios_heaps_HeapMem_Instance_State__buf ti_sysbios_heaps_HeapMem_Instance_State_0_buf__A[2051];

/* Module__root__V */
ti_sysbios_heaps_HeapMem_Module__ ti_sysbios_heaps_HeapMem_Module__root__V = {
    {&ti_sysbios_heaps_HeapMem_Module__root__V.link,  /* link.next */
    &ti_sysbios_heaps_HeapMem_Module__root__V.link},  /* link.prev */
};

/* Object__table__V */
ti_sysbios_heaps_HeapMem_Object__ ti_sysbios_heaps_HeapMem_Object__table__V[1] = {
    {/* instance#0 */
        &ti_sysbios_heaps_HeapMem_Module__FXNS__C,
        ((xdc_UArg)(0x4)),  /* align */
        ((void*)ti_sysbios_heaps_HeapMem_Instance_State_0_buf__A),  /* buf */
        {
            ((ti_sysbios_heaps_HeapMem_Header*)NULL),  /* next */
            ((xdc_UArg)(0x800)),  /* size */
        },  /* head */
        (xdc_SizeT)0x4,  /* minBlockAlign */
    },
};

/* Module__diagsEnabled__C */
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_Module__diagsEnabled__C, ".econst:ti_sysbios_heaps_HeapMem_Module__diagsEnabled__C");
asm("	.sect \".econst:ti_sysbios_heaps_HeapMem_Module__diagsEnabled__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_heaps_HeapMem_Module__diagsEnabled__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_heaps_HeapMem_Module__diagsEnabled__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_heaps_HeapMem_Module__diagsEnabled ti_sysbios_heaps_HeapMem_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_Module__diagsIncluded__C, ".econst:ti_sysbios_heaps_HeapMem_Module__diagsIncluded__C");
asm("	.sect \".econst:ti_sysbios_heaps_HeapMem_Module__diagsIncluded__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_heaps_HeapMem_Module__diagsIncluded__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_heaps_HeapMem_Module__diagsIncluded__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_heaps_HeapMem_Module__diagsIncluded ti_sysbios_heaps_HeapMem_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_Module__diagsMask__C, ".econst:ti_sysbios_heaps_HeapMem_Module__diagsMask__C");
asm("	.sect \".econst:ti_sysbios_heaps_HeapMem_Module__diagsMask__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_heaps_HeapMem_Module__diagsMask__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_heaps_HeapMem_Module__diagsMask__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_heaps_HeapMem_Module__diagsMask ti_sysbios_heaps_HeapMem_Module__diagsMask__C = ((const CT__ti_sysbios_heaps_HeapMem_Module__diagsMask)NULL);

/* Module__gateObj__C */
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_Module__gateObj__C, ".econst:ti_sysbios_heaps_HeapMem_Module__gateObj__C");
asm("	.sect \".econst:ti_sysbios_heaps_HeapMem_Module__gateObj__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_heaps_HeapMem_Module__gateObj__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_heaps_HeapMem_Module__gateObj__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_heaps_HeapMem_Module__gateObj ti_sysbios_heaps_HeapMem_Module__gateObj__C = ((const CT__ti_sysbios_heaps_HeapMem_Module__gateObj)((void*)(xdc_runtime_IGateProvider_Handle)&ti_sysbios_gates_GateMutex_Object__table__V[0]));

/* Module__gatePrms__C */
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_Module__gatePrms__C, ".econst:ti_sysbios_heaps_HeapMem_Module__gatePrms__C");
asm("	.sect \".econst:ti_sysbios_heaps_HeapMem_Module__gatePrms__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_heaps_HeapMem_Module__gatePrms__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_heaps_HeapMem_Module__gatePrms__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_heaps_HeapMem_Module__gatePrms ti_sysbios_heaps_HeapMem_Module__gatePrms__C = ((const CT__ti_sysbios_heaps_HeapMem_Module__gatePrms)NULL);

/* Module__id__C */
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_Module__id__C, ".econst:ti_sysbios_heaps_HeapMem_Module__id__C");
asm("	.sect \".econst:ti_sysbios_heaps_HeapMem_Module__id__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_heaps_HeapMem_Module__id__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_heaps_HeapMem_Module__id__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_heaps_HeapMem_Module__id ti_sysbios_heaps_HeapMem_Module__id__C = (xdc_Bits16)0x8028;

/* Module__loggerDefined__C */
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_Module__loggerDefined__C, ".econst:ti_sysbios_heaps_HeapMem_Module__loggerDefined__C");
asm("	.sect \".econst:ti_sysbios_heaps_HeapMem_Module__loggerDefined__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_heaps_HeapMem_Module__loggerDefined__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_heaps_HeapMem_Module__loggerDefined__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_heaps_HeapMem_Module__loggerDefined ti_sysbios_heaps_HeapMem_Module__loggerDefined__C = 1;

/* Module__loggerObj__C */
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_Module__loggerObj__C, ".econst:ti_sysbios_heaps_HeapMem_Module__loggerObj__C");
asm("	.sect \".econst:ti_sysbios_heaps_HeapMem_Module__loggerObj__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_heaps_HeapMem_Module__loggerObj__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_heaps_HeapMem_Module__loggerObj__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_heaps_HeapMem_Module__loggerObj ti_sysbios_heaps_HeapMem_Module__loggerObj__C = ((const CT__ti_sysbios_heaps_HeapMem_Module__loggerObj)((void*)(xdc_runtime_ILogger_Handle)&xdc_runtime_LoggerBuf_Object__table__V[0]));

/* Module__loggerFxn0__C */
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_Module__loggerFxn0__C, ".econst:ti_sysbios_heaps_HeapMem_Module__loggerFxn0__C");
asm("	.sect \".econst:ti_sysbios_heaps_HeapMem_Module__loggerFxn0__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_heaps_HeapMem_Module__loggerFxn0__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_heaps_HeapMem_Module__loggerFxn0__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_heaps_HeapMem_Module__loggerFxn0 ti_sysbios_heaps_HeapMem_Module__loggerFxn0__C = ((const CT__ti_sysbios_heaps_HeapMem_Module__loggerFxn0)(xdc_runtime_LoggerBuf_write0));

/* Module__loggerFxn1__C */
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_Module__loggerFxn1__C, ".econst:ti_sysbios_heaps_HeapMem_Module__loggerFxn1__C");
asm("	.sect \".econst:ti_sysbios_heaps_HeapMem_Module__loggerFxn1__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_heaps_HeapMem_Module__loggerFxn1__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_heaps_HeapMem_Module__loggerFxn1__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_heaps_HeapMem_Module__loggerFxn1 ti_sysbios_heaps_HeapMem_Module__loggerFxn1__C = ((const CT__ti_sysbios_heaps_HeapMem_Module__loggerFxn1)(xdc_runtime_LoggerBuf_write1));

/* Module__loggerFxn2__C */
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_Module__loggerFxn2__C, ".econst:ti_sysbios_heaps_HeapMem_Module__loggerFxn2__C");
asm("	.sect \".econst:ti_sysbios_heaps_HeapMem_Module__loggerFxn2__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_heaps_HeapMem_Module__loggerFxn2__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_heaps_HeapMem_Module__loggerFxn2__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_heaps_HeapMem_Module__loggerFxn2 ti_sysbios_heaps_HeapMem_Module__loggerFxn2__C = ((const CT__ti_sysbios_heaps_HeapMem_Module__loggerFxn2)(xdc_runtime_LoggerBuf_write2));

/* Module__loggerFxn4__C */
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_Module__loggerFxn4__C, ".econst:ti_sysbios_heaps_HeapMem_Module__loggerFxn4__C");
asm("	.sect \".econst:ti_sysbios_heaps_HeapMem_Module__loggerFxn4__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_heaps_HeapMem_Module__loggerFxn4__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_heaps_HeapMem_Module__loggerFxn4__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_heaps_HeapMem_Module__loggerFxn4 ti_sysbios_heaps_HeapMem_Module__loggerFxn4__C = ((const CT__ti_sysbios_heaps_HeapMem_Module__loggerFxn4)(xdc_runtime_LoggerBuf_write4));

/* Module__loggerFxn8__C */
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_Module__loggerFxn8__C, ".econst:ti_sysbios_heaps_HeapMem_Module__loggerFxn8__C");
asm("	.sect \".econst:ti_sysbios_heaps_HeapMem_Module__loggerFxn8__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_heaps_HeapMem_Module__loggerFxn8__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_heaps_HeapMem_Module__loggerFxn8__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_heaps_HeapMem_Module__loggerFxn8 ti_sysbios_heaps_HeapMem_Module__loggerFxn8__C = ((const CT__ti_sysbios_heaps_HeapMem_Module__loggerFxn8)(xdc_runtime_LoggerBuf_write8));

/* Object__count__C */
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_Object__count__C, ".econst:ti_sysbios_heaps_HeapMem_Object__count__C");
asm("	.sect \".econst:ti_sysbios_heaps_HeapMem_Object__count__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_heaps_HeapMem_Object__count__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_heaps_HeapMem_Object__count__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_heaps_HeapMem_Object__count ti_sysbios_heaps_HeapMem_Object__count__C = 1;

/* Object__heap__C */
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_Object__heap__C, ".econst:ti_sysbios_heaps_HeapMem_Object__heap__C");
asm("	.sect \".econst:ti_sysbios_heaps_HeapMem_Object__heap__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_heaps_HeapMem_Object__heap__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_heaps_HeapMem_Object__heap__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_heaps_HeapMem_Object__heap ti_sysbios_heaps_HeapMem_Object__heap__C = NULL;

/* Object__sizeof__C */
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_Object__sizeof__C, ".econst:ti_sysbios_heaps_HeapMem_Object__sizeof__C");
asm("	.sect \".econst:ti_sysbios_heaps_HeapMem_Object__sizeof__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_heaps_HeapMem_Object__sizeof__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_heaps_HeapMem_Object__sizeof__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_heaps_HeapMem_Object__sizeof ti_sysbios_heaps_HeapMem_Object__sizeof__C = sizeof(ti_sysbios_heaps_HeapMem_Object__);

/* Object__table__C */
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_Object__table__C, ".econst:ti_sysbios_heaps_HeapMem_Object__table__C");
asm("	.sect \".econst:ti_sysbios_heaps_HeapMem_Object__table__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_heaps_HeapMem_Object__table__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_heaps_HeapMem_Object__table__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_heaps_HeapMem_Object__table ti_sysbios_heaps_HeapMem_Object__table__C = ti_sysbios_heaps_HeapMem_Object__table__V;

/* A_zeroBlock__C */
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_A_zeroBlock__C, ".econst:ti_sysbios_heaps_HeapMem_A_zeroBlock__C");
asm("	.sect \".econst:ti_sysbios_heaps_HeapMem_A_zeroBlock__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_heaps_HeapMem_A_zeroBlock__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_heaps_HeapMem_A_zeroBlock__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_heaps_HeapMem_A_zeroBlock ti_sysbios_heaps_HeapMem_A_zeroBlock__C = (((xdc_runtime_Assert_Id)3232) << 16 | 16);

/* A_heapSize__C */
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_A_heapSize__C, ".econst:ti_sysbios_heaps_HeapMem_A_heapSize__C");
asm("	.sect \".econst:ti_sysbios_heaps_HeapMem_A_heapSize__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_heaps_HeapMem_A_heapSize__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_heaps_HeapMem_A_heapSize__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_heaps_HeapMem_A_heapSize ti_sysbios_heaps_HeapMem_A_heapSize__C = (((xdc_runtime_Assert_Id)3268) << 16 | 16);

/* A_align__C */
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_A_align__C, ".econst:ti_sysbios_heaps_HeapMem_A_align__C");
asm("	.sect \".econst:ti_sysbios_heaps_HeapMem_A_align__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_heaps_HeapMem_A_align__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_heaps_HeapMem_A_align__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_heaps_HeapMem_A_align ti_sysbios_heaps_HeapMem_A_align__C = (((xdc_runtime_Assert_Id)3313) << 16 | 16);

/* E_memory__C */
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_E_memory__C, ".econst:ti_sysbios_heaps_HeapMem_E_memory__C");
asm("	.sect \".econst:ti_sysbios_heaps_HeapMem_E_memory__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_heaps_HeapMem_E_memory__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_heaps_HeapMem_E_memory__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_heaps_HeapMem_E_memory ti_sysbios_heaps_HeapMem_E_memory__C = (((xdc_runtime_Error_Id)4589) << 16 | 0U);

/* A_invalidFree__C */
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_A_invalidFree__C, ".econst:ti_sysbios_heaps_HeapMem_A_invalidFree__C");
asm("	.sect \".econst:ti_sysbios_heaps_HeapMem_A_invalidFree__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_heaps_HeapMem_A_invalidFree__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_heaps_HeapMem_A_invalidFree__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_heaps_HeapMem_A_invalidFree ti_sysbios_heaps_HeapMem_A_invalidFree__C = (((xdc_runtime_Assert_Id)3204) << 16 | 16);

/* primaryHeapBaseAddr__C */
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_primaryHeapBaseAddr__C, ".econst:ti_sysbios_heaps_HeapMem_primaryHeapBaseAddr__C");
asm("	.sect \".econst:ti_sysbios_heaps_HeapMem_primaryHeapBaseAddr__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_heaps_HeapMem_primaryHeapBaseAddr__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_heaps_HeapMem_primaryHeapBaseAddr__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_heaps_HeapMem_primaryHeapBaseAddr ti_sysbios_heaps_HeapMem_primaryHeapBaseAddr__C = ((const CT__ti_sysbios_heaps_HeapMem_primaryHeapBaseAddr)NULL);

/* primaryHeapEndAddr__C */
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_primaryHeapEndAddr__C, ".econst:ti_sysbios_heaps_HeapMem_primaryHeapEndAddr__C");
asm("	.sect \".econst:ti_sysbios_heaps_HeapMem_primaryHeapEndAddr__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_heaps_HeapMem_primaryHeapEndAddr__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_heaps_HeapMem_primaryHeapEndAddr__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_heaps_HeapMem_primaryHeapEndAddr ti_sysbios_heaps_HeapMem_primaryHeapEndAddr__C = ((const CT__ti_sysbios_heaps_HeapMem_primaryHeapEndAddr)NULL);

/* reqAlign__C */
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_reqAlign__C, ".econst:ti_sysbios_heaps_HeapMem_reqAlign__C");
asm("	.sect \".econst:ti_sysbios_heaps_HeapMem_reqAlign__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_heaps_HeapMem_reqAlign__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_heaps_HeapMem_reqAlign__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_heaps_HeapMem_reqAlign ti_sysbios_heaps_HeapMem_reqAlign__C = (xdc_SizeT)0x4;


/*
 * ======== ti.sysbios.heaps.HeapMem_Module_GateProxy INITIALIZERS ========
 */


/*
 * ======== ti.sysbios.knl.Clock INITIALIZERS ========
 */

/* Object__DESC__C */
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_knl_Clock_Object__DESC__C;

/* Object__PARAMS__C */
#pragma DATA_SECTION(ti_sysbios_knl_Clock_Object__PARAMS__C, ".econst:ti_sysbios_knl_Clock_Object__PARAMS__C");
asm("	.sect \".econst:ti_sysbios_knl_Clock_Object__PARAMS__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Clock_Object__PARAMS__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Clock_Object__PARAMS__C\"");
asm("	.clink ");

__FAR__ const ti_sysbios_knl_Clock_Params ti_sysbios_knl_Clock_Object__PARAMS__C = {
    sizeof (ti_sysbios_knl_Clock_Params), /* __size */
    NULL, /* __self */
    NULL, /* __fxns */
    (xdc_runtime_IInstance_Params*)&ti_sysbios_knl_Clock_Object__PARAMS__C.__iprms, /* instance */
    0,  /* startFlag */
    (xdc_UInt32)0x0,  /* period */
    ((xdc_UArg)NULL),  /* arg */
    {
        sizeof (xdc_runtime_IInstance_Params), /* __size */
        0,  /* name */
    },  /* instance */
};

/* Module__root__V */
ti_sysbios_knl_Clock_Module__ ti_sysbios_knl_Clock_Module__root__V = {
    {&ti_sysbios_knl_Clock_Module__root__V.link,  /* link.next */
    &ti_sysbios_knl_Clock_Module__root__V.link},  /* link.prev */
};

/* Object__table__V */
ti_sysbios_knl_Clock_Object__ ti_sysbios_knl_Clock_Object__table__V[1] = {
    {/* instance#0 */
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Clock_Module__state__V.Object_field_clockQ.elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Clock_Module__state__V.Object_field_clockQ.elem)),  /* prev */
        },  /* elem */
        (xdc_UInt32)0x3e8,  /* timeout */
        (xdc_UInt32)0x3e8,  /* currTimeout */
        (xdc_UInt32)0x3e8,  /* period */
        1,  /* active */
        ((xdc_Void(*)(xdc_UArg f_arg0))(DoEverySecond)),  /* fxn */
        ((xdc_UArg)NULL),  /* arg */
    },
};

/* Module__state__V */
#if defined (__ICCARM__)
#pragma location = ".data_ti_sysbios_knl_Clock_Module__state__V"
#endif
#if defined(__GNUC__) && !(defined(__MACH__) && defined(__APPLE__))
#ifndef __ti__
ti_sysbios_knl_Clock_Module_State__ ti_sysbios_knl_Clock_Module__state__V __attribute__ ((section(".data_ti_sysbios_knl_Clock_Module__state__V")));
#elif defined(__clang__)
ti_sysbios_knl_Clock_Module_State__ ti_sysbios_knl_Clock_Module__state__V __attribute__ ((section(".data:ti_sysbios_knl_Clock_Module__state__V")));
#endif
#endif
ti_sysbios_knl_Clock_Module_State__ ti_sysbios_knl_Clock_Module__state__V = {
    (xdc_UInt32)0x0,  /* ticks */
    (xdc_UInt)0x0,  /* swiCount */
    (ti_sysbios_knl_Clock_TimerProxy_Handle)&ti_sysbios_family_c28_Timer_Object__table__V[0],  /* timer */
    (ti_sysbios_knl_Swi_Handle)&ti_sysbios_knl_Swi_Object__table__V[0],  /* swi */
    (xdc_UInt)0x1,  /* numTickSkip */
    (xdc_UInt32)0x1,  /* nextScheduledTick */
    (xdc_UInt32)0x0,  /* maxSkippable */
    0,  /* inWorkFunc */
    0,  /* startDuringWorkFunc */
    0,  /* ticking */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Clock_Object__table__V[0].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Clock_Object__table__V[0].elem)),  /* prev */
        },  /* elem */
    },  /* Object_field_clockQ */
};

/* Module__diagsEnabled__C */
#pragma DATA_SECTION(ti_sysbios_knl_Clock_Module__diagsEnabled__C, ".econst:ti_sysbios_knl_Clock_Module__diagsEnabled__C");
asm("	.sect \".econst:ti_sysbios_knl_Clock_Module__diagsEnabled__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Clock_Module__diagsEnabled__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Clock_Module__diagsEnabled__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Clock_Module__diagsEnabled ti_sysbios_knl_Clock_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
#pragma DATA_SECTION(ti_sysbios_knl_Clock_Module__diagsIncluded__C, ".econst:ti_sysbios_knl_Clock_Module__diagsIncluded__C");
asm("	.sect \".econst:ti_sysbios_knl_Clock_Module__diagsIncluded__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Clock_Module__diagsIncluded__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Clock_Module__diagsIncluded__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Clock_Module__diagsIncluded ti_sysbios_knl_Clock_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
#pragma DATA_SECTION(ti_sysbios_knl_Clock_Module__diagsMask__C, ".econst:ti_sysbios_knl_Clock_Module__diagsMask__C");
asm("	.sect \".econst:ti_sysbios_knl_Clock_Module__diagsMask__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Clock_Module__diagsMask__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Clock_Module__diagsMask__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Clock_Module__diagsMask ti_sysbios_knl_Clock_Module__diagsMask__C = ((const CT__ti_sysbios_knl_Clock_Module__diagsMask)NULL);

/* Module__gateObj__C */
#pragma DATA_SECTION(ti_sysbios_knl_Clock_Module__gateObj__C, ".econst:ti_sysbios_knl_Clock_Module__gateObj__C");
asm("	.sect \".econst:ti_sysbios_knl_Clock_Module__gateObj__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Clock_Module__gateObj__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Clock_Module__gateObj__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Clock_Module__gateObj ti_sysbios_knl_Clock_Module__gateObj__C = ((const CT__ti_sysbios_knl_Clock_Module__gateObj)NULL);

/* Module__gatePrms__C */
#pragma DATA_SECTION(ti_sysbios_knl_Clock_Module__gatePrms__C, ".econst:ti_sysbios_knl_Clock_Module__gatePrms__C");
asm("	.sect \".econst:ti_sysbios_knl_Clock_Module__gatePrms__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Clock_Module__gatePrms__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Clock_Module__gatePrms__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Clock_Module__gatePrms ti_sysbios_knl_Clock_Module__gatePrms__C = ((const CT__ti_sysbios_knl_Clock_Module__gatePrms)NULL);

/* Module__id__C */
#pragma DATA_SECTION(ti_sysbios_knl_Clock_Module__id__C, ".econst:ti_sysbios_knl_Clock_Module__id__C");
asm("	.sect \".econst:ti_sysbios_knl_Clock_Module__id__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Clock_Module__id__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Clock_Module__id__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Clock_Module__id ti_sysbios_knl_Clock_Module__id__C = (xdc_Bits16)0x801b;

/* Module__loggerDefined__C */
#pragma DATA_SECTION(ti_sysbios_knl_Clock_Module__loggerDefined__C, ".econst:ti_sysbios_knl_Clock_Module__loggerDefined__C");
asm("	.sect \".econst:ti_sysbios_knl_Clock_Module__loggerDefined__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Clock_Module__loggerDefined__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Clock_Module__loggerDefined__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Clock_Module__loggerDefined ti_sysbios_knl_Clock_Module__loggerDefined__C = 1;

/* Module__loggerObj__C */
#pragma DATA_SECTION(ti_sysbios_knl_Clock_Module__loggerObj__C, ".econst:ti_sysbios_knl_Clock_Module__loggerObj__C");
asm("	.sect \".econst:ti_sysbios_knl_Clock_Module__loggerObj__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Clock_Module__loggerObj__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Clock_Module__loggerObj__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Clock_Module__loggerObj ti_sysbios_knl_Clock_Module__loggerObj__C = ((const CT__ti_sysbios_knl_Clock_Module__loggerObj)((void*)(xdc_runtime_ILogger_Handle)&xdc_runtime_LoggerBuf_Object__table__V[0]));

/* Module__loggerFxn0__C */
#pragma DATA_SECTION(ti_sysbios_knl_Clock_Module__loggerFxn0__C, ".econst:ti_sysbios_knl_Clock_Module__loggerFxn0__C");
asm("	.sect \".econst:ti_sysbios_knl_Clock_Module__loggerFxn0__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Clock_Module__loggerFxn0__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Clock_Module__loggerFxn0__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Clock_Module__loggerFxn0 ti_sysbios_knl_Clock_Module__loggerFxn0__C = ((const CT__ti_sysbios_knl_Clock_Module__loggerFxn0)(xdc_runtime_LoggerBuf_write0));

/* Module__loggerFxn1__C */
#pragma DATA_SECTION(ti_sysbios_knl_Clock_Module__loggerFxn1__C, ".econst:ti_sysbios_knl_Clock_Module__loggerFxn1__C");
asm("	.sect \".econst:ti_sysbios_knl_Clock_Module__loggerFxn1__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Clock_Module__loggerFxn1__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Clock_Module__loggerFxn1__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Clock_Module__loggerFxn1 ti_sysbios_knl_Clock_Module__loggerFxn1__C = ((const CT__ti_sysbios_knl_Clock_Module__loggerFxn1)(xdc_runtime_LoggerBuf_write1));

/* Module__loggerFxn2__C */
#pragma DATA_SECTION(ti_sysbios_knl_Clock_Module__loggerFxn2__C, ".econst:ti_sysbios_knl_Clock_Module__loggerFxn2__C");
asm("	.sect \".econst:ti_sysbios_knl_Clock_Module__loggerFxn2__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Clock_Module__loggerFxn2__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Clock_Module__loggerFxn2__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Clock_Module__loggerFxn2 ti_sysbios_knl_Clock_Module__loggerFxn2__C = ((const CT__ti_sysbios_knl_Clock_Module__loggerFxn2)(xdc_runtime_LoggerBuf_write2));

/* Module__loggerFxn4__C */
#pragma DATA_SECTION(ti_sysbios_knl_Clock_Module__loggerFxn4__C, ".econst:ti_sysbios_knl_Clock_Module__loggerFxn4__C");
asm("	.sect \".econst:ti_sysbios_knl_Clock_Module__loggerFxn4__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Clock_Module__loggerFxn4__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Clock_Module__loggerFxn4__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Clock_Module__loggerFxn4 ti_sysbios_knl_Clock_Module__loggerFxn4__C = ((const CT__ti_sysbios_knl_Clock_Module__loggerFxn4)(xdc_runtime_LoggerBuf_write4));

/* Module__loggerFxn8__C */
#pragma DATA_SECTION(ti_sysbios_knl_Clock_Module__loggerFxn8__C, ".econst:ti_sysbios_knl_Clock_Module__loggerFxn8__C");
asm("	.sect \".econst:ti_sysbios_knl_Clock_Module__loggerFxn8__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Clock_Module__loggerFxn8__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Clock_Module__loggerFxn8__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Clock_Module__loggerFxn8 ti_sysbios_knl_Clock_Module__loggerFxn8__C = ((const CT__ti_sysbios_knl_Clock_Module__loggerFxn8)(xdc_runtime_LoggerBuf_write8));

/* Object__count__C */
#pragma DATA_SECTION(ti_sysbios_knl_Clock_Object__count__C, ".econst:ti_sysbios_knl_Clock_Object__count__C");
asm("	.sect \".econst:ti_sysbios_knl_Clock_Object__count__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Clock_Object__count__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Clock_Object__count__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Clock_Object__count ti_sysbios_knl_Clock_Object__count__C = 1;

/* Object__heap__C */
#pragma DATA_SECTION(ti_sysbios_knl_Clock_Object__heap__C, ".econst:ti_sysbios_knl_Clock_Object__heap__C");
asm("	.sect \".econst:ti_sysbios_knl_Clock_Object__heap__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Clock_Object__heap__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Clock_Object__heap__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Clock_Object__heap ti_sysbios_knl_Clock_Object__heap__C = NULL;

/* Object__sizeof__C */
#pragma DATA_SECTION(ti_sysbios_knl_Clock_Object__sizeof__C, ".econst:ti_sysbios_knl_Clock_Object__sizeof__C");
asm("	.sect \".econst:ti_sysbios_knl_Clock_Object__sizeof__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Clock_Object__sizeof__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Clock_Object__sizeof__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Clock_Object__sizeof ti_sysbios_knl_Clock_Object__sizeof__C = sizeof(ti_sysbios_knl_Clock_Object__);

/* Object__table__C */
#pragma DATA_SECTION(ti_sysbios_knl_Clock_Object__table__C, ".econst:ti_sysbios_knl_Clock_Object__table__C");
asm("	.sect \".econst:ti_sysbios_knl_Clock_Object__table__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Clock_Object__table__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Clock_Object__table__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Clock_Object__table ti_sysbios_knl_Clock_Object__table__C = ti_sysbios_knl_Clock_Object__table__V;

/* LW_delayed__C */
#pragma DATA_SECTION(ti_sysbios_knl_Clock_LW_delayed__C, ".econst:ti_sysbios_knl_Clock_LW_delayed__C");
asm("	.sect \".econst:ti_sysbios_knl_Clock_LW_delayed__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Clock_LW_delayed__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Clock_LW_delayed__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Clock_LW_delayed ti_sysbios_knl_Clock_LW_delayed__C = (((xdc_runtime_Log_Event)4889) << 16 | 1024);

/* LM_tick__C */
#pragma DATA_SECTION(ti_sysbios_knl_Clock_LM_tick__C, ".econst:ti_sysbios_knl_Clock_LM_tick__C");
asm("	.sect \".econst:ti_sysbios_knl_Clock_LM_tick__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Clock_LM_tick__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Clock_LM_tick__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Clock_LM_tick ti_sysbios_knl_Clock_LM_tick__C = (((xdc_runtime_Log_Event)4911) << 16 | 768);

/* LM_begin__C */
#pragma DATA_SECTION(ti_sysbios_knl_Clock_LM_begin__C, ".econst:ti_sysbios_knl_Clock_LM_begin__C");
asm("	.sect \".econst:ti_sysbios_knl_Clock_LM_begin__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Clock_LM_begin__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Clock_LM_begin__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Clock_LM_begin ti_sysbios_knl_Clock_LM_begin__C = (((xdc_runtime_Log_Event)4929) << 16 | 768);

/* A_clockDisabled__C */
#pragma DATA_SECTION(ti_sysbios_knl_Clock_A_clockDisabled__C, ".econst:ti_sysbios_knl_Clock_A_clockDisabled__C");
asm("	.sect \".econst:ti_sysbios_knl_Clock_A_clockDisabled__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Clock_A_clockDisabled__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Clock_A_clockDisabled__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Clock_A_clockDisabled ti_sysbios_knl_Clock_A_clockDisabled__C = (((xdc_runtime_Assert_Id)706) << 16 | 16);

/* A_badThreadType__C */
#pragma DATA_SECTION(ti_sysbios_knl_Clock_A_badThreadType__C, ".econst:ti_sysbios_knl_Clock_A_badThreadType__C");
asm("	.sect \".econst:ti_sysbios_knl_Clock_A_badThreadType__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Clock_A_badThreadType__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Clock_A_badThreadType__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Clock_A_badThreadType ti_sysbios_knl_Clock_A_badThreadType__C = (((xdc_runtime_Assert_Id)787) << 16 | 16);

/* serviceMargin__C */
#pragma DATA_SECTION(ti_sysbios_knl_Clock_serviceMargin__C, ".econst:ti_sysbios_knl_Clock_serviceMargin__C");
asm("	.sect \".econst:ti_sysbios_knl_Clock_serviceMargin__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Clock_serviceMargin__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Clock_serviceMargin__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Clock_serviceMargin ti_sysbios_knl_Clock_serviceMargin__C = (xdc_UInt32)0x0;

/* tickSource__C */
#pragma DATA_SECTION(ti_sysbios_knl_Clock_tickSource__C, ".econst:ti_sysbios_knl_Clock_tickSource__C");
asm("	.sect \".econst:ti_sysbios_knl_Clock_tickSource__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Clock_tickSource__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Clock_tickSource__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Clock_tickSource ti_sysbios_knl_Clock_tickSource__C = ti_sysbios_knl_Clock_TickSource_TIMER;

/* tickMode__C */
#pragma DATA_SECTION(ti_sysbios_knl_Clock_tickMode__C, ".econst:ti_sysbios_knl_Clock_tickMode__C");
asm("	.sect \".econst:ti_sysbios_knl_Clock_tickMode__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Clock_tickMode__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Clock_tickMode__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Clock_tickMode ti_sysbios_knl_Clock_tickMode__C = ti_sysbios_knl_Clock_TickMode_PERIODIC;

/* timerId__C */
#pragma DATA_SECTION(ti_sysbios_knl_Clock_timerId__C, ".econst:ti_sysbios_knl_Clock_timerId__C");
asm("	.sect \".econst:ti_sysbios_knl_Clock_timerId__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Clock_timerId__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Clock_timerId__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Clock_timerId ti_sysbios_knl_Clock_timerId__C = (xdc_UInt)(-0x0 - 1);

/* tickPeriod__C */
#pragma DATA_SECTION(ti_sysbios_knl_Clock_tickPeriod__C, ".econst:ti_sysbios_knl_Clock_tickPeriod__C");
asm("	.sect \".econst:ti_sysbios_knl_Clock_tickPeriod__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Clock_tickPeriod__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Clock_tickPeriod__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Clock_tickPeriod ti_sysbios_knl_Clock_tickPeriod__C = (xdc_UInt32)0x3e8;

/* doTickFunc__C */
#pragma DATA_SECTION(ti_sysbios_knl_Clock_doTickFunc__C, ".econst:ti_sysbios_knl_Clock_doTickFunc__C");
asm("	.sect \".econst:ti_sysbios_knl_Clock_doTickFunc__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Clock_doTickFunc__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Clock_doTickFunc__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Clock_doTickFunc ti_sysbios_knl_Clock_doTickFunc__C = ((const CT__ti_sysbios_knl_Clock_doTickFunc)(ti_sysbios_knl_Clock_doTick__I));

/* triggerClock__C */
#pragma DATA_SECTION(ti_sysbios_knl_Clock_triggerClock__C, ".econst:ti_sysbios_knl_Clock_triggerClock__C");
asm("	.sect \".econst:ti_sysbios_knl_Clock_triggerClock__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Clock_triggerClock__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Clock_triggerClock__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Clock_triggerClock ti_sysbios_knl_Clock_triggerClock__C = 0;


/*
 * ======== ti.sysbios.knl.Clock_TimerProxy INITIALIZERS ========
 */


/*
 * ======== ti.sysbios.knl.Idle INITIALIZERS ========
 */

/* --> ti_sysbios_knl_Idle_funcList__A */
#pragma DATA_SECTION(ti_sysbios_knl_Idle_funcList__A, ".econst:ti_sysbios_knl_Idle_funcList__A");
asm("	.sect \".econst:ti_sysbios_knl_Idle_funcList__A\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Idle_funcList__A\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Idle_funcList__A\"");
asm("	.clink ");

const __T1_ti_sysbios_knl_Idle_funcList ti_sysbios_knl_Idle_funcList__A[1] = {
    ((xdc_Void(*)(xdc_Void))(ti_sysbios_hal_Hwi_checkStack)),  /* [0] */
};

/* --> ti_sysbios_knl_Idle_coreList__A */
#pragma DATA_SECTION(ti_sysbios_knl_Idle_coreList__A, ".econst:ti_sysbios_knl_Idle_coreList__A");
asm("	.sect \".econst:ti_sysbios_knl_Idle_coreList__A\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Idle_coreList__A\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Idle_coreList__A\"");
asm("	.clink ");

const __T1_ti_sysbios_knl_Idle_coreList ti_sysbios_knl_Idle_coreList__A[1] = {
    (xdc_UInt)0x0,  /* [0] */
};

/* Module__diagsEnabled__C */
#pragma DATA_SECTION(ti_sysbios_knl_Idle_Module__diagsEnabled__C, ".econst:ti_sysbios_knl_Idle_Module__diagsEnabled__C");
asm("	.sect \".econst:ti_sysbios_knl_Idle_Module__diagsEnabled__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Idle_Module__diagsEnabled__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Idle_Module__diagsEnabled__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Idle_Module__diagsEnabled ti_sysbios_knl_Idle_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
#pragma DATA_SECTION(ti_sysbios_knl_Idle_Module__diagsIncluded__C, ".econst:ti_sysbios_knl_Idle_Module__diagsIncluded__C");
asm("	.sect \".econst:ti_sysbios_knl_Idle_Module__diagsIncluded__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Idle_Module__diagsIncluded__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Idle_Module__diagsIncluded__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Idle_Module__diagsIncluded ti_sysbios_knl_Idle_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
#pragma DATA_SECTION(ti_sysbios_knl_Idle_Module__diagsMask__C, ".econst:ti_sysbios_knl_Idle_Module__diagsMask__C");
asm("	.sect \".econst:ti_sysbios_knl_Idle_Module__diagsMask__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Idle_Module__diagsMask__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Idle_Module__diagsMask__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Idle_Module__diagsMask ti_sysbios_knl_Idle_Module__diagsMask__C = ((const CT__ti_sysbios_knl_Idle_Module__diagsMask)NULL);

/* Module__gateObj__C */
#pragma DATA_SECTION(ti_sysbios_knl_Idle_Module__gateObj__C, ".econst:ti_sysbios_knl_Idle_Module__gateObj__C");
asm("	.sect \".econst:ti_sysbios_knl_Idle_Module__gateObj__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Idle_Module__gateObj__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Idle_Module__gateObj__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Idle_Module__gateObj ti_sysbios_knl_Idle_Module__gateObj__C = ((const CT__ti_sysbios_knl_Idle_Module__gateObj)NULL);

/* Module__gatePrms__C */
#pragma DATA_SECTION(ti_sysbios_knl_Idle_Module__gatePrms__C, ".econst:ti_sysbios_knl_Idle_Module__gatePrms__C");
asm("	.sect \".econst:ti_sysbios_knl_Idle_Module__gatePrms__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Idle_Module__gatePrms__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Idle_Module__gatePrms__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Idle_Module__gatePrms ti_sysbios_knl_Idle_Module__gatePrms__C = ((const CT__ti_sysbios_knl_Idle_Module__gatePrms)NULL);

/* Module__id__C */
#pragma DATA_SECTION(ti_sysbios_knl_Idle_Module__id__C, ".econst:ti_sysbios_knl_Idle_Module__id__C");
asm("	.sect \".econst:ti_sysbios_knl_Idle_Module__id__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Idle_Module__id__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Idle_Module__id__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Idle_Module__id ti_sysbios_knl_Idle_Module__id__C = (xdc_Bits16)0x801c;

/* Module__loggerDefined__C */
#pragma DATA_SECTION(ti_sysbios_knl_Idle_Module__loggerDefined__C, ".econst:ti_sysbios_knl_Idle_Module__loggerDefined__C");
asm("	.sect \".econst:ti_sysbios_knl_Idle_Module__loggerDefined__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Idle_Module__loggerDefined__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Idle_Module__loggerDefined__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Idle_Module__loggerDefined ti_sysbios_knl_Idle_Module__loggerDefined__C = 1;

/* Module__loggerObj__C */
#pragma DATA_SECTION(ti_sysbios_knl_Idle_Module__loggerObj__C, ".econst:ti_sysbios_knl_Idle_Module__loggerObj__C");
asm("	.sect \".econst:ti_sysbios_knl_Idle_Module__loggerObj__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Idle_Module__loggerObj__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Idle_Module__loggerObj__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Idle_Module__loggerObj ti_sysbios_knl_Idle_Module__loggerObj__C = ((const CT__ti_sysbios_knl_Idle_Module__loggerObj)((void*)(xdc_runtime_ILogger_Handle)&xdc_runtime_LoggerBuf_Object__table__V[0]));

/* Module__loggerFxn0__C */
#pragma DATA_SECTION(ti_sysbios_knl_Idle_Module__loggerFxn0__C, ".econst:ti_sysbios_knl_Idle_Module__loggerFxn0__C");
asm("	.sect \".econst:ti_sysbios_knl_Idle_Module__loggerFxn0__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Idle_Module__loggerFxn0__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Idle_Module__loggerFxn0__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Idle_Module__loggerFxn0 ti_sysbios_knl_Idle_Module__loggerFxn0__C = ((const CT__ti_sysbios_knl_Idle_Module__loggerFxn0)(xdc_runtime_LoggerBuf_write0));

/* Module__loggerFxn1__C */
#pragma DATA_SECTION(ti_sysbios_knl_Idle_Module__loggerFxn1__C, ".econst:ti_sysbios_knl_Idle_Module__loggerFxn1__C");
asm("	.sect \".econst:ti_sysbios_knl_Idle_Module__loggerFxn1__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Idle_Module__loggerFxn1__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Idle_Module__loggerFxn1__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Idle_Module__loggerFxn1 ti_sysbios_knl_Idle_Module__loggerFxn1__C = ((const CT__ti_sysbios_knl_Idle_Module__loggerFxn1)(xdc_runtime_LoggerBuf_write1));

/* Module__loggerFxn2__C */
#pragma DATA_SECTION(ti_sysbios_knl_Idle_Module__loggerFxn2__C, ".econst:ti_sysbios_knl_Idle_Module__loggerFxn2__C");
asm("	.sect \".econst:ti_sysbios_knl_Idle_Module__loggerFxn2__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Idle_Module__loggerFxn2__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Idle_Module__loggerFxn2__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Idle_Module__loggerFxn2 ti_sysbios_knl_Idle_Module__loggerFxn2__C = ((const CT__ti_sysbios_knl_Idle_Module__loggerFxn2)(xdc_runtime_LoggerBuf_write2));

/* Module__loggerFxn4__C */
#pragma DATA_SECTION(ti_sysbios_knl_Idle_Module__loggerFxn4__C, ".econst:ti_sysbios_knl_Idle_Module__loggerFxn4__C");
asm("	.sect \".econst:ti_sysbios_knl_Idle_Module__loggerFxn4__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Idle_Module__loggerFxn4__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Idle_Module__loggerFxn4__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Idle_Module__loggerFxn4 ti_sysbios_knl_Idle_Module__loggerFxn4__C = ((const CT__ti_sysbios_knl_Idle_Module__loggerFxn4)(xdc_runtime_LoggerBuf_write4));

/* Module__loggerFxn8__C */
#pragma DATA_SECTION(ti_sysbios_knl_Idle_Module__loggerFxn8__C, ".econst:ti_sysbios_knl_Idle_Module__loggerFxn8__C");
asm("	.sect \".econst:ti_sysbios_knl_Idle_Module__loggerFxn8__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Idle_Module__loggerFxn8__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Idle_Module__loggerFxn8__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Idle_Module__loggerFxn8 ti_sysbios_knl_Idle_Module__loggerFxn8__C = ((const CT__ti_sysbios_knl_Idle_Module__loggerFxn8)(xdc_runtime_LoggerBuf_write8));

/* Object__count__C */
#pragma DATA_SECTION(ti_sysbios_knl_Idle_Object__count__C, ".econst:ti_sysbios_knl_Idle_Object__count__C");
asm("	.sect \".econst:ti_sysbios_knl_Idle_Object__count__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Idle_Object__count__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Idle_Object__count__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Idle_Object__count ti_sysbios_knl_Idle_Object__count__C = 0;

/* Object__heap__C */
#pragma DATA_SECTION(ti_sysbios_knl_Idle_Object__heap__C, ".econst:ti_sysbios_knl_Idle_Object__heap__C");
asm("	.sect \".econst:ti_sysbios_knl_Idle_Object__heap__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Idle_Object__heap__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Idle_Object__heap__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Idle_Object__heap ti_sysbios_knl_Idle_Object__heap__C = NULL;

/* Object__sizeof__C */
#pragma DATA_SECTION(ti_sysbios_knl_Idle_Object__sizeof__C, ".econst:ti_sysbios_knl_Idle_Object__sizeof__C");
asm("	.sect \".econst:ti_sysbios_knl_Idle_Object__sizeof__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Idle_Object__sizeof__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Idle_Object__sizeof__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Idle_Object__sizeof ti_sysbios_knl_Idle_Object__sizeof__C = 0;

/* Object__table__C */
#pragma DATA_SECTION(ti_sysbios_knl_Idle_Object__table__C, ".econst:ti_sysbios_knl_Idle_Object__table__C");
asm("	.sect \".econst:ti_sysbios_knl_Idle_Object__table__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Idle_Object__table__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Idle_Object__table__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Idle_Object__table ti_sysbios_knl_Idle_Object__table__C = NULL;

/* funcList__C */
#pragma DATA_SECTION(ti_sysbios_knl_Idle_funcList__C, ".econst:ti_sysbios_knl_Idle_funcList__C");
asm("	.sect \".econst:ti_sysbios_knl_Idle_funcList__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Idle_funcList__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Idle_funcList__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Idle_funcList ti_sysbios_knl_Idle_funcList__C = {1, ((__T1_ti_sysbios_knl_Idle_funcList const  *)ti_sysbios_knl_Idle_funcList__A)};

/* coreList__C */
#pragma DATA_SECTION(ti_sysbios_knl_Idle_coreList__C, ".econst:ti_sysbios_knl_Idle_coreList__C");
asm("	.sect \".econst:ti_sysbios_knl_Idle_coreList__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Idle_coreList__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Idle_coreList__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Idle_coreList ti_sysbios_knl_Idle_coreList__C = {1, ((__T1_ti_sysbios_knl_Idle_coreList const  *)ti_sysbios_knl_Idle_coreList__A)};


/*
 * ======== ti.sysbios.knl.Intrinsics INITIALIZERS ========
 */

/* Module__diagsEnabled__C */
#pragma DATA_SECTION(ti_sysbios_knl_Intrinsics_Module__diagsEnabled__C, ".econst:ti_sysbios_knl_Intrinsics_Module__diagsEnabled__C");
asm("	.sect \".econst:ti_sysbios_knl_Intrinsics_Module__diagsEnabled__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Intrinsics_Module__diagsEnabled__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Intrinsics_Module__diagsEnabled__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Intrinsics_Module__diagsEnabled ti_sysbios_knl_Intrinsics_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
#pragma DATA_SECTION(ti_sysbios_knl_Intrinsics_Module__diagsIncluded__C, ".econst:ti_sysbios_knl_Intrinsics_Module__diagsIncluded__C");
asm("	.sect \".econst:ti_sysbios_knl_Intrinsics_Module__diagsIncluded__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Intrinsics_Module__diagsIncluded__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Intrinsics_Module__diagsIncluded__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Intrinsics_Module__diagsIncluded ti_sysbios_knl_Intrinsics_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
#pragma DATA_SECTION(ti_sysbios_knl_Intrinsics_Module__diagsMask__C, ".econst:ti_sysbios_knl_Intrinsics_Module__diagsMask__C");
asm("	.sect \".econst:ti_sysbios_knl_Intrinsics_Module__diagsMask__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Intrinsics_Module__diagsMask__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Intrinsics_Module__diagsMask__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Intrinsics_Module__diagsMask ti_sysbios_knl_Intrinsics_Module__diagsMask__C = ((const CT__ti_sysbios_knl_Intrinsics_Module__diagsMask)NULL);

/* Module__gateObj__C */
#pragma DATA_SECTION(ti_sysbios_knl_Intrinsics_Module__gateObj__C, ".econst:ti_sysbios_knl_Intrinsics_Module__gateObj__C");
asm("	.sect \".econst:ti_sysbios_knl_Intrinsics_Module__gateObj__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Intrinsics_Module__gateObj__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Intrinsics_Module__gateObj__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Intrinsics_Module__gateObj ti_sysbios_knl_Intrinsics_Module__gateObj__C = ((const CT__ti_sysbios_knl_Intrinsics_Module__gateObj)NULL);

/* Module__gatePrms__C */
#pragma DATA_SECTION(ti_sysbios_knl_Intrinsics_Module__gatePrms__C, ".econst:ti_sysbios_knl_Intrinsics_Module__gatePrms__C");
asm("	.sect \".econst:ti_sysbios_knl_Intrinsics_Module__gatePrms__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Intrinsics_Module__gatePrms__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Intrinsics_Module__gatePrms__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Intrinsics_Module__gatePrms ti_sysbios_knl_Intrinsics_Module__gatePrms__C = ((const CT__ti_sysbios_knl_Intrinsics_Module__gatePrms)NULL);

/* Module__id__C */
#pragma DATA_SECTION(ti_sysbios_knl_Intrinsics_Module__id__C, ".econst:ti_sysbios_knl_Intrinsics_Module__id__C");
asm("	.sect \".econst:ti_sysbios_knl_Intrinsics_Module__id__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Intrinsics_Module__id__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Intrinsics_Module__id__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Intrinsics_Module__id ti_sysbios_knl_Intrinsics_Module__id__C = (xdc_Bits16)0x801d;

/* Module__loggerDefined__C */
#pragma DATA_SECTION(ti_sysbios_knl_Intrinsics_Module__loggerDefined__C, ".econst:ti_sysbios_knl_Intrinsics_Module__loggerDefined__C");
asm("	.sect \".econst:ti_sysbios_knl_Intrinsics_Module__loggerDefined__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Intrinsics_Module__loggerDefined__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Intrinsics_Module__loggerDefined__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Intrinsics_Module__loggerDefined ti_sysbios_knl_Intrinsics_Module__loggerDefined__C = 1;

/* Module__loggerObj__C */
#pragma DATA_SECTION(ti_sysbios_knl_Intrinsics_Module__loggerObj__C, ".econst:ti_sysbios_knl_Intrinsics_Module__loggerObj__C");
asm("	.sect \".econst:ti_sysbios_knl_Intrinsics_Module__loggerObj__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Intrinsics_Module__loggerObj__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Intrinsics_Module__loggerObj__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Intrinsics_Module__loggerObj ti_sysbios_knl_Intrinsics_Module__loggerObj__C = ((const CT__ti_sysbios_knl_Intrinsics_Module__loggerObj)((void*)(xdc_runtime_ILogger_Handle)&xdc_runtime_LoggerBuf_Object__table__V[0]));

/* Module__loggerFxn0__C */
#pragma DATA_SECTION(ti_sysbios_knl_Intrinsics_Module__loggerFxn0__C, ".econst:ti_sysbios_knl_Intrinsics_Module__loggerFxn0__C");
asm("	.sect \".econst:ti_sysbios_knl_Intrinsics_Module__loggerFxn0__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Intrinsics_Module__loggerFxn0__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Intrinsics_Module__loggerFxn0__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Intrinsics_Module__loggerFxn0 ti_sysbios_knl_Intrinsics_Module__loggerFxn0__C = ((const CT__ti_sysbios_knl_Intrinsics_Module__loggerFxn0)(xdc_runtime_LoggerBuf_write0));

/* Module__loggerFxn1__C */
#pragma DATA_SECTION(ti_sysbios_knl_Intrinsics_Module__loggerFxn1__C, ".econst:ti_sysbios_knl_Intrinsics_Module__loggerFxn1__C");
asm("	.sect \".econst:ti_sysbios_knl_Intrinsics_Module__loggerFxn1__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Intrinsics_Module__loggerFxn1__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Intrinsics_Module__loggerFxn1__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Intrinsics_Module__loggerFxn1 ti_sysbios_knl_Intrinsics_Module__loggerFxn1__C = ((const CT__ti_sysbios_knl_Intrinsics_Module__loggerFxn1)(xdc_runtime_LoggerBuf_write1));

/* Module__loggerFxn2__C */
#pragma DATA_SECTION(ti_sysbios_knl_Intrinsics_Module__loggerFxn2__C, ".econst:ti_sysbios_knl_Intrinsics_Module__loggerFxn2__C");
asm("	.sect \".econst:ti_sysbios_knl_Intrinsics_Module__loggerFxn2__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Intrinsics_Module__loggerFxn2__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Intrinsics_Module__loggerFxn2__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Intrinsics_Module__loggerFxn2 ti_sysbios_knl_Intrinsics_Module__loggerFxn2__C = ((const CT__ti_sysbios_knl_Intrinsics_Module__loggerFxn2)(xdc_runtime_LoggerBuf_write2));

/* Module__loggerFxn4__C */
#pragma DATA_SECTION(ti_sysbios_knl_Intrinsics_Module__loggerFxn4__C, ".econst:ti_sysbios_knl_Intrinsics_Module__loggerFxn4__C");
asm("	.sect \".econst:ti_sysbios_knl_Intrinsics_Module__loggerFxn4__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Intrinsics_Module__loggerFxn4__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Intrinsics_Module__loggerFxn4__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Intrinsics_Module__loggerFxn4 ti_sysbios_knl_Intrinsics_Module__loggerFxn4__C = ((const CT__ti_sysbios_knl_Intrinsics_Module__loggerFxn4)(xdc_runtime_LoggerBuf_write4));

/* Module__loggerFxn8__C */
#pragma DATA_SECTION(ti_sysbios_knl_Intrinsics_Module__loggerFxn8__C, ".econst:ti_sysbios_knl_Intrinsics_Module__loggerFxn8__C");
asm("	.sect \".econst:ti_sysbios_knl_Intrinsics_Module__loggerFxn8__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Intrinsics_Module__loggerFxn8__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Intrinsics_Module__loggerFxn8__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Intrinsics_Module__loggerFxn8 ti_sysbios_knl_Intrinsics_Module__loggerFxn8__C = ((const CT__ti_sysbios_knl_Intrinsics_Module__loggerFxn8)(xdc_runtime_LoggerBuf_write8));

/* Object__count__C */
#pragma DATA_SECTION(ti_sysbios_knl_Intrinsics_Object__count__C, ".econst:ti_sysbios_knl_Intrinsics_Object__count__C");
asm("	.sect \".econst:ti_sysbios_knl_Intrinsics_Object__count__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Intrinsics_Object__count__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Intrinsics_Object__count__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Intrinsics_Object__count ti_sysbios_knl_Intrinsics_Object__count__C = 0;

/* Object__heap__C */
#pragma DATA_SECTION(ti_sysbios_knl_Intrinsics_Object__heap__C, ".econst:ti_sysbios_knl_Intrinsics_Object__heap__C");
asm("	.sect \".econst:ti_sysbios_knl_Intrinsics_Object__heap__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Intrinsics_Object__heap__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Intrinsics_Object__heap__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Intrinsics_Object__heap ti_sysbios_knl_Intrinsics_Object__heap__C = NULL;

/* Object__sizeof__C */
#pragma DATA_SECTION(ti_sysbios_knl_Intrinsics_Object__sizeof__C, ".econst:ti_sysbios_knl_Intrinsics_Object__sizeof__C");
asm("	.sect \".econst:ti_sysbios_knl_Intrinsics_Object__sizeof__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Intrinsics_Object__sizeof__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Intrinsics_Object__sizeof__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Intrinsics_Object__sizeof ti_sysbios_knl_Intrinsics_Object__sizeof__C = 0;

/* Object__table__C */
#pragma DATA_SECTION(ti_sysbios_knl_Intrinsics_Object__table__C, ".econst:ti_sysbios_knl_Intrinsics_Object__table__C");
asm("	.sect \".econst:ti_sysbios_knl_Intrinsics_Object__table__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Intrinsics_Object__table__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Intrinsics_Object__table__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Intrinsics_Object__table ti_sysbios_knl_Intrinsics_Object__table__C = NULL;


/*
 * ======== ti.sysbios.knl.Intrinsics_SupportProxy INITIALIZERS ========
 */


/*
 * ======== ti.sysbios.knl.Queue INITIALIZERS ========
 */

/* Object__DESC__C */
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_knl_Queue_Object__DESC__C;

/* Object__PARAMS__C */
#pragma DATA_SECTION(ti_sysbios_knl_Queue_Object__PARAMS__C, ".econst:ti_sysbios_knl_Queue_Object__PARAMS__C");
asm("	.sect \".econst:ti_sysbios_knl_Queue_Object__PARAMS__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Queue_Object__PARAMS__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Queue_Object__PARAMS__C\"");
asm("	.clink ");

__FAR__ const ti_sysbios_knl_Queue_Params ti_sysbios_knl_Queue_Object__PARAMS__C = {
    sizeof (ti_sysbios_knl_Queue_Params), /* __size */
    NULL, /* __self */
    NULL, /* __fxns */
    (xdc_runtime_IInstance_Params*)&ti_sysbios_knl_Queue_Object__PARAMS__C.__iprms, /* instance */
    {
        sizeof (xdc_runtime_IInstance_Params), /* __size */
        0,  /* name */
    },  /* instance */
};

/* Module__root__V */
ti_sysbios_knl_Queue_Module__ ti_sysbios_knl_Queue_Module__root__V = {
    {&ti_sysbios_knl_Queue_Module__root__V.link,  /* link.next */
    &ti_sysbios_knl_Queue_Module__root__V.link},  /* link.prev */
};

/* Module__diagsEnabled__C */
#pragma DATA_SECTION(ti_sysbios_knl_Queue_Module__diagsEnabled__C, ".econst:ti_sysbios_knl_Queue_Module__diagsEnabled__C");
asm("	.sect \".econst:ti_sysbios_knl_Queue_Module__diagsEnabled__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Queue_Module__diagsEnabled__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Queue_Module__diagsEnabled__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Queue_Module__diagsEnabled ti_sysbios_knl_Queue_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
#pragma DATA_SECTION(ti_sysbios_knl_Queue_Module__diagsIncluded__C, ".econst:ti_sysbios_knl_Queue_Module__diagsIncluded__C");
asm("	.sect \".econst:ti_sysbios_knl_Queue_Module__diagsIncluded__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Queue_Module__diagsIncluded__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Queue_Module__diagsIncluded__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Queue_Module__diagsIncluded ti_sysbios_knl_Queue_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
#pragma DATA_SECTION(ti_sysbios_knl_Queue_Module__diagsMask__C, ".econst:ti_sysbios_knl_Queue_Module__diagsMask__C");
asm("	.sect \".econst:ti_sysbios_knl_Queue_Module__diagsMask__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Queue_Module__diagsMask__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Queue_Module__diagsMask__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Queue_Module__diagsMask ti_sysbios_knl_Queue_Module__diagsMask__C = ((const CT__ti_sysbios_knl_Queue_Module__diagsMask)NULL);

/* Module__gateObj__C */
#pragma DATA_SECTION(ti_sysbios_knl_Queue_Module__gateObj__C, ".econst:ti_sysbios_knl_Queue_Module__gateObj__C");
asm("	.sect \".econst:ti_sysbios_knl_Queue_Module__gateObj__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Queue_Module__gateObj__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Queue_Module__gateObj__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Queue_Module__gateObj ti_sysbios_knl_Queue_Module__gateObj__C = ((const CT__ti_sysbios_knl_Queue_Module__gateObj)NULL);

/* Module__gatePrms__C */
#pragma DATA_SECTION(ti_sysbios_knl_Queue_Module__gatePrms__C, ".econst:ti_sysbios_knl_Queue_Module__gatePrms__C");
asm("	.sect \".econst:ti_sysbios_knl_Queue_Module__gatePrms__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Queue_Module__gatePrms__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Queue_Module__gatePrms__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Queue_Module__gatePrms ti_sysbios_knl_Queue_Module__gatePrms__C = ((const CT__ti_sysbios_knl_Queue_Module__gatePrms)NULL);

/* Module__id__C */
#pragma DATA_SECTION(ti_sysbios_knl_Queue_Module__id__C, ".econst:ti_sysbios_knl_Queue_Module__id__C");
asm("	.sect \".econst:ti_sysbios_knl_Queue_Module__id__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Queue_Module__id__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Queue_Module__id__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Queue_Module__id ti_sysbios_knl_Queue_Module__id__C = (xdc_Bits16)0x801e;

/* Module__loggerDefined__C */
#pragma DATA_SECTION(ti_sysbios_knl_Queue_Module__loggerDefined__C, ".econst:ti_sysbios_knl_Queue_Module__loggerDefined__C");
asm("	.sect \".econst:ti_sysbios_knl_Queue_Module__loggerDefined__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Queue_Module__loggerDefined__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Queue_Module__loggerDefined__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Queue_Module__loggerDefined ti_sysbios_knl_Queue_Module__loggerDefined__C = 1;

/* Module__loggerObj__C */
#pragma DATA_SECTION(ti_sysbios_knl_Queue_Module__loggerObj__C, ".econst:ti_sysbios_knl_Queue_Module__loggerObj__C");
asm("	.sect \".econst:ti_sysbios_knl_Queue_Module__loggerObj__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Queue_Module__loggerObj__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Queue_Module__loggerObj__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Queue_Module__loggerObj ti_sysbios_knl_Queue_Module__loggerObj__C = ((const CT__ti_sysbios_knl_Queue_Module__loggerObj)((void*)(xdc_runtime_ILogger_Handle)&xdc_runtime_LoggerBuf_Object__table__V[0]));

/* Module__loggerFxn0__C */
#pragma DATA_SECTION(ti_sysbios_knl_Queue_Module__loggerFxn0__C, ".econst:ti_sysbios_knl_Queue_Module__loggerFxn0__C");
asm("	.sect \".econst:ti_sysbios_knl_Queue_Module__loggerFxn0__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Queue_Module__loggerFxn0__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Queue_Module__loggerFxn0__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Queue_Module__loggerFxn0 ti_sysbios_knl_Queue_Module__loggerFxn0__C = ((const CT__ti_sysbios_knl_Queue_Module__loggerFxn0)(xdc_runtime_LoggerBuf_write0));

/* Module__loggerFxn1__C */
#pragma DATA_SECTION(ti_sysbios_knl_Queue_Module__loggerFxn1__C, ".econst:ti_sysbios_knl_Queue_Module__loggerFxn1__C");
asm("	.sect \".econst:ti_sysbios_knl_Queue_Module__loggerFxn1__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Queue_Module__loggerFxn1__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Queue_Module__loggerFxn1__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Queue_Module__loggerFxn1 ti_sysbios_knl_Queue_Module__loggerFxn1__C = ((const CT__ti_sysbios_knl_Queue_Module__loggerFxn1)(xdc_runtime_LoggerBuf_write1));

/* Module__loggerFxn2__C */
#pragma DATA_SECTION(ti_sysbios_knl_Queue_Module__loggerFxn2__C, ".econst:ti_sysbios_knl_Queue_Module__loggerFxn2__C");
asm("	.sect \".econst:ti_sysbios_knl_Queue_Module__loggerFxn2__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Queue_Module__loggerFxn2__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Queue_Module__loggerFxn2__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Queue_Module__loggerFxn2 ti_sysbios_knl_Queue_Module__loggerFxn2__C = ((const CT__ti_sysbios_knl_Queue_Module__loggerFxn2)(xdc_runtime_LoggerBuf_write2));

/* Module__loggerFxn4__C */
#pragma DATA_SECTION(ti_sysbios_knl_Queue_Module__loggerFxn4__C, ".econst:ti_sysbios_knl_Queue_Module__loggerFxn4__C");
asm("	.sect \".econst:ti_sysbios_knl_Queue_Module__loggerFxn4__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Queue_Module__loggerFxn4__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Queue_Module__loggerFxn4__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Queue_Module__loggerFxn4 ti_sysbios_knl_Queue_Module__loggerFxn4__C = ((const CT__ti_sysbios_knl_Queue_Module__loggerFxn4)(xdc_runtime_LoggerBuf_write4));

/* Module__loggerFxn8__C */
#pragma DATA_SECTION(ti_sysbios_knl_Queue_Module__loggerFxn8__C, ".econst:ti_sysbios_knl_Queue_Module__loggerFxn8__C");
asm("	.sect \".econst:ti_sysbios_knl_Queue_Module__loggerFxn8__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Queue_Module__loggerFxn8__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Queue_Module__loggerFxn8__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Queue_Module__loggerFxn8 ti_sysbios_knl_Queue_Module__loggerFxn8__C = ((const CT__ti_sysbios_knl_Queue_Module__loggerFxn8)(xdc_runtime_LoggerBuf_write8));

/* Object__count__C */
#pragma DATA_SECTION(ti_sysbios_knl_Queue_Object__count__C, ".econst:ti_sysbios_knl_Queue_Object__count__C");
asm("	.sect \".econst:ti_sysbios_knl_Queue_Object__count__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Queue_Object__count__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Queue_Object__count__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Queue_Object__count ti_sysbios_knl_Queue_Object__count__C = 0;

/* Object__heap__C */
#pragma DATA_SECTION(ti_sysbios_knl_Queue_Object__heap__C, ".econst:ti_sysbios_knl_Queue_Object__heap__C");
asm("	.sect \".econst:ti_sysbios_knl_Queue_Object__heap__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Queue_Object__heap__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Queue_Object__heap__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Queue_Object__heap ti_sysbios_knl_Queue_Object__heap__C = NULL;

/* Object__sizeof__C */
#pragma DATA_SECTION(ti_sysbios_knl_Queue_Object__sizeof__C, ".econst:ti_sysbios_knl_Queue_Object__sizeof__C");
asm("	.sect \".econst:ti_sysbios_knl_Queue_Object__sizeof__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Queue_Object__sizeof__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Queue_Object__sizeof__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Queue_Object__sizeof ti_sysbios_knl_Queue_Object__sizeof__C = sizeof(ti_sysbios_knl_Queue_Object__);

/* Object__table__C */
#pragma DATA_SECTION(ti_sysbios_knl_Queue_Object__table__C, ".econst:ti_sysbios_knl_Queue_Object__table__C");
asm("	.sect \".econst:ti_sysbios_knl_Queue_Object__table__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Queue_Object__table__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Queue_Object__table__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Queue_Object__table ti_sysbios_knl_Queue_Object__table__C = NULL;


/*
 * ======== ti.sysbios.knl.Semaphore INITIALIZERS ========
 */

/* Object__DESC__C */
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_knl_Semaphore_Object__DESC__C;

/* Object__PARAMS__C */
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_Object__PARAMS__C, ".econst:ti_sysbios_knl_Semaphore_Object__PARAMS__C");
asm("	.sect \".econst:ti_sysbios_knl_Semaphore_Object__PARAMS__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Semaphore_Object__PARAMS__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Semaphore_Object__PARAMS__C\"");
asm("	.clink ");

__FAR__ const ti_sysbios_knl_Semaphore_Params ti_sysbios_knl_Semaphore_Object__PARAMS__C = {
    sizeof (ti_sysbios_knl_Semaphore_Params), /* __size */
    NULL, /* __self */
    NULL, /* __fxns */
    (xdc_runtime_IInstance_Params*)&ti_sysbios_knl_Semaphore_Object__PARAMS__C.__iprms, /* instance */
    0,  /* event */
    (xdc_UInt)0x1,  /* eventId */
    ti_sysbios_knl_Semaphore_Mode_COUNTING,  /* mode */
    {
        sizeof (xdc_runtime_IInstance_Params), /* __size */
        0,  /* name */
    },  /* instance */
};

/* Module__root__V */
ti_sysbios_knl_Semaphore_Module__ ti_sysbios_knl_Semaphore_Module__root__V = {
    {&ti_sysbios_knl_Semaphore_Module__root__V.link,  /* link.next */
    &ti_sysbios_knl_Semaphore_Module__root__V.link},  /* link.prev */
};

/* Module__diagsEnabled__C */
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_Module__diagsEnabled__C, ".econst:ti_sysbios_knl_Semaphore_Module__diagsEnabled__C");
asm("	.sect \".econst:ti_sysbios_knl_Semaphore_Module__diagsEnabled__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Semaphore_Module__diagsEnabled__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Semaphore_Module__diagsEnabled__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Semaphore_Module__diagsEnabled ti_sysbios_knl_Semaphore_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_Module__diagsIncluded__C, ".econst:ti_sysbios_knl_Semaphore_Module__diagsIncluded__C");
asm("	.sect \".econst:ti_sysbios_knl_Semaphore_Module__diagsIncluded__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Semaphore_Module__diagsIncluded__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Semaphore_Module__diagsIncluded__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Semaphore_Module__diagsIncluded ti_sysbios_knl_Semaphore_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_Module__diagsMask__C, ".econst:ti_sysbios_knl_Semaphore_Module__diagsMask__C");
asm("	.sect \".econst:ti_sysbios_knl_Semaphore_Module__diagsMask__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Semaphore_Module__diagsMask__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Semaphore_Module__diagsMask__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Semaphore_Module__diagsMask ti_sysbios_knl_Semaphore_Module__diagsMask__C = ((const CT__ti_sysbios_knl_Semaphore_Module__diagsMask)NULL);

/* Module__gateObj__C */
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_Module__gateObj__C, ".econst:ti_sysbios_knl_Semaphore_Module__gateObj__C");
asm("	.sect \".econst:ti_sysbios_knl_Semaphore_Module__gateObj__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Semaphore_Module__gateObj__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Semaphore_Module__gateObj__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Semaphore_Module__gateObj ti_sysbios_knl_Semaphore_Module__gateObj__C = ((const CT__ti_sysbios_knl_Semaphore_Module__gateObj)NULL);

/* Module__gatePrms__C */
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_Module__gatePrms__C, ".econst:ti_sysbios_knl_Semaphore_Module__gatePrms__C");
asm("	.sect \".econst:ti_sysbios_knl_Semaphore_Module__gatePrms__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Semaphore_Module__gatePrms__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Semaphore_Module__gatePrms__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Semaphore_Module__gatePrms ti_sysbios_knl_Semaphore_Module__gatePrms__C = ((const CT__ti_sysbios_knl_Semaphore_Module__gatePrms)NULL);

/* Module__id__C */
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_Module__id__C, ".econst:ti_sysbios_knl_Semaphore_Module__id__C");
asm("	.sect \".econst:ti_sysbios_knl_Semaphore_Module__id__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Semaphore_Module__id__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Semaphore_Module__id__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Semaphore_Module__id ti_sysbios_knl_Semaphore_Module__id__C = (xdc_Bits16)0x801f;

/* Module__loggerDefined__C */
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_Module__loggerDefined__C, ".econst:ti_sysbios_knl_Semaphore_Module__loggerDefined__C");
asm("	.sect \".econst:ti_sysbios_knl_Semaphore_Module__loggerDefined__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Semaphore_Module__loggerDefined__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Semaphore_Module__loggerDefined__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Semaphore_Module__loggerDefined ti_sysbios_knl_Semaphore_Module__loggerDefined__C = 1;

/* Module__loggerObj__C */
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_Module__loggerObj__C, ".econst:ti_sysbios_knl_Semaphore_Module__loggerObj__C");
asm("	.sect \".econst:ti_sysbios_knl_Semaphore_Module__loggerObj__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Semaphore_Module__loggerObj__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Semaphore_Module__loggerObj__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Semaphore_Module__loggerObj ti_sysbios_knl_Semaphore_Module__loggerObj__C = ((const CT__ti_sysbios_knl_Semaphore_Module__loggerObj)((void*)(xdc_runtime_ILogger_Handle)&xdc_runtime_LoggerBuf_Object__table__V[0]));

/* Module__loggerFxn0__C */
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_Module__loggerFxn0__C, ".econst:ti_sysbios_knl_Semaphore_Module__loggerFxn0__C");
asm("	.sect \".econst:ti_sysbios_knl_Semaphore_Module__loggerFxn0__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Semaphore_Module__loggerFxn0__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Semaphore_Module__loggerFxn0__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Semaphore_Module__loggerFxn0 ti_sysbios_knl_Semaphore_Module__loggerFxn0__C = ((const CT__ti_sysbios_knl_Semaphore_Module__loggerFxn0)(xdc_runtime_LoggerBuf_write0));

/* Module__loggerFxn1__C */
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_Module__loggerFxn1__C, ".econst:ti_sysbios_knl_Semaphore_Module__loggerFxn1__C");
asm("	.sect \".econst:ti_sysbios_knl_Semaphore_Module__loggerFxn1__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Semaphore_Module__loggerFxn1__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Semaphore_Module__loggerFxn1__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Semaphore_Module__loggerFxn1 ti_sysbios_knl_Semaphore_Module__loggerFxn1__C = ((const CT__ti_sysbios_knl_Semaphore_Module__loggerFxn1)(xdc_runtime_LoggerBuf_write1));

/* Module__loggerFxn2__C */
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_Module__loggerFxn2__C, ".econst:ti_sysbios_knl_Semaphore_Module__loggerFxn2__C");
asm("	.sect \".econst:ti_sysbios_knl_Semaphore_Module__loggerFxn2__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Semaphore_Module__loggerFxn2__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Semaphore_Module__loggerFxn2__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Semaphore_Module__loggerFxn2 ti_sysbios_knl_Semaphore_Module__loggerFxn2__C = ((const CT__ti_sysbios_knl_Semaphore_Module__loggerFxn2)(xdc_runtime_LoggerBuf_write2));

/* Module__loggerFxn4__C */
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_Module__loggerFxn4__C, ".econst:ti_sysbios_knl_Semaphore_Module__loggerFxn4__C");
asm("	.sect \".econst:ti_sysbios_knl_Semaphore_Module__loggerFxn4__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Semaphore_Module__loggerFxn4__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Semaphore_Module__loggerFxn4__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Semaphore_Module__loggerFxn4 ti_sysbios_knl_Semaphore_Module__loggerFxn4__C = ((const CT__ti_sysbios_knl_Semaphore_Module__loggerFxn4)(xdc_runtime_LoggerBuf_write4));

/* Module__loggerFxn8__C */
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_Module__loggerFxn8__C, ".econst:ti_sysbios_knl_Semaphore_Module__loggerFxn8__C");
asm("	.sect \".econst:ti_sysbios_knl_Semaphore_Module__loggerFxn8__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Semaphore_Module__loggerFxn8__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Semaphore_Module__loggerFxn8__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Semaphore_Module__loggerFxn8 ti_sysbios_knl_Semaphore_Module__loggerFxn8__C = ((const CT__ti_sysbios_knl_Semaphore_Module__loggerFxn8)(xdc_runtime_LoggerBuf_write8));

/* Object__count__C */
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_Object__count__C, ".econst:ti_sysbios_knl_Semaphore_Object__count__C");
asm("	.sect \".econst:ti_sysbios_knl_Semaphore_Object__count__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Semaphore_Object__count__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Semaphore_Object__count__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Semaphore_Object__count ti_sysbios_knl_Semaphore_Object__count__C = 0;

/* Object__heap__C */
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_Object__heap__C, ".econst:ti_sysbios_knl_Semaphore_Object__heap__C");
asm("	.sect \".econst:ti_sysbios_knl_Semaphore_Object__heap__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Semaphore_Object__heap__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Semaphore_Object__heap__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Semaphore_Object__heap ti_sysbios_knl_Semaphore_Object__heap__C = NULL;

/* Object__sizeof__C */
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_Object__sizeof__C, ".econst:ti_sysbios_knl_Semaphore_Object__sizeof__C");
asm("	.sect \".econst:ti_sysbios_knl_Semaphore_Object__sizeof__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Semaphore_Object__sizeof__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Semaphore_Object__sizeof__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Semaphore_Object__sizeof ti_sysbios_knl_Semaphore_Object__sizeof__C = sizeof(ti_sysbios_knl_Semaphore_Object__);

/* Object__table__C */
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_Object__table__C, ".econst:ti_sysbios_knl_Semaphore_Object__table__C");
asm("	.sect \".econst:ti_sysbios_knl_Semaphore_Object__table__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Semaphore_Object__table__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Semaphore_Object__table__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Semaphore_Object__table ti_sysbios_knl_Semaphore_Object__table__C = NULL;

/* LM_post__C */
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_LM_post__C, ".econst:ti_sysbios_knl_Semaphore_LM_post__C");
asm("	.sect \".econst:ti_sysbios_knl_Semaphore_LM_post__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Semaphore_LM_post__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Semaphore_LM_post__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Semaphore_LM_post ti_sysbios_knl_Semaphore_LM_post__C = (((xdc_runtime_Log_Event)4961) << 16 | 768);

/* LM_pend__C */
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_LM_pend__C, ".econst:ti_sysbios_knl_Semaphore_LM_pend__C");
asm("	.sect \".econst:ti_sysbios_knl_Semaphore_LM_pend__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Semaphore_LM_pend__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Semaphore_LM_pend__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Semaphore_LM_pend ti_sysbios_knl_Semaphore_LM_pend__C = (((xdc_runtime_Log_Event)4991) << 16 | 768);

/* A_noEvents__C */
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_A_noEvents__C, ".econst:ti_sysbios_knl_Semaphore_A_noEvents__C");
asm("	.sect \".econst:ti_sysbios_knl_Semaphore_A_noEvents__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Semaphore_A_noEvents__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Semaphore_A_noEvents__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Semaphore_A_noEvents ti_sysbios_knl_Semaphore_A_noEvents__C = (((xdc_runtime_Assert_Id)1197) << 16 | 16);

/* A_invTimeout__C */
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_A_invTimeout__C, ".econst:ti_sysbios_knl_Semaphore_A_invTimeout__C");
asm("	.sect \".econst:ti_sysbios_knl_Semaphore_A_invTimeout__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Semaphore_A_invTimeout__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Semaphore_A_invTimeout__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Semaphore_A_invTimeout ti_sysbios_knl_Semaphore_A_invTimeout__C = (((xdc_runtime_Assert_Id)1252) << 16 | 16);

/* A_badContext__C */
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_A_badContext__C, ".econst:ti_sysbios_knl_Semaphore_A_badContext__C");
asm("	.sect \".econst:ti_sysbios_knl_Semaphore_A_badContext__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Semaphore_A_badContext__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Semaphore_A_badContext__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Semaphore_A_badContext ti_sysbios_knl_Semaphore_A_badContext__C = (((xdc_runtime_Assert_Id)986) << 16 | 16);

/* A_overflow__C */
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_A_overflow__C, ".econst:ti_sysbios_knl_Semaphore_A_overflow__C");
asm("	.sect \".econst:ti_sysbios_knl_Semaphore_A_overflow__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Semaphore_A_overflow__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Semaphore_A_overflow__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Semaphore_A_overflow ti_sysbios_knl_Semaphore_A_overflow__C = (((xdc_runtime_Assert_Id)1317) << 16 | 16);

/* A_pendTaskDisabled__C */
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_A_pendTaskDisabled__C, ".econst:ti_sysbios_knl_Semaphore_A_pendTaskDisabled__C");
asm("	.sect \".econst:ti_sysbios_knl_Semaphore_A_pendTaskDisabled__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Semaphore_A_pendTaskDisabled__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Semaphore_A_pendTaskDisabled__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Semaphore_A_pendTaskDisabled ti_sysbios_knl_Semaphore_A_pendTaskDisabled__C = (((xdc_runtime_Assert_Id)1371) << 16 | 16);

/* E_objectNotInKernelSpace__C */
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_E_objectNotInKernelSpace__C, ".econst:ti_sysbios_knl_Semaphore_E_objectNotInKernelSpace__C");
asm("	.sect \".econst:ti_sysbios_knl_Semaphore_E_objectNotInKernelSpace__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Semaphore_E_objectNotInKernelSpace__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Semaphore_E_objectNotInKernelSpace__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Semaphore_E_objectNotInKernelSpace ti_sysbios_knl_Semaphore_E_objectNotInKernelSpace__C = (((xdc_runtime_Error_Id)4044) << 16 | 0U);

/* supportsEvents__C */
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_supportsEvents__C, ".econst:ti_sysbios_knl_Semaphore_supportsEvents__C");
asm("	.sect \".econst:ti_sysbios_knl_Semaphore_supportsEvents__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Semaphore_supportsEvents__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Semaphore_supportsEvents__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Semaphore_supportsEvents ti_sysbios_knl_Semaphore_supportsEvents__C = 0;

/* supportsPriority__C */
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_supportsPriority__C, ".econst:ti_sysbios_knl_Semaphore_supportsPriority__C");
asm("	.sect \".econst:ti_sysbios_knl_Semaphore_supportsPriority__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Semaphore_supportsPriority__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Semaphore_supportsPriority__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Semaphore_supportsPriority ti_sysbios_knl_Semaphore_supportsPriority__C = 1;

/* eventPost__C */
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_eventPost__C, ".econst:ti_sysbios_knl_Semaphore_eventPost__C");
asm("	.sect \".econst:ti_sysbios_knl_Semaphore_eventPost__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Semaphore_eventPost__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Semaphore_eventPost__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Semaphore_eventPost ti_sysbios_knl_Semaphore_eventPost__C = ((const CT__ti_sysbios_knl_Semaphore_eventPost)NULL);

/* eventSync__C */
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_eventSync__C, ".econst:ti_sysbios_knl_Semaphore_eventSync__C");
asm("	.sect \".econst:ti_sysbios_knl_Semaphore_eventSync__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Semaphore_eventSync__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Semaphore_eventSync__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Semaphore_eventSync ti_sysbios_knl_Semaphore_eventSync__C = ((const CT__ti_sysbios_knl_Semaphore_eventSync)NULL);


/*
 * ======== ti.sysbios.knl.Swi INITIALIZERS ========
 */

/* Object__DESC__C */
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_knl_Swi_Object__DESC__C;

/* Object__PARAMS__C */
#pragma DATA_SECTION(ti_sysbios_knl_Swi_Object__PARAMS__C, ".econst:ti_sysbios_knl_Swi_Object__PARAMS__C");
asm("	.sect \".econst:ti_sysbios_knl_Swi_Object__PARAMS__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Swi_Object__PARAMS__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Swi_Object__PARAMS__C\"");
asm("	.clink ");

__FAR__ const ti_sysbios_knl_Swi_Params ti_sysbios_knl_Swi_Object__PARAMS__C = {
    sizeof (ti_sysbios_knl_Swi_Params), /* __size */
    NULL, /* __self */
    NULL, /* __fxns */
    (xdc_runtime_IInstance_Params*)&ti_sysbios_knl_Swi_Object__PARAMS__C.__iprms, /* instance */
    ((xdc_UArg)(0x0)),  /* arg0 */
    ((xdc_UArg)(0x0)),  /* arg1 */
    (xdc_UInt)(-0x0 - 1),  /* priority */
    (xdc_UInt)0x0,  /* trigger */
    {
        sizeof (xdc_runtime_IInstance_Params), /* __size */
        0,  /* name */
    },  /* instance */
};

/* Module__root__V */
ti_sysbios_knl_Swi_Module__ ti_sysbios_knl_Swi_Module__root__V = {
    {&ti_sysbios_knl_Swi_Module__root__V.link,  /* link.next */
    &ti_sysbios_knl_Swi_Module__root__V.link},  /* link.prev */
};

/* Object__table__V */
ti_sysbios_knl_Swi_Object__ ti_sysbios_knl_Swi_Object__table__V[1] = {
    {/* instance#0 */
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Object__table__V[0].qElem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Object__table__V[0].qElem)),  /* prev */
        },  /* qElem */
        ((xdc_Void(*)(xdc_UArg f_arg0,xdc_UArg f_arg1))(ti_sysbios_knl_Clock_workFunc__E)),  /* fxn */
        ((xdc_UArg)(0x0)),  /* arg0 */
        ((xdc_UArg)(0x0)),  /* arg1 */
        (xdc_UInt)0xf,  /* priority */
        (xdc_UInt)0x8000,  /* mask */
        0,  /* posted */
        (xdc_UInt)0x0,  /* initTrigger */
        (xdc_UInt)0x0,  /* trigger */
        (ti_sysbios_knl_Queue_Handle)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[15],  /* readyQ */
        ((void*)0),  /* hookEnv */
    },
};

/* --> ti_sysbios_knl_Swi_Module_State_0_readyQ__A */
__T1_ti_sysbios_knl_Swi_Module_State__readyQ ti_sysbios_knl_Swi_Module_State_0_readyQ__A[16] = {
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[0].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[0].elem)),  /* prev */
        },  /* elem */
    },  /* [0] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[1].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[1].elem)),  /* prev */
        },  /* elem */
    },  /* [1] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[2].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[2].elem)),  /* prev */
        },  /* elem */
    },  /* [2] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[3].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[3].elem)),  /* prev */
        },  /* elem */
    },  /* [3] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[4].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[4].elem)),  /* prev */
        },  /* elem */
    },  /* [4] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[5].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[5].elem)),  /* prev */
        },  /* elem */
    },  /* [5] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[6].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[6].elem)),  /* prev */
        },  /* elem */
    },  /* [6] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[7].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[7].elem)),  /* prev */
        },  /* elem */
    },  /* [7] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[8].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[8].elem)),  /* prev */
        },  /* elem */
    },  /* [8] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[9].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[9].elem)),  /* prev */
        },  /* elem */
    },  /* [9] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[10].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[10].elem)),  /* prev */
        },  /* elem */
    },  /* [10] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[11].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[11].elem)),  /* prev */
        },  /* elem */
    },  /* [11] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[12].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[12].elem)),  /* prev */
        },  /* elem */
    },  /* [12] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[13].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[13].elem)),  /* prev */
        },  /* elem */
    },  /* [13] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[14].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[14].elem)),  /* prev */
        },  /* elem */
    },  /* [14] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[15].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Swi_Module_State_0_readyQ__A[15].elem)),  /* prev */
        },  /* elem */
    },  /* [15] */
};

/* Module__state__V */
#if defined (__ICCARM__)
#pragma location = ".data_ti_sysbios_knl_Swi_Module__state__V"
#endif
#if defined(__GNUC__) && !(defined(__MACH__) && defined(__APPLE__))
#ifndef __ti__
ti_sysbios_knl_Swi_Module_State__ ti_sysbios_knl_Swi_Module__state__V __attribute__ ((section(".data_ti_sysbios_knl_Swi_Module__state__V")));
#elif defined(__clang__)
ti_sysbios_knl_Swi_Module_State__ ti_sysbios_knl_Swi_Module__state__V __attribute__ ((section(".data:ti_sysbios_knl_Swi_Module__state__V")));
#endif
#endif
ti_sysbios_knl_Swi_Module_State__ ti_sysbios_knl_Swi_Module__state__V = {
    1,  /* locked */
    (xdc_UInt)0x0,  /* curSet */
    (xdc_UInt)0x0,  /* curTrigger */
    0,  /* curSwi */
    0,  /* curQ */
    ((void*)ti_sysbios_knl_Swi_Module_State_0_readyQ__A),  /* readyQ */
    ((void*)0),  /* constructedSwis */
};

/* Module__diagsEnabled__C */
#pragma DATA_SECTION(ti_sysbios_knl_Swi_Module__diagsEnabled__C, ".econst:ti_sysbios_knl_Swi_Module__diagsEnabled__C");
asm("	.sect \".econst:ti_sysbios_knl_Swi_Module__diagsEnabled__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Swi_Module__diagsEnabled__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Swi_Module__diagsEnabled__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Swi_Module__diagsEnabled ti_sysbios_knl_Swi_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
#pragma DATA_SECTION(ti_sysbios_knl_Swi_Module__diagsIncluded__C, ".econst:ti_sysbios_knl_Swi_Module__diagsIncluded__C");
asm("	.sect \".econst:ti_sysbios_knl_Swi_Module__diagsIncluded__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Swi_Module__diagsIncluded__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Swi_Module__diagsIncluded__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Swi_Module__diagsIncluded ti_sysbios_knl_Swi_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
#pragma DATA_SECTION(ti_sysbios_knl_Swi_Module__diagsMask__C, ".econst:ti_sysbios_knl_Swi_Module__diagsMask__C");
asm("	.sect \".econst:ti_sysbios_knl_Swi_Module__diagsMask__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Swi_Module__diagsMask__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Swi_Module__diagsMask__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Swi_Module__diagsMask ti_sysbios_knl_Swi_Module__diagsMask__C = ((const CT__ti_sysbios_knl_Swi_Module__diagsMask)NULL);

/* Module__gateObj__C */
#pragma DATA_SECTION(ti_sysbios_knl_Swi_Module__gateObj__C, ".econst:ti_sysbios_knl_Swi_Module__gateObj__C");
asm("	.sect \".econst:ti_sysbios_knl_Swi_Module__gateObj__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Swi_Module__gateObj__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Swi_Module__gateObj__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Swi_Module__gateObj ti_sysbios_knl_Swi_Module__gateObj__C = ((const CT__ti_sysbios_knl_Swi_Module__gateObj)NULL);

/* Module__gatePrms__C */
#pragma DATA_SECTION(ti_sysbios_knl_Swi_Module__gatePrms__C, ".econst:ti_sysbios_knl_Swi_Module__gatePrms__C");
asm("	.sect \".econst:ti_sysbios_knl_Swi_Module__gatePrms__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Swi_Module__gatePrms__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Swi_Module__gatePrms__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Swi_Module__gatePrms ti_sysbios_knl_Swi_Module__gatePrms__C = ((const CT__ti_sysbios_knl_Swi_Module__gatePrms)NULL);

/* Module__id__C */
#pragma DATA_SECTION(ti_sysbios_knl_Swi_Module__id__C, ".econst:ti_sysbios_knl_Swi_Module__id__C");
asm("	.sect \".econst:ti_sysbios_knl_Swi_Module__id__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Swi_Module__id__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Swi_Module__id__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Swi_Module__id ti_sysbios_knl_Swi_Module__id__C = (xdc_Bits16)0x8020;

/* Module__loggerDefined__C */
#pragma DATA_SECTION(ti_sysbios_knl_Swi_Module__loggerDefined__C, ".econst:ti_sysbios_knl_Swi_Module__loggerDefined__C");
asm("	.sect \".econst:ti_sysbios_knl_Swi_Module__loggerDefined__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Swi_Module__loggerDefined__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Swi_Module__loggerDefined__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Swi_Module__loggerDefined ti_sysbios_knl_Swi_Module__loggerDefined__C = 1;

/* Module__loggerObj__C */
#pragma DATA_SECTION(ti_sysbios_knl_Swi_Module__loggerObj__C, ".econst:ti_sysbios_knl_Swi_Module__loggerObj__C");
asm("	.sect \".econst:ti_sysbios_knl_Swi_Module__loggerObj__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Swi_Module__loggerObj__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Swi_Module__loggerObj__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Swi_Module__loggerObj ti_sysbios_knl_Swi_Module__loggerObj__C = ((const CT__ti_sysbios_knl_Swi_Module__loggerObj)((void*)(xdc_runtime_ILogger_Handle)&xdc_runtime_LoggerBuf_Object__table__V[0]));

/* Module__loggerFxn0__C */
#pragma DATA_SECTION(ti_sysbios_knl_Swi_Module__loggerFxn0__C, ".econst:ti_sysbios_knl_Swi_Module__loggerFxn0__C");
asm("	.sect \".econst:ti_sysbios_knl_Swi_Module__loggerFxn0__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Swi_Module__loggerFxn0__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Swi_Module__loggerFxn0__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Swi_Module__loggerFxn0 ti_sysbios_knl_Swi_Module__loggerFxn0__C = ((const CT__ti_sysbios_knl_Swi_Module__loggerFxn0)(xdc_runtime_LoggerBuf_write0));

/* Module__loggerFxn1__C */
#pragma DATA_SECTION(ti_sysbios_knl_Swi_Module__loggerFxn1__C, ".econst:ti_sysbios_knl_Swi_Module__loggerFxn1__C");
asm("	.sect \".econst:ti_sysbios_knl_Swi_Module__loggerFxn1__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Swi_Module__loggerFxn1__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Swi_Module__loggerFxn1__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Swi_Module__loggerFxn1 ti_sysbios_knl_Swi_Module__loggerFxn1__C = ((const CT__ti_sysbios_knl_Swi_Module__loggerFxn1)(xdc_runtime_LoggerBuf_write1));

/* Module__loggerFxn2__C */
#pragma DATA_SECTION(ti_sysbios_knl_Swi_Module__loggerFxn2__C, ".econst:ti_sysbios_knl_Swi_Module__loggerFxn2__C");
asm("	.sect \".econst:ti_sysbios_knl_Swi_Module__loggerFxn2__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Swi_Module__loggerFxn2__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Swi_Module__loggerFxn2__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Swi_Module__loggerFxn2 ti_sysbios_knl_Swi_Module__loggerFxn2__C = ((const CT__ti_sysbios_knl_Swi_Module__loggerFxn2)(xdc_runtime_LoggerBuf_write2));

/* Module__loggerFxn4__C */
#pragma DATA_SECTION(ti_sysbios_knl_Swi_Module__loggerFxn4__C, ".econst:ti_sysbios_knl_Swi_Module__loggerFxn4__C");
asm("	.sect \".econst:ti_sysbios_knl_Swi_Module__loggerFxn4__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Swi_Module__loggerFxn4__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Swi_Module__loggerFxn4__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Swi_Module__loggerFxn4 ti_sysbios_knl_Swi_Module__loggerFxn4__C = ((const CT__ti_sysbios_knl_Swi_Module__loggerFxn4)(xdc_runtime_LoggerBuf_write4));

/* Module__loggerFxn8__C */
#pragma DATA_SECTION(ti_sysbios_knl_Swi_Module__loggerFxn8__C, ".econst:ti_sysbios_knl_Swi_Module__loggerFxn8__C");
asm("	.sect \".econst:ti_sysbios_knl_Swi_Module__loggerFxn8__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Swi_Module__loggerFxn8__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Swi_Module__loggerFxn8__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Swi_Module__loggerFxn8 ti_sysbios_knl_Swi_Module__loggerFxn8__C = ((const CT__ti_sysbios_knl_Swi_Module__loggerFxn8)(xdc_runtime_LoggerBuf_write8));

/* Object__count__C */
#pragma DATA_SECTION(ti_sysbios_knl_Swi_Object__count__C, ".econst:ti_sysbios_knl_Swi_Object__count__C");
asm("	.sect \".econst:ti_sysbios_knl_Swi_Object__count__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Swi_Object__count__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Swi_Object__count__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Swi_Object__count ti_sysbios_knl_Swi_Object__count__C = 1;

/* Object__heap__C */
#pragma DATA_SECTION(ti_sysbios_knl_Swi_Object__heap__C, ".econst:ti_sysbios_knl_Swi_Object__heap__C");
asm("	.sect \".econst:ti_sysbios_knl_Swi_Object__heap__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Swi_Object__heap__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Swi_Object__heap__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Swi_Object__heap ti_sysbios_knl_Swi_Object__heap__C = NULL;

/* Object__sizeof__C */
#pragma DATA_SECTION(ti_sysbios_knl_Swi_Object__sizeof__C, ".econst:ti_sysbios_knl_Swi_Object__sizeof__C");
asm("	.sect \".econst:ti_sysbios_knl_Swi_Object__sizeof__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Swi_Object__sizeof__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Swi_Object__sizeof__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Swi_Object__sizeof ti_sysbios_knl_Swi_Object__sizeof__C = sizeof(ti_sysbios_knl_Swi_Object__);

/* Object__table__C */
#pragma DATA_SECTION(ti_sysbios_knl_Swi_Object__table__C, ".econst:ti_sysbios_knl_Swi_Object__table__C");
asm("	.sect \".econst:ti_sysbios_knl_Swi_Object__table__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Swi_Object__table__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Swi_Object__table__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Swi_Object__table ti_sysbios_knl_Swi_Object__table__C = ti_sysbios_knl_Swi_Object__table__V;

/* LM_begin__C */
#pragma DATA_SECTION(ti_sysbios_knl_Swi_LM_begin__C, ".econst:ti_sysbios_knl_Swi_LM_begin__C");
asm("	.sect \".econst:ti_sysbios_knl_Swi_LM_begin__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Swi_LM_begin__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Swi_LM_begin__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Swi_LM_begin ti_sysbios_knl_Swi_LM_begin__C = (((xdc_runtime_Log_Event)5034) << 16 | 768);

/* LD_end__C */
#pragma DATA_SECTION(ti_sysbios_knl_Swi_LD_end__C, ".econst:ti_sysbios_knl_Swi_LD_end__C");
asm("	.sect \".econst:ti_sysbios_knl_Swi_LD_end__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Swi_LD_end__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Swi_LD_end__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Swi_LD_end ti_sysbios_knl_Swi_LD_end__C = (((xdc_runtime_Log_Event)5081) << 16 | 512);

/* LM_post__C */
#pragma DATA_SECTION(ti_sysbios_knl_Swi_LM_post__C, ".econst:ti_sysbios_knl_Swi_LM_post__C");
asm("	.sect \".econst:ti_sysbios_knl_Swi_LM_post__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Swi_LM_post__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Swi_LM_post__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Swi_LM_post ti_sysbios_knl_Swi_LM_post__C = (((xdc_runtime_Log_Event)5099) << 16 | 768);

/* A_swiDisabled__C */
#pragma DATA_SECTION(ti_sysbios_knl_Swi_A_swiDisabled__C, ".econst:ti_sysbios_knl_Swi_A_swiDisabled__C");
asm("	.sect \".econst:ti_sysbios_knl_Swi_A_swiDisabled__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Swi_A_swiDisabled__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Swi_A_swiDisabled__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Swi_A_swiDisabled ti_sysbios_knl_Swi_A_swiDisabled__C = (((xdc_runtime_Assert_Id)1465) << 16 | 16);

/* A_badPriority__C */
#pragma DATA_SECTION(ti_sysbios_knl_Swi_A_badPriority__C, ".econst:ti_sysbios_knl_Swi_A_badPriority__C");
asm("	.sect \".econst:ti_sysbios_knl_Swi_A_badPriority__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Swi_A_badPriority__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Swi_A_badPriority__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Swi_A_badPriority ti_sysbios_knl_Swi_A_badPriority__C = (((xdc_runtime_Assert_Id)1522) << 16 | 16);

/* numPriorities__C */
#pragma DATA_SECTION(ti_sysbios_knl_Swi_numPriorities__C, ".econst:ti_sysbios_knl_Swi_numPriorities__C");
asm("	.sect \".econst:ti_sysbios_knl_Swi_numPriorities__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Swi_numPriorities__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Swi_numPriorities__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Swi_numPriorities ti_sysbios_knl_Swi_numPriorities__C = (xdc_UInt)0x10;

/* hooks__C */
#pragma DATA_SECTION(ti_sysbios_knl_Swi_hooks__C, ".econst:ti_sysbios_knl_Swi_hooks__C");
asm("	.sect \".econst:ti_sysbios_knl_Swi_hooks__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Swi_hooks__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Swi_hooks__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Swi_hooks ti_sysbios_knl_Swi_hooks__C = {0, 0};

/* taskDisable__C */
#pragma DATA_SECTION(ti_sysbios_knl_Swi_taskDisable__C, ".econst:ti_sysbios_knl_Swi_taskDisable__C");
asm("	.sect \".econst:ti_sysbios_knl_Swi_taskDisable__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Swi_taskDisable__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Swi_taskDisable__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Swi_taskDisable ti_sysbios_knl_Swi_taskDisable__C = ((const CT__ti_sysbios_knl_Swi_taskDisable)(ti_sysbios_knl_Task_disable__E));

/* taskRestore__C */
#pragma DATA_SECTION(ti_sysbios_knl_Swi_taskRestore__C, ".econst:ti_sysbios_knl_Swi_taskRestore__C");
asm("	.sect \".econst:ti_sysbios_knl_Swi_taskRestore__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Swi_taskRestore__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Swi_taskRestore__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Swi_taskRestore ti_sysbios_knl_Swi_taskRestore__C = ((const CT__ti_sysbios_knl_Swi_taskRestore)(ti_sysbios_knl_Task_restore__E));

/* numConstructedSwis__C */
#pragma DATA_SECTION(ti_sysbios_knl_Swi_numConstructedSwis__C, ".econst:ti_sysbios_knl_Swi_numConstructedSwis__C");
asm("	.sect \".econst:ti_sysbios_knl_Swi_numConstructedSwis__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Swi_numConstructedSwis__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Swi_numConstructedSwis__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Swi_numConstructedSwis ti_sysbios_knl_Swi_numConstructedSwis__C = (xdc_UInt)0x0;


/*
 * ======== ti.sysbios.knl.Task INITIALIZERS ========
 */

/* Object__DESC__C */
__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_knl_Task_Object__DESC__C;

/* Object__PARAMS__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_Object__PARAMS__C, ".econst:ti_sysbios_knl_Task_Object__PARAMS__C");
asm("	.sect \".econst:ti_sysbios_knl_Task_Object__PARAMS__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Task_Object__PARAMS__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Task_Object__PARAMS__C\"");
asm("	.clink ");

__FAR__ const ti_sysbios_knl_Task_Params ti_sysbios_knl_Task_Object__PARAMS__C = {
    sizeof (ti_sysbios_knl_Task_Params), /* __size */
    NULL, /* __self */
    NULL, /* __fxns */
    (xdc_runtime_IInstance_Params*)&ti_sysbios_knl_Task_Object__PARAMS__C.__iprms, /* instance */
    ((xdc_UArg)(0x0)),  /* arg0 */
    ((xdc_UArg)(0x0)),  /* arg1 */
    (xdc_Int)0x1,  /* priority */
    ((xdc_Ptr)NULL),  /* stack */
    (xdc_SizeT)0x0,  /* stackSize */
    0,  /* stackHeap */
    ((xdc_Ptr)NULL),  /* env */
    1,  /* vitalTaskFlag */
    (xdc_UInt)0x0,  /* affinity */
    1,  /* privileged */
    ((xdc_Ptr)NULL),  /* domain */
    {
        sizeof (xdc_runtime_IInstance_Params), /* __size */
        0,  /* name */
    },  /* instance */
};

/* --> ti_sysbios_knl_Task_Instance_State_0_stack__A */
__T1_ti_sysbios_knl_Task_Instance_State__stack ti_sysbios_knl_Task_Instance_State_0_stack__A[256];

/* Module__root__V */
ti_sysbios_knl_Task_Module__ ti_sysbios_knl_Task_Module__root__V = {
    {&ti_sysbios_knl_Task_Module__root__V.link,  /* link.next */
    &ti_sysbios_knl_Task_Module__root__V.link},  /* link.prev */
};

/* Object__table__V */
ti_sysbios_knl_Task_Object__ ti_sysbios_knl_Task_Object__table__V[1] = {
    {/* instance#0 */
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Object__table__V[0].qElem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Object__table__V[0].qElem)),  /* prev */
        },  /* qElem */
        (xdc_Int)0x0,  /* priority */
        (xdc_UInt)0x1,  /* mask */
        ((xdc_Ptr)NULL),  /* context */
        ti_sysbios_knl_Task_Mode_INACTIVE,  /* mode */
        ((ti_sysbios_knl_Task_PendElem*)NULL),  /* pendElem */
        (xdc_SizeT)0x100,  /* stackSize */
        ((void*)ti_sysbios_knl_Task_Instance_State_0_stack__A),  /* stack */
        0,  /* stackHeap */
        ((xdc_Void(*)(xdc_UArg f_arg0,xdc_UArg f_arg1))(ti_sysbios_knl_Idle_loop__E)),  /* fxn */
        ((xdc_UArg)(0x0)),  /* arg0 */
        ((xdc_UArg)(0x0)),  /* arg1 */
        ((xdc_Ptr)NULL),  /* env */
        ((void*)0),  /* hookEnv */
        1,  /* vitalTaskFlag */
        0,  /* readyQ */
        (xdc_UInt)0x0,  /* curCoreId */
        (xdc_UInt)0x0,  /* affinity */
        1,  /* privileged */
        ((xdc_Ptr)NULL),  /* domain */
        (xdc_UInt32)0x0,  /* checkValue */
        ((xdc_Ptr)NULL),  /* tls */
    },
};

/* --> ti_sysbios_knl_Task_Module_State_0_readyQ__A */
__T1_ti_sysbios_knl_Task_Module_State__readyQ ti_sysbios_knl_Task_Module_State_0_readyQ__A[16] = {
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[0].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[0].elem)),  /* prev */
        },  /* elem */
    },  /* [0] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[1].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[1].elem)),  /* prev */
        },  /* elem */
    },  /* [1] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[2].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[2].elem)),  /* prev */
        },  /* elem */
    },  /* [2] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[3].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[3].elem)),  /* prev */
        },  /* elem */
    },  /* [3] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[4].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[4].elem)),  /* prev */
        },  /* elem */
    },  /* [4] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[5].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[5].elem)),  /* prev */
        },  /* elem */
    },  /* [5] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[6].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[6].elem)),  /* prev */
        },  /* elem */
    },  /* [6] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[7].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[7].elem)),  /* prev */
        },  /* elem */
    },  /* [7] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[8].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[8].elem)),  /* prev */
        },  /* elem */
    },  /* [8] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[9].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[9].elem)),  /* prev */
        },  /* elem */
    },  /* [9] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[10].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[10].elem)),  /* prev */
        },  /* elem */
    },  /* [10] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[11].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[11].elem)),  /* prev */
        },  /* elem */
    },  /* [11] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[12].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[12].elem)),  /* prev */
        },  /* elem */
    },  /* [12] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[13].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[13].elem)),  /* prev */
        },  /* elem */
    },  /* [13] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[14].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[14].elem)),  /* prev */
        },  /* elem */
    },  /* [14] */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[15].elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module_State_0_readyQ__A[15].elem)),  /* prev */
        },  /* elem */
    },  /* [15] */
};

/* --> ti_sysbios_knl_Task_Module_State_0_idleTask__A */
__T1_ti_sysbios_knl_Task_Module_State__idleTask ti_sysbios_knl_Task_Module_State_0_idleTask__A[1] = {
    (ti_sysbios_knl_Task_Handle)&ti_sysbios_knl_Task_Object__table__V[0],  /* [0] */
};

/* Module__state__V */
#if defined (__ICCARM__)
#pragma location = ".data_ti_sysbios_knl_Task_Module__state__V"
#endif
#if defined(__GNUC__) && !(defined(__MACH__) && defined(__APPLE__))
#ifndef __ti__
ti_sysbios_knl_Task_Module_State__ ti_sysbios_knl_Task_Module__state__V __attribute__ ((section(".data_ti_sysbios_knl_Task_Module__state__V")));
#elif defined(__clang__)
ti_sysbios_knl_Task_Module_State__ ti_sysbios_knl_Task_Module__state__V __attribute__ ((section(".data:ti_sysbios_knl_Task_Module__state__V")));
#endif
#endif
ti_sysbios_knl_Task_Module_State__ ti_sysbios_knl_Task_Module__state__V = {
    1,  /* locked */
    (xdc_UInt)0x0,  /* curSet */
    0,  /* workFlag */
    (xdc_UInt)0x1,  /* vitalTasks */
    0,  /* curTask */
    0,  /* curQ */
    ((void*)ti_sysbios_knl_Task_Module_State_0_readyQ__A),  /* readyQ */
    ((void*)0),  /* smpCurSet */
    ((void*)0),  /* smpCurMask */
    ((void*)0),  /* smpCurTask */
    ((void*)0),  /* smpReadyQ */
    ((void*)ti_sysbios_knl_Task_Module_State_0_idleTask__A),  /* idleTask */
    ((void*)0),  /* constructedTasks */
    1,  /* curTaskPrivileged */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module__state__V.Object_field_inactiveQ.elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module__state__V.Object_field_inactiveQ.elem)),  /* prev */
        },  /* elem */
    },  /* Object_field_inactiveQ */
    {
        {
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module__state__V.Object_field_terminatedQ.elem)),  /* next */
            ((ti_sysbios_knl_Queue_Elem*)((void*)&ti_sysbios_knl_Task_Module__state__V.Object_field_terminatedQ.elem)),  /* prev */
        },  /* elem */
    },  /* Object_field_terminatedQ */
};

/* Module__diagsEnabled__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_Module__diagsEnabled__C, ".econst:ti_sysbios_knl_Task_Module__diagsEnabled__C");
asm("	.sect \".econst:ti_sysbios_knl_Task_Module__diagsEnabled__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Task_Module__diagsEnabled__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Task_Module__diagsEnabled__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Task_Module__diagsEnabled ti_sysbios_knl_Task_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_Module__diagsIncluded__C, ".econst:ti_sysbios_knl_Task_Module__diagsIncluded__C");
asm("	.sect \".econst:ti_sysbios_knl_Task_Module__diagsIncluded__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Task_Module__diagsIncluded__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Task_Module__diagsIncluded__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Task_Module__diagsIncluded ti_sysbios_knl_Task_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_Module__diagsMask__C, ".econst:ti_sysbios_knl_Task_Module__diagsMask__C");
asm("	.sect \".econst:ti_sysbios_knl_Task_Module__diagsMask__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Task_Module__diagsMask__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Task_Module__diagsMask__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Task_Module__diagsMask ti_sysbios_knl_Task_Module__diagsMask__C = ((const CT__ti_sysbios_knl_Task_Module__diagsMask)NULL);

/* Module__gateObj__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_Module__gateObj__C, ".econst:ti_sysbios_knl_Task_Module__gateObj__C");
asm("	.sect \".econst:ti_sysbios_knl_Task_Module__gateObj__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Task_Module__gateObj__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Task_Module__gateObj__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Task_Module__gateObj ti_sysbios_knl_Task_Module__gateObj__C = ((const CT__ti_sysbios_knl_Task_Module__gateObj)NULL);

/* Module__gatePrms__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_Module__gatePrms__C, ".econst:ti_sysbios_knl_Task_Module__gatePrms__C");
asm("	.sect \".econst:ti_sysbios_knl_Task_Module__gatePrms__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Task_Module__gatePrms__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Task_Module__gatePrms__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Task_Module__gatePrms ti_sysbios_knl_Task_Module__gatePrms__C = ((const CT__ti_sysbios_knl_Task_Module__gatePrms)NULL);

/* Module__id__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_Module__id__C, ".econst:ti_sysbios_knl_Task_Module__id__C");
asm("	.sect \".econst:ti_sysbios_knl_Task_Module__id__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Task_Module__id__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Task_Module__id__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Task_Module__id ti_sysbios_knl_Task_Module__id__C = (xdc_Bits16)0x8021;

/* Module__loggerDefined__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_Module__loggerDefined__C, ".econst:ti_sysbios_knl_Task_Module__loggerDefined__C");
asm("	.sect \".econst:ti_sysbios_knl_Task_Module__loggerDefined__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Task_Module__loggerDefined__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Task_Module__loggerDefined__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Task_Module__loggerDefined ti_sysbios_knl_Task_Module__loggerDefined__C = 1;

/* Module__loggerObj__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_Module__loggerObj__C, ".econst:ti_sysbios_knl_Task_Module__loggerObj__C");
asm("	.sect \".econst:ti_sysbios_knl_Task_Module__loggerObj__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Task_Module__loggerObj__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Task_Module__loggerObj__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Task_Module__loggerObj ti_sysbios_knl_Task_Module__loggerObj__C = ((const CT__ti_sysbios_knl_Task_Module__loggerObj)((void*)(xdc_runtime_ILogger_Handle)&xdc_runtime_LoggerBuf_Object__table__V[0]));

/* Module__loggerFxn0__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_Module__loggerFxn0__C, ".econst:ti_sysbios_knl_Task_Module__loggerFxn0__C");
asm("	.sect \".econst:ti_sysbios_knl_Task_Module__loggerFxn0__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Task_Module__loggerFxn0__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Task_Module__loggerFxn0__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Task_Module__loggerFxn0 ti_sysbios_knl_Task_Module__loggerFxn0__C = ((const CT__ti_sysbios_knl_Task_Module__loggerFxn0)(xdc_runtime_LoggerBuf_write0));

/* Module__loggerFxn1__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_Module__loggerFxn1__C, ".econst:ti_sysbios_knl_Task_Module__loggerFxn1__C");
asm("	.sect \".econst:ti_sysbios_knl_Task_Module__loggerFxn1__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Task_Module__loggerFxn1__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Task_Module__loggerFxn1__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Task_Module__loggerFxn1 ti_sysbios_knl_Task_Module__loggerFxn1__C = ((const CT__ti_sysbios_knl_Task_Module__loggerFxn1)(xdc_runtime_LoggerBuf_write1));

/* Module__loggerFxn2__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_Module__loggerFxn2__C, ".econst:ti_sysbios_knl_Task_Module__loggerFxn2__C");
asm("	.sect \".econst:ti_sysbios_knl_Task_Module__loggerFxn2__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Task_Module__loggerFxn2__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Task_Module__loggerFxn2__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Task_Module__loggerFxn2 ti_sysbios_knl_Task_Module__loggerFxn2__C = ((const CT__ti_sysbios_knl_Task_Module__loggerFxn2)(xdc_runtime_LoggerBuf_write2));

/* Module__loggerFxn4__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_Module__loggerFxn4__C, ".econst:ti_sysbios_knl_Task_Module__loggerFxn4__C");
asm("	.sect \".econst:ti_sysbios_knl_Task_Module__loggerFxn4__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Task_Module__loggerFxn4__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Task_Module__loggerFxn4__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Task_Module__loggerFxn4 ti_sysbios_knl_Task_Module__loggerFxn4__C = ((const CT__ti_sysbios_knl_Task_Module__loggerFxn4)(xdc_runtime_LoggerBuf_write4));

/* Module__loggerFxn8__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_Module__loggerFxn8__C, ".econst:ti_sysbios_knl_Task_Module__loggerFxn8__C");
asm("	.sect \".econst:ti_sysbios_knl_Task_Module__loggerFxn8__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Task_Module__loggerFxn8__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Task_Module__loggerFxn8__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Task_Module__loggerFxn8 ti_sysbios_knl_Task_Module__loggerFxn8__C = ((const CT__ti_sysbios_knl_Task_Module__loggerFxn8)(xdc_runtime_LoggerBuf_write8));

/* Object__count__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_Object__count__C, ".econst:ti_sysbios_knl_Task_Object__count__C");
asm("	.sect \".econst:ti_sysbios_knl_Task_Object__count__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Task_Object__count__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Task_Object__count__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Task_Object__count ti_sysbios_knl_Task_Object__count__C = 1;

/* Object__heap__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_Object__heap__C, ".econst:ti_sysbios_knl_Task_Object__heap__C");
asm("	.sect \".econst:ti_sysbios_knl_Task_Object__heap__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Task_Object__heap__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Task_Object__heap__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Task_Object__heap ti_sysbios_knl_Task_Object__heap__C = NULL;

/* Object__sizeof__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_Object__sizeof__C, ".econst:ti_sysbios_knl_Task_Object__sizeof__C");
asm("	.sect \".econst:ti_sysbios_knl_Task_Object__sizeof__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Task_Object__sizeof__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Task_Object__sizeof__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Task_Object__sizeof ti_sysbios_knl_Task_Object__sizeof__C = sizeof(ti_sysbios_knl_Task_Object__);

/* Object__table__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_Object__table__C, ".econst:ti_sysbios_knl_Task_Object__table__C");
asm("	.sect \".econst:ti_sysbios_knl_Task_Object__table__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Task_Object__table__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Task_Object__table__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Task_Object__table ti_sysbios_knl_Task_Object__table__C = ti_sysbios_knl_Task_Object__table__V;

/* LM_switch__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_LM_switch__C, ".econst:ti_sysbios_knl_Task_LM_switch__C");
asm("	.sect \".econst:ti_sysbios_knl_Task_LM_switch__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Task_LM_switch__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Task_LM_switch__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Task_LM_switch ti_sysbios_knl_Task_LM_switch__C = (((xdc_runtime_Log_Event)5139) << 16 | 768);

/* LM_sleep__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_LM_sleep__C, ".econst:ti_sysbios_knl_Task_LM_sleep__C");
asm("	.sect \".econst:ti_sysbios_knl_Task_LM_sleep__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Task_LM_sleep__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Task_LM_sleep__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Task_LM_sleep ti_sysbios_knl_Task_LM_sleep__C = (((xdc_runtime_Log_Event)5207) << 16 | 768);

/* LD_ready__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_LD_ready__C, ".econst:ti_sysbios_knl_Task_LD_ready__C");
asm("	.sect \".econst:ti_sysbios_knl_Task_LD_ready__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Task_LD_ready__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Task_LD_ready__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Task_LD_ready ti_sysbios_knl_Task_LD_ready__C = (((xdc_runtime_Log_Event)5252) << 16 | 512);

/* LD_block__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_LD_block__C, ".econst:ti_sysbios_knl_Task_LD_block__C");
asm("	.sect \".econst:ti_sysbios_knl_Task_LD_block__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Task_LD_block__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Task_LD_block__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Task_LD_block ti_sysbios_knl_Task_LD_block__C = (((xdc_runtime_Log_Event)5293) << 16 | 512);

/* LM_yield__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_LM_yield__C, ".econst:ti_sysbios_knl_Task_LM_yield__C");
asm("	.sect \".econst:ti_sysbios_knl_Task_LM_yield__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Task_LM_yield__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Task_LM_yield__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Task_LM_yield ti_sysbios_knl_Task_LM_yield__C = (((xdc_runtime_Log_Event)5325) << 16 | 768);

/* LM_setPri__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_LM_setPri__C, ".econst:ti_sysbios_knl_Task_LM_setPri__C");
asm("	.sect \".econst:ti_sysbios_knl_Task_LM_setPri__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Task_LM_setPri__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Task_LM_setPri__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Task_LM_setPri ti_sysbios_knl_Task_LM_setPri__C = (((xdc_runtime_Log_Event)5373) << 16 | 768);

/* LD_exit__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_LD_exit__C, ".econst:ti_sysbios_knl_Task_LD_exit__C");
asm("	.sect \".econst:ti_sysbios_knl_Task_LD_exit__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Task_LD_exit__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Task_LD_exit__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Task_LD_exit ti_sysbios_knl_Task_LD_exit__C = (((xdc_runtime_Log_Event)5429) << 16 | 512);

/* LM_setAffinity__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_LM_setAffinity__C, ".econst:ti_sysbios_knl_Task_LM_setAffinity__C");
asm("	.sect \".econst:ti_sysbios_knl_Task_LM_setAffinity__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Task_LM_setAffinity__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Task_LM_setAffinity__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Task_LM_setAffinity ti_sysbios_knl_Task_LM_setAffinity__C = (((xdc_runtime_Log_Event)5460) << 16 | 768);

/* LM_schedule__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_LM_schedule__C, ".econst:ti_sysbios_knl_Task_LM_schedule__C");
asm("	.sect \".econst:ti_sysbios_knl_Task_LM_schedule__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Task_LM_schedule__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Task_LM_schedule__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Task_LM_schedule ti_sysbios_knl_Task_LM_schedule__C = (((xdc_runtime_Log_Event)5543) << 16 | 1024);

/* LM_noWork__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_LM_noWork__C, ".econst:ti_sysbios_knl_Task_LM_noWork__C");
asm("	.sect \".econst:ti_sysbios_knl_Task_LM_noWork__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Task_LM_noWork__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Task_LM_noWork__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Task_LM_noWork ti_sysbios_knl_Task_LM_noWork__C = (((xdc_runtime_Log_Event)5629) << 16 | 1024);

/* E_stackOverflow__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_E_stackOverflow__C, ".econst:ti_sysbios_knl_Task_E_stackOverflow__C");
asm("	.sect \".econst:ti_sysbios_knl_Task_E_stackOverflow__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Task_E_stackOverflow__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Task_E_stackOverflow__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Task_E_stackOverflow ti_sysbios_knl_Task_E_stackOverflow__C = (((xdc_runtime_Error_Id)4123) << 16 | 0U);

/* E_spOutOfBounds__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_E_spOutOfBounds__C, ".econst:ti_sysbios_knl_Task_E_spOutOfBounds__C");
asm("	.sect \".econst:ti_sysbios_knl_Task_E_spOutOfBounds__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Task_E_spOutOfBounds__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Task_E_spOutOfBounds__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Task_E_spOutOfBounds ti_sysbios_knl_Task_E_spOutOfBounds__C = (((xdc_runtime_Error_Id)4166) << 16 | 0U);

/* E_deleteNotAllowed__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_E_deleteNotAllowed__C, ".econst:ti_sysbios_knl_Task_E_deleteNotAllowed__C");
asm("	.sect \".econst:ti_sysbios_knl_Task_E_deleteNotAllowed__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Task_E_deleteNotAllowed__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Task_E_deleteNotAllowed__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Task_E_deleteNotAllowed ti_sysbios_knl_Task_E_deleteNotAllowed__C = (((xdc_runtime_Error_Id)4217) << 16 | 0U);

/* E_moduleStateCheckFailed__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_E_moduleStateCheckFailed__C, ".econst:ti_sysbios_knl_Task_E_moduleStateCheckFailed__C");
asm("	.sect \".econst:ti_sysbios_knl_Task_E_moduleStateCheckFailed__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Task_E_moduleStateCheckFailed__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Task_E_moduleStateCheckFailed__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Task_E_moduleStateCheckFailed ti_sysbios_knl_Task_E_moduleStateCheckFailed__C = (((xdc_runtime_Error_Id)4248) << 16 | 0U);

/* E_objectCheckFailed__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_E_objectCheckFailed__C, ".econst:ti_sysbios_knl_Task_E_objectCheckFailed__C");
asm("	.sect \".econst:ti_sysbios_knl_Task_E_objectCheckFailed__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Task_E_objectCheckFailed__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Task_E_objectCheckFailed__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Task_E_objectCheckFailed ti_sysbios_knl_Task_E_objectCheckFailed__C = (((xdc_runtime_Error_Id)4321) << 16 | 0U);

/* E_objectNotInKernelSpace__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_E_objectNotInKernelSpace__C, ".econst:ti_sysbios_knl_Task_E_objectNotInKernelSpace__C");
asm("	.sect \".econst:ti_sysbios_knl_Task_E_objectNotInKernelSpace__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Task_E_objectNotInKernelSpace__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Task_E_objectNotInKernelSpace__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Task_E_objectNotInKernelSpace ti_sysbios_knl_Task_E_objectNotInKernelSpace__C = (((xdc_runtime_Error_Id)4388) << 16 | 0U);

/* A_badThreadType__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_A_badThreadType__C, ".econst:ti_sysbios_knl_Task_A_badThreadType__C");
asm("	.sect \".econst:ti_sysbios_knl_Task_A_badThreadType__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Task_A_badThreadType__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Task_A_badThreadType__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Task_A_badThreadType ti_sysbios_knl_Task_A_badThreadType__C = (((xdc_runtime_Assert_Id)1571) << 16 | 16);

/* A_badTaskState__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_A_badTaskState__C, ".econst:ti_sysbios_knl_Task_A_badTaskState__C");
asm("	.sect \".econst:ti_sysbios_knl_Task_A_badTaskState__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Task_A_badTaskState__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Task_A_badTaskState__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Task_A_badTaskState ti_sysbios_knl_Task_A_badTaskState__C = (((xdc_runtime_Assert_Id)1640) << 16 | 16);

/* A_noPendElem__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_A_noPendElem__C, ".econst:ti_sysbios_knl_Task_A_noPendElem__C");
asm("	.sect \".econst:ti_sysbios_knl_Task_A_noPendElem__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Task_A_noPendElem__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Task_A_noPendElem__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Task_A_noPendElem ti_sysbios_knl_Task_A_noPendElem__C = (((xdc_runtime_Assert_Id)1694) << 16 | 16);

/* A_taskDisabled__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_A_taskDisabled__C, ".econst:ti_sysbios_knl_Task_A_taskDisabled__C");
asm("	.sect \".econst:ti_sysbios_knl_Task_A_taskDisabled__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Task_A_taskDisabled__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Task_A_taskDisabled__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Task_A_taskDisabled ti_sysbios_knl_Task_A_taskDisabled__C = (((xdc_runtime_Assert_Id)1748) << 16 | 16);

/* A_badPriority__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_A_badPriority__C, ".econst:ti_sysbios_knl_Task_A_badPriority__C");
asm("	.sect \".econst:ti_sysbios_knl_Task_A_badPriority__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Task_A_badPriority__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Task_A_badPriority__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Task_A_badPriority ti_sysbios_knl_Task_A_badPriority__C = (((xdc_runtime_Assert_Id)1811) << 16 | 16);

/* A_badTimeout__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_A_badTimeout__C, ".econst:ti_sysbios_knl_Task_A_badTimeout__C");
asm("	.sect \".econst:ti_sysbios_knl_Task_A_badTimeout__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Task_A_badTimeout__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Task_A_badTimeout__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Task_A_badTimeout ti_sysbios_knl_Task_A_badTimeout__C = (((xdc_runtime_Assert_Id)1861) << 16 | 16);

/* A_badAffinity__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_A_badAffinity__C, ".econst:ti_sysbios_knl_Task_A_badAffinity__C");
asm("	.sect \".econst:ti_sysbios_knl_Task_A_badAffinity__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Task_A_badAffinity__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Task_A_badAffinity__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Task_A_badAffinity ti_sysbios_knl_Task_A_badAffinity__C = (((xdc_runtime_Assert_Id)1896) << 16 | 16);

/* A_sleepTaskDisabled__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_A_sleepTaskDisabled__C, ".econst:ti_sysbios_knl_Task_A_sleepTaskDisabled__C");
asm("	.sect \".econst:ti_sysbios_knl_Task_A_sleepTaskDisabled__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Task_A_sleepTaskDisabled__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Task_A_sleepTaskDisabled__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Task_A_sleepTaskDisabled ti_sysbios_knl_Task_A_sleepTaskDisabled__C = (((xdc_runtime_Assert_Id)1929) << 16 | 16);

/* A_invalidCoreId__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_A_invalidCoreId__C, ".econst:ti_sysbios_knl_Task_A_invalidCoreId__C");
asm("	.sect \".econst:ti_sysbios_knl_Task_A_invalidCoreId__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Task_A_invalidCoreId__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Task_A_invalidCoreId__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Task_A_invalidCoreId ti_sysbios_knl_Task_A_invalidCoreId__C = (((xdc_runtime_Assert_Id)2013) << 16 | 16);

/* numPriorities__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_numPriorities__C, ".econst:ti_sysbios_knl_Task_numPriorities__C");
asm("	.sect \".econst:ti_sysbios_knl_Task_numPriorities__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Task_numPriorities__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Task_numPriorities__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Task_numPriorities ti_sysbios_knl_Task_numPriorities__C = (xdc_UInt)0x10;

/* defaultStackSize__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_defaultStackSize__C, ".econst:ti_sysbios_knl_Task_defaultStackSize__C");
asm("	.sect \".econst:ti_sysbios_knl_Task_defaultStackSize__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Task_defaultStackSize__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Task_defaultStackSize__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Task_defaultStackSize ti_sysbios_knl_Task_defaultStackSize__C = (xdc_SizeT)0x100;

/* defaultStackHeap__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_defaultStackHeap__C, ".econst:ti_sysbios_knl_Task_defaultStackHeap__C");
asm("	.sect \".econst:ti_sysbios_knl_Task_defaultStackHeap__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Task_defaultStackHeap__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Task_defaultStackHeap__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Task_defaultStackHeap ti_sysbios_knl_Task_defaultStackHeap__C = 0;

/* allBlockedFunc__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_allBlockedFunc__C, ".econst:ti_sysbios_knl_Task_allBlockedFunc__C");
asm("	.sect \".econst:ti_sysbios_knl_Task_allBlockedFunc__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Task_allBlockedFunc__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Task_allBlockedFunc__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Task_allBlockedFunc ti_sysbios_knl_Task_allBlockedFunc__C = ((const CT__ti_sysbios_knl_Task_allBlockedFunc)NULL);

/* initStackFlag__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_initStackFlag__C, ".econst:ti_sysbios_knl_Task_initStackFlag__C");
asm("	.sect \".econst:ti_sysbios_knl_Task_initStackFlag__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Task_initStackFlag__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Task_initStackFlag__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Task_initStackFlag ti_sysbios_knl_Task_initStackFlag__C = 1;

/* checkStackFlag__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_checkStackFlag__C, ".econst:ti_sysbios_knl_Task_checkStackFlag__C");
asm("	.sect \".econst:ti_sysbios_knl_Task_checkStackFlag__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Task_checkStackFlag__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Task_checkStackFlag__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Task_checkStackFlag ti_sysbios_knl_Task_checkStackFlag__C = 1;

/* deleteTerminatedTasks__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_deleteTerminatedTasks__C, ".econst:ti_sysbios_knl_Task_deleteTerminatedTasks__C");
asm("	.sect \".econst:ti_sysbios_knl_Task_deleteTerminatedTasks__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Task_deleteTerminatedTasks__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Task_deleteTerminatedTasks__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Task_deleteTerminatedTasks ti_sysbios_knl_Task_deleteTerminatedTasks__C = 0;

/* hooks__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_hooks__C, ".econst:ti_sysbios_knl_Task_hooks__C");
asm("	.sect \".econst:ti_sysbios_knl_Task_hooks__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Task_hooks__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Task_hooks__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Task_hooks ti_sysbios_knl_Task_hooks__C = {0, 0};

/* moduleStateCheckFxn__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_moduleStateCheckFxn__C, ".econst:ti_sysbios_knl_Task_moduleStateCheckFxn__C");
asm("	.sect \".econst:ti_sysbios_knl_Task_moduleStateCheckFxn__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Task_moduleStateCheckFxn__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Task_moduleStateCheckFxn__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Task_moduleStateCheckFxn ti_sysbios_knl_Task_moduleStateCheckFxn__C = ((const CT__ti_sysbios_knl_Task_moduleStateCheckFxn)(ti_sysbios_knl_Task_moduleStateCheck__I));

/* moduleStateCheckValueFxn__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_moduleStateCheckValueFxn__C, ".econst:ti_sysbios_knl_Task_moduleStateCheckValueFxn__C");
asm("	.sect \".econst:ti_sysbios_knl_Task_moduleStateCheckValueFxn__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Task_moduleStateCheckValueFxn__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Task_moduleStateCheckValueFxn__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Task_moduleStateCheckValueFxn ti_sysbios_knl_Task_moduleStateCheckValueFxn__C = ((const CT__ti_sysbios_knl_Task_moduleStateCheckValueFxn)(ti_sysbios_knl_Task_getModuleStateCheckValue__I));

/* moduleStateCheckFlag__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_moduleStateCheckFlag__C, ".econst:ti_sysbios_knl_Task_moduleStateCheckFlag__C");
asm("	.sect \".econst:ti_sysbios_knl_Task_moduleStateCheckFlag__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Task_moduleStateCheckFlag__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Task_moduleStateCheckFlag__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Task_moduleStateCheckFlag ti_sysbios_knl_Task_moduleStateCheckFlag__C = 0;

/* objectCheckFxn__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_objectCheckFxn__C, ".econst:ti_sysbios_knl_Task_objectCheckFxn__C");
asm("	.sect \".econst:ti_sysbios_knl_Task_objectCheckFxn__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Task_objectCheckFxn__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Task_objectCheckFxn__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Task_objectCheckFxn ti_sysbios_knl_Task_objectCheckFxn__C = ((const CT__ti_sysbios_knl_Task_objectCheckFxn)(ti_sysbios_knl_Task_objectCheck__I));

/* objectCheckValueFxn__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_objectCheckValueFxn__C, ".econst:ti_sysbios_knl_Task_objectCheckValueFxn__C");
asm("	.sect \".econst:ti_sysbios_knl_Task_objectCheckValueFxn__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Task_objectCheckValueFxn__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Task_objectCheckValueFxn__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Task_objectCheckValueFxn ti_sysbios_knl_Task_objectCheckValueFxn__C = ((const CT__ti_sysbios_knl_Task_objectCheckValueFxn)(ti_sysbios_knl_Task_getObjectCheckValue__I));

/* objectCheckFlag__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_objectCheckFlag__C, ".econst:ti_sysbios_knl_Task_objectCheckFlag__C");
asm("	.sect \".econst:ti_sysbios_knl_Task_objectCheckFlag__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Task_objectCheckFlag__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Task_objectCheckFlag__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Task_objectCheckFlag ti_sysbios_knl_Task_objectCheckFlag__C = 0;

/* numConstructedTasks__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_numConstructedTasks__C, ".econst:ti_sysbios_knl_Task_numConstructedTasks__C");
asm("	.sect \".econst:ti_sysbios_knl_Task_numConstructedTasks__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Task_numConstructedTasks__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Task_numConstructedTasks__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Task_numConstructedTasks ti_sysbios_knl_Task_numConstructedTasks__C = (xdc_UInt)0x0;

/* startupHookFunc__C */
#pragma DATA_SECTION(ti_sysbios_knl_Task_startupHookFunc__C, ".econst:ti_sysbios_knl_Task_startupHookFunc__C");
asm("	.sect \".econst:ti_sysbios_knl_Task_startupHookFunc__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Task_startupHookFunc__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Task_startupHookFunc__C\"");
asm("	.clink ");

__FAR__ const CT__ti_sysbios_knl_Task_startupHookFunc ti_sysbios_knl_Task_startupHookFunc__C = ((const CT__ti_sysbios_knl_Task_startupHookFunc)NULL);


/*
 * ======== ti.sysbios.knl.Task_SupportProxy INITIALIZERS ========
 */


/*
 * ======== xdc.runtime.Assert INITIALIZERS ========
 */

/* Module__diagsEnabled__C */
#pragma DATA_SECTION(xdc_runtime_Assert_Module__diagsEnabled__C, ".econst:xdc_runtime_Assert_Module__diagsEnabled__C");
asm("	.sect \".econst:xdc_runtime_Assert_Module__diagsEnabled__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Assert_Module__diagsEnabled__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Assert_Module__diagsEnabled__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Assert_Module__diagsEnabled xdc_runtime_Assert_Module__diagsEnabled__C = (xdc_Bits32)0x10;

/* Module__diagsIncluded__C */
#pragma DATA_SECTION(xdc_runtime_Assert_Module__diagsIncluded__C, ".econst:xdc_runtime_Assert_Module__diagsIncluded__C");
asm("	.sect \".econst:xdc_runtime_Assert_Module__diagsIncluded__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Assert_Module__diagsIncluded__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Assert_Module__diagsIncluded__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Assert_Module__diagsIncluded xdc_runtime_Assert_Module__diagsIncluded__C = (xdc_Bits32)0x10;

/* Module__diagsMask__C */
#pragma DATA_SECTION(xdc_runtime_Assert_Module__diagsMask__C, ".econst:xdc_runtime_Assert_Module__diagsMask__C");
asm("	.sect \".econst:xdc_runtime_Assert_Module__diagsMask__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Assert_Module__diagsMask__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Assert_Module__diagsMask__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Assert_Module__diagsMask xdc_runtime_Assert_Module__diagsMask__C = ((const CT__xdc_runtime_Assert_Module__diagsMask)NULL);

/* Module__gateObj__C */
#pragma DATA_SECTION(xdc_runtime_Assert_Module__gateObj__C, ".econst:xdc_runtime_Assert_Module__gateObj__C");
asm("	.sect \".econst:xdc_runtime_Assert_Module__gateObj__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Assert_Module__gateObj__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Assert_Module__gateObj__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Assert_Module__gateObj xdc_runtime_Assert_Module__gateObj__C = ((const CT__xdc_runtime_Assert_Module__gateObj)NULL);

/* Module__gatePrms__C */
#pragma DATA_SECTION(xdc_runtime_Assert_Module__gatePrms__C, ".econst:xdc_runtime_Assert_Module__gatePrms__C");
asm("	.sect \".econst:xdc_runtime_Assert_Module__gatePrms__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Assert_Module__gatePrms__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Assert_Module__gatePrms__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Assert_Module__gatePrms xdc_runtime_Assert_Module__gatePrms__C = ((const CT__xdc_runtime_Assert_Module__gatePrms)NULL);

/* Module__id__C */
#pragma DATA_SECTION(xdc_runtime_Assert_Module__id__C, ".econst:xdc_runtime_Assert_Module__id__C");
asm("	.sect \".econst:xdc_runtime_Assert_Module__id__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Assert_Module__id__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Assert_Module__id__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Assert_Module__id xdc_runtime_Assert_Module__id__C = (xdc_Bits16)0x8002;

/* Module__loggerDefined__C */
#pragma DATA_SECTION(xdc_runtime_Assert_Module__loggerDefined__C, ".econst:xdc_runtime_Assert_Module__loggerDefined__C");
asm("	.sect \".econst:xdc_runtime_Assert_Module__loggerDefined__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Assert_Module__loggerDefined__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Assert_Module__loggerDefined__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Assert_Module__loggerDefined xdc_runtime_Assert_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
#pragma DATA_SECTION(xdc_runtime_Assert_Module__loggerObj__C, ".econst:xdc_runtime_Assert_Module__loggerObj__C");
asm("	.sect \".econst:xdc_runtime_Assert_Module__loggerObj__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Assert_Module__loggerObj__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Assert_Module__loggerObj__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Assert_Module__loggerObj xdc_runtime_Assert_Module__loggerObj__C = ((const CT__xdc_runtime_Assert_Module__loggerObj)NULL);

/* Module__loggerFxn0__C */
#pragma DATA_SECTION(xdc_runtime_Assert_Module__loggerFxn0__C, ".econst:xdc_runtime_Assert_Module__loggerFxn0__C");
asm("	.sect \".econst:xdc_runtime_Assert_Module__loggerFxn0__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Assert_Module__loggerFxn0__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Assert_Module__loggerFxn0__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Assert_Module__loggerFxn0 xdc_runtime_Assert_Module__loggerFxn0__C = ((const CT__xdc_runtime_Assert_Module__loggerFxn0)NULL);

/* Module__loggerFxn1__C */
#pragma DATA_SECTION(xdc_runtime_Assert_Module__loggerFxn1__C, ".econst:xdc_runtime_Assert_Module__loggerFxn1__C");
asm("	.sect \".econst:xdc_runtime_Assert_Module__loggerFxn1__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Assert_Module__loggerFxn1__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Assert_Module__loggerFxn1__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Assert_Module__loggerFxn1 xdc_runtime_Assert_Module__loggerFxn1__C = ((const CT__xdc_runtime_Assert_Module__loggerFxn1)NULL);

/* Module__loggerFxn2__C */
#pragma DATA_SECTION(xdc_runtime_Assert_Module__loggerFxn2__C, ".econst:xdc_runtime_Assert_Module__loggerFxn2__C");
asm("	.sect \".econst:xdc_runtime_Assert_Module__loggerFxn2__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Assert_Module__loggerFxn2__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Assert_Module__loggerFxn2__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Assert_Module__loggerFxn2 xdc_runtime_Assert_Module__loggerFxn2__C = ((const CT__xdc_runtime_Assert_Module__loggerFxn2)NULL);

/* Module__loggerFxn4__C */
#pragma DATA_SECTION(xdc_runtime_Assert_Module__loggerFxn4__C, ".econst:xdc_runtime_Assert_Module__loggerFxn4__C");
asm("	.sect \".econst:xdc_runtime_Assert_Module__loggerFxn4__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Assert_Module__loggerFxn4__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Assert_Module__loggerFxn4__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Assert_Module__loggerFxn4 xdc_runtime_Assert_Module__loggerFxn4__C = ((const CT__xdc_runtime_Assert_Module__loggerFxn4)NULL);

/* Module__loggerFxn8__C */
#pragma DATA_SECTION(xdc_runtime_Assert_Module__loggerFxn8__C, ".econst:xdc_runtime_Assert_Module__loggerFxn8__C");
asm("	.sect \".econst:xdc_runtime_Assert_Module__loggerFxn8__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Assert_Module__loggerFxn8__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Assert_Module__loggerFxn8__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Assert_Module__loggerFxn8 xdc_runtime_Assert_Module__loggerFxn8__C = ((const CT__xdc_runtime_Assert_Module__loggerFxn8)NULL);

/* Object__count__C */
#pragma DATA_SECTION(xdc_runtime_Assert_Object__count__C, ".econst:xdc_runtime_Assert_Object__count__C");
asm("	.sect \".econst:xdc_runtime_Assert_Object__count__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Assert_Object__count__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Assert_Object__count__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Assert_Object__count xdc_runtime_Assert_Object__count__C = 0;

/* Object__heap__C */
#pragma DATA_SECTION(xdc_runtime_Assert_Object__heap__C, ".econst:xdc_runtime_Assert_Object__heap__C");
asm("	.sect \".econst:xdc_runtime_Assert_Object__heap__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Assert_Object__heap__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Assert_Object__heap__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Assert_Object__heap xdc_runtime_Assert_Object__heap__C = NULL;

/* Object__sizeof__C */
#pragma DATA_SECTION(xdc_runtime_Assert_Object__sizeof__C, ".econst:xdc_runtime_Assert_Object__sizeof__C");
asm("	.sect \".econst:xdc_runtime_Assert_Object__sizeof__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Assert_Object__sizeof__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Assert_Object__sizeof__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Assert_Object__sizeof xdc_runtime_Assert_Object__sizeof__C = 0;

/* Object__table__C */
#pragma DATA_SECTION(xdc_runtime_Assert_Object__table__C, ".econst:xdc_runtime_Assert_Object__table__C");
asm("	.sect \".econst:xdc_runtime_Assert_Object__table__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Assert_Object__table__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Assert_Object__table__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Assert_Object__table xdc_runtime_Assert_Object__table__C = NULL;

/* E_assertFailed__C */
#pragma DATA_SECTION(xdc_runtime_Assert_E_assertFailed__C, ".econst:xdc_runtime_Assert_E_assertFailed__C");
asm("	.sect \".econst:xdc_runtime_Assert_E_assertFailed__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Assert_E_assertFailed__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Assert_E_assertFailed__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Assert_E_assertFailed xdc_runtime_Assert_E_assertFailed__C = (((xdc_runtime_Error_Id)3575) << 16 | 0U);


/*
 * ======== xdc.runtime.Core INITIALIZERS ========
 */

/* Module__diagsEnabled__C */
#pragma DATA_SECTION(xdc_runtime_Core_Module__diagsEnabled__C, ".econst:xdc_runtime_Core_Module__diagsEnabled__C");
asm("	.sect \".econst:xdc_runtime_Core_Module__diagsEnabled__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Core_Module__diagsEnabled__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Core_Module__diagsEnabled__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Core_Module__diagsEnabled xdc_runtime_Core_Module__diagsEnabled__C = (xdc_Bits32)0x10;

/* Module__diagsIncluded__C */
#pragma DATA_SECTION(xdc_runtime_Core_Module__diagsIncluded__C, ".econst:xdc_runtime_Core_Module__diagsIncluded__C");
asm("	.sect \".econst:xdc_runtime_Core_Module__diagsIncluded__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Core_Module__diagsIncluded__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Core_Module__diagsIncluded__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Core_Module__diagsIncluded xdc_runtime_Core_Module__diagsIncluded__C = (xdc_Bits32)0x10;

/* Module__diagsMask__C */
#pragma DATA_SECTION(xdc_runtime_Core_Module__diagsMask__C, ".econst:xdc_runtime_Core_Module__diagsMask__C");
asm("	.sect \".econst:xdc_runtime_Core_Module__diagsMask__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Core_Module__diagsMask__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Core_Module__diagsMask__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Core_Module__diagsMask xdc_runtime_Core_Module__diagsMask__C = ((const CT__xdc_runtime_Core_Module__diagsMask)NULL);

/* Module__gateObj__C */
#pragma DATA_SECTION(xdc_runtime_Core_Module__gateObj__C, ".econst:xdc_runtime_Core_Module__gateObj__C");
asm("	.sect \".econst:xdc_runtime_Core_Module__gateObj__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Core_Module__gateObj__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Core_Module__gateObj__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Core_Module__gateObj xdc_runtime_Core_Module__gateObj__C = ((const CT__xdc_runtime_Core_Module__gateObj)NULL);

/* Module__gatePrms__C */
#pragma DATA_SECTION(xdc_runtime_Core_Module__gatePrms__C, ".econst:xdc_runtime_Core_Module__gatePrms__C");
asm("	.sect \".econst:xdc_runtime_Core_Module__gatePrms__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Core_Module__gatePrms__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Core_Module__gatePrms__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Core_Module__gatePrms xdc_runtime_Core_Module__gatePrms__C = ((const CT__xdc_runtime_Core_Module__gatePrms)NULL);

/* Module__id__C */
#pragma DATA_SECTION(xdc_runtime_Core_Module__id__C, ".econst:xdc_runtime_Core_Module__id__C");
asm("	.sect \".econst:xdc_runtime_Core_Module__id__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Core_Module__id__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Core_Module__id__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Core_Module__id xdc_runtime_Core_Module__id__C = (xdc_Bits16)0x8003;

/* Module__loggerDefined__C */
#pragma DATA_SECTION(xdc_runtime_Core_Module__loggerDefined__C, ".econst:xdc_runtime_Core_Module__loggerDefined__C");
asm("	.sect \".econst:xdc_runtime_Core_Module__loggerDefined__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Core_Module__loggerDefined__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Core_Module__loggerDefined__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Core_Module__loggerDefined xdc_runtime_Core_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
#pragma DATA_SECTION(xdc_runtime_Core_Module__loggerObj__C, ".econst:xdc_runtime_Core_Module__loggerObj__C");
asm("	.sect \".econst:xdc_runtime_Core_Module__loggerObj__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Core_Module__loggerObj__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Core_Module__loggerObj__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Core_Module__loggerObj xdc_runtime_Core_Module__loggerObj__C = ((const CT__xdc_runtime_Core_Module__loggerObj)NULL);

/* Module__loggerFxn0__C */
#pragma DATA_SECTION(xdc_runtime_Core_Module__loggerFxn0__C, ".econst:xdc_runtime_Core_Module__loggerFxn0__C");
asm("	.sect \".econst:xdc_runtime_Core_Module__loggerFxn0__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Core_Module__loggerFxn0__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Core_Module__loggerFxn0__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Core_Module__loggerFxn0 xdc_runtime_Core_Module__loggerFxn0__C = ((const CT__xdc_runtime_Core_Module__loggerFxn0)NULL);

/* Module__loggerFxn1__C */
#pragma DATA_SECTION(xdc_runtime_Core_Module__loggerFxn1__C, ".econst:xdc_runtime_Core_Module__loggerFxn1__C");
asm("	.sect \".econst:xdc_runtime_Core_Module__loggerFxn1__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Core_Module__loggerFxn1__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Core_Module__loggerFxn1__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Core_Module__loggerFxn1 xdc_runtime_Core_Module__loggerFxn1__C = ((const CT__xdc_runtime_Core_Module__loggerFxn1)NULL);

/* Module__loggerFxn2__C */
#pragma DATA_SECTION(xdc_runtime_Core_Module__loggerFxn2__C, ".econst:xdc_runtime_Core_Module__loggerFxn2__C");
asm("	.sect \".econst:xdc_runtime_Core_Module__loggerFxn2__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Core_Module__loggerFxn2__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Core_Module__loggerFxn2__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Core_Module__loggerFxn2 xdc_runtime_Core_Module__loggerFxn2__C = ((const CT__xdc_runtime_Core_Module__loggerFxn2)NULL);

/* Module__loggerFxn4__C */
#pragma DATA_SECTION(xdc_runtime_Core_Module__loggerFxn4__C, ".econst:xdc_runtime_Core_Module__loggerFxn4__C");
asm("	.sect \".econst:xdc_runtime_Core_Module__loggerFxn4__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Core_Module__loggerFxn4__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Core_Module__loggerFxn4__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Core_Module__loggerFxn4 xdc_runtime_Core_Module__loggerFxn4__C = ((const CT__xdc_runtime_Core_Module__loggerFxn4)NULL);

/* Module__loggerFxn8__C */
#pragma DATA_SECTION(xdc_runtime_Core_Module__loggerFxn8__C, ".econst:xdc_runtime_Core_Module__loggerFxn8__C");
asm("	.sect \".econst:xdc_runtime_Core_Module__loggerFxn8__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Core_Module__loggerFxn8__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Core_Module__loggerFxn8__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Core_Module__loggerFxn8 xdc_runtime_Core_Module__loggerFxn8__C = ((const CT__xdc_runtime_Core_Module__loggerFxn8)NULL);

/* Object__count__C */
#pragma DATA_SECTION(xdc_runtime_Core_Object__count__C, ".econst:xdc_runtime_Core_Object__count__C");
asm("	.sect \".econst:xdc_runtime_Core_Object__count__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Core_Object__count__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Core_Object__count__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Core_Object__count xdc_runtime_Core_Object__count__C = 0;

/* Object__heap__C */
#pragma DATA_SECTION(xdc_runtime_Core_Object__heap__C, ".econst:xdc_runtime_Core_Object__heap__C");
asm("	.sect \".econst:xdc_runtime_Core_Object__heap__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Core_Object__heap__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Core_Object__heap__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Core_Object__heap xdc_runtime_Core_Object__heap__C = NULL;

/* Object__sizeof__C */
#pragma DATA_SECTION(xdc_runtime_Core_Object__sizeof__C, ".econst:xdc_runtime_Core_Object__sizeof__C");
asm("	.sect \".econst:xdc_runtime_Core_Object__sizeof__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Core_Object__sizeof__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Core_Object__sizeof__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Core_Object__sizeof xdc_runtime_Core_Object__sizeof__C = 0;

/* Object__table__C */
#pragma DATA_SECTION(xdc_runtime_Core_Object__table__C, ".econst:xdc_runtime_Core_Object__table__C");
asm("	.sect \".econst:xdc_runtime_Core_Object__table__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Core_Object__table__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Core_Object__table__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Core_Object__table xdc_runtime_Core_Object__table__C = NULL;

/* A_initializedParams__C */
#pragma DATA_SECTION(xdc_runtime_Core_A_initializedParams__C, ".econst:xdc_runtime_Core_A_initializedParams__C");
asm("	.sect \".econst:xdc_runtime_Core_A_initializedParams__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Core_A_initializedParams__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Core_A_initializedParams__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Core_A_initializedParams xdc_runtime_Core_A_initializedParams__C = (((xdc_runtime_Assert_Id)1) << 16 | 16);


/*
 * ======== xdc.runtime.Defaults INITIALIZERS ========
 */

/* Module__diagsEnabled__C */
#pragma DATA_SECTION(xdc_runtime_Defaults_Module__diagsEnabled__C, ".econst:xdc_runtime_Defaults_Module__diagsEnabled__C");
asm("	.sect \".econst:xdc_runtime_Defaults_Module__diagsEnabled__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Defaults_Module__diagsEnabled__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Defaults_Module__diagsEnabled__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Defaults_Module__diagsEnabled xdc_runtime_Defaults_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
#pragma DATA_SECTION(xdc_runtime_Defaults_Module__diagsIncluded__C, ".econst:xdc_runtime_Defaults_Module__diagsIncluded__C");
asm("	.sect \".econst:xdc_runtime_Defaults_Module__diagsIncluded__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Defaults_Module__diagsIncluded__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Defaults_Module__diagsIncluded__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Defaults_Module__diagsIncluded xdc_runtime_Defaults_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
#pragma DATA_SECTION(xdc_runtime_Defaults_Module__diagsMask__C, ".econst:xdc_runtime_Defaults_Module__diagsMask__C");
asm("	.sect \".econst:xdc_runtime_Defaults_Module__diagsMask__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Defaults_Module__diagsMask__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Defaults_Module__diagsMask__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Defaults_Module__diagsMask xdc_runtime_Defaults_Module__diagsMask__C = ((const CT__xdc_runtime_Defaults_Module__diagsMask)NULL);

/* Module__gateObj__C */
#pragma DATA_SECTION(xdc_runtime_Defaults_Module__gateObj__C, ".econst:xdc_runtime_Defaults_Module__gateObj__C");
asm("	.sect \".econst:xdc_runtime_Defaults_Module__gateObj__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Defaults_Module__gateObj__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Defaults_Module__gateObj__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Defaults_Module__gateObj xdc_runtime_Defaults_Module__gateObj__C = ((const CT__xdc_runtime_Defaults_Module__gateObj)NULL);

/* Module__gatePrms__C */
#pragma DATA_SECTION(xdc_runtime_Defaults_Module__gatePrms__C, ".econst:xdc_runtime_Defaults_Module__gatePrms__C");
asm("	.sect \".econst:xdc_runtime_Defaults_Module__gatePrms__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Defaults_Module__gatePrms__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Defaults_Module__gatePrms__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Defaults_Module__gatePrms xdc_runtime_Defaults_Module__gatePrms__C = ((const CT__xdc_runtime_Defaults_Module__gatePrms)NULL);

/* Module__id__C */
#pragma DATA_SECTION(xdc_runtime_Defaults_Module__id__C, ".econst:xdc_runtime_Defaults_Module__id__C");
asm("	.sect \".econst:xdc_runtime_Defaults_Module__id__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Defaults_Module__id__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Defaults_Module__id__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Defaults_Module__id xdc_runtime_Defaults_Module__id__C = (xdc_Bits16)0x8004;

/* Module__loggerDefined__C */
#pragma DATA_SECTION(xdc_runtime_Defaults_Module__loggerDefined__C, ".econst:xdc_runtime_Defaults_Module__loggerDefined__C");
asm("	.sect \".econst:xdc_runtime_Defaults_Module__loggerDefined__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Defaults_Module__loggerDefined__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Defaults_Module__loggerDefined__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Defaults_Module__loggerDefined xdc_runtime_Defaults_Module__loggerDefined__C = 1;

/* Module__loggerObj__C */
#pragma DATA_SECTION(xdc_runtime_Defaults_Module__loggerObj__C, ".econst:xdc_runtime_Defaults_Module__loggerObj__C");
asm("	.sect \".econst:xdc_runtime_Defaults_Module__loggerObj__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Defaults_Module__loggerObj__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Defaults_Module__loggerObj__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Defaults_Module__loggerObj xdc_runtime_Defaults_Module__loggerObj__C = ((const CT__xdc_runtime_Defaults_Module__loggerObj)((void*)(xdc_runtime_ILogger_Handle)&xdc_runtime_LoggerBuf_Object__table__V[0]));

/* Module__loggerFxn0__C */
#pragma DATA_SECTION(xdc_runtime_Defaults_Module__loggerFxn0__C, ".econst:xdc_runtime_Defaults_Module__loggerFxn0__C");
asm("	.sect \".econst:xdc_runtime_Defaults_Module__loggerFxn0__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Defaults_Module__loggerFxn0__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Defaults_Module__loggerFxn0__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Defaults_Module__loggerFxn0 xdc_runtime_Defaults_Module__loggerFxn0__C = ((const CT__xdc_runtime_Defaults_Module__loggerFxn0)(xdc_runtime_LoggerBuf_write0));

/* Module__loggerFxn1__C */
#pragma DATA_SECTION(xdc_runtime_Defaults_Module__loggerFxn1__C, ".econst:xdc_runtime_Defaults_Module__loggerFxn1__C");
asm("	.sect \".econst:xdc_runtime_Defaults_Module__loggerFxn1__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Defaults_Module__loggerFxn1__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Defaults_Module__loggerFxn1__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Defaults_Module__loggerFxn1 xdc_runtime_Defaults_Module__loggerFxn1__C = ((const CT__xdc_runtime_Defaults_Module__loggerFxn1)(xdc_runtime_LoggerBuf_write1));

/* Module__loggerFxn2__C */
#pragma DATA_SECTION(xdc_runtime_Defaults_Module__loggerFxn2__C, ".econst:xdc_runtime_Defaults_Module__loggerFxn2__C");
asm("	.sect \".econst:xdc_runtime_Defaults_Module__loggerFxn2__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Defaults_Module__loggerFxn2__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Defaults_Module__loggerFxn2__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Defaults_Module__loggerFxn2 xdc_runtime_Defaults_Module__loggerFxn2__C = ((const CT__xdc_runtime_Defaults_Module__loggerFxn2)(xdc_runtime_LoggerBuf_write2));

/* Module__loggerFxn4__C */
#pragma DATA_SECTION(xdc_runtime_Defaults_Module__loggerFxn4__C, ".econst:xdc_runtime_Defaults_Module__loggerFxn4__C");
asm("	.sect \".econst:xdc_runtime_Defaults_Module__loggerFxn4__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Defaults_Module__loggerFxn4__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Defaults_Module__loggerFxn4__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Defaults_Module__loggerFxn4 xdc_runtime_Defaults_Module__loggerFxn4__C = ((const CT__xdc_runtime_Defaults_Module__loggerFxn4)(xdc_runtime_LoggerBuf_write4));

/* Module__loggerFxn8__C */
#pragma DATA_SECTION(xdc_runtime_Defaults_Module__loggerFxn8__C, ".econst:xdc_runtime_Defaults_Module__loggerFxn8__C");
asm("	.sect \".econst:xdc_runtime_Defaults_Module__loggerFxn8__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Defaults_Module__loggerFxn8__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Defaults_Module__loggerFxn8__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Defaults_Module__loggerFxn8 xdc_runtime_Defaults_Module__loggerFxn8__C = ((const CT__xdc_runtime_Defaults_Module__loggerFxn8)(xdc_runtime_LoggerBuf_write8));

/* Object__count__C */
#pragma DATA_SECTION(xdc_runtime_Defaults_Object__count__C, ".econst:xdc_runtime_Defaults_Object__count__C");
asm("	.sect \".econst:xdc_runtime_Defaults_Object__count__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Defaults_Object__count__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Defaults_Object__count__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Defaults_Object__count xdc_runtime_Defaults_Object__count__C = 0;

/* Object__heap__C */
#pragma DATA_SECTION(xdc_runtime_Defaults_Object__heap__C, ".econst:xdc_runtime_Defaults_Object__heap__C");
asm("	.sect \".econst:xdc_runtime_Defaults_Object__heap__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Defaults_Object__heap__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Defaults_Object__heap__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Defaults_Object__heap xdc_runtime_Defaults_Object__heap__C = NULL;

/* Object__sizeof__C */
#pragma DATA_SECTION(xdc_runtime_Defaults_Object__sizeof__C, ".econst:xdc_runtime_Defaults_Object__sizeof__C");
asm("	.sect \".econst:xdc_runtime_Defaults_Object__sizeof__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Defaults_Object__sizeof__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Defaults_Object__sizeof__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Defaults_Object__sizeof xdc_runtime_Defaults_Object__sizeof__C = 0;

/* Object__table__C */
#pragma DATA_SECTION(xdc_runtime_Defaults_Object__table__C, ".econst:xdc_runtime_Defaults_Object__table__C");
asm("	.sect \".econst:xdc_runtime_Defaults_Object__table__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Defaults_Object__table__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Defaults_Object__table__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Defaults_Object__table xdc_runtime_Defaults_Object__table__C = NULL;


/*
 * ======== xdc.runtime.Diags INITIALIZERS ========
 */

/* Module__diagsEnabled__C */
#pragma DATA_SECTION(xdc_runtime_Diags_Module__diagsEnabled__C, ".econst:xdc_runtime_Diags_Module__diagsEnabled__C");
asm("	.sect \".econst:xdc_runtime_Diags_Module__diagsEnabled__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Diags_Module__diagsEnabled__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Diags_Module__diagsEnabled__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Diags_Module__diagsEnabled xdc_runtime_Diags_Module__diagsEnabled__C = (xdc_Bits32)0x10;

/* Module__diagsIncluded__C */
#pragma DATA_SECTION(xdc_runtime_Diags_Module__diagsIncluded__C, ".econst:xdc_runtime_Diags_Module__diagsIncluded__C");
asm("	.sect \".econst:xdc_runtime_Diags_Module__diagsIncluded__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Diags_Module__diagsIncluded__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Diags_Module__diagsIncluded__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Diags_Module__diagsIncluded xdc_runtime_Diags_Module__diagsIncluded__C = (xdc_Bits32)0x10;

/* Module__diagsMask__C */
#pragma DATA_SECTION(xdc_runtime_Diags_Module__diagsMask__C, ".econst:xdc_runtime_Diags_Module__diagsMask__C");
asm("	.sect \".econst:xdc_runtime_Diags_Module__diagsMask__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Diags_Module__diagsMask__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Diags_Module__diagsMask__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Diags_Module__diagsMask xdc_runtime_Diags_Module__diagsMask__C = ((const CT__xdc_runtime_Diags_Module__diagsMask)NULL);

/* Module__gateObj__C */
#pragma DATA_SECTION(xdc_runtime_Diags_Module__gateObj__C, ".econst:xdc_runtime_Diags_Module__gateObj__C");
asm("	.sect \".econst:xdc_runtime_Diags_Module__gateObj__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Diags_Module__gateObj__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Diags_Module__gateObj__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Diags_Module__gateObj xdc_runtime_Diags_Module__gateObj__C = ((const CT__xdc_runtime_Diags_Module__gateObj)NULL);

/* Module__gatePrms__C */
#pragma DATA_SECTION(xdc_runtime_Diags_Module__gatePrms__C, ".econst:xdc_runtime_Diags_Module__gatePrms__C");
asm("	.sect \".econst:xdc_runtime_Diags_Module__gatePrms__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Diags_Module__gatePrms__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Diags_Module__gatePrms__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Diags_Module__gatePrms xdc_runtime_Diags_Module__gatePrms__C = ((const CT__xdc_runtime_Diags_Module__gatePrms)NULL);

/* Module__id__C */
#pragma DATA_SECTION(xdc_runtime_Diags_Module__id__C, ".econst:xdc_runtime_Diags_Module__id__C");
asm("	.sect \".econst:xdc_runtime_Diags_Module__id__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Diags_Module__id__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Diags_Module__id__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Diags_Module__id xdc_runtime_Diags_Module__id__C = (xdc_Bits16)0x8005;

/* Module__loggerDefined__C */
#pragma DATA_SECTION(xdc_runtime_Diags_Module__loggerDefined__C, ".econst:xdc_runtime_Diags_Module__loggerDefined__C");
asm("	.sect \".econst:xdc_runtime_Diags_Module__loggerDefined__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Diags_Module__loggerDefined__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Diags_Module__loggerDefined__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Diags_Module__loggerDefined xdc_runtime_Diags_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
#pragma DATA_SECTION(xdc_runtime_Diags_Module__loggerObj__C, ".econst:xdc_runtime_Diags_Module__loggerObj__C");
asm("	.sect \".econst:xdc_runtime_Diags_Module__loggerObj__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Diags_Module__loggerObj__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Diags_Module__loggerObj__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Diags_Module__loggerObj xdc_runtime_Diags_Module__loggerObj__C = ((const CT__xdc_runtime_Diags_Module__loggerObj)NULL);

/* Module__loggerFxn0__C */
#pragma DATA_SECTION(xdc_runtime_Diags_Module__loggerFxn0__C, ".econst:xdc_runtime_Diags_Module__loggerFxn0__C");
asm("	.sect \".econst:xdc_runtime_Diags_Module__loggerFxn0__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Diags_Module__loggerFxn0__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Diags_Module__loggerFxn0__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Diags_Module__loggerFxn0 xdc_runtime_Diags_Module__loggerFxn0__C = ((const CT__xdc_runtime_Diags_Module__loggerFxn0)NULL);

/* Module__loggerFxn1__C */
#pragma DATA_SECTION(xdc_runtime_Diags_Module__loggerFxn1__C, ".econst:xdc_runtime_Diags_Module__loggerFxn1__C");
asm("	.sect \".econst:xdc_runtime_Diags_Module__loggerFxn1__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Diags_Module__loggerFxn1__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Diags_Module__loggerFxn1__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Diags_Module__loggerFxn1 xdc_runtime_Diags_Module__loggerFxn1__C = ((const CT__xdc_runtime_Diags_Module__loggerFxn1)NULL);

/* Module__loggerFxn2__C */
#pragma DATA_SECTION(xdc_runtime_Diags_Module__loggerFxn2__C, ".econst:xdc_runtime_Diags_Module__loggerFxn2__C");
asm("	.sect \".econst:xdc_runtime_Diags_Module__loggerFxn2__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Diags_Module__loggerFxn2__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Diags_Module__loggerFxn2__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Diags_Module__loggerFxn2 xdc_runtime_Diags_Module__loggerFxn2__C = ((const CT__xdc_runtime_Diags_Module__loggerFxn2)NULL);

/* Module__loggerFxn4__C */
#pragma DATA_SECTION(xdc_runtime_Diags_Module__loggerFxn4__C, ".econst:xdc_runtime_Diags_Module__loggerFxn4__C");
asm("	.sect \".econst:xdc_runtime_Diags_Module__loggerFxn4__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Diags_Module__loggerFxn4__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Diags_Module__loggerFxn4__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Diags_Module__loggerFxn4 xdc_runtime_Diags_Module__loggerFxn4__C = ((const CT__xdc_runtime_Diags_Module__loggerFxn4)NULL);

/* Module__loggerFxn8__C */
#pragma DATA_SECTION(xdc_runtime_Diags_Module__loggerFxn8__C, ".econst:xdc_runtime_Diags_Module__loggerFxn8__C");
asm("	.sect \".econst:xdc_runtime_Diags_Module__loggerFxn8__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Diags_Module__loggerFxn8__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Diags_Module__loggerFxn8__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Diags_Module__loggerFxn8 xdc_runtime_Diags_Module__loggerFxn8__C = ((const CT__xdc_runtime_Diags_Module__loggerFxn8)NULL);

/* Object__count__C */
#pragma DATA_SECTION(xdc_runtime_Diags_Object__count__C, ".econst:xdc_runtime_Diags_Object__count__C");
asm("	.sect \".econst:xdc_runtime_Diags_Object__count__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Diags_Object__count__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Diags_Object__count__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Diags_Object__count xdc_runtime_Diags_Object__count__C = 0;

/* Object__heap__C */
#pragma DATA_SECTION(xdc_runtime_Diags_Object__heap__C, ".econst:xdc_runtime_Diags_Object__heap__C");
asm("	.sect \".econst:xdc_runtime_Diags_Object__heap__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Diags_Object__heap__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Diags_Object__heap__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Diags_Object__heap xdc_runtime_Diags_Object__heap__C = NULL;

/* Object__sizeof__C */
#pragma DATA_SECTION(xdc_runtime_Diags_Object__sizeof__C, ".econst:xdc_runtime_Diags_Object__sizeof__C");
asm("	.sect \".econst:xdc_runtime_Diags_Object__sizeof__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Diags_Object__sizeof__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Diags_Object__sizeof__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Diags_Object__sizeof xdc_runtime_Diags_Object__sizeof__C = 0;

/* Object__table__C */
#pragma DATA_SECTION(xdc_runtime_Diags_Object__table__C, ".econst:xdc_runtime_Diags_Object__table__C");
asm("	.sect \".econst:xdc_runtime_Diags_Object__table__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Diags_Object__table__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Diags_Object__table__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Diags_Object__table xdc_runtime_Diags_Object__table__C = NULL;

/* setMaskEnabled__C */
#pragma DATA_SECTION(xdc_runtime_Diags_setMaskEnabled__C, ".econst:xdc_runtime_Diags_setMaskEnabled__C");
asm("	.sect \".econst:xdc_runtime_Diags_setMaskEnabled__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Diags_setMaskEnabled__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Diags_setMaskEnabled__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Diags_setMaskEnabled xdc_runtime_Diags_setMaskEnabled__C = 0;

/* dictBase__C */
#pragma DATA_SECTION(xdc_runtime_Diags_dictBase__C, ".econst:xdc_runtime_Diags_dictBase__C");
asm("	.sect \".econst:xdc_runtime_Diags_dictBase__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Diags_dictBase__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Diags_dictBase__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Diags_dictBase xdc_runtime_Diags_dictBase__C = ((const CT__xdc_runtime_Diags_dictBase)NULL);


/*
 * ======== xdc.runtime.Error INITIALIZERS ========
 */

/* Module__state__V */
#if defined (__ICCARM__)
#pragma location = ".data_xdc_runtime_Error_Module__state__V"
#endif
#if defined(__GNUC__) && !(defined(__MACH__) && defined(__APPLE__))
#ifndef __ti__
xdc_runtime_Error_Module_State__ xdc_runtime_Error_Module__state__V __attribute__ ((section(".data_xdc_runtime_Error_Module__state__V")));
#elif defined(__clang__)
xdc_runtime_Error_Module_State__ xdc_runtime_Error_Module__state__V __attribute__ ((section(".data:xdc_runtime_Error_Module__state__V")));
#endif
#endif
xdc_runtime_Error_Module_State__ xdc_runtime_Error_Module__state__V = {
    (xdc_UInt16)0x0,  /* count */
};

/* Module__diagsEnabled__C */
#pragma DATA_SECTION(xdc_runtime_Error_Module__diagsEnabled__C, ".econst:xdc_runtime_Error_Module__diagsEnabled__C");
asm("	.sect \".econst:xdc_runtime_Error_Module__diagsEnabled__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Error_Module__diagsEnabled__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Error_Module__diagsEnabled__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Error_Module__diagsEnabled xdc_runtime_Error_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
#pragma DATA_SECTION(xdc_runtime_Error_Module__diagsIncluded__C, ".econst:xdc_runtime_Error_Module__diagsIncluded__C");
asm("	.sect \".econst:xdc_runtime_Error_Module__diagsIncluded__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Error_Module__diagsIncluded__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Error_Module__diagsIncluded__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Error_Module__diagsIncluded xdc_runtime_Error_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
#pragma DATA_SECTION(xdc_runtime_Error_Module__diagsMask__C, ".econst:xdc_runtime_Error_Module__diagsMask__C");
asm("	.sect \".econst:xdc_runtime_Error_Module__diagsMask__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Error_Module__diagsMask__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Error_Module__diagsMask__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Error_Module__diagsMask xdc_runtime_Error_Module__diagsMask__C = ((const CT__xdc_runtime_Error_Module__diagsMask)NULL);

/* Module__gateObj__C */
#pragma DATA_SECTION(xdc_runtime_Error_Module__gateObj__C, ".econst:xdc_runtime_Error_Module__gateObj__C");
asm("	.sect \".econst:xdc_runtime_Error_Module__gateObj__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Error_Module__gateObj__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Error_Module__gateObj__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Error_Module__gateObj xdc_runtime_Error_Module__gateObj__C = ((const CT__xdc_runtime_Error_Module__gateObj)NULL);

/* Module__gatePrms__C */
#pragma DATA_SECTION(xdc_runtime_Error_Module__gatePrms__C, ".econst:xdc_runtime_Error_Module__gatePrms__C");
asm("	.sect \".econst:xdc_runtime_Error_Module__gatePrms__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Error_Module__gatePrms__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Error_Module__gatePrms__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Error_Module__gatePrms xdc_runtime_Error_Module__gatePrms__C = ((const CT__xdc_runtime_Error_Module__gatePrms)NULL);

/* Module__id__C */
#pragma DATA_SECTION(xdc_runtime_Error_Module__id__C, ".econst:xdc_runtime_Error_Module__id__C");
asm("	.sect \".econst:xdc_runtime_Error_Module__id__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Error_Module__id__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Error_Module__id__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Error_Module__id xdc_runtime_Error_Module__id__C = (xdc_Bits16)0x8006;

/* Module__loggerDefined__C */
#pragma DATA_SECTION(xdc_runtime_Error_Module__loggerDefined__C, ".econst:xdc_runtime_Error_Module__loggerDefined__C");
asm("	.sect \".econst:xdc_runtime_Error_Module__loggerDefined__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Error_Module__loggerDefined__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Error_Module__loggerDefined__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Error_Module__loggerDefined xdc_runtime_Error_Module__loggerDefined__C = 1;

/* Module__loggerObj__C */
#pragma DATA_SECTION(xdc_runtime_Error_Module__loggerObj__C, ".econst:xdc_runtime_Error_Module__loggerObj__C");
asm("	.sect \".econst:xdc_runtime_Error_Module__loggerObj__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Error_Module__loggerObj__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Error_Module__loggerObj__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Error_Module__loggerObj xdc_runtime_Error_Module__loggerObj__C = ((const CT__xdc_runtime_Error_Module__loggerObj)((void*)(xdc_runtime_ILogger_Handle)&xdc_runtime_LoggerBuf_Object__table__V[0]));

/* Module__loggerFxn0__C */
#pragma DATA_SECTION(xdc_runtime_Error_Module__loggerFxn0__C, ".econst:xdc_runtime_Error_Module__loggerFxn0__C");
asm("	.sect \".econst:xdc_runtime_Error_Module__loggerFxn0__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Error_Module__loggerFxn0__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Error_Module__loggerFxn0__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Error_Module__loggerFxn0 xdc_runtime_Error_Module__loggerFxn0__C = ((const CT__xdc_runtime_Error_Module__loggerFxn0)(xdc_runtime_LoggerBuf_write0));

/* Module__loggerFxn1__C */
#pragma DATA_SECTION(xdc_runtime_Error_Module__loggerFxn1__C, ".econst:xdc_runtime_Error_Module__loggerFxn1__C");
asm("	.sect \".econst:xdc_runtime_Error_Module__loggerFxn1__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Error_Module__loggerFxn1__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Error_Module__loggerFxn1__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Error_Module__loggerFxn1 xdc_runtime_Error_Module__loggerFxn1__C = ((const CT__xdc_runtime_Error_Module__loggerFxn1)(xdc_runtime_LoggerBuf_write1));

/* Module__loggerFxn2__C */
#pragma DATA_SECTION(xdc_runtime_Error_Module__loggerFxn2__C, ".econst:xdc_runtime_Error_Module__loggerFxn2__C");
asm("	.sect \".econst:xdc_runtime_Error_Module__loggerFxn2__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Error_Module__loggerFxn2__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Error_Module__loggerFxn2__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Error_Module__loggerFxn2 xdc_runtime_Error_Module__loggerFxn2__C = ((const CT__xdc_runtime_Error_Module__loggerFxn2)(xdc_runtime_LoggerBuf_write2));

/* Module__loggerFxn4__C */
#pragma DATA_SECTION(xdc_runtime_Error_Module__loggerFxn4__C, ".econst:xdc_runtime_Error_Module__loggerFxn4__C");
asm("	.sect \".econst:xdc_runtime_Error_Module__loggerFxn4__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Error_Module__loggerFxn4__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Error_Module__loggerFxn4__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Error_Module__loggerFxn4 xdc_runtime_Error_Module__loggerFxn4__C = ((const CT__xdc_runtime_Error_Module__loggerFxn4)(xdc_runtime_LoggerBuf_write4));

/* Module__loggerFxn8__C */
#pragma DATA_SECTION(xdc_runtime_Error_Module__loggerFxn8__C, ".econst:xdc_runtime_Error_Module__loggerFxn8__C");
asm("	.sect \".econst:xdc_runtime_Error_Module__loggerFxn8__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Error_Module__loggerFxn8__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Error_Module__loggerFxn8__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Error_Module__loggerFxn8 xdc_runtime_Error_Module__loggerFxn8__C = ((const CT__xdc_runtime_Error_Module__loggerFxn8)(xdc_runtime_LoggerBuf_write8));

/* Object__count__C */
#pragma DATA_SECTION(xdc_runtime_Error_Object__count__C, ".econst:xdc_runtime_Error_Object__count__C");
asm("	.sect \".econst:xdc_runtime_Error_Object__count__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Error_Object__count__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Error_Object__count__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Error_Object__count xdc_runtime_Error_Object__count__C = 0;

/* Object__heap__C */
#pragma DATA_SECTION(xdc_runtime_Error_Object__heap__C, ".econst:xdc_runtime_Error_Object__heap__C");
asm("	.sect \".econst:xdc_runtime_Error_Object__heap__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Error_Object__heap__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Error_Object__heap__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Error_Object__heap xdc_runtime_Error_Object__heap__C = NULL;

/* Object__sizeof__C */
#pragma DATA_SECTION(xdc_runtime_Error_Object__sizeof__C, ".econst:xdc_runtime_Error_Object__sizeof__C");
asm("	.sect \".econst:xdc_runtime_Error_Object__sizeof__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Error_Object__sizeof__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Error_Object__sizeof__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Error_Object__sizeof xdc_runtime_Error_Object__sizeof__C = 0;

/* Object__table__C */
#pragma DATA_SECTION(xdc_runtime_Error_Object__table__C, ".econst:xdc_runtime_Error_Object__table__C");
asm("	.sect \".econst:xdc_runtime_Error_Object__table__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Error_Object__table__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Error_Object__table__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Error_Object__table xdc_runtime_Error_Object__table__C = NULL;

/* policyFxn__C */
#pragma DATA_SECTION(xdc_runtime_Error_policyFxn__C, ".econst:xdc_runtime_Error_policyFxn__C");
asm("	.sect \".econst:xdc_runtime_Error_policyFxn__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Error_policyFxn__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Error_policyFxn__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Error_policyFxn xdc_runtime_Error_policyFxn__C = ((const CT__xdc_runtime_Error_policyFxn)(xdc_runtime_Error_policyDefault__E));

/* E_generic__C */
#pragma DATA_SECTION(xdc_runtime_Error_E_generic__C, ".econst:xdc_runtime_Error_E_generic__C");
asm("	.sect \".econst:xdc_runtime_Error_E_generic__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Error_E_generic__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Error_E_generic__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Error_E_generic xdc_runtime_Error_E_generic__C = (((xdc_runtime_Error_Id)3597) << 16 | 0U);

/* E_memory__C */
#pragma DATA_SECTION(xdc_runtime_Error_E_memory__C, ".econst:xdc_runtime_Error_E_memory__C");
asm("	.sect \".econst:xdc_runtime_Error_E_memory__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Error_E_memory__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Error_E_memory__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Error_E_memory xdc_runtime_Error_E_memory__C = (((xdc_runtime_Error_Id)3601) << 16 | 0U);

/* E_msgCode__C */
#pragma DATA_SECTION(xdc_runtime_Error_E_msgCode__C, ".econst:xdc_runtime_Error_E_msgCode__C");
asm("	.sect \".econst:xdc_runtime_Error_E_msgCode__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Error_E_msgCode__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Error_E_msgCode__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Error_E_msgCode xdc_runtime_Error_E_msgCode__C = (((xdc_runtime_Error_Id)3635) << 16 | 0U);

/* policy__C */
#pragma DATA_SECTION(xdc_runtime_Error_policy__C, ".econst:xdc_runtime_Error_policy__C");
asm("	.sect \".econst:xdc_runtime_Error_policy__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Error_policy__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Error_policy__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Error_policy xdc_runtime_Error_policy__C = xdc_runtime_Error_UNWIND;

/* raiseHook__C */
#pragma DATA_SECTION(xdc_runtime_Error_raiseHook__C, ".econst:xdc_runtime_Error_raiseHook__C");
asm("	.sect \".econst:xdc_runtime_Error_raiseHook__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Error_raiseHook__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Error_raiseHook__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Error_raiseHook xdc_runtime_Error_raiseHook__C = ((const CT__xdc_runtime_Error_raiseHook)(ti_sysbios_BIOS_errorRaiseHook__I));

/* maxDepth__C */
#pragma DATA_SECTION(xdc_runtime_Error_maxDepth__C, ".econst:xdc_runtime_Error_maxDepth__C");
asm("	.sect \".econst:xdc_runtime_Error_maxDepth__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Error_maxDepth__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Error_maxDepth__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Error_maxDepth xdc_runtime_Error_maxDepth__C = (xdc_UInt16)0x10;


/*
 * ======== xdc.runtime.Gate INITIALIZERS ========
 */

/* Module__diagsEnabled__C */
#pragma DATA_SECTION(xdc_runtime_Gate_Module__diagsEnabled__C, ".econst:xdc_runtime_Gate_Module__diagsEnabled__C");
asm("	.sect \".econst:xdc_runtime_Gate_Module__diagsEnabled__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Gate_Module__diagsEnabled__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Gate_Module__diagsEnabled__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Gate_Module__diagsEnabled xdc_runtime_Gate_Module__diagsEnabled__C = (xdc_Bits32)0x10;

/* Module__diagsIncluded__C */
#pragma DATA_SECTION(xdc_runtime_Gate_Module__diagsIncluded__C, ".econst:xdc_runtime_Gate_Module__diagsIncluded__C");
asm("	.sect \".econst:xdc_runtime_Gate_Module__diagsIncluded__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Gate_Module__diagsIncluded__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Gate_Module__diagsIncluded__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Gate_Module__diagsIncluded xdc_runtime_Gate_Module__diagsIncluded__C = (xdc_Bits32)0x10;

/* Module__diagsMask__C */
#pragma DATA_SECTION(xdc_runtime_Gate_Module__diagsMask__C, ".econst:xdc_runtime_Gate_Module__diagsMask__C");
asm("	.sect \".econst:xdc_runtime_Gate_Module__diagsMask__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Gate_Module__diagsMask__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Gate_Module__diagsMask__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Gate_Module__diagsMask xdc_runtime_Gate_Module__diagsMask__C = ((const CT__xdc_runtime_Gate_Module__diagsMask)NULL);

/* Module__gateObj__C */
#pragma DATA_SECTION(xdc_runtime_Gate_Module__gateObj__C, ".econst:xdc_runtime_Gate_Module__gateObj__C");
asm("	.sect \".econst:xdc_runtime_Gate_Module__gateObj__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Gate_Module__gateObj__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Gate_Module__gateObj__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Gate_Module__gateObj xdc_runtime_Gate_Module__gateObj__C = ((const CT__xdc_runtime_Gate_Module__gateObj)NULL);

/* Module__gatePrms__C */
#pragma DATA_SECTION(xdc_runtime_Gate_Module__gatePrms__C, ".econst:xdc_runtime_Gate_Module__gatePrms__C");
asm("	.sect \".econst:xdc_runtime_Gate_Module__gatePrms__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Gate_Module__gatePrms__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Gate_Module__gatePrms__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Gate_Module__gatePrms xdc_runtime_Gate_Module__gatePrms__C = ((const CT__xdc_runtime_Gate_Module__gatePrms)NULL);

/* Module__id__C */
#pragma DATA_SECTION(xdc_runtime_Gate_Module__id__C, ".econst:xdc_runtime_Gate_Module__id__C");
asm("	.sect \".econst:xdc_runtime_Gate_Module__id__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Gate_Module__id__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Gate_Module__id__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Gate_Module__id xdc_runtime_Gate_Module__id__C = (xdc_Bits16)0x8007;

/* Module__loggerDefined__C */
#pragma DATA_SECTION(xdc_runtime_Gate_Module__loggerDefined__C, ".econst:xdc_runtime_Gate_Module__loggerDefined__C");
asm("	.sect \".econst:xdc_runtime_Gate_Module__loggerDefined__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Gate_Module__loggerDefined__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Gate_Module__loggerDefined__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Gate_Module__loggerDefined xdc_runtime_Gate_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
#pragma DATA_SECTION(xdc_runtime_Gate_Module__loggerObj__C, ".econst:xdc_runtime_Gate_Module__loggerObj__C");
asm("	.sect \".econst:xdc_runtime_Gate_Module__loggerObj__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Gate_Module__loggerObj__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Gate_Module__loggerObj__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Gate_Module__loggerObj xdc_runtime_Gate_Module__loggerObj__C = ((const CT__xdc_runtime_Gate_Module__loggerObj)NULL);

/* Module__loggerFxn0__C */
#pragma DATA_SECTION(xdc_runtime_Gate_Module__loggerFxn0__C, ".econst:xdc_runtime_Gate_Module__loggerFxn0__C");
asm("	.sect \".econst:xdc_runtime_Gate_Module__loggerFxn0__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Gate_Module__loggerFxn0__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Gate_Module__loggerFxn0__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Gate_Module__loggerFxn0 xdc_runtime_Gate_Module__loggerFxn0__C = ((const CT__xdc_runtime_Gate_Module__loggerFxn0)NULL);

/* Module__loggerFxn1__C */
#pragma DATA_SECTION(xdc_runtime_Gate_Module__loggerFxn1__C, ".econst:xdc_runtime_Gate_Module__loggerFxn1__C");
asm("	.sect \".econst:xdc_runtime_Gate_Module__loggerFxn1__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Gate_Module__loggerFxn1__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Gate_Module__loggerFxn1__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Gate_Module__loggerFxn1 xdc_runtime_Gate_Module__loggerFxn1__C = ((const CT__xdc_runtime_Gate_Module__loggerFxn1)NULL);

/* Module__loggerFxn2__C */
#pragma DATA_SECTION(xdc_runtime_Gate_Module__loggerFxn2__C, ".econst:xdc_runtime_Gate_Module__loggerFxn2__C");
asm("	.sect \".econst:xdc_runtime_Gate_Module__loggerFxn2__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Gate_Module__loggerFxn2__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Gate_Module__loggerFxn2__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Gate_Module__loggerFxn2 xdc_runtime_Gate_Module__loggerFxn2__C = ((const CT__xdc_runtime_Gate_Module__loggerFxn2)NULL);

/* Module__loggerFxn4__C */
#pragma DATA_SECTION(xdc_runtime_Gate_Module__loggerFxn4__C, ".econst:xdc_runtime_Gate_Module__loggerFxn4__C");
asm("	.sect \".econst:xdc_runtime_Gate_Module__loggerFxn4__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Gate_Module__loggerFxn4__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Gate_Module__loggerFxn4__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Gate_Module__loggerFxn4 xdc_runtime_Gate_Module__loggerFxn4__C = ((const CT__xdc_runtime_Gate_Module__loggerFxn4)NULL);

/* Module__loggerFxn8__C */
#pragma DATA_SECTION(xdc_runtime_Gate_Module__loggerFxn8__C, ".econst:xdc_runtime_Gate_Module__loggerFxn8__C");
asm("	.sect \".econst:xdc_runtime_Gate_Module__loggerFxn8__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Gate_Module__loggerFxn8__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Gate_Module__loggerFxn8__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Gate_Module__loggerFxn8 xdc_runtime_Gate_Module__loggerFxn8__C = ((const CT__xdc_runtime_Gate_Module__loggerFxn8)NULL);

/* Object__count__C */
#pragma DATA_SECTION(xdc_runtime_Gate_Object__count__C, ".econst:xdc_runtime_Gate_Object__count__C");
asm("	.sect \".econst:xdc_runtime_Gate_Object__count__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Gate_Object__count__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Gate_Object__count__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Gate_Object__count xdc_runtime_Gate_Object__count__C = 0;

/* Object__heap__C */
#pragma DATA_SECTION(xdc_runtime_Gate_Object__heap__C, ".econst:xdc_runtime_Gate_Object__heap__C");
asm("	.sect \".econst:xdc_runtime_Gate_Object__heap__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Gate_Object__heap__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Gate_Object__heap__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Gate_Object__heap xdc_runtime_Gate_Object__heap__C = NULL;

/* Object__sizeof__C */
#pragma DATA_SECTION(xdc_runtime_Gate_Object__sizeof__C, ".econst:xdc_runtime_Gate_Object__sizeof__C");
asm("	.sect \".econst:xdc_runtime_Gate_Object__sizeof__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Gate_Object__sizeof__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Gate_Object__sizeof__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Gate_Object__sizeof xdc_runtime_Gate_Object__sizeof__C = 0;

/* Object__table__C */
#pragma DATA_SECTION(xdc_runtime_Gate_Object__table__C, ".econst:xdc_runtime_Gate_Object__table__C");
asm("	.sect \".econst:xdc_runtime_Gate_Object__table__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Gate_Object__table__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Gate_Object__table__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Gate_Object__table xdc_runtime_Gate_Object__table__C = NULL;


/*
 * ======== xdc.runtime.Log INITIALIZERS ========
 */

/* Module__diagsEnabled__C */
#pragma DATA_SECTION(xdc_runtime_Log_Module__diagsEnabled__C, ".econst:xdc_runtime_Log_Module__diagsEnabled__C");
asm("	.sect \".econst:xdc_runtime_Log_Module__diagsEnabled__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Log_Module__diagsEnabled__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Log_Module__diagsEnabled__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Log_Module__diagsEnabled xdc_runtime_Log_Module__diagsEnabled__C = (xdc_Bits32)0x10;

/* Module__diagsIncluded__C */
#pragma DATA_SECTION(xdc_runtime_Log_Module__diagsIncluded__C, ".econst:xdc_runtime_Log_Module__diagsIncluded__C");
asm("	.sect \".econst:xdc_runtime_Log_Module__diagsIncluded__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Log_Module__diagsIncluded__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Log_Module__diagsIncluded__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Log_Module__diagsIncluded xdc_runtime_Log_Module__diagsIncluded__C = (xdc_Bits32)0x10;

/* Module__diagsMask__C */
#pragma DATA_SECTION(xdc_runtime_Log_Module__diagsMask__C, ".econst:xdc_runtime_Log_Module__diagsMask__C");
asm("	.sect \".econst:xdc_runtime_Log_Module__diagsMask__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Log_Module__diagsMask__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Log_Module__diagsMask__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Log_Module__diagsMask xdc_runtime_Log_Module__diagsMask__C = ((const CT__xdc_runtime_Log_Module__diagsMask)NULL);

/* Module__gateObj__C */
#pragma DATA_SECTION(xdc_runtime_Log_Module__gateObj__C, ".econst:xdc_runtime_Log_Module__gateObj__C");
asm("	.sect \".econst:xdc_runtime_Log_Module__gateObj__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Log_Module__gateObj__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Log_Module__gateObj__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Log_Module__gateObj xdc_runtime_Log_Module__gateObj__C = ((const CT__xdc_runtime_Log_Module__gateObj)NULL);

/* Module__gatePrms__C */
#pragma DATA_SECTION(xdc_runtime_Log_Module__gatePrms__C, ".econst:xdc_runtime_Log_Module__gatePrms__C");
asm("	.sect \".econst:xdc_runtime_Log_Module__gatePrms__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Log_Module__gatePrms__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Log_Module__gatePrms__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Log_Module__gatePrms xdc_runtime_Log_Module__gatePrms__C = ((const CT__xdc_runtime_Log_Module__gatePrms)NULL);

/* Module__id__C */
#pragma DATA_SECTION(xdc_runtime_Log_Module__id__C, ".econst:xdc_runtime_Log_Module__id__C");
asm("	.sect \".econst:xdc_runtime_Log_Module__id__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Log_Module__id__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Log_Module__id__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Log_Module__id xdc_runtime_Log_Module__id__C = (xdc_Bits16)0x8008;

/* Module__loggerDefined__C */
#pragma DATA_SECTION(xdc_runtime_Log_Module__loggerDefined__C, ".econst:xdc_runtime_Log_Module__loggerDefined__C");
asm("	.sect \".econst:xdc_runtime_Log_Module__loggerDefined__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Log_Module__loggerDefined__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Log_Module__loggerDefined__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Log_Module__loggerDefined xdc_runtime_Log_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
#pragma DATA_SECTION(xdc_runtime_Log_Module__loggerObj__C, ".econst:xdc_runtime_Log_Module__loggerObj__C");
asm("	.sect \".econst:xdc_runtime_Log_Module__loggerObj__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Log_Module__loggerObj__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Log_Module__loggerObj__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Log_Module__loggerObj xdc_runtime_Log_Module__loggerObj__C = ((const CT__xdc_runtime_Log_Module__loggerObj)NULL);

/* Module__loggerFxn0__C */
#pragma DATA_SECTION(xdc_runtime_Log_Module__loggerFxn0__C, ".econst:xdc_runtime_Log_Module__loggerFxn0__C");
asm("	.sect \".econst:xdc_runtime_Log_Module__loggerFxn0__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Log_Module__loggerFxn0__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Log_Module__loggerFxn0__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Log_Module__loggerFxn0 xdc_runtime_Log_Module__loggerFxn0__C = ((const CT__xdc_runtime_Log_Module__loggerFxn0)NULL);

/* Module__loggerFxn1__C */
#pragma DATA_SECTION(xdc_runtime_Log_Module__loggerFxn1__C, ".econst:xdc_runtime_Log_Module__loggerFxn1__C");
asm("	.sect \".econst:xdc_runtime_Log_Module__loggerFxn1__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Log_Module__loggerFxn1__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Log_Module__loggerFxn1__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Log_Module__loggerFxn1 xdc_runtime_Log_Module__loggerFxn1__C = ((const CT__xdc_runtime_Log_Module__loggerFxn1)NULL);

/* Module__loggerFxn2__C */
#pragma DATA_SECTION(xdc_runtime_Log_Module__loggerFxn2__C, ".econst:xdc_runtime_Log_Module__loggerFxn2__C");
asm("	.sect \".econst:xdc_runtime_Log_Module__loggerFxn2__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Log_Module__loggerFxn2__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Log_Module__loggerFxn2__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Log_Module__loggerFxn2 xdc_runtime_Log_Module__loggerFxn2__C = ((const CT__xdc_runtime_Log_Module__loggerFxn2)NULL);

/* Module__loggerFxn4__C */
#pragma DATA_SECTION(xdc_runtime_Log_Module__loggerFxn4__C, ".econst:xdc_runtime_Log_Module__loggerFxn4__C");
asm("	.sect \".econst:xdc_runtime_Log_Module__loggerFxn4__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Log_Module__loggerFxn4__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Log_Module__loggerFxn4__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Log_Module__loggerFxn4 xdc_runtime_Log_Module__loggerFxn4__C = ((const CT__xdc_runtime_Log_Module__loggerFxn4)NULL);

/* Module__loggerFxn8__C */
#pragma DATA_SECTION(xdc_runtime_Log_Module__loggerFxn8__C, ".econst:xdc_runtime_Log_Module__loggerFxn8__C");
asm("	.sect \".econst:xdc_runtime_Log_Module__loggerFxn8__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Log_Module__loggerFxn8__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Log_Module__loggerFxn8__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Log_Module__loggerFxn8 xdc_runtime_Log_Module__loggerFxn8__C = ((const CT__xdc_runtime_Log_Module__loggerFxn8)NULL);

/* Object__count__C */
#pragma DATA_SECTION(xdc_runtime_Log_Object__count__C, ".econst:xdc_runtime_Log_Object__count__C");
asm("	.sect \".econst:xdc_runtime_Log_Object__count__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Log_Object__count__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Log_Object__count__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Log_Object__count xdc_runtime_Log_Object__count__C = 0;

/* Object__heap__C */
#pragma DATA_SECTION(xdc_runtime_Log_Object__heap__C, ".econst:xdc_runtime_Log_Object__heap__C");
asm("	.sect \".econst:xdc_runtime_Log_Object__heap__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Log_Object__heap__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Log_Object__heap__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Log_Object__heap xdc_runtime_Log_Object__heap__C = NULL;

/* Object__sizeof__C */
#pragma DATA_SECTION(xdc_runtime_Log_Object__sizeof__C, ".econst:xdc_runtime_Log_Object__sizeof__C");
asm("	.sect \".econst:xdc_runtime_Log_Object__sizeof__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Log_Object__sizeof__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Log_Object__sizeof__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Log_Object__sizeof xdc_runtime_Log_Object__sizeof__C = 0;

/* Object__table__C */
#pragma DATA_SECTION(xdc_runtime_Log_Object__table__C, ".econst:xdc_runtime_Log_Object__table__C");
asm("	.sect \".econst:xdc_runtime_Log_Object__table__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Log_Object__table__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Log_Object__table__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Log_Object__table xdc_runtime_Log_Object__table__C = NULL;

/* L_construct__C */
#pragma DATA_SECTION(xdc_runtime_Log_L_construct__C, ".econst:xdc_runtime_Log_L_construct__C");
asm("	.sect \".econst:xdc_runtime_Log_L_construct__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Log_L_construct__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Log_L_construct__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Log_L_construct xdc_runtime_Log_L_construct__C = (((xdc_runtime_Log_Event)4625) << 16 | 4);

/* L_create__C */
#pragma DATA_SECTION(xdc_runtime_Log_L_create__C, ".econst:xdc_runtime_Log_L_create__C");
asm("	.sect \".econst:xdc_runtime_Log_L_create__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Log_L_create__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Log_L_create__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Log_L_create xdc_runtime_Log_L_create__C = (((xdc_runtime_Log_Event)4649) << 16 | 4);

/* L_destruct__C */
#pragma DATA_SECTION(xdc_runtime_Log_L_destruct__C, ".econst:xdc_runtime_Log_L_destruct__C");
asm("	.sect \".econst:xdc_runtime_Log_L_destruct__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Log_L_destruct__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Log_L_destruct__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Log_L_destruct xdc_runtime_Log_L_destruct__C = (((xdc_runtime_Log_Event)4670) << 16 | 4);

/* L_delete__C */
#pragma DATA_SECTION(xdc_runtime_Log_L_delete__C, ".econst:xdc_runtime_Log_L_delete__C");
asm("	.sect \".econst:xdc_runtime_Log_L_delete__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Log_L_delete__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Log_L_delete__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Log_L_delete xdc_runtime_Log_L_delete__C = (((xdc_runtime_Log_Event)4689) << 16 | 4);

/* L_error__C */
#pragma DATA_SECTION(xdc_runtime_Log_L_error__C, ".econst:xdc_runtime_Log_L_error__C");
asm("	.sect \".econst:xdc_runtime_Log_L_error__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Log_L_error__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Log_L_error__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Log_L_error xdc_runtime_Log_L_error__C = (((xdc_runtime_Log_Event)4706) << 16 | 192);

/* L_warning__C */
#pragma DATA_SECTION(xdc_runtime_Log_L_warning__C, ".econst:xdc_runtime_Log_L_warning__C");
asm("	.sect \".econst:xdc_runtime_Log_L_warning__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Log_L_warning__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Log_L_warning__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Log_L_warning xdc_runtime_Log_L_warning__C = (((xdc_runtime_Log_Event)4720) << 16 | 224);

/* L_info__C */
#pragma DATA_SECTION(xdc_runtime_Log_L_info__C, ".econst:xdc_runtime_Log_L_info__C");
asm("	.sect \".econst:xdc_runtime_Log_L_info__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Log_L_info__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Log_L_info__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Log_L_info xdc_runtime_Log_L_info__C = (((xdc_runtime_Log_Event)4736) << 16 | 16384);

/* L_start__C */
#pragma DATA_SECTION(xdc_runtime_Log_L_start__C, ".econst:xdc_runtime_Log_L_start__C");
asm("	.sect \".econst:xdc_runtime_Log_L_start__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Log_L_start__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Log_L_start__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Log_L_start xdc_runtime_Log_L_start__C = (((xdc_runtime_Log_Event)4743) << 16 | 32768);

/* L_stop__C */
#pragma DATA_SECTION(xdc_runtime_Log_L_stop__C, ".econst:xdc_runtime_Log_L_stop__C");
asm("	.sect \".econst:xdc_runtime_Log_L_stop__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Log_L_stop__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Log_L_stop__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Log_L_stop xdc_runtime_Log_L_stop__C = (((xdc_runtime_Log_Event)4754) << 16 | 32768);

/* L_startInstance__C */
#pragma DATA_SECTION(xdc_runtime_Log_L_startInstance__C, ".econst:xdc_runtime_Log_L_startInstance__C");
asm("	.sect \".econst:xdc_runtime_Log_L_startInstance__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Log_L_startInstance__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Log_L_startInstance__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Log_L_startInstance xdc_runtime_Log_L_startInstance__C = (((xdc_runtime_Log_Event)4764) << 16 | 32768);

/* L_stopInstance__C */
#pragma DATA_SECTION(xdc_runtime_Log_L_stopInstance__C, ".econst:xdc_runtime_Log_L_stopInstance__C");
asm("	.sect \".econst:xdc_runtime_Log_L_stopInstance__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Log_L_stopInstance__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Log_L_stopInstance__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Log_L_stopInstance xdc_runtime_Log_L_stopInstance__C = (((xdc_runtime_Log_Event)4783) << 16 | 32768);


/*
 * ======== xdc.runtime.LoggerBuf INITIALIZERS ========
 */

/* Object__DESC__C */
__FAR__ const xdc_runtime_Core_ObjDesc xdc_runtime_LoggerBuf_Object__DESC__C;

/* Object__PARAMS__C */
#pragma DATA_SECTION(xdc_runtime_LoggerBuf_Object__PARAMS__C, ".econst:xdc_runtime_LoggerBuf_Object__PARAMS__C");
asm("	.sect \".econst:xdc_runtime_LoggerBuf_Object__PARAMS__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_LoggerBuf_Object__PARAMS__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_LoggerBuf_Object__PARAMS__C\"");
asm("	.clink ");

__FAR__ const xdc_runtime_LoggerBuf_Params xdc_runtime_LoggerBuf_Object__PARAMS__C = {
    sizeof (xdc_runtime_LoggerBuf_Params), /* __size */
    NULL, /* __self */
    NULL, /* __fxns */
    (xdc_runtime_IInstance_Params*)&xdc_runtime_LoggerBuf_Object__PARAMS__C.__iprms, /* instance */
    (xdc_UInt)0x40,  /* numEntries */
    xdc_runtime_LoggerBuf_BufType_CIRCULAR,  /* bufType */
    0,  /* exitFlush */
    0,  /* bufHeap */
    {
        sizeof (xdc_runtime_IInstance_Params), /* __size */
        0,  /* name */
    },  /* instance */
};

/* --> xdc_runtime_LoggerBuf_Instance_State_0_entryArr__A */
__T1_xdc_runtime_LoggerBuf_Instance_State__entryArr xdc_runtime_LoggerBuf_Instance_State_0_entryArr__A[32];

/* Module__root__V */
xdc_runtime_LoggerBuf_Module__ xdc_runtime_LoggerBuf_Module__root__V = {
    {&xdc_runtime_LoggerBuf_Module__root__V.link,  /* link.next */
    &xdc_runtime_LoggerBuf_Module__root__V.link},  /* link.prev */
};

/* Object__table__V */
xdc_runtime_LoggerBuf_Object__ xdc_runtime_LoggerBuf_Object__table__V[1] = {
    {/* instance#0 */
        &xdc_runtime_LoggerBuf_Module__FXNS__C,
        0,  /* bufHeap */
        ((void*)xdc_runtime_LoggerBuf_Instance_State_0_entryArr__A),  /* entryArr */
        ((xdc_runtime_LoggerBuf_Entry*)(&xdc_runtime_LoggerBuf_Instance_State_0_entryArr__A[0])),  /* curEntry */
        ((xdc_runtime_LoggerBuf_Entry*)(&xdc_runtime_LoggerBuf_Instance_State_0_entryArr__A[31])),  /* endEntry */
        ((xdc_runtime_LoggerBuf_Entry*)(&xdc_runtime_LoggerBuf_Instance_State_0_entryArr__A[0])),  /* readEntry */
        (xdc_Bits32)0x1,  /* serial */
        (xdc_UInt16)0x20,  /* numEntries */
        (xdc_Int8)0x0,  /* advance */
        0,  /* enabled */
        0,  /* flush */
    },
};

/* Module__state__V */
#if defined (__ICCARM__)
#pragma location = ".data_xdc_runtime_LoggerBuf_Module__state__V"
#endif
#if defined(__GNUC__) && !(defined(__MACH__) && defined(__APPLE__))
#ifndef __ti__
xdc_runtime_LoggerBuf_Module_State__ xdc_runtime_LoggerBuf_Module__state__V __attribute__ ((section(".data_xdc_runtime_LoggerBuf_Module__state__V")));
#elif defined(__clang__)
xdc_runtime_LoggerBuf_Module_State__ xdc_runtime_LoggerBuf_Module__state__V __attribute__ ((section(".data:xdc_runtime_LoggerBuf_Module__state__V")));
#endif
#endif
xdc_runtime_LoggerBuf_Module_State__ xdc_runtime_LoggerBuf_Module__state__V = {
    (xdc_Bits16)0x0,  /* level1 */
    (xdc_Bits16)0x0,  /* level2 */
    (xdc_Bits16)0x0,  /* level3 */
};

/* Module__diagsEnabled__C */
#pragma DATA_SECTION(xdc_runtime_LoggerBuf_Module__diagsEnabled__C, ".econst:xdc_runtime_LoggerBuf_Module__diagsEnabled__C");
asm("	.sect \".econst:xdc_runtime_LoggerBuf_Module__diagsEnabled__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_LoggerBuf_Module__diagsEnabled__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_LoggerBuf_Module__diagsEnabled__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_LoggerBuf_Module__diagsEnabled xdc_runtime_LoggerBuf_Module__diagsEnabled__C = (xdc_Bits32)0x10;

/* Module__diagsIncluded__C */
#pragma DATA_SECTION(xdc_runtime_LoggerBuf_Module__diagsIncluded__C, ".econst:xdc_runtime_LoggerBuf_Module__diagsIncluded__C");
asm("	.sect \".econst:xdc_runtime_LoggerBuf_Module__diagsIncluded__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_LoggerBuf_Module__diagsIncluded__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_LoggerBuf_Module__diagsIncluded__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_LoggerBuf_Module__diagsIncluded xdc_runtime_LoggerBuf_Module__diagsIncluded__C = (xdc_Bits32)0x10;

/* Module__diagsMask__C */
#pragma DATA_SECTION(xdc_runtime_LoggerBuf_Module__diagsMask__C, ".econst:xdc_runtime_LoggerBuf_Module__diagsMask__C");
asm("	.sect \".econst:xdc_runtime_LoggerBuf_Module__diagsMask__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_LoggerBuf_Module__diagsMask__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_LoggerBuf_Module__diagsMask__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_LoggerBuf_Module__diagsMask xdc_runtime_LoggerBuf_Module__diagsMask__C = ((const CT__xdc_runtime_LoggerBuf_Module__diagsMask)NULL);

/* Module__gateObj__C */
#pragma DATA_SECTION(xdc_runtime_LoggerBuf_Module__gateObj__C, ".econst:xdc_runtime_LoggerBuf_Module__gateObj__C");
asm("	.sect \".econst:xdc_runtime_LoggerBuf_Module__gateObj__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_LoggerBuf_Module__gateObj__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_LoggerBuf_Module__gateObj__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_LoggerBuf_Module__gateObj xdc_runtime_LoggerBuf_Module__gateObj__C = ((const CT__xdc_runtime_LoggerBuf_Module__gateObj)((void*)(xdc_runtime_IGateProvider_Handle)&ti_sysbios_gates_GateHwi_Object__table__V[0]));

/* Module__gatePrms__C */
#pragma DATA_SECTION(xdc_runtime_LoggerBuf_Module__gatePrms__C, ".econst:xdc_runtime_LoggerBuf_Module__gatePrms__C");
asm("	.sect \".econst:xdc_runtime_LoggerBuf_Module__gatePrms__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_LoggerBuf_Module__gatePrms__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_LoggerBuf_Module__gatePrms__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_LoggerBuf_Module__gatePrms xdc_runtime_LoggerBuf_Module__gatePrms__C = ((const CT__xdc_runtime_LoggerBuf_Module__gatePrms)NULL);

/* Module__id__C */
#pragma DATA_SECTION(xdc_runtime_LoggerBuf_Module__id__C, ".econst:xdc_runtime_LoggerBuf_Module__id__C");
asm("	.sect \".econst:xdc_runtime_LoggerBuf_Module__id__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_LoggerBuf_Module__id__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_LoggerBuf_Module__id__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_LoggerBuf_Module__id xdc_runtime_LoggerBuf_Module__id__C = (xdc_Bits16)0x8009;

/* Module__loggerDefined__C */
#pragma DATA_SECTION(xdc_runtime_LoggerBuf_Module__loggerDefined__C, ".econst:xdc_runtime_LoggerBuf_Module__loggerDefined__C");
asm("	.sect \".econst:xdc_runtime_LoggerBuf_Module__loggerDefined__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_LoggerBuf_Module__loggerDefined__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_LoggerBuf_Module__loggerDefined__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_LoggerBuf_Module__loggerDefined xdc_runtime_LoggerBuf_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
#pragma DATA_SECTION(xdc_runtime_LoggerBuf_Module__loggerObj__C, ".econst:xdc_runtime_LoggerBuf_Module__loggerObj__C");
asm("	.sect \".econst:xdc_runtime_LoggerBuf_Module__loggerObj__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_LoggerBuf_Module__loggerObj__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_LoggerBuf_Module__loggerObj__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_LoggerBuf_Module__loggerObj xdc_runtime_LoggerBuf_Module__loggerObj__C = ((const CT__xdc_runtime_LoggerBuf_Module__loggerObj)NULL);

/* Module__loggerFxn0__C */
#pragma DATA_SECTION(xdc_runtime_LoggerBuf_Module__loggerFxn0__C, ".econst:xdc_runtime_LoggerBuf_Module__loggerFxn0__C");
asm("	.sect \".econst:xdc_runtime_LoggerBuf_Module__loggerFxn0__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_LoggerBuf_Module__loggerFxn0__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_LoggerBuf_Module__loggerFxn0__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_LoggerBuf_Module__loggerFxn0 xdc_runtime_LoggerBuf_Module__loggerFxn0__C = ((const CT__xdc_runtime_LoggerBuf_Module__loggerFxn0)NULL);

/* Module__loggerFxn1__C */
#pragma DATA_SECTION(xdc_runtime_LoggerBuf_Module__loggerFxn1__C, ".econst:xdc_runtime_LoggerBuf_Module__loggerFxn1__C");
asm("	.sect \".econst:xdc_runtime_LoggerBuf_Module__loggerFxn1__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_LoggerBuf_Module__loggerFxn1__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_LoggerBuf_Module__loggerFxn1__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_LoggerBuf_Module__loggerFxn1 xdc_runtime_LoggerBuf_Module__loggerFxn1__C = ((const CT__xdc_runtime_LoggerBuf_Module__loggerFxn1)NULL);

/* Module__loggerFxn2__C */
#pragma DATA_SECTION(xdc_runtime_LoggerBuf_Module__loggerFxn2__C, ".econst:xdc_runtime_LoggerBuf_Module__loggerFxn2__C");
asm("	.sect \".econst:xdc_runtime_LoggerBuf_Module__loggerFxn2__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_LoggerBuf_Module__loggerFxn2__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_LoggerBuf_Module__loggerFxn2__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_LoggerBuf_Module__loggerFxn2 xdc_runtime_LoggerBuf_Module__loggerFxn2__C = ((const CT__xdc_runtime_LoggerBuf_Module__loggerFxn2)NULL);

/* Module__loggerFxn4__C */
#pragma DATA_SECTION(xdc_runtime_LoggerBuf_Module__loggerFxn4__C, ".econst:xdc_runtime_LoggerBuf_Module__loggerFxn4__C");
asm("	.sect \".econst:xdc_runtime_LoggerBuf_Module__loggerFxn4__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_LoggerBuf_Module__loggerFxn4__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_LoggerBuf_Module__loggerFxn4__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_LoggerBuf_Module__loggerFxn4 xdc_runtime_LoggerBuf_Module__loggerFxn4__C = ((const CT__xdc_runtime_LoggerBuf_Module__loggerFxn4)NULL);

/* Module__loggerFxn8__C */
#pragma DATA_SECTION(xdc_runtime_LoggerBuf_Module__loggerFxn8__C, ".econst:xdc_runtime_LoggerBuf_Module__loggerFxn8__C");
asm("	.sect \".econst:xdc_runtime_LoggerBuf_Module__loggerFxn8__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_LoggerBuf_Module__loggerFxn8__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_LoggerBuf_Module__loggerFxn8__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_LoggerBuf_Module__loggerFxn8 xdc_runtime_LoggerBuf_Module__loggerFxn8__C = ((const CT__xdc_runtime_LoggerBuf_Module__loggerFxn8)NULL);

/* Object__count__C */
#pragma DATA_SECTION(xdc_runtime_LoggerBuf_Object__count__C, ".econst:xdc_runtime_LoggerBuf_Object__count__C");
asm("	.sect \".econst:xdc_runtime_LoggerBuf_Object__count__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_LoggerBuf_Object__count__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_LoggerBuf_Object__count__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_LoggerBuf_Object__count xdc_runtime_LoggerBuf_Object__count__C = 1;

/* Object__heap__C */
#pragma DATA_SECTION(xdc_runtime_LoggerBuf_Object__heap__C, ".econst:xdc_runtime_LoggerBuf_Object__heap__C");
asm("	.sect \".econst:xdc_runtime_LoggerBuf_Object__heap__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_LoggerBuf_Object__heap__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_LoggerBuf_Object__heap__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_LoggerBuf_Object__heap xdc_runtime_LoggerBuf_Object__heap__C = NULL;

/* Object__sizeof__C */
#pragma DATA_SECTION(xdc_runtime_LoggerBuf_Object__sizeof__C, ".econst:xdc_runtime_LoggerBuf_Object__sizeof__C");
asm("	.sect \".econst:xdc_runtime_LoggerBuf_Object__sizeof__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_LoggerBuf_Object__sizeof__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_LoggerBuf_Object__sizeof__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_LoggerBuf_Object__sizeof xdc_runtime_LoggerBuf_Object__sizeof__C = sizeof(xdc_runtime_LoggerBuf_Object__);

/* Object__table__C */
#pragma DATA_SECTION(xdc_runtime_LoggerBuf_Object__table__C, ".econst:xdc_runtime_LoggerBuf_Object__table__C");
asm("	.sect \".econst:xdc_runtime_LoggerBuf_Object__table__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_LoggerBuf_Object__table__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_LoggerBuf_Object__table__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_LoggerBuf_Object__table xdc_runtime_LoggerBuf_Object__table__C = xdc_runtime_LoggerBuf_Object__table__V;

/* filterByLevel__C */
#pragma DATA_SECTION(xdc_runtime_LoggerBuf_filterByLevel__C, ".econst:xdc_runtime_LoggerBuf_filterByLevel__C");
asm("	.sect \".econst:xdc_runtime_LoggerBuf_filterByLevel__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_LoggerBuf_filterByLevel__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_LoggerBuf_filterByLevel__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_LoggerBuf_filterByLevel xdc_runtime_LoggerBuf_filterByLevel__C = 0;

/* E_badLevel__C */
#pragma DATA_SECTION(xdc_runtime_LoggerBuf_E_badLevel__C, ".econst:xdc_runtime_LoggerBuf_E_badLevel__C");
asm("	.sect \".econst:xdc_runtime_LoggerBuf_E_badLevel__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_LoggerBuf_E_badLevel__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_LoggerBuf_E_badLevel__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_LoggerBuf_E_badLevel xdc_runtime_LoggerBuf_E_badLevel__C = (((xdc_runtime_Error_Id)3643) << 16 | 0U);

/* enableFlush__C */
#pragma DATA_SECTION(xdc_runtime_LoggerBuf_enableFlush__C, ".econst:xdc_runtime_LoggerBuf_enableFlush__C");
asm("	.sect \".econst:xdc_runtime_LoggerBuf_enableFlush__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_LoggerBuf_enableFlush__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_LoggerBuf_enableFlush__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_LoggerBuf_enableFlush xdc_runtime_LoggerBuf_enableFlush__C = 0;

/* statusLogger__C */
#pragma DATA_SECTION(xdc_runtime_LoggerBuf_statusLogger__C, ".econst:xdc_runtime_LoggerBuf_statusLogger__C");
asm("	.sect \".econst:xdc_runtime_LoggerBuf_statusLogger__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_LoggerBuf_statusLogger__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_LoggerBuf_statusLogger__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_LoggerBuf_statusLogger xdc_runtime_LoggerBuf_statusLogger__C = 0;

/* level1Mask__C */
#pragma DATA_SECTION(xdc_runtime_LoggerBuf_level1Mask__C, ".econst:xdc_runtime_LoggerBuf_level1Mask__C");
asm("	.sect \".econst:xdc_runtime_LoggerBuf_level1Mask__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_LoggerBuf_level1Mask__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_LoggerBuf_level1Mask__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_LoggerBuf_level1Mask xdc_runtime_LoggerBuf_level1Mask__C = (xdc_Bits16)0x0;

/* level2Mask__C */
#pragma DATA_SECTION(xdc_runtime_LoggerBuf_level2Mask__C, ".econst:xdc_runtime_LoggerBuf_level2Mask__C");
asm("	.sect \".econst:xdc_runtime_LoggerBuf_level2Mask__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_LoggerBuf_level2Mask__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_LoggerBuf_level2Mask__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_LoggerBuf_level2Mask xdc_runtime_LoggerBuf_level2Mask__C = (xdc_Bits16)0x0;

/* level3Mask__C */
#pragma DATA_SECTION(xdc_runtime_LoggerBuf_level3Mask__C, ".econst:xdc_runtime_LoggerBuf_level3Mask__C");
asm("	.sect \".econst:xdc_runtime_LoggerBuf_level3Mask__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_LoggerBuf_level3Mask__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_LoggerBuf_level3Mask__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_LoggerBuf_level3Mask xdc_runtime_LoggerBuf_level3Mask__C = (xdc_Bits16)0x0;

/* level4Mask__C */
#pragma DATA_SECTION(xdc_runtime_LoggerBuf_level4Mask__C, ".econst:xdc_runtime_LoggerBuf_level4Mask__C");
asm("	.sect \".econst:xdc_runtime_LoggerBuf_level4Mask__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_LoggerBuf_level4Mask__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_LoggerBuf_level4Mask__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_LoggerBuf_level4Mask xdc_runtime_LoggerBuf_level4Mask__C = (xdc_Bits16)0xff87;


/*
 * ======== xdc.runtime.LoggerBuf_Module_GateProxy INITIALIZERS ========
 */


/*
 * ======== xdc.runtime.LoggerBuf_TimestampProxy INITIALIZERS ========
 */


/*
 * ======== xdc.runtime.Main INITIALIZERS ========
 */

/* Module__diagsEnabled__C */
#pragma DATA_SECTION(xdc_runtime_Main_Module__diagsEnabled__C, ".econst:xdc_runtime_Main_Module__diagsEnabled__C");
asm("	.sect \".econst:xdc_runtime_Main_Module__diagsEnabled__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Main_Module__diagsEnabled__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Main_Module__diagsEnabled__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Main_Module__diagsEnabled xdc_runtime_Main_Module__diagsEnabled__C = (xdc_Bits32)0x4090;

/* Module__diagsIncluded__C */
#pragma DATA_SECTION(xdc_runtime_Main_Module__diagsIncluded__C, ".econst:xdc_runtime_Main_Module__diagsIncluded__C");
asm("	.sect \".econst:xdc_runtime_Main_Module__diagsIncluded__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Main_Module__diagsIncluded__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Main_Module__diagsIncluded__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Main_Module__diagsIncluded xdc_runtime_Main_Module__diagsIncluded__C = (xdc_Bits32)0x4090;

/* Module__diagsMask__C */
#pragma DATA_SECTION(xdc_runtime_Main_Module__diagsMask__C, ".econst:xdc_runtime_Main_Module__diagsMask__C");
asm("	.sect \".econst:xdc_runtime_Main_Module__diagsMask__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Main_Module__diagsMask__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Main_Module__diagsMask__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Main_Module__diagsMask xdc_runtime_Main_Module__diagsMask__C = ((const CT__xdc_runtime_Main_Module__diagsMask)NULL);

/* Module__gateObj__C */
#pragma DATA_SECTION(xdc_runtime_Main_Module__gateObj__C, ".econst:xdc_runtime_Main_Module__gateObj__C");
asm("	.sect \".econst:xdc_runtime_Main_Module__gateObj__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Main_Module__gateObj__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Main_Module__gateObj__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Main_Module__gateObj xdc_runtime_Main_Module__gateObj__C = ((const CT__xdc_runtime_Main_Module__gateObj)((void*)(xdc_runtime_IGateProvider_Handle)&ti_sysbios_gates_GateHwi_Object__table__V[0]));

/* Module__gatePrms__C */
#pragma DATA_SECTION(xdc_runtime_Main_Module__gatePrms__C, ".econst:xdc_runtime_Main_Module__gatePrms__C");
asm("	.sect \".econst:xdc_runtime_Main_Module__gatePrms__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Main_Module__gatePrms__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Main_Module__gatePrms__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Main_Module__gatePrms xdc_runtime_Main_Module__gatePrms__C = ((const CT__xdc_runtime_Main_Module__gatePrms)NULL);

/* Module__id__C */
#pragma DATA_SECTION(xdc_runtime_Main_Module__id__C, ".econst:xdc_runtime_Main_Module__id__C");
asm("	.sect \".econst:xdc_runtime_Main_Module__id__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Main_Module__id__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Main_Module__id__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Main_Module__id xdc_runtime_Main_Module__id__C = (xdc_Bits16)0x800a;

/* Module__loggerDefined__C */
#pragma DATA_SECTION(xdc_runtime_Main_Module__loggerDefined__C, ".econst:xdc_runtime_Main_Module__loggerDefined__C");
asm("	.sect \".econst:xdc_runtime_Main_Module__loggerDefined__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Main_Module__loggerDefined__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Main_Module__loggerDefined__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Main_Module__loggerDefined xdc_runtime_Main_Module__loggerDefined__C = 1;

/* Module__loggerObj__C */
#pragma DATA_SECTION(xdc_runtime_Main_Module__loggerObj__C, ".econst:xdc_runtime_Main_Module__loggerObj__C");
asm("	.sect \".econst:xdc_runtime_Main_Module__loggerObj__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Main_Module__loggerObj__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Main_Module__loggerObj__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Main_Module__loggerObj xdc_runtime_Main_Module__loggerObj__C = ((const CT__xdc_runtime_Main_Module__loggerObj)((void*)(xdc_runtime_ILogger_Handle)&xdc_runtime_LoggerBuf_Object__table__V[0]));

/* Module__loggerFxn0__C */
#pragma DATA_SECTION(xdc_runtime_Main_Module__loggerFxn0__C, ".econst:xdc_runtime_Main_Module__loggerFxn0__C");
asm("	.sect \".econst:xdc_runtime_Main_Module__loggerFxn0__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Main_Module__loggerFxn0__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Main_Module__loggerFxn0__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Main_Module__loggerFxn0 xdc_runtime_Main_Module__loggerFxn0__C = ((const CT__xdc_runtime_Main_Module__loggerFxn0)(xdc_runtime_LoggerBuf_write0));

/* Module__loggerFxn1__C */
#pragma DATA_SECTION(xdc_runtime_Main_Module__loggerFxn1__C, ".econst:xdc_runtime_Main_Module__loggerFxn1__C");
asm("	.sect \".econst:xdc_runtime_Main_Module__loggerFxn1__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Main_Module__loggerFxn1__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Main_Module__loggerFxn1__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Main_Module__loggerFxn1 xdc_runtime_Main_Module__loggerFxn1__C = ((const CT__xdc_runtime_Main_Module__loggerFxn1)(xdc_runtime_LoggerBuf_write1));

/* Module__loggerFxn2__C */
#pragma DATA_SECTION(xdc_runtime_Main_Module__loggerFxn2__C, ".econst:xdc_runtime_Main_Module__loggerFxn2__C");
asm("	.sect \".econst:xdc_runtime_Main_Module__loggerFxn2__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Main_Module__loggerFxn2__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Main_Module__loggerFxn2__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Main_Module__loggerFxn2 xdc_runtime_Main_Module__loggerFxn2__C = ((const CT__xdc_runtime_Main_Module__loggerFxn2)(xdc_runtime_LoggerBuf_write2));

/* Module__loggerFxn4__C */
#pragma DATA_SECTION(xdc_runtime_Main_Module__loggerFxn4__C, ".econst:xdc_runtime_Main_Module__loggerFxn4__C");
asm("	.sect \".econst:xdc_runtime_Main_Module__loggerFxn4__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Main_Module__loggerFxn4__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Main_Module__loggerFxn4__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Main_Module__loggerFxn4 xdc_runtime_Main_Module__loggerFxn4__C = ((const CT__xdc_runtime_Main_Module__loggerFxn4)(xdc_runtime_LoggerBuf_write4));

/* Module__loggerFxn8__C */
#pragma DATA_SECTION(xdc_runtime_Main_Module__loggerFxn8__C, ".econst:xdc_runtime_Main_Module__loggerFxn8__C");
asm("	.sect \".econst:xdc_runtime_Main_Module__loggerFxn8__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Main_Module__loggerFxn8__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Main_Module__loggerFxn8__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Main_Module__loggerFxn8 xdc_runtime_Main_Module__loggerFxn8__C = ((const CT__xdc_runtime_Main_Module__loggerFxn8)(xdc_runtime_LoggerBuf_write8));

/* Object__count__C */
#pragma DATA_SECTION(xdc_runtime_Main_Object__count__C, ".econst:xdc_runtime_Main_Object__count__C");
asm("	.sect \".econst:xdc_runtime_Main_Object__count__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Main_Object__count__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Main_Object__count__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Main_Object__count xdc_runtime_Main_Object__count__C = 0;

/* Object__heap__C */
#pragma DATA_SECTION(xdc_runtime_Main_Object__heap__C, ".econst:xdc_runtime_Main_Object__heap__C");
asm("	.sect \".econst:xdc_runtime_Main_Object__heap__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Main_Object__heap__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Main_Object__heap__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Main_Object__heap xdc_runtime_Main_Object__heap__C = NULL;

/* Object__sizeof__C */
#pragma DATA_SECTION(xdc_runtime_Main_Object__sizeof__C, ".econst:xdc_runtime_Main_Object__sizeof__C");
asm("	.sect \".econst:xdc_runtime_Main_Object__sizeof__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Main_Object__sizeof__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Main_Object__sizeof__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Main_Object__sizeof xdc_runtime_Main_Object__sizeof__C = 0;

/* Object__table__C */
#pragma DATA_SECTION(xdc_runtime_Main_Object__table__C, ".econst:xdc_runtime_Main_Object__table__C");
asm("	.sect \".econst:xdc_runtime_Main_Object__table__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Main_Object__table__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Main_Object__table__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Main_Object__table xdc_runtime_Main_Object__table__C = NULL;


/*
 * ======== xdc.runtime.Main_Module_GateProxy INITIALIZERS ========
 */


/*
 * ======== xdc.runtime.Memory INITIALIZERS ========
 */

/* Module__state__V */
#if defined (__ICCARM__)
#pragma location = ".data_xdc_runtime_Memory_Module__state__V"
#endif
#if defined(__GNUC__) && !(defined(__MACH__) && defined(__APPLE__))
#ifndef __ti__
xdc_runtime_Memory_Module_State__ xdc_runtime_Memory_Module__state__V __attribute__ ((section(".data_xdc_runtime_Memory_Module__state__V")));
#elif defined(__clang__)
xdc_runtime_Memory_Module_State__ xdc_runtime_Memory_Module__state__V __attribute__ ((section(".data:xdc_runtime_Memory_Module__state__V")));
#endif
#endif
xdc_runtime_Memory_Module_State__ xdc_runtime_Memory_Module__state__V = {
    (xdc_SizeT)0x2,  /* maxDefaultTypeAlign */
};

/* Module__diagsEnabled__C */
#pragma DATA_SECTION(xdc_runtime_Memory_Module__diagsEnabled__C, ".econst:xdc_runtime_Memory_Module__diagsEnabled__C");
asm("	.sect \".econst:xdc_runtime_Memory_Module__diagsEnabled__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Memory_Module__diagsEnabled__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Memory_Module__diagsEnabled__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Memory_Module__diagsEnabled xdc_runtime_Memory_Module__diagsEnabled__C = (xdc_Bits32)0x10;

/* Module__diagsIncluded__C */
#pragma DATA_SECTION(xdc_runtime_Memory_Module__diagsIncluded__C, ".econst:xdc_runtime_Memory_Module__diagsIncluded__C");
asm("	.sect \".econst:xdc_runtime_Memory_Module__diagsIncluded__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Memory_Module__diagsIncluded__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Memory_Module__diagsIncluded__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Memory_Module__diagsIncluded xdc_runtime_Memory_Module__diagsIncluded__C = (xdc_Bits32)0x10;

/* Module__diagsMask__C */
#pragma DATA_SECTION(xdc_runtime_Memory_Module__diagsMask__C, ".econst:xdc_runtime_Memory_Module__diagsMask__C");
asm("	.sect \".econst:xdc_runtime_Memory_Module__diagsMask__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Memory_Module__diagsMask__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Memory_Module__diagsMask__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Memory_Module__diagsMask xdc_runtime_Memory_Module__diagsMask__C = ((const CT__xdc_runtime_Memory_Module__diagsMask)NULL);

/* Module__gateObj__C */
#pragma DATA_SECTION(xdc_runtime_Memory_Module__gateObj__C, ".econst:xdc_runtime_Memory_Module__gateObj__C");
asm("	.sect \".econst:xdc_runtime_Memory_Module__gateObj__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Memory_Module__gateObj__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Memory_Module__gateObj__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Memory_Module__gateObj xdc_runtime_Memory_Module__gateObj__C = ((const CT__xdc_runtime_Memory_Module__gateObj)NULL);

/* Module__gatePrms__C */
#pragma DATA_SECTION(xdc_runtime_Memory_Module__gatePrms__C, ".econst:xdc_runtime_Memory_Module__gatePrms__C");
asm("	.sect \".econst:xdc_runtime_Memory_Module__gatePrms__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Memory_Module__gatePrms__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Memory_Module__gatePrms__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Memory_Module__gatePrms xdc_runtime_Memory_Module__gatePrms__C = ((const CT__xdc_runtime_Memory_Module__gatePrms)NULL);

/* Module__id__C */
#pragma DATA_SECTION(xdc_runtime_Memory_Module__id__C, ".econst:xdc_runtime_Memory_Module__id__C");
asm("	.sect \".econst:xdc_runtime_Memory_Module__id__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Memory_Module__id__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Memory_Module__id__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Memory_Module__id xdc_runtime_Memory_Module__id__C = (xdc_Bits16)0x800b;

/* Module__loggerDefined__C */
#pragma DATA_SECTION(xdc_runtime_Memory_Module__loggerDefined__C, ".econst:xdc_runtime_Memory_Module__loggerDefined__C");
asm("	.sect \".econst:xdc_runtime_Memory_Module__loggerDefined__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Memory_Module__loggerDefined__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Memory_Module__loggerDefined__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Memory_Module__loggerDefined xdc_runtime_Memory_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
#pragma DATA_SECTION(xdc_runtime_Memory_Module__loggerObj__C, ".econst:xdc_runtime_Memory_Module__loggerObj__C");
asm("	.sect \".econst:xdc_runtime_Memory_Module__loggerObj__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Memory_Module__loggerObj__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Memory_Module__loggerObj__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Memory_Module__loggerObj xdc_runtime_Memory_Module__loggerObj__C = ((const CT__xdc_runtime_Memory_Module__loggerObj)NULL);

/* Module__loggerFxn0__C */
#pragma DATA_SECTION(xdc_runtime_Memory_Module__loggerFxn0__C, ".econst:xdc_runtime_Memory_Module__loggerFxn0__C");
asm("	.sect \".econst:xdc_runtime_Memory_Module__loggerFxn0__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Memory_Module__loggerFxn0__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Memory_Module__loggerFxn0__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Memory_Module__loggerFxn0 xdc_runtime_Memory_Module__loggerFxn0__C = ((const CT__xdc_runtime_Memory_Module__loggerFxn0)NULL);

/* Module__loggerFxn1__C */
#pragma DATA_SECTION(xdc_runtime_Memory_Module__loggerFxn1__C, ".econst:xdc_runtime_Memory_Module__loggerFxn1__C");
asm("	.sect \".econst:xdc_runtime_Memory_Module__loggerFxn1__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Memory_Module__loggerFxn1__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Memory_Module__loggerFxn1__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Memory_Module__loggerFxn1 xdc_runtime_Memory_Module__loggerFxn1__C = ((const CT__xdc_runtime_Memory_Module__loggerFxn1)NULL);

/* Module__loggerFxn2__C */
#pragma DATA_SECTION(xdc_runtime_Memory_Module__loggerFxn2__C, ".econst:xdc_runtime_Memory_Module__loggerFxn2__C");
asm("	.sect \".econst:xdc_runtime_Memory_Module__loggerFxn2__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Memory_Module__loggerFxn2__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Memory_Module__loggerFxn2__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Memory_Module__loggerFxn2 xdc_runtime_Memory_Module__loggerFxn2__C = ((const CT__xdc_runtime_Memory_Module__loggerFxn2)NULL);

/* Module__loggerFxn4__C */
#pragma DATA_SECTION(xdc_runtime_Memory_Module__loggerFxn4__C, ".econst:xdc_runtime_Memory_Module__loggerFxn4__C");
asm("	.sect \".econst:xdc_runtime_Memory_Module__loggerFxn4__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Memory_Module__loggerFxn4__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Memory_Module__loggerFxn4__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Memory_Module__loggerFxn4 xdc_runtime_Memory_Module__loggerFxn4__C = ((const CT__xdc_runtime_Memory_Module__loggerFxn4)NULL);

/* Module__loggerFxn8__C */
#pragma DATA_SECTION(xdc_runtime_Memory_Module__loggerFxn8__C, ".econst:xdc_runtime_Memory_Module__loggerFxn8__C");
asm("	.sect \".econst:xdc_runtime_Memory_Module__loggerFxn8__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Memory_Module__loggerFxn8__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Memory_Module__loggerFxn8__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Memory_Module__loggerFxn8 xdc_runtime_Memory_Module__loggerFxn8__C = ((const CT__xdc_runtime_Memory_Module__loggerFxn8)NULL);

/* Object__count__C */
#pragma DATA_SECTION(xdc_runtime_Memory_Object__count__C, ".econst:xdc_runtime_Memory_Object__count__C");
asm("	.sect \".econst:xdc_runtime_Memory_Object__count__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Memory_Object__count__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Memory_Object__count__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Memory_Object__count xdc_runtime_Memory_Object__count__C = 0;

/* Object__heap__C */
#pragma DATA_SECTION(xdc_runtime_Memory_Object__heap__C, ".econst:xdc_runtime_Memory_Object__heap__C");
asm("	.sect \".econst:xdc_runtime_Memory_Object__heap__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Memory_Object__heap__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Memory_Object__heap__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Memory_Object__heap xdc_runtime_Memory_Object__heap__C = NULL;

/* Object__sizeof__C */
#pragma DATA_SECTION(xdc_runtime_Memory_Object__sizeof__C, ".econst:xdc_runtime_Memory_Object__sizeof__C");
asm("	.sect \".econst:xdc_runtime_Memory_Object__sizeof__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Memory_Object__sizeof__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Memory_Object__sizeof__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Memory_Object__sizeof xdc_runtime_Memory_Object__sizeof__C = 0;

/* Object__table__C */
#pragma DATA_SECTION(xdc_runtime_Memory_Object__table__C, ".econst:xdc_runtime_Memory_Object__table__C");
asm("	.sect \".econst:xdc_runtime_Memory_Object__table__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Memory_Object__table__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Memory_Object__table__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Memory_Object__table xdc_runtime_Memory_Object__table__C = NULL;

/* defaultHeapInstance__C */
#pragma DATA_SECTION(xdc_runtime_Memory_defaultHeapInstance__C, ".econst:xdc_runtime_Memory_defaultHeapInstance__C");
asm("	.sect \".econst:xdc_runtime_Memory_defaultHeapInstance__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Memory_defaultHeapInstance__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Memory_defaultHeapInstance__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Memory_defaultHeapInstance xdc_runtime_Memory_defaultHeapInstance__C = (xdc_runtime_IHeap_Handle)&ti_sysbios_heaps_HeapMem_Object__table__V[0];


/*
 * ======== xdc.runtime.Memory_HeapProxy INITIALIZERS ========
 */


/*
 * ======== xdc.runtime.Registry INITIALIZERS ========
 */

/* Module__state__V */
#if defined (__ICCARM__)
#pragma location = ".data_xdc_runtime_Registry_Module__state__V"
#endif
#if defined(__GNUC__) && !(defined(__MACH__) && defined(__APPLE__))
#ifndef __ti__
xdc_runtime_Registry_Module_State__ xdc_runtime_Registry_Module__state__V __attribute__ ((section(".data_xdc_runtime_Registry_Module__state__V")));
#elif defined(__clang__)
xdc_runtime_Registry_Module_State__ xdc_runtime_Registry_Module__state__V __attribute__ ((section(".data:xdc_runtime_Registry_Module__state__V")));
#endif
#endif
xdc_runtime_Registry_Module_State__ xdc_runtime_Registry_Module__state__V = {
    ((xdc_runtime_Types_RegDesc*)NULL),  /* listHead */
    (xdc_Bits16)0x7fff,  /* curId */
};

/* Module__diagsEnabled__C */
#pragma DATA_SECTION(xdc_runtime_Registry_Module__diagsEnabled__C, ".econst:xdc_runtime_Registry_Module__diagsEnabled__C");
asm("	.sect \".econst:xdc_runtime_Registry_Module__diagsEnabled__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Registry_Module__diagsEnabled__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Registry_Module__diagsEnabled__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Registry_Module__diagsEnabled xdc_runtime_Registry_Module__diagsEnabled__C = (xdc_Bits32)0x90;

/* Module__diagsIncluded__C */
#pragma DATA_SECTION(xdc_runtime_Registry_Module__diagsIncluded__C, ".econst:xdc_runtime_Registry_Module__diagsIncluded__C");
asm("	.sect \".econst:xdc_runtime_Registry_Module__diagsIncluded__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Registry_Module__diagsIncluded__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Registry_Module__diagsIncluded__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Registry_Module__diagsIncluded xdc_runtime_Registry_Module__diagsIncluded__C = (xdc_Bits32)0x90;

/* Module__diagsMask__C */
#pragma DATA_SECTION(xdc_runtime_Registry_Module__diagsMask__C, ".econst:xdc_runtime_Registry_Module__diagsMask__C");
asm("	.sect \".econst:xdc_runtime_Registry_Module__diagsMask__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Registry_Module__diagsMask__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Registry_Module__diagsMask__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Registry_Module__diagsMask xdc_runtime_Registry_Module__diagsMask__C = ((const CT__xdc_runtime_Registry_Module__diagsMask)NULL);

/* Module__gateObj__C */
#pragma DATA_SECTION(xdc_runtime_Registry_Module__gateObj__C, ".econst:xdc_runtime_Registry_Module__gateObj__C");
asm("	.sect \".econst:xdc_runtime_Registry_Module__gateObj__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Registry_Module__gateObj__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Registry_Module__gateObj__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Registry_Module__gateObj xdc_runtime_Registry_Module__gateObj__C = ((const CT__xdc_runtime_Registry_Module__gateObj)NULL);

/* Module__gatePrms__C */
#pragma DATA_SECTION(xdc_runtime_Registry_Module__gatePrms__C, ".econst:xdc_runtime_Registry_Module__gatePrms__C");
asm("	.sect \".econst:xdc_runtime_Registry_Module__gatePrms__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Registry_Module__gatePrms__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Registry_Module__gatePrms__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Registry_Module__gatePrms xdc_runtime_Registry_Module__gatePrms__C = ((const CT__xdc_runtime_Registry_Module__gatePrms)NULL);

/* Module__id__C */
#pragma DATA_SECTION(xdc_runtime_Registry_Module__id__C, ".econst:xdc_runtime_Registry_Module__id__C");
asm("	.sect \".econst:xdc_runtime_Registry_Module__id__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Registry_Module__id__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Registry_Module__id__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Registry_Module__id xdc_runtime_Registry_Module__id__C = (xdc_Bits16)0x800c;

/* Module__loggerDefined__C */
#pragma DATA_SECTION(xdc_runtime_Registry_Module__loggerDefined__C, ".econst:xdc_runtime_Registry_Module__loggerDefined__C");
asm("	.sect \".econst:xdc_runtime_Registry_Module__loggerDefined__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Registry_Module__loggerDefined__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Registry_Module__loggerDefined__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Registry_Module__loggerDefined xdc_runtime_Registry_Module__loggerDefined__C = 1;

/* Module__loggerObj__C */
#pragma DATA_SECTION(xdc_runtime_Registry_Module__loggerObj__C, ".econst:xdc_runtime_Registry_Module__loggerObj__C");
asm("	.sect \".econst:xdc_runtime_Registry_Module__loggerObj__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Registry_Module__loggerObj__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Registry_Module__loggerObj__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Registry_Module__loggerObj xdc_runtime_Registry_Module__loggerObj__C = ((const CT__xdc_runtime_Registry_Module__loggerObj)((void*)(xdc_runtime_ILogger_Handle)&xdc_runtime_LoggerBuf_Object__table__V[0]));

/* Module__loggerFxn0__C */
#pragma DATA_SECTION(xdc_runtime_Registry_Module__loggerFxn0__C, ".econst:xdc_runtime_Registry_Module__loggerFxn0__C");
asm("	.sect \".econst:xdc_runtime_Registry_Module__loggerFxn0__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Registry_Module__loggerFxn0__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Registry_Module__loggerFxn0__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Registry_Module__loggerFxn0 xdc_runtime_Registry_Module__loggerFxn0__C = ((const CT__xdc_runtime_Registry_Module__loggerFxn0)(xdc_runtime_LoggerBuf_write0));

/* Module__loggerFxn1__C */
#pragma DATA_SECTION(xdc_runtime_Registry_Module__loggerFxn1__C, ".econst:xdc_runtime_Registry_Module__loggerFxn1__C");
asm("	.sect \".econst:xdc_runtime_Registry_Module__loggerFxn1__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Registry_Module__loggerFxn1__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Registry_Module__loggerFxn1__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Registry_Module__loggerFxn1 xdc_runtime_Registry_Module__loggerFxn1__C = ((const CT__xdc_runtime_Registry_Module__loggerFxn1)(xdc_runtime_LoggerBuf_write1));

/* Module__loggerFxn2__C */
#pragma DATA_SECTION(xdc_runtime_Registry_Module__loggerFxn2__C, ".econst:xdc_runtime_Registry_Module__loggerFxn2__C");
asm("	.sect \".econst:xdc_runtime_Registry_Module__loggerFxn2__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Registry_Module__loggerFxn2__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Registry_Module__loggerFxn2__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Registry_Module__loggerFxn2 xdc_runtime_Registry_Module__loggerFxn2__C = ((const CT__xdc_runtime_Registry_Module__loggerFxn2)(xdc_runtime_LoggerBuf_write2));

/* Module__loggerFxn4__C */
#pragma DATA_SECTION(xdc_runtime_Registry_Module__loggerFxn4__C, ".econst:xdc_runtime_Registry_Module__loggerFxn4__C");
asm("	.sect \".econst:xdc_runtime_Registry_Module__loggerFxn4__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Registry_Module__loggerFxn4__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Registry_Module__loggerFxn4__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Registry_Module__loggerFxn4 xdc_runtime_Registry_Module__loggerFxn4__C = ((const CT__xdc_runtime_Registry_Module__loggerFxn4)(xdc_runtime_LoggerBuf_write4));

/* Module__loggerFxn8__C */
#pragma DATA_SECTION(xdc_runtime_Registry_Module__loggerFxn8__C, ".econst:xdc_runtime_Registry_Module__loggerFxn8__C");
asm("	.sect \".econst:xdc_runtime_Registry_Module__loggerFxn8__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Registry_Module__loggerFxn8__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Registry_Module__loggerFxn8__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Registry_Module__loggerFxn8 xdc_runtime_Registry_Module__loggerFxn8__C = ((const CT__xdc_runtime_Registry_Module__loggerFxn8)(xdc_runtime_LoggerBuf_write8));

/* Object__count__C */
#pragma DATA_SECTION(xdc_runtime_Registry_Object__count__C, ".econst:xdc_runtime_Registry_Object__count__C");
asm("	.sect \".econst:xdc_runtime_Registry_Object__count__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Registry_Object__count__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Registry_Object__count__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Registry_Object__count xdc_runtime_Registry_Object__count__C = 0;

/* Object__heap__C */
#pragma DATA_SECTION(xdc_runtime_Registry_Object__heap__C, ".econst:xdc_runtime_Registry_Object__heap__C");
asm("	.sect \".econst:xdc_runtime_Registry_Object__heap__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Registry_Object__heap__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Registry_Object__heap__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Registry_Object__heap xdc_runtime_Registry_Object__heap__C = NULL;

/* Object__sizeof__C */
#pragma DATA_SECTION(xdc_runtime_Registry_Object__sizeof__C, ".econst:xdc_runtime_Registry_Object__sizeof__C");
asm("	.sect \".econst:xdc_runtime_Registry_Object__sizeof__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Registry_Object__sizeof__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Registry_Object__sizeof__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Registry_Object__sizeof xdc_runtime_Registry_Object__sizeof__C = 0;

/* Object__table__C */
#pragma DATA_SECTION(xdc_runtime_Registry_Object__table__C, ".econst:xdc_runtime_Registry_Object__table__C");
asm("	.sect \".econst:xdc_runtime_Registry_Object__table__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Registry_Object__table__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Registry_Object__table__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Registry_Object__table xdc_runtime_Registry_Object__table__C = NULL;


/*
 * ======== xdc.runtime.Startup INITIALIZERS ========
 */

/* Module__state__V */
#if defined (__ICCARM__)
#pragma location = ".data_xdc_runtime_Startup_Module__state__V"
#endif
#if defined(__GNUC__) && !(defined(__MACH__) && defined(__APPLE__))
#ifndef __ti__
xdc_runtime_Startup_Module_State__ xdc_runtime_Startup_Module__state__V __attribute__ ((section(".data_xdc_runtime_Startup_Module__state__V")));
#elif defined(__clang__)
xdc_runtime_Startup_Module_State__ xdc_runtime_Startup_Module__state__V __attribute__ ((section(".data:xdc_runtime_Startup_Module__state__V")));
#endif
#endif
xdc_runtime_Startup_Module_State__ xdc_runtime_Startup_Module__state__V = {
    ((xdc_Int*)NULL),  /* stateTab */
    0,  /* execFlag */
    0,  /* rtsDoneFlag */
};

/* --> xdc_runtime_Startup_firstFxns__A */
#pragma DATA_SECTION(xdc_runtime_Startup_firstFxns__A, ".econst:xdc_runtime_Startup_firstFxns__A");
asm("	.sect \".econst:xdc_runtime_Startup_firstFxns__A\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Startup_firstFxns__A\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Startup_firstFxns__A\"");
asm("	.clink ");

const __T1_xdc_runtime_Startup_firstFxns xdc_runtime_Startup_firstFxns__A[3] = {
    ((xdc_Void(*)(xdc_Void))(ti_sysbios_heaps_HeapMem_init__I)),  /* [0] */
    ((xdc_Void(*)(xdc_Void))(ti_catalog_c2800_initF2837x_Boot_initStartup)),  /* [1] */
    ((xdc_Void(*)(xdc_Void))(ti_sysbios_hal_Hwi_initStack)),  /* [2] */
};

/* --> xdc_runtime_Startup_sfxnTab__A */
#pragma DATA_SECTION(xdc_runtime_Startup_sfxnTab__A, ".econst:xdc_runtime_Startup_sfxnTab__A");
asm("	.sect \".econst:xdc_runtime_Startup_sfxnTab__A\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Startup_sfxnTab__A\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Startup_sfxnTab__A\"");
asm("	.clink ");

const __T1_xdc_runtime_Startup_sfxnTab xdc_runtime_Startup_sfxnTab__A[9] = {
    ((xdc_Int(*)(xdc_Int f_arg0))(xdc_runtime_LoggerBuf_Module_startup__E)),  /* [0] */
    ((xdc_Int(*)(xdc_Int f_arg0))(xdc_runtime_System_Module_startup__E)),  /* [1] */
    ((xdc_Int(*)(xdc_Int f_arg0))(xdc_runtime_SysMin_Module_startup__E)),  /* [2] */
    ((xdc_Int(*)(xdc_Int f_arg0))(ti_sysbios_family_c28_Hwi_Module_startup__E)),  /* [3] */
    ((xdc_Int(*)(xdc_Int f_arg0))(ti_sysbios_family_c28_Timer_Module_startup__E)),  /* [4] */
    ((xdc_Int(*)(xdc_Int f_arg0))(ti_sysbios_knl_Clock_Module_startup__E)),  /* [5] */
    ((xdc_Int(*)(xdc_Int f_arg0))(ti_sysbios_knl_Swi_Module_startup__E)),  /* [6] */
    ((xdc_Int(*)(xdc_Int f_arg0))(ti_sysbios_knl_Task_Module_startup__E)),  /* [7] */
    ((xdc_Int(*)(xdc_Int f_arg0))(ti_sysbios_hal_Hwi_Module_startup__E)),  /* [8] */
};

/* --> xdc_runtime_Startup_sfxnRts__A */
#pragma DATA_SECTION(xdc_runtime_Startup_sfxnRts__A, ".econst:xdc_runtime_Startup_sfxnRts__A");
asm("	.sect \".econst:xdc_runtime_Startup_sfxnRts__A\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Startup_sfxnRts__A\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Startup_sfxnRts__A\"");
asm("	.clink ");

const __T1_xdc_runtime_Startup_sfxnRts xdc_runtime_Startup_sfxnRts__A[9] = {
    1,  /* [0] */
    1,  /* [1] */
    1,  /* [2] */
    0,  /* [3] */
    0,  /* [4] */
    0,  /* [5] */
    0,  /* [6] */
    0,  /* [7] */
    0,  /* [8] */
};

/* Module__diagsEnabled__C */
#pragma DATA_SECTION(xdc_runtime_Startup_Module__diagsEnabled__C, ".econst:xdc_runtime_Startup_Module__diagsEnabled__C");
asm("	.sect \".econst:xdc_runtime_Startup_Module__diagsEnabled__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Startup_Module__diagsEnabled__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Startup_Module__diagsEnabled__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Startup_Module__diagsEnabled xdc_runtime_Startup_Module__diagsEnabled__C = (xdc_Bits32)0x10;

/* Module__diagsIncluded__C */
#pragma DATA_SECTION(xdc_runtime_Startup_Module__diagsIncluded__C, ".econst:xdc_runtime_Startup_Module__diagsIncluded__C");
asm("	.sect \".econst:xdc_runtime_Startup_Module__diagsIncluded__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Startup_Module__diagsIncluded__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Startup_Module__diagsIncluded__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Startup_Module__diagsIncluded xdc_runtime_Startup_Module__diagsIncluded__C = (xdc_Bits32)0x10;

/* Module__diagsMask__C */
#pragma DATA_SECTION(xdc_runtime_Startup_Module__diagsMask__C, ".econst:xdc_runtime_Startup_Module__diagsMask__C");
asm("	.sect \".econst:xdc_runtime_Startup_Module__diagsMask__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Startup_Module__diagsMask__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Startup_Module__diagsMask__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Startup_Module__diagsMask xdc_runtime_Startup_Module__diagsMask__C = ((const CT__xdc_runtime_Startup_Module__diagsMask)NULL);

/* Module__gateObj__C */
#pragma DATA_SECTION(xdc_runtime_Startup_Module__gateObj__C, ".econst:xdc_runtime_Startup_Module__gateObj__C");
asm("	.sect \".econst:xdc_runtime_Startup_Module__gateObj__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Startup_Module__gateObj__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Startup_Module__gateObj__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Startup_Module__gateObj xdc_runtime_Startup_Module__gateObj__C = ((const CT__xdc_runtime_Startup_Module__gateObj)NULL);

/* Module__gatePrms__C */
#pragma DATA_SECTION(xdc_runtime_Startup_Module__gatePrms__C, ".econst:xdc_runtime_Startup_Module__gatePrms__C");
asm("	.sect \".econst:xdc_runtime_Startup_Module__gatePrms__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Startup_Module__gatePrms__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Startup_Module__gatePrms__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Startup_Module__gatePrms xdc_runtime_Startup_Module__gatePrms__C = ((const CT__xdc_runtime_Startup_Module__gatePrms)NULL);

/* Module__id__C */
#pragma DATA_SECTION(xdc_runtime_Startup_Module__id__C, ".econst:xdc_runtime_Startup_Module__id__C");
asm("	.sect \".econst:xdc_runtime_Startup_Module__id__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Startup_Module__id__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Startup_Module__id__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Startup_Module__id xdc_runtime_Startup_Module__id__C = (xdc_Bits16)0x800d;

/* Module__loggerDefined__C */
#pragma DATA_SECTION(xdc_runtime_Startup_Module__loggerDefined__C, ".econst:xdc_runtime_Startup_Module__loggerDefined__C");
asm("	.sect \".econst:xdc_runtime_Startup_Module__loggerDefined__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Startup_Module__loggerDefined__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Startup_Module__loggerDefined__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Startup_Module__loggerDefined xdc_runtime_Startup_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
#pragma DATA_SECTION(xdc_runtime_Startup_Module__loggerObj__C, ".econst:xdc_runtime_Startup_Module__loggerObj__C");
asm("	.sect \".econst:xdc_runtime_Startup_Module__loggerObj__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Startup_Module__loggerObj__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Startup_Module__loggerObj__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Startup_Module__loggerObj xdc_runtime_Startup_Module__loggerObj__C = ((const CT__xdc_runtime_Startup_Module__loggerObj)NULL);

/* Module__loggerFxn0__C */
#pragma DATA_SECTION(xdc_runtime_Startup_Module__loggerFxn0__C, ".econst:xdc_runtime_Startup_Module__loggerFxn0__C");
asm("	.sect \".econst:xdc_runtime_Startup_Module__loggerFxn0__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Startup_Module__loggerFxn0__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Startup_Module__loggerFxn0__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Startup_Module__loggerFxn0 xdc_runtime_Startup_Module__loggerFxn0__C = ((const CT__xdc_runtime_Startup_Module__loggerFxn0)NULL);

/* Module__loggerFxn1__C */
#pragma DATA_SECTION(xdc_runtime_Startup_Module__loggerFxn1__C, ".econst:xdc_runtime_Startup_Module__loggerFxn1__C");
asm("	.sect \".econst:xdc_runtime_Startup_Module__loggerFxn1__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Startup_Module__loggerFxn1__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Startup_Module__loggerFxn1__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Startup_Module__loggerFxn1 xdc_runtime_Startup_Module__loggerFxn1__C = ((const CT__xdc_runtime_Startup_Module__loggerFxn1)NULL);

/* Module__loggerFxn2__C */
#pragma DATA_SECTION(xdc_runtime_Startup_Module__loggerFxn2__C, ".econst:xdc_runtime_Startup_Module__loggerFxn2__C");
asm("	.sect \".econst:xdc_runtime_Startup_Module__loggerFxn2__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Startup_Module__loggerFxn2__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Startup_Module__loggerFxn2__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Startup_Module__loggerFxn2 xdc_runtime_Startup_Module__loggerFxn2__C = ((const CT__xdc_runtime_Startup_Module__loggerFxn2)NULL);

/* Module__loggerFxn4__C */
#pragma DATA_SECTION(xdc_runtime_Startup_Module__loggerFxn4__C, ".econst:xdc_runtime_Startup_Module__loggerFxn4__C");
asm("	.sect \".econst:xdc_runtime_Startup_Module__loggerFxn4__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Startup_Module__loggerFxn4__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Startup_Module__loggerFxn4__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Startup_Module__loggerFxn4 xdc_runtime_Startup_Module__loggerFxn4__C = ((const CT__xdc_runtime_Startup_Module__loggerFxn4)NULL);

/* Module__loggerFxn8__C */
#pragma DATA_SECTION(xdc_runtime_Startup_Module__loggerFxn8__C, ".econst:xdc_runtime_Startup_Module__loggerFxn8__C");
asm("	.sect \".econst:xdc_runtime_Startup_Module__loggerFxn8__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Startup_Module__loggerFxn8__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Startup_Module__loggerFxn8__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Startup_Module__loggerFxn8 xdc_runtime_Startup_Module__loggerFxn8__C = ((const CT__xdc_runtime_Startup_Module__loggerFxn8)NULL);

/* Object__count__C */
#pragma DATA_SECTION(xdc_runtime_Startup_Object__count__C, ".econst:xdc_runtime_Startup_Object__count__C");
asm("	.sect \".econst:xdc_runtime_Startup_Object__count__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Startup_Object__count__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Startup_Object__count__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Startup_Object__count xdc_runtime_Startup_Object__count__C = 0;

/* Object__heap__C */
#pragma DATA_SECTION(xdc_runtime_Startup_Object__heap__C, ".econst:xdc_runtime_Startup_Object__heap__C");
asm("	.sect \".econst:xdc_runtime_Startup_Object__heap__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Startup_Object__heap__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Startup_Object__heap__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Startup_Object__heap xdc_runtime_Startup_Object__heap__C = NULL;

/* Object__sizeof__C */
#pragma DATA_SECTION(xdc_runtime_Startup_Object__sizeof__C, ".econst:xdc_runtime_Startup_Object__sizeof__C");
asm("	.sect \".econst:xdc_runtime_Startup_Object__sizeof__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Startup_Object__sizeof__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Startup_Object__sizeof__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Startup_Object__sizeof xdc_runtime_Startup_Object__sizeof__C = 0;

/* Object__table__C */
#pragma DATA_SECTION(xdc_runtime_Startup_Object__table__C, ".econst:xdc_runtime_Startup_Object__table__C");
asm("	.sect \".econst:xdc_runtime_Startup_Object__table__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Startup_Object__table__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Startup_Object__table__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Startup_Object__table xdc_runtime_Startup_Object__table__C = NULL;

/* maxPasses__C */
#pragma DATA_SECTION(xdc_runtime_Startup_maxPasses__C, ".econst:xdc_runtime_Startup_maxPasses__C");
asm("	.sect \".econst:xdc_runtime_Startup_maxPasses__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Startup_maxPasses__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Startup_maxPasses__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Startup_maxPasses xdc_runtime_Startup_maxPasses__C = (xdc_Int)0x20;

/* firstFxns__C */
#pragma DATA_SECTION(xdc_runtime_Startup_firstFxns__C, ".econst:xdc_runtime_Startup_firstFxns__C");
asm("	.sect \".econst:xdc_runtime_Startup_firstFxns__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Startup_firstFxns__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Startup_firstFxns__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Startup_firstFxns xdc_runtime_Startup_firstFxns__C = {3, ((__T1_xdc_runtime_Startup_firstFxns const  *)xdc_runtime_Startup_firstFxns__A)};

/* lastFxns__C */
#pragma DATA_SECTION(xdc_runtime_Startup_lastFxns__C, ".econst:xdc_runtime_Startup_lastFxns__C");
asm("	.sect \".econst:xdc_runtime_Startup_lastFxns__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Startup_lastFxns__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Startup_lastFxns__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Startup_lastFxns xdc_runtime_Startup_lastFxns__C = {0, 0};

/* startModsFxn__C */
#pragma DATA_SECTION(xdc_runtime_Startup_startModsFxn__C, ".econst:xdc_runtime_Startup_startModsFxn__C");
asm("	.sect \".econst:xdc_runtime_Startup_startModsFxn__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Startup_startModsFxn__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Startup_startModsFxn__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Startup_startModsFxn xdc_runtime_Startup_startModsFxn__C = ((const CT__xdc_runtime_Startup_startModsFxn)(xdc_runtime_Startup_startMods__I));

/* execImpl__C */
#pragma DATA_SECTION(xdc_runtime_Startup_execImpl__C, ".econst:xdc_runtime_Startup_execImpl__C");
asm("	.sect \".econst:xdc_runtime_Startup_execImpl__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Startup_execImpl__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Startup_execImpl__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Startup_execImpl xdc_runtime_Startup_execImpl__C = ((const CT__xdc_runtime_Startup_execImpl)(xdc_runtime_Startup_exec__I));

/* sfxnTab__C */
#pragma DATA_SECTION(xdc_runtime_Startup_sfxnTab__C, ".econst:xdc_runtime_Startup_sfxnTab__C");
asm("	.sect \".econst:xdc_runtime_Startup_sfxnTab__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Startup_sfxnTab__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Startup_sfxnTab__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Startup_sfxnTab xdc_runtime_Startup_sfxnTab__C = ((const CT__xdc_runtime_Startup_sfxnTab)xdc_runtime_Startup_sfxnTab__A);

/* sfxnRts__C */
#pragma DATA_SECTION(xdc_runtime_Startup_sfxnRts__C, ".econst:xdc_runtime_Startup_sfxnRts__C");
asm("	.sect \".econst:xdc_runtime_Startup_sfxnRts__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Startup_sfxnRts__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Startup_sfxnRts__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Startup_sfxnRts xdc_runtime_Startup_sfxnRts__C = ((const CT__xdc_runtime_Startup_sfxnRts)xdc_runtime_Startup_sfxnRts__A);


/*
 * ======== xdc.runtime.SysMin INITIALIZERS ========
 */

/* --> xdc_runtime_SysMin_Module_State_0_outbuf__A */
__T1_xdc_runtime_SysMin_Module_State__outbuf xdc_runtime_SysMin_Module_State_0_outbuf__A[512];

/* Module__state__V */
#if defined (__ICCARM__)
#pragma location = ".data_xdc_runtime_SysMin_Module__state__V"
#endif
#if defined(__GNUC__) && !(defined(__MACH__) && defined(__APPLE__))
#ifndef __ti__
xdc_runtime_SysMin_Module_State__ xdc_runtime_SysMin_Module__state__V __attribute__ ((section(".data_xdc_runtime_SysMin_Module__state__V")));
#elif defined(__clang__)
xdc_runtime_SysMin_Module_State__ xdc_runtime_SysMin_Module__state__V __attribute__ ((section(".data:xdc_runtime_SysMin_Module__state__V")));
#endif
#endif
xdc_runtime_SysMin_Module_State__ xdc_runtime_SysMin_Module__state__V = {
    ((void*)xdc_runtime_SysMin_Module_State_0_outbuf__A),  /* outbuf */
    (xdc_UInt)0x0,  /* outidx */
    0,  /* wrapped */
};

/* Module__diagsEnabled__C */
#pragma DATA_SECTION(xdc_runtime_SysMin_Module__diagsEnabled__C, ".econst:xdc_runtime_SysMin_Module__diagsEnabled__C");
asm("	.sect \".econst:xdc_runtime_SysMin_Module__diagsEnabled__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_SysMin_Module__diagsEnabled__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_SysMin_Module__diagsEnabled__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_SysMin_Module__diagsEnabled xdc_runtime_SysMin_Module__diagsEnabled__C = (xdc_Bits32)0x10;

/* Module__diagsIncluded__C */
#pragma DATA_SECTION(xdc_runtime_SysMin_Module__diagsIncluded__C, ".econst:xdc_runtime_SysMin_Module__diagsIncluded__C");
asm("	.sect \".econst:xdc_runtime_SysMin_Module__diagsIncluded__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_SysMin_Module__diagsIncluded__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_SysMin_Module__diagsIncluded__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_SysMin_Module__diagsIncluded xdc_runtime_SysMin_Module__diagsIncluded__C = (xdc_Bits32)0x10;

/* Module__diagsMask__C */
#pragma DATA_SECTION(xdc_runtime_SysMin_Module__diagsMask__C, ".econst:xdc_runtime_SysMin_Module__diagsMask__C");
asm("	.sect \".econst:xdc_runtime_SysMin_Module__diagsMask__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_SysMin_Module__diagsMask__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_SysMin_Module__diagsMask__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_SysMin_Module__diagsMask xdc_runtime_SysMin_Module__diagsMask__C = ((const CT__xdc_runtime_SysMin_Module__diagsMask)NULL);

/* Module__gateObj__C */
#pragma DATA_SECTION(xdc_runtime_SysMin_Module__gateObj__C, ".econst:xdc_runtime_SysMin_Module__gateObj__C");
asm("	.sect \".econst:xdc_runtime_SysMin_Module__gateObj__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_SysMin_Module__gateObj__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_SysMin_Module__gateObj__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_SysMin_Module__gateObj xdc_runtime_SysMin_Module__gateObj__C = ((const CT__xdc_runtime_SysMin_Module__gateObj)NULL);

/* Module__gatePrms__C */
#pragma DATA_SECTION(xdc_runtime_SysMin_Module__gatePrms__C, ".econst:xdc_runtime_SysMin_Module__gatePrms__C");
asm("	.sect \".econst:xdc_runtime_SysMin_Module__gatePrms__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_SysMin_Module__gatePrms__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_SysMin_Module__gatePrms__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_SysMin_Module__gatePrms xdc_runtime_SysMin_Module__gatePrms__C = ((const CT__xdc_runtime_SysMin_Module__gatePrms)NULL);

/* Module__id__C */
#pragma DATA_SECTION(xdc_runtime_SysMin_Module__id__C, ".econst:xdc_runtime_SysMin_Module__id__C");
asm("	.sect \".econst:xdc_runtime_SysMin_Module__id__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_SysMin_Module__id__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_SysMin_Module__id__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_SysMin_Module__id xdc_runtime_SysMin_Module__id__C = (xdc_Bits16)0x800f;

/* Module__loggerDefined__C */
#pragma DATA_SECTION(xdc_runtime_SysMin_Module__loggerDefined__C, ".econst:xdc_runtime_SysMin_Module__loggerDefined__C");
asm("	.sect \".econst:xdc_runtime_SysMin_Module__loggerDefined__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_SysMin_Module__loggerDefined__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_SysMin_Module__loggerDefined__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_SysMin_Module__loggerDefined xdc_runtime_SysMin_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
#pragma DATA_SECTION(xdc_runtime_SysMin_Module__loggerObj__C, ".econst:xdc_runtime_SysMin_Module__loggerObj__C");
asm("	.sect \".econst:xdc_runtime_SysMin_Module__loggerObj__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_SysMin_Module__loggerObj__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_SysMin_Module__loggerObj__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_SysMin_Module__loggerObj xdc_runtime_SysMin_Module__loggerObj__C = ((const CT__xdc_runtime_SysMin_Module__loggerObj)NULL);

/* Module__loggerFxn0__C */
#pragma DATA_SECTION(xdc_runtime_SysMin_Module__loggerFxn0__C, ".econst:xdc_runtime_SysMin_Module__loggerFxn0__C");
asm("	.sect \".econst:xdc_runtime_SysMin_Module__loggerFxn0__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_SysMin_Module__loggerFxn0__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_SysMin_Module__loggerFxn0__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_SysMin_Module__loggerFxn0 xdc_runtime_SysMin_Module__loggerFxn0__C = ((const CT__xdc_runtime_SysMin_Module__loggerFxn0)NULL);

/* Module__loggerFxn1__C */
#pragma DATA_SECTION(xdc_runtime_SysMin_Module__loggerFxn1__C, ".econst:xdc_runtime_SysMin_Module__loggerFxn1__C");
asm("	.sect \".econst:xdc_runtime_SysMin_Module__loggerFxn1__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_SysMin_Module__loggerFxn1__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_SysMin_Module__loggerFxn1__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_SysMin_Module__loggerFxn1 xdc_runtime_SysMin_Module__loggerFxn1__C = ((const CT__xdc_runtime_SysMin_Module__loggerFxn1)NULL);

/* Module__loggerFxn2__C */
#pragma DATA_SECTION(xdc_runtime_SysMin_Module__loggerFxn2__C, ".econst:xdc_runtime_SysMin_Module__loggerFxn2__C");
asm("	.sect \".econst:xdc_runtime_SysMin_Module__loggerFxn2__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_SysMin_Module__loggerFxn2__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_SysMin_Module__loggerFxn2__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_SysMin_Module__loggerFxn2 xdc_runtime_SysMin_Module__loggerFxn2__C = ((const CT__xdc_runtime_SysMin_Module__loggerFxn2)NULL);

/* Module__loggerFxn4__C */
#pragma DATA_SECTION(xdc_runtime_SysMin_Module__loggerFxn4__C, ".econst:xdc_runtime_SysMin_Module__loggerFxn4__C");
asm("	.sect \".econst:xdc_runtime_SysMin_Module__loggerFxn4__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_SysMin_Module__loggerFxn4__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_SysMin_Module__loggerFxn4__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_SysMin_Module__loggerFxn4 xdc_runtime_SysMin_Module__loggerFxn4__C = ((const CT__xdc_runtime_SysMin_Module__loggerFxn4)NULL);

/* Module__loggerFxn8__C */
#pragma DATA_SECTION(xdc_runtime_SysMin_Module__loggerFxn8__C, ".econst:xdc_runtime_SysMin_Module__loggerFxn8__C");
asm("	.sect \".econst:xdc_runtime_SysMin_Module__loggerFxn8__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_SysMin_Module__loggerFxn8__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_SysMin_Module__loggerFxn8__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_SysMin_Module__loggerFxn8 xdc_runtime_SysMin_Module__loggerFxn8__C = ((const CT__xdc_runtime_SysMin_Module__loggerFxn8)NULL);

/* Object__count__C */
#pragma DATA_SECTION(xdc_runtime_SysMin_Object__count__C, ".econst:xdc_runtime_SysMin_Object__count__C");
asm("	.sect \".econst:xdc_runtime_SysMin_Object__count__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_SysMin_Object__count__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_SysMin_Object__count__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_SysMin_Object__count xdc_runtime_SysMin_Object__count__C = 0;

/* Object__heap__C */
#pragma DATA_SECTION(xdc_runtime_SysMin_Object__heap__C, ".econst:xdc_runtime_SysMin_Object__heap__C");
asm("	.sect \".econst:xdc_runtime_SysMin_Object__heap__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_SysMin_Object__heap__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_SysMin_Object__heap__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_SysMin_Object__heap xdc_runtime_SysMin_Object__heap__C = NULL;

/* Object__sizeof__C */
#pragma DATA_SECTION(xdc_runtime_SysMin_Object__sizeof__C, ".econst:xdc_runtime_SysMin_Object__sizeof__C");
asm("	.sect \".econst:xdc_runtime_SysMin_Object__sizeof__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_SysMin_Object__sizeof__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_SysMin_Object__sizeof__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_SysMin_Object__sizeof xdc_runtime_SysMin_Object__sizeof__C = 0;

/* Object__table__C */
#pragma DATA_SECTION(xdc_runtime_SysMin_Object__table__C, ".econst:xdc_runtime_SysMin_Object__table__C");
asm("	.sect \".econst:xdc_runtime_SysMin_Object__table__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_SysMin_Object__table__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_SysMin_Object__table__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_SysMin_Object__table xdc_runtime_SysMin_Object__table__C = NULL;

/* bufSize__C */
#pragma DATA_SECTION(xdc_runtime_SysMin_bufSize__C, ".econst:xdc_runtime_SysMin_bufSize__C");
asm("	.sect \".econst:xdc_runtime_SysMin_bufSize__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_SysMin_bufSize__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_SysMin_bufSize__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_SysMin_bufSize xdc_runtime_SysMin_bufSize__C = (xdc_SizeT)0x200;

/* flushAtExit__C */
#pragma DATA_SECTION(xdc_runtime_SysMin_flushAtExit__C, ".econst:xdc_runtime_SysMin_flushAtExit__C");
asm("	.sect \".econst:xdc_runtime_SysMin_flushAtExit__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_SysMin_flushAtExit__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_SysMin_flushAtExit__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_SysMin_flushAtExit xdc_runtime_SysMin_flushAtExit__C = 1;

/* outputFxn__C */
#pragma DATA_SECTION(xdc_runtime_SysMin_outputFxn__C, ".econst:xdc_runtime_SysMin_outputFxn__C");
asm("	.sect \".econst:xdc_runtime_SysMin_outputFxn__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_SysMin_outputFxn__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_SysMin_outputFxn__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_SysMin_outputFxn xdc_runtime_SysMin_outputFxn__C = ((const CT__xdc_runtime_SysMin_outputFxn)NULL);

/* outputFunc__C */
#pragma DATA_SECTION(xdc_runtime_SysMin_outputFunc__C, ".econst:xdc_runtime_SysMin_outputFunc__C");
asm("	.sect \".econst:xdc_runtime_SysMin_outputFunc__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_SysMin_outputFunc__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_SysMin_outputFunc__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_SysMin_outputFunc xdc_runtime_SysMin_outputFunc__C = ((const CT__xdc_runtime_SysMin_outputFunc)(xdc_runtime_SysMin_output__I));


/*
 * ======== xdc.runtime.System INITIALIZERS ========
 */

/* --> xdc_runtime_System_Module_State_0_atexitHandlers__A */
__T1_xdc_runtime_System_Module_State__atexitHandlers xdc_runtime_System_Module_State_0_atexitHandlers__A[4] = {
    ((xdc_Void(*)(xdc_Int f_arg0))NULL),  /* [0] */
    ((xdc_Void(*)(xdc_Int f_arg0))NULL),  /* [1] */
    ((xdc_Void(*)(xdc_Int f_arg0))NULL),  /* [2] */
    ((xdc_Void(*)(xdc_Int f_arg0))NULL),  /* [3] */
};

/* Module__state__V */
#if defined (__ICCARM__)
#pragma location = ".data_xdc_runtime_System_Module__state__V"
#endif
#if defined(__GNUC__) && !(defined(__MACH__) && defined(__APPLE__))
#ifndef __ti__
xdc_runtime_System_Module_State__ xdc_runtime_System_Module__state__V __attribute__ ((section(".data_xdc_runtime_System_Module__state__V")));
#elif defined(__clang__)
xdc_runtime_System_Module_State__ xdc_runtime_System_Module__state__V __attribute__ ((section(".data:xdc_runtime_System_Module__state__V")));
#endif
#endif
xdc_runtime_System_Module_State__ xdc_runtime_System_Module__state__V = {
    ((void*)xdc_runtime_System_Module_State_0_atexitHandlers__A),  /* atexitHandlers */
    (xdc_Int)0x0,  /* numAtexitHandlers */
};

/* Module__diagsEnabled__C */
#pragma DATA_SECTION(xdc_runtime_System_Module__diagsEnabled__C, ".econst:xdc_runtime_System_Module__diagsEnabled__C");
asm("	.sect \".econst:xdc_runtime_System_Module__diagsEnabled__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_System_Module__diagsEnabled__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_System_Module__diagsEnabled__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_System_Module__diagsEnabled xdc_runtime_System_Module__diagsEnabled__C = (xdc_Bits32)0x10;

/* Module__diagsIncluded__C */
#pragma DATA_SECTION(xdc_runtime_System_Module__diagsIncluded__C, ".econst:xdc_runtime_System_Module__diagsIncluded__C");
asm("	.sect \".econst:xdc_runtime_System_Module__diagsIncluded__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_System_Module__diagsIncluded__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_System_Module__diagsIncluded__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_System_Module__diagsIncluded xdc_runtime_System_Module__diagsIncluded__C = (xdc_Bits32)0x10;

/* Module__diagsMask__C */
#pragma DATA_SECTION(xdc_runtime_System_Module__diagsMask__C, ".econst:xdc_runtime_System_Module__diagsMask__C");
asm("	.sect \".econst:xdc_runtime_System_Module__diagsMask__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_System_Module__diagsMask__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_System_Module__diagsMask__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_System_Module__diagsMask xdc_runtime_System_Module__diagsMask__C = ((const CT__xdc_runtime_System_Module__diagsMask)NULL);

/* Module__gateObj__C */
#pragma DATA_SECTION(xdc_runtime_System_Module__gateObj__C, ".econst:xdc_runtime_System_Module__gateObj__C");
asm("	.sect \".econst:xdc_runtime_System_Module__gateObj__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_System_Module__gateObj__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_System_Module__gateObj__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_System_Module__gateObj xdc_runtime_System_Module__gateObj__C = ((const CT__xdc_runtime_System_Module__gateObj)((void*)(xdc_runtime_IGateProvider_Handle)&ti_sysbios_gates_GateHwi_Object__table__V[0]));

/* Module__gatePrms__C */
#pragma DATA_SECTION(xdc_runtime_System_Module__gatePrms__C, ".econst:xdc_runtime_System_Module__gatePrms__C");
asm("	.sect \".econst:xdc_runtime_System_Module__gatePrms__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_System_Module__gatePrms__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_System_Module__gatePrms__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_System_Module__gatePrms xdc_runtime_System_Module__gatePrms__C = ((const CT__xdc_runtime_System_Module__gatePrms)NULL);

/* Module__id__C */
#pragma DATA_SECTION(xdc_runtime_System_Module__id__C, ".econst:xdc_runtime_System_Module__id__C");
asm("	.sect \".econst:xdc_runtime_System_Module__id__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_System_Module__id__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_System_Module__id__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_System_Module__id xdc_runtime_System_Module__id__C = (xdc_Bits16)0x800e;

/* Module__loggerDefined__C */
#pragma DATA_SECTION(xdc_runtime_System_Module__loggerDefined__C, ".econst:xdc_runtime_System_Module__loggerDefined__C");
asm("	.sect \".econst:xdc_runtime_System_Module__loggerDefined__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_System_Module__loggerDefined__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_System_Module__loggerDefined__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_System_Module__loggerDefined xdc_runtime_System_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
#pragma DATA_SECTION(xdc_runtime_System_Module__loggerObj__C, ".econst:xdc_runtime_System_Module__loggerObj__C");
asm("	.sect \".econst:xdc_runtime_System_Module__loggerObj__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_System_Module__loggerObj__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_System_Module__loggerObj__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_System_Module__loggerObj xdc_runtime_System_Module__loggerObj__C = ((const CT__xdc_runtime_System_Module__loggerObj)NULL);

/* Module__loggerFxn0__C */
#pragma DATA_SECTION(xdc_runtime_System_Module__loggerFxn0__C, ".econst:xdc_runtime_System_Module__loggerFxn0__C");
asm("	.sect \".econst:xdc_runtime_System_Module__loggerFxn0__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_System_Module__loggerFxn0__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_System_Module__loggerFxn0__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_System_Module__loggerFxn0 xdc_runtime_System_Module__loggerFxn0__C = ((const CT__xdc_runtime_System_Module__loggerFxn0)NULL);

/* Module__loggerFxn1__C */
#pragma DATA_SECTION(xdc_runtime_System_Module__loggerFxn1__C, ".econst:xdc_runtime_System_Module__loggerFxn1__C");
asm("	.sect \".econst:xdc_runtime_System_Module__loggerFxn1__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_System_Module__loggerFxn1__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_System_Module__loggerFxn1__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_System_Module__loggerFxn1 xdc_runtime_System_Module__loggerFxn1__C = ((const CT__xdc_runtime_System_Module__loggerFxn1)NULL);

/* Module__loggerFxn2__C */
#pragma DATA_SECTION(xdc_runtime_System_Module__loggerFxn2__C, ".econst:xdc_runtime_System_Module__loggerFxn2__C");
asm("	.sect \".econst:xdc_runtime_System_Module__loggerFxn2__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_System_Module__loggerFxn2__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_System_Module__loggerFxn2__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_System_Module__loggerFxn2 xdc_runtime_System_Module__loggerFxn2__C = ((const CT__xdc_runtime_System_Module__loggerFxn2)NULL);

/* Module__loggerFxn4__C */
#pragma DATA_SECTION(xdc_runtime_System_Module__loggerFxn4__C, ".econst:xdc_runtime_System_Module__loggerFxn4__C");
asm("	.sect \".econst:xdc_runtime_System_Module__loggerFxn4__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_System_Module__loggerFxn4__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_System_Module__loggerFxn4__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_System_Module__loggerFxn4 xdc_runtime_System_Module__loggerFxn4__C = ((const CT__xdc_runtime_System_Module__loggerFxn4)NULL);

/* Module__loggerFxn8__C */
#pragma DATA_SECTION(xdc_runtime_System_Module__loggerFxn8__C, ".econst:xdc_runtime_System_Module__loggerFxn8__C");
asm("	.sect \".econst:xdc_runtime_System_Module__loggerFxn8__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_System_Module__loggerFxn8__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_System_Module__loggerFxn8__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_System_Module__loggerFxn8 xdc_runtime_System_Module__loggerFxn8__C = ((const CT__xdc_runtime_System_Module__loggerFxn8)NULL);

/* Object__count__C */
#pragma DATA_SECTION(xdc_runtime_System_Object__count__C, ".econst:xdc_runtime_System_Object__count__C");
asm("	.sect \".econst:xdc_runtime_System_Object__count__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_System_Object__count__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_System_Object__count__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_System_Object__count xdc_runtime_System_Object__count__C = 0;

/* Object__heap__C */
#pragma DATA_SECTION(xdc_runtime_System_Object__heap__C, ".econst:xdc_runtime_System_Object__heap__C");
asm("	.sect \".econst:xdc_runtime_System_Object__heap__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_System_Object__heap__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_System_Object__heap__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_System_Object__heap xdc_runtime_System_Object__heap__C = NULL;

/* Object__sizeof__C */
#pragma DATA_SECTION(xdc_runtime_System_Object__sizeof__C, ".econst:xdc_runtime_System_Object__sizeof__C");
asm("	.sect \".econst:xdc_runtime_System_Object__sizeof__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_System_Object__sizeof__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_System_Object__sizeof__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_System_Object__sizeof xdc_runtime_System_Object__sizeof__C = 0;

/* Object__table__C */
#pragma DATA_SECTION(xdc_runtime_System_Object__table__C, ".econst:xdc_runtime_System_Object__table__C");
asm("	.sect \".econst:xdc_runtime_System_Object__table__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_System_Object__table__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_System_Object__table__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_System_Object__table xdc_runtime_System_Object__table__C = NULL;

/* A_cannotFitIntoArg__C */
#pragma DATA_SECTION(xdc_runtime_System_A_cannotFitIntoArg__C, ".econst:xdc_runtime_System_A_cannotFitIntoArg__C");
asm("	.sect \".econst:xdc_runtime_System_A_cannotFitIntoArg__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_System_A_cannotFitIntoArg__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_System_A_cannotFitIntoArg__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_System_A_cannotFitIntoArg xdc_runtime_System_A_cannotFitIntoArg__C = (((xdc_runtime_Assert_Id)352) << 16 | 16);

/* maxAtexitHandlers__C */
#pragma DATA_SECTION(xdc_runtime_System_maxAtexitHandlers__C, ".econst:xdc_runtime_System_maxAtexitHandlers__C");
asm("	.sect \".econst:xdc_runtime_System_maxAtexitHandlers__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_System_maxAtexitHandlers__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_System_maxAtexitHandlers__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_System_maxAtexitHandlers xdc_runtime_System_maxAtexitHandlers__C = (xdc_Int)0x4;

/* abortFxn__C */
#pragma DATA_SECTION(xdc_runtime_System_abortFxn__C, ".econst:xdc_runtime_System_abortFxn__C");
asm("	.sect \".econst:xdc_runtime_System_abortFxn__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_System_abortFxn__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_System_abortFxn__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_System_abortFxn xdc_runtime_System_abortFxn__C = ((const CT__xdc_runtime_System_abortFxn)(xdc_runtime_System_abortStd__E));

/* exitFxn__C */
#pragma DATA_SECTION(xdc_runtime_System_exitFxn__C, ".econst:xdc_runtime_System_exitFxn__C");
asm("	.sect \".econst:xdc_runtime_System_exitFxn__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_System_exitFxn__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_System_exitFxn__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_System_exitFxn xdc_runtime_System_exitFxn__C = ((const CT__xdc_runtime_System_exitFxn)(xdc_runtime_System_exitStd__E));

/* extendFxn__C */
#pragma DATA_SECTION(xdc_runtime_System_extendFxn__C, ".econst:xdc_runtime_System_extendFxn__C");
asm("	.sect \".econst:xdc_runtime_System_extendFxn__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_System_extendFxn__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_System_extendFxn__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_System_extendFxn xdc_runtime_System_extendFxn__C = ((const CT__xdc_runtime_System_extendFxn)(xdc_runtime_System_printfExtend__I));


/*
 * ======== xdc.runtime.System_Module_GateProxy INITIALIZERS ========
 */


/*
 * ======== xdc.runtime.System_SupportProxy INITIALIZERS ========
 */


/*
 * ======== xdc.runtime.Text INITIALIZERS ========
 */

/* Module__state__V */
#if defined (__ICCARM__)
#pragma location = ".data_xdc_runtime_Text_Module__state__V"
#endif
#if defined(__GNUC__) && !(defined(__MACH__) && defined(__APPLE__))
#ifndef __ti__
xdc_runtime_Text_Module_State__ xdc_runtime_Text_Module__state__V __attribute__ ((section(".data_xdc_runtime_Text_Module__state__V")));
#elif defined(__clang__)
xdc_runtime_Text_Module_State__ xdc_runtime_Text_Module__state__V __attribute__ ((section(".data:xdc_runtime_Text_Module__state__V")));
#endif
#endif
xdc_runtime_Text_Module_State__ xdc_runtime_Text_Module__state__V = {
    ((xdc_CPtr)(&xdc_runtime_Text_charTab__A[0])),  /* charBase */
    ((xdc_CPtr)(&xdc_runtime_Text_nodeTab__A[0])),  /* nodeBase */
};

/* --> xdc_runtime_Text_charTab__A */
#pragma DATA_SECTION(xdc_runtime_Text_charTab__A, ".econst:xdc_runtime_Text_charTab__A");
asm("	.sect \".econst:xdc_runtime_Text_charTab__A\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Text_charTab__A\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Text_charTab__A\"");
asm("	.clink ");

const __T1_xdc_runtime_Text_charTab xdc_runtime_Text_charTab__A[6056] = {
    (xdc_Char)0x0,  /* [0] */
    (xdc_Char)0x41,  /* [1] */
    (xdc_Char)0x5f,  /* [2] */
    (xdc_Char)0x69,  /* [3] */
    (xdc_Char)0x6e,  /* [4] */
    (xdc_Char)0x69,  /* [5] */
    (xdc_Char)0x74,  /* [6] */
    (xdc_Char)0x69,  /* [7] */
    (xdc_Char)0x61,  /* [8] */
    (xdc_Char)0x6c,  /* [9] */
    (xdc_Char)0x69,  /* [10] */
    (xdc_Char)0x7a,  /* [11] */
    (xdc_Char)0x65,  /* [12] */
    (xdc_Char)0x64,  /* [13] */
    (xdc_Char)0x50,  /* [14] */
    (xdc_Char)0x61,  /* [15] */
    (xdc_Char)0x72,  /* [16] */
    (xdc_Char)0x61,  /* [17] */
    (xdc_Char)0x6d,  /* [18] */
    (xdc_Char)0x73,  /* [19] */
    (xdc_Char)0x3a,  /* [20] */
    (xdc_Char)0x20,  /* [21] */
    (xdc_Char)0x75,  /* [22] */
    (xdc_Char)0x6e,  /* [23] */
    (xdc_Char)0x69,  /* [24] */
    (xdc_Char)0x6e,  /* [25] */
    (xdc_Char)0x69,  /* [26] */
    (xdc_Char)0x74,  /* [27] */
    (xdc_Char)0x69,  /* [28] */
    (xdc_Char)0x61,  /* [29] */
    (xdc_Char)0x6c,  /* [30] */
    (xdc_Char)0x69,  /* [31] */
    (xdc_Char)0x7a,  /* [32] */
    (xdc_Char)0x65,  /* [33] */
    (xdc_Char)0x64,  /* [34] */
    (xdc_Char)0x20,  /* [35] */
    (xdc_Char)0x50,  /* [36] */
    (xdc_Char)0x61,  /* [37] */
    (xdc_Char)0x72,  /* [38] */
    (xdc_Char)0x61,  /* [39] */
    (xdc_Char)0x6d,  /* [40] */
    (xdc_Char)0x73,  /* [41] */
    (xdc_Char)0x20,  /* [42] */
    (xdc_Char)0x73,  /* [43] */
    (xdc_Char)0x74,  /* [44] */
    (xdc_Char)0x72,  /* [45] */
    (xdc_Char)0x75,  /* [46] */
    (xdc_Char)0x63,  /* [47] */
    (xdc_Char)0x74,  /* [48] */
    (xdc_Char)0x0,  /* [49] */
    (xdc_Char)0x48,  /* [50] */
    (xdc_Char)0x65,  /* [51] */
    (xdc_Char)0x61,  /* [52] */
    (xdc_Char)0x70,  /* [53] */
    (xdc_Char)0x4d,  /* [54] */
    (xdc_Char)0x69,  /* [55] */
    (xdc_Char)0x6e,  /* [56] */
    (xdc_Char)0x5f,  /* [57] */
    (xdc_Char)0x63,  /* [58] */
    (xdc_Char)0x72,  /* [59] */
    (xdc_Char)0x65,  /* [60] */
    (xdc_Char)0x61,  /* [61] */
    (xdc_Char)0x74,  /* [62] */
    (xdc_Char)0x65,  /* [63] */
    (xdc_Char)0x20,  /* [64] */
    (xdc_Char)0x63,  /* [65] */
    (xdc_Char)0x61,  /* [66] */
    (xdc_Char)0x6e,  /* [67] */
    (xdc_Char)0x6e,  /* [68] */
    (xdc_Char)0x6f,  /* [69] */
    (xdc_Char)0x74,  /* [70] */
    (xdc_Char)0x20,  /* [71] */
    (xdc_Char)0x68,  /* [72] */
    (xdc_Char)0x61,  /* [73] */
    (xdc_Char)0x76,  /* [74] */
    (xdc_Char)0x65,  /* [75] */
    (xdc_Char)0x20,  /* [76] */
    (xdc_Char)0x61,  /* [77] */
    (xdc_Char)0x20,  /* [78] */
    (xdc_Char)0x7a,  /* [79] */
    (xdc_Char)0x65,  /* [80] */
    (xdc_Char)0x72,  /* [81] */
    (xdc_Char)0x6f,  /* [82] */
    (xdc_Char)0x20,  /* [83] */
    (xdc_Char)0x73,  /* [84] */
    (xdc_Char)0x69,  /* [85] */
    (xdc_Char)0x7a,  /* [86] */
    (xdc_Char)0x65,  /* [87] */
    (xdc_Char)0x20,  /* [88] */
    (xdc_Char)0x76,  /* [89] */
    (xdc_Char)0x61,  /* [90] */
    (xdc_Char)0x6c,  /* [91] */
    (xdc_Char)0x75,  /* [92] */
    (xdc_Char)0x65,  /* [93] */
    (xdc_Char)0x0,  /* [94] */
    (xdc_Char)0x48,  /* [95] */
    (xdc_Char)0x65,  /* [96] */
    (xdc_Char)0x61,  /* [97] */
    (xdc_Char)0x70,  /* [98] */
    (xdc_Char)0x53,  /* [99] */
    (xdc_Char)0x74,  /* [100] */
    (xdc_Char)0x64,  /* [101] */
    (xdc_Char)0x5f,  /* [102] */
    (xdc_Char)0x63,  /* [103] */
    (xdc_Char)0x72,  /* [104] */
    (xdc_Char)0x65,  /* [105] */
    (xdc_Char)0x61,  /* [106] */
    (xdc_Char)0x74,  /* [107] */
    (xdc_Char)0x65,  /* [108] */
    (xdc_Char)0x20,  /* [109] */
    (xdc_Char)0x63,  /* [110] */
    (xdc_Char)0x61,  /* [111] */
    (xdc_Char)0x6e,  /* [112] */
    (xdc_Char)0x6e,  /* [113] */
    (xdc_Char)0x6f,  /* [114] */
    (xdc_Char)0x74,  /* [115] */
    (xdc_Char)0x20,  /* [116] */
    (xdc_Char)0x68,  /* [117] */
    (xdc_Char)0x61,  /* [118] */
    (xdc_Char)0x76,  /* [119] */
    (xdc_Char)0x65,  /* [120] */
    (xdc_Char)0x20,  /* [121] */
    (xdc_Char)0x61,  /* [122] */
    (xdc_Char)0x20,  /* [123] */
    (xdc_Char)0x7a,  /* [124] */
    (xdc_Char)0x65,  /* [125] */
    (xdc_Char)0x72,  /* [126] */
    (xdc_Char)0x6f,  /* [127] */
    (xdc_Char)0x20,  /* [128] */
    (xdc_Char)0x73,  /* [129] */
    (xdc_Char)0x69,  /* [130] */
    (xdc_Char)0x7a,  /* [131] */
    (xdc_Char)0x65,  /* [132] */
    (xdc_Char)0x20,  /* [133] */
    (xdc_Char)0x76,  /* [134] */
    (xdc_Char)0x61,  /* [135] */
    (xdc_Char)0x6c,  /* [136] */
    (xdc_Char)0x75,  /* [137] */
    (xdc_Char)0x65,  /* [138] */
    (xdc_Char)0x0,  /* [139] */
    (xdc_Char)0x48,  /* [140] */
    (xdc_Char)0x65,  /* [141] */
    (xdc_Char)0x61,  /* [142] */
    (xdc_Char)0x70,  /* [143] */
    (xdc_Char)0x53,  /* [144] */
    (xdc_Char)0x74,  /* [145] */
    (xdc_Char)0x64,  /* [146] */
    (xdc_Char)0x5f,  /* [147] */
    (xdc_Char)0x61,  /* [148] */
    (xdc_Char)0x6c,  /* [149] */
    (xdc_Char)0x6c,  /* [150] */
    (xdc_Char)0x6f,  /* [151] */
    (xdc_Char)0x63,  /* [152] */
    (xdc_Char)0x20,  /* [153] */
    (xdc_Char)0x61,  /* [154] */
    (xdc_Char)0x6c,  /* [155] */
    (xdc_Char)0x69,  /* [156] */
    (xdc_Char)0x67,  /* [157] */
    (xdc_Char)0x6e,  /* [158] */
    (xdc_Char)0x6d,  /* [159] */
    (xdc_Char)0x65,  /* [160] */
    (xdc_Char)0x6e,  /* [161] */
    (xdc_Char)0x74,  /* [162] */
    (xdc_Char)0x20,  /* [163] */
    (xdc_Char)0x6d,  /* [164] */
    (xdc_Char)0x75,  /* [165] */
    (xdc_Char)0x73,  /* [166] */
    (xdc_Char)0x74,  /* [167] */
    (xdc_Char)0x20,  /* [168] */
    (xdc_Char)0x62,  /* [169] */
    (xdc_Char)0x65,  /* [170] */
    (xdc_Char)0x20,  /* [171] */
    (xdc_Char)0x61,  /* [172] */
    (xdc_Char)0x20,  /* [173] */
    (xdc_Char)0x70,  /* [174] */
    (xdc_Char)0x6f,  /* [175] */
    (xdc_Char)0x77,  /* [176] */
    (xdc_Char)0x65,  /* [177] */
    (xdc_Char)0x72,  /* [178] */
    (xdc_Char)0x20,  /* [179] */
    (xdc_Char)0x6f,  /* [180] */
    (xdc_Char)0x66,  /* [181] */
    (xdc_Char)0x20,  /* [182] */
    (xdc_Char)0x32,  /* [183] */
    (xdc_Char)0x0,  /* [184] */
    (xdc_Char)0x48,  /* [185] */
    (xdc_Char)0x65,  /* [186] */
    (xdc_Char)0x61,  /* [187] */
    (xdc_Char)0x70,  /* [188] */
    (xdc_Char)0x53,  /* [189] */
    (xdc_Char)0x74,  /* [190] */
    (xdc_Char)0x64,  /* [191] */
    (xdc_Char)0x20,  /* [192] */
    (xdc_Char)0x69,  /* [193] */
    (xdc_Char)0x6e,  /* [194] */
    (xdc_Char)0x73,  /* [195] */
    (xdc_Char)0x74,  /* [196] */
    (xdc_Char)0x61,  /* [197] */
    (xdc_Char)0x6e,  /* [198] */
    (xdc_Char)0x63,  /* [199] */
    (xdc_Char)0x65,  /* [200] */
    (xdc_Char)0x20,  /* [201] */
    (xdc_Char)0x74,  /* [202] */
    (xdc_Char)0x6f,  /* [203] */
    (xdc_Char)0x74,  /* [204] */
    (xdc_Char)0x61,  /* [205] */
    (xdc_Char)0x6c,  /* [206] */
    (xdc_Char)0x46,  /* [207] */
    (xdc_Char)0x72,  /* [208] */
    (xdc_Char)0x65,  /* [209] */
    (xdc_Char)0x65,  /* [210] */
    (xdc_Char)0x53,  /* [211] */
    (xdc_Char)0x69,  /* [212] */
    (xdc_Char)0x7a,  /* [213] */
    (xdc_Char)0x65,  /* [214] */
    (xdc_Char)0x20,  /* [215] */
    (xdc_Char)0x69,  /* [216] */
    (xdc_Char)0x73,  /* [217] */
    (xdc_Char)0x20,  /* [218] */
    (xdc_Char)0x67,  /* [219] */
    (xdc_Char)0x72,  /* [220] */
    (xdc_Char)0x65,  /* [221] */
    (xdc_Char)0x61,  /* [222] */
    (xdc_Char)0x74,  /* [223] */
    (xdc_Char)0x65,  /* [224] */
    (xdc_Char)0x72,  /* [225] */
    (xdc_Char)0x20,  /* [226] */
    (xdc_Char)0x74,  /* [227] */
    (xdc_Char)0x68,  /* [228] */
    (xdc_Char)0x61,  /* [229] */
    (xdc_Char)0x6e,  /* [230] */
    (xdc_Char)0x20,  /* [231] */
    (xdc_Char)0x73,  /* [232] */
    (xdc_Char)0x74,  /* [233] */
    (xdc_Char)0x61,  /* [234] */
    (xdc_Char)0x72,  /* [235] */
    (xdc_Char)0x74,  /* [236] */
    (xdc_Char)0x69,  /* [237] */
    (xdc_Char)0x6e,  /* [238] */
    (xdc_Char)0x67,  /* [239] */
    (xdc_Char)0x20,  /* [240] */
    (xdc_Char)0x73,  /* [241] */
    (xdc_Char)0x69,  /* [242] */
    (xdc_Char)0x7a,  /* [243] */
    (xdc_Char)0x65,  /* [244] */
    (xdc_Char)0x0,  /* [245] */
    (xdc_Char)0x48,  /* [246] */
    (xdc_Char)0x65,  /* [247] */
    (xdc_Char)0x61,  /* [248] */
    (xdc_Char)0x70,  /* [249] */
    (xdc_Char)0x53,  /* [250] */
    (xdc_Char)0x74,  /* [251] */
    (xdc_Char)0x64,  /* [252] */
    (xdc_Char)0x5f,  /* [253] */
    (xdc_Char)0x61,  /* [254] */
    (xdc_Char)0x6c,  /* [255] */
    (xdc_Char)0x6c,  /* [256] */
    (xdc_Char)0x6f,  /* [257] */
    (xdc_Char)0x63,  /* [258] */
    (xdc_Char)0x20,  /* [259] */
    (xdc_Char)0x2d,  /* [260] */
    (xdc_Char)0x20,  /* [261] */
    (xdc_Char)0x72,  /* [262] */
    (xdc_Char)0x65,  /* [263] */
    (xdc_Char)0x71,  /* [264] */
    (xdc_Char)0x75,  /* [265] */
    (xdc_Char)0x65,  /* [266] */
    (xdc_Char)0x73,  /* [267] */
    (xdc_Char)0x74,  /* [268] */
    (xdc_Char)0x65,  /* [269] */
    (xdc_Char)0x64,  /* [270] */
    (xdc_Char)0x20,  /* [271] */
    (xdc_Char)0x61,  /* [272] */
    (xdc_Char)0x6c,  /* [273] */
    (xdc_Char)0x69,  /* [274] */
    (xdc_Char)0x67,  /* [275] */
    (xdc_Char)0x6e,  /* [276] */
    (xdc_Char)0x6d,  /* [277] */
    (xdc_Char)0x65,  /* [278] */
    (xdc_Char)0x6e,  /* [279] */
    (xdc_Char)0x74,  /* [280] */
    (xdc_Char)0x20,  /* [281] */
    (xdc_Char)0x69,  /* [282] */
    (xdc_Char)0x73,  /* [283] */
    (xdc_Char)0x20,  /* [284] */
    (xdc_Char)0x67,  /* [285] */
    (xdc_Char)0x72,  /* [286] */
    (xdc_Char)0x65,  /* [287] */
    (xdc_Char)0x61,  /* [288] */
    (xdc_Char)0x74,  /* [289] */
    (xdc_Char)0x65,  /* [290] */
    (xdc_Char)0x72,  /* [291] */
    (xdc_Char)0x20,  /* [292] */
    (xdc_Char)0x74,  /* [293] */
    (xdc_Char)0x68,  /* [294] */
    (xdc_Char)0x61,  /* [295] */
    (xdc_Char)0x6e,  /* [296] */
    (xdc_Char)0x20,  /* [297] */
    (xdc_Char)0x61,  /* [298] */
    (xdc_Char)0x6c,  /* [299] */
    (xdc_Char)0x6c,  /* [300] */
    (xdc_Char)0x6f,  /* [301] */
    (xdc_Char)0x77,  /* [302] */
    (xdc_Char)0x65,  /* [303] */
    (xdc_Char)0x64,  /* [304] */
    (xdc_Char)0x0,  /* [305] */
    (xdc_Char)0x41,  /* [306] */
    (xdc_Char)0x5f,  /* [307] */
    (xdc_Char)0x69,  /* [308] */
    (xdc_Char)0x6e,  /* [309] */
    (xdc_Char)0x76,  /* [310] */
    (xdc_Char)0x61,  /* [311] */
    (xdc_Char)0x6c,  /* [312] */
    (xdc_Char)0x69,  /* [313] */
    (xdc_Char)0x64,  /* [314] */
    (xdc_Char)0x4c,  /* [315] */
    (xdc_Char)0x6f,  /* [316] */
    (xdc_Char)0x67,  /* [317] */
    (xdc_Char)0x67,  /* [318] */
    (xdc_Char)0x65,  /* [319] */
    (xdc_Char)0x72,  /* [320] */
    (xdc_Char)0x3a,  /* [321] */
    (xdc_Char)0x20,  /* [322] */
    (xdc_Char)0x54,  /* [323] */
    (xdc_Char)0x68,  /* [324] */
    (xdc_Char)0x65,  /* [325] */
    (xdc_Char)0x20,  /* [326] */
    (xdc_Char)0x6c,  /* [327] */
    (xdc_Char)0x6f,  /* [328] */
    (xdc_Char)0x67,  /* [329] */
    (xdc_Char)0x67,  /* [330] */
    (xdc_Char)0x65,  /* [331] */
    (xdc_Char)0x72,  /* [332] */
    (xdc_Char)0x20,  /* [333] */
    (xdc_Char)0x69,  /* [334] */
    (xdc_Char)0x64,  /* [335] */
    (xdc_Char)0x20,  /* [336] */
    (xdc_Char)0x25,  /* [337] */
    (xdc_Char)0x64,  /* [338] */
    (xdc_Char)0x20,  /* [339] */
    (xdc_Char)0x69,  /* [340] */
    (xdc_Char)0x73,  /* [341] */
    (xdc_Char)0x20,  /* [342] */
    (xdc_Char)0x69,  /* [343] */
    (xdc_Char)0x6e,  /* [344] */
    (xdc_Char)0x76,  /* [345] */
    (xdc_Char)0x61,  /* [346] */
    (xdc_Char)0x6c,  /* [347] */
    (xdc_Char)0x69,  /* [348] */
    (xdc_Char)0x64,  /* [349] */
    (xdc_Char)0x2e,  /* [350] */
    (xdc_Char)0x0,  /* [351] */
    (xdc_Char)0x41,  /* [352] */
    (xdc_Char)0x5f,  /* [353] */
    (xdc_Char)0x63,  /* [354] */
    (xdc_Char)0x61,  /* [355] */
    (xdc_Char)0x6e,  /* [356] */
    (xdc_Char)0x6e,  /* [357] */
    (xdc_Char)0x6f,  /* [358] */
    (xdc_Char)0x74,  /* [359] */
    (xdc_Char)0x46,  /* [360] */
    (xdc_Char)0x69,  /* [361] */
    (xdc_Char)0x74,  /* [362] */
    (xdc_Char)0x49,  /* [363] */
    (xdc_Char)0x6e,  /* [364] */
    (xdc_Char)0x74,  /* [365] */
    (xdc_Char)0x6f,  /* [366] */
    (xdc_Char)0x41,  /* [367] */
    (xdc_Char)0x72,  /* [368] */
    (xdc_Char)0x67,  /* [369] */
    (xdc_Char)0x3a,  /* [370] */
    (xdc_Char)0x20,  /* [371] */
    (xdc_Char)0x73,  /* [372] */
    (xdc_Char)0x69,  /* [373] */
    (xdc_Char)0x7a,  /* [374] */
    (xdc_Char)0x65,  /* [375] */
    (xdc_Char)0x6f,  /* [376] */
    (xdc_Char)0x66,  /* [377] */
    (xdc_Char)0x28,  /* [378] */
    (xdc_Char)0x46,  /* [379] */
    (xdc_Char)0x6c,  /* [380] */
    (xdc_Char)0x6f,  /* [381] */
    (xdc_Char)0x61,  /* [382] */
    (xdc_Char)0x74,  /* [383] */
    (xdc_Char)0x29,  /* [384] */
    (xdc_Char)0x20,  /* [385] */
    (xdc_Char)0x3e,  /* [386] */
    (xdc_Char)0x20,  /* [387] */
    (xdc_Char)0x73,  /* [388] */
    (xdc_Char)0x69,  /* [389] */
    (xdc_Char)0x7a,  /* [390] */
    (xdc_Char)0x65,  /* [391] */
    (xdc_Char)0x6f,  /* [392] */
    (xdc_Char)0x66,  /* [393] */
    (xdc_Char)0x28,  /* [394] */
    (xdc_Char)0x41,  /* [395] */
    (xdc_Char)0x72,  /* [396] */
    (xdc_Char)0x67,  /* [397] */
    (xdc_Char)0x29,  /* [398] */
    (xdc_Char)0x0,  /* [399] */
    (xdc_Char)0x41,  /* [400] */
    (xdc_Char)0x5f,  /* [401] */
    (xdc_Char)0x62,  /* [402] */
    (xdc_Char)0x61,  /* [403] */
    (xdc_Char)0x64,  /* [404] */
    (xdc_Char)0x49,  /* [405] */
    (xdc_Char)0x6e,  /* [406] */
    (xdc_Char)0x74,  /* [407] */
    (xdc_Char)0x4e,  /* [408] */
    (xdc_Char)0x75,  /* [409] */
    (xdc_Char)0x6d,  /* [410] */
    (xdc_Char)0x3a,  /* [411] */
    (xdc_Char)0x20,  /* [412] */
    (xdc_Char)0x49,  /* [413] */
    (xdc_Char)0x6e,  /* [414] */
    (xdc_Char)0x76,  /* [415] */
    (xdc_Char)0x61,  /* [416] */
    (xdc_Char)0x6c,  /* [417] */
    (xdc_Char)0x69,  /* [418] */
    (xdc_Char)0x64,  /* [419] */
    (xdc_Char)0x20,  /* [420] */
    (xdc_Char)0x69,  /* [421] */
    (xdc_Char)0x6e,  /* [422] */
    (xdc_Char)0x74,  /* [423] */
    (xdc_Char)0x65,  /* [424] */
    (xdc_Char)0x72,  /* [425] */
    (xdc_Char)0x72,  /* [426] */
    (xdc_Char)0x75,  /* [427] */
    (xdc_Char)0x70,  /* [428] */
    (xdc_Char)0x74,  /* [429] */
    (xdc_Char)0x20,  /* [430] */
    (xdc_Char)0x6e,  /* [431] */
    (xdc_Char)0x75,  /* [432] */
    (xdc_Char)0x6d,  /* [433] */
    (xdc_Char)0x62,  /* [434] */
    (xdc_Char)0x65,  /* [435] */
    (xdc_Char)0x72,  /* [436] */
    (xdc_Char)0x0,  /* [437] */
    (xdc_Char)0x41,  /* [438] */
    (xdc_Char)0x5f,  /* [439] */
    (xdc_Char)0x69,  /* [440] */
    (xdc_Char)0x6e,  /* [441] */
    (xdc_Char)0x76,  /* [442] */
    (xdc_Char)0x61,  /* [443] */
    (xdc_Char)0x6c,  /* [444] */
    (xdc_Char)0x69,  /* [445] */
    (xdc_Char)0x64,  /* [446] */
    (xdc_Char)0x41,  /* [447] */
    (xdc_Char)0x72,  /* [448] */
    (xdc_Char)0x67,  /* [449] */
    (xdc_Char)0x3a,  /* [450] */
    (xdc_Char)0x20,  /* [451] */
    (xdc_Char)0x49,  /* [452] */
    (xdc_Char)0x6e,  /* [453] */
    (xdc_Char)0x76,  /* [454] */
    (xdc_Char)0x61,  /* [455] */
    (xdc_Char)0x6c,  /* [456] */
    (xdc_Char)0x69,  /* [457] */
    (xdc_Char)0x64,  /* [458] */
    (xdc_Char)0x20,  /* [459] */
    (xdc_Char)0x61,  /* [460] */
    (xdc_Char)0x72,  /* [461] */
    (xdc_Char)0x67,  /* [462] */
    (xdc_Char)0x75,  /* [463] */
    (xdc_Char)0x6d,  /* [464] */
    (xdc_Char)0x65,  /* [465] */
    (xdc_Char)0x6e,  /* [466] */
    (xdc_Char)0x74,  /* [467] */
    (xdc_Char)0x0,  /* [468] */
    (xdc_Char)0x41,  /* [469] */
    (xdc_Char)0x5f,  /* [470] */
    (xdc_Char)0x7a,  /* [471] */
    (xdc_Char)0x65,  /* [472] */
    (xdc_Char)0x72,  /* [473] */
    (xdc_Char)0x6f,  /* [474] */
    (xdc_Char)0x4c,  /* [475] */
    (xdc_Char)0x61,  /* [476] */
    (xdc_Char)0x74,  /* [477] */
    (xdc_Char)0x65,  /* [478] */
    (xdc_Char)0x6e,  /* [479] */
    (xdc_Char)0x63,  /* [480] */
    (xdc_Char)0x79,  /* [481] */
    (xdc_Char)0x43,  /* [482] */
    (xdc_Char)0x6f,  /* [483] */
    (xdc_Char)0x6e,  /* [484] */
    (xdc_Char)0x66,  /* [485] */
    (xdc_Char)0x6c,  /* [486] */
    (xdc_Char)0x69,  /* [487] */
    (xdc_Char)0x63,  /* [488] */
    (xdc_Char)0x74,  /* [489] */
    (xdc_Char)0x3a,  /* [490] */
    (xdc_Char)0x20,  /* [491] */
    (xdc_Char)0x43,  /* [492] */
    (xdc_Char)0x6f,  /* [493] */
    (xdc_Char)0x6e,  /* [494] */
    (xdc_Char)0x66,  /* [495] */
    (xdc_Char)0x6c,  /* [496] */
    (xdc_Char)0x69,  /* [497] */
    (xdc_Char)0x63,  /* [498] */
    (xdc_Char)0x74,  /* [499] */
    (xdc_Char)0x20,  /* [500] */
    (xdc_Char)0x77,  /* [501] */
    (xdc_Char)0x69,  /* [502] */
    (xdc_Char)0x74,  /* [503] */
    (xdc_Char)0x68,  /* [504] */
    (xdc_Char)0x20,  /* [505] */
    (xdc_Char)0x7a,  /* [506] */
    (xdc_Char)0x65,  /* [507] */
    (xdc_Char)0x72,  /* [508] */
    (xdc_Char)0x6f,  /* [509] */
    (xdc_Char)0x20,  /* [510] */
    (xdc_Char)0x6c,  /* [511] */
    (xdc_Char)0x61,  /* [512] */
    (xdc_Char)0x74,  /* [513] */
    (xdc_Char)0x65,  /* [514] */
    (xdc_Char)0x6e,  /* [515] */
    (xdc_Char)0x63,  /* [516] */
    (xdc_Char)0x79,  /* [517] */
    (xdc_Char)0x20,  /* [518] */
    (xdc_Char)0x49,  /* [519] */
    (xdc_Char)0x45,  /* [520] */
    (xdc_Char)0x52,  /* [521] */
    (xdc_Char)0x20,  /* [522] */
    (xdc_Char)0x6d,  /* [523] */
    (xdc_Char)0x61,  /* [524] */
    (xdc_Char)0x73,  /* [525] */
    (xdc_Char)0x6b,  /* [526] */
    (xdc_Char)0x0,  /* [527] */
    (xdc_Char)0x41,  /* [528] */
    (xdc_Char)0x5f,  /* [529] */
    (xdc_Char)0x69,  /* [530] */
    (xdc_Char)0x6e,  /* [531] */
    (xdc_Char)0x76,  /* [532] */
    (xdc_Char)0x61,  /* [533] */
    (xdc_Char)0x6c,  /* [534] */
    (xdc_Char)0x69,  /* [535] */
    (xdc_Char)0x64,  /* [536] */
    (xdc_Char)0x54,  /* [537] */
    (xdc_Char)0x69,  /* [538] */
    (xdc_Char)0x6d,  /* [539] */
    (xdc_Char)0x65,  /* [540] */
    (xdc_Char)0x72,  /* [541] */
    (xdc_Char)0x3a,  /* [542] */
    (xdc_Char)0x20,  /* [543] */
    (xdc_Char)0x54,  /* [544] */
    (xdc_Char)0x69,  /* [545] */
    (xdc_Char)0x6d,  /* [546] */
    (xdc_Char)0x65,  /* [547] */
    (xdc_Char)0x72,  /* [548] */
    (xdc_Char)0x20,  /* [549] */
    (xdc_Char)0x69,  /* [550] */
    (xdc_Char)0x64,  /* [551] */
    (xdc_Char)0x20,  /* [552] */
    (xdc_Char)0x6d,  /* [553] */
    (xdc_Char)0x75,  /* [554] */
    (xdc_Char)0x73,  /* [555] */
    (xdc_Char)0x74,  /* [556] */
    (xdc_Char)0x20,  /* [557] */
    (xdc_Char)0x62,  /* [558] */
    (xdc_Char)0x65,  /* [559] */
    (xdc_Char)0x20,  /* [560] */
    (xdc_Char)0x30,  /* [561] */
    (xdc_Char)0x2d,  /* [562] */
    (xdc_Char)0x32,  /* [563] */
    (xdc_Char)0x0,  /* [564] */
    (xdc_Char)0x41,  /* [565] */
    (xdc_Char)0x5f,  /* [566] */
    (xdc_Char)0x69,  /* [567] */
    (xdc_Char)0x6e,  /* [568] */
    (xdc_Char)0x76,  /* [569] */
    (xdc_Char)0x61,  /* [570] */
    (xdc_Char)0x6c,  /* [571] */
    (xdc_Char)0x69,  /* [572] */
    (xdc_Char)0x64,  /* [573] */
    (xdc_Char)0x52,  /* [574] */
    (xdc_Char)0x75,  /* [575] */
    (xdc_Char)0x6e,  /* [576] */
    (xdc_Char)0x4d,  /* [577] */
    (xdc_Char)0x6f,  /* [578] */
    (xdc_Char)0x64,  /* [579] */
    (xdc_Char)0x65,  /* [580] */
    (xdc_Char)0x3a,  /* [581] */
    (xdc_Char)0x20,  /* [582] */
    (xdc_Char)0x49,  /* [583] */
    (xdc_Char)0x6e,  /* [584] */
    (xdc_Char)0x76,  /* [585] */
    (xdc_Char)0x61,  /* [586] */
    (xdc_Char)0x6c,  /* [587] */
    (xdc_Char)0x69,  /* [588] */
    (xdc_Char)0x64,  /* [589] */
    (xdc_Char)0x20,  /* [590] */
    (xdc_Char)0x52,  /* [591] */
    (xdc_Char)0x75,  /* [592] */
    (xdc_Char)0x6e,  /* [593] */
    (xdc_Char)0x4d,  /* [594] */
    (xdc_Char)0x6f,  /* [595] */
    (xdc_Char)0x64,  /* [596] */
    (xdc_Char)0x65,  /* [597] */
    (xdc_Char)0x0,  /* [598] */
    (xdc_Char)0x41,  /* [599] */
    (xdc_Char)0x5f,  /* [600] */
    (xdc_Char)0x49,  /* [601] */
    (xdc_Char)0x6e,  /* [602] */
    (xdc_Char)0x76,  /* [603] */
    (xdc_Char)0x61,  /* [604] */
    (xdc_Char)0x6c,  /* [605] */
    (xdc_Char)0x69,  /* [606] */
    (xdc_Char)0x64,  /* [607] */
    (xdc_Char)0x4d,  /* [608] */
    (xdc_Char)0x61,  /* [609] */
    (xdc_Char)0x73,  /* [610] */
    (xdc_Char)0x6b,  /* [611] */
    (xdc_Char)0x3a,  /* [612] */
    (xdc_Char)0x20,  /* [613] */
    (xdc_Char)0x4d,  /* [614] */
    (xdc_Char)0x61,  /* [615] */
    (xdc_Char)0x73,  /* [616] */
    (xdc_Char)0x6b,  /* [617] */
    (xdc_Char)0x20,  /* [618] */
    (xdc_Char)0x69,  /* [619] */
    (xdc_Char)0x6e,  /* [620] */
    (xdc_Char)0x20,  /* [621] */
    (xdc_Char)0x68,  /* [622] */
    (xdc_Char)0x77,  /* [623] */
    (xdc_Char)0x69,  /* [624] */
    (xdc_Char)0x50,  /* [625] */
    (xdc_Char)0x61,  /* [626] */
    (xdc_Char)0x72,  /* [627] */
    (xdc_Char)0x61,  /* [628] */
    (xdc_Char)0x6d,  /* [629] */
    (xdc_Char)0x73,  /* [630] */
    (xdc_Char)0x20,  /* [631] */
    (xdc_Char)0x63,  /* [632] */
    (xdc_Char)0x61,  /* [633] */
    (xdc_Char)0x6e,  /* [634] */
    (xdc_Char)0x6e,  /* [635] */
    (xdc_Char)0x6f,  /* [636] */
    (xdc_Char)0x74,  /* [637] */
    (xdc_Char)0x20,  /* [638] */
    (xdc_Char)0x65,  /* [639] */
    (xdc_Char)0x6e,  /* [640] */
    (xdc_Char)0x61,  /* [641] */
    (xdc_Char)0x62,  /* [642] */
    (xdc_Char)0x6c,  /* [643] */
    (xdc_Char)0x65,  /* [644] */
    (xdc_Char)0x20,  /* [645] */
    (xdc_Char)0x73,  /* [646] */
    (xdc_Char)0x65,  /* [647] */
    (xdc_Char)0x6c,  /* [648] */
    (xdc_Char)0x66,  /* [649] */
    (xdc_Char)0x0,  /* [650] */
    (xdc_Char)0x45,  /* [651] */
    (xdc_Char)0x5f,  /* [652] */
    (xdc_Char)0x63,  /* [653] */
    (xdc_Char)0x61,  /* [654] */
    (xdc_Char)0x6e,  /* [655] */
    (xdc_Char)0x6e,  /* [656] */
    (xdc_Char)0x6f,  /* [657] */
    (xdc_Char)0x74,  /* [658] */
    (xdc_Char)0x53,  /* [659] */
    (xdc_Char)0x75,  /* [660] */
    (xdc_Char)0x70,  /* [661] */
    (xdc_Char)0x70,  /* [662] */
    (xdc_Char)0x6f,  /* [663] */
    (xdc_Char)0x72,  /* [664] */
    (xdc_Char)0x74,  /* [665] */
    (xdc_Char)0x3a,  /* [666] */
    (xdc_Char)0x20,  /* [667] */
    (xdc_Char)0x54,  /* [668] */
    (xdc_Char)0x69,  /* [669] */
    (xdc_Char)0x6d,  /* [670] */
    (xdc_Char)0x65,  /* [671] */
    (xdc_Char)0x72,  /* [672] */
    (xdc_Char)0x20,  /* [673] */
    (xdc_Char)0x63,  /* [674] */
    (xdc_Char)0x61,  /* [675] */
    (xdc_Char)0x6e,  /* [676] */
    (xdc_Char)0x6e,  /* [677] */
    (xdc_Char)0x6f,  /* [678] */
    (xdc_Char)0x74,  /* [679] */
    (xdc_Char)0x20,  /* [680] */
    (xdc_Char)0x73,  /* [681] */
    (xdc_Char)0x75,  /* [682] */
    (xdc_Char)0x70,  /* [683] */
    (xdc_Char)0x70,  /* [684] */
    (xdc_Char)0x6f,  /* [685] */
    (xdc_Char)0x72,  /* [686] */
    (xdc_Char)0x74,  /* [687] */
    (xdc_Char)0x20,  /* [688] */
    (xdc_Char)0x72,  /* [689] */
    (xdc_Char)0x65,  /* [690] */
    (xdc_Char)0x71,  /* [691] */
    (xdc_Char)0x75,  /* [692] */
    (xdc_Char)0x65,  /* [693] */
    (xdc_Char)0x73,  /* [694] */
    (xdc_Char)0x74,  /* [695] */
    (xdc_Char)0x65,  /* [696] */
    (xdc_Char)0x64,  /* [697] */
    (xdc_Char)0x20,  /* [698] */
    (xdc_Char)0x70,  /* [699] */
    (xdc_Char)0x65,  /* [700] */
    (xdc_Char)0x72,  /* [701] */
    (xdc_Char)0x69,  /* [702] */
    (xdc_Char)0x6f,  /* [703] */
    (xdc_Char)0x64,  /* [704] */
    (xdc_Char)0x0,  /* [705] */
    (xdc_Char)0x41,  /* [706] */
    (xdc_Char)0x5f,  /* [707] */
    (xdc_Char)0x63,  /* [708] */
    (xdc_Char)0x6c,  /* [709] */
    (xdc_Char)0x6f,  /* [710] */
    (xdc_Char)0x63,  /* [711] */
    (xdc_Char)0x6b,  /* [712] */
    (xdc_Char)0x44,  /* [713] */
    (xdc_Char)0x69,  /* [714] */
    (xdc_Char)0x73,  /* [715] */
    (xdc_Char)0x61,  /* [716] */
    (xdc_Char)0x62,  /* [717] */
    (xdc_Char)0x6c,  /* [718] */
    (xdc_Char)0x65,  /* [719] */
    (xdc_Char)0x64,  /* [720] */
    (xdc_Char)0x3a,  /* [721] */
    (xdc_Char)0x20,  /* [722] */
    (xdc_Char)0x43,  /* [723] */
    (xdc_Char)0x61,  /* [724] */
    (xdc_Char)0x6e,  /* [725] */
    (xdc_Char)0x6e,  /* [726] */
    (xdc_Char)0x6f,  /* [727] */
    (xdc_Char)0x74,  /* [728] */
    (xdc_Char)0x20,  /* [729] */
    (xdc_Char)0x63,  /* [730] */
    (xdc_Char)0x72,  /* [731] */
    (xdc_Char)0x65,  /* [732] */
    (xdc_Char)0x61,  /* [733] */
    (xdc_Char)0x74,  /* [734] */
    (xdc_Char)0x65,  /* [735] */
    (xdc_Char)0x20,  /* [736] */
    (xdc_Char)0x61,  /* [737] */
    (xdc_Char)0x20,  /* [738] */
    (xdc_Char)0x63,  /* [739] */
    (xdc_Char)0x6c,  /* [740] */
    (xdc_Char)0x6f,  /* [741] */
    (xdc_Char)0x63,  /* [742] */
    (xdc_Char)0x6b,  /* [743] */
    (xdc_Char)0x20,  /* [744] */
    (xdc_Char)0x69,  /* [745] */
    (xdc_Char)0x6e,  /* [746] */
    (xdc_Char)0x73,  /* [747] */
    (xdc_Char)0x74,  /* [748] */
    (xdc_Char)0x61,  /* [749] */
    (xdc_Char)0x6e,  /* [750] */
    (xdc_Char)0x63,  /* [751] */
    (xdc_Char)0x65,  /* [752] */
    (xdc_Char)0x20,  /* [753] */
    (xdc_Char)0x77,  /* [754] */
    (xdc_Char)0x68,  /* [755] */
    (xdc_Char)0x65,  /* [756] */
    (xdc_Char)0x6e,  /* [757] */
    (xdc_Char)0x20,  /* [758] */
    (xdc_Char)0x42,  /* [759] */
    (xdc_Char)0x49,  /* [760] */
    (xdc_Char)0x4f,  /* [761] */
    (xdc_Char)0x53,  /* [762] */
    (xdc_Char)0x2e,  /* [763] */
    (xdc_Char)0x63,  /* [764] */
    (xdc_Char)0x6c,  /* [765] */
    (xdc_Char)0x6f,  /* [766] */
    (xdc_Char)0x63,  /* [767] */
    (xdc_Char)0x6b,  /* [768] */
    (xdc_Char)0x45,  /* [769] */
    (xdc_Char)0x6e,  /* [770] */
    (xdc_Char)0x61,  /* [771] */
    (xdc_Char)0x62,  /* [772] */
    (xdc_Char)0x6c,  /* [773] */
    (xdc_Char)0x65,  /* [774] */
    (xdc_Char)0x64,  /* [775] */
    (xdc_Char)0x20,  /* [776] */
    (xdc_Char)0x69,  /* [777] */
    (xdc_Char)0x73,  /* [778] */
    (xdc_Char)0x20,  /* [779] */
    (xdc_Char)0x66,  /* [780] */
    (xdc_Char)0x61,  /* [781] */
    (xdc_Char)0x6c,  /* [782] */
    (xdc_Char)0x73,  /* [783] */
    (xdc_Char)0x65,  /* [784] */
    (xdc_Char)0x2e,  /* [785] */
    (xdc_Char)0x0,  /* [786] */
    (xdc_Char)0x41,  /* [787] */
    (xdc_Char)0x5f,  /* [788] */
    (xdc_Char)0x62,  /* [789] */
    (xdc_Char)0x61,  /* [790] */
    (xdc_Char)0x64,  /* [791] */
    (xdc_Char)0x54,  /* [792] */
    (xdc_Char)0x68,  /* [793] */
    (xdc_Char)0x72,  /* [794] */
    (xdc_Char)0x65,  /* [795] */
    (xdc_Char)0x61,  /* [796] */
    (xdc_Char)0x64,  /* [797] */
    (xdc_Char)0x54,  /* [798] */
    (xdc_Char)0x79,  /* [799] */
    (xdc_Char)0x70,  /* [800] */
    (xdc_Char)0x65,  /* [801] */
    (xdc_Char)0x3a,  /* [802] */
    (xdc_Char)0x20,  /* [803] */
    (xdc_Char)0x43,  /* [804] */
    (xdc_Char)0x61,  /* [805] */
    (xdc_Char)0x6e,  /* [806] */
    (xdc_Char)0x6e,  /* [807] */
    (xdc_Char)0x6f,  /* [808] */
    (xdc_Char)0x74,  /* [809] */
    (xdc_Char)0x20,  /* [810] */
    (xdc_Char)0x63,  /* [811] */
    (xdc_Char)0x72,  /* [812] */
    (xdc_Char)0x65,  /* [813] */
    (xdc_Char)0x61,  /* [814] */
    (xdc_Char)0x74,  /* [815] */
    (xdc_Char)0x65,  /* [816] */
    (xdc_Char)0x2f,  /* [817] */
    (xdc_Char)0x64,  /* [818] */
    (xdc_Char)0x65,  /* [819] */
    (xdc_Char)0x6c,  /* [820] */
    (xdc_Char)0x65,  /* [821] */
    (xdc_Char)0x74,  /* [822] */
    (xdc_Char)0x65,  /* [823] */
    (xdc_Char)0x20,  /* [824] */
    (xdc_Char)0x61,  /* [825] */
    (xdc_Char)0x20,  /* [826] */
    (xdc_Char)0x43,  /* [827] */
    (xdc_Char)0x6c,  /* [828] */
    (xdc_Char)0x6f,  /* [829] */
    (xdc_Char)0x63,  /* [830] */
    (xdc_Char)0x6b,  /* [831] */
    (xdc_Char)0x20,  /* [832] */
    (xdc_Char)0x66,  /* [833] */
    (xdc_Char)0x72,  /* [834] */
    (xdc_Char)0x6f,  /* [835] */
    (xdc_Char)0x6d,  /* [836] */
    (xdc_Char)0x20,  /* [837] */
    (xdc_Char)0x48,  /* [838] */
    (xdc_Char)0x77,  /* [839] */
    (xdc_Char)0x69,  /* [840] */
    (xdc_Char)0x20,  /* [841] */
    (xdc_Char)0x6f,  /* [842] */
    (xdc_Char)0x72,  /* [843] */
    (xdc_Char)0x20,  /* [844] */
    (xdc_Char)0x53,  /* [845] */
    (xdc_Char)0x77,  /* [846] */
    (xdc_Char)0x69,  /* [847] */
    (xdc_Char)0x20,  /* [848] */
    (xdc_Char)0x74,  /* [849] */
    (xdc_Char)0x68,  /* [850] */
    (xdc_Char)0x72,  /* [851] */
    (xdc_Char)0x65,  /* [852] */
    (xdc_Char)0x61,  /* [853] */
    (xdc_Char)0x64,  /* [854] */
    (xdc_Char)0x2e,  /* [855] */
    (xdc_Char)0x0,  /* [856] */
    (xdc_Char)0x41,  /* [857] */
    (xdc_Char)0x5f,  /* [858] */
    (xdc_Char)0x6e,  /* [859] */
    (xdc_Char)0x75,  /* [860] */
    (xdc_Char)0x6c,  /* [861] */
    (xdc_Char)0x6c,  /* [862] */
    (xdc_Char)0x45,  /* [863] */
    (xdc_Char)0x76,  /* [864] */
    (xdc_Char)0x65,  /* [865] */
    (xdc_Char)0x6e,  /* [866] */
    (xdc_Char)0x74,  /* [867] */
    (xdc_Char)0x4d,  /* [868] */
    (xdc_Char)0x61,  /* [869] */
    (xdc_Char)0x73,  /* [870] */
    (xdc_Char)0x6b,  /* [871] */
    (xdc_Char)0x73,  /* [872] */
    (xdc_Char)0x3a,  /* [873] */
    (xdc_Char)0x20,  /* [874] */
    (xdc_Char)0x6f,  /* [875] */
    (xdc_Char)0x72,  /* [876] */
    (xdc_Char)0x4d,  /* [877] */
    (xdc_Char)0x61,  /* [878] */
    (xdc_Char)0x73,  /* [879] */
    (xdc_Char)0x6b,  /* [880] */
    (xdc_Char)0x20,  /* [881] */
    (xdc_Char)0x61,  /* [882] */
    (xdc_Char)0x6e,  /* [883] */
    (xdc_Char)0x64,  /* [884] */
    (xdc_Char)0x20,  /* [885] */
    (xdc_Char)0x61,  /* [886] */
    (xdc_Char)0x6e,  /* [887] */
    (xdc_Char)0x64,  /* [888] */
    (xdc_Char)0x4d,  /* [889] */
    (xdc_Char)0x61,  /* [890] */
    (xdc_Char)0x73,  /* [891] */
    (xdc_Char)0x6b,  /* [892] */
    (xdc_Char)0x20,  /* [893] */
    (xdc_Char)0x61,  /* [894] */
    (xdc_Char)0x72,  /* [895] */
    (xdc_Char)0x65,  /* [896] */
    (xdc_Char)0x20,  /* [897] */
    (xdc_Char)0x6e,  /* [898] */
    (xdc_Char)0x75,  /* [899] */
    (xdc_Char)0x6c,  /* [900] */
    (xdc_Char)0x6c,  /* [901] */
    (xdc_Char)0x2e,  /* [902] */
    (xdc_Char)0x0,  /* [903] */
    (xdc_Char)0x41,  /* [904] */
    (xdc_Char)0x5f,  /* [905] */
    (xdc_Char)0x6e,  /* [906] */
    (xdc_Char)0x75,  /* [907] */
    (xdc_Char)0x6c,  /* [908] */
    (xdc_Char)0x6c,  /* [909] */
    (xdc_Char)0x45,  /* [910] */
    (xdc_Char)0x76,  /* [911] */
    (xdc_Char)0x65,  /* [912] */
    (xdc_Char)0x6e,  /* [913] */
    (xdc_Char)0x74,  /* [914] */
    (xdc_Char)0x49,  /* [915] */
    (xdc_Char)0x64,  /* [916] */
    (xdc_Char)0x3a,  /* [917] */
    (xdc_Char)0x20,  /* [918] */
    (xdc_Char)0x70,  /* [919] */
    (xdc_Char)0x6f,  /* [920] */
    (xdc_Char)0x73,  /* [921] */
    (xdc_Char)0x74,  /* [922] */
    (xdc_Char)0x65,  /* [923] */
    (xdc_Char)0x64,  /* [924] */
    (xdc_Char)0x20,  /* [925] */
    (xdc_Char)0x65,  /* [926] */
    (xdc_Char)0x76,  /* [927] */
    (xdc_Char)0x65,  /* [928] */
    (xdc_Char)0x6e,  /* [929] */
    (xdc_Char)0x74,  /* [930] */
    (xdc_Char)0x49,  /* [931] */
    (xdc_Char)0x64,  /* [932] */
    (xdc_Char)0x20,  /* [933] */
    (xdc_Char)0x69,  /* [934] */
    (xdc_Char)0x73,  /* [935] */
    (xdc_Char)0x20,  /* [936] */
    (xdc_Char)0x6e,  /* [937] */
    (xdc_Char)0x75,  /* [938] */
    (xdc_Char)0x6c,  /* [939] */
    (xdc_Char)0x6c,  /* [940] */
    (xdc_Char)0x2e,  /* [941] */
    (xdc_Char)0x0,  /* [942] */
    (xdc_Char)0x41,  /* [943] */
    (xdc_Char)0x5f,  /* [944] */
    (xdc_Char)0x65,  /* [945] */
    (xdc_Char)0x76,  /* [946] */
    (xdc_Char)0x65,  /* [947] */
    (xdc_Char)0x6e,  /* [948] */
    (xdc_Char)0x74,  /* [949] */
    (xdc_Char)0x49,  /* [950] */
    (xdc_Char)0x6e,  /* [951] */
    (xdc_Char)0x55,  /* [952] */
    (xdc_Char)0x73,  /* [953] */
    (xdc_Char)0x65,  /* [954] */
    (xdc_Char)0x3a,  /* [955] */
    (xdc_Char)0x20,  /* [956] */
    (xdc_Char)0x45,  /* [957] */
    (xdc_Char)0x76,  /* [958] */
    (xdc_Char)0x65,  /* [959] */
    (xdc_Char)0x6e,  /* [960] */
    (xdc_Char)0x74,  /* [961] */
    (xdc_Char)0x20,  /* [962] */
    (xdc_Char)0x6f,  /* [963] */
    (xdc_Char)0x62,  /* [964] */
    (xdc_Char)0x6a,  /* [965] */
    (xdc_Char)0x65,  /* [966] */
    (xdc_Char)0x63,  /* [967] */
    (xdc_Char)0x74,  /* [968] */
    (xdc_Char)0x20,  /* [969] */
    (xdc_Char)0x61,  /* [970] */
    (xdc_Char)0x6c,  /* [971] */
    (xdc_Char)0x72,  /* [972] */
    (xdc_Char)0x65,  /* [973] */
    (xdc_Char)0x61,  /* [974] */
    (xdc_Char)0x64,  /* [975] */
    (xdc_Char)0x79,  /* [976] */
    (xdc_Char)0x20,  /* [977] */
    (xdc_Char)0x69,  /* [978] */
    (xdc_Char)0x6e,  /* [979] */
    (xdc_Char)0x20,  /* [980] */
    (xdc_Char)0x75,  /* [981] */
    (xdc_Char)0x73,  /* [982] */
    (xdc_Char)0x65,  /* [983] */
    (xdc_Char)0x2e,  /* [984] */
    (xdc_Char)0x0,  /* [985] */
    (xdc_Char)0x41,  /* [986] */
    (xdc_Char)0x5f,  /* [987] */
    (xdc_Char)0x62,  /* [988] */
    (xdc_Char)0x61,  /* [989] */
    (xdc_Char)0x64,  /* [990] */
    (xdc_Char)0x43,  /* [991] */
    (xdc_Char)0x6f,  /* [992] */
    (xdc_Char)0x6e,  /* [993] */
    (xdc_Char)0x74,  /* [994] */
    (xdc_Char)0x65,  /* [995] */
    (xdc_Char)0x78,  /* [996] */
    (xdc_Char)0x74,  /* [997] */
    (xdc_Char)0x3a,  /* [998] */
    (xdc_Char)0x20,  /* [999] */
    (xdc_Char)0x62,  /* [1000] */
    (xdc_Char)0x61,  /* [1001] */
    (xdc_Char)0x64,  /* [1002] */
    (xdc_Char)0x20,  /* [1003] */
    (xdc_Char)0x63,  /* [1004] */
    (xdc_Char)0x61,  /* [1005] */
    (xdc_Char)0x6c,  /* [1006] */
    (xdc_Char)0x6c,  /* [1007] */
    (xdc_Char)0x69,  /* [1008] */
    (xdc_Char)0x6e,  /* [1009] */
    (xdc_Char)0x67,  /* [1010] */
    (xdc_Char)0x20,  /* [1011] */
    (xdc_Char)0x63,  /* [1012] */
    (xdc_Char)0x6f,  /* [1013] */
    (xdc_Char)0x6e,  /* [1014] */
    (xdc_Char)0x74,  /* [1015] */
    (xdc_Char)0x65,  /* [1016] */
    (xdc_Char)0x78,  /* [1017] */
    (xdc_Char)0x74,  /* [1018] */
    (xdc_Char)0x2e,  /* [1019] */
    (xdc_Char)0x20,  /* [1020] */
    (xdc_Char)0x4d,  /* [1021] */
    (xdc_Char)0x75,  /* [1022] */
    (xdc_Char)0x73,  /* [1023] */
    (xdc_Char)0x74,  /* [1024] */
    (xdc_Char)0x20,  /* [1025] */
    (xdc_Char)0x62,  /* [1026] */
    (xdc_Char)0x65,  /* [1027] */
    (xdc_Char)0x20,  /* [1028] */
    (xdc_Char)0x63,  /* [1029] */
    (xdc_Char)0x61,  /* [1030] */
    (xdc_Char)0x6c,  /* [1031] */
    (xdc_Char)0x6c,  /* [1032] */
    (xdc_Char)0x65,  /* [1033] */
    (xdc_Char)0x64,  /* [1034] */
    (xdc_Char)0x20,  /* [1035] */
    (xdc_Char)0x66,  /* [1036] */
    (xdc_Char)0x72,  /* [1037] */
    (xdc_Char)0x6f,  /* [1038] */
    (xdc_Char)0x6d,  /* [1039] */
    (xdc_Char)0x20,  /* [1040] */
    (xdc_Char)0x61,  /* [1041] */
    (xdc_Char)0x20,  /* [1042] */
    (xdc_Char)0x54,  /* [1043] */
    (xdc_Char)0x61,  /* [1044] */
    (xdc_Char)0x73,  /* [1045] */
    (xdc_Char)0x6b,  /* [1046] */
    (xdc_Char)0x2e,  /* [1047] */
    (xdc_Char)0x0,  /* [1048] */
    (xdc_Char)0x41,  /* [1049] */
    (xdc_Char)0x5f,  /* [1050] */
    (xdc_Char)0x70,  /* [1051] */
    (xdc_Char)0x65,  /* [1052] */
    (xdc_Char)0x6e,  /* [1053] */
    (xdc_Char)0x64,  /* [1054] */
    (xdc_Char)0x54,  /* [1055] */
    (xdc_Char)0x61,  /* [1056] */
    (xdc_Char)0x73,  /* [1057] */
    (xdc_Char)0x6b,  /* [1058] */
    (xdc_Char)0x44,  /* [1059] */
    (xdc_Char)0x69,  /* [1060] */
    (xdc_Char)0x73,  /* [1061] */
    (xdc_Char)0x61,  /* [1062] */
    (xdc_Char)0x62,  /* [1063] */
    (xdc_Char)0x6c,  /* [1064] */
    (xdc_Char)0x65,  /* [1065] */
    (xdc_Char)0x64,  /* [1066] */
    (xdc_Char)0x3a,  /* [1067] */
    (xdc_Char)0x20,  /* [1068] */
    (xdc_Char)0x43,  /* [1069] */
    (xdc_Char)0x61,  /* [1070] */
    (xdc_Char)0x6e,  /* [1071] */
    (xdc_Char)0x6e,  /* [1072] */
    (xdc_Char)0x6f,  /* [1073] */
    (xdc_Char)0x74,  /* [1074] */
    (xdc_Char)0x20,  /* [1075] */
    (xdc_Char)0x63,  /* [1076] */
    (xdc_Char)0x61,  /* [1077] */
    (xdc_Char)0x6c,  /* [1078] */
    (xdc_Char)0x6c,  /* [1079] */
    (xdc_Char)0x20,  /* [1080] */
    (xdc_Char)0x45,  /* [1081] */
    (xdc_Char)0x76,  /* [1082] */
    (xdc_Char)0x65,  /* [1083] */
    (xdc_Char)0x6e,  /* [1084] */
    (xdc_Char)0x74,  /* [1085] */
    (xdc_Char)0x5f,  /* [1086] */
    (xdc_Char)0x70,  /* [1087] */
    (xdc_Char)0x65,  /* [1088] */
    (xdc_Char)0x6e,  /* [1089] */
    (xdc_Char)0x64,  /* [1090] */
    (xdc_Char)0x28,  /* [1091] */
    (xdc_Char)0x29,  /* [1092] */
    (xdc_Char)0x20,  /* [1093] */
    (xdc_Char)0x77,  /* [1094] */
    (xdc_Char)0x68,  /* [1095] */
    (xdc_Char)0x69,  /* [1096] */
    (xdc_Char)0x6c,  /* [1097] */
    (xdc_Char)0x65,  /* [1098] */
    (xdc_Char)0x20,  /* [1099] */
    (xdc_Char)0x74,  /* [1100] */
    (xdc_Char)0x68,  /* [1101] */
    (xdc_Char)0x65,  /* [1102] */
    (xdc_Char)0x20,  /* [1103] */
    (xdc_Char)0x54,  /* [1104] */
    (xdc_Char)0x61,  /* [1105] */
    (xdc_Char)0x73,  /* [1106] */
    (xdc_Char)0x6b,  /* [1107] */
    (xdc_Char)0x20,  /* [1108] */
    (xdc_Char)0x6f,  /* [1109] */
    (xdc_Char)0x72,  /* [1110] */
    (xdc_Char)0x20,  /* [1111] */
    (xdc_Char)0x53,  /* [1112] */
    (xdc_Char)0x77,  /* [1113] */
    (xdc_Char)0x69,  /* [1114] */
    (xdc_Char)0x20,  /* [1115] */
    (xdc_Char)0x73,  /* [1116] */
    (xdc_Char)0x63,  /* [1117] */
    (xdc_Char)0x68,  /* [1118] */
    (xdc_Char)0x65,  /* [1119] */
    (xdc_Char)0x64,  /* [1120] */
    (xdc_Char)0x75,  /* [1121] */
    (xdc_Char)0x6c,  /* [1122] */
    (xdc_Char)0x65,  /* [1123] */
    (xdc_Char)0x72,  /* [1124] */
    (xdc_Char)0x20,  /* [1125] */
    (xdc_Char)0x69,  /* [1126] */
    (xdc_Char)0x73,  /* [1127] */
    (xdc_Char)0x20,  /* [1128] */
    (xdc_Char)0x64,  /* [1129] */
    (xdc_Char)0x69,  /* [1130] */
    (xdc_Char)0x73,  /* [1131] */
    (xdc_Char)0x61,  /* [1132] */
    (xdc_Char)0x62,  /* [1133] */
    (xdc_Char)0x6c,  /* [1134] */
    (xdc_Char)0x65,  /* [1135] */
    (xdc_Char)0x64,  /* [1136] */
    (xdc_Char)0x2e,  /* [1137] */
    (xdc_Char)0x0,  /* [1138] */
    (xdc_Char)0x4d,  /* [1139] */
    (xdc_Char)0x61,  /* [1140] */
    (xdc_Char)0x69,  /* [1141] */
    (xdc_Char)0x6c,  /* [1142] */
    (xdc_Char)0x62,  /* [1143] */
    (xdc_Char)0x6f,  /* [1144] */
    (xdc_Char)0x78,  /* [1145] */
    (xdc_Char)0x5f,  /* [1146] */
    (xdc_Char)0x63,  /* [1147] */
    (xdc_Char)0x72,  /* [1148] */
    (xdc_Char)0x65,  /* [1149] */
    (xdc_Char)0x61,  /* [1150] */
    (xdc_Char)0x74,  /* [1151] */
    (xdc_Char)0x65,  /* [1152] */
    (xdc_Char)0x27,  /* [1153] */
    (xdc_Char)0x73,  /* [1154] */
    (xdc_Char)0x20,  /* [1155] */
    (xdc_Char)0x62,  /* [1156] */
    (xdc_Char)0x75,  /* [1157] */
    (xdc_Char)0x66,  /* [1158] */
    (xdc_Char)0x53,  /* [1159] */
    (xdc_Char)0x69,  /* [1160] */
    (xdc_Char)0x7a,  /* [1161] */
    (xdc_Char)0x65,  /* [1162] */
    (xdc_Char)0x20,  /* [1163] */
    (xdc_Char)0x70,  /* [1164] */
    (xdc_Char)0x61,  /* [1165] */
    (xdc_Char)0x72,  /* [1166] */
    (xdc_Char)0x61,  /* [1167] */
    (xdc_Char)0x6d,  /* [1168] */
    (xdc_Char)0x65,  /* [1169] */
    (xdc_Char)0x74,  /* [1170] */
    (xdc_Char)0x65,  /* [1171] */
    (xdc_Char)0x72,  /* [1172] */
    (xdc_Char)0x20,  /* [1173] */
    (xdc_Char)0x69,  /* [1174] */
    (xdc_Char)0x73,  /* [1175] */
    (xdc_Char)0x20,  /* [1176] */
    (xdc_Char)0x69,  /* [1177] */
    (xdc_Char)0x6e,  /* [1178] */
    (xdc_Char)0x76,  /* [1179] */
    (xdc_Char)0x61,  /* [1180] */
    (xdc_Char)0x6c,  /* [1181] */
    (xdc_Char)0x69,  /* [1182] */
    (xdc_Char)0x64,  /* [1183] */
    (xdc_Char)0x20,  /* [1184] */
    (xdc_Char)0x28,  /* [1185] */
    (xdc_Char)0x74,  /* [1186] */
    (xdc_Char)0x6f,  /* [1187] */
    (xdc_Char)0x6f,  /* [1188] */
    (xdc_Char)0x20,  /* [1189] */
    (xdc_Char)0x73,  /* [1190] */
    (xdc_Char)0x6d,  /* [1191] */
    (xdc_Char)0x61,  /* [1192] */
    (xdc_Char)0x6c,  /* [1193] */
    (xdc_Char)0x6c,  /* [1194] */
    (xdc_Char)0x29,  /* [1195] */
    (xdc_Char)0x0,  /* [1196] */
    (xdc_Char)0x41,  /* [1197] */
    (xdc_Char)0x5f,  /* [1198] */
    (xdc_Char)0x6e,  /* [1199] */
    (xdc_Char)0x6f,  /* [1200] */
    (xdc_Char)0x45,  /* [1201] */
    (xdc_Char)0x76,  /* [1202] */
    (xdc_Char)0x65,  /* [1203] */
    (xdc_Char)0x6e,  /* [1204] */
    (xdc_Char)0x74,  /* [1205] */
    (xdc_Char)0x73,  /* [1206] */
    (xdc_Char)0x3a,  /* [1207] */
    (xdc_Char)0x20,  /* [1208] */
    (xdc_Char)0x54,  /* [1209] */
    (xdc_Char)0x68,  /* [1210] */
    (xdc_Char)0x65,  /* [1211] */
    (xdc_Char)0x20,  /* [1212] */
    (xdc_Char)0x45,  /* [1213] */
    (xdc_Char)0x76,  /* [1214] */
    (xdc_Char)0x65,  /* [1215] */
    (xdc_Char)0x6e,  /* [1216] */
    (xdc_Char)0x74,  /* [1217] */
    (xdc_Char)0x2e,  /* [1218] */
    (xdc_Char)0x73,  /* [1219] */
    (xdc_Char)0x75,  /* [1220] */
    (xdc_Char)0x70,  /* [1221] */
    (xdc_Char)0x70,  /* [1222] */
    (xdc_Char)0x6f,  /* [1223] */
    (xdc_Char)0x72,  /* [1224] */
    (xdc_Char)0x74,  /* [1225] */
    (xdc_Char)0x73,  /* [1226] */
    (xdc_Char)0x45,  /* [1227] */
    (xdc_Char)0x76,  /* [1228] */
    (xdc_Char)0x65,  /* [1229] */
    (xdc_Char)0x6e,  /* [1230] */
    (xdc_Char)0x74,  /* [1231] */
    (xdc_Char)0x73,  /* [1232] */
    (xdc_Char)0x20,  /* [1233] */
    (xdc_Char)0x66,  /* [1234] */
    (xdc_Char)0x6c,  /* [1235] */
    (xdc_Char)0x61,  /* [1236] */
    (xdc_Char)0x67,  /* [1237] */
    (xdc_Char)0x20,  /* [1238] */
    (xdc_Char)0x69,  /* [1239] */
    (xdc_Char)0x73,  /* [1240] */
    (xdc_Char)0x20,  /* [1241] */
    (xdc_Char)0x64,  /* [1242] */
    (xdc_Char)0x69,  /* [1243] */
    (xdc_Char)0x73,  /* [1244] */
    (xdc_Char)0x61,  /* [1245] */
    (xdc_Char)0x62,  /* [1246] */
    (xdc_Char)0x6c,  /* [1247] */
    (xdc_Char)0x65,  /* [1248] */
    (xdc_Char)0x64,  /* [1249] */
    (xdc_Char)0x2e,  /* [1250] */
    (xdc_Char)0x0,  /* [1251] */
    (xdc_Char)0x41,  /* [1252] */
    (xdc_Char)0x5f,  /* [1253] */
    (xdc_Char)0x69,  /* [1254] */
    (xdc_Char)0x6e,  /* [1255] */
    (xdc_Char)0x76,  /* [1256] */
    (xdc_Char)0x54,  /* [1257] */
    (xdc_Char)0x69,  /* [1258] */
    (xdc_Char)0x6d,  /* [1259] */
    (xdc_Char)0x65,  /* [1260] */
    (xdc_Char)0x6f,  /* [1261] */
    (xdc_Char)0x75,  /* [1262] */
    (xdc_Char)0x74,  /* [1263] */
    (xdc_Char)0x3a,  /* [1264] */
    (xdc_Char)0x20,  /* [1265] */
    (xdc_Char)0x43,  /* [1266] */
    (xdc_Char)0x61,  /* [1267] */
    (xdc_Char)0x6e,  /* [1268] */
    (xdc_Char)0x27,  /* [1269] */
    (xdc_Char)0x74,  /* [1270] */
    (xdc_Char)0x20,  /* [1271] */
    (xdc_Char)0x75,  /* [1272] */
    (xdc_Char)0x73,  /* [1273] */
    (xdc_Char)0x65,  /* [1274] */
    (xdc_Char)0x20,  /* [1275] */
    (xdc_Char)0x42,  /* [1276] */
    (xdc_Char)0x49,  /* [1277] */
    (xdc_Char)0x4f,  /* [1278] */
    (xdc_Char)0x53,  /* [1279] */
    (xdc_Char)0x5f,  /* [1280] */
    (xdc_Char)0x45,  /* [1281] */
    (xdc_Char)0x56,  /* [1282] */
    (xdc_Char)0x45,  /* [1283] */
    (xdc_Char)0x4e,  /* [1284] */
    (xdc_Char)0x54,  /* [1285] */
    (xdc_Char)0x5f,  /* [1286] */
    (xdc_Char)0x41,  /* [1287] */
    (xdc_Char)0x43,  /* [1288] */
    (xdc_Char)0x51,  /* [1289] */
    (xdc_Char)0x55,  /* [1290] */
    (xdc_Char)0x49,  /* [1291] */
    (xdc_Char)0x52,  /* [1292] */
    (xdc_Char)0x45,  /* [1293] */
    (xdc_Char)0x44,  /* [1294] */
    (xdc_Char)0x20,  /* [1295] */
    (xdc_Char)0x77,  /* [1296] */
    (xdc_Char)0x69,  /* [1297] */
    (xdc_Char)0x74,  /* [1298] */
    (xdc_Char)0x68,  /* [1299] */
    (xdc_Char)0x20,  /* [1300] */
    (xdc_Char)0x74,  /* [1301] */
    (xdc_Char)0x68,  /* [1302] */
    (xdc_Char)0x69,  /* [1303] */
    (xdc_Char)0x73,  /* [1304] */
    (xdc_Char)0x20,  /* [1305] */
    (xdc_Char)0x53,  /* [1306] */
    (xdc_Char)0x65,  /* [1307] */
    (xdc_Char)0x6d,  /* [1308] */
    (xdc_Char)0x61,  /* [1309] */
    (xdc_Char)0x70,  /* [1310] */
    (xdc_Char)0x68,  /* [1311] */
    (xdc_Char)0x6f,  /* [1312] */
    (xdc_Char)0x72,  /* [1313] */
    (xdc_Char)0x65,  /* [1314] */
    (xdc_Char)0x2e,  /* [1315] */
    (xdc_Char)0x0,  /* [1316] */
    (xdc_Char)0x41,  /* [1317] */
    (xdc_Char)0x5f,  /* [1318] */
    (xdc_Char)0x6f,  /* [1319] */
    (xdc_Char)0x76,  /* [1320] */
    (xdc_Char)0x65,  /* [1321] */
    (xdc_Char)0x72,  /* [1322] */
    (xdc_Char)0x66,  /* [1323] */
    (xdc_Char)0x6c,  /* [1324] */
    (xdc_Char)0x6f,  /* [1325] */
    (xdc_Char)0x77,  /* [1326] */
    (xdc_Char)0x3a,  /* [1327] */
    (xdc_Char)0x20,  /* [1328] */
    (xdc_Char)0x43,  /* [1329] */
    (xdc_Char)0x6f,  /* [1330] */
    (xdc_Char)0x75,  /* [1331] */
    (xdc_Char)0x6e,  /* [1332] */
    (xdc_Char)0x74,  /* [1333] */
    (xdc_Char)0x20,  /* [1334] */
    (xdc_Char)0x68,  /* [1335] */
    (xdc_Char)0x61,  /* [1336] */
    (xdc_Char)0x73,  /* [1337] */
    (xdc_Char)0x20,  /* [1338] */
    (xdc_Char)0x65,  /* [1339] */
    (xdc_Char)0x78,  /* [1340] */
    (xdc_Char)0x63,  /* [1341] */
    (xdc_Char)0x65,  /* [1342] */
    (xdc_Char)0x65,  /* [1343] */
    (xdc_Char)0x64,  /* [1344] */
    (xdc_Char)0x65,  /* [1345] */
    (xdc_Char)0x64,  /* [1346] */
    (xdc_Char)0x20,  /* [1347] */
    (xdc_Char)0x36,  /* [1348] */
    (xdc_Char)0x35,  /* [1349] */
    (xdc_Char)0x35,  /* [1350] */
    (xdc_Char)0x33,  /* [1351] */
    (xdc_Char)0x35,  /* [1352] */
    (xdc_Char)0x20,  /* [1353] */
    (xdc_Char)0x61,  /* [1354] */
    (xdc_Char)0x6e,  /* [1355] */
    (xdc_Char)0x64,  /* [1356] */
    (xdc_Char)0x20,  /* [1357] */
    (xdc_Char)0x72,  /* [1358] */
    (xdc_Char)0x6f,  /* [1359] */
    (xdc_Char)0x6c,  /* [1360] */
    (xdc_Char)0x6c,  /* [1361] */
    (xdc_Char)0x65,  /* [1362] */
    (xdc_Char)0x64,  /* [1363] */
    (xdc_Char)0x20,  /* [1364] */
    (xdc_Char)0x6f,  /* [1365] */
    (xdc_Char)0x76,  /* [1366] */
    (xdc_Char)0x65,  /* [1367] */
    (xdc_Char)0x72,  /* [1368] */
    (xdc_Char)0x2e,  /* [1369] */
    (xdc_Char)0x0,  /* [1370] */
    (xdc_Char)0x41,  /* [1371] */
    (xdc_Char)0x5f,  /* [1372] */
    (xdc_Char)0x70,  /* [1373] */
    (xdc_Char)0x65,  /* [1374] */
    (xdc_Char)0x6e,  /* [1375] */
    (xdc_Char)0x64,  /* [1376] */
    (xdc_Char)0x54,  /* [1377] */
    (xdc_Char)0x61,  /* [1378] */
    (xdc_Char)0x73,  /* [1379] */
    (xdc_Char)0x6b,  /* [1380] */
    (xdc_Char)0x44,  /* [1381] */
    (xdc_Char)0x69,  /* [1382] */
    (xdc_Char)0x73,  /* [1383] */
    (xdc_Char)0x61,  /* [1384] */
    (xdc_Char)0x62,  /* [1385] */
    (xdc_Char)0x6c,  /* [1386] */
    (xdc_Char)0x65,  /* [1387] */
    (xdc_Char)0x64,  /* [1388] */
    (xdc_Char)0x3a,  /* [1389] */
    (xdc_Char)0x20,  /* [1390] */
    (xdc_Char)0x43,  /* [1391] */
    (xdc_Char)0x61,  /* [1392] */
    (xdc_Char)0x6e,  /* [1393] */
    (xdc_Char)0x6e,  /* [1394] */
    (xdc_Char)0x6f,  /* [1395] */
    (xdc_Char)0x74,  /* [1396] */
    (xdc_Char)0x20,  /* [1397] */
    (xdc_Char)0x63,  /* [1398] */
    (xdc_Char)0x61,  /* [1399] */
    (xdc_Char)0x6c,  /* [1400] */
    (xdc_Char)0x6c,  /* [1401] */
    (xdc_Char)0x20,  /* [1402] */
    (xdc_Char)0x53,  /* [1403] */
    (xdc_Char)0x65,  /* [1404] */
    (xdc_Char)0x6d,  /* [1405] */
    (xdc_Char)0x61,  /* [1406] */
    (xdc_Char)0x70,  /* [1407] */
    (xdc_Char)0x68,  /* [1408] */
    (xdc_Char)0x6f,  /* [1409] */
    (xdc_Char)0x72,  /* [1410] */
    (xdc_Char)0x65,  /* [1411] */
    (xdc_Char)0x5f,  /* [1412] */
    (xdc_Char)0x70,  /* [1413] */
    (xdc_Char)0x65,  /* [1414] */
    (xdc_Char)0x6e,  /* [1415] */
    (xdc_Char)0x64,  /* [1416] */
    (xdc_Char)0x28,  /* [1417] */
    (xdc_Char)0x29,  /* [1418] */
    (xdc_Char)0x20,  /* [1419] */
    (xdc_Char)0x77,  /* [1420] */
    (xdc_Char)0x68,  /* [1421] */
    (xdc_Char)0x69,  /* [1422] */
    (xdc_Char)0x6c,  /* [1423] */
    (xdc_Char)0x65,  /* [1424] */
    (xdc_Char)0x20,  /* [1425] */
    (xdc_Char)0x74,  /* [1426] */
    (xdc_Char)0x68,  /* [1427] */
    (xdc_Char)0x65,  /* [1428] */
    (xdc_Char)0x20,  /* [1429] */
    (xdc_Char)0x54,  /* [1430] */
    (xdc_Char)0x61,  /* [1431] */
    (xdc_Char)0x73,  /* [1432] */
    (xdc_Char)0x6b,  /* [1433] */
    (xdc_Char)0x20,  /* [1434] */
    (xdc_Char)0x6f,  /* [1435] */
    (xdc_Char)0x72,  /* [1436] */
    (xdc_Char)0x20,  /* [1437] */
    (xdc_Char)0x53,  /* [1438] */
    (xdc_Char)0x77,  /* [1439] */
    (xdc_Char)0x69,  /* [1440] */
    (xdc_Char)0x20,  /* [1441] */
    (xdc_Char)0x73,  /* [1442] */
    (xdc_Char)0x63,  /* [1443] */
    (xdc_Char)0x68,  /* [1444] */
    (xdc_Char)0x65,  /* [1445] */
    (xdc_Char)0x64,  /* [1446] */
    (xdc_Char)0x75,  /* [1447] */
    (xdc_Char)0x6c,  /* [1448] */
    (xdc_Char)0x65,  /* [1449] */
    (xdc_Char)0x72,  /* [1450] */
    (xdc_Char)0x20,  /* [1451] */
    (xdc_Char)0x69,  /* [1452] */
    (xdc_Char)0x73,  /* [1453] */
    (xdc_Char)0x20,  /* [1454] */
    (xdc_Char)0x64,  /* [1455] */
    (xdc_Char)0x69,  /* [1456] */
    (xdc_Char)0x73,  /* [1457] */
    (xdc_Char)0x61,  /* [1458] */
    (xdc_Char)0x62,  /* [1459] */
    (xdc_Char)0x6c,  /* [1460] */
    (xdc_Char)0x65,  /* [1461] */
    (xdc_Char)0x64,  /* [1462] */
    (xdc_Char)0x2e,  /* [1463] */
    (xdc_Char)0x0,  /* [1464] */
    (xdc_Char)0x41,  /* [1465] */
    (xdc_Char)0x5f,  /* [1466] */
    (xdc_Char)0x73,  /* [1467] */
    (xdc_Char)0x77,  /* [1468] */
    (xdc_Char)0x69,  /* [1469] */
    (xdc_Char)0x44,  /* [1470] */
    (xdc_Char)0x69,  /* [1471] */
    (xdc_Char)0x73,  /* [1472] */
    (xdc_Char)0x61,  /* [1473] */
    (xdc_Char)0x62,  /* [1474] */
    (xdc_Char)0x6c,  /* [1475] */
    (xdc_Char)0x65,  /* [1476] */
    (xdc_Char)0x64,  /* [1477] */
    (xdc_Char)0x3a,  /* [1478] */
    (xdc_Char)0x20,  /* [1479] */
    (xdc_Char)0x43,  /* [1480] */
    (xdc_Char)0x61,  /* [1481] */
    (xdc_Char)0x6e,  /* [1482] */
    (xdc_Char)0x6e,  /* [1483] */
    (xdc_Char)0x6f,  /* [1484] */
    (xdc_Char)0x74,  /* [1485] */
    (xdc_Char)0x20,  /* [1486] */
    (xdc_Char)0x63,  /* [1487] */
    (xdc_Char)0x72,  /* [1488] */
    (xdc_Char)0x65,  /* [1489] */
    (xdc_Char)0x61,  /* [1490] */
    (xdc_Char)0x74,  /* [1491] */
    (xdc_Char)0x65,  /* [1492] */
    (xdc_Char)0x20,  /* [1493] */
    (xdc_Char)0x61,  /* [1494] */
    (xdc_Char)0x20,  /* [1495] */
    (xdc_Char)0x53,  /* [1496] */
    (xdc_Char)0x77,  /* [1497] */
    (xdc_Char)0x69,  /* [1498] */
    (xdc_Char)0x20,  /* [1499] */
    (xdc_Char)0x77,  /* [1500] */
    (xdc_Char)0x68,  /* [1501] */
    (xdc_Char)0x65,  /* [1502] */
    (xdc_Char)0x6e,  /* [1503] */
    (xdc_Char)0x20,  /* [1504] */
    (xdc_Char)0x53,  /* [1505] */
    (xdc_Char)0x77,  /* [1506] */
    (xdc_Char)0x69,  /* [1507] */
    (xdc_Char)0x20,  /* [1508] */
    (xdc_Char)0x69,  /* [1509] */
    (xdc_Char)0x73,  /* [1510] */
    (xdc_Char)0x20,  /* [1511] */
    (xdc_Char)0x64,  /* [1512] */
    (xdc_Char)0x69,  /* [1513] */
    (xdc_Char)0x73,  /* [1514] */
    (xdc_Char)0x61,  /* [1515] */
    (xdc_Char)0x62,  /* [1516] */
    (xdc_Char)0x6c,  /* [1517] */
    (xdc_Char)0x65,  /* [1518] */
    (xdc_Char)0x64,  /* [1519] */
    (xdc_Char)0x2e,  /* [1520] */
    (xdc_Char)0x0,  /* [1521] */
    (xdc_Char)0x41,  /* [1522] */
    (xdc_Char)0x5f,  /* [1523] */
    (xdc_Char)0x62,  /* [1524] */
    (xdc_Char)0x61,  /* [1525] */
    (xdc_Char)0x64,  /* [1526] */
    (xdc_Char)0x50,  /* [1527] */
    (xdc_Char)0x72,  /* [1528] */
    (xdc_Char)0x69,  /* [1529] */
    (xdc_Char)0x6f,  /* [1530] */
    (xdc_Char)0x72,  /* [1531] */
    (xdc_Char)0x69,  /* [1532] */
    (xdc_Char)0x74,  /* [1533] */
    (xdc_Char)0x79,  /* [1534] */
    (xdc_Char)0x3a,  /* [1535] */
    (xdc_Char)0x20,  /* [1536] */
    (xdc_Char)0x41,  /* [1537] */
    (xdc_Char)0x6e,  /* [1538] */
    (xdc_Char)0x20,  /* [1539] */
    (xdc_Char)0x69,  /* [1540] */
    (xdc_Char)0x6e,  /* [1541] */
    (xdc_Char)0x76,  /* [1542] */
    (xdc_Char)0x61,  /* [1543] */
    (xdc_Char)0x6c,  /* [1544] */
    (xdc_Char)0x69,  /* [1545] */
    (xdc_Char)0x64,  /* [1546] */
    (xdc_Char)0x20,  /* [1547] */
    (xdc_Char)0x53,  /* [1548] */
    (xdc_Char)0x77,  /* [1549] */
    (xdc_Char)0x69,  /* [1550] */
    (xdc_Char)0x20,  /* [1551] */
    (xdc_Char)0x70,  /* [1552] */
    (xdc_Char)0x72,  /* [1553] */
    (xdc_Char)0x69,  /* [1554] */
    (xdc_Char)0x6f,  /* [1555] */
    (xdc_Char)0x72,  /* [1556] */
    (xdc_Char)0x69,  /* [1557] */
    (xdc_Char)0x74,  /* [1558] */
    (xdc_Char)0x79,  /* [1559] */
    (xdc_Char)0x20,  /* [1560] */
    (xdc_Char)0x77,  /* [1561] */
    (xdc_Char)0x61,  /* [1562] */
    (xdc_Char)0x73,  /* [1563] */
    (xdc_Char)0x20,  /* [1564] */
    (xdc_Char)0x75,  /* [1565] */
    (xdc_Char)0x73,  /* [1566] */
    (xdc_Char)0x65,  /* [1567] */
    (xdc_Char)0x64,  /* [1568] */
    (xdc_Char)0x2e,  /* [1569] */
    (xdc_Char)0x0,  /* [1570] */
    (xdc_Char)0x41,  /* [1571] */
    (xdc_Char)0x5f,  /* [1572] */
    (xdc_Char)0x62,  /* [1573] */
    (xdc_Char)0x61,  /* [1574] */
    (xdc_Char)0x64,  /* [1575] */
    (xdc_Char)0x54,  /* [1576] */
    (xdc_Char)0x68,  /* [1577] */
    (xdc_Char)0x72,  /* [1578] */
    (xdc_Char)0x65,  /* [1579] */
    (xdc_Char)0x61,  /* [1580] */
    (xdc_Char)0x64,  /* [1581] */
    (xdc_Char)0x54,  /* [1582] */
    (xdc_Char)0x79,  /* [1583] */
    (xdc_Char)0x70,  /* [1584] */
    (xdc_Char)0x65,  /* [1585] */
    (xdc_Char)0x3a,  /* [1586] */
    (xdc_Char)0x20,  /* [1587] */
    (xdc_Char)0x43,  /* [1588] */
    (xdc_Char)0x61,  /* [1589] */
    (xdc_Char)0x6e,  /* [1590] */
    (xdc_Char)0x6e,  /* [1591] */
    (xdc_Char)0x6f,  /* [1592] */
    (xdc_Char)0x74,  /* [1593] */
    (xdc_Char)0x20,  /* [1594] */
    (xdc_Char)0x63,  /* [1595] */
    (xdc_Char)0x72,  /* [1596] */
    (xdc_Char)0x65,  /* [1597] */
    (xdc_Char)0x61,  /* [1598] */
    (xdc_Char)0x74,  /* [1599] */
    (xdc_Char)0x65,  /* [1600] */
    (xdc_Char)0x2f,  /* [1601] */
    (xdc_Char)0x64,  /* [1602] */
    (xdc_Char)0x65,  /* [1603] */
    (xdc_Char)0x6c,  /* [1604] */
    (xdc_Char)0x65,  /* [1605] */
    (xdc_Char)0x74,  /* [1606] */
    (xdc_Char)0x65,  /* [1607] */
    (xdc_Char)0x20,  /* [1608] */
    (xdc_Char)0x61,  /* [1609] */
    (xdc_Char)0x20,  /* [1610] */
    (xdc_Char)0x74,  /* [1611] */
    (xdc_Char)0x61,  /* [1612] */
    (xdc_Char)0x73,  /* [1613] */
    (xdc_Char)0x6b,  /* [1614] */
    (xdc_Char)0x20,  /* [1615] */
    (xdc_Char)0x66,  /* [1616] */
    (xdc_Char)0x72,  /* [1617] */
    (xdc_Char)0x6f,  /* [1618] */
    (xdc_Char)0x6d,  /* [1619] */
    (xdc_Char)0x20,  /* [1620] */
    (xdc_Char)0x48,  /* [1621] */
    (xdc_Char)0x77,  /* [1622] */
    (xdc_Char)0x69,  /* [1623] */
    (xdc_Char)0x20,  /* [1624] */
    (xdc_Char)0x6f,  /* [1625] */
    (xdc_Char)0x72,  /* [1626] */
    (xdc_Char)0x20,  /* [1627] */
    (xdc_Char)0x53,  /* [1628] */
    (xdc_Char)0x77,  /* [1629] */
    (xdc_Char)0x69,  /* [1630] */
    (xdc_Char)0x20,  /* [1631] */
    (xdc_Char)0x74,  /* [1632] */
    (xdc_Char)0x68,  /* [1633] */
    (xdc_Char)0x72,  /* [1634] */
    (xdc_Char)0x65,  /* [1635] */
    (xdc_Char)0x61,  /* [1636] */
    (xdc_Char)0x64,  /* [1637] */
    (xdc_Char)0x2e,  /* [1638] */
    (xdc_Char)0x0,  /* [1639] */
    (xdc_Char)0x41,  /* [1640] */
    (xdc_Char)0x5f,  /* [1641] */
    (xdc_Char)0x62,  /* [1642] */
    (xdc_Char)0x61,  /* [1643] */
    (xdc_Char)0x64,  /* [1644] */
    (xdc_Char)0x54,  /* [1645] */
    (xdc_Char)0x61,  /* [1646] */
    (xdc_Char)0x73,  /* [1647] */
    (xdc_Char)0x6b,  /* [1648] */
    (xdc_Char)0x53,  /* [1649] */
    (xdc_Char)0x74,  /* [1650] */
    (xdc_Char)0x61,  /* [1651] */
    (xdc_Char)0x74,  /* [1652] */
    (xdc_Char)0x65,  /* [1653] */
    (xdc_Char)0x3a,  /* [1654] */
    (xdc_Char)0x20,  /* [1655] */
    (xdc_Char)0x43,  /* [1656] */
    (xdc_Char)0x61,  /* [1657] */
    (xdc_Char)0x6e,  /* [1658] */
    (xdc_Char)0x27,  /* [1659] */
    (xdc_Char)0x74,  /* [1660] */
    (xdc_Char)0x20,  /* [1661] */
    (xdc_Char)0x64,  /* [1662] */
    (xdc_Char)0x65,  /* [1663] */
    (xdc_Char)0x6c,  /* [1664] */
    (xdc_Char)0x65,  /* [1665] */
    (xdc_Char)0x74,  /* [1666] */
    (xdc_Char)0x65,  /* [1667] */
    (xdc_Char)0x20,  /* [1668] */
    (xdc_Char)0x61,  /* [1669] */
    (xdc_Char)0x20,  /* [1670] */
    (xdc_Char)0x74,  /* [1671] */
    (xdc_Char)0x61,  /* [1672] */
    (xdc_Char)0x73,  /* [1673] */
    (xdc_Char)0x6b,  /* [1674] */
    (xdc_Char)0x20,  /* [1675] */
    (xdc_Char)0x69,  /* [1676] */
    (xdc_Char)0x6e,  /* [1677] */
    (xdc_Char)0x20,  /* [1678] */
    (xdc_Char)0x52,  /* [1679] */
    (xdc_Char)0x55,  /* [1680] */
    (xdc_Char)0x4e,  /* [1681] */
    (xdc_Char)0x4e,  /* [1682] */
    (xdc_Char)0x49,  /* [1683] */
    (xdc_Char)0x4e,  /* [1684] */
    (xdc_Char)0x47,  /* [1685] */
    (xdc_Char)0x20,  /* [1686] */
    (xdc_Char)0x73,  /* [1687] */
    (xdc_Char)0x74,  /* [1688] */
    (xdc_Char)0x61,  /* [1689] */
    (xdc_Char)0x74,  /* [1690] */
    (xdc_Char)0x65,  /* [1691] */
    (xdc_Char)0x2e,  /* [1692] */
    (xdc_Char)0x0,  /* [1693] */
    (xdc_Char)0x41,  /* [1694] */
    (xdc_Char)0x5f,  /* [1695] */
    (xdc_Char)0x6e,  /* [1696] */
    (xdc_Char)0x6f,  /* [1697] */
    (xdc_Char)0x50,  /* [1698] */
    (xdc_Char)0x65,  /* [1699] */
    (xdc_Char)0x6e,  /* [1700] */
    (xdc_Char)0x64,  /* [1701] */
    (xdc_Char)0x45,  /* [1702] */
    (xdc_Char)0x6c,  /* [1703] */
    (xdc_Char)0x65,  /* [1704] */
    (xdc_Char)0x6d,  /* [1705] */
    (xdc_Char)0x3a,  /* [1706] */
    (xdc_Char)0x20,  /* [1707] */
    (xdc_Char)0x4e,  /* [1708] */
    (xdc_Char)0x6f,  /* [1709] */
    (xdc_Char)0x74,  /* [1710] */
    (xdc_Char)0x20,  /* [1711] */
    (xdc_Char)0x65,  /* [1712] */
    (xdc_Char)0x6e,  /* [1713] */
    (xdc_Char)0x6f,  /* [1714] */
    (xdc_Char)0x75,  /* [1715] */
    (xdc_Char)0x67,  /* [1716] */
    (xdc_Char)0x68,  /* [1717] */
    (xdc_Char)0x20,  /* [1718] */
    (xdc_Char)0x69,  /* [1719] */
    (xdc_Char)0x6e,  /* [1720] */
    (xdc_Char)0x66,  /* [1721] */
    (xdc_Char)0x6f,  /* [1722] */
    (xdc_Char)0x20,  /* [1723] */
    (xdc_Char)0x74,  /* [1724] */
    (xdc_Char)0x6f,  /* [1725] */
    (xdc_Char)0x20,  /* [1726] */
    (xdc_Char)0x64,  /* [1727] */
    (xdc_Char)0x65,  /* [1728] */
    (xdc_Char)0x6c,  /* [1729] */
    (xdc_Char)0x65,  /* [1730] */
    (xdc_Char)0x74,  /* [1731] */
    (xdc_Char)0x65,  /* [1732] */
    (xdc_Char)0x20,  /* [1733] */
    (xdc_Char)0x42,  /* [1734] */
    (xdc_Char)0x4c,  /* [1735] */
    (xdc_Char)0x4f,  /* [1736] */
    (xdc_Char)0x43,  /* [1737] */
    (xdc_Char)0x4b,  /* [1738] */
    (xdc_Char)0x45,  /* [1739] */
    (xdc_Char)0x44,  /* [1740] */
    (xdc_Char)0x20,  /* [1741] */
    (xdc_Char)0x74,  /* [1742] */
    (xdc_Char)0x61,  /* [1743] */
    (xdc_Char)0x73,  /* [1744] */
    (xdc_Char)0x6b,  /* [1745] */
    (xdc_Char)0x2e,  /* [1746] */
    (xdc_Char)0x0,  /* [1747] */
    (xdc_Char)0x41,  /* [1748] */
    (xdc_Char)0x5f,  /* [1749] */
    (xdc_Char)0x74,  /* [1750] */
    (xdc_Char)0x61,  /* [1751] */
    (xdc_Char)0x73,  /* [1752] */
    (xdc_Char)0x6b,  /* [1753] */
    (xdc_Char)0x44,  /* [1754] */
    (xdc_Char)0x69,  /* [1755] */
    (xdc_Char)0x73,  /* [1756] */
    (xdc_Char)0x61,  /* [1757] */
    (xdc_Char)0x62,  /* [1758] */
    (xdc_Char)0x6c,  /* [1759] */
    (xdc_Char)0x65,  /* [1760] */
    (xdc_Char)0x64,  /* [1761] */
    (xdc_Char)0x3a,  /* [1762] */
    (xdc_Char)0x20,  /* [1763] */
    (xdc_Char)0x43,  /* [1764] */
    (xdc_Char)0x61,  /* [1765] */
    (xdc_Char)0x6e,  /* [1766] */
    (xdc_Char)0x6e,  /* [1767] */
    (xdc_Char)0x6f,  /* [1768] */
    (xdc_Char)0x74,  /* [1769] */
    (xdc_Char)0x20,  /* [1770] */
    (xdc_Char)0x63,  /* [1771] */
    (xdc_Char)0x72,  /* [1772] */
    (xdc_Char)0x65,  /* [1773] */
    (xdc_Char)0x61,  /* [1774] */
    (xdc_Char)0x74,  /* [1775] */
    (xdc_Char)0x65,  /* [1776] */
    (xdc_Char)0x20,  /* [1777] */
    (xdc_Char)0x61,  /* [1778] */
    (xdc_Char)0x20,  /* [1779] */
    (xdc_Char)0x74,  /* [1780] */
    (xdc_Char)0x61,  /* [1781] */
    (xdc_Char)0x73,  /* [1782] */
    (xdc_Char)0x6b,  /* [1783] */
    (xdc_Char)0x20,  /* [1784] */
    (xdc_Char)0x77,  /* [1785] */
    (xdc_Char)0x68,  /* [1786] */
    (xdc_Char)0x65,  /* [1787] */
    (xdc_Char)0x6e,  /* [1788] */
    (xdc_Char)0x20,  /* [1789] */
    (xdc_Char)0x74,  /* [1790] */
    (xdc_Char)0x61,  /* [1791] */
    (xdc_Char)0x73,  /* [1792] */
    (xdc_Char)0x6b,  /* [1793] */
    (xdc_Char)0x69,  /* [1794] */
    (xdc_Char)0x6e,  /* [1795] */
    (xdc_Char)0x67,  /* [1796] */
    (xdc_Char)0x20,  /* [1797] */
    (xdc_Char)0x69,  /* [1798] */
    (xdc_Char)0x73,  /* [1799] */
    (xdc_Char)0x20,  /* [1800] */
    (xdc_Char)0x64,  /* [1801] */
    (xdc_Char)0x69,  /* [1802] */
    (xdc_Char)0x73,  /* [1803] */
    (xdc_Char)0x61,  /* [1804] */
    (xdc_Char)0x62,  /* [1805] */
    (xdc_Char)0x6c,  /* [1806] */
    (xdc_Char)0x65,  /* [1807] */
    (xdc_Char)0x64,  /* [1808] */
    (xdc_Char)0x2e,  /* [1809] */
    (xdc_Char)0x0,  /* [1810] */
    (xdc_Char)0x41,  /* [1811] */
    (xdc_Char)0x5f,  /* [1812] */
    (xdc_Char)0x62,  /* [1813] */
    (xdc_Char)0x61,  /* [1814] */
    (xdc_Char)0x64,  /* [1815] */
    (xdc_Char)0x50,  /* [1816] */
    (xdc_Char)0x72,  /* [1817] */
    (xdc_Char)0x69,  /* [1818] */
    (xdc_Char)0x6f,  /* [1819] */
    (xdc_Char)0x72,  /* [1820] */
    (xdc_Char)0x69,  /* [1821] */
    (xdc_Char)0x74,  /* [1822] */
    (xdc_Char)0x79,  /* [1823] */
    (xdc_Char)0x3a,  /* [1824] */
    (xdc_Char)0x20,  /* [1825] */
    (xdc_Char)0x41,  /* [1826] */
    (xdc_Char)0x6e,  /* [1827] */
    (xdc_Char)0x20,  /* [1828] */
    (xdc_Char)0x69,  /* [1829] */
    (xdc_Char)0x6e,  /* [1830] */
    (xdc_Char)0x76,  /* [1831] */
    (xdc_Char)0x61,  /* [1832] */
    (xdc_Char)0x6c,  /* [1833] */
    (xdc_Char)0x69,  /* [1834] */
    (xdc_Char)0x64,  /* [1835] */
    (xdc_Char)0x20,  /* [1836] */
    (xdc_Char)0x74,  /* [1837] */
    (xdc_Char)0x61,  /* [1838] */
    (xdc_Char)0x73,  /* [1839] */
    (xdc_Char)0x6b,  /* [1840] */
    (xdc_Char)0x20,  /* [1841] */
    (xdc_Char)0x70,  /* [1842] */
    (xdc_Char)0x72,  /* [1843] */
    (xdc_Char)0x69,  /* [1844] */
    (xdc_Char)0x6f,  /* [1845] */
    (xdc_Char)0x72,  /* [1846] */
    (xdc_Char)0x69,  /* [1847] */
    (xdc_Char)0x74,  /* [1848] */
    (xdc_Char)0x79,  /* [1849] */
    (xdc_Char)0x20,  /* [1850] */
    (xdc_Char)0x77,  /* [1851] */
    (xdc_Char)0x61,  /* [1852] */
    (xdc_Char)0x73,  /* [1853] */
    (xdc_Char)0x20,  /* [1854] */
    (xdc_Char)0x75,  /* [1855] */
    (xdc_Char)0x73,  /* [1856] */
    (xdc_Char)0x65,  /* [1857] */
    (xdc_Char)0x64,  /* [1858] */
    (xdc_Char)0x2e,  /* [1859] */
    (xdc_Char)0x0,  /* [1860] */
    (xdc_Char)0x41,  /* [1861] */
    (xdc_Char)0x5f,  /* [1862] */
    (xdc_Char)0x62,  /* [1863] */
    (xdc_Char)0x61,  /* [1864] */
    (xdc_Char)0x64,  /* [1865] */
    (xdc_Char)0x54,  /* [1866] */
    (xdc_Char)0x69,  /* [1867] */
    (xdc_Char)0x6d,  /* [1868] */
    (xdc_Char)0x65,  /* [1869] */
    (xdc_Char)0x6f,  /* [1870] */
    (xdc_Char)0x75,  /* [1871] */
    (xdc_Char)0x74,  /* [1872] */
    (xdc_Char)0x3a,  /* [1873] */
    (xdc_Char)0x20,  /* [1874] */
    (xdc_Char)0x43,  /* [1875] */
    (xdc_Char)0x61,  /* [1876] */
    (xdc_Char)0x6e,  /* [1877] */
    (xdc_Char)0x27,  /* [1878] */
    (xdc_Char)0x74,  /* [1879] */
    (xdc_Char)0x20,  /* [1880] */
    (xdc_Char)0x73,  /* [1881] */
    (xdc_Char)0x6c,  /* [1882] */
    (xdc_Char)0x65,  /* [1883] */
    (xdc_Char)0x65,  /* [1884] */
    (xdc_Char)0x70,  /* [1885] */
    (xdc_Char)0x20,  /* [1886] */
    (xdc_Char)0x46,  /* [1887] */
    (xdc_Char)0x4f,  /* [1888] */
    (xdc_Char)0x52,  /* [1889] */
    (xdc_Char)0x45,  /* [1890] */
    (xdc_Char)0x56,  /* [1891] */
    (xdc_Char)0x45,  /* [1892] */
    (xdc_Char)0x52,  /* [1893] */
    (xdc_Char)0x2e,  /* [1894] */
    (xdc_Char)0x0,  /* [1895] */
    (xdc_Char)0x41,  /* [1896] */
    (xdc_Char)0x5f,  /* [1897] */
    (xdc_Char)0x62,  /* [1898] */
    (xdc_Char)0x61,  /* [1899] */
    (xdc_Char)0x64,  /* [1900] */
    (xdc_Char)0x41,  /* [1901] */
    (xdc_Char)0x66,  /* [1902] */
    (xdc_Char)0x66,  /* [1903] */
    (xdc_Char)0x69,  /* [1904] */
    (xdc_Char)0x6e,  /* [1905] */
    (xdc_Char)0x69,  /* [1906] */
    (xdc_Char)0x74,  /* [1907] */
    (xdc_Char)0x79,  /* [1908] */
    (xdc_Char)0x3a,  /* [1909] */
    (xdc_Char)0x20,  /* [1910] */
    (xdc_Char)0x49,  /* [1911] */
    (xdc_Char)0x6e,  /* [1912] */
    (xdc_Char)0x76,  /* [1913] */
    (xdc_Char)0x61,  /* [1914] */
    (xdc_Char)0x6c,  /* [1915] */
    (xdc_Char)0x69,  /* [1916] */
    (xdc_Char)0x64,  /* [1917] */
    (xdc_Char)0x20,  /* [1918] */
    (xdc_Char)0x61,  /* [1919] */
    (xdc_Char)0x66,  /* [1920] */
    (xdc_Char)0x66,  /* [1921] */
    (xdc_Char)0x69,  /* [1922] */
    (xdc_Char)0x6e,  /* [1923] */
    (xdc_Char)0x69,  /* [1924] */
    (xdc_Char)0x74,  /* [1925] */
    (xdc_Char)0x79,  /* [1926] */
    (xdc_Char)0x2e,  /* [1927] */
    (xdc_Char)0x0,  /* [1928] */
    (xdc_Char)0x41,  /* [1929] */
    (xdc_Char)0x5f,  /* [1930] */
    (xdc_Char)0x73,  /* [1931] */
    (xdc_Char)0x6c,  /* [1932] */
    (xdc_Char)0x65,  /* [1933] */
    (xdc_Char)0x65,  /* [1934] */
    (xdc_Char)0x70,  /* [1935] */
    (xdc_Char)0x54,  /* [1936] */
    (xdc_Char)0x61,  /* [1937] */
    (xdc_Char)0x73,  /* [1938] */
    (xdc_Char)0x6b,  /* [1939] */
    (xdc_Char)0x44,  /* [1940] */
    (xdc_Char)0x69,  /* [1941] */
    (xdc_Char)0x73,  /* [1942] */
    (xdc_Char)0x61,  /* [1943] */
    (xdc_Char)0x62,  /* [1944] */
    (xdc_Char)0x6c,  /* [1945] */
    (xdc_Char)0x65,  /* [1946] */
    (xdc_Char)0x64,  /* [1947] */
    (xdc_Char)0x3a,  /* [1948] */
    (xdc_Char)0x20,  /* [1949] */
    (xdc_Char)0x43,  /* [1950] */
    (xdc_Char)0x61,  /* [1951] */
    (xdc_Char)0x6e,  /* [1952] */
    (xdc_Char)0x6e,  /* [1953] */
    (xdc_Char)0x6f,  /* [1954] */
    (xdc_Char)0x74,  /* [1955] */
    (xdc_Char)0x20,  /* [1956] */
    (xdc_Char)0x63,  /* [1957] */
    (xdc_Char)0x61,  /* [1958] */
    (xdc_Char)0x6c,  /* [1959] */
    (xdc_Char)0x6c,  /* [1960] */
    (xdc_Char)0x20,  /* [1961] */
    (xdc_Char)0x54,  /* [1962] */
    (xdc_Char)0x61,  /* [1963] */
    (xdc_Char)0x73,  /* [1964] */
    (xdc_Char)0x6b,  /* [1965] */
    (xdc_Char)0x5f,  /* [1966] */
    (xdc_Char)0x73,  /* [1967] */
    (xdc_Char)0x6c,  /* [1968] */
    (xdc_Char)0x65,  /* [1969] */
    (xdc_Char)0x65,  /* [1970] */
    (xdc_Char)0x70,  /* [1971] */
    (xdc_Char)0x28,  /* [1972] */
    (xdc_Char)0x29,  /* [1973] */
    (xdc_Char)0x20,  /* [1974] */
    (xdc_Char)0x77,  /* [1975] */
    (xdc_Char)0x68,  /* [1976] */
    (xdc_Char)0x69,  /* [1977] */
    (xdc_Char)0x6c,  /* [1978] */
    (xdc_Char)0x65,  /* [1979] */
    (xdc_Char)0x20,  /* [1980] */
    (xdc_Char)0x74,  /* [1981] */
    (xdc_Char)0x68,  /* [1982] */
    (xdc_Char)0x65,  /* [1983] */
    (xdc_Char)0x20,  /* [1984] */
    (xdc_Char)0x54,  /* [1985] */
    (xdc_Char)0x61,  /* [1986] */
    (xdc_Char)0x73,  /* [1987] */
    (xdc_Char)0x6b,  /* [1988] */
    (xdc_Char)0x20,  /* [1989] */
    (xdc_Char)0x73,  /* [1990] */
    (xdc_Char)0x63,  /* [1991] */
    (xdc_Char)0x68,  /* [1992] */
    (xdc_Char)0x65,  /* [1993] */
    (xdc_Char)0x64,  /* [1994] */
    (xdc_Char)0x75,  /* [1995] */
    (xdc_Char)0x6c,  /* [1996] */
    (xdc_Char)0x65,  /* [1997] */
    (xdc_Char)0x72,  /* [1998] */
    (xdc_Char)0x20,  /* [1999] */
    (xdc_Char)0x69,  /* [2000] */
    (xdc_Char)0x73,  /* [2001] */
    (xdc_Char)0x20,  /* [2002] */
    (xdc_Char)0x64,  /* [2003] */
    (xdc_Char)0x69,  /* [2004] */
    (xdc_Char)0x73,  /* [2005] */
    (xdc_Char)0x61,  /* [2006] */
    (xdc_Char)0x62,  /* [2007] */
    (xdc_Char)0x6c,  /* [2008] */
    (xdc_Char)0x65,  /* [2009] */
    (xdc_Char)0x64,  /* [2010] */
    (xdc_Char)0x2e,  /* [2011] */
    (xdc_Char)0x0,  /* [2012] */
    (xdc_Char)0x41,  /* [2013] */
    (xdc_Char)0x5f,  /* [2014] */
    (xdc_Char)0x69,  /* [2015] */
    (xdc_Char)0x6e,  /* [2016] */
    (xdc_Char)0x76,  /* [2017] */
    (xdc_Char)0x61,  /* [2018] */
    (xdc_Char)0x6c,  /* [2019] */
    (xdc_Char)0x69,  /* [2020] */
    (xdc_Char)0x64,  /* [2021] */
    (xdc_Char)0x43,  /* [2022] */
    (xdc_Char)0x6f,  /* [2023] */
    (xdc_Char)0x72,  /* [2024] */
    (xdc_Char)0x65,  /* [2025] */
    (xdc_Char)0x49,  /* [2026] */
    (xdc_Char)0x64,  /* [2027] */
    (xdc_Char)0x3a,  /* [2028] */
    (xdc_Char)0x20,  /* [2029] */
    (xdc_Char)0x43,  /* [2030] */
    (xdc_Char)0x61,  /* [2031] */
    (xdc_Char)0x6e,  /* [2032] */
    (xdc_Char)0x6e,  /* [2033] */
    (xdc_Char)0x6f,  /* [2034] */
    (xdc_Char)0x74,  /* [2035] */
    (xdc_Char)0x20,  /* [2036] */
    (xdc_Char)0x70,  /* [2037] */
    (xdc_Char)0x61,  /* [2038] */
    (xdc_Char)0x73,  /* [2039] */
    (xdc_Char)0x73,  /* [2040] */
    (xdc_Char)0x20,  /* [2041] */
    (xdc_Char)0x61,  /* [2042] */
    (xdc_Char)0x20,  /* [2043] */
    (xdc_Char)0x6e,  /* [2044] */
    (xdc_Char)0x6f,  /* [2045] */
    (xdc_Char)0x6e,  /* [2046] */
    (xdc_Char)0x2d,  /* [2047] */
    (xdc_Char)0x7a,  /* [2048] */
    (xdc_Char)0x65,  /* [2049] */
    (xdc_Char)0x72,  /* [2050] */
    (xdc_Char)0x6f,  /* [2051] */
    (xdc_Char)0x20,  /* [2052] */
    (xdc_Char)0x43,  /* [2053] */
    (xdc_Char)0x6f,  /* [2054] */
    (xdc_Char)0x72,  /* [2055] */
    (xdc_Char)0x65,  /* [2056] */
    (xdc_Char)0x49,  /* [2057] */
    (xdc_Char)0x64,  /* [2058] */
    (xdc_Char)0x20,  /* [2059] */
    (xdc_Char)0x69,  /* [2060] */
    (xdc_Char)0x6e,  /* [2061] */
    (xdc_Char)0x20,  /* [2062] */
    (xdc_Char)0x61,  /* [2063] */
    (xdc_Char)0x20,  /* [2064] */
    (xdc_Char)0x6e,  /* [2065] */
    (xdc_Char)0x6f,  /* [2066] */
    (xdc_Char)0x6e,  /* [2067] */
    (xdc_Char)0x2d,  /* [2068] */
    (xdc_Char)0x53,  /* [2069] */
    (xdc_Char)0x4d,  /* [2070] */
    (xdc_Char)0x50,  /* [2071] */
    (xdc_Char)0x20,  /* [2072] */
    (xdc_Char)0x61,  /* [2073] */
    (xdc_Char)0x70,  /* [2074] */
    (xdc_Char)0x70,  /* [2075] */
    (xdc_Char)0x6c,  /* [2076] */
    (xdc_Char)0x69,  /* [2077] */
    (xdc_Char)0x63,  /* [2078] */
    (xdc_Char)0x61,  /* [2079] */
    (xdc_Char)0x74,  /* [2080] */
    (xdc_Char)0x69,  /* [2081] */
    (xdc_Char)0x6f,  /* [2082] */
    (xdc_Char)0x6e,  /* [2083] */
    (xdc_Char)0x2e,  /* [2084] */
    (xdc_Char)0x0,  /* [2085] */
    (xdc_Char)0x41,  /* [2086] */
    (xdc_Char)0x5f,  /* [2087] */
    (xdc_Char)0x7a,  /* [2088] */
    (xdc_Char)0x65,  /* [2089] */
    (xdc_Char)0x72,  /* [2090] */
    (xdc_Char)0x6f,  /* [2091] */
    (xdc_Char)0x54,  /* [2092] */
    (xdc_Char)0x69,  /* [2093] */
    (xdc_Char)0x6d,  /* [2094] */
    (xdc_Char)0x65,  /* [2095] */
    (xdc_Char)0x6f,  /* [2096] */
    (xdc_Char)0x75,  /* [2097] */
    (xdc_Char)0x74,  /* [2098] */
    (xdc_Char)0x3a,  /* [2099] */
    (xdc_Char)0x20,  /* [2100] */
    (xdc_Char)0x54,  /* [2101] */
    (xdc_Char)0x69,  /* [2102] */
    (xdc_Char)0x6d,  /* [2103] */
    (xdc_Char)0x65,  /* [2104] */
    (xdc_Char)0x6f,  /* [2105] */
    (xdc_Char)0x75,  /* [2106] */
    (xdc_Char)0x74,  /* [2107] */
    (xdc_Char)0x20,  /* [2108] */
    (xdc_Char)0x76,  /* [2109] */
    (xdc_Char)0x61,  /* [2110] */
    (xdc_Char)0x6c,  /* [2111] */
    (xdc_Char)0x75,  /* [2112] */
    (xdc_Char)0x65,  /* [2113] */
    (xdc_Char)0x20,  /* [2114] */
    (xdc_Char)0x61,  /* [2115] */
    (xdc_Char)0x6e,  /* [2116] */
    (xdc_Char)0x6e,  /* [2117] */
    (xdc_Char)0x6f,  /* [2118] */
    (xdc_Char)0x74,  /* [2119] */
    (xdc_Char)0x20,  /* [2120] */
    (xdc_Char)0x62,  /* [2121] */
    (xdc_Char)0x65,  /* [2122] */
    (xdc_Char)0x20,  /* [2123] */
    (xdc_Char)0x7a,  /* [2124] */
    (xdc_Char)0x65,  /* [2125] */
    (xdc_Char)0x72,  /* [2126] */
    (xdc_Char)0x6f,  /* [2127] */
    (xdc_Char)0x0,  /* [2128] */
    (xdc_Char)0x41,  /* [2129] */
    (xdc_Char)0x5f,  /* [2130] */
    (xdc_Char)0x69,  /* [2131] */
    (xdc_Char)0x6e,  /* [2132] */
    (xdc_Char)0x76,  /* [2133] */
    (xdc_Char)0x61,  /* [2134] */
    (xdc_Char)0x6c,  /* [2135] */
    (xdc_Char)0x69,  /* [2136] */
    (xdc_Char)0x64,  /* [2137] */
    (xdc_Char)0x4b,  /* [2138] */
    (xdc_Char)0x65,  /* [2139] */
    (xdc_Char)0x79,  /* [2140] */
    (xdc_Char)0x3a,  /* [2141] */
    (xdc_Char)0x20,  /* [2142] */
    (xdc_Char)0x74,  /* [2143] */
    (xdc_Char)0x68,  /* [2144] */
    (xdc_Char)0x65,  /* [2145] */
    (xdc_Char)0x20,  /* [2146] */
    (xdc_Char)0x6b,  /* [2147] */
    (xdc_Char)0x65,  /* [2148] */
    (xdc_Char)0x79,  /* [2149] */
    (xdc_Char)0x20,  /* [2150] */
    (xdc_Char)0x6d,  /* [2151] */
    (xdc_Char)0x75,  /* [2152] */
    (xdc_Char)0x73,  /* [2153] */
    (xdc_Char)0x74,  /* [2154] */
    (xdc_Char)0x20,  /* [2155] */
    (xdc_Char)0x62,  /* [2156] */
    (xdc_Char)0x65,  /* [2157] */
    (xdc_Char)0x20,  /* [2158] */
    (xdc_Char)0x73,  /* [2159] */
    (xdc_Char)0x65,  /* [2160] */
    (xdc_Char)0x74,  /* [2161] */
    (xdc_Char)0x20,  /* [2162] */
    (xdc_Char)0x74,  /* [2163] */
    (xdc_Char)0x6f,  /* [2164] */
    (xdc_Char)0x20,  /* [2165] */
    (xdc_Char)0x61,  /* [2166] */
    (xdc_Char)0x20,  /* [2167] */
    (xdc_Char)0x6e,  /* [2168] */
    (xdc_Char)0x6f,  /* [2169] */
    (xdc_Char)0x6e,  /* [2170] */
    (xdc_Char)0x2d,  /* [2171] */
    (xdc_Char)0x64,  /* [2172] */
    (xdc_Char)0x65,  /* [2173] */
    (xdc_Char)0x66,  /* [2174] */
    (xdc_Char)0x61,  /* [2175] */
    (xdc_Char)0x75,  /* [2176] */
    (xdc_Char)0x6c,  /* [2177] */
    (xdc_Char)0x74,  /* [2178] */
    (xdc_Char)0x20,  /* [2179] */
    (xdc_Char)0x76,  /* [2180] */
    (xdc_Char)0x61,  /* [2181] */
    (xdc_Char)0x6c,  /* [2182] */
    (xdc_Char)0x75,  /* [2183] */
    (xdc_Char)0x65,  /* [2184] */
    (xdc_Char)0x0,  /* [2185] */
    (xdc_Char)0x41,  /* [2186] */
    (xdc_Char)0x5f,  /* [2187] */
    (xdc_Char)0x62,  /* [2188] */
    (xdc_Char)0x61,  /* [2189] */
    (xdc_Char)0x64,  /* [2190] */
    (xdc_Char)0x43,  /* [2191] */
    (xdc_Char)0x6f,  /* [2192] */
    (xdc_Char)0x6e,  /* [2193] */
    (xdc_Char)0x74,  /* [2194] */
    (xdc_Char)0x65,  /* [2195] */
    (xdc_Char)0x78,  /* [2196] */
    (xdc_Char)0x74,  /* [2197] */
    (xdc_Char)0x3a,  /* [2198] */
    (xdc_Char)0x20,  /* [2199] */
    (xdc_Char)0x62,  /* [2200] */
    (xdc_Char)0x61,  /* [2201] */
    (xdc_Char)0x64,  /* [2202] */
    (xdc_Char)0x20,  /* [2203] */
    (xdc_Char)0x63,  /* [2204] */
    (xdc_Char)0x61,  /* [2205] */
    (xdc_Char)0x6c,  /* [2206] */
    (xdc_Char)0x6c,  /* [2207] */
    (xdc_Char)0x69,  /* [2208] */
    (xdc_Char)0x6e,  /* [2209] */
    (xdc_Char)0x67,  /* [2210] */
    (xdc_Char)0x20,  /* [2211] */
    (xdc_Char)0x63,  /* [2212] */
    (xdc_Char)0x6f,  /* [2213] */
    (xdc_Char)0x6e,  /* [2214] */
    (xdc_Char)0x74,  /* [2215] */
    (xdc_Char)0x65,  /* [2216] */
    (xdc_Char)0x78,  /* [2217] */
    (xdc_Char)0x74,  /* [2218] */
    (xdc_Char)0x2e,  /* [2219] */
    (xdc_Char)0x20,  /* [2220] */
    (xdc_Char)0x4d,  /* [2221] */
    (xdc_Char)0x61,  /* [2222] */
    (xdc_Char)0x79,  /* [2223] */
    (xdc_Char)0x20,  /* [2224] */
    (xdc_Char)0x6e,  /* [2225] */
    (xdc_Char)0x6f,  /* [2226] */
    (xdc_Char)0x74,  /* [2227] */
    (xdc_Char)0x20,  /* [2228] */
    (xdc_Char)0x62,  /* [2229] */
    (xdc_Char)0x65,  /* [2230] */
    (xdc_Char)0x20,  /* [2231] */
    (xdc_Char)0x65,  /* [2232] */
    (xdc_Char)0x6e,  /* [2233] */
    (xdc_Char)0x74,  /* [2234] */
    (xdc_Char)0x65,  /* [2235] */
    (xdc_Char)0x72,  /* [2236] */
    (xdc_Char)0x65,  /* [2237] */
    (xdc_Char)0x64,  /* [2238] */
    (xdc_Char)0x20,  /* [2239] */
    (xdc_Char)0x66,  /* [2240] */
    (xdc_Char)0x72,  /* [2241] */
    (xdc_Char)0x6f,  /* [2242] */
    (xdc_Char)0x6d,  /* [2243] */
    (xdc_Char)0x20,  /* [2244] */
    (xdc_Char)0x61,  /* [2245] */
    (xdc_Char)0x20,  /* [2246] */
    (xdc_Char)0x68,  /* [2247] */
    (xdc_Char)0x61,  /* [2248] */
    (xdc_Char)0x72,  /* [2249] */
    (xdc_Char)0x64,  /* [2250] */
    (xdc_Char)0x77,  /* [2251] */
    (xdc_Char)0x61,  /* [2252] */
    (xdc_Char)0x72,  /* [2253] */
    (xdc_Char)0x65,  /* [2254] */
    (xdc_Char)0x20,  /* [2255] */
    (xdc_Char)0x69,  /* [2256] */
    (xdc_Char)0x6e,  /* [2257] */
    (xdc_Char)0x74,  /* [2258] */
    (xdc_Char)0x65,  /* [2259] */
    (xdc_Char)0x72,  /* [2260] */
    (xdc_Char)0x72,  /* [2261] */
    (xdc_Char)0x75,  /* [2262] */
    (xdc_Char)0x70,  /* [2263] */
    (xdc_Char)0x74,  /* [2264] */
    (xdc_Char)0x20,  /* [2265] */
    (xdc_Char)0x74,  /* [2266] */
    (xdc_Char)0x68,  /* [2267] */
    (xdc_Char)0x72,  /* [2268] */
    (xdc_Char)0x65,  /* [2269] */
    (xdc_Char)0x61,  /* [2270] */
    (xdc_Char)0x64,  /* [2271] */
    (xdc_Char)0x2e,  /* [2272] */
    (xdc_Char)0x0,  /* [2273] */
    (xdc_Char)0x41,  /* [2274] */
    (xdc_Char)0x5f,  /* [2275] */
    (xdc_Char)0x62,  /* [2276] */
    (xdc_Char)0x61,  /* [2277] */
    (xdc_Char)0x64,  /* [2278] */
    (xdc_Char)0x43,  /* [2279] */
    (xdc_Char)0x6f,  /* [2280] */
    (xdc_Char)0x6e,  /* [2281] */
    (xdc_Char)0x74,  /* [2282] */
    (xdc_Char)0x65,  /* [2283] */
    (xdc_Char)0x78,  /* [2284] */
    (xdc_Char)0x74,  /* [2285] */
    (xdc_Char)0x3a,  /* [2286] */
    (xdc_Char)0x20,  /* [2287] */
    (xdc_Char)0x62,  /* [2288] */
    (xdc_Char)0x61,  /* [2289] */
    (xdc_Char)0x64,  /* [2290] */
    (xdc_Char)0x20,  /* [2291] */
    (xdc_Char)0x63,  /* [2292] */
    (xdc_Char)0x61,  /* [2293] */
    (xdc_Char)0x6c,  /* [2294] */
    (xdc_Char)0x6c,  /* [2295] */
    (xdc_Char)0x69,  /* [2296] */
    (xdc_Char)0x6e,  /* [2297] */
    (xdc_Char)0x67,  /* [2298] */
    (xdc_Char)0x20,  /* [2299] */
    (xdc_Char)0x63,  /* [2300] */
    (xdc_Char)0x6f,  /* [2301] */
    (xdc_Char)0x6e,  /* [2302] */
    (xdc_Char)0x74,  /* [2303] */
    (xdc_Char)0x65,  /* [2304] */
    (xdc_Char)0x78,  /* [2305] */
    (xdc_Char)0x74,  /* [2306] */
    (xdc_Char)0x2e,  /* [2307] */
    (xdc_Char)0x20,  /* [2308] */
    (xdc_Char)0x4d,  /* [2309] */
    (xdc_Char)0x61,  /* [2310] */
    (xdc_Char)0x79,  /* [2311] */
    (xdc_Char)0x20,  /* [2312] */
    (xdc_Char)0x6e,  /* [2313] */
    (xdc_Char)0x6f,  /* [2314] */
    (xdc_Char)0x74,  /* [2315] */
    (xdc_Char)0x20,  /* [2316] */
    (xdc_Char)0x62,  /* [2317] */
    (xdc_Char)0x65,  /* [2318] */
    (xdc_Char)0x20,  /* [2319] */
    (xdc_Char)0x65,  /* [2320] */
    (xdc_Char)0x6e,  /* [2321] */
    (xdc_Char)0x74,  /* [2322] */
    (xdc_Char)0x65,  /* [2323] */
    (xdc_Char)0x72,  /* [2324] */
    (xdc_Char)0x65,  /* [2325] */
    (xdc_Char)0x64,  /* [2326] */
    (xdc_Char)0x20,  /* [2327] */
    (xdc_Char)0x66,  /* [2328] */
    (xdc_Char)0x72,  /* [2329] */
    (xdc_Char)0x6f,  /* [2330] */
    (xdc_Char)0x6d,  /* [2331] */
    (xdc_Char)0x20,  /* [2332] */
    (xdc_Char)0x61,  /* [2333] */
    (xdc_Char)0x20,  /* [2334] */
    (xdc_Char)0x73,  /* [2335] */
    (xdc_Char)0x6f,  /* [2336] */
    (xdc_Char)0x66,  /* [2337] */
    (xdc_Char)0x74,  /* [2338] */
    (xdc_Char)0x77,  /* [2339] */
    (xdc_Char)0x61,  /* [2340] */
    (xdc_Char)0x72,  /* [2341] */
    (xdc_Char)0x65,  /* [2342] */
    (xdc_Char)0x20,  /* [2343] */
    (xdc_Char)0x6f,  /* [2344] */
    (xdc_Char)0x72,  /* [2345] */
    (xdc_Char)0x20,  /* [2346] */
    (xdc_Char)0x68,  /* [2347] */
    (xdc_Char)0x61,  /* [2348] */
    (xdc_Char)0x72,  /* [2349] */
    (xdc_Char)0x64,  /* [2350] */
    (xdc_Char)0x77,  /* [2351] */
    (xdc_Char)0x61,  /* [2352] */
    (xdc_Char)0x72,  /* [2353] */
    (xdc_Char)0x65,  /* [2354] */
    (xdc_Char)0x20,  /* [2355] */
    (xdc_Char)0x69,  /* [2356] */
    (xdc_Char)0x6e,  /* [2357] */
    (xdc_Char)0x74,  /* [2358] */
    (xdc_Char)0x65,  /* [2359] */
    (xdc_Char)0x72,  /* [2360] */
    (xdc_Char)0x72,  /* [2361] */
    (xdc_Char)0x75,  /* [2362] */
    (xdc_Char)0x70,  /* [2363] */
    (xdc_Char)0x74,  /* [2364] */
    (xdc_Char)0x20,  /* [2365] */
    (xdc_Char)0x74,  /* [2366] */
    (xdc_Char)0x68,  /* [2367] */
    (xdc_Char)0x72,  /* [2368] */
    (xdc_Char)0x65,  /* [2369] */
    (xdc_Char)0x61,  /* [2370] */
    (xdc_Char)0x64,  /* [2371] */
    (xdc_Char)0x2e,  /* [2372] */
    (xdc_Char)0x0,  /* [2373] */
    (xdc_Char)0x41,  /* [2374] */
    (xdc_Char)0x5f,  /* [2375] */
    (xdc_Char)0x62,  /* [2376] */
    (xdc_Char)0x61,  /* [2377] */
    (xdc_Char)0x64,  /* [2378] */
    (xdc_Char)0x43,  /* [2379] */
    (xdc_Char)0x6f,  /* [2380] */
    (xdc_Char)0x6e,  /* [2381] */
    (xdc_Char)0x74,  /* [2382] */
    (xdc_Char)0x65,  /* [2383] */
    (xdc_Char)0x78,  /* [2384] */
    (xdc_Char)0x74,  /* [2385] */
    (xdc_Char)0x3a,  /* [2386] */
    (xdc_Char)0x20,  /* [2387] */
    (xdc_Char)0x62,  /* [2388] */
    (xdc_Char)0x61,  /* [2389] */
    (xdc_Char)0x64,  /* [2390] */
    (xdc_Char)0x20,  /* [2391] */
    (xdc_Char)0x63,  /* [2392] */
    (xdc_Char)0x61,  /* [2393] */
    (xdc_Char)0x6c,  /* [2394] */
    (xdc_Char)0x6c,  /* [2395] */
    (xdc_Char)0x69,  /* [2396] */
    (xdc_Char)0x6e,  /* [2397] */
    (xdc_Char)0x67,  /* [2398] */
    (xdc_Char)0x20,  /* [2399] */
    (xdc_Char)0x63,  /* [2400] */
    (xdc_Char)0x6f,  /* [2401] */
    (xdc_Char)0x6e,  /* [2402] */
    (xdc_Char)0x74,  /* [2403] */
    (xdc_Char)0x65,  /* [2404] */
    (xdc_Char)0x78,  /* [2405] */
    (xdc_Char)0x74,  /* [2406] */
    (xdc_Char)0x2e,  /* [2407] */
    (xdc_Char)0x20,  /* [2408] */
    (xdc_Char)0x53,  /* [2409] */
    (xdc_Char)0x65,  /* [2410] */
    (xdc_Char)0x65,  /* [2411] */
    (xdc_Char)0x20,  /* [2412] */
    (xdc_Char)0x47,  /* [2413] */
    (xdc_Char)0x61,  /* [2414] */
    (xdc_Char)0x74,  /* [2415] */
    (xdc_Char)0x65,  /* [2416] */
    (xdc_Char)0x4d,  /* [2417] */
    (xdc_Char)0x75,  /* [2418] */
    (xdc_Char)0x74,  /* [2419] */
    (xdc_Char)0x65,  /* [2420] */
    (xdc_Char)0x78,  /* [2421] */
    (xdc_Char)0x50,  /* [2422] */
    (xdc_Char)0x72,  /* [2423] */
    (xdc_Char)0x69,  /* [2424] */
    (xdc_Char)0x20,  /* [2425] */
    (xdc_Char)0x41,  /* [2426] */
    (xdc_Char)0x50,  /* [2427] */
    (xdc_Char)0x49,  /* [2428] */
    (xdc_Char)0x20,  /* [2429] */
    (xdc_Char)0x64,  /* [2430] */
    (xdc_Char)0x6f,  /* [2431] */
    (xdc_Char)0x63,  /* [2432] */
    (xdc_Char)0x20,  /* [2433] */
    (xdc_Char)0x66,  /* [2434] */
    (xdc_Char)0x6f,  /* [2435] */
    (xdc_Char)0x72,  /* [2436] */
    (xdc_Char)0x20,  /* [2437] */
    (xdc_Char)0x64,  /* [2438] */
    (xdc_Char)0x65,  /* [2439] */
    (xdc_Char)0x74,  /* [2440] */
    (xdc_Char)0x61,  /* [2441] */
    (xdc_Char)0x69,  /* [2442] */
    (xdc_Char)0x6c,  /* [2443] */
    (xdc_Char)0x73,  /* [2444] */
    (xdc_Char)0x2e,  /* [2445] */
    (xdc_Char)0x0,  /* [2446] */
    (xdc_Char)0x41,  /* [2447] */
    (xdc_Char)0x5f,  /* [2448] */
    (xdc_Char)0x65,  /* [2449] */
    (xdc_Char)0x6e,  /* [2450] */
    (xdc_Char)0x74,  /* [2451] */
    (xdc_Char)0x65,  /* [2452] */
    (xdc_Char)0x72,  /* [2453] */
    (xdc_Char)0x54,  /* [2454] */
    (xdc_Char)0x61,  /* [2455] */
    (xdc_Char)0x73,  /* [2456] */
    (xdc_Char)0x6b,  /* [2457] */
    (xdc_Char)0x44,  /* [2458] */
    (xdc_Char)0x69,  /* [2459] */
    (xdc_Char)0x73,  /* [2460] */
    (xdc_Char)0x61,  /* [2461] */
    (xdc_Char)0x62,  /* [2462] */
    (xdc_Char)0x6c,  /* [2463] */
    (xdc_Char)0x65,  /* [2464] */
    (xdc_Char)0x64,  /* [2465] */
    (xdc_Char)0x3a,  /* [2466] */
    (xdc_Char)0x20,  /* [2467] */
    (xdc_Char)0x43,  /* [2468] */
    (xdc_Char)0x61,  /* [2469] */
    (xdc_Char)0x6e,  /* [2470] */
    (xdc_Char)0x6e,  /* [2471] */
    (xdc_Char)0x6f,  /* [2472] */
    (xdc_Char)0x74,  /* [2473] */
    (xdc_Char)0x20,  /* [2474] */
    (xdc_Char)0x63,  /* [2475] */
    (xdc_Char)0x61,  /* [2476] */
    (xdc_Char)0x6c,  /* [2477] */
    (xdc_Char)0x6c,  /* [2478] */
    (xdc_Char)0x20,  /* [2479] */
    (xdc_Char)0x47,  /* [2480] */
    (xdc_Char)0x61,  /* [2481] */
    (xdc_Char)0x74,  /* [2482] */
    (xdc_Char)0x65,  /* [2483] */
    (xdc_Char)0x4d,  /* [2484] */
    (xdc_Char)0x75,  /* [2485] */
    (xdc_Char)0x74,  /* [2486] */
    (xdc_Char)0x65,  /* [2487] */
    (xdc_Char)0x78,  /* [2488] */
    (xdc_Char)0x50,  /* [2489] */
    (xdc_Char)0x72,  /* [2490] */
    (xdc_Char)0x69,  /* [2491] */
    (xdc_Char)0x5f,  /* [2492] */
    (xdc_Char)0x65,  /* [2493] */
    (xdc_Char)0x6e,  /* [2494] */
    (xdc_Char)0x74,  /* [2495] */
    (xdc_Char)0x65,  /* [2496] */
    (xdc_Char)0x72,  /* [2497] */
    (xdc_Char)0x28,  /* [2498] */
    (xdc_Char)0x29,  /* [2499] */
    (xdc_Char)0x20,  /* [2500] */
    (xdc_Char)0x77,  /* [2501] */
    (xdc_Char)0x68,  /* [2502] */
    (xdc_Char)0x69,  /* [2503] */
    (xdc_Char)0x6c,  /* [2504] */
    (xdc_Char)0x65,  /* [2505] */
    (xdc_Char)0x20,  /* [2506] */
    (xdc_Char)0x74,  /* [2507] */
    (xdc_Char)0x68,  /* [2508] */
    (xdc_Char)0x65,  /* [2509] */
    (xdc_Char)0x20,  /* [2510] */
    (xdc_Char)0x54,  /* [2511] */
    (xdc_Char)0x61,  /* [2512] */
    (xdc_Char)0x73,  /* [2513] */
    (xdc_Char)0x6b,  /* [2514] */
    (xdc_Char)0x20,  /* [2515] */
    (xdc_Char)0x6f,  /* [2516] */
    (xdc_Char)0x72,  /* [2517] */
    (xdc_Char)0x20,  /* [2518] */
    (xdc_Char)0x53,  /* [2519] */
    (xdc_Char)0x77,  /* [2520] */
    (xdc_Char)0x69,  /* [2521] */
    (xdc_Char)0x20,  /* [2522] */
    (xdc_Char)0x73,  /* [2523] */
    (xdc_Char)0x63,  /* [2524] */
    (xdc_Char)0x68,  /* [2525] */
    (xdc_Char)0x65,  /* [2526] */
    (xdc_Char)0x64,  /* [2527] */
    (xdc_Char)0x75,  /* [2528] */
    (xdc_Char)0x6c,  /* [2529] */
    (xdc_Char)0x65,  /* [2530] */
    (xdc_Char)0x72,  /* [2531] */
    (xdc_Char)0x20,  /* [2532] */
    (xdc_Char)0x69,  /* [2533] */
    (xdc_Char)0x73,  /* [2534] */
    (xdc_Char)0x20,  /* [2535] */
    (xdc_Char)0x64,  /* [2536] */
    (xdc_Char)0x69,  /* [2537] */
    (xdc_Char)0x73,  /* [2538] */
    (xdc_Char)0x61,  /* [2539] */
    (xdc_Char)0x62,  /* [2540] */
    (xdc_Char)0x6c,  /* [2541] */
    (xdc_Char)0x65,  /* [2542] */
    (xdc_Char)0x64,  /* [2543] */
    (xdc_Char)0x2e,  /* [2544] */
    (xdc_Char)0x0,  /* [2545] */
    (xdc_Char)0x41,  /* [2546] */
    (xdc_Char)0x5f,  /* [2547] */
    (xdc_Char)0x62,  /* [2548] */
    (xdc_Char)0x61,  /* [2549] */
    (xdc_Char)0x64,  /* [2550] */
    (xdc_Char)0x43,  /* [2551] */
    (xdc_Char)0x6f,  /* [2552] */
    (xdc_Char)0x6e,  /* [2553] */
    (xdc_Char)0x74,  /* [2554] */
    (xdc_Char)0x65,  /* [2555] */
    (xdc_Char)0x78,  /* [2556] */
    (xdc_Char)0x74,  /* [2557] */
    (xdc_Char)0x3a,  /* [2558] */
    (xdc_Char)0x20,  /* [2559] */
    (xdc_Char)0x62,  /* [2560] */
    (xdc_Char)0x61,  /* [2561] */
    (xdc_Char)0x64,  /* [2562] */
    (xdc_Char)0x20,  /* [2563] */
    (xdc_Char)0x63,  /* [2564] */
    (xdc_Char)0x61,  /* [2565] */
    (xdc_Char)0x6c,  /* [2566] */
    (xdc_Char)0x6c,  /* [2567] */
    (xdc_Char)0x69,  /* [2568] */
    (xdc_Char)0x6e,  /* [2569] */
    (xdc_Char)0x67,  /* [2570] */
    (xdc_Char)0x20,  /* [2571] */
    (xdc_Char)0x63,  /* [2572] */
    (xdc_Char)0x6f,  /* [2573] */
    (xdc_Char)0x6e,  /* [2574] */
    (xdc_Char)0x74,  /* [2575] */
    (xdc_Char)0x65,  /* [2576] */
    (xdc_Char)0x78,  /* [2577] */
    (xdc_Char)0x74,  /* [2578] */
    (xdc_Char)0x2e,  /* [2579] */
    (xdc_Char)0x20,  /* [2580] */
    (xdc_Char)0x53,  /* [2581] */
    (xdc_Char)0x65,  /* [2582] */
    (xdc_Char)0x65,  /* [2583] */
    (xdc_Char)0x20,  /* [2584] */
    (xdc_Char)0x47,  /* [2585] */
    (xdc_Char)0x61,  /* [2586] */
    (xdc_Char)0x74,  /* [2587] */
    (xdc_Char)0x65,  /* [2588] */
    (xdc_Char)0x4d,  /* [2589] */
    (xdc_Char)0x75,  /* [2590] */
    (xdc_Char)0x74,  /* [2591] */
    (xdc_Char)0x65,  /* [2592] */
    (xdc_Char)0x78,  /* [2593] */
    (xdc_Char)0x20,  /* [2594] */
    (xdc_Char)0x41,  /* [2595] */
    (xdc_Char)0x50,  /* [2596] */
    (xdc_Char)0x49,  /* [2597] */
    (xdc_Char)0x20,  /* [2598] */
    (xdc_Char)0x64,  /* [2599] */
    (xdc_Char)0x6f,  /* [2600] */
    (xdc_Char)0x63,  /* [2601] */
    (xdc_Char)0x20,  /* [2602] */
    (xdc_Char)0x66,  /* [2603] */
    (xdc_Char)0x6f,  /* [2604] */
    (xdc_Char)0x72,  /* [2605] */
    (xdc_Char)0x20,  /* [2606] */
    (xdc_Char)0x64,  /* [2607] */
    (xdc_Char)0x65,  /* [2608] */
    (xdc_Char)0x74,  /* [2609] */
    (xdc_Char)0x61,  /* [2610] */
    (xdc_Char)0x69,  /* [2611] */
    (xdc_Char)0x6c,  /* [2612] */
    (xdc_Char)0x73,  /* [2613] */
    (xdc_Char)0x2e,  /* [2614] */
    (xdc_Char)0x0,  /* [2615] */
    (xdc_Char)0x41,  /* [2616] */
    (xdc_Char)0x5f,  /* [2617] */
    (xdc_Char)0x62,  /* [2618] */
    (xdc_Char)0x61,  /* [2619] */
    (xdc_Char)0x64,  /* [2620] */
    (xdc_Char)0x43,  /* [2621] */
    (xdc_Char)0x6f,  /* [2622] */
    (xdc_Char)0x6e,  /* [2623] */
    (xdc_Char)0x74,  /* [2624] */
    (xdc_Char)0x65,  /* [2625] */
    (xdc_Char)0x78,  /* [2626] */
    (xdc_Char)0x74,  /* [2627] */
    (xdc_Char)0x3a,  /* [2628] */
    (xdc_Char)0x20,  /* [2629] */
    (xdc_Char)0x62,  /* [2630] */
    (xdc_Char)0x61,  /* [2631] */
    (xdc_Char)0x64,  /* [2632] */
    (xdc_Char)0x20,  /* [2633] */
    (xdc_Char)0x63,  /* [2634] */
    (xdc_Char)0x61,  /* [2635] */
    (xdc_Char)0x6c,  /* [2636] */
    (xdc_Char)0x6c,  /* [2637] */
    (xdc_Char)0x69,  /* [2638] */
    (xdc_Char)0x6e,  /* [2639] */
    (xdc_Char)0x67,  /* [2640] */
    (xdc_Char)0x20,  /* [2641] */
    (xdc_Char)0x63,  /* [2642] */
    (xdc_Char)0x6f,  /* [2643] */
    (xdc_Char)0x6e,  /* [2644] */
    (xdc_Char)0x74,  /* [2645] */
    (xdc_Char)0x65,  /* [2646] */
    (xdc_Char)0x78,  /* [2647] */
    (xdc_Char)0x74,  /* [2648] */
    (xdc_Char)0x2e,  /* [2649] */
    (xdc_Char)0x20,  /* [2650] */
    (xdc_Char)0x53,  /* [2651] */
    (xdc_Char)0x65,  /* [2652] */
    (xdc_Char)0x65,  /* [2653] */
    (xdc_Char)0x20,  /* [2654] */
    (xdc_Char)0x47,  /* [2655] */
    (xdc_Char)0x61,  /* [2656] */
    (xdc_Char)0x74,  /* [2657] */
    (xdc_Char)0x65,  /* [2658] */
    (xdc_Char)0x53,  /* [2659] */
    (xdc_Char)0x70,  /* [2660] */
    (xdc_Char)0x69,  /* [2661] */
    (xdc_Char)0x6e,  /* [2662] */
    (xdc_Char)0x6c,  /* [2663] */
    (xdc_Char)0x6f,  /* [2664] */
    (xdc_Char)0x63,  /* [2665] */
    (xdc_Char)0x6b,  /* [2666] */
    (xdc_Char)0x20,  /* [2667] */
    (xdc_Char)0x41,  /* [2668] */
    (xdc_Char)0x50,  /* [2669] */
    (xdc_Char)0x49,  /* [2670] */
    (xdc_Char)0x20,  /* [2671] */
    (xdc_Char)0x64,  /* [2672] */
    (xdc_Char)0x6f,  /* [2673] */
    (xdc_Char)0x63,  /* [2674] */
    (xdc_Char)0x20,  /* [2675] */
    (xdc_Char)0x66,  /* [2676] */
    (xdc_Char)0x6f,  /* [2677] */
    (xdc_Char)0x72,  /* [2678] */
    (xdc_Char)0x20,  /* [2679] */
    (xdc_Char)0x64,  /* [2680] */
    (xdc_Char)0x65,  /* [2681] */
    (xdc_Char)0x74,  /* [2682] */
    (xdc_Char)0x61,  /* [2683] */
    (xdc_Char)0x69,  /* [2684] */
    (xdc_Char)0x6c,  /* [2685] */
    (xdc_Char)0x73,  /* [2686] */
    (xdc_Char)0x2e,  /* [2687] */
    (xdc_Char)0x0,  /* [2688] */
    (xdc_Char)0x41,  /* [2689] */
    (xdc_Char)0x5f,  /* [2690] */
    (xdc_Char)0x69,  /* [2691] */
    (xdc_Char)0x6e,  /* [2692] */
    (xdc_Char)0x76,  /* [2693] */
    (xdc_Char)0x61,  /* [2694] */
    (xdc_Char)0x6c,  /* [2695] */
    (xdc_Char)0x69,  /* [2696] */
    (xdc_Char)0x64,  /* [2697] */
    (xdc_Char)0x51,  /* [2698] */
    (xdc_Char)0x75,  /* [2699] */
    (xdc_Char)0x61,  /* [2700] */
    (xdc_Char)0x6c,  /* [2701] */
    (xdc_Char)0x69,  /* [2702] */
    (xdc_Char)0x74,  /* [2703] */
    (xdc_Char)0x79,  /* [2704] */
    (xdc_Char)0x3a,  /* [2705] */
    (xdc_Char)0x20,  /* [2706] */
    (xdc_Char)0x53,  /* [2707] */
    (xdc_Char)0x65,  /* [2708] */
    (xdc_Char)0x65,  /* [2709] */
    (xdc_Char)0x20,  /* [2710] */
    (xdc_Char)0x47,  /* [2711] */
    (xdc_Char)0x61,  /* [2712] */
    (xdc_Char)0x74,  /* [2713] */
    (xdc_Char)0x65,  /* [2714] */
    (xdc_Char)0x53,  /* [2715] */
    (xdc_Char)0x70,  /* [2716] */
    (xdc_Char)0x69,  /* [2717] */
    (xdc_Char)0x6e,  /* [2718] */
    (xdc_Char)0x6c,  /* [2719] */
    (xdc_Char)0x6f,  /* [2720] */
    (xdc_Char)0x63,  /* [2721] */
    (xdc_Char)0x6b,  /* [2722] */
    (xdc_Char)0x20,  /* [2723] */
    (xdc_Char)0x41,  /* [2724] */
    (xdc_Char)0x50,  /* [2725] */
    (xdc_Char)0x49,  /* [2726] */
    (xdc_Char)0x20,  /* [2727] */
    (xdc_Char)0x64,  /* [2728] */
    (xdc_Char)0x6f,  /* [2729] */
    (xdc_Char)0x63,  /* [2730] */
    (xdc_Char)0x20,  /* [2731] */
    (xdc_Char)0x66,  /* [2732] */
    (xdc_Char)0x6f,  /* [2733] */
    (xdc_Char)0x72,  /* [2734] */
    (xdc_Char)0x20,  /* [2735] */
    (xdc_Char)0x64,  /* [2736] */
    (xdc_Char)0x65,  /* [2737] */
    (xdc_Char)0x74,  /* [2738] */
    (xdc_Char)0x61,  /* [2739] */
    (xdc_Char)0x69,  /* [2740] */
    (xdc_Char)0x6c,  /* [2741] */
    (xdc_Char)0x73,  /* [2742] */
    (xdc_Char)0x2e,  /* [2743] */
    (xdc_Char)0x0,  /* [2744] */
    (xdc_Char)0x62,  /* [2745] */
    (xdc_Char)0x75,  /* [2746] */
    (xdc_Char)0x66,  /* [2747] */
    (xdc_Char)0x20,  /* [2748] */
    (xdc_Char)0x70,  /* [2749] */
    (xdc_Char)0x61,  /* [2750] */
    (xdc_Char)0x72,  /* [2751] */
    (xdc_Char)0x61,  /* [2752] */
    (xdc_Char)0x6d,  /* [2753] */
    (xdc_Char)0x65,  /* [2754] */
    (xdc_Char)0x74,  /* [2755] */
    (xdc_Char)0x65,  /* [2756] */
    (xdc_Char)0x72,  /* [2757] */
    (xdc_Char)0x20,  /* [2758] */
    (xdc_Char)0x63,  /* [2759] */
    (xdc_Char)0x61,  /* [2760] */
    (xdc_Char)0x6e,  /* [2761] */
    (xdc_Char)0x6e,  /* [2762] */
    (xdc_Char)0x6f,  /* [2763] */
    (xdc_Char)0x74,  /* [2764] */
    (xdc_Char)0x20,  /* [2765] */
    (xdc_Char)0x62,  /* [2766] */
    (xdc_Char)0x65,  /* [2767] */
    (xdc_Char)0x20,  /* [2768] */
    (xdc_Char)0x6e,  /* [2769] */
    (xdc_Char)0x75,  /* [2770] */
    (xdc_Char)0x6c,  /* [2771] */
    (xdc_Char)0x6c,  /* [2772] */
    (xdc_Char)0x0,  /* [2773] */
    (xdc_Char)0x62,  /* [2774] */
    (xdc_Char)0x75,  /* [2775] */
    (xdc_Char)0x66,  /* [2776] */
    (xdc_Char)0x20,  /* [2777] */
    (xdc_Char)0x6e,  /* [2778] */
    (xdc_Char)0x6f,  /* [2779] */
    (xdc_Char)0x74,  /* [2780] */
    (xdc_Char)0x20,  /* [2781] */
    (xdc_Char)0x70,  /* [2782] */
    (xdc_Char)0x72,  /* [2783] */
    (xdc_Char)0x6f,  /* [2784] */
    (xdc_Char)0x70,  /* [2785] */
    (xdc_Char)0x65,  /* [2786] */
    (xdc_Char)0x72,  /* [2787] */
    (xdc_Char)0x6c,  /* [2788] */
    (xdc_Char)0x79,  /* [2789] */
    (xdc_Char)0x20,  /* [2790] */
    (xdc_Char)0x61,  /* [2791] */
    (xdc_Char)0x6c,  /* [2792] */
    (xdc_Char)0x69,  /* [2793] */
    (xdc_Char)0x67,  /* [2794] */
    (xdc_Char)0x6e,  /* [2795] */
    (xdc_Char)0x65,  /* [2796] */
    (xdc_Char)0x64,  /* [2797] */
    (xdc_Char)0x0,  /* [2798] */
    (xdc_Char)0x61,  /* [2799] */
    (xdc_Char)0x6c,  /* [2800] */
    (xdc_Char)0x69,  /* [2801] */
    (xdc_Char)0x67,  /* [2802] */
    (xdc_Char)0x6e,  /* [2803] */
    (xdc_Char)0x20,  /* [2804] */
    (xdc_Char)0x70,  /* [2805] */
    (xdc_Char)0x61,  /* [2806] */
    (xdc_Char)0x72,  /* [2807] */
    (xdc_Char)0x61,  /* [2808] */
    (xdc_Char)0x6d,  /* [2809] */
    (xdc_Char)0x65,  /* [2810] */
    (xdc_Char)0x74,  /* [2811] */
    (xdc_Char)0x65,  /* [2812] */
    (xdc_Char)0x72,  /* [2813] */
    (xdc_Char)0x20,  /* [2814] */
    (xdc_Char)0x6d,  /* [2815] */
    (xdc_Char)0x75,  /* [2816] */
    (xdc_Char)0x73,  /* [2817] */
    (xdc_Char)0x74,  /* [2818] */
    (xdc_Char)0x20,  /* [2819] */
    (xdc_Char)0x62,  /* [2820] */
    (xdc_Char)0x65,  /* [2821] */
    (xdc_Char)0x20,  /* [2822] */
    (xdc_Char)0x30,  /* [2823] */
    (xdc_Char)0x20,  /* [2824] */
    (xdc_Char)0x6f,  /* [2825] */
    (xdc_Char)0x72,  /* [2826] */
    (xdc_Char)0x20,  /* [2827] */
    (xdc_Char)0x61,  /* [2828] */
    (xdc_Char)0x20,  /* [2829] */
    (xdc_Char)0x70,  /* [2830] */
    (xdc_Char)0x6f,  /* [2831] */
    (xdc_Char)0x77,  /* [2832] */
    (xdc_Char)0x65,  /* [2833] */
    (xdc_Char)0x72,  /* [2834] */
    (xdc_Char)0x20,  /* [2835] */
    (xdc_Char)0x6f,  /* [2836] */
    (xdc_Char)0x66,  /* [2837] */
    (xdc_Char)0x20,  /* [2838] */
    (xdc_Char)0x32,  /* [2839] */
    (xdc_Char)0x20,  /* [2840] */
    (xdc_Char)0x3e,  /* [2841] */
    (xdc_Char)0x3d,  /* [2842] */
    (xdc_Char)0x20,  /* [2843] */
    (xdc_Char)0x74,  /* [2844] */
    (xdc_Char)0x68,  /* [2845] */
    (xdc_Char)0x65,  /* [2846] */
    (xdc_Char)0x20,  /* [2847] */
    (xdc_Char)0x76,  /* [2848] */
    (xdc_Char)0x61,  /* [2849] */
    (xdc_Char)0x6c,  /* [2850] */
    (xdc_Char)0x75,  /* [2851] */
    (xdc_Char)0x65,  /* [2852] */
    (xdc_Char)0x20,  /* [2853] */
    (xdc_Char)0x6f,  /* [2854] */
    (xdc_Char)0x66,  /* [2855] */
    (xdc_Char)0x20,  /* [2856] */
    (xdc_Char)0x4d,  /* [2857] */
    (xdc_Char)0x65,  /* [2858] */
    (xdc_Char)0x6d,  /* [2859] */
    (xdc_Char)0x6f,  /* [2860] */
    (xdc_Char)0x72,  /* [2861] */
    (xdc_Char)0x79,  /* [2862] */
    (xdc_Char)0x5f,  /* [2863] */
    (xdc_Char)0x67,  /* [2864] */
    (xdc_Char)0x65,  /* [2865] */
    (xdc_Char)0x74,  /* [2866] */
    (xdc_Char)0x4d,  /* [2867] */
    (xdc_Char)0x61,  /* [2868] */
    (xdc_Char)0x78,  /* [2869] */
    (xdc_Char)0x44,  /* [2870] */
    (xdc_Char)0x65,  /* [2871] */
    (xdc_Char)0x66,  /* [2872] */
    (xdc_Char)0x61,  /* [2873] */
    (xdc_Char)0x75,  /* [2874] */
    (xdc_Char)0x6c,  /* [2875] */
    (xdc_Char)0x74,  /* [2876] */
    (xdc_Char)0x54,  /* [2877] */
    (xdc_Char)0x79,  /* [2878] */
    (xdc_Char)0x70,  /* [2879] */
    (xdc_Char)0x65,  /* [2880] */
    (xdc_Char)0x41,  /* [2881] */
    (xdc_Char)0x6c,  /* [2882] */
    (xdc_Char)0x69,  /* [2883] */
    (xdc_Char)0x67,  /* [2884] */
    (xdc_Char)0x6e,  /* [2885] */
    (xdc_Char)0x28,  /* [2886] */
    (xdc_Char)0x29,  /* [2887] */
    (xdc_Char)0x0,  /* [2888] */
    (xdc_Char)0x61,  /* [2889] */
    (xdc_Char)0x6c,  /* [2890] */
    (xdc_Char)0x69,  /* [2891] */
    (xdc_Char)0x67,  /* [2892] */
    (xdc_Char)0x6e,  /* [2893] */
    (xdc_Char)0x20,  /* [2894] */
    (xdc_Char)0x70,  /* [2895] */
    (xdc_Char)0x61,  /* [2896] */
    (xdc_Char)0x72,  /* [2897] */
    (xdc_Char)0x61,  /* [2898] */
    (xdc_Char)0x6d,  /* [2899] */
    (xdc_Char)0x65,  /* [2900] */
    (xdc_Char)0x74,  /* [2901] */
    (xdc_Char)0x65,  /* [2902] */
    (xdc_Char)0x72,  /* [2903] */
    (xdc_Char)0x20,  /* [2904] */
    (xdc_Char)0x31,  /* [2905] */
    (xdc_Char)0x29,  /* [2906] */
    (xdc_Char)0x20,  /* [2907] */
    (xdc_Char)0x6d,  /* [2908] */
    (xdc_Char)0x75,  /* [2909] */
    (xdc_Char)0x73,  /* [2910] */
    (xdc_Char)0x74,  /* [2911] */
    (xdc_Char)0x20,  /* [2912] */
    (xdc_Char)0x62,  /* [2913] */
    (xdc_Char)0x65,  /* [2914] */
    (xdc_Char)0x20,  /* [2915] */
    (xdc_Char)0x30,  /* [2916] */
    (xdc_Char)0x20,  /* [2917] */
    (xdc_Char)0x6f,  /* [2918] */
    (xdc_Char)0x72,  /* [2919] */
    (xdc_Char)0x20,  /* [2920] */
    (xdc_Char)0x61,  /* [2921] */
    (xdc_Char)0x20,  /* [2922] */
    (xdc_Char)0x70,  /* [2923] */
    (xdc_Char)0x6f,  /* [2924] */
    (xdc_Char)0x77,  /* [2925] */
    (xdc_Char)0x65,  /* [2926] */
    (xdc_Char)0x72,  /* [2927] */
    (xdc_Char)0x20,  /* [2928] */
    (xdc_Char)0x6f,  /* [2929] */
    (xdc_Char)0x66,  /* [2930] */
    (xdc_Char)0x20,  /* [2931] */
    (xdc_Char)0x32,  /* [2932] */
    (xdc_Char)0x20,  /* [2933] */
    (xdc_Char)0x61,  /* [2934] */
    (xdc_Char)0x6e,  /* [2935] */
    (xdc_Char)0x64,  /* [2936] */
    (xdc_Char)0x20,  /* [2937] */
    (xdc_Char)0x32,  /* [2938] */
    (xdc_Char)0x29,  /* [2939] */
    (xdc_Char)0x20,  /* [2940] */
    (xdc_Char)0x6e,  /* [2941] */
    (xdc_Char)0x6f,  /* [2942] */
    (xdc_Char)0x74,  /* [2943] */
    (xdc_Char)0x20,  /* [2944] */
    (xdc_Char)0x67,  /* [2945] */
    (xdc_Char)0x72,  /* [2946] */
    (xdc_Char)0x65,  /* [2947] */
    (xdc_Char)0x61,  /* [2948] */
    (xdc_Char)0x74,  /* [2949] */
    (xdc_Char)0x65,  /* [2950] */
    (xdc_Char)0x72,  /* [2951] */
    (xdc_Char)0x20,  /* [2952] */
    (xdc_Char)0x74,  /* [2953] */
    (xdc_Char)0x68,  /* [2954] */
    (xdc_Char)0x61,  /* [2955] */
    (xdc_Char)0x6e,  /* [2956] */
    (xdc_Char)0x20,  /* [2957] */
    (xdc_Char)0x74,  /* [2958] */
    (xdc_Char)0x68,  /* [2959] */
    (xdc_Char)0x65,  /* [2960] */
    (xdc_Char)0x20,  /* [2961] */
    (xdc_Char)0x68,  /* [2962] */
    (xdc_Char)0x65,  /* [2963] */
    (xdc_Char)0x61,  /* [2964] */
    (xdc_Char)0x70,  /* [2965] */
    (xdc_Char)0x73,  /* [2966] */
    (xdc_Char)0x20,  /* [2967] */
    (xdc_Char)0x61,  /* [2968] */
    (xdc_Char)0x6c,  /* [2969] */
    (xdc_Char)0x69,  /* [2970] */
    (xdc_Char)0x67,  /* [2971] */
    (xdc_Char)0x6e,  /* [2972] */
    (xdc_Char)0x6d,  /* [2973] */
    (xdc_Char)0x65,  /* [2974] */
    (xdc_Char)0x6e,  /* [2975] */
    (xdc_Char)0x74,  /* [2976] */
    (xdc_Char)0x0,  /* [2977] */
    (xdc_Char)0x62,  /* [2978] */
    (xdc_Char)0x6c,  /* [2979] */
    (xdc_Char)0x6f,  /* [2980] */
    (xdc_Char)0x63,  /* [2981] */
    (xdc_Char)0x6b,  /* [2982] */
    (xdc_Char)0x53,  /* [2983] */
    (xdc_Char)0x69,  /* [2984] */
    (xdc_Char)0x7a,  /* [2985] */
    (xdc_Char)0x65,  /* [2986] */
    (xdc_Char)0x20,  /* [2987] */
    (xdc_Char)0x6d,  /* [2988] */
    (xdc_Char)0x75,  /* [2989] */
    (xdc_Char)0x73,  /* [2990] */
    (xdc_Char)0x74,  /* [2991] */
    (xdc_Char)0x20,  /* [2992] */
    (xdc_Char)0x62,  /* [2993] */
    (xdc_Char)0x65,  /* [2994] */
    (xdc_Char)0x20,  /* [2995] */
    (xdc_Char)0x6c,  /* [2996] */
    (xdc_Char)0x61,  /* [2997] */
    (xdc_Char)0x72,  /* [2998] */
    (xdc_Char)0x67,  /* [2999] */
    (xdc_Char)0x65,  /* [3000] */
    (xdc_Char)0x20,  /* [3001] */
    (xdc_Char)0x65,  /* [3002] */
    (xdc_Char)0x6e,  /* [3003] */
    (xdc_Char)0x6f,  /* [3004] */
    (xdc_Char)0x75,  /* [3005] */
    (xdc_Char)0x67,  /* [3006] */
    (xdc_Char)0x68,  /* [3007] */
    (xdc_Char)0x20,  /* [3008] */
    (xdc_Char)0x74,  /* [3009] */
    (xdc_Char)0x6f,  /* [3010] */
    (xdc_Char)0x20,  /* [3011] */
    (xdc_Char)0x68,  /* [3012] */
    (xdc_Char)0x6f,  /* [3013] */
    (xdc_Char)0x6c,  /* [3014] */
    (xdc_Char)0x64,  /* [3015] */
    (xdc_Char)0x20,  /* [3016] */
    (xdc_Char)0x61,  /* [3017] */
    (xdc_Char)0x74,  /* [3018] */
    (xdc_Char)0x6c,  /* [3019] */
    (xdc_Char)0x65,  /* [3020] */
    (xdc_Char)0x61,  /* [3021] */
    (xdc_Char)0x73,  /* [3022] */
    (xdc_Char)0x74,  /* [3023] */
    (xdc_Char)0x20,  /* [3024] */
    (xdc_Char)0x74,  /* [3025] */
    (xdc_Char)0x77,  /* [3026] */
    (xdc_Char)0x6f,  /* [3027] */
    (xdc_Char)0x20,  /* [3028] */
    (xdc_Char)0x70,  /* [3029] */
    (xdc_Char)0x6f,  /* [3030] */
    (xdc_Char)0x69,  /* [3031] */
    (xdc_Char)0x6e,  /* [3032] */
    (xdc_Char)0x74,  /* [3033] */
    (xdc_Char)0x65,  /* [3034] */
    (xdc_Char)0x72,  /* [3035] */
    (xdc_Char)0x73,  /* [3036] */
    (xdc_Char)0x0,  /* [3037] */
    (xdc_Char)0x6e,  /* [3038] */
    (xdc_Char)0x75,  /* [3039] */
    (xdc_Char)0x6d,  /* [3040] */
    (xdc_Char)0x42,  /* [3041] */
    (xdc_Char)0x6c,  /* [3042] */
    (xdc_Char)0x6f,  /* [3043] */
    (xdc_Char)0x63,  /* [3044] */
    (xdc_Char)0x6b,  /* [3045] */
    (xdc_Char)0x73,  /* [3046] */
    (xdc_Char)0x20,  /* [3047] */
    (xdc_Char)0x63,  /* [3048] */
    (xdc_Char)0x61,  /* [3049] */
    (xdc_Char)0x6e,  /* [3050] */
    (xdc_Char)0x6e,  /* [3051] */
    (xdc_Char)0x6f,  /* [3052] */
    (xdc_Char)0x74,  /* [3053] */
    (xdc_Char)0x20,  /* [3054] */
    (xdc_Char)0x62,  /* [3055] */
    (xdc_Char)0x65,  /* [3056] */
    (xdc_Char)0x20,  /* [3057] */
    (xdc_Char)0x7a,  /* [3058] */
    (xdc_Char)0x65,  /* [3059] */
    (xdc_Char)0x72,  /* [3060] */
    (xdc_Char)0x6f,  /* [3061] */
    (xdc_Char)0x0,  /* [3062] */
    (xdc_Char)0x62,  /* [3063] */
    (xdc_Char)0x75,  /* [3064] */
    (xdc_Char)0x66,  /* [3065] */
    (xdc_Char)0x53,  /* [3066] */
    (xdc_Char)0x69,  /* [3067] */
    (xdc_Char)0x7a,  /* [3068] */
    (xdc_Char)0x65,  /* [3069] */
    (xdc_Char)0x20,  /* [3070] */
    (xdc_Char)0x63,  /* [3071] */
    (xdc_Char)0x61,  /* [3072] */
    (xdc_Char)0x6e,  /* [3073] */
    (xdc_Char)0x6e,  /* [3074] */
    (xdc_Char)0x6f,  /* [3075] */
    (xdc_Char)0x74,  /* [3076] */
    (xdc_Char)0x20,  /* [3077] */
    (xdc_Char)0x62,  /* [3078] */
    (xdc_Char)0x65,  /* [3079] */
    (xdc_Char)0x20,  /* [3080] */
    (xdc_Char)0x7a,  /* [3081] */
    (xdc_Char)0x65,  /* [3082] */
    (xdc_Char)0x72,  /* [3083] */
    (xdc_Char)0x6f,  /* [3084] */
    (xdc_Char)0x0,  /* [3085] */
    (xdc_Char)0x48,  /* [3086] */
    (xdc_Char)0x65,  /* [3087] */
    (xdc_Char)0x61,  /* [3088] */
    (xdc_Char)0x70,  /* [3089] */
    (xdc_Char)0x42,  /* [3090] */
    (xdc_Char)0x75,  /* [3091] */
    (xdc_Char)0x66,  /* [3092] */
    (xdc_Char)0x5f,  /* [3093] */
    (xdc_Char)0x63,  /* [3094] */
    (xdc_Char)0x72,  /* [3095] */
    (xdc_Char)0x65,  /* [3096] */
    (xdc_Char)0x61,  /* [3097] */
    (xdc_Char)0x74,  /* [3098] */
    (xdc_Char)0x65,  /* [3099] */
    (xdc_Char)0x27,  /* [3100] */
    (xdc_Char)0x73,  /* [3101] */
    (xdc_Char)0x20,  /* [3102] */
    (xdc_Char)0x62,  /* [3103] */
    (xdc_Char)0x75,  /* [3104] */
    (xdc_Char)0x66,  /* [3105] */
    (xdc_Char)0x53,  /* [3106] */
    (xdc_Char)0x69,  /* [3107] */
    (xdc_Char)0x7a,  /* [3108] */
    (xdc_Char)0x65,  /* [3109] */
    (xdc_Char)0x20,  /* [3110] */
    (xdc_Char)0x70,  /* [3111] */
    (xdc_Char)0x61,  /* [3112] */
    (xdc_Char)0x72,  /* [3113] */
    (xdc_Char)0x61,  /* [3114] */
    (xdc_Char)0x6d,  /* [3115] */
    (xdc_Char)0x65,  /* [3116] */
    (xdc_Char)0x74,  /* [3117] */
    (xdc_Char)0x65,  /* [3118] */
    (xdc_Char)0x72,  /* [3119] */
    (xdc_Char)0x20,  /* [3120] */
    (xdc_Char)0x69,  /* [3121] */
    (xdc_Char)0x73,  /* [3122] */
    (xdc_Char)0x20,  /* [3123] */
    (xdc_Char)0x69,  /* [3124] */
    (xdc_Char)0x6e,  /* [3125] */
    (xdc_Char)0x76,  /* [3126] */
    (xdc_Char)0x61,  /* [3127] */
    (xdc_Char)0x6c,  /* [3128] */
    (xdc_Char)0x69,  /* [3129] */
    (xdc_Char)0x64,  /* [3130] */
    (xdc_Char)0x20,  /* [3131] */
    (xdc_Char)0x28,  /* [3132] */
    (xdc_Char)0x74,  /* [3133] */
    (xdc_Char)0x6f,  /* [3134] */
    (xdc_Char)0x6f,  /* [3135] */
    (xdc_Char)0x20,  /* [3136] */
    (xdc_Char)0x73,  /* [3137] */
    (xdc_Char)0x6d,  /* [3138] */
    (xdc_Char)0x61,  /* [3139] */
    (xdc_Char)0x6c,  /* [3140] */
    (xdc_Char)0x6c,  /* [3141] */
    (xdc_Char)0x29,  /* [3142] */
    (xdc_Char)0x0,  /* [3143] */
    (xdc_Char)0x43,  /* [3144] */
    (xdc_Char)0x61,  /* [3145] */
    (xdc_Char)0x6e,  /* [3146] */
    (xdc_Char)0x6e,  /* [3147] */
    (xdc_Char)0x6f,  /* [3148] */
    (xdc_Char)0x74,  /* [3149] */
    (xdc_Char)0x20,  /* [3150] */
    (xdc_Char)0x63,  /* [3151] */
    (xdc_Char)0x61,  /* [3152] */
    (xdc_Char)0x6c,  /* [3153] */
    (xdc_Char)0x6c,  /* [3154] */
    (xdc_Char)0x20,  /* [3155] */
    (xdc_Char)0x48,  /* [3156] */
    (xdc_Char)0x65,  /* [3157] */
    (xdc_Char)0x61,  /* [3158] */
    (xdc_Char)0x70,  /* [3159] */
    (xdc_Char)0x42,  /* [3160] */
    (xdc_Char)0x75,  /* [3161] */
    (xdc_Char)0x66,  /* [3162] */
    (xdc_Char)0x5f,  /* [3163] */
    (xdc_Char)0x66,  /* [3164] */
    (xdc_Char)0x72,  /* [3165] */
    (xdc_Char)0x65,  /* [3166] */
    (xdc_Char)0x65,  /* [3167] */
    (xdc_Char)0x20,  /* [3168] */
    (xdc_Char)0x77,  /* [3169] */
    (xdc_Char)0x68,  /* [3170] */
    (xdc_Char)0x65,  /* [3171] */
    (xdc_Char)0x6e,  /* [3172] */
    (xdc_Char)0x20,  /* [3173] */
    (xdc_Char)0x6e,  /* [3174] */
    (xdc_Char)0x6f,  /* [3175] */
    (xdc_Char)0x20,  /* [3176] */
    (xdc_Char)0x62,  /* [3177] */
    (xdc_Char)0x6c,  /* [3178] */
    (xdc_Char)0x6f,  /* [3179] */
    (xdc_Char)0x63,  /* [3180] */
    (xdc_Char)0x6b,  /* [3181] */
    (xdc_Char)0x73,  /* [3182] */
    (xdc_Char)0x20,  /* [3183] */
    (xdc_Char)0x68,  /* [3184] */
    (xdc_Char)0x61,  /* [3185] */
    (xdc_Char)0x76,  /* [3186] */
    (xdc_Char)0x65,  /* [3187] */
    (xdc_Char)0x20,  /* [3188] */
    (xdc_Char)0x62,  /* [3189] */
    (xdc_Char)0x65,  /* [3190] */
    (xdc_Char)0x65,  /* [3191] */
    (xdc_Char)0x6e,  /* [3192] */
    (xdc_Char)0x20,  /* [3193] */
    (xdc_Char)0x61,  /* [3194] */
    (xdc_Char)0x6c,  /* [3195] */
    (xdc_Char)0x6c,  /* [3196] */
    (xdc_Char)0x6f,  /* [3197] */
    (xdc_Char)0x63,  /* [3198] */
    (xdc_Char)0x61,  /* [3199] */
    (xdc_Char)0x74,  /* [3200] */
    (xdc_Char)0x65,  /* [3201] */
    (xdc_Char)0x64,  /* [3202] */
    (xdc_Char)0x0,  /* [3203] */
    (xdc_Char)0x41,  /* [3204] */
    (xdc_Char)0x5f,  /* [3205] */
    (xdc_Char)0x69,  /* [3206] */
    (xdc_Char)0x6e,  /* [3207] */
    (xdc_Char)0x76,  /* [3208] */
    (xdc_Char)0x61,  /* [3209] */
    (xdc_Char)0x6c,  /* [3210] */
    (xdc_Char)0x69,  /* [3211] */
    (xdc_Char)0x64,  /* [3212] */
    (xdc_Char)0x46,  /* [3213] */
    (xdc_Char)0x72,  /* [3214] */
    (xdc_Char)0x65,  /* [3215] */
    (xdc_Char)0x65,  /* [3216] */
    (xdc_Char)0x3a,  /* [3217] */
    (xdc_Char)0x20,  /* [3218] */
    (xdc_Char)0x49,  /* [3219] */
    (xdc_Char)0x6e,  /* [3220] */
    (xdc_Char)0x76,  /* [3221] */
    (xdc_Char)0x61,  /* [3222] */
    (xdc_Char)0x6c,  /* [3223] */
    (xdc_Char)0x69,  /* [3224] */
    (xdc_Char)0x64,  /* [3225] */
    (xdc_Char)0x20,  /* [3226] */
    (xdc_Char)0x66,  /* [3227] */
    (xdc_Char)0x72,  /* [3228] */
    (xdc_Char)0x65,  /* [3229] */
    (xdc_Char)0x65,  /* [3230] */
    (xdc_Char)0x0,  /* [3231] */
    (xdc_Char)0x41,  /* [3232] */
    (xdc_Char)0x5f,  /* [3233] */
    (xdc_Char)0x7a,  /* [3234] */
    (xdc_Char)0x65,  /* [3235] */
    (xdc_Char)0x72,  /* [3236] */
    (xdc_Char)0x6f,  /* [3237] */
    (xdc_Char)0x42,  /* [3238] */
    (xdc_Char)0x6c,  /* [3239] */
    (xdc_Char)0x6f,  /* [3240] */
    (xdc_Char)0x63,  /* [3241] */
    (xdc_Char)0x6b,  /* [3242] */
    (xdc_Char)0x3a,  /* [3243] */
    (xdc_Char)0x20,  /* [3244] */
    (xdc_Char)0x43,  /* [3245] */
    (xdc_Char)0x61,  /* [3246] */
    (xdc_Char)0x6e,  /* [3247] */
    (xdc_Char)0x6e,  /* [3248] */
    (xdc_Char)0x6f,  /* [3249] */
    (xdc_Char)0x74,  /* [3250] */
    (xdc_Char)0x20,  /* [3251] */
    (xdc_Char)0x61,  /* [3252] */
    (xdc_Char)0x6c,  /* [3253] */
    (xdc_Char)0x6c,  /* [3254] */
    (xdc_Char)0x6f,  /* [3255] */
    (xdc_Char)0x63,  /* [3256] */
    (xdc_Char)0x61,  /* [3257] */
    (xdc_Char)0x74,  /* [3258] */
    (xdc_Char)0x65,  /* [3259] */
    (xdc_Char)0x20,  /* [3260] */
    (xdc_Char)0x73,  /* [3261] */
    (xdc_Char)0x69,  /* [3262] */
    (xdc_Char)0x7a,  /* [3263] */
    (xdc_Char)0x65,  /* [3264] */
    (xdc_Char)0x20,  /* [3265] */
    (xdc_Char)0x30,  /* [3266] */
    (xdc_Char)0x0,  /* [3267] */
    (xdc_Char)0x41,  /* [3268] */
    (xdc_Char)0x5f,  /* [3269] */
    (xdc_Char)0x68,  /* [3270] */
    (xdc_Char)0x65,  /* [3271] */
    (xdc_Char)0x61,  /* [3272] */
    (xdc_Char)0x70,  /* [3273] */
    (xdc_Char)0x53,  /* [3274] */
    (xdc_Char)0x69,  /* [3275] */
    (xdc_Char)0x7a,  /* [3276] */
    (xdc_Char)0x65,  /* [3277] */
    (xdc_Char)0x3a,  /* [3278] */
    (xdc_Char)0x20,  /* [3279] */
    (xdc_Char)0x52,  /* [3280] */
    (xdc_Char)0x65,  /* [3281] */
    (xdc_Char)0x71,  /* [3282] */
    (xdc_Char)0x75,  /* [3283] */
    (xdc_Char)0x65,  /* [3284] */
    (xdc_Char)0x73,  /* [3285] */
    (xdc_Char)0x74,  /* [3286] */
    (xdc_Char)0x65,  /* [3287] */
    (xdc_Char)0x64,  /* [3288] */
    (xdc_Char)0x20,  /* [3289] */
    (xdc_Char)0x68,  /* [3290] */
    (xdc_Char)0x65,  /* [3291] */
    (xdc_Char)0x61,  /* [3292] */
    (xdc_Char)0x70,  /* [3293] */
    (xdc_Char)0x20,  /* [3294] */
    (xdc_Char)0x73,  /* [3295] */
    (xdc_Char)0x69,  /* [3296] */
    (xdc_Char)0x7a,  /* [3297] */
    (xdc_Char)0x65,  /* [3298] */
    (xdc_Char)0x20,  /* [3299] */
    (xdc_Char)0x69,  /* [3300] */
    (xdc_Char)0x73,  /* [3301] */
    (xdc_Char)0x20,  /* [3302] */
    (xdc_Char)0x74,  /* [3303] */
    (xdc_Char)0x6f,  /* [3304] */
    (xdc_Char)0x6f,  /* [3305] */
    (xdc_Char)0x20,  /* [3306] */
    (xdc_Char)0x73,  /* [3307] */
    (xdc_Char)0x6d,  /* [3308] */
    (xdc_Char)0x61,  /* [3309] */
    (xdc_Char)0x6c,  /* [3310] */
    (xdc_Char)0x6c,  /* [3311] */
    (xdc_Char)0x0,  /* [3312] */
    (xdc_Char)0x41,  /* [3313] */
    (xdc_Char)0x5f,  /* [3314] */
    (xdc_Char)0x61,  /* [3315] */
    (xdc_Char)0x6c,  /* [3316] */
    (xdc_Char)0x69,  /* [3317] */
    (xdc_Char)0x67,  /* [3318] */
    (xdc_Char)0x6e,  /* [3319] */
    (xdc_Char)0x3a,  /* [3320] */
    (xdc_Char)0x20,  /* [3321] */
    (xdc_Char)0x52,  /* [3322] */
    (xdc_Char)0x65,  /* [3323] */
    (xdc_Char)0x71,  /* [3324] */
    (xdc_Char)0x75,  /* [3325] */
    (xdc_Char)0x65,  /* [3326] */
    (xdc_Char)0x73,  /* [3327] */
    (xdc_Char)0x74,  /* [3328] */
    (xdc_Char)0x65,  /* [3329] */
    (xdc_Char)0x64,  /* [3330] */
    (xdc_Char)0x20,  /* [3331] */
    (xdc_Char)0x61,  /* [3332] */
    (xdc_Char)0x6c,  /* [3333] */
    (xdc_Char)0x69,  /* [3334] */
    (xdc_Char)0x67,  /* [3335] */
    (xdc_Char)0x6e,  /* [3336] */
    (xdc_Char)0x20,  /* [3337] */
    (xdc_Char)0x69,  /* [3338] */
    (xdc_Char)0x73,  /* [3339] */
    (xdc_Char)0x20,  /* [3340] */
    (xdc_Char)0x6e,  /* [3341] */
    (xdc_Char)0x6f,  /* [3342] */
    (xdc_Char)0x74,  /* [3343] */
    (xdc_Char)0x20,  /* [3344] */
    (xdc_Char)0x61,  /* [3345] */
    (xdc_Char)0x20,  /* [3346] */
    (xdc_Char)0x70,  /* [3347] */
    (xdc_Char)0x6f,  /* [3348] */
    (xdc_Char)0x77,  /* [3349] */
    (xdc_Char)0x65,  /* [3350] */
    (xdc_Char)0x72,  /* [3351] */
    (xdc_Char)0x20,  /* [3352] */
    (xdc_Char)0x6f,  /* [3353] */
    (xdc_Char)0x66,  /* [3354] */
    (xdc_Char)0x20,  /* [3355] */
    (xdc_Char)0x32,  /* [3356] */
    (xdc_Char)0x0,  /* [3357] */
    (xdc_Char)0x49,  /* [3358] */
    (xdc_Char)0x6e,  /* [3359] */
    (xdc_Char)0x76,  /* [3360] */
    (xdc_Char)0x61,  /* [3361] */
    (xdc_Char)0x6c,  /* [3362] */
    (xdc_Char)0x69,  /* [3363] */
    (xdc_Char)0x64,  /* [3364] */
    (xdc_Char)0x20,  /* [3365] */
    (xdc_Char)0x62,  /* [3366] */
    (xdc_Char)0x6c,  /* [3367] */
    (xdc_Char)0x6f,  /* [3368] */
    (xdc_Char)0x63,  /* [3369] */
    (xdc_Char)0x6b,  /* [3370] */
    (xdc_Char)0x20,  /* [3371] */
    (xdc_Char)0x61,  /* [3372] */
    (xdc_Char)0x64,  /* [3373] */
    (xdc_Char)0x64,  /* [3374] */
    (xdc_Char)0x72,  /* [3375] */
    (xdc_Char)0x65,  /* [3376] */
    (xdc_Char)0x73,  /* [3377] */
    (xdc_Char)0x73,  /* [3378] */
    (xdc_Char)0x20,  /* [3379] */
    (xdc_Char)0x6f,  /* [3380] */
    (xdc_Char)0x6e,  /* [3381] */
    (xdc_Char)0x20,  /* [3382] */
    (xdc_Char)0x74,  /* [3383] */
    (xdc_Char)0x68,  /* [3384] */
    (xdc_Char)0x65,  /* [3385] */
    (xdc_Char)0x20,  /* [3386] */
    (xdc_Char)0x66,  /* [3387] */
    (xdc_Char)0x72,  /* [3388] */
    (xdc_Char)0x65,  /* [3389] */
    (xdc_Char)0x65,  /* [3390] */
    (xdc_Char)0x2e,  /* [3391] */
    (xdc_Char)0x20,  /* [3392] */
    (xdc_Char)0x46,  /* [3393] */
    (xdc_Char)0x61,  /* [3394] */
    (xdc_Char)0x69,  /* [3395] */
    (xdc_Char)0x6c,  /* [3396] */
    (xdc_Char)0x65,  /* [3397] */
    (xdc_Char)0x64,  /* [3398] */
    (xdc_Char)0x20,  /* [3399] */
    (xdc_Char)0x74,  /* [3400] */
    (xdc_Char)0x6f,  /* [3401] */
    (xdc_Char)0x20,  /* [3402] */
    (xdc_Char)0x66,  /* [3403] */
    (xdc_Char)0x72,  /* [3404] */
    (xdc_Char)0x65,  /* [3405] */
    (xdc_Char)0x65,  /* [3406] */
    (xdc_Char)0x20,  /* [3407] */
    (xdc_Char)0x62,  /* [3408] */
    (xdc_Char)0x6c,  /* [3409] */
    (xdc_Char)0x6f,  /* [3410] */
    (xdc_Char)0x63,  /* [3411] */
    (xdc_Char)0x6b,  /* [3412] */
    (xdc_Char)0x20,  /* [3413] */
    (xdc_Char)0x62,  /* [3414] */
    (xdc_Char)0x61,  /* [3415] */
    (xdc_Char)0x63,  /* [3416] */
    (xdc_Char)0x6b,  /* [3417] */
    (xdc_Char)0x20,  /* [3418] */
    (xdc_Char)0x74,  /* [3419] */
    (xdc_Char)0x6f,  /* [3420] */
    (xdc_Char)0x20,  /* [3421] */
    (xdc_Char)0x68,  /* [3422] */
    (xdc_Char)0x65,  /* [3423] */
    (xdc_Char)0x61,  /* [3424] */
    (xdc_Char)0x70,  /* [3425] */
    (xdc_Char)0x2e,  /* [3426] */
    (xdc_Char)0x0,  /* [3427] */
    (xdc_Char)0x41,  /* [3428] */
    (xdc_Char)0x5f,  /* [3429] */
    (xdc_Char)0x64,  /* [3430] */
    (xdc_Char)0x6f,  /* [3431] */
    (xdc_Char)0x75,  /* [3432] */
    (xdc_Char)0x62,  /* [3433] */
    (xdc_Char)0x6c,  /* [3434] */
    (xdc_Char)0x65,  /* [3435] */
    (xdc_Char)0x46,  /* [3436] */
    (xdc_Char)0x72,  /* [3437] */
    (xdc_Char)0x65,  /* [3438] */
    (xdc_Char)0x65,  /* [3439] */
    (xdc_Char)0x3a,  /* [3440] */
    (xdc_Char)0x20,  /* [3441] */
    (xdc_Char)0x42,  /* [3442] */
    (xdc_Char)0x75,  /* [3443] */
    (xdc_Char)0x66,  /* [3444] */
    (xdc_Char)0x66,  /* [3445] */
    (xdc_Char)0x65,  /* [3446] */
    (xdc_Char)0x72,  /* [3447] */
    (xdc_Char)0x20,  /* [3448] */
    (xdc_Char)0x61,  /* [3449] */
    (xdc_Char)0x6c,  /* [3450] */
    (xdc_Char)0x72,  /* [3451] */
    (xdc_Char)0x65,  /* [3452] */
    (xdc_Char)0x61,  /* [3453] */
    (xdc_Char)0x64,  /* [3454] */
    (xdc_Char)0x79,  /* [3455] */
    (xdc_Char)0x20,  /* [3456] */
    (xdc_Char)0x66,  /* [3457] */
    (xdc_Char)0x72,  /* [3458] */
    (xdc_Char)0x65,  /* [3459] */
    (xdc_Char)0x65,  /* [3460] */
    (xdc_Char)0x0,  /* [3461] */
    (xdc_Char)0x41,  /* [3462] */
    (xdc_Char)0x5f,  /* [3463] */
    (xdc_Char)0x62,  /* [3464] */
    (xdc_Char)0x75,  /* [3465] */
    (xdc_Char)0x66,  /* [3466] */
    (xdc_Char)0x4f,  /* [3467] */
    (xdc_Char)0x76,  /* [3468] */
    (xdc_Char)0x65,  /* [3469] */
    (xdc_Char)0x72,  /* [3470] */
    (xdc_Char)0x66,  /* [3471] */
    (xdc_Char)0x6c,  /* [3472] */
    (xdc_Char)0x6f,  /* [3473] */
    (xdc_Char)0x77,  /* [3474] */
    (xdc_Char)0x3a,  /* [3475] */
    (xdc_Char)0x20,  /* [3476] */
    (xdc_Char)0x42,  /* [3477] */
    (xdc_Char)0x75,  /* [3478] */
    (xdc_Char)0x66,  /* [3479] */
    (xdc_Char)0x66,  /* [3480] */
    (xdc_Char)0x65,  /* [3481] */
    (xdc_Char)0x72,  /* [3482] */
    (xdc_Char)0x20,  /* [3483] */
    (xdc_Char)0x6f,  /* [3484] */
    (xdc_Char)0x76,  /* [3485] */
    (xdc_Char)0x65,  /* [3486] */
    (xdc_Char)0x72,  /* [3487] */
    (xdc_Char)0x66,  /* [3488] */
    (xdc_Char)0x6c,  /* [3489] */
    (xdc_Char)0x6f,  /* [3490] */
    (xdc_Char)0x77,  /* [3491] */
    (xdc_Char)0x0,  /* [3492] */
    (xdc_Char)0x41,  /* [3493] */
    (xdc_Char)0x5f,  /* [3494] */
    (xdc_Char)0x6e,  /* [3495] */
    (xdc_Char)0x6f,  /* [3496] */
    (xdc_Char)0x74,  /* [3497] */
    (xdc_Char)0x45,  /* [3498] */
    (xdc_Char)0x6d,  /* [3499] */
    (xdc_Char)0x70,  /* [3500] */
    (xdc_Char)0x74,  /* [3501] */
    (xdc_Char)0x79,  /* [3502] */
    (xdc_Char)0x3a,  /* [3503] */
    (xdc_Char)0x20,  /* [3504] */
    (xdc_Char)0x48,  /* [3505] */
    (xdc_Char)0x65,  /* [3506] */
    (xdc_Char)0x61,  /* [3507] */
    (xdc_Char)0x70,  /* [3508] */
    (xdc_Char)0x20,  /* [3509] */
    (xdc_Char)0x6e,  /* [3510] */
    (xdc_Char)0x6f,  /* [3511] */
    (xdc_Char)0x74,  /* [3512] */
    (xdc_Char)0x20,  /* [3513] */
    (xdc_Char)0x65,  /* [3514] */
    (xdc_Char)0x6d,  /* [3515] */
    (xdc_Char)0x70,  /* [3516] */
    (xdc_Char)0x74,  /* [3517] */
    (xdc_Char)0x79,  /* [3518] */
    (xdc_Char)0x0,  /* [3519] */
    (xdc_Char)0x41,  /* [3520] */
    (xdc_Char)0x5f,  /* [3521] */
    (xdc_Char)0x6e,  /* [3522] */
    (xdc_Char)0x75,  /* [3523] */
    (xdc_Char)0x6c,  /* [3524] */
    (xdc_Char)0x6c,  /* [3525] */
    (xdc_Char)0x4f,  /* [3526] */
    (xdc_Char)0x62,  /* [3527] */
    (xdc_Char)0x6a,  /* [3528] */
    (xdc_Char)0x65,  /* [3529] */
    (xdc_Char)0x63,  /* [3530] */
    (xdc_Char)0x74,  /* [3531] */
    (xdc_Char)0x3a,  /* [3532] */
    (xdc_Char)0x20,  /* [3533] */
    (xdc_Char)0x48,  /* [3534] */
    (xdc_Char)0x65,  /* [3535] */
    (xdc_Char)0x61,  /* [3536] */
    (xdc_Char)0x70,  /* [3537] */
    (xdc_Char)0x54,  /* [3538] */
    (xdc_Char)0x72,  /* [3539] */
    (xdc_Char)0x61,  /* [3540] */
    (xdc_Char)0x63,  /* [3541] */
    (xdc_Char)0x6b,  /* [3542] */
    (xdc_Char)0x5f,  /* [3543] */
    (xdc_Char)0x70,  /* [3544] */
    (xdc_Char)0x72,  /* [3545] */
    (xdc_Char)0x69,  /* [3546] */
    (xdc_Char)0x6e,  /* [3547] */
    (xdc_Char)0x74,  /* [3548] */
    (xdc_Char)0x48,  /* [3549] */
    (xdc_Char)0x65,  /* [3550] */
    (xdc_Char)0x61,  /* [3551] */
    (xdc_Char)0x70,  /* [3552] */
    (xdc_Char)0x20,  /* [3553] */
    (xdc_Char)0x63,  /* [3554] */
    (xdc_Char)0x61,  /* [3555] */
    (xdc_Char)0x6c,  /* [3556] */
    (xdc_Char)0x6c,  /* [3557] */
    (xdc_Char)0x65,  /* [3558] */
    (xdc_Char)0x64,  /* [3559] */
    (xdc_Char)0x20,  /* [3560] */
    (xdc_Char)0x77,  /* [3561] */
    (xdc_Char)0x69,  /* [3562] */
    (xdc_Char)0x74,  /* [3563] */
    (xdc_Char)0x68,  /* [3564] */
    (xdc_Char)0x20,  /* [3565] */
    (xdc_Char)0x6e,  /* [3566] */
    (xdc_Char)0x75,  /* [3567] */
    (xdc_Char)0x6c,  /* [3568] */
    (xdc_Char)0x6c,  /* [3569] */
    (xdc_Char)0x20,  /* [3570] */
    (xdc_Char)0x6f,  /* [3571] */
    (xdc_Char)0x62,  /* [3572] */
    (xdc_Char)0x6a,  /* [3573] */
    (xdc_Char)0x0,  /* [3574] */
    (xdc_Char)0x61,  /* [3575] */
    (xdc_Char)0x73,  /* [3576] */
    (xdc_Char)0x73,  /* [3577] */
    (xdc_Char)0x65,  /* [3578] */
    (xdc_Char)0x72,  /* [3579] */
    (xdc_Char)0x74,  /* [3580] */
    (xdc_Char)0x69,  /* [3581] */
    (xdc_Char)0x6f,  /* [3582] */
    (xdc_Char)0x6e,  /* [3583] */
    (xdc_Char)0x20,  /* [3584] */
    (xdc_Char)0x66,  /* [3585] */
    (xdc_Char)0x61,  /* [3586] */
    (xdc_Char)0x69,  /* [3587] */
    (xdc_Char)0x6c,  /* [3588] */
    (xdc_Char)0x75,  /* [3589] */
    (xdc_Char)0x72,  /* [3590] */
    (xdc_Char)0x65,  /* [3591] */
    (xdc_Char)0x25,  /* [3592] */
    (xdc_Char)0x73,  /* [3593] */
    (xdc_Char)0x25,  /* [3594] */
    (xdc_Char)0x73,  /* [3595] */
    (xdc_Char)0x0,  /* [3596] */
    (xdc_Char)0x25,  /* [3597] */
    (xdc_Char)0x24,  /* [3598] */
    (xdc_Char)0x53,  /* [3599] */
    (xdc_Char)0x0,  /* [3600] */
    (xdc_Char)0x6f,  /* [3601] */
    (xdc_Char)0x75,  /* [3602] */
    (xdc_Char)0x74,  /* [3603] */
    (xdc_Char)0x20,  /* [3604] */
    (xdc_Char)0x6f,  /* [3605] */
    (xdc_Char)0x66,  /* [3606] */
    (xdc_Char)0x20,  /* [3607] */
    (xdc_Char)0x6d,  /* [3608] */
    (xdc_Char)0x65,  /* [3609] */
    (xdc_Char)0x6d,  /* [3610] */
    (xdc_Char)0x6f,  /* [3611] */
    (xdc_Char)0x72,  /* [3612] */
    (xdc_Char)0x79,  /* [3613] */
    (xdc_Char)0x3a,  /* [3614] */
    (xdc_Char)0x20,  /* [3615] */
    (xdc_Char)0x68,  /* [3616] */
    (xdc_Char)0x65,  /* [3617] */
    (xdc_Char)0x61,  /* [3618] */
    (xdc_Char)0x70,  /* [3619] */
    (xdc_Char)0x3d,  /* [3620] */
    (xdc_Char)0x30,  /* [3621] */
    (xdc_Char)0x78,  /* [3622] */
    (xdc_Char)0x25,  /* [3623] */
    (xdc_Char)0x78,  /* [3624] */
    (xdc_Char)0x2c,  /* [3625] */
    (xdc_Char)0x20,  /* [3626] */
    (xdc_Char)0x73,  /* [3627] */
    (xdc_Char)0x69,  /* [3628] */
    (xdc_Char)0x7a,  /* [3629] */
    (xdc_Char)0x65,  /* [3630] */
    (xdc_Char)0x3d,  /* [3631] */
    (xdc_Char)0x25,  /* [3632] */
    (xdc_Char)0x75,  /* [3633] */
    (xdc_Char)0x0,  /* [3634] */
    (xdc_Char)0x25,  /* [3635] */
    (xdc_Char)0x73,  /* [3636] */
    (xdc_Char)0x20,  /* [3637] */
    (xdc_Char)0x30,  /* [3638] */
    (xdc_Char)0x78,  /* [3639] */
    (xdc_Char)0x25,  /* [3640] */
    (xdc_Char)0x78,  /* [3641] */
    (xdc_Char)0x0,  /* [3642] */
    (xdc_Char)0x45,  /* [3643] */
    (xdc_Char)0x5f,  /* [3644] */
    (xdc_Char)0x62,  /* [3645] */
    (xdc_Char)0x61,  /* [3646] */
    (xdc_Char)0x64,  /* [3647] */
    (xdc_Char)0x4c,  /* [3648] */
    (xdc_Char)0x65,  /* [3649] */
    (xdc_Char)0x76,  /* [3650] */
    (xdc_Char)0x65,  /* [3651] */
    (xdc_Char)0x6c,  /* [3652] */
    (xdc_Char)0x3a,  /* [3653] */
    (xdc_Char)0x20,  /* [3654] */
    (xdc_Char)0x42,  /* [3655] */
    (xdc_Char)0x61,  /* [3656] */
    (xdc_Char)0x64,  /* [3657] */
    (xdc_Char)0x20,  /* [3658] */
    (xdc_Char)0x66,  /* [3659] */
    (xdc_Char)0x69,  /* [3660] */
    (xdc_Char)0x6c,  /* [3661] */
    (xdc_Char)0x74,  /* [3662] */
    (xdc_Char)0x65,  /* [3663] */
    (xdc_Char)0x72,  /* [3664] */
    (xdc_Char)0x20,  /* [3665] */
    (xdc_Char)0x6c,  /* [3666] */
    (xdc_Char)0x65,  /* [3667] */
    (xdc_Char)0x76,  /* [3668] */
    (xdc_Char)0x65,  /* [3669] */
    (xdc_Char)0x6c,  /* [3670] */
    (xdc_Char)0x20,  /* [3671] */
    (xdc_Char)0x76,  /* [3672] */
    (xdc_Char)0x61,  /* [3673] */
    (xdc_Char)0x6c,  /* [3674] */
    (xdc_Char)0x75,  /* [3675] */
    (xdc_Char)0x65,  /* [3676] */
    (xdc_Char)0x3a,  /* [3677] */
    (xdc_Char)0x20,  /* [3678] */
    (xdc_Char)0x25,  /* [3679] */
    (xdc_Char)0x64,  /* [3680] */
    (xdc_Char)0x0,  /* [3681] */
    (xdc_Char)0x66,  /* [3682] */
    (xdc_Char)0x72,  /* [3683] */
    (xdc_Char)0x65,  /* [3684] */
    (xdc_Char)0x65,  /* [3685] */
    (xdc_Char)0x28,  /* [3686] */
    (xdc_Char)0x29,  /* [3687] */
    (xdc_Char)0x20,  /* [3688] */
    (xdc_Char)0x69,  /* [3689] */
    (xdc_Char)0x6e,  /* [3690] */
    (xdc_Char)0x76,  /* [3691] */
    (xdc_Char)0x61,  /* [3692] */
    (xdc_Char)0x6c,  /* [3693] */
    (xdc_Char)0x69,  /* [3694] */
    (xdc_Char)0x64,  /* [3695] */
    (xdc_Char)0x20,  /* [3696] */
    (xdc_Char)0x69,  /* [3697] */
    (xdc_Char)0x6e,  /* [3698] */
    (xdc_Char)0x20,  /* [3699] */
    (xdc_Char)0x67,  /* [3700] */
    (xdc_Char)0x72,  /* [3701] */
    (xdc_Char)0x6f,  /* [3702] */
    (xdc_Char)0x77,  /* [3703] */
    (xdc_Char)0x74,  /* [3704] */
    (xdc_Char)0x68,  /* [3705] */
    (xdc_Char)0x2d,  /* [3706] */
    (xdc_Char)0x6f,  /* [3707] */
    (xdc_Char)0x6e,  /* [3708] */
    (xdc_Char)0x6c,  /* [3709] */
    (xdc_Char)0x79,  /* [3710] */
    (xdc_Char)0x20,  /* [3711] */
    (xdc_Char)0x48,  /* [3712] */
    (xdc_Char)0x65,  /* [3713] */
    (xdc_Char)0x61,  /* [3714] */
    (xdc_Char)0x70,  /* [3715] */
    (xdc_Char)0x4d,  /* [3716] */
    (xdc_Char)0x69,  /* [3717] */
    (xdc_Char)0x6e,  /* [3718] */
    (xdc_Char)0x0,  /* [3719] */
    (xdc_Char)0x54,  /* [3720] */
    (xdc_Char)0x68,  /* [3721] */
    (xdc_Char)0x65,  /* [3722] */
    (xdc_Char)0x20,  /* [3723] */
    (xdc_Char)0x52,  /* [3724] */
    (xdc_Char)0x54,  /* [3725] */
    (xdc_Char)0x53,  /* [3726] */
    (xdc_Char)0x20,  /* [3727] */
    (xdc_Char)0x68,  /* [3728] */
    (xdc_Char)0x65,  /* [3729] */
    (xdc_Char)0x61,  /* [3730] */
    (xdc_Char)0x70,  /* [3731] */
    (xdc_Char)0x20,  /* [3732] */
    (xdc_Char)0x69,  /* [3733] */
    (xdc_Char)0x73,  /* [3734] */
    (xdc_Char)0x20,  /* [3735] */
    (xdc_Char)0x75,  /* [3736] */
    (xdc_Char)0x73,  /* [3737] */
    (xdc_Char)0x65,  /* [3738] */
    (xdc_Char)0x64,  /* [3739] */
    (xdc_Char)0x20,  /* [3740] */
    (xdc_Char)0x75,  /* [3741] */
    (xdc_Char)0x70,  /* [3742] */
    (xdc_Char)0x2e,  /* [3743] */
    (xdc_Char)0x20,  /* [3744] */
    (xdc_Char)0x45,  /* [3745] */
    (xdc_Char)0x78,  /* [3746] */
    (xdc_Char)0x61,  /* [3747] */
    (xdc_Char)0x6d,  /* [3748] */
    (xdc_Char)0x69,  /* [3749] */
    (xdc_Char)0x6e,  /* [3750] */
    (xdc_Char)0x65,  /* [3751] */
    (xdc_Char)0x20,  /* [3752] */
    (xdc_Char)0x50,  /* [3753] */
    (xdc_Char)0x72,  /* [3754] */
    (xdc_Char)0x6f,  /* [3755] */
    (xdc_Char)0x67,  /* [3756] */
    (xdc_Char)0x72,  /* [3757] */
    (xdc_Char)0x61,  /* [3758] */
    (xdc_Char)0x6d,  /* [3759] */
    (xdc_Char)0x2e,  /* [3760] */
    (xdc_Char)0x68,  /* [3761] */
    (xdc_Char)0x65,  /* [3762] */
    (xdc_Char)0x61,  /* [3763] */
    (xdc_Char)0x70,  /* [3764] */
    (xdc_Char)0x2e,  /* [3765] */
    (xdc_Char)0x0,  /* [3766] */
    (xdc_Char)0x45,  /* [3767] */
    (xdc_Char)0x5f,  /* [3768] */
    (xdc_Char)0x62,  /* [3769] */
    (xdc_Char)0x61,  /* [3770] */
    (xdc_Char)0x64,  /* [3771] */
    (xdc_Char)0x43,  /* [3772] */
    (xdc_Char)0x6f,  /* [3773] */
    (xdc_Char)0x6d,  /* [3774] */
    (xdc_Char)0x6d,  /* [3775] */
    (xdc_Char)0x61,  /* [3776] */
    (xdc_Char)0x6e,  /* [3777] */
    (xdc_Char)0x64,  /* [3778] */
    (xdc_Char)0x3a,  /* [3779] */
    (xdc_Char)0x20,  /* [3780] */
    (xdc_Char)0x52,  /* [3781] */
    (xdc_Char)0x65,  /* [3782] */
    (xdc_Char)0x63,  /* [3783] */
    (xdc_Char)0x65,  /* [3784] */
    (xdc_Char)0x69,  /* [3785] */
    (xdc_Char)0x76,  /* [3786] */
    (xdc_Char)0x65,  /* [3787] */
    (xdc_Char)0x64,  /* [3788] */
    (xdc_Char)0x20,  /* [3789] */
    (xdc_Char)0x69,  /* [3790] */
    (xdc_Char)0x6e,  /* [3791] */
    (xdc_Char)0x76,  /* [3792] */
    (xdc_Char)0x61,  /* [3793] */
    (xdc_Char)0x6c,  /* [3794] */
    (xdc_Char)0x69,  /* [3795] */
    (xdc_Char)0x64,  /* [3796] */
    (xdc_Char)0x20,  /* [3797] */
    (xdc_Char)0x63,  /* [3798] */
    (xdc_Char)0x6f,  /* [3799] */
    (xdc_Char)0x6d,  /* [3800] */
    (xdc_Char)0x6d,  /* [3801] */
    (xdc_Char)0x61,  /* [3802] */
    (xdc_Char)0x6e,  /* [3803] */
    (xdc_Char)0x64,  /* [3804] */
    (xdc_Char)0x2c,  /* [3805] */
    (xdc_Char)0x20,  /* [3806] */
    (xdc_Char)0x69,  /* [3807] */
    (xdc_Char)0x64,  /* [3808] */
    (xdc_Char)0x3a,  /* [3809] */
    (xdc_Char)0x20,  /* [3810] */
    (xdc_Char)0x25,  /* [3811] */
    (xdc_Char)0x64,  /* [3812] */
    (xdc_Char)0x2e,  /* [3813] */
    (xdc_Char)0x0,  /* [3814] */
    (xdc_Char)0x45,  /* [3815] */
    (xdc_Char)0x5f,  /* [3816] */
    (xdc_Char)0x75,  /* [3817] */
    (xdc_Char)0x6e,  /* [3818] */
    (xdc_Char)0x70,  /* [3819] */
    (xdc_Char)0x6c,  /* [3820] */
    (xdc_Char)0x75,  /* [3821] */
    (xdc_Char)0x67,  /* [3822] */
    (xdc_Char)0x67,  /* [3823] */
    (xdc_Char)0x65,  /* [3824] */
    (xdc_Char)0x64,  /* [3825] */
    (xdc_Char)0x49,  /* [3826] */
    (xdc_Char)0x6e,  /* [3827] */
    (xdc_Char)0x74,  /* [3828] */
    (xdc_Char)0x65,  /* [3829] */
    (xdc_Char)0x72,  /* [3830] */
    (xdc_Char)0x72,  /* [3831] */
    (xdc_Char)0x75,  /* [3832] */
    (xdc_Char)0x70,  /* [3833] */
    (xdc_Char)0x74,  /* [3834] */
    (xdc_Char)0x3a,  /* [3835] */
    (xdc_Char)0x20,  /* [3836] */
    (xdc_Char)0x55,  /* [3837] */
    (xdc_Char)0x6e,  /* [3838] */
    (xdc_Char)0x70,  /* [3839] */
    (xdc_Char)0x6c,  /* [3840] */
    (xdc_Char)0x75,  /* [3841] */
    (xdc_Char)0x67,  /* [3842] */
    (xdc_Char)0x67,  /* [3843] */
    (xdc_Char)0x65,  /* [3844] */
    (xdc_Char)0x64,  /* [3845] */
    (xdc_Char)0x20,  /* [3846] */
    (xdc_Char)0x69,  /* [3847] */
    (xdc_Char)0x6e,  /* [3848] */
    (xdc_Char)0x74,  /* [3849] */
    (xdc_Char)0x65,  /* [3850] */
    (xdc_Char)0x72,  /* [3851] */
    (xdc_Char)0x72,  /* [3852] */
    (xdc_Char)0x75,  /* [3853] */
    (xdc_Char)0x70,  /* [3854] */
    (xdc_Char)0x74,  /* [3855] */
    (xdc_Char)0x20,  /* [3856] */
    (xdc_Char)0x66,  /* [3857] */
    (xdc_Char)0x6c,  /* [3858] */
    (xdc_Char)0x61,  /* [3859] */
    (xdc_Char)0x67,  /* [3860] */
    (xdc_Char)0x67,  /* [3861] */
    (xdc_Char)0x65,  /* [3862] */
    (xdc_Char)0x64,  /* [3863] */
    (xdc_Char)0x3a,  /* [3864] */
    (xdc_Char)0x20,  /* [3865] */
    (xdc_Char)0x69,  /* [3866] */
    (xdc_Char)0x6e,  /* [3867] */
    (xdc_Char)0x74,  /* [3868] */
    (xdc_Char)0x72,  /* [3869] */
    (xdc_Char)0x23,  /* [3870] */
    (xdc_Char)0x20,  /* [3871] */
    (xdc_Char)0x25,  /* [3872] */
    (xdc_Char)0x64,  /* [3873] */
    (xdc_Char)0x0,  /* [3874] */
    (xdc_Char)0x45,  /* [3875] */
    (xdc_Char)0x5f,  /* [3876] */
    (xdc_Char)0x61,  /* [3877] */
    (xdc_Char)0x6c,  /* [3878] */
    (xdc_Char)0x72,  /* [3879] */
    (xdc_Char)0x65,  /* [3880] */
    (xdc_Char)0x61,  /* [3881] */
    (xdc_Char)0x64,  /* [3882] */
    (xdc_Char)0x79,  /* [3883] */
    (xdc_Char)0x44,  /* [3884] */
    (xdc_Char)0x65,  /* [3885] */
    (xdc_Char)0x66,  /* [3886] */
    (xdc_Char)0x69,  /* [3887] */
    (xdc_Char)0x6e,  /* [3888] */
    (xdc_Char)0x65,  /* [3889] */
    (xdc_Char)0x64,  /* [3890] */
    (xdc_Char)0x3a,  /* [3891] */
    (xdc_Char)0x20,  /* [3892] */
    (xdc_Char)0x48,  /* [3893] */
    (xdc_Char)0x77,  /* [3894] */
    (xdc_Char)0x69,  /* [3895] */
    (xdc_Char)0x20,  /* [3896] */
    (xdc_Char)0x61,  /* [3897] */
    (xdc_Char)0x6c,  /* [3898] */
    (xdc_Char)0x72,  /* [3899] */
    (xdc_Char)0x65,  /* [3900] */
    (xdc_Char)0x61,  /* [3901] */
    (xdc_Char)0x64,  /* [3902] */
    (xdc_Char)0x79,  /* [3903] */
    (xdc_Char)0x20,  /* [3904] */
    (xdc_Char)0x64,  /* [3905] */
    (xdc_Char)0x65,  /* [3906] */
    (xdc_Char)0x66,  /* [3907] */
    (xdc_Char)0x69,  /* [3908] */
    (xdc_Char)0x6e,  /* [3909] */
    (xdc_Char)0x65,  /* [3910] */
    (xdc_Char)0x64,  /* [3911] */
    (xdc_Char)0x3a,  /* [3912] */
    (xdc_Char)0x20,  /* [3913] */
    (xdc_Char)0x69,  /* [3914] */
    (xdc_Char)0x6e,  /* [3915] */
    (xdc_Char)0x74,  /* [3916] */
    (xdc_Char)0x72,  /* [3917] */
    (xdc_Char)0x23,  /* [3918] */
    (xdc_Char)0x20,  /* [3919] */
    (xdc_Char)0x25,  /* [3920] */
    (xdc_Char)0x64,  /* [3921] */
    (xdc_Char)0x0,  /* [3922] */
    (xdc_Char)0x45,  /* [3923] */
    (xdc_Char)0x5f,  /* [3924] */
    (xdc_Char)0x6e,  /* [3925] */
    (xdc_Char)0x6f,  /* [3926] */
    (xdc_Char)0x74,  /* [3927] */
    (xdc_Char)0x41,  /* [3928] */
    (xdc_Char)0x76,  /* [3929] */
    (xdc_Char)0x61,  /* [3930] */
    (xdc_Char)0x69,  /* [3931] */
    (xdc_Char)0x6c,  /* [3932] */
    (xdc_Char)0x61,  /* [3933] */
    (xdc_Char)0x62,  /* [3934] */
    (xdc_Char)0x6c,  /* [3935] */
    (xdc_Char)0x65,  /* [3936] */
    (xdc_Char)0x3a,  /* [3937] */
    (xdc_Char)0x20,  /* [3938] */
    (xdc_Char)0x54,  /* [3939] */
    (xdc_Char)0x69,  /* [3940] */
    (xdc_Char)0x6d,  /* [3941] */
    (xdc_Char)0x65,  /* [3942] */
    (xdc_Char)0x72,  /* [3943] */
    (xdc_Char)0x20,  /* [3944] */
    (xdc_Char)0x6e,  /* [3945] */
    (xdc_Char)0x6f,  /* [3946] */
    (xdc_Char)0x74,  /* [3947] */
    (xdc_Char)0x20,  /* [3948] */
    (xdc_Char)0x61,  /* [3949] */
    (xdc_Char)0x76,  /* [3950] */
    (xdc_Char)0x61,  /* [3951] */
    (xdc_Char)0x69,  /* [3952] */
    (xdc_Char)0x6c,  /* [3953] */
    (xdc_Char)0x61,  /* [3954] */
    (xdc_Char)0x62,  /* [3955] */
    (xdc_Char)0x6c,  /* [3956] */
    (xdc_Char)0x65,  /* [3957] */
    (xdc_Char)0x20,  /* [3958] */
    (xdc_Char)0x25,  /* [3959] */
    (xdc_Char)0x64,  /* [3960] */
    (xdc_Char)0x0,  /* [3961] */
    (xdc_Char)0x53,  /* [3962] */
    (xdc_Char)0x74,  /* [3963] */
    (xdc_Char)0x61,  /* [3964] */
    (xdc_Char)0x63,  /* [3965] */
    (xdc_Char)0x6b,  /* [3966] */
    (xdc_Char)0x20,  /* [3967] */
    (xdc_Char)0x28,  /* [3968] */
    (xdc_Char)0x30,  /* [3969] */
    (xdc_Char)0x78,  /* [3970] */
    (xdc_Char)0x25,  /* [3971] */
    (xdc_Char)0x78,  /* [3972] */
    (xdc_Char)0x29,  /* [3973] */
    (xdc_Char)0x20,  /* [3974] */
    (xdc_Char)0x6e,  /* [3975] */
    (xdc_Char)0x6f,  /* [3976] */
    (xdc_Char)0x74,  /* [3977] */
    (xdc_Char)0x20,  /* [3978] */
    (xdc_Char)0x6c,  /* [3979] */
    (xdc_Char)0x6f,  /* [3980] */
    (xdc_Char)0x63,  /* [3981] */
    (xdc_Char)0x61,  /* [3982] */
    (xdc_Char)0x74,  /* [3983] */
    (xdc_Char)0x65,  /* [3984] */
    (xdc_Char)0x64,  /* [3985] */
    (xdc_Char)0x20,  /* [3986] */
    (xdc_Char)0x6f,  /* [3987] */
    (xdc_Char)0x6e,  /* [3988] */
    (xdc_Char)0x20,  /* [3989] */
    (xdc_Char)0x50,  /* [3990] */
    (xdc_Char)0x41,  /* [3991] */
    (xdc_Char)0x47,  /* [3992] */
    (xdc_Char)0x45,  /* [3993] */
    (xdc_Char)0x20,  /* [3994] */
    (xdc_Char)0x30,  /* [3995] */
    (xdc_Char)0x20,  /* [3996] */
    (xdc_Char)0x28,  /* [3997] */
    (xdc_Char)0x73,  /* [3998] */
    (xdc_Char)0x74,  /* [3999] */
    (xdc_Char)0x61,  /* [4000] */
    (xdc_Char)0x63,  /* [4001] */
    (xdc_Char)0x6b,  /* [4002] */
    (xdc_Char)0x20,  /* [4003] */
    (xdc_Char)0x6d,  /* [4004] */
    (xdc_Char)0x75,  /* [4005] */
    (xdc_Char)0x73,  /* [4006] */
    (xdc_Char)0x74,  /* [4007] */
    (xdc_Char)0x20,  /* [4008] */
    (xdc_Char)0x62,  /* [4009] */
    (xdc_Char)0x65,  /* [4010] */
    (xdc_Char)0x20,  /* [4011] */
    (xdc_Char)0x6c,  /* [4012] */
    (xdc_Char)0x6f,  /* [4013] */
    (xdc_Char)0x63,  /* [4014] */
    (xdc_Char)0x61,  /* [4015] */
    (xdc_Char)0x74,  /* [4016] */
    (xdc_Char)0x65,  /* [4017] */
    (xdc_Char)0x64,  /* [4018] */
    (xdc_Char)0x20,  /* [4019] */
    (xdc_Char)0x65,  /* [4020] */
    (xdc_Char)0x6e,  /* [4021] */
    (xdc_Char)0x74,  /* [4022] */
    (xdc_Char)0x69,  /* [4023] */
    (xdc_Char)0x72,  /* [4024] */
    (xdc_Char)0x65,  /* [4025] */
    (xdc_Char)0x6c,  /* [4026] */
    (xdc_Char)0x79,  /* [4027] */
    (xdc_Char)0x20,  /* [4028] */
    (xdc_Char)0x62,  /* [4029] */
    (xdc_Char)0x65,  /* [4030] */
    (xdc_Char)0x6c,  /* [4031] */
    (xdc_Char)0x6f,  /* [4032] */
    (xdc_Char)0x77,  /* [4033] */
    (xdc_Char)0x20,  /* [4034] */
    (xdc_Char)0x30,  /* [4035] */
    (xdc_Char)0x78,  /* [4036] */
    (xdc_Char)0x31,  /* [4037] */
    (xdc_Char)0x30,  /* [4038] */
    (xdc_Char)0x30,  /* [4039] */
    (xdc_Char)0x30,  /* [4040] */
    (xdc_Char)0x30,  /* [4041] */
    (xdc_Char)0x29,  /* [4042] */
    (xdc_Char)0x0,  /* [4043] */
    (xdc_Char)0x45,  /* [4044] */
    (xdc_Char)0x5f,  /* [4045] */
    (xdc_Char)0x6f,  /* [4046] */
    (xdc_Char)0x62,  /* [4047] */
    (xdc_Char)0x6a,  /* [4048] */
    (xdc_Char)0x65,  /* [4049] */
    (xdc_Char)0x63,  /* [4050] */
    (xdc_Char)0x74,  /* [4051] */
    (xdc_Char)0x4e,  /* [4052] */
    (xdc_Char)0x6f,  /* [4053] */
    (xdc_Char)0x74,  /* [4054] */
    (xdc_Char)0x49,  /* [4055] */
    (xdc_Char)0x6e,  /* [4056] */
    (xdc_Char)0x4b,  /* [4057] */
    (xdc_Char)0x65,  /* [4058] */
    (xdc_Char)0x72,  /* [4059] */
    (xdc_Char)0x6e,  /* [4060] */
    (xdc_Char)0x65,  /* [4061] */
    (xdc_Char)0x6c,  /* [4062] */
    (xdc_Char)0x53,  /* [4063] */
    (xdc_Char)0x70,  /* [4064] */
    (xdc_Char)0x61,  /* [4065] */
    (xdc_Char)0x63,  /* [4066] */
    (xdc_Char)0x65,  /* [4067] */
    (xdc_Char)0x3a,  /* [4068] */
    (xdc_Char)0x20,  /* [4069] */
    (xdc_Char)0x53,  /* [4070] */
    (xdc_Char)0x65,  /* [4071] */
    (xdc_Char)0x6d,  /* [4072] */
    (xdc_Char)0x61,  /* [4073] */
    (xdc_Char)0x70,  /* [4074] */
    (xdc_Char)0x68,  /* [4075] */
    (xdc_Char)0x6f,  /* [4076] */
    (xdc_Char)0x72,  /* [4077] */
    (xdc_Char)0x65,  /* [4078] */
    (xdc_Char)0x20,  /* [4079] */
    (xdc_Char)0x6f,  /* [4080] */
    (xdc_Char)0x62,  /* [4081] */
    (xdc_Char)0x6a,  /* [4082] */
    (xdc_Char)0x65,  /* [4083] */
    (xdc_Char)0x63,  /* [4084] */
    (xdc_Char)0x74,  /* [4085] */
    (xdc_Char)0x20,  /* [4086] */
    (xdc_Char)0x70,  /* [4087] */
    (xdc_Char)0x61,  /* [4088] */
    (xdc_Char)0x73,  /* [4089] */
    (xdc_Char)0x73,  /* [4090] */
    (xdc_Char)0x65,  /* [4091] */
    (xdc_Char)0x64,  /* [4092] */
    (xdc_Char)0x20,  /* [4093] */
    (xdc_Char)0x6e,  /* [4094] */
    (xdc_Char)0x6f,  /* [4095] */
    (xdc_Char)0x74,  /* [4096] */
    (xdc_Char)0x20,  /* [4097] */
    (xdc_Char)0x69,  /* [4098] */
    (xdc_Char)0x6e,  /* [4099] */
    (xdc_Char)0x20,  /* [4100] */
    (xdc_Char)0x4b,  /* [4101] */
    (xdc_Char)0x65,  /* [4102] */
    (xdc_Char)0x72,  /* [4103] */
    (xdc_Char)0x6e,  /* [4104] */
    (xdc_Char)0x65,  /* [4105] */
    (xdc_Char)0x6c,  /* [4106] */
    (xdc_Char)0x20,  /* [4107] */
    (xdc_Char)0x61,  /* [4108] */
    (xdc_Char)0x64,  /* [4109] */
    (xdc_Char)0x64,  /* [4110] */
    (xdc_Char)0x72,  /* [4111] */
    (xdc_Char)0x65,  /* [4112] */
    (xdc_Char)0x73,  /* [4113] */
    (xdc_Char)0x73,  /* [4114] */
    (xdc_Char)0x20,  /* [4115] */
    (xdc_Char)0x73,  /* [4116] */
    (xdc_Char)0x70,  /* [4117] */
    (xdc_Char)0x61,  /* [4118] */
    (xdc_Char)0x63,  /* [4119] */
    (xdc_Char)0x65,  /* [4120] */
    (xdc_Char)0x2e,  /* [4121] */
    (xdc_Char)0x0,  /* [4122] */
    (xdc_Char)0x45,  /* [4123] */
    (xdc_Char)0x5f,  /* [4124] */
    (xdc_Char)0x73,  /* [4125] */
    (xdc_Char)0x74,  /* [4126] */
    (xdc_Char)0x61,  /* [4127] */
    (xdc_Char)0x63,  /* [4128] */
    (xdc_Char)0x6b,  /* [4129] */
    (xdc_Char)0x4f,  /* [4130] */
    (xdc_Char)0x76,  /* [4131] */
    (xdc_Char)0x65,  /* [4132] */
    (xdc_Char)0x72,  /* [4133] */
    (xdc_Char)0x66,  /* [4134] */
    (xdc_Char)0x6c,  /* [4135] */
    (xdc_Char)0x6f,  /* [4136] */
    (xdc_Char)0x77,  /* [4137] */
    (xdc_Char)0x3a,  /* [4138] */
    (xdc_Char)0x20,  /* [4139] */
    (xdc_Char)0x54,  /* [4140] */
    (xdc_Char)0x61,  /* [4141] */
    (xdc_Char)0x73,  /* [4142] */
    (xdc_Char)0x6b,  /* [4143] */
    (xdc_Char)0x20,  /* [4144] */
    (xdc_Char)0x30,  /* [4145] */
    (xdc_Char)0x78,  /* [4146] */
    (xdc_Char)0x25,  /* [4147] */
    (xdc_Char)0x78,  /* [4148] */
    (xdc_Char)0x20,  /* [4149] */
    (xdc_Char)0x73,  /* [4150] */
    (xdc_Char)0x74,  /* [4151] */
    (xdc_Char)0x61,  /* [4152] */
    (xdc_Char)0x63,  /* [4153] */
    (xdc_Char)0x6b,  /* [4154] */
    (xdc_Char)0x20,  /* [4155] */
    (xdc_Char)0x6f,  /* [4156] */
    (xdc_Char)0x76,  /* [4157] */
    (xdc_Char)0x65,  /* [4158] */
    (xdc_Char)0x72,  /* [4159] */
    (xdc_Char)0x66,  /* [4160] */
    (xdc_Char)0x6c,  /* [4161] */
    (xdc_Char)0x6f,  /* [4162] */
    (xdc_Char)0x77,  /* [4163] */
    (xdc_Char)0x2e,  /* [4164] */
    (xdc_Char)0x0,  /* [4165] */
    (xdc_Char)0x45,  /* [4166] */
    (xdc_Char)0x5f,  /* [4167] */
    (xdc_Char)0x73,  /* [4168] */
    (xdc_Char)0x70,  /* [4169] */
    (xdc_Char)0x4f,  /* [4170] */
    (xdc_Char)0x75,  /* [4171] */
    (xdc_Char)0x74,  /* [4172] */
    (xdc_Char)0x4f,  /* [4173] */
    (xdc_Char)0x66,  /* [4174] */
    (xdc_Char)0x42,  /* [4175] */
    (xdc_Char)0x6f,  /* [4176] */
    (xdc_Char)0x75,  /* [4177] */
    (xdc_Char)0x6e,  /* [4178] */
    (xdc_Char)0x64,  /* [4179] */
    (xdc_Char)0x73,  /* [4180] */
    (xdc_Char)0x3a,  /* [4181] */
    (xdc_Char)0x20,  /* [4182] */
    (xdc_Char)0x54,  /* [4183] */
    (xdc_Char)0x61,  /* [4184] */
    (xdc_Char)0x73,  /* [4185] */
    (xdc_Char)0x6b,  /* [4186] */
    (xdc_Char)0x20,  /* [4187] */
    (xdc_Char)0x30,  /* [4188] */
    (xdc_Char)0x78,  /* [4189] */
    (xdc_Char)0x25,  /* [4190] */
    (xdc_Char)0x78,  /* [4191] */
    (xdc_Char)0x20,  /* [4192] */
    (xdc_Char)0x73,  /* [4193] */
    (xdc_Char)0x74,  /* [4194] */
    (xdc_Char)0x61,  /* [4195] */
    (xdc_Char)0x63,  /* [4196] */
    (xdc_Char)0x6b,  /* [4197] */
    (xdc_Char)0x20,  /* [4198] */
    (xdc_Char)0x65,  /* [4199] */
    (xdc_Char)0x72,  /* [4200] */
    (xdc_Char)0x72,  /* [4201] */
    (xdc_Char)0x6f,  /* [4202] */
    (xdc_Char)0x72,  /* [4203] */
    (xdc_Char)0x2c,  /* [4204] */
    (xdc_Char)0x20,  /* [4205] */
    (xdc_Char)0x53,  /* [4206] */
    (xdc_Char)0x50,  /* [4207] */
    (xdc_Char)0x20,  /* [4208] */
    (xdc_Char)0x3d,  /* [4209] */
    (xdc_Char)0x20,  /* [4210] */
    (xdc_Char)0x30,  /* [4211] */
    (xdc_Char)0x78,  /* [4212] */
    (xdc_Char)0x25,  /* [4213] */
    (xdc_Char)0x78,  /* [4214] */
    (xdc_Char)0x2e,  /* [4215] */
    (xdc_Char)0x0,  /* [4216] */
    (xdc_Char)0x45,  /* [4217] */
    (xdc_Char)0x5f,  /* [4218] */
    (xdc_Char)0x64,  /* [4219] */
    (xdc_Char)0x65,  /* [4220] */
    (xdc_Char)0x6c,  /* [4221] */
    (xdc_Char)0x65,  /* [4222] */
    (xdc_Char)0x74,  /* [4223] */
    (xdc_Char)0x65,  /* [4224] */
    (xdc_Char)0x4e,  /* [4225] */
    (xdc_Char)0x6f,  /* [4226] */
    (xdc_Char)0x74,  /* [4227] */
    (xdc_Char)0x41,  /* [4228] */
    (xdc_Char)0x6c,  /* [4229] */
    (xdc_Char)0x6c,  /* [4230] */
    (xdc_Char)0x6f,  /* [4231] */
    (xdc_Char)0x77,  /* [4232] */
    (xdc_Char)0x65,  /* [4233] */
    (xdc_Char)0x64,  /* [4234] */
    (xdc_Char)0x3a,  /* [4235] */
    (xdc_Char)0x20,  /* [4236] */
    (xdc_Char)0x54,  /* [4237] */
    (xdc_Char)0x61,  /* [4238] */
    (xdc_Char)0x73,  /* [4239] */
    (xdc_Char)0x6b,  /* [4240] */
    (xdc_Char)0x20,  /* [4241] */
    (xdc_Char)0x30,  /* [4242] */
    (xdc_Char)0x78,  /* [4243] */
    (xdc_Char)0x25,  /* [4244] */
    (xdc_Char)0x78,  /* [4245] */
    (xdc_Char)0x2e,  /* [4246] */
    (xdc_Char)0x0,  /* [4247] */
    (xdc_Char)0x45,  /* [4248] */
    (xdc_Char)0x5f,  /* [4249] */
    (xdc_Char)0x6d,  /* [4250] */
    (xdc_Char)0x6f,  /* [4251] */
    (xdc_Char)0x64,  /* [4252] */
    (xdc_Char)0x75,  /* [4253] */
    (xdc_Char)0x6c,  /* [4254] */
    (xdc_Char)0x65,  /* [4255] */
    (xdc_Char)0x53,  /* [4256] */
    (xdc_Char)0x74,  /* [4257] */
    (xdc_Char)0x61,  /* [4258] */
    (xdc_Char)0x74,  /* [4259] */
    (xdc_Char)0x65,  /* [4260] */
    (xdc_Char)0x43,  /* [4261] */
    (xdc_Char)0x68,  /* [4262] */
    (xdc_Char)0x65,  /* [4263] */
    (xdc_Char)0x63,  /* [4264] */
    (xdc_Char)0x6b,  /* [4265] */
    (xdc_Char)0x46,  /* [4266] */
    (xdc_Char)0x61,  /* [4267] */
    (xdc_Char)0x69,  /* [4268] */
    (xdc_Char)0x6c,  /* [4269] */
    (xdc_Char)0x65,  /* [4270] */
    (xdc_Char)0x64,  /* [4271] */
    (xdc_Char)0x3a,  /* [4272] */
    (xdc_Char)0x20,  /* [4273] */
    (xdc_Char)0x54,  /* [4274] */
    (xdc_Char)0x61,  /* [4275] */
    (xdc_Char)0x73,  /* [4276] */
    (xdc_Char)0x6b,  /* [4277] */
    (xdc_Char)0x20,  /* [4278] */
    (xdc_Char)0x6d,  /* [4279] */
    (xdc_Char)0x6f,  /* [4280] */
    (xdc_Char)0x64,  /* [4281] */
    (xdc_Char)0x75,  /* [4282] */
    (xdc_Char)0x6c,  /* [4283] */
    (xdc_Char)0x65,  /* [4284] */
    (xdc_Char)0x20,  /* [4285] */
    (xdc_Char)0x73,  /* [4286] */
    (xdc_Char)0x74,  /* [4287] */
    (xdc_Char)0x61,  /* [4288] */
    (xdc_Char)0x74,  /* [4289] */
    (xdc_Char)0x65,  /* [4290] */
    (xdc_Char)0x20,  /* [4291] */
    (xdc_Char)0x64,  /* [4292] */
    (xdc_Char)0x61,  /* [4293] */
    (xdc_Char)0x74,  /* [4294] */
    (xdc_Char)0x61,  /* [4295] */
    (xdc_Char)0x20,  /* [4296] */
    (xdc_Char)0x69,  /* [4297] */
    (xdc_Char)0x6e,  /* [4298] */
    (xdc_Char)0x74,  /* [4299] */
    (xdc_Char)0x65,  /* [4300] */
    (xdc_Char)0x67,  /* [4301] */
    (xdc_Char)0x72,  /* [4302] */
    (xdc_Char)0x69,  /* [4303] */
    (xdc_Char)0x74,  /* [4304] */
    (xdc_Char)0x79,  /* [4305] */
    (xdc_Char)0x20,  /* [4306] */
    (xdc_Char)0x63,  /* [4307] */
    (xdc_Char)0x68,  /* [4308] */
    (xdc_Char)0x65,  /* [4309] */
    (xdc_Char)0x63,  /* [4310] */
    (xdc_Char)0x6b,  /* [4311] */
    (xdc_Char)0x20,  /* [4312] */
    (xdc_Char)0x66,  /* [4313] */
    (xdc_Char)0x61,  /* [4314] */
    (xdc_Char)0x69,  /* [4315] */
    (xdc_Char)0x6c,  /* [4316] */
    (xdc_Char)0x65,  /* [4317] */
    (xdc_Char)0x64,  /* [4318] */
    (xdc_Char)0x2e,  /* [4319] */
    (xdc_Char)0x0,  /* [4320] */
    (xdc_Char)0x45,  /* [4321] */
    (xdc_Char)0x5f,  /* [4322] */
    (xdc_Char)0x6f,  /* [4323] */
    (xdc_Char)0x62,  /* [4324] */
    (xdc_Char)0x6a,  /* [4325] */
    (xdc_Char)0x65,  /* [4326] */
    (xdc_Char)0x63,  /* [4327] */
    (xdc_Char)0x74,  /* [4328] */
    (xdc_Char)0x43,  /* [4329] */
    (xdc_Char)0x68,  /* [4330] */
    (xdc_Char)0x65,  /* [4331] */
    (xdc_Char)0x63,  /* [4332] */
    (xdc_Char)0x6b,  /* [4333] */
    (xdc_Char)0x46,  /* [4334] */
    (xdc_Char)0x61,  /* [4335] */
    (xdc_Char)0x69,  /* [4336] */
    (xdc_Char)0x6c,  /* [4337] */
    (xdc_Char)0x65,  /* [4338] */
    (xdc_Char)0x64,  /* [4339] */
    (xdc_Char)0x3a,  /* [4340] */
    (xdc_Char)0x20,  /* [4341] */
    (xdc_Char)0x54,  /* [4342] */
    (xdc_Char)0x61,  /* [4343] */
    (xdc_Char)0x73,  /* [4344] */
    (xdc_Char)0x6b,  /* [4345] */
    (xdc_Char)0x20,  /* [4346] */
    (xdc_Char)0x30,  /* [4347] */
    (xdc_Char)0x78,  /* [4348] */
    (xdc_Char)0x25,  /* [4349] */
    (xdc_Char)0x78,  /* [4350] */
    (xdc_Char)0x20,  /* [4351] */
    (xdc_Char)0x6f,  /* [4352] */
    (xdc_Char)0x62,  /* [4353] */
    (xdc_Char)0x6a,  /* [4354] */
    (xdc_Char)0x65,  /* [4355] */
    (xdc_Char)0x63,  /* [4356] */
    (xdc_Char)0x74,  /* [4357] */
    (xdc_Char)0x20,  /* [4358] */
    (xdc_Char)0x64,  /* [4359] */
    (xdc_Char)0x61,  /* [4360] */
    (xdc_Char)0x74,  /* [4361] */
    (xdc_Char)0x61,  /* [4362] */
    (xdc_Char)0x20,  /* [4363] */
    (xdc_Char)0x69,  /* [4364] */
    (xdc_Char)0x6e,  /* [4365] */
    (xdc_Char)0x74,  /* [4366] */
    (xdc_Char)0x65,  /* [4367] */
    (xdc_Char)0x67,  /* [4368] */
    (xdc_Char)0x72,  /* [4369] */
    (xdc_Char)0x69,  /* [4370] */
    (xdc_Char)0x74,  /* [4371] */
    (xdc_Char)0x79,  /* [4372] */
    (xdc_Char)0x20,  /* [4373] */
    (xdc_Char)0x63,  /* [4374] */
    (xdc_Char)0x68,  /* [4375] */
    (xdc_Char)0x65,  /* [4376] */
    (xdc_Char)0x63,  /* [4377] */
    (xdc_Char)0x6b,  /* [4378] */
    (xdc_Char)0x20,  /* [4379] */
    (xdc_Char)0x66,  /* [4380] */
    (xdc_Char)0x61,  /* [4381] */
    (xdc_Char)0x69,  /* [4382] */
    (xdc_Char)0x6c,  /* [4383] */
    (xdc_Char)0x65,  /* [4384] */
    (xdc_Char)0x64,  /* [4385] */
    (xdc_Char)0x2e,  /* [4386] */
    (xdc_Char)0x0,  /* [4387] */
    (xdc_Char)0x45,  /* [4388] */
    (xdc_Char)0x5f,  /* [4389] */
    (xdc_Char)0x6f,  /* [4390] */
    (xdc_Char)0x62,  /* [4391] */
    (xdc_Char)0x6a,  /* [4392] */
    (xdc_Char)0x65,  /* [4393] */
    (xdc_Char)0x63,  /* [4394] */
    (xdc_Char)0x74,  /* [4395] */
    (xdc_Char)0x4e,  /* [4396] */
    (xdc_Char)0x6f,  /* [4397] */
    (xdc_Char)0x74,  /* [4398] */
    (xdc_Char)0x49,  /* [4399] */
    (xdc_Char)0x6e,  /* [4400] */
    (xdc_Char)0x4b,  /* [4401] */
    (xdc_Char)0x65,  /* [4402] */
    (xdc_Char)0x72,  /* [4403] */
    (xdc_Char)0x6e,  /* [4404] */
    (xdc_Char)0x65,  /* [4405] */
    (xdc_Char)0x6c,  /* [4406] */
    (xdc_Char)0x53,  /* [4407] */
    (xdc_Char)0x70,  /* [4408] */
    (xdc_Char)0x61,  /* [4409] */
    (xdc_Char)0x63,  /* [4410] */
    (xdc_Char)0x65,  /* [4411] */
    (xdc_Char)0x3a,  /* [4412] */
    (xdc_Char)0x20,  /* [4413] */
    (xdc_Char)0x54,  /* [4414] */
    (xdc_Char)0x61,  /* [4415] */
    (xdc_Char)0x73,  /* [4416] */
    (xdc_Char)0x6b,  /* [4417] */
    (xdc_Char)0x20,  /* [4418] */
    (xdc_Char)0x6f,  /* [4419] */
    (xdc_Char)0x62,  /* [4420] */
    (xdc_Char)0x6a,  /* [4421] */
    (xdc_Char)0x65,  /* [4422] */
    (xdc_Char)0x63,  /* [4423] */
    (xdc_Char)0x74,  /* [4424] */
    (xdc_Char)0x20,  /* [4425] */
    (xdc_Char)0x70,  /* [4426] */
    (xdc_Char)0x61,  /* [4427] */
    (xdc_Char)0x73,  /* [4428] */
    (xdc_Char)0x73,  /* [4429] */
    (xdc_Char)0x65,  /* [4430] */
    (xdc_Char)0x64,  /* [4431] */
    (xdc_Char)0x20,  /* [4432] */
    (xdc_Char)0x6e,  /* [4433] */
    (xdc_Char)0x6f,  /* [4434] */
    (xdc_Char)0x74,  /* [4435] */
    (xdc_Char)0x20,  /* [4436] */
    (xdc_Char)0x69,  /* [4437] */
    (xdc_Char)0x6e,  /* [4438] */
    (xdc_Char)0x20,  /* [4439] */
    (xdc_Char)0x4b,  /* [4440] */
    (xdc_Char)0x65,  /* [4441] */
    (xdc_Char)0x72,  /* [4442] */
    (xdc_Char)0x6e,  /* [4443] */
    (xdc_Char)0x65,  /* [4444] */
    (xdc_Char)0x6c,  /* [4445] */
    (xdc_Char)0x20,  /* [4446] */
    (xdc_Char)0x61,  /* [4447] */
    (xdc_Char)0x64,  /* [4448] */
    (xdc_Char)0x64,  /* [4449] */
    (xdc_Char)0x72,  /* [4450] */
    (xdc_Char)0x65,  /* [4451] */
    (xdc_Char)0x73,  /* [4452] */
    (xdc_Char)0x73,  /* [4453] */
    (xdc_Char)0x20,  /* [4454] */
    (xdc_Char)0x73,  /* [4455] */
    (xdc_Char)0x70,  /* [4456] */
    (xdc_Char)0x61,  /* [4457] */
    (xdc_Char)0x63,  /* [4458] */
    (xdc_Char)0x65,  /* [4459] */
    (xdc_Char)0x2e,  /* [4460] */
    (xdc_Char)0x0,  /* [4461] */
    (xdc_Char)0x45,  /* [4462] */
    (xdc_Char)0x5f,  /* [4463] */
    (xdc_Char)0x70,  /* [4464] */
    (xdc_Char)0x72,  /* [4465] */
    (xdc_Char)0x69,  /* [4466] */
    (xdc_Char)0x6f,  /* [4467] */
    (xdc_Char)0x72,  /* [4468] */
    (xdc_Char)0x69,  /* [4469] */
    (xdc_Char)0x74,  /* [4470] */
    (xdc_Char)0x79,  /* [4471] */
    (xdc_Char)0x3a,  /* [4472] */
    (xdc_Char)0x20,  /* [4473] */
    (xdc_Char)0x54,  /* [4474] */
    (xdc_Char)0x68,  /* [4475] */
    (xdc_Char)0x72,  /* [4476] */
    (xdc_Char)0x65,  /* [4477] */
    (xdc_Char)0x61,  /* [4478] */
    (xdc_Char)0x64,  /* [4479] */
    (xdc_Char)0x20,  /* [4480] */
    (xdc_Char)0x70,  /* [4481] */
    (xdc_Char)0x72,  /* [4482] */
    (xdc_Char)0x69,  /* [4483] */
    (xdc_Char)0x6f,  /* [4484] */
    (xdc_Char)0x72,  /* [4485] */
    (xdc_Char)0x69,  /* [4486] */
    (xdc_Char)0x74,  /* [4487] */
    (xdc_Char)0x79,  /* [4488] */
    (xdc_Char)0x20,  /* [4489] */
    (xdc_Char)0x69,  /* [4490] */
    (xdc_Char)0x73,  /* [4491] */
    (xdc_Char)0x20,  /* [4492] */
    (xdc_Char)0x69,  /* [4493] */
    (xdc_Char)0x6e,  /* [4494] */
    (xdc_Char)0x76,  /* [4495] */
    (xdc_Char)0x61,  /* [4496] */
    (xdc_Char)0x6c,  /* [4497] */
    (xdc_Char)0x69,  /* [4498] */
    (xdc_Char)0x64,  /* [4499] */
    (xdc_Char)0x20,  /* [4500] */
    (xdc_Char)0x25,  /* [4501] */
    (xdc_Char)0x64,  /* [4502] */
    (xdc_Char)0x0,  /* [4503] */
    (xdc_Char)0x45,  /* [4504] */
    (xdc_Char)0x5f,  /* [4505] */
    (xdc_Char)0x73,  /* [4506] */
    (xdc_Char)0x74,  /* [4507] */
    (xdc_Char)0x61,  /* [4508] */
    (xdc_Char)0x63,  /* [4509] */
    (xdc_Char)0x6b,  /* [4510] */
    (xdc_Char)0x4f,  /* [4511] */
    (xdc_Char)0x76,  /* [4512] */
    (xdc_Char)0x65,  /* [4513] */
    (xdc_Char)0x72,  /* [4514] */
    (xdc_Char)0x66,  /* [4515] */
    (xdc_Char)0x6c,  /* [4516] */
    (xdc_Char)0x6f,  /* [4517] */
    (xdc_Char)0x77,  /* [4518] */
    (xdc_Char)0x3a,  /* [4519] */
    (xdc_Char)0x20,  /* [4520] */
    (xdc_Char)0x49,  /* [4521] */
    (xdc_Char)0x53,  /* [4522] */
    (xdc_Char)0x52,  /* [4523] */
    (xdc_Char)0x20,  /* [4524] */
    (xdc_Char)0x73,  /* [4525] */
    (xdc_Char)0x74,  /* [4526] */
    (xdc_Char)0x61,  /* [4527] */
    (xdc_Char)0x63,  /* [4528] */
    (xdc_Char)0x6b,  /* [4529] */
    (xdc_Char)0x20,  /* [4530] */
    (xdc_Char)0x6f,  /* [4531] */
    (xdc_Char)0x76,  /* [4532] */
    (xdc_Char)0x65,  /* [4533] */
    (xdc_Char)0x72,  /* [4534] */
    (xdc_Char)0x66,  /* [4535] */
    (xdc_Char)0x6c,  /* [4536] */
    (xdc_Char)0x6f,  /* [4537] */
    (xdc_Char)0x77,  /* [4538] */
    (xdc_Char)0x2e,  /* [4539] */
    (xdc_Char)0x0,  /* [4540] */
    (xdc_Char)0x72,  /* [4541] */
    (xdc_Char)0x65,  /* [4542] */
    (xdc_Char)0x71,  /* [4543] */
    (xdc_Char)0x75,  /* [4544] */
    (xdc_Char)0x65,  /* [4545] */
    (xdc_Char)0x73,  /* [4546] */
    (xdc_Char)0x74,  /* [4547] */
    (xdc_Char)0x65,  /* [4548] */
    (xdc_Char)0x64,  /* [4549] */
    (xdc_Char)0x20,  /* [4550] */
    (xdc_Char)0x73,  /* [4551] */
    (xdc_Char)0x69,  /* [4552] */
    (xdc_Char)0x7a,  /* [4553] */
    (xdc_Char)0x65,  /* [4554] */
    (xdc_Char)0x20,  /* [4555] */
    (xdc_Char)0x69,  /* [4556] */
    (xdc_Char)0x73,  /* [4557] */
    (xdc_Char)0x20,  /* [4558] */
    (xdc_Char)0x74,  /* [4559] */
    (xdc_Char)0x6f,  /* [4560] */
    (xdc_Char)0x6f,  /* [4561] */
    (xdc_Char)0x20,  /* [4562] */
    (xdc_Char)0x62,  /* [4563] */
    (xdc_Char)0x69,  /* [4564] */
    (xdc_Char)0x67,  /* [4565] */
    (xdc_Char)0x3a,  /* [4566] */
    (xdc_Char)0x20,  /* [4567] */
    (xdc_Char)0x68,  /* [4568] */
    (xdc_Char)0x61,  /* [4569] */
    (xdc_Char)0x6e,  /* [4570] */
    (xdc_Char)0x64,  /* [4571] */
    (xdc_Char)0x6c,  /* [4572] */
    (xdc_Char)0x65,  /* [4573] */
    (xdc_Char)0x3d,  /* [4574] */
    (xdc_Char)0x30,  /* [4575] */
    (xdc_Char)0x78,  /* [4576] */
    (xdc_Char)0x25,  /* [4577] */
    (xdc_Char)0x78,  /* [4578] */
    (xdc_Char)0x2c,  /* [4579] */
    (xdc_Char)0x20,  /* [4580] */
    (xdc_Char)0x73,  /* [4581] */
    (xdc_Char)0x69,  /* [4582] */
    (xdc_Char)0x7a,  /* [4583] */
    (xdc_Char)0x65,  /* [4584] */
    (xdc_Char)0x3d,  /* [4585] */
    (xdc_Char)0x25,  /* [4586] */
    (xdc_Char)0x75,  /* [4587] */
    (xdc_Char)0x0,  /* [4588] */
    (xdc_Char)0x6f,  /* [4589] */
    (xdc_Char)0x75,  /* [4590] */
    (xdc_Char)0x74,  /* [4591] */
    (xdc_Char)0x20,  /* [4592] */
    (xdc_Char)0x6f,  /* [4593] */
    (xdc_Char)0x66,  /* [4594] */
    (xdc_Char)0x20,  /* [4595] */
    (xdc_Char)0x6d,  /* [4596] */
    (xdc_Char)0x65,  /* [4597] */
    (xdc_Char)0x6d,  /* [4598] */
    (xdc_Char)0x6f,  /* [4599] */
    (xdc_Char)0x72,  /* [4600] */
    (xdc_Char)0x79,  /* [4601] */
    (xdc_Char)0x3a,  /* [4602] */
    (xdc_Char)0x20,  /* [4603] */
    (xdc_Char)0x68,  /* [4604] */
    (xdc_Char)0x61,  /* [4605] */
    (xdc_Char)0x6e,  /* [4606] */
    (xdc_Char)0x64,  /* [4607] */
    (xdc_Char)0x6c,  /* [4608] */
    (xdc_Char)0x65,  /* [4609] */
    (xdc_Char)0x3d,  /* [4610] */
    (xdc_Char)0x30,  /* [4611] */
    (xdc_Char)0x78,  /* [4612] */
    (xdc_Char)0x25,  /* [4613] */
    (xdc_Char)0x78,  /* [4614] */
    (xdc_Char)0x2c,  /* [4615] */
    (xdc_Char)0x20,  /* [4616] */
    (xdc_Char)0x73,  /* [4617] */
    (xdc_Char)0x69,  /* [4618] */
    (xdc_Char)0x7a,  /* [4619] */
    (xdc_Char)0x65,  /* [4620] */
    (xdc_Char)0x3d,  /* [4621] */
    (xdc_Char)0x25,  /* [4622] */
    (xdc_Char)0x75,  /* [4623] */
    (xdc_Char)0x0,  /* [4624] */
    (xdc_Char)0x3c,  /* [4625] */
    (xdc_Char)0x2d,  /* [4626] */
    (xdc_Char)0x2d,  /* [4627] */
    (xdc_Char)0x20,  /* [4628] */
    (xdc_Char)0x63,  /* [4629] */
    (xdc_Char)0x6f,  /* [4630] */
    (xdc_Char)0x6e,  /* [4631] */
    (xdc_Char)0x73,  /* [4632] */
    (xdc_Char)0x74,  /* [4633] */
    (xdc_Char)0x72,  /* [4634] */
    (xdc_Char)0x75,  /* [4635] */
    (xdc_Char)0x63,  /* [4636] */
    (xdc_Char)0x74,  /* [4637] */
    (xdc_Char)0x3a,  /* [4638] */
    (xdc_Char)0x20,  /* [4639] */
    (xdc_Char)0x25,  /* [4640] */
    (xdc_Char)0x70,  /* [4641] */
    (xdc_Char)0x28,  /* [4642] */
    (xdc_Char)0x27,  /* [4643] */
    (xdc_Char)0x25,  /* [4644] */
    (xdc_Char)0x73,  /* [4645] */
    (xdc_Char)0x27,  /* [4646] */
    (xdc_Char)0x29,  /* [4647] */
    (xdc_Char)0x0,  /* [4648] */
    (xdc_Char)0x3c,  /* [4649] */
    (xdc_Char)0x2d,  /* [4650] */
    (xdc_Char)0x2d,  /* [4651] */
    (xdc_Char)0x20,  /* [4652] */
    (xdc_Char)0x63,  /* [4653] */
    (xdc_Char)0x72,  /* [4654] */
    (xdc_Char)0x65,  /* [4655] */
    (xdc_Char)0x61,  /* [4656] */
    (xdc_Char)0x74,  /* [4657] */
    (xdc_Char)0x65,  /* [4658] */
    (xdc_Char)0x3a,  /* [4659] */
    (xdc_Char)0x20,  /* [4660] */
    (xdc_Char)0x25,  /* [4661] */
    (xdc_Char)0x70,  /* [4662] */
    (xdc_Char)0x28,  /* [4663] */
    (xdc_Char)0x27,  /* [4664] */
    (xdc_Char)0x25,  /* [4665] */
    (xdc_Char)0x73,  /* [4666] */
    (xdc_Char)0x27,  /* [4667] */
    (xdc_Char)0x29,  /* [4668] */
    (xdc_Char)0x0,  /* [4669] */
    (xdc_Char)0x2d,  /* [4670] */
    (xdc_Char)0x2d,  /* [4671] */
    (xdc_Char)0x3e,  /* [4672] */
    (xdc_Char)0x20,  /* [4673] */
    (xdc_Char)0x64,  /* [4674] */
    (xdc_Char)0x65,  /* [4675] */
    (xdc_Char)0x73,  /* [4676] */
    (xdc_Char)0x74,  /* [4677] */
    (xdc_Char)0x72,  /* [4678] */
    (xdc_Char)0x75,  /* [4679] */
    (xdc_Char)0x63,  /* [4680] */
    (xdc_Char)0x74,  /* [4681] */
    (xdc_Char)0x3a,  /* [4682] */
    (xdc_Char)0x20,  /* [4683] */
    (xdc_Char)0x28,  /* [4684] */
    (xdc_Char)0x25,  /* [4685] */
    (xdc_Char)0x70,  /* [4686] */
    (xdc_Char)0x29,  /* [4687] */
    (xdc_Char)0x0,  /* [4688] */
    (xdc_Char)0x2d,  /* [4689] */
    (xdc_Char)0x2d,  /* [4690] */
    (xdc_Char)0x3e,  /* [4691] */
    (xdc_Char)0x20,  /* [4692] */
    (xdc_Char)0x64,  /* [4693] */
    (xdc_Char)0x65,  /* [4694] */
    (xdc_Char)0x6c,  /* [4695] */
    (xdc_Char)0x65,  /* [4696] */
    (xdc_Char)0x74,  /* [4697] */
    (xdc_Char)0x65,  /* [4698] */
    (xdc_Char)0x3a,  /* [4699] */
    (xdc_Char)0x20,  /* [4700] */
    (xdc_Char)0x28,  /* [4701] */
    (xdc_Char)0x25,  /* [4702] */
    (xdc_Char)0x70,  /* [4703] */
    (xdc_Char)0x29,  /* [4704] */
    (xdc_Char)0x0,  /* [4705] */
    (xdc_Char)0x45,  /* [4706] */
    (xdc_Char)0x52,  /* [4707] */
    (xdc_Char)0x52,  /* [4708] */
    (xdc_Char)0x4f,  /* [4709] */
    (xdc_Char)0x52,  /* [4710] */
    (xdc_Char)0x3a,  /* [4711] */
    (xdc_Char)0x20,  /* [4712] */
    (xdc_Char)0x25,  /* [4713] */
    (xdc_Char)0x24,  /* [4714] */
    (xdc_Char)0x46,  /* [4715] */
    (xdc_Char)0x25,  /* [4716] */
    (xdc_Char)0x24,  /* [4717] */
    (xdc_Char)0x53,  /* [4718] */
    (xdc_Char)0x0,  /* [4719] */
    (xdc_Char)0x57,  /* [4720] */
    (xdc_Char)0x41,  /* [4721] */
    (xdc_Char)0x52,  /* [4722] */
    (xdc_Char)0x4e,  /* [4723] */
    (xdc_Char)0x49,  /* [4724] */
    (xdc_Char)0x4e,  /* [4725] */
    (xdc_Char)0x47,  /* [4726] */
    (xdc_Char)0x3a,  /* [4727] */
    (xdc_Char)0x20,  /* [4728] */
    (xdc_Char)0x25,  /* [4729] */
    (xdc_Char)0x24,  /* [4730] */
    (xdc_Char)0x46,  /* [4731] */
    (xdc_Char)0x25,  /* [4732] */
    (xdc_Char)0x24,  /* [4733] */
    (xdc_Char)0x53,  /* [4734] */
    (xdc_Char)0x0,  /* [4735] */
    (xdc_Char)0x25,  /* [4736] */
    (xdc_Char)0x24,  /* [4737] */
    (xdc_Char)0x46,  /* [4738] */
    (xdc_Char)0x25,  /* [4739] */
    (xdc_Char)0x24,  /* [4740] */
    (xdc_Char)0x53,  /* [4741] */
    (xdc_Char)0x0,  /* [4742] */
    (xdc_Char)0x53,  /* [4743] */
    (xdc_Char)0x74,  /* [4744] */
    (xdc_Char)0x61,  /* [4745] */
    (xdc_Char)0x72,  /* [4746] */
    (xdc_Char)0x74,  /* [4747] */
    (xdc_Char)0x3a,  /* [4748] */
    (xdc_Char)0x20,  /* [4749] */
    (xdc_Char)0x25,  /* [4750] */
    (xdc_Char)0x24,  /* [4751] */
    (xdc_Char)0x53,  /* [4752] */
    (xdc_Char)0x0,  /* [4753] */
    (xdc_Char)0x53,  /* [4754] */
    (xdc_Char)0x74,  /* [4755] */
    (xdc_Char)0x6f,  /* [4756] */
    (xdc_Char)0x70,  /* [4757] */
    (xdc_Char)0x3a,  /* [4758] */
    (xdc_Char)0x20,  /* [4759] */
    (xdc_Char)0x25,  /* [4760] */
    (xdc_Char)0x24,  /* [4761] */
    (xdc_Char)0x53,  /* [4762] */
    (xdc_Char)0x0,  /* [4763] */
    (xdc_Char)0x53,  /* [4764] */
    (xdc_Char)0x74,  /* [4765] */
    (xdc_Char)0x61,  /* [4766] */
    (xdc_Char)0x72,  /* [4767] */
    (xdc_Char)0x74,  /* [4768] */
    (xdc_Char)0x49,  /* [4769] */
    (xdc_Char)0x6e,  /* [4770] */
    (xdc_Char)0x73,  /* [4771] */
    (xdc_Char)0x74,  /* [4772] */
    (xdc_Char)0x61,  /* [4773] */
    (xdc_Char)0x6e,  /* [4774] */
    (xdc_Char)0x63,  /* [4775] */
    (xdc_Char)0x65,  /* [4776] */
    (xdc_Char)0x3a,  /* [4777] */
    (xdc_Char)0x20,  /* [4778] */
    (xdc_Char)0x25,  /* [4779] */
    (xdc_Char)0x24,  /* [4780] */
    (xdc_Char)0x53,  /* [4781] */
    (xdc_Char)0x0,  /* [4782] */
    (xdc_Char)0x53,  /* [4783] */
    (xdc_Char)0x74,  /* [4784] */
    (xdc_Char)0x6f,  /* [4785] */
    (xdc_Char)0x70,  /* [4786] */
    (xdc_Char)0x49,  /* [4787] */
    (xdc_Char)0x6e,  /* [4788] */
    (xdc_Char)0x73,  /* [4789] */
    (xdc_Char)0x74,  /* [4790] */
    (xdc_Char)0x61,  /* [4791] */
    (xdc_Char)0x6e,  /* [4792] */
    (xdc_Char)0x63,  /* [4793] */
    (xdc_Char)0x65,  /* [4794] */
    (xdc_Char)0x3a,  /* [4795] */
    (xdc_Char)0x20,  /* [4796] */
    (xdc_Char)0x25,  /* [4797] */
    (xdc_Char)0x24,  /* [4798] */
    (xdc_Char)0x53,  /* [4799] */
    (xdc_Char)0x0,  /* [4800] */
    (xdc_Char)0x4c,  /* [4801] */
    (xdc_Char)0x4d,  /* [4802] */
    (xdc_Char)0x5f,  /* [4803] */
    (xdc_Char)0x62,  /* [4804] */
    (xdc_Char)0x65,  /* [4805] */
    (xdc_Char)0x67,  /* [4806] */
    (xdc_Char)0x69,  /* [4807] */
    (xdc_Char)0x6e,  /* [4808] */
    (xdc_Char)0x3a,  /* [4809] */
    (xdc_Char)0x20,  /* [4810] */
    (xdc_Char)0x68,  /* [4811] */
    (xdc_Char)0x77,  /* [4812] */
    (xdc_Char)0x69,  /* [4813] */
    (xdc_Char)0x3a,  /* [4814] */
    (xdc_Char)0x20,  /* [4815] */
    (xdc_Char)0x30,  /* [4816] */
    (xdc_Char)0x78,  /* [4817] */
    (xdc_Char)0x25,  /* [4818] */
    (xdc_Char)0x78,  /* [4819] */
    (xdc_Char)0x2c,  /* [4820] */
    (xdc_Char)0x20,  /* [4821] */
    (xdc_Char)0x66,  /* [4822] */
    (xdc_Char)0x75,  /* [4823] */
    (xdc_Char)0x6e,  /* [4824] */
    (xdc_Char)0x63,  /* [4825] */
    (xdc_Char)0x3a,  /* [4826] */
    (xdc_Char)0x20,  /* [4827] */
    (xdc_Char)0x30,  /* [4828] */
    (xdc_Char)0x78,  /* [4829] */
    (xdc_Char)0x25,  /* [4830] */
    (xdc_Char)0x78,  /* [4831] */
    (xdc_Char)0x2c,  /* [4832] */
    (xdc_Char)0x20,  /* [4833] */
    (xdc_Char)0x70,  /* [4834] */
    (xdc_Char)0x72,  /* [4835] */
    (xdc_Char)0x65,  /* [4836] */
    (xdc_Char)0x54,  /* [4837] */
    (xdc_Char)0x68,  /* [4838] */
    (xdc_Char)0x72,  /* [4839] */
    (xdc_Char)0x65,  /* [4840] */
    (xdc_Char)0x61,  /* [4841] */
    (xdc_Char)0x64,  /* [4842] */
    (xdc_Char)0x3a,  /* [4843] */
    (xdc_Char)0x20,  /* [4844] */
    (xdc_Char)0x25,  /* [4845] */
    (xdc_Char)0x64,  /* [4846] */
    (xdc_Char)0x2c,  /* [4847] */
    (xdc_Char)0x20,  /* [4848] */
    (xdc_Char)0x69,  /* [4849] */
    (xdc_Char)0x6e,  /* [4850] */
    (xdc_Char)0x74,  /* [4851] */
    (xdc_Char)0x4e,  /* [4852] */
    (xdc_Char)0x75,  /* [4853] */
    (xdc_Char)0x6d,  /* [4854] */
    (xdc_Char)0x3a,  /* [4855] */
    (xdc_Char)0x20,  /* [4856] */
    (xdc_Char)0x25,  /* [4857] */
    (xdc_Char)0x64,  /* [4858] */
    (xdc_Char)0x2c,  /* [4859] */
    (xdc_Char)0x20,  /* [4860] */
    (xdc_Char)0x69,  /* [4861] */
    (xdc_Char)0x72,  /* [4862] */
    (xdc_Char)0x70,  /* [4863] */
    (xdc_Char)0x3a,  /* [4864] */
    (xdc_Char)0x20,  /* [4865] */
    (xdc_Char)0x30,  /* [4866] */
    (xdc_Char)0x78,  /* [4867] */
    (xdc_Char)0x25,  /* [4868] */
    (xdc_Char)0x78,  /* [4869] */
    (xdc_Char)0x0,  /* [4870] */
    (xdc_Char)0x4c,  /* [4871] */
    (xdc_Char)0x44,  /* [4872] */
    (xdc_Char)0x5f,  /* [4873] */
    (xdc_Char)0x65,  /* [4874] */
    (xdc_Char)0x6e,  /* [4875] */
    (xdc_Char)0x64,  /* [4876] */
    (xdc_Char)0x3a,  /* [4877] */
    (xdc_Char)0x20,  /* [4878] */
    (xdc_Char)0x68,  /* [4879] */
    (xdc_Char)0x77,  /* [4880] */
    (xdc_Char)0x69,  /* [4881] */
    (xdc_Char)0x3a,  /* [4882] */
    (xdc_Char)0x20,  /* [4883] */
    (xdc_Char)0x30,  /* [4884] */
    (xdc_Char)0x78,  /* [4885] */
    (xdc_Char)0x25,  /* [4886] */
    (xdc_Char)0x78,  /* [4887] */
    (xdc_Char)0x0,  /* [4888] */
    (xdc_Char)0x4c,  /* [4889] */
    (xdc_Char)0x57,  /* [4890] */
    (xdc_Char)0x5f,  /* [4891] */
    (xdc_Char)0x64,  /* [4892] */
    (xdc_Char)0x65,  /* [4893] */
    (xdc_Char)0x6c,  /* [4894] */
    (xdc_Char)0x61,  /* [4895] */
    (xdc_Char)0x79,  /* [4896] */
    (xdc_Char)0x65,  /* [4897] */
    (xdc_Char)0x64,  /* [4898] */
    (xdc_Char)0x3a,  /* [4899] */
    (xdc_Char)0x20,  /* [4900] */
    (xdc_Char)0x64,  /* [4901] */
    (xdc_Char)0x65,  /* [4902] */
    (xdc_Char)0x6c,  /* [4903] */
    (xdc_Char)0x61,  /* [4904] */
    (xdc_Char)0x79,  /* [4905] */
    (xdc_Char)0x3a,  /* [4906] */
    (xdc_Char)0x20,  /* [4907] */
    (xdc_Char)0x25,  /* [4908] */
    (xdc_Char)0x64,  /* [4909] */
    (xdc_Char)0x0,  /* [4910] */
    (xdc_Char)0x4c,  /* [4911] */
    (xdc_Char)0x4d,  /* [4912] */
    (xdc_Char)0x5f,  /* [4913] */
    (xdc_Char)0x74,  /* [4914] */
    (xdc_Char)0x69,  /* [4915] */
    (xdc_Char)0x63,  /* [4916] */
    (xdc_Char)0x6b,  /* [4917] */
    (xdc_Char)0x3a,  /* [4918] */
    (xdc_Char)0x20,  /* [4919] */
    (xdc_Char)0x74,  /* [4920] */
    (xdc_Char)0x69,  /* [4921] */
    (xdc_Char)0x63,  /* [4922] */
    (xdc_Char)0x6b,  /* [4923] */
    (xdc_Char)0x3a,  /* [4924] */
    (xdc_Char)0x20,  /* [4925] */
    (xdc_Char)0x25,  /* [4926] */
    (xdc_Char)0x64,  /* [4927] */
    (xdc_Char)0x0,  /* [4928] */
    (xdc_Char)0x4c,  /* [4929] */
    (xdc_Char)0x4d,  /* [4930] */
    (xdc_Char)0x5f,  /* [4931] */
    (xdc_Char)0x62,  /* [4932] */
    (xdc_Char)0x65,  /* [4933] */
    (xdc_Char)0x67,  /* [4934] */
    (xdc_Char)0x69,  /* [4935] */
    (xdc_Char)0x6e,  /* [4936] */
    (xdc_Char)0x3a,  /* [4937] */
    (xdc_Char)0x20,  /* [4938] */
    (xdc_Char)0x63,  /* [4939] */
    (xdc_Char)0x6c,  /* [4940] */
    (xdc_Char)0x6b,  /* [4941] */
    (xdc_Char)0x3a,  /* [4942] */
    (xdc_Char)0x20,  /* [4943] */
    (xdc_Char)0x30,  /* [4944] */
    (xdc_Char)0x78,  /* [4945] */
    (xdc_Char)0x25,  /* [4946] */
    (xdc_Char)0x78,  /* [4947] */
    (xdc_Char)0x2c,  /* [4948] */
    (xdc_Char)0x20,  /* [4949] */
    (xdc_Char)0x66,  /* [4950] */
    (xdc_Char)0x75,  /* [4951] */
    (xdc_Char)0x6e,  /* [4952] */
    (xdc_Char)0x63,  /* [4953] */
    (xdc_Char)0x3a,  /* [4954] */
    (xdc_Char)0x20,  /* [4955] */
    (xdc_Char)0x30,  /* [4956] */
    (xdc_Char)0x78,  /* [4957] */
    (xdc_Char)0x25,  /* [4958] */
    (xdc_Char)0x78,  /* [4959] */
    (xdc_Char)0x0,  /* [4960] */
    (xdc_Char)0x4c,  /* [4961] */
    (xdc_Char)0x4d,  /* [4962] */
    (xdc_Char)0x5f,  /* [4963] */
    (xdc_Char)0x70,  /* [4964] */
    (xdc_Char)0x6f,  /* [4965] */
    (xdc_Char)0x73,  /* [4966] */
    (xdc_Char)0x74,  /* [4967] */
    (xdc_Char)0x3a,  /* [4968] */
    (xdc_Char)0x20,  /* [4969] */
    (xdc_Char)0x73,  /* [4970] */
    (xdc_Char)0x65,  /* [4971] */
    (xdc_Char)0x6d,  /* [4972] */
    (xdc_Char)0x3a,  /* [4973] */
    (xdc_Char)0x20,  /* [4974] */
    (xdc_Char)0x30,  /* [4975] */
    (xdc_Char)0x78,  /* [4976] */
    (xdc_Char)0x25,  /* [4977] */
    (xdc_Char)0x78,  /* [4978] */
    (xdc_Char)0x2c,  /* [4979] */
    (xdc_Char)0x20,  /* [4980] */
    (xdc_Char)0x63,  /* [4981] */
    (xdc_Char)0x6f,  /* [4982] */
    (xdc_Char)0x75,  /* [4983] */
    (xdc_Char)0x6e,  /* [4984] */
    (xdc_Char)0x74,  /* [4985] */
    (xdc_Char)0x3a,  /* [4986] */
    (xdc_Char)0x20,  /* [4987] */
    (xdc_Char)0x25,  /* [4988] */
    (xdc_Char)0x64,  /* [4989] */
    (xdc_Char)0x0,  /* [4990] */
    (xdc_Char)0x4c,  /* [4991] */
    (xdc_Char)0x4d,  /* [4992] */
    (xdc_Char)0x5f,  /* [4993] */
    (xdc_Char)0x70,  /* [4994] */
    (xdc_Char)0x65,  /* [4995] */
    (xdc_Char)0x6e,  /* [4996] */
    (xdc_Char)0x64,  /* [4997] */
    (xdc_Char)0x3a,  /* [4998] */
    (xdc_Char)0x20,  /* [4999] */
    (xdc_Char)0x73,  /* [5000] */
    (xdc_Char)0x65,  /* [5001] */
    (xdc_Char)0x6d,  /* [5002] */
    (xdc_Char)0x3a,  /* [5003] */
    (xdc_Char)0x20,  /* [5004] */
    (xdc_Char)0x30,  /* [5005] */
    (xdc_Char)0x78,  /* [5006] */
    (xdc_Char)0x25,  /* [5007] */
    (xdc_Char)0x78,  /* [5008] */
    (xdc_Char)0x2c,  /* [5009] */
    (xdc_Char)0x20,  /* [5010] */
    (xdc_Char)0x63,  /* [5011] */
    (xdc_Char)0x6f,  /* [5012] */
    (xdc_Char)0x75,  /* [5013] */
    (xdc_Char)0x6e,  /* [5014] */
    (xdc_Char)0x74,  /* [5015] */
    (xdc_Char)0x3a,  /* [5016] */
    (xdc_Char)0x20,  /* [5017] */
    (xdc_Char)0x25,  /* [5018] */
    (xdc_Char)0x64,  /* [5019] */
    (xdc_Char)0x2c,  /* [5020] */
    (xdc_Char)0x20,  /* [5021] */
    (xdc_Char)0x74,  /* [5022] */
    (xdc_Char)0x69,  /* [5023] */
    (xdc_Char)0x6d,  /* [5024] */
    (xdc_Char)0x65,  /* [5025] */
    (xdc_Char)0x6f,  /* [5026] */
    (xdc_Char)0x75,  /* [5027] */
    (xdc_Char)0x74,  /* [5028] */
    (xdc_Char)0x3a,  /* [5029] */
    (xdc_Char)0x20,  /* [5030] */
    (xdc_Char)0x25,  /* [5031] */
    (xdc_Char)0x64,  /* [5032] */
    (xdc_Char)0x0,  /* [5033] */
    (xdc_Char)0x4c,  /* [5034] */
    (xdc_Char)0x4d,  /* [5035] */
    (xdc_Char)0x5f,  /* [5036] */
    (xdc_Char)0x62,  /* [5037] */
    (xdc_Char)0x65,  /* [5038] */
    (xdc_Char)0x67,  /* [5039] */
    (xdc_Char)0x69,  /* [5040] */
    (xdc_Char)0x6e,  /* [5041] */
    (xdc_Char)0x3a,  /* [5042] */
    (xdc_Char)0x20,  /* [5043] */
    (xdc_Char)0x73,  /* [5044] */
    (xdc_Char)0x77,  /* [5045] */
    (xdc_Char)0x69,  /* [5046] */
    (xdc_Char)0x3a,  /* [5047] */
    (xdc_Char)0x20,  /* [5048] */
    (xdc_Char)0x30,  /* [5049] */
    (xdc_Char)0x78,  /* [5050] */
    (xdc_Char)0x25,  /* [5051] */
    (xdc_Char)0x78,  /* [5052] */
    (xdc_Char)0x2c,  /* [5053] */
    (xdc_Char)0x20,  /* [5054] */
    (xdc_Char)0x66,  /* [5055] */
    (xdc_Char)0x75,  /* [5056] */
    (xdc_Char)0x6e,  /* [5057] */
    (xdc_Char)0x63,  /* [5058] */
    (xdc_Char)0x3a,  /* [5059] */
    (xdc_Char)0x20,  /* [5060] */
    (xdc_Char)0x30,  /* [5061] */
    (xdc_Char)0x78,  /* [5062] */
    (xdc_Char)0x25,  /* [5063] */
    (xdc_Char)0x78,  /* [5064] */
    (xdc_Char)0x2c,  /* [5065] */
    (xdc_Char)0x20,  /* [5066] */
    (xdc_Char)0x70,  /* [5067] */
    (xdc_Char)0x72,  /* [5068] */
    (xdc_Char)0x65,  /* [5069] */
    (xdc_Char)0x54,  /* [5070] */
    (xdc_Char)0x68,  /* [5071] */
    (xdc_Char)0x72,  /* [5072] */
    (xdc_Char)0x65,  /* [5073] */
    (xdc_Char)0x61,  /* [5074] */
    (xdc_Char)0x64,  /* [5075] */
    (xdc_Char)0x3a,  /* [5076] */
    (xdc_Char)0x20,  /* [5077] */
    (xdc_Char)0x25,  /* [5078] */
    (xdc_Char)0x64,  /* [5079] */
    (xdc_Char)0x0,  /* [5080] */
    (xdc_Char)0x4c,  /* [5081] */
    (xdc_Char)0x44,  /* [5082] */
    (xdc_Char)0x5f,  /* [5083] */
    (xdc_Char)0x65,  /* [5084] */
    (xdc_Char)0x6e,  /* [5085] */
    (xdc_Char)0x64,  /* [5086] */
    (xdc_Char)0x3a,  /* [5087] */
    (xdc_Char)0x20,  /* [5088] */
    (xdc_Char)0x73,  /* [5089] */
    (xdc_Char)0x77,  /* [5090] */
    (xdc_Char)0x69,  /* [5091] */
    (xdc_Char)0x3a,  /* [5092] */
    (xdc_Char)0x20,  /* [5093] */
    (xdc_Char)0x30,  /* [5094] */
    (xdc_Char)0x78,  /* [5095] */
    (xdc_Char)0x25,  /* [5096] */
    (xdc_Char)0x78,  /* [5097] */
    (xdc_Char)0x0,  /* [5098] */
    (xdc_Char)0x4c,  /* [5099] */
    (xdc_Char)0x4d,  /* [5100] */
    (xdc_Char)0x5f,  /* [5101] */
    (xdc_Char)0x70,  /* [5102] */
    (xdc_Char)0x6f,  /* [5103] */
    (xdc_Char)0x73,  /* [5104] */
    (xdc_Char)0x74,  /* [5105] */
    (xdc_Char)0x3a,  /* [5106] */
    (xdc_Char)0x20,  /* [5107] */
    (xdc_Char)0x73,  /* [5108] */
    (xdc_Char)0x77,  /* [5109] */
    (xdc_Char)0x69,  /* [5110] */
    (xdc_Char)0x3a,  /* [5111] */
    (xdc_Char)0x20,  /* [5112] */
    (xdc_Char)0x30,  /* [5113] */
    (xdc_Char)0x78,  /* [5114] */
    (xdc_Char)0x25,  /* [5115] */
    (xdc_Char)0x78,  /* [5116] */
    (xdc_Char)0x2c,  /* [5117] */
    (xdc_Char)0x20,  /* [5118] */
    (xdc_Char)0x66,  /* [5119] */
    (xdc_Char)0x75,  /* [5120] */
    (xdc_Char)0x6e,  /* [5121] */
    (xdc_Char)0x63,  /* [5122] */
    (xdc_Char)0x3a,  /* [5123] */
    (xdc_Char)0x20,  /* [5124] */
    (xdc_Char)0x30,  /* [5125] */
    (xdc_Char)0x78,  /* [5126] */
    (xdc_Char)0x25,  /* [5127] */
    (xdc_Char)0x78,  /* [5128] */
    (xdc_Char)0x2c,  /* [5129] */
    (xdc_Char)0x20,  /* [5130] */
    (xdc_Char)0x70,  /* [5131] */
    (xdc_Char)0x72,  /* [5132] */
    (xdc_Char)0x69,  /* [5133] */
    (xdc_Char)0x3a,  /* [5134] */
    (xdc_Char)0x20,  /* [5135] */
    (xdc_Char)0x25,  /* [5136] */
    (xdc_Char)0x64,  /* [5137] */
    (xdc_Char)0x0,  /* [5138] */
    (xdc_Char)0x4c,  /* [5139] */
    (xdc_Char)0x4d,  /* [5140] */
    (xdc_Char)0x5f,  /* [5141] */
    (xdc_Char)0x73,  /* [5142] */
    (xdc_Char)0x77,  /* [5143] */
    (xdc_Char)0x69,  /* [5144] */
    (xdc_Char)0x74,  /* [5145] */
    (xdc_Char)0x63,  /* [5146] */
    (xdc_Char)0x68,  /* [5147] */
    (xdc_Char)0x3a,  /* [5148] */
    (xdc_Char)0x20,  /* [5149] */
    (xdc_Char)0x6f,  /* [5150] */
    (xdc_Char)0x6c,  /* [5151] */
    (xdc_Char)0x64,  /* [5152] */
    (xdc_Char)0x74,  /* [5153] */
    (xdc_Char)0x73,  /* [5154] */
    (xdc_Char)0x6b,  /* [5155] */
    (xdc_Char)0x3a,  /* [5156] */
    (xdc_Char)0x20,  /* [5157] */
    (xdc_Char)0x30,  /* [5158] */
    (xdc_Char)0x78,  /* [5159] */
    (xdc_Char)0x25,  /* [5160] */
    (xdc_Char)0x78,  /* [5161] */
    (xdc_Char)0x2c,  /* [5162] */
    (xdc_Char)0x20,  /* [5163] */
    (xdc_Char)0x6f,  /* [5164] */
    (xdc_Char)0x6c,  /* [5165] */
    (xdc_Char)0x64,  /* [5166] */
    (xdc_Char)0x66,  /* [5167] */
    (xdc_Char)0x75,  /* [5168] */
    (xdc_Char)0x6e,  /* [5169] */
    (xdc_Char)0x63,  /* [5170] */
    (xdc_Char)0x3a,  /* [5171] */
    (xdc_Char)0x20,  /* [5172] */
    (xdc_Char)0x30,  /* [5173] */
    (xdc_Char)0x78,  /* [5174] */
    (xdc_Char)0x25,  /* [5175] */
    (xdc_Char)0x78,  /* [5176] */
    (xdc_Char)0x2c,  /* [5177] */
    (xdc_Char)0x20,  /* [5178] */
    (xdc_Char)0x6e,  /* [5179] */
    (xdc_Char)0x65,  /* [5180] */
    (xdc_Char)0x77,  /* [5181] */
    (xdc_Char)0x74,  /* [5182] */
    (xdc_Char)0x73,  /* [5183] */
    (xdc_Char)0x6b,  /* [5184] */
    (xdc_Char)0x3a,  /* [5185] */
    (xdc_Char)0x20,  /* [5186] */
    (xdc_Char)0x30,  /* [5187] */
    (xdc_Char)0x78,  /* [5188] */
    (xdc_Char)0x25,  /* [5189] */
    (xdc_Char)0x78,  /* [5190] */
    (xdc_Char)0x2c,  /* [5191] */
    (xdc_Char)0x20,  /* [5192] */
    (xdc_Char)0x6e,  /* [5193] */
    (xdc_Char)0x65,  /* [5194] */
    (xdc_Char)0x77,  /* [5195] */
    (xdc_Char)0x66,  /* [5196] */
    (xdc_Char)0x75,  /* [5197] */
    (xdc_Char)0x6e,  /* [5198] */
    (xdc_Char)0x63,  /* [5199] */
    (xdc_Char)0x3a,  /* [5200] */
    (xdc_Char)0x20,  /* [5201] */
    (xdc_Char)0x30,  /* [5202] */
    (xdc_Char)0x78,  /* [5203] */
    (xdc_Char)0x25,  /* [5204] */
    (xdc_Char)0x78,  /* [5205] */
    (xdc_Char)0x0,  /* [5206] */
    (xdc_Char)0x4c,  /* [5207] */
    (xdc_Char)0x4d,  /* [5208] */
    (xdc_Char)0x5f,  /* [5209] */
    (xdc_Char)0x73,  /* [5210] */
    (xdc_Char)0x6c,  /* [5211] */
    (xdc_Char)0x65,  /* [5212] */
    (xdc_Char)0x65,  /* [5213] */
    (xdc_Char)0x70,  /* [5214] */
    (xdc_Char)0x3a,  /* [5215] */
    (xdc_Char)0x20,  /* [5216] */
    (xdc_Char)0x74,  /* [5217] */
    (xdc_Char)0x73,  /* [5218] */
    (xdc_Char)0x6b,  /* [5219] */
    (xdc_Char)0x3a,  /* [5220] */
    (xdc_Char)0x20,  /* [5221] */
    (xdc_Char)0x30,  /* [5222] */
    (xdc_Char)0x78,  /* [5223] */
    (xdc_Char)0x25,  /* [5224] */
    (xdc_Char)0x78,  /* [5225] */
    (xdc_Char)0x2c,  /* [5226] */
    (xdc_Char)0x20,  /* [5227] */
    (xdc_Char)0x66,  /* [5228] */
    (xdc_Char)0x75,  /* [5229] */
    (xdc_Char)0x6e,  /* [5230] */
    (xdc_Char)0x63,  /* [5231] */
    (xdc_Char)0x3a,  /* [5232] */
    (xdc_Char)0x20,  /* [5233] */
    (xdc_Char)0x30,  /* [5234] */
    (xdc_Char)0x78,  /* [5235] */
    (xdc_Char)0x25,  /* [5236] */
    (xdc_Char)0x78,  /* [5237] */
    (xdc_Char)0x2c,  /* [5238] */
    (xdc_Char)0x20,  /* [5239] */
    (xdc_Char)0x74,  /* [5240] */
    (xdc_Char)0x69,  /* [5241] */
    (xdc_Char)0x6d,  /* [5242] */
    (xdc_Char)0x65,  /* [5243] */
    (xdc_Char)0x6f,  /* [5244] */
    (xdc_Char)0x75,  /* [5245] */
    (xdc_Char)0x74,  /* [5246] */
    (xdc_Char)0x3a,  /* [5247] */
    (xdc_Char)0x20,  /* [5248] */
    (xdc_Char)0x25,  /* [5249] */
    (xdc_Char)0x64,  /* [5250] */
    (xdc_Char)0x0,  /* [5251] */
    (xdc_Char)0x4c,  /* [5252] */
    (xdc_Char)0x44,  /* [5253] */
    (xdc_Char)0x5f,  /* [5254] */
    (xdc_Char)0x72,  /* [5255] */
    (xdc_Char)0x65,  /* [5256] */
    (xdc_Char)0x61,  /* [5257] */
    (xdc_Char)0x64,  /* [5258] */
    (xdc_Char)0x79,  /* [5259] */
    (xdc_Char)0x3a,  /* [5260] */
    (xdc_Char)0x20,  /* [5261] */
    (xdc_Char)0x74,  /* [5262] */
    (xdc_Char)0x73,  /* [5263] */
    (xdc_Char)0x6b,  /* [5264] */
    (xdc_Char)0x3a,  /* [5265] */
    (xdc_Char)0x20,  /* [5266] */
    (xdc_Char)0x30,  /* [5267] */
    (xdc_Char)0x78,  /* [5268] */
    (xdc_Char)0x25,  /* [5269] */
    (xdc_Char)0x78,  /* [5270] */
    (xdc_Char)0x2c,  /* [5271] */
    (xdc_Char)0x20,  /* [5272] */
    (xdc_Char)0x66,  /* [5273] */
    (xdc_Char)0x75,  /* [5274] */
    (xdc_Char)0x6e,  /* [5275] */
    (xdc_Char)0x63,  /* [5276] */
    (xdc_Char)0x3a,  /* [5277] */
    (xdc_Char)0x20,  /* [5278] */
    (xdc_Char)0x30,  /* [5279] */
    (xdc_Char)0x78,  /* [5280] */
    (xdc_Char)0x25,  /* [5281] */
    (xdc_Char)0x78,  /* [5282] */
    (xdc_Char)0x2c,  /* [5283] */
    (xdc_Char)0x20,  /* [5284] */
    (xdc_Char)0x70,  /* [5285] */
    (xdc_Char)0x72,  /* [5286] */
    (xdc_Char)0x69,  /* [5287] */
    (xdc_Char)0x3a,  /* [5288] */
    (xdc_Char)0x20,  /* [5289] */
    (xdc_Char)0x25,  /* [5290] */
    (xdc_Char)0x64,  /* [5291] */
    (xdc_Char)0x0,  /* [5292] */
    (xdc_Char)0x4c,  /* [5293] */
    (xdc_Char)0x44,  /* [5294] */
    (xdc_Char)0x5f,  /* [5295] */
    (xdc_Char)0x62,  /* [5296] */
    (xdc_Char)0x6c,  /* [5297] */
    (xdc_Char)0x6f,  /* [5298] */
    (xdc_Char)0x63,  /* [5299] */
    (xdc_Char)0x6b,  /* [5300] */
    (xdc_Char)0x3a,  /* [5301] */
    (xdc_Char)0x20,  /* [5302] */
    (xdc_Char)0x74,  /* [5303] */
    (xdc_Char)0x73,  /* [5304] */
    (xdc_Char)0x6b,  /* [5305] */
    (xdc_Char)0x3a,  /* [5306] */
    (xdc_Char)0x20,  /* [5307] */
    (xdc_Char)0x30,  /* [5308] */
    (xdc_Char)0x78,  /* [5309] */
    (xdc_Char)0x25,  /* [5310] */
    (xdc_Char)0x78,  /* [5311] */
    (xdc_Char)0x2c,  /* [5312] */
    (xdc_Char)0x20,  /* [5313] */
    (xdc_Char)0x66,  /* [5314] */
    (xdc_Char)0x75,  /* [5315] */
    (xdc_Char)0x6e,  /* [5316] */
    (xdc_Char)0x63,  /* [5317] */
    (xdc_Char)0x3a,  /* [5318] */
    (xdc_Char)0x20,  /* [5319] */
    (xdc_Char)0x30,  /* [5320] */
    (xdc_Char)0x78,  /* [5321] */
    (xdc_Char)0x25,  /* [5322] */
    (xdc_Char)0x78,  /* [5323] */
    (xdc_Char)0x0,  /* [5324] */
    (xdc_Char)0x4c,  /* [5325] */
    (xdc_Char)0x4d,  /* [5326] */
    (xdc_Char)0x5f,  /* [5327] */
    (xdc_Char)0x79,  /* [5328] */
    (xdc_Char)0x69,  /* [5329] */
    (xdc_Char)0x65,  /* [5330] */
    (xdc_Char)0x6c,  /* [5331] */
    (xdc_Char)0x64,  /* [5332] */
    (xdc_Char)0x3a,  /* [5333] */
    (xdc_Char)0x20,  /* [5334] */
    (xdc_Char)0x74,  /* [5335] */
    (xdc_Char)0x73,  /* [5336] */
    (xdc_Char)0x6b,  /* [5337] */
    (xdc_Char)0x3a,  /* [5338] */
    (xdc_Char)0x20,  /* [5339] */
    (xdc_Char)0x30,  /* [5340] */
    (xdc_Char)0x78,  /* [5341] */
    (xdc_Char)0x25,  /* [5342] */
    (xdc_Char)0x78,  /* [5343] */
    (xdc_Char)0x2c,  /* [5344] */
    (xdc_Char)0x20,  /* [5345] */
    (xdc_Char)0x66,  /* [5346] */
    (xdc_Char)0x75,  /* [5347] */
    (xdc_Char)0x6e,  /* [5348] */
    (xdc_Char)0x63,  /* [5349] */
    (xdc_Char)0x3a,  /* [5350] */
    (xdc_Char)0x20,  /* [5351] */
    (xdc_Char)0x30,  /* [5352] */
    (xdc_Char)0x78,  /* [5353] */
    (xdc_Char)0x25,  /* [5354] */
    (xdc_Char)0x78,  /* [5355] */
    (xdc_Char)0x2c,  /* [5356] */
    (xdc_Char)0x20,  /* [5357] */
    (xdc_Char)0x63,  /* [5358] */
    (xdc_Char)0x75,  /* [5359] */
    (xdc_Char)0x72,  /* [5360] */
    (xdc_Char)0x72,  /* [5361] */
    (xdc_Char)0x54,  /* [5362] */
    (xdc_Char)0x68,  /* [5363] */
    (xdc_Char)0x72,  /* [5364] */
    (xdc_Char)0x65,  /* [5365] */
    (xdc_Char)0x61,  /* [5366] */
    (xdc_Char)0x64,  /* [5367] */
    (xdc_Char)0x3a,  /* [5368] */
    (xdc_Char)0x20,  /* [5369] */
    (xdc_Char)0x25,  /* [5370] */
    (xdc_Char)0x64,  /* [5371] */
    (xdc_Char)0x0,  /* [5372] */
    (xdc_Char)0x4c,  /* [5373] */
    (xdc_Char)0x4d,  /* [5374] */
    (xdc_Char)0x5f,  /* [5375] */
    (xdc_Char)0x73,  /* [5376] */
    (xdc_Char)0x65,  /* [5377] */
    (xdc_Char)0x74,  /* [5378] */
    (xdc_Char)0x50,  /* [5379] */
    (xdc_Char)0x72,  /* [5380] */
    (xdc_Char)0x69,  /* [5381] */
    (xdc_Char)0x3a,  /* [5382] */
    (xdc_Char)0x20,  /* [5383] */
    (xdc_Char)0x74,  /* [5384] */
    (xdc_Char)0x73,  /* [5385] */
    (xdc_Char)0x6b,  /* [5386] */
    (xdc_Char)0x3a,  /* [5387] */
    (xdc_Char)0x20,  /* [5388] */
    (xdc_Char)0x30,  /* [5389] */
    (xdc_Char)0x78,  /* [5390] */
    (xdc_Char)0x25,  /* [5391] */
    (xdc_Char)0x78,  /* [5392] */
    (xdc_Char)0x2c,  /* [5393] */
    (xdc_Char)0x20,  /* [5394] */
    (xdc_Char)0x66,  /* [5395] */
    (xdc_Char)0x75,  /* [5396] */
    (xdc_Char)0x6e,  /* [5397] */
    (xdc_Char)0x63,  /* [5398] */
    (xdc_Char)0x3a,  /* [5399] */
    (xdc_Char)0x20,  /* [5400] */
    (xdc_Char)0x30,  /* [5401] */
    (xdc_Char)0x78,  /* [5402] */
    (xdc_Char)0x25,  /* [5403] */
    (xdc_Char)0x78,  /* [5404] */
    (xdc_Char)0x2c,  /* [5405] */
    (xdc_Char)0x20,  /* [5406] */
    (xdc_Char)0x6f,  /* [5407] */
    (xdc_Char)0x6c,  /* [5408] */
    (xdc_Char)0x64,  /* [5409] */
    (xdc_Char)0x50,  /* [5410] */
    (xdc_Char)0x72,  /* [5411] */
    (xdc_Char)0x69,  /* [5412] */
    (xdc_Char)0x3a,  /* [5413] */
    (xdc_Char)0x20,  /* [5414] */
    (xdc_Char)0x25,  /* [5415] */
    (xdc_Char)0x64,  /* [5416] */
    (xdc_Char)0x2c,  /* [5417] */
    (xdc_Char)0x20,  /* [5418] */
    (xdc_Char)0x6e,  /* [5419] */
    (xdc_Char)0x65,  /* [5420] */
    (xdc_Char)0x77,  /* [5421] */
    (xdc_Char)0x50,  /* [5422] */
    (xdc_Char)0x72,  /* [5423] */
    (xdc_Char)0x69,  /* [5424] */
    (xdc_Char)0x20,  /* [5425] */
    (xdc_Char)0x25,  /* [5426] */
    (xdc_Char)0x64,  /* [5427] */
    (xdc_Char)0x0,  /* [5428] */
    (xdc_Char)0x4c,  /* [5429] */
    (xdc_Char)0x44,  /* [5430] */
    (xdc_Char)0x5f,  /* [5431] */
    (xdc_Char)0x65,  /* [5432] */
    (xdc_Char)0x78,  /* [5433] */
    (xdc_Char)0x69,  /* [5434] */
    (xdc_Char)0x74,  /* [5435] */
    (xdc_Char)0x3a,  /* [5436] */
    (xdc_Char)0x20,  /* [5437] */
    (xdc_Char)0x74,  /* [5438] */
    (xdc_Char)0x73,  /* [5439] */
    (xdc_Char)0x6b,  /* [5440] */
    (xdc_Char)0x3a,  /* [5441] */
    (xdc_Char)0x20,  /* [5442] */
    (xdc_Char)0x30,  /* [5443] */
    (xdc_Char)0x78,  /* [5444] */
    (xdc_Char)0x25,  /* [5445] */
    (xdc_Char)0x78,  /* [5446] */
    (xdc_Char)0x2c,  /* [5447] */
    (xdc_Char)0x20,  /* [5448] */
    (xdc_Char)0x66,  /* [5449] */
    (xdc_Char)0x75,  /* [5450] */
    (xdc_Char)0x6e,  /* [5451] */
    (xdc_Char)0x63,  /* [5452] */
    (xdc_Char)0x3a,  /* [5453] */
    (xdc_Char)0x20,  /* [5454] */
    (xdc_Char)0x30,  /* [5455] */
    (xdc_Char)0x78,  /* [5456] */
    (xdc_Char)0x25,  /* [5457] */
    (xdc_Char)0x78,  /* [5458] */
    (xdc_Char)0x0,  /* [5459] */
    (xdc_Char)0x4c,  /* [5460] */
    (xdc_Char)0x4d,  /* [5461] */
    (xdc_Char)0x5f,  /* [5462] */
    (xdc_Char)0x73,  /* [5463] */
    (xdc_Char)0x65,  /* [5464] */
    (xdc_Char)0x74,  /* [5465] */
    (xdc_Char)0x41,  /* [5466] */
    (xdc_Char)0x66,  /* [5467] */
    (xdc_Char)0x66,  /* [5468] */
    (xdc_Char)0x69,  /* [5469] */
    (xdc_Char)0x6e,  /* [5470] */
    (xdc_Char)0x69,  /* [5471] */
    (xdc_Char)0x74,  /* [5472] */
    (xdc_Char)0x79,  /* [5473] */
    (xdc_Char)0x3a,  /* [5474] */
    (xdc_Char)0x20,  /* [5475] */
    (xdc_Char)0x74,  /* [5476] */
    (xdc_Char)0x73,  /* [5477] */
    (xdc_Char)0x6b,  /* [5478] */
    (xdc_Char)0x3a,  /* [5479] */
    (xdc_Char)0x20,  /* [5480] */
    (xdc_Char)0x30,  /* [5481] */
    (xdc_Char)0x78,  /* [5482] */
    (xdc_Char)0x25,  /* [5483] */
    (xdc_Char)0x78,  /* [5484] */
    (xdc_Char)0x2c,  /* [5485] */
    (xdc_Char)0x20,  /* [5486] */
    (xdc_Char)0x66,  /* [5487] */
    (xdc_Char)0x75,  /* [5488] */
    (xdc_Char)0x6e,  /* [5489] */
    (xdc_Char)0x63,  /* [5490] */
    (xdc_Char)0x3a,  /* [5491] */
    (xdc_Char)0x20,  /* [5492] */
    (xdc_Char)0x30,  /* [5493] */
    (xdc_Char)0x78,  /* [5494] */
    (xdc_Char)0x25,  /* [5495] */
    (xdc_Char)0x78,  /* [5496] */
    (xdc_Char)0x2c,  /* [5497] */
    (xdc_Char)0x20,  /* [5498] */
    (xdc_Char)0x6f,  /* [5499] */
    (xdc_Char)0x6c,  /* [5500] */
    (xdc_Char)0x64,  /* [5501] */
    (xdc_Char)0x43,  /* [5502] */
    (xdc_Char)0x6f,  /* [5503] */
    (xdc_Char)0x72,  /* [5504] */
    (xdc_Char)0x65,  /* [5505] */
    (xdc_Char)0x3a,  /* [5506] */
    (xdc_Char)0x20,  /* [5507] */
    (xdc_Char)0x25,  /* [5508] */
    (xdc_Char)0x64,  /* [5509] */
    (xdc_Char)0x2c,  /* [5510] */
    (xdc_Char)0x20,  /* [5511] */
    (xdc_Char)0x6f,  /* [5512] */
    (xdc_Char)0x6c,  /* [5513] */
    (xdc_Char)0x64,  /* [5514] */
    (xdc_Char)0x41,  /* [5515] */
    (xdc_Char)0x66,  /* [5516] */
    (xdc_Char)0x66,  /* [5517] */
    (xdc_Char)0x69,  /* [5518] */
    (xdc_Char)0x6e,  /* [5519] */
    (xdc_Char)0x69,  /* [5520] */
    (xdc_Char)0x74,  /* [5521] */
    (xdc_Char)0x79,  /* [5522] */
    (xdc_Char)0x20,  /* [5523] */
    (xdc_Char)0x25,  /* [5524] */
    (xdc_Char)0x64,  /* [5525] */
    (xdc_Char)0x2c,  /* [5526] */
    (xdc_Char)0x20,  /* [5527] */
    (xdc_Char)0x6e,  /* [5528] */
    (xdc_Char)0x65,  /* [5529] */
    (xdc_Char)0x77,  /* [5530] */
    (xdc_Char)0x41,  /* [5531] */
    (xdc_Char)0x66,  /* [5532] */
    (xdc_Char)0x66,  /* [5533] */
    (xdc_Char)0x69,  /* [5534] */
    (xdc_Char)0x6e,  /* [5535] */
    (xdc_Char)0x69,  /* [5536] */
    (xdc_Char)0x74,  /* [5537] */
    (xdc_Char)0x79,  /* [5538] */
    (xdc_Char)0x20,  /* [5539] */
    (xdc_Char)0x25,  /* [5540] */
    (xdc_Char)0x64,  /* [5541] */
    (xdc_Char)0x0,  /* [5542] */
    (xdc_Char)0x4c,  /* [5543] */
    (xdc_Char)0x44,  /* [5544] */
    (xdc_Char)0x5f,  /* [5545] */
    (xdc_Char)0x73,  /* [5546] */
    (xdc_Char)0x63,  /* [5547] */
    (xdc_Char)0x68,  /* [5548] */
    (xdc_Char)0x65,  /* [5549] */
    (xdc_Char)0x64,  /* [5550] */
    (xdc_Char)0x75,  /* [5551] */
    (xdc_Char)0x6c,  /* [5552] */
    (xdc_Char)0x65,  /* [5553] */
    (xdc_Char)0x3a,  /* [5554] */
    (xdc_Char)0x20,  /* [5555] */
    (xdc_Char)0x63,  /* [5556] */
    (xdc_Char)0x6f,  /* [5557] */
    (xdc_Char)0x72,  /* [5558] */
    (xdc_Char)0x65,  /* [5559] */
    (xdc_Char)0x49,  /* [5560] */
    (xdc_Char)0x64,  /* [5561] */
    (xdc_Char)0x3a,  /* [5562] */
    (xdc_Char)0x20,  /* [5563] */
    (xdc_Char)0x25,  /* [5564] */
    (xdc_Char)0x64,  /* [5565] */
    (xdc_Char)0x2c,  /* [5566] */
    (xdc_Char)0x20,  /* [5567] */
    (xdc_Char)0x77,  /* [5568] */
    (xdc_Char)0x6f,  /* [5569] */
    (xdc_Char)0x72,  /* [5570] */
    (xdc_Char)0x6b,  /* [5571] */
    (xdc_Char)0x46,  /* [5572] */
    (xdc_Char)0x6c,  /* [5573] */
    (xdc_Char)0x61,  /* [5574] */
    (xdc_Char)0x67,  /* [5575] */
    (xdc_Char)0x3a,  /* [5576] */
    (xdc_Char)0x20,  /* [5577] */
    (xdc_Char)0x25,  /* [5578] */
    (xdc_Char)0x64,  /* [5579] */
    (xdc_Char)0x2c,  /* [5580] */
    (xdc_Char)0x20,  /* [5581] */
    (xdc_Char)0x63,  /* [5582] */
    (xdc_Char)0x75,  /* [5583] */
    (xdc_Char)0x72,  /* [5584] */
    (xdc_Char)0x53,  /* [5585] */
    (xdc_Char)0x65,  /* [5586] */
    (xdc_Char)0x74,  /* [5587] */
    (xdc_Char)0x4c,  /* [5588] */
    (xdc_Char)0x6f,  /* [5589] */
    (xdc_Char)0x63,  /* [5590] */
    (xdc_Char)0x61,  /* [5591] */
    (xdc_Char)0x6c,  /* [5592] */
    (xdc_Char)0x3a,  /* [5593] */
    (xdc_Char)0x20,  /* [5594] */
    (xdc_Char)0x25,  /* [5595] */
    (xdc_Char)0x64,  /* [5596] */
    (xdc_Char)0x2c,  /* [5597] */
    (xdc_Char)0x20,  /* [5598] */
    (xdc_Char)0x63,  /* [5599] */
    (xdc_Char)0x75,  /* [5600] */
    (xdc_Char)0x72,  /* [5601] */
    (xdc_Char)0x53,  /* [5602] */
    (xdc_Char)0x65,  /* [5603] */
    (xdc_Char)0x74,  /* [5604] */
    (xdc_Char)0x58,  /* [5605] */
    (xdc_Char)0x3a,  /* [5606] */
    (xdc_Char)0x20,  /* [5607] */
    (xdc_Char)0x25,  /* [5608] */
    (xdc_Char)0x64,  /* [5609] */
    (xdc_Char)0x2c,  /* [5610] */
    (xdc_Char)0x20,  /* [5611] */
    (xdc_Char)0x63,  /* [5612] */
    (xdc_Char)0x75,  /* [5613] */
    (xdc_Char)0x72,  /* [5614] */
    (xdc_Char)0x4d,  /* [5615] */
    (xdc_Char)0x61,  /* [5616] */
    (xdc_Char)0x73,  /* [5617] */
    (xdc_Char)0x6b,  /* [5618] */
    (xdc_Char)0x4c,  /* [5619] */
    (xdc_Char)0x6f,  /* [5620] */
    (xdc_Char)0x63,  /* [5621] */
    (xdc_Char)0x61,  /* [5622] */
    (xdc_Char)0x6c,  /* [5623] */
    (xdc_Char)0x3a,  /* [5624] */
    (xdc_Char)0x20,  /* [5625] */
    (xdc_Char)0x25,  /* [5626] */
    (xdc_Char)0x64,  /* [5627] */
    (xdc_Char)0x0,  /* [5628] */
    (xdc_Char)0x4c,  /* [5629] */
    (xdc_Char)0x44,  /* [5630] */
    (xdc_Char)0x5f,  /* [5631] */
    (xdc_Char)0x6e,  /* [5632] */
    (xdc_Char)0x6f,  /* [5633] */
    (xdc_Char)0x57,  /* [5634] */
    (xdc_Char)0x6f,  /* [5635] */
    (xdc_Char)0x72,  /* [5636] */
    (xdc_Char)0x6b,  /* [5637] */
    (xdc_Char)0x3a,  /* [5638] */
    (xdc_Char)0x20,  /* [5639] */
    (xdc_Char)0x63,  /* [5640] */
    (xdc_Char)0x6f,  /* [5641] */
    (xdc_Char)0x72,  /* [5642] */
    (xdc_Char)0x65,  /* [5643] */
    (xdc_Char)0x49,  /* [5644] */
    (xdc_Char)0x64,  /* [5645] */
    (xdc_Char)0x3a,  /* [5646] */
    (xdc_Char)0x20,  /* [5647] */
    (xdc_Char)0x25,  /* [5648] */
    (xdc_Char)0x64,  /* [5649] */
    (xdc_Char)0x2c,  /* [5650] */
    (xdc_Char)0x20,  /* [5651] */
    (xdc_Char)0x63,  /* [5652] */
    (xdc_Char)0x75,  /* [5653] */
    (xdc_Char)0x72,  /* [5654] */
    (xdc_Char)0x53,  /* [5655] */
    (xdc_Char)0x65,  /* [5656] */
    (xdc_Char)0x74,  /* [5657] */
    (xdc_Char)0x4c,  /* [5658] */
    (xdc_Char)0x6f,  /* [5659] */
    (xdc_Char)0x63,  /* [5660] */
    (xdc_Char)0x61,  /* [5661] */
    (xdc_Char)0x6c,  /* [5662] */
    (xdc_Char)0x3a,  /* [5663] */
    (xdc_Char)0x20,  /* [5664] */
    (xdc_Char)0x25,  /* [5665] */
    (xdc_Char)0x64,  /* [5666] */
    (xdc_Char)0x2c,  /* [5667] */
    (xdc_Char)0x20,  /* [5668] */
    (xdc_Char)0x63,  /* [5669] */
    (xdc_Char)0x75,  /* [5670] */
    (xdc_Char)0x72,  /* [5671] */
    (xdc_Char)0x53,  /* [5672] */
    (xdc_Char)0x65,  /* [5673] */
    (xdc_Char)0x74,  /* [5674] */
    (xdc_Char)0x58,  /* [5675] */
    (xdc_Char)0x3a,  /* [5676] */
    (xdc_Char)0x20,  /* [5677] */
    (xdc_Char)0x25,  /* [5678] */
    (xdc_Char)0x64,  /* [5679] */
    (xdc_Char)0x2c,  /* [5680] */
    (xdc_Char)0x20,  /* [5681] */
    (xdc_Char)0x63,  /* [5682] */
    (xdc_Char)0x75,  /* [5683] */
    (xdc_Char)0x72,  /* [5684] */
    (xdc_Char)0x4d,  /* [5685] */
    (xdc_Char)0x61,  /* [5686] */
    (xdc_Char)0x73,  /* [5687] */
    (xdc_Char)0x6b,  /* [5688] */
    (xdc_Char)0x4c,  /* [5689] */
    (xdc_Char)0x6f,  /* [5690] */
    (xdc_Char)0x63,  /* [5691] */
    (xdc_Char)0x61,  /* [5692] */
    (xdc_Char)0x6c,  /* [5693] */
    (xdc_Char)0x3a,  /* [5694] */
    (xdc_Char)0x20,  /* [5695] */
    (xdc_Char)0x25,  /* [5696] */
    (xdc_Char)0x64,  /* [5697] */
    (xdc_Char)0x0,  /* [5698] */
    (xdc_Char)0x78,  /* [5699] */
    (xdc_Char)0x64,  /* [5700] */
    (xdc_Char)0x63,  /* [5701] */
    (xdc_Char)0x2e,  /* [5702] */
    (xdc_Char)0x0,  /* [5703] */
    (xdc_Char)0x72,  /* [5704] */
    (xdc_Char)0x75,  /* [5705] */
    (xdc_Char)0x6e,  /* [5706] */
    (xdc_Char)0x74,  /* [5707] */
    (xdc_Char)0x69,  /* [5708] */
    (xdc_Char)0x6d,  /* [5709] */
    (xdc_Char)0x65,  /* [5710] */
    (xdc_Char)0x2e,  /* [5711] */
    (xdc_Char)0x0,  /* [5712] */
    (xdc_Char)0x41,  /* [5713] */
    (xdc_Char)0x73,  /* [5714] */
    (xdc_Char)0x73,  /* [5715] */
    (xdc_Char)0x65,  /* [5716] */
    (xdc_Char)0x72,  /* [5717] */
    (xdc_Char)0x74,  /* [5718] */
    (xdc_Char)0x0,  /* [5719] */
    (xdc_Char)0x43,  /* [5720] */
    (xdc_Char)0x6f,  /* [5721] */
    (xdc_Char)0x72,  /* [5722] */
    (xdc_Char)0x65,  /* [5723] */
    (xdc_Char)0x0,  /* [5724] */
    (xdc_Char)0x44,  /* [5725] */
    (xdc_Char)0x65,  /* [5726] */
    (xdc_Char)0x66,  /* [5727] */
    (xdc_Char)0x61,  /* [5728] */
    (xdc_Char)0x75,  /* [5729] */
    (xdc_Char)0x6c,  /* [5730] */
    (xdc_Char)0x74,  /* [5731] */
    (xdc_Char)0x73,  /* [5732] */
    (xdc_Char)0x0,  /* [5733] */
    (xdc_Char)0x44,  /* [5734] */
    (xdc_Char)0x69,  /* [5735] */
    (xdc_Char)0x61,  /* [5736] */
    (xdc_Char)0x67,  /* [5737] */
    (xdc_Char)0x73,  /* [5738] */
    (xdc_Char)0x0,  /* [5739] */
    (xdc_Char)0x45,  /* [5740] */
    (xdc_Char)0x72,  /* [5741] */
    (xdc_Char)0x72,  /* [5742] */
    (xdc_Char)0x6f,  /* [5743] */
    (xdc_Char)0x72,  /* [5744] */
    (xdc_Char)0x0,  /* [5745] */
    (xdc_Char)0x47,  /* [5746] */
    (xdc_Char)0x61,  /* [5747] */
    (xdc_Char)0x74,  /* [5748] */
    (xdc_Char)0x65,  /* [5749] */
    (xdc_Char)0x0,  /* [5750] */
    (xdc_Char)0x4c,  /* [5751] */
    (xdc_Char)0x6f,  /* [5752] */
    (xdc_Char)0x67,  /* [5753] */
    (xdc_Char)0x0,  /* [5754] */
    (xdc_Char)0x4c,  /* [5755] */
    (xdc_Char)0x6f,  /* [5756] */
    (xdc_Char)0x67,  /* [5757] */
    (xdc_Char)0x67,  /* [5758] */
    (xdc_Char)0x65,  /* [5759] */
    (xdc_Char)0x72,  /* [5760] */
    (xdc_Char)0x42,  /* [5761] */
    (xdc_Char)0x75,  /* [5762] */
    (xdc_Char)0x66,  /* [5763] */
    (xdc_Char)0x0,  /* [5764] */
    (xdc_Char)0x4d,  /* [5765] */
    (xdc_Char)0x61,  /* [5766] */
    (xdc_Char)0x69,  /* [5767] */
    (xdc_Char)0x6e,  /* [5768] */
    (xdc_Char)0x0,  /* [5769] */
    (xdc_Char)0x4d,  /* [5770] */
    (xdc_Char)0x65,  /* [5771] */
    (xdc_Char)0x6d,  /* [5772] */
    (xdc_Char)0x6f,  /* [5773] */
    (xdc_Char)0x72,  /* [5774] */
    (xdc_Char)0x79,  /* [5775] */
    (xdc_Char)0x0,  /* [5776] */
    (xdc_Char)0x52,  /* [5777] */
    (xdc_Char)0x65,  /* [5778] */
    (xdc_Char)0x67,  /* [5779] */
    (xdc_Char)0x69,  /* [5780] */
    (xdc_Char)0x73,  /* [5781] */
    (xdc_Char)0x74,  /* [5782] */
    (xdc_Char)0x72,  /* [5783] */
    (xdc_Char)0x79,  /* [5784] */
    (xdc_Char)0x0,  /* [5785] */
    (xdc_Char)0x53,  /* [5786] */
    (xdc_Char)0x74,  /* [5787] */
    (xdc_Char)0x61,  /* [5788] */
    (xdc_Char)0x72,  /* [5789] */
    (xdc_Char)0x74,  /* [5790] */
    (xdc_Char)0x75,  /* [5791] */
    (xdc_Char)0x70,  /* [5792] */
    (xdc_Char)0x0,  /* [5793] */
    (xdc_Char)0x53,  /* [5794] */
    (xdc_Char)0x79,  /* [5795] */
    (xdc_Char)0x73,  /* [5796] */
    (xdc_Char)0x74,  /* [5797] */
    (xdc_Char)0x65,  /* [5798] */
    (xdc_Char)0x6d,  /* [5799] */
    (xdc_Char)0x0,  /* [5800] */
    (xdc_Char)0x53,  /* [5801] */
    (xdc_Char)0x79,  /* [5802] */
    (xdc_Char)0x73,  /* [5803] */
    (xdc_Char)0x4d,  /* [5804] */
    (xdc_Char)0x69,  /* [5805] */
    (xdc_Char)0x6e,  /* [5806] */
    (xdc_Char)0x0,  /* [5807] */
    (xdc_Char)0x54,  /* [5808] */
    (xdc_Char)0x65,  /* [5809] */
    (xdc_Char)0x78,  /* [5810] */
    (xdc_Char)0x74,  /* [5811] */
    (xdc_Char)0x0,  /* [5812] */
    (xdc_Char)0x54,  /* [5813] */
    (xdc_Char)0x79,  /* [5814] */
    (xdc_Char)0x70,  /* [5815] */
    (xdc_Char)0x65,  /* [5816] */
    (xdc_Char)0x73,  /* [5817] */
    (xdc_Char)0x0,  /* [5818] */
    (xdc_Char)0x74,  /* [5819] */
    (xdc_Char)0x69,  /* [5820] */
    (xdc_Char)0x2e,  /* [5821] */
    (xdc_Char)0x0,  /* [5822] */
    (xdc_Char)0x73,  /* [5823] */
    (xdc_Char)0x79,  /* [5824] */
    (xdc_Char)0x73,  /* [5825] */
    (xdc_Char)0x62,  /* [5826] */
    (xdc_Char)0x69,  /* [5827] */
    (xdc_Char)0x6f,  /* [5828] */
    (xdc_Char)0x73,  /* [5829] */
    (xdc_Char)0x2e,  /* [5830] */
    (xdc_Char)0x0,  /* [5831] */
    (xdc_Char)0x66,  /* [5832] */
    (xdc_Char)0x61,  /* [5833] */
    (xdc_Char)0x6d,  /* [5834] */
    (xdc_Char)0x69,  /* [5835] */
    (xdc_Char)0x6c,  /* [5836] */
    (xdc_Char)0x79,  /* [5837] */
    (xdc_Char)0x2e,  /* [5838] */
    (xdc_Char)0x0,  /* [5839] */
    (xdc_Char)0x63,  /* [5840] */
    (xdc_Char)0x32,  /* [5841] */
    (xdc_Char)0x38,  /* [5842] */
    (xdc_Char)0x2e,  /* [5843] */
    (xdc_Char)0x0,  /* [5844] */
    (xdc_Char)0x48,  /* [5845] */
    (xdc_Char)0x77,  /* [5846] */
    (xdc_Char)0x69,  /* [5847] */
    (xdc_Char)0x0,  /* [5848] */
    (xdc_Char)0x54,  /* [5849] */
    (xdc_Char)0x69,  /* [5850] */
    (xdc_Char)0x6d,  /* [5851] */
    (xdc_Char)0x65,  /* [5852] */
    (xdc_Char)0x72,  /* [5853] */
    (xdc_Char)0x0,  /* [5854] */
    (xdc_Char)0x49,  /* [5855] */
    (xdc_Char)0x6e,  /* [5856] */
    (xdc_Char)0x74,  /* [5857] */
    (xdc_Char)0x72,  /* [5858] */
    (xdc_Char)0x69,  /* [5859] */
    (xdc_Char)0x6e,  /* [5860] */
    (xdc_Char)0x73,  /* [5861] */
    (xdc_Char)0x69,  /* [5862] */
    (xdc_Char)0x63,  /* [5863] */
    (xdc_Char)0x73,  /* [5864] */
    (xdc_Char)0x53,  /* [5865] */
    (xdc_Char)0x75,  /* [5866] */
    (xdc_Char)0x70,  /* [5867] */
    (xdc_Char)0x70,  /* [5868] */
    (xdc_Char)0x6f,  /* [5869] */
    (xdc_Char)0x72,  /* [5870] */
    (xdc_Char)0x74,  /* [5871] */
    (xdc_Char)0x0,  /* [5872] */
    (xdc_Char)0x54,  /* [5873] */
    (xdc_Char)0x61,  /* [5874] */
    (xdc_Char)0x73,  /* [5875] */
    (xdc_Char)0x6b,  /* [5876] */
    (xdc_Char)0x53,  /* [5877] */
    (xdc_Char)0x75,  /* [5878] */
    (xdc_Char)0x70,  /* [5879] */
    (xdc_Char)0x70,  /* [5880] */
    (xdc_Char)0x6f,  /* [5881] */
    (xdc_Char)0x72,  /* [5882] */
    (xdc_Char)0x74,  /* [5883] */
    (xdc_Char)0x0,  /* [5884] */
    (xdc_Char)0x42,  /* [5885] */
    (xdc_Char)0x49,  /* [5886] */
    (xdc_Char)0x4f,  /* [5887] */
    (xdc_Char)0x53,  /* [5888] */
    (xdc_Char)0x0,  /* [5889] */
    (xdc_Char)0x6b,  /* [5890] */
    (xdc_Char)0x6e,  /* [5891] */
    (xdc_Char)0x6c,  /* [5892] */
    (xdc_Char)0x2e,  /* [5893] */
    (xdc_Char)0x0,  /* [5894] */
    (xdc_Char)0x43,  /* [5895] */
    (xdc_Char)0x6c,  /* [5896] */
    (xdc_Char)0x6f,  /* [5897] */
    (xdc_Char)0x63,  /* [5898] */
    (xdc_Char)0x6b,  /* [5899] */
    (xdc_Char)0x0,  /* [5900] */
    (xdc_Char)0x49,  /* [5901] */
    (xdc_Char)0x64,  /* [5902] */
    (xdc_Char)0x6c,  /* [5903] */
    (xdc_Char)0x65,  /* [5904] */
    (xdc_Char)0x0,  /* [5905] */
    (xdc_Char)0x49,  /* [5906] */
    (xdc_Char)0x6e,  /* [5907] */
    (xdc_Char)0x74,  /* [5908] */
    (xdc_Char)0x72,  /* [5909] */
    (xdc_Char)0x69,  /* [5910] */
    (xdc_Char)0x6e,  /* [5911] */
    (xdc_Char)0x73,  /* [5912] */
    (xdc_Char)0x69,  /* [5913] */
    (xdc_Char)0x63,  /* [5914] */
    (xdc_Char)0x73,  /* [5915] */
    (xdc_Char)0x0,  /* [5916] */
    (xdc_Char)0x51,  /* [5917] */
    (xdc_Char)0x75,  /* [5918] */
    (xdc_Char)0x65,  /* [5919] */
    (xdc_Char)0x75,  /* [5920] */
    (xdc_Char)0x65,  /* [5921] */
    (xdc_Char)0x0,  /* [5922] */
    (xdc_Char)0x53,  /* [5923] */
    (xdc_Char)0x65,  /* [5924] */
    (xdc_Char)0x6d,  /* [5925] */
    (xdc_Char)0x61,  /* [5926] */
    (xdc_Char)0x70,  /* [5927] */
    (xdc_Char)0x68,  /* [5928] */
    (xdc_Char)0x6f,  /* [5929] */
    (xdc_Char)0x72,  /* [5930] */
    (xdc_Char)0x65,  /* [5931] */
    (xdc_Char)0x0,  /* [5932] */
    (xdc_Char)0x53,  /* [5933] */
    (xdc_Char)0x77,  /* [5934] */
    (xdc_Char)0x69,  /* [5935] */
    (xdc_Char)0x0,  /* [5936] */
    (xdc_Char)0x54,  /* [5937] */
    (xdc_Char)0x61,  /* [5938] */
    (xdc_Char)0x73,  /* [5939] */
    (xdc_Char)0x6b,  /* [5940] */
    (xdc_Char)0x0,  /* [5941] */
    (xdc_Char)0x67,  /* [5942] */
    (xdc_Char)0x61,  /* [5943] */
    (xdc_Char)0x74,  /* [5944] */
    (xdc_Char)0x65,  /* [5945] */
    (xdc_Char)0x73,  /* [5946] */
    (xdc_Char)0x2e,  /* [5947] */
    (xdc_Char)0x0,  /* [5948] */
    (xdc_Char)0x47,  /* [5949] */
    (xdc_Char)0x61,  /* [5950] */
    (xdc_Char)0x74,  /* [5951] */
    (xdc_Char)0x65,  /* [5952] */
    (xdc_Char)0x48,  /* [5953] */
    (xdc_Char)0x77,  /* [5954] */
    (xdc_Char)0x69,  /* [5955] */
    (xdc_Char)0x0,  /* [5956] */
    (xdc_Char)0x47,  /* [5957] */
    (xdc_Char)0x61,  /* [5958] */
    (xdc_Char)0x74,  /* [5959] */
    (xdc_Char)0x65,  /* [5960] */
    (xdc_Char)0x4d,  /* [5961] */
    (xdc_Char)0x75,  /* [5962] */
    (xdc_Char)0x74,  /* [5963] */
    (xdc_Char)0x65,  /* [5964] */
    (xdc_Char)0x78,  /* [5965] */
    (xdc_Char)0x0,  /* [5966] */
    (xdc_Char)0x68,  /* [5967] */
    (xdc_Char)0x61,  /* [5968] */
    (xdc_Char)0x6c,  /* [5969] */
    (xdc_Char)0x2e,  /* [5970] */
    (xdc_Char)0x0,  /* [5971] */
    (xdc_Char)0x68,  /* [5972] */
    (xdc_Char)0x65,  /* [5973] */
    (xdc_Char)0x61,  /* [5974] */
    (xdc_Char)0x70,  /* [5975] */
    (xdc_Char)0x73,  /* [5976] */
    (xdc_Char)0x2e,  /* [5977] */
    (xdc_Char)0x0,  /* [5978] */
    (xdc_Char)0x48,  /* [5979] */
    (xdc_Char)0x65,  /* [5980] */
    (xdc_Char)0x61,  /* [5981] */
    (xdc_Char)0x70,  /* [5982] */
    (xdc_Char)0x4d,  /* [5983] */
    (xdc_Char)0x65,  /* [5984] */
    (xdc_Char)0x6d,  /* [5985] */
    (xdc_Char)0x0,  /* [5986] */
    (xdc_Char)0x66,  /* [5987] */
    (xdc_Char)0x32,  /* [5988] */
    (xdc_Char)0x38,  /* [5989] */
    (xdc_Char)0x33,  /* [5990] */
    (xdc_Char)0x37,  /* [5991] */
    (xdc_Char)0x78,  /* [5992] */
    (xdc_Char)0x2e,  /* [5993] */
    (xdc_Char)0x0,  /* [5994] */
    (xdc_Char)0x54,  /* [5995] */
    (xdc_Char)0x69,  /* [5996] */
    (xdc_Char)0x6d,  /* [5997] */
    (xdc_Char)0x65,  /* [5998] */
    (xdc_Char)0x73,  /* [5999] */
    (xdc_Char)0x74,  /* [6000] */
    (xdc_Char)0x61,  /* [6001] */
    (xdc_Char)0x6d,  /* [6002] */
    (xdc_Char)0x70,  /* [6003] */
    (xdc_Char)0x50,  /* [6004] */
    (xdc_Char)0x72,  /* [6005] */
    (xdc_Char)0x6f,  /* [6006] */
    (xdc_Char)0x76,  /* [6007] */
    (xdc_Char)0x69,  /* [6008] */
    (xdc_Char)0x64,  /* [6009] */
    (xdc_Char)0x65,  /* [6010] */
    (xdc_Char)0x72,  /* [6011] */
    (xdc_Char)0x0,  /* [6012] */
    (xdc_Char)0x43,  /* [6013] */
    (xdc_Char)0x4c,  /* [6014] */
    (xdc_Char)0x4b,  /* [6015] */
    (xdc_Char)0x5f,  /* [6016] */
    (xdc_Char)0x4f,  /* [6017] */
    (xdc_Char)0x6e,  /* [6018] */
    (xdc_Char)0x65,  /* [6019] */
    (xdc_Char)0x53,  /* [6020] */
    (xdc_Char)0x65,  /* [6021] */
    (xdc_Char)0x63,  /* [6022] */
    (xdc_Char)0x6f,  /* [6023] */
    (xdc_Char)0x6e,  /* [6024] */
    (xdc_Char)0x64,  /* [6025] */
    (xdc_Char)0x0,  /* [6026] */
    (xdc_Char)0x74,  /* [6027] */
    (xdc_Char)0x69,  /* [6028] */
    (xdc_Char)0x2e,  /* [6029] */
    (xdc_Char)0x73,  /* [6030] */
    (xdc_Char)0x79,  /* [6031] */
    (xdc_Char)0x73,  /* [6032] */
    (xdc_Char)0x62,  /* [6033] */
    (xdc_Char)0x69,  /* [6034] */
    (xdc_Char)0x6f,  /* [6035] */
    (xdc_Char)0x73,  /* [6036] */
    (xdc_Char)0x2e,  /* [6037] */
    (xdc_Char)0x6b,  /* [6038] */
    (xdc_Char)0x6e,  /* [6039] */
    (xdc_Char)0x6c,  /* [6040] */
    (xdc_Char)0x2e,  /* [6041] */
    (xdc_Char)0x54,  /* [6042] */
    (xdc_Char)0x61,  /* [6043] */
    (xdc_Char)0x73,  /* [6044] */
    (xdc_Char)0x6b,  /* [6045] */
    (xdc_Char)0x2e,  /* [6046] */
    (xdc_Char)0x49,  /* [6047] */
    (xdc_Char)0x64,  /* [6048] */
    (xdc_Char)0x6c,  /* [6049] */
    (xdc_Char)0x65,  /* [6050] */
    (xdc_Char)0x54,  /* [6051] */
    (xdc_Char)0x61,  /* [6052] */
    (xdc_Char)0x73,  /* [6053] */
    (xdc_Char)0x6b,  /* [6054] */
    (xdc_Char)0x0,  /* [6055] */
};

/* --> xdc_runtime_Text_nodeTab__A */
#pragma DATA_SECTION(xdc_runtime_Text_nodeTab__A, ".econst:xdc_runtime_Text_nodeTab__A");
asm("	.sect \".econst:xdc_runtime_Text_nodeTab__A\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Text_nodeTab__A\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Text_nodeTab__A\"");
asm("	.clink ");

const __T1_xdc_runtime_Text_nodeTab xdc_runtime_Text_nodeTab__A[43] = {
    {
        (xdc_Bits16)0x0,  /* left */
        (xdc_Bits16)0x0,  /* right */
    },  /* [0] */
    {
        (xdc_Bits16)0x1643,  /* left */
        (xdc_Bits16)0x1648,  /* right */
    },  /* [1] */
    {
        (xdc_Bits16)0x8001,  /* left */
        (xdc_Bits16)0x1651,  /* right */
    },  /* [2] */
    {
        (xdc_Bits16)0x8001,  /* left */
        (xdc_Bits16)0x1658,  /* right */
    },  /* [3] */
    {
        (xdc_Bits16)0x8001,  /* left */
        (xdc_Bits16)0x165d,  /* right */
    },  /* [4] */
    {
        (xdc_Bits16)0x8001,  /* left */
        (xdc_Bits16)0x1666,  /* right */
    },  /* [5] */
    {
        (xdc_Bits16)0x8001,  /* left */
        (xdc_Bits16)0x166c,  /* right */
    },  /* [6] */
    {
        (xdc_Bits16)0x8001,  /* left */
        (xdc_Bits16)0x1672,  /* right */
    },  /* [7] */
    {
        (xdc_Bits16)0x8001,  /* left */
        (xdc_Bits16)0x1677,  /* right */
    },  /* [8] */
    {
        (xdc_Bits16)0x8001,  /* left */
        (xdc_Bits16)0x167b,  /* right */
    },  /* [9] */
    {
        (xdc_Bits16)0x8001,  /* left */
        (xdc_Bits16)0x1685,  /* right */
    },  /* [10] */
    {
        (xdc_Bits16)0x8001,  /* left */
        (xdc_Bits16)0x168a,  /* right */
    },  /* [11] */
    {
        (xdc_Bits16)0x8001,  /* left */
        (xdc_Bits16)0x1691,  /* right */
    },  /* [12] */
    {
        (xdc_Bits16)0x8001,  /* left */
        (xdc_Bits16)0x169a,  /* right */
    },  /* [13] */
    {
        (xdc_Bits16)0x8001,  /* left */
        (xdc_Bits16)0x16a2,  /* right */
    },  /* [14] */
    {
        (xdc_Bits16)0x8001,  /* left */
        (xdc_Bits16)0x16a9,  /* right */
    },  /* [15] */
    {
        (xdc_Bits16)0x8001,  /* left */
        (xdc_Bits16)0x16b0,  /* right */
    },  /* [16] */
    {
        (xdc_Bits16)0x8001,  /* left */
        (xdc_Bits16)0x16b5,  /* right */
    },  /* [17] */
    {
        (xdc_Bits16)0x16bb,  /* left */
        (xdc_Bits16)0x16bf,  /* right */
    },  /* [18] */
    {
        (xdc_Bits16)0x8012,  /* left */
        (xdc_Bits16)0x16c8,  /* right */
    },  /* [19] */
    {
        (xdc_Bits16)0x8013,  /* left */
        (xdc_Bits16)0x16d0,  /* right */
    },  /* [20] */
    {
        (xdc_Bits16)0x8014,  /* left */
        (xdc_Bits16)0x16d5,  /* right */
    },  /* [21] */
    {
        (xdc_Bits16)0x8014,  /* left */
        (xdc_Bits16)0x16d9,  /* right */
    },  /* [22] */
    {
        (xdc_Bits16)0x8014,  /* left */
        (xdc_Bits16)0x16df,  /* right */
    },  /* [23] */
    {
        (xdc_Bits16)0x8014,  /* left */
        (xdc_Bits16)0x16f1,  /* right */
    },  /* [24] */
    {
        (xdc_Bits16)0x8012,  /* left */
        (xdc_Bits16)0x16fd,  /* right */
    },  /* [25] */
    {
        (xdc_Bits16)0x8012,  /* left */
        (xdc_Bits16)0x1702,  /* right */
    },  /* [26] */
    {
        (xdc_Bits16)0x801a,  /* left */
        (xdc_Bits16)0x1707,  /* right */
    },  /* [27] */
    {
        (xdc_Bits16)0x801a,  /* left */
        (xdc_Bits16)0x170d,  /* right */
    },  /* [28] */
    {
        (xdc_Bits16)0x801a,  /* left */
        (xdc_Bits16)0x1712,  /* right */
    },  /* [29] */
    {
        (xdc_Bits16)0x801a,  /* left */
        (xdc_Bits16)0x171d,  /* right */
    },  /* [30] */
    {
        (xdc_Bits16)0x801a,  /* left */
        (xdc_Bits16)0x1723,  /* right */
    },  /* [31] */
    {
        (xdc_Bits16)0x801a,  /* left */
        (xdc_Bits16)0x172d,  /* right */
    },  /* [32] */
    {
        (xdc_Bits16)0x801a,  /* left */
        (xdc_Bits16)0x1731,  /* right */
    },  /* [33] */
    {
        (xdc_Bits16)0x8012,  /* left */
        (xdc_Bits16)0x1736,  /* right */
    },  /* [34] */
    {
        (xdc_Bits16)0x8022,  /* left */
        (xdc_Bits16)0x173d,  /* right */
    },  /* [35] */
    {
        (xdc_Bits16)0x8022,  /* left */
        (xdc_Bits16)0x1745,  /* right */
    },  /* [36] */
    {
        (xdc_Bits16)0x8012,  /* left */
        (xdc_Bits16)0x174f,  /* right */
    },  /* [37] */
    {
        (xdc_Bits16)0x8025,  /* left */
        (xdc_Bits16)0x16d5,  /* right */
    },  /* [38] */
    {
        (xdc_Bits16)0x8012,  /* left */
        (xdc_Bits16)0x1754,  /* right */
    },  /* [39] */
    {
        (xdc_Bits16)0x8027,  /* left */
        (xdc_Bits16)0x175b,  /* right */
    },  /* [40] */
    {
        (xdc_Bits16)0x8014,  /* left */
        (xdc_Bits16)0x1763,  /* right */
    },  /* [41] */
    {
        (xdc_Bits16)0x8029,  /* left */
        (xdc_Bits16)0x176b,  /* right */
    },  /* [42] */
};

/* Module__diagsEnabled__C */
#pragma DATA_SECTION(xdc_runtime_Text_Module__diagsEnabled__C, ".econst:xdc_runtime_Text_Module__diagsEnabled__C");
asm("	.sect \".econst:xdc_runtime_Text_Module__diagsEnabled__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Text_Module__diagsEnabled__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Text_Module__diagsEnabled__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Text_Module__diagsEnabled xdc_runtime_Text_Module__diagsEnabled__C = (xdc_Bits32)0x10;

/* Module__diagsIncluded__C */
#pragma DATA_SECTION(xdc_runtime_Text_Module__diagsIncluded__C, ".econst:xdc_runtime_Text_Module__diagsIncluded__C");
asm("	.sect \".econst:xdc_runtime_Text_Module__diagsIncluded__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Text_Module__diagsIncluded__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Text_Module__diagsIncluded__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Text_Module__diagsIncluded xdc_runtime_Text_Module__diagsIncluded__C = (xdc_Bits32)0x10;

/* Module__diagsMask__C */
#pragma DATA_SECTION(xdc_runtime_Text_Module__diagsMask__C, ".econst:xdc_runtime_Text_Module__diagsMask__C");
asm("	.sect \".econst:xdc_runtime_Text_Module__diagsMask__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Text_Module__diagsMask__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Text_Module__diagsMask__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Text_Module__diagsMask xdc_runtime_Text_Module__diagsMask__C = ((const CT__xdc_runtime_Text_Module__diagsMask)NULL);

/* Module__gateObj__C */
#pragma DATA_SECTION(xdc_runtime_Text_Module__gateObj__C, ".econst:xdc_runtime_Text_Module__gateObj__C");
asm("	.sect \".econst:xdc_runtime_Text_Module__gateObj__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Text_Module__gateObj__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Text_Module__gateObj__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Text_Module__gateObj xdc_runtime_Text_Module__gateObj__C = ((const CT__xdc_runtime_Text_Module__gateObj)NULL);

/* Module__gatePrms__C */
#pragma DATA_SECTION(xdc_runtime_Text_Module__gatePrms__C, ".econst:xdc_runtime_Text_Module__gatePrms__C");
asm("	.sect \".econst:xdc_runtime_Text_Module__gatePrms__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Text_Module__gatePrms__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Text_Module__gatePrms__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Text_Module__gatePrms xdc_runtime_Text_Module__gatePrms__C = ((const CT__xdc_runtime_Text_Module__gatePrms)NULL);

/* Module__id__C */
#pragma DATA_SECTION(xdc_runtime_Text_Module__id__C, ".econst:xdc_runtime_Text_Module__id__C");
asm("	.sect \".econst:xdc_runtime_Text_Module__id__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Text_Module__id__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Text_Module__id__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Text_Module__id xdc_runtime_Text_Module__id__C = (xdc_Bits16)0x8010;

/* Module__loggerDefined__C */
#pragma DATA_SECTION(xdc_runtime_Text_Module__loggerDefined__C, ".econst:xdc_runtime_Text_Module__loggerDefined__C");
asm("	.sect \".econst:xdc_runtime_Text_Module__loggerDefined__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Text_Module__loggerDefined__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Text_Module__loggerDefined__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Text_Module__loggerDefined xdc_runtime_Text_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
#pragma DATA_SECTION(xdc_runtime_Text_Module__loggerObj__C, ".econst:xdc_runtime_Text_Module__loggerObj__C");
asm("	.sect \".econst:xdc_runtime_Text_Module__loggerObj__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Text_Module__loggerObj__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Text_Module__loggerObj__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Text_Module__loggerObj xdc_runtime_Text_Module__loggerObj__C = ((const CT__xdc_runtime_Text_Module__loggerObj)NULL);

/* Module__loggerFxn0__C */
#pragma DATA_SECTION(xdc_runtime_Text_Module__loggerFxn0__C, ".econst:xdc_runtime_Text_Module__loggerFxn0__C");
asm("	.sect \".econst:xdc_runtime_Text_Module__loggerFxn0__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Text_Module__loggerFxn0__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Text_Module__loggerFxn0__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Text_Module__loggerFxn0 xdc_runtime_Text_Module__loggerFxn0__C = ((const CT__xdc_runtime_Text_Module__loggerFxn0)NULL);

/* Module__loggerFxn1__C */
#pragma DATA_SECTION(xdc_runtime_Text_Module__loggerFxn1__C, ".econst:xdc_runtime_Text_Module__loggerFxn1__C");
asm("	.sect \".econst:xdc_runtime_Text_Module__loggerFxn1__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Text_Module__loggerFxn1__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Text_Module__loggerFxn1__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Text_Module__loggerFxn1 xdc_runtime_Text_Module__loggerFxn1__C = ((const CT__xdc_runtime_Text_Module__loggerFxn1)NULL);

/* Module__loggerFxn2__C */
#pragma DATA_SECTION(xdc_runtime_Text_Module__loggerFxn2__C, ".econst:xdc_runtime_Text_Module__loggerFxn2__C");
asm("	.sect \".econst:xdc_runtime_Text_Module__loggerFxn2__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Text_Module__loggerFxn2__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Text_Module__loggerFxn2__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Text_Module__loggerFxn2 xdc_runtime_Text_Module__loggerFxn2__C = ((const CT__xdc_runtime_Text_Module__loggerFxn2)NULL);

/* Module__loggerFxn4__C */
#pragma DATA_SECTION(xdc_runtime_Text_Module__loggerFxn4__C, ".econst:xdc_runtime_Text_Module__loggerFxn4__C");
asm("	.sect \".econst:xdc_runtime_Text_Module__loggerFxn4__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Text_Module__loggerFxn4__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Text_Module__loggerFxn4__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Text_Module__loggerFxn4 xdc_runtime_Text_Module__loggerFxn4__C = ((const CT__xdc_runtime_Text_Module__loggerFxn4)NULL);

/* Module__loggerFxn8__C */
#pragma DATA_SECTION(xdc_runtime_Text_Module__loggerFxn8__C, ".econst:xdc_runtime_Text_Module__loggerFxn8__C");
asm("	.sect \".econst:xdc_runtime_Text_Module__loggerFxn8__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Text_Module__loggerFxn8__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Text_Module__loggerFxn8__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Text_Module__loggerFxn8 xdc_runtime_Text_Module__loggerFxn8__C = ((const CT__xdc_runtime_Text_Module__loggerFxn8)NULL);

/* Object__count__C */
#pragma DATA_SECTION(xdc_runtime_Text_Object__count__C, ".econst:xdc_runtime_Text_Object__count__C");
asm("	.sect \".econst:xdc_runtime_Text_Object__count__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Text_Object__count__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Text_Object__count__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Text_Object__count xdc_runtime_Text_Object__count__C = 0;

/* Object__heap__C */
#pragma DATA_SECTION(xdc_runtime_Text_Object__heap__C, ".econst:xdc_runtime_Text_Object__heap__C");
asm("	.sect \".econst:xdc_runtime_Text_Object__heap__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Text_Object__heap__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Text_Object__heap__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Text_Object__heap xdc_runtime_Text_Object__heap__C = NULL;

/* Object__sizeof__C */
#pragma DATA_SECTION(xdc_runtime_Text_Object__sizeof__C, ".econst:xdc_runtime_Text_Object__sizeof__C");
asm("	.sect \".econst:xdc_runtime_Text_Object__sizeof__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Text_Object__sizeof__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Text_Object__sizeof__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Text_Object__sizeof xdc_runtime_Text_Object__sizeof__C = 0;

/* Object__table__C */
#pragma DATA_SECTION(xdc_runtime_Text_Object__table__C, ".econst:xdc_runtime_Text_Object__table__C");
asm("	.sect \".econst:xdc_runtime_Text_Object__table__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Text_Object__table__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Text_Object__table__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Text_Object__table xdc_runtime_Text_Object__table__C = NULL;

/* nameUnknown__C */
#pragma DATA_SECTION(xdc_runtime_Text_nameUnknown__C, ".econst:xdc_runtime_Text_nameUnknown__C");
asm("	.sect \".econst:xdc_runtime_Text_nameUnknown__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Text_nameUnknown__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Text_nameUnknown__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Text_nameUnknown xdc_runtime_Text_nameUnknown__C = "{unknown-instance-name}";

/* nameEmpty__C */
#pragma DATA_SECTION(xdc_runtime_Text_nameEmpty__C, ".econst:xdc_runtime_Text_nameEmpty__C");
asm("	.sect \".econst:xdc_runtime_Text_nameEmpty__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Text_nameEmpty__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Text_nameEmpty__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Text_nameEmpty xdc_runtime_Text_nameEmpty__C = "{empty-instance-name}";

/* nameStatic__C */
#pragma DATA_SECTION(xdc_runtime_Text_nameStatic__C, ".econst:xdc_runtime_Text_nameStatic__C");
asm("	.sect \".econst:xdc_runtime_Text_nameStatic__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Text_nameStatic__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Text_nameStatic__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Text_nameStatic xdc_runtime_Text_nameStatic__C = "{static-instance-name}";

/* isLoaded__C */
#pragma DATA_SECTION(xdc_runtime_Text_isLoaded__C, ".econst:xdc_runtime_Text_isLoaded__C");
asm("	.sect \".econst:xdc_runtime_Text_isLoaded__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Text_isLoaded__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Text_isLoaded__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Text_isLoaded xdc_runtime_Text_isLoaded__C = 1;

/* charTab__C */
#pragma DATA_SECTION(xdc_runtime_Text_charTab__C, ".econst:xdc_runtime_Text_charTab__C");
asm("	.sect \".econst:xdc_runtime_Text_charTab__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Text_charTab__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Text_charTab__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Text_charTab xdc_runtime_Text_charTab__C = ((const CT__xdc_runtime_Text_charTab)xdc_runtime_Text_charTab__A);

/* nodeTab__C */
#pragma DATA_SECTION(xdc_runtime_Text_nodeTab__C, ".econst:xdc_runtime_Text_nodeTab__C");
asm("	.sect \".econst:xdc_runtime_Text_nodeTab__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Text_nodeTab__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Text_nodeTab__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Text_nodeTab xdc_runtime_Text_nodeTab__C = ((const CT__xdc_runtime_Text_nodeTab)xdc_runtime_Text_nodeTab__A);

/* charCnt__C */
#pragma DATA_SECTION(xdc_runtime_Text_charCnt__C, ".econst:xdc_runtime_Text_charCnt__C");
asm("	.sect \".econst:xdc_runtime_Text_charCnt__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Text_charCnt__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Text_charCnt__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Text_charCnt xdc_runtime_Text_charCnt__C = (xdc_Int16)0x17a8;

/* nodeCnt__C */
#pragma DATA_SECTION(xdc_runtime_Text_nodeCnt__C, ".econst:xdc_runtime_Text_nodeCnt__C");
asm("	.sect \".econst:xdc_runtime_Text_nodeCnt__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Text_nodeCnt__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Text_nodeCnt__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Text_nodeCnt xdc_runtime_Text_nodeCnt__C = (xdc_Int16)0x2b;

/* unnamedModsLastId__C */
#pragma DATA_SECTION(xdc_runtime_Text_unnamedModsLastId__C, ".econst:xdc_runtime_Text_unnamedModsLastId__C");
asm("	.sect \".econst:xdc_runtime_Text_unnamedModsLastId__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Text_unnamedModsLastId__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Text_unnamedModsLastId__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Text_unnamedModsLastId xdc_runtime_Text_unnamedModsLastId__C = (xdc_UInt16)0x4000;

/* registryModsLastId__C */
#pragma DATA_SECTION(xdc_runtime_Text_registryModsLastId__C, ".econst:xdc_runtime_Text_registryModsLastId__C");
asm("	.sect \".econst:xdc_runtime_Text_registryModsLastId__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Text_registryModsLastId__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Text_registryModsLastId__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Text_registryModsLastId xdc_runtime_Text_registryModsLastId__C = (xdc_UInt16)0x7fff;

/* visitRopeFxn__C */
#pragma DATA_SECTION(xdc_runtime_Text_visitRopeFxn__C, ".econst:xdc_runtime_Text_visitRopeFxn__C");
asm("	.sect \".econst:xdc_runtime_Text_visitRopeFxn__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Text_visitRopeFxn__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Text_visitRopeFxn__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Text_visitRopeFxn xdc_runtime_Text_visitRopeFxn__C = ((const CT__xdc_runtime_Text_visitRopeFxn)(xdc_runtime_Text_visitRope__I));

/* visitRopeFxn2__C */
#pragma DATA_SECTION(xdc_runtime_Text_visitRopeFxn2__C, ".econst:xdc_runtime_Text_visitRopeFxn2__C");
asm("	.sect \".econst:xdc_runtime_Text_visitRopeFxn2__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Text_visitRopeFxn2__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Text_visitRopeFxn2__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Text_visitRopeFxn2 xdc_runtime_Text_visitRopeFxn2__C = ((const CT__xdc_runtime_Text_visitRopeFxn2)(xdc_runtime_Text_visitRope2__I));


/*
 * ======== xdc.runtime.Types INITIALIZERS ========
 */

/* Module__diagsEnabled__C */
#pragma DATA_SECTION(xdc_runtime_Types_Module__diagsEnabled__C, ".econst:xdc_runtime_Types_Module__diagsEnabled__C");
asm("	.sect \".econst:xdc_runtime_Types_Module__diagsEnabled__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Types_Module__diagsEnabled__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Types_Module__diagsEnabled__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Types_Module__diagsEnabled xdc_runtime_Types_Module__diagsEnabled__C = (xdc_Bits32)0x10;

/* Module__diagsIncluded__C */
#pragma DATA_SECTION(xdc_runtime_Types_Module__diagsIncluded__C, ".econst:xdc_runtime_Types_Module__diagsIncluded__C");
asm("	.sect \".econst:xdc_runtime_Types_Module__diagsIncluded__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Types_Module__diagsIncluded__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Types_Module__diagsIncluded__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Types_Module__diagsIncluded xdc_runtime_Types_Module__diagsIncluded__C = (xdc_Bits32)0x10;

/* Module__diagsMask__C */
#pragma DATA_SECTION(xdc_runtime_Types_Module__diagsMask__C, ".econst:xdc_runtime_Types_Module__diagsMask__C");
asm("	.sect \".econst:xdc_runtime_Types_Module__diagsMask__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Types_Module__diagsMask__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Types_Module__diagsMask__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Types_Module__diagsMask xdc_runtime_Types_Module__diagsMask__C = ((const CT__xdc_runtime_Types_Module__diagsMask)NULL);

/* Module__gateObj__C */
#pragma DATA_SECTION(xdc_runtime_Types_Module__gateObj__C, ".econst:xdc_runtime_Types_Module__gateObj__C");
asm("	.sect \".econst:xdc_runtime_Types_Module__gateObj__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Types_Module__gateObj__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Types_Module__gateObj__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Types_Module__gateObj xdc_runtime_Types_Module__gateObj__C = ((const CT__xdc_runtime_Types_Module__gateObj)NULL);

/* Module__gatePrms__C */
#pragma DATA_SECTION(xdc_runtime_Types_Module__gatePrms__C, ".econst:xdc_runtime_Types_Module__gatePrms__C");
asm("	.sect \".econst:xdc_runtime_Types_Module__gatePrms__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Types_Module__gatePrms__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Types_Module__gatePrms__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Types_Module__gatePrms xdc_runtime_Types_Module__gatePrms__C = ((const CT__xdc_runtime_Types_Module__gatePrms)NULL);

/* Module__id__C */
#pragma DATA_SECTION(xdc_runtime_Types_Module__id__C, ".econst:xdc_runtime_Types_Module__id__C");
asm("	.sect \".econst:xdc_runtime_Types_Module__id__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Types_Module__id__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Types_Module__id__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Types_Module__id xdc_runtime_Types_Module__id__C = (xdc_Bits16)0x8011;

/* Module__loggerDefined__C */
#pragma DATA_SECTION(xdc_runtime_Types_Module__loggerDefined__C, ".econst:xdc_runtime_Types_Module__loggerDefined__C");
asm("	.sect \".econst:xdc_runtime_Types_Module__loggerDefined__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Types_Module__loggerDefined__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Types_Module__loggerDefined__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Types_Module__loggerDefined xdc_runtime_Types_Module__loggerDefined__C = 0;

/* Module__loggerObj__C */
#pragma DATA_SECTION(xdc_runtime_Types_Module__loggerObj__C, ".econst:xdc_runtime_Types_Module__loggerObj__C");
asm("	.sect \".econst:xdc_runtime_Types_Module__loggerObj__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Types_Module__loggerObj__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Types_Module__loggerObj__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Types_Module__loggerObj xdc_runtime_Types_Module__loggerObj__C = ((const CT__xdc_runtime_Types_Module__loggerObj)NULL);

/* Module__loggerFxn0__C */
#pragma DATA_SECTION(xdc_runtime_Types_Module__loggerFxn0__C, ".econst:xdc_runtime_Types_Module__loggerFxn0__C");
asm("	.sect \".econst:xdc_runtime_Types_Module__loggerFxn0__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Types_Module__loggerFxn0__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Types_Module__loggerFxn0__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Types_Module__loggerFxn0 xdc_runtime_Types_Module__loggerFxn0__C = ((const CT__xdc_runtime_Types_Module__loggerFxn0)NULL);

/* Module__loggerFxn1__C */
#pragma DATA_SECTION(xdc_runtime_Types_Module__loggerFxn1__C, ".econst:xdc_runtime_Types_Module__loggerFxn1__C");
asm("	.sect \".econst:xdc_runtime_Types_Module__loggerFxn1__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Types_Module__loggerFxn1__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Types_Module__loggerFxn1__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Types_Module__loggerFxn1 xdc_runtime_Types_Module__loggerFxn1__C = ((const CT__xdc_runtime_Types_Module__loggerFxn1)NULL);

/* Module__loggerFxn2__C */
#pragma DATA_SECTION(xdc_runtime_Types_Module__loggerFxn2__C, ".econst:xdc_runtime_Types_Module__loggerFxn2__C");
asm("	.sect \".econst:xdc_runtime_Types_Module__loggerFxn2__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Types_Module__loggerFxn2__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Types_Module__loggerFxn2__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Types_Module__loggerFxn2 xdc_runtime_Types_Module__loggerFxn2__C = ((const CT__xdc_runtime_Types_Module__loggerFxn2)NULL);

/* Module__loggerFxn4__C */
#pragma DATA_SECTION(xdc_runtime_Types_Module__loggerFxn4__C, ".econst:xdc_runtime_Types_Module__loggerFxn4__C");
asm("	.sect \".econst:xdc_runtime_Types_Module__loggerFxn4__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Types_Module__loggerFxn4__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Types_Module__loggerFxn4__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Types_Module__loggerFxn4 xdc_runtime_Types_Module__loggerFxn4__C = ((const CT__xdc_runtime_Types_Module__loggerFxn4)NULL);

/* Module__loggerFxn8__C */
#pragma DATA_SECTION(xdc_runtime_Types_Module__loggerFxn8__C, ".econst:xdc_runtime_Types_Module__loggerFxn8__C");
asm("	.sect \".econst:xdc_runtime_Types_Module__loggerFxn8__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Types_Module__loggerFxn8__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Types_Module__loggerFxn8__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Types_Module__loggerFxn8 xdc_runtime_Types_Module__loggerFxn8__C = ((const CT__xdc_runtime_Types_Module__loggerFxn8)NULL);

/* Object__count__C */
#pragma DATA_SECTION(xdc_runtime_Types_Object__count__C, ".econst:xdc_runtime_Types_Object__count__C");
asm("	.sect \".econst:xdc_runtime_Types_Object__count__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Types_Object__count__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Types_Object__count__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Types_Object__count xdc_runtime_Types_Object__count__C = 0;

/* Object__heap__C */
#pragma DATA_SECTION(xdc_runtime_Types_Object__heap__C, ".econst:xdc_runtime_Types_Object__heap__C");
asm("	.sect \".econst:xdc_runtime_Types_Object__heap__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Types_Object__heap__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Types_Object__heap__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Types_Object__heap xdc_runtime_Types_Object__heap__C = NULL;

/* Object__sizeof__C */
#pragma DATA_SECTION(xdc_runtime_Types_Object__sizeof__C, ".econst:xdc_runtime_Types_Object__sizeof__C");
asm("	.sect \".econst:xdc_runtime_Types_Object__sizeof__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Types_Object__sizeof__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Types_Object__sizeof__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Types_Object__sizeof xdc_runtime_Types_Object__sizeof__C = 0;

/* Object__table__C */
#pragma DATA_SECTION(xdc_runtime_Types_Object__table__C, ".econst:xdc_runtime_Types_Object__table__C");
asm("	.sect \".econst:xdc_runtime_Types_Object__table__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_Types_Object__table__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_Types_Object__table__C\"");
asm("	.clink ");

__FAR__ const CT__xdc_runtime_Types_Object__table xdc_runtime_Types_Object__table__C = NULL;


/*
 * ======== xdc.runtime.System FUNCTION STUBS ========
 */

/* printf_va__E */
xdc_Int xdc_runtime_System_printf_va__E( xdc_CString fmt, va_list arg__va)
{
    return xdc_runtime_System_printf_va__F(fmt, arg__va);
}

/* printf__E */
xdc_Int xdc_runtime_System_printf__E( xdc_CString fmt, ...)
{
    xdc_Int retval;

    va_list arg__va;
    (void)va_start(arg__va, fmt);
    retval = xdc_runtime_System_printf_va__F(fmt, arg__va);

    va_end(arg__va);
    return retval;
}

/* aprintf_va__E */
xdc_Int xdc_runtime_System_aprintf_va__E( xdc_CString fmt, va_list arg__va)
{
    return xdc_runtime_System_aprintf_va__F(fmt, arg__va);
}

/* aprintf__E */
xdc_Int xdc_runtime_System_aprintf__E( xdc_CString fmt, ...)
{
    xdc_Int retval;

    va_list arg__va;
    (void)va_start(arg__va, fmt);
    retval = xdc_runtime_System_aprintf_va__F(fmt, arg__va);

    va_end(arg__va);
    return retval;
}

/* sprintf_va__E */
xdc_Int xdc_runtime_System_sprintf_va__E( xdc_Char buf[], xdc_CString fmt, va_list arg__va)
{
    return xdc_runtime_System_sprintf_va__F(buf, fmt, arg__va);
}

/* sprintf__E */
xdc_Int xdc_runtime_System_sprintf__E( xdc_Char buf[], xdc_CString fmt, ...)
{
    xdc_Int retval;

    va_list arg__va;
    (void)va_start(arg__va, fmt);
    retval = xdc_runtime_System_sprintf_va__F(buf, fmt, arg__va);

    va_end(arg__va);
    return retval;
}

/* asprintf_va__E */
xdc_Int xdc_runtime_System_asprintf_va__E( xdc_Char buf[], xdc_CString fmt, va_list arg__va)
{
    return xdc_runtime_System_asprintf_va__F(buf, fmt, arg__va);
}

/* asprintf__E */
xdc_Int xdc_runtime_System_asprintf__E( xdc_Char buf[], xdc_CString fmt, ...)
{
    xdc_Int retval;

    va_list arg__va;
    (void)va_start(arg__va, fmt);
    retval = xdc_runtime_System_asprintf_va__F(buf, fmt, arg__va);

    va_end(arg__va);
    return retval;
}

/* snprintf_va__E */
xdc_Int xdc_runtime_System_snprintf_va__E( xdc_Char buf[], xdc_SizeT n, xdc_CString fmt, va_list arg__va)
{
    return xdc_runtime_System_snprintf_va__F(buf, n, fmt, arg__va);
}

/* snprintf__E */
xdc_Int xdc_runtime_System_snprintf__E( xdc_Char buf[], xdc_SizeT n, xdc_CString fmt, ...)
{
    xdc_Int retval;

    va_list arg__va;
    (void)va_start(arg__va, fmt);
    retval = xdc_runtime_System_snprintf_va__F(buf, n, fmt, arg__va);

    va_end(arg__va);
    return retval;
}


/*
 * ======== ti.sysbios.BIOS_RtsGateProxy PROXY BODY ========
 */

/* DELEGATES TO ti.sysbios.gates.GateMutex */

/* Module__startupDone__S */
xdc_Bool ti_sysbios_BIOS_RtsGateProxy_Module__startupDone__S(void)
{
    return ti_sysbios_gates_GateMutex_Module__startupDone__S();
}

/* create */
ti_sysbios_BIOS_RtsGateProxy_Handle ti_sysbios_BIOS_RtsGateProxy_create( const ti_sysbios_BIOS_RtsGateProxy_Params *prms, xdc_runtime_Error_Block *eb )
{
    return (ti_sysbios_BIOS_RtsGateProxy_Handle)ti_sysbios_gates_GateMutex_create((const ti_sysbios_gates_GateMutex_Params *)prms, eb);
}

/* delete */
void ti_sysbios_BIOS_RtsGateProxy_delete(ti_sysbios_BIOS_RtsGateProxy_Handle *instp)
{
    ti_sysbios_gates_GateMutex_Object__delete__S(instp);
}

/* Params__init__S */
void ti_sysbios_BIOS_RtsGateProxy_Params__init__S( xdc_Ptr dst, const void *src, xdc_SizeT psz, xdc_SizeT isz )
{
    ti_sysbios_gates_GateMutex_Params__init__S(dst, src, psz, isz);
}

/* Handle__label__S */
xdc_runtime_Types_Label *ti_sysbios_BIOS_RtsGateProxy_Handle__label__S(xdc_Ptr obj, xdc_runtime_Types_Label *lab)
{
    return ti_sysbios_gates_GateMutex_Handle__label__S(obj, lab);
}

/* query__E */
xdc_Bool ti_sysbios_BIOS_RtsGateProxy_query__E( xdc_Int qual )
{
    return ti_sysbios_gates_GateMutex_query(qual);
}

/* enter__E */
xdc_IArg ti_sysbios_BIOS_RtsGateProxy_enter__E( ti_sysbios_BIOS_RtsGateProxy_Handle inst )
{
    return ti_sysbios_gates_GateMutex_enter((ti_sysbios_gates_GateMutex_Handle)inst);
}

/* leave__E */
xdc_Void ti_sysbios_BIOS_RtsGateProxy_leave__E( ti_sysbios_BIOS_RtsGateProxy_Handle inst, xdc_IArg key )
{
    ti_sysbios_gates_GateMutex_leave((ti_sysbios_gates_GateMutex_Handle)inst, key);
}


/*
 * ======== ti.sysbios.hal.Hwi_HwiProxy PROXY BODY ========
 */

/* DELEGATES TO ti.sysbios.family.c28.Hwi */

/* Module__startupDone__S */
xdc_Bool ti_sysbios_hal_Hwi_HwiProxy_Module__startupDone__S(void)
{
    return ti_sysbios_family_c28_Hwi_Module__startupDone__S();
}

/* create */
ti_sysbios_hal_Hwi_HwiProxy_Handle ti_sysbios_hal_Hwi_HwiProxy_create( xdc_Int intNum, ti_sysbios_interfaces_IHwi_FuncPtr hwiFxn, const ti_sysbios_hal_Hwi_HwiProxy_Params *prms, xdc_runtime_Error_Block *eb )
{
    return (ti_sysbios_hal_Hwi_HwiProxy_Handle)ti_sysbios_family_c28_Hwi_create(intNum, hwiFxn, (const ti_sysbios_family_c28_Hwi_Params *)prms, eb);
}

/* delete */
void ti_sysbios_hal_Hwi_HwiProxy_delete(ti_sysbios_hal_Hwi_HwiProxy_Handle *instp)
{
    ti_sysbios_family_c28_Hwi_Object__delete__S(instp);
}

/* Params__init__S */
void ti_sysbios_hal_Hwi_HwiProxy_Params__init__S( xdc_Ptr dst, const void *src, xdc_SizeT psz, xdc_SizeT isz )
{
    ti_sysbios_family_c28_Hwi_Params__init__S(dst, src, psz, isz);
}

/* Handle__label__S */
xdc_runtime_Types_Label *ti_sysbios_hal_Hwi_HwiProxy_Handle__label__S(xdc_Ptr obj, xdc_runtime_Types_Label *lab)
{
    return ti_sysbios_family_c28_Hwi_Handle__label__S(obj, lab);
}

/* getStackInfo__E */
xdc_Bool ti_sysbios_hal_Hwi_HwiProxy_getStackInfo__E( ti_sysbios_interfaces_IHwi_StackInfo *stkInfo, xdc_Bool computeStackDepth )
{
    return ti_sysbios_family_c28_Hwi_getStackInfo(stkInfo, computeStackDepth);
}

/* getCoreStackInfo__E */
xdc_Bool ti_sysbios_hal_Hwi_HwiProxy_getCoreStackInfo__E( ti_sysbios_interfaces_IHwi_StackInfo *stkInfo, xdc_Bool computeStackDepth, xdc_UInt coreId )
{
    return ti_sysbios_family_c28_Hwi_getCoreStackInfo(stkInfo, computeStackDepth, coreId);
}

/* startup__E */
xdc_Void ti_sysbios_hal_Hwi_HwiProxy_startup__E( void )
{
    ti_sysbios_family_c28_Hwi_startup();
}

/* disable__E */
xdc_UInt ti_sysbios_hal_Hwi_HwiProxy_disable__E( void )
{
    return ti_sysbios_family_c28_Hwi_disable();
}

/* enable__E */
xdc_UInt ti_sysbios_hal_Hwi_HwiProxy_enable__E( void )
{
    return ti_sysbios_family_c28_Hwi_enable();
}

/* restore__E */
xdc_Void ti_sysbios_hal_Hwi_HwiProxy_restore__E( xdc_UInt key )
{
    ti_sysbios_family_c28_Hwi_restore(key);
}

/* switchFromBootStack__E */
xdc_Void ti_sysbios_hal_Hwi_HwiProxy_switchFromBootStack__E( void )
{
    ti_sysbios_family_c28_Hwi_switchFromBootStack();
}

/* post__E */
xdc_Void ti_sysbios_hal_Hwi_HwiProxy_post__E( xdc_UInt intNum )
{
    ti_sysbios_family_c28_Hwi_post(intNum);
}

/* getTaskSP__E */
xdc_Char *ti_sysbios_hal_Hwi_HwiProxy_getTaskSP__E( void )
{
    return ti_sysbios_family_c28_Hwi_getTaskSP();
}

/* disableInterrupt__E */
xdc_UInt ti_sysbios_hal_Hwi_HwiProxy_disableInterrupt__E( xdc_UInt intNum )
{
    return ti_sysbios_family_c28_Hwi_disableInterrupt(intNum);
}

/* enableInterrupt__E */
xdc_UInt ti_sysbios_hal_Hwi_HwiProxy_enableInterrupt__E( xdc_UInt intNum )
{
    return ti_sysbios_family_c28_Hwi_enableInterrupt(intNum);
}

/* restoreInterrupt__E */
xdc_Void ti_sysbios_hal_Hwi_HwiProxy_restoreInterrupt__E( xdc_UInt intNum, xdc_UInt key )
{
    ti_sysbios_family_c28_Hwi_restoreInterrupt(intNum, key);
}

/* clearInterrupt__E */
xdc_Void ti_sysbios_hal_Hwi_HwiProxy_clearInterrupt__E( xdc_UInt intNum )
{
    ti_sysbios_family_c28_Hwi_clearInterrupt(intNum);
}

/* getFunc__E */
ti_sysbios_interfaces_IHwi_FuncPtr ti_sysbios_hal_Hwi_HwiProxy_getFunc__E( ti_sysbios_hal_Hwi_HwiProxy_Handle inst, xdc_UArg *arg )
{
    return ti_sysbios_family_c28_Hwi_getFunc((ti_sysbios_family_c28_Hwi_Handle)inst, arg);
}

/* setFunc__E */
xdc_Void ti_sysbios_hal_Hwi_HwiProxy_setFunc__E( ti_sysbios_hal_Hwi_HwiProxy_Handle inst, ti_sysbios_interfaces_IHwi_FuncPtr fxn, xdc_UArg arg )
{
    ti_sysbios_family_c28_Hwi_setFunc((ti_sysbios_family_c28_Hwi_Handle)inst, fxn, arg);
}

/* getHookContext__E */
xdc_Ptr ti_sysbios_hal_Hwi_HwiProxy_getHookContext__E( ti_sysbios_hal_Hwi_HwiProxy_Handle inst, xdc_Int id )
{
    return ti_sysbios_family_c28_Hwi_getHookContext((ti_sysbios_family_c28_Hwi_Handle)inst, id);
}

/* setHookContext__E */
xdc_Void ti_sysbios_hal_Hwi_HwiProxy_setHookContext__E( ti_sysbios_hal_Hwi_HwiProxy_Handle inst, xdc_Int id, xdc_Ptr hookContext )
{
    ti_sysbios_family_c28_Hwi_setHookContext((ti_sysbios_family_c28_Hwi_Handle)inst, id, hookContext);
}

/* getIrp__E */
ti_sysbios_interfaces_IHwi_Irp ti_sysbios_hal_Hwi_HwiProxy_getIrp__E( ti_sysbios_hal_Hwi_HwiProxy_Handle inst )
{
    return ti_sysbios_family_c28_Hwi_getIrp((ti_sysbios_family_c28_Hwi_Handle)inst);
}


/*
 * ======== ti.sysbios.heaps.HeapMem_Module_GateProxy PROXY BODY ========
 */

/* DELEGATES TO ti.sysbios.gates.GateMutex */

/* Module__startupDone__S */
xdc_Bool ti_sysbios_heaps_HeapMem_Module_GateProxy_Module__startupDone__S(void)
{
    return ti_sysbios_gates_GateMutex_Module__startupDone__S();
}

/* create */
ti_sysbios_heaps_HeapMem_Module_GateProxy_Handle ti_sysbios_heaps_HeapMem_Module_GateProxy_create( const ti_sysbios_heaps_HeapMem_Module_GateProxy_Params *prms, xdc_runtime_Error_Block *eb )
{
    return (ti_sysbios_heaps_HeapMem_Module_GateProxy_Handle)ti_sysbios_gates_GateMutex_create((const ti_sysbios_gates_GateMutex_Params *)prms, eb);
}

/* delete */
void ti_sysbios_heaps_HeapMem_Module_GateProxy_delete(ti_sysbios_heaps_HeapMem_Module_GateProxy_Handle *instp)
{
    ti_sysbios_gates_GateMutex_Object__delete__S(instp);
}

/* Params__init__S */
void ti_sysbios_heaps_HeapMem_Module_GateProxy_Params__init__S( xdc_Ptr dst, const void *src, xdc_SizeT psz, xdc_SizeT isz )
{
    ti_sysbios_gates_GateMutex_Params__init__S(dst, src, psz, isz);
}

/* Handle__label__S */
xdc_runtime_Types_Label *ti_sysbios_heaps_HeapMem_Module_GateProxy_Handle__label__S(xdc_Ptr obj, xdc_runtime_Types_Label *lab)
{
    return ti_sysbios_gates_GateMutex_Handle__label__S(obj, lab);
}

/* query__E */
xdc_Bool ti_sysbios_heaps_HeapMem_Module_GateProxy_query__E( xdc_Int qual )
{
    return ti_sysbios_gates_GateMutex_query(qual);
}

/* enter__E */
xdc_IArg ti_sysbios_heaps_HeapMem_Module_GateProxy_enter__E( ti_sysbios_heaps_HeapMem_Module_GateProxy_Handle inst )
{
    return ti_sysbios_gates_GateMutex_enter((ti_sysbios_gates_GateMutex_Handle)inst);
}

/* leave__E */
xdc_Void ti_sysbios_heaps_HeapMem_Module_GateProxy_leave__E( ti_sysbios_heaps_HeapMem_Module_GateProxy_Handle inst, xdc_IArg key )
{
    ti_sysbios_gates_GateMutex_leave((ti_sysbios_gates_GateMutex_Handle)inst, key);
}


/*
 * ======== ti.sysbios.knl.Clock_TimerProxy PROXY BODY ========
 */

/* DELEGATES TO ti.sysbios.family.c28.Timer */

/* Module__startupDone__S */
xdc_Bool ti_sysbios_knl_Clock_TimerProxy_Module__startupDone__S(void)
{
    return ti_sysbios_family_c28_Timer_Module__startupDone__S();
}

/* create */
ti_sysbios_knl_Clock_TimerProxy_Handle ti_sysbios_knl_Clock_TimerProxy_create( xdc_Int id, ti_sysbios_interfaces_ITimer_FuncPtr tickFxn, const ti_sysbios_knl_Clock_TimerProxy_Params *prms, xdc_runtime_Error_Block *eb )
{
    return (ti_sysbios_knl_Clock_TimerProxy_Handle)ti_sysbios_family_c28_Timer_create(id, tickFxn, (const ti_sysbios_family_c28_Timer_Params *)prms, eb);
}

/* delete */
void ti_sysbios_knl_Clock_TimerProxy_delete(ti_sysbios_knl_Clock_TimerProxy_Handle *instp)
{
    ti_sysbios_family_c28_Timer_Object__delete__S(instp);
}

/* Params__init__S */
void ti_sysbios_knl_Clock_TimerProxy_Params__init__S( xdc_Ptr dst, const void *src, xdc_SizeT psz, xdc_SizeT isz )
{
    ti_sysbios_family_c28_Timer_Params__init__S(dst, src, psz, isz);
}

/* Handle__label__S */
xdc_runtime_Types_Label *ti_sysbios_knl_Clock_TimerProxy_Handle__label__S(xdc_Ptr obj, xdc_runtime_Types_Label *lab)
{
    return ti_sysbios_family_c28_Timer_Handle__label__S(obj, lab);
}

/* getNumTimers__E */
xdc_UInt ti_sysbios_knl_Clock_TimerProxy_getNumTimers__E( void )
{
    return ti_sysbios_family_c28_Timer_getNumTimers();
}

/* getStatus__E */
ti_sysbios_interfaces_ITimer_Status ti_sysbios_knl_Clock_TimerProxy_getStatus__E( xdc_UInt id )
{
    return ti_sysbios_family_c28_Timer_getStatus(id);
}

/* startup__E */
xdc_Void ti_sysbios_knl_Clock_TimerProxy_startup__E( void )
{
    ti_sysbios_family_c28_Timer_startup();
}

/* getMaxTicks__E */
xdc_UInt32 ti_sysbios_knl_Clock_TimerProxy_getMaxTicks__E( ti_sysbios_knl_Clock_TimerProxy_Handle inst )
{
    return ti_sysbios_family_c28_Timer_getMaxTicks((ti_sysbios_family_c28_Timer_Handle)inst);
}

/* setNextTick__E */
xdc_Void ti_sysbios_knl_Clock_TimerProxy_setNextTick__E( ti_sysbios_knl_Clock_TimerProxy_Handle inst, xdc_UInt32 ticks )
{
    ti_sysbios_family_c28_Timer_setNextTick((ti_sysbios_family_c28_Timer_Handle)inst, ticks);
}

/* start__E */
xdc_Void ti_sysbios_knl_Clock_TimerProxy_start__E( ti_sysbios_knl_Clock_TimerProxy_Handle inst )
{
    ti_sysbios_family_c28_Timer_start((ti_sysbios_family_c28_Timer_Handle)inst);
}

/* stop__E */
xdc_Void ti_sysbios_knl_Clock_TimerProxy_stop__E( ti_sysbios_knl_Clock_TimerProxy_Handle inst )
{
    ti_sysbios_family_c28_Timer_stop((ti_sysbios_family_c28_Timer_Handle)inst);
}

/* setPeriod__E */
xdc_Void ti_sysbios_knl_Clock_TimerProxy_setPeriod__E( ti_sysbios_knl_Clock_TimerProxy_Handle inst, xdc_UInt32 period )
{
    ti_sysbios_family_c28_Timer_setPeriod((ti_sysbios_family_c28_Timer_Handle)inst, period);
}

/* setPeriodMicroSecs__E */
xdc_Bool ti_sysbios_knl_Clock_TimerProxy_setPeriodMicroSecs__E( ti_sysbios_knl_Clock_TimerProxy_Handle inst, xdc_UInt32 microsecs )
{
    return ti_sysbios_family_c28_Timer_setPeriodMicroSecs((ti_sysbios_family_c28_Timer_Handle)inst, microsecs);
}

/* getPeriod__E */
xdc_UInt32 ti_sysbios_knl_Clock_TimerProxy_getPeriod__E( ti_sysbios_knl_Clock_TimerProxy_Handle inst )
{
    return ti_sysbios_family_c28_Timer_getPeriod((ti_sysbios_family_c28_Timer_Handle)inst);
}

/* getCount__E */
xdc_UInt32 ti_sysbios_knl_Clock_TimerProxy_getCount__E( ti_sysbios_knl_Clock_TimerProxy_Handle inst )
{
    return ti_sysbios_family_c28_Timer_getCount((ti_sysbios_family_c28_Timer_Handle)inst);
}

/* getFreq__E */
xdc_Void ti_sysbios_knl_Clock_TimerProxy_getFreq__E( ti_sysbios_knl_Clock_TimerProxy_Handle inst, xdc_runtime_Types_FreqHz *freq )
{
    ti_sysbios_family_c28_Timer_getFreq((ti_sysbios_family_c28_Timer_Handle)inst, freq);
}

/* getFunc__E */
ti_sysbios_interfaces_ITimer_FuncPtr ti_sysbios_knl_Clock_TimerProxy_getFunc__E( ti_sysbios_knl_Clock_TimerProxy_Handle inst, xdc_UArg *arg )
{
    return ti_sysbios_family_c28_Timer_getFunc((ti_sysbios_family_c28_Timer_Handle)inst, arg);
}

/* setFunc__E */
xdc_Void ti_sysbios_knl_Clock_TimerProxy_setFunc__E( ti_sysbios_knl_Clock_TimerProxy_Handle inst, ti_sysbios_interfaces_ITimer_FuncPtr fxn, xdc_UArg arg )
{
    ti_sysbios_family_c28_Timer_setFunc((ti_sysbios_family_c28_Timer_Handle)inst, fxn, arg);
}

/* trigger__E */
xdc_Void ti_sysbios_knl_Clock_TimerProxy_trigger__E( ti_sysbios_knl_Clock_TimerProxy_Handle inst, xdc_UInt32 cycles )
{
    ti_sysbios_family_c28_Timer_trigger((ti_sysbios_family_c28_Timer_Handle)inst, cycles);
}

/* getExpiredCounts__E */
xdc_UInt32 ti_sysbios_knl_Clock_TimerProxy_getExpiredCounts__E( ti_sysbios_knl_Clock_TimerProxy_Handle inst )
{
    return ti_sysbios_family_c28_Timer_getExpiredCounts((ti_sysbios_family_c28_Timer_Handle)inst);
}

/* getExpiredTicks__E */
xdc_UInt32 ti_sysbios_knl_Clock_TimerProxy_getExpiredTicks__E( ti_sysbios_knl_Clock_TimerProxy_Handle inst, xdc_UInt32 tickPeriod )
{
    return ti_sysbios_family_c28_Timer_getExpiredTicks((ti_sysbios_family_c28_Timer_Handle)inst, tickPeriod);
}

/* getCurrentTick__E */
xdc_UInt32 ti_sysbios_knl_Clock_TimerProxy_getCurrentTick__E( ti_sysbios_knl_Clock_TimerProxy_Handle inst, xdc_Bool save )
{
    return ti_sysbios_family_c28_Timer_getCurrentTick((ti_sysbios_family_c28_Timer_Handle)inst, save);
}


/*
 * ======== ti.sysbios.knl.Intrinsics_SupportProxy PROXY BODY ========
 */

/* DELEGATES TO ti.sysbios.family.c28.IntrinsicsSupport */

/* Module__startupDone__S */
xdc_Bool ti_sysbios_knl_Intrinsics_SupportProxy_Module__startupDone__S(void)
{
    return ti_sysbios_family_c28_IntrinsicsSupport_Module__startupDone__S();
}

/* maxbit__E */
xdc_UInt ti_sysbios_knl_Intrinsics_SupportProxy_maxbit__E( xdc_UInt bits )
{
    return ti_sysbios_family_c28_IntrinsicsSupport_maxbit(bits);
}


/*
 * ======== ti.sysbios.knl.Task_SupportProxy PROXY BODY ========
 */

/* DELEGATES TO ti.sysbios.family.c28.TaskSupport */

/* Module__startupDone__S */
xdc_Bool ti_sysbios_knl_Task_SupportProxy_Module__startupDone__S(void)
{
    return ti_sysbios_family_c28_TaskSupport_Module__startupDone__S();
}

/* start__E */
xdc_Ptr ti_sysbios_knl_Task_SupportProxy_start__E( xdc_Ptr curTask, ti_sysbios_interfaces_ITaskSupport_FuncPtr enterFxn, ti_sysbios_interfaces_ITaskSupport_FuncPtr exitFxn, xdc_runtime_Error_Block *eb )
{
    return ti_sysbios_family_c28_TaskSupport_start(curTask, enterFxn, exitFxn, eb);
}

/* swap__E */
xdc_Void ti_sysbios_knl_Task_SupportProxy_swap__E( xdc_Ptr *oldtskContext, xdc_Ptr *newtskContext )
{
    ti_sysbios_family_c28_TaskSupport_swap(oldtskContext, newtskContext);
}

/* checkStack__E */
xdc_Bool ti_sysbios_knl_Task_SupportProxy_checkStack__E( xdc_Char *stack, xdc_SizeT size )
{
    return ti_sysbios_family_c28_TaskSupport_checkStack(stack, size);
}

/* stackUsed__E */
xdc_SizeT ti_sysbios_knl_Task_SupportProxy_stackUsed__E( xdc_Char *stack, xdc_SizeT size )
{
    return ti_sysbios_family_c28_TaskSupport_stackUsed(stack, size);
}

/* getStackAlignment__E */
xdc_UInt ti_sysbios_knl_Task_SupportProxy_getStackAlignment__E( void )
{
    return ti_sysbios_family_c28_TaskSupport_getStackAlignment();
}


/*
 * ======== xdc.runtime.LoggerBuf_Module_GateProxy PROXY BODY ========
 */

/* DELEGATES TO ti.sysbios.gates.GateHwi */

/* Module__startupDone__S */
xdc_Bool xdc_runtime_LoggerBuf_Module_GateProxy_Module__startupDone__S(void)
{
    return ti_sysbios_gates_GateHwi_Module__startupDone__S();
}

/* create */
xdc_runtime_LoggerBuf_Module_GateProxy_Handle xdc_runtime_LoggerBuf_Module_GateProxy_create( const xdc_runtime_LoggerBuf_Module_GateProxy_Params *prms, xdc_runtime_Error_Block *eb )
{
    return (xdc_runtime_LoggerBuf_Module_GateProxy_Handle)ti_sysbios_gates_GateHwi_create((const ti_sysbios_gates_GateHwi_Params *)prms, eb);
}

/* delete */
void xdc_runtime_LoggerBuf_Module_GateProxy_delete(xdc_runtime_LoggerBuf_Module_GateProxy_Handle *instp)
{
    ti_sysbios_gates_GateHwi_Object__delete__S(instp);
}

/* Params__init__S */
void xdc_runtime_LoggerBuf_Module_GateProxy_Params__init__S( xdc_Ptr dst, const void *src, xdc_SizeT psz, xdc_SizeT isz )
{
    ti_sysbios_gates_GateHwi_Params__init__S(dst, src, psz, isz);
}

/* Handle__label__S */
xdc_runtime_Types_Label *xdc_runtime_LoggerBuf_Module_GateProxy_Handle__label__S(xdc_Ptr obj, xdc_runtime_Types_Label *lab)
{
    return ti_sysbios_gates_GateHwi_Handle__label__S(obj, lab);
}

/* query__E */
xdc_Bool xdc_runtime_LoggerBuf_Module_GateProxy_query__E( xdc_Int qual )
{
    return ti_sysbios_gates_GateHwi_query(qual);
}

/* enter__E */
xdc_IArg xdc_runtime_LoggerBuf_Module_GateProxy_enter__E( xdc_runtime_LoggerBuf_Module_GateProxy_Handle inst )
{
    return ti_sysbios_gates_GateHwi_enter((ti_sysbios_gates_GateHwi_Handle)inst);
}

/* leave__E */
xdc_Void xdc_runtime_LoggerBuf_Module_GateProxy_leave__E( xdc_runtime_LoggerBuf_Module_GateProxy_Handle inst, xdc_IArg key )
{
    ti_sysbios_gates_GateHwi_leave((ti_sysbios_gates_GateHwi_Handle)inst, key);
}


/*
 * ======== xdc.runtime.LoggerBuf_TimestampProxy PROXY BODY ========
 */

/* DELEGATES TO ti.sysbios.family.c28.f2837x.TimestampProvider */

/* Module__startupDone__S */
xdc_Bool xdc_runtime_LoggerBuf_TimestampProxy_Module__startupDone__S(void)
{
    return ti_sysbios_family_c28_f2837x_TimestampProvider_Module__startupDone__S();
}

/* get32__E */
xdc_Bits32 xdc_runtime_LoggerBuf_TimestampProxy_get32__E( void )
{
    return ti_sysbios_family_c28_f2837x_TimestampProvider_get32();
}

/* get64__E */
xdc_Void xdc_runtime_LoggerBuf_TimestampProxy_get64__E( xdc_runtime_Types_Timestamp64 *result )
{
    ti_sysbios_family_c28_f2837x_TimestampProvider_get64(result);
}

/* getFreq__E */
xdc_Void xdc_runtime_LoggerBuf_TimestampProxy_getFreq__E( xdc_runtime_Types_FreqHz *freq )
{
    ti_sysbios_family_c28_f2837x_TimestampProvider_getFreq(freq);
}


/*
 * ======== xdc.runtime.Main_Module_GateProxy PROXY BODY ========
 */

/* DELEGATES TO ti.sysbios.gates.GateHwi */

/* Module__startupDone__S */
xdc_Bool xdc_runtime_Main_Module_GateProxy_Module__startupDone__S(void)
{
    return ti_sysbios_gates_GateHwi_Module__startupDone__S();
}

/* create */
xdc_runtime_Main_Module_GateProxy_Handle xdc_runtime_Main_Module_GateProxy_create( const xdc_runtime_Main_Module_GateProxy_Params *prms, xdc_runtime_Error_Block *eb )
{
    return (xdc_runtime_Main_Module_GateProxy_Handle)ti_sysbios_gates_GateHwi_create((const ti_sysbios_gates_GateHwi_Params *)prms, eb);
}

/* delete */
void xdc_runtime_Main_Module_GateProxy_delete(xdc_runtime_Main_Module_GateProxy_Handle *instp)
{
    ti_sysbios_gates_GateHwi_Object__delete__S(instp);
}

/* Params__init__S */
void xdc_runtime_Main_Module_GateProxy_Params__init__S( xdc_Ptr dst, const void *src, xdc_SizeT psz, xdc_SizeT isz )
{
    ti_sysbios_gates_GateHwi_Params__init__S(dst, src, psz, isz);
}

/* Handle__label__S */
xdc_runtime_Types_Label *xdc_runtime_Main_Module_GateProxy_Handle__label__S(xdc_Ptr obj, xdc_runtime_Types_Label *lab)
{
    return ti_sysbios_gates_GateHwi_Handle__label__S(obj, lab);
}

/* query__E */
xdc_Bool xdc_runtime_Main_Module_GateProxy_query__E( xdc_Int qual )
{
    return ti_sysbios_gates_GateHwi_query(qual);
}

/* enter__E */
xdc_IArg xdc_runtime_Main_Module_GateProxy_enter__E( xdc_runtime_Main_Module_GateProxy_Handle inst )
{
    return ti_sysbios_gates_GateHwi_enter((ti_sysbios_gates_GateHwi_Handle)inst);
}

/* leave__E */
xdc_Void xdc_runtime_Main_Module_GateProxy_leave__E( xdc_runtime_Main_Module_GateProxy_Handle inst, xdc_IArg key )
{
    ti_sysbios_gates_GateHwi_leave((ti_sysbios_gates_GateHwi_Handle)inst, key);
}


/*
 * ======== xdc.runtime.Memory_HeapProxy PROXY BODY ========
 */

/* DELEGATES TO ti.sysbios.heaps.HeapMem */

/* Module__startupDone__S */
xdc_Bool xdc_runtime_Memory_HeapProxy_Module__startupDone__S(void)
{
    return ti_sysbios_heaps_HeapMem_Module__startupDone__S();
}

/* create */
xdc_runtime_Memory_HeapProxy_Handle xdc_runtime_Memory_HeapProxy_create( const xdc_runtime_Memory_HeapProxy_Params *prms, xdc_runtime_Error_Block *eb )
{
    return (xdc_runtime_Memory_HeapProxy_Handle)ti_sysbios_heaps_HeapMem_create((const ti_sysbios_heaps_HeapMem_Params *)prms, eb);
}

/* delete */
void xdc_runtime_Memory_HeapProxy_delete(xdc_runtime_Memory_HeapProxy_Handle *instp)
{
    ti_sysbios_heaps_HeapMem_Object__delete__S(instp);
}

/* Params__init__S */
void xdc_runtime_Memory_HeapProxy_Params__init__S( xdc_Ptr dst, const void *src, xdc_SizeT psz, xdc_SizeT isz )
{
    ti_sysbios_heaps_HeapMem_Params__init__S(dst, src, psz, isz);
}

/* Handle__label__S */
xdc_runtime_Types_Label *xdc_runtime_Memory_HeapProxy_Handle__label__S(xdc_Ptr obj, xdc_runtime_Types_Label *lab)
{
    return ti_sysbios_heaps_HeapMem_Handle__label__S(obj, lab);
}

/* alloc__E */
xdc_Ptr xdc_runtime_Memory_HeapProxy_alloc__E( xdc_runtime_Memory_HeapProxy_Handle inst, xdc_SizeT size, xdc_SizeT align, xdc_runtime_Error_Block *eb )
{
    return xdc_runtime_IHeap_alloc((xdc_runtime_IHeap_Handle)inst, size, align, eb);
}

/* free__E */
xdc_Void xdc_runtime_Memory_HeapProxy_free__E( xdc_runtime_Memory_HeapProxy_Handle inst, xdc_Ptr block, xdc_SizeT size )
{
    xdc_runtime_IHeap_free((xdc_runtime_IHeap_Handle)inst, block, size);
}

/* isBlocking__E */
xdc_Bool xdc_runtime_Memory_HeapProxy_isBlocking__E( xdc_runtime_Memory_HeapProxy_Handle inst )
{
    return xdc_runtime_IHeap_isBlocking((xdc_runtime_IHeap_Handle)inst);
}

/* getStats__E */
xdc_Void xdc_runtime_Memory_HeapProxy_getStats__E( xdc_runtime_Memory_HeapProxy_Handle inst, xdc_runtime_Memory_Stats *stats )
{
    xdc_runtime_IHeap_getStats((xdc_runtime_IHeap_Handle)inst, stats);
}


/*
 * ======== xdc.runtime.System_Module_GateProxy PROXY BODY ========
 */

/* DELEGATES TO ti.sysbios.gates.GateHwi */

/* Module__startupDone__S */
xdc_Bool xdc_runtime_System_Module_GateProxy_Module__startupDone__S(void)
{
    return ti_sysbios_gates_GateHwi_Module__startupDone__S();
}

/* create */
xdc_runtime_System_Module_GateProxy_Handle xdc_runtime_System_Module_GateProxy_create( const xdc_runtime_System_Module_GateProxy_Params *prms, xdc_runtime_Error_Block *eb )
{
    return (xdc_runtime_System_Module_GateProxy_Handle)ti_sysbios_gates_GateHwi_create((const ti_sysbios_gates_GateHwi_Params *)prms, eb);
}

/* delete */
void xdc_runtime_System_Module_GateProxy_delete(xdc_runtime_System_Module_GateProxy_Handle *instp)
{
    ti_sysbios_gates_GateHwi_Object__delete__S(instp);
}

/* Params__init__S */
void xdc_runtime_System_Module_GateProxy_Params__init__S( xdc_Ptr dst, const void *src, xdc_SizeT psz, xdc_SizeT isz )
{
    ti_sysbios_gates_GateHwi_Params__init__S(dst, src, psz, isz);
}

/* Handle__label__S */
xdc_runtime_Types_Label *xdc_runtime_System_Module_GateProxy_Handle__label__S(xdc_Ptr obj, xdc_runtime_Types_Label *lab)
{
    return ti_sysbios_gates_GateHwi_Handle__label__S(obj, lab);
}

/* query__E */
xdc_Bool xdc_runtime_System_Module_GateProxy_query__E( xdc_Int qual )
{
    return ti_sysbios_gates_GateHwi_query(qual);
}

/* enter__E */
xdc_IArg xdc_runtime_System_Module_GateProxy_enter__E( xdc_runtime_System_Module_GateProxy_Handle inst )
{
    return ti_sysbios_gates_GateHwi_enter((ti_sysbios_gates_GateHwi_Handle)inst);
}

/* leave__E */
xdc_Void xdc_runtime_System_Module_GateProxy_leave__E( xdc_runtime_System_Module_GateProxy_Handle inst, xdc_IArg key )
{
    ti_sysbios_gates_GateHwi_leave((ti_sysbios_gates_GateHwi_Handle)inst, key);
}


/*
 * ======== xdc.runtime.System_SupportProxy PROXY BODY ========
 */

/* DELEGATES TO xdc.runtime.SysMin */

/* Module__startupDone__S */
xdc_Bool xdc_runtime_System_SupportProxy_Module__startupDone__S(void)
{
    return xdc_runtime_SysMin_Module__startupDone__S();
}

/* abort__E */
xdc_Void xdc_runtime_System_SupportProxy_abort__E( xdc_CString str )
{
    xdc_runtime_SysMin_abort(str);
}

/* exit__E */
xdc_Void xdc_runtime_System_SupportProxy_exit__E( xdc_Int stat )
{
    xdc_runtime_SysMin_exit(stat);
}

/* flush__E */
xdc_Void xdc_runtime_System_SupportProxy_flush__E( void )
{
    xdc_runtime_SysMin_flush();
}

/* putch__E */
xdc_Void xdc_runtime_System_SupportProxy_putch__E( xdc_Char ch )
{
    xdc_runtime_SysMin_putch(ch);
}

/* ready__E */
xdc_Bool xdc_runtime_System_SupportProxy_ready__E( void )
{
    return xdc_runtime_SysMin_ready();
}


/*
 * ======== ti.sysbios.family.c28.Hwi OBJECT DESCRIPTOR ========
 */

/* Object__DESC__C */
typedef struct { ti_sysbios_family_c28_Hwi_Object2__ s0; char c; } ti_sysbios_family_c28_Hwi___S1;
#pragma DATA_SECTION(ti_sysbios_family_c28_Hwi_Object__DESC__C, ".econst:ti_sysbios_family_c28_Hwi_Object__DESC__C");
asm("	.sect \".econst:ti_sysbios_family_c28_Hwi_Object__DESC__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_Hwi_Object__DESC__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_Hwi_Object__DESC__C\"");
asm("	.clink ");

__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_family_c28_Hwi_Object__DESC__C = {
    (xdc_CPtr)NULL, /* fxnTab */
    &ti_sysbios_family_c28_Hwi_Module__root__V.link, /* modLink */
    sizeof(ti_sysbios_family_c28_Hwi___S1) - sizeof(ti_sysbios_family_c28_Hwi_Object2__), /* objAlign */
    0, /* objHeap */
    0, /* objName */
    sizeof(ti_sysbios_family_c28_Hwi_Object2__), /* objSize */
    (xdc_CPtr)&ti_sysbios_family_c28_Hwi_Object__PARAMS__C, /* prmsInit */
    sizeof(ti_sysbios_family_c28_Hwi_Params), /* prmsSize */
};


/*
 * ======== ti.sysbios.family.c28.Timer OBJECT DESCRIPTOR ========
 */

/* Object__DESC__C */
typedef struct { ti_sysbios_family_c28_Timer_Object2__ s0; char c; } ti_sysbios_family_c28_Timer___S1;
#pragma DATA_SECTION(ti_sysbios_family_c28_Timer_Object__DESC__C, ".econst:ti_sysbios_family_c28_Timer_Object__DESC__C");
asm("	.sect \".econst:ti_sysbios_family_c28_Timer_Object__DESC__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_family_c28_Timer_Object__DESC__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_family_c28_Timer_Object__DESC__C\"");
asm("	.clink ");

__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_family_c28_Timer_Object__DESC__C = {
    (xdc_CPtr)NULL, /* fxnTab */
    &ti_sysbios_family_c28_Timer_Module__root__V.link, /* modLink */
    sizeof(ti_sysbios_family_c28_Timer___S1) - sizeof(ti_sysbios_family_c28_Timer_Object2__), /* objAlign */
    0, /* objHeap */
    0, /* objName */
    sizeof(ti_sysbios_family_c28_Timer_Object2__), /* objSize */
    (xdc_CPtr)&ti_sysbios_family_c28_Timer_Object__PARAMS__C, /* prmsInit */
    sizeof(ti_sysbios_family_c28_Timer_Params), /* prmsSize */
};


/*
 * ======== ti.sysbios.gates.GateHwi OBJECT DESCRIPTOR ========
 */

/* Object__DESC__C */
typedef struct { ti_sysbios_gates_GateHwi_Object2__ s0; char c; } ti_sysbios_gates_GateHwi___S1;
#pragma DATA_SECTION(ti_sysbios_gates_GateHwi_Object__DESC__C, ".econst:ti_sysbios_gates_GateHwi_Object__DESC__C");
asm("	.sect \".econst:ti_sysbios_gates_GateHwi_Object__DESC__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_gates_GateHwi_Object__DESC__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_gates_GateHwi_Object__DESC__C\"");
asm("	.clink ");

__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_gates_GateHwi_Object__DESC__C = {
    (xdc_CPtr)&ti_sysbios_gates_GateHwi_Module__FXNS__C, /* fxnTab */
    &ti_sysbios_gates_GateHwi_Module__root__V.link, /* modLink */
    sizeof(ti_sysbios_gates_GateHwi___S1) - sizeof(ti_sysbios_gates_GateHwi_Object2__), /* objAlign */
    0, /* objHeap */
    0, /* objName */
    sizeof(ti_sysbios_gates_GateHwi_Object2__), /* objSize */
    (xdc_CPtr)&ti_sysbios_gates_GateHwi_Object__PARAMS__C, /* prmsInit */
    sizeof(ti_sysbios_gates_GateHwi_Params), /* prmsSize */
};


/*
 * ======== ti.sysbios.gates.GateMutex OBJECT DESCRIPTOR ========
 */

/* Object__DESC__C */
typedef struct { ti_sysbios_gates_GateMutex_Object2__ s0; char c; } ti_sysbios_gates_GateMutex___S1;
#pragma DATA_SECTION(ti_sysbios_gates_GateMutex_Object__DESC__C, ".econst:ti_sysbios_gates_GateMutex_Object__DESC__C");
asm("	.sect \".econst:ti_sysbios_gates_GateMutex_Object__DESC__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_gates_GateMutex_Object__DESC__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_gates_GateMutex_Object__DESC__C\"");
asm("	.clink ");

__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_gates_GateMutex_Object__DESC__C = {
    (xdc_CPtr)&ti_sysbios_gates_GateMutex_Module__FXNS__C, /* fxnTab */
    &ti_sysbios_gates_GateMutex_Module__root__V.link, /* modLink */
    sizeof(ti_sysbios_gates_GateMutex___S1) - sizeof(ti_sysbios_gates_GateMutex_Object2__), /* objAlign */
    0, /* objHeap */
    0, /* objName */
    sizeof(ti_sysbios_gates_GateMutex_Object2__), /* objSize */
    (xdc_CPtr)&ti_sysbios_gates_GateMutex_Object__PARAMS__C, /* prmsInit */
    sizeof(ti_sysbios_gates_GateMutex_Params), /* prmsSize */
};


/*
 * ======== ti.sysbios.hal.Hwi OBJECT DESCRIPTOR ========
 */

/* Object__DESC__C */
typedef struct { ti_sysbios_hal_Hwi_Object2__ s0; char c; } ti_sysbios_hal_Hwi___S1;
#pragma DATA_SECTION(ti_sysbios_hal_Hwi_Object__DESC__C, ".econst:ti_sysbios_hal_Hwi_Object__DESC__C");
asm("	.sect \".econst:ti_sysbios_hal_Hwi_Object__DESC__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_hal_Hwi_Object__DESC__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_hal_Hwi_Object__DESC__C\"");
asm("	.clink ");

__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_hal_Hwi_Object__DESC__C = {
    (xdc_CPtr)NULL, /* fxnTab */
    &ti_sysbios_hal_Hwi_Module__root__V.link, /* modLink */
    sizeof(ti_sysbios_hal_Hwi___S1) - sizeof(ti_sysbios_hal_Hwi_Object2__), /* objAlign */
    0, /* objHeap */
    0, /* objName */
    sizeof(ti_sysbios_hal_Hwi_Object2__), /* objSize */
    (xdc_CPtr)&ti_sysbios_hal_Hwi_Object__PARAMS__C, /* prmsInit */
    sizeof(ti_sysbios_hal_Hwi_Params), /* prmsSize */
};


/*
 * ======== ti.sysbios.heaps.HeapMem OBJECT DESCRIPTOR ========
 */

/* Object__DESC__C */
typedef struct { ti_sysbios_heaps_HeapMem_Object2__ s0; char c; } ti_sysbios_heaps_HeapMem___S1;
#pragma DATA_SECTION(ti_sysbios_heaps_HeapMem_Object__DESC__C, ".econst:ti_sysbios_heaps_HeapMem_Object__DESC__C");
asm("	.sect \".econst:ti_sysbios_heaps_HeapMem_Object__DESC__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_heaps_HeapMem_Object__DESC__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_heaps_HeapMem_Object__DESC__C\"");
asm("	.clink ");

__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_heaps_HeapMem_Object__DESC__C = {
    (xdc_CPtr)&ti_sysbios_heaps_HeapMem_Module__FXNS__C, /* fxnTab */
    &ti_sysbios_heaps_HeapMem_Module__root__V.link, /* modLink */
    sizeof(ti_sysbios_heaps_HeapMem___S1) - sizeof(ti_sysbios_heaps_HeapMem_Object2__), /* objAlign */
    0, /* objHeap */
    0, /* objName */
    sizeof(ti_sysbios_heaps_HeapMem_Object2__), /* objSize */
    (xdc_CPtr)&ti_sysbios_heaps_HeapMem_Object__PARAMS__C, /* prmsInit */
    sizeof(ti_sysbios_heaps_HeapMem_Params), /* prmsSize */
};


/*
 * ======== ti.sysbios.knl.Clock OBJECT DESCRIPTOR ========
 */

/* Object__DESC__C */
typedef struct { ti_sysbios_knl_Clock_Object2__ s0; char c; } ti_sysbios_knl_Clock___S1;
#pragma DATA_SECTION(ti_sysbios_knl_Clock_Object__DESC__C, ".econst:ti_sysbios_knl_Clock_Object__DESC__C");
asm("	.sect \".econst:ti_sysbios_knl_Clock_Object__DESC__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Clock_Object__DESC__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Clock_Object__DESC__C\"");
asm("	.clink ");

__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_knl_Clock_Object__DESC__C = {
    (xdc_CPtr)-1, /* fxnTab */
    &ti_sysbios_knl_Clock_Module__root__V.link, /* modLink */
    sizeof(ti_sysbios_knl_Clock___S1) - sizeof(ti_sysbios_knl_Clock_Object2__), /* objAlign */
    0, /* objHeap */
    0, /* objName */
    sizeof(ti_sysbios_knl_Clock_Object2__), /* objSize */
    (xdc_CPtr)&ti_sysbios_knl_Clock_Object__PARAMS__C, /* prmsInit */
    sizeof(ti_sysbios_knl_Clock_Params), /* prmsSize */
};


/*
 * ======== ti.sysbios.knl.Queue OBJECT DESCRIPTOR ========
 */

/* Object__DESC__C */
typedef struct { ti_sysbios_knl_Queue_Object2__ s0; char c; } ti_sysbios_knl_Queue___S1;
#pragma DATA_SECTION(ti_sysbios_knl_Queue_Object__DESC__C, ".econst:ti_sysbios_knl_Queue_Object__DESC__C");
asm("	.sect \".econst:ti_sysbios_knl_Queue_Object__DESC__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Queue_Object__DESC__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Queue_Object__DESC__C\"");
asm("	.clink ");

__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_knl_Queue_Object__DESC__C = {
    (xdc_CPtr)-1, /* fxnTab */
    &ti_sysbios_knl_Queue_Module__root__V.link, /* modLink */
    sizeof(ti_sysbios_knl_Queue___S1) - sizeof(ti_sysbios_knl_Queue_Object2__), /* objAlign */
    0, /* objHeap */
    0, /* objName */
    sizeof(ti_sysbios_knl_Queue_Object2__), /* objSize */
    (xdc_CPtr)&ti_sysbios_knl_Queue_Object__PARAMS__C, /* prmsInit */
    sizeof(ti_sysbios_knl_Queue_Params), /* prmsSize */
};


/*
 * ======== ti.sysbios.knl.Semaphore OBJECT DESCRIPTOR ========
 */

/* Object__DESC__C */
typedef struct { ti_sysbios_knl_Semaphore_Object2__ s0; char c; } ti_sysbios_knl_Semaphore___S1;
#pragma DATA_SECTION(ti_sysbios_knl_Semaphore_Object__DESC__C, ".econst:ti_sysbios_knl_Semaphore_Object__DESC__C");
asm("	.sect \".econst:ti_sysbios_knl_Semaphore_Object__DESC__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Semaphore_Object__DESC__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Semaphore_Object__DESC__C\"");
asm("	.clink ");

__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_knl_Semaphore_Object__DESC__C = {
    (xdc_CPtr)-1, /* fxnTab */
    &ti_sysbios_knl_Semaphore_Module__root__V.link, /* modLink */
    sizeof(ti_sysbios_knl_Semaphore___S1) - sizeof(ti_sysbios_knl_Semaphore_Object2__), /* objAlign */
    0, /* objHeap */
    0, /* objName */
    sizeof(ti_sysbios_knl_Semaphore_Object2__), /* objSize */
    (xdc_CPtr)&ti_sysbios_knl_Semaphore_Object__PARAMS__C, /* prmsInit */
    sizeof(ti_sysbios_knl_Semaphore_Params), /* prmsSize */
};


/*
 * ======== ti.sysbios.knl.Swi OBJECT DESCRIPTOR ========
 */

/* Object__DESC__C */
typedef struct { ti_sysbios_knl_Swi_Object2__ s0; char c; } ti_sysbios_knl_Swi___S1;
#pragma DATA_SECTION(ti_sysbios_knl_Swi_Object__DESC__C, ".econst:ti_sysbios_knl_Swi_Object__DESC__C");
asm("	.sect \".econst:ti_sysbios_knl_Swi_Object__DESC__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Swi_Object__DESC__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Swi_Object__DESC__C\"");
asm("	.clink ");

__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_knl_Swi_Object__DESC__C = {
    (xdc_CPtr)-1, /* fxnTab */
    &ti_sysbios_knl_Swi_Module__root__V.link, /* modLink */
    sizeof(ti_sysbios_knl_Swi___S1) - sizeof(ti_sysbios_knl_Swi_Object2__), /* objAlign */
    0, /* objHeap */
    0, /* objName */
    sizeof(ti_sysbios_knl_Swi_Object2__), /* objSize */
    (xdc_CPtr)&ti_sysbios_knl_Swi_Object__PARAMS__C, /* prmsInit */
    sizeof(ti_sysbios_knl_Swi_Params), /* prmsSize */
};


/*
 * ======== ti.sysbios.knl.Task OBJECT DESCRIPTOR ========
 */

/* Object__DESC__C */
typedef struct { ti_sysbios_knl_Task_Object2__ s0; char c; } ti_sysbios_knl_Task___S1;
#pragma DATA_SECTION(ti_sysbios_knl_Task_Object__DESC__C, ".econst:ti_sysbios_knl_Task_Object__DESC__C");
asm("	.sect \".econst:ti_sysbios_knl_Task_Object__DESC__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:ti_sysbios_knl_Task_Object__DESC__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:ti_sysbios_knl_Task_Object__DESC__C\"");
asm("	.clink ");

__FAR__ const xdc_runtime_Core_ObjDesc ti_sysbios_knl_Task_Object__DESC__C = {
    (xdc_CPtr)-1, /* fxnTab */
    &ti_sysbios_knl_Task_Module__root__V.link, /* modLink */
    sizeof(ti_sysbios_knl_Task___S1) - sizeof(ti_sysbios_knl_Task_Object2__), /* objAlign */
    0, /* objHeap */
    0, /* objName */
    sizeof(ti_sysbios_knl_Task_Object2__), /* objSize */
    (xdc_CPtr)&ti_sysbios_knl_Task_Object__PARAMS__C, /* prmsInit */
    sizeof(ti_sysbios_knl_Task_Params), /* prmsSize */
};


/*
 * ======== xdc.runtime.LoggerBuf OBJECT DESCRIPTOR ========
 */

/* Object__DESC__C */
typedef struct { xdc_runtime_LoggerBuf_Object2__ s0; char c; } xdc_runtime_LoggerBuf___S1;
#pragma DATA_SECTION(xdc_runtime_LoggerBuf_Object__DESC__C, ".econst:xdc_runtime_LoggerBuf_Object__DESC__C");
asm("	.sect \".econst:xdc_runtime_LoggerBuf_Object__DESC__C\"");
asm("	.clink ");
asm("	.sect \"[0].econst:xdc_runtime_LoggerBuf_Object__DESC__C\"");
asm("	.clink ");
asm("	.sect \"[1].econst:xdc_runtime_LoggerBuf_Object__DESC__C\"");
asm("	.clink ");

__FAR__ const xdc_runtime_Core_ObjDesc xdc_runtime_LoggerBuf_Object__DESC__C = {
    (xdc_CPtr)&xdc_runtime_LoggerBuf_Module__FXNS__C, /* fxnTab */
    &xdc_runtime_LoggerBuf_Module__root__V.link, /* modLink */
    sizeof(xdc_runtime_LoggerBuf___S1) - sizeof(xdc_runtime_LoggerBuf_Object2__), /* objAlign */
    0, /* objHeap */
    0, /* objName */
    sizeof(xdc_runtime_LoggerBuf_Object2__), /* objSize */
    (xdc_CPtr)&xdc_runtime_LoggerBuf_Object__PARAMS__C, /* prmsInit */
    sizeof(xdc_runtime_LoggerBuf_Params), /* prmsSize */
};


/*
 * ======== xdc.runtime.IGateProvider VIRTUAL FUNCTIONS ========
 */

/* create */
xdc_runtime_IGateProvider_Handle xdc_runtime_IGateProvider_create( xdc_runtime_IGateProvider_Module mod, const xdc_runtime_IGateProvider_Params *prms, xdc_runtime_Error_Block *eb )
{
    return (xdc_runtime_IGateProvider_Handle) mod->__sysp->__create(0, (const xdc_UChar*)prms, sizeof (xdc_runtime_IGateProvider_Params), eb);
}

/* delete */
void xdc_runtime_IGateProvider_delete( xdc_runtime_IGateProvider_Handle *instp )
{
    (*instp)->__fxns->__sysp->__delete(instp);
}


/*
 * ======== xdc.runtime.IFilterLogger VIRTUAL FUNCTIONS ========
 */

/* create */
xdc_runtime_IFilterLogger_Handle xdc_runtime_IFilterLogger_create( xdc_runtime_IFilterLogger_Module mod, const xdc_runtime_IFilterLogger_Params *prms, xdc_runtime_Error_Block *eb )
{
    return (xdc_runtime_IFilterLogger_Handle) mod->__sysp->__create(0, (const xdc_UChar*)prms, sizeof (xdc_runtime_IFilterLogger_Params), eb);
}

/* delete */
void xdc_runtime_IFilterLogger_delete( xdc_runtime_IFilterLogger_Handle *instp )
{
    (*instp)->__fxns->__sysp->__delete(instp);
}


/*
 * ======== xdc.runtime.ILogger VIRTUAL FUNCTIONS ========
 */

/* create */
xdc_runtime_ILogger_Handle xdc_runtime_ILogger_create( xdc_runtime_ILogger_Module mod, const xdc_runtime_ILogger_Params *prms, xdc_runtime_Error_Block *eb )
{
    return (xdc_runtime_ILogger_Handle) mod->__sysp->__create(0, (const xdc_UChar*)prms, sizeof (xdc_runtime_ILogger_Params), eb);
}

/* delete */
void xdc_runtime_ILogger_delete( xdc_runtime_ILogger_Handle *instp )
{
    (*instp)->__fxns->__sysp->__delete(instp);
}


/*
 * ======== xdc.runtime.IHeap VIRTUAL FUNCTIONS ========
 */

/* create */
xdc_runtime_IHeap_Handle xdc_runtime_IHeap_create( xdc_runtime_IHeap_Module mod, const xdc_runtime_IHeap_Params *prms, xdc_runtime_Error_Block *eb )
{
    return (xdc_runtime_IHeap_Handle) mod->__sysp->__create(0, (const xdc_UChar*)prms, sizeof (xdc_runtime_IHeap_Params), eb);
}

/* delete */
void xdc_runtime_IHeap_delete( xdc_runtime_IHeap_Handle *instp )
{
    (*instp)->__fxns->__sysp->__delete(instp);
}


/*
 * ======== ti.sysbios.BIOS SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool ti_sysbios_BIOS_Module__startupDone__S( void )
{
    return 1;
}



/*
 * ======== ti.sysbios.BIOS_RtsGateProxy SYSTEM FUNCTIONS ========
 */

/* per-module runtime symbols */
#undef Module__MID
#define Module__MID ti_sysbios_BIOS_RtsGateProxy_Module__id__C

#undef Module__DGSINCL
#define Module__DGSINCL ti_sysbios_BIOS_RtsGateProxy_Module__diagsIncluded__C

#undef Module__DGSENAB
#define Module__DGSENAB ti_sysbios_BIOS_RtsGateProxy_Module__diagsEnabled__C

#undef Module__DGSMASK
#define Module__DGSMASK ti_sysbios_BIOS_RtsGateProxy_Module__diagsMask__C

#undef Module__LOGDEF
#define Module__LOGDEF ti_sysbios_BIOS_RtsGateProxy_Module__loggerDefined__C

#undef Module__LOGOBJ
#define Module__LOGOBJ ti_sysbios_BIOS_RtsGateProxy_Module__loggerObj__C

#undef Module__LOGFXN0
#define Module__LOGFXN0 ti_sysbios_BIOS_RtsGateProxy_Module__loggerFxn0__C

#undef Module__LOGFXN1
#define Module__LOGFXN1 ti_sysbios_BIOS_RtsGateProxy_Module__loggerFxn1__C

#undef Module__LOGFXN2
#define Module__LOGFXN2 ti_sysbios_BIOS_RtsGateProxy_Module__loggerFxn2__C

#undef Module__LOGFXN4
#define Module__LOGFXN4 ti_sysbios_BIOS_RtsGateProxy_Module__loggerFxn4__C

#undef Module__LOGFXN8
#define Module__LOGFXN8 ti_sysbios_BIOS_RtsGateProxy_Module__loggerFxn8__C

#undef Module__G_OBJ
#define Module__G_OBJ ti_sysbios_BIOS_RtsGateProxy_Module__gateObj__C

#undef Module__G_PRMS
#define Module__G_PRMS ti_sysbios_BIOS_RtsGateProxy_Module__gatePrms__C

#undef Module__GP_create
#define Module__GP_create ti_sysbios_BIOS_RtsGateProxy_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete ti_sysbios_BIOS_RtsGateProxy_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter ti_sysbios_BIOS_RtsGateProxy_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave ti_sysbios_BIOS_RtsGateProxy_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query ti_sysbios_BIOS_RtsGateProxy_Module_GateProxy_query

xdc_Bool ti_sysbios_BIOS_RtsGateProxy_Proxy__abstract__S(void)
{
    return 0;
}
xdc_CPtr ti_sysbios_BIOS_RtsGateProxy_Proxy__delegate__S(void)
{
    return (const void *)&ti_sysbios_gates_GateMutex_Module__FXNS__C;
}



/*
 * ======== ti.sysbios.family.c28.Hwi SYSTEM FUNCTIONS ========
 */

/* per-module runtime symbols */
#undef Module__MID
#define Module__MID ti_sysbios_family_c28_Hwi_Module__id__C

#undef Module__DGSINCL
#define Module__DGSINCL ti_sysbios_family_c28_Hwi_Module__diagsIncluded__C

#undef Module__DGSENAB
#define Module__DGSENAB ti_sysbios_family_c28_Hwi_Module__diagsEnabled__C

#undef Module__DGSMASK
#define Module__DGSMASK ti_sysbios_family_c28_Hwi_Module__diagsMask__C

#undef Module__LOGDEF
#define Module__LOGDEF ti_sysbios_family_c28_Hwi_Module__loggerDefined__C

#undef Module__LOGOBJ
#define Module__LOGOBJ ti_sysbios_family_c28_Hwi_Module__loggerObj__C

#undef Module__LOGFXN0
#define Module__LOGFXN0 ti_sysbios_family_c28_Hwi_Module__loggerFxn0__C

#undef Module__LOGFXN1
#define Module__LOGFXN1 ti_sysbios_family_c28_Hwi_Module__loggerFxn1__C

#undef Module__LOGFXN2
#define Module__LOGFXN2 ti_sysbios_family_c28_Hwi_Module__loggerFxn2__C

#undef Module__LOGFXN4
#define Module__LOGFXN4 ti_sysbios_family_c28_Hwi_Module__loggerFxn4__C

#undef Module__LOGFXN8
#define Module__LOGFXN8 ti_sysbios_family_c28_Hwi_Module__loggerFxn8__C

#undef Module__G_OBJ
#define Module__G_OBJ ti_sysbios_family_c28_Hwi_Module__gateObj__C

#undef Module__G_PRMS
#define Module__G_PRMS ti_sysbios_family_c28_Hwi_Module__gatePrms__C

#undef Module__GP_create
#define Module__GP_create ti_sysbios_family_c28_Hwi_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete ti_sysbios_family_c28_Hwi_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter ti_sysbios_family_c28_Hwi_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave ti_sysbios_family_c28_Hwi_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query ti_sysbios_family_c28_Hwi_Module_GateProxy_query

/* Module__startupDone__S */
xdc_Bool ti_sysbios_family_c28_Hwi_Module__startupDone__S( void )
{
    return ti_sysbios_family_c28_Hwi_Module__startupDone__F();
}

/* Handle__label__S */
xdc_runtime_Types_Label *ti_sysbios_family_c28_Hwi_Handle__label__S(xdc_Ptr obj, xdc_runtime_Types_Label *lab) 
{
    lab->handle = obj;
    lab->modId = 32789;
    lab->named = FALSE;
    lab->iname = xdc_runtime_Text_nameUnknown;

    return lab;
}

/* Params__init__S */
xdc_Void ti_sysbios_family_c28_Hwi_Params__init__S( xdc_Ptr prms, const void *src, xdc_SizeT psz, xdc_SizeT isz ) 
{
    xdc_runtime_Core_assignParams__I(prms, (xdc_CPtr)(src ? src : &ti_sysbios_family_c28_Hwi_Object__PARAMS__C), psz, isz);
}

/* Object__get__S */
xdc_Ptr ti_sysbios_family_c28_Hwi_Object__get__S(xdc_Ptr oa, xdc_Int i)
{
    if (oa != NULL) {
        return ((ti_sysbios_family_c28_Hwi_Object__ *)oa) + i;
    }

    /* the bogus 'const' in the cast suppresses Klocwork MISRA complaints */
    return ((ti_sysbios_family_c28_Hwi_Object__ * const)ti_sysbios_family_c28_Hwi_Object__table__C) + i;
}

/* Object__first__S */
xdc_Ptr ti_sysbios_family_c28_Hwi_Object__first__S( void ) 
{
    xdc_runtime_Types_InstHdr *iHdr = (xdc_runtime_Types_InstHdr *)ti_sysbios_family_c28_Hwi_Module__root__V.link.next;

    if (iHdr != (xdc_runtime_Types_InstHdr *)&ti_sysbios_family_c28_Hwi_Module__root__V.link) {
        return iHdr + 1;
    }
    else {
        return NULL;
    }
}

/* Object__next__S */
xdc_Ptr ti_sysbios_family_c28_Hwi_Object__next__S( xdc_Ptr obj )
{
    xdc_runtime_Types_InstHdr *iHdr = ((xdc_runtime_Types_InstHdr *)obj) - 1;

    if (iHdr->link.next != (xdc_runtime_Types_Link *)&ti_sysbios_family_c28_Hwi_Module__root__V.link) {
        return (xdc_runtime_Types_InstHdr *)(iHdr->link.next) + 1;
    }
    else {
        return NULL;
    }
}

/* Object__create__S */
xdc_Ptr ti_sysbios_family_c28_Hwi_Object__create__S(
    xdc_CPtr req_args,
    const xdc_UChar *paramsPtr,
    xdc_SizeT prm_size,
    xdc_runtime_Error_Block *eb)
{
    const ti_sysbios_family_c28_Hwi_Args__create *__args = req_args;
    ti_sysbios_family_c28_Hwi_Params instPrms;
    ti_sysbios_family_c28_Hwi_Object *objp;
    int iStat;

    /* common instance initialization */
    objp = xdc_runtime_Core_createObject__I(&ti_sysbios_family_c28_Hwi_Object__DESC__C, NULL, &instPrms, (xdc_CPtr)paramsPtr, 0, eb);
    if (objp == NULL) {
        return NULL;
    }


    /* module-specific initialization */
    iStat = ti_sysbios_family_c28_Hwi_Instance_init__E(objp, __args->intNum, __args->hwiFxn, &instPrms, eb);
    if (iStat) {
        xdc_runtime_Core_deleteObject__I(&ti_sysbios_family_c28_Hwi_Object__DESC__C, objp, (xdc_Fxn)ti_sysbios_family_c28_Hwi_Instance_finalize__E, iStat, 0);
        return NULL;
    }

    return objp;
}

/* create */
ti_sysbios_family_c28_Hwi_Handle ti_sysbios_family_c28_Hwi_create( xdc_Int intNum, ti_sysbios_interfaces_IHwi_FuncPtr hwiFxn, const ti_sysbios_family_c28_Hwi_Params *paramsPtr, xdc_runtime_Error_Block *eb)
{
    ti_sysbios_family_c28_Hwi_Params prms;
    ti_sysbios_family_c28_Hwi_Object *obj;

    int iStat;

    /* common instance initialization */
    obj = xdc_runtime_Core_createObject__I(&ti_sysbios_family_c28_Hwi_Object__DESC__C, NULL, &prms, (xdc_CPtr)paramsPtr, 0, eb);
    if (obj == NULL) {
        return NULL;
    }

    /* module-specific initialization */
    iStat = ti_sysbios_family_c28_Hwi_Instance_init__E(obj, intNum, hwiFxn, &prms, eb);
    if (iStat) {
        xdc_runtime_Core_deleteObject__I(&ti_sysbios_family_c28_Hwi_Object__DESC__C, obj, (xdc_Fxn)ti_sysbios_family_c28_Hwi_Instance_finalize__E, iStat, 0);
        return NULL;
    }

    return obj;
}

/* construct */
void ti_sysbios_family_c28_Hwi_construct(ti_sysbios_family_c28_Hwi_Struct *objp, xdc_Int intNum, ti_sysbios_interfaces_IHwi_FuncPtr hwiFxn, const ti_sysbios_family_c28_Hwi_Params *paramsPtr, xdc_runtime_Error_Block *eb)
{
    ti_sysbios_family_c28_Hwi_Params instPrms;
    int iStat;

    /* common instance initialization */
    (Void)xdc_runtime_Core_constructObject__I(&ti_sysbios_family_c28_Hwi_Object__DESC__C, objp, &instPrms, (xdc_CPtr)paramsPtr, 0, eb);

    /* module-specific initialization */
    iStat = ti_sysbios_family_c28_Hwi_Instance_init__E((xdc_Ptr)objp, intNum, hwiFxn, &instPrms, eb);
    if (iStat) {
        xdc_runtime_Core_deleteObject__I(&ti_sysbios_family_c28_Hwi_Object__DESC__C, objp, (xdc_Fxn)ti_sysbios_family_c28_Hwi_Instance_finalize__E, iStat, 1);
    }

}

/* destruct */
void ti_sysbios_family_c28_Hwi_destruct(ti_sysbios_family_c28_Hwi_Struct *obj)
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_family_c28_Hwi_Object__DESC__C, obj, (xdc_Fxn)ti_sysbios_family_c28_Hwi_Instance_finalize__E, 0, TRUE);
}

/* Object__delete__S */
xdc_Void ti_sysbios_family_c28_Hwi_Object__delete__S( xdc_Ptr instp ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_family_c28_Hwi_Object__DESC__C, *((ti_sysbios_family_c28_Hwi_Object**)instp), (xdc_Fxn)ti_sysbios_family_c28_Hwi_Instance_finalize__E, 0, FALSE);
    *((ti_sysbios_family_c28_Hwi_Handle*)instp) = NULL;
}

/* delete */
void ti_sysbios_family_c28_Hwi_delete(ti_sysbios_family_c28_Hwi_Handle *instp)
{
    ti_sysbios_family_c28_Hwi_Object__delete__S(instp);
}


/*
 * ======== ti.sysbios.family.c28.IntrinsicsSupport SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool ti_sysbios_family_c28_IntrinsicsSupport_Module__startupDone__S( void )
{
    return 1;
}



/*
 * ======== ti.sysbios.family.c28.TaskSupport SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool ti_sysbios_family_c28_TaskSupport_Module__startupDone__S( void )
{
    return 1;
}



/*
 * ======== ti.sysbios.family.c28.Timer SYSTEM FUNCTIONS ========
 */

/* per-module runtime symbols */
#undef Module__MID
#define Module__MID ti_sysbios_family_c28_Timer_Module__id__C

#undef Module__DGSINCL
#define Module__DGSINCL ti_sysbios_family_c28_Timer_Module__diagsIncluded__C

#undef Module__DGSENAB
#define Module__DGSENAB ti_sysbios_family_c28_Timer_Module__diagsEnabled__C

#undef Module__DGSMASK
#define Module__DGSMASK ti_sysbios_family_c28_Timer_Module__diagsMask__C

#undef Module__LOGDEF
#define Module__LOGDEF ti_sysbios_family_c28_Timer_Module__loggerDefined__C

#undef Module__LOGOBJ
#define Module__LOGOBJ ti_sysbios_family_c28_Timer_Module__loggerObj__C

#undef Module__LOGFXN0
#define Module__LOGFXN0 ti_sysbios_family_c28_Timer_Module__loggerFxn0__C

#undef Module__LOGFXN1
#define Module__LOGFXN1 ti_sysbios_family_c28_Timer_Module__loggerFxn1__C

#undef Module__LOGFXN2
#define Module__LOGFXN2 ti_sysbios_family_c28_Timer_Module__loggerFxn2__C

#undef Module__LOGFXN4
#define Module__LOGFXN4 ti_sysbios_family_c28_Timer_Module__loggerFxn4__C

#undef Module__LOGFXN8
#define Module__LOGFXN8 ti_sysbios_family_c28_Timer_Module__loggerFxn8__C

#undef Module__G_OBJ
#define Module__G_OBJ ti_sysbios_family_c28_Timer_Module__gateObj__C

#undef Module__G_PRMS
#define Module__G_PRMS ti_sysbios_family_c28_Timer_Module__gatePrms__C

#undef Module__GP_create
#define Module__GP_create ti_sysbios_family_c28_Timer_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete ti_sysbios_family_c28_Timer_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter ti_sysbios_family_c28_Timer_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave ti_sysbios_family_c28_Timer_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query ti_sysbios_family_c28_Timer_Module_GateProxy_query

/* Module__startupDone__S */
xdc_Bool ti_sysbios_family_c28_Timer_Module__startupDone__S( void )
{
    return ti_sysbios_family_c28_Timer_Module__startupDone__F();
}

/* Handle__label__S */
xdc_runtime_Types_Label *ti_sysbios_family_c28_Timer_Handle__label__S(xdc_Ptr obj, xdc_runtime_Types_Label *lab) 
{
    lab->handle = obj;
    lab->modId = 32790;
    lab->named = FALSE;
    lab->iname = xdc_runtime_Text_nameUnknown;

    return lab;
}

/* Params__init__S */
xdc_Void ti_sysbios_family_c28_Timer_Params__init__S( xdc_Ptr prms, const void *src, xdc_SizeT psz, xdc_SizeT isz ) 
{
    xdc_runtime_Core_assignParams__I(prms, (xdc_CPtr)(src ? src : &ti_sysbios_family_c28_Timer_Object__PARAMS__C), psz, isz);
}

/* Object__get__S */
xdc_Ptr ti_sysbios_family_c28_Timer_Object__get__S(xdc_Ptr oa, xdc_Int i)
{
    if (oa != NULL) {
        return ((ti_sysbios_family_c28_Timer_Object__ *)oa) + i;
    }

    /* the bogus 'const' in the cast suppresses Klocwork MISRA complaints */
    return ((ti_sysbios_family_c28_Timer_Object__ * const)ti_sysbios_family_c28_Timer_Object__table__C) + i;
}

/* Object__first__S */
xdc_Ptr ti_sysbios_family_c28_Timer_Object__first__S( void ) 
{
    xdc_runtime_Types_InstHdr *iHdr = (xdc_runtime_Types_InstHdr *)ti_sysbios_family_c28_Timer_Module__root__V.link.next;

    if (iHdr != (xdc_runtime_Types_InstHdr *)&ti_sysbios_family_c28_Timer_Module__root__V.link) {
        return iHdr + 1;
    }
    else {
        return NULL;
    }
}

/* Object__next__S */
xdc_Ptr ti_sysbios_family_c28_Timer_Object__next__S( xdc_Ptr obj )
{
    xdc_runtime_Types_InstHdr *iHdr = ((xdc_runtime_Types_InstHdr *)obj) - 1;

    if (iHdr->link.next != (xdc_runtime_Types_Link *)&ti_sysbios_family_c28_Timer_Module__root__V.link) {
        return (xdc_runtime_Types_InstHdr *)(iHdr->link.next) + 1;
    }
    else {
        return NULL;
    }
}

/* Object__create__S */
xdc_Ptr ti_sysbios_family_c28_Timer_Object__create__S(
    xdc_CPtr req_args,
    const xdc_UChar *paramsPtr,
    xdc_SizeT prm_size,
    xdc_runtime_Error_Block *eb)
{
    const ti_sysbios_family_c28_Timer_Args__create *__args = req_args;
    ti_sysbios_family_c28_Timer_Params instPrms;
    ti_sysbios_family_c28_Timer_Object *objp;
    int iStat;

    /* common instance initialization */
    objp = xdc_runtime_Core_createObject__I(&ti_sysbios_family_c28_Timer_Object__DESC__C, NULL, &instPrms, (xdc_CPtr)paramsPtr, 0, eb);
    if (objp == NULL) {
        return NULL;
    }


    /* module-specific initialization */
    iStat = ti_sysbios_family_c28_Timer_Instance_init__E(objp, __args->id, __args->tickFxn, &instPrms, eb);
    if (iStat) {
        xdc_runtime_Core_deleteObject__I(&ti_sysbios_family_c28_Timer_Object__DESC__C, objp, (xdc_Fxn)ti_sysbios_family_c28_Timer_Instance_finalize__E, iStat, 0);
        return NULL;
    }

    return objp;
}

/* create */
ti_sysbios_family_c28_Timer_Handle ti_sysbios_family_c28_Timer_create( xdc_Int id, ti_sysbios_interfaces_ITimer_FuncPtr tickFxn, const ti_sysbios_family_c28_Timer_Params *paramsPtr, xdc_runtime_Error_Block *eb)
{
    ti_sysbios_family_c28_Timer_Params prms;
    ti_sysbios_family_c28_Timer_Object *obj;

    int iStat;

    /* common instance initialization */
    obj = xdc_runtime_Core_createObject__I(&ti_sysbios_family_c28_Timer_Object__DESC__C, NULL, &prms, (xdc_CPtr)paramsPtr, 0, eb);
    if (obj == NULL) {
        return NULL;
    }

    /* module-specific initialization */
    iStat = ti_sysbios_family_c28_Timer_Instance_init__E(obj, id, tickFxn, &prms, eb);
    if (iStat) {
        xdc_runtime_Core_deleteObject__I(&ti_sysbios_family_c28_Timer_Object__DESC__C, obj, (xdc_Fxn)ti_sysbios_family_c28_Timer_Instance_finalize__E, iStat, 0);
        return NULL;
    }

    return obj;
}

/* construct */
void ti_sysbios_family_c28_Timer_construct(ti_sysbios_family_c28_Timer_Struct *objp, xdc_Int id, ti_sysbios_interfaces_ITimer_FuncPtr tickFxn, const ti_sysbios_family_c28_Timer_Params *paramsPtr, xdc_runtime_Error_Block *eb)
{
    ti_sysbios_family_c28_Timer_Params instPrms;
    int iStat;

    /* common instance initialization */
    (Void)xdc_runtime_Core_constructObject__I(&ti_sysbios_family_c28_Timer_Object__DESC__C, objp, &instPrms, (xdc_CPtr)paramsPtr, 0, eb);

    /* module-specific initialization */
    iStat = ti_sysbios_family_c28_Timer_Instance_init__E((xdc_Ptr)objp, id, tickFxn, &instPrms, eb);
    if (iStat) {
        xdc_runtime_Core_deleteObject__I(&ti_sysbios_family_c28_Timer_Object__DESC__C, objp, (xdc_Fxn)ti_sysbios_family_c28_Timer_Instance_finalize__E, iStat, 1);
    }

}

/* destruct */
void ti_sysbios_family_c28_Timer_destruct(ti_sysbios_family_c28_Timer_Struct *obj)
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_family_c28_Timer_Object__DESC__C, obj, (xdc_Fxn)ti_sysbios_family_c28_Timer_Instance_finalize__E, 0, TRUE);
}

/* Object__delete__S */
xdc_Void ti_sysbios_family_c28_Timer_Object__delete__S( xdc_Ptr instp ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_family_c28_Timer_Object__DESC__C, *((ti_sysbios_family_c28_Timer_Object**)instp), (xdc_Fxn)ti_sysbios_family_c28_Timer_Instance_finalize__E, 0, FALSE);
    *((ti_sysbios_family_c28_Timer_Handle*)instp) = NULL;
}

/* delete */
void ti_sysbios_family_c28_Timer_delete(ti_sysbios_family_c28_Timer_Handle *instp)
{
    ti_sysbios_family_c28_Timer_Object__delete__S(instp);
}


/*
 * ======== ti.sysbios.family.c28.f2837x.TimestampProvider SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool ti_sysbios_family_c28_f2837x_TimestampProvider_Module__startupDone__S( void )
{
    return 1;
}



/*
 * ======== ti.sysbios.gates.GateHwi SYSTEM FUNCTIONS ========
 */

/* per-module runtime symbols */
#undef Module__MID
#define Module__MID ti_sysbios_gates_GateHwi_Module__id__C

#undef Module__DGSINCL
#define Module__DGSINCL ti_sysbios_gates_GateHwi_Module__diagsIncluded__C

#undef Module__DGSENAB
#define Module__DGSENAB ti_sysbios_gates_GateHwi_Module__diagsEnabled__C

#undef Module__DGSMASK
#define Module__DGSMASK ti_sysbios_gates_GateHwi_Module__diagsMask__C

#undef Module__LOGDEF
#define Module__LOGDEF ti_sysbios_gates_GateHwi_Module__loggerDefined__C

#undef Module__LOGOBJ
#define Module__LOGOBJ ti_sysbios_gates_GateHwi_Module__loggerObj__C

#undef Module__LOGFXN0
#define Module__LOGFXN0 ti_sysbios_gates_GateHwi_Module__loggerFxn0__C

#undef Module__LOGFXN1
#define Module__LOGFXN1 ti_sysbios_gates_GateHwi_Module__loggerFxn1__C

#undef Module__LOGFXN2
#define Module__LOGFXN2 ti_sysbios_gates_GateHwi_Module__loggerFxn2__C

#undef Module__LOGFXN4
#define Module__LOGFXN4 ti_sysbios_gates_GateHwi_Module__loggerFxn4__C

#undef Module__LOGFXN8
#define Module__LOGFXN8 ti_sysbios_gates_GateHwi_Module__loggerFxn8__C

#undef Module__G_OBJ
#define Module__G_OBJ ti_sysbios_gates_GateHwi_Module__gateObj__C

#undef Module__G_PRMS
#define Module__G_PRMS ti_sysbios_gates_GateHwi_Module__gatePrms__C

#undef Module__GP_create
#define Module__GP_create ti_sysbios_gates_GateHwi_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete ti_sysbios_gates_GateHwi_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter ti_sysbios_gates_GateHwi_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave ti_sysbios_gates_GateHwi_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query ti_sysbios_gates_GateHwi_Module_GateProxy_query

/* Module__startupDone__S */
xdc_Bool ti_sysbios_gates_GateHwi_Module__startupDone__S( void )
{
    return 1;
}

/* Handle__label__S */
xdc_runtime_Types_Label *ti_sysbios_gates_GateHwi_Handle__label__S(xdc_Ptr obj, xdc_runtime_Types_Label *lab) 
{
    lab->handle = obj;
    lab->modId = 32803;
    lab->named = FALSE;
    lab->iname = xdc_runtime_Text_nameUnknown;

    return lab;
}

/* Params__init__S */
xdc_Void ti_sysbios_gates_GateHwi_Params__init__S( xdc_Ptr prms, const void *src, xdc_SizeT psz, xdc_SizeT isz ) 
{
    xdc_runtime_Core_assignParams__I(prms, (xdc_CPtr)(src ? src : &ti_sysbios_gates_GateHwi_Object__PARAMS__C), psz, isz);
}

/* Object__get__S */
xdc_Ptr ti_sysbios_gates_GateHwi_Object__get__S(xdc_Ptr oa, xdc_Int i)
{
    if (oa != NULL) {
        return ((ti_sysbios_gates_GateHwi_Object__ *)oa) + i;
    }

    /* the bogus 'const' in the cast suppresses Klocwork MISRA complaints */
    return ((ti_sysbios_gates_GateHwi_Object__ * const)ti_sysbios_gates_GateHwi_Object__table__C) + i;
}

/* Object__first__S */
xdc_Ptr ti_sysbios_gates_GateHwi_Object__first__S( void ) 
{
    xdc_runtime_Types_InstHdr *iHdr = (xdc_runtime_Types_InstHdr *)ti_sysbios_gates_GateHwi_Module__root__V.link.next;

    if (iHdr != (xdc_runtime_Types_InstHdr *)&ti_sysbios_gates_GateHwi_Module__root__V.link) {
        return iHdr + 1;
    }
    else {
        return NULL;
    }
}

/* Object__next__S */
xdc_Ptr ti_sysbios_gates_GateHwi_Object__next__S( xdc_Ptr obj )
{
    xdc_runtime_Types_InstHdr *iHdr = ((xdc_runtime_Types_InstHdr *)obj) - 1;

    if (iHdr->link.next != (xdc_runtime_Types_Link *)&ti_sysbios_gates_GateHwi_Module__root__V.link) {
        return (xdc_runtime_Types_InstHdr *)(iHdr->link.next) + 1;
    }
    else {
        return NULL;
    }
}

/* Object__create__S */
xdc_Ptr ti_sysbios_gates_GateHwi_Object__create__S(
    xdc_CPtr req_args,
    const xdc_UChar *paramsPtr,
    xdc_SizeT prm_size,
    xdc_runtime_Error_Block *eb)
{
    ti_sysbios_gates_GateHwi_Params instPrms;
    ti_sysbios_gates_GateHwi_Object *objp;

    /* common instance initialization */
    objp = xdc_runtime_Core_createObject__I(&ti_sysbios_gates_GateHwi_Object__DESC__C, NULL, &instPrms, (xdc_CPtr)paramsPtr, 0, eb);
    if (objp == NULL) {
        return NULL;
    }


    /* module-specific initialization */
    ti_sysbios_gates_GateHwi_Instance_init__E(objp, &instPrms);
    return objp;
}

/* create */
ti_sysbios_gates_GateHwi_Handle ti_sysbios_gates_GateHwi_create( const ti_sysbios_gates_GateHwi_Params *paramsPtr, xdc_runtime_Error_Block *eb)
{
    ti_sysbios_gates_GateHwi_Params prms;
    ti_sysbios_gates_GateHwi_Object *obj;


    /* common instance initialization */
    obj = xdc_runtime_Core_createObject__I(&ti_sysbios_gates_GateHwi_Object__DESC__C, NULL, &prms, (xdc_CPtr)paramsPtr, 0, eb);
    if (obj == NULL) {
        return NULL;
    }

    /* module-specific initialization */
    ti_sysbios_gates_GateHwi_Instance_init__E(obj, &prms);
    return obj;
}

/* construct */
void ti_sysbios_gates_GateHwi_construct(ti_sysbios_gates_GateHwi_Struct *objp, const ti_sysbios_gates_GateHwi_Params *paramsPtr)
{
    ti_sysbios_gates_GateHwi_Params instPrms;

    /* common instance initialization */
    (Void)xdc_runtime_Core_constructObject__I(&ti_sysbios_gates_GateHwi_Object__DESC__C, objp, &instPrms, (xdc_CPtr)paramsPtr, 0, NULL);

    /* module-specific initialization */
    ti_sysbios_gates_GateHwi_Instance_init__E((xdc_Ptr)objp, &instPrms);
}

/* destruct */
void ti_sysbios_gates_GateHwi_destruct(ti_sysbios_gates_GateHwi_Struct *obj)
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_gates_GateHwi_Object__DESC__C, obj, NULL, -1, TRUE);
}

/* Object__delete__S */
xdc_Void ti_sysbios_gates_GateHwi_Object__delete__S( xdc_Ptr instp ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_gates_GateHwi_Object__DESC__C, *((ti_sysbios_gates_GateHwi_Object**)instp), NULL, -1, FALSE);
    *((ti_sysbios_gates_GateHwi_Handle*)instp) = NULL;
}

/* delete */
void ti_sysbios_gates_GateHwi_delete(ti_sysbios_gates_GateHwi_Handle *instp)
{
    ti_sysbios_gates_GateHwi_Object__delete__S(instp);
}


/*
 * ======== ti.sysbios.gates.GateMutex SYSTEM FUNCTIONS ========
 */

/* per-module runtime symbols */
#undef Module__MID
#define Module__MID ti_sysbios_gates_GateMutex_Module__id__C

#undef Module__DGSINCL
#define Module__DGSINCL ti_sysbios_gates_GateMutex_Module__diagsIncluded__C

#undef Module__DGSENAB
#define Module__DGSENAB ti_sysbios_gates_GateMutex_Module__diagsEnabled__C

#undef Module__DGSMASK
#define Module__DGSMASK ti_sysbios_gates_GateMutex_Module__diagsMask__C

#undef Module__LOGDEF
#define Module__LOGDEF ti_sysbios_gates_GateMutex_Module__loggerDefined__C

#undef Module__LOGOBJ
#define Module__LOGOBJ ti_sysbios_gates_GateMutex_Module__loggerObj__C

#undef Module__LOGFXN0
#define Module__LOGFXN0 ti_sysbios_gates_GateMutex_Module__loggerFxn0__C

#undef Module__LOGFXN1
#define Module__LOGFXN1 ti_sysbios_gates_GateMutex_Module__loggerFxn1__C

#undef Module__LOGFXN2
#define Module__LOGFXN2 ti_sysbios_gates_GateMutex_Module__loggerFxn2__C

#undef Module__LOGFXN4
#define Module__LOGFXN4 ti_sysbios_gates_GateMutex_Module__loggerFxn4__C

#undef Module__LOGFXN8
#define Module__LOGFXN8 ti_sysbios_gates_GateMutex_Module__loggerFxn8__C

#undef Module__G_OBJ
#define Module__G_OBJ ti_sysbios_gates_GateMutex_Module__gateObj__C

#undef Module__G_PRMS
#define Module__G_PRMS ti_sysbios_gates_GateMutex_Module__gatePrms__C

#undef Module__GP_create
#define Module__GP_create ti_sysbios_gates_GateMutex_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete ti_sysbios_gates_GateMutex_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter ti_sysbios_gates_GateMutex_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave ti_sysbios_gates_GateMutex_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query ti_sysbios_gates_GateMutex_Module_GateProxy_query

/* Module__startupDone__S */
xdc_Bool ti_sysbios_gates_GateMutex_Module__startupDone__S( void )
{
    return 1;
}

/* Handle__label__S */
xdc_runtime_Types_Label *ti_sysbios_gates_GateMutex_Handle__label__S(xdc_Ptr obj, xdc_runtime_Types_Label *lab) 
{
    lab->handle = obj;
    lab->modId = 32804;
    lab->named = FALSE;
    lab->iname = xdc_runtime_Text_nameUnknown;

    return lab;
}

/* Params__init__S */
xdc_Void ti_sysbios_gates_GateMutex_Params__init__S( xdc_Ptr prms, const void *src, xdc_SizeT psz, xdc_SizeT isz ) 
{
    xdc_runtime_Core_assignParams__I(prms, (xdc_CPtr)(src ? src : &ti_sysbios_gates_GateMutex_Object__PARAMS__C), psz, isz);
}

/* Object__get__S */
xdc_Ptr ti_sysbios_gates_GateMutex_Object__get__S(xdc_Ptr oa, xdc_Int i)
{
    if (oa != NULL) {
        return ((ti_sysbios_gates_GateMutex_Object__ *)oa) + i;
    }

    /* the bogus 'const' in the cast suppresses Klocwork MISRA complaints */
    return ((ti_sysbios_gates_GateMutex_Object__ * const)ti_sysbios_gates_GateMutex_Object__table__C) + i;
}

/* Object__first__S */
xdc_Ptr ti_sysbios_gates_GateMutex_Object__first__S( void ) 
{
    xdc_runtime_Types_InstHdr *iHdr = (xdc_runtime_Types_InstHdr *)ti_sysbios_gates_GateMutex_Module__root__V.link.next;

    if (iHdr != (xdc_runtime_Types_InstHdr *)&ti_sysbios_gates_GateMutex_Module__root__V.link) {
        return iHdr + 1;
    }
    else {
        return NULL;
    }
}

/* Object__next__S */
xdc_Ptr ti_sysbios_gates_GateMutex_Object__next__S( xdc_Ptr obj )
{
    xdc_runtime_Types_InstHdr *iHdr = ((xdc_runtime_Types_InstHdr *)obj) - 1;

    if (iHdr->link.next != (xdc_runtime_Types_Link *)&ti_sysbios_gates_GateMutex_Module__root__V.link) {
        return (xdc_runtime_Types_InstHdr *)(iHdr->link.next) + 1;
    }
    else {
        return NULL;
    }
}

/* Object__create__S */
xdc_Ptr ti_sysbios_gates_GateMutex_Object__create__S(
    xdc_CPtr req_args,
    const xdc_UChar *paramsPtr,
    xdc_SizeT prm_size,
    xdc_runtime_Error_Block *eb)
{
    ti_sysbios_gates_GateMutex_Params instPrms;
    ti_sysbios_gates_GateMutex_Object *objp;

    /* common instance initialization */
    objp = xdc_runtime_Core_createObject__I(&ti_sysbios_gates_GateMutex_Object__DESC__C, NULL, &instPrms, (xdc_CPtr)paramsPtr, 0, eb);
    if (objp == NULL) {
        return NULL;
    }


    /* module-specific initialization */
    ti_sysbios_gates_GateMutex_Instance_init__E(objp, &instPrms);
    return objp;
}

/* create */
ti_sysbios_gates_GateMutex_Handle ti_sysbios_gates_GateMutex_create( const ti_sysbios_gates_GateMutex_Params *paramsPtr, xdc_runtime_Error_Block *eb)
{
    ti_sysbios_gates_GateMutex_Params prms;
    ti_sysbios_gates_GateMutex_Object *obj;


    /* common instance initialization */
    obj = xdc_runtime_Core_createObject__I(&ti_sysbios_gates_GateMutex_Object__DESC__C, NULL, &prms, (xdc_CPtr)paramsPtr, 0, eb);
    if (obj == NULL) {
        return NULL;
    }

    /* module-specific initialization */
    ti_sysbios_gates_GateMutex_Instance_init__E(obj, &prms);
    return obj;
}

/* construct */
void ti_sysbios_gates_GateMutex_construct(ti_sysbios_gates_GateMutex_Struct *objp, const ti_sysbios_gates_GateMutex_Params *paramsPtr)
{
    ti_sysbios_gates_GateMutex_Params instPrms;

    /* common instance initialization */
    (Void)xdc_runtime_Core_constructObject__I(&ti_sysbios_gates_GateMutex_Object__DESC__C, objp, &instPrms, (xdc_CPtr)paramsPtr, 0, NULL);

    /* module-specific initialization */
    ti_sysbios_gates_GateMutex_Instance_init__E((xdc_Ptr)objp, &instPrms);
}

/* destruct */
void ti_sysbios_gates_GateMutex_destruct(ti_sysbios_gates_GateMutex_Struct *obj)
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_gates_GateMutex_Object__DESC__C, obj, (xdc_Fxn)ti_sysbios_gates_GateMutex_Instance_finalize__E, -1, TRUE);
}

/* Object__delete__S */
xdc_Void ti_sysbios_gates_GateMutex_Object__delete__S( xdc_Ptr instp ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_gates_GateMutex_Object__DESC__C, *((ti_sysbios_gates_GateMutex_Object**)instp), (xdc_Fxn)ti_sysbios_gates_GateMutex_Instance_finalize__E, -1, FALSE);
    *((ti_sysbios_gates_GateMutex_Handle*)instp) = NULL;
}

/* delete */
void ti_sysbios_gates_GateMutex_delete(ti_sysbios_gates_GateMutex_Handle *instp)
{
    ti_sysbios_gates_GateMutex_Object__delete__S(instp);
}


/*
 * ======== ti.sysbios.hal.Hwi SYSTEM FUNCTIONS ========
 */

/* per-module runtime symbols */
#undef Module__MID
#define Module__MID ti_sysbios_hal_Hwi_Module__id__C

#undef Module__DGSINCL
#define Module__DGSINCL ti_sysbios_hal_Hwi_Module__diagsIncluded__C

#undef Module__DGSENAB
#define Module__DGSENAB ti_sysbios_hal_Hwi_Module__diagsEnabled__C

#undef Module__DGSMASK
#define Module__DGSMASK ti_sysbios_hal_Hwi_Module__diagsMask__C

#undef Module__LOGDEF
#define Module__LOGDEF ti_sysbios_hal_Hwi_Module__loggerDefined__C

#undef Module__LOGOBJ
#define Module__LOGOBJ ti_sysbios_hal_Hwi_Module__loggerObj__C

#undef Module__LOGFXN0
#define Module__LOGFXN0 ti_sysbios_hal_Hwi_Module__loggerFxn0__C

#undef Module__LOGFXN1
#define Module__LOGFXN1 ti_sysbios_hal_Hwi_Module__loggerFxn1__C

#undef Module__LOGFXN2
#define Module__LOGFXN2 ti_sysbios_hal_Hwi_Module__loggerFxn2__C

#undef Module__LOGFXN4
#define Module__LOGFXN4 ti_sysbios_hal_Hwi_Module__loggerFxn4__C

#undef Module__LOGFXN8
#define Module__LOGFXN8 ti_sysbios_hal_Hwi_Module__loggerFxn8__C

#undef Module__G_OBJ
#define Module__G_OBJ ti_sysbios_hal_Hwi_Module__gateObj__C

#undef Module__G_PRMS
#define Module__G_PRMS ti_sysbios_hal_Hwi_Module__gatePrms__C

#undef Module__GP_create
#define Module__GP_create ti_sysbios_hal_Hwi_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete ti_sysbios_hal_Hwi_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter ti_sysbios_hal_Hwi_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave ti_sysbios_hal_Hwi_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query ti_sysbios_hal_Hwi_Module_GateProxy_query

/* Module__startupDone__S */
xdc_Bool ti_sysbios_hal_Hwi_Module__startupDone__S( void )
{
    return ti_sysbios_hal_Hwi_Module__startupDone__F();
}

/* Handle__label__S */
xdc_runtime_Types_Label *ti_sysbios_hal_Hwi_Handle__label__S(xdc_Ptr obj, xdc_runtime_Types_Label *lab) 
{
    lab->handle = obj;
    lab->modId = 32806;
    lab->named = FALSE;
    lab->iname = xdc_runtime_Text_nameUnknown;

    return lab;
}

/* Params__init__S */
xdc_Void ti_sysbios_hal_Hwi_Params__init__S( xdc_Ptr prms, const void *src, xdc_SizeT psz, xdc_SizeT isz ) 
{
    xdc_runtime_Core_assignParams__I(prms, (xdc_CPtr)(src ? src : &ti_sysbios_hal_Hwi_Object__PARAMS__C), psz, isz);
}

/* Object__get__S */
xdc_Ptr ti_sysbios_hal_Hwi_Object__get__S(xdc_Ptr oa, xdc_Int i)
{
    if (oa != NULL) {
        return ((ti_sysbios_hal_Hwi_Object__ *)oa) + i;
    }

    return NULL;
}


/* Object__first__S */
xdc_Ptr ti_sysbios_hal_Hwi_Object__first__S( void ) 
{
    xdc_runtime_Types_InstHdr *iHdr = (xdc_runtime_Types_InstHdr *)ti_sysbios_hal_Hwi_Module__root__V.link.next;

    if (iHdr != (xdc_runtime_Types_InstHdr *)&ti_sysbios_hal_Hwi_Module__root__V.link) {
        return iHdr + 1;
    }
    else {
        return NULL;
    }
}

/* Object__next__S */
xdc_Ptr ti_sysbios_hal_Hwi_Object__next__S( xdc_Ptr obj )
{
    xdc_runtime_Types_InstHdr *iHdr = ((xdc_runtime_Types_InstHdr *)obj) - 1;

    if (iHdr->link.next != (xdc_runtime_Types_Link *)&ti_sysbios_hal_Hwi_Module__root__V.link) {
        return (xdc_runtime_Types_InstHdr *)(iHdr->link.next) + 1;
    }
    else {
        return NULL;
    }
}

/* Object__create__S */
xdc_Ptr ti_sysbios_hal_Hwi_Object__create__S(
    xdc_CPtr req_args,
    const xdc_UChar *paramsPtr,
    xdc_SizeT prm_size,
    xdc_runtime_Error_Block *eb)
{
    const ti_sysbios_hal_Hwi_Args__create *__args = req_args;
    ti_sysbios_hal_Hwi_Params instPrms;
    ti_sysbios_hal_Hwi_Object *objp;
    int iStat;

    /* common instance initialization */
    objp = xdc_runtime_Core_createObject__I(&ti_sysbios_hal_Hwi_Object__DESC__C, NULL, &instPrms, (xdc_CPtr)paramsPtr, 0, eb);
    if (objp == NULL) {
        return NULL;
    }


    /* module-specific initialization */
    iStat = ti_sysbios_hal_Hwi_Instance_init__E(objp, __args->intNum, __args->hwiFxn, &instPrms, eb);
    if (iStat) {
        xdc_runtime_Core_deleteObject__I(&ti_sysbios_hal_Hwi_Object__DESC__C, objp, (xdc_Fxn)ti_sysbios_hal_Hwi_Instance_finalize__E, iStat, 0);
        return NULL;
    }

    return objp;
}

/* create */
ti_sysbios_hal_Hwi_Handle ti_sysbios_hal_Hwi_create( xdc_Int intNum, ti_sysbios_hal_Hwi_FuncPtr hwiFxn, const ti_sysbios_hal_Hwi_Params *paramsPtr, xdc_runtime_Error_Block *eb)
{
    ti_sysbios_hal_Hwi_Params prms;
    ti_sysbios_hal_Hwi_Object *obj;

    int iStat;

    /* common instance initialization */
    obj = xdc_runtime_Core_createObject__I(&ti_sysbios_hal_Hwi_Object__DESC__C, NULL, &prms, (xdc_CPtr)paramsPtr, 0, eb);
    if (obj == NULL) {
        return NULL;
    }

    /* module-specific initialization */
    iStat = ti_sysbios_hal_Hwi_Instance_init__E(obj, intNum, hwiFxn, &prms, eb);
    if (iStat) {
        xdc_runtime_Core_deleteObject__I(&ti_sysbios_hal_Hwi_Object__DESC__C, obj, (xdc_Fxn)ti_sysbios_hal_Hwi_Instance_finalize__E, iStat, 0);
        return NULL;
    }

    return obj;
}

/* construct */
void ti_sysbios_hal_Hwi_construct(ti_sysbios_hal_Hwi_Struct *objp, xdc_Int intNum, ti_sysbios_hal_Hwi_FuncPtr hwiFxn, const ti_sysbios_hal_Hwi_Params *paramsPtr, xdc_runtime_Error_Block *eb)
{
    ti_sysbios_hal_Hwi_Params instPrms;
    int iStat;

    /* common instance initialization */
    (Void)xdc_runtime_Core_constructObject__I(&ti_sysbios_hal_Hwi_Object__DESC__C, objp, &instPrms, (xdc_CPtr)paramsPtr, 0, eb);

    /* module-specific initialization */
    iStat = ti_sysbios_hal_Hwi_Instance_init__E((xdc_Ptr)objp, intNum, hwiFxn, &instPrms, eb);
    if (iStat) {
        xdc_runtime_Core_deleteObject__I(&ti_sysbios_hal_Hwi_Object__DESC__C, objp, (xdc_Fxn)ti_sysbios_hal_Hwi_Instance_finalize__E, iStat, 1);
    }

}

/* destruct */
void ti_sysbios_hal_Hwi_destruct(ti_sysbios_hal_Hwi_Struct *obj)
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_hal_Hwi_Object__DESC__C, obj, (xdc_Fxn)ti_sysbios_hal_Hwi_Instance_finalize__E, 0, TRUE);
}

/* Object__delete__S */
xdc_Void ti_sysbios_hal_Hwi_Object__delete__S( xdc_Ptr instp ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_hal_Hwi_Object__DESC__C, *((ti_sysbios_hal_Hwi_Object**)instp), (xdc_Fxn)ti_sysbios_hal_Hwi_Instance_finalize__E, 0, FALSE);
    *((ti_sysbios_hal_Hwi_Handle*)instp) = NULL;
}

/* delete */
void ti_sysbios_hal_Hwi_delete(ti_sysbios_hal_Hwi_Handle *instp)
{
    ti_sysbios_hal_Hwi_Object__delete__S(instp);
}


/*
 * ======== ti.sysbios.hal.Hwi_HwiProxy SYSTEM FUNCTIONS ========
 */

/* per-module runtime symbols */
#undef Module__MID
#define Module__MID ti_sysbios_hal_Hwi_HwiProxy_Module__id__C

#undef Module__DGSINCL
#define Module__DGSINCL ti_sysbios_hal_Hwi_HwiProxy_Module__diagsIncluded__C

#undef Module__DGSENAB
#define Module__DGSENAB ti_sysbios_hal_Hwi_HwiProxy_Module__diagsEnabled__C

#undef Module__DGSMASK
#define Module__DGSMASK ti_sysbios_hal_Hwi_HwiProxy_Module__diagsMask__C

#undef Module__LOGDEF
#define Module__LOGDEF ti_sysbios_hal_Hwi_HwiProxy_Module__loggerDefined__C

#undef Module__LOGOBJ
#define Module__LOGOBJ ti_sysbios_hal_Hwi_HwiProxy_Module__loggerObj__C

#undef Module__LOGFXN0
#define Module__LOGFXN0 ti_sysbios_hal_Hwi_HwiProxy_Module__loggerFxn0__C

#undef Module__LOGFXN1
#define Module__LOGFXN1 ti_sysbios_hal_Hwi_HwiProxy_Module__loggerFxn1__C

#undef Module__LOGFXN2
#define Module__LOGFXN2 ti_sysbios_hal_Hwi_HwiProxy_Module__loggerFxn2__C

#undef Module__LOGFXN4
#define Module__LOGFXN4 ti_sysbios_hal_Hwi_HwiProxy_Module__loggerFxn4__C

#undef Module__LOGFXN8
#define Module__LOGFXN8 ti_sysbios_hal_Hwi_HwiProxy_Module__loggerFxn8__C

#undef Module__G_OBJ
#define Module__G_OBJ ti_sysbios_hal_Hwi_HwiProxy_Module__gateObj__C

#undef Module__G_PRMS
#define Module__G_PRMS ti_sysbios_hal_Hwi_HwiProxy_Module__gatePrms__C

#undef Module__GP_create
#define Module__GP_create ti_sysbios_hal_Hwi_HwiProxy_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete ti_sysbios_hal_Hwi_HwiProxy_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter ti_sysbios_hal_Hwi_HwiProxy_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave ti_sysbios_hal_Hwi_HwiProxy_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query ti_sysbios_hal_Hwi_HwiProxy_Module_GateProxy_query

xdc_Bool ti_sysbios_hal_Hwi_HwiProxy_Proxy__abstract__S(void)
{
    return 0;
}
xdc_CPtr ti_sysbios_hal_Hwi_HwiProxy_Proxy__delegate__S(void)
{
    return 0;
}



/*
 * ======== ti.sysbios.heaps.HeapMem SYSTEM FUNCTIONS ========
 */

/* per-module runtime symbols */
#undef Module__MID
#define Module__MID ti_sysbios_heaps_HeapMem_Module__id__C

#undef Module__DGSINCL
#define Module__DGSINCL ti_sysbios_heaps_HeapMem_Module__diagsIncluded__C

#undef Module__DGSENAB
#define Module__DGSENAB ti_sysbios_heaps_HeapMem_Module__diagsEnabled__C

#undef Module__DGSMASK
#define Module__DGSMASK ti_sysbios_heaps_HeapMem_Module__diagsMask__C

#undef Module__LOGDEF
#define Module__LOGDEF ti_sysbios_heaps_HeapMem_Module__loggerDefined__C

#undef Module__LOGOBJ
#define Module__LOGOBJ ti_sysbios_heaps_HeapMem_Module__loggerObj__C

#undef Module__LOGFXN0
#define Module__LOGFXN0 ti_sysbios_heaps_HeapMem_Module__loggerFxn0__C

#undef Module__LOGFXN1
#define Module__LOGFXN1 ti_sysbios_heaps_HeapMem_Module__loggerFxn1__C

#undef Module__LOGFXN2
#define Module__LOGFXN2 ti_sysbios_heaps_HeapMem_Module__loggerFxn2__C

#undef Module__LOGFXN4
#define Module__LOGFXN4 ti_sysbios_heaps_HeapMem_Module__loggerFxn4__C

#undef Module__LOGFXN8
#define Module__LOGFXN8 ti_sysbios_heaps_HeapMem_Module__loggerFxn8__C

#undef Module__G_OBJ
#define Module__G_OBJ ti_sysbios_heaps_HeapMem_Module__gateObj__C

#undef Module__G_PRMS
#define Module__G_PRMS ti_sysbios_heaps_HeapMem_Module__gatePrms__C

#undef Module__GP_create
#define Module__GP_create ti_sysbios_heaps_HeapMem_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete ti_sysbios_heaps_HeapMem_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter ti_sysbios_heaps_HeapMem_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave ti_sysbios_heaps_HeapMem_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query ti_sysbios_heaps_HeapMem_Module_GateProxy_query

/* Module__startupDone__S */
xdc_Bool ti_sysbios_heaps_HeapMem_Module__startupDone__S( void )
{
    return 1;
}

/* Handle__label__S */
xdc_runtime_Types_Label *ti_sysbios_heaps_HeapMem_Handle__label__S(xdc_Ptr obj, xdc_runtime_Types_Label *lab) 
{
    lab->handle = obj;
    lab->modId = 32808;
    lab->named = FALSE;
    lab->iname = xdc_runtime_Text_nameUnknown;

    return lab;
}

/* Params__init__S */
xdc_Void ti_sysbios_heaps_HeapMem_Params__init__S( xdc_Ptr prms, const void *src, xdc_SizeT psz, xdc_SizeT isz ) 
{
    xdc_runtime_Core_assignParams__I(prms, (xdc_CPtr)(src ? src : &ti_sysbios_heaps_HeapMem_Object__PARAMS__C), psz, isz);
}

/* Object__get__S */
xdc_Ptr ti_sysbios_heaps_HeapMem_Object__get__S(xdc_Ptr oa, xdc_Int i)
{
    if (oa != NULL) {
        return ((ti_sysbios_heaps_HeapMem_Object__ *)oa) + i;
    }

    /* the bogus 'const' in the cast suppresses Klocwork MISRA complaints */
    return ((ti_sysbios_heaps_HeapMem_Object__ * const)ti_sysbios_heaps_HeapMem_Object__table__C) + i;
}

/* Object__first__S */
xdc_Ptr ti_sysbios_heaps_HeapMem_Object__first__S( void ) 
{
    xdc_runtime_Types_InstHdr *iHdr = (xdc_runtime_Types_InstHdr *)ti_sysbios_heaps_HeapMem_Module__root__V.link.next;

    if (iHdr != (xdc_runtime_Types_InstHdr *)&ti_sysbios_heaps_HeapMem_Module__root__V.link) {
        return iHdr + 1;
    }
    else {
        return NULL;
    }
}

/* Object__next__S */
xdc_Ptr ti_sysbios_heaps_HeapMem_Object__next__S( xdc_Ptr obj )
{
    xdc_runtime_Types_InstHdr *iHdr = ((xdc_runtime_Types_InstHdr *)obj) - 1;

    if (iHdr->link.next != (xdc_runtime_Types_Link *)&ti_sysbios_heaps_HeapMem_Module__root__V.link) {
        return (xdc_runtime_Types_InstHdr *)(iHdr->link.next) + 1;
    }
    else {
        return NULL;
    }
}

/* Object__create__S */
xdc_Ptr ti_sysbios_heaps_HeapMem_Object__create__S(
    xdc_CPtr req_args,
    const xdc_UChar *paramsPtr,
    xdc_SizeT prm_size,
    xdc_runtime_Error_Block *eb)
{
    ti_sysbios_heaps_HeapMem_Params instPrms;
    ti_sysbios_heaps_HeapMem_Object *objp;

    /* common instance initialization */
    objp = xdc_runtime_Core_createObject__I(&ti_sysbios_heaps_HeapMem_Object__DESC__C, NULL, &instPrms, (xdc_CPtr)paramsPtr, 0, eb);
    if (objp == NULL) {
        return NULL;
    }


    /* module-specific initialization */
    ti_sysbios_heaps_HeapMem_Instance_init__E(objp, &instPrms);
    return objp;
}

/* create */
ti_sysbios_heaps_HeapMem_Handle ti_sysbios_heaps_HeapMem_create( const ti_sysbios_heaps_HeapMem_Params *paramsPtr, xdc_runtime_Error_Block *eb)
{
    ti_sysbios_heaps_HeapMem_Params prms;
    ti_sysbios_heaps_HeapMem_Object *obj;


    /* common instance initialization */
    obj = xdc_runtime_Core_createObject__I(&ti_sysbios_heaps_HeapMem_Object__DESC__C, NULL, &prms, (xdc_CPtr)paramsPtr, 0, eb);
    if (obj == NULL) {
        return NULL;
    }

    /* module-specific initialization */
    ti_sysbios_heaps_HeapMem_Instance_init__E(obj, &prms);
    return obj;
}

/* construct */
void ti_sysbios_heaps_HeapMem_construct(ti_sysbios_heaps_HeapMem_Struct *objp, const ti_sysbios_heaps_HeapMem_Params *paramsPtr)
{
    ti_sysbios_heaps_HeapMem_Params instPrms;

    /* common instance initialization */
    (Void)xdc_runtime_Core_constructObject__I(&ti_sysbios_heaps_HeapMem_Object__DESC__C, objp, &instPrms, (xdc_CPtr)paramsPtr, 0, NULL);

    /* module-specific initialization */
    ti_sysbios_heaps_HeapMem_Instance_init__E((xdc_Ptr)objp, &instPrms);
}

/* destruct */
void ti_sysbios_heaps_HeapMem_destruct(ti_sysbios_heaps_HeapMem_Struct *obj)
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_heaps_HeapMem_Object__DESC__C, obj, NULL, -1, TRUE);
}

/* Object__delete__S */
xdc_Void ti_sysbios_heaps_HeapMem_Object__delete__S( xdc_Ptr instp ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_heaps_HeapMem_Object__DESC__C, *((ti_sysbios_heaps_HeapMem_Object**)instp), NULL, -1, FALSE);
    *((ti_sysbios_heaps_HeapMem_Handle*)instp) = NULL;
}

/* delete */
void ti_sysbios_heaps_HeapMem_delete(ti_sysbios_heaps_HeapMem_Handle *instp)
{
    ti_sysbios_heaps_HeapMem_Object__delete__S(instp);
}


/*
 * ======== ti.sysbios.heaps.HeapMem_Module_GateProxy SYSTEM FUNCTIONS ========
 */

/* per-module runtime symbols */
#undef Module__MID
#define Module__MID ti_sysbios_heaps_HeapMem_Module_GateProxy_Module__id__C

#undef Module__DGSINCL
#define Module__DGSINCL ti_sysbios_heaps_HeapMem_Module_GateProxy_Module__diagsIncluded__C

#undef Module__DGSENAB
#define Module__DGSENAB ti_sysbios_heaps_HeapMem_Module_GateProxy_Module__diagsEnabled__C

#undef Module__DGSMASK
#define Module__DGSMASK ti_sysbios_heaps_HeapMem_Module_GateProxy_Module__diagsMask__C

#undef Module__LOGDEF
#define Module__LOGDEF ti_sysbios_heaps_HeapMem_Module_GateProxy_Module__loggerDefined__C

#undef Module__LOGOBJ
#define Module__LOGOBJ ti_sysbios_heaps_HeapMem_Module_GateProxy_Module__loggerObj__C

#undef Module__LOGFXN0
#define Module__LOGFXN0 ti_sysbios_heaps_HeapMem_Module_GateProxy_Module__loggerFxn0__C

#undef Module__LOGFXN1
#define Module__LOGFXN1 ti_sysbios_heaps_HeapMem_Module_GateProxy_Module__loggerFxn1__C

#undef Module__LOGFXN2
#define Module__LOGFXN2 ti_sysbios_heaps_HeapMem_Module_GateProxy_Module__loggerFxn2__C

#undef Module__LOGFXN4
#define Module__LOGFXN4 ti_sysbios_heaps_HeapMem_Module_GateProxy_Module__loggerFxn4__C

#undef Module__LOGFXN8
#define Module__LOGFXN8 ti_sysbios_heaps_HeapMem_Module_GateProxy_Module__loggerFxn8__C

#undef Module__G_OBJ
#define Module__G_OBJ ti_sysbios_heaps_HeapMem_Module_GateProxy_Module__gateObj__C

#undef Module__G_PRMS
#define Module__G_PRMS ti_sysbios_heaps_HeapMem_Module_GateProxy_Module__gatePrms__C

#undef Module__GP_create
#define Module__GP_create ti_sysbios_heaps_HeapMem_Module_GateProxy_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete ti_sysbios_heaps_HeapMem_Module_GateProxy_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter ti_sysbios_heaps_HeapMem_Module_GateProxy_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave ti_sysbios_heaps_HeapMem_Module_GateProxy_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query ti_sysbios_heaps_HeapMem_Module_GateProxy_Module_GateProxy_query

xdc_Bool ti_sysbios_heaps_HeapMem_Module_GateProxy_Proxy__abstract__S(void)
{
    return 0;
}
xdc_CPtr ti_sysbios_heaps_HeapMem_Module_GateProxy_Proxy__delegate__S(void)
{
    return (const void *)&ti_sysbios_gates_GateMutex_Module__FXNS__C;
}



/*
 * ======== ti.sysbios.knl.Clock SYSTEM FUNCTIONS ========
 */

/* per-module runtime symbols */
#undef Module__MID
#define Module__MID ti_sysbios_knl_Clock_Module__id__C

#undef Module__DGSINCL
#define Module__DGSINCL ti_sysbios_knl_Clock_Module__diagsIncluded__C

#undef Module__DGSENAB
#define Module__DGSENAB ti_sysbios_knl_Clock_Module__diagsEnabled__C

#undef Module__DGSMASK
#define Module__DGSMASK ti_sysbios_knl_Clock_Module__diagsMask__C

#undef Module__LOGDEF
#define Module__LOGDEF ti_sysbios_knl_Clock_Module__loggerDefined__C

#undef Module__LOGOBJ
#define Module__LOGOBJ ti_sysbios_knl_Clock_Module__loggerObj__C

#undef Module__LOGFXN0
#define Module__LOGFXN0 ti_sysbios_knl_Clock_Module__loggerFxn0__C

#undef Module__LOGFXN1
#define Module__LOGFXN1 ti_sysbios_knl_Clock_Module__loggerFxn1__C

#undef Module__LOGFXN2
#define Module__LOGFXN2 ti_sysbios_knl_Clock_Module__loggerFxn2__C

#undef Module__LOGFXN4
#define Module__LOGFXN4 ti_sysbios_knl_Clock_Module__loggerFxn4__C

#undef Module__LOGFXN8
#define Module__LOGFXN8 ti_sysbios_knl_Clock_Module__loggerFxn8__C

#undef Module__G_OBJ
#define Module__G_OBJ ti_sysbios_knl_Clock_Module__gateObj__C

#undef Module__G_PRMS
#define Module__G_PRMS ti_sysbios_knl_Clock_Module__gatePrms__C

#undef Module__GP_create
#define Module__GP_create ti_sysbios_knl_Clock_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete ti_sysbios_knl_Clock_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter ti_sysbios_knl_Clock_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave ti_sysbios_knl_Clock_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query ti_sysbios_knl_Clock_Module_GateProxy_query

/* Module__startupDone__S */
xdc_Bool ti_sysbios_knl_Clock_Module__startupDone__S( void )
{
    return ti_sysbios_knl_Clock_Module__startupDone__F();
}

/* Handle__label__S */
xdc_runtime_Types_Label *ti_sysbios_knl_Clock_Handle__label__S(xdc_Ptr obj, xdc_runtime_Types_Label *lab) 
{
    lab->handle = obj;
    lab->modId = 32795;
    lab->named = FALSE;
    lab->iname = xdc_runtime_Text_nameUnknown;

    return lab;
}

/* Params__init__S */
xdc_Void ti_sysbios_knl_Clock_Params__init__S( xdc_Ptr prms, const void *src, xdc_SizeT psz, xdc_SizeT isz ) 
{
    xdc_runtime_Core_assignParams__I(prms, (xdc_CPtr)(src ? src : &ti_sysbios_knl_Clock_Object__PARAMS__C), psz, isz);
}

/* Object__get__S */
xdc_Ptr ti_sysbios_knl_Clock_Object__get__S(xdc_Ptr oa, xdc_Int i)
{
    if (oa != NULL) {
        return ((ti_sysbios_knl_Clock_Object__ *)oa) + i;
    }

    /* the bogus 'const' in the cast suppresses Klocwork MISRA complaints */
    return ((ti_sysbios_knl_Clock_Object__ * const)ti_sysbios_knl_Clock_Object__table__C) + i;
}

/* Object__first__S */
xdc_Ptr ti_sysbios_knl_Clock_Object__first__S( void ) 
{
    xdc_runtime_Types_InstHdr *iHdr = (xdc_runtime_Types_InstHdr *)ti_sysbios_knl_Clock_Module__root__V.link.next;

    if (iHdr != (xdc_runtime_Types_InstHdr *)&ti_sysbios_knl_Clock_Module__root__V.link) {
        return iHdr + 1;
    }
    else {
        return NULL;
    }
}

/* Object__next__S */
xdc_Ptr ti_sysbios_knl_Clock_Object__next__S( xdc_Ptr obj )
{
    xdc_runtime_Types_InstHdr *iHdr = ((xdc_runtime_Types_InstHdr *)obj) - 1;

    if (iHdr->link.next != (xdc_runtime_Types_Link *)&ti_sysbios_knl_Clock_Module__root__V.link) {
        return (xdc_runtime_Types_InstHdr *)(iHdr->link.next) + 1;
    }
    else {
        return NULL;
    }
}

/* Object__create__S */
xdc_Ptr ti_sysbios_knl_Clock_Object__create__S(
    xdc_CPtr req_args,
    const xdc_UChar *paramsPtr,
    xdc_SizeT prm_size,
    xdc_runtime_Error_Block *eb)
{
    const ti_sysbios_knl_Clock_Args__create *__args = req_args;
    ti_sysbios_knl_Clock_Params instPrms;
    ti_sysbios_knl_Clock_Object *objp;

    /* common instance initialization */
    objp = xdc_runtime_Core_createObject__I(&ti_sysbios_knl_Clock_Object__DESC__C, NULL, &instPrms, (xdc_CPtr)paramsPtr, 0, eb);
    if (objp == NULL) {
        return NULL;
    }


    /* module-specific initialization */
    ti_sysbios_knl_Clock_Instance_init__E(objp, __args->clockFxn, __args->timeout, &instPrms);
    return objp;
}

/* create */
ti_sysbios_knl_Clock_Handle ti_sysbios_knl_Clock_create( ti_sysbios_knl_Clock_FuncPtr clockFxn, xdc_UInt timeout, const ti_sysbios_knl_Clock_Params *paramsPtr, xdc_runtime_Error_Block *eb)
{
    ti_sysbios_knl_Clock_Params prms;
    ti_sysbios_knl_Clock_Object *obj;


    /* common instance initialization */
    obj = xdc_runtime_Core_createObject__I(&ti_sysbios_knl_Clock_Object__DESC__C, NULL, &prms, (xdc_CPtr)paramsPtr, 0, eb);
    if (obj == NULL) {
        return NULL;
    }

    /* module-specific initialization */
    ti_sysbios_knl_Clock_Instance_init__E(obj, clockFxn, timeout, &prms);
    return obj;
}

/* construct */
void ti_sysbios_knl_Clock_construct(ti_sysbios_knl_Clock_Struct *objp, ti_sysbios_knl_Clock_FuncPtr clockFxn, xdc_UInt timeout, const ti_sysbios_knl_Clock_Params *paramsPtr)
{
    ti_sysbios_knl_Clock_Params instPrms;

    /* common instance initialization */
    (Void)xdc_runtime_Core_constructObject__I(&ti_sysbios_knl_Clock_Object__DESC__C, objp, &instPrms, (xdc_CPtr)paramsPtr, 0, NULL);

    /* module-specific initialization */
    ti_sysbios_knl_Clock_Instance_init__E((xdc_Ptr)objp, clockFxn, timeout, &instPrms);
}

/* destruct */
void ti_sysbios_knl_Clock_destruct(ti_sysbios_knl_Clock_Struct *obj)
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_knl_Clock_Object__DESC__C, obj, (xdc_Fxn)ti_sysbios_knl_Clock_Instance_finalize__E, -1, TRUE);
}

/* Object__delete__S */
xdc_Void ti_sysbios_knl_Clock_Object__delete__S( xdc_Ptr instp ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_knl_Clock_Object__DESC__C, *((ti_sysbios_knl_Clock_Object**)instp), (xdc_Fxn)ti_sysbios_knl_Clock_Instance_finalize__E, -1, FALSE);
    *((ti_sysbios_knl_Clock_Handle*)instp) = NULL;
}

/* delete */
void ti_sysbios_knl_Clock_delete(ti_sysbios_knl_Clock_Handle *instp)
{
    ti_sysbios_knl_Clock_Object__delete__S(instp);
}


/*
 * ======== ti.sysbios.knl.Clock_TimerProxy SYSTEM FUNCTIONS ========
 */

/* per-module runtime symbols */
#undef Module__MID
#define Module__MID ti_sysbios_knl_Clock_TimerProxy_Module__id__C

#undef Module__DGSINCL
#define Module__DGSINCL ti_sysbios_knl_Clock_TimerProxy_Module__diagsIncluded__C

#undef Module__DGSENAB
#define Module__DGSENAB ti_sysbios_knl_Clock_TimerProxy_Module__diagsEnabled__C

#undef Module__DGSMASK
#define Module__DGSMASK ti_sysbios_knl_Clock_TimerProxy_Module__diagsMask__C

#undef Module__LOGDEF
#define Module__LOGDEF ti_sysbios_knl_Clock_TimerProxy_Module__loggerDefined__C

#undef Module__LOGOBJ
#define Module__LOGOBJ ti_sysbios_knl_Clock_TimerProxy_Module__loggerObj__C

#undef Module__LOGFXN0
#define Module__LOGFXN0 ti_sysbios_knl_Clock_TimerProxy_Module__loggerFxn0__C

#undef Module__LOGFXN1
#define Module__LOGFXN1 ti_sysbios_knl_Clock_TimerProxy_Module__loggerFxn1__C

#undef Module__LOGFXN2
#define Module__LOGFXN2 ti_sysbios_knl_Clock_TimerProxy_Module__loggerFxn2__C

#undef Module__LOGFXN4
#define Module__LOGFXN4 ti_sysbios_knl_Clock_TimerProxy_Module__loggerFxn4__C

#undef Module__LOGFXN8
#define Module__LOGFXN8 ti_sysbios_knl_Clock_TimerProxy_Module__loggerFxn8__C

#undef Module__G_OBJ
#define Module__G_OBJ ti_sysbios_knl_Clock_TimerProxy_Module__gateObj__C

#undef Module__G_PRMS
#define Module__G_PRMS ti_sysbios_knl_Clock_TimerProxy_Module__gatePrms__C

#undef Module__GP_create
#define Module__GP_create ti_sysbios_knl_Clock_TimerProxy_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete ti_sysbios_knl_Clock_TimerProxy_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter ti_sysbios_knl_Clock_TimerProxy_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave ti_sysbios_knl_Clock_TimerProxy_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query ti_sysbios_knl_Clock_TimerProxy_Module_GateProxy_query

xdc_Bool ti_sysbios_knl_Clock_TimerProxy_Proxy__abstract__S(void)
{
    return 0;
}
xdc_CPtr ti_sysbios_knl_Clock_TimerProxy_Proxy__delegate__S(void)
{
    return 0;
}



/*
 * ======== ti.sysbios.knl.Idle SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool ti_sysbios_knl_Idle_Module__startupDone__S( void )
{
    return 1;
}



/*
 * ======== ti.sysbios.knl.Intrinsics SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool ti_sysbios_knl_Intrinsics_Module__startupDone__S( void )
{
    return 1;
}



/*
 * ======== ti.sysbios.knl.Intrinsics_SupportProxy SYSTEM FUNCTIONS ========
 */


xdc_Bool ti_sysbios_knl_Intrinsics_SupportProxy_Proxy__abstract__S(void)
{
    return 0;
}
xdc_CPtr ti_sysbios_knl_Intrinsics_SupportProxy_Proxy__delegate__S(void)
{
    return 0;
}


/*
 * ======== ti.sysbios.knl.Queue SYSTEM FUNCTIONS ========
 */

/* per-module runtime symbols */
#undef Module__MID
#define Module__MID ti_sysbios_knl_Queue_Module__id__C

#undef Module__DGSINCL
#define Module__DGSINCL ti_sysbios_knl_Queue_Module__diagsIncluded__C

#undef Module__DGSENAB
#define Module__DGSENAB ti_sysbios_knl_Queue_Module__diagsEnabled__C

#undef Module__DGSMASK
#define Module__DGSMASK ti_sysbios_knl_Queue_Module__diagsMask__C

#undef Module__LOGDEF
#define Module__LOGDEF ti_sysbios_knl_Queue_Module__loggerDefined__C

#undef Module__LOGOBJ
#define Module__LOGOBJ ti_sysbios_knl_Queue_Module__loggerObj__C

#undef Module__LOGFXN0
#define Module__LOGFXN0 ti_sysbios_knl_Queue_Module__loggerFxn0__C

#undef Module__LOGFXN1
#define Module__LOGFXN1 ti_sysbios_knl_Queue_Module__loggerFxn1__C

#undef Module__LOGFXN2
#define Module__LOGFXN2 ti_sysbios_knl_Queue_Module__loggerFxn2__C

#undef Module__LOGFXN4
#define Module__LOGFXN4 ti_sysbios_knl_Queue_Module__loggerFxn4__C

#undef Module__LOGFXN8
#define Module__LOGFXN8 ti_sysbios_knl_Queue_Module__loggerFxn8__C

#undef Module__G_OBJ
#define Module__G_OBJ ti_sysbios_knl_Queue_Module__gateObj__C

#undef Module__G_PRMS
#define Module__G_PRMS ti_sysbios_knl_Queue_Module__gatePrms__C

#undef Module__GP_create
#define Module__GP_create ti_sysbios_knl_Queue_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete ti_sysbios_knl_Queue_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter ti_sysbios_knl_Queue_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave ti_sysbios_knl_Queue_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query ti_sysbios_knl_Queue_Module_GateProxy_query

/* Module__startupDone__S */
xdc_Bool ti_sysbios_knl_Queue_Module__startupDone__S( void )
{
    return 1;
}

/* Handle__label__S */
xdc_runtime_Types_Label *ti_sysbios_knl_Queue_Handle__label__S(xdc_Ptr obj, xdc_runtime_Types_Label *lab) 
{
    lab->handle = obj;
    lab->modId = 32798;
    lab->named = FALSE;
    lab->iname = xdc_runtime_Text_nameUnknown;

    return lab;
}

/* Params__init__S */
xdc_Void ti_sysbios_knl_Queue_Params__init__S( xdc_Ptr prms, const void *src, xdc_SizeT psz, xdc_SizeT isz ) 
{
    xdc_runtime_Core_assignParams__I(prms, (xdc_CPtr)(src ? src : &ti_sysbios_knl_Queue_Object__PARAMS__C), psz, isz);
}

/* Object__get__S */
xdc_Ptr ti_sysbios_knl_Queue_Object__get__S(xdc_Ptr oa, xdc_Int i)
{
    if (oa != NULL) {
        return ((ti_sysbios_knl_Queue_Object__ *)oa) + i;
    }

    return NULL;
}


/* Object__first__S */
xdc_Ptr ti_sysbios_knl_Queue_Object__first__S( void ) 
{
    xdc_runtime_Types_InstHdr *iHdr = (xdc_runtime_Types_InstHdr *)ti_sysbios_knl_Queue_Module__root__V.link.next;

    if (iHdr != (xdc_runtime_Types_InstHdr *)&ti_sysbios_knl_Queue_Module__root__V.link) {
        return iHdr + 1;
    }
    else {
        return NULL;
    }
}

/* Object__next__S */
xdc_Ptr ti_sysbios_knl_Queue_Object__next__S( xdc_Ptr obj )
{
    xdc_runtime_Types_InstHdr *iHdr = ((xdc_runtime_Types_InstHdr *)obj) - 1;

    if (iHdr->link.next != (xdc_runtime_Types_Link *)&ti_sysbios_knl_Queue_Module__root__V.link) {
        return (xdc_runtime_Types_InstHdr *)(iHdr->link.next) + 1;
    }
    else {
        return NULL;
    }
}

/* Object__create__S */
xdc_Ptr ti_sysbios_knl_Queue_Object__create__S(
    xdc_CPtr req_args,
    const xdc_UChar *paramsPtr,
    xdc_SizeT prm_size,
    xdc_runtime_Error_Block *eb)
{
    ti_sysbios_knl_Queue_Params instPrms;
    ti_sysbios_knl_Queue_Object *objp;

    /* common instance initialization */
    objp = xdc_runtime_Core_createObject__I(&ti_sysbios_knl_Queue_Object__DESC__C, NULL, &instPrms, (xdc_CPtr)paramsPtr, 0, eb);
    if (objp == NULL) {
        return NULL;
    }


    /* module-specific initialization */
    ti_sysbios_knl_Queue_Instance_init__E(objp, &instPrms);
    return objp;
}

/* create */
ti_sysbios_knl_Queue_Handle ti_sysbios_knl_Queue_create( const ti_sysbios_knl_Queue_Params *paramsPtr, xdc_runtime_Error_Block *eb)
{
    ti_sysbios_knl_Queue_Params prms;
    ti_sysbios_knl_Queue_Object *obj;


    /* common instance initialization */
    obj = xdc_runtime_Core_createObject__I(&ti_sysbios_knl_Queue_Object__DESC__C, NULL, &prms, (xdc_CPtr)paramsPtr, 0, eb);
    if (obj == NULL) {
        return NULL;
    }

    /* module-specific initialization */
    ti_sysbios_knl_Queue_Instance_init__E(obj, &prms);
    return obj;
}

/* construct */
void ti_sysbios_knl_Queue_construct(ti_sysbios_knl_Queue_Struct *objp, const ti_sysbios_knl_Queue_Params *paramsPtr)
{
    ti_sysbios_knl_Queue_Params instPrms;

    /* common instance initialization */
    (Void)xdc_runtime_Core_constructObject__I(&ti_sysbios_knl_Queue_Object__DESC__C, objp, &instPrms, (xdc_CPtr)paramsPtr, 0, NULL);

    /* module-specific initialization */
    ti_sysbios_knl_Queue_Instance_init__E((xdc_Ptr)objp, &instPrms);
}

/* destruct */
void ti_sysbios_knl_Queue_destruct(ti_sysbios_knl_Queue_Struct *obj)
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_knl_Queue_Object__DESC__C, obj, NULL, -1, TRUE);
}

/* Object__delete__S */
xdc_Void ti_sysbios_knl_Queue_Object__delete__S( xdc_Ptr instp ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_knl_Queue_Object__DESC__C, *((ti_sysbios_knl_Queue_Object**)instp), NULL, -1, FALSE);
    *((ti_sysbios_knl_Queue_Handle*)instp) = NULL;
}

/* delete */
void ti_sysbios_knl_Queue_delete(ti_sysbios_knl_Queue_Handle *instp)
{
    ti_sysbios_knl_Queue_Object__delete__S(instp);
}


/*
 * ======== ti.sysbios.knl.Semaphore SYSTEM FUNCTIONS ========
 */

/* per-module runtime symbols */
#undef Module__MID
#define Module__MID ti_sysbios_knl_Semaphore_Module__id__C

#undef Module__DGSINCL
#define Module__DGSINCL ti_sysbios_knl_Semaphore_Module__diagsIncluded__C

#undef Module__DGSENAB
#define Module__DGSENAB ti_sysbios_knl_Semaphore_Module__diagsEnabled__C

#undef Module__DGSMASK
#define Module__DGSMASK ti_sysbios_knl_Semaphore_Module__diagsMask__C

#undef Module__LOGDEF
#define Module__LOGDEF ti_sysbios_knl_Semaphore_Module__loggerDefined__C

#undef Module__LOGOBJ
#define Module__LOGOBJ ti_sysbios_knl_Semaphore_Module__loggerObj__C

#undef Module__LOGFXN0
#define Module__LOGFXN0 ti_sysbios_knl_Semaphore_Module__loggerFxn0__C

#undef Module__LOGFXN1
#define Module__LOGFXN1 ti_sysbios_knl_Semaphore_Module__loggerFxn1__C

#undef Module__LOGFXN2
#define Module__LOGFXN2 ti_sysbios_knl_Semaphore_Module__loggerFxn2__C

#undef Module__LOGFXN4
#define Module__LOGFXN4 ti_sysbios_knl_Semaphore_Module__loggerFxn4__C

#undef Module__LOGFXN8
#define Module__LOGFXN8 ti_sysbios_knl_Semaphore_Module__loggerFxn8__C

#undef Module__G_OBJ
#define Module__G_OBJ ti_sysbios_knl_Semaphore_Module__gateObj__C

#undef Module__G_PRMS
#define Module__G_PRMS ti_sysbios_knl_Semaphore_Module__gatePrms__C

#undef Module__GP_create
#define Module__GP_create ti_sysbios_knl_Semaphore_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete ti_sysbios_knl_Semaphore_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter ti_sysbios_knl_Semaphore_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave ti_sysbios_knl_Semaphore_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query ti_sysbios_knl_Semaphore_Module_GateProxy_query

/* Module__startupDone__S */
xdc_Bool ti_sysbios_knl_Semaphore_Module__startupDone__S( void )
{
    return 1;
}

/* Handle__label__S */
xdc_runtime_Types_Label *ti_sysbios_knl_Semaphore_Handle__label__S(xdc_Ptr obj, xdc_runtime_Types_Label *lab) 
{
    lab->handle = obj;
    lab->modId = 32799;
    lab->named = FALSE;
    lab->iname = xdc_runtime_Text_nameUnknown;

    return lab;
}

/* Params__init__S */
xdc_Void ti_sysbios_knl_Semaphore_Params__init__S( xdc_Ptr prms, const void *src, xdc_SizeT psz, xdc_SizeT isz ) 
{
    xdc_runtime_Core_assignParams__I(prms, (xdc_CPtr)(src ? src : &ti_sysbios_knl_Semaphore_Object__PARAMS__C), psz, isz);
}

/* Object__get__S */
xdc_Ptr ti_sysbios_knl_Semaphore_Object__get__S(xdc_Ptr oa, xdc_Int i)
{
    if (oa != NULL) {
        return ((ti_sysbios_knl_Semaphore_Object__ *)oa) + i;
    }

    return NULL;
}


/* Object__first__S */
xdc_Ptr ti_sysbios_knl_Semaphore_Object__first__S( void ) 
{
    xdc_runtime_Types_InstHdr *iHdr = (xdc_runtime_Types_InstHdr *)ti_sysbios_knl_Semaphore_Module__root__V.link.next;

    if (iHdr != (xdc_runtime_Types_InstHdr *)&ti_sysbios_knl_Semaphore_Module__root__V.link) {
        return iHdr + 1;
    }
    else {
        return NULL;
    }
}

/* Object__next__S */
xdc_Ptr ti_sysbios_knl_Semaphore_Object__next__S( xdc_Ptr obj )
{
    xdc_runtime_Types_InstHdr *iHdr = ((xdc_runtime_Types_InstHdr *)obj) - 1;

    if (iHdr->link.next != (xdc_runtime_Types_Link *)&ti_sysbios_knl_Semaphore_Module__root__V.link) {
        return (xdc_runtime_Types_InstHdr *)(iHdr->link.next) + 1;
    }
    else {
        return NULL;
    }
}

/* Object__create__S */
xdc_Ptr ti_sysbios_knl_Semaphore_Object__create__S(
    xdc_CPtr req_args,
    const xdc_UChar *paramsPtr,
    xdc_SizeT prm_size,
    xdc_runtime_Error_Block *eb)
{
    const ti_sysbios_knl_Semaphore_Args__create *__args = req_args;
    ti_sysbios_knl_Semaphore_Params instPrms;
    ti_sysbios_knl_Semaphore_Object *objp;

    /* common instance initialization */
    objp = xdc_runtime_Core_createObject__I(&ti_sysbios_knl_Semaphore_Object__DESC__C, NULL, &instPrms, (xdc_CPtr)paramsPtr, 0, eb);
    if (objp == NULL) {
        return NULL;
    }


    /* module-specific initialization */
    ti_sysbios_knl_Semaphore_Instance_init__E(objp, __args->count, &instPrms);
    return objp;
}

/* create */
ti_sysbios_knl_Semaphore_Handle ti_sysbios_knl_Semaphore_create( xdc_Int count, const ti_sysbios_knl_Semaphore_Params *paramsPtr, xdc_runtime_Error_Block *eb)
{
    ti_sysbios_knl_Semaphore_Params prms;
    ti_sysbios_knl_Semaphore_Object *obj;


    /* common instance initialization */
    obj = xdc_runtime_Core_createObject__I(&ti_sysbios_knl_Semaphore_Object__DESC__C, NULL, &prms, (xdc_CPtr)paramsPtr, 0, eb);
    if (obj == NULL) {
        return NULL;
    }

    /* module-specific initialization */
    ti_sysbios_knl_Semaphore_Instance_init__E(obj, count, &prms);
    return obj;
}

/* construct */
void ti_sysbios_knl_Semaphore_construct(ti_sysbios_knl_Semaphore_Struct *objp, xdc_Int count, const ti_sysbios_knl_Semaphore_Params *paramsPtr)
{
    ti_sysbios_knl_Semaphore_Params instPrms;

    /* common instance initialization */
    (Void)xdc_runtime_Core_constructObject__I(&ti_sysbios_knl_Semaphore_Object__DESC__C, objp, &instPrms, (xdc_CPtr)paramsPtr, 0, NULL);

    /* module-specific initialization */
    ti_sysbios_knl_Semaphore_Instance_init__E((xdc_Ptr)objp, count, &instPrms);
}

/* destruct */
void ti_sysbios_knl_Semaphore_destruct(ti_sysbios_knl_Semaphore_Struct *obj)
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_knl_Semaphore_Object__DESC__C, obj, (xdc_Fxn)ti_sysbios_knl_Semaphore_Instance_finalize__E, -1, TRUE);
}

/* Object__delete__S */
xdc_Void ti_sysbios_knl_Semaphore_Object__delete__S( xdc_Ptr instp ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_knl_Semaphore_Object__DESC__C, *((ti_sysbios_knl_Semaphore_Object**)instp), (xdc_Fxn)ti_sysbios_knl_Semaphore_Instance_finalize__E, -1, FALSE);
    *((ti_sysbios_knl_Semaphore_Handle*)instp) = NULL;
}

/* delete */
void ti_sysbios_knl_Semaphore_delete(ti_sysbios_knl_Semaphore_Handle *instp)
{
    ti_sysbios_knl_Semaphore_Object__delete__S(instp);
}


/*
 * ======== ti.sysbios.knl.Swi SYSTEM FUNCTIONS ========
 */

/* per-module runtime symbols */
#undef Module__MID
#define Module__MID ti_sysbios_knl_Swi_Module__id__C

#undef Module__DGSINCL
#define Module__DGSINCL ti_sysbios_knl_Swi_Module__diagsIncluded__C

#undef Module__DGSENAB
#define Module__DGSENAB ti_sysbios_knl_Swi_Module__diagsEnabled__C

#undef Module__DGSMASK
#define Module__DGSMASK ti_sysbios_knl_Swi_Module__diagsMask__C

#undef Module__LOGDEF
#define Module__LOGDEF ti_sysbios_knl_Swi_Module__loggerDefined__C

#undef Module__LOGOBJ
#define Module__LOGOBJ ti_sysbios_knl_Swi_Module__loggerObj__C

#undef Module__LOGFXN0
#define Module__LOGFXN0 ti_sysbios_knl_Swi_Module__loggerFxn0__C

#undef Module__LOGFXN1
#define Module__LOGFXN1 ti_sysbios_knl_Swi_Module__loggerFxn1__C

#undef Module__LOGFXN2
#define Module__LOGFXN2 ti_sysbios_knl_Swi_Module__loggerFxn2__C

#undef Module__LOGFXN4
#define Module__LOGFXN4 ti_sysbios_knl_Swi_Module__loggerFxn4__C

#undef Module__LOGFXN8
#define Module__LOGFXN8 ti_sysbios_knl_Swi_Module__loggerFxn8__C

#undef Module__G_OBJ
#define Module__G_OBJ ti_sysbios_knl_Swi_Module__gateObj__C

#undef Module__G_PRMS
#define Module__G_PRMS ti_sysbios_knl_Swi_Module__gatePrms__C

#undef Module__GP_create
#define Module__GP_create ti_sysbios_knl_Swi_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete ti_sysbios_knl_Swi_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter ti_sysbios_knl_Swi_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave ti_sysbios_knl_Swi_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query ti_sysbios_knl_Swi_Module_GateProxy_query

/* Module__startupDone__S */
xdc_Bool ti_sysbios_knl_Swi_Module__startupDone__S( void )
{
    return ti_sysbios_knl_Swi_Module__startupDone__F();
}

/* Handle__label__S */
xdc_runtime_Types_Label *ti_sysbios_knl_Swi_Handle__label__S(xdc_Ptr obj, xdc_runtime_Types_Label *lab) 
{
    lab->handle = obj;
    lab->modId = 32800;
    lab->named = FALSE;
    lab->iname = xdc_runtime_Text_nameUnknown;

    return lab;
}

/* Params__init__S */
xdc_Void ti_sysbios_knl_Swi_Params__init__S( xdc_Ptr prms, const void *src, xdc_SizeT psz, xdc_SizeT isz ) 
{
    xdc_runtime_Core_assignParams__I(prms, (xdc_CPtr)(src ? src : &ti_sysbios_knl_Swi_Object__PARAMS__C), psz, isz);
}

/* Object__get__S */
xdc_Ptr ti_sysbios_knl_Swi_Object__get__S(xdc_Ptr oa, xdc_Int i)
{
    if (oa != NULL) {
        return ((ti_sysbios_knl_Swi_Object__ *)oa) + i;
    }

    /* the bogus 'const' in the cast suppresses Klocwork MISRA complaints */
    return ((ti_sysbios_knl_Swi_Object__ * const)ti_sysbios_knl_Swi_Object__table__C) + i;
}

/* Object__first__S */
xdc_Ptr ti_sysbios_knl_Swi_Object__first__S( void ) 
{
    xdc_runtime_Types_InstHdr *iHdr = (xdc_runtime_Types_InstHdr *)ti_sysbios_knl_Swi_Module__root__V.link.next;

    if (iHdr != (xdc_runtime_Types_InstHdr *)&ti_sysbios_knl_Swi_Module__root__V.link) {
        return iHdr + 1;
    }
    else {
        return NULL;
    }
}

/* Object__next__S */
xdc_Ptr ti_sysbios_knl_Swi_Object__next__S( xdc_Ptr obj )
{
    xdc_runtime_Types_InstHdr *iHdr = ((xdc_runtime_Types_InstHdr *)obj) - 1;

    if (iHdr->link.next != (xdc_runtime_Types_Link *)&ti_sysbios_knl_Swi_Module__root__V.link) {
        return (xdc_runtime_Types_InstHdr *)(iHdr->link.next) + 1;
    }
    else {
        return NULL;
    }
}

/* Object__create__S */
xdc_Ptr ti_sysbios_knl_Swi_Object__create__S(
    xdc_CPtr req_args,
    const xdc_UChar *paramsPtr,
    xdc_SizeT prm_size,
    xdc_runtime_Error_Block *eb)
{
    const ti_sysbios_knl_Swi_Args__create *__args = req_args;
    ti_sysbios_knl_Swi_Params instPrms;
    ti_sysbios_knl_Swi_Object *objp;
    int iStat;

    /* common instance initialization */
    objp = xdc_runtime_Core_createObject__I(&ti_sysbios_knl_Swi_Object__DESC__C, NULL, &instPrms, (xdc_CPtr)paramsPtr, 0, eb);
    if (objp == NULL) {
        return NULL;
    }


    /* module-specific initialization */
    iStat = ti_sysbios_knl_Swi_Instance_init__E(objp, __args->swiFxn, &instPrms, eb);
    if (iStat) {
        xdc_runtime_Core_deleteObject__I(&ti_sysbios_knl_Swi_Object__DESC__C, objp, (xdc_Fxn)ti_sysbios_knl_Swi_Instance_finalize__E, iStat, 0);
        return NULL;
    }

    return objp;
}

/* create */
ti_sysbios_knl_Swi_Handle ti_sysbios_knl_Swi_create( ti_sysbios_knl_Swi_FuncPtr swiFxn, const ti_sysbios_knl_Swi_Params *paramsPtr, xdc_runtime_Error_Block *eb)
{
    ti_sysbios_knl_Swi_Params prms;
    ti_sysbios_knl_Swi_Object *obj;

    int iStat;

    /* common instance initialization */
    obj = xdc_runtime_Core_createObject__I(&ti_sysbios_knl_Swi_Object__DESC__C, NULL, &prms, (xdc_CPtr)paramsPtr, 0, eb);
    if (obj == NULL) {
        return NULL;
    }

    /* module-specific initialization */
    iStat = ti_sysbios_knl_Swi_Instance_init__E(obj, swiFxn, &prms, eb);
    if (iStat) {
        xdc_runtime_Core_deleteObject__I(&ti_sysbios_knl_Swi_Object__DESC__C, obj, (xdc_Fxn)ti_sysbios_knl_Swi_Instance_finalize__E, iStat, 0);
        return NULL;
    }

    return obj;
}

/* construct */
void ti_sysbios_knl_Swi_construct(ti_sysbios_knl_Swi_Struct *objp, ti_sysbios_knl_Swi_FuncPtr swiFxn, const ti_sysbios_knl_Swi_Params *paramsPtr, xdc_runtime_Error_Block *eb)
{
    ti_sysbios_knl_Swi_Params instPrms;
    int iStat;

    /* common instance initialization */
    (Void)xdc_runtime_Core_constructObject__I(&ti_sysbios_knl_Swi_Object__DESC__C, objp, &instPrms, (xdc_CPtr)paramsPtr, 0, eb);

    /* module-specific initialization */
    iStat = ti_sysbios_knl_Swi_Instance_init__E((xdc_Ptr)objp, swiFxn, &instPrms, eb);
    if (iStat) {
        xdc_runtime_Core_deleteObject__I(&ti_sysbios_knl_Swi_Object__DESC__C, objp, (xdc_Fxn)ti_sysbios_knl_Swi_Instance_finalize__E, iStat, 1);
    }

}

/* destruct */
void ti_sysbios_knl_Swi_destruct(ti_sysbios_knl_Swi_Struct *obj)
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_knl_Swi_Object__DESC__C, obj, (xdc_Fxn)ti_sysbios_knl_Swi_Instance_finalize__E, 0, TRUE);
}

/* Object__delete__S */
xdc_Void ti_sysbios_knl_Swi_Object__delete__S( xdc_Ptr instp ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_knl_Swi_Object__DESC__C, *((ti_sysbios_knl_Swi_Object**)instp), (xdc_Fxn)ti_sysbios_knl_Swi_Instance_finalize__E, 0, FALSE);
    *((ti_sysbios_knl_Swi_Handle*)instp) = NULL;
}

/* delete */
void ti_sysbios_knl_Swi_delete(ti_sysbios_knl_Swi_Handle *instp)
{
    ti_sysbios_knl_Swi_Object__delete__S(instp);
}


/*
 * ======== ti.sysbios.knl.Task SYSTEM FUNCTIONS ========
 */

/* per-module runtime symbols */
#undef Module__MID
#define Module__MID ti_sysbios_knl_Task_Module__id__C

#undef Module__DGSINCL
#define Module__DGSINCL ti_sysbios_knl_Task_Module__diagsIncluded__C

#undef Module__DGSENAB
#define Module__DGSENAB ti_sysbios_knl_Task_Module__diagsEnabled__C

#undef Module__DGSMASK
#define Module__DGSMASK ti_sysbios_knl_Task_Module__diagsMask__C

#undef Module__LOGDEF
#define Module__LOGDEF ti_sysbios_knl_Task_Module__loggerDefined__C

#undef Module__LOGOBJ
#define Module__LOGOBJ ti_sysbios_knl_Task_Module__loggerObj__C

#undef Module__LOGFXN0
#define Module__LOGFXN0 ti_sysbios_knl_Task_Module__loggerFxn0__C

#undef Module__LOGFXN1
#define Module__LOGFXN1 ti_sysbios_knl_Task_Module__loggerFxn1__C

#undef Module__LOGFXN2
#define Module__LOGFXN2 ti_sysbios_knl_Task_Module__loggerFxn2__C

#undef Module__LOGFXN4
#define Module__LOGFXN4 ti_sysbios_knl_Task_Module__loggerFxn4__C

#undef Module__LOGFXN8
#define Module__LOGFXN8 ti_sysbios_knl_Task_Module__loggerFxn8__C

#undef Module__G_OBJ
#define Module__G_OBJ ti_sysbios_knl_Task_Module__gateObj__C

#undef Module__G_PRMS
#define Module__G_PRMS ti_sysbios_knl_Task_Module__gatePrms__C

#undef Module__GP_create
#define Module__GP_create ti_sysbios_knl_Task_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete ti_sysbios_knl_Task_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter ti_sysbios_knl_Task_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave ti_sysbios_knl_Task_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query ti_sysbios_knl_Task_Module_GateProxy_query

/* Module__startupDone__S */
xdc_Bool ti_sysbios_knl_Task_Module__startupDone__S( void )
{
    return ti_sysbios_knl_Task_Module__startupDone__F();
}

/* Handle__label__S */
xdc_runtime_Types_Label *ti_sysbios_knl_Task_Handle__label__S(xdc_Ptr obj, xdc_runtime_Types_Label *lab) 
{
    lab->handle = obj;
    lab->modId = 32801;
    lab->named = FALSE;
    lab->iname = xdc_runtime_Text_nameUnknown;

    return lab;
}

/* Params__init__S */
xdc_Void ti_sysbios_knl_Task_Params__init__S( xdc_Ptr prms, const void *src, xdc_SizeT psz, xdc_SizeT isz ) 
{
    xdc_runtime_Core_assignParams__I(prms, (xdc_CPtr)(src ? src : &ti_sysbios_knl_Task_Object__PARAMS__C), psz, isz);
}

/* Object__get__S */
xdc_Ptr ti_sysbios_knl_Task_Object__get__S(xdc_Ptr oa, xdc_Int i)
{
    if (oa != NULL) {
        return ((ti_sysbios_knl_Task_Object__ *)oa) + i;
    }

    /* the bogus 'const' in the cast suppresses Klocwork MISRA complaints */
    return ((ti_sysbios_knl_Task_Object__ * const)ti_sysbios_knl_Task_Object__table__C) + i;
}

/* Object__first__S */
xdc_Ptr ti_sysbios_knl_Task_Object__first__S( void ) 
{
    xdc_runtime_Types_InstHdr *iHdr = (xdc_runtime_Types_InstHdr *)ti_sysbios_knl_Task_Module__root__V.link.next;

    if (iHdr != (xdc_runtime_Types_InstHdr *)&ti_sysbios_knl_Task_Module__root__V.link) {
        return iHdr + 1;
    }
    else {
        return NULL;
    }
}

/* Object__next__S */
xdc_Ptr ti_sysbios_knl_Task_Object__next__S( xdc_Ptr obj )
{
    xdc_runtime_Types_InstHdr *iHdr = ((xdc_runtime_Types_InstHdr *)obj) - 1;

    if (iHdr->link.next != (xdc_runtime_Types_Link *)&ti_sysbios_knl_Task_Module__root__V.link) {
        return (xdc_runtime_Types_InstHdr *)(iHdr->link.next) + 1;
    }
    else {
        return NULL;
    }
}

/* Object__create__S */
xdc_Ptr ti_sysbios_knl_Task_Object__create__S(
    xdc_CPtr req_args,
    const xdc_UChar *paramsPtr,
    xdc_SizeT prm_size,
    xdc_runtime_Error_Block *eb)
{
    const ti_sysbios_knl_Task_Args__create *__args = req_args;
    ti_sysbios_knl_Task_Params instPrms;
    ti_sysbios_knl_Task_Object *objp;
    int iStat;

    /* common instance initialization */
    objp = xdc_runtime_Core_createObject__I(&ti_sysbios_knl_Task_Object__DESC__C, NULL, &instPrms, (xdc_CPtr)paramsPtr, 0, eb);
    if (objp == NULL) {
        return NULL;
    }


    /* module-specific initialization */
    iStat = ti_sysbios_knl_Task_Instance_init__E(objp, __args->fxn, &instPrms, eb);
    if (iStat) {
        xdc_runtime_Core_deleteObject__I(&ti_sysbios_knl_Task_Object__DESC__C, objp, (xdc_Fxn)ti_sysbios_knl_Task_Instance_finalize__E, iStat, 0);
        return NULL;
    }

    return objp;
}

/* create */
ti_sysbios_knl_Task_Handle ti_sysbios_knl_Task_create( ti_sysbios_knl_Task_FuncPtr fxn, const ti_sysbios_knl_Task_Params *paramsPtr, xdc_runtime_Error_Block *eb)
{
    ti_sysbios_knl_Task_Params prms;
    ti_sysbios_knl_Task_Object *obj;

    int iStat;

    /* common instance initialization */
    obj = xdc_runtime_Core_createObject__I(&ti_sysbios_knl_Task_Object__DESC__C, NULL, &prms, (xdc_CPtr)paramsPtr, 0, eb);
    if (obj == NULL) {
        return NULL;
    }

    /* module-specific initialization */
    iStat = ti_sysbios_knl_Task_Instance_init__E(obj, fxn, &prms, eb);
    if (iStat) {
        xdc_runtime_Core_deleteObject__I(&ti_sysbios_knl_Task_Object__DESC__C, obj, (xdc_Fxn)ti_sysbios_knl_Task_Instance_finalize__E, iStat, 0);
        return NULL;
    }

    return obj;
}

/* construct */
void ti_sysbios_knl_Task_construct(ti_sysbios_knl_Task_Struct *objp, ti_sysbios_knl_Task_FuncPtr fxn, const ti_sysbios_knl_Task_Params *paramsPtr, xdc_runtime_Error_Block *eb)
{
    ti_sysbios_knl_Task_Params instPrms;
    int iStat;

    /* common instance initialization */
    (Void)xdc_runtime_Core_constructObject__I(&ti_sysbios_knl_Task_Object__DESC__C, objp, &instPrms, (xdc_CPtr)paramsPtr, 0, eb);

    /* module-specific initialization */
    iStat = ti_sysbios_knl_Task_Instance_init__E((xdc_Ptr)objp, fxn, &instPrms, eb);
    if (iStat) {
        xdc_runtime_Core_deleteObject__I(&ti_sysbios_knl_Task_Object__DESC__C, objp, (xdc_Fxn)ti_sysbios_knl_Task_Instance_finalize__E, iStat, 1);
    }

}

/* destruct */
void ti_sysbios_knl_Task_destruct(ti_sysbios_knl_Task_Struct *obj)
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_knl_Task_Object__DESC__C, obj, (xdc_Fxn)ti_sysbios_knl_Task_Instance_finalize__E, 0, TRUE);
}

/* Object__delete__S */
xdc_Void ti_sysbios_knl_Task_Object__delete__S( xdc_Ptr instp ) 
{
    xdc_runtime_Core_deleteObject__I(&ti_sysbios_knl_Task_Object__DESC__C, *((ti_sysbios_knl_Task_Object**)instp), (xdc_Fxn)ti_sysbios_knl_Task_Instance_finalize__E, 0, FALSE);
    *((ti_sysbios_knl_Task_Handle*)instp) = NULL;
}

/* delete */
void ti_sysbios_knl_Task_delete(ti_sysbios_knl_Task_Handle *instp)
{
    ti_sysbios_knl_Task_Object__delete__S(instp);
}


/*
 * ======== ti.sysbios.knl.Task_SupportProxy SYSTEM FUNCTIONS ========
 */


xdc_Bool ti_sysbios_knl_Task_SupportProxy_Proxy__abstract__S(void)
{
    return 0;
}
xdc_CPtr ti_sysbios_knl_Task_SupportProxy_Proxy__delegate__S(void)
{
    return 0;
}


/*
 * ======== xdc.runtime.Assert SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool xdc_runtime_Assert_Module__startupDone__S( void )
{
    return 1;
}



/*
 * ======== xdc.runtime.Core SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool xdc_runtime_Core_Module__startupDone__S( void )
{
    return 1;
}



/*
 * ======== xdc.runtime.Defaults SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool xdc_runtime_Defaults_Module__startupDone__S( void )
{
    return 1;
}



/*
 * ======== xdc.runtime.Diags SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool xdc_runtime_Diags_Module__startupDone__S( void )
{
    return 1;
}



/*
 * ======== xdc.runtime.Error SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool xdc_runtime_Error_Module__startupDone__S( void )
{
    return 1;
}



/*
 * ======== xdc.runtime.Gate SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool xdc_runtime_Gate_Module__startupDone__S( void )
{
    return 1;
}



/*
 * ======== xdc.runtime.Log SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool xdc_runtime_Log_Module__startupDone__S( void )
{
    return 1;
}



/*
 * ======== xdc.runtime.LoggerBuf SYSTEM FUNCTIONS ========
 */

/* per-module runtime symbols */
#undef Module__MID
#define Module__MID xdc_runtime_LoggerBuf_Module__id__C

#undef Module__DGSINCL
#define Module__DGSINCL xdc_runtime_LoggerBuf_Module__diagsIncluded__C

#undef Module__DGSENAB
#define Module__DGSENAB xdc_runtime_LoggerBuf_Module__diagsEnabled__C

#undef Module__DGSMASK
#define Module__DGSMASK xdc_runtime_LoggerBuf_Module__diagsMask__C

#undef Module__LOGDEF
#define Module__LOGDEF xdc_runtime_LoggerBuf_Module__loggerDefined__C

#undef Module__LOGOBJ
#define Module__LOGOBJ xdc_runtime_LoggerBuf_Module__loggerObj__C

#undef Module__LOGFXN0
#define Module__LOGFXN0 xdc_runtime_LoggerBuf_Module__loggerFxn0__C

#undef Module__LOGFXN1
#define Module__LOGFXN1 xdc_runtime_LoggerBuf_Module__loggerFxn1__C

#undef Module__LOGFXN2
#define Module__LOGFXN2 xdc_runtime_LoggerBuf_Module__loggerFxn2__C

#undef Module__LOGFXN4
#define Module__LOGFXN4 xdc_runtime_LoggerBuf_Module__loggerFxn4__C

#undef Module__LOGFXN8
#define Module__LOGFXN8 xdc_runtime_LoggerBuf_Module__loggerFxn8__C

#undef Module__G_OBJ
#define Module__G_OBJ xdc_runtime_LoggerBuf_Module__gateObj__C

#undef Module__G_PRMS
#define Module__G_PRMS xdc_runtime_LoggerBuf_Module__gatePrms__C

#undef Module__GP_create
#define Module__GP_create xdc_runtime_LoggerBuf_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete xdc_runtime_LoggerBuf_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter xdc_runtime_LoggerBuf_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave xdc_runtime_LoggerBuf_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query xdc_runtime_LoggerBuf_Module_GateProxy_query

/* Module__startupDone__S */
xdc_Bool xdc_runtime_LoggerBuf_Module__startupDone__S( void )
{
    return xdc_runtime_LoggerBuf_Module__startupDone__F();
}

/* Handle__label__S */
xdc_runtime_Types_Label *xdc_runtime_LoggerBuf_Handle__label__S(xdc_Ptr obj, xdc_runtime_Types_Label *lab) 
{
    lab->handle = obj;
    lab->modId = 32777;
    lab->named = FALSE;
    lab->iname = xdc_runtime_Text_nameUnknown;

    return lab;
}

/* Params__init__S */
xdc_Void xdc_runtime_LoggerBuf_Params__init__S( xdc_Ptr prms, const void *src, xdc_SizeT psz, xdc_SizeT isz ) 
{
    xdc_runtime_Core_assignParams__I(prms, (xdc_CPtr)(src ? src : &xdc_runtime_LoggerBuf_Object__PARAMS__C), psz, isz);
}

/* Object__get__S */
xdc_Ptr xdc_runtime_LoggerBuf_Object__get__S(xdc_Ptr oa, xdc_Int i)
{
    if (oa != NULL) {
        return ((xdc_runtime_LoggerBuf_Object__ *)oa) + i;
    }

    /* the bogus 'const' in the cast suppresses Klocwork MISRA complaints */
    return ((xdc_runtime_LoggerBuf_Object__ * const)xdc_runtime_LoggerBuf_Object__table__C) + i;
}

/* Object__first__S */
xdc_Ptr xdc_runtime_LoggerBuf_Object__first__S( void ) 
{
    xdc_runtime_Types_InstHdr *iHdr = (xdc_runtime_Types_InstHdr *)xdc_runtime_LoggerBuf_Module__root__V.link.next;

    if (iHdr != (xdc_runtime_Types_InstHdr *)&xdc_runtime_LoggerBuf_Module__root__V.link) {
        return iHdr + 1;
    }
    else {
        return NULL;
    }
}

/* Object__next__S */
xdc_Ptr xdc_runtime_LoggerBuf_Object__next__S( xdc_Ptr obj )
{
    xdc_runtime_Types_InstHdr *iHdr = ((xdc_runtime_Types_InstHdr *)obj) - 1;

    if (iHdr->link.next != (xdc_runtime_Types_Link *)&xdc_runtime_LoggerBuf_Module__root__V.link) {
        return (xdc_runtime_Types_InstHdr *)(iHdr->link.next) + 1;
    }
    else {
        return NULL;
    }
}

/* Object__create__S */
xdc_Ptr xdc_runtime_LoggerBuf_Object__create__S(
    xdc_CPtr req_args,
    const xdc_UChar *paramsPtr,
    xdc_SizeT prm_size,
    xdc_runtime_Error_Block *eb)
{
    xdc_runtime_LoggerBuf_Params instPrms;
    xdc_runtime_LoggerBuf_Object *objp;
    int iStat;

    /* common instance initialization */
    objp = xdc_runtime_Core_createObject__I(&xdc_runtime_LoggerBuf_Object__DESC__C, NULL, &instPrms, (xdc_CPtr)paramsPtr, 0, eb);
    if (objp == NULL) {
        return NULL;
    }


    /* module-specific initialization */
    iStat = xdc_runtime_LoggerBuf_Instance_init__E(objp, &instPrms, eb);
    if (iStat) {
        xdc_runtime_Core_deleteObject__I(&xdc_runtime_LoggerBuf_Object__DESC__C, objp, (xdc_Fxn)xdc_runtime_LoggerBuf_Instance_finalize__E, iStat, 0);
        return NULL;
    }

    return objp;
}

/* create */
xdc_runtime_LoggerBuf_Handle xdc_runtime_LoggerBuf_create( const xdc_runtime_LoggerBuf_Params *paramsPtr, xdc_runtime_Error_Block *eb)
{
    xdc_runtime_LoggerBuf_Params prms;
    xdc_runtime_LoggerBuf_Object *obj;

    int iStat;

    /* common instance initialization */
    obj = xdc_runtime_Core_createObject__I(&xdc_runtime_LoggerBuf_Object__DESC__C, NULL, &prms, (xdc_CPtr)paramsPtr, 0, eb);
    if (obj == NULL) {
        return NULL;
    }

    /* module-specific initialization */
    iStat = xdc_runtime_LoggerBuf_Instance_init__E(obj, &prms, eb);
    if (iStat) {
        xdc_runtime_Core_deleteObject__I(&xdc_runtime_LoggerBuf_Object__DESC__C, obj, (xdc_Fxn)xdc_runtime_LoggerBuf_Instance_finalize__E, iStat, 0);
        return NULL;
    }

    return obj;
}

/* construct */
void xdc_runtime_LoggerBuf_construct(xdc_runtime_LoggerBuf_Struct *objp, const xdc_runtime_LoggerBuf_Params *paramsPtr, xdc_runtime_Error_Block *eb)
{
    xdc_runtime_LoggerBuf_Params instPrms;
    int iStat;

    /* common instance initialization */
    (Void)xdc_runtime_Core_constructObject__I(&xdc_runtime_LoggerBuf_Object__DESC__C, objp, &instPrms, (xdc_CPtr)paramsPtr, 0, eb);

    /* module-specific initialization */
    iStat = xdc_runtime_LoggerBuf_Instance_init__E((xdc_Ptr)objp, &instPrms, eb);
    if (iStat) {
        xdc_runtime_Core_deleteObject__I(&xdc_runtime_LoggerBuf_Object__DESC__C, objp, (xdc_Fxn)xdc_runtime_LoggerBuf_Instance_finalize__E, iStat, 1);
    }

}

/* destruct */
void xdc_runtime_LoggerBuf_destruct(xdc_runtime_LoggerBuf_Struct *obj)
{
    xdc_runtime_Core_deleteObject__I(&xdc_runtime_LoggerBuf_Object__DESC__C, obj, (xdc_Fxn)xdc_runtime_LoggerBuf_Instance_finalize__E, 0, TRUE);
}

/* Object__delete__S */
xdc_Void xdc_runtime_LoggerBuf_Object__delete__S( xdc_Ptr instp ) 
{
    xdc_runtime_Core_deleteObject__I(&xdc_runtime_LoggerBuf_Object__DESC__C, *((xdc_runtime_LoggerBuf_Object**)instp), (xdc_Fxn)xdc_runtime_LoggerBuf_Instance_finalize__E, 0, FALSE);
    *((xdc_runtime_LoggerBuf_Handle*)instp) = NULL;
}

/* delete */
void xdc_runtime_LoggerBuf_delete(xdc_runtime_LoggerBuf_Handle *instp)
{
    xdc_runtime_LoggerBuf_Object__delete__S(instp);
}


/*
 * ======== xdc.runtime.LoggerBuf_Module_GateProxy SYSTEM FUNCTIONS ========
 */

/* per-module runtime symbols */
#undef Module__MID
#define Module__MID xdc_runtime_LoggerBuf_Module_GateProxy_Module__id__C

#undef Module__DGSINCL
#define Module__DGSINCL xdc_runtime_LoggerBuf_Module_GateProxy_Module__diagsIncluded__C

#undef Module__DGSENAB
#define Module__DGSENAB xdc_runtime_LoggerBuf_Module_GateProxy_Module__diagsEnabled__C

#undef Module__DGSMASK
#define Module__DGSMASK xdc_runtime_LoggerBuf_Module_GateProxy_Module__diagsMask__C

#undef Module__LOGDEF
#define Module__LOGDEF xdc_runtime_LoggerBuf_Module_GateProxy_Module__loggerDefined__C

#undef Module__LOGOBJ
#define Module__LOGOBJ xdc_runtime_LoggerBuf_Module_GateProxy_Module__loggerObj__C

#undef Module__LOGFXN0
#define Module__LOGFXN0 xdc_runtime_LoggerBuf_Module_GateProxy_Module__loggerFxn0__C

#undef Module__LOGFXN1
#define Module__LOGFXN1 xdc_runtime_LoggerBuf_Module_GateProxy_Module__loggerFxn1__C

#undef Module__LOGFXN2
#define Module__LOGFXN2 xdc_runtime_LoggerBuf_Module_GateProxy_Module__loggerFxn2__C

#undef Module__LOGFXN4
#define Module__LOGFXN4 xdc_runtime_LoggerBuf_Module_GateProxy_Module__loggerFxn4__C

#undef Module__LOGFXN8
#define Module__LOGFXN8 xdc_runtime_LoggerBuf_Module_GateProxy_Module__loggerFxn8__C

#undef Module__G_OBJ
#define Module__G_OBJ xdc_runtime_LoggerBuf_Module_GateProxy_Module__gateObj__C

#undef Module__G_PRMS
#define Module__G_PRMS xdc_runtime_LoggerBuf_Module_GateProxy_Module__gatePrms__C

#undef Module__GP_create
#define Module__GP_create xdc_runtime_LoggerBuf_Module_GateProxy_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete xdc_runtime_LoggerBuf_Module_GateProxy_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter xdc_runtime_LoggerBuf_Module_GateProxy_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave xdc_runtime_LoggerBuf_Module_GateProxy_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query xdc_runtime_LoggerBuf_Module_GateProxy_Module_GateProxy_query

xdc_Bool xdc_runtime_LoggerBuf_Module_GateProxy_Proxy__abstract__S(void)
{
    return 0;
}
xdc_CPtr xdc_runtime_LoggerBuf_Module_GateProxy_Proxy__delegate__S(void)
{
    return (const void *)&ti_sysbios_gates_GateHwi_Module__FXNS__C;
}



/*
 * ======== xdc.runtime.LoggerBuf_TimestampProxy SYSTEM FUNCTIONS ========
 */


xdc_Bool xdc_runtime_LoggerBuf_TimestampProxy_Proxy__abstract__S(void)
{
    return 0;
}
xdc_CPtr xdc_runtime_LoggerBuf_TimestampProxy_Proxy__delegate__S(void)
{
    return 0;
}


/*
 * ======== xdc.runtime.Main SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool xdc_runtime_Main_Module__startupDone__S( void )
{
    return 1;
}



/*
 * ======== xdc.runtime.Main_Module_GateProxy SYSTEM FUNCTIONS ========
 */

/* per-module runtime symbols */
#undef Module__MID
#define Module__MID xdc_runtime_Main_Module_GateProxy_Module__id__C

#undef Module__DGSINCL
#define Module__DGSINCL xdc_runtime_Main_Module_GateProxy_Module__diagsIncluded__C

#undef Module__DGSENAB
#define Module__DGSENAB xdc_runtime_Main_Module_GateProxy_Module__diagsEnabled__C

#undef Module__DGSMASK
#define Module__DGSMASK xdc_runtime_Main_Module_GateProxy_Module__diagsMask__C

#undef Module__LOGDEF
#define Module__LOGDEF xdc_runtime_Main_Module_GateProxy_Module__loggerDefined__C

#undef Module__LOGOBJ
#define Module__LOGOBJ xdc_runtime_Main_Module_GateProxy_Module__loggerObj__C

#undef Module__LOGFXN0
#define Module__LOGFXN0 xdc_runtime_Main_Module_GateProxy_Module__loggerFxn0__C

#undef Module__LOGFXN1
#define Module__LOGFXN1 xdc_runtime_Main_Module_GateProxy_Module__loggerFxn1__C

#undef Module__LOGFXN2
#define Module__LOGFXN2 xdc_runtime_Main_Module_GateProxy_Module__loggerFxn2__C

#undef Module__LOGFXN4
#define Module__LOGFXN4 xdc_runtime_Main_Module_GateProxy_Module__loggerFxn4__C

#undef Module__LOGFXN8
#define Module__LOGFXN8 xdc_runtime_Main_Module_GateProxy_Module__loggerFxn8__C

#undef Module__G_OBJ
#define Module__G_OBJ xdc_runtime_Main_Module_GateProxy_Module__gateObj__C

#undef Module__G_PRMS
#define Module__G_PRMS xdc_runtime_Main_Module_GateProxy_Module__gatePrms__C

#undef Module__GP_create
#define Module__GP_create xdc_runtime_Main_Module_GateProxy_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete xdc_runtime_Main_Module_GateProxy_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter xdc_runtime_Main_Module_GateProxy_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave xdc_runtime_Main_Module_GateProxy_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query xdc_runtime_Main_Module_GateProxy_Module_GateProxy_query

xdc_Bool xdc_runtime_Main_Module_GateProxy_Proxy__abstract__S(void)
{
    return 0;
}
xdc_CPtr xdc_runtime_Main_Module_GateProxy_Proxy__delegate__S(void)
{
    return (const void *)&ti_sysbios_gates_GateHwi_Module__FXNS__C;
}



/*
 * ======== xdc.runtime.Memory SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool xdc_runtime_Memory_Module__startupDone__S( void )
{
    return 1;
}



/*
 * ======== xdc.runtime.Memory_HeapProxy SYSTEM FUNCTIONS ========
 */

/* per-module runtime symbols */
#undef Module__MID
#define Module__MID xdc_runtime_Memory_HeapProxy_Module__id__C

#undef Module__DGSINCL
#define Module__DGSINCL xdc_runtime_Memory_HeapProxy_Module__diagsIncluded__C

#undef Module__DGSENAB
#define Module__DGSENAB xdc_runtime_Memory_HeapProxy_Module__diagsEnabled__C

#undef Module__DGSMASK
#define Module__DGSMASK xdc_runtime_Memory_HeapProxy_Module__diagsMask__C

#undef Module__LOGDEF
#define Module__LOGDEF xdc_runtime_Memory_HeapProxy_Module__loggerDefined__C

#undef Module__LOGOBJ
#define Module__LOGOBJ xdc_runtime_Memory_HeapProxy_Module__loggerObj__C

#undef Module__LOGFXN0
#define Module__LOGFXN0 xdc_runtime_Memory_HeapProxy_Module__loggerFxn0__C

#undef Module__LOGFXN1
#define Module__LOGFXN1 xdc_runtime_Memory_HeapProxy_Module__loggerFxn1__C

#undef Module__LOGFXN2
#define Module__LOGFXN2 xdc_runtime_Memory_HeapProxy_Module__loggerFxn2__C

#undef Module__LOGFXN4
#define Module__LOGFXN4 xdc_runtime_Memory_HeapProxy_Module__loggerFxn4__C

#undef Module__LOGFXN8
#define Module__LOGFXN8 xdc_runtime_Memory_HeapProxy_Module__loggerFxn8__C

#undef Module__G_OBJ
#define Module__G_OBJ xdc_runtime_Memory_HeapProxy_Module__gateObj__C

#undef Module__G_PRMS
#define Module__G_PRMS xdc_runtime_Memory_HeapProxy_Module__gatePrms__C

#undef Module__GP_create
#define Module__GP_create xdc_runtime_Memory_HeapProxy_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete xdc_runtime_Memory_HeapProxy_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter xdc_runtime_Memory_HeapProxy_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave xdc_runtime_Memory_HeapProxy_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query xdc_runtime_Memory_HeapProxy_Module_GateProxy_query

xdc_Bool xdc_runtime_Memory_HeapProxy_Proxy__abstract__S(void)
{
    return 1;
}
xdc_CPtr xdc_runtime_Memory_HeapProxy_Proxy__delegate__S(void)
{
    return (const void *)&ti_sysbios_heaps_HeapMem_Module__FXNS__C;
}



/*
 * ======== xdc.runtime.Registry SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool xdc_runtime_Registry_Module__startupDone__S( void )
{
    return 1;
}



/*
 * ======== xdc.runtime.Startup SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool xdc_runtime_Startup_Module__startupDone__S( void )
{
    return 1;
}



/*
 * ======== xdc.runtime.SysMin SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool xdc_runtime_SysMin_Module__startupDone__S( void )
{
    return xdc_runtime_SysMin_Module__startupDone__F();
}



/*
 * ======== xdc.runtime.System SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool xdc_runtime_System_Module__startupDone__S( void )
{
    return xdc_runtime_System_Module__startupDone__F();
}



/*
 * ======== xdc.runtime.System_Module_GateProxy SYSTEM FUNCTIONS ========
 */

/* per-module runtime symbols */
#undef Module__MID
#define Module__MID xdc_runtime_System_Module_GateProxy_Module__id__C

#undef Module__DGSINCL
#define Module__DGSINCL xdc_runtime_System_Module_GateProxy_Module__diagsIncluded__C

#undef Module__DGSENAB
#define Module__DGSENAB xdc_runtime_System_Module_GateProxy_Module__diagsEnabled__C

#undef Module__DGSMASK
#define Module__DGSMASK xdc_runtime_System_Module_GateProxy_Module__diagsMask__C

#undef Module__LOGDEF
#define Module__LOGDEF xdc_runtime_System_Module_GateProxy_Module__loggerDefined__C

#undef Module__LOGOBJ
#define Module__LOGOBJ xdc_runtime_System_Module_GateProxy_Module__loggerObj__C

#undef Module__LOGFXN0
#define Module__LOGFXN0 xdc_runtime_System_Module_GateProxy_Module__loggerFxn0__C

#undef Module__LOGFXN1
#define Module__LOGFXN1 xdc_runtime_System_Module_GateProxy_Module__loggerFxn1__C

#undef Module__LOGFXN2
#define Module__LOGFXN2 xdc_runtime_System_Module_GateProxy_Module__loggerFxn2__C

#undef Module__LOGFXN4
#define Module__LOGFXN4 xdc_runtime_System_Module_GateProxy_Module__loggerFxn4__C

#undef Module__LOGFXN8
#define Module__LOGFXN8 xdc_runtime_System_Module_GateProxy_Module__loggerFxn8__C

#undef Module__G_OBJ
#define Module__G_OBJ xdc_runtime_System_Module_GateProxy_Module__gateObj__C

#undef Module__G_PRMS
#define Module__G_PRMS xdc_runtime_System_Module_GateProxy_Module__gatePrms__C

#undef Module__GP_create
#define Module__GP_create xdc_runtime_System_Module_GateProxy_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete xdc_runtime_System_Module_GateProxy_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter xdc_runtime_System_Module_GateProxy_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave xdc_runtime_System_Module_GateProxy_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query xdc_runtime_System_Module_GateProxy_Module_GateProxy_query

xdc_Bool xdc_runtime_System_Module_GateProxy_Proxy__abstract__S(void)
{
    return 0;
}
xdc_CPtr xdc_runtime_System_Module_GateProxy_Proxy__delegate__S(void)
{
    return (const void *)&ti_sysbios_gates_GateHwi_Module__FXNS__C;
}



/*
 * ======== xdc.runtime.System_SupportProxy SYSTEM FUNCTIONS ========
 */


xdc_Bool xdc_runtime_System_SupportProxy_Proxy__abstract__S(void)
{
    return 0;
}
xdc_CPtr xdc_runtime_System_SupportProxy_Proxy__delegate__S(void)
{
    return (const void *)&xdc_runtime_SysMin_Module__FXNS__C;
}


/*
 * ======== xdc.runtime.Text SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool xdc_runtime_Text_Module__startupDone__S( void )
{
    return 1;
}



/*
 * ======== xdc.runtime.Types SYSTEM FUNCTIONS ========
 */

/* Module__startupDone__S */
xdc_Bool xdc_runtime_Types_Module__startupDone__S( void )
{
    return 1;
}



/*
 * ======== INITIALIZATION ENTRY POINT ========
 */

#include <stdint.h>
extern int_least32_t __xdc__init(void);
#ifdef __GNUC__
#if defined(__clang__) && defined(__ti__)
    __attribute__ ((used))
#else
#ifndef __ti__
    __attribute__ ((externally_visible))
#endif
#endif
#endif
__FAR__ int_least32_t (* volatile __xdc__init__addr)(void) = &__xdc__init;


/*
 * ======== PROGRAM GLOBALS ========
 */

#ifdef __GNUC__
#if defined(__clang__) && defined(__ti__)
    __attribute__ ((used))
#else
#ifndef __ti__
    __attribute__ ((externally_visible))
#endif
#endif
#endif
const ti_sysbios_knl_Clock_Handle CLK_OneSecond = (ti_sysbios_knl_Clock_Handle)((ti_sysbios_knl_Clock_Handle)&ti_sysbios_knl_Clock_Object__table__V[0]);

