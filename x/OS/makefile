PROJ := os

PROJ_PATH := .

SRC := main.c\
		bsp/sam3s/source/exceptions.c\
		bsp/sam3s/source/system_sam3s.c\
		bsp/sam3s/source/startup_sam3s.c\
		bsp/sam3s/wdt/wdt.c\
		bsp/sam3s/board/board_boschbsx.c\
		bsp/sam3s/uart/uart.c\
		bsp/sam3s/usart/usart.c\
		bsp/sam3s/sysclk/sam3s/sysclk.c\
		bsp/sam3s/stdio/write.c\
		bsp/sam3s/stdio/read.c\
		bsp/sam3s/stdio/syscalls.c\
		bsp/sam3s/pmc/pmc.c\
		bsp/sam3s/source/pio.c

#;		bsp/sam3s/source/system_sam3s.c\
#		bsp/system_SAM3S.c\


PROJ_INCLUDES := bsp/cmsis/include\
				bsp/sam3s/include\
				bsp/sam3s/include/sam3s\
				bsp/sam3s/include/component\
				bsp/sam3s/include/instance\
				bsp/sam3s/include/pio\
				bsp/sam3s/ioport\
				bsp/sam3s/uart\
				bsp/sam3s/usart\
				bsp/sam3s/sysclk\
				bsp/sam3s/board\
				bsp/sam3s/include/preprocessor\
				bsp/sam3s/include/interrupt\
				bsp/sam3s/pmc
				

PROJ_MEMORYMAP := bsp/sam3s/memory/flash.ld

# compile c flags for sam3s2a 
PROJ_CFLAGS = -std=gnu99 -D__SAM3S2A__

PROJ_CFLAGS += -Wall -Wstrict-prototypes -Wmissing-prototypes

PROJ_CFLAGS += -Werror-implicit-function-declaration

PROJ_CFLAGS += -mcpu=cortex-m3 -mthumb

PROJ_CFLAGS += -ffunction-sections -fdata-sections

PROJ_CFLAGS += -Os -gdwarf-2 -Wcast-align \
    -Wchar-subscripts -Winline -Wpointer-arith -Wredundant-decls -Wshadow \
    -Wwrite-strings

# Garbage collect unreferred sections when linking.
PROJ_LDFLAGS = -Wl,--gc-sections

PROJ_LDFLAGS += -Wl,--entry=Reset_Handler

PROJ_LDFLAGS += -Wl,--cref -mcpu=cortex-m3 -mthumb -O3

#PROJ_CFLAGS += -Wa,-meabi=5 -ffunction-sections -fno-common

#-mfloat-abi=soft  -mfpu=vfp

include ../infrastructure/build.mk

all: merge_bin

.PHONY : merge_bin
merge_bin:
	cp ../../sam3s_simple/sam3s_test.bin generated-x.bin
	dd if=out/x-os.bin of=generated-x.bin bs=1024 count=40 seek=20