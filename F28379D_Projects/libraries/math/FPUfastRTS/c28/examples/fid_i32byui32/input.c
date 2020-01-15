//#############################################################################
//! \file   input.c
//! \brief  FID Input Vectors (256) 
//! \author Vishal Coelho 
//! \date   30-Mar-2016
//! 
//
//  Group:          C2000
//  Target Family:  $DEVICE$
//
//#############################################################################
// $TI Release: C28x Floating Point Unit Library V2.01.00.00 $
// $Release Date: May 27, 2019 $
// $Copyright: Copyright (C) 2019 Texas Instruments Incorporated -
//             http://www.ti.com/ ALL RIGHTS RESERVED $
//#############################################################################

#include "fpu64/fid.h"
#include <stdint.h>

const int32_t test_dividend[256] = {
      1024709139,  -1140707897,  -1385458141,  -1472148073,
       978849373,    755939539,  -1941022661,    848118878,
     -2065611093,   1336818482,    336350490,   1645364718,
     -1477055151,    190249696,   -483930122,   -474639294,
     -1218556679,    -26217294,    929525563,   -273142355,
      1758410085,   -201472396,   -306144427,    -11492879,
      -116046023,    641023703,   -113021274,       882355,
       504214787,   1010493344,   -108586459,   1250144438,
        94559512,   2114025489,    658891591,    152321031,
      1180855706,   -414782350,  -2027324583,   1542663006,
      1598306813,   1848772059,    440349619,  -1284166277,
     -1023606793,  -1694437797,  -1746706627,    930146360,
     -1172465165,   1253650709,   -790052336,   1410423172,
      1592508717,    639681253,   1686984650,    478043674,
     -1879516878,    972218970,   1266780228,  -1030687584,
      -372855096,   1889164489,   -610255351,  -1873732115,
      1171291612,  -1349408586,   1767503212,     88317276,
       948534416,   1773229749,   1831265179,   -535260938,
       447669120,    439948046,   -863139083,   -513808877,
      -932067500,   -149079814,   -901275949,   1413282975,
     -1848902220,   -506943039,   -403200996,    -94912742,
     -1219710681,   1367492117,   1866623589,   1592862272,
       -94345510,   2040589628,  -1351512949,    457581986,
      -182384739,  -1307490941,   -838414204,   -782320362,
       451952613,   -148817057,   -554253603,   1884029739,
      1771456903,   2004984089,    322710572,   -306709094,
     -2123846601,  -2039024953,    415496899,  -1581095635,
      1877735451,   -813973117,   1422739453,  -2004149241,
      1545171165,   1739954989,  -1335168925,     63418076,
      -989655154,  -1524954579,   -863787585,   1536416462,
      1536119926,  -1549641596,   -886398630,   1587967770,
       161769409,  -1303566524,   1476024645,   -766119221,
      1653911408,    183585003,   -116979842,  -1786044351,
     -1697556885,   1471953136,   1662420092,    -59242684,
       -67760823,  -1901557230,  -1886312994,  -1318305265,
      -617818239,   1862867607,    336150684,  -1908146249,
     -1061243231,   1105985089,  -1091610033,   2090034857,
      -623897654,   1798509060,   1975024566,   1940018816,
       445547608,  -1104687451,  -1357674703,  -1463593559,
      1054081703,   -382072470,  -1189413703,    827159426,
      -220681612,    619259742,   1363280519,   1703564013,
      1658445005,   -755693716,  -1275954922,  -1914429593,
      1526352657,   1379703875,  -1661305910,   1992349643,
      1296992253,  -1808610321,    866426199,   1289005981,
      -802817944,    541249465,  -1648030599,  -1793583808,
     -1246190596,  -1486642790,   1625165695,   -453059087,
       779101154,    668287653,   -942726365,   1407385082,
      1606165756,   -905953994,   -419181599,   1347146983,
     -1933011694,  -1732495532,   -791655047,   1732316225,
       326788693,  -1414124914,  -1802712556,    201393133,
      1432362015,  -1535517783,   1730467356,   -465264081,
     -1673989659,   -845676711,   1847568467,  -1712813129,
      1045377313,   -314119480,   -901197314,   -993265581,
      2111925049,   -794930370,  -1065775737,   -237071122,
      1675104221,  -1817542581,   -791681340,   1800586422,
      -959461884,    531497627,    -35339844,     27607956,
      -733199233,  -2081052452,    498933340,   2074521740,
       441499483,     47880063,    -25922978,  -1245694853,
       595049501,   1021006410,  -1067175877,    664639423,
       408996277,    167719411,  -1775354451,   2100351188,
     -1811734889,  -1767186369,  -2080829353,   1950982308,
       206587966,    455056189,  -2092689642,    211012401,
        25227568,   1301652725,     39221238,   1107688961,
      2057196616,   1775218725,   -751902919,    212631292,
}; 

const uint32_t test_divisor[256] = {
      3654178831,   3108505830,   3148169442,   4043313955,
      2891542371,   2097567958,   1473826341,   3729468157,
      1468666308,   1505516171,    961515125,    291571587,
      4026545811,   1288981510,   3959365386,    951495060,
      1937444572,    987393526,   2043467851,   1165657974,
      1519321986,   1561880145,   2822099571,   1201092514,
       257612020,   1584781715,   1127392676,   1806337434,
       858846360,   3357919532,    571661352,   1469754468,
      1348263819,   3774836909,   2355423033,    243414949,
      3490649703,   2830393110,    503308881,   1200211595,
      2279388210,   3145088413,   3549168720,    985333861,
      3962472104,   1578202571,    163422989,   2786965842,
      3512402116,   1808416491,   3457444461,    888483988,
      1336482947,   3747811947,   2520011041,   3228984784,
      3242734640,    120360407,   2758427871,   2975933079,
       997204143,   1247587129,    883076261,   3621348131,
       409320781,    819078923,   3277396949,    922808631,
       201268959,    767168991,   1877511641,   3013204176,
      1875431828,   1429007916,   2087187908,     47164700,
       231319393,   1534563388,   3302688606,   2638591447,
      2507954103,   3026121111,   2191216567,   2475186287,
      4147400802,    633228946,   3330406114,   2961795306,
       507864426,   3260194731,   1432404402,   2906462386,
      1708164178,    573454078,   2648477175,   3420998469,
      2528093313,   2425600888,    776844939,   2196999728,
      4143565473,   2350566508,   2380953351,    832423614,
      1157673211,   3992217306,    442403253,    788559159,
      1044004996,   3198275918,   1047655638,   1767180438,
      1136964854,   2019671588,   1650398760,    896741496,
       332376586,   4040988146,   2242316108,   1203641515,
      1790655994,   1136381545,   2253250895,   1742902212,
      2377679252,   1162705982,   3402964770,    136969701,
      2923264134,   3747732469,   4259699745,   3422067185,
      2794626130,   2298233875,   1234363946,    422723234,
      2533549978,   3926959867,   1594346822,   1220410380,
       956636018,    228213887,   3857882982,    856474900,
      3067763922,   3141147392,    983234858,   2956522417,
      3273113714,   1503471823,   1054751753,    958637898,
      1060042108,   3139035662,   3454720904,   3336428952,
       697536356,   1491099832,    131856126,    150251076,
      2061584703,    103317263,   3766058740,   2913540440,
      3518898540,    841485862,   1962848916,   1928312002,
       982994020,    476126036,   2510567825,   2485922147,
      3190643904,   3318898839,   2266058679,   1537898770,
      1459619203,   3873405919,   2895115748,   1399092157,
      3691161742,   3021570855,   3948946039,   2610555468,
      1363441030,   2184167297,   3705098221,     33573797,
      2522873673,   3645535724,    647378216,   1440687212,
       893010837,   2174811267,   3470161052,     97548422,
      4144896798,   1488360594,   2520761029,   1262387808,
       549322445,      7397608,    780216940,   1163444583,
       531982078,   3170516221,   3475164889,   2293212511,
      3870132771,    400630908,    399946633,   2566673681,
      3330182178,   3674563380,   3534329741,   1265532550,
      2944977103,    538254158,   2801710369,   1171772269,
      4109035105,   1783654813,   2502636581,   3013216773,
      1235692613,    576314813,   3700863399,   1320330143,
      3609627662,   2330902198,    684627082,   1700378608,
       309201674,    609220371,   2684398550,    210369217,
       449884083,    866729410,   2385027474,   2355296296,
      1777391303,   1643950281,   1308202013,   4168690574,
      3576332898,   3293076592,    744576810,     72448715,
       744988777,   1878603189,    568553231,   3416259446,
      3113352491,    381137528,    311679988,     86307615,
}; 


// End of File
