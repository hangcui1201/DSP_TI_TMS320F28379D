/* constants_dep.h */

#ifndef CONSTANTS_DEP_H
#define CONSTANTS_DEP_H

/**
*\file
* \brief Plateform-dependent constants definition
*
* This header defines all includes and constants which are plateform-dependent
*
* This ptpdv2 port is intended to work on TI's F2838X devices without any OS.
*/

/* platform dependent */
#ifdef IF_NAMESIZE
    #define IFACE_NAME_LENGTH   IF_NAMESIZE
#else
    #define IFACE_NAME_LENGTH   16
#endif

#ifdef INET_ADDRSTRLEN
    #define NET_ADDRESS_LENGTH  INET_ADDRSTRLEN
#else
    #define NET_ADDRESS_LENGTH  16
#endif

/*--- Added for TI F2838x device support */
#define MAXHOSTNAMELEN NET_ADDRESS_LENGTH   // used in RunTimeOpts, datatypes.h
#define PATH_MAX    20          // used in RunTimeOpts, datatypes.h
/* Added for TI F2838x device support ---*/

#define IFCONF_LENGTH 10

#define PTPD_LSBF

#define CLOCK_IDENTITY_LENGTH 8
#define ADJ_FREQ_MAX  512000

/* UDP/IPv4 dependent */
#ifndef INADDR_LOOPBACK
#define INADDR_LOOPBACK 0x7f000001UL
#endif

#define SUBDOMAIN_ADDRESS_LENGTH  4
#define PORT_ADDRESS_LENGTH       2
#define PTP_UUID_LENGTH           6
#define CLOCK_IDENTITY_LENGTH	  8
#define FLAG_FIELD_LENGTH         2

#define PACKET_SIZE  300 //ptpdv1 value kept because of use of TLV...

#define PTP_EVENT_PORT    319
#define PTP_GENERAL_PORT  320

#define DEFAULT_PTP_DOMAIN_ADDRESS     "224.0.1.129"
#define PEER_PTP_DOMAIN_ADDRESS        "224.0.0.107"

/* used for -I option */
#define ALTERNATE_PTP_DOMAIN1_ADDRESS  "224.0.1.130"
#define ALTERNATE_PTP_DOMAIN2_ADDRESS  "224.0.1.131"
#define ALTERNATE_PTP_DOMAIN3_ADDRESS  "224.0.1.132"



#define MM_STARTING_BOUNDARY_HOPS  0x7fff

/* others */

/* bigger screen size constants */
#define SCREEN_BUFSZ  228
#define SCREEN_MAXSZ  180

/* default size for string buffers */
#define BUF_SIZE  1000


#define NANOSECONDS_MAX 999999999


// limit operator messages to once every X seconds
#define OPERATOR_MESSAGES_INTERVAL 300.0


#define MAXTIMESTR 32

// Added By TI
#define PBUF_QUEUE_SIZE 16

/* override default values */
#ifdef      DEFAULT_AP
#undef      DEFAULT_AP
#define     DEFAULT_AP  2
#endif

#ifdef      DEFAULT_AI
#undef      DEFAULT_AI
#define     DEFAULT_AI  200
#endif

#define     MAX_AP      10
#define     MAX_AI      1000

#ifdef      DEFAULT_INBOUND_LATENCY
#undef      DEFAULT_INBOUND_LATENCY
#define     DEFAULT_INBOUND_LATENCY     16500
#endif

#ifdef      DEFAULT_OUTBOUND_LATENCY
#undef      DEFAULT_OUTBOUND_LATENCY
#define     DEFAULT_OUTBOUND_LATENCY    16500
#endif

#ifdef      CLOCK_FOLLOWUP
#undef      CLOCK_FOLLOWUP
#define     CLOCK_FOLLOWUP              FALSE
#endif

#endif /*CONSTANTS_DEP_H_*/
