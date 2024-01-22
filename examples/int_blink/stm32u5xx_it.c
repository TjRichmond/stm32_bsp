#include "stm32u5xx_it.h"
#include "stm32u575xx.h"

void tim6_handler(void)
{
  // Clear the interrupt flag to reset interrupt
  TIM6->SR &= ~(TIM_SR_UIF);
}