//#############################################################################
//! \file i16byi16Input.c
//! \brief  FID Input Vectors (256) 
//! \author Vishal Coelho 
//! \date   15-Apr-2016
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


#include <stdint.h>

const int16_t test_dividend[256] = {
            2876,        14486,         1474,        32354, 
          -18437,       -25835,       -25579,       -28601, 
           -6254,        -3384,        -8794,        17268, 
            8381,        17824,        28367,        30981, 
          -20183,       -23667,        12862,       -26620, 
            1664,         1988,        23667,         -993, 
           -6983,        11234,        15810,         1314, 
           -9981,       -22938,         5642,       -15588, 
          -29855,        16707,       -16857,        -3775, 
           12307,        -9226,        15488,        -6901, 
           12020,        13372,        -3782,       -31485, 
          -11085,        -4961,       -15056,       -19854, 
           21083,        -4593,        25412,        -7132, 
           17636,        -6764,        20218,        16716, 
           -8035,       -18611,        19031,        29445, 
          -11301,        11223,        -4021,        21855, 
           17619,       -21807,        23722,        32103, 
             945,        25183,         5768,       -22626, 
          -19670,        -6098,        16298,        21337, 
           19002,       -11894,         2232,       -26873, 
          -25447,       -23836,        11707,         -317, 
          -20335,         -328,       -23094,       -29165, 
           22983,         3968,        28154,        12888, 
            5425,        20669,        24838,        32040, 
          -32734,        23949,         7377,        32108, 
            1814,        -1342,        19748,       -17836, 
            -125,        26269,         4892,        22621, 
           15639,         5635,       -16598,        10906, 
          -27297,         8254,        10547,        15056, 
           25607,        31607,        17630,         5337, 
           28069,         5248,       -31655,       -24847, 
           23770,        -1030,        22600,       -19045, 
            3426,         8511,       -30671,         7517, 
           -9017,       -29522,         -684,       -20152, 
          -24702,       -19301,       -23166,       -20377, 
          -29973,         8860,       -14296,         2529, 
           12790,          -58,         2346,        -3593, 
          -24646,         -632,        23133,        24505, 
          -15054,       -19106,         4258,         9195, 
           -5438,       -19269,        29355,       -27389, 
          -25840,       -23459,       -21859,         7927, 
            4830,       -29355,        28258,        14985, 
           15586,       -28613,        23621,        28468, 
           31745,        23523,        18714,          876, 
          -21129,        -6646,       -23991,       -30744, 
           28779,       -13022,       -13400,       -10949, 
           -2159,         9712,       -31115,        22426, 
            3868,        23205,        -9970,        -3538, 
          -29213,       -21161,        10669,       -11087, 
           26114,       -25025,        32008,         2620, 
           13560,        32734,       -13904,        -5602, 
           -2305,        17298,        20853,       -26200, 
          -21095,        -9199,       -29052,         1434, 
          -10758,       -21256,       -19075,        26551, 
           11494,        -2067,        27009,       -25952, 
           16091,        15483,         4054,       -20697, 
            6370,       -13112,       -23978,       -18835, 
           25882,       -28085,       -16877,       -29245, 
           -3820,       -31897,        26029,       -19880, 
          -26649,       -12625,        -2880,       -26105, 
           32465,       -11004,       -13281,       -28702, 
          -13223,       -29730,          355,        17132, 
            8589,       -26877,       -27469,        18168, 
           26550,         2213,       -25615,        21351, 
}; 

const int16_t test_divisor[256] = {
          -10611,       -13502,        16142,       -32091, 
          -29593,        11004,         6780,         1710, 
           15054,        13582,        18440,       -13895, 
           12617,         3713,        -6782,       -28732, 
           18361,       -10644,         7068,        15810, 
          -25899,       -24387,         3246,         -968, 
           25589,        19592,        15357,       -29404, 
          -27991,       -26966,        19552,        29032, 
           12039,       -24112,        14596,       -25536, 
          -25068,         9221,       -11219,        10080, 
           16326,         5451,        15730,       -17379, 
           15397,        30840,        24046,       -27117, 
           -8754,        -8573,        12125,         6418, 
           18963,        -8674,       -19266,       -27088, 
           17821,       -19289,        -7323,         3393, 
          -17764,         9302,        -1018,       -22817, 
           18476,       -26175,       -13496,       -17212, 
            2023,       -26772,        -6206,       -25897, 
          -25409,        18639,       -13660,         6785, 
           30435,        -4425,        12763,        16914, 
           -4415,        10190,       -25575,        28426, 
          -20483,       -15324,        19518,         -813, 
           17626,        -6816,       -14881,       -30328, 
           11356,        -4616,        -3163,         7199, 
          -28875,       -12071,        17872,        12873, 
          -24554,       -24239,       -26716,       -32255, 
           -5040,        10195,        14609,         2045, 
          -25637,         8635,       -24478,       -23966, 
          -26307,       -23460,       -21742,       -19907, 
          -11962,       -12031,       -18510,       -16316, 
           25750,        13318,         3652,       -20681, 
          -18873,       -27699,        27118,        13547, 
            3787,       -12227,       -21876,         8027, 
           31976,       -21599,       -15874,        -6764, 
          -27919,        12064,        -6397,        31642, 
           -6411,         7908,       -22651,        -7777, 
          -22208,        16915,        24320,        -9780, 
           12159,       -13491,         2007,        21785, 
            6389,       -10793,       -13158,        -3107, 
           -5070,        -9201,         3821,        15895, 
           -4959,        -4630,       -24584,       -31167, 
          -13751,       -11959,        10072,        29945, 
           28555,        -2760,       -17008,        17294, 
           16995,        15770,        15970,       -25827, 
           11898,        -2408,       -18864,       -26312, 
           21205,       -21299,       -22048,        10877, 
           25846,         1085,        13284,       -22702, 
           29717,         2679,        11778,       -30372, 
           20263,        16293,       -24892,         1641, 
          -11414,         3044,        -6627,        -5565, 
          -20923,       -16031,       -31422,        27765, 
           10072,        28351,       -22052,        27596, 
           19310,         5072,        -3930,       -15885, 
           16511,       -17782,       -28561,        17519, 
           11219,        14103,         9309,        -5306, 
           -7159,        20718,       -11965,        20613, 
           18944,        23085,          369,         8890, 
           29549,        -3673,       -28835,        24034, 
            8597,        -9498,        32571,       -18077, 
            9990,         6880,        -7390,       -23450, 
          -31121,        -5170,       -20703,        14796, 
           -8496,        22384,        15350,         4654, 
          -21178,        29974,       -15380,        27824, 
          -18103,        -8286,       -27034,         9182, 
}; 


// End of File
