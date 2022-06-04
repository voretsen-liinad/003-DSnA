//DSnA - Webinar 4 (28.05.2022)
//Lesson 13
//Created by Daniil Neserov (e-mail: maidanov1991@yandex.ru)
#include "Header13.h"

//Task 1-----------------------------------------------------------------------	
void stackDepthTravers(int** matrix, const int dimension, int start_point){
	int* visited = (int*) calloc(sizeof(int), dimension);
	Stack* stack = (Stack*) malloc(sizeof(Stack));
	initStack(stack); 
	visited[start_point] = 1; 
	printf("Stack depth travers way started by %d: %d ", start_point, start_point);
	int next_point = start_point;
	int lim = dimension - 1;
	for (int i = 0; i < dimension; i++){
		if (visited[i] != 1 && matrix[next_point][i] == 1){
			start_point = next_point; 
			next_point = i;
			visited[next_point] = 1; 
			pushToStack(stack, start_point); 
			printf("%d ", next_point);
			i = -1;
		}
		else if (i == lim){
			if (stack->Size == 0)
					break;
			else 
				next_point = popFromStack(stack); 	
			i = -1;	
		} 
	}
	free (stack);
	free (visited);
}
//End of task 1----------------------------------------------------------------


//Task 2-----------------------------------------------------------------------
void widthTraversIncomingEdgesCounting(int** matrix, const int dimension, int start_point){
	int* incomingEdges = (int*) calloc(sizeof(int), dimension); 
	TwoLinkList *queue = (TwoLinkList*) malloc(sizeof(TwoLinkList));
	initTwoLinkList(queue);
	int* visited = (int*) calloc(sizeof(int), dimension);
	TwoLinkEnqueue(queue, start_point);
	printf("Width travers incoming edges counting starting from %d:\nWay: ", start_point); 
	for (int j = 0; j < dimension; j++){
		if (start_point != j && matrix[j][start_point] == 1)
			incomingEdges[start_point]++; 
	}	
	while(queue->Size > 0){
		int indx = TwoLinkDequeue(queue);
		if (visited[indx] == 1) 
			continue;
		visited[indx] = 1; 
		printf("%d ", indx);
		for (int i = 0; i < dimension; i++){
			if (matrix[indx][i] == 1 && indx != i){
				if (visited[i] == 0)
					TwoLinkEnqueue(queue, i);
				if (incomingEdges[i] == 0){
					for (int j = 0; j < dimension; j++){
					if (i != j && matrix[j][i] == 1)
						incomingEdges[i]++; 
					}
				}	
			}
		}
	}
	printf("\n");
	for (int i = 0; i < dimension; i++){
		if (visited[i] != 0)
			printf("Incoming edges number of vertex %d: %d\n", i, incomingEdges[i]);
	}
	printf("\n");
	free(visited);
	free(queue);
	free(incomingEdges); 
}

void matrixIncomingEdgesCounting(int** matrix, const int dimension){
	int* incomingEdges = (int*) calloc(sizeof(int), dimension);
	printf("Matrix incoming edges counter:\n"); 
	for (int i = 0; i < dimension; i++){
		for (int j = 0; j < dimension; j++){
			if (i != j && matrix[j][i] == 1)
				incomingEdges[i]++; 
		}
	}
	for (int i = 0; i < dimension; i++){
		printf("Incoming edges number of vertex %d: %d\n", i, incomingEdges[i]);
	}
	free(incomingEdges);
}
//End of task 2----------------------------------------------------------------


int main(const int argc, const char **argv){
	printf("Task 1.------------------------------------------------------------\n");
	const int DIMENSION = 6;
	int** matrix = init2dIntZeroArray(matrix, DIMENSION, DIMENSION);
	matrix[0][1] = 1;
	matrix[0][2] = 1;
	matrix[1][3] = 1;
	matrix[1][4] = 1;
	matrix[1][5] = 1;
	matrix[2][5] = 1;
	matrix[3][0] = 1;
	matrix[5][4] = 1;\
	
	/*We'll get matrix: 
	{{0, 1, 1, 0, 0, 0} ,
	 {0, 0, 0, 1, 1, 1} , 
	 {0, 0, 0, 0, 0, 1} , 
	 {1, 0, 0, 0, 0, 0} , 
	 {0, 0, 0, 0, 0, 0} , 
	 {0, 0, 0, 0, 1, 0} };
	*/
	
	printf("Matrix of dimension %d:\n", DIMENSION); 
	print2dIntArray(matrix, DIMENSION, DIMENSION, 2);
	stackDepthTravers(matrix, DIMENSION, 0);
	printf("\n");
	stackDepthTravers(matrix, DIMENSION, 2);
	printf("\n");

	printf("\n");
	
	printf("Task 2.------------------------------------------------------------\n");
	widthTraversIncomingEdgesCounting(matrix, DIMENSION, 1);
	widthTraversIncomingEdgesCounting(matrix, DIMENSION, 5);
	matrixIncomingEdgesCounting(matrix, DIMENSION);
	
	return 0;
}
