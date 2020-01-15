/* DCL_MLOG.h - Multi-channel data logger
 *
 * Copyright (C) 2019 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
*/

#ifndef _C_DCL_MLOG_H
#define _C_DCL_MLOG_H

#ifdef __cplusplus
extern "C" {
#endif

//! \file           DCL_MLOG.h
//! \brief          Contains the public interface to the multi-channel data log module (MLOG)
//!

#include <stdint.h>
#include "DCL_fdlog.h"

//! \brief          Defines the number of MLOG channels
//!
#define MLOG_CHANS   4

//! \brief          Defines the MLOG structure
//!
typedef volatile struct dcl_mlog {
    FDLOG captFrame[MLOG_CHANS];    //!< Capture data frames
    float32_t *data[MLOG_CHANS];    //!< Data channel pointers
    float32_t trigMax;              //!< Upper trigger threshold
    float32_t trigMin;              //!< Lower trigger threshold
    uint16_t tScale;                //!< Number of samples per log write
    uint16_t sCount;                //!< Sample counter
    uint16_t mode;                  //!< Operating mode
} MLOG;

//! \brief          Defines default values to initialise the MLOG structure
//!                 Note: modify to match number of channels
//!
#define MLOG_DEFAULTS { { FDLOG_DEFAULTS, FDLOG_DEFAULTS, FDLOG_DEFAULTS, FDLOG_DEFAULTS }, \
                        { 0x00000000, 0x00000000, 0x00000000, 0x00000000 }, \
                          0.1, -0.1, 1, 1, 0 }

//! \brief          Enumerated MLOG operating modes
//!
typedef enum
{
    MLOG_invalid = 0,   //!< Buffer pointers not initialised
    MLOG_idle,          //!< Memory initialised but module not armed
    MLOG_armed,         //!< Armed: capturing monitor frame data and waiting for trigger
    MLOG_capture,       //!< Triggered: logging data into capture frame
    MLOG_complete,      //!< Full data frame captured and available for read-out
    MLOG_numStates      //!< Number of MLOG states
} MLOG_states;


//! \brief          Initializes the MLOG module
//! \param[in] q    The MLOG structure
//! \param[in] addr The start address of the memory block
//! \param[in] size The size of the memory block in 32-bit words
//! \param[in] tmin The upper trigger threshold
//! \param[in] tmax The lower trigger threshold
//!
static inline void DCL_initMLOG(MLOG *q, float32_t *addr, uint16_t size, float32_t tmax, float32_t tmin, uint16_t div)
{
    int i;

    for (i=0; i<MLOG_CHANS; i++)
    {
        // assign and clear capture frame, and initialize index to end of lead frame
        DCL_initLog(&(q->captFrame[i]), (addr + i*size), size);
        DCL_clearLog(&(q->captFrame[i]));
    }

    q->trigMax = tmax;
    q->trigMin = tmin;
    q->tScale = div;
    q->sCount = div;
    q->mode = MLOG_idle;
}


//! \brief          Resets the MLOG module: clears all frame buffers and sets idle mode
//! \param[in] q    The MLOG structure
//! \return         The operating mode
//!
static inline void DCL_resetMLOG(MLOG *q)
{
    int i;

    for (i=0; i<MLOG_CHANS; i++)
    {
        DCL_clearLog(&(q->captFrame[i]));
    }

    q->mode = MLOG_idle;
}


//! \brief          Changes the MLOG mode to "MLOG_armed".  Only valid if current operating mode is "MLOG_idle"
//! \param[in] q    The MLOG structure
//! \return         The operating mode
//!
static inline uint16_t DCL_armMLOG(MLOG *q)
{
    q->mode = (q->mode == MLOG_idle) ? MLOG_armed : MLOG_idle;
    return(q->mode);
}


//! \brief          Runs the MLOG module
//! \param[in] q    The MLOG structure
//! \return         The operating mode
//!
static inline uint16_t DCL_runMLOG(MLOG *q)
{
    int i;

    // skip sample unless counter reaches zero
    if (--(q->sCount) == 0)
    {
        switch(q->mode)
        {
        // MLOG not initialised
        case MLOG_invalid:
            break;

        // idle: do nothing
        case MLOG_idle:
            break;

        // armed: ready to begin capturing when either trigger threshold is crossed
        case MLOG_armed:
            // check for trigger condition
            if ((*(q->data[0]) > q->trigMax) || (*(q->data[0]) < q->trigMin))
            {
                for (i=0; i<MLOG_CHANS; i++)
                {
                    DCL_fwriteLog(&(q->captFrame[i]), *(q->data[i]));
                }
                q->mode = MLOG_capture;
            }
            break;

        // capture mode: acquiring data
        case MLOG_capture:
            // check for full capture frame
            if (q->captFrame[0].dptr == q->captFrame[0].fptr)
            {
                q->mode = MLOG_complete;
            }
            else
            {
                // log data channels
                for (i=0; i<MLOG_CHANS; i++)
                {
                    DCL_fwriteLog(&(q->captFrame[i]), *(q->data[i]));
                }
            }
            break;

        // complete: do nothing - results available in capture buffer
        case MLOG_complete:
            break;

        default:
            ;
        }

        q->sCount = q->tScale;
    }

    return(q->mode);
}

//----------------------------------------------------------------------------

#ifdef __cplusplus
}
#endif // extern "C"

#endif // _C_DCL_MLOG_H

/* end of file */
