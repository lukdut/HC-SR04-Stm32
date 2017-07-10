#ifndef STM32F10X_HC_SR04_H_
#define STM32F10X_HC_SR04_H_

#include "stm32f10x.h"

#define US_TIMER					TIM3

#define US_TRIG_PORT				GPIOB
#define US_TRIG_PIN					GPIO_Pin_0		//TIM Ch3 (trig output)

#define US_ECHO_PORT				GPIOA
#define US_ECHO_PIN					GPIO_Pin_6		//TIM Ch1 (echo input)
#define US_TIMER_TRIG_SOURCE		TIM_TS_TI1FP1

/**
 *	How to use this driver:
 * 	1. Implement EnableHCSR04PeriphClock function and turn on clock for used peripherals
 * 		ex:
 * 		void EnableHCSR04PeriphClock() {
 *			RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
 *			RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
 *			RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
 *		}
 *	2. Call InitHCSR04();
 *	3. Get distance (in mm) using HCSR04GetDistance function.
 *		Value lower than zero means no echo received (distance >3m)
 *		Measuring takes about 65ms
 *
 *	If necessary, change defines above, but be careful, US_ECHO_PIN must be tim ch1
 *	and US_TRIG_PIN must be ch3 or ch4. In case of ch4 change TIM_OC3Init into TIM_OC4Init in stm32f10x_HC-SR04.c file
 */



/**
 * Implement this function. See instruction at the top of this file.
 */
void EnableHCSR04PeriphClock();

/**
 * Initialization of HCSR04's peripherals
 */
void InitHCSR04();

/**
 * Measure distance and get value in mm. Lover than 0 means no echo signal: distance more than ~3m.
 */
int32_t HCSR04GetDistance();

#endif /* STM32F10X_HC_SR04_H_ */
