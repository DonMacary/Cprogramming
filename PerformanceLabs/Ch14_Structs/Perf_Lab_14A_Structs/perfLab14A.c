/*********************************************************************
/   AUTHOR: ELF
/   COURSE: C Programming
/   PROGRAM NAME: perfLab14A.c
/   PROGRAM DESCRIPTION: Performance Lab 14A - Structs
/   INSTRUCTIONS:

# PERFORMANCE LAB: SURFIN BIRD TEST STRUCT

Struct

“Surfin’ Bird Test Struct”

**Define a struct to test find_the_word() from Performance Lab I.5.a-4**

```c
char * find_the_word(char * sentence_ptr, char * searchWord_ptr, int * errorCode_ptr);
```

* **Your struct should include:**
* Input string (sentence_ptr)
* Input search word (searchWord_ptr)
* Expected return value (char *)
* Expected error code (*(errorCode_ptr))
* Only Address Arithmetic is permitted
* Print the human-readable results

* **Test input should include, at a minimum, the following situations:**
* Normal input
* sentence_ptr is NULL
* searchWord_ptr is NULL
* errorCode_ptr is NULL
* Two occurrences of searchWord
* No occurrences of searchWord
/*********************************************************************/

#include "Header.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i = 0;
	int numTestsRun = 0;
	int numTestsPassed = 0;
	int putErrorCodeHere = DEFAULT_ERROR_CODE;
	char * tempReturnValue_ptr = NULL;
	char testChar1 = 0; // DEBUGGING
	char testChar2 = 0; // DEBUGGING

						/* TEST INPUT */
						// Three normal strings
	char testInput0[] = { "Good luck to you on this lab.\nI hope you do well." };
	struct FunctionTest testInputStruct0 = { testInput0, "\n", (testInput0 +29),  &putErrorCodeHere, ERROR_CODE_SUCCESS };

	char testInput1[] = { "Normal test input.  'The' is the search key." };
	struct FunctionTest testInputStruct1 = { testInput1, "The", (testInput1 +21), &putErrorCodeHere, ERROR_CODE_SUCCESS };

	char testInput2[] = { "This is also normal input.  The 'bird' is the word." };
	struct FunctionTest testInputStruct2 = { testInput2, "bird", (testInput2 + 33), &putErrorCodeHere, ERROR_CODE_SUCCESS };

	// Two strings that have duplicate keys
	char testInput3[] = { "This string is an example of a string that has two occurrences of the word 'is'." }; // Key: is
	struct FunctionTest testInputStruct3 = { testInput3, "is", (testInput3 + 2), &putErrorCodeHere, ERROR_CODE_SUCCESS };

	char testInput4[] = { "The word 'the' is very common in the English language." }; // Key: the
	struct FunctionTest testInputStruct4 = { testInput4, "the", (testInput4 + 10), &putErrorCodeHere, ERROR_CODE_SUCCESS };

	// Two strings that have multiple occurrences of the key
	char testInput5[] = { "Many English words are 'loan words', which is defined as 'a word that has been adopted from one language into another'." }; // Key: word
	struct FunctionTest testInputStruct5 = { &testInput5, "word", (testInput5 + 13), &putErrorCodeHere, ERROR_CODE_SUCCESS };

	char testInput6[] = { "The search keys don't have to be letters!  They could be any character or array of characters!  They could even be puntuation!  Maybe even non-printable characters!  Crazy, right?" }; // Key: "!  "
	struct FunctionTest testInputStruct6 = { testInput6, "! ", (testInput6 + 40), &putErrorCodeHere, ERROR_CODE_SUCCESS };

	// Two NULL strings to pass as sentence_ptr
	char * testInput7 = NULL; // Key: "Doesn't matter"
	struct FunctionTest testInputStruct7 = { testInput7, "Doesn't Matter", testInput7, &putErrorCodeHere, ERROR_NULL_SENTENCE_POINTER };

	char * testInput8 = NULL; // Key: "Don't bother"
	struct FunctionTest testInputStruct8 = { testInput8, "Don't bother", testInput8, &putErrorCodeHere, ERROR_NULL_SENTENCE_POINTER };

	// Two real strings to pass alongside a NULL searchWord
	char testInput9[] = { "It's a shame to waste a perfectly good sentence." }; // Key:  NULL
	struct FunctionTest testInputStruct9 = { testInput9, NULL, NULL, &putErrorCodeHere, ERROR_NULL_SEARCH_POINTER };

	char testInput10[] = { "It's a shame to waste a perfectly good null-terminated string." }; // Key:  NULL
	struct FunctionTest testInputStruct10 = { testInput10, NULL, NULL, &putErrorCodeHere, ERROR_NULL_SEARCH_POINTER };

	// Two real strings to pass alongside a NULL errorCode
	char testInput11[] = { "At least electrons are free." }; // Key: are
	struct FunctionTest testInputStruct11 = { testInput11, "are", NULL, NULL, DEFAULT_ERROR_CODE };

	char testInput12[] = { "Even if they're not free, there is are a plethora of electrons freely available." }; // Key: e
	struct FunctionTest testInputStruct12 = { testInput12, "e", NULL, NULL, DEFAULT_ERROR_CODE };

	// Two strings that will pass more NULL search keys
	char testInput13[] = { "You can't find a key here!" }; // Key: NULL
	struct FunctionTest testInputStruct13 = { testInput13, NULL, NULL, &putErrorCodeHere, ERROR_NULL_SEARCH_POINTER };

	char testInput14[] = { "Take a picture!  It'll last longer." }; // Key: NULL
	struct FunctionTest testInputStruct14 = { testInput14, NULL, NULL, &putErrorCodeHere, ERROR_NULL_SEARCH_POINTER };

	// Two strings to pass long keys
	char testInput15[] = { "Now is the time for all good men to come to the aid of their country." }; // Key: "come to the aid"
	struct FunctionTest testInputStruct15 = { testInput15, "come to the aid", (testInput15 + 36), &putErrorCodeHere, ERROR_CODE_SUCCESS };

	char testInput16[] = { "Sometimes it's hard to play the game the way it was intended to be played instead of following the game's rules as written." }; // Key: "play the game"
	struct FunctionTest testInputStruct16 = { testInput16, "play the game", (testInput16 + 23), &putErrorCodeHere, ERROR_CODE_SUCCESS };

	// Edge cases that may break find_the_word()
	char testInput17[] = { "I hope you didn't find anything here!" }; // Key: '\0' (0x0)
	struct FunctionTest testInputStruct17 = { testInput17, "\0", NULL, &putErrorCodeHere, ERROR_SEARCH_NOT_FOUND };

	char testInput18[BUFF_SIZE] = { 0 }; // Key: "Don't do it!"
	struct FunctionTest testInputStruct18 = { testInput18, "Don't do it!", NULL, &putErrorCodeHere, ERROR_SEARCH_NOT_FOUND };

	char testInput19[] = { "Not a long string" }; // Key: "long string as a search key"
	struct FunctionTest testInputStruct19 = { testInput19, "long string as a search key", NULL, &putErrorCodeHere, ERROR_SEARCH_NOT_FOUND };

	char testInput20[] = { "part" }; // Key: "partial"
	struct FunctionTest testInputStruct20 = { testInput20, "partial", NULL, &putErrorCodeHere, ERROR_SEARCH_NOT_FOUND };

	char testInput21[BUFF_SIZE] = { 0 }; // Key: '\0' (0x0)
	struct FunctionTest testInputStruct21 = { testInput21, "\0", NULL, &putErrorCodeHere, ERROR_SEARCH_NOT_FOUND };

	// Two strings whose keys are non printable characters
	char testInput22[] = { 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0x9, 0xA, 0xB, 0xC, 0xD, 0xE, 0xF, 0x0 }; // Key: 0x8
	char expRet[] = { 0x8, 0x0 };
	struct FunctionTest testInputStruct22 = { testInput22, expRet, (testInput22 + 7), &putErrorCodeHere, ERROR_CODE_SUCCESS };

	char expRet1[] = { 0x1C, 0x0 };
	char testInput23[] = { 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F, 0x1E, 0x1D, 0x1C, 0x1B, 0x1A, 0x0 }; // Key: 0x1C
	struct FunctionTest testInputStruct23 = { testInput23, expRet1, (testInput23 + 2), &putErrorCodeHere, ERROR_CODE_SUCCESS };

	// Two strings that include characters from the extended ASCII codes
	char expRet2[] = { 0xC4, 0x0 };
	char testInput24[] = { '\n', 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, '\n', 0x7C, '$', '(', '5', ')', '$', 0x7C, '\n', 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, '\n', 0x0 }; // Key: 0xC4
	struct FunctionTest testInputStruct24 = { testInput24, expRet2, (testInput24 + 17), &putErrorCodeHere, ERROR_CODE_SUCCESS };

	//	puts(testInput24); // DEBUGGING
	char expRet3[] = { 0x2F, 0x0 };
	char testInput25[] = { 0xC4, 0x5C, 0x5F, 0x2, 0x5F, 0x2F, 0xC4, 0x0 }; // Key: 0x2F
	struct FunctionTest testInputStruct25 = { testInput25, expRet3, (testInput25 + 5), &putErrorCodeHere, ERROR_CODE_SUCCESS };

	//	puts(testInput25); // DEBUGGING
	char testInput26[] = { "Sometimes keys are at the beggining of a string." }; // Key: "Sometime"
	struct FunctionTest testInputStruct26 = { testInput26, "Sometime", (testInput26 + 0), &putErrorCodeHere, ERROR_CODE_SUCCESS };

	char testInput27[] = { "When you lose an item, you always find it in the last place you look." }; // Key: "look."
	struct FunctionTest testInputStruct27 = { testInput27, "look.", (testInput27 + 64), &putErrorCodeHere, ERROR_CODE_SUCCESS };

	struct FunctionTest testInputArray[] = { \
		testInputStruct0, testInputStruct1, testInputStruct2, \
		testInputStruct3, testInputStruct4, testInputStruct5, \
		testInputStruct6, testInputStruct7, testInputStruct8, \
		testInputStruct9, testInputStruct10, testInputStruct11, \
		testInputStruct12, testInputStruct13, testInputStruct14, \
		testInputStruct15, testInputStruct16, testInputStruct17, \
		testInputStruct18, testInputStruct19, testInputStruct20, \
		testInputStruct21, testInputStruct22, testInputStruct23, \
		testInputStruct24, testInputStruct25, testInputStruct26, \
		testInputStruct27 };



	/* CALCULATE THE NUMBER OF TESTS */
	int numTotalTests = sizeof(testInputArray) / sizeof(testInputArray[0]);
	//printf("The length of the test array is: %d \n", sizeof(testInputArray) / sizeof(testInputArray[0])); // DEBUGGING

																										  /* EXECUTE THE TESTS */
	for (i = 0; i < numTotalTests; i++)
	{
		/* 0. TEST HEADER */
		printf("\n");
		printf("************\n");
		printf("* TEST #%02d *\n", i);
		printf("************\n");
		tempReturnValue_ptr = find_the_word((testInputArray + i)->sentence_ptr, (testInputArray + i)->searchWord_Ptr, (testInputArray + i)->errorCode_ptr);

		/* 1. TEST RETURN VALUE */
		numTestsRun++;
		printf("\tReturn Value Test:\t");
		if (tempReturnValue_ptr == ((testInputArray + i)->expectedReturn))
		{
			puts("Pass");
			numTestsPassed++;
		}
		else
		{
			puts("FAIL!");
			printf("\t\tExpected pointer:\t%p\n", (testInputArray + i)->expectedReturn);
			printf("\t\tReceived pointer:\t%d\n", tempReturnValue_ptr);
		}

		/* 2. TEST ERROR CODE */
		numTestsRun++;
		printf("\tError Code Test:\t");
		if (putErrorCodeHere == (testInputArray + i)->errorCodeReturnValue)
		{
			puts("Pass");
			numTestsPassed++;
		}
		else
		{
			puts("FAIL!");
			printf("\t\tExpected error code:\t%d\n", (testInputArray + i)->errorCodeReturnValue);
			printf("\t\tReceived error code:\t%d\n", putErrorCodeHere);
			if (putErrorCodeHere == DEFAULT_ERROR_CODE)
			{
				puts("\t\tError code not even updated!");
			}
		}

		putErrorCodeHere = DEFAULT_ERROR_CODE; // Reset error code
	}

	if (numTestsRun)
	{
		printf("\n\n\n*******************************\n");
		printf("Out of the %d tests that ran...\n", numTestsRun);
		printf("%d tests passed.\n", numTestsPassed);
		printf("*******************************\n");
	}
	while (1);
	return 0;
}

