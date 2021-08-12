/*
 * Ex2.c
 *
 *  Created on: Aug 12, 2021
 *      Author: BassantAhmed
 */
#include <stdio.h>


int factorial(int n);
int main ()
{

	int num;
	printf("Enter a positive integer:");
	fflush(stdin);	fflush(stdout);
	scanf("%d ",&num);
	printf("factorial of %d = %d",num,factorial(num));

	return 0;

}
int factorial(int n)
{

	if (n!=1)
		return n*factorial(n-1);

}
