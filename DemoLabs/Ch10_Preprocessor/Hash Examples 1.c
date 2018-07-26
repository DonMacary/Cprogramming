#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

#define DEBUG_INT(x) \
printf(#x " is %d\n", x)

int main(void)
{
	int getNum = 0;
	_flushall();
	scanf("%d", &getNum);
	DEBUG_INT(getNum);

	return 0;
}
