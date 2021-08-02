/*
 * Ex4.c
 *
 *  Created on: Aug 2, 2021
 *      Author: BassantAhmed
 */

#include <stdio.h>

int main()
{
	float num;
	printf("Enter a number:");
	fflush(stdin);	fflush(stdout);
	scanf("%f",&num);
	if (num>0)
		printf("%.2f is a positive.\r\n",num);
	else if (num<0)
		printf("%.2f is a negative.\r\n",num);
	else
		printf("you entered zero");
	return 0;
}
