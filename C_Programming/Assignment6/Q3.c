/*
 * Q3.c
 *
 *  Created on: Sep 9, 2021
 *      Author: BassantAhmed
 */

#include <stdio.h>
#include <string.h>


int main(){
	char str[100];
	printf("Input a string : ");
	fflush(stdin);	fflush(stdout);
	gets(str);
	char* Ptr=&str[strlen(str)-1];
	printf("reverse of the string is : ");
	for(int i=0;i<strlen(str);i++)
	{
		printf("%c",*Ptr);
		Ptr--;
	}

	return 0;
}
