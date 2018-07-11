#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>

int main(void)
{
	/* Initialize variables here */
	double rightTriangleLegA = 0;
	double rightTriangleLegB = 0;
	double rightTriangleHypotenuse = 0;

	/* Input values and assign to variables here*/
	printf("Input the length of leg A and leg B for your right triangle. \n"); // User prompt
	printf("Separate the two lengths with a space.  (e.g., 1.3 3.7) \n"); // User prompt
	//_flushall(); // Flushes all open streams while leaving them open
	scanf("%lf %lf", &rightTriangleLegA, &rightTriangleLegB);

	/* INPUT VALIDATION */
	/* rightTriangleLegA > 0 tests that the user input was positive */
	/* rightTriangleLegB > 0 tests that the user input was positive */
	/* (relational test A) && (relational test B) tests that both conditions are True */
	if ((rightTriangleLegA > 0) && (rightTriangleLegB > 0))
	{
		/* Place arithmetic hypotenuse calculation here */
		rightTriangleHypotenuse = sqrt((rightTriangleLegA*rightTriangleLegA) + (rightTriangleLegB*rightTriangleLegB));
		//		rightTriangleHypotenuse = sqrt((pow(rightTriangleLegA, 2) + pow(rightTriangleLegB, 2)));
		/* double pow(double x, double y) returns x raised to the power of y (e.g., x^y) */

		/* Print the hypotenuse here */
		printf("Your hypotenuse is %.2f. \n", rightTriangleHypotenuse);
	}

	return 0;
}
