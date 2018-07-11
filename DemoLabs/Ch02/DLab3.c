#include <stdio.h>

int main(void)
{
	int integer = 42;
	float singlePrecision = 2.2;
	double doublePrecision = 3.347839264523;
	char singleChar = 'J';
	
	printf("Your int: %d cast to a float: %f \n", integer, (float) integer);
	printf("Your int: %d cast to a char: %c \n", integer, (char) integer);
	printf("Your float: %f cast to a double: %lf \n", singlePrecision, (double) singlePrecision);
	printf("Your double: %.15lf cast to a float: %f \n", doublePrecision, (float) doublePrecision);
	printf("Your char: %c cast to an int: %d \n", singleChar, (int) singleChar);
	printf("63 cast to a char: %c \n", (char) 63);

	return 0;
}