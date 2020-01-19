#include <F28379D_Coecsl.h>
#include <F28379D_Spi.h>
#include "F28x_Project.h"

void init_SPIB_GPIO(void) {

    // MOSI-B - GPIO24
    // MISO-B - GPIO25
    // CLK-B  - GPIO26
    // STE-B  - GPIO27 (not used, ste = slave transmit enable)

    EALLOW;

     /* Enable internal pull-up for the selected pins */
     // Pull-ups can be enabled or disabled by the user.
     // This will enable the pullups for the specified pins.
    GpioCtrlRegs.GPAPUD.bit.GPIO24 = 0;  // Enable pull-up on Gpio24 (MOSI-B)
    GpioCtrlRegs.GPAPUD.bit.GPIO25 = 0;  // Enable pull-up on Gpio25 (MISO-B)
    GpioCtrlRegs.GPAPUD.bit.GPIO26 = 0;  // Enable pull-up on Gpio26 (CLK-B)
//    GpioCtrlRegs.GPAPUD.bit.GPIO27 = 0;  // Enable pull-up on Gpio27 (STE-B)

     /* Set qualification for selected pins to asynch only */
     // This will select asynch (no qualification) for the selected pins.
    GpioCtrlRegs.GPAQSEL2.bit.GPIO24 = 3;  // Asynch input Gpio24 (MOSI-B)
    GpioCtrlRegs.GPAQSEL2.bit.GPIO25 = 3;  // Asynch input Gpio25 (MISO-B)
    GpioCtrlRegs.GPAQSEL2.bit.GPIO26 = 3;  // Asynch input Gpio26 (CLK-B)
//    GpioCtrlRegs.GPAQSEL2.bit.GPIO27 = 3;  // Asynch input Gpio27 (STE-B)

     /* Configure SPI-b pins using GPIO regs*/
     // This specifies which of the possible GPIO pins will be SPI functional pins.
    GpioCtrlRegs.GPAMUX2.bit.GPIO24 = 2;   // Configure Gpio24 (MOSI-B)
    GpioCtrlRegs.GPAGMUX2.bit.GPIO24 = 1;
    GpioCtrlRegs.GPAMUX2.bit.GPIO25 = 2;   // Configure Gpio25 (MISO-B)
    GpioCtrlRegs.GPAGMUX2.bit.GPIO25 = 1;
    GpioCtrlRegs.GPAMUX2.bit.GPIO26 = 2;   // Configure Gpio26 (CLK-B)
    GpioCtrlRegs.GPAGMUX2.bit.GPIO26 = 1;
//    GpioCtrlRegs.GPAMUX2.bit.GPIO27 = 6;   // Configure Gpio27 (STE-B)

    EDIS;

}
