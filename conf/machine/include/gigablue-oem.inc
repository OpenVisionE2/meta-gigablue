# We know about rtc
include conf/machine/include/build-extras.inc

MTD_KERNEL = "mtd2"
MTD_ROOTFS = "mtd0"

KERNEL_FILE = "kernel.bin"
ROOTFS_FILE = "rootfs.bin"

MACHINE_ESSENTIAL_EXTRA_RDEPENDS += "\
    gigablue-ddbootup \
    enigma2-plugin-systemplugins-vfdcontrol \
    "

DVBPROVIDER = "kernel"

MACHINE_ESSENTIAL_EXTRA_RRECOMMENDS += "\
    kernel-module-cdfs \
    kernel-module-zram \
    kernel-module-ext2 \
    kernel-module-ext3 \
    kernel-module-ext4 \
    kernel-module-cifs \
    kernel-module-autofs4 \
    "

MACHINE_EXTRA_RRECOMMENDS += "\
    gstreamer1.0-plugin-dvbmediasink \
    gstreamer1.0-libav \
    gigablue-cfe \
    "

include conf/machine/include/autoload-filesystems.inc

PREFERRED_PROVIDER_virtual/transtreamproxy = "gb-transtreamproxy"
PREFERRED_PROVIDER_virtual/kernel = "linux-gigablue"

KERNEL_OUTPUT = "${KERNEL_IMAGETYPE}"
KERNEL_CONSOLE = "ttyS0,115200n8"

MACHINE_FEATURES += "3dtv alsa hdmicec switchoff blindscan-tbs omb HDMI"
#MACHINE_FEATURES += "bootsplash"

BOOTLOGO_FILENAME = "splash.bin"

require conf/machine/include/soc-family.inc
