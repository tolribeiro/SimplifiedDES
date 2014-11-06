#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void ip(char *result, char *str)
{
	result[0] = str[1];
	result[1] = str[5];
	result[2] = str[2];
	result[3] = str[0];
	result[4] =	str[3];
	result[5] = str[7];
	result[6] = str[4];
	result[7] = str[6];
	result[8] = '\0';
}
void xor(char *str1, char *str2, char *result)
{
	unsigned long int i;

	if (strlen(str1) != strlen(str2)) {
		printf("Error: xor operation does not support different string lengths.\n");
		exit(0);
	}

	for (i = 0; i < strlen(str1); i++) {
		if (str1[i] == str2[i]) {
			result[i] = '0';
		}
		else result[i] = '1';
	}
}