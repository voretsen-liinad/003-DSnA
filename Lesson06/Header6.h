//DSnA - Webinar 2 (14.05.2022)
//Header for lesson 6
//Created by Daniil Neserov (e-mail: maidanov1991@yandex.ru)

#include <stdio.h>
#include <stdlib.h>


int** init2dIntArray(int** array, const int row, const int col){
	array = (int**) calloc(sizeof(int*), row); 
	for (int i = 0; i < row; i++){
		*(array + i) = (int*) calloc(sizeof(int), col); 
	}
	return array; 
}

void print2dIntArray(int** array, const int row, const int col, int offset){
	char format[7]; 
	sprintf(format, "%%%dd", offset); 
	for (int i = 0; i < row; i++){
		for (int j = 0; j < col; j++){
			printf(format, *((*(array + i)) + j));
			if (j != col - 1)
				printf(","); 
		}
		printf("\n");
	}
	printf("\n"); 
}

void fill2dIntRandom(int** array, const int row, const int col, int border){
	for (int i = 0; i < row; i++){
		for (int j = 0; j < col; j++){
			*((*(array + i)) + j) = rand() % border;
		}
	}
}

void swapInt(int *a, int *b){
	int t = *a; 
	*a = *b; 
	*b = t;
}

void swapFloat(float *a, float *b){
	float t = *a; 
	*a = *b; 
	*b = t;
}
