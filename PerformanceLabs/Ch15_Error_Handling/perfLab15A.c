/********************************************************************************************************************
/   AUTHOR: ELF
/   COURSE: C Programming
/   PROGRAM NAME: perfLab15A.c
/   PROGRAM DESCRIPTION: Performance lab A - Walk The String
/   INSTRUCTIONS:
READ A STRING AND WRITE IT TO A ZEROIZED CHAR ARRAY.
USE ASSERT() TO VERIFY THE LAST ELEMENT OF THE CHAR ARRAY IS NUL.
STEP #1- SAFELY WRITE TO THE ARRAY.
STEP #2- BREAK ASSERT() BY UNSAFELY READING INPUT INTO THE CHAR ARRAY.
**********************************************************************************************************************/

#include <stdio.h>
#include <assert.h>

int main(void)
{

	//safely reading a character array
	char string1[15] = { 0 };
	char string2[16] = { 0 };
	printf("Print a string: ");
	fgets(string2, sizeof(string2), stdin);

	strcpy(string1, string2);
	//If you write more than 15 characters in to the string we will have an error here - showing that there is bad code because we are writing a string of size 16
	//into a string of sie 15 - this overwrites the null character and gives us an error
	assert(string1[14] == '\0');

	printf("%s\n", string1);
	while (1);
	return 0;
}