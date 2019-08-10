SUMMARY = "libreader for Gigablue Model ${MACHINE}"
SECTION = "base"
PRIORITY = "optional"
LICENSE = "CLOSED"
PACKAGE_ARCH = "${MACHINE_ARCH}"

RDEPENDS_${PN} = "libsdl"

COMPATIBLE_MACHINE = "gbtrio4k"

SRCDATE = "20190808"

PV = "${SRCDATE}"

SRC_URI = "http://source.mynonpublic.com/gigablue/mv200/gbmv200-libreader-${SRCDATE}.tar.gz"

SRC_URI[md5sum] = "76cc12221e913ed1be18bef13309b866"
SRC_URI[sha256sum] = "1b192779852cb089d0d26ca1e7c7cf3e88b39b1a4521a59a0bace8e5047130e1"

S = "${WORKDIR}"

do_install() {
    install -d ${D}${bindir}
    install -m 0755 ${S}/libreader ${D}/${bindir}
}

do_package_qa() {
}

FILES_${PN}  = "${bindir}/libreader"
