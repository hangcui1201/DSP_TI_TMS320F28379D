/* net.c */

#include "ptpd.h"

/*--- Added for TI F2838x device support */
#include "utils/lwiplib.h"
#include "utils/ptpdlib.h"
#include "lwip/inet.h"
/* Added for TI F2838x device support ---*/

/*--- Added for TI F2838x device support */
/*
 * TI F2838x port info note:
 * A structure used to keep track of messages count at the network layer.
 */
typedef struct {
    uint32_t rxEventMsgCount;
    uint32_t recvEventCount;
    uint32_t rxGeneralMsgCount;
    uint32_t recvGeneralCount;
    uint32_t rxEventErrorCount;
    uint32_t rxGeneralErrorCount;
    uint32_t sendEventCount;
    uint32_t sendGeneralCount;
    uint32_t rxInitError;
    uint32_t txInitError;
}
PtpdNetStats;

PtpdNetStats ptpdNetStats = {0};

#define PTPD_NET_STATS_INC(x) do{ ptpdNetStats.x++; } while(0)
#define PTPD_NET_STATS_DEC(x) do{ ptpdNetStats.x--; } while(0)
#define PTPD_NET_STATS_ADD(x, inc) do{ ptpdNetStats.x += inc; } while(0)
#define PTPD_NET_STATS_SUB(x, dec) do{ ptpdNetStats.x -= dec; } while(0)

/* Network Buffer Queue Functions. */
static void netQInit(BufQueue *pQ)
{
  pQ->get = 0;
  pQ->put = 0;
  pQ->count = 0;
}

static Integer32 netQPut(BufQueue *pQ, void *pbuf)
{
  if(pQ->count >= PBUF_QUEUE_SIZE)
    return FALSE;
  pQ->pbuf[pQ->put] = pbuf;
  pQ->put = (pQ->put + 1) % PBUF_QUEUE_SIZE;
  pQ->count++;
  return TRUE;
}

void *netQGet(BufQueue *pQ)
{
  void *pbuf;

  if(!pQ->count)
    return NULL;
  pbuf = pQ->pbuf[pQ->get];
  pQ->get = (pQ->get + 1) % PBUF_QUEUE_SIZE;
  pQ->count--;
  return pbuf;
}

static Integer32 netQCheck(BufQueue *pQ)
{
  if(!pQ->count)
    return FALSE;
  return TRUE;
}

/* Processing an incoming message on the Event port. */
static void eventRecv(void *arg, struct udp_pcb *pcb, struct pbuf *p,
                      const ip_addr_t *addr, u16_t port)
{
  NetPath *netPath = (NetPath *)arg;

  /* prevent warnings about unused arguments */
  (void)pcb; (void)addr; (void)port;

  /* Place the incoming message on the Event Port QUEUE. */
  if(!netQPut(&netPath->eventQ, p))
  {
    PERROR("Event Queue Full!\n");
    PTPD_NET_STATS_INC(rxEventErrorCount);
  }
  else
  {
      PTPD_NET_STATS_INC(rxEventMsgCount);
  }
}

/* Processing an incoming message on the Event port. */
static void generalRecv(void *arg, struct udp_pcb *pcb, struct pbuf *p,
                        const ip_addr_t *addr, u16_t port)
{
  NetPath *netPath = (NetPath *)arg;

  /* prevent warnings about unused arguments */
  (void)pcb; (void)addr; (void)port;

  /* Place the incoming message on the Event Port QUEUE. */
    if(!netQPut(&netPath->generalQ, p))
    {
        PERROR("Event Queue Full!\n");
        PTPD_NET_STATS_INC(rxGeneralErrorCount);
    }
    else
    {
        PTPD_NET_STATS_INC(rxGeneralMsgCount);
    }
}
/* Added for TI F2838x device support ---*/

/*
 * TI F2838x port info note: Modified
 * The vanilla implementation uses sockets to achieve networking. The current
 * F2838x port doesn't use OS and hence a custom method to handle ptp packets
 * is implemented.
 */
/* shut down the UDP stuff */
Boolean 
netShutdown(NetPath * netPath)
{
	 /* Disconnect and close the Event UDP interface */
	  if(netPath->eventPcb)
	  {
	    udp_disconnect(netPath->eventPcb);
	    udp_remove(netPath->eventPcb);
	  }

	  /* Disconnect and close the General UDP interface */
	  if(netPath->generalPcb)
	  {
	    udp_disconnect(netPath->generalPcb);
	    udp_remove(netPath->generalPcb);
	  }

	  /* Free up the Event and General Tx PBUFs. */
	  if(netPath->eventTxBuf)
	  {
	    pbuf_free(netPath->eventTxBuf);
	  }
	  if(netPath->generalTxBuf)
	  {
	    pbuf_free(netPath->generalTxBuf);
	  }

	  /* Clear the network addresses. */
	  netPath->multicastAddr = 0;
	  netPath->unicastAddr = 0;

	  /* Return a success code. */
	  return TRUE;
}

/*
 * This is a replacement for lookupSubdomainAddress API from the previous ports.
 * TODO: For now, this not done by default. Figure out why that is the case.
 */
Boolean
chooseMcastGroup(RunTimeOpts * rtOpts, struct in_addr *netAddr)
{

	char *addrStr;

#ifdef PTP_EXPERIMENTAL
	switch(rtOpts->mcast_group_Number){
	case 0:
		addrStr = DEFAULT_PTP_DOMAIN_ADDRESS;
		break;

	case 1:
		addrStr = ALTERNATE_PTP_DOMAIN1_ADDRESS;
		break;
	case 2:
		addrStr = ALTERNATE_PTP_DOMAIN2_ADDRESS;
		break;
	case 3:
		addrStr = ALTERNATE_PTP_DOMAIN3_ADDRESS;
		break;

	default:
		ERROR("Unk group %d\n", rtOpts->mcast_group_Number);
		exit(3);
		break;
	}
#else
	addrStr = DEFAULT_PTP_DOMAIN_ADDRESS;
#endif

	if (!inet_aton(addrStr, netAddr)) {
		ERROR("failed to encode multicast address: %s\n", addrStr);
		return FALSE;
	}
	return TRUE;
}

/*
 * TI F2838x port info note: Modified
 * The vanilla implementation uses sockets to achieve networking. The current
 * F2838x port doesn't use OS and hence a custom method to handle ptp packets
 * is implemented.
 */

/**
 * start all of the UDP stuff 
 * must specify 'subdomainName', and optionally 'ifaceName', 
 * if not then pass ifaceName == "" 
 * on socket options, see the 'socket(7)' and 'ip' man pages 
 *
 * @param netPath 
 * @param rtOpts 
 * @param ptpClock 
 * 
 * @return TRUE if successful
 */
Boolean 
netInit(NetPath * netPath, RunTimeOpts * rtOpts, PtpClock * ptpClock)
{
	struct in_addr netAddr;
	ip4_addr_t ip4Addr;

	DBG("netInit\n");

    /* Allocate tx buffer for the event port. */
    netPath->eventTxBuf = pbuf_alloc(PBUF_TRANSPORT, PACKET_SIZE, PBUF_RAM);
    if(netPath->eventTxBuf == NULL)
    {
    PERROR("Failed to allocate Event Tx Buffer\n");
    PTPD_NET_STATS_INC(txInitError);
    return FALSE;
    }

    /* Allocate tx buffer for the general port. */
    netPath->generalTxBuf = pbuf_alloc(PBUF_TRANSPORT, PACKET_SIZE, PBUF_RAM);
    if(netPath->generalTxBuf == NULL)
    {
    PERROR("Failed to allocate Event Tx Buffer\n");
    pbuf_free(netPath->eventTxBuf);
    PTPD_NET_STATS_INC(txInitError);
    return FALSE;
    }

    /* Open lwIP raw udp interfaces for the event port. */
    netPath->eventPcb = udp_new();
    if(netPath->eventPcb == NULL)
    {
      PERROR("Failed to open Event UDP PCB\n");
      pbuf_free(netPath->eventTxBuf);
      pbuf_free(netPath->generalTxBuf);
      PTPD_NET_STATS_INC(rxInitError);
      return FALSE;
    }

    /* Open lwIP raw udp interfaces for the general port. */
    netPath->generalPcb = udp_new();
    if(netPath->generalPcb == NULL)
    {
      PERROR("Failed to open General UDP PCB\n");
      udp_remove(netPath->eventPcb);
      pbuf_free(netPath->eventTxBuf);
      pbuf_free(netPath->generalTxBuf);
      PTPD_NET_STATS_INC(rxInitError);
      return FALSE;
    }

    /* Initialize the buffer queues. */
    netQInit(&netPath->eventQ);
    netQInit(&netPath->generalQ);

    /*
     * XXX: Finding the interface address is not implemented in this port. The
     * lwip layer maintains the interface address and it is not really needed
     * by the ptpd network layer.
     */

    /* save interface address for IGMP refresh */
    // netPath->interfaceAddr = interfaceAddr;

	/* Establish the appropriate UDP bindings/connections for events. */

    udp_recv(netPath->eventPcb, eventRecv, netPath);
    if (ERR_OK != udp_bind(netPath->eventPcb, IP_ADDR_ANY, PTP_EVENT_PORT))
      PTPD_NET_STATS_INC(rxInitError);

    /* Establish the appropriate UDP bindings/connections for general. */
    udp_recv(netPath->generalPcb, generalRecv, netPath);
    if(ERR_OK != udp_bind(netPath->generalPcb, IP_ADDR_ANY, PTP_GENERAL_PORT))
      PTPD_NET_STATS_INC(rxInitError);

	/*
	 * XXX: Currently, only multicast networking is enabled/tested. So, making
	 * unicast address null.
	 */
	netPath->unicastAddr = 0;

    /* Configure network (multicast) addresses. */
    if(!chooseMcastGroup(rtOpts, &netAddr))
    {
    udp_disconnect(netPath->eventPcb);
    udp_disconnect(netPath->generalPcb);
    udp_remove(netPath->eventPcb);
    udp_remove(netPath->generalPcb);
    pbuf_free(netPath->eventTxBuf);
    pbuf_free(netPath->generalTxBuf);
    return FALSE;
    }

    /* Store this multicast address. */
    netPath->multicastAddr = netAddr.s_addr;

    ip4Addr.addr = netAddr.s_addr;
    /* Enable multicasting explicitly. */
    lwIPJoinMulticastGroup(&ip4Addr);

	return TRUE;
}

/*
 * TI F2838x port info note: Modified
 * The vanilla implementation uses sockets to achieve networking. The current
 * F2838x port doesn't use OS and hence a custom method to handle ptp packets
 * is implemented.
 */

/*Check if data have been received*/
int 
netSelect(TimeInternal * timeout, NetPath * netPath)
{
    /* Wait for a packet to come in on either port.  For now, there is no wait.
     * Simply check to see if a packet is available on either port and return 1,
     * otherwise return 0. */

    /* Check the packet queues.  If there is data, return TRUE. */
    if(netQCheck(&netPath->eventQ) || netQCheck(&netPath->generalQ))
        return 1;

    return 0;
}

/*
 * TI F2838x port info note: Modified
 * The vanilla implementation uses sockets to achieve networking. The current
 * F2838x port doesn't use OS and hence a custom method to handle ptp packets
 * is implemented.
 */

/** 
 * store received data from network to "buf" , get and store the
 * SO_TIMESTAMP value in "time" for an event message
 *
 * @note Should this function be merged with netRecvGeneral(), below?
 * Jan Breuer: I think that netRecvGeneral should be simplified. Timestamp returned by this
 * function is never used. According to this, netInitTimestamping can be also simplified
 * to initialize timestamping only on eventSock.
 *
 * @param buf 
 * @param time 
 * @param netPath 
 *
 * @return
 */

ssize_t 
netRecvEvent(Octet * buf, TimeInternal * time, NetPath * netPath)
{
    /* Pop a message off of the event queue and copy it to the passed in buffer. */
    int i, j;
    int iPacketSize;
    struct pbuf *p, *pcopy;
    Timestamp originTs;

    /*
     * Attempt to get a buffer from the Q.  If none is available,
     * return length of 0.
     */
    p = netQGet(&netPath->eventQ);
    if(p == NULL)
    return 0;
    pcopy = p;


    /*
     * Here, p points to a valid PBUF structure.  Verify that we have
     * enough space to store the contents.
     */
    if(p->tot_len > PACKET_SIZE)
    {
        ERROR("received truncated message\n");
        return 0;
    }
    else
        PTPD_NET_STATS_INC(recvEventCount);

    /* Copy the PBUF payload into the buffer. */
    j = 0;
    iPacketSize = p->tot_len;
    for(i = 0; i < iPacketSize; i++)
    {
        buf[i] = ((u8_t *)pcopy->payload)[j++];
        if(j == pcopy->len)
        {
            pcopy = pcopy->next;
            j = 0;
        }
    }

    /* Get the timestamp information. */
    time->seconds = p->time_s;
    time->nanoseconds = p->time_ns;

    /*
     * Some ptpd stack implementation specific operations need to be done
     * based on the type of packet received. This is achieved by partially
     * parsing through the incoming packet contents.
     */
    switch((*(Enumeration4 *) ((u8_t *)p->payload)) & 0x0F)
    {
    case SYNC:
        /*
         * Handling sync packets. Currently, not being used.
         */
        break;
    case DELAY_REQ:
        /*
         * Timestamp information is not available here in the pbuf structure
         * since this is a looped back packet from the ip layer and delay_req
         * send timestamp information was embedded to the payload at the
         * protocol layer. For a normal packet arriving at the interface, the
         * timestamp information is added to the pbuf properties in the lwip
         * port layer i.e. lwip/ports/c2000/f2838x.c.
         * So, parse the packets and extract the originTimestamp
         * field which is formed in the ptpd protocol.c/issueDelayReq api.
         */
        originTs.secondsField.msb =
            flip16(*(UInteger16 *) ((UInteger8 *)(p->payload) + 34));
        originTs.secondsField.lsb =
            flip32(*(UInteger32 *) ((UInteger8 *)(p->payload) + 36));
        originTs.nanosecondsField =
            flip32(*(UInteger32 *) ((UInteger8 *)(p->payload) + 40));

        toInternalTime(time, &originTs);

        break;
    }

    /* Free up the pbuf (chain). */
    pbuf_free(p);

    /* Return the length of data copied. */
    return iPacketSize;
}

/*
 * TI F2838x port info note: Modified
 * The vanilla implementation uses sockets to achieve networking. The current
 * F2838x port doesn't use OS and hence a custom method to handle ptp packets
 * is implemented.
 */

/** 
 * 
 * store received data from network to "buf" get and store the
 * SO_TIMESTAMP value in "time" for a general message
 * 
 * @param buf 
 * @param time 
 * @param netPath 
 * 
 * @return 
 */

ssize_t 
netRecvGeneral(Octet * buf, TimeInternal * time, NetPath * netPath)
{
    /* Pop a message off of the general queue and copy to the passed in buffer. */

	int i, j;
    int iPacketSize;
    struct pbuf *p, *pcopy;


    /*
     * Attempt to get a buffer from the Q.  If none is available,
     * return length of 0.
     */
    p = netQGet(&netPath->generalQ);
    if(p == NULL)
    return 0;
    pcopy = p;

    /*
     * Here, p points to a valid PBUF structure.  Verify that we have
     * enough space to store the contents.
     */
    if(p->tot_len > PACKET_SIZE)
    {
        ERROR("received truncated message\n");
        return 0;
    }
    else
        PTPD_NET_STATS_INC(recvGeneralCount);

    /* Copy the PBUF payload into the buffer. */
    j = 0;
    iPacketSize = p->tot_len;
    for(i = 0; i < iPacketSize; i++)
    {
        buf[i] = ((u8_t *)pcopy->payload)[j++];
        if(j == pcopy->len)
        {
            pcopy = pcopy->next;
            j = 0;
        }
    }

    /* Get the timestamp information. */
    time->seconds = p->time_s;
    time->nanoseconds = p->time_ns;

    /* Free up the pbuf (chain). */
    pbuf_free(p);

    /* Return the length of data copied. */
    return iPacketSize;
}

/*
 * TI F2838x port info note: Modified
 * The vanilla implementation uses sockets to achieve networking. The current
 * F2838x port doesn't use OS and hence a custom method to handle ptp packets
 * is implemented.
 */
ssize_t 
netSendEvent(Octet * buf, UInteger16 length, NetPath * netPath, Integer32 alt_dst)
{
    /*
     * Transmit a packet on the Event Port.
     * XXX: The usage of "alt_dst" argument is not implemented in this port.
     */

    int i, j;
    struct pbuf *pcopy;

    /* Reallocate the tx pbuf based on the current size. */
    pbuf_realloc(netPath->eventTxBuf, length);
    pcopy = netPath->eventTxBuf;

    /* Set multicast option in the pbuf flags field */
    pcopy->flags |= PBUF_FLAG_MCASTLOOP;

    /* Copy the incoming data into the pbuf payload. */
    j = 0;
    for(i = 0; i < length; i++)
    {
        ((u8_t *)pcopy->payload)[j++] = buf[i];
        if(j == pcopy->len)
        {
            pcopy = pcopy->next;
            j = 0;
        }
    }

    /* send the buffer. */
    udp_sendto(netPath->eventPcb, netPath->eventTxBuf,
    (void *)&netPath->multicastAddr, PTP_EVENT_PORT);

    /*
     * Need to call this function to push the loopback packet up the ip layer.
     * If this is not called, then the looped back packet remains in the
     * loopback queue at the ip layer and is not forwarded up the stack. With
     * time the queue itself overflows and starts dropping further looped back
     * packets.
     */
    lwIPMulticastLoopbackPoll();

    PTPD_NET_STATS_INC(sendEventCount);
    return(length);
}

/*
 * TI F2838x port info note: Modified
 * The vanilla implementation uses sockets to achieve networking. The current
 * F2838x port doesn't use OS and hence a custom method to handle ptp packets
 * is implemented.
 */
ssize_t 
netSendGeneral(Octet * buf, UInteger16 length, NetPath * netPath, Integer32 alt_dst)
{
    /* Transmit a packet on the General Port. */

    int i, j;
    struct pbuf *pcopy;

    /* Reallocate the tx pbuf based on the current size. */
    pbuf_realloc(netPath->generalTxBuf, length);
    pcopy = netPath->generalTxBuf;

    /* Copy the incoming data into the pbuf payload. */
    j = 0;
    for(i = 0; i < length; i++)
    {
        ((u8_t *)pcopy->payload)[j++] = buf[i];
        if(j == pcopy->len)
        {
            pcopy = pcopy->next;
            j = 0;
        }
    }

    /* send the buffer. */
    udp_sendto(netPath->eventPcb, netPath->generalTxBuf,
    (void *)&netPath->multicastAddr, PTP_GENERAL_PORT);

    PTPD_NET_STATS_INC(sendGeneralCount);

    return(length);
}

/*
 * TI F2838x port info note:
 * This api is not being used in this port, hence commenting out some internal
 * section. The function(symbol) name is needed for compiling the stack
 * successfully.
 */
ssize_t 
netSendPeerGeneral(Octet * buf, UInteger16 length, NetPath * netPath)
{
	/*
	 * XXX: Currently, this function is not actually being used in the port.
	 */
	return 0;
}

/*
 * TI F2838x port info note:
 * This api is not being used in this port, hence commenting out some internal
 * section. The function(symbol) name is needed for compiling the stack
 * successfully.
 */
ssize_t 
netSendPeerEvent(Octet * buf, UInteger16 length, NetPath * netPath)
{
	/*
     * XXX: Currently, this function is not actually being used in the port.
     */
    return 0;
}

/*
 * TI F2838x port info note: Modified
 * The vanilla implementation uses sockets to achieve networking. The current
 * F2838x port doesn't use OS and hence a custom method to handle ptp packets
 * is implemented.
 */

/*
 * refresh IGMP on a timeout
 */
/*
 * @return TRUE if successful
 */
Boolean
netRefreshIGMP(NetPath * netPath, RunTimeOpts * rtOpts, PtpClock * ptpClock)
{
	/*
     * Multicasting is enabled by making raw api calls to the lwip stack.
     */
	ip4_addr_t multi_addr;

	multi_addr.addr = netPath->multicastAddr;

	/* Leave the multicast group. */
	lwIPLeaveMulticastGroup(&multi_addr);

	/* Join back the multicast group. */
	lwIPJoinMulticastGroup(&multi_addr);

    return TRUE;
}
