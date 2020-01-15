This example application demonstrates the operation of the F2838x Ethernet
controller with the third-party ptpd and lwIP TCP/IP stacks. The device
is programmed with a static IP address - 192.168.0.4.

Once programmed, the device will respond to ping request from other devices
which are in the same network (255.255.255.0).

Further, the IEEE-1588 based ptpd software stack enables the device to
synchronize the internal clock to a network master clock source.

Summary of stack working:
The ptpd stack configures the device in slave mode. Then every systick
period, the main application checks if any PTP packet is received in the
queues maintained at ptpd layer. According to the packets received, the
state machine in the ptpd stack progresses and calculates the two important
time delta w.r.t master namely "Offset From Master" and "Mean Path Delay".
Based on these calculations, the stack issues call to the F2838x ethernet
drivers to adjust the system time.

The software stack uses "Fine" method to correct system time. Based on the
offset from master, drift value is calculated from the master and in turn
the addend value in the ethernet system time module is adjusted. Addend
based adjustments can factor in the drift in the frequency from the master
clock source.

The System and PTP Reference clock frequency are 125MHz and 100MHz
respectively, by default, which are configured by c28x core. In this
application example, these values are hard-programmed and not known to the
code dynamically. Also, the desired accuracy is assumed to be 20ns in this
code which corresponds to 50MHz and this is different from PTP Reference
clock frequency which is, in reality, just used to achieve this desired
accuracy. Note that the desired (accuracy)frequency should be less than the
PTP Reference clock frequency.

To track the working of the example, open the "Expressions" view and add
the following two expressions: "gPTPClock.offsetFromMaster" and
"gDiffLatestPpb". The first one indicates the offset from master in
nanoseconds. This should decrease in magnitude over time to the order of
around +-2500ns. The second one indicates the drift in frequency from the
master in terms of parts per billion. This value should also decrease
correspondingly over time.

For additional details on lwIP, refer to the lwIP web page at:
http://savannah.nongnu.org/projects/lwip/

For additional details on the PTPd software, refer to the PTPd web page at:
http://ptpd.sourceforge.net