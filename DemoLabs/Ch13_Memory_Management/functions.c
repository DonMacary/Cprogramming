/*
/demonstration_labs/functions.c
The purpose of this demo lab is to show off some functions that work on memory
DEFINITIONS: (You should always have the documentation up for functions you do not know/or remember how they work)
-strcpy(<char * destination>, <const char * source>)
    -Copies the C string pointed by <source> into the array pointed by <destination>, including the terminating null character
-strcmp(<const char * str1>, <const char * str2>)
    -This function starts comparing the first character of each string.
    If they are equal to each other, it continues with the following
    pairs until the characters differ or until a terminating null-character is reached.
-malloc(<size_t size>)
    -Allocates a block of <size> bytes of memory, returning a pointer to the beginning of the block.
-memmove( <void * destination>, <const void * source>, <size_t num> )
    -Copies the values of <num> bytes from the location pointed by <source> to the memory block pointed by <destination>.
    Copying takes place as if an intermediate buffer were used, allowing the destination and source to overlap.
-memcpy( <void * destination>, <const void * source>, <size_t num> )
    -Copies the values of <num> bytes from the location pointed
    to by <source> directly to the memory block pointed to by <destination>.
-strstr(const char * str1, const char * str2)
    -Returns a pointer to the first occurrence of str2 in str1, or a null pointer if str2 is not part of str1.
*/

// TODO: Include needed headers
#include <stdio.h>  // For things such as printf
#include <string.h> // For things such as strcpy, memmove, etc
#include <stdlib.h> // For things such as malloc

int main(void)
{

    char string[] = "Hello World";
    char substring[] = "World";
    char substring2[] = "Wo";

    // ============== malloc() ===============
    printf("\n\n========= malloc() =========\n");
    // TODO: Create a buffer large enough to fit the string length +1 of string using malloc()
    // NOTE: strlen only gives us the string length. The +1 is for the nul-terminator
    char *buffer = malloc(strlen(string) + 1);

    // TODO: Check that buffer was created, if not return 1
    if (!buffer)
    {
        return 1;
    }

    // ============== strcpy() ===============
    printf("\n\n========= strcpy() =========\n");
    // TODO: Using strcpy(), copy the string into the buffer
    strcpy(buffer, string);

    printf("Buffer is now: %s\n\n", buffer);
    printf("String is still: %s\n", string);

    // ============== strcmp() ===============
    printf("\n\n========= strcmp() =========\n");
    // TODO: Compare string to buffer. Print out match or not match depending on return
    if (strcmp(string, buffer) == 0)
    {
        printf("Match!\n");
    }
    else
    {
        printf("Not a match!\n");
    }

    // ============== memcpy() ===============
    printf("\n\n========= memcpy() =========\n");
    // TODO: Create a char buffer on the stack of size 50 and zeroize
    char stackBuffer[50] = {0};

    printf("String in buffer before memcpy: %s\n", stackBuffer);
    // TODO: Using memcpy, copy the string from string into the new buffer
    memcpy(stackBuffer, string, strlen(string) + 1);

    printf("String is: %s\n", string);
    printf("String in buffer after memcpy: %s\n",stackBuffer);


    // ============== memmove() ===============
    printf("\n\n========= memmove() =========\n");

    // TODO: Create another buffer on the stack size 50 and zeroize
    char stackBuffer2[50] = {0};

    printf("String in buffer before memmove: %s\n", stackBuffer2);
    // TODO: Using memove, move the original string into the new buffer
    memmove(stackBuffer2, string, strlen(string) + 1);
    printf("String is: %s\n", string);
    printf("String in buffer after memcpy: %s\n",stackBuffer2);



    // NOTE
    /*
    Weird eh? It looks like memcpy and memmove do the same thing. Well... they do. But they don't.
    memcpy() cannot handle overlapping memory. memmove on the other hand can. SO while the example above has no issue...
    the upcoming example MAY have issues with memcpy
    */

    memmove(&string[5], &string[6], 6);
    printf("%s\n", string);

    // NOTE: Do you see what we did there? Our destination and source were the same. We started at \
    the address of the 6th element in string 'W' and overwrote the same memory we were just copying from \
    aka removing " World" and effectivly replacing it with "World"... in other words removing the space between \
    the two words.

    // ============== strstr() ===============
    printf("\n\n========= strstr() =========\n");
    // TODO: Let's grab a substring from the String

    // TODO: Using strstr, find the substring variable within the string...\
    assign this new pointer position to a char pointer called mark_position
    char *mark_position = strstr(string, substring);
    printf("%s", mark_position);


    // TODO: Free your heap buffers
    free(buffer);


    getchar();
    getchar();
    return 0;
}