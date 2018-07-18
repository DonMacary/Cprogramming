#pragma once
#ifndef MY_STRING_HEADER_
#define MY_STRING_HEADER_


/*
* FUNCTION:   int print_the_count(char * inputString, int strLen)
*
* ARGUMENTS:  inputString is a pointer to a character array (see: string) and is *NOT*
*                 guaranteed to be NULL terminated.  This is why the length of the
*                 string is also passed as an argument.
*             strLen is the length of the inputString.  strLen is required as a safety
*                 measure since inputString is not guaranteed to be null-terminated.
*                 strLen does not need to be long enough to include any null character,
*                 even if there was one.
*
* RETURNS:    # of alphabet letters found in inputString
*             ERR_NULL_POINTER is inputString is NULL
*             ERR_INVALID_LENGTH is strLen is unreasonable (zero or less)
*
* NOTES:      Not only does this function return the total number of alphabet letters
*                 that were counted, it should also print a table of letters from the
*                 string with their count.  Do not print any letters that were not
*                 found in inputString.
*             The "case" of the letter (upper or lower) should not matter for the count.
*                 There are different ways to ignore the case of a char.  It is up
*                 to the student to determine the method.
*/
int print_the_count(char * inputString, int strLen);
int reverse_it(char * forwardString, int strLen);
#endif