//DSnA - Webinar 3 (21.05.2022)
//Header for Lesson 10
//Created by Daniil Neserov (e-mail: maidanov1991@yandex.ru)
#include <stdio.h>
#include <stdlib.h>

#define T char
#define true 1 == 1
#define false 1 != 1

typedef int boolean;

typedef struct{
	T Data;
	struct Node *Next;
}TNode;

typedef struct{
	int Data;
	struct Node *Next;
}Node;

typedef struct{
	Node *Head;
	int Size;
}List;

void initList(List *lst){
	lst->Head = NULL;
	lst->Size = 0;
}

boolean push(List *stack, T value){
	TNode *new = (TNode*) malloc(sizeof(TNode));
	if (new == NULL){
		printf("Stack overflow\n");
		return false;
	}
	new->Data = value;
	new->Next = stack->Head;
	stack->Head = new;
	stack->Size++;
	return true;
}

T pop(List *stack){
	if (stack->Size == 0){
		printf("Stack is empty\n");
		return -1;
	}
	T data = stack->Head->Data;
	stack->Head = stack->Head->Next;
	stack->Size--;
	return data;
}

void insertNode(List *lst, int data){
	Node *new = (Node*) malloc(sizeof(Node));
	new->Data = data;
	new->Next = NULL;
	
	if (lst->Head == NULL){
		lst->Head = new;
	}
	else{
		Node *current = lst->Head;
		while (current->Next != NULL){
			current = current->Next;
		}
		current->Next = new; 
	}
	lst->Size++;
}

Node* removeNode(List *lst, int data){
	if (lst->Head == NULL)
		return NULL;
	
	Node *parent = NULL;
	Node *current = lst->Head;
	while (current->Next != NULL && current->Data != data){
		parent = current;
		current = current->Next;
	}
	if (current->Data != data)
		return NULL; 
	if (current == lst->Head)
		lst->Head = current->Next;
	else 
		parent->Next = current->Next;
	lst->Size--;
	return current;
}

void printNode(Node *n){
	if (n == NULL){
		printf("[] ");
		return;
	}
	printf("[%d] ", n->Data);
}

void printList(List *lst){
	Node *current = lst->Head;
	if (current == NULL)
		printNode(current);
	else{
		do{
			printNode(current);
			current = current->Next;
		}while (current != NULL);
	}
	printf(" Size: %d \n", lst->Size);
}
