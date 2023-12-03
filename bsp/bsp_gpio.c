#include "bsp_gpio.h"

// function for toggling a output data register based on the port and pin
int8_t GpioToggleOutput(GPIO_TypeDef *port, uint8_t pin)
{
  // Check if pin is outside of bounds of a 32 bit register
  if (pin > 32) return -1;

  // Toggle pin output value
  port->ODR ^= (1 << pin);
  return 0;
}

// function for setting gpio pin mode
void GpioPinMode(GPIO_TypeDef *port, uint8_t pin, pinMode mode)
{
  switch (mode)
  {
  case INPUT_MODE:
    break;

  case OUTPUT_MODE:
    port->MODER &= ~(2 << (pin*2));
    port->PUPDR |= (1 << (pin*2));
    break;

  case ALT_FUNC_MODE:
    break;

  case ANALOG_MODE:
    break;

  default:
    break;
  };
}