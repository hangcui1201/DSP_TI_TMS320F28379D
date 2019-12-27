#
_XDCBUILDCOUNT = 
ifneq (,$(findstring path,$(_USEXDCENV_)))
override XDCPATH = C:/ti/bios_6_76_02_02/packages
override XDCROOT = C:/ti/ccs920/xdctools_3_60_01_27_core
override XDCBUILDCFG = ./config.bld
endif
ifneq (,$(findstring args,$(_USEXDCENV_)))
override XDCARGS = 
override XDCTARGETS = 
endif
#
ifeq (0,1)
PKGPATH = C:/ti/bios_6_76_02_02/packages;C:/ti/ccs920/xdctools_3_60_01_27_core/packages;..
HOSTOS = Windows
endif
