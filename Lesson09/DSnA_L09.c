//DSnA - Webinar 3 (21.05.2022)
//Lesson 9
//Created by Daniil Neserov (e-mail: maidanov1991@yandex.ru)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define Q_SIZE 10

#define S_SIZE 255
#define S int
#define true 1 == 1
#define false 1 != 1

//Task 1-----------------------------------------------------------------------
typedef struct{
	int Priority;
	int Data;
} Unit;

Unit* Queue[Q_SIZE];
int head;
int tail;
int items;

void initQueue(){
	for (int i = 0; i < Q_SIZE; i++){
		Queue[i] = NULL;
	}
	head = 0;
	tail = 0;
	items = 0;
}

void simpleEnqueue(int priority, int data){
	if (items == Q_SIZE){
		printf("%s \n", "Queue is full");
		return;
	}
	
	Unit *unit = (Unit*) malloc(sizeof(Unit));
	(*unit).Priority = priority;
	(*unit).Data = data; 
	
	Queue[tail++] = unit; 
	items++;
}

Unit* priorityDequeue(){
	if (items == 0){
		printf("%s \n", "Queue is empty");
		return 0;
	}
	
	int firstPriority = head;
	if (items > 1){
		for (int i = head + 1; i < tail; i++){
			if ((*Queue[i % Q_SIZE]).Priority < (*Queue[firstPriority % Q_SIZE]).Priority)
				firstPriority = i;
		}
	}
	
	Unit *result = Queue[firstPriority % Q_SIZE]; 
	
	for (int i = firstPriority + 1; i < tail; i++){
		Queue[(i - 1) % Q_SIZE] = Queue[i % Q_SIZE]; 
	}
	tail--; 
	Queue[tail % Q_SIZE] = NULL; 
	items--;
	return result;
}

void printQueue(){
	printf("[ ");
	for (int i = 0; i < Q_SIZE; i++){
		if (Queue[i] == NULL) 
			printf("[*, *] ");
		else 
			printf("[%d, %d] ", (*Queue[i]).Priority, (*Queue[i]).Data);
	}
	printf(" ]\n"); 
}
//End of task 1----------------------------------------------------------------


//Task 2-----------------------------------------------------------------------
typedef int boolean;

S Stack[S_SIZE];
int cursor = -1;

boolean addToStack(S data){
	if (cursor < S_SIZE){
		Stack[++cursor] = data;
		return true;
	}
	else{
		printf("%s \n", "Stack overflow"); 
		return false;
	}				
}

S popFromStack(){
	if (cursor != -1)
		return Stack[cursor--]; 
	else{
		printf("%s \n", "Stack is empty");
		return -1;
	}
}

void positiveIntToBinConversion(int number){
	if (number < 0){
		printf("Error: number is not positive");
		return;
	}
	
	if (number == 0){
		printf("0"); 
		return;
	}
	
	if (number == 1)
		addToStack(1);
	else{
		if (number % 2 == 1)
			addToStack(1);
		else 
			addToStack(0);
		positiveIntToBinConversion(number / 2);
	}		
	
	printf("%d", popFromStack());
}

//End of task 2----------------------------------------------------------------


int main(const int argc, const char** argv){
	printf("Task 1.------------------------------------------------------------\n"); 
	printf("%s \n", "Queue initialization:");
	initQueue();
	printQueue();
	printf("\n");
	
	printf("%s \n", "Enqueue 8 elements:");
	srand(time(0));
	for (int i = 0; i < 8; i++){
		simpleEnqueue(rand() % 20, rand() % 100);
	}
	printQueue();
	printf("\n");
	
	printf("%s \n", "Dequeue 3 elements:");
	for (int i = 0; i < 3; i++){
		priorityDequeue();
	}
	printQueue();
	printf("\n");
	
	printf("%s \n", "Enqueue 7 elements:");
	srand(time(0));
	for (int i = 0; i < 7; i++){
		simpleEnqueue(rand() % 20, rand() % 100);
	}
	printQueue();
	printf("\n");
	
	printf("%s \n", "Dequeue 5 elements:");
	for (int i = 0; i < 5; i++){
		priorityDequeue();
	}
	printQueue();
	printf("\n");
	
	printf("%s \n", "Dequeue 8 elements:");
	for (int i = 0; i < 8; i++){
		priorityDequeue();
	}
	printQueue();
	printf("\n");
	
	printf("\n");
	
	
	printf("Task 2.------------------------------------------------------------\n"); 
	printf("Enter positive decimal integer to binary conversion: ");
	int number;
	scanf("%d", &number);
	printf("Conversion result: ");
	positiveIntToBinConversion(number);
	printf("\n");
	
	printf("\n");
	
	
	return 0;
}
