#include <stdio.h>

#define BAD_DIMENSION

#ifndef BAD_DIMENSION
#define BUFF_SIZE 10
#endif

int main(void)
{

	_flushall();

#ifdef BAD_DIMENSION
	const int buffSize = 10;
	char myArray[buffSize];
	fgets(myArray, buffSize, stdin);
#endif

#ifndef BAD_DIMENSION
	char myArray[BUFF_SIZE] = { 0 };
	fgets(myArray, BUFF_SIZE, stdin);
#endif
		
	puts(myArray);

	getchar(); getchar();
	return 0;
}
