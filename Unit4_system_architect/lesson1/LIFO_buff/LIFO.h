/*
 * LIFO.h
 *
 *  Created on: 17/10/2021
 *      Author: BassantAhmed
 */

#ifndef LIFO_H_
#define LIFO_H_
#endif /* LIFO_H_ */

#define buffer_length 5

typedef struct {
	unsigned int *base;
	unsigned int *head;
	unsigned int length;
	unsigned int count;

}LIFO_buf_t;

typedef enum {
	LIFO_no_error,
	LIFO_NULL,
	LIFO_full,
	LIFO_empty
}Buffer_status;

Buffer_status LIFO_add_item (LIFO_buf_t *LIFO_Buf , unsigned int item);
Buffer_status LIFO_get_item (LIFO_buf_t *LIFO_Buf, unsigned int *item);
char LIFO_is_full (LIFO_buf_t *LIFO_Buf);
char LIFO_is_empty (LIFO_buf_t *LIFO_Buf);
Buffer_status LIFO_init (LIFO_buf_t *LIFO_Buf , unsigned int *Buffer,unsigned int length);
void print_full_LIFO (LIFO_buf_t *LIFO_Buf);


