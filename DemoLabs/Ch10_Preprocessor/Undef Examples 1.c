#include <stdio.h>

#define BAD_MACRO

int main(void)
{
	printf("Old EOF:  %d \n", EOF);

#ifndef BAD_MACRO
#undef EOF
#endif

#define EOF (-3)
	printf("New EOF:  %d \n", EOF);

	return 0;
}

