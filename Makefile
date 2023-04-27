# Project Name
TARGET = oscvasynth

# Sources
CPP_SOURCES = main.cpp vasynth.cpp

# Library Locations
LIBDAISY_DIR = ./libDaisy
DAISYSP_DIR = ./DaisySP

# Core location, and generic makefile.
SYSTEM_FILES_DIR = $(LIBDAISY_DIR)/core
include $(SYSTEM_FILES_DIR)/Makefile

.PHONY: libdaisy daisysp

all: ./build/$(TARGET).bin libdaisy daisysp

libdaisy:
	make -C $(LIBDAISY_DIR)

daisysp:
	make -C $(DAISYSP_DIR)

deep-clean: clean
	make -C $(LIBDAISY_DIR) clean
	make -C $(DAISYSP_DIR) clean
	
#clean:
#	rm -rf build

