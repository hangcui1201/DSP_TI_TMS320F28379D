//###########################################################################
//
// FILE:   i2c.c
//
// TITLE:  CM I2C driver.
//
//###########################################################################
// $TI Release:  $
// $Release Date:  $
// $Copyright: $
//###########################################################################

#include <stdbool.h>
#include <stdint.h>
#include "inc_cm/hw_i2c.h"
#include "inc_cm/hw_memmap.h"
#include "inc_cm/hw_types.h"
#include "debug.h"
#include "i2c.h"

//*****************************************************************************
//
// I2C_initMaster()
//
//*****************************************************************************

void
I2C_initMaster(uint32_t base, uint32_t i2cClk,
               bool fast)
{
    uint32_t sclFreq;
    uint32_t tPr;

    //
    // Check the arguments.
    //
    ASSERT(I2C_isBaseValid(base));

    //
    // Must enable the device before doing anything else.
    //
    I2C_enableMaster(base);

    //
    // Get the desired SCL speed.
    //
    if(fast == true)
    {
        sclFreq = I2C_SCL_FREQ_FAST_MODE;
    }
    else
    {
        sclFreq = I2C_SCL_FREQ_STD_MODE;
    }

    //
    // Compute the clock divider that achieves the fastest speed less than or
    // equal to the desired speed.  The numerator is biased to favor a larger
    // clock divider so that the resulting clock is always less than or equal
    // to the desired clock, never greater.
    // SCL_PERIOD = 2 X (1 + TPR) X ( SCL_LP + SCL_HP) X CLK_PRD
    //
    //SCL_PRD is the SCL line period (I2C clock). TPR is the Timer Period 
    //register value (range of 1 to 127).SCL_LP is the SCL Low period 
    //(fixed at 6). SCL_HP is the SCL High period (fixed at 4). 
    //CLK_PRD is the system clock period in ns.
    //
    
    tPr = ((i2cClk + (2U * 10U * sclFreq) - 1U) /
          (2U * 10U * sclFreq)) - 1U;
    HWREG(base + I2C_O_MTPR) = tPr;

    //
    // Check to see if this I2C peripheral is High-Speed enabled.  If yes, also
    // choose the fastest speed that is less than or equal to 3.4 Mbps.
    // ( SCL_LP + SCL_HP) fixed at 3
    //
    if((HWREG(base + I2C_O_PP) & I2C_PP_HS) == I2C_PP_HS)
    {
        tPr = ((i2cClk + (2U * 3U * I2C_SCL_FREQ_HS_MODE) - 1U) /
              (2U * 3U * I2C_SCL_FREQ_HS_MODE)) - 1U;
        HWREG(base + I2C_O_MTPR) = I2C_MTPR_HS | tPr;
    }
}

//*****************************************************************************
//
// I2C_setSlaveAddress()
//
//*****************************************************************************
void
I2C_setOwnSlaveAddress(uint32_t base, I2C_SlaveAddrmode addrNum,
                       uint8_t slaveAddr)
{
    //
    // Check the arguments.
    //
    ASSERT(I2C_isBaseValid(base));
    ASSERT(!(addrNum > 1U));
    ASSERT(!(slaveAddr & I2C_SA_A6_0_MASK));

    //
    // Determine which slave address is being set.
    //
    switch((uint8_t)addrNum)
    {
        //
        // Set up the primary slave address.
        //
        case I2C_SLAVE_ADDR_PRIMARY:
        {
            HWREG(base + I2C_O_SOAR) = slaveAddr;
            break;
        }

        //
        // Set up and enable the secondary slave address.
        //
        case I2C_SLAVE_ADDR_SECONDARY:
        {
            HWREG(base + I2C_O_SOAR2) = I2C_SOAR2_OAR2EN | slaveAddr;
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
}

//*****************************************************************************
//
// I2C_getMasterErr()
//
//*****************************************************************************
uint32_t
I2C_getMasterErr(uint32_t base)
{
    uint32_t err, ret;

    //
    // Check the arguments.
    //
    ASSERT(I2C_isBaseValid(base));

    //
    // Get the raw error state
    //
    err = HWREG(base + I2C_O_MCS);

    //
    // If the I2C master is busy, then all the other bit are invalid, and
    // don't have an error to report.
    //
    if((err & I2C_MCS_BUSY) == I2C_MCS_BUSY)
    {
        ret = I2C_MASTER_ERR_NONE;
    }

    //
    // Check for errors.
    //
    if((err & (I2C_MCS_ERROR | I2C_MCS_ARBLST))!= 0U)
    {
        ret = (err & (I2C_MCS_ARBLST | I2C_MCS_DATACK |
                      I2C_MCS_ADRACK | I2C_MCS_CLKTO));
    }
    else
    {
        ret = I2C_MASTER_ERR_NONE;
    }
    return(ret);
}
