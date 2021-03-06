KERNELVERSION = "4.8.3"

SOC_FAMILY = "bcm7362"

require gigablue-mips.inc

MACHINE_FEATURES += "wol osdanimation blindscan-dvbs"

# Broken bootloader can only flash around 100 MB
FLASHSIZE = "96"


PREFERRED_VERSION_linux-gigablue = "${KERNELVERSION}"

IMAGE_FSTYPES ?= "ubi"
MKUBIFS_ARGS = "-m 2048 -e 126976 -c 4096"
UBINIZE_ARGS = "-m 2048 -p 128KiB"

MACHINE_ESSENTIAL_EXTRA_RDEPENDS += "\
	gigablue-dvb-modules-${STB_PLATFORM} \
	"

DVBMEDIASINK_CONFIG = "--with-wmv --with-wma --with-pcm --with-dts --with-eac3 --with-amr"

GLIBC_EXTRA_OECONF = "--with-tls --with-__thread"

STB_PLATFORM = "gb7362"
