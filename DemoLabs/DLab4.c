#include <stdio.h>

int main(void)
{
	int myIntArray[10] = {0};
	myIntArray[0] = 100;
 	myIntArray[1] = 100;
 	myIntArray[2] = 100;
 	myIntArray[3] = 100;
 	myIntArray[4] = 100;
 	myIntArray[5] = 100;
 	myIntArray[6] = 100;
 	myIntArray[7] = 100;
 	myIntArray[8] = 100;
 	myIntArray[9] = 100;

	float myFloatArray[5] = {1.0, 2.0, 3.0, 4.0, 5.0};
	char myCharArray[256] = {0};

	// END INIT ARRAYS

	int index = 0;

	printf("%d \n", myIntArray[2]);
	printf("%f \n", myFloatArray[2]);
	printf("%c \n", myCharArray[2]);


    // myIntArray[y] = (y + 1) * 10;
	myIntArray[0] = (0 + 1) * 10;
	myIntArray[1] = (1 + 1) * 10;
	myIntArray[2] = (2 + 1) * 10;
	myIntArray[3] = (3 + 1) * 10;
	myIntArray[4] = (4 + 1) * 10;		//Isn't this kind of a P.I.T.A....?
	myIntArray[5] = (5 + 1) * 10;
	myIntArray[6] = (6 + 1) * 10;
	myIntArray[7] = (7 + 1) * 10;
	myIntArray[8] = (8 + 1) * 10;
	myIntArray[9] = (9 + 1) * 10;

	myFloatArray[0] = myFloatArray[0] * 1.1;
	myFloatArray[1] = myFloatArray[1] * 1.1;
	myFloatArray[2] = myFloatArray[2] * 1.1;		//There must be a better way!!
	myFloatArray[3] = myFloatArray[3] * 1.1;
	myFloatArray[4] = myFloatArray[4] * 1.1;

	myCharArray[0] = 'J';
	myCharArray[1] = 'E';
	myCharArray[2] = 'R';
	myCharArray[3] = 'E';
	myCharArray[4] = 'M';
	myCharArray[5] = 'Y';

	printf("%d \n", myIntArray[2]);
	printf("%f \n", myFloatArray[2]);
	printf("%c \n", myCharArray[2]);

	return 0;

}