/********************************************************************************************************************
/   AUTHOR: ELF
/   COURSE: C Programming
/   PROGRAM NAME: perfLab10B.c
/   PROGRAM DESCRIPTION: Performance Lab 10B - Conditional Compilation
/   INSTRUCTIONS:
		CONDITONAL COMPILATION
			Redefine EOF as 66 (without compiler warnings)
			Use preprocessor directive(s) to:
			Only compile in "release" and only compile if _INC_STDIO is defined
			Prints the name of a MACRO and also print the integer value of that MACRO
			Use a #else 'fall through' for ease of use and safety
			Use your preprocessor directives on FOPEN_MAX, FILENAME_MAX, and EOF
**********************************************************************************************************************/
#include <stdio.h>
#undef EOF //EFO is defined in stdio.h so we need to undefine it and redefine it
#define EOF (66)
#ifdef _INC_STDIO //if this is defined (it is in stdio.h) 
#	define PRINT_MACRO(x) {printf(#x " is %d \n", x); } //stringize the macro and output its integer value
#else
#endif



int main(void)
{
	//print out the following definitions and their values
	PRINT_MACRO(FOPEN_MAX);
	PRINT_MACRO(FILENAME_MAX);
	PRINT_MACRO(EOF); //expecting this to be 66 since we redefined

	while (1);
	return 0;
}