#include <F28379D_EQep.h>
#include <F28379D_Coecsl.h>

eqep_t eqep1;
eqep_t eqep2;

/* init_EQEP(): initialize quadrature encoder pulse QEP
 *
 * parameters:
 *    eqep  = address pointer to QEP structure
 *    eq    = EQEP 1 or 2
 *    cpr   = encoder's rated counts per revolution
 *    init_rad_coord = initial radian coordinate for 0 encoder count
 */
void init_EQEP(eqep_t *eqep, enum eQep_e eq, long cpr, int pol, float init_rad_coord)
{

	eqep->eq = eq;
	eqep->cpr = 4*cpr;
	eqep->init_rad_coord = init_rad_coord;
	eqep->res = TWOPI/(eqep->cpr);
	eqep->pol = pol;

	// select event manager
	switch (eq) {

        case EQEP1:

            // setup eQEP1 pins for input
            EALLOW;

            /* Disable internal pull-up for the selected output pins for reduced power consumption */
            GpioCtrlRegs.GPAPUD.bit.GPIO20 = 1;    // Disable pull-up on GPIO20 (EQEP1A)
            GpioCtrlRegs.GPAPUD.bit.GPIO21 = 1;    // Disable pull-up on GPIO21 (EQEP1B)

            GpioCtrlRegs.GPAQSEL2.bit.GPIO20 = 2;   // Qual every 6 samples
            GpioCtrlRegs.GPAQSEL2.bit.GPIO21 = 2;   // Qual every 6 samples

            GpioCtrlRegs.GPAMUX2.bit.GPIO20 = 1;    // Configure GPIO20 as EQEP1A
            GpioCtrlRegs.GPAMUX2.bit.GPIO21 = 1;    // Configure GPIO21 as EQEP1B

            EDIS;

            EQep1Regs.QEPCTL.bit.QPEN = 0;       // make sure qep reset
            //EQep1Regs.QEPCTL.bit.SWI = 1;      // Initialize Position counter to zero
            EQep1Regs.QDECCTL.bit.QSRC = 0;      // Quadrature count mode
            EQep1Regs.QPOSCTL.all = 0x0;         // Disable eQep Position Compare
            EQep1Regs.QCAPCTL.all = 0x0;         // Disable eQep Capture
            EQep1Regs.QEINT.all = 0x0;           // Disable all eQep interrupts
            EQep1Regs.QPOSMAX = 0xFFFFFFFF;
            EQep1Regs.QEPCTL.bit.FREE_SOFT = 2;  // EQep uneffected by emulation suspend
            EQep1Regs.QEPCTL.bit.QPEN = 1;       // Enable EQep

            break;

        case EQEP2:

            // setup eQEP2 pins for input
            EALLOW;

            /* Disable internal pull-up for the selected output pins for reduced power consumption */
            GpioCtrlRegs.GPBPUD.bit.GPIO54 = 1;    // Disable pull-up on GPIO54 (EQEP2A)
            GpioCtrlRegs.GPBPUD.bit.GPIO55 = 1;    // Disable pull-up on GPIO55 (EQEP2B)

            GpioCtrlRegs.GPBQSEL2.bit.GPIO54 = 2;   // Qual every 6 samples
            GpioCtrlRegs.GPBQSEL2.bit.GPIO55 = 2;   // Qual every 6 samples

            /* Configure EQEP-2 pins using GPIO regs*/
            // This specifies which of the possible GPIO pins will be EQEP2 functional pins.

            GpioCtrlRegs.GPBGMUX2.bit.GPIO54 = 1;   // Configure GPIO54 as EQEP2A
            GpioCtrlRegs.GPBMUX2.bit.GPIO54 = 1;    // Configure GPIO54 as EQEP2A

            GpioCtrlRegs.GPBGMUX2.bit.GPIO55 = 1;   // Configure GPIO55 as EQEP2B
            GpioCtrlRegs.GPBMUX2.bit.GPIO55 = 1;    // Configure GPIO55 as EQEP2B

            EDIS;

            EQep2Regs.QEPCTL.bit.QPEN = 0;       // make sure qep reset
            //EQep2Regs.QEPCTL.bit.SWI = 1;      // Initialize Position counter to zero
            EQep2Regs.QDECCTL.bit.QSRC = 0;      // Quadrature count mode
            EQep2Regs.QPOSCTL.all = 0x0;         // Disable eQep Position Compare
            EQep2Regs.QCAPCTL.all = 0x0;         // Disable eQep Capture
            EQep2Regs.QEINT.all = 0x0;           // Disable all eQep interrupts
            EQep2Regs.QPOSMAX = 0xFFFFFFFF;
            EQep2Regs.QEPCTL.bit.FREE_SOFT = 2;  // EQep uneffected by emulation suspend
            EQep2Regs.QEPCTL.bit.QPEN = 1;       // Enable EQep

            break;

	}

}



/* EQEP_read(): read QEP encoder's position in radians
 *
 * parameters:
 *    eqep   = address pointer to an initialized QEP structure
 *
 * return: encoder position in radians
 */

float EQEP_read(eqep_t *eqep)
{
	long raw = 0;

	// read raw value
	switch (eqep->eq) {

        case EQEP1:
            raw = EQep1Regs.QPOSCNT;
            break;

        case EQEP2:
            raw = EQep2Regs.QPOSCNT;
            break;
	}

	if (raw >= QEP_MAXVALUE/2) raw -= QEP_MAXVALUE;

	return ((eqep->pol)*(eqep->res)*raw + eqep->init_rad_coord);
}


long EQEP_readraw(eqep_t *eqep)
{
	long raw = 0;

	// read raw value
	switch (eqep->eq) {

        case EQEP1:
            raw = EQep1Regs.QPOSCNT;
            break;

        case EQEP2:
            raw = EQep2Regs.QPOSCNT;
            break;

	}

	if (raw >= QEP_MAXVALUE/2) raw -= QEP_MAXVALUE;

	return (raw);
}

// This function is called for you in main().
// It initializes EQEP1 and EQEP2 on the 28379D.
// EQEP1 is ENC1,  EQEP2 is ENC2
void init_EQEPs(void) {

    // 100: total slits of motor's encoder in one revolution
    // 30: gear ratio
    // 3000 = 100 * 30
    // 1: polarity of motor direction
    // 0: start  0 rad
	init_EQEP(&eqep1, EQEP1, 3000, 1, 0.0);
	EQep1Regs.QPOSCNT = 0;

    // 100: total slits of motor's encoder in one revolution
    // 30: gear ratio
    // 3000 = 100 * 30
    // -1: polarity of motor direction
    // 0: start  0 rad
	init_EQEP(&eqep2, EQEP2, 3000, -1, 0.0);
	EQep2Regs.QPOSCNT = 0;

}


// This function returns the radian value of Encoder 1.  Normally attached to the motor
//  Example code
//  float enc1 = 0;
//	enc1 = readEnc1();
float read_Enc1(void) {
	return(EQEP_read(&eqep1));
}

// This function returns the radian value of Encoder 2.  Normally attached to the pendulum
//  Example code
//  float enc2 = 0;
//	enc2 = readEnc2();
float read_Enc2(void) {
	return(EQEP_read(&eqep2));
}





