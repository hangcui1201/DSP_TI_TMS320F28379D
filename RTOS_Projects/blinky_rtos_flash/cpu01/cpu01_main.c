#include <xdc/std.h>

#include <xdc/runtime/Log.h>
#include <xdc/runtime/Error.h>
#include <xdc/runtime/System.h>

#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>
#include <ti/sysbios/knl/Swi.h>
#include <ti/sysbios/knl/Clock.h>
#include <ti/sysbios/knl/Semaphore.h>
#include <ti/sysbios/family/c28/Hwi.h>

#include "F28x_Project.h"     // Device Headerfile and Examples Include File
#include "F2837xD_device.h"
#include "F2837xD_Ipc_drivers.h"

// Customized functions
#include "LCD.h"
#include "LS7366R.h"
#include "F28379D_EPwm.h"
#include "F28379D_EQep.h"
#include "F28379D_Serial.h"
#include "F28379D_Spi.h"

#define PI       3.1415926535897932384626433832795
#define TWOPI    6.2831853071795864769252867665590
#define HALFPI   1.5707963267948966192313216916398

///* Swi handle defined in swi.cfg */
//extern const Swi_Handle SWI_control;

#ifdef _FLASH
    // These are defined by the linker (see device linker command file)
    extern unsigned int RamfuncsLoadStart;
    extern unsigned int RamfuncsLoadSize;
    extern unsigned int RamfuncsRunStart;
#endif

int adcb0result = 0;
int adcb1result = 0;

float u_ctrl_1a = 0.0;
float u_ctrl_1b = 0.0;

float enc_read1 = 0.0;
float enc_read2 = 0.0;

// PI control for speed control
float dt = 0.001;                // sample period 1ms

float motor_speed_refer = 0.0;   // rad/s
float motor_speed = 0.0;

float enc_read1_pre = 0.0;
float enc_read1_cur = 0.0;

float Kp = 0.0; //20
float Ki = 0.0; //1

float err = 0;
float err_pre = 0;

float errSum = 0;      // integral
float errSum_pre = 0;


// LS7366R

extern int SPIenc_state;
extern long SPIenc1_reading;
extern long SPIenc2_reading;

float SPIB_enc1_rad = 0;
float SPIB_enc2_rad = 0;


// SYS/BIOS Clock function
long int time_counter = 0;
void DoEveryMilliSecond_CPU1(void){

//    enc_read1_cur = read_Enc1();
//
//    motor_speed = (enc_read1_cur - enc_read1_pre)/dt;  // rad/s
//
//    enc_read1_pre = enc_read1_cur;
//
//    err = motor_speed_refer - motor_speed;
//
//    errSum = errSum_pre + 0.0005 * (err + err_pre);
//
//    u_ctrl_1a = Kp * err + Ki * errSum;
//
//    if((u_ctrl_1a >= 10) || (u_ctrl_1a <= -10)){
//        // do not update errSum
//        errSum = errSum_pre;
//    }
//    else{
//        // update errSum as usual
//        errSum_pre = errSum;
//    }
//
//    err_pre = err;
//
//    set_EPWM1A(u_ctrl_1a);

//    if((time_counter%100)==0){
//        UART_printfLine(1,"u=%.3f Ik=%.3f", u_ctrl_1a, errSum);
//        UART_printfLine(2,"V=%.3f r=%.3f", motor_speed, motor_speed_refer);
//    }
//
//    time_counter++;

    start_SPIB_LS7366R();

}



// SYS/BIOS Clock function
void DoEverySecond_CPU1(void){
    GpioDataRegs.GPADAT.bit.GPIO31 ^= 1;
}


void control(void) {

    // 30*100*4 = 12000
    SPIB_enc1_rad = ((float) SPIenc1_reading)*(TWOPI/(12000.0f)); // left encoder
//    SPIB_enc1_rad = -SPIB_enc1_rad;
    SPIB_enc2_rad = ((float) SPIenc2_reading)*(TWOPI/(12000.0f)); // right encoder
}




//#pragma CODE_SECTION(function_name, "ramfuncs");
//void function_name(void)
//{}

int main() {

    #ifdef _FLASH
        memcpy(&RamfuncsRunStart, &RamfuncsLoadStart, (size_t)&RamfuncsLoadSize);
    #endif

    // Comment this when use CCS for debugging
//    #ifdef _FLASH
//        // Send boot command to allow the CPU2 application to begin execution
//        IPCBootCPU2(C1C2_BROM_BOOTMODE_BOOT_FROM_FLASH);
//    #else
//        // Send boot command to allow the CPU2 application to begin execution
//        IPCBootCPU2(C1C2_BROM_BOOTMODE_BOOT_FROM_RAM);
//    #endif

    #ifdef _FLASH
        InitFlash();
    #endif

    // Initialize System Control: PLL, WatchDog, enable Peripheral Clocks
    InitSysCtrl(); // F2837xD_SysCtrl.c

    // Initialize GPIO
    InitGpio(); // F2837xD_Gpio.c

    EALLOW;

    // For CPU1
    // Enable an GPIO output on GPIO31, set it high
    GpioCtrlRegs.GPAPUD.bit.GPIO31 = 0;   // Enable pullup on GPIO31
    GpioDataRegs.GPASET.bit.GPIO31 = 1;   // Load output latch
    GpioCtrlRegs.GPAMUX2.bit.GPIO31 = 0;  // GPIO31 = GPIO31
    GpioCtrlRegs.GPADIR.bit.GPIO31 = 1;   // GPIO31 = output

    // For CPU2
    // Enable an GPIO output on GPIO34, set it high
    GpioCtrlRegs.GPBPUD.bit.GPIO34 = 0;   // Enable pullup on GPIO3
    GpioDataRegs.GPBSET.bit.GPIO34 = 1;   // Load output latch
    GpioCtrlRegs.GPBDIR.bit.GPIO34 = 1;   // GPIO34 = output
    GpioCtrlRegs.GPBCSEL1.bit.GPIO34 = 2; // MUX with CPU2
    GpioCtrlRegs.GPBGMUX1.bit.GPIO34 = 0;
    GpioCtrlRegs.GPBMUX1.bit.GPIO34 = 0;

    // Driverlib way for CPU2
//    GpioCtrlRegs.GPBDIR.bit.GPIO34 = 1;   // GPIO34 = output
//    GPIO_SetupPinOptions(34, GPIO_OUTPUT, GPIO_PUSHPULL);
//    GPIO_SetupPinMux(34, GPIO_MUX_CPU2, 0);

    EDIS;

//    /********************************** Init EPwm1A **********************************/
//    init_EPWM1A_GPIO();      // init GPIO0 as EPWM1A (J4-40)
//    init_EPWM1A();           // init EPWM1A with a 20KHz carrier frequency PWM signal.
//    set_EPWM1A(u_ctrl_1a);   // set to 0 (50% duty cycle)at the beginning, update in SYS/BIOS
//
//    init_EPWM1B_GPIO();      // init GPIO1 as EPWM1A (J4-39)
//    init_EPWM1B();           // init EPWM1B with a 20KHz carrier frequency PWM signal.
//    set_EPWM1B(u_ctrl_1b);   // set to 0 (50% duty cycle)at the beginning, update in SYS/BIOS
//
//
//    /****************************** Init EQep1 and EQep2 *****************************/
//    // J14 - EQEP1A(GPIO20), EQEP1B(GPIO21), J15 - EQEP2A(GPIO54), EQEP2B(GPIO55)
//    init_EQEPs();
//    enc_read1 = read_Enc1(); // read encoder1 at the beginning, update in SYS/BIOS func
//    enc_read2 = read_Enc2(); // read encoder2 at the beginning, update in SYS/BIOS func
//
//
//    /********************************* Init Text LCD *********************************/
//
//    init_serial(&SerialC, 19200, NULL);
//    init_lcd(90);
//
//    UART_printfLine(1, "Digital Control 0f");
//    UART_printfLine(2, "Dynamic Systems");
//    UART_printfLine(3, "Univer of Illinois");
//    UART_printfLine(4, "at Urbana-Champaign");

    /********************************* Init SPIB GPIO *********************************/
    init_SPIB_GPIO();
    init_SPIB_LS7366R();





    /*************************  NO CODE below here in Main() *************************/

    // Clear all interrupts and initialize PIE vector table:
    // Disable CPU interrupts
    DINT;

    // Disable CPU interrupts and clear all CPU interrupt flags
//    IER = 0x0000;
    IFR = 0x0000;

    // Enable global Interrupts and higher priority real-time debug events
    EINT;  // Enable Global interrupt INTM
    ERTM;  // Enable Global real-time interrupt DBGM

    PieCtrlRegs.PIEACK.all = (PIEACK_GROUP8 | PIEACK_GROUP9);  // ACKnowledge any SCI interrupt requests

    BIOS_start();

    return 0;

}





