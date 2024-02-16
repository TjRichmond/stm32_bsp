CC = arm-none-eabi-gcc
CFLAGS = -mcpu=cortex-m33 -mthumb -nostdlib -mfpu=fpv4-sp-d16 -mfloat-abi=hard -g
CPPFLAGS =-DSTM32U575xx \
				 	-I../CMSIS/Device/ST/STM32U5/Include \
				 	-I../CMSIS/CMSIS/Core/Include \
				 	-Iinclude \
				 	-g

OBJ_DIR = obj
SRC_DIR = src
STARTUP_DIR = startup
LIB_NAME = stm32_bsp.a

CMSIS_DEVICE_FILE = ../CMSIS/Device/ST/STM32U5/Source/Templates/system_stm32u5xx

SRC_FILES = $(wildcard $(SRC_DIR)/*.c) $(STARTUP_DIR)/startup.c $(CMSIS_DEVICE_FILE).c
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

all: $(OBJ_DIR) $(OBJ_DIR)/$(STARTUP_DIR).o $(OBJ_DIR)/system_stm32u5xx.o $(LIB_NAME)

$(LIB_NAME): $(OBJ_FILES)
	ar rcs $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR)/$(STARTUP_DIR).o: $(STARTUP_DIR)/startup.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR)/system_stm32u5xx.o: $(CMSIS_DEVICE_FILE).c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

clean:
	rm -rf $(OBJ_DIR) $(LIB_NAME)

.PHONY: all clean