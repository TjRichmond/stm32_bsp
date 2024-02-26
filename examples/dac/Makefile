EXAMPLE_NAME=dac

TARGET_DIR = ../obj
TARGET = $(TARGET_DIR)/$(EXAMPLE_NAME).elf

BSP_DIR = ../../bsp
BSP_LIB = $(BSP_DIR)/libstm32_bsp.a

STARTUP_DIR = $(BSP_DIR)/startup
LINKER_FILE=$(STARTUP_DIR)/linker_script.ld
LDFLAGS=-T$(LINKER_FILE)

SRC_DIR = src
OBJ_DIR = obj

SRC_FILES = $(wildcard $(SRC_DIR)/*.c) $(STARTUP_DIR)/startup.c $(CMSIS_DEVICE_FILE).c
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

CMSIS_DEVICE_FILE = ../../CMSIS/Device/ST/STM32U5/Source/Templates/system_stm32u5xx

CC = arm-none-eabi-gcc
CFLAGS = -mcpu=cortex-m33 -mthumb -nostdlib -mfpu=fpv4-sp-d16 -mfloat-abi=hard -g
CPPFLAGS =-DSTM32U575xx \
				 	-I../../CMSIS/Device/ST/STM32U5/Include \
				 	-I../../CMSIS/CMSIS/Core/Include \
					-I$(BSP_DIR)/include \
				 	-g

all: $(OBJ_DIR) $(TARGET) $(OBJ_DIR)/startup.o $(OBJ_DIR)/system_stm32u5xx.o

$(TARGET): $(OBJ_FILES) $(BSP_LIB) | $(TARGET_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -L$(BSP_DIR) -lstm32_bsp $^ -o $@ 

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR)/startup.o: $(STARTUP_DIR)/startup.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR)/system_stm32u5xx.o: $(CMSIS_DEVICE_FILE).c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

$(TARGET_DIR):
	mkdir -p $@

$(BSP_LIB):
	$(MAKE) -C $(BSP_DIR)

clean:
	rm -rf $(OBJ_DIR) $(TARGET)
	$(MAKE) -C $(BSP_DIR) clean