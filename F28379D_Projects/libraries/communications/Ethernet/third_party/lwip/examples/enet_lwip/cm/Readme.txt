# Ethernet with lwIP

About:
This example application demonstrates the operation of the F2838x microcontroller
Ethernet controller using the lwIP TCP/IP Stack. This example sets up the Ethernet 
MAC. It then configures the lwIP network stack with a static IP address of 
192.168.0.4.

Protocols enabled:
ARP, ICMP, TCP/IP, HTTP

Current Capabilities:
Once programmed, the device sits in an endless loop and all the processing takes
place in the interrupt context. This example is capable of the following:
1.ICMP ping - sends ping responses to ping requests.
2.HTTP Webserver example - displays a webpage with a basic bidirectional data 
transfer utility.

Note: The sender should be in the same network (192.168.0.x / 255.255.255.0).

Steps to run this example:
1. Program the c28 core with correct pinmux configuration. 
2. Program the cm core with the enet_lwip example binary. Let the controller run.
   It is programmed with a static IP address - 192.168.0.4.
3. On any sending device, set the IP address to something like 192.168.0.x so that
   the sending device and the f2838x device are in the same network. Now, both the 
   device can be connected directly or even through a switch in between. Since the
   f2838x device supports ARP, it will be able to respond to ICMP/HTTP requests
   even through the switch.
4. For ping example:   
    a. Ping the f2838x device which can be typically done with standard 'ping' command
       on most devices. 
                    ping 192.168.0.4
    b. The sender device should be able to see ping replies from the f2838x device's 
       IP address.
5. For Webserver example:
    a. Open a web browser in the other device. Type 192.168.0.4 in the address bar.
    b. A webpage shows up with TI logo and an interactive button. Clicking on the 
       button should update a number value on the webpage. Button click sends an
       HTTP query to the device which sends back the value of a global counter and
       then increments the value of the counter. So, the webpage value should increase
       with each button click.
       
+Note: The webserver is currently capable of handling only the HTTP requests and not
      cgi/ssi scripting.

++Note on Custom Webserver Pages/FileSystem :
1. Design your own webserver pages and store them in a folder under 
   {LWIP_DIR}/src/apps/http/fs. Run the makefsdata.exe program which will generate 
   "fsdata.c" file in the same directory which has all the files converted and stored
   as C arrays.
2. Copy the contents of this file into the {LWIP_DIR}/src/apps/http/fsdata.c file. 
   This file is included in this enet_lwip project and hence the webserver will 
   get updated in the device and query to the device IP address in the network will
   show the updated webpages.

For additional details on lwIP, refer to the lwIP web page at:
http://savannah.nongnu.org/projects/lwip/
