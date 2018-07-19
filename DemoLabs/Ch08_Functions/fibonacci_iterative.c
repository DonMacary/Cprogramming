#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main(void)
{
	int i = 0;
	int numberFibonacciNumbers = 0;
	int fibNumMinus2 = 0;
	int fibNumMinus1 = 1;
	int currentFibNum = 0;

	printf("How many Fibonacci numbers would you like to print? \n");
	_flushall();
	scanf("%d", &numberFibonacciNumbers);

	printf("******************\n");
	printf("FIBONACCI SEQUENCE\n");
	printf("******************\n");
	printf("%d\n%d\n", fibNumMinus2, fibNumMinus1);

	for (i = 0; i < numberFibonacciNumbers; i++)
	{
		currentFibNum = fibNumMinus1 + fibNumMinus2;
		printf("%d\n", currentFibNum);
		fibNumMinus2 = fibNumMinus1;
		fibNumMinus1 = currentFibNum;
	}

	getchar(); getchar();
	return 0;
}