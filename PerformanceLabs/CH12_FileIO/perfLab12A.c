/********************************************************************************************************************
/   AUTHOR: ELF
/   COURSE: C Programming
/   PROGRAM NAME: perfLab12A.c
/   PROGRAM DESCRIPTION: Performance Lab 12A - MIGHTY MORHPIN'
/   INSTRUCTIONS:
		## PERORMANCE LAB: MIGHTY MORHPIN'

        File I/O – getc()
        “Mighty Morphin”

        Save the lyrics for the Mighty Morphin' Power Rangers theme song into a text file.

        **Write a C program to:**

        * Open the file in read-only mode
        * Read it char-by-char
        * Print each char as it is read
        * Close the file at the end
**********************************************************************************************************************/

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main(void)
{
	FILE * myFile_ptr = fopen("MMPR.txt", "r"); // Opens a read-only file
	char readFromFile = 0; // Store char-by-char input from myFile_ptr
	if (myFile_ptr != NULL) 	// Verify fopen() succeeded
	{
		while (readFromFile != EOF) // Continue reading until the end of file
		{
			readFromFile = getc(myFile_ptr); 	// Read one character
			putc(readFromFile, stdout); 		// Print that character
		}
		fclose(myFile_ptr); // Always fclose anything you fopen
		system("start https://www.youtube.com/watch?v=7Wt6XlVob_E");
	}
	else 			// Otherwise, fopen() failed
	{
		puts("Error opening file!"); 	// Tell the user and...
		getchar(); getchar();
		return -1;			// Return an error value
	}

	getchar(); getchar();

	return 0;
}