/*
- Title: SDES - A simplified version of the DES Algorithm	 
- Author: Thiago Ribeiro. 								 
- Date: November 5th, 2014.					
	Compiling: gcc -o sdes sdes.c functions.c -I.			 
*/

#include <stdio.h>
#include <string.h>
#include "headers.h"

#define S_STRING 10

char result[S_STRING+1]; /* terminating character */
char str1[S_STRING]; 
char str2[S_STRING];

int main()
{
	scanf("%s", str1);
	printf("%s\n", str1);

	scanf("%s", str2);
	printf("%s\n", str2);

	printf("\n");
	xor(str1, str2, result);

	printf("%s", result);

	return 0;
}
