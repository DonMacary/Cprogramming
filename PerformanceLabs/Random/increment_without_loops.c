#include <stdio.h>

void printNos(unsigned int n)
{
	
	n > 1 ? printNos(n - 1) : printf("");
	printf("%d ", n);
	return;

}
int main()
{
printNos(10);

getchar(); getchar();
return 0;

}