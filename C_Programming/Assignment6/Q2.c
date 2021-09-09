/*
 * Q2.c
 *
 *  Created on: Sep 9, 2021
 *      Author: BassantAhmed
 */

#include <stdio.h>
#include <string.h>


int main(){
	char alpha[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','W','X','Y','Z'};
	char* Ptr=alpha;
	printf("The alphabets are : \n");
	for(int i=0;i<sizeof(alpha);i++)
	{
		printf("%c ",*Ptr);
		Ptr++;
	}

	return 0;
}
