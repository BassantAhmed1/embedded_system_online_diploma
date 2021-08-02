/*
 * Ex7.c
 *
 *  Created on: Aug 2, 2021
 *      Author: BassantAhmed
 */

#include <stdio.h>

int main()
{
	int n,sum=1;
	printf("Enter an integer:");
	fflush(stdin);	fflush(stdout);
	scanf("%d",&n);
	if (n==0)
		printf("Factorial = 1\r\n");
	else if (n<0)
		printf("Error!!! Factorial of negative number doesn't exist.\r\n");
	else
	{
		for (int i=1;i<=n;i++)
		{
			sum = sum * i;
		}
		printf("sum = %d",sum);
	}

	return 0;
}
