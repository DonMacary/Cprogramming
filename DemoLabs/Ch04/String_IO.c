#include <stdio.h>

int main(void)
{
	char buff[4];
	printf("Enter a string:      ");
	fgets(buff, sizeof(buff), stdin);
	printf("Your string was:  ");
	puts(buff);

	return 0;
}
