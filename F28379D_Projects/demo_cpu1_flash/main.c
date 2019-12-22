#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <file.h>

#include "F28x_Project.h"     // DSP28x Headerfile

void main() {

    // If running from flash copy RAM only functions to RAM   
    #ifdef _FLASH
        memcpy(&RamfuncsRunStart, &RamfuncsLoadStart, (size_t)&RamfuncsLoadSize);
    #endif

    // Initialize System Control: PLL, WatchDog, enable Peripheral Clocks
    InitSysCtrl(); // F2837xD_SysCtrl.c

    // Initialize GPIO
    InitGpio(); // F2837xD_Gpio.c

    // Clear all interrupts and initialize PIE vector table:
    // Disable CPU interrupts
    DINT;

    // Initialize the PIE control registers to their default state.
    // The default state is all PIE interrupts disabled and flags are cleared.
    InitPieCtrl(); // F2837xD_PieCtrl.c

    // Disable CPU interrupts and clear all CPU interrupt flags
    IER = 0x0000;
    IFR = 0x0000;

    // Initialize the PIE vector table with pointers to the shell Interrupt Service Routines (ISR).
    // This will populate the entire table, even if the interrupt is not used in this example.  This is useful for debug purposes.
    // The shell ISR routines are found in F2837xD_DefaultIsr.c.
    InitPieVectTable(); // F2837xD_PieVect.c

    // Enable global Interrupts and higher priority real-time debug events
    EINT;  // Enable Global interrupt INTM
    ERTM;  // Enable Global realtime interrupt DBGM

    EALLOW;
    // Enable an GPIO output on GPIO31, set it high
    GpioCtrlRegs.GPAPUD.bit.GPIO31 = 0;   // Enable pullup on GPIO31
    GpioDataRegs.GPASET.bit.GPIO31 = 1;   // Load output latch
    GpioCtrlRegs.GPAMUX2.bit.GPIO31 = 0;  // GPIO31 = GPIO31
    GpioCtrlRegs.GPADIR.bit.GPIO31 = 1;   // GPIO31 = output
    EDIS;

    for(;;) {

        // Turn on LED
        GpioDataRegs.GPADAT.bit.GPIO31 = 0;

        // Delay for a bit.
        DELAY_US(1000*500);

        // Turn off LED
        GpioDataRegs.GPADAT.bit.GPIO31 = 1;

        // Delay for a bit.
        DELAY_US(1000*500);
    }

}



