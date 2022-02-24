/*
 * stm32_F103C6_GPIO_Driver.h
 *
 *  Created on: Dec 1, 2021
 *      Author: Bassant Ahmed
 */

#ifndef INC_STM32_F103C6_GPIO_DRIVER_H_
#define INC_STM32_F103C6_GPIO_DRIVER_H_



//-----------------------------
//Includes
//-----------------------------

#include "stm32f103x6.h"


//-----------------------------
//User type definitions (structures)
//-----------------------------

typedef struct {
	uint16_t GPIO_PinNumber		; 	//specifies the GPIO pins to be configured.
	//this parameter must be set based on a value @ref GPIO_Pins_define

	uint32_t GPIO_MODE			;	//specifies the operating mode for the selected pin
	//this parameter must be set based on a value @ref GPIO_MODE_define

	uint32_t GPIO_OUTPUT_SPEED	;	//specifies the speed for the selected pin
	//this parameter must be set based on a value @ref GPIO_SPEED_define
}GPIO_PinConfig_t;


//-----------------------------
//Macros Configuration References
//-----------------------------
/*@ref Module_REF_NAME_define
 */
//@ref GPIO_Pins_define
#define GPIO_PIN_0		((uint16_t)1<<0)
#define GPIO_PIN_1		((uint16_t)1<<1)
#define GPIO_PIN_2		((uint16_t)1<<2)
#define GPIO_PIN_3		((uint16_t)1<<3)
#define GPIO_PIN_4		((uint16_t)1<<4)
#define GPIO_PIN_5		((uint16_t)1<<5)
#define GPIO_PIN_6		((uint16_t)1<<6)
#define GPIO_PIN_7		((uint16_t)1<<7)
#define GPIO_PIN_8		((uint16_t)1<<8)
#define GPIO_PIN_9		((uint16_t)1<<9)
#define GPIO_PIN_10		((uint16_t)1<<10)
#define GPIO_PIN_11		((uint16_t)1<<11)
#define GPIO_PIN_12		((uint16_t)1<<12)
#define GPIO_PIN_13		((uint16_t)1<<13)
#define GPIO_PIN_14		((uint16_t)1<<14)
#define GPIO_PIN_15		((uint16_t)1<<15)

#define GPIO_PIN_ALL	((uint16_t)0xFFFF)

#define GPIO_PIN_Mask	0x0000FFFFu

//@ref GPIO_MODE_define


#define GPIO_MODE_ANALOG			0x00000000u //Analog mode
#define GPIO_MODE_INPUT_FLO			0x00000001u //Floating input (reset state)
#define GPIO_MODE_INPUT_PU			0x00000002u //Input with pull-up
#define GPIO_MODE_INPUT_PD			0x00000003u //Input with Pull_down
#define GPIO_MODE_OUTPUT_PP			0x00000004u //General purpose output push-pull
#define GPIO_MODE_OUTPUT_OD			0x00000005u //General purpose output Open-drain
#define GPIO_MODE_OUTPUT_AF_PP		0x00000006u //Alternate function output Push-pull
#define GPIO_MODE_OUTPUT_AF_OD		0x00000007u //Alternate function output Open-drain
#define GPIO_MODE_INPUT_AF			0x00000008u //alternate function input


//@ref GPIO_SPEED_define

#define GPIO_SPEED_10M	0x00000001u	//Output mode, max speed 10 MHz.
#define GPIO_SPEED_2M	0x00000002u	//Output mode, max speed 2 MHz.
#define GPIO_SPEED_50M	0x00000003u	//Output mode, max speed 50 MHz.

//@ref GPIO_RETURN_LOCK

#define GPIO_RETURN_LOCK_ENABLED	1
#define GPIO_RETURN_LOCK_ERROR		0

//@ref GPIO_PIN_state

#define GPIO_PIN_SET		1
#define GPIO_PIN_RESET		0

/*
 * ===============================================
 * APIs Supported by "MCAL GPIO DRIVER"
 * ===============================================
 */

void MCAL_GPIO_Init (GPIO_TypeDef *GPIOx,GPIO_PinConfig_t* PinConfig);
void MCAL_GPIO_DeInit (GPIO_TypeDef *GPIOx);

//read APIs
uint8_t MCAL_GPIO_ReadPin(GPIO_TypeDef *GPIOx, uint16_t PinNumber);
uint16_t MCAL_GPIO_ReadPort(GPIO_TypeDef *GPIOx);

//write APIs
void MCAL_GPIO_WritePin(GPIO_TypeDef *GPIOx, uint16_t PinNumber, uint8_t Value);
void MCAL_GPIO_WritePort(GPIO_TypeDef *GPIOx , uint16_t value);

void MCAL_GPIO_TogglePin(GPIO_TypeDef *GPIOx, uint16_t PinNumber);

uint8_t MCAL_GPIO_LockPin(GPIO_TypeDef *GPIOx, uint16_t PinNumber);

uint8_t Get_CRLH_Postion (uint16_t PinNumber);


#endif /* INC_STM32_F103C6_GPIO_DRIVER_H_ */
