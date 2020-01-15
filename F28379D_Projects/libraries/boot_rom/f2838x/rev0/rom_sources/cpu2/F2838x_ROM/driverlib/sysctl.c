//###########################################################################
//
// FILE:   sysctl.c
//
// TITLE:  C28x system control driver.
//
//###########################################################################
// $TI Release: $
// $Release Date: $
// $Copyright: $
//###########################################################################

#include "sysctl.h"

//
// Define to isolate inline assembly
//
#define SYSCTL_DELAY        __asm(" .def _SysCtl_delay\n"                     \
                                  " .sect \".TI.ramfunc\"\n"                  \
                                  " .global  _SysCtl_delay\n"                 \
                                  "_SysCtl_delay:\n"                          \
                                  " SUB    ACC,#1\n"                          \
                                  " BF     _SysCtl_delay,GEQ\n"               \
                                  " LRETR\n")

//*****************************************************************************
//
// SysCtl_delay()
//
//*****************************************************************************
SYSCTL_DELAY;

//*****************************************************************************
//
// SysCtl_pollX1Counter()
//
//*****************************************************************************
static void
SysCtl_pollX1Counter(void)
{
    uint16_t loopCount = 0U;

    //
    // Delay for 1 ms while the XTAL powers up
    //
    // 2000 loops, 5 cycles per loop + 9 cycles overhead = 10009 cycles
    //
    SysCtl_delay(2000);

    //
    // Clear and saturate X1CNT 4 times to guarantee operation
    //
    do
    {
        //
        // Keep clearing the counter until it is no longer saturated
        //
        while(HWREG(CLKCFG_BASE + SYSCTL_O_X1CNT) > 0x1FFU)
        {
            HWREG(CLKCFG_BASE + SYSCTL_O_X1CNT) |= SYSCTL_X1CNT_CLR;
        }

        //
        // Wait for the X1 clock to saturate
        //
        while(HWREGH(CLKCFG_BASE + SYSCTL_O_X1CNT) != 0x3FFU)
        {
            ;
        }

        //
        // Increment the counter
        //
        loopCount++;
    }while(loopCount < 4U);
}

//*****************************************************************************
//
// SysCtl_getClock()
//
//*****************************************************************************
uint32_t
SysCtl_getClock(uint32_t clockInHz)
{
    uint32_t temp;
    uint32_t oscSource;
    uint32_t clockOut;

    //
    // Don't proceed if an MCD failure is detected.
    //
    if(SysCtl_isMCDClockFailureDetected())
    {
        //
        // OSCCLKSRC2 failure detected. Returning the INTOSC1 rate. You need
        // to handle the MCD and clear the failure.
        //
        clockOut = SYSCTL_DEFAULT_OSC_FREQ;
    }
    else
    {
        //
        // If one of the internal oscillators is being used, start from the
        // known default frequency.  Otherwise, use clockInHz parameter.
        //
        oscSource = HWREG(CLKCFG_BASE + SYSCTL_O_CLKSRCCTL1) &
                    (uint32_t)SYSCTL_CLKSRCCTL1_OSCCLKSRCSEL_M;

        if((oscSource == ((uint32_t)SYSCTL_OSCSRC_OSC2 >> SYSCTL_OSCSRC_S)) ||
           (oscSource == ((uint32_t)SYSCTL_OSCSRC_OSC1 >> SYSCTL_OSCSRC_S)))
        {
            clockOut = SYSCTL_DEFAULT_OSC_FREQ;
        }
        else
        {
            clockOut = clockInHz;
        }

        //
        // If the PLL is enabled calculate its effect on the clock
        //
        if((HWREG(CLKCFG_BASE + SYSCTL_O_SYSPLLCTL1) &
            (SYSCTL_SYSPLLCTL1_PLLEN | SYSCTL_SYSPLLCTL1_PLLCLKEN)) == 3U)
        {
            //
            // Calculate portion from fractional multiplier
            //
            switch((HWREG(CLKCFG_BASE + SYSCTL_O_SYSPLLMULT) &
                    SYSCTL_SYSPLLMULT_FMULT_M) >> SYSCTL_SYSPLLMULT_FMULT_S)
            {
                case 0U:
                    // No fractional portion.
                    temp = 0U;
                    break;

                case 1U:
                    temp = clockInHz / 4U;
                    break;

                case 2U:
                    temp = clockInHz / 2U;
                    break;

                case 3U:
                    temp = (clockInHz * 3U) / 4U;
                    break;

                default:
                    // Not a valid value for the FMULT register.
                    temp = 0U;
                    break;
            }

            //
            // Calculate integer multiplier and fixed divide by 2
            //
            clockOut = clockOut * ((HWREG(CLKCFG_BASE + SYSCTL_O_SYSPLLMULT) &
                                      SYSCTL_SYSPLLMULT_IMULT_M) >>
                                     SYSCTL_SYSPLLMULT_IMULT_S);

            //
            // Add in fractional portion
            //
            clockOut += temp;
        }

        if((HWREG(CLKCFG_BASE + SYSCTL_O_SYSCLKDIVSEL) &
           SYSCTL_SYSCLKDIVSEL_PLLSYSCLKDIV_M) != 0U)
        {
            clockOut /= (2U * (HWREG(CLKCFG_BASE + SYSCTL_O_SYSCLKDIVSEL) &
                                SYSCTL_SYSCLKDIVSEL_PLLSYSCLKDIV_M));
        }
    }

    return(clockOut);
}

//*****************************************************************************
//
// SysCtl_getAuxClock()
//
//*****************************************************************************
uint32_t SysCtl_getAuxClock(uint32_t clockInHz)
{
    uint32_t temp = 0;

    if(((HWREG(CLKCFG_BASE + SYSCTL_O_CLKSRCCTL1) &
         SYSCTL_CLKSRCCTL1_OSCCLKSRCSEL_M) ==
        ((uint32_t)SYSCTL_OSCSRC_OSC2 >> SYSCTL_OSCSRC_S)) ||
       ((HWREG(CLKCFG_BASE + SYSCTL_O_CLKSRCCTL1) &
         SYSCTL_CLKSRCCTL1_OSCCLKSRCSEL_M) ==
        ((uint32_t)SYSCTL_OSCSRC_OSC1 >> SYSCTL_OSCSRC_S)))
    {
        // 10MHz Internal Clock
        clockInHz = SYSCTL_DEFAULT_OSC_FREQ;
    }

    //
    // If the PLL is enabled calculate its effect on the clock
    //
    if((HWREG(CLKCFG_BASE + SYSCTL_O_AUXPLLCTL1) &
        (SYSCTL_AUXPLLCTL1_PLLEN | SYSCTL_AUXPLLCTL1_PLLCLKEN)) == 3U)
    {
        //
        // Calculate portion from fractional multiplier
        //
        temp = (clockInHz * ((HWREG(CLKCFG_BASE + SYSCTL_O_AUXPLLMULT) &
                SYSCTL_AUXPLLMULT_FMULT_M) >> SYSCTL_AUXPLLMULT_FMULT_S))/ 4U;

        //
        // Calculate integer multiplier and fixed divide by 2
        //
        clockInHz = clockInHz * ((HWREG(CLKCFG_BASE + SYSCTL_O_AUXPLLMULT) &
                                  SYSCTL_AUXPLLMULT_IMULT_M) >>
                                 SYSCTL_AUXPLLMULT_IMULT_S);

        //
        // Add in fractional portion
        //
        clockInHz += temp;
    }

    clockInHz /= (1U << (HWREG(CLKCFG_BASE + SYSCTL_O_AUXCLKDIVSEL) &
                        SYSCTL_AUXCLKDIVSEL_AUXPLLDIV_M));

    return(clockInHz);
}

//*****************************************************************************
//
// SysCtl_setClock()
//
//*****************************************************************************
bool
SysCtl_setClock(uint32_t config)
{
    uint16_t divSel;
    uint16_t pllMult;
    uint32_t retries, oscSource, pllLockStatus;
    uint32_t timeout;
    bool status = false;

    //
    // Check the arguments.
    //
    ASSERT((config & SYSCTL_OSCSRC_M) != SYSCTL_OSCSRC_M); // 3 is not valid

    //
    // Don't proceed to the PLL initialization if an MCD failure is detected.
    //
    if(SysCtl_isMCDClockFailureDetected())
    {
        //
        // OSCCLKSRC2 failure detected. Returning false. You'll need to clear
        // the MCD error.
        //
        status = false;
    }
    else
    {
        //
        // Configure oscillator source
        //
        oscSource = config & SYSCTL_OSCSRC_M;
        SysCtl_selectOscSource(oscSource);

        //
        // Bypass PLL
        //
        EALLOW;
        HWREGH(CLKCFG_BASE + SYSCTL_O_SYSPLLCTL1) &=
            ~SYSCTL_SYSPLLCTL1_PLLCLKEN;
        EDIS;

        SysCtl_delay(3U);

        //
        // Configure PLL if enabled
        //
        if((config & SYSCTL_PLL_ENABLE) == SYSCTL_PLL_ENABLE)
        {
            //
            // Set dividers to /1
            //
            EALLOW;
            HWREGH(CLKCFG_BASE + SYSCTL_O_SYSCLKDIVSEL) = 0U;
            EDIS;

            //
            // Get the PLL multiplier settings from config
            //
            pllMult  = (uint16_t)((config & SYSCTL_IMULT_M) <<
                                  SYSCTL_SYSPLLMULT_IMULT_S);

            pllMult |= (uint16_t)(((config & SYSCTL_FMULT_M) >>
                                   SYSCTL_FMULT_S) <<
                                  SYSCTL_SYSPLLMULT_FMULT_S);

            //
            // Loop to retry locking the PLL should the DCC module indicate
            // that it was not successful.
            //
            for(retries = 0U; (retries < SYSCTL_PLL_RETRIES); retries++)
            {
                //
                // Turn off PLL
                //
                EALLOW;
                HWREGH(CLKCFG_BASE + SYSCTL_O_SYSPLLCTL1) &=
                    ~SYSCTL_SYSPLLCTL1_PLLEN;

                SysCtl_delay(3U);

                //
                // Write multiplier, which automatically turns on the PLL
                //
                HWREGH(CLKCFG_BASE + SYSCTL_O_SYSPLLMULT) |= pllMult;

                //
                // Wait for the SYSPLL lock counter or a timeout
                //
                timeout = SYSCTL_PLLLOCK_TIMEOUT;
                pllLockStatus = HWREGH(CLKCFG_BASE + SYSCTL_O_SYSPLLSTS) &
                                SYSCTL_SYSPLLSTS_LOCKS;

                while((pllLockStatus != 1U) && (timeout != 0U))
                {
                    pllLockStatus = HWREGH(CLKCFG_BASE + SYSCTL_O_SYSPLLSTS) &
                                    SYSCTL_SYSPLLSTS_LOCKS;
                    timeout--;
                }
                EDIS;

                //
                // Check PLL Frequency using DCC
                //
                status = true;

                //
                // Check DCC Status, if no error break the loop
                //
                if(status)
                {
                    break;
                }
            }
        }
        else
        {
            status = true;
        }

        //
        // If PLL locked successfully, configure the dividers
        //
        if(status)
        {
            //
            // Set divider to produce slower output frequency to limit current
            // increase.
            //
            divSel = (uint16_t)(config & SYSCTL_SYSDIV_M) >> SYSCTL_SYSDIV_S;

            EALLOW;
            if(divSel != (126U / 2U))
            {
                HWREGH(CLKCFG_BASE + SYSCTL_O_SYSCLKDIVSEL) =
                    (HWREGH(CLKCFG_BASE + SYSCTL_O_SYSCLKDIVSEL) &
                     ~(uint16_t)SYSCTL_SYSCLKDIVSEL_PLLSYSCLKDIV_M) |
                    (divSel + 1U);
            }
            else
            {
                HWREGH(CLKCFG_BASE + SYSCTL_O_SYSCLKDIVSEL) =
                    (HWREGH(CLKCFG_BASE + SYSCTL_O_SYSCLKDIVSEL) &
                     ~(uint16_t)SYSCTL_SYSCLKDIVSEL_PLLSYSCLKDIV_M) | divSel;
            }

            EDIS;

            //
            // Enable PLLSYSCLK is fed from system PLL clock
            //
            EALLOW;
            HWREGH(CLKCFG_BASE + SYSCTL_O_SYSPLLCTL1) |=
                SYSCTL_SYSPLLCTL1_PLLCLKEN;
            EDIS;

            //
            // ~200 PLLSYSCLK delay to allow voltage regulator to stabilize
            // prior to increasing entire system clock frequency.
            //
            SysCtl_delay(40U);

            //
            // Set the divider to user value
            //
            EALLOW;
            HWREGH(CLKCFG_BASE + SYSCTL_O_SYSCLKDIVSEL) =
                (HWREGH(CLKCFG_BASE + SYSCTL_O_SYSCLKDIVSEL) &
                 ~SYSCTL_SYSCLKDIVSEL_PLLSYSCLKDIV_M) | divSel;
            EDIS;
        }
    }

    return(status);
}

//*****************************************************************************
//
// SysCtl_selectXTAL()
//
//*****************************************************************************
void
SysCtl_selectXTAL(void)
{
    //
    // Turn on XTAL and select crystal mode
    //
    EALLOW;
    HWREGH(CLKCFG_BASE + SYSCTL_O_XTALCR) &= ~SYSCTL_XTALCR_OSCOFF;
    HWREGH(CLKCFG_BASE + SYSCTL_O_XTALCR) &= ~SYSCTL_XTALCR_SE;
    EDIS;

    //
    // Wait for the X1 clock to saturate
    //
    SysCtl_pollX1Counter();

    //Turn on XTALOSC
    HWREGH(CLKCFG_BASE + SYSCTL_O_CLKSRCCTL1) &=
          ~SYSCTL_CLKSRCCTL1_XTALOFF;

    //
    // Select XTAL as the oscillator source
    //
    EALLOW;
    HWREGH(CLKCFG_BASE + SYSCTL_O_CLKSRCCTL1) &=
        ~SYSCTL_CLKSRCCTL1_OSCCLKSRCSEL_M;
    HWREGH(CLKCFG_BASE + SYSCTL_O_CLKSRCCTL1) |=
        ((uint32_t)SYSCTL_OSCSRC_XTAL >> SYSCTL_OSCSRC_S);
    EDIS;

    //
    // If a missing clock failure was detected, try waiting for the X1 counter
    // to saturate again. Consider modifying this code to add a 10ms timeout.
    //
    while(SysCtl_isMCDClockFailureDetected())
    {
        //
        // Clear the MCD failure
        //
        SysCtl_resetMCD();

        //
        // Wait for the X1 clock to saturate
        //
        SysCtl_pollX1Counter();

        //Turn on XTALOSC
        HWREGH(CLKCFG_BASE + SYSCTL_O_CLKSRCCTL1) &=
              ~SYSCTL_CLKSRCCTL1_XTALOFF;

        //
        // Select XTAL as the oscillator source
        //
        EALLOW;
        HWREGH(CLKCFG_BASE + SYSCTL_O_CLKSRCCTL1) &=
            ~SYSCTL_CLKSRCCTL1_OSCCLKSRCSEL_M;
        HWREGH(CLKCFG_BASE + SYSCTL_O_CLKSRCCTL1) |=
            ((uint32_t)SYSCTL_OSCSRC_XTAL >> SYSCTL_OSCSRC_S);
        EDIS;
    }
}

//*****************************************************************************
//
// SysCtl_selectXTALSingleEnded()
//
//*****************************************************************************
void
SysCtl_selectXTALSingleEnded(void)
{
    //
    // Turn on XTAL and select single-ended mode.
    //
    EALLOW;
    HWREGH(CLKCFG_BASE + SYSCTL_O_XTALCR) &= ~SYSCTL_XTALCR_OSCOFF;
    HWREGH(CLKCFG_BASE + SYSCTL_O_XTALCR) |= SYSCTL_XTALCR_SE;
    EDIS;

    //
    // Wait for the X1 clock to saturate
    //
    SysCtl_pollX1Counter();

    //Turn on XTALOSC
    HWREGH(CLKCFG_BASE + SYSCTL_O_CLKSRCCTL1) &=
          ~SYSCTL_CLKSRCCTL1_XTALOFF;

    //
    // Select XTAL as the oscillator source
    //
    EALLOW;
    HWREGH(CLKCFG_BASE + SYSCTL_O_CLKSRCCTL1) &=
        ~SYSCTL_CLKSRCCTL1_OSCCLKSRCSEL_M;
    HWREGH(CLKCFG_BASE + SYSCTL_O_CLKSRCCTL1) |=
        ((uint32_t)SYSCTL_OSCSRC_XTAL >> SYSCTL_OSCSRC_S);
    EDIS;

    //
    // Something is wrong with the oscillator module. Replace the ESTOP0 with
    // an appropriate error-handling routine.
    //
    while(SysCtl_isMCDClockFailureDetected())
    {
        ESTOP0;
    }
}

//*****************************************************************************
//
// SysCtl_selectOscSource()
//
//*****************************************************************************
void
SysCtl_selectOscSource(uint32_t oscSource)
{
    ASSERT((oscSource == SYSCTL_OSCSRC_OSC1) |
           (oscSource == SYSCTL_OSCSRC_OSC2) |
           (oscSource == SYSCTL_OSCSRC_XTAL) |
           (oscSource == SYSCTL_OSCSRC_XTAL_SE));

    //
    // Select the specified source.
    //
    EALLOW;
    switch(oscSource)
    {
        case SYSCTL_OSCSRC_OSC2:
            // Turn on INTOSC2
            HWREGH(CLKCFG_BASE + SYSCTL_O_CLKSRCCTL1) &=
                ~SYSCTL_CLKSRCCTL1_INTOSC2OFF;
            // Clk Src = INTOSC2
            HWREGH(CLKCFG_BASE + SYSCTL_O_CLKSRCCTL1) &=
                ~SYSCTL_CLKSRCCTL1_OSCCLKSRCSEL_M;
            //Turn off XTALOSC
            HWREGH(CLKCFG_BASE + SYSCTL_O_CLKSRCCTL1) |=
                SYSCTL_CLKSRCCTL1_XTALOFF;
            break;

        case SYSCTL_OSCSRC_XTAL:
            // Select XTAL in crystal mode and wait for it to power up
            SysCtl_selectXTAL();
            break;

        case SYSCTL_OSCSRC_XTAL_SE:
            // Select XTAL in single-ended mode and wait for it to power up
            SysCtl_selectXTALSingleEnded();
            break;

        case SYSCTL_OSCSRC_OSC1:
            // Clk Src = INTOSC1
            HWREGH(CLKCFG_BASE + SYSCTL_O_CLKSRCCTL1) &=
                ~SYSCTL_CLKSRCCTL1_OSCCLKSRCSEL_M;
            HWREGH(CLKCFG_BASE + SYSCTL_O_CLKSRCCTL1) |=
                ((uint32_t)SYSCTL_OSCSRC_OSC1 >> SYSCTL_OSCSRC_S);
            //Turn off XTALOSC
            HWREGH(CLKCFG_BASE + SYSCTL_O_CLKSRCCTL1) |=
                SYSCTL_CLKSRCCTL1_XTALOFF;
            break;

        default:
            // Do nothing. Not a valid oscSource value.
            break;
    }
    EDIS;
}

//*****************************************************************************
//
// SysCtl_getLowSpeedClock()
//
//*****************************************************************************
uint32_t
SysCtl_getLowSpeedClock(uint32_t clockInHz)
{
    uint32_t clockOut;

    //
    // Get the main system clock
    //
    clockOut = SysCtl_getClock(clockInHz);

    //
    // Apply the divider to the main clock
    //
    if((HWREG(CLKCFG_BASE + SYSCTL_O_LOSPCP) &
        SYSCTL_LOSPCP_LSPCLKDIV_M) != 0U)
    {
        clockOut /= (2U * (HWREG(CLKCFG_BASE + SYSCTL_O_LOSPCP) &
                            SYSCTL_LOSPCP_LSPCLKDIV_M));
    }

    return(clockOut);
}

//*****************************************************************************
//
// SysCtl_getDeviceParametric()
//
//*****************************************************************************
uint16_t
SysCtl_getDeviceParametric(SysCtl_DeviceParametric parametric)
{
    uint32_t value;

    //
    // Get requested parametric value
    //
    switch(parametric)
    {
        case SYSCTL_DEVICE_TEMPERATURE:
            //
            // Device Temperature
            //
            value = ((HWREG(DEVCFG_BASE + SYSCTL_O_PARTIDL) &
                      SYSCTL_PARTIDL_TEMPERATURE_M) >> 
                      SYSCTL_PARTIDL_TEMPERATURE_S);
            break;

        case SYSCTL_DEVICE_PACKAGE:
            //
            // Device Package
            //
            value = ((HWREG(DEVCFG_BASE + SYSCTL_O_PARTIDL) &
                      SYSCTL_PARTIDL_PACKAGE_M) >> SYSCTL_PARTIDL_PACKAGE_S);
            break;
        case SYSCTL_DEVICE_QUAL:
            //
            // Qualification Status
            //
            value = ((HWREG(DEVCFG_BASE + SYSCTL_O_PARTIDL) &
                      SYSCTL_PARTIDL_QUAL_M) >> SYSCTL_PARTIDL_QUAL_S);
            break;

        case SYSCTL_DEVICE_PINCOUNT:
            //
            // Pin Count
            //
            value = ((HWREG(DEVCFG_BASE + SYSCTL_O_PARTIDL) &
                      SYSCTL_PARTIDL_PIN_COUNT_M) >>
                     SYSCTL_PARTIDL_PIN_COUNT_S);
            break;

        case SYSCTL_DEVICE_INSTASPIN:
            //
            // InstaSPIN Feature Set
            //
            value = ((HWREG(DEVCFG_BASE + SYSCTL_O_PARTIDL) &
                      SYSCTL_PARTIDL_INSTASPIN_M) >>
                     SYSCTL_PARTIDL_INSTASPIN_S);
            break;

        case SYSCTL_DEVICE_FLASH:
            //
            // Flash Size (KB)
            //
            value = ((HWREG(DEVCFG_BASE + SYSCTL_O_PARTIDL) &
                      SYSCTL_PARTIDL_FLASH_SIZE_M) >>
                     SYSCTL_PARTIDL_FLASH_SIZE_S);
            break;
        case SYSCTL_DEVICE_PARTID:
            //
            // PARTID Format Revision
            //
            value = ((HWREG(DEVCFG_BASE + SYSCTL_O_PARTIDL) &
                      SYSCTL_PARTIDL_PARTID_FORMAT_REVISION_M) >>
                     SYSCTL_PARTIDL_PARTID_FORMAT_REVISION_S);
            break;
        case SYSCTL_DEVICE_FAMILY:
            //
            // Device Family
            //
            value = ((HWREG(DEVCFG_BASE + SYSCTL_O_PARTIDH) &
                      SYSCTL_PARTIDH_FAMILY_M) >> SYSCTL_PARTIDH_FAMILY_S);
            break;

        case SYSCTL_DEVICE_PARTNO:
            //
            // Part Number
            //
            value = ((HWREG(DEVCFG_BASE + SYSCTL_O_PARTIDH) &
                      SYSCTL_PARTIDH_PARTNO_M) >> SYSCTL_PARTIDH_PARTNO_S);
            break;

        case SYSCTL_DEVICE_CLASSID:
            //
            // Class ID
            //
            value = ((HWREG(DEVCFG_BASE + SYSCTL_O_PARTIDH) &
                      SYSCTL_PARTIDH_DEVICE_CLASS_ID_M) >>
                     SYSCTL_PARTIDH_DEVICE_CLASS_ID_S);
            break;

        default:
            // Not a valid value for PARTID register
            value = 0U;
            break;
    }

    return((uint16_t)value);
}
//*****************************************************************************
//
// SysCtl_controlCPU2Reset()
//
//*****************************************************************************
void
SysCtl_controlCPU2Reset(SysCtl_CoreReset control)
{  
    uint32_t clearvalue;

  //
  //Based on whether the Core is to be reset or not, 
  //the core would be put into reset or brought out.
  //
    if(control != 0x0U)
  {
    //
    //On matching key, write to the reset bits would be successful
    //
    EALLOW;
    HWREG(DEVCFG_BASE + SYSCTL_O_CPU2RESCTL) |= ((uint32_t)SYSCTL_CPU2RESCTL_RESET |
                                                (SYSCTL_REG_KEY &
                                                 SYSCTL_CPU2RESCTL_KEY_M));
    EDIS;
  }
 else 
  { 
    EALLOW;
    //
    //On matching key, write to the reset bits would be successful
    //
    clearvalue = HWREG(DEVCFG_BASE + SYSCTL_O_CPU2RESCTL);
    clearvalue &= ~SYSCTL_CPU2RESCTL_RESET;
    HWREG(DEVCFG_BASE + SYSCTL_O_CPU2RESCTL) = (SYSCTL_REG_KEY &
                                                SYSCTL_CPU2RESCTL_KEY_M)| 
                                                clearvalue;
    EDIS;
  }
}

//*****************************************************************************
//
// SysCtl_configureType()
//
//*****************************************************************************
void
SysCtl_configureType(SysCtl_SelType type , uint16_t config, uint16_t lock)
{
  EALLOW;
  
  //
  // Check which type needs to be configured , the type would be enabled /
  // disabled along with making the configurations unalterable as per input.
  //
  switch((uint16_t)type)
  {
    case SYSCTL_USBTYPE:
    {
      HWREGH(DEVCFG_BASE + 
             SYSCTL_O_USBTYPE) |= (config |((lock << SYSCTL_TYPE_LOCK_S) &
                                            SYSCTL_USBTYPE_LOCK));
      break;
    }
    case SYSCTL_ECAPTYPE:
    {
      HWREGH(DEVCFG_BASE + 
             SYSCTL_O_ECAPTYPE) |= (config |((lock << SYSCTL_TYPE_LOCK_S) & 
                                             SYSCTL_ECAPTYPE_LOCK));
      break;
    }
    case SYSCTL_SDFMTYPE:
    {
      HWREGH(DEVCFG_BASE + 
             SYSCTL_O_SDFMTYPE) |= (config |((lock << SYSCTL_TYPE_LOCK_S) & 
                                             SYSCTL_SDFMTYPE_LOCK));
      break;
    }
    case SYSCTL_MEMMAPTYPE:
    {
      HWREGH(DEVCFG_BASE + 
             SYSCTL_O_MEMMAPTYPE) |= (config |((lock << SYSCTL_TYPE_LOCK_S)& 
                                               SYSCTL_MEMMAPTYPE_LOCK));
      break;
    }
    //
    //default case 
    //
    default: 
    {
      break;
    }
  }

  EDIS;

}

//*****************************************************************************
//
// SysCtl_isConfigTypeLocked()
//
//*****************************************************************************
bool
SysCtl_isConfigTypeLocked(SysCtl_SelType type)
{
  bool lock = 0x0U;
  
  EALLOW;
  //
  // Check if the provided type registers can be modified or not.
  //
  switch((uint16_t)type)
  {
    case SYSCTL_USBTYPE:
    {
        lock =((HWREGH(DEVCFG_BASE + SYSCTL_O_USBTYPE) &
                SYSCTL_USBTYPE_LOCK) != 0U);
        break;
    }
    case SYSCTL_ECAPTYPE:
    {
        lock =((HWREGH(DEVCFG_BASE + SYSCTL_O_ECAPTYPE) &
                SYSCTL_ECAPTYPE_LOCK) != 0U);
        break;
    }
    case SYSCTL_SDFMTYPE:
    {
        lock =((HWREGH(DEVCFG_BASE + SYSCTL_O_SDFMTYPE) &
                SYSCTL_SDFMTYPE_LOCK) != 0U);
        break;
    }
    case SYSCTL_MEMMAPTYPE:
    {     
        lock =((HWREGH(DEVCFG_BASE + SYSCTL_O_MEMMAPTYPE) &
                SYSCTL_MEMMAPTYPE_LOCK) != 0U);
        break;
    }
    //
    //default case 
    //
    default: 
    {
        break;
    }
  }

  EDIS;
  
  return(lock);
}

//*****************************************************************************
//
// SysCtl_setSemOwner()
//
//*****************************************************************************
void
SysCtl_setSemOwner (SysCtl_CPUSel cpuInst)
{
  EALLOW;
  
  //
  // Configures which core should be given clock ownership
  // based on the user input.
  //
  if((uint16_t)cpuInst == 0U)
    {
      //
      //free the semaphore 
      //
      HWREG(CLKCFG_BASE + SYSCTL_O_CLKSEM) = ((HWREG(DEVCFG_BASE +
                                                       SYSCTL_O_CLKSEM) &
                                               ~(SYSCTL_CLKSEM_SEM_M)) |
                                                (SYSCTL_REG_KEY &
                                                 SYSCTL_CLKSEM_KEY_M));

      //
      //CPU1 acquires the semaphore
      //
      HWREG(CLKCFG_BASE + SYSCTL_O_CLKSEM) |= ((uint32_t)0x10U | (SYSCTL_REG_KEY &
                                                       SYSCTL_CLKSEM_KEY_M));
    }
  else
    {
      //
      //free the semaphore 
      //
      HWREG(CLKCFG_BASE + SYSCTL_O_CLKSEM) = ((HWREG(DEVCFG_BASE +
                                                       SYSCTL_O_CLKSEM) &
                                               ~(SYSCTL_CLKSEM_SEM_M)) |
                                                (SYSCTL_REG_KEY &
                                                 SYSCTL_CLKSEM_KEY_M));

      //
      //CPU2 acquires the semaphore
      //
      HWREG(CLKCFG_BASE + SYSCTL_O_CLKSEM) |= ((uint32_t)0x01U |(SYSCTL_REG_KEY &
                                                       SYSCTL_CLKSEM_KEY_M));
    }
  
  EDIS;
}

//*****************************************************************************
//
// SysCtl_lockClkConfig()
//
//*****************************************************************************
void
SysCtl_lockClkConfig(SysCtl_ClkRegSel registerName)
{
  uint16_t bitIndex;
  
  //
  // Decode the register variable.
  //
  bitIndex = ((uint16_t)registerName & SYSCTL_PERIPH_BIT_M) >>
              SYSCTL_PERIPH_BIT_S;

  //
  // Locks the particular clock configuration register
  //
  EALLOW;
  HWREG(CLKCFG_BASE + SYSCTL_O_CLKCFGLOCK1) |= ((uint32_t)1U <<
                                                bitIndex);
  EDIS;
}

//*****************************************************************************
//
// SysCtl_lockSysConfig()
//
//*****************************************************************************
void
SysCtl_lockSysConfig (SysCtl_CpuRegSel registerName)
{
  uint16_t regIndex;
  uint16_t bitIndex;
  
  //
  // Decode the register variable.
  //
  regIndex = (uint16_t)2U * ((uint16_t)registerName &
                            (uint16_t)SYSCTL_PERIPH_REG_M);
  bitIndex = ((uint16_t)registerName & SYSCTL_PERIPH_BIT_M) >>
              SYSCTL_PERIPH_BIT_S;

  //
  // Locks the particular System configuration register
  //
  EALLOW;
  HWREG(CPUSYS_BASE + SYSCTL_O_CPUSYSLOCK1 + regIndex) |= ((uint32_t)1U <<
                                                           bitIndex);
  EDIS;
}

//*****************************************************************************
//
// SysCtl_controlCMReset()
//
//*****************************************************************************
void
SysCtl_controlCMReset(SysCtl_CoreReset control)
{
  uint32_t clearvalue;
  
      if(control != 0x0U)
    {
      //
      // On matching key, write to the reset bits would be successful
      //
      EALLOW;
      HWREG(CMCONF_BASE + SYSCTL_O_CMRESCTL) |= (((uint32_t)1U)|
                                                  (SYSCTL_REG_KEY &
                                                   SYSCTL_CMRESCTL_KEY_M));
      //
      //Activate reset and wait until CM is put to reset.
      //
      while(SysCtl_isCMReset() == 0x1U)
      {
      }

      //
      // On matching key, write to the reset bits would be successful
      //
      clearvalue = HWREG(CMCONF_BASE + SYSCTL_O_CMRESCTL);
      clearvalue &= ~((uint32_t)1U);
      HWREG(CMCONF_BASE + SYSCTL_O_CMRESCTL) = (SYSCTL_REG_KEY &
                                                SYSCTL_CMRESCTL_KEY_M)| 
                                                clearvalue;
      EDIS;
    }
   else 
    { 
      //
      //Bring CM out of reset only when CM is in reset state
      //
      if(SysCtl_isCMReset() == 0x1U)
      {
      EALLOW;
      //
      // On matching key, write to the reset bits would be successful
      //
      clearvalue = HWREG(CMCONF_BASE + SYSCTL_O_CMRESCTL);
      clearvalue &= ~((uint32_t)1U);
      HWREG(CMCONF_BASE + SYSCTL_O_CMRESCTL) = (SYSCTL_REG_KEY &
                                                SYSCTL_CMRESCTL_KEY_M)| 
                                                clearvalue;
      EDIS;
      }
    }

}

//*****************************************************************************
//
// SysCtl_requestPeripheralClockStop()
//
//*****************************************************************************
void
SysCtl_requestPeripheralClockStop(SysCtl_PeripheralClkStopReq peripheral,
                                            uint16_t enable)
{   
    uint16_t bitIndex;
    uint32_t clearvalue;

    //
    // Decode the peripheral variable bits.
    //
    bitIndex = ((uint16_t)peripheral & SYSCTL_PERIPH_BIT_M) >>
                SYSCTL_PERIPH_BIT_S;


    //
    //Write will succeed only if a matching key value is written 
    //to the KEY field
    // Request to stop the clock
    //
    if(enable == 1U) //enable the peripheral clock Stop
    {
     HWREG(CPUSYS_BASE + SYSCTL_O_CLKSTOPREQ) |= (((uint32_t)1U << bitIndex)|
                                                   (SYSCTL_CLK_KEY &
                                                    SYSCTL_CLKSTOPREQ_KEY_M));
    }
    else //disable the peripheral clock Stop
    {
        clearvalue = HWREG(CPUSYS_BASE + SYSCTL_O_CLKSTOPREQ);
        clearvalue &= ~((uint32_t)1U << bitIndex);
        HWREG(CPUSYS_BASE + SYSCTL_O_CLKSTOPREQ) = (SYSCTL_CLK_KEY &
                                                   SYSCTL_CLKSTOPREQ_KEY_M) |
                                                   clearvalue;
    }
}

//*****************************************************************************
//
// SysCtl_controlPLL()
//
//*****************************************************************************
void
SysCtl_controlPLL(uint32_t source, uint16_t override)
{
 uint32_t clearvalue;
 
 //
 // Configure the input to the PLL based on if the input is override or not
 //
 EALLOW;
 if((override == SYSCTL_PLLTEST_OVERRIDE)||
    (override == SYSCTL_PLLTEST_OVERRIDE_AUXPLL)||
    (override == SYSCTL_PLLTEST_ALL))
  {
   //
   // On matching key, write to the PLL control bits would be successful
   //
   HWREG(CLKCFG_BASE + SYSCTL_O_PLLTEST) |= ((override | source)| 
                                            (SYSCTL_PLL_KEY &
                                             SYSCTL_PLLTEST_KEY_M));
  }
 else
  {
  //
  // On matching key, write to the PLL control bits would be successful
  //
  clearvalue = HWREG(CLKCFG_BASE + SYSCTL_O_PLLTEST);
  clearvalue &= ~(SYSCTL_PLLTEST_ALL);
  HWREG(CLKCFG_BASE + SYSCTL_O_PLLTEST) = (SYSCTL_PLL_KEY &
                                           SYSCTL_PLLTEST_KEY_M)| 
                                           clearvalue;
  }
 EDIS;
}

