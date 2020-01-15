// TI File $Revision: /main/4 $
// Checkin $Date: June 4, 2007   13:30:28 $
//###########################################################################
//
// FILE:    MCBSP_Boot.c
//
// TITLE:   2833x McBSP-A Boot mode routines
//
// Functions:
//
//     Uint32 MCBSP_Boot()
//     void MCBSP_Init(void
//     Uint32 MCBSP_GetWordData(void)
//
// Notes:
// XCLKIN = 30 MHz  SYSCLKOUT = 15 MHz  LSPCLK = 3.75 MHz CLKG = 3.75 MHz
// XCLKIN = 15 MHz  SYSCLKOUT = 7.5 MHz LSPCLK = 1.875 MHz CLKG = 1.875 MHz

//###########################################################################
// $TI Release: 2833x Boot ROM Version 1 $
// $Release Date: June 25, 2007 $
//###########################################################################

#include "DSP2833x_Device.h"
#include "TMS320x2833x_Boot.h"

// Private functions
void MCBSP_Init(void);
Uint16 MCBSP_GetWordData(void);

// External functions
extern void CopyData(void);
extern Uint32 GetLongData(void);
extern void ReadReservedFn(void);


//#################################################
// Uint32 MCBSP_Boot(void)
//--------------------------------------------
// This module is the main MCBSP boot routine.
// It will load code via the MCBSP-A port.
//
// It will return a entry point address back
// to the InitBoot routine which in turn calls
// the ExitBoot routine.
//--------------------------------------------

Uint32 MCBSP_Boot()
{
   Uint32 EntryAddr;

   // If the missing clock detect bit is set, just
   // loop here.
   if(SysCtrlRegs.PLLSTS.bit.MCLKSTS == 1)
   {
      for(;;);
   }

   // Asign GetWordData to the MCBSP-A version of the
   // function.  GetWordData is a pointer to a function.
   GetWordData = MCBSP_GetWordData;

   MCBSP_Init();

   // If the KeyValue was invalid, abort the load
   // and return the flash entry point.
   if (MCBSP_GetWordData() != 0x10AA) return FLASH_ENTRY_POINT;

   ReadReservedFn();

   EntryAddr = GetLongData();

   CopyData();

   return EntryAddr;
}


//#################################################
// void MCBSP_Init(void)
//----------------------------------------------
// Initialize the MCBSP-A port for communications
// with the host.
//----------------------------------------------

void MCBSP_Init()
{
	Uint16 k;	

   EALLOW;	

/* Enable MCBSP clock  */

   SysCtrlRegs.PCLKCR0.bit.MCBSPAENCLK=1;

/* Configure MCBSP-A pins using GPIO regs*/

   	GpioCtrlRegs.GPAMUX2.bit.GPIO20 = 2;		// GPIO20 is MDXA pin
   	GpioCtrlRegs.GPAMUX2.bit.GPIO21 = 2;		// GPIO21 is MDRA pin 
   	GpioCtrlRegs.GPAMUX2.bit.GPIO22 = 2;		// GPIO22 is MCLKXA pin 
   	GpioCtrlRegs.GPAMUX2.bit.GPIO23 = 2; 		// GPIO23 is MFSXA pin
	GpioCtrlRegs.GPAMUX1.bit.GPIO7 = 2;			// GPIO7 is MCLKRA pin
	GpioCtrlRegs.GPAMUX1.bit.GPIO5 = 2;			// GPIO5 is MFSRA pin
	   
/* Enable internal pullups for the MCBSP pins  */

   GpioCtrlRegs.GPAPUD.bit.GPIO20 = 0;
   GpioCtrlRegs.GPAPUD.bit.GPIO21 = 0;
   GpioCtrlRegs.GPAPUD.bit.GPIO22 = 0;
   GpioCtrlRegs.GPAPUD.bit.GPIO23 = 0;
   GpioCtrlRegs.GPAPUD.bit.GPIO7 = 0;
   GpioCtrlRegs.GPAPUD.bit.GPIO5 = 0;
   
/* Asynch Qual */

   GpioCtrlRegs.GPAQSEL2.bit.GPIO21 = 3;   
   GpioCtrlRegs.GPAQSEL1.bit.GPIO7 = 3;
   GpioCtrlRegs.GPAQSEL1.bit.GPIO5 = 3;

   // McBSP-A register settings

	McbspaRegs.SPCR2.all=0x0000;		// Reset FS generator, sample rate generator & transmitter
	McbspaRegs.SPCR1.all=0x0000;		// Reset Receiver, Right justify word
	
	McbspaRegs.MFFINT.all=0x0;			// Disable all interrupts
    McbspaRegs.MFFST.all=0x0;  			// Clear all status bits

    McbspaRegs.RCR2.all=0x0;			// Single-phase frame, 1 word/frame, No companding	(Receive)
    McbspaRegs.RCR1.all=0x0;

    McbspaRegs.XCR2.all=0x0;			// Single-phase frame, 1 word/frame, No companding	(Transmit)
    McbspaRegs.XCR1.all=0x0;

    McbspaRegs.RCR1.bit.RWDLEN1=2;      // 16-bit word
    McbspaRegs.XCR1.bit.XWDLEN1=2;      // 16-bit word

	McbspaRegs.RCR2.bit.RDATDLY = 1;	//	1-bit data delay on the receive side
    
    McbspaRegs.SRGR2.bit.CLKSM = 1;		// CLKSM=1 (If SCLKME=0, i/p clock to SRG is LSPCLK)
	McbspaRegs.SRGR2.bit.FPER = 31;		// FPER = 32 CLKG periods

    McbspaRegs.SRGR1.bit.FWID = 1;      // Frame Width = 1 CLKG period
    McbspaRegs.SRGR1.bit.CLKGDV = 1;	// CLKG frequency = LSPCLK/(CLKGDV+1) = LSPCLK

    McbspaRegs.PCR.all = 0;    

	McbspaRegs.SPCR2.bit.XRST=1;       	// Release TX from Reset
    McbspaRegs.SPCR1.bit.RRST=1;		// Release RX from Reset
    for(k=0; k<50000; k++){}		 // delay_loop()
    McbspaRegs.SPCR2.all |=0x00C0;     	// Frame sync & sample rate generators pulled out of reset
	for(k=0; k<50000; k++){}		 // delay_loop()

   EDIS;

    return;
}

//#################################################
// Uint16 MCBSP_GetWordData(void)
//---------------------------------------------------
// This routine fetches the 16-bit word from MCBSP-A
//---------------------------------------------------

Uint16 MCBSP_GetWordData()
{
   Uint16 wordData;
   wordData = 0x0000;

// Fetch word
   while( McbspaRegs.SPCR1.bit.RRDY == 0){}

   wordData =  (Uint16) McbspaRegs.DRR1.all;   

   return wordData;
}


// EOF-------
