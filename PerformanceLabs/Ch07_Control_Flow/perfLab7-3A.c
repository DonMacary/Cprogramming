/*********************************************************************
/   AUTHOR: ELF
/   COURSE: C Programming
/   PROGRAM NAME: perfLab7-3A.c
/   PROGRAM DESCRIPTION: Performance Lab 7.3A - For Loops
/   INSTRUCTIONS:
		Create some stuff in for loops....

/*********************************************************************/

#include <stdio.h>

int main(void)
{

	int numbers[50];
	char alphabet[26] = {0};
	char hello[] = "Hello Travis!!";
	for (int i = 0; i < 50; i++) 
	{
		numbers[i] = i + 1;
		printf("numbers[%d] is  %d\n", i, numbers[i]);
	}
	for (int i = 0; i < 26; i++)
	{
		alphabet[i] = i + 97;
		printf("alphabet[%d] is %c\n", i, alphabet[i]);
	}
	for (int i = 0; i < sizeof(hello); i++) 
	{
		printf("%c\n", hello[i]);
	}
	for (int i = 0; i <25; i++)
	{
		for (int j = 0; j < i; j++)
		{
			printf("*");
		}
		printf("\n");
		
	}
	for (int i = 25; i >0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			printf("*");
		}
		printf("\n");

	}
	while (1);
	return 0;

}

