ROOT_DIR=../../
CC=arm-none-eabi-gcc
CFLAGS=-mcpu=cortex-m33 -mthumb -nostdlib -mfpu=fpv4-sp-d16 -mfloat-abi=hard -g
CPPFLAGS=-DSTM32U575xx \
				 -I$(ROOT_DIR)CMSIS/Device/ST/STM32U5/Include \
				 -I$(ROOT_DIR)CMSIS/CMSIS/Core/Include \
				 -I$(ROOT_DIR) \
				 -g

LINKER_FILE=linker_script.ld
LDFLAGS=-T $(LINKER_FILE)

BINARY = test.elf

PROGRAMMER = openocd
PROGRAMMER_FLAGS = -f interface/stlink.cfg -f target/stm32u5x.cfg

all: $(BINARY)

$(BINARY): main.o startup.o system_stm32u5xx.o
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $^ -o $(BINARY)

main.o: main.c
	$(CC) $(CFLAGS) $(CPPFLAGS) main.c -c

startup.o: startup.c
	$(CC) $(CFLAGS) $(CPPFLAGS) startup.c -c

system_stm32u5xx.o: $(ROOT_DIR)CMSIS/Device/ST/STM32U5/Source/Templates/system_stm32u5xx.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $(ROOT_DIR)CMSIS/Device/ST/STM32U5/Source/Templates/system_stm32u5xx.c -c


.PHONY: clean
clean:
	rm -f *.o *.elf

flash: $(BINARY)
	$(PROGRAMMER) $(PROGRAMMER_FLAGS) -c "program $(BINARY) verify reset exit"