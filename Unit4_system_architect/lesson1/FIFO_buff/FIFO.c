/*
 * FIFO.c
 *
 *  Created on: 17/10/2021
 *      Author: BassantAhmed
 */

#include "FIFO.h"

Buffer_status FIFO_enqueue (FIFO_buf_t *FIFO_Buf , elem_type *item){
	if (!FIFO_Buf->base || !FIFO_Buf->head || !FIFO_Buf->tail){
		printf("FIFO is null\n");
		return FIFO_NULL;}
	if (FIFO_is_full(FIFO_Buf))
	{	printf("FIFO is full \n");
	return FIFO_full;
	}
	*FIFO_Buf->head = *item;
	FIFO_Buf->count++;
	if (FIFO_Buf->head == (FIFO_Buf->base + (FIFO_Buf->length * sizeof(elem_type))))
		FIFO_Buf->head = FIFO_Buf->base;
	else
		FIFO_Buf->head++;
	return FIFO_no_error;


}


Buffer_status FIFO_dequeue (FIFO_buf_t *FIFO_Buf, elem_type *item){
	if (!FIFO_Buf->base || !FIFO_Buf->head || !FIFO_Buf->tail){
		printf("FIFO is null\n");
		return FIFO_NULL;}
	if (FIFO_is_empty(FIFO_Buf))
	{
		printf("FIFO is empty \n");
		return FIFO_empty;
	}
	*item = *FIFO_Buf->tail;
	FIFO_Buf->count--;
	if (FIFO_Buf->tail == (FIFO_Buf->base + (FIFO_Buf->length * sizeof(elem_type))) )
		FIFO_Buf->tail = FIFO_Buf->base;
	else
		FIFO_Buf->tail++;
	return FIFO_no_error;
}

char FIFO_is_full (FIFO_buf_t *FIFO_Buf){
	if(FIFO_Buf->count==FIFO_Buf->length)
		return 1;
	else
		return 0;

}

char FIFO_is_empty (FIFO_buf_t *FIFO_Buf){
	if(FIFO_Buf->count==0)
		return 1;
	else
		return 0;


}

Buffer_status FIFO_init (FIFO_buf_t *FIFO_Buf , elem_type *Buffer,uint32_t length){
	FIFO_Buf->base = Buffer;
	FIFO_Buf->head = Buffer;
	FIFO_Buf->tail = Buffer;
	FIFO_Buf->length = length;
	FIFO_Buf->count = 0;

	return FIFO_no_error ;
}

void print_FIFO (FIFO_buf_t *FIFO_Buf){
	elem_type *ptr = FIFO_Buf->tail ;
	if (!FIFO_Buf->base || !FIFO_Buf->head || !FIFO_Buf->tail)
		printf("faild to find the FIFO buffer .\n");
	else
	{
		printf("FIFO print .... \n");
		for (int i=0 ; i<FIFO_Buf->count ; i++)
		{
			printf("%x \n ",*(ptr++));
		}
	}



}



