//////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////// DEMONSTRATION LAB I.2.A-2 ////////////////////////////
////////////////////////////////////// Even It Out ///////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
// Input a number from the user
// Determine if the number is even or odd utilizing the "mod" operator
// Utilizing an IF-ELSE statement:
//     If the number is odd, multiply the number by 2, store the result in the
//         original variable, and print the new number
//     If the number is even, say so
// BONUS:  Determine if the number is odd or even utilizaing a bitwise operator
//     instead
//////////////////////////////////////////////////////////////////////////////////////


#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>


int main(void)
{
	int userInputNumber = 0;

	printf("Input a number:  \n");
	_flushall();
	scanf("%d", &userInputNumber);

	if (userInputNumber & 1 == 1) // If there is a remainder from num / 2 then it, by definition, is odd
	{
		/* If the number is odd, multiply the number by 2 and store the result in the original variable... */
		userInputNumber = userInputNumber * 2;
		/* ...and print the new number */
		printf("The number was odd but I made it even. \nThe new number is %d. \n", userInputNumber);
	}
	else
	{
		/* If the number is even, say so */
		printf("The number is even. \n");
	}


	return 0;
}
