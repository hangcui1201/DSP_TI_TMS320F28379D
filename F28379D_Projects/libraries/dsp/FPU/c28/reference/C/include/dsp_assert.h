#ifndef _DSP_ASSERT_H_
#define _DSP_ASSERT_H_
//#############################################################################
//! \file   reference/C/include/$FILENAME$
//! \brief  DSP Assert Header File
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
//!
//! \defgroup DSP_ASSERT Code Development with Assertion

//!
//! \ingroup DSP_ASSERT
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
#define DSP_FILENUM(number) \
    enum{FILE_NUM = number};    \
    void _nullFunction##number(void){}

//! \brief The assert() for the PMBus communications stack
//!
#define DSP_ASSERT(expr) \
    if (expr)                \
    {}                       \
    else                     \
    DSP_assertionFailed(FILE_NUM, __LINE__)

//*****************************************************************************
// the function prototypes
//*****************************************************************************
//! \brief Handles failed assertions
//! \param[in] file File number where the assertion failed
//! \param[in] line Line number where the assertion failed
//!
static inline void DSP_assertionFailed(int16_t file, int16_t line)
{
#if defined(_DEBUG)
    // Do nothing
#else
    printf("Error in file %d on line %d\n",file,line );
#endif //defined(_DEBUG)
}

#ifdef __cplusplus
}
#endif // extern "C"
//@}  // ingroup

#endif // end of _DSP_ASSERT_H_ definition
