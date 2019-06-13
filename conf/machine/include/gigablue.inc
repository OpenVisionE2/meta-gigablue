KERNEL_MODULE_AUTOLOAD += "xfs"

# We know about rtc
MACHINE_FEATURES_BACKFILL_CONSIDERED = "rtc"

IMAGEVERSION := "${IMAGE_NAME}"
IMAGEVERSION[vardepsexclude] = "DATE"

MACHINE_FEATURES += "3dtv alsa hdmicec switchoff"

BOX_BRAND = "gigablue"