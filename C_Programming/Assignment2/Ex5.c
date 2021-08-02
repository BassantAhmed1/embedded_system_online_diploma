/*
 * Ex5.c
 *
 *  Created on: Aug 2, 2021
 *      Author: BassantAhmed
 */

#include <stdio.h>

int main()
{
	char c;
	printf("Enter a character:");
	fflush(stdin);	fflush(stdout);
	scanf("%c",&c);
	if (((c>=65)&&(c <= 90) )|| ((c>=97)&&(c<=122)))
		printf("%c is an alphabet.\r\n",c);
	else
		printf("%c is not an alphabet.\r\n",c);

	return 0;
}
