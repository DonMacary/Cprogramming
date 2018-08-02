/********************************************************************************************************************
/   AUTHOR: ELF
/   COURSE: C Programming
/   PROGRAM NAME: perfLab12B.c
/   PROGRAM DESCRIPTION: Performance Lab 12B - YOUR SONG
/   INSTRUCTIONS:
		## PERFOMANCE LAB: YOUR SONG

            File I/O – fgets()
            “Your Song”

            Save your favorite song into a text file.
            **Write a C program to:**
            * Open the file in read-only mode
            * Read it line-by-line
            * Print each line as it is read
            * Close the file at the end
**********************************************************************************************************************/

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main(void)
{
	FILE * myFile_ptr = fopen("WMAA.txt", "r"); // Opens a read-only file
	char readFromFile = 0; // Store char-by-char input from myFile_ptr
	if (myFile_ptr != NULL) 	// Verify fopen() succeeded
	{
		while (readFromFile != EOF) // Continue reading until the end of file
		{
			readFromFile = getc(myFile_ptr); 	// Read one character
			putc(readFromFile, stdout); 		// Print that character
		}
		fclose(myFile_ptr); // Always fclose anything you fopen
		system("start https://www.youtube.com/watch?v=K7l5ZeVVoCA");
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