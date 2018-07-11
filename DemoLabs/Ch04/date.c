#include <stdio.h>

int main(void)
{
    int month = 0; int day = 0; int year = 0; // Ignore this faux pas

    printf("Enter today's date as mm-dd-yyyy \n");
    // _flushall(); // Clears all open input streams, leaving them open * This no longer works. We will go into this more once we learn while loops
    scanf("%d-%d-%d", &month, &day, &year);


    printf("Today's date is:  %02d/%02d/%04d \n", month, day, year);

    return 0;
}
