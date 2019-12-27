# invoke SourceDir generated makefile for app.p28FP
app.p28FP: .libraries,app.p28FP
.libraries,app.p28FP: package/cfg/app_p28FP.xdl
	$(MAKE) -f C:\Github_Repo\DSP_TI_TMS320F28379D\F28379D_Projects\demo_rtos_cpu1/src/makefile.libs

clean::
	$(MAKE) -f C:\Github_Repo\DSP_TI_TMS320F28379D\F28379D_Projects\demo_rtos_cpu1/src/makefile.libs clean

