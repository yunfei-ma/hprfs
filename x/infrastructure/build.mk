# Disable GNU Make implicit rules

# this turns off the suffix rules built into make
.SUFFIXES:

# this turns off the RCS / SCCS implicit rules of GNU Make
% : RCS/%,v
% : RCS/%
% : %,v
% : s.%
% : SCCS/s.%

# If a rule fails, delete $@.
.DELETE_ON_ERROR:

.PHONY : all

all:

# X cross compile makefile
# Created by Yunfei 2014.01.14
# All rights reserved
TARGET := x

X_INFRASTRUCTURE := $(dir $(lastword $(MAKEFILE_LIST)))
X_INFRASTRUCTURE := $(strip $(X_INFRASTRUCTURE:%build/core/=%))
X_INFRASTRUCTURE := $(subst \,/,$(X_INFRASTRUCTURE))
X_INFRASTRUCTURE := $(X_INFRASTRUCTURE:%/=%)
ifeq ($(X_INFRASTRUCTURE),)
    # for the case when we're invoked from the NDK install path
    X_INFRASTRUCTURE := .
endif

TARGET_OUT := $(dir $(firstword $(MAKEFILE_LIST)))out

X_INC := $(addprefix -I,$(PROJ_INCLUDES))
# ----------------------------------------
# Tool chain definitions
# ----------------------------------------
ROOT_TOOLCHAIN ?= 
TOOLCHAIN ?= $(ROOT_TOOLCHAIN)arm-none-eabi-

CC := $(TOOLCHAIN)gcc
LD := $(TOOLCHAIN)g++
AS := $(TOOLCHAIN)as
NM := $(TOOLCHAIN)nm
AR := $(TOOLCHAIN)ar
READELF := $(TOOLCHAIN)readelf
OBJCOPY := $(TOOLCHAIN)objcopy
OBJDUMP := $(TOOLCHAIN)objdump
SIZE    := $(TOOLCHAIN)size

LINT=cpplint

X_CFLAGS += $(PROJ_CFLAGS)

USE_LINT=false

X_LDFLAGS += $(PROJ_LDFLAGS)

X_LDFLAGS += -Wl,-T $(PROJ_MEMORYMAP)

include $(X_INFRASTRUCTURE)/common.mk

#$(call x_info, target out $(TARGET_OUT))
#$(call x_info, using CC tool : $(CC))

$(call handle-set-module, $(TARGET), $(PROJ))
X_MODULE = $(TARGET)-$(PROJ)
$(call generate-dir,$(TARGET_OUT))
X_MODULE_TARGETS = $(TARGET_OUT)/$(X_MODULE).elf $(TARGET_OUT)/$(X_MODULE).bin $(TARGET_OUT)/$(X_MODULE).sym $(TARGET_OUT)/$(X_MODULE).lss

X_LDFLAGS += -Wl,-Map=$(TARGET_OUT)/$(X_MODULE).map

ifneq (, $(PROJ_LIB))
X_LDFLAGS += -L$(PROJ_LIB)
endif

all: $(X_MODULE_TARGETS)

$(foreach c_file,$(filter %.c,$(SRC)), $(call compile-c-source,$(c_file),$(call get-object-name,$(c_file))))
$(foreach s_file,$(filter %.s,$(SRC)), $(call compile-s-source,$(s_file),$(call get-object-name,$(s_file))))

$(TARGET_OUT)/$(X_MODULE).elf : $(X_OBJS)
	$(hide) $(HOST_ECHO) $(X_MODULE) : generating  $@
	$(hide) $(LD) $(X_LDFLAGS) $(X_CFLAGS) $(X_OBJS) $(X_LIBS) -o $@
	$(hide) $(SIZE) -Ax -d $@ >> $(TARGET_OUT)/$(X_MODULE).map
	$(hide) $(SIZE) -Bx -d $@ >> $(TARGET_OUT)/$(X_MODULE).map

$(TARGET_OUT)/$(X_MODULE).bin : $(TARGET_OUT)/$(X_MODULE).elf
	$(hide) $(HOST_ECHO) $(X_MODULE) : generating  $@
	$(hide) $(OBJCOPY) -O binary $< $@

$(TARGET_OUT)/$(X_MODULE).sym : $(TARGET_OUT)/$(X_MODULE).elf
	$(hide) $(HOST_ECHO) generating : generating  $@
	$(hide) $(NM) -n $< > $@

$(TARGET_OUT)/$(X_MODULE).lss : $(TARGET_OUT)/$(X_MODULE).elf
	$(hide) $(OBJDUMP) -h -S $< > $@
	
print_objs:
	@echo $(X_OBJS)

clean:
	$(host-rm) $(X_MODULE_TARGETS) $(X_OBJS) $(X_DEPS)

