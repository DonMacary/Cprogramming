/*********************************************************************
/   AUTHOR: ELF
/   COURSE: C Programming 
/   PROGRAM NAME: perfLab6A.c
/   PROGRAM DESCRIPTION: Performance Lab 6A - Shift Left
/   INSTRUCTIONS:
        Input a uint32_t userInput from stdin utilizing fscanf()
        Initialize another uint32_t bitChecker to 0x01
        Use a Bitwise Shift Left on bitChecker to ensure only the left most bit is turned on
        Print the binary representation of userInput to stdout using only the following:
            fprintf()
            Bitwise Shift Right >>
            Bitwise AND &
            Relational Operator (e.g., >)
/*********************************************************************/

#include <stdio.h>
#include <inttypes.h>
int binary(uint32_t);

int main (void)
{
	//THIS WAS NOT COMPLETED!!!!
	 uint32_t userInt;
	 uint32_t bitChecker = 1;
	 printf("Please type an integer: ");
	 fscanf(stdin, "%u", &userInt);
	 printf("Your integer is %u (0x%.8X in hex)\n", userInt, userInt);
	 binary(userInt);
	 
}

int binary(uint32_t num)
{
	printf("This number in binary is ");
	unsigned i;
	for (i = 1 << (sizeof(num) * 8) - 1; i > 0; i = i / 2)
		(num & i) ? printf("1") : printf("0");
	printf("\n");
}