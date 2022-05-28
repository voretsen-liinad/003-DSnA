//DSnA - Webinar 3 (21.05.2022)
//Lesson 10
//Created by Daniil Neserov (e-mail: maidanov1991@yandex.ru)

#include "Header10.h"

//Task 1-----------------------------------------------------------------------
boolean checkBrackets(const char *string, int size){
	List *stack = (List*) malloc(sizeof(List));
	initList(stack);
	for (int i = 0; i < size; i++){
		if (string[i] == '(' || string[i] == '[' || string[i] == '{'){
			switch (string[i]){
				case '(':
					push(stack, ')');
					break;
				case '[':
					push(stack, ']');
					break;
				case '{':
					push(stack, '}');
					break;
				default:
					break;
			}
		}
		if (string[i] == ')' || string[i] == ']' || string[i] == '}'){
			if (stack->Size > 0){
				T close_bracket = pop(stack); 
				if (string[i] == close_bracket)
					continue;
				else{
					free(stack);
					return false;
				}				
			}
			else
				return false;
		}
		else
			continue;
	}
	if (stack->Size == 0)
		return true;
	else 
		return false;
}
//End of task 1----------------------------------------------------------------


//Task 2-----------------------------------------------------------------------
List* copyOneLinkIntList(List *list){
	List *copy_list = (List*) malloc(sizeof(List));
	initList(copy_list);
	
	if (list->Head == NULL)
		return copy_list;
	
	Node *current = list->Head; 
	while(current != NULL){
		insertNode(copy_list, current->Data);
		current = current->Next;
	}
	free(current);	
	return copy_list;
}
//End of task 2----------------------------------------------------------------


//Task 3-----------------------------------------------------------------------
boolean checkOneLinkIntListForSorting(List *list){
	if (list->Head == NULL || list->Head->Next == NULL)
		return true;
	
	Node *current = (Node*) malloc(sizeof(Node));
	Node *next = (Node*) malloc(sizeof(Node));
	current = list->Head;
	next = current->Next;
	boolean result = true;
	while(next != NULL){
		if (current->Data <= next->Data){
			current = next;
			next = next->Next;
		}
		else{
			result = false;
			break; 
		}
	}
	if (result == false){
		current = list->Head;
		next = current->Next;
		result = true;
		while(next != NULL){
			if (current->Data >= next->Data){
				current = next;
				next = next->Next;
			}
			else{
				result = false;
				break;
			}	
		}
	}	
	free(current);
	free(next);
	return result;
}
//End of task 2----------------------------------------------------------------


int main(const int argc, const char **argv){
	printf("Task 1.------------------------------------------------------------\n");
	const int SIZE = 255; 
	char *string = (char*) calloc(SIZE, sizeof(char)); 
	printf("Enter expression with brackets and without spaces: ");
	scanf("%s", string);
	printf("The brackets in expression are %s\n", checkBrackets(string, SIZE) ? "correct" : "incorrect");
	printf("\n");
	
	printf("Task 2.------------------------------------------------------------\n");
	List *lst = (List*) malloc(sizeof(List));
	initList(lst);
	insertNode(lst, 50);
	insertNode(lst, 222);
	insertNode(lst, 333);
	insertNode(lst, 44);
	insertNode(lst, 5);
	insertNode(lst, 5002);
	printf("Original list:\n");
	printList(lst);
	
	List *copy_lst = copyOneLinkIntList(lst);
	printf("Copy of original list:\n");
	printList(copy_lst);
	
	removeNode(lst, 222);
	removeNode(lst, 333);
	removeNode(lst, 5002);
	printf("Modified original list:\n");
	printList(lst);
	
	printf("Unmodified copy of original list:\n");
	printList(copy_lst);
	printf("\n");
	
	printf("Task 3.------------------------------------------------------------\n");
	printf("Current original list:\n");
	printList(lst);
	printf("Current original list %s\n", checkOneLinkIntListForSorting(lst) ? "sorted" : "is not sorted");
	printf("Current copy of original list:\n");
	printList(copy_lst);
	printf("Current copy of original list %s\n", checkOneLinkIntListForSorting(copy_lst) ? "sorted" : "is not sorted");
	
	return 0;
}
