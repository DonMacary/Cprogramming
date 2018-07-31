/*
PERFORMANCE LAB 1
Follow instructions below!
The basis of this lab is simple... allocate a section of memory that will
hold a string (your first name). Print the name out, then cleanup the memory and exit.
*/

//TODO: Include needed headers
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	//TODO: Create a string containing your first name
	char myName[7] = { "DONNIE" };
	//TODO: Get the size of this string
	int size = strlen(myName);
	//TODO: Declare a char pointer *str
	char *myNameAgain;


	//TODO: Allocate a section of memory of type char
	char *someMemorySpace = (char*)malloc(40 * sizeof(char));
	//TODO: Set the size of this allocated space to 40 bytes
	//TODO: Asign the address of this allocated space to the pointer value
	myNameAgain = someMemorySpace;

	//TODO: Copy your name into the allocated space using strcpy()
	strcpy(myNameAgain, myName);
	//TODO: Print out your name that is stored in the allocated memory space
	printf("%s\n", myNameAgain);
	//TODO: Reallocate the memory space using the size of the string rather than 40 bytes
	realloc(myNameAgain, size * sizeof(char));
	//TODO: Print out the string again
	printf("%s\n", myNameAgain);

    free(myNameAgain);
    myNameAgain = NULL;
    someMemorySpace = NULL;

	while (1);
	return 1;

}