/*
 * FIFO.h
 *
 *  Created on: 17/10/2021
 *      Author: BassantAhmed
 */

#ifndef FIFO_H_
#define FIFO_H_
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "stdint.h"

#define elem_type uint8_t


typedef struct {
	elem_type *base;
	elem_type *head;
	elem_type *tail;
	unsigned int length;
	unsigned int count;

}FIFO_buf_t;

typedef enum {
	FIFO_NULL,
	FIFO_no_error,
	FIFO_full,
	FIFO_empty
}Buffer_status;

Buffer_status FIFO_enqueue (FIFO_buf_t *FIFO_Buf , elem_type *item);
Buffer_status FIFO_dequeue (FIFO_buf_t *FIFO_Buf, elem_type *item);
char FIFO_is_full (FIFO_buf_t *FIFO_Buf);
char FIFO_is_empty (FIFO_buf_t *FIFO_Buf);
Buffer_status FIFO_init (FIFO_buf_t *FIFO_Buf , elem_type *Buffer, uint32_t length);
void print_FIFO (FIFO_buf_t *FIFO_Buf);







#endif /* FIFO_H_ */
