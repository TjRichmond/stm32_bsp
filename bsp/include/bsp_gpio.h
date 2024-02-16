// MIT License

// Copyright (c) 2024 Tristan Richmond

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

/**
 * @file bsp_gpio.h
 * @brief Header for using gpio pins
 * 
 * This header contains functions to control gpio pins hardware for
 * the STM32U575. These functions include initializing, reading, and
 * write values to the GPIO pins.
*/

#ifndef _BSP_GPIO_H_
#define _BSP_GPIO_H_

#include "stm32u575xx.h"

#define MAX_GPIO_PORT_PINS (16)

/**
 * @brief Enumeration representing supported gpio pin modes
 * 
 * The STM32U575 supports up to 4 modes that determines how the
 * pin behaves.
 * - Input mode will receive digital signals
 * - Ouput mode will transmit digital signals
 * - Alternative function mode will behave as a different hardware controller
 * - Analog mode will remain floating and not engage with core
*/
typedef enum pinMode{
  /** @brief Input mode*/
  GPIO_INPUT_MODE = 3,
  
  /** @brief Output mode*/
  GPIO_OUTPUT_MODE = 2,

  /** @brief Alternate function mode*/
  GPIO_ALT_FUNC_MODE = 1,

  /** @brief Analog/floating mode*/
  GPIO_ANALOG_MODE = 0
} PinMode;

/**
 * @brief Enumeration representing supported gpio resistor pull directions
 * 
 * The STM32U575 supports up to 3 modes that determines how the
 * pin behaves.
 * - No pull mode will default the pin to floating 
 * - Pull up mode will default the pin to logic high
 * - Pull down mode will default the pin to logic low
*/
typedef enum pullMode {
  /** @brief No pull mode*/
  GPIO_NO_PULL = 3,

  /** @brief Pull up resistor mode*/
  GPIO_PULL_UP = 2,

  /** @brief Pull down resistor mode*/
  GPIO_PULL_DOWN = 1
} PullMode;

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
uint8_t GpioPinInit(GPIO_TypeDef *, uint8_t , PinMode , PullMode);

/**
 * @brief Set the direction mode for a gpio pin 
 * 
 * The gpio pin will be configured as an input/output
 * @param port gpio port
 * @param pin gpio pin
 * @param mode input/output mode
 * @return true/false value to indicate success of function 
*/
uint8_t GpioPinMode(GPIO_TypeDef *, uint8_t, PinMode);

/**
 * @brief Set the resistor pull direction
 * 
 * The gpio pin resistor will be configured to be pull up or pull down
 * @param port gpio port
 * @param pin gpio pin
 * @param mode pull up/down mode
 * @return true/false value to indicate success of function
*/
uint8_t GpioSetOutput(GPIO_TypeDef *, uint8_t);

/**
 * @brief Set the output value of the pin to high
 * 
 * The gpio pin output value will be set high or 1
 * @param port gpio port
 * @param pin gpio pin
 * @return true/false value to indicate success of function
*/
uint8_t GpioClearOutput(GPIO_TypeDef *, uint8_t);

/**
 * @brief Set the output value of the pin to low
 * 
 * The gpio pin output value will be cleared to low or 0
 * @param port gpio port
 * @param pin gpio pin
 * @return true/false value to indicate success of function
*/
uint8_t GpioToggleOutput(GPIO_TypeDef *, uint8_t);

/**
 * @brief Toggle the output value of the pin
 * 
 * The gpio pin output value will be toggled
 * @param port gpio port
 * @param pin gpio pin
 * @return true/false value to indicate success of function
*/
uint8_t GpioSetPullReg(GPIO_TypeDef *, uint8_t, PullMode);

#endif