#include "F28x_Project.h"

#define BLINKY_LED_GPIO    31 // LED10 - Blue

//void main(void) {
//
//    // Initialize System Control: PLL, WatchDog, enable Peripheral Clocks
//    InitSysCtrl(); // F2837xD_SysCtrl.c
//
//    // Initialize GPIO
//    InitGpio(); // F2837xD_Gpio.c
//    GPIO_SetupPinMux(BLINKY_LED_GPIO, GPIO_MUX_CPU1, 0);
//    GPIO_SetupPinOptions(BLINKY_LED_GPIO, GPIO_OUTPUT, GPIO_PUSHPULL);
//
//    // Clear all interrupts and initialize PIE vector table:
//    // Disable CPU interrupts
//    DINT;
//
//    // Initialize the PIE control registers to their default state.
//    // The default state is all PIE interrupts disabled and flags are cleared.
//    InitPieCtrl(); // F2837xD_PieCtrl.c
//
//    // Disable CPU interrupts and clear all CPU interrupt flags
//    IER = 0x0000;
//    IFR = 0x0000;
//
//    // Initialize the PIE vector table with pointers to the shell Interrupt Service Routines (ISR).
//    // This will populate the entire table, even if the interrupt is not used in this example.  This is useful for debug purposes.
//    // The shell ISR routines are found in F2837xD_DefaultIsr.c.
//    InitPieVectTable(); // F2837xD_PieVect.c
//
//    // Enable global Interrupts and higher priority real-time debug events
//    EINT;  // Enable Global interrupt INTM
//    ERTM;  // Enable Global realtime interrupt DBGM
//
//    // IDLE loop. Just sit and loop forever (optional):
//    for(;;) {
//
//        // Turn on LED
//        GPIO_WritePin(BLINKY_LED_GPIO, 0);
//
//        // Delay for a bit.
//        DELAY_US(1000*500);
//
//        // Turn off LED
//        GPIO_WritePin(BLINKY_LED_GPIO, 1);
//
//        // Delay for a bit.
//        DELAY_US(1000*500);
//    }
//
//}


// Method 2
void main(void) {

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

//    // Method 1
//    for(;;) {
//
//        // Turn on LED
//        GpioDataRegs.GPACLEAR.bit.GPIO31 = 1;
//
//        // Delay for a bit.
//        DELAY_US(1000*500);
//
//        // Turn off LED
//        GpioDataRegs.GPASET.bit.GPIO31 = 1;
//
//        // Delay for a bit.
//        DELAY_US(1000*500);
//    }

    // Method 2
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

    // state = GpioDataRegs.GPADAT.bit.GPIO31; // read state of GPIO31

}


