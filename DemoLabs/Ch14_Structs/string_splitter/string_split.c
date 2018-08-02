#include "string_split.h"

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
extern char * split_the_string(char * string_ptr, char delimiter)
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
