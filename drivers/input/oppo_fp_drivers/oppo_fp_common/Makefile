ifeq ($(CONFIG_OPPO_FINGERPRINT_MTK),y)
PROJECT_NAME = full_oppo6771
endif

DEFS = -DCONFIG_OPPO_FINGERPRINT_PROJCT=$(PROJECT_NAME)
ccflags-y += $(DEFS)

ifeq ($(TARGET_PRODUCT),CPH1861)
DEFS_PLATFORM = -DCONFIG_OPPO_FINGERPRINT_PLATFORM=8976
else ifeq ($(shell echo $(TARGET_PRODUCT) | sed -e 's/_1.*//g'),full_oppo6763)
DEFS_PLATFORM = -DCONFIG_OPPO_FINGERPRINT_PLATFORM=6771
ccflags-y += -I$(srctree)/drivers/misc/mediatek/masp/asfv2/asf_inc
ccflags-y += -I$(srctree)/drivers/misc/mediatek/masp/asfv2/asf_export_inc
ccflags-y += -I$(srctree)/drivers/misc/mediatek/masp/asfv2/module
else
DEFS_PLATFORM = -DCONFIG_OPPO_FINGERPRINT_PLATFORM=0
endif

ccflags-y += $(DEFS_PLATFORM)

obj-y     +=  oppo_fp_common.o

