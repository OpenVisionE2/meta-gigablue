require gigablue-partitions-gbmv200.inc

COMPATIBLE_MACHINE = "^(gbip4k)$"

SRCDATE = "20200423"

SRC_URI = "http://source.mynonpublic.com/gigablue/mv200/${MACHINE}-partitions-${SRCDATE}.zip \
  file://flash-apploader \
"

SRC_URI[md5sum] = "ce5f86de7b575cb143b4470bff05bcc2"
SRC_URI[sha256sum] = "f588756d0e7f3673a28d6976ec172f5aaa63d78d655b10f9836a755418abf07d"
