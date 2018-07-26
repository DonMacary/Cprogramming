/********************************************************************************************************************
/   AUTHOR: ELF
/   COURSE: C Programming
/   PROGRAM NAME: perfLab10A.c
/   PROGRAM DESCRIPTION: Performance Lab 10A - Preprocessor Directives
/   INSTRUCTIONS:
		PREPROCESSOR DIRECTIVES
			Write a C program with preprocessor directives to:
			Combine two string literals
			Wrap those string literals in quotes
			Define a constant buffer size of 64
			Define an array:
			Of standard buffer size
			Assign the wrapped string literals to the array
			Print the array
**********************************************************************************************************************/
#include <stdio.h>
#define MAX_BUFFER 64
#define STRINGY(x) #x
#define WRAP_STRING(a) STRINGY(a) 
#define COMBINE_STRING(x,y) x##y
#define WRAP_COMBINE_STRING(a,b) COMBINE_STRING(a,b)
#define STR Im Mr. Meeseeks \ 
#define STR2 look at me!!!



int main(void)
{
	
	char resultArray[MAX_BUFFER] = WRAP_STRING(WRAP_COMBINE_STRING(STR, STR2));
	printf("Your Result is: \"%s\"", resultArray);
	while (1); 
	return 0;
}
