DESCRIPTION = "V3D driver for ${MACHINE}"
SECTION = "base"
PRIORITY = "required"
LICENSE = "CLOSED"

PACKAGE_ARCH = "${MACHINE_ARCH}"

PROVIDES = "virtual/libgles2 virtual/egl"

DEPENDS = "gb-v3ddriver-headers"

PV = "${SRCDATE}"

SRC_URI = "http://source.mynonpublic.com/gigablue/v3ddriver/${STB_PLATFORM}-v3ddriver-${SRCDATE}.zip"

S = "${WORKDIR}"

do_configure() {
}

do_compile() {
}

do_install_append() {
	install -d ${D}${libdir}
	install -m 0755 ${S}/v3ddriver/libnxpl.so ${D}${libdir}/
	install -m 0755 ${S}/v3ddriver/libv3ddriver.so ${D}${libdir}/
	install -m 0755 ${S}/v3ddriver/libnexus.so ${D}${libdir}/
	install -m 0755 ${S}/v3ddriver/libnxclient.so ${D}${libdir}/
	ln -s libv3ddriver.so ${D}${libdir}/libEGL.so
	ln -s libv3ddriver.so ${D}${libdir}/libGLESv2.so
}

FILES_${PN} = "${libdir}/*"
FILES_${PN}-dev = "${incdir}/*"

RPROVIDES_${PN} = "virtual/libgles2 virtual/egl libnexus.so libnxclient.so libnxpl.so libv3ddriver.so libGLESv2.so libEGL.so"
