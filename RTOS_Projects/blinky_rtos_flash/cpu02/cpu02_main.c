#include <xdc/std.h>

#include <xdc/runtime/Log.h>
#include <xdc/runtime/Error.h>
#include <xdc/runtime/System.h>

#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>
#include <ti/sysbios/knl/Swi.h>
#include <ti/sysbios/knl/Clock.h>
#include <ti/sysbios/knl/Semaphore.h>
#include <ti/sysbios/family/c28/Hwi.h>

#include "F28x_Project.h"     // Device Headerfile and Examples Include File


#ifdef _FLASH
// These are defined by the linker (see device linker command file)
extern unsigned int RamfuncsLoadStart;
extern unsigned int RamfuncsLoadSize;
extern unsigned int RamfuncsRunStart;
#endif


void DoHalfSecond_CPU2(void){
    // GpioCtrlRegs cannot be accessed by CPU2
    GpioDataRegs.GPBTOGGLE.bit.GPIO34 = 1;
//    GpioDataRegs.GPBDAT.bit.GPIO34 ^= 1;

}

//#pragma CODE_SECTION(function_name, "ramfuncs");
//void function_name(void)
//{}


int main() {

    // Initialize System Control: PLL, WatchDog, enable Peripheral Clocks
    InitSysCtrl(); // F2837xD_SysCtrl.c

    #ifdef _FLASH
        memcpy(&RamfuncsRunStart, &RamfuncsLoadStart, (size_t)&RamfuncsLoadSize);
    #endif

    #ifdef _FLASH
        InitFlash();
    #endif

    // Clear all interrupts and initialize PIE vector table:
    // Disable CPU interrupts
    DINT;

    // Disable CPU interrupts and clear all CPU interrupt flags
//    IER = 0x0000;
    IFR = 0x0000;

    // Enable global Interrupts and higher priority real-time debug events
    EINT;  // Enable Global interrupt INTM
    ERTM;  // Enable Global realtime interrupt DBGM

    BIOS_start();

    return 0;

}





