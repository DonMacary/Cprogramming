/*********************************************************************
/   AUTHOR: ELF
/   COURSE: C Programming 
/   PROGRAM NAME: perfLab4B.c
/   PROGRAM DESCRIPTION: Performance Lab 4B - Basic IO pt 2
/   INSTRUCTIONS:
/        Input a single character and then print the next sequential character
/        Use getc() and putc()
/        Test it with the following input:
/            - 7
/            - H
/            - 1337
/            - abc
/            - Ctrl-D
/            - \
/            - -1
/            - <Space>
/            - ~
/            - 1234567890
/        HINT:
/
/        putchar(yourVar + 1);
/*********************************************************************/

#include <stdio.h>

int main(void)
{
    //Input a single character and then print the next sequential character
    int inputChar = 0;
    printf("Enter a single character now: ");
    inputChar = getc(stdin);
    printf("Your character is: ");
    putc(inputChar, stdout);
    printf("\nThe previous character in the sequence is: ");
    putc(inputChar -1, stdout);
    printf("\n");
}