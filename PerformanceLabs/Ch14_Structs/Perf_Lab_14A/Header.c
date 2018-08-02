#include <stdio.h>
#include <string.h>

/* Error code default value */
#ifdef DEFAULT_ERROR_CODE
#undef DEFAULT_ERROR_CODE
#endif
#define DEFAULT_ERROR_CODE 90318

/* Just in case NULL was undefined... */
#ifndef NULL
#define NULL ((void*) 0)
#endif

/* Error code for success */
#ifdef ERROR_CODE_SUCCESS
#undef ERROR_CODE_SUCCESS
#endif
#define ERROR_CODE_SUCCESS ((int)1)

/* Error code if sentence_ptr is NULL */
#ifdef ERROR_NULL_SENTENCE_POINTER
#undef ERROR_NULL_SENTENCE_POINTER
#endif
#define ERROR_NULL_SENTENCE_POINTER ((int)-1)

/* Error code if searchWord_ptr is NULL */
#ifdef ERROR_NULL_SEARCH_POINTER
#undef ERROR_NULL_SEARCH_POINTER
#endif
#define ERROR_NULL_SEARCH_POINTER ((int)-2)

/* Error code is the string in searchWord_ptr can not be found in the string located at sentence_ptr */
#ifdef ERROR_SEARCH_NOT_FOUND
#undef ERROR_SEARCH_NOT_FOUND
#endif
#define ERROR_SEARCH_NOT_FOUND ((int)-3)

/* Standard array size for manual dimension declaration */
#ifdef BUFF_SIZE
#undef BUFF_SIZE
#endif
#define BUFF_SIZE 1024
/*
* FUNCTION:   find_the_word(char * sentence_ptr, char * searchWord_ptr, int * errorCode_ptr)
*
* ARGUMENTS:  sentence_ptr is a char pointer to a null-terminated string to search
*             searchWord_ptr is a char pointer to a null-terminated string to find inside sentence_ptr
*             errorCode_ptr is an int pointer.  Store your error code at this memory address.
*
* RETURNS:	   char pointer to the first occurrence of the searchWord_ptr string found in the
*                 sentence_ptr string.  The char pointer should be a memory address in the
*                 sentence_ptr string and this memory address should represent the first 'index'
*                 of the searchWord_ptr string.  This memory address from the sentence_ptr string
*                 should dereference to a value equivalent to searchWord_ptr[0].
*             All other occurences should return NULL.  This includes, but is not limited to, the
*                 following:
*                     sentence_ptr is NULL
*                     searchWord_ptr is NULL
*                     errorCode_ptr is NULL
*                     the searchWord_ptr string is not found in the sentence_ptr string
*
* NOTES:      This function only utilizes address arithmetic to access information within the
*                 null-terminated char array found at both sentence_ptr and searchWord_ptr
*             Only access elements of the char array found at both sentence_ptr and searchWord_ptr
*                 using address arithmetic (AKA pointer math).  The definition of this function should
*                 be entirely devoid of the [ and ] characters.  (e.g., sentence_ptr[i] is forbidden)
*             The only guarantees for the arguments are:
*                 Any string found at sentence_ptr is null-terminated
*                 Any string found at searchWord_ptr is null-terminated
*             There is no guarantee sentence_ptr has an address (return NULL if it's NULL and assign the
*                 proper error code)
*             There is no guarantee searchWord_ptr has an address (return NULL if it's NULL and assign the
*                 proper error code)
*             There is no guarantee errorCode_ptr has an address (return NULL if it's NULL and assign the
*                 proper error code)
*             There is no guarantee the string found at sentence_ptr contains the string found at
*                 searchWord_ptr (return NULL if the string at searchWord_ptr is not found and assign the
*                 proper error code)
*             There is no guarantee the strings found at both sentence_ptr and searchWord_ptr will
*                 return a string length longer than zero (0)
*/


extern char * find_the_word(char * sentence_ptr, char * searchWord_ptr, int * errorCode_ptr)
{
	char testChar1 = 0; // DEBUGGING
	char testChar2 = 0; // DEBUGGING
	char * returnValue_ptr = NULL;
	int sentenceLength = 0;
	int searchWordLength = 0;
	int i = 0;
	int j = 0;

	if (!sentence_ptr)
	{
		returnValue_ptr = NULL;
		*errorCode_ptr = ERROR_NULL_SENTENCE_POINTER;
	}
	else if (!searchWord_ptr)
	{
		returnValue_ptr = NULL;
		*errorCode_ptr = ERROR_NULL_SEARCH_POINTER;
	}
	else if (!errorCode_ptr)
	{
		returnValue_ptr = NULL;
	}
	else
	{
		sentenceLength = strlen(sentence_ptr);
		searchWordLength = strlen(searchWord_ptr);
		// If it's longer... it obvs ain't found. 
		if (searchWordLength > sentenceLength)
		{
			returnValue_ptr = NULL;
			*errorCode_ptr = ERROR_SEARCH_NOT_FOUND;
		}
		else
		{
			*errorCode_ptr = ERROR_SEARCH_NOT_FOUND;
			for (i = 0; i <= (sentenceLength - searchWordLength); i++)
			{
				testChar1 = *(sentence_ptr + i);
				testChar2 = *(searchWord_ptr);
				if (*(sentence_ptr + i) == *(searchWord_ptr)) // If the first letter of the Key matches the current value...
				{
					if (searchWordLength == 1)
					{
						returnValue_ptr = (sentence_ptr + i);
						*errorCode_ptr = ERROR_CODE_SUCCESS;
						return returnValue_ptr;
					}
					else
					{
						for (j = 1; j < searchWordLength; j++) // ...check for the rest of the Key
						{
							if (*(sentence_ptr + i + j) != *(searchWord_ptr + j))
							{
								break; // No match
							}
							// Check last characters
							else if (j == (searchWordLength - 1))
							{
								returnValue_ptr = (sentence_ptr + i);
								*errorCode_ptr = ERROR_CODE_SUCCESS;
								return returnValue_ptr;
							}
						}
					}
				}
			}
		}
	}

	return returnValue_ptr;
}