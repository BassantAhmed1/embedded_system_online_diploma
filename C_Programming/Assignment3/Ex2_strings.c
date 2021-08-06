/*
 * Ex2.c
 *
 *  Created on: Aug 6, 2021
 *      Author: BassantAhmed
 */


#include <stdio.h>
#include <string.h>

int main()
{
	char text [100];
	int len=0;
	printf("Enter a string :");
	fflush(stdin);	fflush(stdout);
	gets(text);
	while(text[len]!=0)
		len+=1;
	printf("length of string : %d",len);
	return 0;
}


