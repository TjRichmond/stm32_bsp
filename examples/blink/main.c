#include <stdint.h>
#include "stm32u5xx.h"

#define LED_PIN 7

void clock_init();

void main(void)
{
  SystemInit();
  clock_init();
  SystemCoreClockUpdate();

  RCC->AHB2ENR1 |= (1 << RCC_AHB2ENR1_GPIOCEN_Pos);
  
  // do two dummy reads after enabling the peripheral clock, as per the errata
  volatile uint32_t dummy;
  dummy = RCC->AHB2ENR1;
  dummy = RCC->AHB2ENR1;

  GPIOC->MODER &= ~GPIO_MODER_MODE7_1;
  GPIOC->PUPDR |= GPIO_PUPDR_PUPD7_0;

  __enable_irq();
  
  while(1)
  {
    GPIOC->ODR ^= (1 << LED_PIN);
    for (uint32_t i = 0; i < 1000000; i++);
  }
}

void clock_init()
{
  /* By default HSI (4 MHz RC oscillator) is selected as system clock.
   * through the PLL to get 160 MHz system clock.
   */ 

  // Configure PLL dividers and multiplier
  /* Input to PLL should be 16 MHz. Choosing M=1 gives us 16 MHz
   * The output of the PLL should be 160 MHz, so setting the feedback
   * multiplier to 10 gives us 16 MHz * 10 = 160 MHz.
  */

  // Enable HSI osc
  RCC->CR |= RCC_CR_HSION;
  while(!(RCC->CR & RCC_CR_HSIRDY));

  // Enable power controller and dummy read once
  RCC->AHB3ENR |= RCC_AHB3ENR_PWREN;
  volatile uint32_t dummy;
  dummy = RCC->AHB3ENR;

  // Select HSI as PLL1 CLK src
  RCC->PLL1CFGR |= (2 << RCC_PLL1CFGR_PLL1SRC_Pos);

  // Set voltage scale mode 1
  PWR->VOSR |= (0b11 << PWR_VOSR_VOS_Pos);
  while(!(PWR->VOSR & PWR_VOSR_VOSRDY));

  // Set EPOD booster
  PWR->VOSR |= PWR_VOSR_BOOSTEN;
  while (!(PWR->VOSR & PWR_VOSR_BOOSTRDY));

  // Configure flash controller for 3V3 supply and 160 MHz -> 4 wait states
  FLASH->ACR |= FLASH_ACR_LATENCY_4WS | FLASH_ACR_PRFTEN;

  // Enable Instruction Cache
  ICACHE->CR |= ICACHE_CR_EN;

  // Enable Data Cache
  DCACHE1->CR |= DCACHE_CR_EN;

  // Clear and Set N multipler
  RCC->PLL1DIVR &= ~(RCC_PLL1DIVR_PLL1N_Msk);
  RCC->PLL1DIVR |= (19 << RCC_PLL1DIVR_PLL1N_Pos);

  // Set R clk output enable and input freq range
  RCC->PLL1CFGR |= RCC_PLL1CFGR_PLL1REN | (3 << RCC_PLL1CFGR_PLL1RGE_Pos);

  // Enable PLL and wait for ready
  RCC->CR |= RCC_CR_PLL1ON;
  while (!(RCC->CR & RCC_CR_PLL1RDY));
  
  // Select PLL output as system clock
  RCC->CFGR1 |= (3 << RCC_CFGR1_SW_Pos);
  while ((RCC->CFGR1 & RCC_CFGR1_SWS_Msk) != RCC_CFGR1_SWS_Msk);
}