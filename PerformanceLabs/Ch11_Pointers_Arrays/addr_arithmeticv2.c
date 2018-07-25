////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////// PERFORMANCE LAB I.5.A-3 ////////////////////////////////////////////
////////////////////////////////////////////////// ADDRESS ARITHMETIC //////////////////////////////////////////////
/////////////////////////////////////////////////// "String Splitter" //////////////////////////////////////////////
////////////////////////////////////////////////// Instructor Solution /////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Do *NOT* modify main() as it runs 19 tests on split_the_string()
// Define char * split_the_string(char * string_ptr, char delimiter) with the following requirements:
// Return Value - 
//     In short, split_the_string() returns a pointer to a second null-terminated string upon success.
//     ERROR_NULL_POINTER if string_ptr is NULL
//     ERROR_ABUNDANT_DELIMITER if string_ptr has more than one occurrence of delimiter
//     ERROR_NULL_DELIMITER if delimiter is '\0' (0x0)
//     string_ptr if delimiter is not found
// Parameters - 
//     string_ptr is a null-terminated char array (see: string) that may include a delimiting
//         character.  That delimiting character (see: char delimiter) is a logical (as in virtual) break point
//         between two separate phrases/words/characters/sentences within the original null-terminated char array
//         (string_ptr).  If there is a delimiting character, this function will return the pointer to the
//         beginning of the second null-terminated char array (in addition to performing other procedures).
//         
//     delimiter is the delimiting character that separates the two strings logically combined inside the
//         the null-terminated char array found at string_ptr.  (NOTE:  delimiter should *NOT* be '\0' (0x0)
// Purpose - This function separates a null-terminated string into two different strings, breaking them apart
//     at "delimiter".  The first part of the original string (the portion of the array preceding "delimiter")
//     will remain as is.  The deliminating character will be changed to a null character ('\0').  Then, the
//     memory address of the second part of the original string (the portion of the array following the "delimiter")
//     will be returned to the caller.  This function can't handle more than two strings so it verifies there's
//     only one occurrence of the delimiting character.  It also checks if string_ptr is NULL.  This function
//     only utilizes Address Arithmetic (see: Pointer Math) to access the data found in the char array found
//     at string_ptr. 
// Version 3 incorporates tests to verify the student re-nul-terminated the original string
//     by replacing the "delimiter" character with '\0'.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#include <stdio.h>
#include <string.h>

#ifndef NULL
#define NULL ((void*) 0)
#endif

#ifdef ERROR_NULL_POINTER
#undef ERROR_NULL_POINTER
#endif
#define ERROR_NULL_POINTER ((char*)-1)

#ifdef ERROR_ABUNDANT_DELIMITER
#undef ERROR_ABUNDANT_DELIMITER
#endif
#define ERROR_ABUNDANT_DELIMITER ((char*)-2)

#ifdef ERROR_NULL_DELIMITER
#undef ERROR_NULL_DELIMITER
#endif
#define ERROR_NULL_DELIMITER ((char*)-3)

#ifndef TRUE
#define TRUE ((int)1)
#endif

#ifndef FALSE
#define FALSE ((int)0)
#endif

#define NUM_TEST_STRINGS 19

/*
 * FUNCTION:   char * split_the_string(char * string_ptr, char delimiter)
 *
 * ARGUMENTS:  string_ptr is a null-terminated string that may or may not contain a delimiting
 *                 character (see: delimiter) that logically separates two phrases to be "split"
 *             delimiter is the character that logically separates the two phrases that may be
 *                 in the null-terminated char array found at string_ptr
 *
 * RETURNS:	   char pointer to the first element of the second (null-terminated) phrase on success
 *             ERROR_NULL_POINTER if string_ptr is NULL
 *             ERROR_NULL_DELIMITER if delimiter is '\0' (0x0)
 *             ERROR_ABUNDANT_DELIMITER if string_ptr has more than one occurrence of delimiter
 *             string_ptr if delimiter is not found
 *
 * NOTES:      This function only utilizes address arithmetic to access information within the
 *                 null-terminated char array found at string_ptr
 *             Only access elements of the char array found at string_ptr using address arithmetic
 *                 (AKA pointer math).  The definition of this function should be entirely devoid
 *                 of the [ and ] characters.  (e.g., string_ptr[i] is forbidden)
 *             The only guarantee for the arguments is that string_ptr is null-terminated
 *             There is no guarantee it has a delimiter (return string_ptr if not)
 *             There is no guarantee it only has one delimiter if there is one (return ERROR_ABUNDANT_DELIMITER if not)
 *             There is no guarantee the delimiter is some char *other* than '\0' (return ERROR_NULL_DELIMITER if not)
 *             There is no guarantee that string_ptr has an address (return ERROR_NULL_POINTER if NULL)
 */
char * split_the_string(char * string_ptr, char delimiter);

int main(void)
{
	int i = 0;								// Iterating variable
	char * secondString_ptr = NULL;			// Holds the return value of split_the_string()
	int tempValue = 0;						// Used to temporarily hold strcmp()'s return value
	int numTestsRun = 0;					// Number of tests that ran
	int numTestsPassed = 0;					// Number of ran tests that passed
	int thereWasAnErrorCode = FALSE;		// Boolean representation that one of the #defined ERROR_* codes were returned
	int thereShouldBeAnErrorCode = FALSE;	// Boolean representation that one of the #defined ERROR_* codes should be returned

	//////////////////////////////////
	// INPUT STRINGS
	//////////////////////////////////
	/*
	 *  Normal input
	 *  Two examples each of special characters, letters, and non-printable
	 *      characters as delimiters
	 */
	char inputString0[] = { "Integer/Float" };	// Delimiter = 0x2F
	char inputString1[] = { "aeiou" };			// Delimiter = 0x69
	char inputString2[] = { "First phrase&Second phrase" };	// Delimiter = 0xA
	inputString2[12] = 10; // Manually setting delimiter
	char inputString3[] = {"C programming uses the & character to determine the address of something."}; // Delimite = 0x26
	char inputString4[] = { "Bust A Move" }; // Delimiter = 0x41
	char inputString5[] = { "Alexander Graham was a Scottish-born scientist, inventor, engineer and innovator who is credited with patenting the first practical telephone." }; // Delimiter = 0x7
	inputString5[16] = 7; // Manually setting delimiter
	/*
	 *  No delimiters found
	 *  Two examples
	 */
	char inputString6[] = { "This string does not have any delimiters." }; // Delimiter = 0x5A
	char inputString7[] = { "!@#$%^&*()_+" }; // Delimiter = 0x20
	/*
	 *  Null pointers
	 *  Two examples
	 */
	char * inputString8 = NULL; // Delimiter doesn't matter
	char * inputString9 = NULL; // Delimiter doesn't matter
	/*
	 *  Extra delimiters
	 *  Two examples each of two, 10, and many delimiters
	 */
	char inputString10[] = { "This uses spaces." }; // Delimiter = 0x20
	char inputString11[] = { "Fandango" }; // Delimiter = 0x61
	char inputString12[] = { "This-string-uses-dashes-as-delimiters.  They-were-selected-by-Hark." }; // Delimiter = 0x2D
	char inputString13[22] = { "a b c d e f g h i j k" }; // Delimiter = 0xD
	for (i = 1; i <= 20; i+= 2)
	{
		inputString13[i] = 13;
	}
	char inputString14[] = { "The dental patient says, 'Aaaaaaaah'" }; // Delimiter = 0x61
	char inputString15[127] = { 0 }; // Delimiter = 0x7F
	for (i = 0; i < 126; i+=2)
	{
		inputString15[i] = 0x7F;							// Sets a multitude of delimiting characters
		inputString15[i + 1] = (char)((2 * i) - i + 1); // Sets each index to it's own index number in decimal
	}
	inputString15[126] = 0; // For safety
	char inputString16[127] = { 0 }; // Delimiter = 0x5A;
	for (i = 0; i < 126; i++)
	{
		inputString16[i] = 0x5A;
	}
	char inputString17[] = { "Normal string with the null character as the deliminator" }; // Deliminator = 0x0
	char inputString18[] = { 0, 'W', 'h', 'o', 'o', 'p', 's', 0 }; // Deliminator = 0x0
	char * inputStringArray[NUM_TEST_STRINGS] = { \
		inputString0, inputString1, inputString2, \
		inputString3, inputString4, inputString5, \
		inputString6, inputString7, inputString8, \
		inputString9, inputString10, inputString11, \
		inputString12, inputString13, inputString14, \
		inputString15, inputString16, inputString17, \
		inputString18 };
	//////////////////////////////////
	//////////////////////////////////
	//////////////////////////////////

	//////////////////////////////////
	// DELIMITING CHARACTERS
	//////////////////////////////////
	char inputStringDelimiters[NUM_TEST_STRINGS] = { \
		0x2F, 0x69, 0xA, \
		0x26, 0x41, 0x7, \
		0x5A, 0x20, 0x13, \
		0x37, 0x20, 0x61, \
		0x2D, 0xD, 0x61, \
		0x7F, 0x5A, 0x0, \
		0x0 };
	//////////////////////////////////
	//////////////////////////////////
	//////////////////////////////////

	//////////////////////////////////
	// NEW INPUT STRINGS
	//////////////////////////////////
	char newInputString0[] = { "Integer" };
	char newInputString1[] = { "ae" };
	char newInputString2[] = { "First phrase" };
	char newInputString3[] = { "C programming uses the " };
	char newInputString4[] = { "Bust " };
	char newInputString5[] = { "Alexander Graham" };
	char newInputString6[] = { "This string does not have any delimiters." };
	char newInputString7[] = { "!@#$%^&*()_+" };
	//char newInputString8[] = { 0 };
	//char newInputString9[] = { 0 };
	char * newInputString8 = NULL;
	char * newInputString9 = NULL;
	char newInputString10[] = { "This uses spaces." };
	char newInputString11[] = { "Fandango" };
	char newInputString12[] = { "This-string-uses-dashes-as-delimiters.  They-were-selected-by-Hark." };
	char newInputString13[22] = { "a b c d e f g h i j k" };
	for (i = 1; i <= 20; i += 2)
	{
		newInputString13[i] = 13;
	}
	char newInputString14[] = { "The dental patient says, 'Aaaaaaaah'" };
	char newInputString15[127] = { 0 };
	for (i = 0; i < 126; i += 2)
	{
		newInputString15[i] = 0x7F;							// Sets a multitude of delimiting characters
		newInputString15[i + 1] = (char)((2 * i) - i + 1); // Sets each index to it's own index number in decimal
	}
	newInputString15[126] = 0; // For safety
	char newInputString16[127] = { 0 };
	for (i = 0; i < 126; i++)
	{
		newInputString16[i] = 0x5A;
	}
	newInputString16[126] = 0; // For safety
	char newInputString17[] = { "Normal string with the null character as the deliminator" }; 
	char newInputString18[] = { 0, 'W', 'h', 'o', 'o', 'p', 's', 0 };

	char * newInputStringArray[NUM_TEST_STRINGS] = { \
		newInputString0, newInputString1, newInputString2, \
		newInputString3, newInputString4, newInputString5, \
		newInputString6, newInputString7, newInputString8, \
		newInputString9, newInputString10, newInputString11, \
		newInputString12, newInputString13, newInputString14, \
		newInputString15, newInputString16, newInputString17, \
		newInputString18 \
	};
	//////////////////////////////////
	//////////////////////////////////
	//////////////////////////////////

	//////////////////////////////////
	// OUTPUT STRINGS
	//////////////////////////////////
	/*
	 *  Expected output
	 *  Parallels the input strings
	 */
	char outputString0[] = { "Float" };	// Delimiter = /
	char outputString1[] = { "ou" };			// Delimiter = i
	char outputString2[] = { "Second phrase" };	// Delimiter = 0xA
	char outputString3[] = { " character to determine the address of something." }; // Delimite = &
	char outputString4[] = { " Move" }; // Delimiter = A
	char outputString5[] = { "was a Scottish-born scientist, inventor, engineer and innovator who is credited with patenting the first practical telephone." }; // Delimiter = 0x7
    /*
	 *  No delimiters found
	 *  Two examples
	 */
	char outputString6[] = { "This string does not have any delimiters." }; // Delimiter = Z
	char outputString7[] = { "!@#$%^&*()_+" }; // Delimiter = 0x20
	/*
	*  Null pointers
	*  Two examples
	*/
	char * outputString8 = ERROR_NULL_POINTER;
	char * outputString9 = ERROR_NULL_POINTER;
	/*
	*  Extra delimiters
	*  Two examples each of two, 10, and many delimiters
	*/
	char * outputString10 = ERROR_ABUNDANT_DELIMITER; // Delimiter = 0x20
	char * outputString11 = ERROR_ABUNDANT_DELIMITER; // Delimiter = 0x61
	char * outputString12 = ERROR_ABUNDANT_DELIMITER; // Delimiter = 0x2D
	char * outputString13 = ERROR_ABUNDANT_DELIMITER; // Delimiter = 0xD
	char * outputString14 = ERROR_ABUNDANT_DELIMITER; // Delimiter = 0x61
	char * outputString15 = ERROR_ABUNDANT_DELIMITER; // Delimiter = 0x7F
	char * outputString16 = ERROR_ABUNDANT_DELIMITER; // Delimiter = 0x5A;
	char * outputString17 = ERROR_NULL_DELIMITER; // Deliminator = 0x0
	char * outputString18 = ERROR_NULL_DELIMITER; // Deliminator = 0x0
	char * outputStringArray[NUM_TEST_STRINGS] = { \
		outputString0, outputString1, outputString2, \
		outputString3, outputString4, outputString5, \
		outputString6, outputString7, outputString8, \
		outputString9, outputString10, outputString11, \
		outputString12, outputString13, outputString14, \
		outputString15, outputString16, outputString17, \
		outputString18 };
	//////////////////////////////////
	//////////////////////////////////
	//////////////////////////////////


	for (i = 0; i < (int)NUM_TEST_STRINGS; i++)
	{
		thereWasAnErrorCode = FALSE; // Reset the variable
		thereShouldBeAnErrorCode = FALSE; // Reset the variable
		printf("\nUNIT TEST #%d:\n\t", i);
		secondString_ptr = split_the_string(inputStringArray[i], inputStringDelimiters[i]);
		if (secondString_ptr == ERROR_ABUNDANT_DELIMITER || \
			secondString_ptr == ERROR_NULL_DELIMITER || \
			secondString_ptr == ERROR_NULL_POINTER)
		{
			thereWasAnErrorCode = TRUE;
		}
		if (outputStringArray[i] == ERROR_ABUNDANT_DELIMITER || outputStringArray[i] == ERROR_NULL_DELIMITER || outputStringArray[i] == ERROR_NULL_POINTER)
		{
			thereShouldBeAnErrorCode = TRUE;
		}
		if (thereWasAnErrorCode == FALSE && thereShouldBeAnErrorCode == FALSE && secondString_ptr && outputStringArray[i]) // If both pointers are *NOT* NULL...
		{
			/* TEST ORIGINAL STRING WAS NEWLY NUL TERMINATED */
//			puts(secondString_ptr); // DEBUGGING
			printf("Original String Test:\t");
			tempValue = strcmp(newInputStringArray[i], inputStringArray[i]);
			numTestsRun++;
			if (!tempValue) // If those two strings match...
			{
				printf("Success\n\t"); // ...then let the human know...
				numTestsPassed++; // ...and increment the counter
			}
			else // ...Otherwise, they don't match...
			{
				printf("Error\n\t"); // ...so let the human know
				printf("Received:\t%s\n\t", inputStringArray[i]);
				printf("Expected:\t%s\n\t", newInputStringArray[i]);
			}

			/* TEST THE NEWLY SPLIT STRING */
			printf("Split String Test:\t");
			tempValue = strcmp(secondString_ptr, outputStringArray[i]); // ...then compare the two strings
			numTestsRun++;
			if (!tempValue) // If those two strings match...
			{
				puts("Success"); // ...then let the human know...
				numTestsPassed++; // ...and increment the counter
			}
			else // ...Otherwise, they don't match...
			{
				printf("Error\n\t"); // ...so let the human know
				printf("Received:\t%s\n\t", secondString_ptr);
				printf("Expected:\t%s\n\t", outputStringArray[i]);
			}
		}
		else	/* THERE WAS AN ERROR CODE */
		{
			/* TEST THE ORIGINAL STRING */
			printf("Original String Test:\t");
			
			if (newInputStringArray[i] > NULL && inputStringArray[i] > NULL)
			{
				tempValue = strcmp(newInputStringArray[i], inputStringArray[i]);
			}
			else
			{
				tempValue = !(newInputStringArray[i] == inputStringArray[i]);
			}
			numTestsRun++;
			if (!tempValue) // If those two strings match...
			{
				printf("Success\n\t"); // ...then let the human know...
				numTestsPassed++; // ...and increment the counter
			}
			else // ...Otherwise, they don't match...
			{
				printf("Error\n\t"); // ...so let the human know
				if (inputStringArray[i] != NULL && \
					inputStringArray[i] != ERROR_NULL_POINTER && \
					inputStringArray[i] != ERROR_ABUNDANT_DELIMITER && \
					inputStringArray[i] != ERROR_NULL_DELIMITER \
					)
				{
					printf("Original String:\t%s\n\t", inputStringArray[i]);
				}
				else
				{
					printf("Original String:\tNULL\n\t");
				}

				if (newInputStringArray[i] != NULL && \
					newInputStringArray[i] != ERROR_NULL_POINTER && \
					newInputStringArray[i] != ERROR_ABUNDANT_DELIMITER && \
					newInputStringArray[i] != ERROR_NULL_DELIMITER \
					)
				{
					printf("Expected String:\t%s\n\t", newInputStringArray[i]);
				}
				else
				{
					printf("Expected String:\tNULL\n\t");
				}
			}

			/* TEST THE NEWLY SPLIT STRING */
			printf("Split String Test:\t");
//			tempValue = strcmp(secondString_ptr, outputStringArray[i]); // ...then compare the two strings
			numTestsRun++;

			if (secondString_ptr == outputStringArray[i]) // Otherwise, there's at least one error so if they match...
			{
				puts("Success"); // ...then count that as a success because they match...
				numTestsPassed++; // ...and increment the counter
			}
			else // Otherwise, only one of the pointers is NULL so they don't match...
			{
				printf("Error\n\t"); // ...so let the human know
				if (secondString_ptr != NULL && \
					secondString_ptr != ERROR_NULL_POINTER && \
					secondString_ptr != ERROR_ABUNDANT_DELIMITER && \
					secondString_ptr != ERROR_NULL_DELIMITER \
					)
				{
					printf("Second String:\t%s\n\t", secondString_ptr);
				}
				else
				{
					printf("Second String:\t\tNULL\n\t");
				}

				if (outputStringArray[i] != NULL && \
					outputStringArray[i] != ERROR_NULL_POINTER && \
					outputStringArray[i] != ERROR_ABUNDANT_DELIMITER && \
					outputStringArray[i] != ERROR_NULL_DELIMITER \
					)
				{
					printf("Expected String:\t%s\n\t", outputStringArray[i]);
				}
				else
				{
					printf("Expected String:\tNULL\n\t");
				}
			}
		}
	}

	/* Let the human know how they did in a safe way */
	if (numTestsRun && numTestsPassed)
	{
		if (numTestsRun >= numTestsPassed)
		{
			printf("\nOf the %d tests run...\n%d tests passed.", numTestsRun, numTestsPassed);
		}
		else
		{
			fputs("Something has gone awry with the test counter.", stderr);
		}
	}

	return 0;
}

/*
 * FUNCTION:   char * split_the_string(char * string_ptr, char delimiter)
 *
 * ARGUMENTS:  string_ptr is a null-terminated string that may or may not contain a delimiting
 *                 character (see: delimiter) that logically separates two phrases to be "split"
 *             delimiter is the character that logically separates the two phrases that may be
 *                 in the null-terminated char array found at string_ptr
 *
 * RETURNS:	   char pointer to the first element of the second (null-terminated) phrase on success
 *             ERROR_NULL_POINTER if string_ptr is NULL
 *             ERROR_NULL_DELIMITER if delimiter is '\0' (0x0)
 *             ERROR_ABUNDANT_DELIMITER if string_ptr has more than one occurrence of delimiter
 *             string_ptr if delimiter is not found
 *
 * NOTES:      This function only utilizes address arithmetic to access information within the
 *                 null-terminated char array found at string_ptr
 *             Only access elements of the char array found at string_ptr using address arithmetic
 *                 (AKA pointer math).  The definition of this function should be entirely devoid
 *                 of the [ and ] characters.  (e.g., string_ptr[i] is forbidden)
 *             The only guarantee for the arguments is that string_ptr is null-terminated
 *             There is no guarantee it has a delimiter (return string_ptr if not)
 *             There is no guarantee it only has one delimiter if there is one (return ERROR_ABUNDANT_DELIMITER if not)
 *             There is no guarantee the delimiter is some char *other* than '\0' (return ERROR_NULL_DELIMITER if not)
 *             There is no guarantee that string_ptr has an address (return ERROR_NULL_POINTER if NULL)
 */
char * split_the_string(char * string_ptr, char delimiter)
{

	// YOUR CODE HERE
	//////////////////////////////////
	//////////////////////////////////
	//////////////////////////////////
	return NULL;
}
