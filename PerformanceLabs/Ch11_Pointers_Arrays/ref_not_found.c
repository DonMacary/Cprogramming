/*********************************************************************
/   AUTHOR: ELF
/   COURSE: C Programming
/   PROGRAM NAME: perfLab8A.c
/   PROGRAM DESCRIPTION: Performance Lab 8A - Functions
/   INSTRUCTIONS:


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////// MQT (I.5.A) PERFORMANCE LAB 1 ////////////////////////////////////////////
///////////////////////////////////////////////// MEMORY OPERATORS //////////////////////////////////////////////////
////////////////////////////////////////////// "Reference Not Found" ////////////////////////////////////////////////
/////////////////////////////////////////////// Instructor Solution /////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Declare userInput, tempValue, and input_ptr as the same data type (and input_ptr should be a pointer variable)
// Read user input into variable userInput
// Ensure tempValue contains the same value as userInput utilizing one or more memory operators
//     tempValue = userInput;  // NOT PERMITTED... use a memory operator
// Print the value *and* the pointer for each of the three variables in a human-readable format
// Locate those addresses in the "memory window"
// Summon your instructor
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*********************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define HUMAN_READABLE_CHAR(printChar) printf(#printChar " has a value of %c(%d) at pointer %p.\n", printChar, (int)printChar, &printChar)
#define HUMAN_READABLE_POINTER(printPointer) printf(#printPointer " has a value of %p which is stored at pointer %p.\n", printPointer, &printPointer)

int main(void)
{
	/* Declare userInput, tempValue, and input_ptr as the same data type (and input_ptr should be a pointer variable) */
	int userInput, tempValue;
	int *inputPtr;
	int goodIn = 1;
	char strInput[10];
	/* Read user input into variable userInput */
	printf("Enter a number: ");
		while (goodIn == 1)
	{
		printf("Type the integer value of the first leg: ");
		//take in input using fgets
		fgets(strInput, sizeof(strInput), stdin);
		//convert input to an integer
		userInput = atoi(strInput);
		//error checking - note atoi converts everything that isnt a number to 0 so this correctly input checks letters and special characters!
		if (userInput <= 0) {
			printf("You must enter a number greater than 0\n");
		}
		else if (!strchr(strInput, '\n'))
		{
			printf("Too many characters!\n");
			while (fgetc(stdin) != '\n');
		}
		else {
			goodIn = 0;
		}
		

	}

	/* Ensure tempValue contains the same value as userInput utilizing one or more memory operators */


	/* Print the value *and* the pointer for each of the three variables in a human-readable format */


	return 0;
}
