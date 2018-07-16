///////////////////////////////////////////////////////////////////////////////
/////////////////////////DEMONSTRATION LAB I.1.g-6 ////////////////////////////
///////////////////////////////////////////////////////////////////////////////
// Input a uint32_t
// Drop the four right-most bits off the uint32_t using a Bitwise Shift Right
// Replace the four left-most bits of the uint32_t with the dropped bits
// Print the I/O in uppercase Hexadecimal, field width 8, leading zeros
///////////////////////////////////////////////////////////////////////////////


#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <inttypes.h>
#define solution4 // This source file contains four solutions to the given Demonstration Lab
#ifdef solution3
#include <math.h>
#endif

int main(void)
{
	uint32_t inputNumber = 0;
	uint32_t transitionNumber = 0;
	printf("Input a positive number:  ");
	//_flushall();
	scanf("%u", &inputNumber);

	printf("Your number was %u (Hex: 0x%08X) \n", inputNumber, inputNumber);

#ifdef solution1
	{
		printf("Solution #1: \n");
		printf("\tA. Copy the original value to a temp. \n");
		transitionNumber = inputNumber;

		printf("\tB. Bit shift the original right by four. \n");
		inputNumber = inputNumber >> 4;

		printf("\tC. Bit shift the copy left by 32 - 4 = 28. \n");
		transitionNumber = transitionNumber << ((sizeof(transitionNumber) * 8) - 4);

		printf("\tD. OR the bit shifted original and the bit shifted copy. \n");
		inputNumber = inputNumber | transitionNumber;

		printf("\tE. Profit. \n");
	}
#endif

#ifdef solution2
	{
		printf("Solution #2 \n");
		printf("\tA. Bitmask the last four bits from the original into a temp. \n");
		transitionNumber = inputNumber & 0x0000000F; // Each Hexadecimal F masks four binary bits

		printf("\tB. Bit shift the temp by 32 - 4 = 28 to put it in position. \n");
		transitionNumber = transitionNumber << ((sizeof(transitionNumber) * 8) - 4);

		printf("\tC. Bit shift the original right by 4 to make room. \n");
		inputNumber = inputNumber >> 4;

		printf("\tD. OR the bit shifted temp and the bit shifted original. \n");
		inputNumber = inputNumber | transitionNumber;

		printf("\tE. Profit. \n");
	}
#endif

#ifdef solution3
	{
		printf("Solution #3 \n");
		printf("\tA. Bitmask the last four bits from the original into a temp. \n");
//		transitionNumber = inputNumber & 0x0000000F; // Each Hexadecimal F masks four binary bits
		transitionNumber = inputNumber; // Bitmasking not necessary; This feels dangerous though
		/* Step B will effectively overflow the leading bits of the temp variable using multiplication */

		printf("\tB. Multiply the temp by 2^(32 - 4) = 2^28 to put it in position. \n");
		printf("\tNOTE:  This is the same as a Bitwise Shift Left of 28 (e.g., x << 28). \n");
		transitionNumber = transitionNumber * pow((double)2,(double)((sizeof(transitionNumber) * 8) - 4));

		printf("\tC. Bit shift the original right by 4 to make room. \n");
		inputNumber = inputNumber >> 4;

		printf("\tD. OR the bit shifted temp and the bit shifted original. \n");
		inputNumber = inputNumber | transitionNumber;

		printf("\tE. Profit. \n");
	}
#endif

#ifdef solution4
	{
		printf("(Fancy) Solution #4 \n");
		printf("\tA. Perform a Bitwise OR on inline Bitwise Shift Rights and Shift Lefts.\n");
		inputNumber = (inputNumber >> 4) | (inputNumber << ((sizeof(inputNumber) * 8) - 4));
		printf("\tB. Profit. \n");
	}
#endif

	printf("Your new number is %u (Hex: 0x%08X) \n", inputNumber, inputNumber);

	return 0;
}