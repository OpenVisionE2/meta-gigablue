SUMMARY = "libreader for Gigablue Model ${MACHINE}"
SECTION = "base"
PRIORITY = "optional"
LICENSE = "CLOSED"
PACKAGE_ARCH = "${MACHINE_ARCH}"

RDEPENDS_${PN} = "libsdl"

COMPATIBLE_MACHINE = "gbtrio4k"

SRCDATE = "20190415"

PV = "${SRCDATE}"

SRC_URI = "http://source.mynonpublic.com/gigablue/mv200/gbmv200-libreader-${SRCDATE}.tar.gz"

SRC_URI[md5sum] = "af943bd4add908538c0ed38795f685a2"
SRC_URI[sha256sum] = "3f9e6207633d16240e5b65010a2ae89b0cce817022e41bac8ba7a2a2fdadb671"

S = "${WORKDIR}"

do_install() {
    install -d ${D}${bindir}
    install -m 0755 ${S}/libreader ${D}/${bindir}
}

do_package_qa() {
}

FILES_${PN}  = "${bindir}/libreader"
