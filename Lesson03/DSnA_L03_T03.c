//DSnA - Webinar 1 (23.04.2022)
//Lesson 3 - Task 3
//Created by Daniil Neserov (e-mail: maidanov1991@yandex.ru)

#include <stdio.h>
#include <math.h>

int IsPrime(int n) //if the argument is prime then the function returns 1, else - return 0
{
	int result = 0; 
	if (n < 2 || (n != 2 && ((n % 2) == 0))) return result; 
	if (n == 2) result = 1; 
	else
	{
		float sqrt_n =  sqrt(n); 
		int limit = (int)sqrt_n + 1; 
		for (int i = 3; i <= limit; i += 2)
		{
			if (n != i && ((n % i) == 0)) return result; 
		}
		result = 1; 
	}
	return result; 
}

int main(const int argc, const char** argv)
{
	int n; 
	do 
	{
		printf("%s", "Enter positive integer more than 1: "); 
		scanf("%d", &n); 
	} while (n < 2); 
	if (IsPrime(n) == 1) printf("The number %d is prime\n", n);
	else printf("The number %d is not prime\n", n); 
	return 0;
}
