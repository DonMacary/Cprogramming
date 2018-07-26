#include <stdio.h>

#ifdef _DEBUG
#define DEBUG_INT(x) printf(#x " is %d", x)
#else
#define DEBUG_INT(y) ;
#endif /* _DEBUG */

int main(void)
{
	int someNum = 42;

	DEBUG_INT(someNum);

	return 0;
}
