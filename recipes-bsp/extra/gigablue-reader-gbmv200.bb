SUMMARY = "libreader for Gigablue Model ${MACHINE}"
SECTION = "base"
PRIORITY = "optional"
LICENSE = "CLOSED"
PACKAGE_ARCH = "${MACHINE_ARCH}"

RDEPENDS_${PN} = "libsdl"

COMPATIBLE_MACHINE = "gbtrio4k"

SRCDATE = "20190508"

PV = "${SRCDATE}"

SRC_URI = "http://source.mynonpublic.com/gigablue/mv200/gbmv200-libreader-${SRCDATE}.tar.gz"

SRC_URI[md5sum] = "acd828a91bd1dc905f7db1de66208865"
SRC_URI[sha256sum] = "dd3972ce17be7f476a59a7af6fb53fc2ba26037a217d54c262de785041d1b2f9"

S = "${WORKDIR}"

do_install() {
    install -d ${D}${bindir}
    install -m 0755 ${S}/libreader ${D}/${bindir}
}

do_package_qa() {
}

FILES_${PN}  = "${bindir}/libreader"
