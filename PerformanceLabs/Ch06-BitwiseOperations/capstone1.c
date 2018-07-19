/*********************************************************************
/   AUTHOR: ELF
/   COURSE: C Programming
/   PROGRAM NAME: capstone1.c
/   PROGRAM DESCRIPTION: Captstone 1 - Flip a Single bit using XOR
/   INSTRUCTIONS:

Initialize an unsigned int with an arbitrary value
Ask the user input on which bit position to flip (0 through ((sizeof(unsigned int)*8) -1))
Create a dynamic bit mask based on the user input "inputMask"
XOR the original value with the inputMask and print the result

NOTE: This capstone requires a lot of logic and almost all the previously used bitwise operators.
/*********************************************************************/

#include <stdio.h>
#include <inttypes.h>

int binary_conversion(int);
int binary(__uint32_t);


int main(void)
{

	uint32_t flipMe = 0;
	uint32_t inputMask = 0;
	int bitToFlip;
	int validInput = 0;
	int validNum = 0;

	//take a number to flip from the user - NOTE: this number must be below 1024 - I am only able to account for 11 bits currently...
	printf("Enter a number you would like to flip: ");
	fscanf(stdin, "%u", &flipMe);
	/*
	//Use this code if you are using the binary conversion function since it doesnt work with numbers greater than 1023
	while(validNum == 0)
	{
	printf("Enter a number you would like to flip: ");
	fscanf(stdin, "%u", &flipMe);
	if(flipMe>1023)
	{
	printf("Please enter a number below 1024\n");
	}
	else{
	validNum = 1;
	}
	}
	*/
	printf("The number we will be flipping is %u or 0x%.8X \n", flipMe, flipMe); //print the user's number in decimal and hex
	binary(flipMe);
	//printf("The number in binary is %.32u \n",binary(flipMe)); //print the binary of the number


	//input validation - does not account for non-integers... IE characters break the shit out of this 
	//TODO: handle case of user inputs a non-integer
	while (validInput == 0)
	{
		printf("Please enter an integer between 0 and %d: ", (sizeof(flipMe) * 8) - 1);
		// fscanf(stdin, "%d", &bitToFlip);
		if (fscanf(stdin, "%u", &bitToFlip) == 0) {
			printf("Invalid input, try again \n");
		}
		else if (bitToFlip < 0)
		{
			printf("Invalid input, try again \n");
		}
		else if (bitToFlip >((sizeof(flipMe) * 8) - 1))
		{
			printf("Invalid input, try again \n");
		}
		else
		{
			validInput = 1;
		}
	}
	printf("You want to flip bit %d\n", bitToFlip);
	//determine the bit mask by doing a left shift (this reads inputMask = 2^bitToFlip)
	inputMask = 1 << bitToFlip;
	printf("Your input mask is 0x%.8X \n", inputMask); //display the input mask in HEX
													   //printf("The binary of your input mask is %.32u \n", binary(inputMask)); //display the bitmask in binary
	binary(inputMask);
	//XOR the value and print it 
	printf("Your shifted value is %u or 0x%.8X in hex \n", flipMe ^ inputMask, flipMe ^ inputMask); //display the result in decimal and hex
																									//printf("Your shifted value in binary is: %.32u \n", binary(flipMe ^ inputMask)); //display the result in binary
	binary(flipMe ^ inputMask);
}

//the math on this function is super fun - it uses recursion to determine binary (thanks stack overflow!) However this is limited to ints up to 1023 then it
//shits the bed
int binary_conversion(int num)
{
	if (num == 0)
	{
		return 0;
	}
	else
	{
		return (num % 2) + 10 * binary_conversion(num / 2);
	}
}

//this function does much better at handling larger numbers but doesnt store it in a variable so you can only print the output...
int binary(uint32_t num)
{
	printf("This number in binary is ");
	unsigned i;
	for (i = 1 << (sizeof(num) * 8) - 1; i > 0; i = i / 2)
		(num & i) ? printf("1") : printf("0");
	printf("\n");
}