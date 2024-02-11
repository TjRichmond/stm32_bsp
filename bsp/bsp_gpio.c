/**
 * @file bsp_gpio.c
 * @brief module for controlling mcu gpio hardware 
 *
 * This module contains functions to configure and read/write gpio hardware
*/
#include "bsp_gpio.h"

/**
 * @brief Initialize a gpio pin configuration
 * 
 * The gpio pin will be configured as an input/output and which pull mode
 * @param port gpio port
 * @param pin gpio pin
 * @param pinMode input/output mode
 * @param pullMode resistor pull up/down mode
 * @return true/false value to indicate success of function 
*/
uint8_t GpioPinInit(GPIO_TypeDef *port, uint8_t pin, PinMode pinMode, \
                PullMode pullMode)
{
    // Enable peripheral clock for the provided pin
    if(port == GPIOA) RCC->AHB2ENR1 |= (1 << RCC_AHB2ENR1_GPIOAEN_Pos);
    else if(port == GPIOB) RCC->AHB2ENR1 |= (1 << RCC_AHB2ENR1_GPIOBEN_Pos);
    else if(port == GPIOC) RCC->AHB2ENR1 |= (1 << RCC_AHB2ENR1_GPIOCEN_Pos);
    else if(port == GPIOD) RCC->AHB2ENR1 |= (1 << RCC_AHB2ENR1_GPIODEN_Pos);
    else if(port == GPIOE) RCC->AHB2ENR1 |= (1 << RCC_AHB2ENR1_GPIOEEN_Pos);
    else if(port == GPIOF) RCC->AHB2ENR1 |= (1 << RCC_AHB2ENR1_GPIOFEN_Pos);
    else if(port == GPIOG) RCC->AHB2ENR1 |= (1 << RCC_AHB2ENR1_GPIOGEN_Pos);
    else if(port == GPIOH) RCC->AHB2ENR1 |= (1 << RCC_AHB2ENR1_GPIOHEN_Pos);
    else if(port == GPIOI) RCC->AHB2ENR1 |= (1 << RCC_AHB2ENR1_GPIOIEN_Pos);

  // Set the pin direction and pull resistor mode
  if(!GpioPinMode(port, pin, pinMode)) return 0;
  if(!GpioSetPullReg(port, pin, pullMode)) return 0;

  return 1;
}

/**
 * @brief Set the direction mode for a gpio pin 
 * 
 * The gpio pin will be configured as an input/output
 * @param port gpio port
 * @param pin gpio pin
 * @param mode input/output mode
 * @return true/false value to indicate success of function 
*/
uint8_t GpioPinMode(GPIO_TypeDef *port, uint8_t pin, PinMode mode)
{
  // Check if pin is outside of bounds of a 32 bit register
  if (pin > 32) return 0;

  // Check if mode is out of range
  if ((mode > GPIO_INPUT_MODE) || (mode < GPIO_ANALOG_MODE)) return 0; 

  // Set mode of pin register
  port->MODER &= ~(mode << (pin*2));
  return 1;
}

/**
 * @brief Set the resistor pull direction
 * 
 * The gpio pin resistor will be configured to be pull up or pull down
 * @param port gpio port
 * @param pin gpio pin
 * @param mode pull up/down mode
 * @return true/false value to indicate success of function
*/
uint8_t GpioSetPullReg(GPIO_TypeDef *port, uint8_t pin, PullMode mode)
{
  // Check if provided pin is outside of maximum possible pins in a port
  if (pin >= MAX_GPIO_PORT_PINS) return 0;

  // Check if mode is out of range
  if ((mode > GPIO_NO_PULL) || (mode < GPIO_PULL_DOWN)) return 0; 

  // Assign pull mode to pull register
  port->PUPDR &= ~(mode << (pin*2));
  return 1;
}

/**
 * @brief Set the output value of the pin to high
 * 
 * The gpio pin output value will be set high or 1
 * @param port gpio port
 * @param pin gpio pin
 * @return true/false value to indicate success of function
*/
uint8_t GpioSetOutput(GPIO_TypeDef *port, uint8_t pin)
{
  // Check if provided pin is outside of maximum possible pins in a port
  if (pin >= MAX_GPIO_PORT_PINS) return 0;

  // Set data pin of port data register
  port->ODR |= (1 << pin);
  return 1;
}

/**
 * @brief Set the output value of the pin to low
 * 
 * The gpio pin output value will be cleared to low or 0
 * @param port gpio port
 * @param pin gpio pin
 * @return true/false value to indicate success of function
*/
uint8_t GpioClearOutput(GPIO_TypeDef *port, uint8_t pin)
{
  // Check if provided pin is outside of maximum possible pins in a port
  if (pin >= MAX_GPIO_PORT_PINS) return 0;

  // Clear data pin of port data register
  port->ODR &= ~(1 << pin);
  return 1;
}

/**
 * @brief Toggle the output value of the pin
 * 
 * The gpio pin output value will be toggled
 * @param port gpio port
 * @param pin gpio pin
 * @return true/false value to indicate success of function
*/
uint8_t GpioToggleOutput(GPIO_TypeDef *port, uint8_t pin)
{
  // Check if provided pin is outside of maximum possible pins in a port
  if (pin >= MAX_GPIO_PORT_PINS) return 0;

  // Toggle pin output value
  port->ODR ^= (1 << pin);
  return 1;
}