EXAMPLES = blink int_blink usart

OPENOCD_PROGRAMMER = openocd
OPENOCD_FLAGS = -f interface/stlink.cfg -f target/stm32u5x.cfg

STM_PROGRAMMER = STM32_Programmer_CLI

PROGRAM ?= int_blink.elf

.PHONY: all bsp clean $(EXAMPLES)

all: bsp $(EXAMPLES)

bsp: 
	$(MAKE) -C bsp

$(EXAMPLES): bsp
	$(MAKE) -C examples/$@

cleaner: clean
	rm -rf examples/obj

clean:
	for examples in $(EXAMPLES); do \
		$(MAKE) -C examples/$$examples clean; \
	done
	$(MAKE) -C bsp clean

openocd_flash:
	$(OPENOCD_PROGRAMMER) $(OPENOCD_FLAGS) -c "program examples/obj/$(PROGRAM) verify reset exit"

stm_flash:
	$(STM_PROGRAMMER) -c port=SWD -w examples/obj/$(PROGRAM) 0x08000000 -s 0x08000000

stm_erase:
	$(STM_PROGRAMMER) -c port=SWD -e all