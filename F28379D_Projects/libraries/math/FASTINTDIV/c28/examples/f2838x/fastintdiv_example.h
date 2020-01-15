//#############################################################################
//
//! \file   fastintdiv_example.h
//!
//! \brief  Header file for fast integer division example
//! \date   Feb 14, 2019
//
//  Group:          C2000
//  Target Device:  TMS320f2838x
//
// The header file defines various types of user-defined data types used for
// storing input data passed to various forms of division tests
//
//#############################################################################
// $TI Release: $
// $Release Date: $
// $Copyright: $
//#############################################################################


#ifndef FASTINTDIV_EXAMPLE_H_
#define FASTINTDIV_EXAMPLE_H_

#include <stdint.h>


typedef struct {
int16_t dividend; int16_t divisor; int32_t quotient; int32_t remainder;
} parameters_div_i16byi16;

typedef struct {
uint16_t dividend; uint16_t divisor; uint32_t quotient; uint32_t remainder;
} parameters_div_u16byu16;

typedef struct {
int32_t dividend; int32_t divisor; int32_t quotient; int32_t remainder;
} parameters_div_i32byi32;

typedef struct {
int32_t dividend; uint32_t divisor; int32_t quotient; int32_t remainder;
} parameters_div_i32byu32;

typedef struct {
uint32_t dividend; uint32_t divisor; uint32_t quotient; uint32_t remainder;
} parameters_div_u32byu32;

typedef struct {
int32_t dividend; int16_t divisor; int32_t quotient; int32_t remainder;
} parameters_div_i32byi16;

typedef struct {
uint32_t dividend; uint16_t divisor; uint32_t quotient; uint32_t remainder;
} parameters_div_u32byu16;

typedef struct {
int64_t dividend; int64_t divisor; int64_t quotient; int64_t remainder;
} parameters_div_i64byi64;

typedef struct {
int64_t dividend; uint64_t divisor; int64_t quotient; int64_t remainder;
} parameters_div_i64byu64;

typedef struct {
uint64_t dividend; uint64_t divisor; uint64_t quotient; uint64_t remainder;
} parameters_div_u64byu64;

#endif /* FASTINTDIV_EXAMPLE_H_ */
