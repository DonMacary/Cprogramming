/*********************************************************************
/   AUTHOR: ELF
/   COURSE: C Programming
/   PROGRAM NAME: perfLab5A.c
/   PROGRAM DESCRIPTION: Performance Lab 5A
/   INSTRUCTIONS:

Arithmetic

Write a program to calculate the hypotenuse of a right triangle
Use the Pythagorean Theorem (a^2 + b^2 = c^2)
Input the two legs (A and B)
Output the hypotenuse (C)
Add this to your code "shell"
#include <math.h> // Math header contains sqrt()
**NOTE: **gcc may require a -lm flag. This tells gcc to link a library (-l), specifically the math library (-m).
Relational
Write a relational expression to appropriately test the user input for leg A and then for leg B
Logical
Combine the previous Relational expressions with a logical operator so that both must be True
Error Checking
Include the Arithmetic, Relational and Logical code in this shell code as indicated by /* insert here */
/*********************************************************************/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char leg1Str[5];
	int leg1Int;
	char leg2Str[5];
	int leg2Int;
	double hypotenuse;
	int goodIn = 1;
	int goodIn2 = 1;

	//loop until user gives acceptable input
	while (goodIn == 1)
	{
		printf("Type the integer value of the first leg: ");
		//take in input using fgets
		fgets(leg1Str, sizeof(leg1Str), stdin);
		//convert input to an integer
		leg1Int = atoi(leg1Str);
		//error checking - note atoi converts everything that isnt a number to 0 so this correctly input checks letters and special characters!
		if (leg1Int <= 0) {
			printf("You must enter a number greater than 0\n");
		}
		else if (!strchr(leg1Str, '\n'))
		{
			printf("Too many characters!\n");
			while (fgetc(stdin) != '\n');
		}
		else {
			goodIn = 0;
		}
		

	}
	printf("Your first leg is size: %d\n", leg1Int);
	//do the same for the second leg
	while (goodIn2 == 1)
	{
		printf("Type the integer value of the second leg: ");
		//take in input using fgets
		fgets(leg2Str, sizeof(leg2Str), stdin);
		//convert input to an integer
		leg2Int = atoi(leg2Str);
		//error checking - note atoi converts everything that isnt a number to 0 so this correctly input checks letters and special characters!
		if (leg2Int <= 0) {
			printf("You must enter a number greater than 0\n");
		}
		else {
			goodIn2 = 0;
		}

	}
	printf("Your second leg is size: %d\n", leg2Int);
	//calculate the hypotenuse
	hypotenuse = (double)(leg1Int*leg1Int) + (double)(leg2Int*leg2Int);
	hypotenuse = sqrt(hypotenuse);
	printf("The hypotenuse of a right triangle with legs %d and %d is %f\n", leg1Int, leg2Int, hypotenuse);
	while (1);
	return 0;
}