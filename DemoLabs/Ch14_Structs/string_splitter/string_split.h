#define STRING_SPLIT
#ifdef STRING_SPLIT
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
#endif