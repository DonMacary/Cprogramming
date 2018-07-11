#include <stdio.h>

int main(void)
{
	int userInput = 0;
	printf("Enter a character:  ");
	userInput = getc(stdin);
	printf("Your character was:  ");
	putc(userInput, stdout);

	getchar();
	return 0;
}
