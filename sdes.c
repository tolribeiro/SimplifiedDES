/*
- Title: SDES - A simplified version of the DES Algorithm	 
- Author: Thiago Ribeiro. 								 
- Date: November 5th, 2014.								 
*/

#include <stdio.h>
#include <string.h>
#include "headers.h"

#define S_STRING 10

char result[S_STRING+1]; //terminating character
char str1[S_STRING]; 
char str2[S_STRING];

int main(int argc, char const *argv[])
{
	/*scanf("%s", str1);
	printf("%s\n", str1);

	scanf("%s", str2);
	printf("%s\n", str2);

	printf("\n");

	xor(str1, str2);
	printf("%s", result);*/

	return 0;
}

//xor operation between two strings, same length
void xor(char *str1, char *str2)
{
	int i;

	if (strlen(str1) != strlen(str2)) {
		printf("Error: xor operation does not support different string lengths.");
		return;
	}

	for (i = 0; i < strlen(str1); i++) {
		if (str1[i] == str2[i]) {
			result[i] = '0';
		}
		else result[i] = '1';
	}
	result[i] = '\0';

	return;
}