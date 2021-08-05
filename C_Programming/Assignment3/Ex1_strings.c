/*
 * Ex1.c
 *
 *  Created on: Aug 5, 2021
 *      Author: BassantAhmed
 */


#include <stdio.h>
#include <string.h>

int main()
{
	char text [100];
	char x;
	int count=0;
	printf("Enter a string :");
	fflush(stdin);	fflush(stdout);
	gets(text);
	printf("Enter a character to find frequency: ");
	fflush(stdin);	fflush(stdout);
	scanf("%c",&x);
	for(int i=0;i<strlen(text);i++)
	{
		if (text[i]==x)
		{
			count++;
		}
	}
	printf("frequency of %c =%d",x,count);
	return 0;
}


