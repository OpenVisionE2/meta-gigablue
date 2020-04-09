require conf/machine/include/gigablue-oem.inc

MTD_KERNEL = "mmcblk0p12"
MTD_ROOTFS = "mmcblk0p13"
MTD_BLACK  = "mmcblk0"

ROOTFS_FILE = "rootfs.tar.bz2"

DISTRO_FEATURES_remove = "x11 wayland"

MACHINE_ESSENTIAL_EXTRA_RDEPENDS += "\
    gigablue-dvb-modules-${MACHINE} \
    gigablue-loadmodules-gbmv200 \ 
    gigablue-libs-gbmv200 \
    gigablue-hihalt-gbmv200 \
    gigablue-reader-${MACHINE} \
    gigablue-partitions-${MACHINE} \
    gigablue-libreader-gbmv200 \
    gigablue-buildimage \
    e2fsprogs-resize2fs \
    gptfdisk \
    ${@bb.utils.contains('MACHINE_FEATURES', 'emmc', 'partitions-by-name' , '', d)} \
"

MACHINE_FEATURES += "switchoff 7segment hdmicec textlcd emmc mmc blindscan-dvbs alsa hisi"

IMAGE_CLASSES  += "gigablue-emmc_image"
IMAGE_FSTYPES += "gigablueemmc"
IMAGE_ROOTFS_SIZE ?= "524288"

TARGET_ARCH = "arm"
DEFAULTTUNE = "cortexa15hf-neon-vfpv4"

PREFERRED_VERSION_linux-gigablue = "4.4.35"
PREFERRED_PROVIDER_virtual/blindscan-dvbs = "gigablue-blindscan-gbmv200"
PREFERRED_RPROVIDER_showiframe = "gigablue-showiframe-gbmv200"
PREFERRED_RPROVIDER_aio-grab = "gigablue-grab-gbmv200"
PREFERRED_PROVIDER_virtual/enigma2-mediaservice ?= "enigma2-plugin-systemplugins-servicehisilicon"
PREFERRED_VERSION_ffmpeg = "3.4.2"

require conf/machine/include/tune-cortexa15.inc

DVBSKYPROVIDER = "kernel"

DVBMEDIASINK_CONFIG = "--with-h265 --with-vb8 --with-vb9 --with-spark --with-wma --with-wmv --with-pcm --with-dts --with-eac3"
