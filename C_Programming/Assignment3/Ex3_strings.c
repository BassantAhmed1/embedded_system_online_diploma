/*
 * Ex3.c
 *
 *  Created on: Aug 6, 2021
 *      Author: BassantAhmed
 */


#include <stdio.h>
#include <string.h>

int main()
{
	char a [50];
	char b;
	int rev,i;
	printf("Enter the string :");
	fflush(stdin);	fflush(stdout);
	gets(a);
	rev=strlen(a)-1;
	for ( i=0;i<strlen(a)/2;i++)
	{
		b=a[i];
		a [i]=a[rev];
		a [rev]=b;
		rev--;

	}
	printf("Reverse string is : %s",a);
	return 0;
}


