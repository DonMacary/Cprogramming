/*********************************************************************
/   AUTHOR: ELF
/   COURSE: C Programming
/   PROGRAM NAME: perfLab7-45.c
/   PROGRAM DESCRIPTION: Performance Lab 7.5A - Nested Control Flow
/   INSTRUCTIONS:
		NESTED CONTROL FLOW
			Print all the even or odd numbers from 0 to 100.
			Prompt the user for input to indicate odds or evens.
			Loop from 0 to 100 and print all indicated numbers.
			Use and IF statement to check if even or odd.
		BONUS: Ask the user to continue with a DO-WHILE loop
			* write a version with the counting loop written as a FOR loop, and a WHILE loop version.

/*********************************************************************/

#include <stdio.h>

int main(void)
{
	char inputStr[5];
	int goodInput = 0;

	
	//ask user for either even or odds 
	do
	{
		printf("Enter either 'even' or 'odds': ");
		_flushall();
		if (fgets(inputStr, sizeof(inputStr), stdin) == NULL) 
		{
			printf("Error reading input! Try again\n");
		}
		
		if (strcmp(inputStr, "even") == 0 || strcmp(inputStr, "odds") == 0)
		{
			printf("%s\n", inputStr);
			goodInput = 1;
		}
		
		else
		{
			printf("Invalid input, please enter eithter 'even' or 'odds'\n");
		}
		if (!strchr(inputStr, '\n'))
		{
			while (fgetc(stdin) != '\n');
		}
		
	} while (goodInput == 0);

	//check if the user selected even
	if (strcmp(inputStr, "even") == 0)
	{
		//iterate 0100 and print the even numbers
		for (int i = 0; i < 101; i++)
		{
			if (i % 2 == 0) {
				printf("%d\n", i);

			}
		}
		
	}
	//check if the user selected odds
	else if (strcmp(inputStr, "odds") == 0)
	{
		//iterate 0-101 and print the odd numbers
		for (int i = 0; i < 101; i++)
		{
			if (i % 2 == 1) {
				printf("%d\n", i);

			}
		}

	}
	//if the user checked neither even or odds then exit
	else
	{
		printf("Invalid Input!\n");
	}
	

	while (1);
	return 0;

}