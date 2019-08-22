SUMMARY = "halt for Gigablue Model ${MACHINE}"
SECTION = "base"
PRIORITY = "optional"
LICENSE = "CLOSED"

PACKAGE_ARCH = "${MACHINE_ARCH}"

COMPATIBLE_MACHINE = "gbtrio4k|gbip4k"

RDEPENDS_${PN} = "harfbuzz"

SRCDATE = "20190307"

PV = "${SRCDATE}"

INITSCRIPT_NAME = "suspend"
INITSCRIPT_PARAMS = "start 89 0 ."
inherit update-rc.d

SRC_URI  = "http://source.mynonpublic.com/gigablue/mv200/gbmv200-hihalt-${SRCDATE}.tar.gz \
    file://suspend.sh \
"

SRC_URI[md5sum] = "76cced6b5510ecbef7b7a4db33e745d9"
SRC_URI[sha256sum] = "c00ca6d751ead876a46391cc47734e8292679f07adc446da0f0cbcb88dffb26d"

S = "${WORKDIR}"

do_install() {
    install -d ${D}${bindir}
    install -m 0755 ${S}/hihalt ${D}/${bindir}
    install -d ${D}${sysconfdir}/init.d
    install -m 0755 ${S}/suspend.sh ${D}${sysconfdir}/init.d/suspend
}

do_package_qa() {
}

FILES_${PN}  = "${bindir}/hihalt ${sysconfdir}/init.d"
