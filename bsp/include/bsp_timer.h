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

#ifndef _BSP_TIMER_H_
#define _BSP_TIMER_H_

#include "stm32u575xx.h"

// Timer Enable RCC_APB1ENR1
// Timer Reset RCC_APB2RSTR
// Timer Reset RCC_APB1RSTR1
// Timer Sleep Stop RCC_APB1MENR1
// Timer Sleep Stop RCC_APB2SMENR

// TIM6/7 Basic Timers ~ x = Timer Number
// Control Register TIMx_CR1
// Control Register for mode (Reset, Enable, Update) TIMx_CR2 
// Prescalar for speed TIMx_PSC
// Status Register TIMx_SR
// Update Generation TIMxEGR
// Auto Reload Register [15:0] TIMx_ARR
// Counter TIMx_CNT
// Auto reload register TIMx_ARR

uint8_t TimerBasicInit(TIM_TypeDef *);

uint8_t TimerBasicClkReset(TIM_TypeDef *);

#endif