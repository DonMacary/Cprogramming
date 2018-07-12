/*********************************************************************
/   AUTHOR: ELF
/   COURSE: C Programming 
/   PROGRAM NAME: perfLab4D.c
/   PROGRAM DESCRIPTION: Performance Lab 4D - Scanf
/   INSTRUCTIONS:
/       Part 1
            Formatted Input (strings)

                Read a first, middle and last name as input into separate char arrays
                Specify a field-width to protect against buffer overflow
                Ensure the field-width leaves room for a nul-terminator
                Specify a ("\t") as a delimitating character
                Print the full name, separating each string with a tab and newline ("\t\n")

        Part 2
            Formatted Input (numbers)

                Read two integers from one line
                Format the input so that the integers are separated by an asterisk (*) x*y (e.g., 2*3, 11*14)
                Reprint the two integers and result as if the answer were being read by a human

        ////////////// EXAMPLE #1 ///////////////
        OUTPUT:  Enter two integers, separated by a *, to be multiplied…
        INPUT:   2*3
        OUTPUT:  The result of 2 multiplied by 3 is 6.  
        ////////////// EXAMPLE #2 ///////////////
        OUTPUT:  Enter two integers, separated by a *, to be multiplied…
        INPUT:   11*14
        OUTPUT:  The result of 11 multiplied by 14 is 154.
/*********************************************************************/

#include <stdio.h>

int main(void)
{
    //part 1 - Formatted Input (Strings) - note I could not get it to only accept tabs as a deliminator. I dont think scanf allows you to change the delim
    //from white space. Also note I was unable to make multiple filters (IE as soon as I put a filter on the first one it stopped reading and wouldn't
    //scan any more input into oher variables). My solution going forward would be to do input checking with loops and ifs but we haven't learned those yet
    char firstName[25];
    char middleName[25];
    char lastName[25];
  
    //these two lines dont work - it does not like specifying a comma as a delim
    //scanf("%24s,%24s,%24s", &firstName, &middleName, &lastName);
    //printf("Your name is: \t%s\n \t%s\n \t%s\n",firstName, middleName, lastName);

    //In the below code the commented out code works but will take any character as a delimiter - the running code shows how to separate on a specific 
    //delimiter, specifically the -
    printf("Please print your full name: ");
    //scanf("%24s%*c%24s%*c%24s",&firstName,&middleName,&lastName);
    scanf("%32[^-]-%32[^-]-%s32", &firstName, &middleName, &lastName);
    printf("Name: \n\t%s\n\t%s\n\t%s\n",firstName,middleName,lastName);

    //these two lines dont work - It doesn't like using multiple filters, as soon as it hits one filter condition it stops reading anything else
    //use the above fix to work around this limitation
    //scanf("%10[A-z]s%10[A-z]s%10[A-z]s", &firstName, &middleName, &lastName);
    //printf("Name: \n\t%s\n \t%s\n \t%s\n", firstName, middleName, lastName);

    //Part 2 - Formatted Input (numbers)
    
    int number1;
    int number2;
    printf("Enter two integers, separated by a *, to be multiplied: ");
    scanf("%d%*c%d",&number1,&number2);
    printf("The Result of %d multiplied by %d is %d\n", number1, number2, number1*number2);
    
}