//#############################################################################
//! \file ui16byui16Input.c
//! \brief  FID Input Vectors (256) 
//! \author Vishal Coelho 
//! \date   14-Apr-2016
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

const uint16_t test_dividend[256] = {
           53393,        59361,         8322,        59858, 
           41442,         6392,        18251,        35840, 
           62750,        63234,        10329,        63608, 
           62728,        31809,        52446,         9299, 
           27640,        60013,        51917,        62880, 
           42974,         2340,        55648,        61209, 
           44481,        49658,        48701,        25705, 
           42957,        11219,        46271,         2086, 
           18148,         3026,         6366,        53965, 
           45536,        20781,        62273,         2257, 
           28753,        25005,        50168,        52113, 
           12247,        32097,        29201,        42356, 
           46488,        49458,        18089,        44544, 
           42932,        10657,         7799,        32660, 
           62897,        22307,        38356,        14668, 
           49234,        16718,        33158,        45814, 
           58385,        62867,        35862,         9085, 
            9784,        16876,        55096,        16664, 
           53364,        15959,        60899,        22936, 
           12884,        16455,        40372,        31017, 
           23046,        54448,        38355,        36026, 
           60108,        18732,        49623,        49396, 
           24933,        37212,         4971,         3536, 
           34786,        51063,        61210,         8513, 
           37278,        30762,          780,        22093, 
           10629,        52053,        20395,        34637, 
           10856,        39451,        17234,        42865, 
           45168,        49030,        29526,         5493, 
           15006,        59856,         9986,        54120, 
           35280,        65282,         5123,        29011, 
            6989,        63038,          304,        50784, 
           53562,        56930,         5534,        26200, 
           17031,        52432,        28273,        59679, 
           11917,        17288,         9538,         8917, 
           56969,        37991,        36035,         9500, 
           55903,        40766,        23000,        33636, 
           26332,         4978,        15723,         8082, 
           12052,        15725,        27346,         3254, 
           59160,        61917,        32169,        32063, 
           22132,        58985,        24199,         7288, 
           51134,        25542,        15839,        26470, 
            6321,         8649,        61737,        62660, 
           37696,         3918,        15386,        23144, 
           53817,         1009,         2820,        11075, 
           42540,        47953,        42450,        29551, 
           35848,        19419,        48803,        12383, 
           45008,        12026,        24149,        41000, 
           51132,         5317,        60907,        50836, 
           31902,        28564,        29280,        20077, 
           33325,        33473,        53583,        52089, 
           42225,        24812,        53187,        34919, 
           22985,        61537,        57405,        36054, 
           40794,        38472,        13614,        19742, 
           30862,        15105,        55332,        12764, 
           14806,        11187,        14920,        28554, 
           20388,        60514,        28194,        12112, 
           59301,        64208,        28761,         7282, 
           16912,        26785,        38987,        17184, 
           39507,        46610,        14532,         7695, 
           19443,        20891,        27798,        33282, 
            5604,        17202,        52494,         1915, 
           60872,        47862,        32021,        37914, 
           15550,        30071,        63116,        35835, 
           34153,        15178,        32040,        40898, 
}; 

const uint16_t test_divisor[256] = {
           44507,        25920,        24080,        64747, 
            2473,        58009,        59852,        52178, 
            6469,        17162,        21978,        44546, 
            8949,        47266,         6997,        42844, 
           32386,        51055,        46860,        59225, 
           58387,        21899,        45792,        12963, 
            2002,        48763,        32769,        31452, 
           59291,        39968,        40479,        56324, 
           52788,        37795,        11988,        15724, 
           58098,         1879,        32106,        11005, 
           64138,        46706,        32798,        30873, 
            3907,        44693,         2781,         4682, 
           34186,         6339,        53617,        53578, 
           47345,         9821,        43227,        33986, 
           63764,        42532,        52450,        29740, 
           28337,        54087,         5470,         8727, 
           11363,        25620,        54484,        52648, 
            3963,        26165,        34529,        27315, 
           43047,        41154,        19135,        28288, 
            1015,        64491,        10955,         6961, 
           24406,        12984,        32092,        22249, 
           62365,        60314,         3452,        48356, 
           17637,        27711,        35905,        61782, 
           27377,        64424,        19756,        45947, 
           43669,        35332,        45750,        43681, 
           11674,         8389,        65475,        11214, 
            2136,        36778,        57793,        43854, 
           12480,        24177,        30194,        64332, 
           10250,        56067,        42255,        24659, 
           12512,        28066,        31589,         7904, 
           38633,        14823,        25206,        38206, 
           16502,        19034,        40441,        17385, 
           54025,        64399,        47857,        22536, 
           38277,         7063,        59395,        57648, 
           53592,        17087,        38951,         1475, 
           27869,        20494,        10583,        11715, 
           27714,         6175,        39224,        30862, 
           45609,        45867,        41846,         2202, 
            4509,        20945,        34790,        42889, 
           26713,        53737,        47078,        63480, 
           34821,        21308,         6922,        40039, 
           51039,        27751,         5952,        17463, 
           10070,        18416,        28841,        34546, 
           29977,        57367,        33951,        61840, 
           41792,        62762,        15775,        44310, 
           18944,        44027,        45556,         4456, 
           16698,        14682,        43766,        55337, 
           22574,        51151,        44258,          440, 
           39463,        25347,        60029,           75, 
           30307,        27810,        30206,        50472, 
           21133,        51428,        30890,         2344, 
           11526,        47300,        31030,        10009, 
           22356,        39805,        12566,        48393, 
           15915,        60123,        17633,        50167, 
           12364,        18841,         5971,        37762, 
           44784,        35821,        27900,        42234, 
           42442,        44499,        41666,        61942, 
           13693,        46483,        15481,         7825, 
           39800,        29500,        30063,        43381, 
           50481,        22952,        43385,        27273, 
           55176,        54585,        16806,        40203, 
           38158,        35437,        57012,        17352, 
           20845,         7813,        61592,        42306, 
           31422,        41898,        35698,        42422, 
}; 


// End of File
