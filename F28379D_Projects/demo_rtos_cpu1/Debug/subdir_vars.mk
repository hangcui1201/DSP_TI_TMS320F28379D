################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Add inputs and outputs from these tool invocations to the build variables 
CFG_SRCS += \
../demo_rtos_cpu1.cfg 

CMD_SRCS += \
../F2837xD_Headers_BIOS_cpu1.cmd \
../TMS320F28379D.cmd 

ASM_SRCS += \
../F2837xD_usDelay.asm 

C_SRCS += \
../F2837xD_Adc.c \
../F2837xD_EPwm.c \
../F2837xD_EQep.c \
../F2837xD_GlobalVariableDefs.c \
../F2837xD_Gpio.c \
../F2837xD_I2C.c \
../F2837xD_Spi.c \
../F2837xD_SysCtrl.c \
../F2837xD_can.c \
../demo_rtos_cpu1.c 

GEN_CMDS += \
./configPkg/linker.cmd 

GEN_FILES += \
./configPkg/linker.cmd \
./configPkg/compiler.opt 

GEN_MISC_DIRS += \
./configPkg/ 

C_DEPS += \
./F2837xD_Adc.d \
./F2837xD_EPwm.d \
./F2837xD_EQep.d \
./F2837xD_GlobalVariableDefs.d \
./F2837xD_Gpio.d \
./F2837xD_I2C.d \
./F2837xD_Spi.d \
./F2837xD_SysCtrl.d \
./F2837xD_can.d \
./demo_rtos_cpu1.d 

GEN_OPTS += \
./configPkg/compiler.opt 

OBJS += \
./F2837xD_Adc.obj \
./F2837xD_EPwm.obj \
./F2837xD_EQep.obj \
./F2837xD_GlobalVariableDefs.obj \
./F2837xD_Gpio.obj \
./F2837xD_I2C.obj \
./F2837xD_Spi.obj \
./F2837xD_SysCtrl.obj \
./F2837xD_can.obj \
./F2837xD_usDelay.obj \
./demo_rtos_cpu1.obj 

ASM_DEPS += \
./F2837xD_usDelay.d 

GEN_MISC_DIRS__QUOTED += \
"configPkg\" 

OBJS__QUOTED += \
"F2837xD_Adc.obj" \
"F2837xD_EPwm.obj" \
"F2837xD_EQep.obj" \
"F2837xD_GlobalVariableDefs.obj" \
"F2837xD_Gpio.obj" \
"F2837xD_I2C.obj" \
"F2837xD_Spi.obj" \
"F2837xD_SysCtrl.obj" \
"F2837xD_can.obj" \
"F2837xD_usDelay.obj" \
"demo_rtos_cpu1.obj" 

C_DEPS__QUOTED += \
"F2837xD_Adc.d" \
"F2837xD_EPwm.d" \
"F2837xD_EQep.d" \
"F2837xD_GlobalVariableDefs.d" \
"F2837xD_Gpio.d" \
"F2837xD_I2C.d" \
"F2837xD_Spi.d" \
"F2837xD_SysCtrl.d" \
"F2837xD_can.d" \
"demo_rtos_cpu1.d" 

GEN_FILES__QUOTED += \
"configPkg\linker.cmd" \
"configPkg\compiler.opt" 

ASM_DEPS__QUOTED += \
"F2837xD_usDelay.d" 

C_SRCS__QUOTED += \
"../F2837xD_Adc.c" \
"../F2837xD_EPwm.c" \
"../F2837xD_EQep.c" \
"../F2837xD_GlobalVariableDefs.c" \
"../F2837xD_Gpio.c" \
"../F2837xD_I2C.c" \
"../F2837xD_Spi.c" \
"../F2837xD_SysCtrl.c" \
"../F2837xD_can.c" \
"../demo_rtos_cpu1.c" 

ASM_SRCS__QUOTED += \
"../F2837xD_usDelay.asm" 


