/*
 * stm32_F103C6_GPIO_Driver.c
 *
 *  Created on: Dec 1, 2021
 *      Author: Bassant Ahmed
 */

#include "inc/stm32F103C6_GPIO_Driver.h"
#include "inc/stm32f103x6.h"


/*
* ===============================================
 * 				Generic functions
 * ===============================================
 */

uint8_t Get_CRLH_Postion 	(uint16_t PinNumber)
{
	switch (PinNumber)
	{
	case GPIO_PIN_0:
		return 0;
		break;
	case GPIO_PIN_1:
		return 4;
		break;
	case GPIO_PIN_2:
		return 8;
		break;
	case GPIO_PIN_3:
		return 12;
		break;
	case GPIO_PIN_4:
		return 16;
		break;
	case GPIO_PIN_5:
		return 20;
		break;
	case GPIO_PIN_6:
		return 24;
		break;
	case GPIO_PIN_7:
		return 28;
		break;
	case GPIO_PIN_8:
		return 0;
		break;
	case GPIO_PIN_9:
		return 4;
		break;
	case GPIO_PIN_10:
		return 8;
		break;
	case GPIO_PIN_11:
		return 12;
		break;
	case GPIO_PIN_12:
		return 16;
		break;
	case GPIO_PIN_13:
		return 20;
		break;
	case GPIO_PIN_14:
		return 24;
		break;
	case GPIO_PIN_15:
		return 28;
		break;

	}
	return 0;

}
//-----------------------------
//Macros Configuration References
//-----------------------------
/*@ref Module_REF_NAME_define
 */
/*
 * ===============================================
 * APIs Supported by "MCAL GPIO DRIVER"
 * ===============================================
 */

/**================================================================
 * @Fn			-MCAL_GPIO_Init
 * @brief 		-initialize GPIOx PINy aaccording to the specified parameter in the PinConfig
 * @param [in] 	-GPIOx:where x can be (A..E depending on device) to set GPIO peripherals.
 * @param [in] 	-PinConfig pointer to GPIO_PinConfig_t structure that contains the configuration info. for a pin
 * @retval 		-none
 * Note			-none
 */
void MCAL_GPIO_Init 		(GPIO_typedef * GPIOx, GPIO_PinConfig_t *PinConfig)
{
	uint8_t Pin_Config = 0;
	//select bet. CRH and CRL
	volatile uint32_t * ConfigReg = NULL;
	ConfigReg = (PinConfig->GPIO_PinNumber < GPIO_PIN_8 )? &GPIOx->CRL : &GPIOx->CRH ;

	//clear CNFx[1:0] and MODEx[1:0]
	*ConfigReg &= ~(0xF << Get_CRLH_Postion(PinConfig->GPIO_PinNumber));

	//if output mode
	if (PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_PP || PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_OD || PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_AF_PP || PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_AF_OD)
		Pin_Config = (((PinConfig->GPIO_MODE - 4)<<2) | PinConfig->GPIO_Output_Speed)& 0x0F;
	else
	{
		if(PinConfig->GPIO_MODE == GPIO_MODE_INPUT_FLO || PinConfig->GPIO_MODE == GPIO_MODE_ANALOG)
			Pin_Config = ((PinConfig->GPIO_MODE <<2 ) &0x0F);
		else if (PinConfig->GPIO_MODE == GPIO_MODE_INPUT_AF) //consider it as input floating
			Pin_Config = ((GPIO_MODE_INPUT_FLO <<2 ) &0x0F);
		else // PU or PD
		{
			Pin_Config = ((PinConfig->GPIO_MODE <<2 ) &0x0F);
			if(PinConfig->GPIO_MODE == GPIO_MODE_INPUT_PU)
				GPIOx->ODR |= PinConfig->GPIO_PinNumber;
			if(PinConfig->GPIO_MODE == GPIO_MODE_INPUT_PD)
				GPIOx->ODR &= ~(PinConfig->GPIO_PinNumber);
		}
	}
	*ConfigReg |= Pin_Config << Get_CRLH_Postion(PinConfig->GPIO_PinNumber);

}

/**================================================================
 * @Fn			-MCAL_GPIO_DeInit
 * @brief 		-Reset the GPIOx All registers.
 * @param [in] 	-GPIOx:where x can be (A..E depending on device) to set GPIO peripherals.
 * @retval 		-none
 * Note			-none
 */
void MCAL_GPIO_DeInit 		(GPIO_typedef* GPIOx)
{
	GPIOx->BRR = 0x00000000;
	GPIOx->BSRR = 0x00000000;
	GPIOx->CRH = 0x44444444;
	GPIOx->CRL = 0x44444444;
	//GPIOx->IDR is Read only Reg.
	GPIOx->ODR = 0x00000000;
	GPIOx->LCKR = 0x00000000;
}

/**================================================================
 * @Fn			-MCAL_GPIO_ReadPin
 * @brief 		-Read specific pin
 * @param [in] 	-GPIOx:where x can be (A..E depending on device) to set GPIO peripherals.
 * @param [in] 	-PinNmber: set according to @ref GPIO_Pins_define
 * @retval 		-the pin value
 * Note			-none
 */
uint8_t MCAL_GPIO_ReadPin 	(GPIO_typedef * GPIOx, uint16_t PinNumber)
{
	uint8_t bitStatus = 0;
	if((GPIOx->IDR & PinNumber)==1)
		bitStatus= 1;
	else
		bitStatus= 0;
	return bitStatus;
}

/**================================================================
 * @Fn			-MCAL_GPIO_ReadPort
 * @brief 		-read specific Port
 * @param [in] 	-GPIOx:where x can be (A..E depending on device) to set GPIO peripherals.
 * @retval 		-the port value
 * Note			-none
 */
uint16_t MCAL_GPIO_ReadPort (GPIO_typedef * GPIOx)
{
	uint16_t PortVal = 0x0000;
	PortVal= (uint16_t)GPIOx->IDR ;
	return PortVal;
}

/**================================================================
 * @Fn			-MCAL_GPIO_WritePort
 * @brief 		-Write on specific port x
 * @param [in] 	-GPIOx:where x can be (A..E depending on device) to set GPIO peripherals.
 * @param [in] 	-the value to be written on the selected port.
 * @retval 		-none
 * Note			-none
 */
void MCAL_GPIO_WritePort 	(GPIO_typedef * GPIOx, uint16_t value)
{
	GPIOx->ODR = (uint32_t)value;
}

/**================================================================
 * @Fn			-MCAL_GPIO_WritePin
 * @brief 		-write on specific pin in portx
 * @param [in] 	-GPIOx:where x can be (A..E depending on device) to set GPIO peripherals.
 * @param [in] 	-the value to be written on the selected Pin
 * @retval 		-none
 * Note			-none
 */
void MCAL_GPIO_WritePin 	(GPIO_typedef * GPIOx, uint16_t PinNumber, uint8_t value)
{
	if (value==1)
		GPIOx->ODR |= (uint32_t)PinNumber;
	else
		GPIOx->ODR &= ~((uint32_t)PinNumber);
}

/**================================================================
 * @Fn			-MCAL_GPIO_TogglePin
 * @brief 		-toggling the GPIOx PINy
 * @param [in] 	-GPIOx:where x can be (A..E depending on device) to set GPIO peripherals.
 * @param [in] 	-PinNmber: set according to @ref GPIO_Pins_define
 * @retval 		-none
 * Note			-none
 */
void MCAL_GPIO_TogglePin 	(GPIO_typedef * GPIOx, uint16_t PinNumber)
{
	GPIOx->ODR ^= (uint32_t)PinNumber;
}

/**================================================================
 * @Fn			-MCAL_GPIO_LockPin
 * @brief 		-Mechanism to freeze the Pin's configuration
 * @param [in] 	-GPIOx:where x can be (A..E depending on device) to set GPIO peripherals.
 * @param [in] 	-PinNmber: set according to @ref GPIO_Pins_define
 * @retval 		-Ok if locked, Error if not locked (based on @ref GPIO_RETURN_LOCK)
 * Note			-none
 */
uint8_t MCAL_GPIO_LockPin 		(GPIO_typedef * GPIOx, uint16_t PinNumber)
{
	//set LCKK[16]
	volatile uint32_t tmp = 1<<16;

	//set LCKy

	tmp |= PinNumber;

	//write 1
	GPIOx->LCKR = tmp;

	//write 0
	GPIOx->LCKR = PinNumber;

	//write 1
	GPIOx->LCKR = tmp;

	//read 0
	tmp = GPIOx->LCKR;

	//read 1
	if ((uint32_t)(GPIOx->LCKR & 1<<16))
		return GPIO_RETURN_LOCK_ENABLED;
	else
		return GPIO_RETURN_LOCK_ERROR;
}

