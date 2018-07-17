/*********************************************************************
/   AUTHOR: ELF
/   COURSE: C Programming
/   PROGRAM NAME: perfLab7B.c
/   PROGRAM DESCRIPTION: Performance Lab 7B - Else If Statement
/   INSTRUCTIONS:
		IF-ELSE STATEMENT
		Initialize a signed int to 0.
		Input a number from the user and store it in the signed int.
		Determine if the number is negative or positive utilizing a bitwise operator.
		Utilizing an IF-ELSE statement:
			INDICATE if the number is negative
			Otherwise, print the original value in binary, and use a bitwise operation to flip one bit to make it negative
		Print the binary

/*********************************************************************/

#include <stdio.h>
#include <limits.h>
int binary(int num);

int main(void)
{
	int input = 0;
	printf("Enter a number: ");
	scanf("%d", &input);
	printf("Your number is: %d \n", input);
	int mask = INT_MAX;

	//checks to see if number is odd (if there is a remainder then it is odd)
	if (input & 1 == 1)
	{
		printf("%d is odd \n", input);
	}
	else
	{
		printf("Even \n");
		binary(input);
		printf("size of input: %d bits\n", (sizeof(input) * 8 - 1));
		//convert the number to binary using two's complement
		printf("Converting to negative number using two's complement method \n");
		binary(~input + 1);
		printf("Your new number is: %d\n", ~input+1);

	}

	return 0;

}

int binary(int num)
{
	printf("This number in binary is ");
	unsigned i;
	for (i = 1 << (sizeof(num) * 8) - 1; i > 0; i = i / 2)
		(num & i) ? printf("1") : printf("0");
	printf("\n");
}