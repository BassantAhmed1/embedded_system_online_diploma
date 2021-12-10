/*
 * unit7_lesson1_sec_Lab3.c
 *
 * Created: 07/11/2021 03:38:51 pm
 * Author : Bassant Ahmed
 */ 

#include "stdio.h"
#include <stdint.h>
#include <stdlib.h>

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>



int main(void)
{
	unsigned int i;
	//set Port A as an output
	DDRA= 0xFF;
    while(1) 
    {
		//light on sequential
		for (i=0;i<8;i++)
		{
			PORTA |= (1<<i);
			_delay_ms(500);		
		}
		//light off sequential
		for(i=7 ; i>0 ; i--)
		{
			PORTA &= ~(1<<i);
			_delay_ms(500);
		}
		PORTA &= ~(1<<0);
		_delay_ms(500);

	}
	
}

