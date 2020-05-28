SOC_FAMILY = "bcm7325"

require gigablue-mips.inc

MACHINE_FEATURES += "singlecore blindscan-dvbc ci YUV RCA"

PREFERRED_VERSION_linux-gigablue = "3.9.6"

MACHINE_ESSENTIAL_EXTRA_RDEPENDS += "\
    gigablue-dvb-modules-gb7325 \
"

DVBMEDIASINK_CONFIG = "--with-wmv"

GLIBC_EXTRA_OECONF = "--with-tls"
