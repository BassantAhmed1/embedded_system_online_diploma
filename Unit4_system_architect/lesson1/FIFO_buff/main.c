/*
 * main.c
 *
 *  Created on: 17/10/2021
 *      Author: BassantAhmed
 */

#include "FIFO.h"

#define buffer_length 5
elem_type buffer1 [buffer_length];

int main(){

	FIFO_buf_t uart_FIFO ;
	unsigned char i;
	elem_type temp=0 ;


	//FIFO enqueue
	if (FIFO_init(&uart_FIFO , buffer1 , buffer_length) == FIFO_no_error)
		printf("FIFO initialization is done ... \r\n");

	for (i=0 ; i<10 ; i++)
	{
		if (FIFO_is_full(&uart_FIFO)){
			printf("FIFO is full \n");
			break;
		}
		if(FIFO_enqueue(&uart_FIFO, &i) != FIFO_no_error)
			printf("there is an error adding (%x) to the queue\n",i);
		else
			printf("FIFO enqueue (%x) is done ... \n",i);
	}
	print_FIFO(&uart_FIFO);
	//FIFO dequeue
	for (i=0 ; i<buffer_length ; i++){
		if (FIFO_is_empty(&uart_FIFO))
		{
			printf("FIFO is empty \n");
			break;
		}

		if (FIFO_dequeue(&uart_FIFO , &temp) != FIFO_no_error)
			printf("there is a dequeue problem \n");
		else
			printf("FIFO dequeue : %x \n",temp);
	}

	return 0;
}
