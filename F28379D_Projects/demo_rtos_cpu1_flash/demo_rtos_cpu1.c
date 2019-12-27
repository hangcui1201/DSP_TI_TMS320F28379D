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


void DoEverySecond(void){
    GpioDataRegs.GPADAT.bit.GPIO31 ^= 1;
}


int main() {

    // Initialize System Control: PLL, WatchDog, enable Peripheral Clocks
    InitSysCtrl(); // F2837xD_SysCtrl.c

    // Initialize GPIO
    InitGpio(); // F2837xD_Gpio.c

//    // Clear all interrupts and initialize PIE vector table:
//    // Disable CPU interrupts
//    DINT;
//
//    // Disable CPU interrupts and clear all CPU interrupt flags
//    IER = 0x0000;
//    IFR = 0x0000;
//
//    // Enable global Interrupts and higher priority real-time debug events
//    EINT;  // Enable Global interrupt INTM
//    ERTM;  // Enable Global realtime interrupt DBGM

    EALLOW;
    // Enable an GPIO output on GPIO31, set it high
    GpioCtrlRegs.GPAPUD.bit.GPIO31 = 0;   // Enable pullup on GPIO31
    GpioDataRegs.GPASET.bit.GPIO31 = 1;   // Load output latch
    GpioCtrlRegs.GPAMUX2.bit.GPIO31 = 0;  // GPIO31 = GPIO31
    GpioCtrlRegs.GPADIR.bit.GPIO31 = 1;   // GPIO31 = output
    EDIS;

    BIOS_start();

    return 0;

}
