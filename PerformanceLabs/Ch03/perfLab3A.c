/*********************************************************************
/   AUTHOR: ELF
/   COURSE: C Programming 
/   PROGRAM NAME: perfLab3A.c
/   PROGRAM DESCRIPTION: Performance Lab 3A - Arrays
/   Instructions:     
/       Student ages
/            Declare and zeroize an int array with a dimension equal to the number of students + 1
/            Set index 0 with the age* of the instructor
/            Fill the elements of the array with the ages* of the students starting with index 1
/            Print the array
/        Favorite quote
/            Declare and initialize a char array with your favorite saying
/            Ensure the last index is set to nul ('\0')
/            Separate each word in the array with a new line character ('\n' or decimal value 10)
/
/           NOTE: * use your best guess
*********************************************************************/

#include <stdio.h>

int main(void)
{
    int numberOfStudents = 5; //The number of students in class

    int studentsArray [6] = {0}; //An int array with a dimension of the number of students + 1s
    

    //Manually filling in the array with the ages of the students in the class
    studentsArray[0] = 67;
    studentsArray[1] = 25;
    studentsArray[2] = 28;
    studentsArray[3] = 31;
    studentsArray[4] = 23;
    studentsArray[5] = 21;

    //manually printing out each index (because we haven't learned loops yet)
    printf("%d \n",studentsArray[0]);
    printf("%d \n",studentsArray[1]);
    printf("%d \n",studentsArray[2]);
    printf("%d \n",studentsArray[3]);
    printf("%d \n",studentsArray[4]);
    printf("%d \n",studentsArray[5]);

    //Declare and initialize a char array with your favorite saying
    char meeseeksQuote [35] = "I'm Mr Meeseeks look at me!";

    //ensure last index is set to nul
    printf("Last character in arrary = %c \n", meeseeksQuote[35]);  

    printf("%s \n",meeseeksQuote);

    //Separate each word in the array with a new line character ('\n' or decimal value 10) Again only doing it this way because we haven't learned loops and ifs
    meeseeksQuote[3] = 10;
    meeseeksQuote[6] = 10;
    meeseeksQuote[15] = 10;
    meeseeksQuote[20] = 10;
    meeseeksQuote[23] = 10;

    //print out the string one more time to see that each word is now on a new line!
    printf("%s \n",meeseeksQuote);









}

