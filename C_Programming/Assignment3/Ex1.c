/*
 * Ex1.c
 *
 *  Created on: Aug 4, 2021
 *      Author: BassantAhmed
 */

#include <stdio.h>

int main()
{

	float a[2][2];
	float b[2][2];
	int r,c;
	printf("Enter the elements of 1st matrix\n");
	for (r=0;r<2;r++)
	{
		for (c=0;c<2;c++)
		{
			printf("Enter a%d%d : ",r+1,c+1);
			fflush(stdin);	fflush(stdout);
			scanf("%f",&a[r][c]);
		}
	}
	printf("Enter the elements of 2st matrix\n");
	for (r=0;r<2;r++)
		{
			for (c=0;c<2;c++)
			{
				printf("Enter b%d%d : ",r+1,c+1);
				fflush(stdin);	fflush(stdout);
				scanf("%f",&b[r][c]);
			}
		}
	printf("sum of matrix:\n");
	for (r=0;r<2;r++)
		{
			for (c=0;c<2;c++)
			{
				printf("%.1f	",a[r][c]+b[r][c]);
			}
			printf("\n");
		}

	return 0;
}

