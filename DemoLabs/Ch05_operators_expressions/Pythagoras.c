#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>

int main(void)
{
	double legA = 0;
	double legB = 0;
	double hypotenuse = 0;

	printf("Input the length of leg A and leg B for your right triangle. \n");
	printf("Separate the two lengths with a space.  (e.g., 1.3 9.7) \n");
	//_flushall();
	scanf("%lf %lf", &legA, &legB);

	hypotenuse = sqrt((legA*legA) + (legB*legB));
	printf("Your hypotenuse is %.2f. \n", hypotenuse);

	getchar();
	return 0;
}
