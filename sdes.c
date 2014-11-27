/*
- Title: SDES - A simplified version of the DES Algorithm	 
- Author: Thiago Ribeiro. 								 
- Date: November 5th, 2014.								 
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void xor(char *str1, char *str2);
void ip(char *result);
void ip_inverse(char *str);
void divide_block(char *left, char *right);
void p10_key_permutation(char *key);
void circular_left_shift(char *key);
void p8_key_permutation(char *key);
void key_generation(char *key);
void expansion_permutation(char *str);
void sbox_s0();
void sbox_s1();

char result[11]; // used for permutations: max is 10 (key) plus terminator character
char plaintext[9]; // compatible for strcpy
char left[5]; // 4 bits plus terminator character
char right[5];
char key[11]; // 10-bit size key plus terminator
char key1[9]; // 8-bit subkey1 plus terminator character	
char key2[9]; // 8-bit subkey2 plus terminator character
char temp[11]; // temporary variable to generate subkey k2
char s_0[4][4]; // s0 box
char s_1[4][4]; // s1 box

int main()
{
	int i;
	//do {
	//	scanf("%s", plaintext);
	//} while (strlen(plaintext) != SIZE_BLOCK);

	//ip(plaintext);
	//printf("%s\n", result);
	//strcpy(plaintext, result);
 	//divide_block(left, right);
 	
 	// key permutation test
 	
 	/*strcpy(key, "1010000010");
 	p10_key_permutation(key);
	//printf("%s\n", result);
	circular_left_shift(result);
	printf("%s\n", result);
	strcpy(key, result);
	p8_key_permutation(key);
	printf("%s\n", result);
	strcpy(key, "1010000010");
	key_generation(key);
	printf("%s\n", key1);
	printf("%s\n", key2);*/

	strcpy(left, "1001");
	expansion_permutation(left);
	printf("%s\n", result);
	strcpy(key, "10100010");
	xor(result, key);
	printf("%s\n", result);

	return 0;
}

void sbox_s0()
{
	strcpy(s_0[0],"1032");
	strcpy(s_0[1],"3210");
	strcpy(s_0[2],"0213");
	strcpy(s_0[3],"3132");
}

void sbox_s1()
{
	strcpy(s_1[0],"0123");
	strcpy(s_1[1],"2013");
	strcpy(s_1[2],"3010");
	strcpy(s_1[3],"2103");
}

void expansion_permutation(char *str)
{
	result[0] = str[3];
	result[1] = str[0];
	result[2] = str[1];
	result[3] = str[2];
	result[4] =	str[1];
	result[5] = str[2];
	result[6] = str[3];
	result[7] = str[0];
	result[8] = '\0';
}

void key_generation(char *key)
{
	// generating first subkey key1 from key
	p10_key_permutation(key);
	strcpy(key, result);
	circular_left_shift(key);
	strcpy(temp, key);
	p8_key_permutation(key);
	strcpy(key1, result);

	// generating second subkey key2 from temp
	circular_left_shift(temp);
	circular_left_shift(temp);
	p8_key_permutation(temp);
	strcpy(key2, result);
}

void circular_left_shift(char *key)
{
	char temp = key[0];

	for (int i = 0; i < 5; i++) {
		key[i] = key[i+1];
	}	
	key[4] = temp;
	temp = key[5];
	for (int i = 5 ; i < 10; i++) {
		key[i] = key[i+1];
	}	
	key[9] = temp;
}

void p8_key_permutation(char *key)
{
	result[0] = key[5];
	result[1] = key[2];
	result[2] = key[6];
	result[3] = key[3];
	result[4] =	key[7];
	result[5] = key[4];
	result[6] = key[9];
	result[7] = key[8];
	result[8] = '\0';
}

// key permutation
void p10_key_permutation(char *key)
{
	result[0] = key[2];
	result[1] = key[4];
	result[2] = key[1];
	result[3] = key[6];
	result[4] =	key[3];
	result[5] = key[9];
	result[6] = key[0];
	result[7] = key[8];
	result[8] = key[7];
	result[9] = key[5];
	result[10] = '\0';
}

// divide the 8-bit block into 4-bit left and right
void divide_block(char *left, char *right)
{	
	int i, j;

	for (i = 0; i < 4; i++) {
		left[i] = plaintext[i];
	}
	left[i] = '\0';

	for (j = 0; j < 4; j++) {
		right[j] = plaintext[i];
		i++;
	}
	right[j] = '\0';
}

// initial permutation 
void ip(char *str)
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

// inverse permutation 
void ip_inverse(char *str)
{
	result[0] = str[3];
	result[1] = str[0];
	result[2] = str[2];
	result[3] = str[4];
	result[4] =	str[6];
	result[5] = str[1];
	result[6] = str[7];
	result[7] = str[5];
	result[8] = '\0';
}

// f_k function
void fk(char left[], char right[])
{

}

// xor implementation between two strings, same length
void xor(char *str1, char *str2)
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
	result[i] = '\0';
}
