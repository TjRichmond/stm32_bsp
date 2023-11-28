cd CMSIS/Device
mkdir ST
cd ST
git clone https://github.com/STMicroelectronics/cmsis_device_u5 STM32U5
# Add step to uncomment line 65 & remove '\' from line 64 in stm32u5xx.h 
cd STM32U5/Include