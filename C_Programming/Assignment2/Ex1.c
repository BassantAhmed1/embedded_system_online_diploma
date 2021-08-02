/*
 * Ex1.c
 *
 *  Created on: Aug 2, 2021
 *      Author: BassantAhmed
 */

#include <stdio.h>

int main()
{
	int number;
	printf("Enter an integer you want to check:");
	fflush(stdin);	fflush(stdout);
	scanf("%d",&number);
	if (number%2==0)
		printf("%d is even \r\n",number);
	else
		printf("%d is odd ",number);

	return 0;
}
