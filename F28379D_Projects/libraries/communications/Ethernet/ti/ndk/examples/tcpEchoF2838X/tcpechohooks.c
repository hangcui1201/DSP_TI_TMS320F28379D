/*
 * Copyright (c) 2018-2019 Texas Instruments Incorporated - http://www.ti.com
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 *    ======== tcpechohooks.c ========
 */

/* xdc headers */
#include <xdc/std.h>
#include <xdc/runtime/System.h>

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#include <ti/ndk/inc/netmain.h>

#include <ti/ndk/slnetif/slnetifndk.h>
#include <ti/net/slnetif.h>
#include <ti/net/slnetutils.h>

#define TCPHANDLERSTACK 1536
#define IFPRI  4   /* Ethernet interface priority */

/* Prototypes */
// TODO change to pthread signature
extern void tcpHandler(uint32_t arg0, uint32_t arg1);

/*
 *  ======== netIPAddrHook ========
 *  user defined network IP address hook
 */
void netIPAddrHook(uint32_t IPAddr, unsigned int IfIdx, unsigned int fAdd)
{
    uint32_t hostByteAddr;
    static bool createTask = true;
    void *taskHandle = NULL;
    int32_t status = 0;

    if (fAdd) {
        System_printf("Network Added: ");
    }
    else {
        System_printf("Network Removed: ");
    }

    /* print the IP address that was added/removed */
    hostByteAddr = NDK_ntohl(IPAddr);
    System_printf("If-%d:%d.%d.%d.%d\n", IfIdx,
            (uint8_t)(hostByteAddr>>24)&0xFF, (uint8_t)(hostByteAddr>>16)&0xFF,
            (uint8_t)(hostByteAddr>>8)&0xFF, (uint8_t)hostByteAddr&0xFF);


    status = SlNetSock_init(0);
    if (status != 0) {
        System_printf("SlNetSock_init fail (%d)\n", status);
    }

    status = SlNetIf_init(0);
    if (status != 0) {
        System_printf("SlNetIf_init fail (%d)\n", status);
    }

    status = SlNetUtil_init(0);
    if (status != 0) {
        System_printf("SlNetUtil_init fail (%d)\n", status);
    }

    status = SlNetIf_add(SLNETIF_ID_2, "eth0",
                         (const SlNetIf_Config_t *)&SlNetIfConfigNDK, IFPRI);
    if (status != 0) {
        System_printf("SlNetIf_add fail (%d)\n", status);
    }

    if (fAdd && createTask) {
        /*
         *  Create the Task that farms out incoming TCP connections.
         *  arg0 will be the port that this task listens to.
         */
        // TODO: change to pthread
        taskHandle = TaskCreate(tcpHandler, NULL, 1, TCPHANDLERSTACK, 0, 0, 0);
        if (!taskHandle)
        {
            /* netOpenHook: Failed to create tcpHandler thread */
            while (1);
        }

        createTask = false;
    }
}

/*
 *  ======== serviceReportHook ========
 *  NDK service report hook
 */
void serviceReportHook(uint32_t item, uint32_t status, uint32_t report, void *h)
{
    static char *taskName[] = {"Telnet", "HTTP", "NAT", "DHCPS", "DHCPC", "DNS"};
    static char *reportStr[] = {"", "Running", "Updated", "Complete", "Fault"};
    static char *statusStr[] =
        {"Disabled", "Waiting", "IPTerm", "Failed","Enabled"};

    System_printf("Service Status: %-9s: %-9s: %-9s: %03d\n",
            taskName[item - 1], statusStr[status], reportStr[report / 256],
            report & 0xFF);
}


/*
 *  ======== netOpenHook ========
 *  NDK network open hook
 */
void netOpenHook()
{
}
