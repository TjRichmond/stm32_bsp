#include <stdint.h>

#define SRAM_START (0x20000000U)
#define SRAM_SIZE (32U * 1024U)
#define SRAM_END (SRAM_START + SRAM_SIZE)
#define STACK_POINTER_INIT_ADDRESS (SRAM_END)
#define ISR_VECTOR_SIZE_WORDS 156

void reset_handler(void);
void default_handler(void);

void nmi_handler(void) __attribute__((weak, alias("default_handler")));
void hard_fault_handler(void) __attribute__((weak, alias("default_handler")));
void mem_manage_handler(void) __attribute__((weak, alias("default_handler")));
void bus_fault_handler(void) __attribute__((weak, alias("default_handler")));
void usage_fault_handler(void) __attribute__((weak, alias("default_handler")));
void secure_fault_handler(void) __attribute__((weak, alias("default_handler")));
void svcall_handler(void) __attribute__((weak, alias("default_handler")));
void debug_monitor_handler(void) __attribute__((weak, alias("default_handler")));
void pendsv_handler(void) __attribute__((weak, alias("default_handler")));
void systick_handler(void) __attribute__((weak, alias("default_handler")));

//STM32U575 interrupt handlers
void wwdg_handler(void) __attribute__((weak, alias("default_handler")));
void pvd_handler(void) __attribute__((weak, alias("default_handler")));
void rtc_handler(void) __attribute__((weak, alias("default_handler")));
void rtc_s_handler(void) __attribute__((weak, alias("default_handler")));
void tamp_handler(void) __attribute__((weak, alias("default_handler")));
void ramcfg_handler(void) __attribute__((weak, alias("default_handler")));
void flash_handler(void) __attribute__((weak, alias("default_handler")));
void flash_s_handler(void) __attribute__((weak, alias("default_handler")));
void gtzc_handler(void) __attribute__((weak, alias("default_handler")));
void rcc_handler(void) __attribute__((weak, alias("default_handler")));
void rcc_s_handler(void) __attribute__((weak, alias("default_handler")));
void exti0_handler(void) __attribute__((weak, alias("default_handler")));
void exti1_handler(void) __attribute__((weak, alias("default_handler")));
void exti2_handler(void) __attribute__((weak, alias("default_handler")));
void exti3_handler(void) __attribute__((weak, alias("default_handler")));
void exti4_handler(void) __attribute__((weak, alias("default_handler")));
void exti5_handler(void) __attribute__((weak, alias("default_handler")));
void exti6_handler(void) __attribute__((weak, alias("default_handler")));
void exti7_handler(void) __attribute__((weak, alias("default_handler")));
void exti8_handler(void) __attribute__((weak, alias("default_handler")));
void exti9_handler(void) __attribute__((weak, alias("default_handler")));
void exti10_handler(void) __attribute__((weak, alias("default_handler")));
void exti11_handler(void) __attribute__((weak, alias("default_handler")));
void exti12_handler(void) __attribute__((weak, alias("default_handler")));
void exti13_handler(void) __attribute__((weak, alias("default_handler")));
void exti14_handler(void) __attribute__((weak, alias("default_handler")));
void exti15_handler(void) __attribute__((weak, alias("default_handler")));
void iwdg_handler(void) __attribute__((weak, alias("default_handler")));
void gpdma1_channel0_handler(void) __attribute__((weak, alias("default_handler")));
void gpdma1_channel1_handler(void) __attribute__((weak, alias("default_handler")));
void gpdma1_channel2_handler(void) __attribute__((weak, alias("default_handler")));
void gpdma1_channel3_handler(void) __attribute__((weak, alias("default_handler")));
void gpdma1_channel4_handler(void) __attribute__((weak, alias("default_handler")));
void gpdma1_channel5_handler(void) __attribute__((weak, alias("default_handler")));
void gpdma1_channel6_handler(void) __attribute__((weak, alias("default_handler")));
void gpdma1_channel7_handler(void) __attribute__((weak, alias("default_handler")));
void adc1_handler(void) __attribute__((weak, alias("default_handler")));
void dac1_handler(void) __attribute__((weak, alias("default_handler")));
void fdcan1_it0_handler(void) __attribute__((weak, alias("default_handler")));
void fdcan1_it1_handler(void) __attribute__((weak, alias("default_handler")));
void tim1_brk_handler(void) __attribute__((weak, alias("default_handler")));
void tim1_up_handler(void) __attribute__((weak, alias("default_handler")));
void tim1_trg_com_handler(void) __attribute__((weak, alias("default_handler")));
void tim1_cc_handler(void) __attribute__((weak, alias("default_handler")));
void tim2_handler(void) __attribute__((weak, alias("default_handler")));
void tim3_handler(void) __attribute__((weak, alias("default_handler")));
void tim4_handler(void) __attribute__((weak, alias("default_handler")));
void tim5_handler(void) __attribute__((weak, alias("default_handler")));
void tim6_handler(void) __attribute__((weak, alias("default_handler")));
void tim7_handler(void) __attribute__((weak, alias("default_handler")));
void tim8_brk_handler(void) __attribute__((weak, alias("default_handler")));
void tim8_up_handler(void) __attribute__((weak, alias("default_handler")));
void tim8_trg_com_handler(void) __attribute__((weak, alias("default_handler")));
void tim8_cc_handler(void) __attribute__((weak, alias("default_handler")));
void i2c1_ev_handler(void) __attribute__((weak, alias("default_handler")));
void i2c1_er_handler(void) __attribute__((weak, alias("default_handler")));
void i2c2_ev_handler(void) __attribute__((weak, alias("default_handler")));
void i2c2_er_handler(void) __attribute__((weak, alias("default_handler")));
void spi1_handler(void) __attribute__((weak, alias("default_handler")));
void spi2_handler(void) __attribute__((weak, alias("default_handler")));
void usart1_handler(void) __attribute__((weak, alias("default_handler")));
void usart2_handler(void) __attribute__((weak, alias("default_handler")));
void usart3_handler(void) __attribute__((weak, alias("default_handler")));
void uart4_handler(void) __attribute__((weak, alias("default_handler")));
void uart5_handler(void) __attribute__((weak, alias("default_handler")));
void lpuart1_handler(void) __attribute__((weak, alias("default_handler")));
void lptim1_handler(void) __attribute__((weak, alias("default_handler")));
void lptim2_handler(void) __attribute__((weak, alias("default_handler")));
void tim15_handler(void) __attribute__((weak, alias("default_handler")));
void tim16_handler(void) __attribute__((weak, alias("default_handler")));
void tim17_handler(void) __attribute__((weak, alias("default_handler")));
void comp_handler(void) __attribute__((weak, alias("default_handler")));
void otg_fs_handler(void) __attribute__((weak, alias("default_handler")));
void crs_handler(void) __attribute__((weak, alias("default_handler")));
void fmc_handler(void) __attribute__((weak, alias("default_handler")));
void octospi1_handler(void) __attribute__((weak, alias("default_handler")));
void pwr_s3wu_handler(void) __attribute__((weak, alias("default_handler")));
void sdmmc1_handler(void) __attribute__((weak, alias("default_handler")));
void sdmmc2_handler(void) __attribute__((weak, alias("default_handler")));
void gpdma1_channel8_handler(void) __attribute__((weak, alias("default_handler")));
void gpdma1_channel9_handler(void) __attribute__((weak, alias("default_handler")));
void gpdma1_channel10_handler(void) __attribute__((weak, alias("default_handler")));
void gpdma1_channel11_handler(void) __attribute__((weak, alias("default_handler")));
void gpdma1_channel12_handler(void) __attribute__((weak, alias("default_handler")));
void gpdma1_channel13_handler(void) __attribute__((weak, alias("default_handler")));
void gpdma1_channel14_handler(void) __attribute__((weak, alias("default_handler")));
void gpdma1_channel15_handler(void) __attribute__((weak, alias("default_handler")));
void i2c3_ev_handler(void) __attribute__((weak, alias("default_handler")));
void i2c3_er_handler(void) __attribute__((weak, alias("default_handler")));
void sai1_handler(void) __attribute__((weak, alias("default_handler")));
void sai2_handler(void) __attribute__((weak, alias("default_handler")));
void tsc_handler(void) __attribute__((weak, alias("default_handler")));
void rng_handler(void) __attribute__((weak, alias("default_handler")));
void fpu_handler(void) __attribute__((weak, alias("default_handler")));
void hash_handler(void) __attribute__((weak, alias("default_handler")));
void lptim3_handler(void) __attribute__((weak, alias("default_handler")));
void spi3_handler(void) __attribute__((weak, alias("default_handler")));
void i2c4_ev_handler(void) __attribute__((weak, alias("default_handler")));
void i2c4_er_handler(void) __attribute__((weak, alias("default_handler")));
void mdf1_flt0_handler(void) __attribute__((weak, alias("default_handler")));
void mdf1_flt1_handler(void) __attribute__((weak, alias("default_handler")));
void mdf1_flt2_handler(void) __attribute__((weak, alias("default_handler")));
void mdf1_flt3_handler(void) __attribute__((weak, alias("default_handler")));
void ucpd1_handler(void) __attribute__((weak, alias("default_handler")));
void icache_handler(void) __attribute__((weak, alias("default_handler")));
void lptim4_handler(void) __attribute__((weak, alias("default_handler")));
void dcache1_handler(void) __attribute__((weak, alias("default_handler")));
void adf1_handler(void) __attribute__((weak, alias("default_handler")));
void adc4_handler(void) __attribute__((weak, alias("default_handler")));
void lpdma1_channel0_handler(void) __attribute__((weak, alias("default_handler")));
void lpdma1_channel1_handler(void) __attribute__((weak, alias("default_handler")));
void lpdma1_channel2_handler(void) __attribute__((weak, alias("default_handler")));
void lpdma1_channel3_handler(void) __attribute__((weak, alias("default_handler")));
void dma2d_handler(void) __attribute__((weak, alias("default_handler")));
void dcmi_pssi_handler(void) __attribute__((weak, alias("default_handler")));
void octospi2_handler(void) __attribute__((weak, alias("default_handler")));
void mdf1_flt4_handler(void) __attribute__((weak, alias("default_handler")));
void mdf1_flt5_handler(void) __attribute__((weak, alias("default_handler")));
void cordic_handler(void) __attribute__((weak, alias("default_handler")));
void fmac_handler(void) __attribute__((weak, alias("default_handler")));
void lsecssd_handler(void) __attribute__((weak, alias("default_handler")));


uint32_t isr_vector[ISR_VECTOR_SIZE_WORDS] __attribute__((section(".isr_vector"))) = {
  STACK_POINTER_INIT_ADDRESS,
  (uint32_t)&reset_handler,
  (uint32_t)&nmi_handler,
  (uint32_t)&hard_fault_handler,
  (uint32_t)&mem_manage_handler,
  (uint32_t)&bus_fault_handler,
  (uint32_t)&usage_fault_handler,
  (uint32_t)&secure_fault_handler,
  0,
  0,
  0,
  (uint32_t)&svcall_handler,
  (uint32_t)&debug_monitor_handler,
  0,
  (uint32_t)&pendsv_handler,
  (uint32_t)&systick_handler,
  (uint32_t)&wwdg_handler,
  (uint32_t)&pvd_handler,
  (uint32_t)&rtc_handler,
  (uint32_t)&rtc_s_handler,
  (uint32_t)&tamp_handler,
  (uint32_t)&ramcfg_handler,
  (uint32_t)&flash_handler,
  (uint32_t)&flash_s_handler,
  (uint32_t)&gtzc_handler,
  (uint32_t)&rcc_handler,
  (uint32_t)&rcc_s_handler,
  (uint32_t)&exti0_handler,
  (uint32_t)&exti1_handler,
  (uint32_t)&exti2_handler,
  (uint32_t)&exti3_handler,
  (uint32_t)&exti4_handler,
  (uint32_t)&exti5_handler,
  (uint32_t)&exti6_handler,
  (uint32_t)&exti7_handler,
  (uint32_t)&exti8_handler,
  (uint32_t)&exti9_handler,
  (uint32_t)&exti10_handler,
  (uint32_t)&exti11_handler,
  (uint32_t)&exti12_handler,
  (uint32_t)&exti13_handler,
  (uint32_t)&exti14_handler,
  (uint32_t)&exti15_handler,
  (uint32_t)&iwdg_handler,
  0,
  (uint32_t)&gpdma1_channel0_handler,
  (uint32_t)&gpdma1_channel1_handler,
  (uint32_t)&gpdma1_channel2_handler,
  (uint32_t)&gpdma1_channel3_handler,
  (uint32_t)&gpdma1_channel4_handler,
  (uint32_t)&gpdma1_channel5_handler,
  (uint32_t)&gpdma1_channel6_handler,
  (uint32_t)&gpdma1_channel7_handler,
  (uint32_t)&adc1_handler,
  (uint32_t)&dac1_handler,
  (uint32_t)&fdcan1_it0_handler,
  (uint32_t)&fdcan1_it1_handler,
  (uint32_t)&tim1_brk_handler,
  (uint32_t)&tim1_up_handler,
  (uint32_t)&tim1_trg_com_handler,
  (uint32_t)&tim1_cc_handler,
  (uint32_t)&tim2_handler,
  (uint32_t)&tim3_handler,
  (uint32_t)&tim4_handler,
  (uint32_t)&tim5_handler,
  (uint32_t)&tim6_handler,
  (uint32_t)&tim7_handler,
  (uint32_t)&tim8_brk_handler,
  (uint32_t)&tim8_up_handler,
  (uint32_t)&tim8_trg_com_handler,
  (uint32_t)&tim8_cc_handler,
  (uint32_t)&i2c1_ev_handler,
  (uint32_t)&i2c1_er_handler,
  (uint32_t)&i2c2_ev_handler,
  (uint32_t)&i2c2_er_handler,
  (uint32_t)&spi1_handler,
  (uint32_t)&spi2_handler,
  (uint32_t)&usart1_handler,
  (uint32_t)&usart2_handler,
  (uint32_t)&usart3_handler,
  (uint32_t)&uart4_handler,
  (uint32_t)&uart5_handler,
  (uint32_t)&lpuart1_handler,
  (uint32_t)&lptim1_handler,
  (uint32_t)&lptim2_handler,
  (uint32_t)&tim15_handler,
  (uint32_t)&tim16_handler,
  (uint32_t)&tim17_handler,
  (uint32_t)&comp_handler,
  (uint32_t)&otg_fs_handler,
  (uint32_t)&crs_handler,
  (uint32_t)&fmc_handler,
  (uint32_t)&octospi1_handler,
  (uint32_t)&pwr_s3wu_handler,
  (uint32_t)&sdmmc1_handler,
  (uint32_t)&sdmmc2_handler,
  (uint32_t)&gpdma1_channel8_handler,
  (uint32_t)&gpdma1_channel9_handler,
  (uint32_t)&gpdma1_channel10_handler,
  (uint32_t)&gpdma1_channel11_handler,
  (uint32_t)&gpdma1_channel12_handler,
  (uint32_t)&gpdma1_channel13_handler,
  (uint32_t)&gpdma1_channel14_handler,
  (uint32_t)&gpdma1_channel15_handler,
  (uint32_t)&i2c3_ev_handler,
  (uint32_t)&i2c3_er_handler,
  (uint32_t)&sai1_handler,
  (uint32_t)&sai2_handler,
  (uint32_t)&tsc_handler,
  0,
  (uint32_t)&rng_handler,
  (uint32_t)&fpu_handler,
  (uint32_t)&hash_handler,
  0,
  (uint32_t)&lptim3_handler,
  (uint32_t)&spi3_handler,
  (uint32_t)&i2c4_er_handler,
  (uint32_t)&i2c4_ev_handler,
  (uint32_t)&mdf1_flt0_handler,
  (uint32_t)&mdf1_flt1_handler,
  (uint32_t)&mdf1_flt2_handler,
  (uint32_t)&mdf1_flt3_handler,
  (uint32_t)&ucpd1_handler,
  (uint32_t)&icache_handler,
  0,
  0,
  (uint32_t)&lptim4_handler,
  (uint32_t)&dcache1_handler,
  (uint32_t)&adf1_handler,
  (uint32_t)&adc4_handler,
  (uint32_t)&lpdma1_channel0_handler,
  (uint32_t)&lpdma1_channel1_handler,
  (uint32_t)&lpdma1_channel2_handler,
  (uint32_t)&lpdma1_channel3_handler,
  (uint32_t)&dma2d_handler,
  (uint32_t)&dcmi_pssi_handler,
  (uint32_t)&octospi2_handler,
  (uint32_t)&mdf1_flt4_handler,
  (uint32_t)&mdf1_flt5_handler,
  (uint32_t)&cordic_handler,
  (uint32_t)&fmac_handler,
  (uint32_t)&lsecssd_handler
};

void default_handler(void)
{
  while(1);
}

extern uint32_t _etext, _sdata, _edata, _sbss, _ebss;
void main(void);

void reset_handler(void)
{
  // Copy .data from FLASH to SRAM
  uint32_t data_size = (uint32_t)&_edata - (uint32_t)&_sdata;
  uint8_t *flash_data = (uint8_t*) &_etext;
  uint8_t *sram_data = (uint8_t*) &_sdata;
  
  for (uint32_t i = 0; i < data_size; i++)
  {
    sram_data[i] = flash_data[i];
  }

  // Zero-fill .bss section in SRAM
  uint32_t bss_size = (uint32_t)&_ebss - (uint32_t)&_sbss;
  uint8_t *bss = (uint8_t*) &_sbss;

  for (uint32_t i = 0; i < bss_size; i++)
  {
    bss[i] = 0;
  }
  
  main();
}