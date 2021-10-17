/*
 * main.c
 *
 *  Created on: 17/10/2021
 *      Author: BassantAhmed
 */

#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "LIFO.h"

unsigned int buff1[buffer_length];
unsigned int buff2[buffer_length];

void main()
{
	int i , temp;
	LIFO_buf_t uart_buff , i2c_buff;
	LIFO_init(&uart_buff, buff1 ,buffer_length);
	LIFO_init(&i2c_buff, buff2 ,buffer_length);

	for (i=0 ; i< buffer_length ; i++)
	{
		if(LIFO_is_full(&uart_buff))
			break;
		if (LIFO_add_item(&uart_buff, i) != LIFO_no_error)
			printf("there is a problem adding : %d\n",i);
		printf("LIFO added %d to uart_buff \n",i);
	}

	for (i=0 ; i< buffer_length ; i++)
	{
		if(LIFO_is_empty(&uart_buff))
			break;
		if (LIFO_get_item(&uart_buff, &temp) != LIFO_no_error){
			printf("there is a problem getting , will break the reading tell find the problem \n");
			break;}
		printf("LIFO red %d\n",temp);
	}







}
