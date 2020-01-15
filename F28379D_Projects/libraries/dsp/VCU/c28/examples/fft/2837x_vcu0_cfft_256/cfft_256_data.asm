;******************************************************************************
;******************************************************************************
; 
; FILE: cfft_256_data.asm
; 
; DESCRIPTION: Input test data for the FFT
; 
;******************************************************************************
;  $TI Release: C28x VCU Library V2.10.00.00 $
;  $Release Date: May 27, 2019 $
;  $Copyright: Copyright (C) 2019 Texas Instruments Incorporated -
;              http://www.ti.com/ ALL RIGHTS RESERVED $
;******************************************************************************
;  This software is licensed for use with Texas Instruments C28x
;  family DSCs.  This license was provided to you prior to installing
;  the software.  You may review this license by consulting a copy of
;  the agreement in the doc directory of this library.
; ------------------------------------------------------------------------
;******************************************************************************
        ;.cdecls   C,LIST,"fft.h"
;############################################################################
;
;/*! \page CFFT_256_DATA (Input test data to the FFT)
;
; The input test data is a two tone function. We run the fft on this 
; data and compare to the expected output.
;*/
;############################################################################
 		 .sect .econst
         .align 512
         .global _CFFT16_256p_in_data,_CFFT16_256p_out_data
 
; FFT input data, two-tone test          
_CFFT16_256p_in_data: 
        .word   0, 2232,  0, 1930,  0, 1165,  0, 286
        .word   0, -347,  0, -560,  0, -445,  0, -286
        .word   0, -373,  0, -809,  0, -1440,  0, -1930
        .word   0, -1957,  0, -1406,  0, -445,  0, 560
        .word   0, 1237,  0, 1406,  0, 1165,  0, 809
        .word   0, 648,  0, 809,  0, 1165,  0, 1406
        .word   0, 1237,  0, 560,  0, -445,  0, -1406
        .word   0, -1957,  0, -1930,  0, -1440,  0, -809
        .word   0, -373,  0, -286,  0, -445,  0, -560
        .word   0, -347,  0, 286,  0, 1165,  0, 1930
        .word   0, 2232,  0, 1930,  0, 1165,  0, 286
        .word   0, -347,  0, -560,  0, -445,  0, -286
        .word   0, -373,  0, -809,  0, -1440,  0, -1930
        .word   0, -1957,  0, -1406,  0, -445,  0, 560
        .word   0, 1237,  0, 1406,  0, 1165,  0, 809
        .word   0, 648,  0, 809,  0, 1165,  0, 1406
        .word   0, 1237,  0, 560,  0, -445,  0, -1406
        .word   0, -1957,  0, -1930,  0, -1440,  0, -809
        .word   0, -373,  0, -286,  0, -445,  0, -560
        .word   0, -347,  0, 286,  0, 1165,  0, 1930
        .word   0, 2232,  0, 1930,  0, 1165,  0, 286
        .word   0, -347,  0, -560,  0, -445,  0, -286
        .word   0, -373,  0, -809,  0, -1440,  0, -1930
        .word   0, -1957,  0, -1406,  0, -445,  0, 560
        .word   0, 1237,  0, 1406,  0, 1165,  0, 809
        .word   0, 648,  0, 809,  0, 1165,  0, 1406
        .word   0, 1237,  0, 560,  0, -445,  0, -1406
        .word   0, -1957,  0, -1930,  0, -1440,  0, -809
        .word   0, -373,  0, -286,  0, -445,  0, -560
        .word   0, -347,  0, 286,  0, 1165,  0, 1930
        .word   0, 2232,  0, 1930,  0, 1165,  0, 286
        .word   0, -347,  0, -560,  0, -445,  0, -286
        .word   0, -373,  0, -809,  0, -1440,  0, -1930
        .word   0, -1957,  0, -1406,  0, -445,  0, 560
        .word   0, 1237,  0, 1406,  0, 1165,  0, 809
        .word   0, 648,  0, 809,  0, 1165,  0, 1406
        .word   0, 1237,  0, 560,  0, -445,  0, -1406
        .word   0, -1957,  0, -1930,  0, -1440,  0, -809
        .word   0, -373,  0, -286,  0, -445,  0, -560
        .word   0, -347,  0, 286,  0, 1165,  0, 1930
        .word   0, 2232,  0, 1930,  0, 1165,  0, 286
        .word   0, -347,  0, -560,  0, -445,  0, -286
        .word   0, -373,  0, -809,  0, -1440,  0, -1930
        .word   0, -1957,  0, -1406,  0, -445,  0, 560
        .word   0, 1237,  0, 1406,  0, 1165,  0, 809
        .word   0, 648,  0, 809,  0, 1165,  0, 1406
        .word   0, 1237,  0, 560,  0, -445,  0, -1406
        .word   0, -1957,  0, -1930,  0, -1440,  0, -809
        .word   0, -373,  0, -286,  0, -445,  0, -560
        .word   0, -347,  0, 286,  0, 1165,  0, 1930
        .word   0, 2232,  0, 1930,  0, 1165,  0, 286
        .word   0, -347,  0, -560,  0, -445,  0, -286
        .word   0, -373,  0, -809,  0, -1440,  0, -1930
        .word   0, -1957,  0, -1406,  0, -445,  0, 560
        .word   0, 1237,  0, 1406,  0, 1165,  0, 809
        .word   0, 648,  0, 809,  0, 1165,  0, 1406
        .word   0, 1237,  0, 560,  0, -445,  0, -1406
        .word   0, -1957,  0, -1930,  0, -1440,  0, -809
        .word   0, -373,  0, -286,  0, -445,  0, -560
        .word   0, -347,  0, 286,  0, 1165,  0, 1930
        .word   0, 2232,  0, 1930,  0, 1165,  0, 286
        .word   0, -347,  0, -560,  0, -445,  0, -286
        .word   0, -373,  0, -809,  0, -1440,  0, -1930
        .word   0, -1957,  0, -1406,  0, -445,  0, 560




; FFT output data 
_CFFT16_256p_out_data:
        .word   0, -14,  1, -14,  2, -15,  3, -16
        .word   4, -16,  6, -18,  8, -20,  10, -22
        .word   13, -26,  17, -32,  25, -42,  41, -63
        .word   95, -138,  -399, 542,  -69, 89,  -39, 47
        .word   -27, 32,  -21, 25,  -17, 19,  -15, 17
        .word   -13, 14,  -12, 13,  -10, 10,  -10, 10
        .word   -9, 9,  -9, 8,  -8, 7,  -8, 7
        .word   -7, 7,  -6, 6,  -6, 6,  -6, 6
        .word   -5, 401,  -5, 5,  -5, 5,  -5, 5
        .word   -4, 5,  -4, 4,  -5, 5,  -5, 4
        .word   -4, 4,  -3, 4,  -4, 4,  -4, 3
        .word   -3, 4,  -3, 3,  -3, 4,  -3, 3
        .word   -4, 3,  -3, 3,  -3, 3,  -4, 3
        .word   -3, 3,  -3, 3,  -3, 3,  -2, 3
        .word   -2, 3,  -3, 3,  -2, 3,  -2, 3
        .word   -2, 2,  -2, 3,  -2, 3,  -2, 3
        .word   -2, 3,  -2, 2,  -2, 3,  -2, 3
        .word   -2, 3,  -2, 3,  -2, 3,  -2, 3
        .word   -1, 3,  -1, 3,  -2, 3,  -2, 3
        .word   -1, 3,  -2, 3,  -2, 3,  -2, 3
        .word   -2, 3,  -2, 3,  -1, 2,  -1, 3
        .word   -1, 3,  -2, 3,  -1, 2,  -1, 3
        .word   -1, 3,  -1, 2,  -1, 2,  -1, 3
        .word   -1, 2,  -1, 2,  -1, 3,  -1, 3
        .word   -1, 2,  -1, 2,  -1, 2,  0, 3
        .word   -1, 2,  -1, 2,  0, 3,  -1, 3
        .word   -1, 2,  -1, 2,  0, 3,  -1, 2
        .word   -1, 2,  -1, 2,  0, 3,  0, 2
        .word   0, 3,  -1, 2,  -1, 2,  0, 3
        .word   -1, 2,  0, 2,  -1, 3,  0, 2
        .word   0, 3,  0, 2,  0, 2,  0, 2
        .word   0, 2,  0, 2,  0, 2,  0, 2
        .word   0, 2,  0, 2,  0, 2,  0, 2
        .word   0, 2,  0, 2,  0, 2,  0, 2
        .word   0, 3,  0, 2,  1, 3,  0, 2
        .word   1, 2,  0, 3,  1, 2,  1, 2
        .word   0, 3,  0, 2,  0, 3,  1, 2
        .word   1, 2,  1, 2,  0, 3,  1, 2
        .word   1, 2,  1, 3,  0, 3,  1, 2
        .word   1, 2,  0, 3,  1, 2,  1, 2
        .word   1, 2,  1, 3,  1, 3,  1, 2
        .word   1, 2,  1, 3,  1, 2,  1, 2
        .word   1, 3,  1, 3,  1, 2,  2, 3
        .word   1, 3,  1, 3,  1, 2,  2, 3
        .word   2, 3,  2, 3,  2, 3,  2, 3
        .word   1, 3,  2, 3,  2, 3,  1, 3
        .word   1, 3,  2, 3,  2, 3,  2, 3
        .word   2, 3,  2, 3,  2, 3,  2, 2
        .word   2, 3,  2, 3,  2, 3,  2, 3
        .word   2, 2,  2, 3,  2, 3,  3, 3
        .word   2, 3,  2, 3,  3, 3,  3, 3
        .word   3, 3,  4, 3,  3, 3,  3, 3
        .word   4, 3,  3, 3,  3, 4,  3, 3
        .word   3, 4,  4, 3,  4, 4,  3, 4
        .word   4, 4,  5, 4,  5, 5,  4, 4
        .word   4, 5,  5, 5,  5, 5,  5, 5
        .word   5, 401,  6, 6,  6, 6,  6, 6
        .word   7, 7,  8, 7,  8, 7,  9, 8
        .word   9, 9,  10, 10,  10, 10,  12, 13
        .word   13, 14,  15, 17,  17, 19,  21, 25
        .word   27, 32,  39, 47,  69, 89,  399, 542
        .word   -95, -138,  -41, -63,  -25, -42,  -17, -32
        .word   -13, -26,  -10, -22,  -8, -20,  -6, -18
        .word   -4, -16,  -3, -16,  -2, -15,  -1, -14
