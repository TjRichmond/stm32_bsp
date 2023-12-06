# stm32_bsp
Board support package without any vendor-supplied HAL

# Setup
Clone the STM32U5 CMSIS device repo into the correct CMSIS directory.
```
sudo chmod +x ./setup.sh && ./setup.sh
```
A future feature of the script could be to accept a parameter to choose which stm32 device to check.

# Links
Boilerplate based on this article: https://kleinembedded.com/stm32-without-cubeide-part-2-cmsis-make-and-clock-configuration/

Google C++ style guide: https://google.github.io/styleguide/cppguide.html
