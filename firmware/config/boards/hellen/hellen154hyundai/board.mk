# Combine the related files for a specific platform and MCU.

# Target ECU board design
BOARDCPPSRC = $(BOARDS_DIR)/hellen/hellen154hyundai/board_configuration.cpp
BOARDINC = $(BOARDS_DIR)/hellen/hellen154hyundai

# Set this if you want a default engine type other than normal hellen121nissan
ifeq ($(VAR_DEF_ENGINE_TYPE),)
  VAR_DEF_ENGINE_TYPE = -DDEFAULT_ENGINE_TYPE=HELLEN_154_HYUNDAI_COUPE_BK2
endif

DDEFS += -DEFI_MAIN_RELAY_CONTROL=TRUE

# Disable serial ports on this board as UART3 causes a DMA conflict with the SD card
DDEFS += -DTS_NO_PRIMARY=1

# Add them all together
DDEFS += -DFIRMWARE_ID=\"hellen154hyundai\" $(VAR_DEF_ENGINE_TYPE)
DDEFS += -DEFI_SOFTWARE_KNOCK=TRUE -DSTM32_ADC_USE_ADC3=TRUE

DDEFS += -DSHORT_BOARD_NAME=hellen154hyundai

include $(BOARDS_DIR)/hellen/hellen-common144.mk
