///////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////// DEMONSTRATION LAB X.2.A-4 /////////////////////////////
/////////////////////////////////// May I see a menu? /////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
// Input an integer from the user
// Create a menu allowing the user to:
//     Print their input as Octal
//     Print their input as Decimal
//     Print their input as Hexadecimal
//     Print their input as a Character
//     Input a new number
//     Exit
///////////////////////////////////////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int printMenu(void);

int main(void)
{
	int number = 0;
	int menuSelection = 3;
	printf("Input an number:  ");
	_flushall();
	scanf("%d", &number);


	do
	{
		printMenu();
		_flushall();
		scanf("%d", &menuSelection);
		switch (menuSelection)
		{
			case 0:
				printf("\n\nExiting...");
				break;
			case 1:			// 2 - Octal
				printf("Octal:  %o\n\n", number);
				break;
			case 2:			// 3 - Decimal
				printf("Decimal:  %d\n\n", number);
				break;
			case 3:			// 4 - Hexadecimal
				printf("Hexadecimal:  %X\n\n", number);
				break;
			case 4:			// 5 - Char
				printf("Character:  %c\n\n", number);
				break;
			case 5:			// 6 - New number
				printf("\n\nEnter a new number to display:  ");
				_flushall();
				scanf("%d", &number);
			
			default:
				break;
		}
	} while (menuSelection != 0);

	return 0;
}

int printMenu(void)
{
	printf("How do you want to print that number?  \n");
	printf("1 - Octal \n2 - Decimal \n3 - Hexadecimal \n4 - Char \n5 - Enter a new number \n0 - Exit this program. \n\n\n");

	return 0;
}
