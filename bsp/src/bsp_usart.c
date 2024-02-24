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
 * The usart hardware and necessary gpio pins will be configured to support
 * the desired usart configuration.
 * @param usart usart
 * @param baudRate baud rate
 * @param dataBits number of data bits
 * @param stopBits number of stop bits
 * @return true/false value to indicate success of function
*/
uint8_t UsartInit(USART_TypeDef *usart, BaudRate baudRate, DataBits dataBits, StopBits stopBits)
{
  // Turn on usart/pin clock on and set tx/rx pins to alternative function mode
  if(usart == (USART_TypeDef *)USART1)
  {
    // Enable usart1/gpioa clocks
    RCC->APB2ENR  |= (1 << RCC_APB2ENR_USART1EN_Pos);
    RCC->AHB2ENR1 |= (1 << RCC_AHB2ENR1_GPIOAEN_Pos);
    GPIOA->MODER  &= ~(GPIO_MODER_MODE9_0 | GPIO_MODER_MODE10_0);

    // Set PA9 to TX and PA10 to RX
    GPIOA->AFR[1] |= (7 << GPIO_AFRH_AFSEL9_Pos);
    GPIOA->AFR[1] |= (7 << GPIO_AFRH_AFSEL10_Pos);
  } 
  else if(usart == (USART_TypeDef *)USART2)
  {
    // Enable usart2/gpiod clocks
    RCC->APB1ENR1 |= (1 << RCC_APB1ENR1_USART2EN_Pos);
    RCC->AHB2ENR1 |= (1 << RCC_AHB2ENR1_GPIODEN_Pos);
    GPIOD->MODER  &= ~(GPIO_MODER_MODE5_0 | GPIO_MODER_MODE6_0);

    // Set PD5 to TX and PD6 to RX
    GPIOD->AFR[0] |= (7 << GPIO_AFRL_AFSEL5_Pos);
    GPIOD->AFR[0] |= (7 << GPIO_AFRL_AFSEL6_Pos);
  }
  else if(usart == (USART_TypeDef *)USART3)
  {
    // Enable usart3/gpiob clocks
    RCC->APB1ENR1 |= (1 << RCC_APB1ENR1_USART3EN_Pos);
    RCC->AHB2ENR1 |= (1 << RCC_AHB2ENR1_GPIOBEN_Pos);
    GPIOB->MODER &= ~(GPIO_MODER_MODE10_0 | GPIO_MODER_MODE11_0);

    // Set PB10 to TX and PB11 to RX
    GPIOB->AFR[1] |= (7 << GPIO_AFRH_AFSEL10_Pos);
    GPIOB->AFR[1] |= (7 << GPIO_AFRH_AFSEL11_Pos);
  }
  else if(usart == (USART_TypeDef *)UART4)
  {
    // Enable uart4/gpioa clocks
    RCC->APB1ENR1 |= (1 << RCC_APB1ENR1_UART4EN_Pos);
    RCC->AHB2ENR1 |= (1 << RCC_AHB2ENR1_GPIOAEN_Pos);
    GPIOA->MODER &= ~(GPIO_MODER_MODE0_0 | GPIO_MODER_MODE1_0);

    // Set PA0 to TX and PA1 to RX
    GPIOA->AFR[1] |= (8 << GPIO_AFRL_AFSEL0_Pos);
    GPIOA->AFR[1] |= (8 << GPIO_AFRL_AFSEL1_Pos);
  }
  else if(usart == (USART_TypeDef *)UART5)
  {
    // Enable uart5/gpioc/gpiod clocks
    RCC->APB1ENR1 |= (1 << RCC_APB1ENR1_UART5EN_Pos);
    RCC->AHB2ENR1 |= (1 << RCC_AHB2ENR1_GPIOCEN_Pos);
    RCC->AHB2ENR1 |= (1 << RCC_AHB2ENR1_GPIODEN_Pos);
    GPIOC->MODER &= ~(GPIO_MODER_MODE12_0);
    GPIOD->MODER &= ~(GPIO_MODER_MODE2_0);

    // Set PC12 to TX and PD2 to RX
    GPIOC->AFR[1] |= (8 << GPIO_AFRH_AFSEL12_Pos);
    GPIOD->AFR[1] |= (8 << GPIO_AFRL_AFSEL2_Pos);
  }

  // Configure usart message format
  usart->CR1 |= (dataBits & USART_CR1_M_Msk);
  usart->CR2 |= (stopBits << USART_CR2_STOP_Pos);

  // Configure baud rate
  usart->BRR = baudRate;

  // Enable TX and RX 
  usart->CR1 |= (USART_CR1_RE) | (1 << USART_CR1_TE_Pos);

  // Turn on USART 
  usart->CR1 |= (USART_CR1_UE);

  return 1;
}

/**
 * @brief Send TX 
 * 
 * The USART will send char on its TX line
 * @param usart USART 
 * @param dataTX outgoing data buff
 * @return true/false value to indicate success of function
*/
uint8_t UsartTxChar(USART_TypeDef *usart, uint8_t *dataTX)
{
  // Wait until data register is empty
  while (!(usart->ISR & USART_ISR_TXE));

  // Write char to TX register
  usart->TDR = (*dataTX & USART_TDR_TDR);

  // Wait until transmission is complete
  while(!(usart->ISR & (USART_ISR_TC)));

  return 1;
}

/**
 * @brief Send TX buf
 * 
 * The USART will send buf on its tx line
 * @param usart USART 
 * @param dataTX outgoing data buff
 * @param dataLen size of outgoing data buff
 * @return true/false value to indicate success of function
*/
uint8_t UsartTxBuf(USART_TypeDef *usart, uint8_t *dataTX, uint32_t dataLen)
{
  // Loop through all data bytes
  uint8_t dataCount;
  for(dataCount = 0; dataCount < dataLen; dataCount++)
  {
    // Wait until data register is empty
    while (!(usart->ISR & USART_ISR_TXE));

    // Write char to TX register
    usart->TDR = dataTX[dataCount];
  }

  // Wait until transmission is complete
  while(!(usart->ISR & (USART_ISR_TC)));

  return 1;
}

/**
 * @brief Receive char 
 * 
 * The usart will receive char on its rx line
 * @param usart usart
 * @param dataRX incoming char 
 * @return true/false value to indicate success of function
*/
uint8_t UsartRxChar(USART_TypeDef *usart, uint8_t *dataRX)
{
  // Wait until all data has been shifted into RDR
  while(!(usart->ISR & USART_ISR_RXNE));

  // Transfer char in RDR into accessible variable
  *dataRX = (uint8_t)(usart->RDR & USART_RDR_RDR);

  return 1;
}