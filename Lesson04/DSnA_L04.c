//DSnA - Webinar 1 (23.04.2022)
//Lesson 4
//Created by Daniil Neserov (e-mail: maidanov1991@yandex.ru)

#include <stdio.h>

float nPow(float, int); 
float nPow2(float, int); 

//Task 1-----------------------------------------------------------------------
void printBin20(int n)
{
	int isStarted = 0; 
	int remainder = n; 
	for (int i = 19; i >=0; i--)
	{
		int digit = 0; 
		int currentTwoPow = (int)nPow2(2, i); 
		if ((remainder - currentTwoPow) >= 0) 
		{
			isStarted = 1; 
			digit = 1; 
			remainder -= currentTwoPow;
		}
		if (isStarted == 1 || i == 0) printf("%d", digit); 
	}
	printf("\n");
}
//End of task 1----------------------------------------------------------------


//Task 2-----------------------------------------------------------------------
float nPow(float n, int p)
{
	if (p == 0) return 1;
	return (p > 0) ? n * nPow(n, p - 1) : 1 / (n * nPow(n, -p - 1));
}
//End of task 2----------------------------------------------------------------


//Task 3-----------------------------------------------------------------------
float nPow2(float n, int p)
{
	if (p == 0) return 1; 
	if (p > 0) return ((p % 2) == 0) ? nPow2(n * n, p / 2) : n * nPow2(n, p - 1); 
	else return ((-p % 2) == 0) ? 1 / nPow2(n * n, -p / 2) : 1 / (n * nPow2(n, -p - 1));
}
//End of task 3----------------------------------------------------------------


//Task 4-----------------------------------------------------------------------
#define HEIGHT 8
#define WIDTH 8

int board[HEIGHT][WIDTH]; 

void clearBoard()
{
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)	
		{
			board[i][j] = 0;
		}			
	}
}

void printBoard()
{
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			printf ("%5d", board[i][j]); 
		}
		printf("\n"); 
	}
}

int routesTo(int x, int y)
{
	if (x == 0 && y == 0 || board[y][x] != 0) return 0; 
	if (x == 0)
	{
		for (int i = 0; i < y; i++)
		{
			if (board[i][x] != 0) return 0;
		}	
		return 1;
	}
	if (y == 0) 
	{
		for (int j = 0; j < x; j++)
		{
			if (board[y][j] != 0) return 0; 
		}
		return 1; 
	}
	if (routesTo(x - 1, y) == 0) return routesTo(x, y - 1); 
	if (routesTo(x, y - 1) == 0) return routesTo(x - 1, y);
	if (board[y][x - 1] != 0) return routesTo(x, y - 1) + 1; 
	if (board[y - 1][x] != 0) return routesTo(x - 1, y) + 1; 
	return routesTo(x - 1, y) + routesTo(x, y - 1); 
}
//End of task 4----------------------------------------------------------------


int main(const int argc, const char** argv)
{
	printf("Task 1.------------------------------------------------------------\n"); 
	int num1; 
	do
	{
		printf("Enter an integer number from 0 to 1 048 575: "); 
    	scanf("%d", &num1); 
	} while (num1 < 0 || num1 > 1048575); 
	printf("The binary form of the decimal number %d is ", num1);
	printBin20(num1); 
	printf("\n"); 
	
	printf("Task 2.------------------------------------------------------------\n"); 
	float num2;
	int p; 
	printf("Enter a number: "); 
	scanf("%f", &num2); 
	printf("Enter an integer exponent: "); 
	scanf("%d", &p); 
	printf("%f ^ %d = %f (counted by function from Task 2) \n", num2, p, nPow(num2, p));
	printf("\n");
	
	printf("Task 3.------------------------------------------------------------\n"); 
	printf("%f ^ %d = %f (counted by function from Task 3) \n", num2, p, nPow2(num2, p));
	printf("\n");
	
	printf("Task 4.------------------------------------------------------------\n"); 
	clearBoard(); 
	//determine occupied cells
	board[1][0] = 1; 
	board[0][5] = 1;
	board[6][6] = 1;
	printf("Board for Task 4: \n"); 
	printBoard(); 
	printf("\nRoutes calculation for Task 4: \n"); 
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			printf("%5d", routesTo(j, i));  
		}
		printf("\n");
	}
	printf("\n");
	
	return 0;
}
