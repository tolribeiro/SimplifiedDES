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
int convert_to_decimal(char *str);
void convert_to_binary(int num);
void p4(char *str);

char result[11]; // used for permutations: max is 10 (key) plus terminator character
char plaintext[9]; // compatible for strcpy
char left[5]; // 4 bits plus terminator character
char right[5];
char key[11]; // 10-bit size key plus terminator
char key1[9]; // 8-bit subkey1 plus terminator character	
char key2[9]; // 8-bit subkey2 plus terminator character
char temp[11]; // temporary variable to generate subkey k2
int s_0[4][4]; // s0 box
char s_1[4][4]; // s1 box
char tmp[3];
int row, column;
char S_str[3];
char buffer[5];
char p4_output[5];

int main()
{
	int i, tmp2, s0, s1;

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

	//strcpy(left, "1001");
	strcpy(left, "1011");
	expansion_permutation(left);
	printf("%s\n", result);
	strcpy(key, "10100010");
	xor(result, key);
	printf("%s\n", result);

	//sbox_s0
	tmp[0] = result[0];
	tmp[1] = result[3];
	tmp[2] = '\0';
	row = convert_to_decimal(tmp);
	printf("%d\n", row);
	tmp[0] = result[1];
	tmp[1] = result[2];
	tmp[2] = '\0';
	column = convert_to_decimal(tmp);
	printf("%d\n", column);
	sbox_s0();
	tmp2 = s_0[row][column];
	printf("%d\n", tmp2);
	s0 = tmp2;
	//sbox_s1
	tmp[0] = result[4];
	tmp[1] = result[7];
	tmp[2] = '\0';
	row = convert_to_decimal(tmp);
	printf("%d\n", row);
	tmp[0] = result[5];
	tmp[1] = result[6];
	tmp[2] = '\0';
	column = convert_to_decimal(tmp);
	printf("%d\n", column);
	sbox_s1();
	tmp2 = s_1[row][column];
	printf("%d\n", tmp2);
	s1 = tmp2;
	printf("%d %d\n", s0, s1);
	convert_to_binary(s0);
	strcpy(buffer, S_str);
	convert_to_binary(s1);
	strcat(buffer, S_str);
	strcpy(p4_output, buffer);
	printf("%s\n", p4_output);
	p4(p4_output);
	printf("%s\n", p4_output);
	/*
	S_str[0] = (char)(((int)'0')+s0);
	S_str[1] = (char)(((int)'0')+s1);
	S_str[2] = '\0';
	printf("%c %c\n", S_str[0], S_str[1]);*/
	//printf("%c, %c\n", result[1], result[2]);
	
	return 0;
}



int convert_to_decimal(char *str)
{
	if(strlen(str)!=2)
	return -1;

	if (strcmp(str,"00")==0)
	return 0;

	if (strcmp(str,"01")==0)
	return 1;

	if (strcmp(str,"10")==0)
	return 2;

	if (strcmp(str,"11")==0)
	return 3;

	return -1;
}

void convert_to_binary(int num)
{
	if(num==0)
	strcpy(S_str,"00");

	if(num==1)
	strcpy(S_str,"01");

	if(num==2)
	strcpy(S_str,"10");

	if(num==3)
	strcpy(S_str,"11");
}


void sbox_s0()
{
	int i, j, k = 0;
	int item[16] = {1, 0, 3, 2,
					3, 2, 1, 0,
					0, 2, 1, 3,
					3, 1, 3, 2};

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			s_0[i][j] = item[k];
			k++;
		}
	}
}

void sbox_s1()
{
	int i, j, k = 0;
	int item[16] = {0, 1, 2, 3,
					2, 0, 1, 3,
					3, 0, 1, 0,
					2, 1, 0, 3};

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			s_1[i][j] = item[k];
			k++;
		}
	}
}

void p4(char *str)
{
	p4_output[0] = buffer[1];
	p4_output[1] = buffer[3];	
	p4_output[2] = buffer[2];
	p4_output[3] = buffer[0];
	p4_output[4] = '\0';
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
