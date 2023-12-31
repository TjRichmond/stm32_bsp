// MIT License

// Copyright (c) 2023 Tristan Richmond

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

#ifndef _BSP_GPIO_H_
#define _BSP_GPIO_H_

#include "stm32u575xx.h"

#define MAX_GPIO_PORT_PINS (16)

// GPIO pin modes
typedef enum pinMode{
  GPIO_INPUT_MODE = 3,
  GPIO_OUTPUT_MODE = 2,
  GPIO_ALT_FUNC_MODE = 1,
  GPIO_ANALOG_MODE = 0
} PinMode;

// GPIO pin pull resistor register modes
typedef enum pullMode {
  GPIO_NO_PULL = 3,
  GPIO_PULL_UP = 2,
  GPIO_PULL_DOWN = 1
} PullMode;

// Init pin gpio
uint8_t GpioPinInit(GPIO_TypeDef *, uint8_t , PinMode , PullMode);

// Set pin mode
uint8_t GpioPinMode(GPIO_TypeDef *, uint8_t, PinMode);

// Set pin output value
uint8_t GpioSetOutput(GPIO_TypeDef *, uint8_t);

// Clear pin output value
uint8_t GpioClearOutput(GPIO_TypeDef *, uint8_t);

// Toggle pin output
uint8_t GpioToggleOutput(GPIO_TypeDef *, uint8_t);

// Set pull up/down resistor mode
uint8_t GpioSetPullReg(GPIO_TypeDef *, uint8_t, PullMode);

#endif