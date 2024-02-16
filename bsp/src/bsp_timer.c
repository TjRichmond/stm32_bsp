/**
 * @file bsp_timer.c
 * @brief module for controlling mcu basic timer hardware
 * 
 * This module contains functions to configure and reset basic timers
*/
#include "bsp_timer.h"

/**
 * @brief Initialize basic timer registers
 * 
 * The basic timer will have its registers initializated except for time base
 * @param timer timer
 * @param duration undefined base unit time duration
 * @return true/false value to indicate success of function
*/
static uint8_t TimerBasicInit(TIM_TypeDef *timer, uint16_t duration)
{
  // Enable timer RCC based on supplied timer number
  if (timer == (TIM_TypeDef *)TIM6) RCC->APB1ENR1 |= (1 << RCC_APB1ENR1_TIM6EN_Pos);
  if (timer == (TIM_TypeDef *)TIM7) RCC->APB1ENR1 |= (1 << RCC_APB1ENR1_TIM7EN_Pos);

  // Enable overflow interrupts
  timer->DIER |= (TIM_DIER_UIE);

  // Set counter top value in microseconds
  timer->ARR = (uint16_t)(duration);

  // Turn on timer
  timer->CR1 |= (TIM_CR1_CEN);

  return 1;
}

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
  // Set timer 6 prescaler to 80 to make timer 6 counter equal to 1us
  timer->PSC |= (uint16_t)(80);

  // Initialize timer registers and start timer
  if(!TimerBasicInit(timer, usec))  return 0;

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

  // Set timer 6 prescaler to 10k to make timer 6 counter equal to 1ms
  timer->PSC |= (uint16_t)(10000);
  
  // Initialize timer registers and start timer
  if(!TimerBasicInit(timer, msec))  return 0;

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

  // Set timer 6 prescaler to 39063 to make timer 6 counter equal to 1s
  timer->PSC |= (uint16_t)(39063);

  // Initialize timer registers and start timer
  if(!TimerBasicInit(timer, sec))  return 0;

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
  RCC->APB1RSTR1 |= (1 << RCC_APB1RSTR1_TIM7RST_Pos);
  
  return 1;
}