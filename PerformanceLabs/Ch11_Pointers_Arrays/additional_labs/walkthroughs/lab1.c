/*
-additional_labs/walkthroughs/lab1.c
-The purpose of this walkthrough is to give you a step by step understanding of
pointers.
*/
// TODO: Include any headers needed
#include <stdio.h>
#include <string.h>

int main(void)
{
	// TODO: Create a int variable and set it to some positive number
	int integerVar = 20;

	// TODO: Create a string variable and set it to your first name
	char firstName[] = "William";

	// TODO: Create a int array with a few random ints
	int intArray[5] = { 4,5,2,6,7 };

	// TODO: Create an int pointer and a string pointer and point them to\
	    the int/string we created above. Also create a pointer for the intArray

// NOTE: Notice we point the int pointer to the address of integerVar by using\
    the & (and symbol). This is not needed when pointing to the firstName\
    because the firstName variable is already pointing to the first address in it's array
	int *integer_ptr = &integerVar;
	char *firstName_ptr = firstName;
	int *intArray_ptr = intArray;


	// TODO: Print out the value of integerVar... using only the pointer *integer_ptr to access it
	// NOTE: * (astriks) allows us to dereference a pointer. Remember, a pointer's value is an address to\
	    another variable's memory address. Dereferencing simply means to see what data that memory address is holding.
	printf("integerVar is: %d\n", *integer_ptr);

	// TODO: Print out the memory address of integerVar... using only the pointer *integer_ptr to access it
	// NOTE: %p is great for printing out pointers and really any address. Pass in the pointer as is\
	    in other words... no & or * before it. This means to access the value of integer_ptr... which is just a\
    memory address to another variable. In this case, integerVar's memory address
	printf("integerVar's memory address is: %p\n", integer_ptr);

	// TODO: Print out the memory address of the integer_ptr
	// NOTE: To access the memory address of integer_ptr... you just use the & symbol... which grabs the address
	printf("integer_ptr's memory address is: %p\n", &integer_ptr);

	// TODO: Multiply the value of integerVar by 2 (integerVar * 2)... using only the pointer to it.\
	     Print out the result.
// NOTE: Notice we actually changed integerVar by using the pointer to it's address. \
    That's because we are accessing that variable DIRECTLY through it's OWN ADDRESS
	*integer_ptr = *integer_ptr * 2;
	printf("integerVar now equals %d. integer_ptr dereferenced equals %d\n", integerVar, *integer_ptr);

	// TODO: Print out your firstName var using only the pointer to it
	printf("firstName is: %s\n", firstName_ptr);
	/*NOTE: "What in the world?"... I'm sure you said. You are probaly wondering why...
	...I was able to use just firstName_ptr even though I said that points to a memory address of another variable.
	Right? RIGHT?
	Yes... you are right. It points to the memory address... just as firstName itself ALSO pointers to a memory address
	What? Why? How?
	-The %s specifier in printf() actually requires a pointer to an array of chars. Remember... a normal variable
	points to a value like 10, 55.20 or 'a'. But an array variable name pointers to the first address of the array
	... the FIRST ELEMENT in the array. This is true for all arrays. But how come we can only print out all the
	letters of a string in a char array... but not all the ints in a int array? Well, that's where the
	nul-terminator comes in. \0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0
	The nul-terminator \0\0\0\0\0\0 tells us that's the end of the string. So when we use %s inside of printf...
	printf will keep spitting out characters until it sees that \0. BOOM.
	*/
	int i = 0;
	// TODO: Print out each character in intArray using only it's pointer
	for (i = 0; i < 5; i++)
	{
		printf("%d\n", *(intArray_ptr + i));
	}

	/* NOTE
	Well... how did this work? Let's take a look inside of the () first... the intArray_ptr + i part
	First off, obviously we are using a for loop to itterate through each element in the array.
	That's why we started at 0 (i=0) to access the first element. And that's why we counted up until < 5
	(aka 4... 0,1,2,3,4... each index in the array). With that out of the way... let's look back inside the ()

	Currently, intArray_ptr is looking at the FIRST element's address in intArray. Remember, intArray is
	technically doing the same thing. So... as long as we don't dereference* or access intArray_ptr's address
	itself... we can look directly at the address of intArray and move it left or right by using simple addition
	and subtraction! So... (firstName_ptr + 1) simply means to start at firstName[0] and move over one address
	... in other words... fisrtName[1]. Yeah. Moving outside of the () we have an * before it.

	So let's break it down.
	firstName_ptr == firstName
	*(firstName_ptr) == firstName[0]
	*(firstName_ptr + 1) == firstName[1]
	etc etc
	This is because we are moving address over first within the () then dereferencing that address!
	In other words, moving over an element then grabbing that value.
	*/
	// NOTE: We can do the same thing with the firstName
	for (int x = 0; x < strlen(firstName_ptr); x++)
	{
		printf("%c\n", *(firstName_ptr + x));
	}
	printf("\n\n");


	// TODO: Multiply each number in the intArray by itself, using only it's pointer. Print out the new values.
    // NOTE: Use the same principles as above. We can reasign these values once we access them correctly.\
    Notice the printf points directly to the inArray rather than it's pointer. Thus we actually modified\
    The value.
    
	for (i = 0; i < 5; i++)
	{
		*(intArray_ptr + i) = *(intArray_ptr + i) * (*(intArray_ptr + i));
	}

	for (i = 0; i < 5; i++)
	{
		printf("%d\n", intArray[i]);
	}

	getchar();
	getchar();

	return 0;

}
