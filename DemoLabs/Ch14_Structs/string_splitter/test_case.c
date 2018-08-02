#include "string_split.h"

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