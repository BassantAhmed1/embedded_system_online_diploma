/*
 * Ex2.c
 *
 *  Created on: Aug 5, 2021
 *      Author: MAK
 */


#include <stdio.h>

int main()
{
	int n;
	float sum=0;
	printf("Enter the number of data: ");
	fflush(stdin);	fflush(stdout);
	scanf("%d",&n);
	float numbers [n];
	for (int i=0;i<n;i++)
	{
		printf("%d. Enter number: ",i+1);
		fflush(stdin);	fflush(stdout);
		scanf("%f",&numbers[i]);
	}
	for (int j=0;j<n;j++)
		{
			sum += numbers[j];
		}
	printf("Average = %.2f",sum/n);
	return 0;
}


