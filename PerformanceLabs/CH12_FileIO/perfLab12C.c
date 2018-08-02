/********************************************************************************************************************
/   AUTHOR: ELF
/   COURSE: C Programming
/   PROGRAM NAME: perfLab12C.c
/   PROGRAM DESCRIPTION: Performance Lab 12C - CONTENT COPY CHAR-BY-CHAR
/   INSTRUCTIONS:
	## PEFORMANCE LAB: CONTENT COPY CHAR-BY-CHAR

        File I/O – putc()

        **“Content Copy”**
        * Open an existing file in read mode.
        * Open a new file in write mode.
        * Copy the existing file into the new file **char-by-char**. 
        * Close the existing file.
        * Close and open the new file in *read* mode.
        * Print the new file **char-by-char**.
**********************************************************************************************************************/

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main(void)
{
	FILE * myInputFile_ptr = fopen("input.txt", "r"); //open input file
	FILE * myOutputFile_ptr = fopen("output.txt", "w"); //open output file
	char readChar = 0; //temp char storage

	if (myInputFile_ptr != NULL || myOutputFile_ptr != NULL) //check if we opened files correctly
	{
		while (readChar != EOF) //make sure we have input left
		{
			readChar = getc(myInputFile_ptr); //read the character
			putc(readChar, myOutputFile_ptr); //write the character to output file
			//putc(readChar, stdout);
		}
		fclose(myInputFile_ptr);
		fclose(myOutputFile_ptr);

	}
	else
	{
		printf("Error Opening Files\n");
		getchar(); getchar();
		return -1;
	}
	FILE *myOutoutFile2_ptr = fopen("output.txt", "r"); //open the output file wew just created
	char readChar2 = 0;
	if (myOutoutFile2_ptr != NULL) //check to see if the file opened correctly
	{
		while (readChar2 != EOF) // is there anything left to read?
		{
			readChar2 = getc(myOutoutFile2_ptr); // read the charcter to temp char
			putc(readChar2, stdout); //print the temp char to stdout
		}
	}
	fclose(myOutoutFile2_ptr);


	getchar(); getchar();

	return 0;
}