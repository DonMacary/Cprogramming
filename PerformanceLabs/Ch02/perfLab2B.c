/*********************************************************************
/   AUTHOR: ELF
/   COURSE: C Programming 
/   PROGRAM NAME: perfLab2B.c
/   PROGRAM DESCRIPTION: Performance Lab 2B - Type Casting
/   Instructions:
/       Declare and initialize variables of data types:
/            int
/            float
/            double
/            char
/       Type cast and print the following:
/           int -> float
/           int -> char
/           float -> double
/           double -> float
/           char -> int
/           33 -> char
/       Note: Initialize int to a value between 32 and 126
*********************************************************************/

#include <stdio.h>

int main(void)
{
    int integer = 116;
    float singlePre = 3.13;
    double doublePre = 5.2334236233;
    char letter = 'D';

    printf("My integer %d casted to a float is: %f \n", integer, (float) integer);
    printf("My integer %d casted to a char is: %c \n", integer, (char) integer);
    printf("My float %f casted to a double is: %.15f \n", singlePre, (double) singlePre);
    printf("My double %.15g casted to a float is: %f \n", doublePre, (float) doublePre);
    printf("My character %c casted to an int is %d \n", letter, (int) letter);
    printf("The number 33 casted to a character is: %c \n", (char) 33);

}