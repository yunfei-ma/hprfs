PROJ := os

PROJ_PATH := .

SRC := main.c

PROJ_INCLUDES := atmel/chip/include\
				atmel/drivers/include
				

PROJ_MEMORYMAP := flash.ld

# compile c flags for sam3s2a 
PROJ_CFLAGS = -std=gnu99 -Dsam3s2

PROJ_CFLAGS += -Wall -Wstrict-prototypes -Wmissing-prototypes

PROJ_CFLAGS += -Werror-implicit-function-declaration

PROJ_CFLAGS += -mcpu=cortex-m3 -mthumb

PROJ_CFLAGS += -mfpu=vfp -mfloat-abi=soft -Wa,-meabi=5 -ffunction-sections -fno-common

PROJ_LIB   := libchip_sam3s2_mdk_dbg.lib

include ../infrastructure/build.mk