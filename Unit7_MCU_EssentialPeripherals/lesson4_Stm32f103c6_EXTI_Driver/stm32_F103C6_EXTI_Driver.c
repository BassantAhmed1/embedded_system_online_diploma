/*
 * stm32_F103C6_EXTI_Driver.c
 *
 *  Created on: Mar 18, 2023
 *      Author: BassantAhmed
 */

/*
* ===============================================
 * 				Includes
 * ===============================================
 */

#include "inc/stm32_F103C6_EXTI_Driver.h"

//-----------------------------
//Macros Configuration References
//-----------------------------
/*@ref Module_REF_NAME_define
 */

/*
*===============================================
* 				Generic variables
*===============================================
*/

void (* GP_IRQ_CallBack[15])(void);


/*
* ===============================================
 * 				Generic Macros
 * ===============================================
 */
#define AFIO_GPIO_EXTI_Mapping(x)		((x== GPIOA)? 0:((x==GPIOB)?  1:((x==GPIOC)? 2:3) ))

/*
* ===============================================
 * 				Generic functions
 * ===============================================
 */
void EXTI_NVIC_ENABLE (EXTI_PinConfig_t* EXTI_config)
{
	if (EXTI_config->EXTI_PIN.IVT_IRQ_Number < 32)
	{
		switch (EXTI_config->EXTI_PIN.IVT_IRQ_Number)
		{
		case EXTI0_IRQ:
			NVIC_IRQ6_EXTI0_Enable;
			break;
		case EXTI1_IRQ:
			NVIC_IRQ7_EXTI1_Enable;
			break;
		case EXTI2_IRQ:
			NVIC_IRQ8_EXTI2_Enable;
			break;
		case EXTI3_IRQ:
			NVIC_IRQ9_EXTI3_Enable;
			break;
		case EXTI4_IRQ:
			NVIC_IRQ10_EXTI4_Enable;
			break;
		default:
			NVIC_IRQ23_EXTI5_9_Enable;
			break;
		}
	}
	else if (EXTI_config->EXTI_PIN.IVT_IRQ_Number < 64)
		NVIC_IRQ40_EXTI10_15_Enable;
}
void EXTI_NVIC_DISABLE (EXTI_PinConfig_t* EXTI_config)
{
	if (EXTI_config->EXTI_PIN.IVT_IRQ_Number < 32)
	{
		switch (EXTI_config->EXTI_PIN.IVT_IRQ_Number)
		{
		case EXTI0_IRQ:
			NVIC_IRQ6_EXTI0_Disable;
			break;
		case EXTI1_IRQ:
			NVIC_IRQ7_EXTI1_Disable;
			break;
		case EXTI2_IRQ:
			NVIC_IRQ8_EXTI2_Disable;
			break;
		case EXTI3_IRQ:
			NVIC_IRQ9_EXTI3_Disable;
			break;
		case EXTI4_IRQ:
			NVIC_IRQ10_EXTI4_Disable;
			break;
		default:
			NVIC_IRQ23_EXTI5_9_Disable;
			break;
		}
	}
	else if (EXTI_config->EXTI_PIN.IVT_IRQ_Number < 64)
		NVIC_IRQ40_EXTI10_15_Disable;
}

void Update_EXTI(EXTI_PinConfig_t* EXTI_config)
{
	//1- configure GPIO to be AF
	GPIO_PinConfig_t PinConfig ;
	PinConfig.GPIO_PinNumber = EXTI_config->EXTI_PIN.GPIO_PIN;
	PinConfig.GPIO_MODE = GPIO_MODE_INPUT_AF;
	MCAL_GPIO_Init(EXTI_config->EXTI_PIN.GPIO_PORT, &PinConfig);

//=============================================================================================

	//2- update AFIO to route between EXTI lines
	uint8_t AFIO_EXTICR_index = EXTI_config->EXTI_PIN.EXTI_InputLineNumber / 4;
	uint8_t AFIO_EXTICR_position = (EXTI_config->EXTI_PIN.EXTI_InputLineNumber % 4)*4;

	AFIO->EXTICR[AFIO_EXTICR_index] &= ~(0xF << AFIO_EXTICR_position); //clear the used bits first

	AFIO->EXTICR[AFIO_EXTICR_index] |= ((AFIO_GPIO_EXTI_Mapping(EXTI_config->EXTI_PIN.GPIO_PORT) & 0xF)<< AFIO_EXTICR_position);

//=================================================================================================

	//3-update rising and falling edge
	EXTI->RTSR &= ~(1 << EXTI_config->EXTI_PIN.EXTI_InputLineNumber);	//clear the used bits first
	EXTI->FTSR &= ~(1 << EXTI_config->EXTI_PIN.EXTI_InputLineNumber);	//clear the used bits first

	if (EXTI_config->Trigger_Case == EXTI_Trigger_Rising)
		EXTI->RTSR |= (1 << EXTI_config->EXTI_PIN.EXTI_InputLineNumber);
	else if (EXTI_config->Trigger_Case == EXTI_Trigger_Falling)
		EXTI->FTSR |= (1 << EXTI_config->EXTI_PIN.EXTI_InputLineNumber);
	else if (EXTI_config->Trigger_Case == EXTI_Trigger_RisingAndFalling)
	{
		EXTI->RTSR |= (1 << EXTI_config->EXTI_PIN.EXTI_InputLineNumber);
		EXTI->FTSR |= (1 << EXTI_config->EXTI_PIN.EXTI_InputLineNumber);
	}

//=====================================================================================================
	//4- update interrupt handling callback

	GP_IRQ_CallBack[EXTI_config->EXTI_PIN.EXTI_InputLineNumber] = EXTI_config->P_IRQ_CallBack;

//=====================================================================================================

	//5- NVIC enable
	if (EXTI_config->IRQ_EN ==EXTI_IRQ_ENABLE)
	{
		EXTI->IMR |= (1<<EXTI_config->EXTI_PIN.EXTI_InputLineNumber); 		//Enabling EXTI
		EXTI_NVIC_ENABLE (EXTI_config);										//Enabling NVIC
	}
	else if (EXTI_config->IRQ_EN ==EXTI_IRQ_DISABLE)
	{
		EXTI->IMR &= ~(1<<EXTI_config->EXTI_PIN.EXTI_InputLineNumber);
		EXTI_NVIC_DISABLE (EXTI_config);
	}

}

/*
 * ===============================================
 * APIs Supported by "MCAL EXTI DRIVER"
 * ===============================================
 */
/**================================================================
 * @Fn			-MCAL_EXTI_GPIO_Init
 * @brief 		-initialize GPIOx PINy aaccording to the specified parameter in the PinConfig
 * @param [in] 	-GPIOx:where x can be (A..E depending on device) to set GPIO peripherals.
 * @param [in] 	-PinConfig pointer to GPIO_PinConfig_t structure that contains the configuration info. for a pin
 * @retval 		-none
 * Note			-none
 */

void MCAL_EXTI_GPIO_Init(EXTI_PinConfig_t* EXTI_config)
{
	Update_EXTI(EXTI_config);
}




/**================================================================
 * @Fn			-MCAL_EXTI_GPIO_Deinit
 * @brief 		-Reset EXTI registers and NVIC corresponding IRQ mask
 * @retval 		-none
 * Note			-none
 */

void MCAL_EXTI_GPIO_Deinit(void)
{
	EXTI->EMR = 0x00000000;
	EXTI->FTSR = 0x00000000;
	EXTI->IMR = 0x00000000;
	EXTI->RTSR = 0x00000000;
	EXTI->SWIER = 0x00000000;
	EXTI->PR = 0xFFFFFFFF;		//write 1 to clear

	//disable EXTI_IRQ from NVIC

	NVIC_IRQ6_EXTI0_Disable;
	NVIC_IRQ7_EXTI1_Disable;
	NVIC_IRQ8_EXTI2_Disable;
	NVIC_IRQ9_EXTI3_Disable;
	NVIC_IRQ10_EXTI4_Disable;
	NVIC_IRQ23_EXTI5_9_Disable;
	NVIC_IRQ40_EXTI10_15_Disable;
}



/**================================================================
 * @Fn			-MCAL_EXTI_GPIO_Update
 * @brief 		-this is used to initialize EXTI form specific GPIO pin and specify mask/trigger condition and IRQ callback
 * @param [in] 	-EXTI_config set by @ref_EXTI_define
 * @retval 		-none
 * Note			-none
 */

void MCAL_EXTI_GPIO_Update(EXTI_PinConfig_t* EXTI_config)
{
	Update_EXTI(EXTI_config);
}


/*
*===============================================
* 				ISR functions
*===============================================
*/


void EXTI0_IRQHandler (void)
{
	//clear by writing 1 into the bit pining register (EXTI_PR)
	EXTI->PR |= (1<< EXTI0);

	//call callback function
	GP_IRQ_CallBack[EXTI0] ();
}

void EXTI1_IRQHandler (void)
{
	//clear by writing 1 into the bit pining register (EXTI_PR)
	EXTI->PR |= (1<< EXTI1);

	//call callback function
	GP_IRQ_CallBack[EXTI1] ();
}

void EXTI2_IRQHandler (void)
{
	//clear by writing 1 into the bit pining register (EXTI_PR)
	EXTI->PR |= (1<< EXTI2);
	//call callback function
	GP_IRQ_CallBack[EXTI2] ();
}

void EXTI3_IRQHandler (void)
{
	//clear by writing 1 into the bit pining register (EXTI_PR)
	EXTI->PR |= (1<< EXTI3);

	//call callback function
	GP_IRQ_CallBack[EXTI3] ();
}

void EXTI4_IRQHandler (void)
{
	//clear by writing 1 into the bit pining register (EXTI_PR)
	EXTI->PR |= (1<< EXTI4);

	//call callback function
	GP_IRQ_CallBack[EXTI4] ();
}

void EXTI9_5_IRQHandler (void)
{
	if (EXTI->PR & (1<<5))		{EXTI->PR |= (1<< EXTI5);	GP_IRQ_CallBack[EXTI5] ();}
	if (EXTI->PR & (1<<6))		{EXTI->PR |= (1<< EXTI6);	GP_IRQ_CallBack[EXTI6] ();}
	if (EXTI->PR & (1<<7))		{EXTI->PR |= (1<< EXTI7);	GP_IRQ_CallBack[EXTI7] ();}
	if (EXTI->PR & (1<<8))		{EXTI->PR |= (1<< EXTI8);	GP_IRQ_CallBack[EXTI8] ();}
	if (EXTI->PR & (1<<9))		{EXTI->PR |= (1<< EXTI9);	GP_IRQ_CallBack[EXTI9] ();}
}

void EXTI15_10_IRQHandler (void)
{
	if (EXTI->PR & (1<<10))		{EXTI->PR |= (1<< EXTI10);	GP_IRQ_CallBack[EXTI10] ();}
	if (EXTI->PR & (1<<11))		{EXTI->PR |= (1<< EXTI11);	GP_IRQ_CallBack[EXTI11] ();}
	if (EXTI->PR & (1<<12))		{EXTI->PR |= (1<< EXTI12);	GP_IRQ_CallBack[EXTI12] ();}
	if (EXTI->PR & (1<<13))		{EXTI->PR |= (1<< EXTI13);	GP_IRQ_CallBack[EXTI13] ();}
	if (EXTI->PR & (1<<14))		{EXTI->PR |= (1<< EXTI14);	GP_IRQ_CallBack[EXTI14] ();}
	if (EXTI->PR & (1<<15))		{EXTI->PR |= (1<< EXTI15);	GP_IRQ_CallBack[EXTI15] ();}
}



