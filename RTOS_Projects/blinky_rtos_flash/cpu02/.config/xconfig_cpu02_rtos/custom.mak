## THIS IS A GENERATED FILE -- DO NOT EDIT
.configuro: .libraries,28FP linker.cmd package/cfg/cpu02_rtos_p28FP.o28FP

# To simplify configuro usage in makefiles:
#     o create a generic linker command file name 
#     o set modification times of compiler.opt* files to be greater than
#       or equal to the generated config header
#
linker.cmd: package/cfg/cpu02_rtos_p28FP.xdl
	$(SED) 's"^\"\(package/cfg/cpu02_rtos_p28FPcfg.cmd\)\"$""\"C:/Github_Repo/TMS320F28379D/blinky_rtos_flash/cpu02/.config/xconfig_cpu02_rtos/\1\""' package/cfg/cpu02_rtos_p28FP.xdl > $@
	-$(SETDATE) -r:max package/cfg/cpu02_rtos_p28FP.h compiler.opt compiler.opt.defs
