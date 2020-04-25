require gigablue-partitions-gbmv200.inc

COMPATIBLE_MACHINE = "^(gbtrio4k)$"

SRCDATE = "20200423"

SRC_URI = "http://source.mynonpublic.com/gigablue/mv200/gbmv200-partitions-${SRCDATE}.zip \
  file://flash-apploader \
"

SRC_URI[md5sum] = "e8347114efb7ec47b51e489974a53c17"
SRC_URI[sha256sum] = "02375a1414c80ffdbefb5340d39833e4ee1cc93c73711c8dfad226c19b2df8c7"
