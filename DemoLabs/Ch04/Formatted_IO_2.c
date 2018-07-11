#include <stdio.h>

int main(void)
{
	char inputBuffer[256] = {0};

	printf("Enter a string but don't use any capital letters. \n");
	scanf("%255[^A-Z\n]s", inputBuffer);
	printf("Your lower case string was: \n%s", inputBuffer);

	return 0;
}
