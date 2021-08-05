/*
 * Ex5.c
 *
 *  Created on: Aug 5, 2021
 *      Author: BassantAhmed
 */


#include <stdio.h>

int main()
{
	int elem_num,i;  //number of elements
	int search_elem;
	printf("Enter no. of elements: ");
	fflush(stdin);	fflush(stdout);
	scanf("%d",&elem_num);
	int elements[elem_num];
	for ( i=0;i<elem_num;i++)
		elements[i]=(i+1)*11;
	for ( i =0;i<elem_num;i++)
		printf("%d ",elements[i]);


	printf("\r\n Enter the element to be searched: ");
	fflush(stdin);	fflush(stdout);
	scanf("%d",&search_elem);

	i=0;
	while (elements[i]!= search_elem)
		i++;

	printf("number found at the location = %d ",i+1);



	return 0;
}


