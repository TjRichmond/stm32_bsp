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
 * @file bsp_uart.h
 * @brief Module for using usart hardware
 * 
 * This header contains functions to configure and use the uart module 
 * for the STM32U575.
*/

#ifndef _BSP_USART_H_
#define _BSP_USART_H_

#include "stm32u575xx.h"

/**
 * @brief Enumeration representing data word length in usart messages 
 * 
 * The STM32U575 supports up to 3 modes for usart word length 
 * - 1 start, 8 data, n stop
 * - 1 start, 9 data, n stop
 * - 1 start, 7 data, n stop 
*/
typedef enum dataBits{
  /** @brief 8 bits*/
  USART_8DATA_BITS = 0x00000000,

  /** @brief 9 bits*/
  USART_9DATA_BITS = 0x00001000,

  /** @brief 7 bits*/
  USART_7DATA_BITS = 0x10001000
} DataBits;

/**
 * @brief Enumeration representing data word length in usart messages 
 * 
 * The STM32U575 supports up to 3 modes for usart word length 
 * - 1 start, 8 data, n stop
 * - 1 start, 9 data, n stop
 * - 1 start, 7 data, n stop 
*/
typedef enum stopBits{
  /** @brief 1 bit*/
  USART_1STOP_BITS = 0,

  /** @brief 0.5 bit*/
  USART_0_5STOP_BITS = 1,

  /** @brief 2 bits*/
  USART_2STOP_BITS = 2,

  /** @brief 1.5 bits*/
  USART_1_5STOP_BITS = 3
} StopBits;

/**
 * @brief Enumeration representing supported baud rates 
 * 
 * Baud rate register = systemclk/(desired baud)
 * The supports the following baud rates 
 * - 9600
 * - 115200
 * - 230400
*/
typedef enum baudRate{
  /** @brief 9600*/
  USART_9600_BAUD = 0x411A,

  /** @brief 115200*/
  USART_115200_BAUD = 0x056C,

  /** @brief 230400*/
  USART_230400_BAUD = 0x2B6
} BaudRate;

/**
 * @brief Initialize usart 
 * 
 * The usart hardware and necessary gpio pins will be configured to support
 * the desired usart configuration.
 * @param usart usart
 * @param baudRate baud rate
 * @param dataBits number of data bits
 * @param stopBits number of stop bits
 * @return true/false value to indicate success of function
*/
uint8_t UsartInit(USART_TypeDef *usart, BaudRate baudRate, DataBits dataBits, StopBits stopBits);


/**
 * @brief Send tx
 * 
 * The usart will send data on its tx line
 * @param usart usart
 * @param dataTX outgoing data buff
 * @return true/false value to indicate success of function
*/
uint8_t UsartSendChar(USART_TypeDef *usart, uint8_t *dataTX);

#endif