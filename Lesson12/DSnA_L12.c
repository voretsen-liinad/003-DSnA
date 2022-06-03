//DSnA - Webinar 4 (28.05.2022)
//Lesson 12
//Created by Daniil Neserov (e-mail: maidanov1991@yandex.ru)
#include "Header12.h"

//Task 1-----------------------------------------------------------------------
int minTreeLevelsNumber(BinTreeNode *root){
	if (root == NULL)
		return 0;
	if (root->Left == NULL && root->Right == NULL) 
		return 1;
	else {
		if (root->Left != NULL && root->Right != NULL)
			return fmin(minTreeLevelsNumber(root->Left), minTreeLevelsNumber(root->Right)) + 1;
		else{
			if (root->Left != NULL)
				return minTreeLevelsNumber(root->Left) + 1;		
			else
				return minTreeLevelsNumber(root->Right) + 1;
		}		
	}
}

int maxTreeLevelsNumber(BinTreeNode *root){
	if (root == NULL)
		return 0;
	if (root->Left == NULL && root->Right == NULL) 
		return 1;
	else {
		if (root->Left != NULL && root->Right != NULL)
			return fmax(maxTreeLevelsNumber(root->Left), maxTreeLevelsNumber(root->Right)) + 1;
		else{
			if (root->Left != NULL)
				return maxTreeLevelsNumber(root->Left) + 1;		
			else
				return maxTreeLevelsNumber(root->Right) + 1;
		}		
	}
}

boolean isBinTreeBalanced(BinTreeNode *root){
	if (root == NULL || (root->Left == NULL && root->Right == NULL))
		return true;
	if (abs(maxTreeLevelsNumber(root) - minTreeLevelsNumber(root)) <= 1)
		return true;
	else
		return false; 
}

void CreateRandomIntBinTrees(BinTreeNode* arr[], const int size, const int number_of_nodes){
	srand(time(0));
	int balanced_trees_counter = 0;
	for (int i = 0; i < size; i++){
		arr[i] = NULL;
		arr[i] = treeInsert(arr[i], (rand() % 100));
		for (int j = 1; j < number_of_nodes; j++){
			treeInsert(arr[i], rand() % 100); 
		}			
		if (isBinTreeBalanced(arr[i])) 
			balanced_trees_counter++;
	}
	float balanced_trees_percentage = (float)balanced_trees_counter / (float)size * 100;
	printf("%2d bin trees of %4d nodes created\n", size, number_of_nodes); 
	printf("Balanced bin trees number is %2d\n", balanced_trees_counter);
	printf("Percentage of balanced bin trees is %.2f%%\n", balanced_trees_percentage);
}
//End of task 1----------------------------------------------------------------


//Task 2-----------------------------------------------------------------------
boolean binSearchInBinIntTree(BinTreeNode *root, const int value){
	if (root->Key == value)
		return true;
	if (value < root->Key){
		if (root->Left != NULL)
			return binSearchInBinIntTree(root->Left, value);
		else
			return false;
	}
	else{
		if (root->Right != NULL)
			return binSearchInBinIntTree(root->Right, value);
		else
			return false;
	}
}
//End of task 2----------------------------------------------------------------


int main(const int argc, const char **argv){
	printf("Task 1.------------------------------------------------------------\n");
	const int SIZE = 50;
	BinTreeNode* ArrayOfBinTrees[SIZE];
	const int NUMBER_Of_NODES = 1000;
	CreateRandomIntBinTrees(ArrayOfBinTrees, SIZE, NUMBER_Of_NODES);
	printf("\n");
	
	printf("Task 2.------------------------------------------------------------\n");
	BinTreeNode *tree = NULL;
	tree = treeInsert(tree, 90); 
	treeInsert(tree, 45);
	treeInsert(tree, 70);
	treeInsert(tree, 11);
	treeInsert(tree, 100);
	treeInsert(tree, 5);
	treeInsert(tree, 34);
	printf("Bin int tree created:\n");
	printBinTree(tree);
	printf("\n");
	printf("75 %s in the tree\n", binSearchInBinIntTree(tree, 71) ? "is" : "is not");
	printf("11 %s in the tree\n", binSearchInBinIntTree(tree, 11) ? "is" : "is not");
	
	return 0;	
}
