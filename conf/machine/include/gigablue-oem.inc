# We know about rtc
MACHINE_FEATURES_BACKFILL_CONSIDERED += "rtc"

BOX_BRAND = "gigablue"

KERNEL_FILE = "kernel.bin"

MACHINE_ESSENTIAL_EXTRA_RDEPENDS += "\
	gigablue-ddbootup \
	enigma2-plugin-systemplugins-vfdcontrol \
	kernel-module-rtl8192cu \
	firmware-rtl8192cu \
	firmware-rtl8192cufw \
	kernel-module-extrawlan-rtl8192eu \
	firmware-rtl8192eu \
	kernel-module-extrawlan-rt8812au \
	kernel-module-extrawlan-rt8822bu \
	"

DVBPROVIDER = "kernel"

MACHINE_ESSENTIAL_EXTRA_RRECOMMENDS += "\
	kernel-module-zram \
	kernel-module-autofs4 \
	"

MACHINE_EXTRA_RRECOMMENDS += "\
	gstreamer1.0-plugin-dvbmediasink \
	${@bb.utils.contains("MACHINE_FEATURES", "hisi", "" , "gigablue-cfe", d)} \
	"

KERNEL_MODULE_AUTOLOAD += "\
	autofs4 \
	xfs \
	"

PREFERRED_PROVIDER_virtual/kernel = "linux-gigablue"

KERNEL_OUTPUT = "${KERNEL_IMAGETYPE}"
KERNEL_CONSOLE = "ttyS0,115200n8"

MACHINE_FEATURES += "3dtv alsa hdmicec switchoff blindscan-tbs gigablue"

BOOTLOGO_FILENAME = "splash.bin"

require conf/machine/include/soc-family.inc
