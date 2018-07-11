/*********************************************************************
/   AUTHOR: ELF
/   COURSE: C Programming 
/   PROGRAM NAME: perfLab2A.c
/   PROGRAM DESCRIPTION: Performance Lab 2A - Declaring and Initializing Variables
/   Instructions: 
/       In this lab, you will declare and initialize variables of the following types:
/           int
/           float
/           double
/           char
/       Then print the variables and their sizes.
*********************************************************************/
#include <stdio.h>

int main(void)
{
    //Declare all the variables
    int integer;
    float singlePrecision;
    double doublePrecision;
    char singleCharacter;

    //Initialize each variable
    integer = 69;
    singlePrecision = 3.14;
    doublePrecision = 3.141592636;
    singleCharacter = 'D';

    //print each variable and its size
    printf("My integer is %d and is %d BYTES \n", integer, sizeof(integer));
    printf("My float is %.f and is %d BYTES \n", singlePrecision, sizeof(singlePrecision));
    printf("My double is %.15g and is %d BYTES \n", doublePrecision, sizeof(doublePrecision));
    printf("My character is %c and is %d BYTE \n", singleCharacter, sizeof(singleCharacter));



}

