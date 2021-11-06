/*
 * unit7_lesson1_Lab2.c
 *
 * Created: 06/11/2021 02:53:41 م
 * Author : Bassant Ahmed
 */ 

#include "stdio.h"
#include <stdint.h>
#include <stdlib.h>

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

void GPIO_init(void);
void threeLedsToggle(void);

int main ()
{
	GPIO_init();
	while(1)
	{
		threeLedsToggle();
	}
	return 0;
}


void GPIO_init(void)
{
	DDRD =0x00;
	DDRB =0x00;

	//Pins PD5, PD6, PD7 output
	DDRD |= (1<<5) | (1<<6) | (1<<7);
	//Pin PB7 output
	DDRB |= (1<<7);
}

void threeLedsToggle(void)
{
	//led 1 on then off
		PORTD |= (1<<5);
		_delay_ms(3000);
		PORTD &= ~(1<<5);
		//led 2 on then off
		PORTD |= (1<<6);
		_delay_ms(3000);
		PORTD &= ~(1<<6);
		//led 3 on then off
		PORTD |= (1<<7);
		_delay_ms(3000);
		PORTD &= ~(1<<7);
		//buzzer on then off after 3000ms
		PORTB |= (1<<7);
		_delay_ms(3000);
		PORTB &= ~(1<<7);
}