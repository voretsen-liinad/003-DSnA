//DSnA - Webinar 4 (28.05.2022)
//Header for Lesson 12
//Created by Daniil Neserov (e-mail: maidanov1991@yandex.ru)
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define true 1 == 1
#define false 1 != 1

typedef int boolean;

typedef struct BinTreeNode{
	int Key;
	struct BinTreeNode *Left;
	struct BinTreeNode *Right;
}BinTreeNode;

BinTreeNode* treeInsert(BinTreeNode *t, int data){
	BinTreeNode *newNode = (BinTreeNode*) malloc(sizeof(BinTreeNode));
	newNode->Key = data;
	newNode->Left = NULL;
	newNode->Right = NULL;

	if (t == NULL){
		t = newNode;
	}
	else{
		BinTreeNode *current = t;
		BinTreeNode *parent = t;
		while (current->Key != data){
			parent = current;
			if (current->Key > data){
				current = current->Left;
				if (current == NULL){
					parent->Left = newNode;
					return t;
				}
			}
			else{
				current = current->Right;
				if (current == NULL){
					parent->Right = newNode;
					return t;
				}
			}
		}
	}
	return t;
}


void printBinTree(BinTreeNode *root){
	if (root){
		printf("%d", root->Key);
		if (root->Left || root->Right){
			printf("(");
			if (root->Left)
				printBinTree(root->Left);
			else
				printf("NULL");
			printf(",");
			if (root->Right)
				printBinTree(root->Right);
			else
				printf("NULL");
			printf(")");
		}
	}
}

BinTreeNode* getSuccessor(BinTreeNode *node){
	BinTreeNode *current = node->Right;
	BinTreeNode *parent = node;
	BinTreeNode *s = node;
	
	while (current != NULL){
		parent = s;
		s = current;
		current = current->Left;
	}
	if (s != node->Right){
		parent->Left = s->Right;
		s->Right = node->Right;
	}
	return s;
}

boolean deleteNode(BinTreeNode *root, int Key){
	BinTreeNode *current = root;
	BinTreeNode *parent = root;
	boolean isLeftChild = true;
	
	while (current->Key != Key){
		parent = current;
		if (Key < current->Key){
			current = current->Left;
			isLeftChild = true;
		}
		else{
			current = current->Right;
			isLeftChild = false;
		}
		if (current == NULL)
			return false;
	}
	
	if (current->Left == NULL && current->Right == NULL){
		if (current == root)
			root = NULL;
		else if (isLeftChild)
			parent->Left = NULL;
		else 
			parent->Right = NULL;
	}
	else if (current->Right == NULL){
		if (isLeftChild)
			parent->Left = current->Left;
		else
			parent->Right = current->Left;
	}
	else if (current->Left == NULL){
		if (isLeftChild)
			parent->Left = current->Right;
		else
			parent->Right = current->Right;
	}
	else{
		BinTreeNode *successor = getSuccessor(current);
		if (current == root)
			root = successor;
		else if (isLeftChild)
			parent->Left = successor;
		else
			parent->Right = successor;
		successor->Left = current->Left;
	}
	return true;
}

