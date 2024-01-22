#include "bsp_timer.h"

uint8_t TimerBasicInitSec(TIM_TypeDef *timer, uint16_t msec)
{
    // Enable timer 6 RCC
    RCC->APB1ENR1 |= (1 << RCC_APB1ENR1_TIM6EN_Pos);
    // RCC->APB1ENR1 |= (1 << RCC_APB1ENR1_TIM7EN_Pos);

    // Set prescaler to max value 160M
    timer->PSC |= ~(uint16_t)(0);

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
