#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

//#define BAD_STATEMENTS

#ifdef BAD_STATEMENTS
#define DIE puts("Fatal Error"); exit(EXIT_FAILURE);
#endif

#ifndef BAD_STATEMENTS
#define DIE {puts("Fatal Error"); exit(EXIT_FAILURE);}
#endif

int main(void)
{
	int x = 3;

	if (0 == x)
		DIE;
	
	printf("%.5f", 10.0 / x);

	return 0;
}
