/*
- Title: SDES - A simplified version of the DES Algorithm	 
- Author: Thiago Ribeiro. 								 
- Date: November 5th, 2014.								 
*/

#include <stdio.h>

int main(int argc, char const *argv[])
{

	return 0;
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