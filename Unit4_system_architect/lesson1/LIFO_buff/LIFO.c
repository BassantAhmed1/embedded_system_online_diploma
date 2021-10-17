/*
 * LIFO.c
 *
 *  Created on: 17/10/2021
 *      Author: BassantAhmedf
 */
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "LIFO.h"

Buffer_status LIFO_add_item (LIFO_buf_t *LIFO_Buf, unsigned int item){
	if(!LIFO_Buf->base || !LIFO_Buf->head)
		return LIFO_NULL;
	if(LIFO_Buf->count == LIFO_Buf->length)
		return LIFO_full;
	*LIFO_Buf->head=item;
	LIFO_Buf->head++;
	LIFO_Buf->count++;

	return LIFO_no_error ;
}


Buffer_status LIFO_get_item (LIFO_buf_t *LIFO_Buf, unsigned int *item){
	if(!LIFO_Buf->base || !LIFO_Buf->head)
		return LIFO_NULL;
	if(!LIFO_Buf->count)
		return LIFO_empty;

	LIFO_Buf->head--;
	*item=*LIFO_Buf->head;
	LIFO_Buf->count--;
	return LIFO_no_error ;
}

char LIFO_is_full (LIFO_buf_t *LIFO_Buf){//if full the function return one , else 0
	if(LIFO_Buf->count == LIFO_Buf->length)
		return 1 ;
	else
		return 0;
}



char LIFO_is_empty (LIFO_buf_t *LIFO_Buf){//if empty the function return one , else 0
	if(!LIFO_Buf->count)
			return 1 ;
		else
			return 0;
}
Buffer_status LIFO_init (LIFO_buf_t *LIFO_Buf , unsigned int *Buffer,unsigned int length){
	if (!Buffer)
		return LIFO_NULL;
	LIFO_Buf->base=Buffer;
	LIFO_Buf->head=Buffer;
	LIFO_Buf->length=length;
	LIFO_Buf->count=0;


	return LIFO_no_error ;
}

void print_full_LIFO (LIFO_buf_t *LIFO_Buf){
	unsigned int* ptr = LIFO_Buf->head;
	int i;
	for(i=0;i <LIFO_Buf->count ; i++)
	{
		printf("item number 1= %d",*ptr++);
	}
}



