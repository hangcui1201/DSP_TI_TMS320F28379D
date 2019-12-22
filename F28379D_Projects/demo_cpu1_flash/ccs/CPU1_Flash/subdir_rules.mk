################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
%.obj: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs920/ccs/tools/compiler/ti-cgt-c2000_18.12.4.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu2 --include_path="C:/ti/ccs920/ccs/tools/compiler/ti-cgt-c2000_18.12.4.LTS/include" --include_path="C:/Github_Repo/DSP_TI_TMS320F28379D/F28379D_Projects/device_support/F2837xD_headers/include" --include_path="C:/Github_Repo/DSP_TI_TMS320F28379D/F28379D_Projects/device_support/F2837xD_common/include" --advice:performance=all --define=CPU1 --define=_LAUNCHXL_F28379D --define=_FLASH -g --diag_suppress=1311 --diag_suppress=552 --diag_suppress=10063 --diag_warning=225 --display_error_number --abi=coffabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

%.obj: ../%.asm $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs920/ccs/tools/compiler/ti-cgt-c2000_18.12.4.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu2 --include_path="C:/ti/ccs920/ccs/tools/compiler/ti-cgt-c2000_18.12.4.LTS/include" --include_path="C:/Github_Repo/DSP_TI_TMS320F28379D/F28379D_Projects/device_support/F2837xD_headers/include" --include_path="C:/Github_Repo/DSP_TI_TMS320F28379D/F28379D_Projects/device_support/F2837xD_common/include" --advice:performance=all --define=CPU1 --define=_LAUNCHXL_F28379D --define=_FLASH -g --diag_suppress=1311 --diag_suppress=552 --diag_suppress=10063 --diag_warning=225 --display_error_number --abi=coffabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


