/*
 * Ex1.c
 *
 *  Created on: Aug 2, 2021
 *      Author: BassantAhmed
 */

#include <stdio.h>

int main()
{
	float max;
	float a,b,c;
	printf("Enter three numbers:");
	fflush(stdin);	fflush(stdout);
	scanf("%f %f %f",&a,&b,&c);
	max =(a>b) ? a : b;
	max = (max>c)? max:c;
	printf("the largest number is %f",max);

	return 0;
}
