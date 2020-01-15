#include <F28379D_EPwm.h>
#include <F28379D_Coecsl.h>
#include <F2837xD_EPwm_defines.h>

//InitEPwm1Gpio();         // init GPIO0 as EPWM1A (J4-40) & GPIO1 as EPWM1B (J4-39)
//InitEPwm2Gpio();         // init GPIO2 as EPWM2A (J4-38) & GPIO3 as EPWM2B (J4-37)
//InitEPwm3Gpio();         // init GPIO4 as EPWM3A (J4-36) & GPIO5 as EPWM3B (J4-35)
//InitEPwm4Gpio();         // init GPIO6 as EPWM4A (J8-80) & GPIO7 as EPWM4B (J8-79)
//InitEPwm5Gpio();         // init GPIO8 as EPWM5A (J8-78) & GPIO9 as EPWM5B (J8-77)
//InitEPwm6Gpio();         // init GPIO10 as EPWM6A (J4-76) & GPIO11 as EPWM6B (J4-75)

//// init EPwm1A
//init_EPWM1A_GPIO();      // init GPIO0 as EPWM1A (J4-40)
//init_EPWM1A();           // init EPWM1A with a 20KHz carrier frequency PWM signal.
//set_EPWM1A(u_ctrl_1a);      // set to 0 (50% duty cycle)at the beginning, update in SYS/BIOS
//
//// init EPwm1B
//init_EPWM1B_GPIO();      // init GPIO1 as EPWM1B (J4-39)
//init_EPWM1B();           // init EPWM1B with a 20KHz carrier frequency PWM signal.
//set_EPWM1B(u_ctrl_1b);      // set to 0 (50% duty cycle)at the beginning, update in SYS/BIOS
//
//// init EPwm2A
//init_EPWM2A_GPIO();      // init GPIO2 as EPWM1A (J4-38)
//init_EPWM2A();           // init EPWM1A with a 20KHz carrier frequency PWM signal.
//set_EPWM2A(u_ctrl_2a);      // set to 0 (50% duty cycle)at the beginning, update in SYS/BIOS
//
//// init EPwm2B
//init_EPWM2B_GPIO();      // init GPIO3 as EPWM1B (J4-37)
//init_EPWM2B();           // init EPWM1B with a 20KHz carrier frequency PWM signal.
//set_EPWM2B(u_ctrl_2b);      // set to 0 (50% duty cycle)at the beginning, update in SYS/BIOS
//
//// init EPwm3A
//init_EPWM3A_GPIO();      // init GPIO4 as EPWM3A (J4-36)
//init_EPWM3A();           // init EPWM1A with a 20KHz carrier frequency PWM signal.
//set_EPWM3A(u_ctrl_3a);      // set to 0 (50% duty cycle)at the beginning, update in SYS/BIOS
//
//// init EPwm3B
//init_EPWM3B_GPIO();      // init GPIO5 as EPWM3B (J4-35)
//init_EPWM3B();           // init EPWM1B with a 20KHz carrier frequency PWM signal.
//set_EPWM3B(u_ctrl_3b);      // set to 0 (50% duty cycle)at the beginning, update in SYS/BIOS


/************************** Setup EPWM1A **************************/
void init_EPWM1A_GPIO(void)
{
    EALLOW;
    // Disable internal pull-up for the selected output pins
    // for reduced power consumption
    // Pull-ups can be enabled or disabled by the user.
    // Comment out other unwanted lines.
    GpioCtrlRegs.GPAPUD.bit.GPIO0 = 1;    // Disable pull-up on GPIO0 (EPWM1A)
    // Configure EPWM-1 pins using GPIO regs
    // This specifies which of the possible GPIO pins will be EPWM1 functional pins.
    GpioCtrlRegs.GPAMUX1.bit.GPIO0 = 1;   // Configure GPIO0 as EPWM1A
    EDIS;
}

// This function has already been called for you in the main() function.  
// It sets up PWM1A with a 20KHz carrier frequency PWM signal.  
void init_EPWM1A(void)
{
	EPwm1Regs.TBCTL.bit.CTRMODE = TB_COUNT_UP;		// Set epwm1 to upcount mode, 0x0
	EPwm1Regs.TBCTL.bit.FREE_SOFT = 0x2;            // Free Run, do not stop
    EPwm1Regs.TBCTL.bit.PHSEN = TB_DISABLE;         // Disable phase loading, 0x0
	
	EPwm1Regs.TBPRD = 2500;                         // Set epwm1 counter  20KHz, set timer period
	EPwm1Regs.TBPHS.bit.TBPHS = 0x0000;             // Phase is 0
	EPwm1Regs.TBCTR = 0x0000;                       // Clear counter
	
	// For EPWM1A
	EPwm1Regs.AQCTLA.bit.CAU = AQ_CLEAR;		    // Clear when counter = compareA
	EPwm1Regs.AQCTLA.bit.ZRO = AQ_SET;			    // Set when timer is 0
}

// This function sets PWM1A duty cycle given the float value between -10 and 10. Where
// -10 equates to 0% duty cycle
//   0 equates to 50% duty cycle
//  10 equates to 100% duty cycle
//  if you pass -5.0 to this function EPWM1A will be set to 25% duty cycle
//  if you pass 5.0 to this function EPWM1A will be set to 75% duty cycle

//  Example code
//  float myu = 0;
//  float Kpgain = 4.5;
//  float error = 0;
//	myu = Kpgain*error;
//	set_EPWM1A(myu);
void set_EPWM1A(float u)
{
    float pwmCountMax = 2500.0;
    float pwmVal = 0;
	
    if (u >  10) u =  10;
    if (u < -10) u = -10;
	
    pwmVal = u * (pwmCountMax / 20.0) + pwmCountMax / 2.0;
	
	// set compareA compare value
    EPwm1Regs.CMPA.bit.CMPA = (int)pwmVal;
}


/************************** Setup EPWM1B **************************/

void init_EPWM1B_GPIO(void)
{
    EALLOW;
    GpioCtrlRegs.GPAPUD.bit.GPIO1 = 1;    // Disable pull-up on GPIO1 (EPWM1B)
    GpioCtrlRegs.GPAMUX1.bit.GPIO1 = 1;   // Configure GPIO1 as EPWM1B
    EDIS;
}


void init_EPWM1B(void)
{
    EPwm1Regs.TBCTL.bit.CTRMODE = TB_COUNT_UP;      // Set epwm1 to upcount mode, 0x0
    EPwm1Regs.TBCTL.bit.FREE_SOFT = 0x2;            // Free Run, do not stop
    EPwm1Regs.TBCTL.bit.PHSEN = TB_DISABLE;         // Disable phase loading, 0x0
    EPwm1Regs.TBPRD = 2500;                         // set epwm1 counter  20KHz
    EPwm1Regs.TBPHS.bit.TBPHS = 0x0000;             // Phase is 0
    EPwm1Regs.TBCTR = 0x0000;                       // Clear counter
    // For EPWM1B
    EPwm1Regs.AQCTLB.bit.CBU = AQ_CLEAR;            // Clear when counter = compareA
    EPwm1Regs.AQCTLB.bit.ZRO = AQ_SET;              // Set when timer is 0
}

void set_EPWM1B(float u)
{
    float pwmCountMax = 2500.0;
    float pwmVal = 0;
    if (u >  10) u =  10;
    if (u < -10) u = -10;
    pwmVal = u * (pwmCountMax / 20.0) + pwmCountMax / 2.0;
    EPwm1Regs.CMPB.bit.CMPB = (int)pwmVal;
}


/************************** Setup EPWM2A **************************/
void init_EPWM2A_GPIO(void)
{
    EALLOW;
    GpioCtrlRegs.GPAPUD.bit.GPIO2 = 1;    // Disable pull-up on GPIO2 (EPWM2A)
    GpioCtrlRegs.GPAMUX1.bit.GPIO2 = 1;   // Configure GPIO2 as EPWM2A
    EDIS;
}

void init_EPWM2A(void)
{
    EPwm2Regs.TBCTL.bit.CTRMODE = TB_COUNT_UP;      // Set epwm1 to upcount mode, 0x0
    EPwm2Regs.TBCTL.bit.FREE_SOFT = 0x2;            // Free Run, do not stop
    EPwm2Regs.TBCTL.bit.PHSEN = TB_DISABLE;         // Disable phase loading, 0x0
    EPwm2Regs.TBPRD = 2500;                         // set epwm1 counter  20KHz
    EPwm2Regs.TBPHS.bit.TBPHS = 0x0000;             // Phase is 0
    EPwm2Regs.TBCTR = 0x0000;                       // Clear counter
    // For EPWM2A
    EPwm2Regs.AQCTLA.bit.CAU = AQ_CLEAR;            // Clear when counter = compareA
    EPwm2Regs.AQCTLA.bit.ZRO = AQ_SET;              // Set when timer is 0
}

void set_EPWM2A(float u)
{
    float pwmCountMax = 2500.0;
    float pwmVal = 0;
    if (u >  10) u =  10;
    if (u < -10) u = -10;
    pwmVal = u * (pwmCountMax / 20.0) + pwmCountMax / 2.0;
    EPwm2Regs.CMPA.bit.CMPA = (int)pwmVal;
}


/************************** Setup EPWM2B **************************/
void init_EPWM2B_GPIO(void)
{
    EALLOW;
    GpioCtrlRegs.GPAPUD.bit.GPIO3 = 1;    // Disable pull-up on GPIO3 (EPWM2B)
    GpioCtrlRegs.GPAMUX1.bit.GPIO3 = 1;   // Configure GPIO3 as EPWM2B
    EDIS;
}


void init_EPWM2B(void)
{
    EPwm2Regs.TBCTL.bit.CTRMODE = TB_COUNT_UP;      // Set epwm1 to upcount mode, 0x0
    EPwm2Regs.TBCTL.bit.FREE_SOFT = 0x2;            // Free Run, do not stop
    EPwm2Regs.TBCTL.bit.PHSEN = TB_DISABLE;         // Disable phase loading, 0x0
    EPwm2Regs.TBPRD = 2500;                         // set epwm1 counter  20KHz
    EPwm2Regs.TBPHS.bit.TBPHS = 0x0000;             // Phase is 0
    EPwm2Regs.TBCTR = 0x0000;                       // Clear counter
    // For EPWM2B
    EPwm2Regs.AQCTLB.bit.CBU = AQ_CLEAR;            // Clear when counter = compareA
    EPwm2Regs.AQCTLB.bit.ZRO = AQ_SET;              // Set when timer is 0
}

void set_EPWM2B(float u)
{
    float pwmCountMax = 2500.0;
    float pwmVal = 0;
    if (u >  10) u =  10;
    if (u < -10) u = -10;
    pwmVal = u * (pwmCountMax / 20.0) + pwmCountMax / 2.0;
    EPwm2Regs.CMPB.bit.CMPB = (int)pwmVal;
}


/************************** Setup EPWM3A **************************/
void init_EPWM3A_GPIO(void)
{
    EALLOW;
    GpioCtrlRegs.GPAPUD.bit.GPIO4 = 1;    // Disable pull-up on GPIO4 (EPWM3A)
    GpioCtrlRegs.GPAMUX1.bit.GPIO4 = 1;   // Configure GPIO4 as EPWM3A
    EDIS;
}

void init_EPWM3A(void)
{
    EPwm3Regs.TBCTL.bit.CTRMODE = TB_COUNT_UP;      // Set epwm1 to upcount mode, 0x0
    EPwm3Regs.TBCTL.bit.FREE_SOFT = 0x2;            // Free Run, do not stop
    EPwm3Regs.TBCTL.bit.PHSEN = TB_DISABLE;         // Disable phase loading, 0x0
    EPwm3Regs.TBPRD = 2500;                         // set epwm1 counter  20KHz
    EPwm3Regs.TBPHS.bit.TBPHS = 0x0000;             // Phase is 0
    EPwm3Regs.TBCTR = 0x0000;                       // Clear counter
    // For EPWM3A
    EPwm3Regs.AQCTLA.bit.CAU = AQ_CLEAR;            // Clear when counter = compareA
    EPwm3Regs.AQCTLA.bit.ZRO = AQ_SET;              // Set when timer is 0
}

void set_EPWM3A(float u)
{
    float pwmCountMax = 2500.0;
    float pwmVal = 0;
    if (u >  10) u =  10;
    if (u < -10) u = -10;
    pwmVal = u * (pwmCountMax / 20.0) + pwmCountMax / 2.0;
    EPwm3Regs.CMPA.bit.CMPA = (int)pwmVal;
}


/************************** Setup EPWM3B **************************/
void init_EPWM3B_GPIO(void)
{
    EALLOW;
    GpioCtrlRegs.GPAPUD.bit.GPIO5 = 1;    // Disable pull-up on GPIO5 (EPWM3B)
    GpioCtrlRegs.GPAMUX1.bit.GPIO5 = 1;   // Configure GPIO5 as EPWM3B
    EDIS;
}

void init_EPWM3B(void)
{
    EPwm3Regs.TBCTL.bit.CTRMODE = TB_COUNT_UP;      // Set epwm1 to upcount mode, 0x0
    EPwm3Regs.TBCTL.bit.FREE_SOFT = 0x2;            // Free Run, do not stop
    EPwm3Regs.TBCTL.bit.PHSEN = TB_DISABLE;         // Disable phase loading, 0x0
    EPwm3Regs.TBPRD = 2500;                         // set epwm1 counter  20KHz
    EPwm3Regs.TBPHS.bit.TBPHS = 0x0000;             // Phase is 0
    EPwm3Regs.TBCTR = 0x0000;                       // Clear counter
    // For EPWM3B
    EPwm3Regs.AQCTLB.bit.CBU = AQ_CLEAR;            // Clear when counter = compareA
    EPwm3Regs.AQCTLB.bit.ZRO = AQ_SET;              // Set when timer is 0
}

void set_EPWM3B(float u)
{
    float pwmCountMax = 2500.0;
    float pwmVal = 0;
    if (u >  10) u =  10;
    if (u < -10) u = -10;
    pwmVal = u * (pwmCountMax / 20.0) + pwmCountMax / 2.0;
    EPwm3Regs.CMPB.bit.CMPB = (int)pwmVal;
}


/************************** Setup EPWM4A **************************/

void init_EPWM4A_GPIO(void)
{
    EALLOW;
    GpioCtrlRegs.GPAPUD.bit.GPIO6 = 1;    // Disable pull-up on GPIO6 (EPWM4A)
    GpioCtrlRegs.GPAMUX1.bit.GPIO6 = 1;   // Configure GPIO6 as EPWM4A
    EDIS;
}

void init_EPWM4A(void)
{
    EPwm4Regs.TBCTL.bit.CTRMODE = TB_COUNT_UP;      // Set epwm1 to upcount mode, 0x0
    EPwm4Regs.TBCTL.bit.FREE_SOFT = 0x2;            // Free Run, do not stop
    EPwm4Regs.TBCTL.bit.PHSEN = TB_DISABLE;         // Disable phase loading, 0x0
    EPwm4Regs.TBPRD = 2500;                         // set epwm1 counter  20KHz
    EPwm4Regs.TBPHS.bit.TBPHS = 0x0000;             // Phase is 0
    EPwm4Regs.TBCTR = 0x0000;                       // Clear counter
    // For EPWM4A
    EPwm4Regs.AQCTLA.bit.CAU = AQ_CLEAR;            // Clear when counter = compareA
    EPwm4Regs.AQCTLA.bit.ZRO = AQ_SET;              // Set when timer is 0
}

void set_EPWM4A(float u)
{
    float pwmCountMax = 2500.0;
    float pwmVal = 0;
    if (u >  10) u =  10;
    if (u < -10) u = -10;
    pwmVal = u * (pwmCountMax / 20.0) + pwmCountMax / 2.0;
    EPwm4Regs.CMPA.bit.CMPA = (int)pwmVal;
}

/************************** Setup EPWM4B **************************/

void init_EPWM4B_GPIO(void)
{
    EALLOW;
    GpioCtrlRegs.GPAPUD.bit.GPIO7 = 1;    // Disable pull-up on GPIO7 (EPWM4B)
    GpioCtrlRegs.GPAMUX1.bit.GPIO7 = 1;   // Configure GPIO7 as EPWM4B
    EDIS;
}

void init_EPWM4B(void)
{
    EPwm4Regs.TBCTL.bit.CTRMODE = TB_COUNT_UP;      // Set epwm1 to upcount mode, 0x0
    EPwm4Regs.TBCTL.bit.FREE_SOFT = 0x2;            // Free Run, do not stop
    EPwm4Regs.TBCTL.bit.PHSEN = TB_DISABLE;         // Disable phase loading, 0x0
    EPwm4Regs.TBPRD = 2500;                         // set epwm1 counter  20KHz
    EPwm4Regs.TBPHS.bit.TBPHS = 0x0000;             // Phase is 0
    EPwm4Regs.TBCTR = 0x0000;                       // Clear counter
    // For EPWM4B
    EPwm4Regs.AQCTLB.bit.CBU = AQ_CLEAR;            // Clear when counter = compareA
    EPwm4Regs.AQCTLB.bit.ZRO = AQ_SET;              // Set when timer is 0
}

void set_EPWM4B(float u)
{
    float pwmCountMax = 2500.0;
    float pwmVal = 0;
    if (u >  10) u =  10;
    if (u < -10) u = -10;
    pwmVal = u * (pwmCountMax / 20.0) + pwmCountMax / 2.0;
    EPwm4Regs.CMPB.bit.CMPB = (int)pwmVal;
}

/************************** Setup EPWM5A **************************/

void init_EPWM5A_GPIO(void)
{
    EALLOW;
    GpioCtrlRegs.GPAPUD.bit.GPIO8 = 1;    // Disable pull-up on GPIO8 (EPWM5A)
    GpioCtrlRegs.GPAMUX1.bit.GPIO8 = 1;   // Configure GPIO8 as EPWM5A
    EDIS;
}

void init_EPWM5A(void)
{
    EPwm5Regs.TBCTL.bit.CTRMODE = TB_COUNT_UP;      // Set epwm1 to upcount mode, 0x0
    EPwm5Regs.TBCTL.bit.FREE_SOFT = 0x2;            // Free Run, do not stop
    EPwm5Regs.TBCTL.bit.PHSEN = TB_DISABLE;         // Disable phase loading, 0x0
    EPwm5Regs.TBPRD = 2500;                         // set epwm1 counter  20KHz
    EPwm5Regs.TBPHS.bit.TBPHS = 0x0000;             // Phase is 0
    EPwm5Regs.TBCTR = 0x0000;                       // Clear counter
    // For EPWM5A
    EPwm5Regs.AQCTLA.bit.CAU = AQ_CLEAR;            // Clear when counter = compareA
    EPwm5Regs.AQCTLA.bit.ZRO = AQ_SET;              // Set when timer is 0
}

void set_EPWM5A(float u)
{
    float pwmCountMax = 2500.0;
    float pwmVal = 0;
    if (u >  10) u =  10;
    if (u < -10) u = -10;
    pwmVal = u * (pwmCountMax / 20.0) + pwmCountMax / 2.0;
    EPwm5Regs.CMPA.bit.CMPA = (int)pwmVal;
}

/************************** Setup EPWM5B **************************/

void init_EPWM5B_GPIO(void)
{
    EALLOW;
    GpioCtrlRegs.GPAPUD.bit.GPIO9 = 1;    // Disable pull-up on GPIO9 (EPWM5B)
    GpioCtrlRegs.GPAMUX1.bit.GPIO9 = 1;   // Configure GPIO9 as EPWM5B
    EDIS;
}

void init_EPWM5B(void)
{
    EPwm5Regs.TBCTL.bit.CTRMODE = TB_COUNT_UP;      // Set epwm1 to upcount mode, 0x0
    EPwm5Regs.TBCTL.bit.FREE_SOFT = 0x2;            // Free Run, do not stop
    EPwm5Regs.TBCTL.bit.PHSEN = TB_DISABLE;         // Disable phase loading, 0x0
    EPwm5Regs.TBPRD = 2500;                         // set epwm1 counter  20KHz
    EPwm5Regs.TBPHS.bit.TBPHS = 0x0000;             // Phase is 0
    EPwm5Regs.TBCTR = 0x0000;                       // Clear counter
    // For EPWM5B
    EPwm5Regs.AQCTLB.bit.CBU = AQ_CLEAR;            // Clear when counter = compareA
    EPwm5Regs.AQCTLB.bit.ZRO = AQ_SET;              // Set when timer is 0
}

void set_EPWM5B(float u)
{
    float pwmCountMax = 2500.0;
    float pwmVal = 0;
    if (u >  10) u =  10;
    if (u < -10) u = -10;
    pwmVal = u * (pwmCountMax / 20.0) + pwmCountMax / 2.0;
    EPwm5Regs.CMPB.bit.CMPB = (int)pwmVal;
}

/************************** Setup EPWM6A **************************/

void init_EPWM6A_GPIO(void)
{
    EALLOW;
    GpioCtrlRegs.GPAPUD.bit.GPIO10 = 1;    // Disable pull-up on GPIO10 (EPWM6A)
    GpioCtrlRegs.GPAMUX1.bit.GPIO10 = 1;   // Configure GPIO10 as EPWM6A
    EDIS;
}

void init_EPWM6A(void)
{
    EPwm6Regs.TBCTL.bit.CTRMODE = TB_COUNT_UP;      // Set epwm1 to upcount mode, 0x0
    EPwm6Regs.TBCTL.bit.FREE_SOFT = 0x2;            // Free Run, do not stop
    EPwm6Regs.TBCTL.bit.PHSEN = TB_DISABLE;         // Disable phase loading, 0x0
    EPwm6Regs.TBPRD = 2500;                         // set epwm1 counter  20KHz
    EPwm6Regs.TBPHS.bit.TBPHS = 0x0000;             // Phase is 0
    EPwm6Regs.TBCTR = 0x0000;                       // Clear counter
    // For EPWM6A
    EPwm6Regs.AQCTLA.bit.CAU = AQ_CLEAR;            // Clear when counter = compareA
    EPwm6Regs.AQCTLA.bit.ZRO = AQ_SET;              // Set when timer is 0
}

void set_EPWM6A(float u)
{
    float pwmCountMax = 2500.0;
    float pwmVal = 0;
    if (u >  10) u =  10;
    if (u < -10) u = -10;
    pwmVal = u * (pwmCountMax / 20.0) + pwmCountMax / 2.0;
    EPwm6Regs.CMPA.bit.CMPA = (int)pwmVal;
}

/************************** Setup EPWM6B **************************/

void init_EPWM6B_GPIO(void)
{
    EALLOW;
    GpioCtrlRegs.GPAPUD.bit.GPIO11 = 1;    // Disable pull-up on GPIO11 (EPWM6B)
    GpioCtrlRegs.GPAMUX1.bit.GPIO11 = 1;   // Configure GPIO11 as EPWM6B
    EDIS;
}

void init_EPWM6B(void)
{
    EPwm6Regs.TBCTL.bit.CTRMODE = TB_COUNT_UP;      // Set epwm1 to upcount mode, 0x0
    EPwm6Regs.TBCTL.bit.FREE_SOFT = 0x2;            // Free Run, do not stop
    EPwm6Regs.TBCTL.bit.PHSEN = TB_DISABLE;         // Disable phase loading, 0x0
    EPwm6Regs.TBPRD = 2500;                         // set epwm1 counter  20KHz
    EPwm6Regs.TBPHS.bit.TBPHS = 0x0000;             // Phase is 0
    EPwm6Regs.TBCTR = 0x0000;                       // Clear counter
    // For EPWM6B
    EPwm6Regs.AQCTLB.bit.CBU = AQ_CLEAR;            // Clear when counter = compareA
    EPwm6Regs.AQCTLB.bit.ZRO = AQ_SET;              // Set when timer is 0
}

void set_EPWM6B(float u)
{
    float pwmCountMax = 2500.0;
    float pwmVal = 0;
    if (u >  10) u =  10;
    if (u < -10) u = -10;
    pwmVal = u * (pwmCountMax / 20.0) + pwmCountMax / 2.0;
    EPwm6Regs.CMPB.bit.CMPB = (int)pwmVal;
}

















