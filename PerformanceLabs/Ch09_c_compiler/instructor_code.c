//#include "c:\Users\hark\documents\visual studio 2013\Projects\MQT (I.4.a) Performance Lab 2\MQT (I.4.a) Performance Lab 2\student_header.h"
#include <stdio.h>
#include <limits.h>
#include "student_header.h"

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

int print_array(int * arrayToPrint, int arrayLength);
int do_arrays_match(int * modifiedArray, int * expectedArray, int arrayLength);

int main(void)
{
	/*
	*  VARIABLE DECLARATION
	*/
	int i = 0;
	int j = 0;
	int tempReturnValue = 0;
	int tempRealLength = 0;
	int testsRun = 0;
	int testsPassed = 0;
	
	/*
	 *  TEST INPUT DECLARATION
	 *  The following input is captured in parallel arrays
	 *  testArrayX[] holds the int array to test
	 *  testArrayArray[] is an array that holds pointers to all of the testArrayX[]s
	 *  testArrayLen[] holds the function input value for each testArrayX[] dimension (NOTE: Some are purposely wrong to test function error handling)
	 *  realArrayLen[] holds the actual dimension for each testArrayX[] (for safety)
	 *  expectedTestResults[] holds the expected return values for sort_int_array()
	 *  expectedArrayX[] holds the sorted array expectation.  expectedArrayX[] should match testArrayX[] *after* calling sort_int_array()
	 *  expectedArrayArray[] is an array that holds pointers to all of the expectedArrayX[]s
	 */

	/* TEST INT ARRAY INPUT */
	int testArray1 [] = { 1, 2, 3, 4 };
	int testArray2 [] = { 4, 3, 2, 5, 93 };
	int testArray3 [] = { 2, 3, 4, 1, -23, -101 };
	int testArray4 [] = { 2, 4, 3 };
	int testArray5 [] = { 1, 2, 2, 1, 2, 1 };
	int testArray6 [] = { 19, -3, -24, -80 };
	int testArray7 [] = { 100, 99, 98 };
	int testArray8 [] = { 1 };
	int testArray9 [] = { 4919, 201527 };
	int testArray10[] = { -2, -1, 0, -3 };
	int testArray11[] = { 42, 0xEA7, 0xBEEF };
	int testArray12[] = { 0, 0xBAD, 0xBEEF };
	int * testArray13 = NULL;
	int testArray14[] = { 234, 23452, 239, -234, 456, -456, 2372, 29912, 0, -1, 1, 29912, 2372, 234, 239 };
	int testArray15[] = { SHRT_MIN, SHRT_MAX, USHRT_MAX, INT_MIN, INT_MAX, 0, 1, -1 };

	/* ARRAY OF TEST INT ARRAY INPUT */
	int * testArrayArray[] = { testArray1, testArray2, testArray3, testArray4, testArray5, testArray6, testArray7, testArray8, testArray9, testArray10, testArray11, testArray12, testArray13, testArray14, testArray15 };

	/* TEST ARRAY LENGTH INPUT*/
	int testArrayLen[] = { 4, 5, 6, 3, 6, 4, 3, 1, 2, 0, -1, 1, 0xBAD, 15, 8 };
	
	/* ACTUAL TEST ARRAY LENGTH */
	int realArrayLen[] = { 4, 5, 6, 3, 6, 4, 3, 1, 2, 4, 3, 3, 0, 15, 8 };

	/* EXPECTED sort_int_array() RETURN VALUES */
	int expectedTestResults[] = { 0, 0, 0, 0, 0, 0, 0, -2, 0, -2, -2, -2, -1, 0, 0 };
	
	/* EXPECTED INT ARRAY OUTPUT */
	int expectedArray1 [] = { 4, 3, 2, 1 };
	int expectedArray2 [] = { 93, 5, 4, 3, 2};
	int expectedArray3 [] = { 4, 3, 2, 1, -23, -101 };
	int expectedArray4 [] = { 4, 3, 2};
	int expectedArray5 [] = { 2, 2, 2, 1, 1, 1};
	int expectedArray6 [] = { 19, -3, -24, -80};
	int expectedArray7 [] = { 100, 99, 98 };
	int expectedArray8 [] = { 1 };
	int expectedArray9 [] = { 201527, 4919 };
	int expectedArray10[] = { -2, -1, 0, -3 };
	int expectedArray11[] = { 42, 3751, 48879 };
	int expectedArray12[] = { 0, 2989, 48879 };
	int * expectedArray13 = NULL;
	int expectedArray14[] = { 29912, 29912, 23452, 2372, 2372, 456, 239, 239, 234, 234, 1, 0, -1, -234, -456 };
	int expectedArray15[] = { INT_MAX, USHRT_MAX, SHRT_MAX, 1, 0, -1, SHRT_MIN, INT_MIN };

	/* ARRAY OF EXPECTED INT ARRAY OUTPUT */
	int * expectedArrayArray[] = { expectedArray1, expectedArray2, expectedArray3, expectedArray4, expectedArray5, expectedArray6, expectedArray7, expectedArray8, expectedArray9, expectedArray10, expectedArray11, expectedArray12, expectedArray13, expectedArray14, expectedArray15 };


	/*
	 *  PROGRAM INTEGRITY CHECK
	 */
	int testArrayArrayLENGTH = sizeof(testArrayArray) / sizeof(testArrayArray[0]);
	int testArrayLenLENGTH = sizeof(testArrayLen) / sizeof(int);
	int realArrayLenLENGTH = sizeof(realArrayLen) / sizeof(int);
	int expectedTestResultsLENGTH = sizeof(expectedTestResults) / sizeof(int);
	int expectedArrayArrayLENGTH = sizeof(expectedArrayArray) / sizeof(expectedArrayArray[0]);

	if (testArrayArrayLENGTH != testArrayArrayLENGTH ||
		testArrayArrayLENGTH != realArrayLenLENGTH ||
		realArrayLenLENGTH != expectedTestResultsLENGTH ||
		expectedTestResultsLENGTH != expectedArrayArrayLENGTH)
	{
		puts("There is a disparity in the dimension of the parallel arrays!\nEXITING...\n");
		return 0xDEADC0DE;
	}

	/* 
	 *  TESTING SECTION
	 */
	for (i = 0; i < (sizeof(testArrayArray) / sizeof(testArrayArray[0])); i++)
	{
		putchar(10);
		printf("********\n");
		printf("TEST #%d\n", i + 1);
		printf("********\n");
		testsRun++;
		printf("\tOriginal Array:\t");
		print_array(testArrayArray[i], realArrayLen[i]);
		printf("\tActual Length:\t%d\n", realArrayLen[i]);
		printf("\tTesting Length:\t%d\n", testArrayLen[i]);
		tempReturnValue = sort_int_array(testArrayArray[i], testArrayLen[i]);
		printf("\tReturn Value:\t");
		if (tempReturnValue == expectedTestResults[i])
		{
			printf("PASS\n");
			testsPassed++;
		}
		else
		{
			printf("FAIL\n");
		}
		printf("\tOutput Array:\t");
		print_array(testArrayArray[i], realArrayLen[i]);
		printf("\tExpected Array:\t");
		print_array(expectedArrayArray[i], realArrayLen[i]);
		testsRun++;
		printf("\tSort Test:\t");
		if (TRUE == do_arrays_match(testArrayArray[i], expectedArrayArray[i], realArrayLen[i]))
		{
			printf("PASS\n");
			testsPassed++;
		}
		else
		{
			printf("FAIL\n");
		}
	}

	putchar(10);
	printf("******************\n");
	printf("%d tests were run.\n", testsRun);
	printf("%d tests passed.\n", testsPassed);
	printf("******************\n");

	printf("\nPress any key...\n");
	getchar();

	return 0;
}


/*
 * FUNCTION:   int print_array(int * arrayToPrint, int arrayLength);
 *
 * ARGUMENTS:  arrayToPrint is a pointer to an integer array
 *             arrayLength is the dimension of arrayToPrint
 *
 * RETURNS:	  0 if successful
 *             -1 if arrayToPrint is a NULL pointer
 *             -2 if arrayLength is unrealistic
 *
 * NOTES:      This function prints the values from each element, separated by a single space
 *             This function always prints one newline prior to return, regardless of the value
 */
int print_array(int * arrayToPrint, int arrayLength)
{
	int returnValue = 0;

	if (!arrayToPrint)
	{
		returnValue = -1;
	}
	else if (arrayLength < 1)
	{
		returnValue = -2;
	}
	else
	{
		int i = 0;

		for (i = 0; i < arrayLength; i++)
		{
			printf("%d ", arrayToPrint[i]);
		}
	}
	printf("\n");

	return returnValue;
}


/*
 * FUNCTION:   do_arrays_match(int * modifiedArray, int * expectedArray, int arrayLength);
 *
 * ARGUMENTS:  modifiedArray is a pointer to an integer array
 *             expectedArray is a pointer to an integer array
 *             arrayLength represents the dimension of both arrays
 *
 * RETURNS:	  TRUE (1) if the values in both arrays match
 *            FALSE (0) if the is one or more mismatched values between both arrays
 *
 * NOTES:      This function compares the values of both int arrays, element by element
 *             If one mismatch is found, this function returns FALSE (0) and stops checking
 *             This function trusts that modifiedArray and expectedArray are the same length
 */
int do_arrays_match(int * modifiedArray, int * expectedArray, int arrayLength)
{
	int i = 0;
	int arraysMatch = TRUE;

	for (i = 0; i < arrayLength; i++)
	{
		if (modifiedArray[i] != expectedArray[i])
		{
			arraysMatch = FALSE;
			break;
		}
	}

	return arraysMatch;
}
