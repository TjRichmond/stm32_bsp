CC=arm-none-eabi-gcc
CFLAGS=-mcpu=cortex-m33 -mthumb -nostdlib -mfpu=fpv4-sp-d16 -mfloat-abi=hard -g
CPPFLAGS=-DSTM32U575xx \
				 -Ivendor/CMSIS/Device/ST/STM32U5/Include \
				 -Ivendor/CMSIS/CMSIS/Core/Include \
				 -g

LINKER_FILE=linker_script.ld
LDFLAGS=-T $(LINKER_FILE)

BINARY = blink.elf

PROGRAMMER = openocd
PROGRAMMER_FLAGS = -f interface/stlink.cfg -f target/stm32u5x.cfg

all: $(BINARY)

$(BINARY): main.o startup.o system_stm32u5xx.o
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $^ -o $(BINARY)

main.o: main.c
	$(CC) $(CFLAGS) $(CPPFLAGS) main.c -c

startup.o: startup.c
	$(CC) $(CFLAGS) $(CPPFLAGS) startup.c -c

system_stm32u5xx.o: vendor/CMSIS/Device/ST/STM32U5/Source/Templates/system_stm32u5xx.c
	$(CC) $(CFLAGS) $(CPPFLAGS) vendor/CMSIS/Device/ST/STM32U5/Source/Templates/system_stm32u5xx.c -c


.PHONY: clean
clean:
	rm -f *.o *.elf

flash: $(BINARY)
	$(PROGRAMMER) $(PROGRAMMER_FLAGS) -c "program $(BINARY) verify reset exit"