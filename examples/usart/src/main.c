#include <stdint.h>

#include "stm32u5xx.h"
#include "bsp_usart.h"
#include "bsp_gpio.h"

#define LED_PIN (7)

void clock_init();

void main(void)
{
  // Boiler plate initialization functions
  SystemInit();
  clock_init();
  SystemCoreClockUpdate();

  // Initialize LED
  GpioPinInit(GPIOC, LED_PIN, GPIO_OUTPUT_MODE, GPIO_PULL_UP);
  
  UsartInit(USART2, USART_9600_BAUD, USART_8DATA_BITS, USART_1STOP_BITS);

  uint8_t data_buf[] = {0,1,2,3,4};
    
  while(1)
  {
    // Toggle led and send the inverse of the received byte
    GpioToggleOutput(GPIOC, LED_PIN);
    // UsartRxChar(USART2, &data_buf);
    // data_buf = ~data_buf;
    UsartTxBuf(USART2, data_buf, 5);
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
  ATOMIC_SET_BIT(RCC->CR, RCC_CR_HSION);
  while(!READ_BIT(RCC->CR, RCC_CR_HSIRDY));

  // Enable power controller and dummy read once
  ATOMIC_SET_BIT(RCC->AHB3ENR, RCC_AHB3ENR_PWREN);
  volatile uint32_t dummy;
  dummy = RCC->AHB3ENR;

  // Select HSI as PLL1 CLK src
  ATOMIC_SET_BIT(RCC->PLL1CFGR, RCC_PLL1CFGR_PLL1SRC_1);

  // Set voltage scale mode 1
  ATOMIC_SET_BIT(PWR->VOSR, PWR_VOSR_VOS);
  while(!(READ_BIT(PWR->VOSR, PWR_VOSR_VOSRDY)));

  // Set EPOD booster
  ATOMIC_SET_BIT(PWR->VOSR, PWR_VOSR_BOOSTEN);
  while(!(READ_BIT(PWR->VOSR, PWR_VOSR_BOOSTRDY)));

  // Configure flash controller for 3V3 supply and 160 MHz -> 4 wait states
  ATOMIC_SET_BIT(FLASH->ACR, FLASH_ACR_LATENCY_4WS);
  ATOMIC_SET_BIT(FLASH->ACR, FLASH_ACR_PRFTEN);

  // Enable Instruction Cache
  ATOMIC_SET_BIT(ICACHE->CR, ICACHE_CR_EN);

  // Enable Data Cache
  ATOMIC_SET_BIT(DCACHE1->CR, DCACHE_CR_EN);

  // Clear and Set N multipler
  ATOMIC_CLEAR_BIT(RCC->PLL1DIVR,RCC_PLL1DIVR_PLL1N_Msk);
  ATOMIC_MODIFY_REG(RCC->PLL1DIVR, 0, 19);

  // Set R clk output enable and input freq range
  ATOMIC_SET_BIT(RCC->PLL1CFGR, RCC_PLL1CFGR_PLL1REN);
  ATOMIC_SET_BIT(RCC->PLL1CFGR, RCC_PLL1CFGR_PLL1RGE_Msk);

  // Enable PLL and wait for ready
  ATOMIC_SET_BIT(RCC->CR, RCC_CR_PLL1ON);
  while(!(READ_BIT(RCC->CR, RCC_CR_PLL1RDY)));
  
  // Select PLL output as system clock
  ATOMIC_SET_BIT(RCC->CFGR1, RCC_CFGR1_SW_Msk);
  while((READ_BIT(RCC->CFGR1, RCC_CFGR1_SWS_Msk)) != RCC_CFGR1_SWS_Msk);
}