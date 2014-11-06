/*
- Title: SDES - A simplified version of the DES Algorithm	 
- Author: Thiago Ribeiro. 								 
- Date: November 5th, 2014.					
	Compiling: gcc -o sdes sdes.c functions.c -I.			 
*/

#include <stdio.h>
#include <string.h>
#include "headers.h"

#define SIZE 10

char result[SIZE]; 
char str1[SIZE]; 
char str2[SIZE];

int main()
{
	scanf("%s", str1);
	printf("%s\n", str1);

	scanf("%s", str2);
	printf("%s\n", str2);

	xor(str1, str2, result);

	printf("%s", result);

	return 0;
}
