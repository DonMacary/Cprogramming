/*********************************************************************
/   AUTHOR: ELF
/   COURSE: C Programming
/   PROGRAM NAME: perfLab7-4A.c
/   PROGRAM DESCRIPTION: Performance Lab 7.4A - Continue
/   INSTRUCTIONS:
		CONTINUE
		Input an unsigned integer "x".
		Print the first 20 positive integers that x is divisible by utilizing the mod operator (not the most efficient)
		Repeat this process.
		Immediately stop this process when the user inputs an integer above 999.
		Ignore any "divide by 0" errors using continue.

/*********************************************************************/

#include <stdio.h>

int main(void)
{
	unsigned int x; 
	int counter = 0; //tallys the number of divisible numbers
	int divideBy = 0; //the number to divide x by
	printf("Please enter a value for X (positive integer): ");
	scanf("%u", &x); //take in user input (no error checking here)
	//While the counter is less than 20 - keeping in mind that this is not a for loop and the last iteration will go to 20 and then it would 
	//exit, however since i am testing breaks i hard coded the exit condition
	while (counter < 20)
	{
		//stop running if the user puts in a number greater than 999
		if (x > 999)
		{
			printf("Cannot input a number greater than 999\n");
			break;
		}
		//skip the 0 condition
		if (divideBy == 0)
		{
			printf("Cannot divide by 0\n");
			divideBy++;
			continue;
		}
		//checking wheter or not x is divisible by a certain number
		if (x % divideBy == 0)
		{
			counter++;
			printf("%d.) %u is divisible by %d\n",counter, x, divideBy);
			
		}
		//if we have run through all possible numbers to divide x by then stop and report how many divisible numbers x has
		if (x == divideBy) {
			printf("%u is divisible by %d numbers", x, counter);
			break;
		}
		//if we have found the first 20 numbers x is divisible by stop and report it
		if (counter == 20)
		{
			printf("These are the first %d numbers %u is divisible by\n", counter, x);
			break;
		}
		divideBy++;
	}
	
	while (1);
	return 0;

}