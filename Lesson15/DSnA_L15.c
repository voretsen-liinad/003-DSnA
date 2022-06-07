//DSnA - Webinar 5 (04.06.2022)
//Lesson 15
//Created by Daniil Neserov (e-mail: maidanov1991@yandex.ru)

#include <stdio.h>
#include <stdlib.h>

void printIntArray(int* array, int size, int offset){
	char format[7];
	sprintf(format, "%%%dd", offset); 
	for (int i = 0; i < size; i++){
		printf(format, array[i]); 
		if (i != size - 1) 
			printf(","); 
	}
	printf("\n"); 
}	

//Task 1-----------------------------------------------------------------------
int hashFunc(char *string){
	int result = 0;
	int i = 0;
	while (string[i]){
		result += (int)string[i];
		i++;
	}
	return result;
}
//End of task 1----------------------------------------------------------------


//Task 2-----------------------------------------------------------------------
int* coins_quantities(const int *coins_values_in_descending_order, const int number_of_coins_values, const int target_amount){
	int* result = (int*) calloc(sizeof(int), number_of_coins_values);
	if (target_amount <= 0){
		printf("Target amount %d is or less than 0\n", target_amount); 
		return result;
	}
	int remaining_amount = target_amount;
	int i = 0; 
	int lim = number_of_coins_values - 1;
	while (remaining_amount != 0 && i <= lim && coins_values_in_descending_order[i] > 0){
		result[i] = remaining_amount / coins_values_in_descending_order[i]; 
		remaining_amount -= result[i] * coins_values_in_descending_order[i]; 
		if (i == lim)
			break; 
		i++;
	}
	if (remaining_amount != 0){
		printf("Greedy algorithm not succeed (got only amount %d instead of target amount %d)\n", target_amount - remaining_amount, target_amount);
		return result; 
	}
	else{
		printf("Greedy algorithm succeed (got the target amount %d)\n", target_amount); 
		return result; 
	}
}
//End of task 2----------------------------------------------------------------


int main(const int argc, const char **argv){
	printf("Task 1.------------------------------------------------------------\n");
	char *str = "AbCdF19";
	printf("HashFunc(%s) = %d\n", str, hashFunc(str)); 
	printf("\n");
	
	
	printf("Task 2.------------------------------------------------------------\n");
	const int NUMBER_OF_COINS_VALUES = 5;
	int coins[NUMBER_OF_COINS_VALUES]; 
   	coins[0] = 50; 
	coins[1] = 10;
	coins[2] = 5;
	coins[3] = 2;
	coins[4] = 1;
	int target_amount = 98; 
	int *quantity = coins_quantities(coins, NUMBER_OF_COINS_VALUES, target_amount); 
	printf("Target amount:     %d\n", target_amount); 
	printf("Coins values:     "); printIntArray(coins, NUMBER_OF_COINS_VALUES, 3); 
	printf("Coins quantities: "); printIntArray(quantity, NUMBER_OF_COINS_VALUES, 3); 
	printf("\n");
	
	
	return 0;
}
