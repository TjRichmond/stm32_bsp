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
 * @file bsp_usart.c
 * @brief Module for using usart hardware
 * 
 * This module contains functions to configure and use the usart module 
 * for the STM32U575.
*/

#include "bsp_usart.h"

/**
 * @brief Initialize usart 
 * 
 * The uart will be initialized 
 * @param usart usart
 * @param baudRate baud rate
 * @param dataBits number of data bits
 * @param stopBits number of stop bits
 * @return true/false value to indicate success of function
*/
uint8_t UsartInit(USART_TypeDef *usart, BaudRate baudRate, DataBits dataBits, StopBits stopBits)
{
  // Turn on peripheral clock
  if(usart == (USART_TypeDef *)USART1) RCC->APB2ENR |= (1 << RCC_APB2ENR_USART1EN_Pos);
  else if(usart == (USART_TypeDef *)USART2) RCC->APB1ENR1 |= (1 << RCC_APB1ENR1_USART2EN_Pos);
  else if(usart == (USART_TypeDef *)USART3) RCC->APB1ENR1 |= (1 << RCC_APB1ENR1_USART3EN_Pos);
  else if(usart == (USART_TypeDef *)UART4) RCC->APB1ENR1 |= (1 << RCC_APB1ENR1_UART4EN_Pos);
  else if(usart == (USART_TypeDef *)UART5) RCC->APB1ENR1 |= (1 << RCC_APB1ENR1_UART5EN_Pos);

  // Configure usart message format
  usart->CR1 |= (dataBits & USART_CR1_M_Msk);
  usart->CR2 |= (stopBits << USART_CR2_STOP_Pos);

  // Configure baud rate
  usart->BRR = baudRate;


  // Turn on usart
  usart->CR1 |= (USART_CR1_UE);
}