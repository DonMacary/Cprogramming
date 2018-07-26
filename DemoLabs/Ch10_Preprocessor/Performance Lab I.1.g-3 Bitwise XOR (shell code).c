//////////////////////////////////////////////////////////////////////
///////////////////// PERFORMANCE LAB I.1.g-3 ////////////////////////
///////////////// Brute force an obfuscated string ///////////////////
//////////////////////////////////////////////////////////////////////
// C:\Temp\Obfuscated?.txt contains an obfuscated string
//     ? represents the fact that multiple files exist, (1 - 14)
//     Modify the "#define File?" line below to access different files
//     The ? number equates to the Obfuscated?.txt file that is opened
// The original string was XOR'd against a four (4) bit mask stored in
//     an unsigned char
// Shell code has been provided that already:
//     Safely read the file contents into a char array
//     Loops through each element of the char array
// Fill in the shell code, as documented, to brute force this
//     obfuscated string
// There are sections of this shell code that contain a comment block
//     specifying remaining code requirements.  Replace the comment
//     block with the code required.
// Visually scan the results for a human-readable string
//////////////////////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#define BUFF_SIZE 256
#define MAX_MASKS 14
#define File1

int main(void)
{
	unsigned char cypherText[BUFF_SIZE] = { 0 }; // Stores the obfuscated text from the C:\Temp file
	unsigned char clearText[BUFF_SIZE] = { 0 }; // Stores the XOR'd cypherText 
	unsigned char xorMask = 0; // Stores the mask used to XOR the cypher text read from the file
	unsigned char inputChar = 255; // Temporarily stores file input character by character on its way to the cypher text array
	unsigned int i = 0; // Used to iterate through a loop
	unsigned int j = 0; // Used to iterate through a loop
	FILE * obfuscatedFile; // File pointer used to store the memory address of the opened Obfuscated?.txt file
#ifdef File1
	obfuscatedFile = fopen("C:\\Temp\\Obfuscated1.txt", "r"); // Opens Obfuscated1.txt as read-only.  "#define File1" to access this file.
#endif
#ifdef File2
	obfuscatedFile = fopen("C:\\Temp\\Obfuscated2.txt", "r"); // Opens Obfuscated2.txt as read-only.  "#define File2" to access this file.
#endif
#ifdef File3
	obfuscatedFile = fopen("C:\\Temp\\Obfuscated3.txt", "r"); // Opens Obfuscated3.txt as read-only.  "#define File3" to access this file.
#endif
#ifdef File4
	obfuscatedFile = fopen("C:\\Temp\\Obfuscated4.txt", "r"); // Opens Obfuscated4.txt as read-only.  "#define File4" to access this file.
#endif
#ifdef File5
	obfuscatedFile = fopen("C:\\Temp\\Obfuscated5.txt", "r"); // Opens Obfuscated5.txt as read-only.  "#define File5" to access this file.
#endif
#ifdef File6
	obfuscatedFile = fopen("C:\\Temp\\Obfuscated6.txt", "r"); // Opens Obfuscated6.txt as read-only.  "#define File6" to access this file.
#endif
#ifdef File7
	obfuscatedFile = fopen("C:\\Temp\\Obfuscated7.txt", "r"); // Opens Obfuscated7.txt as read-only.  "#define File7" to access this file.
#endif
#ifdef File8
	obfuscatedFile = fopen("C:\\Temp\\Obfuscated8.txt", "r"); // Opens Obfuscated8.txt as read-only.  "#define File8" to access this file.
#endif
#ifdef File9
	obfuscatedFile = fopen("C:\\Temp\\Obfuscated9.txt", "r"); // Opens Obfuscated9.txt as read-only.  "#define File9" to access this file.
#endif
#ifdef File10
	obfuscatedFile = fopen("C:\\Temp\\Obfuscated10.txt", "r"); // Opens Obfuscated10.txt as read-only.  "#define File10" to access this file.
#endif
#ifdef File11
	obfuscatedFile = fopen("C:\\Temp\\Obfuscated11.txt", "r"); // Opens Obfuscated11.txt as read-only.  "#define File11" to access this file.
#endif
#ifdef File12
	obfuscatedFile = fopen("C:\\Temp\\Obfuscated12.txt", "r"); // Opens Obfuscated12.txt as read-only.  "#define File12" to access this file.
#endif
#ifdef File13
	obfuscatedFile = fopen("C:\\Temp\\Obfuscated13.txt", "r"); // Opens Obfuscated13.txt as read-only.  "#define File13" to access this file.
#endif
#ifdef File14
	obfuscatedFile = fopen("C:\\Temp\\Obfuscated14.txt", "r"); // Opens Obfuscated14.txt as read-only.  "#define File14" to access this file.
#endif

	/* Verify the file is open */
	if (obfuscatedFile) // File pointer is NOT NULL
	{
		/* Stops at newlines (10), line feeds (13), End of File (EOF), empty characters (inputChar), and verifies there's room at the end for a newline and NUL termination */
		while (inputChar != 10 && inputChar != 13 && inputChar != EOF && inputChar && i < (BUFF_SIZE - 1))
		{
			inputChar = fgetc(obfuscatedFile); // Reads one character from the open file into inputChar
			cypherText[i] = inputChar; // Assigns inputChar into an element of the cypher text array
			i++; // Increments the counter used to iterate through the array
		}
		cypherText[BUFF_SIZE - 1] = '\0'; // Manually null terminates the string... for safety
	}
	else // File pointer is NULL
	{
		fprintf(stderr, "Error:  Unable to input file! \n"); // Prints and error statement
		return -1; // Ends main() and returns a value of -1 to indicate an error
	}

	/* Iterate all possible	XOR mask values for each cypher text array */
	for (xorMask = 1; xorMask <= MAX_MASKS; xorMask++) // Iterates through xorMask (1, 2, 3, ... MAX_MASKS).  (see "#define MAX_MASKS")
	{
		for (j = 0; j < strlen(cypherText); j++) // Iterates through all elements of the cypherText array
		{
			if (cypherText[j] != 0 && cypherText[j] != 10 && cypherText[j] != 13) // Skips XOR'ing NULL, newline, and line feed characters...
			{
				/**************************************************************
				Write a statement, or block of code, here that:
				    A. Performs a Bitwise XOR between the unsigned char 
					variable named "xorMask" and index "j" of the unsigned char
					array named "cypherText"
					B. Assign the result from the Bitwise XOR into index "j" of
					the unsigned char array named "clearText"
					C. Remove, or comment, the printf statement on the line
					below.  It was only intended as a placeholder for the
					statement, or block of code, you must write here.
				**************************************************************/
				printf("****\nReplace this statement with a Bitwise XOR\n****"); // ...and XORs all the rest against xorMASK, storing the result in the clearText array
			}
			else
			{
				/**************************************************************
				Write a statement, or block of code, here that:
				A. Assigns index "j" of the unsigned char array named
				"cypherText" into index "j" of the unsigned char array named 
				"clearText"
				NOTE:  No XOR is necessary here because we want to preserve
				any NULL, newline, or line feed characters.
				**************************************************************/
				printf("****\nReplace this statement with an assignment statement\n****");
			}
		}
		printf("\nMask #%d produced the string: \n\t%s", xorMask, clearText); // This line is printed once for each of the XOR masks attempted on the cypher text
	}

	/* Print the Cleartext */
//	puts(clearText1); // DEBUGGING
	/* Print the Cyphertext */
//	puts(cypherText); // DEBUGGING
	/* Close the open file */
	fclose(obfuscatedFile); // Closes the open file

	return 0;
}
