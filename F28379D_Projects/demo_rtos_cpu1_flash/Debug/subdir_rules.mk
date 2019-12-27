################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
%.obj: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs920/ccs/tools/compiler/ti-cgt-c2000_18.12.4.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu2 --include_path="C:/ti/ccs920/ccs/tools/compiler/ti-cgt-c2000_18.12.4.LTS/include" --include_path="C:/Github_Repo/DSP_TI_TMS320F28379D/F28379D_Projects/demo_rtos_cpu1" --include_path="C:/Github_Repo/DSP_TI_TMS320F28379D/F28379D_Projects/device_support/F2837xD_headers/include" --include_path="C:/Github_Repo/DSP_TI_TMS320F28379D/F28379D_Projects/device_support/F2837xD_common/include" --include_path="C:/ti/bios_6_76_02_02/packages/ti/posix/ccs" --define=_FLASH --define=CPU1 --define=_LAUNCHXL_F28379D -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=coffabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

%.obj: ../%.asm $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs920/ccs/tools/compiler/ti-cgt-c2000_18.12.4.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu2 --include_path="C:/ti/ccs920/ccs/tools/compiler/ti-cgt-c2000_18.12.4.LTS/include" --include_path="C:/Github_Repo/DSP_TI_TMS320F28379D/F28379D_Projects/demo_rtos_cpu1" --include_path="C:/Github_Repo/DSP_TI_TMS320F28379D/F28379D_Projects/device_support/F2837xD_headers/include" --include_path="C:/Github_Repo/DSP_TI_TMS320F28379D/F28379D_Projects/device_support/F2837xD_common/include" --include_path="C:/ti/bios_6_76_02_02/packages/ti/posix/ccs" --define=_FLASH --define=CPU1 --define=_LAUNCHXL_F28379D -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=coffabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

build-1386885071:
	@$(MAKE) --no-print-directory -Onone -f subdir_rules.mk build-1386885071-inproc

build-1386885071-inproc: ../demo_rtos_cpu1.cfg
	@echo 'Building file: "$<"'
	@echo 'Invoking: XDCtools'
	"C:/ti/ccs920/xdctools_3_60_01_27_core/xs" --xdcpath="C:/ti/bios_6_76_02_02/packages;" xdc.tools.configuro -o configPkg -t ti.targets.C28_float -p ti.platforms.tms320x28:TMS320F28379D -r debug -c "C:/ti/ccs920/ccs/tools/compiler/ti-cgt-c2000_18.12.4.LTS" --compileOptions "-g" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

configPkg/linker.cmd: build-1386885071 ../demo_rtos_cpu1.cfg
configPkg/compiler.opt: build-1386885071
configPkg/: build-1386885071


