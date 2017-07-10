# HC-SR04-Stm32

Stm32 driver for US distance sensor HC-SR04. No interrupts and only 1 timer used for triggering and measurements.

How to use this driver:
1. Implement EnableHCSR04PeriphClock function and turn on clock for used peripherals
ex:
  ```
  void EnableHCSR04PeriphClock() {
      RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
      RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
      RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	}
  ```
2. Call InitHCSR04();
3. Get distance (in mm) using HCSR04GetDistance function. Value lower than zero means no echo received (distance >3m). Measuring takes about 65ms

*If necessary, change defines above, but be careful, US_ECHO_PIN must be tim ch1 and US_TRIG_PIN must be ch3 or ch4. In case of ch4 change TIM_OC3Init into TIM_OC4Init in stm32f10x_HC-SR04.c file
