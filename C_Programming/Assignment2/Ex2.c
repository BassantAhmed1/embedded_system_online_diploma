/*
 * Ex1.c
 *
 *  Created on: Aug 2, 2021
 *      Author: BassantAhmed
 */

#include <stdio.h>

int main()
{
	char alpha;
	printf("Enter an alphabet:");
	fflush(stdin);	fflush(stdout);
	scanf("%c",&alpha);
	if (alpha=='a'||alpha=='A'||alpha=='e'||alpha=='E'||alpha=='i'||alpha=='I'||alpha=='o'||alpha=='O'||alpha=='u'||alpha=='u')
		printf("%c is a vowel.\r\n",alpha);
	else
		printf("%c is a consonant",alpha);

	return 0;
}
