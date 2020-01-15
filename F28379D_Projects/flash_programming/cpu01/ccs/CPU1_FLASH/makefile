################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/ti/ccs920/ccs/tools/compiler/ti-cgt-c2000_18.12.4.LTS

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./F2837xD_CodeStartBranch.obj" \
"./F2837xD_DefaultISR.obj" \
"./F2837xD_Gpio.obj" \
"./F2837xD_Ipc.obj" \
"./F2837xD_PieCtrl.obj" \
"./F2837xD_PieVect.obj" \
"./F2837xD_SysCtrl.obj" \
"./F2837xD_usDelay.obj" \
"./Fapi_UserDefinedFunctions.obj" \
"./flash_programming_cpu01.obj" \
"../F021_API_F2837xD_FPU32.lib" \
"C:/Github_Repo/DSP_TI_TMS320F28379D/F28379D_Projects/flash_programming/cpu01/flash_programming_cpu1_FLASH.cmd" \
$(GEN_CMDS__FLAG) \
-lrts2800_fpu32.lib \
-lF2837xD_Headers_nonBIOS_cpu1.cmd \
-llibc.a \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
flash_programming_cpu01.out \

EXE_OUTPUTS__QUOTED += \
"flash_programming_cpu01.out" \

BIN_OUTPUTS += \
flash_programming_cpu01.hex \

BIN_OUTPUTS__QUOTED += \
"flash_programming_cpu01.hex" \


# All Target
all: flash_programming_cpu01.out

# Tool invocations
flash_programming_cpu01.out: $(OBJS) $(CMD_SRCS) $(LIB_SRCS) $(GEN_CMDS)
	@echo 'Building target: "$@"'
	@echo 'Invoking: C2000 Linker'
	"C:/ti/ccs920/ccs/tools/compiler/ti-cgt-c2000_18.12.4.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu2 --advice:performance=all --define=CPU1 --define=_FLASH -g --diag_suppress=10063 --diag_warning=225 --display_error_number --abi=coffabi -z -m"flash_programming_cpu01.map" --stack_size=0x100 --warn_sections -i"C:/ti/ccs920/ccs/tools/compiler/ti-cgt-c2000_18.12.4.LTS/lib" -i"C:/ti/ccs920/ccs/tools/compiler/ti-cgt-c2000_18.12.4.LTS/include" -i"C:/Github_Repo/DSP_TI_TMS320F28379D/F28379D_Projects/device_support/F2837xD_common/cmd" -i"C:/Github_Repo/DSP_TI_TMS320F28379D/F28379D_Projects/device_support/F2837xD_headers/cmd" -i"C:/Github_Repo/DSP_TI_TMS320F28379D/F28379D_Projects/libraries/flash_api/f2837xd/lib" --reread_libs --display_error_number --xml_link_info="flash_programming_cpu01_linkInfo.xml" --entry_point=code_start --rom_model -o "flash_programming_cpu01.out" $(ORDERED_OBJS)
	@echo 'Finished building target: "$@"'
	@echo ' '

flash_programming_cpu01.hex: $(EXE_OUTPUTS)
	@echo 'Building files: $(strip $(EXE_OUTPUTS__QUOTED))'
	@echo 'Invoking: C2000 Hex Utility'
	"C:/ti/ccs920/ccs/tools/compiler/ti-cgt-c2000_18.12.4.LTS/bin/hex2000"  -o "flash_programming_cpu01.hex" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building: $(strip $(EXE_OUTPUTS__QUOTED))'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(BIN_OUTPUTS__QUOTED)$(EXE_OUTPUTS__QUOTED)
	-$(RM) "F2837xD_CodeStartBranch.obj" "F2837xD_DefaultISR.obj" "F2837xD_Gpio.obj" "F2837xD_Ipc.obj" "F2837xD_PieCtrl.obj" "F2837xD_PieVect.obj" "F2837xD_SysCtrl.obj" "F2837xD_usDelay.obj" "Fapi_UserDefinedFunctions.obj" "flash_programming_cpu01.obj" 
	-$(RM) "F2837xD_DefaultISR.d" "F2837xD_Gpio.d" "F2837xD_Ipc.d" "F2837xD_PieCtrl.d" "F2837xD_PieVect.d" "F2837xD_SysCtrl.d" "Fapi_UserDefinedFunctions.d" "flash_programming_cpu01.d" 
	-$(RM) "F2837xD_CodeStartBranch.d" "F2837xD_usDelay.d" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

