#include <stdio.h>
//#define BAD_CONSTANT

#ifdef BAD_CONSTANT
#define UNIT 90COS
#endif

#ifndef BAD_CONSTANT
#define UNIT "90COS"
#endif

int main(void)
{
#ifdef BAD_CONSTANT
	char squadron[] = { "UNIT" };
#endif

#ifndef BAD_CONSTANT
	char squadron[] = { UNIT };
#endif

	puts(squadron);

	return 0;
}
