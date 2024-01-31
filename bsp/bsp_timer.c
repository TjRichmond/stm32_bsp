#include "bsp_timer.h"

uint8_t TimerBasicInitMilSec(TIM_TypeDef *timer, uint16_t msec)
{
    // Set APB1 prescaler to /16 which makes timer 6/7 clk source 10MHz
    RCC->CFGR2 |= (7 << RCC_CFGR2_PPRE1_Pos);

    // Enable timer 6 RCC
    RCC->APB1ENR1 |= (1 << RCC_APB1ENR1_TIM6EN_Pos);
    // RCC->APB1ENR1 |= (1 << RCC_APB1ENR1_TIM7EN_Pos);

    // Set tim6 prescaler to 10k to make timer 6 counter equal to 1ms
    timer->PSC |= (uint16_t)(10000);

    // Set counter top value in milliseconds
    timer->ARR = (uint16_t)(msec);

    // Enable overflow interrupts
    timer->DIER |= (TIM_DIER_UIE);

    // Turn on timer
    timer->CR1 |= TIM_CR1_CEN;
    return 0;
}

uint8_t TimerBasicClkReset(TIM_TypeDef *timer)
{
    // Reset timer clock
    RCC->APB1RSTR1 |= (1 << RCC_APB1RSTR1_TIM6RST_Pos);
    // RCC->APB2RSTR1 |= (1 << RCC_APB1RSTR1_TIM7RST_Pos);
    return 1;
}
