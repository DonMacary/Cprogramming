#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

#define DIE(d) {puts(#d" err");\
exit(EXIT_FAILURE);}

int main(void)
{
	int x = 0;

	_flushall();
	scanf("%d", &x);

	if (0 == x)
		DIE(x);

	printf("%.5f", 10.0 / x);
	return 0;
}
