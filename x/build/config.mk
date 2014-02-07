
# Root of build system
ROOT_BUILD ?= 

X_MODULE := $(strip $(X_MODULE))
X_ARCH := $(strip $(X_ARCH))

ifeq ($(X_MODULE), "")
$(error No module name specified)
endif



