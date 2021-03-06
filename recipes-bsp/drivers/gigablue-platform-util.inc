SUMMARY = "Platform Util drivers for ${MACHINE}"
SECTION = "base"
PRIORITY = "required"
LICENSE = "CLOSED"

PACKAGE_ARCH = "${MACHINE_ARCH}"

PV = "${KV}+${SRCDATE}"

INHIBIT_PACKAGE_STRIP = "1"
INHIBIT_PACKAGE_DEBUG_SPLIT = "1"

SRC_URI = " \
	http://source.mynonpublic.com/gigablue/drivers/platform-util-${STB_PLATFORM}-${KV}-${SRCDATE}.zip \
	file://${INITSCRIPT_NAME}.sysvinit \
	"

S="${WORKDIR}/platform"

do_install() {
	install -d ${D}/home/root/platform
	install -m 0755 ${S}/* ${D}/home/root/platform
	install -d ${D}${INIT_D_DIR}
	install -m 0755 ${WORKDIR}/${INITSCRIPT_NAME}.sysvinit ${D}${INIT_D_DIR}/${INITSCRIPT_NAME}
}

do_package_qa() {
}

do_populate_sysroot() {
}

FILES_${PN} = "/"

inherit update-rc.d

INITSCRIPT_PARAMS = "start 65 S . stop 90 0 ."
INITSCRIPT_NAME = "gigablue-platform-util"
