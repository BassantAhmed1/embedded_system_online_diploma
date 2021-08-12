/*
 * Ex1.c
 *
 *  Created on: Aug 12, 2021
 *      Author: BassantAhmed
 */
#include <stdio.h>


void prime_num(int num1, int num2);

int main ()
{

	int num1,num2;
	printf("Enter two numbers (intervals):");
	fflush(stdin);	fflush(stdout);
	scanf("%d %d",&num1,&num2);
	printf("prime numbers between %d and %d are: ",num1,num2);
	prime_num(num1,num2);
	return 0;

}
void prime_num(int num1, int num2)
{
	for (; num1<=num2 ;num1++)
		{
			if (num1==11)
				printf("%d ",num1);
			else if(!((num1%2==0)||(num1%3==0) || (num1%5==0) || (num1%7==0) || (num1%11==0)))
				printf("%d ",num1);

		}
}
