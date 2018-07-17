/*********************************************************************
/   AUTHOR: ELF
/   COURSE: C Programming
/   PROGRAM NAME: perfLab7-2D.c
/   PROGRAM DESCRIPTION: Performance Lab 7D - Switch Statements
/   INSTRUCTIONS:
		SWITCH STATEMENT
		Write a program that will evaluate a simple math formula.
		Input the formula with two integers separated by an arithmetic operator from one line.
			Example: 1 + 1, (-8) - 3, 2 * (-7), (-15) / (-4)
		Use a switch statement to print the correct value using the operators as cases.
		Set the default condition to an error.
		Ensure any division provides a double answer with a precision of two decimal places.
		NOTE: Scan the arithmetic operator as a char

/*********************************************************************/

#include <stdio.h>

int main(void)
{
	int value1 = 0;
	int value2 = 0;
	char op = '0';
	printf("Please enter to integer values: ");
	_flushall();
	scanf("%d%d", &value1, &value2);

	do
	{
		printf("Enter an arithmetic operator or enter 1 to exit: ");
		_flushall();
		scanf("%1c", &op);

		switch (op)
		{

		case '+':
			printf("%d + %d is %d\n", value1, value2, value1 + value2);
			break;

		case '-':
			printf("%d - %d is %d\n", value1, value2, value1 - value2);
			break;

		case '/':
			printf("%d / %d is %.5lf\n", value1, value2, (double) value1 / value2);
			break;

		case '*':
			printf("%d * %d is %d\n", value1, value2, value1 * value2);
			break;
		default:
			printf("You did not enter a arithmetic operator! Try again!\n");
			break;
		}
		
	} while (op != '1');


	return 0;

}

