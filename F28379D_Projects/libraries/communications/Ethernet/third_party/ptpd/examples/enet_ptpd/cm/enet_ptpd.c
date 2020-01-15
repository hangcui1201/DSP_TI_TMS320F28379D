//###########################################################################
// FILE:   enet_ptpd.c
// TITLE:  Sample application that uses ptpd stack to correct system time.
//###########################################################################
// $TI Release: $
// $Release Date: $
// $Copyright: $
//###########################################################################

#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<math.h>

#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "inc/hw_nvic.h"
#include "inc/hw_types.h"
#include "inc/hw_sysctl.h"
#include "inc/hw_emac.h"
#include "driverlib_cm/ethernet.h"
#include "driverlib_cm/interrupt.h"
#include "driverlib_cm/sysctl.h"
#include "driverlib_cm/systick.h"
#include "utils/lwiplib.h"
#include "utils/ptpdlib.h"
#include "utils/ustdlib.h"
#include "random.h"

#include "dep-f2838x/ptpd_dep.h"
#include "ptpd.h"

//*****************************************************************************
//
//! \addtogroup master_example_list
//! <h1>Ethernet with PTP (enet_ptpd)</h1>
//!
//! This example application demonstrates the operation of the F2838x Ethernet
//! controller with the third-party ptpd and lwIP TCP/IP stacks. The device
//! is programmed with a static IP address - 192.168.0.4.
//!
//! Once programmed, the device will respond to ping request from other devices
//! which are in the same network (255.255.255.0).
//!
//! Further, the IEEE-1588 based ptpd software stack enables the device to
//! synchronize the internal clock to a network master clock source.
//!
//! Summary of stack working:
//! The ptpd stack configures the device in slave mode. Then every systick
//! period, the main application checks if any PTP packet is received in the
//! queues maintained at ptpd layer. According to the packets received, the
//! state machine in the ptpd stack progresses and calculates the two important
//! time delta w.r.t master namely "Offset From Master" and "Mean Path Delay".
//! Based on these calculations, the stack issues call to the F2838x ethernet
//! drivers to adjust the system time.
//!
//! The software stack uses "Fine" method to correct system time. Based on the
//! offset from master, drift value is calculated from the master and in turn
//! the addend value in the ethernet system time module is adjusted. Addend
//! based adjustments can factor in the drift in the frequency from the master
//! clock source.
//!
//! The System and PTP Reference clock frequency are 125MHz and 100MHz
//! respectively by default, and are configured by c28x core. These values
//! are not programmed by this example and therefore are needed to be available
//! statically to the code. Also, the desired accuracy is assumed to be 20ns
//! here which corresponds to 50MHz and this is different from PTP Reference
//! clock frequency which is, in reality, just used to achieve this desired
//! accuracy. Note that the desired (accuracy)frequency should be less than the
//! PTP Reference clock frequency.
//!
//! To track the working of the example, open the "Expressions" view and add
//! the following two expressions: "gPTPClock.offsetFromMaster" and
//! "gDiffLatestPpb". The first one indicates the offset from master in
//! nanoseconds. This should decrease in magnitude over time to the order of
//! around +-2500ns. The second one indicates the drift in frequency from the
//! master in terms of parts per billion. This value should also decrease
//! correspondingly over time.
//!
//! For additional details on lwIP, refer to the lwIP web page at:
//! http://savannah.nongnu.org/projects/lwip/
//!
//! For additional details on the PTPd software, refer to the PTPd web page at:
//! http://ptpd.sourceforge.net
//
//*****************************************************************************

// These are defined by the linker (see device linker command file)
extern unsigned long RamfuncsLoadStart;
extern unsigned long RamfuncsLoadSize;
extern unsigned long RamfuncsRunStart;

//*****************************************************************************
//
// Driver specific initialization code and macro.
//
//*****************************************************************************
#define ETHERNET_NO_OF_RX_PACKETS   8U
#define ETHERNET_MAX_PACKET_LENGTH 400
#define NUM_PACKET_DESC_RX_APPLICATION 8

Ethernet_Handle emac_handle;
Ethernet_InitConfig *pInitCfg;
uint32_t Ethernet_numRxCallbackCustom = 0;
uint32_t releaseTxCount = 0;
Ethernet_Pkt_Desc  pktDescriptorRXCustom[NUM_PACKET_DESC_RX_APPLICATION];

extern uint32_t Ethernet_numGetPacketBufferCallback;
extern Ethernet_Device Ethernet_device_struct;

//
// The receive buffer needs to be defined
//
uint8_t Ethernet_rxBuffer[ETHERNET_NO_OF_RX_PACKETS *
                          ETHERNET_MAX_PACKET_LENGTH];

extern Ethernet_Pkt_Desc*
lwIPEthernetIntHandler(Ethernet_Pkt_Desc *pPacket);

//*****************************************************************************
//
// Define the System Clock and PTP reference clock rate here. The max possible
// values are 125 MHz and 100 MHz respectively. We are the using the max
// values in this example. For using any custom values, a few things need to
// be taken care of:
// 1. C28x is the master and it configures the Cortex-M core's system Clock.
//    Hence, it must be changed from the C28x core initialization routine.
// 2. When the RMII mode is enabled on the CM side, then the clock required for
//    it is 50 MHz as a rule of thumb. By the clock design logic, the PTP ref.
//    clock then is compulsorily fixed to 100 MHz.
// 3. If the RMII mode is disabled on the CM side, then the PTP reference clock
//    rate should be configured between 100 MHz and 5 MHz but note that the
//    precision decreases for lower frequencies.
//
// NOTE:
// These clock rates are actually set in the C28x side code. Here we maintain
// them as a known constant in this code. If this is changed in the C28x code,
// then it also needs to be updated here.
//*****************************************************************************
#define SYSTEM_CLOCK_FREQ        125000000U
#define PTP_REF_CLOCK_FREQ       100000000U

//*****************************************************************************
//
// Defines for setting up the Systick timer.
//
//*****************************************************************************
#define SYSTICKHZ               20
#define SYSTICKMS               (1000 / SYSTICKHZ)
#define SYSTICKUS               (1000000 / SYSTICKHZ)
#define SYSTICKNS               (1000000000 / SYSTICKHZ)

//*****************************************************************************
//
// These values were being used for previous versions of ptpd.
//
//*****************************************************************************
uint32_t systickPeriodCount = 0;

//*****************************************************************************
//
// A set of flags used to track the state of the application.
//
//*****************************************************************************
static volatile unsigned long g_ulFlags;
#define FLAG_PPSOUT             0           // PPS Output is on.
#define FLAG_PPSOFF             1           // PPS Output should be turned off.
#define FLAG_PTPDINIT           2           // PTPd has been initialized.  The value is zero in TIVA.
static volatile uint32_t g_ui32Flags;

//*****************************************************************************
//
// System Time - Internal representaion.
//
//*****************************************************************************
volatile unsigned long g_ulSystemTimeSeconds;
volatile unsigned long g_ulSystemTimeNanoSeconds;

//*****************************************************************************
//
// System Run Time - Ticks
//
//*****************************************************************************
volatile unsigned long g_ulSystemTimeTicks;

//*****************************************************************************
//
// The current system and PTP clock frequencies in Hz and the number of
// nanoseconds in each PTP clock tick.
//
//*****************************************************************************
uint_fast32_t gSysClockFreq;
uint_fast32_t gReqPTPClockFreq;

//*****************************************************************************
//
// A couple of variables we use to provide some feedback on how well
// our local clock is converging on the master clock.  The calculation used
// isn't particularly scientific but should give us an idea of how the clocks
// are doing.  We first calculate a rolling average of the absolute clock rate
// adjustment we are asked to make by PTPD then calculate the difference
// between this rolling average and the current adjustment.  As the clock
// rates converge, this difference should reduce to a small number over time.
//
//*****************************************************************************
int_fast32_t gAdjAverage = 0;
int_fast32_t gDiffLatestPpb = 0;
bool gDiffValid = false;

#define ADJ_AVERAGE_SIZE 10
#define DISCARD_INITIAL_VALUES 3

#define MY_ABS(x) (((x) < 0) ? -(x) : (x))

//*****************************************************************************
//
// Statically allocated runtime options and parameters for PTPd.
//
//*****************************************************************************
PtpClock gPTPClock;
ForeignMasterRecord gForeignMasterRec[DEFAULT_MAX_FOREIGN_RECORDS];
RunTimeOpts gRtOpts;

//*****************************************************************************
//
// Local function prototypes.
//
//*****************************************************************************
static void ptpd_init(void);
static void ptpd_tick(void);

//*****************************************************************************
//
// The most recently assigned IP address. This is used to detect when the IP
// address has changed (due to DHCP/AutoIP) so that the new address can be
// printed.
//
//*****************************************************************************
static unsigned long gLastIPAddr = 0;

//*****************************************************************************
//
// A mapping from day of the week numbers to the name of the day.
//
//*****************************************************************************
const char *g_ppcDay[7] =
{
    "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"
};

//*****************************************************************************
//
// A mapping from month numbers to the name of the month.
//
//*****************************************************************************
const char *g_ppcMonth[12] =
{
    "Jan", "Feb", "Mar", "Apr", "May", "Jun",
    "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
};

struct tm
{
    int tm_sec;      /* seconds after the minute   - [0,59]  */
    int tm_min;      /* minutes after the hour     - [0,59]  */
    int tm_hour;     /* hours after the midnight   - [0,23]  */
    int tm_mday;     /* day of the month           - [1,31]  */
    int tm_mon;      /* months since January       - [0,11]  */
    int tm_year;     /* years since 1900                     */
    int tm_wday;     /* days since Sunday          - [0,6]   */
    int tm_yday;     /* days since Jan 1st         - [0,365] */
    int tm_isdst;    /* Daylight Savings Time flag           */
#if _AEABI_PORTABILITY_CHECK
    int __extra_1, __extra_2;            /* ABI-required extra fields */
#endif

};

//*****************************************************************************
//! A structure that contains the broken down date and time.
//*****************************************************************************
struct tTime
{
        //! The number of years since 0 AD.
        unsigned short usYear;

        //! The month, where January is 0 and December is 11.
        unsigned char ucMon;

        //! The day of the month.
        unsigned char ucMday;

        //! The day of the week, where Sunday is 0 and Saturday is 6.
        unsigned char ucWday;

        //! The number of hours.
        unsigned char ucHour;

        //! The number of minutes.
        unsigned char ucMin;

        //! The number of seconds.
        unsigned char ucSec;
};

//*****************************************************************************
//
// The error routine that is called if the driver library encounters an error.
//
//*****************************************************************************
#ifdef DEBUG
void
__error__(char *pcFilename, unsigned long ulLine)
{
}
#endif

//*****************************************************************************
//
// Required by lwIP library to support any host-related timer functions.
//
//*****************************************************************************
void
lwIPHostTimerHandler(void)
{
    unsigned long ipAddress;

    //
    // Get the local IP address.
    //
    ipAddress = lwIPLocalIPAddrGet();

    //
    // Check if IP Address has been assigned or changed
    //
    if(ipAddress == 0)
    {

    }
    else if(gLastIPAddr != ipAddress)
    {
        //
        // Save the new IP address.
        //
        gLastIPAddr = ipAddress;
    }

    //
    // If IP address has been assigned, initialize the PTPD software (if
    // not already initialized).
    //
    if(ipAddress && !HWREGBITW(&g_ulFlags, FLAG_PTPDINIT))
    {
        ptpd_init();
        HWREGBITW(&g_ulFlags, FLAG_PTPDINIT) = 1;
    }

    //
    // If PTPD software has been initialized, run the ptpd tick.
    //
    if(HWREGBITW(&g_ulFlags, FLAG_PTPDINIT))
    {
        ptpd_tick();
    }
}

//*****************************************************************************
//
// The interrupt handler for the SysTick interrupt.
//
//*****************************************************************************
void
SysTickIntHandler(void)
{
    systickPeriodCount=systickPeriodCount+1;
    tTime sLocalTime;
    static uint32_t ui32LastSec = 0;
    uint32_t ui32Sec, ui32Nanosec;

    //
    // Service the PTPd Timer.
    //
    timerTick((int)SYSTICKMS);

    //
    // Get the current time.
    //
    Ethernet_getSysTimePTP(EMAC_BASE, &ui32Sec, &ui32Nanosec);

    //
    // Has the second count changed since last interrupt?
    //
    if(ui32Sec != ui32LastSec)
    {
        //
        // Yes - update the time if PTP has been initialized.
        //
        if(HWREGBITW(&g_ui32Flags, FLAG_PTPDINIT))
        {
            //
            // Convert the elapsed seconds (ulSec) into time structure.
            //
            ulocaltime(ui32Sec, &sLocalTime);
        }
    }

    //
    // Remember the current time for next interrupt.
    //
    ui32LastSec = ui32Sec;

    //
    // Call the lwIP timer handler.
    //
    lwIPTimer(SYSTICKMS);
}

//*****************************************************************************
//
// Initialization code for PTPD software.
//
//*****************************************************************************
static void
ptpd_init(void)
{
    uint32_t mac_low,mac_high;
    uint8_t *pucTemp;

    //
    // Clear out all of the run time options and protocol stack options.
    //
    memset(&gRtOpts, 0, sizeof(gRtOpts));
    memset(&gPTPClock, 0, sizeof(gPTPClock));

    //
    // initialize run-time options to default values
    //
    gRtOpts.announceInterval = DEFAULT_ANNOUNCE_INTERVAL;
    gRtOpts.syncInterval = DEFAULT_SYNC_INTERVAL;
    gRtOpts.clockQuality.clockAccuracy = DEFAULT_CLOCK_ACCURACY;
    gRtOpts.clockQuality.clockClass = DEFAULT_CLOCK_CLASS;
    gRtOpts.clockQuality.offsetScaledLogVariance = DEFAULT_CLOCK_VARIANCE;
    gRtOpts.priority1 = DEFAULT_PRIORITY1;
    gRtOpts.priority2 = DEFAULT_PRIORITY2;
    gRtOpts.domainNumber = DEFAULT_DOMAIN_NUMBER;

#ifdef PTP_EXPERIMENTAL
    gRtOpts.mcast_group_Number = 0;
    gRtOpts.do_hybrid_mode = 0;
#endif
    gRtOpts.currentUtcOffset = DEFAULT_UTC_OFFSET;

    memcpy(gRtOpts.ifaceName, "TI", strlen("TI"));
    gRtOpts.do_unicast_mode = 0;

    gRtOpts.maxReset = 0;
    gRtOpts.noAdjust = NO_ADJUST;  // false
    gRtOpts.displayStats = FALSE;
    gRtOpts.csvStats = FALSE;

    //
    // Deep display of all packets seen by the daemon
    //
    gRtOpts.displayPackets = FALSE;

    //
    // If ptpd is to be run in unicast mode, uncomment and assign this option.
    //
    // gRtOpts.unicastAddress
    gRtOpts.ap = DEFAULT_AP;
    gRtOpts.ai = DEFAULT_AI;
    gRtOpts.s = DEFAULT_DELAY_S;
    gRtOpts.inboundLatency.nanoseconds = DEFAULT_INBOUND_LATENCY;
    gRtOpts.outboundLatency.nanoseconds = DEFAULT_OUTBOUND_LATENCY;
    gRtOpts.max_foreign_records = DEFAULT_MAX_FOREIGN_RECORDS;

    //
    // Ethernet mode is not provided
    //
    gRtOpts.ethernet_mode = FALSE;

    //
    // Following options are commented out. If needed, they should be set here.
    //
    // gRtOpts.offset_first_updated = FALSE;
    // gRtOpts.file[0] = 0;
    gRtOpts.logFd = -1;
    gRtOpts.recordFP = NULL;
    gRtOpts.do_log_to_file = FALSE;
    gRtOpts.do_record_quality_file = FALSE;
    gRtOpts.nonDaemon = FALSE;

    //
    // defaults for new options
    //
    gRtOpts.slaveOnly = TRUE;
    gRtOpts.ignore_delayreq_interval_master = TRUE;

    //
    // Do not refresh the IGMP Multicast menbership at each protol reset
    //
    gRtOpts.do_IGMP_refresh = FALSE;
    gRtOpts.useSysLog       = FALSE;
    gRtOpts.syslog_startup_messages_also_to_stdout = FALSE;       /* used to print inital messages both to syslog and screen */
    gRtOpts.announceReceiptTimeout  = DEFAULT_ANNOUNCE_RECEIPT_TIMEOUT;
#ifdef RUNTIME_DEBUG
    gRtOpts.debug_level = LOG_INFO;          /* by default debug messages as disabled, but INFO messages and below are printed */
#endif

    gRtOpts.ttl = 1;
    gRtOpts.delayMechanism   = DEFAULT_DELAY_MECHANISM;
    gRtOpts.noResetClock     = DEFAULT_NO_RESET_CLOCK;
    gRtOpts.log_seconds_between_message = 0;

    gRtOpts.initial_delayreq = DEFAULT_DELAYREQ_INTERVAL;
    gRtOpts.subsequent_delayreq = DEFAULT_DELAYREQ_INTERVAL; // this will be updated if -g is given

    //
    // Initialize the PTP Clock Fields.
    //
    gPTPClock.foreign = &gForeignMasterRec[0];

    //
    // Configure port "uuid" parameters.
    //
    gPTPClock.port_communication_technology = PTP_ETHER;

    Ethernet_getMACAddr(EMAC_BASE, 0, &mac_high, &mac_low);

    pucTemp = (uint8_t *)&mac_low;
    gPTPClock.port_uuid_field[0] = pucTemp[0];
    gPTPClock.port_uuid_field[1] = pucTemp[1];
    gPTPClock.port_uuid_field[2] = pucTemp[2];
    gPTPClock.port_uuid_field[3] = pucTemp[3];

    pucTemp = (uint8_t *)&mac_high;
    gPTPClock.port_uuid_field[4] = pucTemp[0];
    gPTPClock.port_uuid_field[5] = pucTemp[1];

    //
    // Run the protocol engine for the first time to initialize the state
    // machines.
    //
    protocol_first(&gRtOpts, &gPTPClock);
}

//*****************************************************************************
//
// Run the protocol engine loop/poll.
//
//*****************************************************************************
static void
ptpd_tick(void)
{
    //
    // Run the protocol engine for each pass through the main process loop.
    //
    protocol_loop(&gRtOpts, &gPTPClock);
}

//*****************************************************************************
//
//  This function is a callback function called by the example to
//  get a Packet Buffer. Has to return a ETHERNET_Pkt_Desc Structure.
//  Rewrite this API for custom use case.
//
//*****************************************************************************
Ethernet_Pkt_Desc* Ethernet_getPacketBufferCustom(void)
{
    //
    // Get the next packet descriptor from the descriptor pool
    //
    uint32_t shortIndex = (Ethernet_numGetPacketBufferCallback + 3)
                % NUM_PACKET_DESC_RX_APPLICATION;

    //
    // Increment the book-keeping pointer which acts as a head pointer
    // to the circular array of packet descriptor pool.
    //
    Ethernet_numGetPacketBufferCallback++;

    //
    // Update buffer length information to the newly procured packet
    // descriptor.
    //
    pktDescriptorRXCustom[shortIndex].bufferLength =
                                  ETHERNET_MAX_PACKET_LENGTH;

    //
    // Update the receive buffer address in the packer descriptor.
    //
    pktDescriptorRXCustom[shortIndex].dataBuffer =
                                      &Ethernet_device_struct.rxBuffer [ \
               (ETHERNET_MAX_PACKET_LENGTH*Ethernet_device_struct.rxBuffIndex)];

    //
    // Update the receive buffer pool index.
    //
    Ethernet_device_struct.rxBuffIndex += 1U;
    Ethernet_device_struct.rxBuffIndex  = \
    (Ethernet_device_struct.rxBuffIndex%ETHERNET_NO_OF_RX_PACKETS);

    //
    // Receive buffer is usable from Address 0
    //
    pktDescriptorRXCustom[shortIndex].dataOffset = 0U;

    //
    // Return this new descriptor to the driver.
    //
    return (&(pktDescriptorRXCustom[shortIndex]));
}

//*****************************************************************************
//
//  This is a hook function and called by the driver when it receives a
//  packet. Application is expected to replenish the buffer after consuming it.
//  Has to return a ETHERNET_Pkt_Desc Structure.
//  Rewrite this API for custom use case.
//
//*****************************************************************************
Ethernet_Pkt_Desc* Ethernet_receivePacketCallbackCustom(
        Ethernet_Handle handleApplication,
        Ethernet_Pkt_Desc *pPacket)
{
    //
    // Book-keeping to maintain number of callbacks received.
    //
#ifdef ETHERNET_DEBUG
    Ethernet_numRxCallbackCustom++;
#endif

    //
    // This is a placeholder for Application specific handling
    // We are replenishing the buffer received with another buffer
    //
    return lwIPEthernetIntHandler(pPacket);
}

void Ethernet_releaseTxPacketBufferCustom(
        Ethernet_Handle handleApplication,
        Ethernet_Pkt_Desc *pPacket)
{
    //
    // Once the packet is sent, reuse the packet memory to avoid
    // memory leaks.
    //
    //mem_free(pPacket);

    //
    // TODO: Describe the action of calling this function.
    //
    lwIPEthernetIntHandler(pPacket);

    //
    // Increment the book-keeping counter.
    //
#ifdef ETHERNET_DEBUG
    releaseTxCount++;
#endif
}

void Ethernet_init(const unsigned char *mac)
{
    uint32_t macLower;
    uint32_t macHigher;
    uint32_t varPtpConfig;
    uint8_t *temp;
    float subSecondInc;
    Ethernet_InitInterfaceConfig initInterfaceConfig;

    initInterfaceConfig.ssbase = EMAC_SS_BASE;
    initInterfaceConfig.eqos_base = EMAC_BASE;
    initInterfaceConfig.phyMode = ETHERNET_SS_PHY_INTF_SEL_MII;

    //
    // Assign SoC specific functions for Enabling,Disabling interrupts
    // and for enabling the Peripheral at system level
    //
    initInterfaceConfig.ptrPlatformInterruptDisable =
                                                    &Platform_disableInterrupt;
    initInterfaceConfig.ptrPlatformInterruptEnable =
                                                     &Platform_enableInterrupt;
    initInterfaceConfig.ptrPlatformPeripheralEnable =
                                                    &Platform_enablePeripheral;
    initInterfaceConfig.ptrPlatformPeripheralReset =
                                                     &Platform_resetPeripheral;

    //
    // Assign the peripheral number at the SoC
    //
    initInterfaceConfig.peripheralNum = SYSCTL_PERIPH_CLK_ENET;

    //
    // Assign the default SoC specific interrupt numbers of Ethernet interrupts
    //
    initInterfaceConfig.interruptNum[0] = INT_EMAC;
    initInterfaceConfig.interruptNum[1] = INT_EMAC_TX0;
    initInterfaceConfig.interruptNum[2] = INT_EMAC_TX1;
    initInterfaceConfig.interruptNum[3] = INT_EMAC_RX0;
    initInterfaceConfig.interruptNum[4] = INT_EMAC_RX1;

    pInitCfg = Ethernet_initInterface(initInterfaceConfig);

    Ethernet_getInitConfig(pInitCfg);
    pInitCfg->dmaMode.InterruptMode = ETHERNET_DMA_MODE_INTM_MODE2;

    //
    // Assign the callbacks for Getting packet buffer when needed
    // Releasing the TxPacketBuffer on Transmit interrupt callbacks
    // Receive packet callback on Receive packet completion interrupt
    //
    pInitCfg->pfcbRxPacket = &Ethernet_receivePacketCallbackCustom;
    pInitCfg->pfcbGetPacket = &Ethernet_getPacketBufferCustom;
    pInitCfg->pfcbFreePacket = &Ethernet_releaseTxPacketBufferCustom;

    //
    //Assign the Buffer to be used by the Low level driver for receiving
    //Packets. This should be accessible by the Ethernet DMA
    //
    pInitCfg->rxBuffer = Ethernet_rxBuffer;

    //
    // The Application handle is not used by this application
    // Hence using a dummy value of 1
    //
    Ethernet_getHandle((Ethernet_Handle)1, pInitCfg , &emac_handle);

    //
    // Do global Interrupt Enable
    //
    (void)Interrupt_enableInProcessor();

    //
    // Assign default ISRs
    //
    Interrupt_registerHandler(INT_EMAC_TX0, Ethernet_transmitISR);
    Interrupt_registerHandler(INT_EMAC_RX0, Ethernet_receiveISR);
    Interrupt_registerHandler(INT_EMAC,Ethernet_genericISR);

    //
    // Enable the default interrupt handlers
    //
    Interrupt_enable(INT_EMAC_TX0);
    Interrupt_enable(INT_EMAC_RX0);
    Interrupt_enable(INT_EMAC);

    //
    // PTP init code here.
    // In this example, we just use the PTP clock and fine correction method
    // to correct the system time driven by the PTP clock. Also, Digital
    // Rollover mode is enabled for the system time counter which means that
    // the System Time Nanoseconds register provides 1ns accuracy i.e. it will
    // generate carry to the System Time Seconds register after reaching
    // value 0x3B9ACA00(equivalent to 10^9 ns).
    //
    varPtpConfig = 0x0 |
                   ETHERNET_MAC_TIMESTAMP_CONTROL_TSCTRLSSR |
                   ETHERNET_MAC_TIMESTAMP_CONTROL_TSCFUPDT
                   ;

    //
    // Since, we want the accuracy to be 20ns. The ptp clock will just provide
    // the reference frequency for us to achieve the 20ns accuracy.
    //
    subSecondInc = (float)(1000000000/gReqPTPClockFreq);

    Ethernet_setConfigTimestampPTP(EMAC_BASE, varPtpConfig, subSecondInc);

    Ethernet_setAddend(EMAC_BASE, 0x80000000);

    Ethernet_enableSysTimePTP(EMAC_BASE);
    Ethernet_setSysTimePTP(EMAC_BASE, 0x00000000, 0x00000000);

    //
    // Convert the mac address string into the 32/16 split variables format
    // that is required by the driver to program into hardware registers.
    // Note: This step is done after the Ethernet_getHandle function because
    //       a dummy MAC address is programmed in that function.
    //
    temp = (uint8_t *)&macLower;
    temp[0] = mac[0];
    temp[1] = mac[1];
    temp[2] = mac[2];
    temp[3] = mac[3];

    temp = (uint8_t *)&macHigher;
    temp[0] = mac[4];
    temp[1] = mac[5];

    //
    // Program the unicast mac address.
    //
    Ethernet_setMACAddr(EMAC_BASE,
                        0,
                        macHigher,
                        macLower,
                        ETHERNET_CHANNEL_0);

    //
    // Program the multicast mac address that is required for PTP over UDP
    // packets.
    // 01-00-5E-00-01-81
    //
    // Information below:
    //
    // Ethernet Multicast Address
    // 01-00-5E-00-00-00 through 01-00-5E-7F-FF-FF
    // 0x0800 IPv4 Multicast (RFC 1112), insert the low 23 Bits of the multicast IPv4 Address into the Ethernet Address (RFC 7042 2.1.1.)
    //
    // IP Multicast address
    // 224.0.1.129
    // Precision Time Protocol (PTP) version 2 messages (Sync, Announce, etc.) except peer delay measurement
    //
    // 224.0.0.107
    // Precision Time Protocol (PTP) version 2 peer delay measurement messaging
    //
    Ethernet_setMACAddr(EMAC_BASE,
                        1,
                        0x00008101,
                        0x005E0001,
                        ETHERNET_CHANNEL_0);
}

//*****************************************************************************
//
// This example demonstrates the use of the Ethernet Controller.
//
//*****************************************************************************
int
main(void)
{
    unsigned char macArray[8];

    //
    // Set user/company specific MAC octets
    // (for this code we are using A8-63-F2-00-00-80)
    // 0x00 MACOCT3 MACOCT2 MACOCT1
    //
    unsigned long ulUser0 = 0x00F263A8;

    //
    // 0x00 MACOCT6 MACOCT5 MACOCT4
    //
    unsigned long ulUser1 = 0x00800000;

    //
    // User specific IP Address Configuration.
    // Current implementation works with Static IP address only.
    //
    unsigned long IPAddr = 0xC0A80004;
    unsigned long NetMask = 0xFFFFFF00;
    unsigned long GWAddr = 0x00000000;

    //
    // Saving the values of System clock and the PTP reference clock in
    // global variables.
    //
    gSysClockFreq = SYSTEM_CLOCK_FREQ;
    gReqPTPClockFreq = PTP_REF_CLOCK_FREQ/2;

    //
    // We are setting the systick period value as a fraction of the system
    // clock. For other custom values, keep in mind the maximum value that is
    // possible for the systick counter module.
    //
    SYSTICK_setPeriod(gSysClockFreq/SYSTICKHZ);
    SYSTICK_enableCounter();
    SYSTICK_registerInterruptHandler(SysTickIntHandler);
    SYSTICK_enableInterrupt();

    //
    // Enable processor interrupts.
    //
    Interrupt_enableInProcessor();

    //
    // Convert the 24/24 split MAC address into a 32/16 split MAC
    // address needed to program the hardware registers, then program the MAC
    // address into the Ethernet Controller registers.
    //
    macArray[0] = ((ulUser0 >>  0) & 0xff);
    macArray[1] = ((ulUser0 >>  8) & 0xff);
    macArray[2] = ((ulUser0 >> 16) & 0xff);
    macArray[3] = ((ulUser1 >>  0) & 0xff);
    macArray[4] = ((ulUser1 >>  8) & 0xff);
    macArray[5] = ((ulUser1 >> 16) & 0xff);


     //
     // Initialize ethernet module.
     //
    Ethernet_init(macArray);

    //
    // Initialze the lwIP library, using DHCP.
    //
    lwIPInit(0, macArray, IPAddr, NetMask, GWAddr, IPADDR_USE_STATIC);

    //
    // Wait forever in a loop. All the processing happens in the interrupts.
    //
    while(1)
    {

    }
}

//*****************************************************************************
//
// This function returns the local time (in PTPd internal time format). This
// is maintained by the system time counter present in the IEEE 1588
// timestamping module in F2838x device.
//
//*****************************************************************************
void
getTime(TimeInternal *time)
{
    //
    // Fetch the current system time.
    //
    Ethernet_getSysTimePTP(EMAC_BASE, (uint32_t *)&time->seconds,
                                (uint32_t *)&time->nanoseconds);
}

//*****************************************************************************
//
// This function will set the local time (provided in PTPd internal time
// format).  This time is maintained by the system time counter present in the
// IEEE 1588 timestamping module in F2838x device.
//
//*****************************************************************************
void
setTime(TimeInternal *time)
{
    //
    // Set the new system time.
    //
    Ethernet_setSysTimePTP(EMAC_BASE, (uint32_t)time->seconds,
                            (uint32_t)time->nanoseconds);
}

//*****************************************************************************
//
// Get the RX Timestamp.  This is called from the lwIP low_level_input function
// when configured to include PTPd support.
//
//*****************************************************************************
void
lwIPHostGetTime(u32_t *time_s, u32_t *time_ns)
{
    TimeInternal psRxTime;

    //
    // Get the current IEEE1588 time.
    //
    getTime(&psRxTime);

    //
    // Fill in the appropriate return values.
    //
    *time_s = psRxTime.seconds;
    *time_ns = psRxTime.nanoseconds;
}

//*****************************************************************************
//
// Based on the value (adj) provided by the PTPd Clock Servo routine, this
// function will adjust the SysTick periodic interval to allow fine-tuning of
// the PTP Clock.
//
//*****************************************************************************
Boolean
adjFreq(Integer32 adj)
{
        uint32_t add, rate;
        float subSecondInc;
        static uint32_t discard = 0;

        //
        // Update our rolling average and rate difference.
        //
        if(discard++ > DISCARD_INITIAL_VALUES)
        {
            //
            // Update the rolling average of the total rate adjustment.
            //
            gAdjAverage -= (gAdjAverage / ADJ_AVERAGE_SIZE);
            gAdjAverage += (adj / ADJ_AVERAGE_SIZE);

            //
            // Remember how far away from the moving average we are.
            //
            gDiffLatestPpb = MY_ABS(adj - gAdjAverage);

            gDiffValid = true;
        }
        else
        {
            //
            // Set the initial rolling average to the current clock offset
            // adjustment.
            //
            gAdjAverage = adj;
        }

        //
        // If there's no adjustment to make, just return.
        //
        if(!adj)
        {
            return(TRUE);
        }

        //
        // Fetch the subsecond increment value.
        //
        Ethernet_getConfigTimestampPTP(EMAC_BASE, &subSecondInc);

        //
        // Convert input to a number of system time ticks.
        //
        adj = (Integer32)((float)adj / subSecondInc);

        //
        // Work out the new ADDEND value based on the nominal tick rate and the
        // new adjustment.
        //
        rate = (uint32_t)((Integer32)gReqPTPClockFreq + adj);

        add = (0x80000000 / gReqPTPClockFreq) * rate;

        //
        // Set the new frequency divider value.
        //
        Ethernet_setAddend(EMAC_BASE, add);

    //
    // Return.
    //
    return(TRUE);
}
