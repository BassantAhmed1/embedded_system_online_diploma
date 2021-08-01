/*
 * Ex6.c
 *
 *  Created on: Aug 1, 2021
 *      Author: BassantAhmed
 */
#include <stdio.h>

int main()
{
	float a,b,c;
	printf("Enter value of a:");
	fflush(stdin);	fflush(stdout);
	scanf("%f",&a);
	printf("Enter value of b:");
	fflush(stdin);	fflush(stdout);
	scanf("%f",&b);
	c=a;
	a=b;
	b=c;
	printf("After swapping, value of a =%f \r\n",a);
	printf("After swapping, value of b =%f\r\n",b);

}

