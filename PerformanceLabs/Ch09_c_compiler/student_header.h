#ifndef _STUDENT_HEADER_INCLUDED_
#define _STUDENT_HEADER_INCLUDED_

/*
 * FUNCTION:   int sort_int_array(int * intArray, int arrayLen)
 *
 * ARGUMENTS:  inputArray is a pointer to an integer array and is *NOT*
 *                 terminated by a special character.  This is why the length of the
 *                 string is also passed as an argument (see: arrayLen).
 *             arrayLen is the length of intArray.  arrayLen is required as a safety
 *                 measure since intArray is not terminated by any special character.
 *
 * RETURNS:    0 on success
 *             -1 if intArray is NULL
 *             -2 if intArray is unsortable (dimension of 1) or arrayLen is unrealistic (e.g., negative)
 *
 * NOTES:      This function should simply sort an array of integers from largest to smallest, in place.
 *                 This means the values of integers should be swapped within the given array.
 *             This function was written in 53 lines (counting function declaration, Allman style
 *                 brackets, error checking and comments.  The concept may be more difficult than the
 *                 implementation.
 *             Other than the requirements listed here, the student is given freedom to solve this
 *                 problem as they see fit.  This lab is not a test of iterative vs recursive programming.
 *                 It is not a test to see how few lines of code someone can solve this problem in.
 *                 It merely forces reinforces previous objectives while also requiring the students
 *                 to manually link object code in order to test their solution.
 */
int sort_int_array(int * intArray, int arrayLen);

#endif
