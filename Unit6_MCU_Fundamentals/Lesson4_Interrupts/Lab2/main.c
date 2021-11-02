/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Eng.Ahmed Youssef
 */
#include "stdio.h"
#include <stdint.h>
#include <stdlib.h>

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>


int main ()
{

	//set outputs
	DDRD |= (1<<5);
	DDRD |= (1<<6);
	DDRD |= (1<<7);

	//set INT0 to any logical change
	MCUCR |= (1<<0);
	//set INT1 to rising edge
	MCUCR |= (0b11<<2);
	MCUCR &= ~(1<<1);



	//Set INT2 to falling edge
	MCUCSR &= ~(1<<6);

	//enable interrupts
	GICR |= (0b111<<5);
	SREG |= (1<<7);

	while (1)
	{

	}
	return 0;
}
ISR(INT0_vect){
	PORTD |= (1<<5);
	_delay_ms(3600);
	PORTD &= ~(1<<5);
}

ISR(INT1_vect){
	PORTD |= (1<<6);
	_delay_ms(3600);
	PORTD &= ~(1<<6);
}

ISR(INT2_vect){
	PORTD |= (1<<7);
	_delay_ms(3600);
	PORTD &= ~(1<<7);
}
