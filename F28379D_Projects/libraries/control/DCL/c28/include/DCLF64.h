/* DCLF64.h - Digital Control Library (64-bit floating point)
 *
 * Copyright (C) 2019 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED 
*/

#ifndef _C_DCLF64_H
#define _C_DCLF64_H

#ifdef __cplusplus
extern "C" {
#endif

//! \file   		DCLF64.h
//! \brief  		Contains the public interface to the
//!         		64-bit PID controller functions

#include "DCL.h"

//--- PIDF64 controller -----------------------------------------------

//! \brief          Defines the shadow PIDF64 controller structure
//!
typedef volatile struct dcl_pidf64_sps {
    float64_t Kp;       //!< Proportional gain
    float64_t Ki;       //!< Integral gain
    float64_t Kd;       //!< Derivative gain
    float64_t Kr;       //!< Set point weight
    float64_t c1;       //!< D-term filter coefficient 1
    float64_t c2;       //!< D-term filter coefficient 2
    float64_t Umax;     //!< Upper saturation limit
    float64_t Umin;     //!< Lower saturation limit
} DCL_PIDF64_SPS;

//! \brief          Defines default values to initialize the DCL_PIDF64 shadow structure
//!
#define PIDF64_SPS_DEFAULTS { 1.0L, 0.0L, 0.0L, 1.0L, 1.0L, 0.0L, 1.0L, -1.0L }

//! \brief          Defines the active PIDF64 controller structure
//!
typedef volatile struct dcl_pidf64 {
    // active parameters
    float64_t Kp;       //!< Proportional gain
    float64_t Ki;       //!< Integral gain
    float64_t Kd;       //!< Derivative gain
    float64_t Kr;       //!< Set point weight
    float64_t c1;       //!< D-term filter coefficient 1
    float64_t c2;       //!< D-term filter coefficient 2
    float64_t d2;       //!< D-term filter intermediate storage 1
    float64_t d3;       //!< D-term filter intermediate storage 2
    float64_t i10;      //!< I-term intermediate storage
    float64_t i14;      //!< Intermediate saturation storage
    float64_t i16;      //!< Spare
    float64_t Umax;     //!< Upper saturation limit
    float64_t Umin;     //!< Lower saturation limit
    DCL_PIDF64_SPS *sps;  //!< Pointer to shadow parameter set
    DCL_CSS *css;       //!< Pointer to common support structure
} DCL_PIDF64;

//! \brief          Defines default values to initialize the DCL_PIDF64 active structure
//!
#define PIDF64_DEFAULTS {  1.0L, 0.0L, 0.0L, 1.0L, 0.0L, 0.0L, 0.0L, 0.0L, \
                           0.0L, 0.0L, 0.0L, 1.0L, -1.0L, NULL_ADDR, NULL_ADDR }

//! \brief          Resets the PIDF64 internal storage data
//! \param[in] p    Pointer to the DCL_PIDF64 structure
//! \return         None
//!
static inline void DCL_resetPIDF64(DCL_PIDF64 *p)
{
    uint16_t v;

    v = DCL_DISABLE_INTS;
    p->d2 = p->d3 = p->i10 = 0.0L;
    p->i14 = 1.0L;
    p->css->err = ERR_NONE;
    DCL_RESTORE_INTS(v);
}

//! \brief          Copies shadow controller parameters to the active
//!                 DCL_PIDF64 structure while global interrupts disabled
//! \param[in] p    Pointer to the DCL_PIDF64 controller structure
//! \return         None
//!
static inline void DCL_updatePIDF64(DCL_PIDF64 *p)
{
    uint16_t v;

    if (p->css->sts == STS_UPDATE_PENDING)
     {
         v = DCL_DISABLE_INTS;
         p->Kp = p->sps->Kp;
         p->Ki = p->sps->Ki;
         p->Kd = p->sps->Kd;
         p->Kr = p->sps->Kr;
         p->c1 = p->sps->c1;
         p->c2 = p->sps->c2;
         p->Umax = p->sps->Umax;
         p->Umin = p->sps->Umin;
         DCL_RESTORE_INTS(v);
         DCL_CLEAR_UPDATE_REQUEST(p);
     }
}

//! \brief          Loads the derivative path filter shadow coefficients
//!                 Note: changes will not become effective until update called
//! \param[in] p    Pointer to the DCL_PIDF64 structure
//! \param[in] fc   The desired filter bandwidth in Hz
//! \param[in] T    The sample period in seconds
//! \return         None
//!
static inline void DCL_setPIDF64filterBW(DCL_PIDF64 *p, float64_t fc)
{
    float64_t tau;

#ifdef DCL_ERROR_HANDLING_ENABLED
    p->css->err |= ((fc >= 1.0L / (2.0L * p->css->T)) || (fc <= 0.0L)) ? ERR_PARAM_RANGE : ERR_NONE;
    if (p->css->err)
    {
        DCL_GET_ERROR_LOC(p->css);
        DCL_RUN_ERROR_HANDLER(p->css);
    }
#endif

    tau = 1.0L / (2.0L * CONST_PI_64 * fc);
    p->sps->c1 = 2.0L / (p->css->T + 2.0L * tau);
    p->sps->c2 = (p->css->T - 2.0L * tau) / (p->css->T + 2.0L * tau);
}

//! \brief          Loads the PIDF64 derivative path filter active coefficients
//!                 Note: new coefficients take effect immediately.  SPS &
//!                 CSS contents are unaffected.
//! \param[in] p    Pointer to the DCL_PIDF64 structure
//! \param[in] fc   The desired filter bandwidth in Hz
//! \param[in] T    The controller update rate in seconds
//! \return         None
//!
static inline void DCL_setActivePIDF64filterBW(DCL_PIDF64 *p, float64_t fc, float64_t T)
{
    float64_t tau;

#ifdef DCL_ERROR_HANDLING_ENABLED
    p->css->err |= ((fc >= 1.0L / (2.0L * T)) || (fc <= 0.0L)) ? ERR_PARAM_RANGE : ERR_NONE;
    if (p->css->err)
    {
        DCL_GET_ERROR_LOC(p->css);
        DCL_RUN_ERROR_HANDLER(p->css);
    }
#endif

    tau = 1.0L / (2.0L * CONST_PI_64 * fc);
    p->c1 = 2.0L / (T + 2.0L * tau);
    p->c2 = (T - 2.0L * tau) / (T + 2.0L * tau);
}

//! \brief          Returns the active derivative path filter bandwidth in Hz
//! \param[in] p    Pointer to the DCL_PIDF64 structure
//! \return         The filter bandwidth in Hz
//!
static inline float64_t DCL_getPIDF64filterBW(DCL_PIDF64 *p)
{
    float64_t tau;

    tau = ((2.0L - p->c1 * p->css->T) / (2.0L * p->c1));
    return(1.0L / (2.0L * CONST_PI_64 * tau));
}

//! \brief          Executes an inline series form PIDF64 controller
//! \param[in] p    Pointer to the DCL_PIDF64 structure
//! \param[in] rk   The controller set-point reference
//! \param[in] yk   The measured feedback value
//! \param[in] lk   External output clamp flag
//! \return         The control effort
//!
static inline float64_t DCL_runPIDF64_S1(DCL_PIDF64 *p, float64_t rk, float64_t yk, float64_t lk)
{
    float64_t v1, v4, v5, v8, v9, v10, v12;

#ifdef DCL_ERROR_HANDLING_ENABLED
    p->css->err |= (p->css->sts & STS_CONTROLLER_RUNNING) ? ERR_CONTROLLER : ERR_NONE;
    if (p->css->err)
    {
        DCL_GET_ERROR_LOC(p->css);
        DCL_RUN_ERROR_HANDLER(p->css);
    }
    DCL_CONTROLLER_BEGIN(p);
#endif

    v5 = (p->Kr * rk) - yk;
    v8 = ((rk - yk) * p->Ki * p->Kp * p->i14) + p->i10;
    p->i10 = v8;
    v1 = yk * p->Kd * p->c1;
    v4 = v1 - p->d2 - p->d3;
    p->d2 = v1;
    p->d3 = v4 * p->c2;
    v9 = ((v5 - v4) * p->Kp) + v8;
    v10 = (v9 > p->Umax) ? p->Umax : v9;
    v10 = (v10 < p->Umin) ? p->Umin : v10;
    v12 = (v10 == v9) ? 1.0 : 0.0;
    p->i14 = v12 * lk;

#ifdef DCL_TESTPOINTS_ENABLED
    p->css->tpt = (float32_t) v5;
#endif

#ifdef DCL_ERROR_HANDLING_ENABLED
    DCL_CONTROLLER_END(p);
#endif

    return(v10);
}

//----------------------------------------------------------------------------

#ifdef __cplusplus
}
#endif // extern "C"

#endif // _C_DCLF64_H

/* end of file */
