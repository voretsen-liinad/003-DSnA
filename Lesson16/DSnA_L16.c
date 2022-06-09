//DSnA - Webinar 5 (04.06.2022)
//Lesson 16
//Created by Daniil Neserov (e-mail: maidanov1991@yandex.ru)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Task 1-----------------------------------------------------------------------
char* CaesarCipherEncryption(const char *eng_string, const int key){
	int shift = (key >= 0) ? key % 26 : -((-key) % 26);
	if (shift == 0) 
		return eng_string;
	int size = strlen(eng_string);
	char* result = (char*) calloc(sizeof(char), size);
	char *alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"; 
	int i = 0; 
	int j;
	int start;
	int current_char_code;
	while(i < size){
		current_char_code = (int)eng_string[i]; 
		if ((current_char_code >= 65 && current_char_code <= 90) || 
			(current_char_code >= 97 && current_char_code <= 122)){
			if (current_char_code >= 65 && current_char_code <= 90){
				j = 0; 
				start = 0;
			}
			else{
				j = 26; 
				start = 26;
			}
			while(eng_string[i] != alphabet[j]){
				j++;
			}
			if (shift >= 0)
				j = start + (j + shift) % 26; 
			else 
				j = start + (j + shift + 26) % 26;  
			result[i] = alphabet[j]; 
		} 
		else{
			result[i] = eng_string[i];
		}
		i++;
	}
	free(alphabet);
	return result;
}

char* CaesarCipherDecryption(const char *eng_string, const int key){
	return CaesarCipherEncryption(eng_string, (-key));
}
//End of task 1----------------------------------------------------------------


//Task 2-----------------------------------------------------------------------
char* permutationCipherEncription(const char *string, const int columns){
	if (columns <= 1){
		if (columns <= 0) 
			printf("Error: number of columns is or less than 0\n");
		return string;
	}
	int len = strlen(string); 
	int rows = ((len % columns) == 0) ? (len / columns) : (len / columns + 1);
	len = rows * columns;
	char* result = (char*) calloc(sizeof(char), len + 1);
	int i = 0;
	int j;
	int index = 0;
	while (i < columns){
		j = i;
		while (j < len){
			if (string[j])
				result[index++] = string[j];
			else 
				result[index++] = ' '; 
			j += columns; 
		}
		i++;
	}
	result[index] = '\0';
	return result;
}
	
char* permutationCipherDecription(const char *string, const int columns){
	int len = strlen(string); 
	int rows = ((len % columns) == 0) ? (len / columns) : (len / columns + 1);
	return permutationCipherEncription(string, rows);
}
//End of task 2----------------------------------------------------------------


int main(const int argc, const char **argv){
	printf("Task 1.------------------------------------------------------------\n");
	char *str = "This is a message!"; 
	int key = 11;
	printf("Caesar cipher encryption (key = %d):\n", key);
	printf("       Input string: %s\n", str);
	char *enc_str = CaesarCipherEncryption(str, key); 
	printf("   Encrypted string: %s\n", enc_str);
	printf("Caesar cipher decryption (key = %d):\n", key);
	printf("       Input string: %s\n", enc_str);
	printf("   Decrypted string: %s\n", CaesarCipherDecryption(enc_str, key));
	printf("\n"); 
	
	printf("Task 2.------------------------------------------------------------\n");
	char *str2 = "Another text message :)"; 
	int columns = 4;
	printf("Permutation cipher encryption (number of columns = %d):\n", columns);
	printf("       Input string: %s\n", str2);
	char *enc_str2 = permutationCipherEncription(str2, columns); 
	printf("   Encrypted string: %s\n", enc_str2); 
	printf("Permutation cipher decryption (number of columns = %d):\n", columns);
	printf("       Input string: %s\n", enc_str2);
	printf("   Decrypted string: %s\n", permutationCipherDecription(enc_str2, columns));
	printf("\n"); 
	
	return 0;
}
