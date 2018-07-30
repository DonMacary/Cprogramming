/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////// PERFORMANCE LAB (I.5.A) 8 /////////////////////////////////////////////
///////////////////////////////////////////////// FUNCTION POINTERS /////////////////////////////////////////////////
/////////////////////////////////////////// "Every integer is bigger in Texas" //////////////////////////////////////
///////////////////////////////////////////////// Instructor Solution ///////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Define each of the following function prototypes IAW their associated comment blocks:
//     int low_to_high_compare(int x, int y)
//     int high_to_low_compare(int x, int y)
//     int absolute_low_to_high_compare(int x, int y)
//     int absolute_high_to_low_compare(int x, int y)
// Write eight (8) tests for bubble_sort() (see: the comment block below), two tests for each of the function
//     prototypes listed above. 
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <math.h>

#ifndef TRUE
#define TRUE ((int)1)
#endif

#ifndef FALSE
#define FALSE ((int)0)
#endif

/*
* FUNCTION:   low_to_high_compare(int x, int y)
*
* ARGUMENTS:  Two sequential integers to compare
*             For the sake of ordering, x should come before y
*
* RETURNS:	   If x is greater than or equal to y, return 1
*             On error, return -1
*             Return 0 for all other conditions
*
* NOTES:      This function compares the values of x and y
*             If x is greater than or equal y, y needs to be "bubbled up" to the top
*             Large numbers are ordered first
*
* EXAMPLES:   x = 9, y = 0, return 1
*             x = 8, y = 68, return 0
*             x = -24, y = 318, return 0
*             x = -318, y = -688, return 1
*/
int low_to_high_compare(int x, int y);				// Choice 1

	/*
	* FUNCTION:   int high_to_low_compare(int x, int y)
	*
	* ARGUMENTS:  Two sequential integers to compare
	*             For the sake of ordering, x should come before y
	*
	* RETURNS:	   If x is less than or equal to y, return 1
	*             On error, return -1
	*             Return 0 for all other conditions
	*
	* NOTES:      This function compares the values of x and y
	*             If x is less than or equal y, y needs to be "bubbled up" to the top
	*             Large numbers are ordered first
	*
	* EXAMPLES:   x = 9, y = 0, return 0
	*             x = 8, y = 68, return 1
	*             x = -24, y = 318, return 1
	*             x = -318, y = -688, return 0
	*/
int high_to_low_compare(int x, int y);				// Choice 2

	/*
	* FUNCTION:   int absolute_low_to_high_compare(int x, int y)
	*
	* ARGUMENTS:  Two sequential integers to compare
	*             For the sake of ordering, x should come before y
	*
	*  RETURNS:   If the absolute value of x is greater than or equal to the absolute value of y, return 1
	*             On error, return -1
	*             Return 0 for all other conditions
	*
	* NOTES:      This function compares the values of x and y
	*             If the absolute value of x is greater than or equal the absolute value of y,
	*                 y needs to be "bubbled up" to the top
	*             This function will not attempt to modify the values of x and y
	*             Smaller numbers, regardless of 'sign', are ordered first
	*
	* EXAMPLES:   x = 9, y = 0, return 1
	*             x = 8, y = 68, return 0
	*             x = -24, y = 318, return 0
	*             x = -318, y = -688, return 0
	*/
int absolute_low_to_high_compare(int x, int y);		// Choice 3

	/*
	* FUNCTION:   absolute_high_to_low_compare(int x, int y)
	*
	* ARGUMENTS:  Two sequential integers to compare
	*             For the sake of ordering, x should come before y
	*
	* RETURNS:    If the absolute value of x is less than or equal to the absolute value of y, return 1
	*             On error, return -1
	*             Return 0 for all other conditions
	*
	* NOTES:      This function compares the values of x and y
	*             If the absolute value of x is less than or equal the absolute value of y,
	*                 y needs to be "bubbled up" to the top
	*             This function will not attempt to modify the values of x and y
	*             Large numbers, regardless of 'sign', are ordered first
	*
	* EXAMPLES:   x = 9, y = 0, return 0
	*             x = 8, y = 68, return 1
	*             x = -24, y = 318, return 1
	*             x = -318, y = -688, return 1
	*/
int absolute_high_to_low_compare(int x, int y);		// Choice 4


	/*
	* FUNCTION:   bubble_sort(int * arrayOfInts, int numOfElements, int(*compare_function)(int, int))
	*
	* ARGUMENTS:  arrayOfInts - a pointer to an array of integers
	*             numOfElements - the dimension of the integer array found at the int pointer arrayOfInts
	*             compare_function - a function pointer; This function should take two ints as parameters
	*                 and return an int.  The expectation is that compare_function performs a comparison
	*                 of the two ints and returns a boolean value.  This boolean value should represent
	*                 whether or not the two ints should be swapped.  If the return value of compare_function
	*                 is 1, then the two ints should be swapped in place.
	*
	* RETURNS:    The total number of int swaps that were made
	*             0 if no swaps were made
	*             -1 if any pointer is NULL
	*             -2 if numOfElements is unrealistic
	*             -3 on any other error
	*
	* NOTES:      This function is already defined below.  Do not modify this function.
	*             This function will sort, in place, the first "numOfElements" elements that are found
	*                 in the integer array found at pointer "arrayOfInts".  To accomplish this, bubble_sort()
	*                 will utilize the comparison function found at "compare_function" to accomplish this.
	*                 The expectation is that compare_function will compare two ints, n1 and n2.  In this, it
	*                 is expected that n1 comes before n2.  If n1 needs to swap with n2, compare_function will
	*                 return 1.  If not, compare_function will return 0.  Any other return value from
	*                 compare_function will be considered an error value (see: RETURNS).
	*/
int bubble_sort(int * arrayOfInts, int numOfElements, int(*compare_function)(int, int));

int array_size(int *sizeMe);

int print_array(int *printMe);

int main(void)
{
	int (*compareFunPtr)(int x, int y);
	int arrayTest1[6] = { 0,5,10,15,11,20 }; // tests low to high
	int arrayTest2[] = { 1, 2, 3, 5, 9,6 };  
	int arrayTest3[] = { 100, 90, 95 , 70 ,60 ,50 }; // tests high to low
	int arrayTest4[] = { 50, 40, 45 , 43, 20, 10 };
	int arrayTest5[] = { -3, 5, -4, 6, 10, 12}; // tests absolute low to high
	int arrayTest6[] = { -10, 13, -12, 14, 15, 16 };
	int arrayTest7[] = { -20, 18, -19, 17, 16, 15 }; //tests absolute high to low
	int arrayTest8[] = { -25, 24, -23, 21, -22, 20 };

	int arraySorted1[6] = { 0,5,10,11,15,20 }; // tests low to high
	int arraySorted2[] = { 1, 2, 3, 5, 6,9 };
	int arraySorted3[] = { 100, 95, 90 , 70 ,60 ,50 }; // tests high to low
	int arraySorted4[] = { 50, 45, 43 , 40, 20, 10 };
	int arraySorted5[] = { -3, -4, 5, 6, 10, 12 }; // tests absolute low to high
	int arraySorted6[] = { -10, -12, 13, 14, 15, 16 };
	int arraySorted7[] = { -20, -19, 18, 17, 16, 15 }; //tests absolute high to low
	int arraySorted8[] = { -25, 24, -23, -22, 21, 20 };

	int size;
	//I was trying to do sophisticated automated testing but I didn't have enough time to implement this...
	int arrayOfTests[] = { arrayTest1, arrayTest2, arrayTest3, arrayTest4, arrayTest5, arrayTest6, arrayTest7, arrayTest8 };
	int arrayOfTestsSorted[] = { arraySorted1, arraySorted2, arraySorted3, arraySorted4, arraySorted5, arraySorted6, arraySorted7, arraySorted8 };
	int answerArray[] = { 1, 1, 1, 2, 1, 1, 1, 1, };

	/*
	for (int i = 0; i < sizeof(arrayOfTests); i++)
	{
		printf("--------------------------\n");
		printf("Starting test #%d\n", i);
		
		int tempAnswer;
		size = sizeof(arrayOfTests[i]);
		switch (i)
		{
		case 0:
		case 1:
			compareFunPtr = &low_to_high_compare;
			break;
		case 2:
		case 3:
			compareFunPtr = &high_to_low_compare;
			break;
		case 4:
		case 5:
			compareFunPtr = &absolute_low_to_high_compare;
			break;
		case 6:
		case 7:
			compareFunPtr = &absolute_high_to_low_compare;
			break;
		default:
			printf("There was an error!\n");
			return 0;
		}
		tempAnswer = bubble_sort(arrayOfTests[i], size, compareFunPtr);
		if (tempAnswer == answerArray[i])
		{
			printf("Test%d Success!\n", i);
		}
		else
		{
			printf("Result of bubble Sort = %d", tempAnswer);
			printf("Expected result: %d", answerArray[i]);
			printf("Original Array: ");
			for (int j = 0; j < size; j++)
			{
				printf("%d", print_array(arrayOfTests[i]));
			}
			printf("\nExpected Output: ");
			for (int j = 0; j < size; j++)
			{
				printf("%d", print_array(arrayOfTests[i]));
			}
		}
	}
	*/
	//test low to high compare
	printf("Test #1\n");
	printf("-------------------------------\n");
	printf("Original Array: ");
	for (int i = 0; i < 6; i++)
	{
		printf("%d ", *(arrayTest1 + i));
	}

	compareFunPtr = &low_to_high_compare;
	int value = bubble_sort(arrayTest1, 6, compareFunPtr);
	printf("\nExpected Result: ");
	for (int i = 0; i < 6; i++)
	{
		printf("%d ", *(arraySorted1 + i));
	}
	
	printf("\nActual Result: ");
	for (int i = 0; i < 6; i++)
	{
		printf("%d ", *(arrayTest1 + i));
	}
	printf("\n-------------------------------\n");


	printf("Test #2\n");
	printf("-------------------------------\n");
	printf("Original Array: ");
	for (int i = 0; i < 6; i++)
	{
		printf("%d ", *(arrayTest2 + i));
	}

	compareFunPtr = &low_to_high_compare;
	int value2 = bubble_sort(arrayTest2, 6, compareFunPtr);
	printf("\nExpected Result: ");
	for (int i = 0; i < 6; i++)
	{
		printf("%d ", *(arraySorted2+ i));
	}

	printf("\nActual Result: ");
	for (int i = 0; i < 6; i++)
	{
		printf("%d ", *(arrayTest2 + i));
	}
	printf("\n-------------------------------\n");

	//test high to low compare
	printf("Test #3\n");
	printf("-------------------------------\n");
	printf("Original Array: ");
	for (int i = 0; i < 6; i++)
	{
		printf("%d ", *(arrayTest3 + i));
	}

	compareFunPtr = &high_to_low_compare;
	int value3 = bubble_sort(arrayTest3, 6, compareFunPtr);
	printf("\nExpected Result: ");
	for (int i = 0; i < 6; i++)
	{
		printf("%d ", *(arraySorted3 + i));
	}

	printf("\nActual Result: ");
	for (int i = 0; i < 6; i++)
	{
		printf("%d ", *(arrayTest3 + i));
	}
	printf("\n-------------------------------\n");


	printf("Test #4\n");
	printf("-------------------------------\n");
	printf("Original Array: ");
	for (int i = 0; i < 6; i++)
	{
		printf("%d ", *(arrayTest4 + i));
	}

	compareFunPtr = &high_to_low_compare;
	int value4 = bubble_sort(arrayTest4, 6, compareFunPtr);
	printf("\nExpected Result: ");
	for (int i = 0; i < 6; i++)
	{
		printf("%d ", *(arraySorted4 + i));
	}

	printf("\nActual Result: ");
	for (int i = 0; i < 6; i++)
	{
		printf("%d ", *(arrayTest4 + i));
	}
	printf("\n-------------------------------\n");


	// test absolute low to high comapre
	printf("Test #5\n");
	printf("-------------------------------\n");
	printf("Original Array: ");
	for (int i = 0; i < 6; i++)
	{
		printf("%d ", *(arrayTest5 + i));
	}

	compareFunPtr = &absolute_low_to_high_compare;
	int value5 = bubble_sort(arrayTest5, 6, compareFunPtr);
	printf("\nExpected Result: ");
	for (int i = 0; i < 6; i++)
	{
		printf("%d ", *(arraySorted5 + i));
	}

	printf("\nActual Result: ");
	for (int i = 0; i < 6; i++)
	{
		printf("%d ", *(arrayTest5 + i));
	}
	printf("\n-------------------------------\n");


	printf("Test #6\n");
	printf("-------------------------------\n");
	printf("Original Array: ");
	for (int i = 0; i < 6; i++)
	{
		printf("%d ", *(arrayTest6 + i));
	}

	compareFunPtr = &absolute_low_to_high_compare;
	int value6 = bubble_sort(arrayTest6, 6, compareFunPtr);
	printf("\nExpected Result: ");
	for (int i = 0; i < 6; i++)
	{
		printf("%d ", *(arraySorted6 + i));
	}

	printf("\nActual Result: ");
	for (int i = 0; i < 6; i++)
	{
		printf("%d ", *(arrayTest6 + i));
	}
	printf("\n-------------------------------\n");


	//test absolute high to low compate
	printf("Test #7\n");
	printf("-------------------------------\n");
	printf("Original Array: ");
	for (int i = 0; i < 6; i++)
	{
		printf("%d ", *(arrayTest7 + i));
	}

	compareFunPtr = &absolute_high_to_low_compare;
	int value7 = bubble_sort(arrayTest7, 6, compareFunPtr);
	printf("\nExpected Result: ");
	for (int i = 0; i < 6; i++)
	{
		printf("%d ", *(arraySorted7 + i));
	}

	printf("\nActual Result: ");
	for (int i = 0; i < 6; i++)
	{
		printf("%d ", *(arrayTest7 + i));
	}
	printf("\n-------------------------------\n");


	printf("Test #8\n");
	printf("-------------------------------\n");
	printf("Original Array: ");
	for (int i = 0; i < 6; i++)
	{
		printf("%d ", *(arrayTest8 + i));
	}

	compareFunPtr = &absolute_high_to_low_compare;
	int value8 = bubble_sort(arrayTest8, 6, compareFunPtr);
	printf("\nExpected Result: ");
	for (int i = 0; i < 6; i++)
	{
		printf("%d ", *(arraySorted8 + i));
	}

	printf("\nActual Result: ");
	for (int i = 0; i < 6; i++)
	{
		printf("%d ", *(arrayTest8 + i));
	}
	printf("\n-------------------------------\n");


	while (1);
	return 0;
}

/*
* FUNCTION:   low_to_high_compare(int x, int y)
*
* ARGUMENTS:  Two sequential integers to compare
*             For the sake of ordering, x should come before y
*
* RETURNS:	   If x is greater than or equal to y, return 1
*             On error, return -1
*             Return 0 for all other conditions
*
* NOTES:      This function compares the values of x and y
*             If x is greater than or equal y, y needs to be "bubbled up" to the top
*             Large numbers are ordered first
*
* EXAMPLES:   x = 9, y = 0, return 1
*             x = 8, y = 68, return 0
*             x = -24, y = 318, return 0
*             x = -318, y = -688, return 1
*/
int low_to_high_compare(int x, int y)
{
	if (!x || !y)
	{
		return -1;
	}

	if(x >= y)
	{
		return 1;
	}
	else
	{
		return 0;
	}

}

/*
* FUNCTION:   int high_to_low_compare(int x, int y)
*
* ARGUMENTS:  Two sequential integers to compare
*             For the sake of ordering, x should come before y
*
* RETURNS:	   If x is less than or equal to y, return 1
*             On error, return -1
*             Return 0 for all other conditions
*
* NOTES:      This function compares the values of x and y
*             If x is less than or equal y, y needs to be "bubbled up" to the top
*             Large numbers are ordered first
*
* EXAMPLES:   x = 9, y = 0, return 0
*             x = 8, y = 68, return 1
*             x = -24, y = 318, return 1
*             x = -318, y = -688, return 0
*/
int high_to_low_compare(int x, int y)
{

	if (!x || !y)
	{
		return -1;
	}

	if (x <= y)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/*
* FUNCTION:   int absolute_low_to_high_compare(int x, int y)
*
* ARGUMENTS:  Two sequential integers to compare
*             For the sake of ordering, x should come before y
*
*  RETURNS:   If the absolute value of x is greater than or equal to the absolute value of y, return 1
*             On error, return -1
*             Return 0 for all other conditions
*
* NOTES:      This function compares the values of x and y
*             If the absolute value of x is greater than or equal the absolute value of y,
*                 y needs to be "bubbled up" to the top
*             This function will not attempt to modify the values of x and y
*             Smaller numbers, regardless of 'sign', are ordered first
*
* EXAMPLES:   x = 9, y = 0, return 1
*             x = 8, y = 68, return 0
*             x = -24, y = 318, return 0
*             x = -318, y = -688, return 0
*/
int absolute_low_to_high_compare(int x, int y)
{
	if (!x || !y)
	{
		return -1;
	}
	if (abs(x) >= abs(y))
	{
		return 1;
	}
	else
	{
		return 0;
	}

}

/*
* FUNCTION:   absolute_high_to_low_compare(int x, int y)
*
* ARGUMENTS:  Two sequential integers to compare
*             For the sake of ordering, x should come before y
*
* RETURNS:    If the absolute value of x is less than or equal to the absolute value of y, return 1
*             On error, return -1
*             Return 0 for all other conditions
*
* NOTES:      This function compares the values of x and y
*             If the absolute value of x is less than or equal the absolute value of y,
*                 y needs to be "bubbled up" to the top
*             This function will not attempt to modify the values of x and y
*             Large numbers, regardless of 'sign', are ordered first
*
* EXAMPLES:   x = 9, y = 0, return 0
*             x = 8, y = 68, return 1
*             x = -24, y = 318, return 1
*             x = -318, y = -688, return 1
*/
int absolute_high_to_low_compare(int x, int y)
{
	if (!x || !y)
	{
		return -1;
	}
	if (abs(x) <= abs(y))
	{
		return 1;
	}
	else
	{
		return 0;
	}

}

/*
* FUNCTION:   bubble_sort(int * arrayOfInts, int numOfElements, int(*compare_function)(int, int))
*
* ARGUMENTS:  arrayOfInts - a pointer to an array of integers
*             numOfElements - the dimension of the integer array found at the int pointer arrayOfInts
*              compare_function - a function pointer; This function should take two ints as parameters
*                 and return an int.  The expectation is that compare_function performs a comparison
*                 of the two ints and returns a boolean value.  This boolean value should represent
*                 whether or not the two ints should be swapped.  If the return value of compare_function
*                 is 1, then the two ints should be swapped in place.
*
* RETURNS:    The total number of int swaps that were made
*             0 if no swaps were made
*             -1 if any pointer is NULL
*             -2 if numOfElements is unrealistic
*             -3 on any other error
*
* NOTES:      This function is already defined below.  Do not modify this function.
*             This function will sort, in place, the first "numOfElements" elements that are found
*                 in the integer array found at pointer "arrayOfInts".  To accomplish this, bubble_sort()
*                 will utilize the comparison function found at "compare_function" to accomplish this.
*                 The expectation is that compare_function will compare two ints, n1 and n2.  In this, it
*                 is expected that n1 comes before n2.  If n1 needs to swap with n2, compare_function will
*                 return 1.  If not, compare_function will return 0.  Any other return value from
*                 compare_function will be considered an error value (see: RETURNS).
*/
int bubble_sort(int * arrayOfInts, int numOfElements, int(*compare_function)(int, int))
{
	int returnValue = -3;	// Default return value in case something dies
	int i = 0;				// Iterating variable
	int j = 0;				// Iterating variable
	int swapCount = 0;		// Number of element swaps that have been made

	if (!arrayOfInts || !compare_function)	// If either of the pointers are NULL...
	{
		returnValue = -1;	// ...return -1
	}
	else if (numOfElements < 2) // If the number of elements is unrealistic...
	{
		returnValue = -2; // ...return -2
	}
	else
	{
		for (i = 0; i < numOfElements; i++) // Iterate through all of the elements...
		{
			for (j = 0; j < (numOfElements - 1); j++) // ...comparing each element to all the other elements
			{
				if ((compare_function(*(arrayOfInts + j), *(arrayOfInts + j + 1))) > 0) // If the compare function suggests a swap...
				{
					/* ...swap the values stored in each element */
					*(arrayOfInts + j) = *(arrayOfInts + j) ^ *(arrayOfInts + j + 1);
					*(arrayOfInts + j + 1) = *(arrayOfInts + j) ^ *(arrayOfInts + j + 1);
					*(arrayOfInts + j) = *(arrayOfInts + j) ^ *(arrayOfInts + j + 1);
					swapCount++; // A swap took place so increment the number of swaps counted
				}
			}
		}
		returnValue = swapCount; // Return the total number of swaps that took place
	}

	return returnValue;
}

int array_size(int *sizeMe)
{
	int i = 0;
	while (!sizeMe[i])
	{
		i++;
	}
	return i;
}

int print_array(int *printMe)
{
	int i = 0;
	while (!printMe)
	{
		printf("%d", printMe[i]);
	}
}