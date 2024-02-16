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
 * @file bsp_timer.h
 * @brief Module for using basic hardware timer
 * 
 * This header contains functions to control 1 of 2 basic hardware timers
 * for the STM32U575. These functions include initializing and reseting the 
 * timers.
*/

#ifndef _BSP_TIMER_H_
#define _BSP_TIMER_H_

#include "stm32u575xx.h"

/**
 * @brief Initialize a basic microsecond timer
 * 
 * The basic timer will be configured to count in microseconds
 * @param timer timer
 * @param usec number of microseconds
 * @return true/false value to indicate success of function
*/
uint8_t TimerBasicInitMicroSec(TIM_TypeDef *, uint16_t);

/**
 * @brief Initialize a basic millisecond timer
 * 
 * The basic timer will be configured to count in milliseconds
 * @param timer timer
 * @param msec number of milliseconds
 * @return true/false value to indicate success of function
*/
uint8_t TimerBasicInitMilliSec(TIM_TypeDef *, uint16_t);

/**
 * @brief Initialize a basic second timer
 * 
 * The basic timer will be configured to count in seconds
 * @param timer timer
 * @param sec number of seconds
 * @return true/false value to indicate success of function
*/
uint8_t TimerBasicInitSec(TIM_TypeDef *, uint16_t);

/**
 * @brief Reset a basic timer 
 * 
 * The basic timer will be reset its counter to 0 
 * @param timer timer
 * @return true/false value to indicate success of function
*/
uint8_t TimerBasicClkReset(TIM_TypeDef *);

#endif