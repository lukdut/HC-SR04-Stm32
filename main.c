#include <stm32f10x_HC-SR04.h>

int main(void) {
	InitHCSR04();
	int32_t dist = HCSR04GetDistance();
	while (1);
}

void EnableHCSR04PeriphClock() {
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
}
