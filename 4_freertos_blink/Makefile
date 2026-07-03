# Pico 2 (RP2350) Blink Example with FreeRTOS - Custom Makefile
# Target: main_adc.uf2

# ============================================================================
# TOOLCHAIN SETTINGS
# ============================================================================
ARMGNU    = ../toolchain/gcc-arm-none-eabi-10.3-2021.10/bin/arm-none-eabi
PICOTOOL  = ../toolchain/pqt-picotool/4.1.0-1aec55e/picotool

CC        = $(ARMGNU)-gcc
CXX       = $(ARMGNU)-g++
AS        = $(ARMGNU)-as
AR        = $(ARMGNU)-ar
OBJCOPY   = $(ARMGNU)-objcopy
OBJDUMP   = $(ARMGNU)-objdump
SIZE      = $(ARMGNU)-size

# ============================================================================
# TARGET CONFIGURATION
# ============================================================================
PICO_BOARD      ?= pico2
PICO_PLATFORM   ?= rp2350
PICO_TARGET      = main_adc
PICO_BAUD_RATE  ?= 115200

# RP2350 specific
PICO_RP2350          = 1
PICO_RP2350_AARCH32  = 1

# Floating point ABI: soft, softfp, or hard
FPU = hard

# ============================================================================
# DIRECTORIES
# ============================================================================
SDK_DIR   = ../pico-sdk
RTOS_DIR  = ../FreeRTOS-Kernel

# ============================================================================
# COMPILER FLAGS
# ============================================================================
ARCH_FLAGS = -mcpu=cortex-m33 -mthumb -march=armv8-m.main+fp+dsp -mfloat-abi=$(FPU) -mcmse

CFLAGS  = $(ARCH_FLAGS)
CFLAGS += -O2 -g3 -Wall -Wextra -Wno-unused-parameter
CFLAGS += -ffunction-sections -fdata-sections
CFLAGS += -std=gnu11

# RP2350 definitions
CFLAGS += -D$(PICO_PLATFORM)
CFLAGS += -DPICO_BOARD=$(PICO_BOARD)
CFLAGS += -DPICO_RP2350=$(PICO_RP2350)
CFLAGS += -DPICO_RP2350_AARCH32=$(PICO_RP2350_AARCH32)
CFLAGS += -DPICO_BAUD_RATE=$(PICO_BAUD_RATE)
CFLAGS += -DPICO_STDIO_ENABLE_CRLF_SUPPORT=1
CFLAGS += -DPICO_RP2350_USE_CMSIS=1

# USB configuration
CFLAGS += -DLIB_PICO_STDIO_USB=1
CFLAGS += -DPICO_USB_DEVICE_ENUMERATION_FIX=1
CFLAGS += -DPICO_USB_DEVICE_CDC_ENUMERATION_FIX=1
CFLAGS += -DPICO_USB_DEVICE_FORCE_ENUMERATION=1
CFLAGS += -DPICO_NO_HARDWARE=0
CFLAGS += -DPICO_NO_FLASH=0

# FreeRTOS definitions
CFLAGS += -DFREE_RTOS_KERNEL_SMP=1
CFLAGS += -DLIB_FREERTOS_KERNEL=1
CFLAGS += -DLIB_PICO_ASYNC_CONTEXT_FREERTOS=1
CFLAGS += -DLIB_PICO_MULTICORE=1
CFLAGS += -DPICO_CONFIG_RTOS_ADAPTER_HEADER=$(RTOS_DIR)/portable/ThirdParty/GCC/RP2350_ARM_NTZ/non_secure/freertos_sdk_config.h

# Common SDK definitions (merged from BLINK and RTOS)
CFLAGS += -DCFG_TUSB_DEBUG=0
CFLAGS += -DCFG_TUSB_MCU=OPT_MCU_RP2040
CFLAGS += -DCFG_TUSB_OS=OPT_OS_PICO
CFLAGS += -DLIB_BOOT_STAGE2_HEADERS=1
CFLAGS += -DLIB_PICO_ATOMIC=1
CFLAGS += -DLIB_PICO_BIT_OPS=1
CFLAGS += -DLIB_PICO_BIT_OPS_PICO=1
CFLAGS += -DLIB_PICO_CLIB_INTERFACE=1
CFLAGS += -DLIB_PICO_CRT0=1
CFLAGS += -DLIB_PICO_CXX_OPTIONS=1
CFLAGS += -DLIB_PICO_DIVIDER=1
CFLAGS += -DLIB_PICO_DIVIDER_COMPILER=1
CFLAGS += -DLIB_PICO_DOUBLE=1
CFLAGS += -DLIB_PICO_DOUBLE_PICO=1
CFLAGS += -DLIB_PICO_FIX_RP2040_USB_DEVICE_ENUMERATION=1
CFLAGS += -DLIB_PICO_FLASH=1
CFLAGS += -DLIB_PICO_FLOAT=1
CFLAGS += -DLIB_PICO_FLOAT_PICO=1
CFLAGS += -DLIB_PICO_FLOAT_PICO_VFP=1
CFLAGS += -DLIB_PICO_INT64_OPS=1
CFLAGS += -DLIB_PICO_INT64_OPS_COMPILER=1
CFLAGS += -DLIB_PICO_MALLOC=1
CFLAGS += -DLIB_PICO_MEM_OPS=1
CFLAGS += -DLIB_PICO_MEM_OPS_COMPILER=1
CFLAGS += -DLIB_PICO_NEWLIB_INTERFACE=1
CFLAGS += -DLIB_PICO_PLATFORM=1
CFLAGS += -DLIB_PICO_PLATFORM_COMMON=1
CFLAGS += -DLIB_PICO_PLATFORM_COMPILER=1
CFLAGS += -DLIB_PICO_PLATFORM_PANIC=1
CFLAGS += -DLIB_PICO_PLATFORM_SECTIONS=1
CFLAGS += -DLIB_PICO_PRINTF=1
CFLAGS += -DLIB_PICO_PRINTF_PICO=1
CFLAGS += -DLIB_PICO_RUNTIME=1
CFLAGS += -DLIB_PICO_RUNTIME_INIT=1
CFLAGS += -DLIB_PICO_STANDARD_BINARY_INFO=1
CFLAGS += -DLIB_PICO_STANDARD_LINK=1
CFLAGS += -DLIB_PICO_STDIO=1
CFLAGS += -DLIB_PICO_STDIO_UART=1
CFLAGS += -DLIB_PICO_STDIO_USB=1
CFLAGS += -DLIB_PICO_STDLIB=1
CFLAGS += -DLIB_PICO_SYNC=1
CFLAGS += -DLIB_PICO_SYNC_CRITICAL_SECTION=1
CFLAGS += -DLIB_PICO_SYNC_MUTEX=1
CFLAGS += -DLIB_PICO_SYNC_SEM=1
CFLAGS += -DLIB_PICO_TIME=1
CFLAGS += -DLIB_PICO_TIME_ADAPTER=1
CFLAGS += -DLIB_PICO_UNIQUE_ID=1
CFLAGS += -DLIB_PICO_UTIL=1
CFLAGS += -DPICO_32BIT=1
CFLAGS += -DPICO_BUILD=1
CFLAGS += -DPICO_CMAKE_BUILD_TYPE=\"Release\"
CFLAGS += -DPICO_COPY_TO_RAM=0
CFLAGS += -DPICO_CXX_ENABLE_EXCEPTIONS=0
CFLAGS += -DPICO_NO_FLASH=0
CFLAGS += -DPICO_NO_HARDWARE=0
CFLAGS += -DPICO_ON_DEVICE=1
CFLAGS += -DPICO_RP2040_USB_DEVICE_UFRAME_FIX=1
CFLAGS += -DPICO_RP2350=1
CFLAGS += -DPICO_USE_BLOCKED_RAM=0

# ============================================================================
# INCLUDE PATHS
# ============================================================================
CFLAGS += -I.

# Pico SDK includes
CFLAGS += -I$(SDK_DIR)/src/common/pico_stdlib/include 
CFLAGS += -I$(SDK_DIR)/src/common/pico_stdlib_headers/include
CFLAGS += -I$(SDK_DIR)/src/common/pico_time/include
CFLAGS += -I$(SDK_DIR)/src/common/pico_base/include
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
#CFLAGS += -I$(SDK_DIR)/src/rp2040/hardware_regs/include
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
#CFLAGS += -I$(SDK_DIR)/lib/tinyusb/src
CFLAGS += -I$(SDK_DIR)/src/rp2_common/pico_stdio_usb/include

CFLAGS += -I$(SDK_DIR)/src/rp2_common/pico_multicore/include
CFLAGS += -I$(SDK_DIR)/src/rp2_common/pico_async_context/include
CFLAGS += -I$(SDK_DIR)/src/rp2_common/hardware_exception/include

#include untuk pheripheral
CFLAGS += -I$(SDK_DIR)/src/rp2_common/hardware_adc/include

# TinyUSB
CFLAGS += -I$(SDK_DIR)/lib/tinyusb/src

# FreeRTOS
CFLAGS += -I$(RTOS_DIR)/include
CFLAGS += -I$(RTOS_DIR)/portable/ThirdParty/GCC/RP2350_ARM_NTZ/non_secure

# ============================================================================
# LINKER FLAGS
# ============================================================================
LDFLAGS  = $(ARCH_FLAGS)
LDFLAGS += -Wl,--gc-sections
LDFLAGS += -Wl,--wrap,malloc -Wl,--wrap,free
LDFLAGS += -Wl,--wrap,realloc -Wl,--wrap,calloc
LDFLAGS += -Wl,-Map=$(PICO_TARGET).map
# LDFLAGS += -specs=nano.specs  # Uncomment for smaller binary (floating point printf won't work)

LIBS = -lc -lgcc -lm

# ============================================================================
# SOURCE FILES
# ============================================================================
# Application
APP_SOURCES = main.c

# FreeRTOS sources
RTOS_SOURCES = \
    $(RTOS_DIR)/croutine.c \
    $(RTOS_DIR)/event_groups.c \
    $(RTOS_DIR)/list.c \
    $(RTOS_DIR)/queue.c \
    $(RTOS_DIR)/stream_buffer.c \
    $(RTOS_DIR)/tasks.c \
    $(RTOS_DIR)/timers.c \
    $(RTOS_DIR)/portable/MemMang/heap_4.c \
    $(RTOS_DIR)/portable/ThirdParty/GCC/RP2350_ARM_NTZ/non_secure/port.c \
    $(RTOS_DIR)/portable/ThirdParty/GCC/RP2350_ARM_NTZ/non_secure/portasm.c

# Pico SDK sources
SDK_SOURCES = \
    $(SDK_DIR)/src/common/hardware_claim/claim.c \
    $(SDK_DIR)/src/common/pico_sync/critical_section.c \
    $(SDK_DIR)/src/common/pico_sync/lock_core.c \
    $(SDK_DIR)/src/common/pico_sync/mutex.c \
    $(SDK_DIR)/src/common/pico_time/time.c \
    $(SDK_DIR)/src/rp2_common/hardware_adc/adc.c \
    $(SDK_DIR)/src/rp2_common/hardware_boot_lock/boot_lock.c \
    $(SDK_DIR)/src/rp2_common/hardware_clocks/clocks.c \
    $(SDK_DIR)/src/rp2_common/hardware_exception/exception.c \
    $(SDK_DIR)/src/rp2_common/hardware_gpio/gpio.c \
    $(SDK_DIR)/src/rp2_common/hardware_irq/irq.c \
    $(SDK_DIR)/src/rp2_common/hardware_pll/pll.c \
    $(SDK_DIR)/src/rp2_common/hardware_sync/sync.c \
    $(SDK_DIR)/src/rp2_common/hardware_sync_spin_lock/sync_spin_lock.c \
    $(SDK_DIR)/src/rp2_common/hardware_ticks/ticks.c \
    $(SDK_DIR)/src/rp2_common/hardware_timer/timer.c \
    $(SDK_DIR)/src/rp2_common/hardware_uart/uart.c \
    $(SDK_DIR)/src/rp2_common/hardware_watchdog/watchdog.c \
    $(SDK_DIR)/src/rp2_common/hardware_xosc/xosc.c \
    $(SDK_DIR)/src/rp2_common/pico_async_context/async_context_base.c \
    $(SDK_DIR)/src/rp2_common/pico_async_context/async_context_freertos.c \
    $(SDK_DIR)/src/rp2_common/pico_bootrom/bootrom.c \
    $(SDK_DIR)/src/rp2_common/pico_bootrom/bootrom_lock.c \
    $(SDK_DIR)/src/rp2_common/pico_clib_interface/newlib_interface.c \
    $(SDK_DIR)/src/rp2_common/pico_multicore/multicore.c \
    $(SDK_DIR)/src/rp2_common/pico_platform_panic/panic.c \
    $(SDK_DIR)/src/rp2_common/pico_printf/printf.c \
    $(SDK_DIR)/src/rp2_common/pico_runtime/runtime.c \
    $(SDK_DIR)/src/rp2_common/pico_runtime_init/runtime_init.c \
    $(SDK_DIR)/src/rp2_common/pico_runtime_init/runtime_init_clocks.c \
    $(SDK_DIR)/src/rp2_common/pico_stdio/stdio.c \
    $(SDK_DIR)/src/rp2_common/pico_stdio_uart/stdio_uart.c \
    $(SDK_DIR)/src/rp2_common/pico_stdio_usb/reset_interface.c \
    $(SDK_DIR)/src/rp2_common/pico_stdio_usb/stdio_usb.c \
    $(SDK_DIR)/src/rp2_common/pico_stdio_usb/stdio_usb_descriptors.c \
    $(SDK_DIR)/src/rp2_common/pico_unique_id/unique_id.c

# TinyUSB sources
TINYUSB_SOURCES = \
    $(SDK_DIR)/lib/tinyusb/src/class/cdc/cdc_device.c \
    $(SDK_DIR)/lib/tinyusb/src/class/vendor/vendor_device.c \
    $(SDK_DIR)/lib/tinyusb/src/common/tusb_fifo.c \
    $(SDK_DIR)/lib/tinyusb/src/device/usbd.c \
    $(SDK_DIR)/lib/tinyusb/src/device/usbd_control.c \
    $(SDK_DIR)/lib/tinyusb/src/portable/raspberrypi/rp2040/dcd_rp2040.c \
    $(SDK_DIR)/lib/tinyusb/src/portable/raspberrypi/rp2040/rp2040_usb.c \
    $(SDK_DIR)/lib/tinyusb/src/tusb.c

# Startup and linker
STARTUP_SOURCES = \
    $(SDK_DIR)/src/rp2_common/pico_crt0/crt0.S \
    $(SDK_DIR)/src/rp2_common/hardware_irq/irq_handler_chain.S

# Combine all sources
ALL_SOURCES = $(APP_SOURCES) $(SDK_SOURCES) $(TINYUSB_SOURCES) $(RTOS_SOURCES) $(STARTUP_SOURCES)

# ============================================================================
# OBJECT FILES
# ============================================================================
ALL_OBJS = $(ALL_SOURCES:%.c=%.o)
ALL_OBJS := $(ALL_OBJS:%.S=%.o)

# ============================================================================
# OUTPUT FILES
# ============================================================================
ELF = $(PICO_TARGET).elf
UF2 = $(PICO_TARGET).uf2
BIN = $(PICO_TARGET).bin
HEX = $(PICO_TARGET).hex
DIS = $(PICO_TARGET).disam

# ============================================================================
# RULES
# ============================================================================
.PHONY: all clean flash

all: $(UF2) $(DIS)
	@echo "============================================================"
	@echo "Build complete! $(UF2) created."
	@echo "Target: Pico 2 (RP2350)"
	@echo "============================================================"
	@$(SIZE) $(ELF)

$(ELF): $(ALL_OBJS)
	@echo "Linking $@..."
	$(CC) $(LDFLAGS) -Wl,-T,memmap_default.ld \
		-Wl,--start-group $^ -Wl,--end-group \
		$(LIBS) -o $@

$(UF2): $(ELF)
	@echo "Creating $@..."
	$(OBJCOPY) -O binary $< $(BIN)
	$(PICOTOOL) uf2 convert $< $@ --family rp2350-arm-s --abs-block

$(DIS): $(ELF)
	@echo "Generating disassembly $@..."
	$(OBJDUMP) -d -S -C -l --no-show-raw-insn $< > $@
	@echo "Disassembly saved to $(DIS)"

%.o: %.c
	@echo "Compiling $<..."
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.S
	@echo "Compiling $<..."
	$(CC) $(CFLAGS) -c $< -o $@

flash: $(UF2)
	@echo "Flashing $(UF2) to Pico 2... & Reboot"
	$(PICOTOOL) load $(UF2) -t uf2 -f

clean:
	@echo "Cleaning..."
	rm -f $(ELF) $(UF2) $(BIN) $(HEX) $(PICO_TARGET).map $(DIS)
	rm -f $(ALL_OBJS)
	rm -f $(ALL_OBJS:.o=.d)
	@echo "Clean complete."

# Generate dependency files
%.d: %.c
	@$(CC) -M $(CFLAGS) $< > $@.tmp
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.tmp > $@
	rm -f $@.tmp

%.d: %.S
	@$(CC) -M $(CFLAGS) $< > $@.tmp
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.tmp > $@
	rm -f $@.tmp

-include $(ALL_OBJS:.o=.d)
