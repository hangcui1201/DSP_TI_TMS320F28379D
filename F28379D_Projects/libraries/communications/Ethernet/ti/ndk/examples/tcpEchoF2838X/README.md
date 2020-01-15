
---
# tcpecho

---

## Example Summary

This application demonstrates how to use TCP.

## Peripherals Exercised

* `EMAC`      Connection to network

## Resources & Jumper Settings

This example needs the 
1. C2000Ware Package
2. SYS/BIOS 
3. XDC Tools
4. Network Developer Kit(NDK)
5. Network Services (NS)

Please refer to the C2000Ware Quick Start Guide 
(available at http://www.ti.com/tool/C2000WARE) on where to source them for 
F2838X device.

Before compiling please set the following Environment variables in windows
 NDK_INSTALL_DIR= <NDK Install location>
 NS_INSTALL_DIR= <NS Install location>
 C2000WARE_INSTALL_DIR=<your C2000 driverlib install location>
Example:
 NDK_INSTALL_DIR=C:\ti\f2838xSDK\ndk_f2838x_3_61_00_08_eng
 NS_INSTALL_DIR=C:\ti\f2838xSDK\ns_2_60_00_07
 C2000WARE_INSTALL_DIR=C:\ti\c2000\C2000Ware_2_00_00_02

Python 3.X is required for this example. To install python download the latest
version at https://www.python.org/downloads/release

## Example Usage

* Connect an Ethernet cable to the Ethernet port on the control card and connected
other end to a PC. 

* The device must be connected to a network with a DHCP server to run this
example successfully.

* The example starts the network stack. When the stack receives an IP address 
from the DHCP server, the IP address is written to the console. 
Use the CCS Run Time Object View -> SysMin -> Output Buffer to view the 
IP Address acquired by the device from the DHCP Server.


* Run the tcpSendReceive python script on the PC

Usage:

```
python tcpSendReceive.py <IP-addr> <port> <id> -l[length] -s[sleep in mS] -n[number of transmits per report]

  <IP-addr>     is the IP address of the device
  <port>        is the TCP port being listened to (1000)
  <id>          is a unique id for the executable. Printed out with a packet transmission report.
                It allows the user to run multiple instances of tcpSendReceive.


  Optional:
    -l[length]      size of the packet in bytes. Default is 1024 bytes.
    -s[sleep in mS] usleep time to between sends. Default is 0 mSecs.
    -n[number of transmits per report] the number of transmits to occur before being reported onto the console. Default is 100 transmits.
```

  Example:
        **python tcpSendReceive.py 192.168.1.100 1000 1 -s100**

* Messages such as the following will begin to appear on the terminal window when a TCP packet has been echoed back:
```
        Starting test with a 100 mSec delay between transmits and reporting every 100 transmit(s)
        [id 1] count = 100, time = 10
        [id 1] count = 200, time = 20
        [id 1] count = 300, time = 30
```

## Application Design Details

* This application uses two types of tasks:

1. **tcpHandler** - Creates a socket and accepts incoming connections.  When a
                  connection is established a **tcpWorker** task is dynamically
                  created to send or receive data.
2. **tcpWorker**  - Echoes TCP packets back to the client.

**tcpHandler** performs the following actions:
   * Create a socket and bind it to a port (1000 for this example).
   * Wait for incoming requests.
   * Once a request is received, a new tcpWorker task is dynamically created to
     manage the communication (echo TCP packets).
   * Waiting for new requests.

**tcpWorker** performs the following actions:
   * Allocate memory to serve as a TCP packet buffer.
   * Receive data from socket client.
   * Echo the TCP packet back to the client.
   * When client closes the socket, close server socket, free TCP buffer memory
     and exit the task.

* TI-RTOS:

    * When building in Code Composer Studio, the kernel configuration project will
be imported along with the example. The kernel configuration project is
referenced by the example, so it will be built first. The "release" kernel
configuration is the default project used. It has many debug features disabled.
These feature include assert checking, logging and runtime stack checks. 