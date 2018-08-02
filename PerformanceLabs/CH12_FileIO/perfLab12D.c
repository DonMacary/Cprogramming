/********************************************************************************************************************
/   AUTHOR: ELF
/   COURSE: C Programming
/   PROGRAM NAME: perfLab12D.c
/   PROGRAM DESCRIPTION: Performance Lab 12D - CONTENT COPY Line by Line
/   INSTRUCTIONS:
## PERFORMANCE LAB: CONTENT COPY (LINE-BY-LINE)

File I/O – fputs()

**“Content Copy”**

* Open an existing file in read mode.
* Open a new file in write mode.
* Copy the existing file into the new file **line-by-line** .
* Close the existing file.
* Close and open the new file in *read* mode.
* Print the new file **line-by-line**.
**********************************************************************************************************************/


#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#define MAX_BUFFER 256

int main(void)
{
	FILE * myInputFile_ptr = fopen("input.txt", "r"); //open my input file
	FILE * myOutputFile_ptr = fopen("output.txt", "w"); //create my output file
	char readStr[MAX_BUFFER] = { 0 }; //place to store the input strings

	if (myInputFile_ptr != NULL || myOutputFile_ptr != NULL) // check to see if the file was opened correctly
	{
		while (fgets(readStr, MAX_BUFFER, myInputFile_ptr) != NULL) //check to see if there is any input left
		{			
			fputs(readStr, myOutputFile_ptr); //write the string to the new file

		}
		fclose(myInputFile_ptr); //CLOSE FILE
		fclose(myOutputFile_ptr);

	}
	else
	{
		printf("Error Opening Files\n"); //throw an error if there was an issue opening the file
		getchar(); getchar();
		return -1;
	}
	FILE *myOutputFile2_ptr = fopen("output.txt", "r"); // open my outputfile that I just wrote
	char readStr2[MAX_BUFFER] = { 0 };
	if (myOutputFile2_ptr != NULL)		//check to make sure we opened the file correctly
	{
		while (fgets(readStr2, MAX_BUFFER, myOutputFile2_ptr) != NULL) // check tho see if there is any input left
		{
			fputs(readStr2, stdout); //write the contents to stdout
			
		}
	}
	fclose(myOutputFile2_ptr); //close the file
			

	getchar(); getchar();

	return 0;
}