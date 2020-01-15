################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
bootROM/source/tables/CFFT_f32_twiddleFactors.obj: C:/Users/a0221343/Git/bootROM/bootrom_f28004x/F28004x_ROM_dev_PG2.0/F28004x_ROM/bootROM/source/tables/CFFT_f32_twiddleFactors.asm $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-c2000_6.4.4/bin/cl2000" -v28 -ml --float_support=fpu32 --tmu_support=tmu0 --cla_support=cla0 --vcu_support=vcu0 -Ooff --include_path="C:/ti/ccsv6/tools/compiler/ti-cgt-c2000_6.4.4/include" --include_path="C:/Users/a0221343/Git/bootROM/bootrom_f28004x/F28004x_ROM_dev_PG2.0/F28004x_ROM/bootROM/include" --include_path="C:/Users/a0221343/Git/bootROM/bootrom_f28004x/F28004x_ROM_dev_PG2.0/F28004x_ROM/bootROM/source/tables" --include_path="C:/Users/a0221343/Git/bootROM/bootrom_f28004x/F28004x_ROM_dev_PG2.0/F28004x_ROM/driverlib" --include_path="C:/Users/a0221343/Git/bootROM/bootrom_f28004x/F28004x_ROM_dev_PG2.0/F28004x_ROM/inc" --include_path="C:/Users/a0221343/Git/bootROM/bootrom_f28004x/F28004x_ROM_dev_PG2.0/F28004x_ROM" -g --no_inlining --gcc --diag_warning=225 --display_error_number --asm_listing --preproc_with_compile --preproc_dependency="bootROM/source/tables/CFFT_f32_twiddleFactors.d" --obj_directory="bootROM/source/tables" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

bootROM/source/tables/IQmathTables.obj: C:/Users/a0221343/Git/bootROM/bootrom_f28004x/F28004x_ROM_dev_PG2.0/F28004x_ROM/bootROM/source/tables/IQmathTables.asm $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-c2000_6.4.4/bin/cl2000" -v28 -ml --float_support=fpu32 --tmu_support=tmu0 --cla_support=cla0 --vcu_support=vcu0 -Ooff --include_path="C:/ti/ccsv6/tools/compiler/ti-cgt-c2000_6.4.4/include" --include_path="C:/Users/a0221343/Git/bootROM/bootrom_f28004x/F28004x_ROM_dev_PG2.0/F28004x_ROM/bootROM/include" --include_path="C:/Users/a0221343/Git/bootROM/bootrom_f28004x/F28004x_ROM_dev_PG2.0/F28004x_ROM/bootROM/source/tables" --include_path="C:/Users/a0221343/Git/bootROM/bootrom_f28004x/F28004x_ROM_dev_PG2.0/F28004x_ROM/driverlib" --include_path="C:/Users/a0221343/Git/bootROM/bootrom_f28004x/F28004x_ROM_dev_PG2.0/F28004x_ROM/inc" --include_path="C:/Users/a0221343/Git/bootROM/bootrom_f28004x/F28004x_ROM_dev_PG2.0/F28004x_ROM" -g --no_inlining --gcc --diag_warning=225 --display_error_number --asm_listing --preproc_with_compile --preproc_dependency="bootROM/source/tables/IQmathTables.d" --obj_directory="bootROM/source/tables" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

bootROM/source/tables/RFFT_f32_twiddleFactors.obj: C:/Users/a0221343/Git/bootROM/bootrom_f28004x/F28004x_ROM_dev_PG2.0/F28004x_ROM/bootROM/source/tables/RFFT_f32_twiddleFactors.asm $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-c2000_6.4.4/bin/cl2000" -v28 -ml --float_support=fpu32 --tmu_support=tmu0 --cla_support=cla0 --vcu_support=vcu0 -Ooff --include_path="C:/ti/ccsv6/tools/compiler/ti-cgt-c2000_6.4.4/include" --include_path="C:/Users/a0221343/Git/bootROM/bootrom_f28004x/F28004x_ROM_dev_PG2.0/F28004x_ROM/bootROM/include" --include_path="C:/Users/a0221343/Git/bootROM/bootrom_f28004x/F28004x_ROM_dev_PG2.0/F28004x_ROM/bootROM/source/tables" --include_path="C:/Users/a0221343/Git/bootROM/bootrom_f28004x/F28004x_ROM_dev_PG2.0/F28004x_ROM/driverlib" --include_path="C:/Users/a0221343/Git/bootROM/bootrom_f28004x/F28004x_ROM_dev_PG2.0/F28004x_ROM/inc" --include_path="C:/Users/a0221343/Git/bootROM/bootrom_f28004x/F28004x_ROM_dev_PG2.0/F28004x_ROM" -g --no_inlining --gcc --diag_warning=225 --display_error_number --asm_listing --preproc_with_compile --preproc_dependency="bootROM/source/tables/RFFT_f32_twiddleFactors.d" --obj_directory="bootROM/source/tables" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

bootROM/source/tables/mac_plc.obj: C:/Users/a0221343/Git/bootROM/bootrom_f28004x/F28004x_ROM_dev_PG2.0/F28004x_ROM/bootROM/source/tables/mac_plc.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-c2000_6.4.4/bin/cl2000" -v28 -ml --float_support=fpu32 --tmu_support=tmu0 --cla_support=cla0 --vcu_support=vcu0 -Ooff --include_path="C:/ti/ccsv6/tools/compiler/ti-cgt-c2000_6.4.4/include" --include_path="C:/Users/a0221343/Git/bootROM/bootrom_f28004x/F28004x_ROM_dev_PG2.0/F28004x_ROM/bootROM/include" --include_path="C:/Users/a0221343/Git/bootROM/bootrom_f28004x/F28004x_ROM_dev_PG2.0/F28004x_ROM/bootROM/source/tables" --include_path="C:/Users/a0221343/Git/bootROM/bootrom_f28004x/F28004x_ROM_dev_PG2.0/F28004x_ROM/driverlib" --include_path="C:/Users/a0221343/Git/bootROM/bootrom_f28004x/F28004x_ROM_dev_PG2.0/F28004x_ROM/inc" --include_path="C:/Users/a0221343/Git/bootROM/bootrom_f28004x/F28004x_ROM_dev_PG2.0/F28004x_ROM" -g --no_inlining --gcc --diag_warning=225 --display_error_number --asm_listing --preproc_with_compile --preproc_dependency="bootROM/source/tables/mac_plc.d" --obj_directory="bootROM/source/tables" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

bootROM/source/tables/phy_primeprefTable.obj: C:/Users/a0221343/Git/bootROM/bootrom_f28004x/F28004x_ROM_dev_PG2.0/F28004x_ROM/bootROM/source/tables/phy_primeprefTable.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-c2000_6.4.4/bin/cl2000" -v28 -ml --float_support=fpu32 --tmu_support=tmu0 --cla_support=cla0 --vcu_support=vcu0 -Ooff --include_path="C:/ti/ccsv6/tools/compiler/ti-cgt-c2000_6.4.4/include" --include_path="C:/Users/a0221343/Git/bootROM/bootrom_f28004x/F28004x_ROM_dev_PG2.0/F28004x_ROM/bootROM/include" --include_path="C:/Users/a0221343/Git/bootROM/bootrom_f28004x/F28004x_ROM_dev_PG2.0/F28004x_ROM/bootROM/source/tables" --include_path="C:/Users/a0221343/Git/bootROM/bootrom_f28004x/F28004x_ROM_dev_PG2.0/F28004x_ROM/driverlib" --include_path="C:/Users/a0221343/Git/bootROM/bootrom_f28004x/F28004x_ROM_dev_PG2.0/F28004x_ROM/inc" --include_path="C:/Users/a0221343/Git/bootROM/bootrom_f28004x/F28004x_ROM_dev_PG2.0/F28004x_ROM" -g --no_inlining --gcc --diag_warning=225 --display_error_number --asm_listing --preproc_with_compile --preproc_dependency="bootROM/source/tables/phy_primeprefTable.d" --obj_directory="bootROM/source/tables" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

bootROM/source/tables/phy_primetxpreamble.obj: C:/Users/a0221343/Git/bootROM/bootrom_f28004x/F28004x_ROM_dev_PG2.0/F28004x_ROM/bootROM/source/tables/phy_primetxpreamble.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-c2000_6.4.4/bin/cl2000" -v28 -ml --float_support=fpu32 --tmu_support=tmu0 --cla_support=cla0 --vcu_support=vcu0 -Ooff --include_path="C:/ti/ccsv6/tools/compiler/ti-cgt-c2000_6.4.4/include" --include_path="C:/Users/a0221343/Git/bootROM/bootrom_f28004x/F28004x_ROM_dev_PG2.0/F28004x_ROM/bootROM/include" --include_path="C:/Users/a0221343/Git/bootROM/bootrom_f28004x/F28004x_ROM_dev_PG2.0/F28004x_ROM/bootROM/source/tables" --include_path="C:/Users/a0221343/Git/bootROM/bootrom_f28004x/F28004x_ROM_dev_PG2.0/F28004x_ROM/driverlib" --include_path="C:/Users/a0221343/Git/bootROM/bootrom_f28004x/F28004x_ROM_dev_PG2.0/F28004x_ROM/inc" --include_path="C:/Users/a0221343/Git/bootROM/bootrom_f28004x/F28004x_ROM_dev_PG2.0/F28004x_ROM" -g --no_inlining --gcc --diag_warning=225 --display_error_number --asm_listing --preproc_with_compile --preproc_dependency="bootROM/source/tables/phy_primetxpreamble.d" --obj_directory="bootROM/source/tables" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

bootROM/source/tables/phy_primrxpreamble.obj: C:/Users/a0221343/Git/bootROM/bootrom_f28004x/F28004x_ROM_dev_PG2.0/F28004x_ROM/bootROM/source/tables/phy_primrxpreamble.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-c2000_6.4.4/bin/cl2000" -v28 -ml --float_support=fpu32 --tmu_support=tmu0 --cla_support=cla0 --vcu_support=vcu0 -Ooff --include_path="C:/ti/ccsv6/tools/compiler/ti-cgt-c2000_6.4.4/include" --include_path="C:/Users/a0221343/Git/bootROM/bootrom_f28004x/F28004x_ROM_dev_PG2.0/F28004x_ROM/bootROM/include" --include_path="C:/Users/a0221343/Git/bootROM/bootrom_f28004x/F28004x_ROM_dev_PG2.0/F28004x_ROM/bootROM/source/tables" --include_path="C:/Users/a0221343/Git/bootROM/bootrom_f28004x/F28004x_ROM_dev_PG2.0/F28004x_ROM/driverlib" --include_path="C:/Users/a0221343/Git/bootROM/bootrom_f28004x/F28004x_ROM_dev_PG2.0/F28004x_ROM/inc" --include_path="C:/Users/a0221343/Git/bootROM/bootrom_f28004x/F28004x_ROM_dev_PG2.0/F28004x_ROM" -g --no_inlining --gcc --diag_warning=225 --display_error_number --asm_listing --preproc_with_compile --preproc_dependency="bootROM/source/tables/phy_primrxpreamble.d" --obj_directory="bootROM/source/tables" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

bootROM/source/tables/phy_tf512pfftTable.obj: C:/Users/a0221343/Git/bootROM/bootrom_f28004x/F28004x_ROM_dev_PG2.0/F28004x_ROM/bootROM/source/tables/phy_tf512pfftTable.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-c2000_6.4.4/bin/cl2000" -v28 -ml --float_support=fpu32 --tmu_support=tmu0 --cla_support=cla0 --vcu_support=vcu0 -Ooff --include_path="C:/ti/ccsv6/tools/compiler/ti-cgt-c2000_6.4.4/include" --include_path="C:/Users/a0221343/Git/bootROM/bootrom_f28004x/F28004x_ROM_dev_PG2.0/F28004x_ROM/bootROM/include" --include_path="C:/Users/a0221343/Git/bootROM/bootrom_f28004x/F28004x_ROM_dev_PG2.0/F28004x_ROM/bootROM/source/tables" --include_path="C:/Users/a0221343/Git/bootROM/bootrom_f28004x/F28004x_ROM_dev_PG2.0/F28004x_ROM/driverlib" --include_path="C:/Users/a0221343/Git/bootROM/bootrom_f28004x/F28004x_ROM_dev_PG2.0/F28004x_ROM/inc" --include_path="C:/Users/a0221343/Git/bootROM/bootrom_f28004x/F28004x_ROM_dev_PG2.0/F28004x_ROM" -g --no_inlining --gcc --diag_warning=225 --display_error_number --asm_listing --preproc_with_compile --preproc_dependency="bootROM/source/tables/phy_tf512pfftTable.d" --obj_directory="bootROM/source/tables" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


