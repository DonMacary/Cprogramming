/*********************************************************************
/   AUTHOR: ELF
/   COURSE: C Programming
/   PROGRAM NAME: perfLab7A.c
/   PROGRAM DESCRIPTION: Performance Lab 7A - If Statement
/   INSTRUCTIONS:
		IF STATEMENT
		Initialize a char array to zero.
		Safely store a user-input string in the char array.
		Safely print the string IF the following conditions are both true:
			The first element greater than or equal to decimal value 32.
			The first element is less than decimal value 126.
		NOTE: decimal values 32-126 represent printable ASCII characters

/*********************************************************************/

#include <stdio.h>

int main(void)
{
	//Initialize and zero a sting 
	char userInput[50] = { 0 };
	//ask user for string
	printf("Enter a string: ");
	//store user input
	fgets(userInput, sizeof(userInput), stdin);
	//if the first character of the string is a printable ASCII character print the string
	if (userInput[0] >= 32 && userInput[0] <= 126)
	{
		printf("Your string is: %s \n", userInput);
	}
	//debug - check if you made it past the if statement
	printf("End of code\n");
	return 0;

}