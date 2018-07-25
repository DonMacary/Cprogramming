/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////// DEMONSTRATION LAB I.5.A-1 ////////////////////////////////////////////
////////////////////////////////////////////////// MEMORY OPERATORS /////////////////////////////////////////////////
///////////////////////////////////////////////// "Title Not Found" /////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Declare two variables, named var1 and var2, of the same data type
// Declare a pointer variable, named var_ptr, of the same data type
// Define the first variable with an arbitrary value
// Assign var1's memory address to var_ptr
// Define var2 by dereferencing var_ptr
// Compare var1 to var2 and print human-readable results
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>

int main(void)
{
	/* Declare two variables, named var1 and var2, of the same data type */
	long long var1, var2;					// The author chose a data type that wasn't 4 bytes
	/* Declare a pointer variable, named var_ptr, of the same data type */
	long long * var_ptr;					// This variable holds the memory address of a long long
//	printf("var1 is at %p\n", &var1);		// DEBUGGING; This is one way to see the memory address of a variable

	/* Define the first variable with an arbitrary value */
	var1 = 0x4ABADABBAD000000;				// The author chose a human-readable value that would fill the variable

//	printf("%d\n", sizeof(var1));			// DEBUGGING; Needed to verify the size of a long long on this sytem

	/* Assign var1's memory address to var_ptr */
	var_ptr = &var1;
	/* Define var2 by dereferencing var_ptr */
	var2 = *var_ptr;

	/* Compare var1 to var2 and print human-readable results */
	printf("\nComparing the two vars:\t");
	if (var1 == var2)						// If var1 is equal to var2 then...
	{
		printf("Equal\n");					// Good
	}
	else									// ...otherwise...
	{
		printf("NOT EQUAL\n");				// BAD
		printf("var1 == %d\nvar2 == %d\n", var1, var2);
	}

	getchar(); getchar();
	return 0;
}
