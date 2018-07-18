// MyStringHeader.c
#include <stdio.h>
#include <ctype.h>

#define ERR_NULL_POINTER -1;        // string is null
#define ERR_INVALID_LENGTH -2;      // string length is zero or less

extern int print_the_count(char * inputString, int strLen)
{
	char tempChar = 0;      // Current char being acted on
	int table[26] = { 0 };    // Alpha
	int count = 0;

	if (!inputString)
	{
		return ERR_NULL_POINTER;
	}
	else if (!strLen)
	{
		return ERR_INVALID_LENGTH;
	}

	for (int i = 0; i < strLen; i++)
	{
		if (inputString[i] >= 65 && inputString[i] <= 122)
		{
			tempChar = inputString[i];
			tempChar = toupper(tempChar);
			table[tempChar - 65] += 1;
			count++;
		}
	}

	// Print the table
	for (int i = 0; i < sizeof(table) / sizeof(table[0]); i++)
	{
		printf("%c: %d\n", i + 65, table[i]);
	}
	return count;
}


extern int reverse_it(char * forwardString, int strLen)
{
	char tempChar; //create a temp character that is a copy of the originial
	//check if the string is NULL if so return error -1
	if (forwardString == NULL)
	{
		return -1;
	}
	//check if the string length doesnt make sense (if it is 0 or less)
	else if (strLen <= 0)
	{
		return -2;
	}
	//otherwise loop through the characters
	else
	{
		//loop through the first half of the string, store the first letter into a temp variable then replace the first letter with the last then make the last letter the temp character
		for (int i = 0; i < (int) strLen/2; i++)
		{
			tempChar = forwardString[i]; //store the first character in a temp character variable
			forwardString[i] = forwardString[strLen - i -1]; //make the first character = to the last character - make sure to ignore that null character!!
			forwardString[strLen - i-1] = tempChar; //make the last character (that isnt the NULL) = to the temp variable which is the original first character
			
		}
		//if you get here you are good and return success!
		return 0;
	}

}