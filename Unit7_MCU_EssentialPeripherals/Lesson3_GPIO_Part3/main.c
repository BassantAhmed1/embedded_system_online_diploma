#include "stm32f103x6.h"
#include "stm32_F103C6_GPIO_Driver.h"
#include ""


void clock_init (void){
	//init clock for GPIOA
	RCC_GPIOA_CLK_EN();

	//init clock for GPIOB
	RCC_GPIOB_CLK_EN();


}

void GPIO_init(void)
{


	//input init
	//PA1 floating input
	GPIO_PinConfig_t PinConfig;
	PinConfig.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	PinConfig.GPIO_PinNumber = GPIO_PIN_1;

	MCAL_GPIO_Init(GPIOA, &PinConfig);

	//PA13 floating input
	PinConfig.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	PinConfig.GPIO_PinNumber = GPIO_PIN_13;

	MCAL_GPIO_Init(GPIOA, &PinConfig);

	//output init
	//PB1 push pull mode (Output mode, max speed 10 MHz)
	PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_PinNumber = GPIO_PIN_1;
	PinConfig.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;

	MCAL_GPIO_Init(GPIOB, &PinConfig);

	//PB13 push pull mode (Output mode, max speed 10 MHz)
	PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_PinNumber = GPIO_PIN_13;
	PinConfig.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;

	MCAL_GPIO_Init(GPIOB, &PinConfig);
}

void wait (unsigned int time)
{
	unsigned int i,j;
	for(i=0;i<time;i++)
		for(j=0;j<255;j++);
}

int main(void)
{
	clock_init();
	GPIO_init();


	while(1)
	{
		if (((GPIOA->IDR & (1<<1))>>1) == 0)
		{
			MCAL_GPIO_TogglePin(GPIOB, GPIO_PIN_1);
			while (((GPIOA->IDR & (1<<1))>>1) == 0);
		}
		if (((GPIOA->IDR & (1<<13))>>13) == 1)
		{
			while(((GPIOA->IDR & (1<<13))>>13) == 1)
			{
				MCAL_GPIO_TogglePin(GPIOB, GPIO_PIN_13);
				wait(1);
			}
		}


	}
}
