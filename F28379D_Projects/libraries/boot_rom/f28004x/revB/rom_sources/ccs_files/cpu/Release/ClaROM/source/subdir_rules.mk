################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
ClaROM/source/cla_rom_version.obj: C:/Users/a0221343/Git/bootROM/bootrom_f28004x/F28004x_ROM_dev_PG2.0/F28004x_ROM/ClaROM/source/cla_rom_version.asm $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-c2000_6.4.4/bin/cl2000" -v28 -ml --float_support=fpu32 --tmu_support=tmu0 --cla_support=cla0 --vcu_support=vcu0 -Ooff --include_path="C:/ti/ccsv6/tools/compiler/ti-cgt-c2000_6.4.4/include" --include_path="C:/Users/a0221343/Git/bootROM/bootrom_f28004x/F28004x_ROM_dev_PG2.0/F28004x_ROM/bootROM/include" --include_path="C:/Users/a0221343/Git/bootROM/bootrom_f28004x/F28004x_ROM_dev_PG2.0/F28004x_ROM/bootROM/source/tables" --include_path="C:/Users/a0221343/Git/bootROM/bootrom_f28004x/F28004x_ROM_dev_PG2.0/F28004x_ROM/driverlib" --include_path="C:/Users/a0221343/Git/bootROM/bootrom_f28004x/F28004x_ROM_dev_PG2.0/F28004x_ROM/inc" --include_path="C:/Users/a0221343/Git/bootROM/bootrom_f28004x/F28004x_ROM_dev_PG2.0/F28004x_ROM" -g --no_inlining --gcc --diag_warning=225 --display_error_number --asm_listing --preproc_with_compile --preproc_dependency="ClaROM/source/cla_rom_version.d" --obj_directory="ClaROM/source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

ClaROM/source/fft_twiddle_bit_reverse.obj: C:/Users/a0221343/Git/bootROM/bootrom_f28004x/F28004x_ROM_dev_PG2.0/F28004x_ROM/ClaROM/source/fft_twiddle_bit_reverse.asm $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-c2000_6.4.4/bin/cl2000" -v28 -ml --float_support=fpu32 --tmu_support=tmu0 --cla_support=cla0 --vcu_support=vcu0 -Ooff --include_path="C:/ti/ccsv6/tools/compiler/ti-cgt-c2000_6.4.4/include" --include_path="C:/Users/a0221343/Git/bootROM/bootrom_f28004x/F28004x_ROM_dev_PG2.0/F28004x_ROM/bootROM/include" --include_path="C:/Users/a0221343/Git/bootROM/bootrom_f28004x/F28004x_ROM_dev_PG2.0/F28004x_ROM/bootROM/source/tables" --include_path="C:/Users/a0221343/Git/bootROM/bootrom_f28004x/F28004x_ROM_dev_PG2.0/F28004x_ROM/driverlib" --include_path="C:/Users/a0221343/Git/bootROM/bootrom_f28004x/F28004x_ROM_dev_PG2.0/F28004x_ROM/inc" --include_path="C:/Users/a0221343/Git/bootROM/bootrom_f28004x/F28004x_ROM_dev_PG2.0/F28004x_ROM" -g --no_inlining --gcc --diag_warning=225 --display_error_number --asm_listing --preproc_with_compile --preproc_dependency="ClaROM/source/fft_twiddle_bit_reverse.d" --obj_directory="ClaROM/source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


