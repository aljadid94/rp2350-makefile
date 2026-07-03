# Pico 2 (RP2350) Blink Example - Custom Makefile
# Usage: make all (or just make)
# 
# dicustom dari 
# deepseek & reverse engineering dari blink_sdk
#

# Toolchain settings
ARMGNU  = ../toolchain/gcc-arm-none-eabi-10.3-2021.10/bin/arm-none-eabi
PICOTOOL = ../toolchain/pqt-picotool/4.1.0-1aec55e/picotool

# Compiler settings - Note: Cortex-M33 for RP2350
CC  = $(ARMGNU)-gcc 
CXX = $(ARMGNU)-g++
AS  = $(ARMGNU)-as
AR  = $(ARMGNU)-ar
OBJCOPY = $(ARMGNU)-objcopy
OBJDUMP = $(ARMGNU)-objdump
SIZE = $(ARMGNU)-size

# Target configuration - Pico 2 specific
PICO_BOARD ?= pico2
PICO_PLATFORM ?= rp2350
PICO_TARGET = main_adc
PICO_BAUD_RATE ?= 115200

# RP2350 specific options
PICO_RP2350 = 1
PICO_RP2350_AARCH32 = 1  # Using ARM mode (Cortex-M33)

# SDK version detection
# SDK_VERSION = $(shell grep -oP 'PICO_SDK_VERSION_STRING "\K[^"]+' $(PICO_SDK_PATH)/include/pico/version.h 2>/dev/null || echo "unknown")
#FPU = softfp
#FPU = soft
FPU = hard

# Compiler flags - Cortex-M33 for RP2350 (ARM mode) -march=armv8-m.main+dsp
#CFLAGS = -mcpu=cortex-m33 -mthumb -march=armv8-m.main+fp+dsp -mfloat-abi=softfp -mcmse
CFLAGS = -mcpu=cortex-m33 -mthumb -march=armv8-m.main+fp+dsp -mfloat-abi=$(FPU) -mcmse
CFLAGS += -O2 -g3 -Wall -Wextra -Wno-unused-parameter
CFLAGS += -ffunction-sections -fdata-sections
CFLAGS += -std=gnu11

# RP2350 specific preprocessor definitions, ini tidak dipakai
CFLAGS2 += -D$(PICO_PLATFORM)
CFLAGS2 += -DPICO_BOARD=$(PICO_BOARD)
CFLAGS2 += -DPICO_RP2350=$(PICO_RP2350)
CFLAGS2 += -DPICO_RP2350_AARCH32=$(PICO_RP2350_AARCH32)
CFLAGS2 += -DPICO_BAUD_RATE=$(PICO_BAUD_RATE)
#CFLAGS += -DPICO_STDIO_UART=0
CFLAGS2 += -DPICO_STDIO_ENABLE_CRLF_SUPPORT=1
#CFLAGS += -DPICO_STDIO_USB=1
CFLAGS2 += -DPICO_RP2350_USE_CMSIS=1

# ini diambil dari file flags.make, dari blink_sdk
C_DEFINES = -DCFG_TUSB_DEBUG=0 -DCFG_TUSB_MCU=OPT_MCU_RP2040 \
-DCFG_TUSB_OS=OPT_OS_PICO -DLIB_BOOT_STAGE2_HEADERS=1 -DLIB_PICO_ATOMIC=1 \
-DLIB_PICO_BIT_OPS=1 -DLIB_PICO_BIT_OPS_PICO=1 -DLIB_PICO_CLIB_INTERFACE=1 \
-DLIB_PICO_CRT0=1 -DLIB_PICO_CXX_OPTIONS=1 -DLIB_PICO_DIVIDER=1 \
-DLIB_PICO_DIVIDER_COMPILER=1 -DLIB_PICO_DOUBLE=1 -DLIB_PICO_DOUBLE_PICO=1 \
-DLIB_PICO_FIX_RP2040_USB_DEVICE_ENUMERATION=1 -DLIB_PICO_FLASH=1 \
-DLIB_PICO_FLOAT=1 -DLIB_PICO_FLOAT_PICO=1 -DLIB_PICO_FLOAT_PICO_VFP=1 \
-DLIB_PICO_INT64_OPS=1 -DLIB_PICO_INT64_OPS_COMPILER=1 -DLIB_PICO_MALLOC=1 \
-DLIB_PICO_MEM_OPS=1 -DLIB_PICO_MEM_OPS_COMPILER=1 -DLIB_PICO_NEWLIB_INTERFACE=1 \
-DLIB_PICO_PLATFORM=1 -DLIB_PICO_PLATFORM_COMMON=1 -DLIB_PICO_PLATFORM_COMPILER=1 \
-DLIB_PICO_PLATFORM_PANIC=1 -DLIB_PICO_PLATFORM_SECTIONS=1 -DLIB_PICO_PRINTF=1 \
-DLIB_PICO_PRINTF_PICO=1 -DLIB_PICO_RUNTIME=1 -DLIB_PICO_RUNTIME_INIT=1 \
-DLIB_PICO_STANDARD_BINARY_INFO=1 -DLIB_PICO_STANDARD_LINK=1 -DLIB_PICO_STDIO=1 \
-DLIB_PICO_STDIO_UART=1 -DLIB_PICO_STDIO_USB=1 -DLIB_PICO_STDLIB=1 \
-DLIB_PICO_SYNC=1 -DLIB_PICO_SYNC_CRITICAL_SECTION=1 -DLIB_PICO_SYNC_MUTEX=1 \
-DLIB_PICO_SYNC_SEM=1 -DLIB_PICO_TIME=1 -DLIB_PICO_TIME_ADAPTER=1 \
-DLIB_PICO_UNIQUE_ID=1 -DLIB_PICO_UTIL=1 -DPICO_32BIT=1 -DPICO_BOARD=\"pico2\" \
-DPICO_BUILD=1 -DPICO_CMAKE_BUILD_TYPE=\"Release\" -DPICO_COPY_TO_RAM=0 \
-DPICO_CXX_ENABLE_EXCEPTIONS=0 -DPICO_NO_FLASH=0 -DPICO_NO_HARDWARE=0 \
-DPICO_ON_DEVICE=1 -DPICO_RP2040_USB_DEVICE_UFRAME_FIX=1 \
-DPICO_RP2350=1 -DPICO_TARGET_NAME=\"blink_simple\" -DPICO_USE_BLOCKED_RAM=0

CFLAGS += $(C_DEFINES)

# ini USB 
CFLAGS += -DLIB_PICO_STDIO_USB=1

# ini dibutuhkan oleh dcd_musb.c	
# CFLAGS += -DTUP_DCD_ENDPOINT_MAX=16	


CFLAGS += -DPICO_USB_DEVICE_ENUMERATION_FIX=1  # Fix untuk deteksi
CFLAGS += -DPICO_USB_DEVICE_CDC_ENUMERATION_FIX=1
CFLAGS += -DPICO_USB_DEVICE_FORCE_ENUMERATION=1

# Tambahan untuk USB
CFLAGS += -DPICO_NO_HARDWARE=0
CFLAGS += -DPICO_NO_FLASH=0

# Linker flags for Cortex-M33
#LDFLAGS = -mcpu=cortex-m33 -mthumb -march=armv8-m.main+fp+dsp -mfloat-abi=softfp -mcmse
LDFLAGS = -mcpu=cortex-m33 -mthumb -march=armv8-m.main+fp+dsp -mfloat-abi=$(FPU) -mcmse
LDFLAGS += -Wl,--gc-sections -Wl,--wrap,malloc -Wl,--wrap,free
LDFLAGS += -Wl,--wrap,realloc -Wl,--wrap,calloc

# pakai nano.specs jika mau kecil, tetapi printf tidak bisa muncul floating point
#LDFLAGS += -specs=nano.specs 			
LDFLAGS += -Wl,-Map=$(PICO_TARGET).map 

#SDK_DIR = ../toolchain/pico-sdk
SDK_DIR = ../pico-sdk

CFLAGS += -I.
CFLAGS += -I$(SDK_DIR)/src/common/pico_stdlib/include 
CFLAGS += -I$(SDK_DIR)/src/common/pico_stdlib_headers/include
CFLAGS += -I$(SDK_DIR)/src/common/pico_time/include
CFLAGS += -I$(SDK_DIR)/src/common/pico_base/include
#CFLAGS += -I$(SDK_DIR)/src/boards/include						#// biar ketemu pico2.h
#CFLAGS += -k/src/boards/include/boards			// pico.h
CFLAGS += -I$(SDK_DIR)/src/common/pico_base_headers/include		# pico.h
CFLAGS += -I$(SDK_DIR)/src/rp2350/hardware_structs/include
CFLAGS += -I$(SDK_DIR)/src/rp2350/hardware_regs/include
CFLAGS += -I$(SDK_DIR)/src/rp2350/pico_platform/include
CFLAGS += -I$(SDK_DIR)/src/rp2_common/pico_platform_compiler/include
CFLAGS += -I$(SDK_DIR)/src/rp2_common/pico_platform_sections/include
CFLAGS += -I$(SDK_DIR)/src/rp2_common/pico_platform_panic/include
CFLAGS += -I$(SDK_DIR)/src/rp2_common/pico_platform_common/include
CFLAGS += -I$(SDK_DIR)/src/rp2_common/pico_runtime_init/include
CFLAGS += -I$(SDK_DIR)/src/rp2_common/pico_runtime/include
CFLAGS += -I$(SDK_DIR)/src/common/hardware_claim/include
CFLAGS += -I$(SDK_DIR)/src/rp2_common/hardware_sync_spin_lock/include
CFLAGS += -I$(SDK_DIR)/src/rp2_common/boot_bootrom_headers/include
CFLAGS += -I$(SDK_DIR)/src/rp2_common/hardware_boot_lock/include
CFLAGS += -I$(SDK_DIR)/src/rp2_common/pico_flash/include
CFLAGS += -I$(SDK_DIR)/src/common/boot_picoboot_headers/include
CFLAGS += -I$(SDK_DIR)/src/common/boot_picobin_headers/include
CFLAGS += -I$(SDK_DIR)/src/rp2_common/hardware_rcp/include/
CFLAGS += -I$(SDK_DIR)/src/rp2040/hardware_regs/include
CFLAGS += -I$(SDK_DIR)/src/rp2_common/hardware_rtc/include
CFLAGS += -I$(SDK_DIR)/src/rp2_common/hardware_clocks/include
CFLAGS += -I$(SDK_DIR)/src/rp2_common/pico_time_adapter/include
CFLAGS += -I$(SDK_DIR)/src/rp2_common/hardware_xip_cache/include
CFLAGS += -I$(SDK_DIR)/src/rp2_common/hardware_ticks/include
CFLAGS += -I$(SDK_DIR)/src/rp2_common/pico_bootrom/include
CFLAGS += -I$(SDK_DIR)/src/rp2_common/pico_crt0
CFLAGS += -I$(SDK_DIR)/src/rp2_common/hardware_sync/include
CFLAGS += -I$(SDK_DIR)/src/rp2_common/hardware_pll/include

CFLAGS += -I$(SDK_DIR)/src/rp2_common/pico_stdio/include
CFLAGS += -I$(SDK_DIR)/src/rp2_common/hardware_base/include
CFLAGS += -I$(SDK_DIR)/src/rp2_common/hardware_gpio/include
CFLAGS += -I$(SDK_DIR)/src/rp2_common/hardware_timer/include
CFLAGS += -I$(SDK_DIR)/src/rp2_common/hardware_irq/include
CFLAGS += -I$(SDK_DIR)/src/rp2_common/hardware_uart/include
CFLAGS += -I$(SDK_DIR)/src/rp2_common/pico_platform/include
CFLAGS += -I$(SDK_DIR)/src/common/pico_binary_info/include

CFLAGS += -I$(SDK_DIR)/src/rp2_common/hardware_flash/include
CFLAGS += -I$(SDK_DIR)/src/rp2_common/pico_printf/include/
CFLAGS += -I$(SDK_DIR)/src/rp2_common/pico_unique_id/include/
CFLAGS += -I$(SDK_DIR)/src/rp2_common/pico_stdio_uart/include/
CFLAGS += -I$(SDK_DIR)/src/rp2_common/pico_malloc/include/

CFLAGS += -I$(SDK_DIR)/src/common/pico_sync/include
CFLAGS += -I$(SDK_DIR)/src/rp2_common/hardware_pio/include
CFLAGS += -I$(SDK_DIR)/src/rp2_common/hardware_resets/include
CFLAGS += -I$(SDK_DIR)/src/common/pico_util/include
CFLAGS += -I$(SDK_DIR)/src/rp2_common/hardware_watchdog/include
CFLAGS += -I$(SDK_DIR)/src/rp2_common/hardware_xosc/include
CFLAGS += -I$(SDK_DIR)/src/rp2_common/hardware_vreg/include

CFLAGS += -I$(SDK_DIR)/src/common/pico_usb_reset_interface_headers/include
CFLAGS += -I$(SDK_DIR)/lib/tinyusb/src
CFLAGS += -I$(SDK_DIR)/src/rp2_common/pico_stdio_usb/include

#include untuk pheripheral
CFLAGS += -I$(SDK_DIR)/src/rp2_common/hardware_adc/include


# source file untuk pheripheral
SDK_SRC += $(SDK_DIR)/src/rp2_common/hardware_gpio/gpio.c
SDK_SRC += $(SDK_DIR)/src/rp2_common/hardware_adc/adc.c


SDK_SRC += $(SDK_DIR)/src/rp2_common/pico_platform_panic/panic.c
SDK_SRC += $(SDK_DIR)/src/common/hardware_claim/claim.c
SDK_SRC += $(SDK_DIR)/src/rp2_common/hardware_sync/sync.c
SDK_SRC += $(SDK_DIR)/src/rp2_common/hardware_sync_spin_lock/sync_spin_lock.c
SDK_SRC += $(SDK_DIR)/src/rp2_common/hardware_irq/irq.c
SDK_SRC += $(SDK_DIR)/src/common/pico_sync/lock_core.c
SDK_SRC += $(SDK_DIR)/src/common/pico_sync/mutex.c
SDK_SRC += $(SDK_DIR)/src/common/pico_sync/critical_section.c
SDK_SRC += $(SDK_DIR)/src/common/pico_time/time.c
SDK_SRC += $(SDK_DIR)/src/rp2_common/hardware_timer/timer.c
SDK_SRC += $(SDK_DIR)/src/rp2_common/hardware_uart/uart.c
SDK_SRC += $(SDK_DIR)/src/rp2_common/hardware_clocks/clocks.c
SDK_SRC += $(SDK_DIR)/src/rp2_common/hardware_pll/pll.c
SDK_SRC += $(SDK_DIR)/src/rp2_common/hardware_watchdog/watchdog.c
SDK_SRC += $(SDK_DIR)/src/rp2_common/hardware_ticks/ticks.c
SDK_SRC += $(SDK_DIR)/src/rp2_common/pico_bootrom/bootrom.c
SDK_SRC += $(SDK_DIR)/src/rp2_common/pico_bootrom/bootrom_lock.c
SDK_SRC += $(SDK_DIR)/src/rp2_common/hardware_boot_lock/boot_lock.c
SDK_SRC += $(SDK_DIR)/src/rp2_common/hardware_xosc/xosc.c
SDK_SRC += $(SDK_DIR)/src/rp2_common/pico_runtime/runtime.c
SDK_SRC += $(SDK_DIR)/src/rp2_common/pico_runtime_init/runtime_init.c
SDK_SRC += $(SDK_DIR)/src/rp2_common/pico_runtime_init/runtime_init_clocks.c
SDK_SRC += $(SDK_DIR)/src/rp2_common/pico_printf/printf.c
SDK_SRC += $(SDK_DIR)/src/rp2_common/pico_clib_interface/newlib_interface.c
SDK_SRC += $(SDK_DIR)/src/rp2_common/pico_stdio/stdio.c
SDK_SRC += $(SDK_DIR)/src/rp2_common/pico_stdio_uart/stdio_uart.c
SDK_SRC += $(SDK_DIR)/src/rp2_common/pico_stdio_usb/reset_interface.c
SDK_SRC += $(SDK_DIR)/src/rp2_common/pico_stdio_usb/stdio_usb.c
SDK_SRC += $(SDK_DIR)/src/rp2_common/pico_stdio_usb/stdio_usb_descriptors.c
SDK_SRC += $(SDK_DIR)/src/rp2_common/pico_unique_id/unique_id.c

# Tiny USB
SDK_SRC += $(SDK_DIR)/lib/tinyusb/src/portable/raspberrypi/rp2040/dcd_rp2040.c
SDK_SRC += $(SDK_DIR)/lib/tinyusb/src/portable/raspberrypi/rp2040/rp2040_usb.c
SDK_SRC += $(SDK_DIR)/lib/tinyusb/src/device/usbd.c
SDK_SRC += $(SDK_DIR)/lib/tinyusb/src/device/usbd_control.c
SDK_SRC += $(SDK_DIR)/lib/tinyusb/src/class/cdc/cdc_device.c
SDK_SRC += $(SDK_DIR)/lib/tinyusb/src/class/vendor/vendor_device.c
SDK_SRC += $(SDK_DIR)/lib/tinyusb/src/tusb.c
SDK_SRC += $(SDK_DIR)/lib/tinyusb/src/common/tusb_fifo.c

# SDK source files for RP2350
SDK_SOURCES = $(SDK_SRC)

# Startup and linker files for RP2350
STARTUP_SOURCES = \
	$(SDK_DIR)/src/rp2_common/pico_crt0/crt0.S \
	$(SDK_DIR)/src/rp2_common/hardware_irq/irq_handler_chain.S
	
# Application source
APP_SOURCES = main.c

# Generate object files
SDK_OBJS = $(SDK_SOURCES:.c=.o)

STARTUP_OBJS = $(STARTUP_SOURCES:.S=.o)
APP_OBJS = $(APP_SOURCES:.c=.o)

#ALL_OBJS = $(STARTUP_OBJS) $(APP_OBJS) $(SDK_OBJS)
ALL_OBJS = $(APP_OBJS) $(SDK_OBJS) $(STARTUP_OBJS)

# Output files
ELF = $(PICO_TARGET).elf
UF2 = $(PICO_TARGET).uf2
BIN = $(PICO_TARGET).bin
HEX = $(PICO_TARGET).hex
DIS = $(PICO_TARGET).disam

# Default target
all: $(UF2) $(DIS)
	@echo "Build complete! $(UF2) created."
	@echo "SDK Version: $(SDK_VERSION)"
	@echo "Target: Pico 2 (RP2350)"
	@$(SIZE) $(ELF)
	#$(OBJDUMP) -d $< > disamb

#LIBS = -lc -lgcc -lnosys 
LIBS = -lc -lgcc -lm
#LIBS = -lc -lstdc++

# Link the final executable - RP2350 specific linker script
$(ELF): $(ALL_OBJS)
	@echo "Linking $@... ===========================>>>>>>>"
	$(CC) $(LDFLAGS) -Wl,-T,memmap_default.ld \
		-Wl,--start-group $^ -Wl,--end-group \
		$(LIBS) -o $@

# Convert to UF2 format (RP2350 uses same address)
$(UF2): $(ELF)
	@echo "Creating $@..."
	$(OBJCOPY) -O binary $< $(BIN)
	$(PICOTOOL) uf2 convert $< $@ --family rp2350-arm-s --abs-block
	#$(PICOTOOL) uf2 convert blink.elf blink.uf2 --family rp2350-arm-s --abs-block

$(DIS): $(ELF)
	@echo "Generating disassembly $@..."
	$(OBJDUMP) -d -S -C -l --no-show-raw-insn $< > $@
	@echo "  - Disassembly saved to $(DIS)"


# Compile C files
%.o: %.c
	@echo "HHHHHHHHHHHHHHHHHHHHHH"
	@echo "Compiling $<..."
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Compile assembly files
%.o: %.S
	@echo "OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO"
	@echo "Compiling $<..."
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	
# Clean
clean:
	@echo "Cleaning..."
	rm -f $(ELF) $(UF2) $(BIN) $(HEX) $(PICO_TARGET).map $(DIS)
	rm -f $(ALL_OBJS)
	rm -f $(STARTUP_OBJS:.o=.d) $(APP_OBJS:.o=.d) $(SDK_OBJS:.o=.d)
	@echo "Clean complete."

# Program the Pico 2 (requires picotool)
flash: $(UF2)
	@echo "Flashing $(UF2) to Pico 2... & reboot.."
	$(PICOTOOL) load $(UF2) -t uf2 -f 
	
# Generate dependency files
%.d: %.c
	@echo "Generating dependencies for $<..."
	$(CC) -M $(CFLAGS) $(INCLUDES) $< > $@.tmp
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.tmp > $@
	rm -f $@.tmp

# Include dependency files
-include $(ALL_OBJS:.o=.d)

# PHONY targets
.PHONY: all clean flash

