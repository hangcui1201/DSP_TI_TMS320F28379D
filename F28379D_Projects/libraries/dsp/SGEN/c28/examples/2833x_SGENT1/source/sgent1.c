// =====================================================================================
//  This software is licensed for use with Texas Instruments C28x
//  family DSCs.  This license was provided to you prior to installing
//  the software.  You may review this license by consulting a copy of
//  the agreement in the doc directory of this library.
//======================================================================================
/* ==============================================================================

System Name:    Signal Generator Module demo 

File Name:      SGENT1.C

Description:    Primary System file for demonstrating the Signal Generator module

Originator:     Digital control systems Group - Texas Instruments

Target dependency:  C28x

Description:
============

   The "C" frame work, for demonstrating the signal generator module is given below
                 ___________           _____________
                |           |         |             |
                |           | X1=OUT  |   EVMDAC    |
                |  SGENT_1  |-------->|   DLOG_4CH  |
                |           |         |   PWMDAC    |
                |___________|         |_____________|

*/
//######################################################################################
// $TI Release: C28x SGEN Library v1.02.00.00 $
// $Release Date: Mon May 27 06:58:34 CDT 2019 $
// $Copyright: Copyright (C) 2011-2019 Texas Instruments Incorporated -
//             http://www.ti.com/ ALL RIGHTS RESERVED $
//######################################################################################

#include "DSP28x_Project.h"     // Device Headerfile and Examples Include File
#include <sgen.h>

#define SIGNAL_LENGTH 512

/* Create an instance of Signal generator module    */
SGENT_1 sgen = SGENT_1_DEFAULTS;  
  
#pragma DATA_SECTION(ipcb, "SGENipcb");
int ipcb[SIGNAL_LENGTH];  
    
int xn,yn;

void main()
{    
	    unsigned long i;

  	    InitSysCtrl();
	    DINT;
	    InitPieCtrl();
	    IER = 0x0000;
	    IFR = 0x0000;
	    InitPieVectTable();
	    EINT;   // Enable Global interrupt INTM
	    ERTM;   // Enable Global realtime interrupt DBGM

		/* Signal Generator module initialisation           */ 
		sgen.offset=0;
		sgen.gain=0x7fff; /* gain=1 in Q15 */
		sgen.freq=5369; /* freq = (Required Freq/Max Freq)*2^15 */
		/* = (50/305.17)*2^15 = 5369 */
		sgen.step_max=1000; /* Max Freq= (step_max * sampling freq)/65536 */
		sgen.alpha=8192;    /* phase_norm =(pi/4/(2*pi))*2^16=8192   */
		
		/* So call step_max is normalized fmax in Q16 format             */
		/*  step_max=fmax/fs*65536										 */
		/*  f/fmax*2^15=freq											*/

        for(i=0;i<SIGNAL_LENGTH;i++)
        {
        	ipcb[i]=0;
        }

        for(i=0;i<SIGNAL_LENGTH;i++)
        {
        	sgen.calc(&sgen);
        	xn=sgen.out;
        	ipcb[i]=xn;
        }
        
		
		for(;;);

} /* End: main() */

             



