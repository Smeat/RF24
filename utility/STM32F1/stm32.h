
#include <stdint.h>

#include "stm32f1xx_hal_conf.h"

void setPin(uint8_t pin, bool direction){
	GPIO_PinState state = GPIO_PIN_RESET;
	if(direction) state = GPIO_PIN_SET;

	HAL_GPIO_WritePin(GPIOA, pin, state);
}

void setMode(uint32_t pin, uint32_t mode){
	GPIO_InitTypeDef GPIO_InitStructure;
	__HAL_RCC_GPIOA_CLK_ENABLE();

	GPIO_InitStructure.Pin = pin;
	GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_LOW;
	GPIO_InitStructure.Pull = GPIO_PULLUP;
	GPIO_InitStructure.Mode = mode;


	HAL_GPIO_Init(GPIOA, &GPIO_InitStructure);
}
