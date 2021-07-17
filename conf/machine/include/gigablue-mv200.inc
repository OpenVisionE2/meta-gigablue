require conf/machine/include/gigablue-oem.inc

KERNELVERSION = "4.4.35"

MTD_KERNEL = "mmcblk0p12"
MTD_ROOTFS = "mmcblk0p16"
MTD_BLACK  = "mmcblk0"

ROOTFS_FILE = "rootfs.tar.bz2"

DISTRO_FEATURES_remove += "x11 wayland"

SOC_FAMILY = "hisi3798mv200"
HICHIPSET = "3798mv200"
CHIPSET = "Hi3798Mv200"

MACHINE_ESSENTIAL_EXTRA_RDEPENDS += "\
	gigablue-dvb-modules-${MACHINE} \
	gigablue-loadmodules-${STB_PLATFORM} \
	gigablue-opengl-${STB_PLATFORM} \
	gigablue-libs-${STB_PLATFORM} \
	gigablue-hihalt-${STB_PLATFORM} \
	gigablue-reader-${MACHINE} \
	gigablue-partitions-${MACHINE} \
	gigablue-libreader-${STB_PLATFORM} \
	gigablue-buildimage \
	e2fsprogs-resize2fs \
	gptfdisk \
	${@bb.utils.contains('MACHINE_FEATURES', 'emmc', 'partitions-by-name' , '', d)} \
	"

MACHINE_FEATURES += "switchoff 7segment hdmicec textlcd emmc mmc blindscan-dvbs alsa hisil multitranscoding vfdsymbol kodi19"

IMAGE_CLASSES  += "gigablue-emmc_image"
IMAGE_FSTYPES += "gigablueemmc"
IMAGE_ROOTFS_SIZE ?= "524288"

TARGET_ARCH = "arm"
DEFAULTTUNE = "cortexa15hf-neon-vfpv4"

PREFERRED_VERSION_linux-gigablue = "${KERNELVERSION}"
PREFERRED_PROVIDER_virtual/egl ?= "gigablue-opengl-${STB_PLATFORM}" 
PREFERRED_PROVIDER_virtual/libgles1 ?= "gigablue-opengl-${STB_PLATFORM}"
PREFERRED_PROVIDER_virtual/libgles2 ?= "gigablue-opengl-${STB_PLATFORM}"
PREFERRED_PROVIDER_virtual/blindscan-dvbs = "gigablue-blindscan-${STB_PLATFORM}"
PREFERRED_RPROVIDER_showiframe = "gigablue-showiframe-${STB_PLATFORM}"
PREFERRED_RPROVIDER_aio-grab = "gigablue-grab-${STB_PLATFORM}"
PREFERRED_PROVIDER_virtual/enigma2-mediaservice = "enigma2-plugin-systemplugins-servicehisilicon"

require conf/machine/include/tune-cortexa15.inc


DVBMEDIASINK_CONFIG = "--with-h265 --with-vb8 --with-vb9 --with-spark --with-wma --with-wmv --with-pcm --with-dts --with-eac3"

EXTRA_OECONF_append_pn-enigma2 = "--with-lcddev=/dev/null --with-alphablendingacceleration=always --with-blitaccelerationthreshold=250  --with-fillaccelerationthreshold=190000"

IMAGE_CMD_gigablueemmc_append = " \
	mkdir -p ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}; \
	mv -f ${IMGDEPLOYDIR}/${IMAGE_NAME}${IMAGE_NAME_SUFFIX}.ext4 ${DEPLOY_DIR_IMAGE}/${MACHINE}-partitions/rootfs.ext4; \
	cd ${IMAGE_ROOTFS}; \
	tar -cvf ${DEPLOY_DIR_IMAGE}/rootfs.tar -C ${IMAGE_ROOTFS} .; \
	mv -f ${DEPLOY_DIR_IMAGE}/rootfs.tar ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/rootfs.tar; \
	bzip2 ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/rootfs.tar; \
	cp -f ${DEPLOY_DIR_IMAGE}/uImage ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/${KERNEL_FILE}; \
	cp -f ${DEPLOY_DIR_IMAGE}/uImage ${DEPLOY_DIR_IMAGE}/${MACHINE}-partitions/${KERNEL_FILE}; \
	echo ${IMAGE_NAME} > ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/imageversion; \
	echo "https://forum.openvision.tech/app.php/donate" > ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/donate.txt; \
	cd ${DEPLOY_DIR_IMAGE}/${MACHINE}-partitions; \
	mkupdate -s 00000003-00000001-01010101 -f ${DEPLOY_DIR_IMAGE}/${MACHINE}-partitions/emmc_partitions.xml -d ${DEPLOY_DIR_IMAGE}/usb_update.bin; \
	rm -f ${DEPLOY_DIR_IMAGE}/*.zip; \
	cd ${DEPLOY_DIR_IMAGE}; \
	cp -f ${IMGDEPLOYDIR}/${IMAGE_NAME}${IMAGE_NAME_SUFFIX}.manifest ${IMAGE_NAME}_usb.zip.manifest; \
	zip -j ${IMAGE_NAME}_recovery_emmc.zip ${DEPLOY_DIR_IMAGE}/usb_update.bin ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/imageversion ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/donate.txt ${DEPLOY_DIR_IMAGE}/${MACHINE}-partitions/bootargs.bin ${DEPLOY_DIR_IMAGE}/${MACHINE}-partitions/fastboot.bin ${DEPLOY_DIR_IMAGE}/${MACHINE}-partitions/apploader.bin; \
	zip ${IMAGE_NAME}_usb.zip ${IMAGEDIR}/*; \
	rm -f ${DEPLOY_DIR_IMAGE}/*.ext4; \
	rm -f ${DEPLOY_DIR_IMAGE}/usb_update.bin; \
	rm -Rf ${IMAGEDIR}; \
	rm -Rf gigablue; \
	rm -Rf userdata; \
	rm -Rf ${MACHINE}-partitions; \
	"

IMAGE_CMD_prepend = "\
	rm -Rf ${IMAGE_ROOTFS}/tmp/*; \
	rm -Rf ${DEPLOY_DIR_IMAGE}/userdata; \
	"

STB_PLATFORM = "gbmv200"

EXTRA_ALSA = "mv200"

RCNAME = "gb3"
