/*
 * Q1.c
 *
 *  Created on: Sep 9, 2021
 *      Author: BassantAhmed
 */

#include <stdio.h>
#include <string.h>


int main(){
	int m;
	int* ab=&m;

	*ab = 29;
	printf("address of m : 0x%x \n",(unsigned int)&m);
	printf("value of m : %d \n",m);
	printf("address of pointer ab : 0x%x\n",(unsigned int )ab);
	printf("content of pointer ab : %d\n",*ab);

	return 0;
}
