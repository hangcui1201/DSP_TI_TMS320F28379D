#ifndef _DSP_ERROR_H_
#define _DSP_ERROR_H_
//#############################################################################
//! \file   reference/C/include/$FILENAME$
//! \brief  DSP Error Header File
//! \author Vishal Coelho 
//! \date   14-Sep-2015
//! 
//
//  Group:            C2000
//  Target Family:    $DEVICE$
//
//#############################################################################
// $TI Release: $
// $Release Date: $
// $Copyright: $
//#############################################################################


//*****************************************************************************
// the includes
//*****************************************************************************
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include "dsp.h"
//!
//! \defgroup DSP_ERROR Error Metrics

//!
//! \ingroup DSP_ERROR
//@{

#ifdef __cplusplus
extern "C" {
#endif
//*****************************************************************************
// typedefs
//*****************************************************************************

//! \brief The Error Structure
//!
typedef struct _error_Obj_{
    fsize_t *testPtr;  //!< Pointer to the test vector
    fsize_t *goldPtr;  //!< Pointer to the Reference vector
    fsize_t *errPtr;   //!< Pointer to the error buffer
    errorType et;      //!< The error type enumeration
    fsize_t tolerance; //!< Error Tolerance
    fsize_t maxErr;    //!< The maximum error
    uint16_t maxErrPos;//!< The index into the error buffer (for max error)
    fsize_t minErr;    //!< The minimum error
    uint16_t minErrPos;//!< The index into the error buffer (for min error)
    fsize_t avgErr;    //!< The average error
    fsize_t spanErr;   //!< Difference between the min and max erro
    int16_t size;      //!< The size of the buffers
    uint16_t pass;     //!< Number of data points within the error tolerance
    uint16_t fail;     //!< Number of data points outside the error tolerance
}error;

//! \brief The Handle to the Error Object
//!
typedef error *errorHandle;

//*****************************************************************************
// 'inline' function
//*****************************************************************************
//! \brief Set the Error Object Test Pointer
//! \param[in] eh , handle to the 'error' object
//! \param[in] tp , pointer to the test array
//!
static inline void error_setTestPtr(errorHandle eh, const fsize_t *tp)
{
    eh->testPtr = (fsize_t *)tp;
}

//! \brief Get the Error Object Test Pointer
//! \param[in] eh , handle to the 'error' object
//! \return pointer to the test array
//!
static inline fsize_t* error_getTestPtr(errorHandle eh)
{
    return(eh->testPtr);
}

//! \brief Set the Error Object Gold Pointer
//! \param[in] eh , handle to the 'error' object
//! \param[in] tp , pointer to the gold array
//!
static inline void error_setGoldPtr(errorHandle eh, const fsize_t *gp)
{
    eh->goldPtr = (fsize_t *)gp;
}

//! \brief Get the Error Object Gold Pointer
//! \param[in] eh , handle to the 'error' object
//! \return pointer to the gold array
//!
static inline fsize_t* error_getGoldPtr(errorHandle eh)
{
    return(eh->goldPtr);
}

//! \brief Set the Error Object Error Pointer
//! \param[in] eh , handle to the 'error' object
//! \param[in] ep , pointer to the gold array
//!
static inline void error_setErrPtr(errorHandle eh, const fsize_t *ep)
{
    eh->errPtr = (fsize_t *)ep;
}

//! \brief Get the Error Object Error Pointer
//! \param[in] eh , handle to the 'error' object
//! \return pointer to the error array
//!
static inline fsize_t* error_getErrPtr(errorHandle eh)
{
    return(eh->errPtr);
}

//! \brief Set the Error Object Error Type
//! \param[in] eh , handle to the 'error' object
//! \param[in] et , Error Type
//!
static inline void error_setErrType(errorHandle eh, const errorType et)
{
    eh->et = (errorType)et;
}

//! \brief Get the Error Object Error Type
//! \param[in] eh , handle to the 'error' object
//! \return Error Type
//!
static inline errorType error_getErrType(errorHandle eh)
{
    return(eh->et);
}

//! \brief Set the Error Object Error Tolerance
//! \param[in] eh , handle to the 'error' object
//! \param[in] tolerance , Error Tolerance
//!
static inline void error_setTolerance(errorHandle eh, const fsize_t tolerance)
{
    eh->tolerance = (fsize_t)tolerance;
}

//! \brief Get the Error Object Error Tolerance
//! \param[in] eh , handle to the 'error' object
//! \return Error Tolerance
//!
static inline fsize_t error_getTolerance(errorHandle eh)
{
    return(eh->tolerance);
}

//! \brief Set the Error Object Max Error
//! \param[in] eh , handle to the 'error' object
//! \param[in] maxErr , Maximum Error
//!
static inline void error_setMaxErr(errorHandle eh, const fsize_t maxErr)
{
    eh->maxErr = (fsize_t)maxErr;
}

//! \brief Get the Error Object Max Error
//! \param[in] eh , handle to the 'error' object
//! \return Maximum Error
//!
static inline fsize_t error_getMaxErr(errorHandle eh)
{
    return(eh->maxErr);
}

//! \brief Set the Error Object Max Error Position
//! \param[in] eh , handle to the 'error' object
//! \param[in] maxErrPos , Maximum Error Position
//!
static inline void error_setMaxErrPos(errorHandle eh, const uint16_t maxErrPos)
{
    eh->maxErrPos = (int16_t)maxErrPos;
}

//! \brief Get the Error Object Max Error Position
//! \param[in] eh , handle to the 'error' object
//! \return Maximum Error Position
//!
static inline uint16_t error_getMaxErrPos(errorHandle eh)
{
    return(eh->maxErrPos);
}

//! \brief Set the Error Object Min Error
//! \param[in] eh , handle to the 'error' object
//! \param[in] minErr , Minimum Error Position
//!
static inline void error_setMinErr(errorHandle eh, const fsize_t minErr)
{
    eh->minErr = (fsize_t)minErr;
}

//! \brief Get the Error Object Min Error
//! \param[in] eh , handle to the 'error' object
//! \return Minimum Error
//!
static inline fsize_t error_getMinErr(errorHandle eh)
{
    return(eh->minErr);
}

//! \brief Set the Error Object Min Error Position
//! \param[in] eh , handle to the 'error' object
//! \param[in] minErrPos , Minimum Error Position
//!
static inline void error_setMinErrPos(errorHandle eh, const uint16_t minErrPos)
{
    eh->minErrPos = (int16_t)minErrPos;
}

//! \brief Get the Error Object Min Error Position
//! \param[in] eh , handle to the 'error' object
//! \return Minimum Error Position
//!
static inline uint16_t error_getMinErrPos(errorHandle eh)
{
    return(eh->minErrPos);
}

//! \brief Set the Error Object Avg Error
//! \param[in] eh , handle to the 'error' object
//! \param[in] avgErr , Average Error
//!
static inline void error_setAvgErr(errorHandle eh, const fsize_t avgErr)
{
    eh->avgErr = (fsize_t)avgErr;
}

//! \brief Get the Error Object Avg Error
//! \param[in] eh , handle to the 'error' object
//! \return Average Error
//!
static inline fsize_t error_getAvgErr(errorHandle eh)
{
    return(eh->avgErr);
}

//! \brief Set the Error Object Span Error
//! \param[in] eh , handle to the 'error' object
//! \param[in] spanErr , Error Span
//!
static inline void error_setSpanErr(errorHandle eh, const fsize_t spanErr)
{
    eh->spanErr = (fsize_t)spanErr;
}

//! \brief Get the Error Object error span
//! \param[in] eh , handle to the 'error' object
//! \return Error Span (difference between man and min error)
//!
static inline fsize_t error_getSpanErr(errorHandle eh)
{
    return(eh->spanErr);
}

//! \brief Set the Error Object Array Size
//! \param[in] eh , handle to the 'error' object
//! \param[in] sz , size of the three arrays (test, gold, err)
//!
static inline void error_setSize(errorHandle eh, const int16_t sz)
{
    eh->size = (int16_t)sz;
}

//! \brief Get the Error Object Array Size
//! \param[in] eh , handle to the 'error' object
//! \return size of the three arrays (test, gold, err)
//!
static inline int16_t error_getSize(errorHandle eh)
{
    return(eh->size);
}

//! \brief Reset the Error Object Pass Count
//! \param[in] eh , handle to the 'error' object
//! \param[in] pc , pass count
static inline void error_setPass(errorHandle eh, const uint16_t pc)
{
    eh->pass = (uint16_t)pc;
}

//! \brief Get the Error Object Pass Count
//! \param[in] eh , handle to the 'error' object
//! \return the pass count
static inline uint16_t error_getPass(errorHandle eh)
{
    return(eh->pass);
}

//! \brief Reset the Error Object Fail Count
//! \param[in] eh , handle to the 'error' object
//! \param[in] fc , fail count
static inline void error_setFail(errorHandle eh, const uint16_t fc)
{
    eh->fail = (uint16_t)fc;
}


//! \brief Get the Error Object Fail Count
//! \param[in] eh , handle to the 'error' object
//! \return the fail count
static inline uint16_t error_getFail(errorHandle eh)
{
    return(eh->pass);
}

//*****************************************************************************
// 'extern' function prototypes
//*****************************************************************************
//! \brief The Error Function
//! \param[in] eh , Handle to the Error Object
//!
//! This function will calculate the error (the type is given in the object) 
//! between the test and gold (reference) arrays.
//!
//! \return None
extern void DSP_error(errorHandle eh);

#ifdef __cplusplus
}
#endif // extern "C"
//@}  // ingroup

#endif // end of _DSP_ASSERT_H_ definition
