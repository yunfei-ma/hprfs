
TARGET_TOOLCHAIN ?= $(ROOT_TOOLCHAIN)arm-none-eabi-

TARGET_CC := $(TOOLCHAIN)gcc
TARGET_LD := $(TOOLCHAIN)ld
TARGET_OBJCOPY := $(TOOLCHAIN)objcopy
TARGET_OBJDUMP := $(TOOLCHAIN)objdump

TARGET_CFLAGS := -mcpu=cortex-m3

TARGET_LDFLAGS :=

TARGET_C_INCLUDES := \
    $(SYSROOT)/usr/include


TARGET_CFLAGS += -mcpu=cortex-m3 -Wall

TARGET_arm_release_CFLAGS :=  -O2

TARGET_thumb_release_CFLAGS := -mthumb \
                               -Os

# When building for debug, compile everything as arm.
TARGET_arm_debug_CFLAGS := $(TARGET_arm_release_CFLAGS) \
							-g

TARGET_thumb_debug_CFLAGS := $(TARGET_thumb_release_CFLAGS) \
							 -g