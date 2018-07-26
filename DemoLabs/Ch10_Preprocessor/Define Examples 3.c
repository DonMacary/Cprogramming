#include <stdio.h>
//#define BAD_MACRO

#ifdef BAD_MACRO
#define TIMES(a,b) a * b
#endif

#ifndef BAD_MACRO
#define TIMES(a,b) ((a) * (b))
#endif

int main(void)
{
	printf("%d\n", (45 + 45) * 2);
	int quotient = TIMES(45 + 45, 2);
	printf("%d\n", quotient);

	return 0;
}
