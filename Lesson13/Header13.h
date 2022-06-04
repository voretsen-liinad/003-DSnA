//DSnA - Webinar 4 (28.05.2022)
//Header for Lesson 13
//Created by Daniil Neserov (e-mail: maidanov1991@yandex.ru)
#include <stdio.h>
#include <stdlib.h>

#define true 1 == 1
#define false 1 != 1

typedef int boolean;

typedef struct Node{
	int Data;
	struct Node *Next;
} Node;

typedef struct Stack{
	Node *Head;
	int Size;
} Stack;

void initStack(Stack *stack){
	stack->Head = NULL;
	stack->Size = 0;
}

boolean pushToStack(Stack *stack, int value){
	Node *temp = (Node*) malloc(sizeof(Node));
	if (temp == NULL){
		printf("Stasck overflow\n");
		return false;
	}
	temp->Data = value;
	temp->Next = stack->Head;
	stack->Head = temp; 
	stack->Size++;
	return true;
}

int popFromStack(Stack *stack){
	if (stack->Size == 0){
		printf("Stack is empty\n");
		return -1;
	}
	Node *temp = stack->Head;
	int data = stack->Head->Data;
	stack->Head = stack->Head->Next;
	free(temp);
	stack->Size--;
	return data;
}

typedef struct TwoLinkNode{
	int Data;
	struct TwoLinkNode *Prev;
	struct TwoLinkNode *Next;
} TwoLinkNode;

typedef struct TwoLinkList{
	TwoLinkNode *Head;
	TwoLinkNode *Tail;
	int Size;
} TwoLinkList;

void initTwoLinkList(TwoLinkList *lst){
	lst->Head = NULL;
	lst->Tail = NULL;
	lst->Size = 0;
}

boolean TwoLinkEnqueue(TwoLinkList *queue, int value){
	TwoLinkNode *temp = (TwoLinkNode*) malloc(sizeof(TwoLinkNode));
	if (temp == NULL){
		printf("Out of memory!\n");
		return false;
	}
	temp->Data = value;
	temp->Next = NULL;
	temp->Prev = queue->Tail; 
	
	if (queue->Head == NULL)
		queue->Head = temp;
	
	if (queue->Tail != NULL)
		queue->Tail->Next = temp;
	
	queue->Tail = temp;
	queue->Size++;
	return true; 
}

int TwoLinkDequeue(TwoLinkList *queue){
	if (queue->Size == 0){
		printf("Queue is empty\n");
		return -1;
	}
	TwoLinkNode *temp = queue->Head;
	int data = queue->Head->Data;
	queue->Head = queue->Head->Next;
	
	if (queue->Head != NULL)
		queue->Head->Prev = NULL; 
	if (temp == queue->Tail)
		queue->Tail = NULL; 
	
	free(temp);
	queue->Size--;
	return data;
}

int** init2dIntZeroArray(int** array, const int row, const int col){
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
