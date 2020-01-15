//###########################################################################
//
// FILE:   pin_map.h
//
// TITLE:  Definitions of pin mux info for gpio.c.
//
//###########################################################################
// $TI Release: $
// $Release Date: $
//###########################################################################

#ifndef __PIN_MAP_H__
#define __PIN_MAP_H__

//*****************************************************************************
// 0x00000003 = MUX register value
// 0x0000000C = GMUX register value
// 0x0000FF00 = Shift amount within mux registers
// 0xFFFF0000 = Offset of MUX register
//*****************************************************************************
#define GPIO_0_GPIO0                    0x00060000U
#define GPIO_0_EPWM1A                   0x00060001U
#define GPIO_0_SDAA                     0x00060006U
#define GPIO_0_CMI2CSDAA                0x00060009U
#define GPIO_0_ECAT_GPI0                0x0006000AU
#define GPIO_0_FSITXD0A                 0x0006000DU

#define GPIO_1_GPIO1                    0x00060200U
#define GPIO_1_EPWM1B                   0x00060201U
#define GPIO_1_MFSRB                    0x00060203U
#define GPIO_1_SCLA                     0x00060206U
#define GPIO_1_CMI2CSCLA                0x00060209U
#define GPIO_1_ECAT_GPI1                0x0006020AU
#define GPIO_1_FSITXD1A                 0x0006020DU

#define GPIO_2_GPIO2                    0x00060400U
#define GPIO_2_EPWM2A                   0x00060401U
#define GPIO_2_OUTPUTXBAR1              0x00060405U
#define GPIO_2_SDAB                     0x00060406U
#define GPIO_2_ECAT_GPI2                0x0006040AU
#define GPIO_2_FSITXCLKA                0x0006040DU

#define GPIO_3_GPIO3                    0x00060600U
#define GPIO_3_EPWM2B                   0x00060601U
#define GPIO_3_OUTPUTXBAR2              0x00060602U
#define GPIO_3_MCLKRB                   0x00060603U
#define GPIO_3_SCLB                     0x00060606U
#define GPIO_3_ECAT_GPI3                0x0006060AU
#define GPIO_3_FSIRXD0A                 0x0006060DU

#define GPIO_4_GPIO4                    0x00060800U
#define GPIO_4_EPWM3A                   0x00060801U
#define GPIO_4_OUTPUTXBAR3              0x00060805U
#define GPIO_4_CANTXA                   0x00060806U
#define GPIO_4_MCANTXA                  0x00060809U
#define GPIO_4_ECAT_GPI4                0x0006080AU
#define GPIO_4_FSIRXD1A                 0x0006080DU

#define GPIO_5_GPIO5                    0x00060A00U
#define GPIO_5_EPWM3B                   0x00060A01U
#define GPIO_5_MFSRA                    0x00060A02U
#define GPIO_5_OUTPUTXBAR3              0x00060A03U
#define GPIO_5_CANRXA                   0x00060A06U
#define GPIO_5_MCANRXA                  0x00060A09U
#define GPIO_5_ECAT_GPI5                0x00060A0AU
#define GPIO_5_FSIRXCLKA                0x00060A0DU

#define GPIO_6_GPIO6                    0x00060C00U
#define GPIO_6_EPWM4A                   0x00060C01U
#define GPIO_6_OUTPUTXBAR4              0x00060C02U
#define GPIO_6_EPWMSYNCO                0x00060C03U
#define GPIO_6_EQEP3A                   0x00060C05U
#define GPIO_6_CANTXB                   0x00060C06U
#define GPIO_6_ECAT_GPI6                0x00060C0AU
#define GPIO_6_FSITXD0B                 0x00060C0DU

#define GPIO_7_GPIO7                    0x00060E00U
#define GPIO_7_EPWM4B                   0x00060E01U
#define GPIO_7_MCLKRA                   0x00060E02U
#define GPIO_7_OUTPUTXBAR5              0x00060E03U
#define GPIO_7_EQEP3B                   0x00060E05U
#define GPIO_7_CANRXB                   0x00060E06U
#define GPIO_7_ECAT_GPI7                0x00060E0AU
#define GPIO_7_FSITXD1B                 0x00060E0DU

#define GPIO_8_GPIO8                    0x00061000U
#define GPIO_8_EPWM5A                   0x00061001U
#define GPIO_8_CANTXB                   0x00061002U
#define GPIO_8_ADCSOCAO                 0x00061003U
#define GPIO_8_EQEP3S                   0x00061005U
#define GPIO_8_SCITXDA                  0x00061006U
#define GPIO_8_MCANTXA                  0x00061009U
#define GPIO_8_ECAT_GPO0                0x0006100AU
#define GPIO_8_FSITXCLKB                0x0006100DU
#define GPIO_8_FSITXD1A                 0x0006100EU
#define GPIO_8_FSIRXD0A                 0x0006100FU

#define GPIO_9_GPIO9                    0x00061200U
#define GPIO_9_EPWM5B                   0x00061201U
#define GPIO_9_SCITXDB                  0x00061202U
#define GPIO_9_OUTPUTXBAR6              0x00061203U
#define GPIO_9_EQEP3I                   0x00061205U
#define GPIO_9_SCIRXDA                  0x00061206U
#define GPIO_9_ECAT_GPO1                0x0006120AU
#define GPIO_9_FSIRXD0B                 0x0006120DU
#define GPIO_9_FSITXD0A                 0x0006120EU
#define GPIO_9_FSIRXCLKA                0x0006120FU

#define GPIO_10_GPIO10                   0x00061400U
#define GPIO_10_EPWM6A                   0x00061401U
#define GPIO_10_CANRXB                   0x00061402U
#define GPIO_10_ADCSOCBO                 0x00061403U
#define GPIO_10_EQEP1A                   0x00061405U
#define GPIO_10_SCITXDB                  0x00061406U
#define GPIO_10_MCANRXA                  0x00061409U
#define GPIO_10_ECAT_GPO2                0x0006140AU
#define GPIO_10_FSIRXD1B                 0x0006140DU
#define GPIO_10_FSITXCLKA                0x0006140EU
#define GPIO_10_FSIRXD1A                 0x0006140FU

#define GPIO_11_GPIO11                   0x00061600U
#define GPIO_11_EPWM6B                   0x00061601U
#define GPIO_11_SCIRXDB                  0x00061602U
#define GPIO_11_OUTPUTXBAR7              0x00061603U
#define GPIO_11_EQEP1B                   0x00061605U
#define GPIO_11_ECAT_GPO3                0x0006160AU
#define GPIO_11_FSIRXCLKB                0x0006160DU
#define GPIO_11_FSIRXD1A                 0x0006160EU

#define GPIO_12_GPIO12                   0x00061800U
#define GPIO_12_EPWM7A                   0x00061801U
#define GPIO_12_CANTXB                   0x00061802U
#define GPIO_12_MDXB                     0x00061803U
#define GPIO_12_EQEP1S                   0x00061805U
#define GPIO_12_SCITXDC                  0x00061806U
#define GPIO_12_ECAT_GPO4                0x0006180AU
#define GPIO_12_FSIRXD0C                 0x0006180DU
#define GPIO_12_FSIRXD0A                 0x0006180EU

#define GPIO_13_GPIO13                   0x00061A00U
#define GPIO_13_EPWM7B                   0x00061A01U
#define GPIO_13_CANRXB                   0x00061A02U
#define GPIO_13_MDRB                     0x00061A03U
#define GPIO_13_EQEP1I                   0x00061A05U
#define GPIO_13_SCIRXDC                  0x00061A06U
#define GPIO_13_ECAT_GPO5                0x00061A0AU
#define GPIO_13_FSIRXD1C                 0x00061A0DU
#define GPIO_13_FSIRXCLKA                0x00061A0EU

#define GPIO_14_GPIO14                   0x00061C00U
#define GPIO_14_EPWM8A                   0x00061C01U
#define GPIO_14_SCITXDB                  0x00061C02U
#define GPIO_14_MCLKXB                   0x00061C03U
#define GPIO_14_OUTPUTXBAR3              0x00061C06U
#define GPIO_14_ECAT_GPO6                0x00061C0AU
#define GPIO_14_FSIRXCLKC                0x00061C0DU

#define GPIO_15_GPIO15                   0x00061E00U
#define GPIO_15_EPWM8B                   0x00061E01U
#define GPIO_15_SCIRXDB                  0x00061E02U
#define GPIO_15_MFSXB                    0x00061E03U
#define GPIO_15_OUTPUTXBAR4              0x00061E06U
#define GPIO_15_ECAT_GPO7                0x00061E0AU
#define GPIO_15_FSIRXD0D                 0x00061E0DU

#define GPIO_16_GPIO16                   0x00080000U
#define GPIO_16_SPISIMOA                 0x00080001U
#define GPIO_16_CANTXB                   0x00080002U
#define GPIO_16_OUTPUTXBAR7              0x00080003U
#define GPIO_16_EPWM9A                   0x00080005U
#define GPIO_16_SD_D1                    0x00080007U
#define GPIO_16_CMSSITXA                 0x0008000BU
#define GPIO_16_FSIRXD1D                 0x0008000DU

#define GPIO_17_GPIO17                   0x00080200U
#define GPIO_17_SPISOMIA                 0x00080201U
#define GPIO_17_CANRXB                   0x00080202U
#define GPIO_17_OUTPUTXBAR8              0x00080203U
#define GPIO_17_EPWM9B                   0x00080205U
#define GPIO_17_SD_C1                    0x00080207U
#define GPIO_17_CMSSIRXA                 0x0008020BU
#define GPIO_17_FSIRXCLKD                0x0008020DU

#define GPIO_18_GPIO18                   0x00080400U
#define GPIO_18_SPICLKA                  0x00080401U
#define GPIO_18_SCITXDB                  0x00080402U
#define GPIO_18_CANRXA                   0x00080403U
#define GPIO_18_EPWM10A                  0x00080405U
#define GPIO_18_SD_D2                    0x00080407U
#define GPIO_18_MCANRXA                  0x00080409U
#define GPIO_18_EM1CS2N                  0x0008040AU
#define GPIO_18_CMSSICLKA                0x0008040BU
#define GPIO_18_FSIRXD0E                 0x0008040DU

#define GPIO_19_GPIO19                   0x00080600U
#define GPIO_19_SPISTEA                  0x00080601U
#define GPIO_19_SCIRXDB                  0x00080602U
#define GPIO_19_CANTXA                   0x00080603U
#define GPIO_19_EPWM10B                  0x00080605U
#define GPIO_19_SD_C2                    0x00080607U
#define GPIO_19_MCANTXA                  0x00080609U
#define GPIO_19_EM1CS3N                  0x0008060AU
#define GPIO_19_CMSSIFSSA                0x0008060BU
#define GPIO_19_FSIRXD1E                 0x0008060DU

#define GPIO_20_GPIO20                   0x00080800U
#define GPIO_20_EQEP1A                   0x00080801U
#define GPIO_20_MDXA                     0x00080802U
#define GPIO_20_CANTXB                   0x00080803U
#define GPIO_20_EPWM11A                  0x00080805U
#define GPIO_20_SD_D3                    0x00080807U
#define GPIO_20_EM1BA0                   0x0008080AU
#define GPIO_20_TRACEDATA0               0x0008080BU
#define GPIO_20_FSIRXCLKE                0x0008080DU
#define GPIO_20_SPISIMOC                 0x0008080EU

#define GPIO_21_GPIO21                   0x00080A00U
#define GPIO_21_EQEP1B                   0x00080A01U
#define GPIO_21_MDRA                     0x00080A02U
#define GPIO_21_CANRXB                   0x00080A03U
#define GPIO_21_EPWM11B                  0x00080A05U
#define GPIO_21_SD_C3                    0x00080A07U
#define GPIO_21_EM1BA1                   0x00080A0AU
#define GPIO_21_TRACEDATA1               0x00080A0BU
#define GPIO_21_FSIRXD0F                 0x00080A0DU
#define GPIO_21_SPISOMIC                 0x00080A0EU

#define GPIO_22_GPIO22                   0x00080C00U
#define GPIO_22_EQEP1S                   0x00080C01U
#define GPIO_22_MCLKXA                   0x00080C02U
#define GPIO_22_SCITXDB                  0x00080C03U
#define GPIO_22_EPWM12A                  0x00080C05U
#define GPIO_22_SPICLKB                  0x00080C06U
#define GPIO_22_SD_D4                    0x00080C07U
#define GPIO_22_MCANTXA                  0x00080C09U
#define GPIO_22_EM1RAS                   0x00080C0AU
#define GPIO_22_TRACEDATA2               0x00080C0BU
#define GPIO_22_FSIRXD1F                 0x00080C0DU
#define GPIO_22_SPICLKC                  0x00080C0EU

#define GPIO_23_GPIO23                   0x00080E00U
#define GPIO_23_EQEP1I                   0x00080E01U
#define GPIO_23_MFSXA                    0x00080E02U
#define GPIO_23_SCIRXDB                  0x00080E03U
#define GPIO_23_EPWM12B                  0x00080E05U
#define GPIO_23_SPISTEB                  0x00080E06U
#define GPIO_23_SD_C4                    0x00080E07U
#define GPIO_23_MCANRXA                  0x00080E09U
#define GPIO_23_EM1CAS                   0x00080E0AU
#define GPIO_23_TRACEDATA3               0x00080E0BU
#define GPIO_23_FSIRXCLKF                0x00080E0DU
#define GPIO_23_SPISTEC                  0x00080E0EU

#define GPIO_24_GPIO24                   0x00081000U
#define GPIO_24_OUTPUTXBAR1              0x00081001U
#define GPIO_24_EQEP2A                   0x00081002U
#define GPIO_24_MDXB                     0x00081003U
#define GPIO_24_SPISIMOB                 0x00081006U
#define GPIO_24_SD_D5                    0x00081007U
#define GPIO_24_PMBCLK                   0x00081009U
#define GPIO_24_EM1DQM0                  0x0008100AU
#define GPIO_24_TRACECLK                 0x0008100BU
#define GPIO_24_EPWM13A                  0x0008100DU
#define GPIO_24_FSIRXD0G                 0x0008100FU

#define GPIO_25_GPIO25                   0x00081200U
#define GPIO_25_OUTPUTXBAR2              0x00081201U
#define GPIO_25_EQEP2B                   0x00081202U
#define GPIO_25_MDRB                     0x00081203U
#define GPIO_25_SPISOMIB                 0x00081206U
#define GPIO_25_SD_C5                    0x00081207U
#define GPIO_25_PMBDAT                   0x00081209U
#define GPIO_25_EM1DQM1                  0x0008120AU
#define GPIO_25_TRACESWO                 0x0008120BU
#define GPIO_25_EPWM13B                  0x0008120DU
#define GPIO_25_FSITXD1A                 0x0008120EU
#define GPIO_25_FSIRXD1G                 0x0008120FU

#define GPIO_26_GPIO26                   0x00081400U
#define GPIO_26_OUTPUTXBAR3              0x00081401U
#define GPIO_26_EQEP2I                   0x00081402U
#define GPIO_26_MCLKXB                   0x00081403U
#define GPIO_26_SPICLKB                  0x00081406U
#define GPIO_26_SD_D6                    0x00081407U
#define GPIO_26_PMBALERT                 0x00081409U
#define GPIO_26_EM1DQM2                  0x0008140AU
#define GPIO_26_ECAT_MDIO_CLK            0x0008140BU
#define GPIO_26_EPWM14A                  0x0008140DU
#define GPIO_26_FSITXD0A                 0x0008140EU
#define GPIO_26_FSIRXCLKG                0x0008140FU

#define GPIO_27_GPIO27                   0x00081600U
#define GPIO_27_OUTPUTXBAR4              0x00081601U
#define GPIO_27_EQEP2S                   0x00081602U
#define GPIO_27_MFSXB                    0x00081603U
#define GPIO_27_SPISTEB                  0x00081606U
#define GPIO_27_SD_C6                    0x00081607U
#define GPIO_27_PMBCTRL                  0x00081609U
#define GPIO_27_EM1DQM3                  0x0008160AU
#define GPIO_27_ECAT_MDIO_DATA           0x0008160BU
#define GPIO_27_EPWM14B                  0x0008160DU
#define GPIO_27_FSITXCLKA                0x0008160EU
#define GPIO_27_FSIRXD0H                 0x0008160FU

#define GPIO_28_GPIO28                   0x00081800U
#define GPIO_28_SCIRXDA                  0x00081801U
#define GPIO_28_EM1CS4N                  0x00081802U
#define GPIO_28_OUTPUTXBAR5              0x00081805U
#define GPIO_28_EQEP3A                   0x00081806U
#define GPIO_28_SD_D7                    0x00081807U
#define GPIO_28_EM1CS2N                  0x00081809U
#define GPIO_28_EPWM15A                  0x0008180DU
#define GPIO_28_FSIRXD1H                 0x0008180FU

#define GPIO_29_GPIO29                   0x00081A00U
#define GPIO_29_SCITXDA                  0x00081A01U
#define GPIO_29_EM1SDCKE                 0x00081A02U
#define GPIO_29_OUTPUTXBAR6              0x00081A05U
#define GPIO_29_EQEP3B                   0x00081A06U
#define GPIO_29_SD_C7                    0x00081A07U
#define GPIO_29_EM1CS3N                  0x00081A09U
#define GPIO_29_ECAT_LATCH0              0x00081A0AU
#define GPIO_29_ECAT_I2C_SDA             0x00081A0BU
#define GPIO_29_EPWM15B                  0x00081A0DU
#define GPIO_29_ECAT_SYNC0               0x00081A0EU
#define GPIO_29_FSIRXCLKH                0x00081A0FU

#define GPIO_30_GPIO30                   0x00081C00U
#define GPIO_30_CANRXA                   0x00081C01U
#define GPIO_30_EM1CLK                   0x00081C02U
#define GPIO_30_MCANRXA                  0x00081C03U
#define GPIO_30_OUTPUTXBAR7              0x00081C05U
#define GPIO_30_EQEP3S                   0x00081C06U
#define GPIO_30_SD_D8                    0x00081C07U
#define GPIO_30_EM1CS4N                  0x00081C09U
#define GPIO_30_ECAT_LATCH1              0x00081C0AU
#define GPIO_30_ECAT_I2C_SCL             0x00081C0BU
#define GPIO_30_EPWM16A                  0x00081C0DU
#define GPIO_30_ECAT_SYNC1               0x00081C0EU
#define GPIO_30_SPISIMOD                 0x00081C0FU

#define GPIO_31_GPIO31                   0x00081E00U
#define GPIO_31_CANTXA                   0x00081E01U
#define GPIO_31_EM1WEN                   0x00081E02U
#define GPIO_31_MCANTXA                  0x00081E03U
#define GPIO_31_OUTPUTXBAR8              0x00081E05U
#define GPIO_31_EQEP3I                   0x00081E06U
#define GPIO_31_SD_C8                    0x00081E07U
#define GPIO_31_EM1RNW                   0x00081E09U
#define GPIO_31_SDAA                     0x00081E0AU
#define GPIO_31_CMI2CSDAA                0x00081E0BU
#define GPIO_31_EPWM16B                  0x00081E0DU
#define GPIO_31_SPISOMID                 0x00081E0FU

#define GPIO_32_GPIO32                   0x00460000U
#define GPIO_32_SDAA                     0x00460001U
#define GPIO_32_EM1CS0N                  0x00460002U
#define GPIO_32_SPISIMOA                 0x00460003U
#define GPIO_32_CLBOUTPUTXBAR1           0x00460007U
#define GPIO_32_EM1OEN                   0x00460009U
#define GPIO_32_SCLA                     0x0046000AU
#define GPIO_32_CMI2CSCLA                0x0046000BU
#define GPIO_32_SPICLKD                  0x0046000FU

#define GPIO_33_GPIO33                   0x00460200U
#define GPIO_33_SCLA                     0x00460201U
#define GPIO_33_EM1RNW                   0x00460202U
#define GPIO_33_SPISOMIA                 0x00460203U
#define GPIO_33_CLBOUTPUTXBAR2           0x00460207U
#define GPIO_33_EM1BA0                   0x00460209U
#define GPIO_33_SPISTED                  0x0046020FU

#define GPIO_34_GPIO34                   0x00460400U
#define GPIO_34_OUTPUTXBAR1              0x00460401U
#define GPIO_34_EM1CS2N                  0x00460402U
#define GPIO_34_SPICLKA                  0x00460403U
#define GPIO_34_SDAB                     0x00460406U
#define GPIO_34_CLBOUTPUTXBAR3           0x00460407U
#define GPIO_34_EM1BA1                   0x00460409U
#define GPIO_34_ECAT_LATCH0              0x0046040AU
#define GPIO_34_ENET_MII_CRS             0x0046040BU
#define GPIO_34_SCITXDA                  0x0046040DU
#define GPIO_34_ECAT_SYNC0               0x0046040EU
#define GPIO_34_OFSD_2_N                 0x0046040FU

#define GPIO_35_GPIO35                   0x00460600U
#define GPIO_35_SCIRXDA                  0x00460601U
#define GPIO_35_EM1CS3N                  0x00460602U
#define GPIO_35_SPISTEA                  0x00460603U
#define GPIO_35_SCLB                     0x00460606U
#define GPIO_35_CLBOUTPUTXBAR4           0x00460607U
#define GPIO_35_EM1A0                    0x00460609U
#define GPIO_35_ECAT_LATCH1              0x0046060AU
#define GPIO_35_ENET_MII_COL             0x0046060BU
#define GPIO_35_ECAT_SYNC1               0x0046060EU
#define GPIO_35_IID                      0x0046060FU

#define GPIO_36_GPIO36                   0x00460800U
#define GPIO_36_SCITXDA                  0x00460801U
#define GPIO_36_EM1WAIT0                 0x00460802U
#define GPIO_36_CANRXA                   0x00460806U
#define GPIO_36_CLBOUTPUTXBAR5           0x00460807U
#define GPIO_36_EM1A1                    0x00460809U
#define GPIO_36_MCANRXA                  0x0046080AU
#define GPIO_36_SD_D1                    0x0046080DU
#define GPIO_36_ISESSEND                 0x0046080FU

#define GPIO_37_GPIO37                   0x00460A00U
#define GPIO_37_OUTPUTXBAR2              0x00460A01U
#define GPIO_37_EM1OEN                   0x00460A02U
#define GPIO_37_CANTXA                   0x00460A06U
#define GPIO_37_CLBOUTPUTXBAR6           0x00460A07U
#define GPIO_37_EM1A2                    0x00460A09U
#define GPIO_37_MCANTXA                  0x00460A0AU
#define GPIO_37_SD_D2                    0x00460A0DU
#define GPIO_37_IAVALID                  0x00460A0FU

#define GPIO_38_GPIO38                   0x00460C00U
#define GPIO_38_EM1A0                    0x00460C02U
#define GPIO_38_SCITXDC                  0x00460C05U
#define GPIO_38_CANTXB                   0x00460C06U
#define GPIO_38_CLBOUTPUTXBAR7           0x00460C07U
#define GPIO_38_EM1A3                    0x00460C09U
#define GPIO_38_ENET_MII_RX_DV           0x00460C0AU
#define GPIO_38_ENET_MII_CRS             0x00460C0BU
#define GPIO_38_SD_D3                    0x00460C0DU

#define GPIO_39_GPIO39                   0x00460E00U
#define GPIO_39_EM1A1                    0x00460E02U
#define GPIO_39_SCIRXDC                  0x00460E05U
#define GPIO_39_CANRXB                   0x00460E06U
#define GPIO_39_CLBOUTPUTXBAR8           0x00460E07U
#define GPIO_39_EM1A4                    0x00460E09U
#define GPIO_39_ENET_MII_RX_ERR          0x00460E0AU
#define GPIO_39_ENET_MII_COL             0x00460E0BU
#define GPIO_39_SD_D4                    0x00460E0DU

#define GPIO_40_GPIO40                   0x00461000U
#define GPIO_40_EM1A2                    0x00461002U
#define GPIO_40_SDAB                     0x00461006U
#define GPIO_40_ENET_MII_CRS             0x0046100BU
#define GPIO_40_ECAT_I2C_SDA             0x0046100EU

#define GPIO_41_GPIO41                   0x00461200U
#define GPIO_41_EM1A3                    0x00461202U
#define GPIO_41_EMU1                     0x00461203U
#define GPIO_41_SCLB                     0x00461206U
#define GPIO_41_ENET_REVMII_MDIO_RST     0x0046120AU
#define GPIO_41_ENET_MII_COL             0x0046120BU
#define GPIO_41_ECAT_I2C_SCL             0x0046120EU

#define GPIO_42_GPIO42                   0x00461400U
#define GPIO_42_SDAA                     0x00461406U
#define GPIO_42_ENET_MDIO_CLK            0x0046140AU
#define GPIO_42_CMUARTTXA                0x0046140BU
#define GPIO_42_SCITXDA                  0x0046140FU

#define GPIO_43_GPIO43                   0x00461600U
#define GPIO_43_SCLA                     0x00461606U
#define GPIO_43_ENET_MDIO_DATA           0x0046160AU
#define GPIO_43_CMUARTRXA                0x0046160BU
#define GPIO_43_SCIRXDA                  0x0046160FU

#define GPIO_44_GPIO44                   0x00461800U
#define GPIO_44_EM1A4                    0x00461802U
#define GPIO_44_ENET_MII_TX_CLK          0x0046180BU
#define GPIO_44_ECAT_TX1_CLK             0x0046180EU
#define GPIO_44_IXRCV                    0x0046180FU

#define GPIO_45_GPIO45                   0x00461A00U
#define GPIO_45_EM1A5                    0x00461A02U
#define GPIO_45_ENET_MII_TX_EN           0x00461A0BU
#define GPIO_45_ECAT_TX1_ENA             0x00461A0EU
#define GPIO_45_IDM                      0x00461A0FU

#define GPIO_46_GPIO46                   0x00461C00U
#define GPIO_46_EM1A6                    0x00461C02U
#define GPIO_46_SCIRXDD                  0x00461C06U
#define GPIO_46_ENET_MII_TX_ERR          0x00461C0BU
#define GPIO_46_ECAT_MDIO_CLK            0x00461C0EU
#define GPIO_46_IDP                      0x00461C0FU

#define GPIO_47_GPIO47                   0x00461E00U
#define GPIO_47_EM1A7                    0x00461E02U
#define GPIO_47_SCITXDD                  0x00461E06U
#define GPIO_47_ENET_PPS0                0x00461E0BU
#define GPIO_47_ECAT_MDIO_DATA           0x00461E0EU
#define GPIO_47_OFSD_1_N                 0x00461E0FU

#define GPIO_48_GPIO48                   0x00480000U
#define GPIO_48_OUTPUTXBAR3              0x00480001U
#define GPIO_48_EM1A8                    0x00480002U
#define GPIO_48_SCITXDA                  0x00480006U
#define GPIO_48_SD_D1                    0x00480007U
#define GPIO_48_ENET_PPS1                0x0048000BU
#define GPIO_48_ECAT_PHY_CLK             0x0048000EU

#define GPIO_49_GPIO49                   0x00480200U
#define GPIO_49_OUTPUTXBAR4              0x00480201U
#define GPIO_49_EM1A9                    0x00480202U
#define GPIO_49_SCIRXDA                  0x00480206U
#define GPIO_49_SD_C1                    0x00480207U
#define GPIO_49_EM1A5                    0x00480209U
#define GPIO_49_ENET_MII_RX_CLK          0x0048020BU
#define GPIO_49_SD_D5                    0x0048020DU
#define GPIO_49_FSITXD0A                 0x0048020EU

#define GPIO_50_GPIO50                   0x00480400U
#define GPIO_50_EQEP1A                   0x00480401U
#define GPIO_50_EM1A10                   0x00480402U
#define GPIO_50_SPISIMOC                 0x00480406U
#define GPIO_50_SD_D2                    0x00480407U
#define GPIO_50_EM1A6                    0x00480409U
#define GPIO_50_ENET_MII_RX_DV           0x0048040BU
#define GPIO_50_SD_D6                    0x0048040DU
#define GPIO_50_FSITXD1A                 0x0048040EU

#define GPIO_51_GPIO51                   0x00480600U
#define GPIO_51_EQEP1B                   0x00480601U
#define GPIO_51_EM1A11                   0x00480602U
#define GPIO_51_SPISOMIC                 0x00480606U
#define GPIO_51_SD_C2                    0x00480607U
#define GPIO_51_EM1A7                    0x00480609U
#define GPIO_51_ENET_MII_RX_ERR          0x0048060BU
#define GPIO_51_SD_D7                    0x0048060DU
#define GPIO_51_FSITXCLKA                0x0048060EU

#define GPIO_52_GPIO52                   0x00480800U
#define GPIO_52_EQEP1S                   0x00480801U
#define GPIO_52_EM1A12                   0x00480802U
#define GPIO_52_SPICLKC                  0x00480806U
#define GPIO_52_SD_D3                    0x00480807U
#define GPIO_52_EM1A8                    0x00480809U
#define GPIO_52_ENET_MII_RX_DATA0        0x0048080BU
#define GPIO_52_SD_D8                    0x0048080DU
#define GPIO_52_FSIRXD0A                 0x0048080EU

#define GPIO_53_GPIO53                   0x00480A00U
#define GPIO_53_EQEP1I                   0x00480A01U
#define GPIO_53_EM1D31                   0x00480A02U
#define GPIO_53_EM2D15                   0x00480A03U
#define GPIO_53_SPISTEC                  0x00480A06U
#define GPIO_53_SD_C3                    0x00480A07U
#define GPIO_53_EM1A9                    0x00480A09U
#define GPIO_53_ENET_MII_RX_DATA1        0x00480A0BU
#define GPIO_53_SD_C1                    0x00480A0DU
#define GPIO_53_FSIRXD1A                 0x00480A0EU

#define GPIO_54_GPIO54                   0x00480C00U
#define GPIO_54_SPISIMOA                 0x00480C01U
#define GPIO_54_EM1D30                   0x00480C02U
#define GPIO_54_EM2D14                   0x00480C03U
#define GPIO_54_EQEP2A                   0x00480C05U
#define GPIO_54_SCITXDB                  0x00480C06U
#define GPIO_54_SD_D4                    0x00480C07U
#define GPIO_54_EM1A10                   0x00480C09U
#define GPIO_54_ENET_MII_RX_DATA2        0x00480C0BU
#define GPIO_54_SD_C2                    0x00480C0DU
#define GPIO_54_FSIRXCLKA                0x00480C0EU
#define GPIO_54_CMSSITXA                 0x00480C0FU

#define GPIO_55_GPIO55                   0x00480E00U
#define GPIO_55_SPISOMIA                 0x00480E01U
#define GPIO_55_EM1D29                   0x00480E02U
#define GPIO_55_EM2D13                   0x00480E03U
#define GPIO_55_EQEP2B                   0x00480E05U
#define GPIO_55_SCIRXDB                  0x00480E06U
#define GPIO_55_SD_C4                    0x00480E07U
#define GPIO_55_EM1D0                    0x00480E09U
#define GPIO_55_ENET_MII_RX_DATA3        0x00480E0BU
#define GPIO_55_SD_C3                    0x00480E0DU
#define GPIO_55_FSITXD0B                 0x00480E0EU
#define GPIO_55_CMSSIRXA                 0x00480E0FU

#define GPIO_56_GPIO56                   0x00481000U
#define GPIO_56_SPICLKA                  0x00481001U
#define GPIO_56_EM1D28                   0x00481002U
#define GPIO_56_EM2D12                   0x00481003U
#define GPIO_56_EQEP2S                   0x00481005U
#define GPIO_56_SCITXDC                  0x00481006U
#define GPIO_56_SD_D5                    0x00481007U
#define GPIO_56_EM1D1                    0x00481009U
#define GPIO_56_SDAA                     0x0048100AU
#define GPIO_56_ENET_MII_TX_EN           0x0048100BU
#define GPIO_56_SD_C4                    0x0048100DU
#define GPIO_56_FSITXCLKB                0x0048100EU
#define GPIO_56_CMSSICLKA                0x0048100FU

#define GPIO_57_GPIO57                   0x00481200U
#define GPIO_57_SPISTEA                  0x00481201U
#define GPIO_57_EM1D27                   0x00481202U
#define GPIO_57_EM2D11                   0x00481203U
#define GPIO_57_EQEP2I                   0x00481205U
#define GPIO_57_SCIRXDC                  0x00481206U
#define GPIO_57_SD_C5                    0x00481207U
#define GPIO_57_EM1D2                    0x00481209U
#define GPIO_57_SCLA                     0x0048120AU
#define GPIO_57_ENET_MII_TX_ERR          0x0048120BU
#define GPIO_57_FSITXD1B                 0x0048120EU
#define GPIO_57_CMSSIFSSA                0x0048120FU

#define GPIO_58_GPIO58                   0x00481400U
#define GPIO_58_MCLKRA                   0x00481401U
#define GPIO_58_EM1D26                   0x00481402U
#define GPIO_58_EM2D10                   0x00481403U
#define GPIO_58_OUTPUTXBAR1              0x00481405U
#define GPIO_58_SPICLKB                  0x00481406U
#define GPIO_58_SD_D6                    0x00481407U
#define GPIO_58_EM1D3                    0x00481409U
#define GPIO_58_ECAT_LED_LINK0_ACTIVE    0x0048140AU
#define GPIO_58_ENET_MII_TX_CLK          0x0048140BU
#define GPIO_58_SD_C6                    0x0048140DU
#define GPIO_58_FSIRXD0B                 0x0048140EU
#define GPIO_58_SPISIMOA                 0x0048140FU

#define GPIO_59_GPIO59                   0x00481600U
#define GPIO_59_MFSRA                    0x00481601U
#define GPIO_59_EM1D25                   0x00481602U
#define GPIO_59_EM2D9                    0x00481603U
#define GPIO_59_OUTPUTXBAR2              0x00481605U
#define GPIO_59_SPISTEB                  0x00481606U
#define GPIO_59_SD_C6                    0x00481607U
#define GPIO_59_EM1D4                    0x00481609U
#define GPIO_59_ECAT_LED_LINK1_ACTIVE    0x0048160AU
#define GPIO_59_ENET_MII_TX_DATA0        0x0048160BU
#define GPIO_59_SD_C7                    0x0048160DU
#define GPIO_59_FSIRXD1B                 0x0048160EU
#define GPIO_59_SPISOMIA                 0x0048160FU

#define GPIO_60_GPIO60                   0x00481800U
#define GPIO_60_MCLKRB                   0x00481801U
#define GPIO_60_EM1D24                   0x00481802U
#define GPIO_60_EM2D8                    0x00481803U
#define GPIO_60_OUTPUTXBAR3              0x00481805U
#define GPIO_60_SPISIMOB                 0x00481806U
#define GPIO_60_SD_D7                    0x00481807U
#define GPIO_60_EM1D5                    0x00481809U
#define GPIO_60_ECAT_LED_ERR             0x0048180AU
#define GPIO_60_ENET_MII_TX_DATA1        0x0048180BU
#define GPIO_60_SD_C8                    0x0048180DU
#define GPIO_60_FSIRXCLKB                0x0048180EU
#define GPIO_60_SPICLKA                  0x0048180FU

#define GPIO_61_GPIO61                   0x00481A00U
#define GPIO_61_MFSRB                    0x00481A01U
#define GPIO_61_EM1D23                   0x00481A02U
#define GPIO_61_EM2D7                    0x00481A03U
#define GPIO_61_OUTPUTXBAR4              0x00481A05U
#define GPIO_61_SPISOMIB                 0x00481A06U
#define GPIO_61_SD_C7                    0x00481A07U
#define GPIO_61_EM1D6                    0x00481A09U
#define GPIO_61_ECAT_LED_RUN             0x00481A0AU
#define GPIO_61_ENET_MII_TX_DATA2        0x00481A0BU
#define GPIO_61_CANRXA                   0x00481A0EU
#define GPIO_61_SPISTEA                  0x00481A0FU

#define GPIO_62_GPIO62                   0x00481C00U
#define GPIO_62_SCIRXDC                  0x00481C01U
#define GPIO_62_EM1D22                   0x00481C02U
#define GPIO_62_EM2D6                    0x00481C03U
#define GPIO_62_EQEP3A                   0x00481C05U
#define GPIO_62_CANRXA                   0x00481C06U
#define GPIO_62_SD_D8                    0x00481C07U
#define GPIO_62_EM1D7                    0x00481C09U
#define GPIO_62_ECAT_LED_STATE_RUN       0x00481C0AU
#define GPIO_62_ENET_MII_TX_DATA3        0x00481C0BU
#define GPIO_62_CANTXA                   0x00481C0EU

#define GPIO_63_GPIO63                   0x00481E00U
#define GPIO_63_SCITXDC                  0x00481E01U
#define GPIO_63_EM1D21                   0x00481E02U
#define GPIO_63_EM2D5                    0x00481E03U
#define GPIO_63_EQEP3B                   0x00481E05U
#define GPIO_63_CANTXA                   0x00481E06U
#define GPIO_63_SD_C8                    0x00481E07U
#define GPIO_63_CMSSITXA                 0x00481E09U
#define GPIO_63_ENET_MII_RX_DATA0        0x00481E0BU
#define GPIO_63_SD_D1                    0x00481E0DU
#define GPIO_63_ECAT_RX1_DATA0           0x00481E0EU
#define GPIO_63_SPISIMOB                 0x00481E0FU

#define GPIO_64_GPIO64                   0x00860000U
#define GPIO_64_EM1D20                   0x00860002U
#define GPIO_64_EM2D4                    0x00860003U
#define GPIO_64_EQEP3S                   0x00860005U
#define GPIO_64_SCIRXDA                  0x00860006U
#define GPIO_64_CMSSIRXA                 0x00860009U
#define GPIO_64_ENET_MII_RX_DV           0x0086000AU
#define GPIO_64_ENET_MII_RX_DATA1        0x0086000BU
#define GPIO_64_SD_C1                    0x0086000DU
#define GPIO_64_ECAT_RX1_DATA1           0x0086000EU
#define GPIO_64_SPISOMIB                 0x0086000FU

#define GPIO_65_GPIO65                   0x00860200U
#define GPIO_65_EM1D19                   0x00860202U
#define GPIO_65_EM2D3                    0x00860203U
#define GPIO_65_EQEP3I                   0x00860205U
#define GPIO_65_SCITXDA                  0x00860206U
#define GPIO_65_CMSSICLKA                0x00860209U
#define GPIO_65_ENET_MII_RX_ERR          0x0086020AU
#define GPIO_65_ENET_MII_RX_DATA2        0x0086020BU
#define GPIO_65_SD_D2                    0x0086020DU
#define GPIO_65_ECAT_RX1_DATA2           0x0086020EU
#define GPIO_65_SPICLKB                  0x0086020FU

#define GPIO_66_GPIO66                   0x00860400U
#define GPIO_66_EM1D18                   0x00860402U
#define GPIO_66_EM2D2                    0x00860403U
#define GPIO_66_SDAB                     0x00860406U
#define GPIO_66_CMSSIFSSA                0x00860409U
#define GPIO_66_ENET_MII_RX_DATA0        0x0086040AU
#define GPIO_66_ENET_MII_RX_DATA3        0x0086040BU
#define GPIO_66_SD_C2                    0x0086040DU
#define GPIO_66_ECAT_RX1_DATA3           0x0086040EU
#define GPIO_66_SPISTEB                  0x0086040FU

#define GPIO_67_GPIO67                   0x00860600U
#define GPIO_67_EM1D17                   0x00860602U
#define GPIO_67_EM2D1                    0x00860603U
#define GPIO_67_ENET_MII_RX_CLK          0x0086060AU
#define GPIO_67_ENET_REVMII_MDIO_RST     0x0086060BU
#define GPIO_67_SD_D3                    0x0086060DU

#define GPIO_68_GPIO68                   0x00860800U
#define GPIO_68_EM1D16                   0x00860802U
#define GPIO_68_EM2D0                    0x00860803U
#define GPIO_68_ENET_MII_INTR            0x0086080BU
#define GPIO_68_SD_C3                    0x0086080DU
#define GPIO_68_ECAT_PHY1_LINKSTATUS     0x0086080EU

#define GPIO_69_GPIO69                   0x00860A00U
#define GPIO_69_EM1D15                   0x00860A02U
#define GPIO_69_EMU0                     0x00860A03U
#define GPIO_69_SCLB                     0x00860A06U
#define GPIO_69_ENET_MII_TX_EN           0x00860A0AU
#define GPIO_69_ENET_MII_RX_CLK          0x00860A0BU
#define GPIO_69_SD_D4                    0x00860A0DU
#define GPIO_69_ECAT_RX1_CLK             0x00860A0EU
#define GPIO_69_SPISIMOC                 0x00860A0FU

#define GPIO_70_GPIO70                   0x00860C00U
#define GPIO_70_EM1D14                   0x00860C02U
#define GPIO_70_EMU0                     0x00860C03U
#define GPIO_70_CANRXA                   0x00860C05U
#define GPIO_70_SCITXDB                  0x00860C06U
#define GPIO_70_MCANRXA                  0x00860C09U
#define GPIO_70_ENET_MII_RX_DV           0x00860C0BU
#define GPIO_70_SD_C4                    0x00860C0DU
#define GPIO_70_ECAT_RX1_DV              0x00860C0EU
#define GPIO_70_SPISOMIC                 0x00860C0FU

#define GPIO_71_GPIO71                   0x00860E00U
#define GPIO_71_EM1D13                   0x00860E02U
#define GPIO_71_EMU1                     0x00860E03U
#define GPIO_71_CANTXA                   0x00860E05U
#define GPIO_71_SCIRXDB                  0x00860E06U
#define GPIO_71_MCANTXA                  0x00860E09U
#define GPIO_71_ENET_MII_RX_DATA0        0x00860E0AU
#define GPIO_71_ENET_MII_RX_ERR          0x00860E0BU
#define GPIO_71_ECAT_RX1_ERR             0x00860E0EU
#define GPIO_71_SPICLKC                  0x00860E0FU

#define GPIO_72_GPIO72                   0x00861000U
#define GPIO_72_EM1D12                   0x00861002U
#define GPIO_72_CANTXB                   0x00861005U
#define GPIO_72_SCITXDC                  0x00861006U
#define GPIO_72_ENET_MII_RX_DATA1        0x0086100AU
#define GPIO_72_ENET_MII_TX_DATA3        0x0086100BU
#define GPIO_72_ECAT_TX1_DATA3           0x0086100EU
#define GPIO_72_SPISTEC                  0x0086100FU

#define GPIO_73_GPIO73                   0x00861200U
#define GPIO_73_EM1D11                   0x00861202U
#define GPIO_73_XCLKOUT                  0x00861203U
#define GPIO_73_CANRXB                   0x00861205U
#define GPIO_73_SCIRXDC                  0x00861206U
#define GPIO_73_ENET_RMII_CLK            0x0086120AU
#define GPIO_73_ENET_MII_TX_DATA2        0x0086120BU
#define GPIO_73_SD_D6                    0x0086120DU
#define GPIO_73_ECAT_TX1_DATA2           0x0086120EU

#define GPIO_74_GPIO74                   0x00861400U
#define GPIO_74_EM1D10                   0x00861402U
#define GPIO_74_MCANTXA                  0x00861409U
#define GPIO_74_ENET_MII_TX_DATA1        0x0086140BU
#define GPIO_74_SD_C6                    0x0086140DU
#define GPIO_74_ECAT_TX1_DATA1           0x0086140EU

#define GPIO_75_GPIO75                   0x00861600U
#define GPIO_75_EM1D9                    0x00861602U
#define GPIO_75_MCANRXA                  0x00861609U
#define GPIO_75_ENET_MII_TX_DATA0        0x0086160BU
#define GPIO_75_SD_D7                    0x0086160DU
#define GPIO_75_ECAT_TX1_DATA0           0x0086160EU

#define GPIO_76_GPIO76                   0x00861800U
#define GPIO_76_EM1D8                    0x00861802U
#define GPIO_76_SCITXDD                  0x00861806U
#define GPIO_76_ENET_MII_RX_ERR          0x0086180AU
#define GPIO_76_SD_C7                    0x0086180DU
#define GPIO_76_ECAT_PHY_RESETN          0x0086180EU

#define GPIO_77_GPIO77                   0x00861A00U
#define GPIO_77_EM1D7                    0x00861A02U
#define GPIO_77_SCIRXDD                  0x00861A06U
#define GPIO_77_SD_D8                    0x00861A0DU
#define GPIO_77_ECAT_RX0_CLK             0x00861A0EU

#define GPIO_78_GPIO78                   0x00861C00U
#define GPIO_78_EM1D6                    0x00861C02U
#define GPIO_78_EQEP2A                   0x00861C06U
#define GPIO_78_SD_C8                    0x00861C0DU
#define GPIO_78_ECAT_RX0_DV              0x00861C0EU

#define GPIO_79_GPIO79                   0x00861E00U
#define GPIO_79_EM1D5                    0x00861E02U
#define GPIO_79_EQEP2B                   0x00861E06U
#define GPIO_79_SD_D5                    0x00861E0DU
#define GPIO_79_ECAT_RX0_ERR             0x00861E0EU

#define GPIO_80_GPIO80                   0x00880000U
#define GPIO_80_EM1D4                    0x00880002U
#define GPIO_80_EQEP2S                   0x00880006U
#define GPIO_80_SD_C5                    0x0088000DU
#define GPIO_80_ECAT_RX0_DATA0           0x0088000EU

#define GPIO_81_GPIO81                   0x00880200U
#define GPIO_81_EM1D3                    0x00880202U
#define GPIO_81_EQEP2I                   0x00880206U
#define GPIO_81_ECAT_RX0_DATA1           0x0088020EU

#define GPIO_82_GPIO82                   0x00880400U
#define GPIO_82_EM1D2                    0x00880402U
#define GPIO_82_ECAT_RX0_DATA2           0x0088040EU

#define GPIO_83_GPIO83                   0x00880600U
#define GPIO_83_EM1D1                    0x00880602U
#define GPIO_83_ECAT_RX0_DATA3           0x0088060EU

#define GPIO_84_GPIO84                   0x00880800U
#define GPIO_84_SCITXDA                  0x00880805U
#define GPIO_84_MDXB                     0x00880806U
#define GPIO_84_CMUARTTXA                0x0088080BU
#define GPIO_84_ECAT_TX0_ENA             0x0088080EU
#define GPIO_84_MDXA                     0x0088080FU

#define GPIO_85_GPIO85                   0x00880A00U
#define GPIO_85_EM1D0                    0x00880A02U
#define GPIO_85_SCIRXDA                  0x00880A05U
#define GPIO_85_MDRB                     0x00880A06U
#define GPIO_85_CMUARTRXA                0x00880A0BU
#define GPIO_85_ECAT_TX0_CLK             0x00880A0EU
#define GPIO_85_MDRA                     0x00880A0FU

#define GPIO_86_GPIO86                   0x00880C00U
#define GPIO_86_EM1A13                   0x00880C02U
#define GPIO_86_EM1CAS                   0x00880C03U
#define GPIO_86_SCITXDB                  0x00880C05U
#define GPIO_86_MCLKXB                   0x00880C06U
#define GPIO_86_ECAT_PHY0_LINKSTATUS     0x00880C0EU
#define GPIO_86_MCLKXA                   0x00880C0FU

#define GPIO_87_GPIO87                   0x00880E00U
#define GPIO_87_EM1A14                   0x00880E02U
#define GPIO_87_EM1RAS                   0x00880E03U
#define GPIO_87_SCIRXDB                  0x00880E05U
#define GPIO_87_MFSXB                    0x00880E06U
#define GPIO_87_EM1DQM3                  0x00880E09U
#define GPIO_87_ECAT_TX0_DATA0           0x00880E0EU
#define GPIO_87_MFSXA                    0x00880E0FU

#define GPIO_88_GPIO88                   0x00881000U
#define GPIO_88_EM1A15                   0x00881002U
#define GPIO_88_EM1DQM0                  0x00881003U
#define GPIO_88_EM1DQM1                  0x00881009U
#define GPIO_88_ECAT_TX0_DATA1           0x0088100EU

#define GPIO_89_GPIO89                   0x00881200U
#define GPIO_89_EM1A16                   0x00881202U
#define GPIO_89_EM1DQM1                  0x00881203U
#define GPIO_89_SCITXDC                  0x00881206U
#define GPIO_89_EM1CAS                   0x00881209U
#define GPIO_89_ECAT_TX0_DATA2           0x0088120EU

#define GPIO_90_GPIO90                   0x00881400U
#define GPIO_90_EM1A17                   0x00881402U
#define GPIO_90_EM1DQM2                  0x00881403U
#define GPIO_90_SCIRXDC                  0x00881406U
#define GPIO_90_EM1RAS                   0x00881409U
#define GPIO_90_ECAT_TX0_DATA3           0x0088140EU

#define GPIO_91_GPIO91                   0x00881600U
#define GPIO_91_EM1A18                   0x00881602U
#define GPIO_91_EM1DQM3                  0x00881603U
#define GPIO_91_SDAA                     0x00881606U
#define GPIO_91_EM1DQM2                  0x00881609U
#define GPIO_91_PMBCLK                   0x0088160AU
#define GPIO_91_CMSSITXA                 0x0088160BU
#define GPIO_91_FSIRXD0F                 0x0088160DU
#define GPIO_91_CLBOUTPUTXBAR1           0x0088160EU
#define GPIO_91_SPISIMOD                 0x0088160FU

#define GPIO_92_GPIO92                   0x00881800U
#define GPIO_92_EM1A19                   0x00881802U
#define GPIO_92_EM1BA1                   0x00881803U
#define GPIO_92_SCLA                     0x00881806U
#define GPIO_92_EM1DQM0                  0x00881809U
#define GPIO_92_PMBDAT                   0x0088180AU
#define GPIO_92_CMSSIRXA                 0x0088180BU
#define GPIO_92_FSIRXD1F                 0x0088180DU
#define GPIO_92_CLBOUTPUTXBAR2           0x0088180EU
#define GPIO_92_SPISOMID                 0x0088180FU

#define GPIO_93_GPIO93                   0x00881A00U
#define GPIO_93_EM1A20                   0x00881A02U
#define GPIO_93_EM1BA0                   0x00881A03U
#define GPIO_93_SCITXDD                  0x00881A06U
#define GPIO_93_PMBALERT                 0x00881A0AU
#define GPIO_93_CMSSICLKA                0x00881A0BU
#define GPIO_93_FSIRXCLKF                0x00881A0DU
#define GPIO_93_CLBOUTPUTXBAR3           0x00881A0EU
#define GPIO_93_SPICLKD                  0x00881A0FU

#define GPIO_94_GPIO94                   0x00881C00U
#define GPIO_94_EM1A21                   0x00881C02U
#define GPIO_94_SCIRXDD                  0x00881C06U
#define GPIO_94_EM1BA1                   0x00881C09U
#define GPIO_94_PMBCTRL                  0x00881C0AU
#define GPIO_94_CMSSIFSSA                0x00881C0BU
#define GPIO_94_FSIRXD0G                 0x00881C0DU
#define GPIO_94_CLBOUTPUTXBAR4           0x00881C0EU
#define GPIO_94_SPISTED                  0x00881C0FU

#define GPIO_95_GPIO95                   0x00881E00U
#define GPIO_95_EM2A12                   0x00881E03U
#define GPIO_95_FSIRXD1G                 0x00881E0DU
#define GPIO_95_CLBOUTPUTXBAR5           0x00881E0EU

#define GPIO_96_GPIO96                   0x00C60000U
#define GPIO_96_EM2DQM1                  0x00C60003U
#define GPIO_96_EQEP1A                   0x00C60005U
#define GPIO_96_FSIRXCLKG                0x00C6000DU
#define GPIO_96_CLBOUTPUTXBAR6           0x00C6000EU

#define GPIO_97_GPIO97                   0x00C60200U
#define GPIO_97_EM2DQM0                  0x00C60203U
#define GPIO_97_EQEP1B                   0x00C60205U
#define GPIO_97_FSIRXD0H                 0x00C6020DU
#define GPIO_97_CLBOUTPUTXBAR7           0x00C6020EU

#define GPIO_98_GPIO98                   0x00C60400U
#define GPIO_98_EM2A0                    0x00C60403U
#define GPIO_98_EQEP1S                   0x00C60405U
#define GPIO_98_FSIRXD1H                 0x00C6040DU
#define GPIO_98_CLBOUTPUTXBAR8           0x00C6040EU

#define GPIO_99_GPIO99                   0x00C60600U
#define GPIO_99_EM2A1                    0x00C60603U
#define GPIO_99_EQEP1I                   0x00C60605U
#define GPIO_99_FSIRXCLKH                0x00C6060DU

#define GPIO_100_GPIO100                  0x00C60800U
#define GPIO_100_EM2A2                    0x00C60803U
#define GPIO_100_EQEP2A                   0x00C60805U
#define GPIO_100_SPISIMOC                 0x00C60806U
#define GPIO_100_ECAT_GPI0                0x00C6080AU
#define GPIO_100_FSITXD0A                 0x00C6080DU

#define GPIO_101_GPIO101                  0x00C60A00U
#define GPIO_101_EM2A3                    0x00C60A03U
#define GPIO_101_EQEP2B                   0x00C60A05U
#define GPIO_101_SPISOMIC                 0x00C60A06U
#define GPIO_101_ECAT_GPI1                0x00C60A0AU
#define GPIO_101_FSITXD1A                 0x00C60A0DU

#define GPIO_102_GPIO102                  0x00C60C00U
#define GPIO_102_EM2A4                    0x00C60C03U
#define GPIO_102_EQEP2S                   0x00C60C05U
#define GPIO_102_SPICLKC                  0x00C60C06U
#define GPIO_102_ECAT_GPI2                0x00C60C0AU
#define GPIO_102_FSITXCLKA                0x00C60C0DU

#define GPIO_103_GPIO103                  0x00C60E00U
#define GPIO_103_EM2A5                    0x00C60E03U
#define GPIO_103_EQEP2I                   0x00C60E05U
#define GPIO_103_SPISTEC                  0x00C60E06U
#define GPIO_103_ECAT_GPI3                0x00C60E0AU
#define GPIO_103_FSIRXD0A                 0x00C60E0DU

#define GPIO_104_GPIO104                  0x00C61000U
#define GPIO_104_SDAA                     0x00C61001U
#define GPIO_104_EM2A6                    0x00C61003U
#define GPIO_104_EQEP3A                   0x00C61005U
#define GPIO_104_SCITXDD                  0x00C61006U
#define GPIO_104_ECAT_GPI4                0x00C6100AU
#define GPIO_104_CMI2CSDAA                0x00C6100BU
#define GPIO_104_FSIRXD1A                 0x00C6100DU

#define GPIO_105_GPIO105                  0x00C61200U
#define GPIO_105_SCLA                     0x00C61201U
#define GPIO_105_EM2A7                    0x00C61203U
#define GPIO_105_EQEP3B                   0x00C61205U
#define GPIO_105_SCIRXDD                  0x00C61206U
#define GPIO_105_ECAT_GPI5                0x00C6120AU
#define GPIO_105_CMI2CSCLA                0x00C6120BU
#define GPIO_105_FSIRXCLKA                0x00C6120DU
#define GPIO_105_ENET_MDIO_CLK            0x00C6120EU

#define GPIO_106_GPIO106                  0x00C61400U
#define GPIO_106_EM2A8                    0x00C61403U
#define GPIO_106_EQEP3S                   0x00C61405U
#define GPIO_106_SCITXDC                  0x00C61406U
#define GPIO_106_ECAT_GPI6                0x00C6140AU
#define GPIO_106_FSITXD0B                 0x00C6140DU
#define GPIO_106_ENET_MDIO_DATA           0x00C6140EU

#define GPIO_107_GPIO107                  0x00C61600U
#define GPIO_107_EM2A9                    0x00C61603U
#define GPIO_107_EQEP3I                   0x00C61605U
#define GPIO_107_SCIRXDC                  0x00C61606U
#define GPIO_107_ECAT_GPI7                0x00C6160AU
#define GPIO_107_FSITXD1B                 0x00C6160DU
#define GPIO_107_ENET_REVMII_MDIO_RST     0x00C6160EU

#define GPIO_108_GPIO108                  0x00C61800U
#define GPIO_108_EM2A10                   0x00C61803U
#define GPIO_108_ECAT_GPI8                0x00C6180AU
#define GPIO_108_FSITXCLKB                0x00C6180DU
#define GPIO_108_ENET_MII_INTR            0x00C6180EU

#define GPIO_109_GPIO109                  0x00C61A00U
#define GPIO_109_EM2A11                   0x00C61A03U
#define GPIO_109_ECAT_GPI9                0x00C61A0AU
#define GPIO_109_ENET_MII_CRS             0x00C61A0EU

#define GPIO_110_GPIO110                  0x00C61C00U
#define GPIO_110_EM2WAIT0                 0x00C61C03U
#define GPIO_110_ECAT_GPI10               0x00C61C0AU
#define GPIO_110_FSIRXD0B                 0x00C61C0DU
#define GPIO_110_ENET_MII_COL             0x00C61C0EU

#define GPIO_111_GPIO111                  0x00C61E00U
#define GPIO_111_EM2BA0                   0x00C61E03U
#define GPIO_111_ECAT_GPI11               0x00C61E0AU
#define GPIO_111_FSIRXD1B                 0x00C61E0DU
#define GPIO_111_ENET_MII_RX_CLK          0x00C61E0EU

#define GPIO_112_GPIO112                  0x00C80000U
#define GPIO_112_EM2BA1                   0x00C80003U
#define GPIO_112_ECAT_GPI12               0x00C8000AU
#define GPIO_112_FSIRXCLKB                0x00C8000DU
#define GPIO_112_ENET_MII_RX_DV           0x00C8000EU

#define GPIO_113_GPIO113                  0x00C80200U
#define GPIO_113_EM2CAS                   0x00C80203U
#define GPIO_113_ECAT_GPI13               0x00C8020AU
#define GPIO_113_ENET_MII_RX_ERR          0x00C8020EU

#define GPIO_114_GPIO114                  0x00C80400U
#define GPIO_114_EM2RAS                   0x00C80403U
#define GPIO_114_ECAT_GPI14               0x00C8040AU
#define GPIO_114_ENET_MII_RX_DATA0        0x00C8040EU

#define GPIO_115_GPIO115                  0x00C80600U
#define GPIO_115_EM2CS0N                  0x00C80603U
#define GPIO_115_OUTPUTXBAR5              0x00C80605U
#define GPIO_115_ECAT_GPI15               0x00C8060AU
#define GPIO_115_FSIRXD0C                 0x00C8060DU
#define GPIO_115_ENET_MII_RX_DATA1        0x00C8060EU

#define GPIO_116_GPIO116                  0x00C80800U
#define GPIO_116_EM2CS2N                  0x00C80803U
#define GPIO_116_OUTPUTXBAR6              0x00C80805U
#define GPIO_116_ECAT_GPI16               0x00C8080AU
#define GPIO_116_FSIRXD1C                 0x00C8080DU
#define GPIO_116_ENET_MII_RX_DATA2        0x00C8080EU

#define GPIO_117_GPIO117                  0x00C80A00U
#define GPIO_117_EM2SDCKE                 0x00C80A03U
#define GPIO_117_ECAT_GPI17               0x00C80A0AU
#define GPIO_117_FSIRXCLKC                0x00C80A0DU
#define GPIO_117_ENET_MII_RX_DATA3        0x00C80A0EU

#define GPIO_118_GPIO118                  0x00C80C00U
#define GPIO_118_EM2CLK                   0x00C80C03U
#define GPIO_118_ECAT_GPI18               0x00C80C0AU
#define GPIO_118_FSIRXD0D                 0x00C80C0DU
#define GPIO_118_ENET_MII_TX_EN           0x00C80C0EU

#define GPIO_119_GPIO119                  0x00C80E00U
#define GPIO_119_EM2RNW                   0x00C80E03U
#define GPIO_119_ECAT_GPI19               0x00C80E0AU
#define GPIO_119_FSIRXD1D                 0x00C80E0DU
#define GPIO_119_ENET_MII_TX_ERR          0x00C80E0EU

#define GPIO_120_GPIO120                  0x00C81000U
#define GPIO_120_EM2WEN                   0x00C81003U
#define GPIO_120_ECAT_GPI20               0x00C8100AU
#define GPIO_120_FSIRXCLKD                0x00C8100DU
#define GPIO_120_ENET_MII_TX_CLK          0x00C8100EU
#define GPIO_120_USB0PFLT                 0x00C8100FU

#define GPIO_121_GPIO121                  0x00C81200U
#define GPIO_121_EM2OEN                   0x00C81203U
#define GPIO_121_ECAT_GPI21               0x00C8120AU
#define GPIO_121_FSIRXD0E                 0x00C8120DU
#define GPIO_121_ENET_MII_TX_DATA0        0x00C8120EU
#define GPIO_121_USB0EPEN                 0x00C8120FU

#define GPIO_122_GPIO122                  0x00C81400U
#define GPIO_122_EM2D15                   0x00C81403U
#define GPIO_122_SPISIMOC                 0x00C81406U
#define GPIO_122_SD_D1                    0x00C81407U
#define GPIO_122_ECAT_GPI22               0x00C8140AU
#define GPIO_122_ENET_MII_TX_DATA1        0x00C8140EU
#define GPIO_122_ODISCHRGVBUS             0x00C8140FU

#define GPIO_123_GPIO123                  0x00C81600U
#define GPIO_123_EM2D14                   0x00C81603U
#define GPIO_123_SPISOMIC                 0x00C81606U
#define GPIO_123_SD_C1                    0x00C81607U
#define GPIO_123_ECAT_GPI23               0x00C8160AU
#define GPIO_123_ENET_MII_TX_DATA2        0x00C8160EU
#define GPIO_123_OCHRGVBUS                0x00C8160FU

#define GPIO_124_GPIO124                  0x00C81800U
#define GPIO_124_EM2D13                   0x00C81803U
#define GPIO_124_SPICLKC                  0x00C81806U
#define GPIO_124_SD_D2                    0x00C81807U
#define GPIO_124_ECAT_GPI24               0x00C8180AU
#define GPIO_124_ENET_MII_TX_DATA3        0x00C8180EU
#define GPIO_124_ODMPULLDN                0x00C8180FU

#define GPIO_125_GPIO125                  0x00C81A00U
#define GPIO_125_EM2D12                   0x00C81A03U
#define GPIO_125_SPISTEC                  0x00C81A06U
#define GPIO_125_SD_C2                    0x00C81A07U
#define GPIO_125_ECAT_GPI25               0x00C81A0AU
#define GPIO_125_FSIRXD1E                 0x00C81A0DU
#define GPIO_125_ECAT_LATCH0              0x00C81A0EU
#define GPIO_125_ODPPULLDN                0x00C81A0FU

#define GPIO_126_GPIO126                  0x00C81C00U
#define GPIO_126_EM2D11                   0x00C81C03U
#define GPIO_126_SD_D3                    0x00C81C07U
#define GPIO_126_ECAT_GPI26               0x00C81C0AU
#define GPIO_126_FSIRXCLKE                0x00C81C0DU
#define GPIO_126_ECAT_LATCH1              0x00C81C0EU
#define GPIO_126_OLSD_2_N                 0x00C81C0FU

#define GPIO_127_GPIO127                  0x00C81E00U
#define GPIO_127_EM2D10                   0x00C81E03U
#define GPIO_127_SD_C3                    0x00C81E07U
#define GPIO_127_ECAT_GPI27               0x00C81E0AU
#define GPIO_127_ECAT_SYNC0               0x00C81E0EU
#define GPIO_127_OLSD_1_N                 0x00C81E0FU

#define GPIO_128_GPIO128                  0x01060000U
#define GPIO_128_EM2D9                    0x01060003U
#define GPIO_128_SD_D4                    0x01060007U
#define GPIO_128_ECAT_GPI28               0x0106000AU
#define GPIO_128_ECAT_SYNC1               0x0106000EU
#define GPIO_128_OIDPULLUP                0x0106000FU

#define GPIO_129_GPIO129                  0x01060200U
#define GPIO_129_EM2D8                    0x01060203U
#define GPIO_129_SD_C4                    0x01060207U
#define GPIO_129_ECAT_GPI29               0x0106020AU
#define GPIO_129_ECAT_TX1_ENA             0x0106020EU
#define GPIO_129_OSPEED                   0x0106020FU

#define GPIO_130_GPIO130                  0x01060400U
#define GPIO_130_EM2D7                    0x01060403U
#define GPIO_130_SD_D5                    0x01060407U
#define GPIO_130_ECAT_GPI30               0x0106040AU
#define GPIO_130_ECAT_TX1_CLK             0x0106040EU
#define GPIO_130_OSUSPEND                 0x0106040FU

#define GPIO_131_GPIO131                  0x01060600U
#define GPIO_131_EM2D6                    0x01060603U
#define GPIO_131_SD_C5                    0x01060607U
#define GPIO_131_ECAT_GPI31               0x0106060AU
#define GPIO_131_ECAT_TX1_DATA0           0x0106060EU
#define GPIO_131_OOE                      0x0106060FU

#define GPIO_132_GPIO132                  0x01060800U
#define GPIO_132_EM2D5                    0x01060803U
#define GPIO_132_SD_D6                    0x01060807U
#define GPIO_132_ECAT_GPO0                0x0106080AU
#define GPIO_132_ECAT_TX1_DATA1           0x0106080EU
#define GPIO_132_ODMSE0                   0x0106080FU

#define GPIO_133_GPIO133                  0x01060A00U
#define GPIO_133_SD_C6                    0x01060A07U
#define GPIO_133_ODPDAT                   0x01060A0FU

#define GPIO_134_GPIO134                  0x01060C00U
#define GPIO_134_EM2D4                    0x01060C03U
#define GPIO_134_SD_D7                    0x01060C07U
#define GPIO_134_ECAT_GPO1                0x01060C0AU
#define GPIO_134_ECAT_TX1_DATA2           0x01060C0EU
#define GPIO_134_IVBUSVALID               0x01060C0FU

#define GPIO_135_GPIO135                  0x01060E00U
#define GPIO_135_EM2D3                    0x01060E03U
#define GPIO_135_SCITXDA                  0x01060E06U
#define GPIO_135_SD_C7                    0x01060E07U
#define GPIO_135_ECAT_GPO2                0x01060E0AU
#define GPIO_135_ECAT_TX1_DATA3           0x01060E0EU

#define GPIO_136_GPIO136                  0x01061000U
#define GPIO_136_EM2D2                    0x01061003U
#define GPIO_136_SCIRXDA                  0x01061006U
#define GPIO_136_SD_D8                    0x01061007U
#define GPIO_136_ECAT_GPO3                0x0106100AU
#define GPIO_136_ECAT_RX1_DV              0x0106100EU

#define GPIO_137_GPIO137                  0x01061200U
#define GPIO_137_EPWM13A                  0x01061201U
#define GPIO_137_EM2D1                    0x01061203U
#define GPIO_137_SCITXDB                  0x01061206U
#define GPIO_137_SD_C8                    0x01061207U
#define GPIO_137_ECAT_GPO4                0x0106120AU
#define GPIO_137_ECAT_RX1_CLK             0x0106120EU

#define GPIO_138_GPIO138                  0x01061400U
#define GPIO_138_EPWM13B                  0x01061401U
#define GPIO_138_EM2D0                    0x01061403U
#define GPIO_138_SCIRXDB                  0x01061406U
#define GPIO_138_ECAT_GPO5                0x0106140AU
#define GPIO_138_ECAT_RX1_ERR             0x0106140EU

#define GPIO_139_GPIO139                  0x01061600U
#define GPIO_139_EPWM14A                  0x01061601U
#define GPIO_139_SCIRXDC                  0x01061606U
#define GPIO_139_ECAT_GPO6                0x0106160AU
#define GPIO_139_ECAT_RX1_DATA0           0x0106160EU

#define GPIO_140_GPIO140                  0x01061800U
#define GPIO_140_EPWM14B                  0x01061801U
#define GPIO_140_SCITXDC                  0x01061806U
#define GPIO_140_ECAT_GPO7                0x0106180AU
#define GPIO_140_ECAT_RX1_DATA1           0x0106180EU

#define GPIO_141_GPIO141                  0x01061A00U
#define GPIO_141_EPWM15A                  0x01061A01U
#define GPIO_141_SCIRXDD                  0x01061A06U
#define GPIO_141_ECAT_GPO8                0x01061A0AU
#define GPIO_141_ECAT_RX1_DATA2           0x01061A0EU

#define GPIO_142_GPIO142                  0x01061C00U
#define GPIO_142_EPWM15B                  0x01061C01U
#define GPIO_142_SCITXDD                  0x01061C06U
#define GPIO_142_ECAT_GPO9                0x01061C0AU
#define GPIO_142_ECAT_RX1_DATA3           0x01061C0EU

#define GPIO_143_GPIO143                  0x01061E00U
#define GPIO_143_EPWM16A                  0x01061E01U
#define GPIO_143_ECAT_GPO10               0x01061E0AU
#define GPIO_143_ECAT_LED_LINK0_ACTIVE    0x01061E0EU

#define GPIO_144_GPIO144                  0x01080000U
#define GPIO_144_EPWM16B                  0x01080001U
#define GPIO_144_ECAT_GPO11               0x0108000AU
#define GPIO_144_ECAT_LED_LINK1_ACTIVE    0x0108000EU

#define GPIO_145_GPIO145                  0x01080200U
#define GPIO_145_EPWM1A                   0x01080201U
#define GPIO_145_ECAT_GPO12               0x0108020AU
#define GPIO_145_ECAT_LED_ERR             0x0108020EU

#define GPIO_146_GPIO146                  0x01080400U
#define GPIO_146_EPWM1B                   0x01080401U
#define GPIO_146_ECAT_GPO13               0x0108040AU
#define GPIO_146_ECAT_LED_RUN             0x0108040EU

#define GPIO_147_GPIO147                  0x01080600U
#define GPIO_147_EPWM2A                   0x01080601U
#define GPIO_147_ECAT_GPO14               0x0108060AU
#define GPIO_147_ECAT_LED_STATE_RUN       0x0108060EU

#define GPIO_148_GPIO148                  0x01080800U
#define GPIO_148_EPWM2B                   0x01080801U
#define GPIO_148_ECAT_GPO15               0x0108080AU
#define GPIO_148_ECAT_PHY0_LINKSTATUS     0x0108080EU

#define GPIO_149_GPIO149                  0x01080A00U
#define GPIO_149_EPWM3A                   0x01080A01U
#define GPIO_149_ECAT_GPO16               0x01080A0AU
#define GPIO_149_ECAT_PHY1_LINKSTATUS     0x01080A0EU

#define GPIO_150_GPIO150                  0x01080C00U
#define GPIO_150_EPWM3B                   0x01080C01U
#define GPIO_150_ECAT_GPO17               0x01080C0AU
#define GPIO_150_ECAT_I2C_SDA             0x01080C0EU

#define GPIO_151_GPIO151                  0x01080E00U
#define GPIO_151_EPWM4A                   0x01080E01U
#define GPIO_151_ECAT_GPO18               0x01080E0AU
#define GPIO_151_ECAT_I2C_SCL             0x01080E0EU

#define GPIO_152_GPIO152                  0x01081000U
#define GPIO_152_EPWM4B                   0x01081001U
#define GPIO_152_ECAT_GPO19               0x0108100AU
#define GPIO_152_ECAT_MDIO_CLK            0x0108100EU

#define GPIO_153_GPIO153                  0x01081200U
#define GPIO_153_EPWM5A                   0x01081201U
#define GPIO_153_ECAT_GPO20               0x0108120AU
#define GPIO_153_ECAT_MDIO_DATA           0x0108120EU

#define GPIO_154_GPIO154                  0x01081400U
#define GPIO_154_EPWM5B                   0x01081401U
#define GPIO_154_ECAT_GPO21               0x0108140AU
#define GPIO_154_ECAT_PHY_CLK             0x0108140EU

#define GPIO_155_GPIO155                  0x01081600U
#define GPIO_155_EPWM6A                   0x01081601U
#define GPIO_155_ECAT_GPO22               0x0108160AU
#define GPIO_155_ECAT_PHY_RESETN          0x0108160EU

#define GPIO_156_GPIO156                  0x01081800U
#define GPIO_156_EPWM6B                   0x01081801U
#define GPIO_156_ECAT_GPO23               0x0108180AU
#define GPIO_156_ECAT_TX0_ENA             0x0108180EU

#define GPIO_157_GPIO157                  0x01081A00U
#define GPIO_157_EPWM7A                   0x01081A01U
#define GPIO_157_ECAT_GPO24               0x01081A0AU
#define GPIO_157_ECAT_TX0_CLK             0x01081A0EU

#define GPIO_158_GPIO158                  0x01081C00U
#define GPIO_158_EPWM7B                   0x01081C01U
#define GPIO_158_ECAT_GPO25               0x01081C0AU
#define GPIO_158_ECAT_TX0_DATA0           0x01081C0EU

#define GPIO_159_GPIO159                  0x01081E00U
#define GPIO_159_EPWM8A                   0x01081E01U
#define GPIO_159_ECAT_GPO26               0x01081E0AU
#define GPIO_159_ECAT_TX0_DATA1           0x01081E0EU

#define GPIO_160_GPIO160                  0x01460000U
#define GPIO_160_EPWM8B                   0x01460001U
#define GPIO_160_ECAT_GPO27               0x0146000AU
#define GPIO_160_ECAT_TX0_DATA2           0x0146000EU

#define GPIO_161_GPIO161                  0x01460200U
#define GPIO_161_EPWM9A                   0x01460201U
#define GPIO_161_ECAT_GPO28               0x0146020AU
#define GPIO_161_ECAT_TX0_DATA3           0x0146020EU

#define GPIO_162_GPIO162                  0x01460400U
#define GPIO_162_EPWM9B                   0x01460401U
#define GPIO_162_ECAT_GPO29               0x0146040AU
#define GPIO_162_ECAT_RX0_DV              0x0146040EU

#define GPIO_163_GPIO163                  0x01460600U
#define GPIO_163_EPWM10A                  0x01460601U
#define GPIO_163_ECAT_GPO30               0x0146060AU
#define GPIO_163_ECAT_RX0_CLK             0x0146060EU

#define GPIO_164_GPIO164                  0x01460800U
#define GPIO_164_EPWM10B                  0x01460801U
#define GPIO_164_ECAT_GPO31               0x0146080AU
#define GPIO_164_ECAT_RX0_ERR             0x0146080EU

#define GPIO_165_GPIO165                  0x01460A00U
#define GPIO_165_EPWM11A                  0x01460A01U
#define GPIO_165_MDXA                     0x01460A0AU
#define GPIO_165_ECAT_RX0_DATA0           0x01460A0EU

#define GPIO_166_GPIO166                  0x01460C00U
#define GPIO_166_EPWM11B                  0x01460C01U
#define GPIO_166_MDRA                     0x01460C0AU
#define GPIO_166_ECAT_RX0_DATA1           0x01460C0EU

#define GPIO_167_GPIO167                  0x01460E00U
#define GPIO_167_EPWM12A                  0x01460E01U
#define GPIO_167_MCLKXA                   0x01460E0AU
#define GPIO_167_ECAT_RX0_DATA2           0x01460E0EU

#define GPIO_168_GPIO168                  0x01461000U
#define GPIO_168_EPWM12B                  0x01461001U
#define GPIO_168_MFSXA                    0x0146100AU
#define GPIO_168_ECAT_RX0_DATA3           0x0146100EU

#endif // __PIN_MAP_H__
