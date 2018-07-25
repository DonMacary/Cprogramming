#include <stdio.h>

#define BUFF_SIZE ((int)1024)

int count_this_letter(char * string_ptr, char countThis, int * howMany_ptr);

int main(void)
{
	/* VARIABLE DECLARATION */
	char userString[BUFF_SIZE] = { 0 };
	char countThis = 0x0;
	int thisManyTimes = 0;
	int returnValue = 0;

	/* TAKE USER INPUT */
	puts("Enter a string:");
	_flushall();
	fgets(userString, BUFF_SIZE, stdin);
	puts("Enter a character to search for:");
	_flushall();
	countThis = getc(stdin);

	/* VERIFICATION */
	printf("\n\n\n\nSearching the folowing string...\n%s", userString);
//	puts(userString);
	puts("...for this character:");
	putchar(countThis);
	putchar(10);

	/* FIND THE CHARACTER */
	returnValue = count_this_letter(userString, countThis, &thisManyTimes);

	if (!userString)
	{
		puts("The user string is NULL");
	}
	else if (!thisManyTimes)
	{
		puts("The search character count is zero (0)");
	}
	else
	{
		printf("The original string was:\n%s", userString);
//		puts(userString);
//		printf("The search character was:\n%c", countThis);
//		putchar(countThis);
//		putchar(10);
//		printf("The search character was found at memory address:\n%p", countThis_ptr);
		printf("The search character %c was found %d times.\n", countThis, thisManyTimes);
		printf("That data was found at memory address %p\n", &thisManyTimes);
	}
	printf("The function's return value was: %d\n", returnValue);

	getchar(); getchar();
	return 0;
}

int count_this_letter(char * string_ptr, char countThis, int * howMany_ptr)
{
	int returnValue = 0;
	int i = 0;

	if (!string_ptr)
	{
		returnValue = -1;
	}
	else if (!howMany_ptr)
	{
		returnValue = -2;
	}
	else if (!countThis)
	{
		returnValue = -3;
	}
	else
	{
		i = 0;

		while (*(string_ptr + i))
		{
			if (*(string_ptr + i) == countThis)
			{
				*howMany_ptr = *howMany_ptr + 1;
			}
			i++;
		}
	}


	return returnValue;
}
