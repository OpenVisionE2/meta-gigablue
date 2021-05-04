require conf/machine/include/gigablue.inc

TARGET_ARCH = "arm"
DEFAULTTUNE = "cortexa15hf-neon-vfpv4"
IMAGE_FSTYPES += "tar.bz2"

ROOTFS_FILE = "rootfs.tar.bz2"
MTD_KERNEL = "mmcblk0p4"
MTD_ROOTFS = "mmcblk0p5"
MTD_BOOTFS = "mmcblk0p1"
MTD_BLACK  = "mmcblk0"

require conf/machine/include/tune-cortexa15.inc

DVBMEDIASINK_CONFIG = "--with-wma --with-wmv --with-amr --with-pcm --with-dts --with-eac3 --with-h265 --with-vb6 --with-vb8 --with-vb9 --with-spark"

PREFERRED_PROVIDER_virtual/blindscan-dvbc = "gigablue-blindscan-utils-arm"
PREFERRED_PROVIDER_virtual/blindscan-dvbs = "gigablue-blindscan-utils-arm"

require conf/machine/include/soc-family.inc

MACHINE_FEATURES += "mmc emmc swap bluetooth mountboot dvb-c transcoding ci blindscan-dvbs blindscan-dvbc colorlcd gigabluelcd kodi19"

MACHINE_ESSENTIAL_EXTRA_RDEPENDS += "\
	${@bb.utils.contains('MACHINE_FEATURES', 'swap', 'gigablue-swapcreate', '',d)} \
	"

KERNELVERSION = "4.1.20"

PREFERRED_VERSION_linux-gigablue = "${KERNELVERSION}"
PREFERRED_PROVIDER_virtual/kernel = "linux-gigablue"
PREFERRED_PROVIDER_virtual/egl ?= "gb-v3ddriver-${STB_PLATFORM}"
PREFERRED_PROVIDER_virtual/libgles2 ?= "gb-v3ddriver-${STB_PLATFORM}"

MACHINE_ESSENTIAL_EXTRA_RDEPENDS += "\
	gb-v3ddriver-${STB_PLATFORM} \
	gigablue-platform-util-${STB_PLATFORM} \
	gigablue-ddbootup \
	gigablue-swapcreate \
	"

EXTRA_IMAGEDEPENDS += "\
	gigablue-initrd-cfe-${MACHINE} \
	"

IMAGE_INSTALL_append = " \
	bluetoothsetup-${STB_PLATFORM} \
	"
