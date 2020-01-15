#ifndef F28379D_COECSL_H__
#define F28379D_COECSL_H__

/* standard ANSI C includes */
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <math.h>
#include <limits.h>

/* device includes */
#include <F2837xD_device.h>
#include <F2837xD_Examples.h>

/* general constants */
#define PI			3.1415926535897932384626433832795
#define TWOPI		6.283185307179586476925286766559
#define HALFPI		1.5707963267948966192313216916398
#define GRAV		9.81

#define PLL_IMULT           0x28        //40
#define OSCCLK_KHZ          10000L      //10 MHz

#if PLL_IMULT
#define SYSCLKOUT_KHZ   (OSCCLK_KHZ*PLL_IMULT/((ClkCfgRegs.SYSCLKDIVSEL.bit.PLLSYSCLKDIV == 0) ? 1 : (ClkCfgRegs.SYSCLKDIVSEL.bit.PLLSYSCLKDIV*2)))
#else
#define SYSCLKOUT_KHZ       (OSCCLK_KHZ)    //10MHz
#endif

//LSPCLKDIV shouldn't be changed, so then should still be default /4
//so 200Mhz/4 = 50Mhz
#define LSPCLK_KHZ (SYSCLKOUT_KHZ/((ClkCfgRegs.LOSPCP.bit.LSPCLKDIV == 0) ? 1 : (ClkCfgRegs.LOSPCP.bit.LSPCLKDIV*2)))

//#define LSPCLK_KHZ   50000
#define LSPCLK_HZ  (LSPCLK_KHZ*1000L)

/* general structures/enumerations */
//enum eQep_e {
//	EQEP1,
//	EQEP2,
//	EQEP3
//};

#endif 
