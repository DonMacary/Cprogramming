/*********************************************************************
/   AUTHOR: ELF
/   COURSE: C Programming
/   PROGRAM NAME: perfLab8A.c
/   PROGRAM DESCRIPTION: Performance Lab 8A - Functions
/   INSTRUCTIONS:


/*********************************************************************/

#include <stdio.h>

#include <stdio.h>
#include <string.h>
#define ERR_NULL_POINTER -1		                // Error:  Pointer passed was NULL
#define ERR_NONE_FOUND 0		                // Error:  Character not found
#define ERR_FIND_EQUALS_REPLACE -2              // Error:  To replace and replace are equal to each other
#define ERR_NON_PRINTABLE_CHARACTER -3          // Error:  One of the characters is not printable


int replace_char(char * buffer, char findChar, char replaceChar);
int clearInput();

int main(void)
{
	/* FUNCTION INPUT ARRAYS */
	char beforeString1[] = { "If debugging is the process of removing software bugs, then programming must be the process of putting them in.  -Edsger Dijkstra\n" }; // No newlines
	char * beforeStringArray[] = { beforeString1 };
	char userChar = 0; // Character to replace
	char replaceChar = 0; // Character replacing userChar
	int tempResults = 0;

	printf("Program: Healthy Substitutions. Press enter to continue!");
	clearInput();
	printf("What character would you like replaced?\n");
	userChar = getchar();
	printf("What character would you like to replace character %c with?\n", userChar);
	clearInput();
	replaceChar = getchar();

	// Implement for loop here for multiple strings
	printf("%s\n", beforeString1);
	tempResults = replace_char(beforeString1, userChar, replaceChar);

	// Check for errors
	if (tempResults > 0)
	{
		printf("\n\n\nThe new string is: \n");
		printf("%s\n", beforeString1);
		printf("There were %d instances of %c replaced with %c.\n", tempResults, userChar, replaceChar);
	}
	else if (tempResults == ERR_NULL_POINTER)
	{
		printf("The string was empty");
	}
	else if (tempResults == ERR_NONE_FOUND)
	{
		printf("There were no instances of that character");
	}
	else if (tempResults == ERR_FIND_EQUALS_REPLACE)
	{
		printf("The character to replace was the same as the replace character");
	}
	else
	{
		printf("One of the characters entered were not printable");
	}

	while (1);
	return 0;
}

/*
* FUNCTION:   int replace_char(char * buffer, char findChar, char replaceChar)
*
* ARGUMENTS:  -buffer is a pointer to a null-terminated string
*              The string is passed by reference and modified in place
*              -findChar is a char to be found in the string
*              -replaceChar is the char to replace the findChar
*
* RETURNS:	   Number of characers replaced
*             ERR_NULL_POINTER if buffer == NULL
*             ERR_NONE_FOUND if no newlines are found
*             ERR_FIND_EQUALS_REPLACE -2              // Error:  To replace and replace are equal to each other
*             ERR_NON_PRINTABLE_CHARACTER -3          // Error:  One of the characters is not printable
*
* NOTES:      This function replaces instances of a userinputted character with another user inputted char
*/
int replace_char(char * buffer, char findChar, char replaceChar)
{
    //We dont want to check the last character because its a null pointer
	int size = strlen(buffer)-1;
	int counter = 0; // counter to count instances of the character
    //check if the string is empty and return an error if so
	if (buffer == NULL)
	{
		return ERR_NULL_POINTER;
	}
    //check if there is a null character at the end of the string if so return an error
	else if (strchr(buffer, '\n') == NULL)
	{
		return ERR_NONE_FOUND;
	}
    //check if the two inputted characters are equal if so return an error
	else if (findChar == replaceChar)
	{
		return ERR_FIND_EQUALS_REPLACE;
	}
    //begin looping through all the characters
	else
	{
		for (int i = 0; i < size; i++)
		{
			//check to see if the character is printable if not return an error
			if (buffer[i] < 32 || buffer[i] > 126)
			{
				return ERR_NON_PRINTABLE_CHARACTER;
			}
			//check if the character in the string is the character were looking for, replace it
            //and increment your counter
			if (buffer[i] == findChar)
			{
				buffer[i] = replaceChar;
				counter++;
			}
		}
	}

	return counter;
}


// This is an awesome function and useful if you need to clear the input buffer
int clearInput()
{
	while (getchar() != '\n');
}