/*********************************************************************
/   AUTHOR: ELF
/   COURSE: C Programming 
/   PROGRAM NAME: perfLab4A.c
/   PROGRAM DESCRIPTION: Performance Lab 4A - Basic IO pt 1
/   INSTRUCTIONS:
/        Input a single character and then print the next sequential character
/        Use getchar() and putchar()
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
    printf("Type a single character now: ");
    inputChar = getchar();
    printf("Your character is: ");
    putchar(inputChar);
    printf("\nThe next sequential character is: ");
    putchar(inputChar + 1);
    printf("\n");


}
