ROOT_DIR=../..
CC=arm-none-eabi-gcc
CFLAGS=-mcpu=cortex-m33 -mthumb -nostdlib -mfpu=fpv4-sp-d16 -mfloat-abi=hard -g
CPPFLAGS=-DSTM32U575xx \
				 -I$(ROOT_DIR)/CMSIS/Device/ST/STM32U5/Include \
				 -I$(ROOT_DIR)/CMSIS/CMSIS/Core/Include \
				 -I$(ROOT_DIR)/bsp/include \
				 -g

LINKER_FILE=linker_script.ld
LDFLAGS=-T $(LINKER_FILE)

TARGET = int_blink.elf

OPENOCD_PROGRAMMER = openocd
OPENOCD_FLAGS = -f interface/stlink.cfg -f target/stm32u5x.cfg

STM_PROGRAMMER = STM32_Programmer_CLI

OBJFILES = 	main.o \
         	startup.o \
		 	system_stm32u5xx.o \
		 	bsp_gpio.o \

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $^ -o $(TARGET)

main.o: main.c
	$(CC) $(CFLAGS) $(CPPFLAGS) main.c -c

startup.o: startup.c
	$(CC) $(CFLAGS) $(CPPFLAGS) startup.c -c

system_stm32u5xx.o: $(ROOT_DIR)/CMSIS/Device/ST/STM32U5/Source/Templates/system_stm32u5xx.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $(ROOT_DIR)/CMSIS/Device/ST/STM32U5/Source/Templates/system_stm32u5xx.c -c

clean:
	rm -f *.o *.elf

openocd_flash: $(TARGET)
	$(OPENOCD_PROGRAMMER) $(OPENOCD_FLAGS) -c "program $(TARGET) verify reset exit"

stm_flash: $(TARGET)
	$(STM_PROGRAMMER) -c port=SWD -w $(TARGET) 0x08000000 -s 0x08000000

stm_erase: $(TARGET)
	$(STM_PROGRAMMER) -c port=SWD -e all