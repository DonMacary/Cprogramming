#include <stdio.h>

#define HARK_DEBUG			// Uncomment to debug code

#ifdef HARK_DEBUG
#define DEBUG_PRINT(x) printf("DEBUG:\t" #x " is %d\n", x)
#else
#define DEBUG_PRINT(x) ;
#endif

int main(void)
{
	int myVar = 11;

	DEBUG_PRINT(myVar);

	return 0;
}

