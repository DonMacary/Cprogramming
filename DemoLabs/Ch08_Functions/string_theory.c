#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "MyStringHeader.h"

int main()
{
	char someString[] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd'}; // Non null term
	int someStringLen = 11;

	int counter = print_the_count(someString, someStringLen);

	printf("\n\n\n\nTotal count: %d", counter);

	return 0;
}
