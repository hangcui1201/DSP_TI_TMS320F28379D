#ifndef _FASTRTS_ASSERT_H_
#define _FASTRTS_ASSERT_H_
//#############################################################################
//! \file   reference/C/include/$FILENAME$
//! \brief  Fast RTS Assert Header File
//! \author Vishal Coelho 
//! \date   19-Aug-2015
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
#include <stdlib.h>
//!
//! \defgroup FASTRTS_ASSERT Code Development with Assertion

//!
//! \ingroup FASTRTS_ASSERT
//@{

#ifdef __cplusplus
extern "C" {
#endif
//*****************************************************************************
//defines
//*****************************************************************************
//! \brief Assign a "unique" number to each file, compiler error
//! on duplicates
//!
#define FASTRTS_FILENUM(number) \
    enum{FILE_NUM = number};    \
    void _nullFunction##number(void){}

//! \brief The assert() for the PMBus communications stack
//!
#define FASTRTS_ASSERT(expr) \
    if (expr)                \
    {}                       \
    else                     \
    FastRTS_assertionFailed(FILE_NUM, __LINE__)

//*****************************************************************************
// the function prototypes
//*****************************************************************************
//! \brief Handles failed assertions
//! \param[in] file File number where the assertion failed
//! \param[in] line Line number where the assertion failed
//!
static inline void FastRTS_assertionFailed(int16_t file, int16_t line)
{
#if defined(_DEBUG)
    printf("Error in file %d on line %d\n",file,line );
    abort();
#else
    printf("Error in file %d on line %d\n",file,line );
    // User must define some failure mechanism here instead (or in addition to)
    // of abort
    abort();
#endif //defined(_DEBUG)
}

#ifdef __cplusplus
}
#endif // extern "C"
//@}  // ingroup

#endif // end of _FASTRTS_ASSERT_H_ definition
