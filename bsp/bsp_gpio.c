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
int8_t GpioPinMode(GPIO_TypeDef *port, uint8_t pin, PinMode mode)
{
  // Check if pin is outside of bounds of a 32 bit register
  if (pin > 32) return -1;

  // Set mode of pin register
  port->MODER &= ~(mode << (pin*2));
  return 0;
}