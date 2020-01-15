/* DCLCLA.h - C2000 Digital Controller Library header file
 *
 * Copyright (C) 2019 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

#ifndef _C_DCLCLA_H
#define _C_DCLCLA_H

#ifdef __cplusplus
extern "C" {
#endif

//! \file           DCLCLA.h
//! \brief          Contains the public interface to the
//!                 Digital Controller Library CLA functions

#include "DCL.h"

//--- Linear PID controller ---------------------------------------------------

//! \brief          Defines the DCL_PID_CLA controller structure
//!
typedef volatile struct dcl_pid_cla {
    float32_t Kp;       //!< Proportional gain
    float32_t Ki;       //!< Integral gain
    float32_t Kd;       //!< Derivative gain
    float32_t Kr;       //!< Set point weight
    float32_t c1;       //!< D-term filter coefficient 1
    float32_t c2;       //!< D-term filter coefficient 2
    float32_t d2;       //!< D-term filter intermediate storage 1
    float32_t d3;       //!< D-term filter intermediate storage 2
    float32_t i10;      //!< I-term intermediate storage
    float32_t i14;      //!< Intermediate saturation storage
    float32_t Umax;     //!< Upper saturation limit
    float32_t Umin;     //!< Lower saturation limit
} DCL_PID_CLA;

//! \brief          Defines default values to initialize the DCL_PID structure
//!
#define PID_CLA_DEFAULTS {  1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, \
                            0.0f, 0.0f, 1.0f, -1.0f }

//! \brief          Executes an ideal form PID controller on the CLA
//! \param[in] p    Pointer to the DCL_PID_CLA structure
//! \param[in] rk   The controller set-point reference
//! \param[in] yk   The measured feedback value
//! \param[in] lk   External output clamp flag
//! \return         The control effort
//!
extern float32_t DCL_runPID_L1(DCL_PID_CLA *p, float32_t rk, float32_t yk, float32_t lk);

//! \brief          Executes a parallel form PID controller on the CLA
//! \param[in] p    Pointer to the DCL_PID_CLA structure
//! \param[in] rk   The controller set-point reference
//! \param[in] yk   The measured feedback value
//! \param[in] lk   External output clamp flag
//! \return         The control effort
//!
extern float32_t DCL_runPID_L2(DCL_PID_CLA *p, float32_t rk, float32_t yk, float32_t lk);


//--- Linear PI controller ----------------------------------------------------

//! \brief          Defines the DCL_PI_CLA controller structure
//!
typedef volatile struct dcl_pi_cla {
    float32_t Kp;       //!< Proportional gain
    float32_t Ki;       //!< Integral gain
    float32_t i10;      //!< I storage
    float32_t Umax;     //!< Upper control saturation limit
    float32_t Umin;     //!< Lower control saturation limit
    float32_t i6;       //!< Saturation storage
    float32_t i11;      //!< I storage
    float32_t Imax;     //!< Upper integrator saturation limit
    float32_t Imin;     //!< Lower integrator saturation limit
} DCL_PI_CLA;

//! \brief  Defines default values to initialize the PI_CLA structure
//!
#define PI_CLA_DEFAULTS { 1.0f, 0.0f, 0.0f, 1.0f, -1.0f, 1.0f, 1.0f, -1.0f }

//! \brief          Executes a series form PI controller on the CLA
//! \param[in] p    Pointer to the DCL_PI_CLA structure
//! \param[in] rk   The controller set-point reference
//! \param[in] yk   The measured feedback value
//! \return         The control effort
//!
extern float32_t DCL_runPI_L1(DCL_PI_CLA *p, float32_t rk, float32_t yk);

//! \brief          Executes a parallel form PI controller on the CLA
//! \param[in] p    Pointer to the DCL_PI_CLA structure
//! \param[in] rk   The controller set-point reference
//! \param[in] yk   The measured feedback value
//! \return         The control effort
//!
extern float32_t DCL_runPI_L2(DCL_PI_CLA *p, float32_t rk, float32_t yk);

//! \brief 			Executes an inline series form PI controller on the CLA
//! 				Implemented as inline C function
//! \param[in] p 	Pointer to the DCL_PI structure
//! \param[in] rk 	The controller set-point reference
//! \param[in] yk 	The measured feedback value
//! \return 		The control effort
//!
static inline float32_t DCL_runPI_L3(DCL_PI_CLA *p, float32_t rk, float32_t yk)
{
    float32_t v2, v4, v5, v9;

	v2 = p->Kp * (rk - yk);
	v4 = p->i10 + (p->Ki * p->i6 * v2);
	v5 = v2 + v4;
	v9 = (v5 > p->Umax) ? p->Umax : v5;
	v9 = (v9 < p->Umin) ? p->Umin : v9;
	p->i10 = v4;
	p->i6 = (v5 == v9) ? 1.0f : 0.0f;

	return(v9);
}

//! \brief 			Executes an parallel form PI controller on the CLA
//! 				Implemented as inline C function
//! \param[in] p 	Pointer to the DCL_PI structure
//! \param[in] rk 	The controller set-point reference
//! \param[in] yk 	The measured feedback value
//! \return 		The control effort
//!
static inline float32_t DCL_runPI_L4(DCL_PI_CLA *p, float32_t rk, float32_t yk)
{
	float32_t v1, v2, v4, v5, v9;

	v1 = rk - yk;
	v2 = p->Kp * v1;
	v4 = p->i10 + (v1 * p->Ki * p->i6);
	p->i10 = v4;
	v5 = v2 + v4;
	v9 = (v5 > p->Umax) ? p->Umax : v5;
	v9 = (v9 < p->Umin) ? p->Umin : v9;
	p->i6 = (v5 == v9) ? 1.0f : 0.0f;

	return(v9);
}

//! \brief          Executes a series form PI controller with Tustin integrator
//!                 on the CLA.
//! \param[in] p    Pointer to the DCL_PI_CLA structure
//! \param[in] rk   The controller set-point reference
//! \param[in] yk   The measured feedback value
//! \return         The control effort
//!
static inline float32_t DCL_runPI_L5(DCL_PI_CLA *p, float32_t rk, float32_t yk)
{
    float32_t v2, v4, v5, v8, v9;

    v2 = (rk - yk) * p->Kp;
    v8 = v2 * p->Ki * p->i6;
    v4 = v8 + p->i11 + p->i10;
    v5 = v2 + v4;
    p->i10 = v4;
    p->i11 = v8;
    v9 = (v5 > p->Umax) ? p->Umax : v5;
    v9 = (v9 < p->Umin) ? p->Umin : v9;
    p->i6 = (v5 == v9) ? 1.0f : 0.0f;

    return(v9);
}



//--- Direct Form 1 - 1st order -----------------------------------------------

//! \brief          Defines the DCL_DF11 controller structure
//!
typedef volatile struct dcl_df11_cla {
    float32_t b0;   //!< b0
    float32_t b1;   //!< b1
    float32_t a1;   //!< a1
    float32_t d1;   //!< e(k-1)
    float32_t d2;   //!< u(k-1)
} DCL_DF11_CLA;

//! \brief          Defines default values to initialize the DCL_DF11_CLA structure
//!
#define DF11_CLA_DEFAULTS { 0.5f, 0.5f, 1.0f, 0.0f, 0.0f }

//! \brief          Executes a 1st order Direct Form 1 controller on the CLA
//! \param[in] p    Pointer to the DCL_DF11_CLA controller structure
//! \param[in] ek   The servo error
//! \return         The control effort
//!
extern float32_t DCL_runDF11_L1(DCL_DF11_CLA *p, float32_t ek);


//--- Direct Form 1 - 3rd order -----------------------------------------------

//! \brief          Defines the DCL_DF13_CLA controller structure
//!
typedef volatile struct dcl_df13_cla {
    // coefficients
    float32_t b0;   //!< b0
    float32_t b1;   //!< b1
    float32_t b2;   //!< b2
    float32_t b3;   //!< b3
    float32_t a0;   //!< a0
    float32_t a1;   //!< a1
    float32_t a2;   //!< a2
    float32_t a3;   //!< a3

    //data
    float32_t d0;   //!< e(k)
    float32_t d1;   //!< e(k-1)
    float32_t d2;   //!< e(k-2)
    float32_t d3;   //!< e(k-3)
    float32_t d4;   //!< u(k)
    float32_t d5;   //!< u(k-1)
    float32_t d6;   //!< u(k-2)
    float32_t d7;   //!< u(k-3)
} DCL_DF13_CLA;

//! \brief          Defines default values to initialize the DCL_DF13_CLA structure
//!
#define DF13_CLA_DEFAULTS { 0.25f, 0.25f, 0.25f, 0.25f, 0.0f, 0.0f, 0.0f, 0.0f, \
                        0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f }

//! \brief          Executes a full 3rd order Direct Form 1 controller on the CLA
//! \param[in] p    Pointer to the DCL_DF13_CLA controller structure
//! \param[in] ek   The servo error
//! \return         The control effort
//!
extern float32_t DCL_runDF13_L1(DCL_DF13_CLA *p, float32_t ek);

//! \brief          Executes an immediate 3rd order Direct Form 1 controller on the CLA
//! \param[in] p    Pointer to the DCL_DF13_CLA controller structure
//! \param[in] ek   The servo error
//! \param[in] vk   The partial pre-computed control effort
//! \return         The control effort
//!
extern float32_t DCL_runDF13_L2(DCL_DF13_CLA *p, float32_t ek, float32_t vk);

//! \brief          Executes a partial pre-computed 3rd order Direct Form 1 controller on the CLA
//! \param[in] p    Pointer to the DCL_DF13_CLA controller structure
//! \param[in] ek   The servo error
//! \param[in] uk   The controller output in the previous sample interval
//! \return         The control effort
//!
extern float32_t DCL_runDF13_L3(DCL_DF13_CLA *p, float32_t ek, float32_t uk);


//--- Direct Form 2 - 2nd order -----------------------------------------------

//! \brief          Defines the DCL_DF22_CLA controller structure
//!
typedef volatile struct dcl_df22_cla {
    float32_t b0;   //!< b0
    float32_t b1;   //!< b1
    float32_t b2;   //!< b2
    float32_t a1;   //!< a1
    float32_t a2;   //!< a2
    float32_t x1;   //!< x1
    float32_t x2;   //!< x2
} DCL_DF22_CLA;

//! \brief          Defines default values to initialize the DCL_DF22_CLA structure
//!
#define DF22_CLA_DEFAULTS { 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f }

//! \brief          Executes a full 2nd order Direct Form 2 controller on the CLA
//! \param[in] p    Pointer to the DCL_DF22_CLA controller structure
//! \param[in] ek   The servo error
//! \return         The control effort
//!
extern float32_t DCL_runDF22_L1(DCL_DF22_CLA *p, float32_t ek);

//! \brief          Executes an immediate 2nd order Direct Form 2 controller on the CLA
//! \param[in] p    Pointer to the DCL_DF22_CLA controller structure
//! \param[in] ek   The servo error
//! \return         The control effort
//!
extern float32_t DCL_runDF22_L2(DCL_DF22_CLA *p, float32_t ek);

//! \brief          Executes a partial pre-computed 2nd order Direct Form 2 controller on the CLA
//! \param[in] p    Pointer to the DCL_DF22_CLA controller structure
//! \param[in] ek   The servo error
//! \param[in] uk   The controller output in the previous sample interval
//!
extern void DCL_runDF22_L3(DCL_DF22_CLA *p, float32_t ek, float32_t uk);

//! \brief 			Executes a full 2nd order Direct Form 2 controller on the CLA
//! 				Implemented as inline C function
//! \param[in] p 	Pointer to the DCL_DF22 controller structure
//! \param[in] ek 	The servo error
//! \return 		The control effort
//!
static inline float32_t DCL_runDF22_L4(DCL_DF22_CLA *p, float32_t ek)
{
	float32_t v7;

	v7 = (ek * p->b0) + p->x1;
	p->x1 = (ek * p->b1) + p->x2 - (v7 * p->a1);
	p->x2 = (ek * p->b2) - (v7 * p->a2);

	return(v7);
}


//--- Direct Form 2 - 3rd order -----------------------------------------------

//! \brief          Defines the DCL_DF23_CLA controller structure
//!
typedef volatile struct dcl_df23_cla {
    float32_t b0;   //!< b0
    float32_t b1;   //!< b1
    float32_t b2;   //!< b2
    float32_t b3;   //!< b3
    float32_t a1;   //!< a1
    float32_t a2;   //!< a2
    float32_t a3;   //!< a3
    float32_t x1;   //!< x1
    float32_t x2;   //!< x2
    float32_t x3;   //!< x3
} DCL_DF23_CLA;

//! \brief          Defines default values to initialize the DCL_DF23_CLA structure
//!
#define DF23_CLA_DEFAULTS { 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f }

//! \brief          Executes a full 3rd order Direct Form 2 controller on the CLA
//! \param[in] p    Pointer to the DCL_DF23_CLA controller structure
//! \param[in] ek   The servo error
//! \return         The control effort
//!
extern float32_t DCL_runDF23_L1(DCL_DF23_CLA *p, float32_t ek);

//! \brief          Executes an immediate 3rd order Direct Form 2 controller on the CLA
//! \param[in] p    Pointer to the DCL_DF23_CLA controller structure
//! \param[in] ek   The servo error
//! \return         The control effort
//!
extern float32_t DCL_runDF23_L2(DCL_DF23_CLA *p, float32_t ek);

//! \brief          Executes a partial pre-computed 2nd order Direct Form 2 controller on the CLA
//! \param[in] p    Pointer to the DCL_DF23_CLA controller structure
//! \param[in] ek   The servo error
//! \param[in] uk   The controller output in the previous sample interval
//!
extern void DCL_runDF23_L3(DCL_DF23_CLA *p, float32_t ek, float32_t uk);


//--- Direct Form 2 - clamp ---------------------------------------------------

//! \brief          Saturates a control variable and returns 1.0f if either limit is exceeded
//!
//! \details        Can be used to saturate a pre-computed Direct Form 2 controller.
//!                 If the immediate result is in range it can be used, otherwise
//!                 it can be clamped and the next partial pre-computation skipped.
//!                 An example of use with a pre-computed DF22 controller follows:
//!
//! \code
//! uk = DCL_runDF22_L2(&arma2, rk);                // immediate result from pre-computed controller
//! f = DCL_runClamp_L1(&uk, 1.0f, -1.0f);          // clamp immediate result to +/-1.0
//! // ...use uk here...
//! if (0.5f > f)                                   // if immediate result is in range...
//! {
//!     DCL_runDF22_L3(&arma2, rk, uk);             // ...pre-compute the next partial result
//! }
//! \endcode
//!
//! \param[in] data The address of the data variable
//! \param[in] Umax The upper limit
//! \param[in] Umin The lower limit
//! \return         Returns 0.0f if (Umin < data < Umax), else 1.0f
//!
extern float32_t DCL_runClamp_L1(float32_t *data, float32_t Umax, float32_t Umin);

//----------------------------------------------------------------------------

#ifdef __cplusplus
}
#endif // extern "C"

#endif // _C_DCLCLA_H

/* end of file */
