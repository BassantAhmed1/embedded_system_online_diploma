/*
 * Ex3.c
 *
 *  Created on: Aug 5, 2021
 *      Author: MAK
 */


#include <stdio.h>

int main()
{
	int r,c,rows,columns;
	printf("Enter Rows and columns of matrix: ");
	fflush(stdin);	fflush(stdout);
	scanf("%d %d",&rows,&columns);
	int a[rows][columns];
	int t[columns][rows];
	printf("Enter elements of matrix:\n");
	for (r=0;r<rows;r++)
	{
		for(c=0;c<columns;c++)
		{
			printf("Enter element a%d%d: ",r+1,c+1);
			fflush(stdin);	fflush(stdout);
			scanf("%d",&a[r][c]);
		}
	}
	printf("\r\n");
	printf("Entered matrix: \n");
	for (r=0;r<rows;r++)
	{
		for(c=0;c<columns;c++)
			printf("%d	",a[r][c]);
		printf("\n");
	}
	printf("\r\n");
	for (r=0;r<rows;r++)
		{
			for(c=0;c<columns;c++)
				t[c][r]= a[r][c];
		}
	printf("transpose of matrix: \n");
	for (c=0;c<columns;c++)
		{
			for(r=0;r<rows;r++)
				printf("%d	",t[c][r]);
			printf("\n");
		}

	return 0;
}


