#include "Lab.h"                        // Main include file

void main(void)
{
    //--- CPU Initialization
	InitSysCtrl();						// Initialize the CPU (FILE: SysCtrl.c)
	InitGpio();							// Initialize the shared GPIO pins (FILE: Gpio.c)
	InitXbar();							// Initialize the input, output & ePWM X-Bar (FILE: Xbar.c)
	//	InitPieCtrl();						// Initialize and enable the PIE (FILE: PieCtrl.c)
	InitWatchdog();						// Initialize the Watchdog Timer (FILE: WatchDog.c)

	//--- Enable global interrupts
	asm(" CLRC INTM, DBGM");			// Enable global interrupts and realtime debug

	//--- Main Loop
	while(1)							// endless loop - wait for an interrupt
	{
		asm(" NOP");
	}


}
