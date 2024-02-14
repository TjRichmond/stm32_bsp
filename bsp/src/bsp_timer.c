/**
 * @file bsp_timer.c
 * @brief module for controlling mcu timer hardware
 * 
 * This module contains functions to configure and reset timers
*/
#include "bsp_timer.h"

/**
 * @brief Initialize a basic microsecond timer
 * 
 * The basic timer will be configured to count in microseconds
 * @param timer timer
 * @param usec number of microseconds
 * @return true/false value to indicate success of function
*/
uint8_t TimerBasicInitMicroSec(TIM_TypeDef *timer, uint16_t usec)
{
  // Enable timer 6 RCC
  RCC->APB1ENR1 |= (1 << RCC_APB1ENR1_TIM6EN_Pos);

  // Set timer 6 prescaler to 80 to make timer 6 counter equal to 1us
  timer->PSC |= (uint16_t)(80);

  // Set counter top value in microseconds
  timer->ARR = (uint16_t)(usec);

  // Enable overflow interrupts
  timer->DIER |= (TIM_DIER_UIE);

  // Turn on timer
  timer->CR1 |= (TIM_CR1_CEN);

  return 1;
}

/**
 * @brief Initialize a basic millisecond timer
 * 
 * The basic timer will be configured to count in milliseconds
 * @param timer timer
 * @param msec number of milliseconds
 * @return true/false value to indicate success of function
*/
uint8_t TimerBasicInitMilliSec(TIM_TypeDef *timer, uint16_t msec)
{
  // Set APB1 prescaler to /16 which makes timer 6/7 clk source 10MHz
  RCC->CFGR2 |= (7 << RCC_CFGR2_PPRE1_Pos);

  // Enable timer 6 RCC
  RCC->APB1ENR1 |= (1 << RCC_APB1ENR1_TIM6EN_Pos);
  // RCC->APB1ENR1 |= (1 << RCC_APB1ENR1_TIM7EN_Pos);

  // Set timer 6 prescaler to 10k to make timer 6 counter equal to 1ms
  timer->PSC |= (uint16_t)(10000);

  // Set counter top value in milliseconds
  timer->ARR = (uint16_t)(msec);

  // Enable overflow interrupts
  timer->DIER |= (TIM_DIER_UIE);

  // Turn on timer
  timer->CR1 |= (TIM_CR1_CEN);

  return 1;
}

/**
 * @brief Initialize a basic second timer
 * 
 * The basic timer will be configured to count in seconds
 * @param timer timer
 * @param sec number of seconds
 * @return true/false value to indicate success of function
*/
uint8_t TimerBasicInitSec(TIM_TypeDef *timer, uint16_t sec)
{
  // Set AHB Prescaler to /128 which makes system clk 1.25MHz
  RCC->CFGR2 |= (13 << RCC_CFGR2_HPRE_Pos);

  // Set APB1 prescaler to /16 which makes timer 6/7 clk source 78.125kHz
  RCC->CFGR2 |= (7 << RCC_CFGR2_PPRE1_Pos);

  // Enable timer 6 RCC
  RCC->APB1ENR1 |= (1 << RCC_APB1ENR1_TIM6EN_Pos);

  // Set timer 6 prescaler to 39063 to make timer 6 counter equal to 1s
  timer->PSC |= (uint16_t)(39063);

  // Set counter top value in seconds
  timer->ARR = (uint16_t)(sec);

  // Enable overflow interrupts
  timer->DIER |= (TIM_DIER_UIE);

  // Turn on timer
  timer->CR1 |= (TIM_CR1_CEN);

  return 1;
}

/**
 * @brief Reset a basic timer 
 * 
 * The basic timer will be reset its counter to 0 
 * @param timer timer
 * @return true/false value to indicate success of function
*/
uint8_t TimerBasicClkReset(TIM_TypeDef *timer)
{
  // Reset timer clock
  RCC->APB1RSTR1 |= (1 << RCC_APB1RSTR1_TIM6RST_Pos);
  // RCC->APB2RSTR1 |= (1 << RCC_APB1RSTR1_TIM7RST_Pos);
  
  return 1;
}