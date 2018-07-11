/*********************************************************************
/   AUTHOR: ELF
/   COURSE: C Programming 
/   PROGRAM NAME: perfLab3B.c
/   PROGRAM DESCRIPTION: Performance Lab 3B - Strings
/   INSTRUCTIONS: 
/        Declare and zeroize a char array with a dimension of 256
/        Assign your chosen pharse to the leading elements of that array
/        Explicitly verify your string is nul-terminated
/        Print your string
/
/       QUIZ: What is your string length?
/
/       EVIL: Replace/remove/comment all null ('\0') characters and print the string
/*********************************************************************/

#include <stdio.h>
#include <string.h>

int main(void)
{
    //Declare and zeroize a char array with a dimension of 256
    char phrase [256] = {0};

    //Assign your chosen pharse to the leading elements of that array
    phrase[0] = 'S';
    phrase[1] = 'z';
    phrase[2] = 'e';
    phrase[3] = 'c';
    phrase[4] = 'h';
    phrase[5] = 'u';
    phrase[6] = 'a';
    phrase[7] = 'n';
    phrase[8] = '\0';

    //Print your string
    printf("%s \n", phrase);

    //Quiz - What is my string length? - I suspect the length of my string is 8 
    printf("The length of your string is: %d \n", strlen(phrase));

    //EVIL: Replace/remove/comment all null ('\0') characters and print the string
    int i;
    for(i = 0; i < 255; i++)
    {
        if(phrase[i] == '\0')
        {
            phrase[i] = 'D';
        }


    }
    // Once all Null characters are replaced with the letter D print out the string

    printf("%s \n", phrase);

}