/********************************************************************************************************************
/   AUTHOR: ELF
/   COURSE: C Programming
/   PROGRAM NAME: perfLab15B.c
/   PROGRAM DESCRIPTION: Performance lab A - Errno
/   INSTRUCTIONS:
        Write (or modify) a program that implements the following:
        feof()
        perror()
        Return errno
        strerror()
        Replicate some error to test your implementation…

        Read a non-existent file.
        Write to a locked file.
        Misuse a math function .
**********************************************************************************************************************/

#define _CRT_SECURE_NO_WARNINGS	
#include <string.h>
#include <errno.h>
#include <stdio.h>

void error_reporting(int currentErrno);

int main(void)
{
	int currentErrno = 0;
	char currentChar = 0;

	// Open an existing file 
	FILE * weirdFile = fopen("./filee.txt", "r");

	// Store the errno
	currentErrno = errno;
	if (currentErrno != 0)
	{
		//prints the error using perror
		error_reporting(currentErrno);
		//prints the error using strerror
		printf("ERROR: %s", strerror(currentErrno));
		getchar(); getchar();
		//exits the program with the errno value (so when we get here it should say exited with error code 2)
		return currentErrno;
		currentErrno = 0;
	}
	else
	{
		fclose(weirdFile);
	}


	while (1);
	return 1;
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