//DSnA - Webinar 2 (14.05.2022)
//Lesson 6
//Created by Daniil Neserov (e-mail: maidanov1991@yandex.ru)
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Header6.h"

//Task 1-----------------------------------------------------------------------
void bubble2dIntSort(int** arr, const int row, const int col){
	int lim = row * col; 
	for (int k = 0; k < lim; k++){
		for (int i = 0; i < row; i++){
			for (int j = 0; j < col - 1; j++){
				if (arr[i][j] > arr[i][j + 1])
					swapInt(&arr[i][j], &arr[i][j + 1]); 
			}
			if ((i < (row - 1)) && (arr[i][col - 1] > arr[i + 1][0])) 
				swapInt(&arr[i][col - 1], &arr[i + 1][0]);
		}	
	}	
}
//End of task 1----------------------------------------------------------------

//Task 2-----------------------------------------------------------------------
void TPK(){
	float* array = (float*) calloc(sizeof(float), 11); 
	for (int i = 0; i < 11; i++){
		printf("Enter number #%2d: ", i + 1); 
		scanf("%f", &array[i]); 
	}
	for (int i = 0; i < 6; i++){
		swapFloat(&array[i], &array[11 - 1 - i]);
	}
	printf("\n");
	for (int i = 0; i < 11; i++){
		float result = sqrt(fabs(array[i])) + 5 * pow(array[i], 3); 
		printf("result[%2d]: ", i + 1); 
		(result <= 400) ? printf("%f\n", result) : printf("is more than 400\n"); 
	}
	printf("\n");
}
//End of task 2----------------------------------------------------------------

int main(const int argc, const char** argv){
	printf("Task 1.------------------------------------------------------------\n"); 
	const int ROW = 5;
	const int COL = 5;
	int** Array = init2dIntArray(Array, ROW, COL);
	fill2dIntRandom(Array, ROW, COL, 100); 
	printf("Array[%d][%d] before sorting:\n", ROW, COL);
	print2dIntArray(Array, ROW, COL, 3); 
	bubble2dIntSort(Array, ROW, COL);
	printf("Array[%d][%d] after sorting:\n", ROW, COL);
	print2dIntArray(Array, ROW, COL, 3); 
	
	printf("Task 2.------------------------------------------------------------\n"); 
	TPK();
	return 0;
}
