/*
 * Ex6.c
 *
 *  Created on: Aug 2, 2021
 *      Author: BassantAhmed
 */

#include <stdio.h>

int main()
{
	int n,sum=0;
	printf("Enter an integer:");
	fflush(stdin);	fflush(stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		sum +=i;
	}
	printf("sum = %d",sum);

	return 0;
}
