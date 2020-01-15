//###########################################################################
//
// FILE:   pdi_test_app.c
//
// TITLE:  EtherCAT PDI (Processor Data Interface) example for F2838x CPU1
//
// F2838x CPU1 PDI Interface Test App
//
// This example tests the F2838x CPU1 EtherCAT PDI and demonstrates usage of
// the EtherCAT CPU1 HAL drivers. The example should be run on a F2838x
// controlCARD.
//
// External Connections
//  The controlCARD RJ45 port 0 is connected to PC running TwinCAT master
//
// Watch Variables
//  ESC_escRegs (ESC stands for EtherCAT Slave Controller) data structure will
//  be constantly updated to show the latest values of the specified ESC
//  registers
//
//#############################################################################
// $TI Release: F2838x EtherCAT Software v2.00.00.00 $
// $Release Date: Mon May 27 07:11:43 CDT 2019 $
// $Copyright:
// Copyright (C) 2019 Texas Instruments Incorporated - http://www.ti.com/
//
// Redistribution and use in source and binary forms, with or without 
// modification, are permitted provided that the following conditions 
// are met:
// 
//   Redistributions of source code must retain the above copyright 
//   notice, this list of conditions and the following disclaimer.
// 
//   Redistributions in binary form must reproduce the above copyright
//   notice, this list of conditions and the following disclaimer in the 
//   documentation and/or other materials provided with the   
//   distribution.
// 
//   Neither the name of Texas Instruments Incorporated nor the names of
//   its contributors may be used to endorse or promote products derived
//   from this software without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// $
//#############################################################################

//
// Included Files
//
#include "ethercat_slave_cpu1_hal.h"

//
// Main
//
void main()
{
    uint16_t initStatus;

    //
    // Initialize CPU1 and HAL interface
    //
    initStatus = ESC_initHW();

    //
    // Loop and signal error if initHW returns failure
    //
    if(initStatus == ESC_HW_INIT_FAIL)
    {
        while(1)
        {
            //
            // Toggle Error
            //
            ESC_signalFail();
        }
    }

    //
    // Setup and perform PDI Test
    //
    ESC_setupPDITestInterface();

    //
    // Update local RAM with ESC register values for debugging
    //
    while(1)
    {
        ESC_debugUpdateESCRegLogs();
        DEVICE_DELAY_US((uint32_t)(50000));
    }
}

//
// End of File
//
