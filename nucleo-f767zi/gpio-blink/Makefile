PROJECT = gpio-blink
BUILD_DIR = bin

CFILES = gpio-blink.c

# Nucleo-F767ZI settings
DEVICE=stm32f767zit6
OOCD_FILE = board/st_nucleo_f7.cfg

# libopencm3 directory path
OPENCM3_DIR=/opt/libopencm3

include $(OPENCM3_DIR)/mk/genlink-config.mk
include ../rules.mk
include $(OPENCM3_DIR)/mk/genlink-rules.mk

# Custom st-link flash target
flash: $(PROJECT).bin
	@echo "Flashing $(PROJECT).bin to the board using ST-Link..."
	st-flash write $(PROJECT).bin 0x8000000
	@echo "Resetting the MCU..."
	st-flash reset
