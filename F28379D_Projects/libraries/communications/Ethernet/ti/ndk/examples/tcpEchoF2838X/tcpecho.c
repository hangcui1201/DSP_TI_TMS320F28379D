/*
 * Copyright (c) 2014-2018, Texas Instruments Incorporated
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
 *    ======== tcpecho.c ========
 */

#include <xdc/std.h>
#include <xdc/runtime/System.h>

#include <string.h>
#include <stdint.h>

#include <pthread.h>

#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#include <ti/net/slnetutils.h>

#define TCPPORT 1000
#define TCPPACKETSIZE 256
#define NUMTCPWORKERS 3

extern void fdOpenSession();
extern void fdCloseSession();
extern void *TaskSelf();

extern void myPing(uint32_t IPAddr, int rrop);
extern void myDumpSockets(int protocol);

/*
 *  ======== tcpWorker ========
 *  Task to handle TCP connection. There may be multiple Tasks running
 *  this function.
 */
void *tcpWorker(void *arg0)
{
    int  clientfd = *(int *)arg0;
    int  bytesRcvd;
    int  bytesSent;
    char buffer[TCPPACKETSIZE];

    fdOpenSession(TaskSelf());

    System_printf("tcpWorker: start clientfd = 0x%x\n", clientfd);

    while ((bytesRcvd = recv(clientfd, buffer, TCPPACKETSIZE, 0)) > 0) {
        bytesSent = send(clientfd, buffer, bytesRcvd, 0);
        if (bytesSent < 0 || bytesSent != bytesRcvd) {
            System_printf("send failed.\n");
            break;
        }
    }
    System_printf("tcpWorker stop clientfd = 0x%x\n", clientfd);

    close(clientfd);

    fdCloseSession(TaskSelf());

    return (NULL);
}

/*
 *  ======== tcpHandler ========
 *  Creates new Task to handle new TCP connections.
 */
void *tcpHandler(void *arg0)
{
    pthread_t          thread;
    pthread_attr_t     attrs;
    struct sched_param priParam;
    int                retc;
    int                detachState;
    int                status;
    int                server;
    struct sockaddr_in localAddr;
    struct sockaddr_in clientAddr;
    int                optval;
    static int         clientfd;
    int                optlen = sizeof(optval);
    socklen_t          addrlen = sizeof(clientAddr);
    uint16_t           portNumber = TCPPORT;

    fdOpenSession(TaskSelf());

    System_printf("TCP Echo example started\n");

    server = socket(AF_INET, SOCK_STREAM, 0);
    if (server == -1) {
        System_printf("tcpHandler: socket failed\n");
        goto shutdown;
    }

    memset(&localAddr, 0, sizeof(localAddr));
    localAddr.sin_family = AF_INET;
    localAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    localAddr.sin_port = htons(portNumber);

    status = bind(server, (struct sockaddr *)&localAddr, sizeof(localAddr));
    if (status == -1) {
        System_printf("tcpHandler: bind failed\n");
        goto shutdown;
    }

    status = listen(server, NUMTCPWORKERS);
    if (status == -1) {
        System_printf("tcpHandler: listen failed\n");
        goto shutdown;
    }

    optval = 1;
    status = setsockopt(server, SOL_SOCKET, SO_KEEPALIVE, &optval, optlen);
    if (status == -1) {
        System_printf("tcpHandler: setsockopt failed\n");
        goto shutdown;
    }


    while ((clientfd =
            accept(server, (struct sockaddr *)&clientAddr, &addrlen)) != -1) {

        System_printf("tcpHandler: Creating thread clientfd = %x\n", clientfd);

        /* Set priority and stack size attributes */
        pthread_attr_init(&attrs);
        priParam.sched_priority = 3;

        detachState = PTHREAD_CREATE_DETACHED;
        retc = pthread_attr_setdetachstate(&attrs, detachState);
        if (retc != 0) {
            System_printf("tcpHandler: pthread_attr_setdetachstate() failed");
            while (1);
        }

        pthread_attr_setschedparam(&attrs, &priParam);

        retc |= pthread_attr_setstacksize(&attrs, 1536);
        if (retc != 0) {
            System_printf("tcpHandler: pthread_attr_setstacksize() failed");
            while (1);
        }

        retc = pthread_create(&thread, &attrs, tcpWorker, (void *)&clientfd);
        if (retc != 0) {
            System_printf("tcpHandler: pthread_create() failed");
            while (1);
        }

        /* addrlen is a value-result param, must reset for next accept call */
        addrlen = sizeof(clientAddr);
    }

    System_printf("tcpHandler: accept failed.\n");

shutdown:
    if (server != -1) {
        close(server);
    }

    fdCloseSession(TaskSelf());

    return (NULL);
}
