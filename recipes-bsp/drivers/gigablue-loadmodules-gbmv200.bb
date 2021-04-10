SUMMARY = "kernel modules load helper"
MAINTAINER = "gigablue"

require conf/license/license-gplv2.inc

COMPATIBLE_MACHINE = "^(gbtrio4k|gbip4k)$"

SRC_URI = "file://gigablue-loadmodules-${STB_PLATFORM}.sh"

INITSCRIPT_NAME = "gigablue-loadmodules"
INITSCRIPT_PARAMS = "start 01 S ."

inherit update-rc.d

S = "${WORKDIR}"

do_compile() {
}

do_install() {
	install -d ${D}${INIT_D_DIR}/
	install -m 0755 ${WORKDIR}/gigablue-loadmodules-${STB_PLATFORM}.sh ${D}${INIT_D_DIR}/gigablue-loadmodules
}
