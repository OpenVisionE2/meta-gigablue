require conf/machine/include/gigablue-oem.inc

MTD_KERNEL = "mmcblk0p12"
MTD_ROOTFS = "mmcblk0p16"
MTD_BLACK  = "mmcblk0"

ROOTFS_FILE = "rootfs.tar.bz2"

DISTRO_FEATURES_remove += "x11 wayland"

SOC_FAMILY = "hisi3798mv200"
HICHIPSET = "3798mv200"

MACHINE_ESSENTIAL_EXTRA_RDEPENDS += "\
    gigablue-dvb-modules-${MACHINE} \
    gigablue-loadmodules-gbmv200 \ 
    gigablue-libs-gbmv200 \
    gigablue-hihalt-gbmv200 \
    gigablue-reader-${MACHINE} \
    gigablue-partitions-${MACHINE} \
    gigablue-tntfs-${HICHIPSET} \
    gigablue-libreader-gbmv200 \
    gigablue-buildimage \
    e2fsprogs-resize2fs \
    gptfdisk \
    ${@bb.utils.contains('MACHINE_FEATURES', 'emmc', 'partitions-by-name' , '', d)} \
"

MACHINE_FEATURES += "switchoff 7segment hdmicec textlcd emmc mmc blindscan-dvbs alsa hisi multitranscoding AV_JACK"

IMAGE_CLASSES  += "gigablue-emmc_image"
IMAGE_FSTYPES += "gigablueemmc"
IMAGE_ROOTFS_SIZE ?= "524288"

TARGET_ARCH = "arm"
DEFAULTTUNE = "cortexa15hf-neon-vfpv4"

PREFERRED_VERSION_linux-gigablue = "4.4.35"
PREFERRED_PROVIDER_virtual/blindscan-dvbs = "gigablue-blindscan-gbmv200"
PREFERRED_RPROVIDER_showiframe = "gigablue-showiframe-gbmv200"
PREFERRED_RPROVIDER_aio-grab = "gigablue-grab-gbmv200"
PREFERRED_PROVIDER_virtual/enigma2-mediaservice = "enigma2-plugin-systemplugins-servicehisilicon"

require conf/machine/include/tune-cortexa15.inc

DVBSKYPROVIDER = "kernel"

DVBMEDIASINK_CONFIG = "--with-h265 --with-vb8 --with-vb9 --with-spark --with-wma --with-wmv --with-pcm --with-dts --with-eac3"

EXTRA_OECONF_append_pn-enigma2 = "--with-lcddev=/dev/null --with-alphablendingacceleration=always --with-blitaccelerationthreshold=250  --with-fillaccelerationthreshold=190000"

IMAGE_CMD_gigablueemmc_append = "\
    mkdir -p ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}; \
    mkdir -p ${DEPLOY_DIR_IMAGE}/userdata; \
    mkdir -p ${DEPLOY_DIR_IMAGE}/userdata/linuxrootfs1; \
    mkdir -p ${DEPLOY_DIR_IMAGE}/userdata/linuxrootfs2; \
    mkdir -p ${DEPLOY_DIR_IMAGE}/userdata/linuxrootfs3; \
    mkdir -p ${DEPLOY_DIR_IMAGE}/userdata/linuxrootfs4; \
    cp -a ${IMAGE_ROOTFS}/* ${DEPLOY_DIR_IMAGE}/userdata/linuxrootfs1/; \
    mkfs.ext4 -F -i 4096 ${DEPLOY_DIR_IMAGE}/${MACHINE}-partitions/rootfs.ext4 -d ${DEPLOY_DIR_IMAGE}/userdata; \
    cd ${IMAGE_ROOTFS}; \
    tar -cvf ${DEPLOY_DIR_IMAGE}/rootfs.tar -C ${IMAGE_ROOTFS} .; \
    mv ${DEPLOY_DIR_IMAGE}/rootfs.tar ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/rootfs.tar; \
    bzip2 ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/rootfs.tar; \
    cp ${DEPLOY_DIR_IMAGE}/uImage ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/${KERNEL_FILE}; \
    cp ${DEPLOY_DIR_IMAGE}/uImage ${DEPLOY_DIR_IMAGE}/${MACHINE}-partitions/${KERNEL_FILE}; \
    echo ${IMAGE_NAME} > ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/imageversion; \
    cd ${DEPLOY_DIR_IMAGE}/${MACHINE}-partitions; \
    mkupdate -s 00000003-00000001-01010101 -f ${DEPLOY_DIR_IMAGE}/${MACHINE}-partitions/emmc_partitions.xml -d ${DEPLOY_DIR_IMAGE}/usb_update.bin; \
    rm -f ${DEPLOY_DIR_IMAGE}/*.zip; \
    cd ${DEPLOY_DIR_IMAGE}; \
    cp ${IMGDEPLOYDIR}/${IMAGE_NAME}.rootfs.manifest ${IMAGE_NAME}_usb.zip.manifest; \
    zip -j ${IMAGE_NAME}_recovery_emmc.zip ${DEPLOY_DIR_IMAGE}/usb_update.bin ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/imageversion ${DEPLOY_DIR_IMAGE}/${MACHINE}-partitions/bootargs.bin ${DEPLOY_DIR_IMAGE}/${MACHINE}-partitions/fastboot.bin ${DEPLOY_DIR_IMAGE}/${MACHINE}-partitions/apploader.bin; \
    zip ${IMAGE_NAME}_usb.zip ${IMAGEDIR}/*; \
    rm -f ${DEPLOY_DIR_IMAGE}/*.ext4; \
    rm -Rf ${DEPLOY_DIR_IMAGE}/usb_update.bin; \
    rm -Rf ${IMAGEDIR}; \
    rm -Rf ${DEPLOY_DIR_IMAGE}/userdata; \
    "

STB_PLATFORM = "gbmv200"
