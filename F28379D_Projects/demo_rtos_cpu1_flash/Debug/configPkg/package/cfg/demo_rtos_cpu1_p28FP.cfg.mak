# invoke SourceDir generated makefile for demo_rtos_cpu1.p28FP
demo_rtos_cpu1.p28FP: .libraries,demo_rtos_cpu1.p28FP
.libraries,demo_rtos_cpu1.p28FP: package/cfg/demo_rtos_cpu1_p28FP.xdl
	$(MAKE) -f C:\Github_Repo\DSP_TI_TMS320F28379D\F28379D_Projects\demo_rtos_cpu1/src/makefile.libs

clean::
	$(MAKE) -f C:\Github_Repo\DSP_TI_TMS320F28379D\F28379D_Projects\demo_rtos_cpu1/src/makefile.libs clean

