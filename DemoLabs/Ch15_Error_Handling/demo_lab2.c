/*
DEMONSTRATION LAB I.8.a-2 "End of Line"
Open an existing file
If the FILE pointer is NULL:
Store the errno
Print an error message (perror)
Print the string associated witih the errno (strerror)
Immediately utilize the errno as a return value
Utilize feof() to read a file char by char until the end
*/

#define _CRT_SECURE_NO_WARNINGS	
#include <string.h>
#include <errno.h>
#include <stdio.h>

void error_reporting(int currErrno);

int main(void)
{
	int currentErrno = 0;
	char currentChar = 0;

	// Open an existing file 
	FILE * weirdFile = fopen("./file1.txt", "r");

	// Store the errno
	currentErrno = errno;

	if (!weirdFile)
	{
		// Print an error message utilizing the string associated with the errno
		error_reporting(currentErrno);

		// Immediately utilize errno as the return value
		return currentErrno;
	}
	else
	{
		// Utilize feof() to read a file char by char until the end
		while (!feof(weirdFile))
		{
			currentChar = getc(weirdFile);	// Read a char and...
			putchar(currentChar);			// ...print a char
		}
	}

	while (1);
	return 0;
}

void error_reporting(int currErrno)
{
	char* errStr;
	if (currErrno)
	{

		perror("Error");
	}

	return;
}