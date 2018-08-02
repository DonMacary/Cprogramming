////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////// DEMONSTRATION LAB I.7.A-1 //////////////////////////////////////////
///////////////////////////////////////////////////////// STRUCT ///////////////////////////////////////////////////
//////////////////////////////////////////// "String Splitter Test Struct" /////////////////////////////////////////
///////////////////////////////////////////////// Instructor Solution //////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Define a struct to test split_the_string() from Performance Lab I.5.a-3 (see below)
// Test input should include:
//     Input string
//     Delimiter
//     Expected return value
// Only Address Arithmetic is permitted
// Write at least one test to cover every requirement:
//     Normal input
//     string_ptr is NULL
//     string_ptr has more than one occurrence of delimiter
//     Delimimted is '\0' (0x0)
//     string_ptr is missing any occurrence of delimiter
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////// PERFORMANCE LAB I.5.A-3 ////////////////////////////////////////////
////////////////////////////////////////////////// ADDRESS ARITHMETIC //////////////////////////////////////////////
/////////////////////////////////////////////////// "String Splitter" //////////////////////////////////////////////
////////////////////////////////////////////////// Instructor Solution /////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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

struct FunctionTest {
	char * input_string_ptr;			// Holds the string_ptr input parameter to split_the_string()
	char input_delimiter;				// Holds the delimiter input parameter to split_the_string()
	char * split_string_return_ptr;		// Holds the expected return value from split_the_string()
};

int main(void)
{
	int i = 0;
	int numTotalTests = 0;
	int numTestsRun = 0;
	int numTestsPassed = 0;
	char * tempReturnValue = NULL;

	/* 0 - NORMAL INPUT */
	char stringInput0[] = { "Split by a semi-colon;This is the second part." };
	struct FunctionTest test0 = { stringInput0, ';', (stringInput0 + 22) };

	/* 1 - NULL POINTER */
	char * stringInput1 = NULL;
	struct FunctionTest test1 = { stringInput1, '?', ERROR_NULL_POINTER };

	/* 2 - MORE THAN ONE DELIMITER */
	char stringInput2[] = { "Too many delimiters!" };
	struct FunctionTest test2 = { stringInput2, 'o', ERROR_ABUNDANT_DELIMITER };

	/* 3 - NULL DELIMITER */
	char stringInput3[] = { "Perfectly normal string" };
	struct FunctionTest test3 = { stringInput3, 0x0, ERROR_NULL_DELIMITER };

	/* 4 - MISSING DELIMITER */
	char stringInput4[] = { "This string will be missing a delimiter!" };
	struct FunctionTest test4 = { stringInput4, 'z', stringInput4 };

	/* 5 - NORMAL INPUT - EDGE CASE 1 - Delimiter is first */
	char stringInput5[] = { "The delimiter will be first in this string." };
	struct FunctionTest test5 = { stringInput5, 'T', (stringInput5 + 1) };

	/* 6 - NORMAL INPUT - EDGE CASE 2 - Delimiter is last */
	char stringInput6[] = { "The delimiter will be last in this string." };
	struct FunctionTest test6 = { stringInput6, '.', (stringInput6 + 42) };

	/* 7 - NORMAL INPUT - Delimiter is a non-printable character */
	char stringInput7[] = { 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0x9, 0xA, 0xB, 0xC, 0xD, 0xE, 0xF, 0x0 };
	struct FunctionTest test7 = { stringInput7, 0xA, (stringInput7 + 10) };

	/* 8 - NORMAL INPUT - Two delimiters, one hidden behind the nul terminating character */
	char stringInput8[] = { 0x48, 0x61, 0x72, 0x6B, 0x0, 0x6C, 0x65, 0x72, 0x6F, 0x61, 0x62, 0x0 };
	struct FunctionTest test8 = { stringInput8, 0x61, (stringInput8 + 2) };

	/* 9 - NORMAL INPUT - No delimiter found */
	char stringInput9[] = { "Yeah just put thppppppt." };
	struct FunctionTest test9;
	test9.input_string_ptr = stringInput9;
	test9.input_delimiter = '$';
	test9.split_string_return_ptr = stringInput9;

	/* 10 - WEIRD INPUT - Send in an input string that only contains the delimiter */
	char stringInput10[] = { 'a', '\0' };
	struct FunctionTest test10;
	test10.input_string_ptr = stringInput10;
	test10.input_delimiter = 'a';
	test10.split_string_return_ptr = (stringInput10 + 1);

	/* ARRAY OF TEST INPUT STRUCTS */
	struct FunctionTest inputArray[] = { test0, test1, test2, test3, test4, test5, test6, test7, test8, test9, test10 };

	numTotalTests = sizeof(inputArray) / sizeof(*(inputArray));

	for (i = 0; i < numTotalTests; i++)
	{
		/* FUNCTION CALL WITH TEST INPUT */
		tempReturnValue = split_the_string((inputArray + i)->input_string_ptr, (inputArray + i)->input_delimiter);

		/* TEST RETURN VALUE */
		printf("TEST #%2d\n\t", i);
		numTestsRun++;
		if (tempReturnValue == ((inputArray + i)->split_string_return_ptr))
		{
			printf("Passed\n");
			numTestsPassed++;
		}
		else
		{
			printf("FAIL\n\t");
			printf("Expected the following string at pointer %p:\n", (inputArray + i)->split_string_return_ptr);
			if ((inputArray + 1)->split_string_return_ptr != NULL && \
				(inputArray + 1)->split_string_return_ptr != ERROR_NULL_POINTER && \
				(inputArray + 1)->split_string_return_ptr != ERROR_ABUNDANT_DELIMITER && \
				(inputArray + 1)->split_string_return_ptr != ERROR_NULL_POINTER)
			{
				printf("%s", (inputArray + i));
			}
			else
			{
				printf("NULL\n");
			}

			printf("Received the following string at pointer %p:\n", tempReturnValue);
			if (tempReturnValue != NULL && \
				tempReturnValue != ERROR_NULL_POINTER && \
				tempReturnValue != ERROR_ABUNDANT_DELIMITER && \
				tempReturnValue != ERROR_NULL_POINTER)
			{
				printf("%s", tempReturnValue);
			}
			else
			{
				printf("NULL\n");
			}

		}
	}

	/* Let the human know how they did in a safe way */
	if (numTestsRun != numTotalTests)
	{
		printf("\nERROR:  Some of the established tests did not run.");
	}
	if (numTestsRun > 0)
	{
		printf("\nOf the %d tests run...\n%d tests passed.", numTestsRun, numTestsPassed);
	}

	getchar();
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
	char * returnValue_ptr = NULL;
	int i = 0;
	int delimiterCount = 0;

	if (!string_ptr) // If the char pointer is NULL...
	{
		returnValue_ptr = ERROR_NULL_POINTER; // ...then return ERROR_NULL_POINTER
	}
	else if (!delimiter) // If the delimiter is '\0' (0x0)...
	{
		returnValue_ptr = ERROR_NULL_DELIMITER; // ...then return ERROR_NULL_DELIMITER
	}
	else
	{
		/* Count delimiters */
		i = 0;
		while (*(string_ptr + i)) // Perform this code block until the null terminator has been reached
		{
			if (*(string_ptr + i) == delimiter) // If a delimiter is found...
			{
				delimiterCount++; // ...then increase the count
			}
			i++; // Iterate the variable that will take this loop to the next contiguous memory address
		}

		/* Test number of delimiters found */
		if (delimiterCount > 1) // If there's more than one delimiter...
		{
			returnValue_ptr = ERROR_ABUNDANT_DELIMITER; // ...then return NULL
		}
		else if (!delimiterCount) // If there's no delimiter's found...
		{
			returnValue_ptr = string_ptr; // ...return NULL
		}
		else /* This is where the actual "split the string" algorithm lies */
		{
			i = 0;
			do // Execute this code...
			{
				if (*(string_ptr + i) == delimiter) // If this memory address matches the delimiter...
				{
					/* ...then clear the delimiter... */
					*(string_ptr + i) = 0;
					/* ...and set the return value */
					returnValue_ptr = (string_ptr + i + 1);
				}
				i++; // Increment to the next element
			} while (!returnValue_ptr); // ...until you notice that the return variable has been populated with an address
		}
	}

	return returnValue_ptr;
}
