/********************************************************************************************************************
/   AUTHOR: ELF
/   COURSE: C Programming
/   PROGRAM NAME: Optimization.c
/   PROGRAM DESCRIPTION: Random Lab - Optimization Example
/   INSTRUCTIONS:
		The purpose of this lab is to show:
			A) Usage of time.h to show how long a function takes to run
			B) Optimizing a function to decrease the time it takes to run
		In my examples - I show the Fibonacci Sequence being run in 3 ways - The first two are Recursive functions run in two ways:
			The first runs it using a switch case
			The second runs it using an if block
		The third example shows an iterative function to print the fibonacci secuence

		This example shows how much more expensive it is to run recursive functions than iterative in C as well as how much faster using a switch case is. 
		I recommend using an iteration of at least 40 to really show the difference in computation
**********************************************************************************************************************/

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
#include <errno.h>
#include <time.h>

#ifndef ASSERR
#define ASSERR
#endif

clock_t start, end;
double cpu_time_used;
int fibonacci_number_switch(int sequenceNumber); //recusrive fibonacci function using a switch
int fibonacci_number_if(int sequenceNumber);	//recursive fibonacci function using an if
void error_reporting(int currentErrno);
int fibonacci_iterative(int sequenceNumber);	//iterarive fibonacci function



int main(void)
{
	int i = 0;
	int numberFibonacciNumbers = 0;
	int currentFibNum = 0;
	int currentErr = 0;
	//grab user input & error check it using assert
	printf("How many Fibonacci numbers would you like to print? \n");
	_flushall();
	scanf("%d", &numberFibonacciNumbers);
	currentErr = errno;
	if (currentErr != 0)
	{
		error_reporting(currentErr);
	}
#ifdef ASSERR
	assert(numberFibonacciNumbers > 0);
#endif

	//run the fibonacci sequence with the switch case
	start = clock(); //get the start clock time
	printf("************************************\n");
	printf("FIBONACCI SEQUENCE RECURSIVE SWITCH\n");
	printf("***********************************\n");
	for (i = 0; i < numberFibonacciNumbers; i++)
	{
		currentFibNum = fibonacci_number_switch(i);	//run the fibonacci recursive switch function 
		printf("%d\n", currentFibNum);

	}
	end = clock();	//grab the end clock time

	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC; // calculate how long the function by taking the difference in clock time and dividing it by your cpus clocks/sec
	printf("The recursive function took %lf seconds\n", cpu_time_used);

	//run the fibonacci sequence with the if case
	start = clock();	//get the start clock time
	printf("*******************************\n");
	printf("FIBONACCI SEQUENCE RECURSIVE IF\n");
	printf("*******************************\n");
	for (i = 0; i < numberFibonacciNumbers; i++)
	{
		currentFibNum = fibonacci_number_if(i); //run the fibonacci recursive if function
		printf("%d\n", currentFibNum);

	}
	end = clock();	//get the end clock time

	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC; // calculate how long the function by taking the difference in clock time and dividing it by your cpus clocks/sec
	printf("The recursive function took %lf seconds\n", cpu_time_used);

	start = clock(); //get the start clock time
	fibonacci_iterative(numberFibonacciNumbers); //run the fibonacci iterative function
	end = clock(); // get the end clock time
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	printf("The iterative function took %lf seconds\n", cpu_time_used);

	getchar(); getchar();
	return 0;
}

/*
*	Calculates the number in the fibonacci sequence recursively and uses a switch statement
*
*
*/
int fibonacci_number_switch(int sequenceNumber)
{
	int returnValue;
	switch (sequenceNumber)
	{
	case 0:
		returnValue = 0;
		break;
	case 1:
		returnValue = 1;
		break;
	default:
		returnValue = fibonacci_number_switch(sequenceNumber - 1) + fibonacci_number_switch(sequenceNumber - 2);
		break;
	}

	return returnValue;
}

/*
*	Calculate the fibonacci number and uses an if block
*
*/
int fibonacci_number_if(int sequenceNumber)
{
	int returnValue;

	if (sequenceNumber < 0)
	{
	returnValue = -1;
	}
	else if (0 == sequenceNumber)
	{
	returnValue = 0;
	}
	else if (1 == sequenceNumber)
	{
	returnValue = 1;
	}
	else
	{
	returnValue = fibonacci_number_if(sequenceNumber - 1) + fibonacci_number_if(sequenceNumber - 2);
	}

	return returnValue;
}

void error_reporting(int currErrno)
{
	if (currErrno)
	{
		perror(strerror(currErrno));
	}

	return;
}

/*
*	Calculate the fibonacci number iteratively.
*
*/
int fibonacci_iterative(int sequenceNumber)
{
	int fibNumMinus1 = 1;
	int fibNumMinus2 = 0;
	int currentFibNum = 0;
	printf("****************************\n");
	printf("FIBONACCI SEQUENCE ITERATIVE\n");
	printf("****************************\n");
	printf("%d\n%d\n", fibNumMinus2, fibNumMinus1);

	for (int i = 2; i < sequenceNumber; i++)
	{
		currentFibNum = fibNumMinus1 + fibNumMinus2;
		printf("%d\n", currentFibNum);
		fibNumMinus2 = fibNumMinus1;
		fibNumMinus1 = currentFibNum;
	}
	return 0;
}