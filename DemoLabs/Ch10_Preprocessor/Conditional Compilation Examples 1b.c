#include <stdio.h>

#ifdef _DEBUG
#define DEBUG_INT(x) printf(#x " is %d", x)
#endif /* _DEBUG */

int main(void)
{
	int someNum = 42;

#ifdef _DEBUG
		DEBUG_INT(someNum);
#endif /* _DEBUG */

	return 0;
}
