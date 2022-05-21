//DSnA - Webinar 2 (14.05.2022)
//Lesson 7
//Created by Daniil Neserov (e-mail: maidanov1991@yandex.ru)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fillIntRandom(int* arr, int len, int border){
	srand(time(0));
	for (int i = 0; i < len; i++){
		arr[i] = rand() % border;
	}
}

void printIntArray(int* arr, int len, int offset){
	char format[7]; 
	sprintf(format, "%%%dd", offset);
	for (int i = 0; i < len; i++){
		printf(format, arr[i]);
		if (i != (len - 1))
			printf(",");
	}
	printf("\n");
}

void swapInt(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}


//Task 1-----------------------------------------------------------------------
void improvedQSort(int* arr, int first, int last){
	if ((last - first + 1) <= 10){
		int temp, pos;
		for (int i = first + 1; i <= last; i++){
			temp = arr[i];
			pos = i - 1;
			while (pos >= first && arr[pos] > temp){
				arr[pos + 1] = arr[pos];
				pos--;
			}
			arr[pos + 1] = temp;
		}
	}	
	else{
		int mid = (first + last) / 2;
		if (arr[first] >= arr[mid] && arr[last] >= arr[mid]){
			if (arr[first] < arr[last]) 
				swapInt(&arr[first], &arr[mid]);
			else
				swapInt(&arr[last], &arr[mid]);
		}
		else if (arr[first] <= arr[mid] && arr[last] <= arr[mid]){
			if (arr[first] > arr[last]) 
				swapInt(&arr[first], &arr[mid]);
			else
				swapInt(&arr[last], &arr[mid]);
		}
		
		int i = first;
		int j = last;
		int x = arr[mid]; 
		do{
			while (arr[i] < x) i++;
			while (arr[j] > x) j--;
			if (i <= j){
				swapInt(&arr[i++],&arr[j--]);
			}
		}while (i <= j);
		if (first < j) improvedQSort(arr, first, j);	
		if (i < last) improvedQSort(arr, i, last);
	}
}
//End of task 1----------------------------------------------------------------

//Task 2-----------------------------------------------------------------------
void evenBucketSort(int* arr, int len){
	const int max = len;
	const int b = 10; 
	
	int** buckets = (int**) calloc(b, sizeof(int*));
	for (int i = 0; i < b; i++){
		buckets[i] = (int*) calloc(max + 1, sizeof(int));
	}
	
	for (int digit = 1; digit < 1000000000; digit *= 10){
		for (int i = 0; i < max; i++){
			if (arr[i] % 2 != 0)
				continue;
			int d = (arr[i] / digit) % b; 
			buckets[d][buckets[d][max]++] = arr[i];	
		}
		int indx = 0; 
		for (int i = 0; i < b; i++){
			for (int j = 0; j < buckets[i][max]; j++){
				if (arr[indx] % 2 != 0){
					indx++;
					j--;
					continue;
				}
				arr[indx++] = buckets[i][j];
			}
			buckets[i][max] = 0;
		}
	}
}
//End of task 2----------------------------------------------------------------

int main(const int argc, const char** argv){
	printf("Task 1.------------------------------------------------------------\n"); 
	const int SIZE = 25;
	int Array_1[SIZE]; 
	fillIntRandom(Array_1, SIZE, 100);
	
	printf("Array_1[%d] before improvedQSort():\n", SIZE); 
	printIntArray(Array_1, SIZE, 3);
	
	improvedQSort(Array_1, 0, SIZE - 1);
	printf("Array_1[%d] after improvedQSort():\n", SIZE); 
	printIntArray(Array_1, SIZE, 3);
	printf("\n");
	
	printf("Task 2.------------------------------------------------------------\n"); 
	const int SIZE_2 = 30;
	int Array_2[SIZE_2]; 
	fillIntRandom(Array_2, SIZE_2, 100);
	
	printf("Array_2[%d] before evenBucketSort():\n", SIZE_2); 
	printIntArray(Array_2, SIZE_2, 3);
	
	evenBucketSort(Array_2, SIZE_2);
	printf("Array_2[%d] after evenBucketSort():\n", SIZE_2); 
	printIntArray(Array_2, SIZE_2, 3);
	printf("\n");
	
	return 0;
}
