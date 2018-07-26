#include <stdio.h>
//#define PARTIAL_SUB

#define COUNT 1

int main(void)
{
#ifdef PARTIAL_SUB 
	printf("LAUNCH# %d\n"\
, COUNTCOUNT);
#endif
#ifndef PARTIAL_SUB
	printf("LAUNCH# %d\n"\
		, (COUNT * 10) + (COUNT));
#endif
	printf("%d\n", COUNT * 3); 
	printf("%d\n", COUNT + COUNT); 
	printf("%d\n", COUNT);
	
	return 0;
}
