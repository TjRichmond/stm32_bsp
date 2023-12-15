#include "bsp_timer.h"

uint8_t TimerBasicInit(TIM_TypeDef *timer, uint16_t period)
{
    RCC->APB1ENR1 |= (1 << RCC_APB1ENR1_TIM6EN_Pos);
    // RCC->APB1ENR1 |= (1 << RCC_APB1ENR1_TIM7EN_Pos);

    // TIM6->CR1 |= (dith_en << TIM_CR1_DITHEN_Pos);
    // TIM6->CR1 |= (arp_en << TIM_CR1_ARPE_Pos);
    // TIM6->CR1 |= (one_en << TIM_CR1_OPM_Pos);

    TIM6->DIER |= (1 << TIM_DIER_UIE_Pos);
    
    // Set prescaler
    
    // 160MHz
    // CLK_SRC/(pre + 1) = f_pre -> 1/T_pre
    // pre = CLK/f_pre - 1
    // pre = (CLK*T_pre) - 1

    // T_pre*cnt = T
    // cnt/f_pre = 1/f -> f = f_pre/cnt

    // f = (CLK*cnt)/(pre+1)
    // T = (160M*cnt)/(pre+1)
    // f = (159,999,999+1)/(160M*cnt) -> f = 1/cnt -> T = T_pre*cnt

    // Prescaler = 160Mhz -> 6.25us = 1/160,000,000 -> 6.25us*(count + 1) = T
    // T/6.25us - 1 = count
    // 0.00000000625*cnt = 1 -> 160,000,000
    // Counter = 160Million
    // 1 count = 6.25us, 4 counts = 25us, 16 counts = 100us

    uint16_t prescaler = 0;
    uint32_t count = 0;
    uint16_t counter = count + 1;
    uint32_t freq_pre = 160000000 / (prescaler + 1);

    counter = freq_pre * period;
    
    while(counter==0)
    {
        prescaler++;
        freq_pre = 160000000 / (prescaler + 1);
        counter = freq_pre * period;
    }

    TIM6->CR1 |= TIM_CR1_CEN;
}

uint8_t TimerBasicClkReset(TIM_TypeDef *timer)
{
    // Reset timer clock
    RCC->APB1RSTR1 |= (1 << RCC_APB1RSTR1_TIM6RST_Pos);
    // RCC->APB1RSTR1 |= (1 << RCC_APB1RSTR1_TIM7RST_Pos);
}