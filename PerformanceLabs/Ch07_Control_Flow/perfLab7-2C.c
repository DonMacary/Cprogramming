/*********************************************************************
/   AUTHOR: ELF
/   COURSE: C Programming
/   PROGRAM NAME: perfLab7-2C.c
/   PROGRAM DESCRIPTION: Performance Lab 7C - Else If Statement
/   INSTRUCTIONS:
		ELSE-IF STATEMENT
		SWAP THE LARGEST NUMBER
		Initialize ONLY three unsigned int variables to 0.
		Safely scan user input into the variable #1 and #2 utilizing a single line.
		Using a single ELSE-IF statement:
			If variable #1 is equal to variable #2, print an ERROR.
			Otherwise, exchange the value of the largest variable with variable #3 while preserving the other value.
		Print the values of all three variables if the SUM of the three variables is greater than 2 regardless of the previous ELSE-IF statement.

/*********************************************************************/

#include <stdio.h>
#include <limits.h>


int main(void)
{
	unsigned int value1 = 0;
	unsigned int value2 = 0;
	unsigned int value3 = 0;
	//allow user to input 2 int values
	printf("Enter two integers separated by a space: ");
	scanf("%d%d", &value1, &value2);
	printf("Your two integers are: %d and %d\n", value1, value2);

	//if the values are equal print an error
	if (value1 == value2)
	{
		printf("ERROR values are equal!\n");
	}
	//if the first value is bigger then make value 3 its value
	else if(value1 > value2)
	{
		value3 = value1;

	}
	//if the second value is bigger make value3 it
	else
	{
		value3 = value2;

	}
	//print the sum
	printf("The sum of the numbers is: %d \n", value1 + value2 + value3);
	//if the sum is bigger than 2 then print all the values
	if (value1 + value2 + value3 > 2)
	{
		printf("value 1 is %d, value2 is %d, and value 3 is %d \n", value1, value2, value3);
	}
	//if the sum is smaller than print so
	else
	{
		printf("The sum of the 3 variables is less than 2!\n");
	}

	while (1);
	return 0;

}

