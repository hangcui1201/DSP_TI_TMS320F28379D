#include <F28379D_Coecsl.h>
#include <F28379D_Spi.h>
#include <F28x_Project.h>
#include <LS7366R.h>

#include <ti/sysbios/knl/Swi.h>

/* Swi handle defined in swi.cfg */
extern const Swi_Handle SWI_control;

//init_SPIB_LS7366R(void);
//void SPI_RXint_LS7366R(void);
//Swi_post(&SWI_control);

/*
Two LS7366 chips are interfaced to the F28379D through its SPI serial 
peripheral.

These LS7366 chips are 32 bit counters that count up when the optical 
encoder is turned in the positive direction and count down when turned 
in the opposite direction.

F28379D uses its SPI serial port to read this 32 bit count from each of 
the LS7366 chips.
**/

long SPIbyte1, SPIbyte2, SPIbyte3, SPIbyte4, SPIbyte5; // 4 bytes = 32 bits

long SPIenc1_reading = 0;
long SPIenc2_reading = 0;

int SPIenc_state = 0;
int	SPIenc_state_errors = 0;


void init_SPIB_LS7366R(void) {

    /************** Setup Gpio for chip select **************/

    // Chip select 1 - Gpio130
    // Chip select 2 - Gpio131

    EALLOW;
        // GPIO Port E MUX1 (GPEMUX1) Register
        GpioCtrlRegs.GPEMUX1.bit.GPIO130 = 0;    // Set pin as GPIO
        GpioCtrlRegs.GPEMUX1.bit.GPIO131 = 0;   // Set pin as GPIO

        // GPIO Port E Direction (GPEDIR) Register
        GpioCtrlRegs.GPEDIR.bit.GPIO130 = 1;    // Set GPIO as Output
        GpioCtrlRegs.GPEDIR.bit.GPIO131 = 1;    // Set GPIO as Output

        // GPIO Port E Set (GPESET) Register
        GpioDataRegs.GPESET.bit.GPIO130 = 1;    // Set the output as high, disable LS7366 1
        GpioDataRegs.GPESET.bit.GPIO131 = 1;    // Set the output as high, disable LS7366 2
    EDIS;


    // SPI Configuration Control Register (SPICCR)
    // Put SPI in reset condition (default)
    SpibRegs.SPICCR.bit.SPISWRESET = 0;  // Put SPI in reset

    /*
    This configuration POLARITY = 0, PHASE = 1 is due to default LS7366 setting

    Data is output on rising edge and input on falling edge. When no SPI data is sent,
    SPICLK is at low level. The data input and output edges depend on the value of the
    CLOCK PHASE bit (SPICTL.3) as follows:

    CLOCK PHASE = 0: Data is output on the rising edge of the SPICLK signal;
                     input data is latched on the falling edge of the SPICLK signal

    CLOCK PHASE = 1: Data is output one half-cycle before the first rising edge of the
                     SPICLK signal and on subsequent falling edges of the SPICLK signal;
                     input data is latched on the rising edge of the SPICLK signal
    **/

    // SPI Configuration Control Register (SPICCR)
    SpibRegs.SPICCR.bit.CLKPOLARITY = 0;     // Set for LS7366

    // SPICLK signal delayed by one half-cycle; polarity determined by the CLOCK POLARITY bit
    // SPI Operation Control Register (SPICTL)
    SpibRegs.SPICTL.bit.CLK_PHASE = 1;

    // SPI Configuration Control Register (SPICCR)
    // Set to transmit 8 bits
    SpibRegs.SPICCR.bit.SPICHAR = 7;

    // SPI Operation Control Register (SPICTL)
    // SPI configuraed as a Master
    SpibRegs.SPICTL.bit.MASTER_SLAVE = 1;

    // SPI Operation Control Register (SPICTL)
    // Master/Slave Transmit Enable
    // Enables transmission for the 4-pin option, (MOSI-MISO-SCK-SS)
    // Ensure to enable the receiver SPISTE/ input pin (namely the chip select SS/)
    SpibRegs.SPICTL.bit.TALK = 1;

    // SPI Operation Control Register (SPICTL)
    // This bit controls the SPI's ability to generate a transmit/receive interrupt
    // The SPI INT FLAG bit (SPISTS.6) is unaffected by this bit
    // Disable interrupt
    SpibRegs.SPICTL.bit.SPIINTENA = 0;


    /**************  SPI status register **************/
    /*
    Bit 7 = 1: Clears this bit.
    The RECEIVER OVERRUN Flag bit should be cleared during the interrupt service routine
    because the RECEIVER OVERRUN Flag bit and SPI INT FLAG bit (SPISTS.6) share the same
    interrupt vector. This will alleviate any possible doubt as to the source of the
    interrupt when the next byte is received

    Bit 6 = 1: This bit is cleared in one of three ways:
               Reading SPIRXBUF
               Writing a 0 to SPI SW RESET (SPICCR.7)
               Resetting the system

    Bit 5 = 1: This bit is cleared at reset
    **/
    SpibRegs.SPISTS.all = 0x00E0;   // (0000 0000 1110 0000)

    // SPI Baud Rate Register (SPIBRR)
    // SPI Baud Rate = LSPCLK / (SPIBRR + 1)
    SpibRegs.SPIBRR.bit.SPI_BIT_RATE = 39;          // Divide by 40 - 2.5 Mhz


    /***************** FIFO Settings *****************/

    // SPI FIFO Transmit (SPIFFTX) Register

    // Description: SPI reset
    // SPI FIFO can resume transmit or receive.
    // No effect to the SPI registers bits
    SpibRegs.SPIFFTX.bit.SPIRST = 1;

    // Description: SPI FIFO enhancements enable
    // SPI FIFO enhancements function are enabled
    SpibRegs.SPIFFTX.bit.SPIFFENA = 1;

    // Description: Transmit FIFO reset
    // Write 0 to reset the FIFO pointer to zero, and hold in reset
    SpibRegs.SPIFFTX.bit.TXFIFO = 0;

    // Description: TXFIFO clear
    // Write 1 to clear TXFFINT flag in bit 7 (TXFFINT=0)
    // TXFFINT=0: interrupt has not occured, this is a read-only bit
    SpibRegs.SPIFFTX.bit.TXFFINTCLR = 1;


    /************** SPI FIFO Receive (SPIFFRX) Register **************/

    // Description: Receive FIFO reset
    // Write 0 to reset the FIFO pointer to zero, and hold in reset
    SpibRegs.SPIFFRX.bit.RXFIFORESET = 0;

    // Description: Receive FIFO overflow clear
    // Write 1 to clear RXFFOVF flag in bit 15 (RXFFOVF - receive FIFO overflow flag)
    // RXFFOVF=0: receive FIFO has not overflowed, this is a read-only bit
    SpibRegs.SPIFFRX.bit.RXFFOVFCLR = 1;

    // Description: Receive FIFO interrupt clear
    // Write 1 to clear RXFFINT flag in bit 7 (RXFFINT - receive FIFO interrupt)
    // RXFFINT=0: RXFIFO interrupt has not occured, this is a read-only bit
    SpibRegs.SPIFFRX.bit.RXFFINTCLR = 1;

    // Description: Receive FIFO interrupt enable
    // RXFIFO interrupt based on RXFFIL match (greater than or equal to) will be disabled
    SpibRegs.SPIFFRX.bit.RXFFIENA = 0;


    /************** SPI FIFO Control (SPIFFCT) Register **************/
    /*
    These bits define the delay between every transfer from FIFO transmit buffer to transmit shift
    register. The delay is defined in number SPI serial clock cycles. The 8-bit register could define
    a minimum delay of 0 serial clock cycles and a maximum of 255 serial clock cycles
    **/
    // Description: FIFO transmit delay bits
    SpibRegs.SPIFFCT.all=0x00;


    /************** SPI Configuration Control Register (SPICCR) **************/
    /*
    SPI is ready to transmit or receive the next character. When the SPISWRESET bit is a 0, a
    character written to the transmitter will not be shifted out. When this bit is set, a new
    character must be written to the serial data register.
    **/
    // Pull the SPI out of reset
    SpibRegs.SPICCR.bit.SPISWRESET = 1;

    // SPI FIFO Transmit (SPIFFTX) Register
    // Description: transmit FIFO reset
    // Re-enable Transmit FIFO operation
    SpibRegs.SPIFFTX.bit.TXFIFO=1;

    // SPI FIFO Receive (SPIFFRX) Register
    // Description: receive FIFO reset
    // Re-enable receive FIFO operation
    SpibRegs.SPIFFRX.bit.RXFIFORESET=1;


    /***********************************************/

    // Enable LS7366 SPI SS/
    GpioDataRegs.GPECLEAR.bit.GPIO130 = 1;
    GpioDataRegs.GPECLEAR.bit.GPIO131 = 1;

    // F28379D send data to LS7366 (x2)
    // CLR COUNT all four chips
    // B(5-3) = 100 : Select CNTR
    // B(6-7) = 00 : Clear register
    // 0010 0000 0000 0000
    // SPITXBUF is a 16-bit register
    // 0010 0000 is the command to clear CNTR register, LS7366 will only receive the MSB 8 bits
    SpibRegs.SPITXBUF = ((unsigned)0x20)<<8;

    // Wait until finishing transmission (1 word)
    // Receive FIFO != 1 word = 2 bytes = 16 bits
    while (SpibRegs.SPIFFRX.bit.RXFFST != 1) {}
    DELAY_US(50);

    // Disable LS7366 SPI SS
    GpioDataRegs.GPESET.bit.GPIO130 = 1;
    GpioDataRegs.GPESET.bit.GPIO131 = 1;

    DELAY_US(50);

    // F28379D receive garbage data from LS7366 (x2)
    // Save data to SPIbyte1
    SPIbyte1 = SpibRegs.SPIRXBUF;


    /***********************************************/

    // Enable LS7366 SPI SS
    GpioDataRegs.GPECLEAR.bit.GPIO130 = 1;
    GpioDataRegs.GPECLEAR.bit.GPIO131 = 1;

    // F28379D send data to LS7366 (x2)
    // WR register, select MDR0
    // 10 001 000
    SpibRegs.SPITXBUF = ((unsigned)0x88)<<8;  // WR to MDR0

    // Set up Mode Register 0 (MDR0)
    // B1B0 = 11 : x4 quadrature count mode (four counts per quadrature cycle)
    // B3B2 = 00 : free-running count mode
    // B5B4 = 00 : disable index
    // B6 = 0 : Negative index input
    // B7 = 1 :  Filter clock division factor = 2
    // 1000 0011
    SpibRegs.SPITXBUF = ((unsigned)0x83)<<8;

    // Wait until finishing transmission (2 words = 4 bytes = 32 bits)
    // Receive FIFO != 2 words = 4 bytes = 32 bits
    while (SpibRegs.SPIFFRX.bit.RXFFST != 2) {}
    DELAY_US(50);

    // Disable LS7366 SPI SS
    GpioDataRegs.GPESET.bit.GPIO130 = 1;
    GpioDataRegs.GPESET.bit.GPIO131 = 1;

    DELAY_US(50);

    // F28379D receive the same size (2 words) garbage data from LS7366 (x2)
    // Save data to SPIbyte1, SPIbyte2
    SPIbyte1 = SpibRegs.SPIRXBUF;
    SPIbyte2 = SpibRegs.SPIRXBUF;


    /***********************************************/

    // Enable LS7366 SPI SS
    GpioDataRegs.GPECLEAR.bit.GPIO130 = 1;
    GpioDataRegs.GPECLEAR.bit.GPIO131 = 1;

    // F28379D send data to LS7366 (x2)
    // WR register, select MDR1
    // 10 010 000
    SpibRegs.SPITXBUF = ((unsigned)0x90)<<8;  // WR to MDR1

    // Set up Mode Register 1 (MDR1)
    // B1B0 = 00 : 4-byte counter mode, 32-bit up/down counter
    // B2 = 0 : enable counting
    // B3 : not used
    // B4 = 0 : NOP (No Operation)
    // B5 = 0 : NOP
    // B6 = 0 : NOP
    // B7 = 0 : NOP
    // 1000 0011
    SpibRegs.SPITXBUF = 0x00<<8;

    // Wait until finishing transmission (2 words = 4 bytes = 32 bits)
    // Receive FIFO != 2 word = 4 bytes = 32 bits
    while (SpibRegs.SPIFFRX.bit.RXFFST != 2) {}
    DELAY_US(50);

    // Disable LS7366 SPI SS
    GpioDataRegs.GPESET.bit.GPIO130 = 1;
    GpioDataRegs.GPESET.bit.GPIO131 = 1;

    // F28379D receive the same size (2 words) garbage data from LS7366 (x2)
    // Save data to SPIbyte1, SPIbyte2
    SPIbyte1 = SpibRegs.SPIRXBUF;
    SPIbyte2 = SpibRegs.SPIRXBUF;


    /***********************************************/

    // SPI Operation Control Register (SPICTL)
    // Enable interrupt
    SpibRegs.SPICTL.bit.SPIINTENA = 1;

    // SPI FIFO Receive (SPIFFRX) Register

    // Write 1 to clear RXFFOVF flag in bit 15 (RXFFOVF - receive FIFO overflow flag)
    SpibRegs.SPIFFRX.bit.RXFFOVFCLR = 1;

    // Write 1 to clear RXFFINT flag in bit 7 (RXFFINT - receive FIFO interrupt)
    SpibRegs.SPIFFRX.bit.RXFFINTCLR = 1;

    // RX FIFO interrupt based on RXFFIL match (greater than or equal to) will be enabled
    SpibRegs.SPIFFRX.bit.RXFFIENA = 1;


    /*****************  SPI  ********************/

    // PIE = Peripheral Interrupt Expansion

    // PIE Interrupt Acknowledge Register (PIEACK)
    // #define PIEACK_GROUP6 0x0020
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP6;   // Acknowledge interrupt to PIE

    // PIE Interrupt Enable Registers
    PieCtrlRegs.PIEIER6.bit.INTx3=1;          // Enable PIE Group 6, INT 3 (SPIB_RX)


//    PieCtrlRegs.PIECTRL.bit.ENPIE = 1;   // Enable the PIE block
//    PieCtrlRegs.PIEIER6.bit.INTx1 = 1;   //Enable Pie Group 6, Int 1 (spia_rx)
//    PieCtrlRegs.PIEIER6.bit.INTx2 = 1;   //enable pie gropu 6, int 2 (spia_tx)
//    PieCtrlRegs.PIEIER6.bit.INTx3=1;     // Enable PIE Group 6, INT 3 (spib_rx)
//    PieCtrlRegs.PIEIER6.bit.INTx4=1;     // Enable PIE Group 6, INT 4 (spib_tx)
    IER|= M_INT6;                         // Enable CPU INT6



}


/*
SPI_RXint() is the SPI receive ISR

The SPI serial ports sends and receives at the same time so when the 
receive interrupt occurs the SPI has also completed transmitting.

After transmitting the 8 bits command to latch the two LS7366 readings,
the SPI serial port generates a Receive interrupt (we are not using the 
SPI Transmit interrupt with the F28379D) indicating that the transfer is
complete. On receiving this interrupt the HWI function void SPI_RXint(void) 
is called.

Inside the SPI_RXint interrupt function, the TMS320F28379D selects the first
LS7366 chip and sends it a command to return its 32-bit count value.

On receiving the SPI's next interrupt the SPI_RXint interrupt function knows
that the 32 bit count reading is sitting in the SPI's FIFO buffer. After
reading the data from the first LS7366 chip, the function will select the 
second LS7366 chip and sends it the command to return its 32 bit count value.

This reading of the remaining LS7366 chips repeats one more time to acquire
the count readings of the second LS7366 chip.

On the final SPI receive interrupt that indicates the second count value has
been communicated from the second LS7366 chip the SWI SWI_control is posted.
The SWI's function is void control(void).

Here in this function void control(void) is where you will be putting your own 
code, but before your code the function updateData(); needs to be called. 
updateData() checks if there is any new sensor readings from the slow sensors 
like the compass and IR distance sensors and communicates those values to your 
code in predefined global variables.

After updateData() returns is where you should insert your code. At this point 
you have all the sensor readings at your access.

After your code you should call the function sendData(). This function communicates 
all the data sampled by the TMS320F28379D to the OMAPL138's DSP core through the McBSP
(Multi Channel Buffered Serial Port) serial port.

Then when 1 millisecond occurs again the entire process is repeated.

**/

// HWI function
void SPIB_RXint_LS7366R(void) {

	// Disable LS7366 SPI SS
	GpioDataRegs.GPESET.bit.GPIO130 = 1;
	GpioDataRegs.GPESET.bit.GPIO131 = 1;

	// SPIenc_state start from 1
	
	switch (SPIenc_state) {
		
		case 1:
		
		    // Receive garbage data 
			SPIbyte1 = SpibRegs.SPIRXBUF;
			
			SpibRegs.SPIFFRX.bit.RXFFIL = 5; // Send five times
			
			SPIenc_state = 2;
			
			// Enable first LS7366 SPI SS
			GpioDataRegs.GPECLEAR.bit.GPIO130 = 1;
			
			// 01 101 000
			// RD register, select OTR
			// Read CNTR data from OTR register instead of CNTR register 
			SpibRegs.SPITXBUF = ((unsigned)0x68)<<8;
			
			// Send garbage data in order to receive data
			SpibRegs.SPITXBUF = 0;
			SpibRegs.SPITXBUF = 0;
			SpibRegs.SPITXBUF = 0;
			SpibRegs.SPITXBUF = 0;

			break;
			
		case 2:
		
			// Receive garbage data for the command in case 1
			// SpibRegs.SPITXBUF = ((unsigned)0x68)<<8;
			SPIbyte1 = SpibRegs.SPIRXBUF;
			
			// LS7366 is 32 bit count value
			SPIbyte2 = SpibRegs.SPIRXBUF & 0xFF;
			SPIbyte3 = SpibRegs.SPIRXBUF & 0xFF;
			SPIbyte4 = SpibRegs.SPIRXBUF & 0xFF;
			SPIbyte5 = SpibRegs.SPIRXBUF & 0xFF;
			SPIenc1_reading = (SPIbyte2<<24) | (SPIbyte3<<16) | (SPIbyte4<<8) | SPIbyte5;

			SpibRegs.SPIFFRX.bit.RXFFIL = 5;
			
			SPIenc_state = 3;
			
			// Enable second LS7366 SPI SS
			GpioDataRegs.GPECLEAR.bit.GPIO131 = 1;
			
			// 01 101 000
			// RD register, select OTR
			// Read CNTR data from OTR register instead of CNTR register 
			SpibRegs.SPITXBUF = ((unsigned)0x68)<<8;
			
			// Send garbage data in order to receive data
			SpibRegs.SPITXBUF = 0;
			SpibRegs.SPITXBUF = 0;
			SpibRegs.SPITXBUF = 0;
			SpibRegs.SPITXBUF = 0;

			break;
			
		case 3:
		
			// Receive garbage data
			SPIbyte1 = SpibRegs.SPIRXBUF;
			
			// LS7366 is 32 bit count value
			SPIbyte2 = SpibRegs.SPIRXBUF & 0xFF;
			SPIbyte3 = SpibRegs.SPIRXBUF & 0xFF;
			SPIbyte4 = SpibRegs.SPIRXBUF & 0xFF;
			SPIbyte5 = SpibRegs.SPIRXBUF & 0xFF;
			SPIenc2_reading = (SPIbyte2<<24) | (SPIbyte3<<16) | (SPIbyte4<<8) | SPIbyte5;
			
            Swi_post(SWI_control);

            SPIenc_state = 0;

            break;
			
		default:
		
			SPIbyte1 = SpibRegs.SPIRXBUF;      // Should never get in here.
			SPIbyte2 = SpibRegs.SPIRXBUF;
			SPIbyte3 = SpibRegs.SPIRXBUF;
			SPIbyte4 = SpibRegs.SPIRXBUF;
			SPIbyte5 = SpibRegs.SPIRXBUF;
			SPIenc_state_errors++;
			
			break;
	}

	SpibRegs.SPIFFRX.bit.RXFFOVFCLR=1;         // Clear Overflow flag
	SpibRegs.SPIFFRX.bit.RXFFINTCLR=1; 	       // Clear Interrupt flag
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP6;    // Acknowledge interrupt to PIE

}



/*

start_SPI() is called every 1 ms inside the ADC ISR

start_SPI() selects all two of the LS7366 chips and sends
a command to them over the SPI to latch the current reading 
of their connected optical encoder. 

start_SPI() does not wait for the 8 bits of data to be transmitted. It 
starts the SPI transfer in the SPI peripheral unit. After start_SPI() 
initiates the transfer, the function ends, leaving the processor free 
for other tasks while the SPI peripheral handles the SPI transfer. Once 
the transfer is complete, the SPI's receive interrupt takes care of the
next steps in reading the four LS7366 chips.

After transmitting the 8 bits command to latch the four LS7366 readings, 
the SPI serial port generates a Receive interrupt (we are not using the 
SPI Transmit interrupt with the F28379D) indicating that the transfer is
complete. On receiving this interrupt the HWI function void SPI_RXint(void) 
is called.

**/

void start_SPIB_LS7366R(void) {

	// SPI FIFO Receive (SPIFFRX) Register
	
	/*
	Receive FIFO interrupt level bits: RXFFIL(4-0) = 11111 
	
	Receive FIFO generates an interrupt when the FIFO status bits (RXFFST4-0)
	are greater than or equal to the FIFO level bits (RXFFIL4-0). The default
	value of these bits after reset is 11111. This avoids frequent interrupts 
	after reset, as the receive FIFO will be empty most of the time.
	**/
	SpibRegs.SPIFFRX.bit.RXFFIL = 1;       // 00001
	
	// Enable LS7366 SPI SS
	GpioDataRegs.GPECLEAR.bit.GPIO130 = 1;
	GpioDataRegs.GPECLEAR.bit.GPIO131 = 1;
	
	// 11101000
	// Will receive garbage data for this command from LS7366 to F28379D
	SpibRegs.SPITXBUF = ((unsigned)0xE8)<<8; // Latch All ENCs
	
	SPIenc_state = 1;

}


