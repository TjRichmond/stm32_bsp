EXAMPLE_NAME=int_blink

CC = arm-none-eabi-gcc
LD = arm-none-eabi-ld
OBJ_DIR = ../obj
TARGET = $(EXAMPLE_NAME).elf
BSP_LIB = ../../bsp/stm32_bsp.a

SRC_DIR = src
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

CFLAGS = -mcpu=cortex-m33 -mthumb -nostdlib -mfpu=fpv4-sp-d16 -mfloat-abi=hard -g
CPPFLAGS =-DSTM32U575xx \
				 	-I../../CMSIS/Device/ST/STM32U5/Include \
				 	-I../../CMSIS/CMSIS/Core/Include \
				 	-g

STARTUP_DIR = ../../bsp/startup

LINKER_FILE=$(STARTUP_DIR)/linker_script.ld
LDFLAGS=-T$(LINKER_FILE)

all: $(OBJ_DIR) $(OBJ_DIR)/$(TARGET)

$(OBJ_DIR)/$(TARGET): $(OBJFILES) $(BSP_LIB)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

$(BSP_LIB):
	$(MAKE) -C ../../bsp

clean:
	rm -rf $(OBJ_DIR) $(TARGET)
	$(MAKE) -C ../../bsp clean