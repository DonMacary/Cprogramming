#include <stdio.h>

//#define BAD_TYPE

#ifdef BAD_TYPE
#define NUM 68.8
#else
//#define NUM (float)68.8
const float NUM = 68.8;
#endif

int main(void)
{
	float x = NUM;

	int numSize = sizeof(NUM);
	int xSize = sizeof(x);

	double y = NUM;

	int ySize = sizeof(y);

	if (numSize != xSize)
	{
		printf("Float is not equal to NUM");
		return -1;
	}

	if (numSize != ySize)
	{
		printf("Double is not equal to NUM");
//		return -2;
	}
	
	return 0;
	// Replicate the example code from the slides
}
