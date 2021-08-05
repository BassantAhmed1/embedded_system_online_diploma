/*
 * Ex4.c
 *
 *  Created on: Aug 5, 2021
 *      Author: BassantAhmed
 */


#include <stdio.h>

int main()
{
	int elem_num,i;  //number of elements
	int ins_elem;  //inserted element
	int location;
	printf("Enter no. of elements: ");
	fflush(stdin);	fflush(stdout);
	scanf("%d",&elem_num);
	int elements[elem_num];
	for ( i=0;i<elem_num;i++)
		elements[i]=i+1;
	for ( i =0;i<elem_num;i++)
		printf("%d ",elements[i]);
	printf("\r\n Enter the element to be inserted: ");
	fflush(stdin);	fflush(stdout);
	scanf("%d",&ins_elem);
	printf("\r\n Enter the location : ");
	fflush(stdin);	fflush(stdout);
	scanf("%d",&location);
	elements[(location-1)]=ins_elem;
	for ( i =0;i<elem_num;i++)
		printf("%d ",elements[i]);



	return 0;
}


