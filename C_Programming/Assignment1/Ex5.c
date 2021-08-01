/*
 * Ex5.c
 *
 *  Created on: Aug 1, 2021
 *      Author: BassantAhmed
 */
#include <stdio.h>

int main()
{
	char character;
	printf("Enter a character:");
	fflush(stdin);	fflush(stdout);
	scanf("%c",&character);
	printf("ASCII value of %c is %d",character,character);
	return 0;
}

