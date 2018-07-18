/*Create a tailored times table
REQUIREMENTS:
    - Input an integer "x".
    - Print the product of x and y when y ranges from 1 through 10.
    - Exit if the user inputs an integer larger than 10.
    - Use continue to ignore any zeroes or negative numbers 
    in x, while repeating the loop.
*/

#include <stdio.h>

int main()
{
    int x = 0;      // User inputted number
    int y = 1;      // Increment var

    printf("Enter a number between 1-10: ");
    scanf("%4d", &x);

    // Prevents user from enter a number over 10... exits
    if (x > 10)
    {
        printf("Senpai!! You can't enter numbers larger than 10");
        return 0;
    }

    // print x * y, increment y until equal to 10.
    while (y <= 10)
    {
        // Add 1 to x until positive
        if (x <= 0)
        {
            printf("Skipping Number %d! Adding 1.\n", x);
            x++;
            continue;
        }
        printf("%d x %d = %d\n", x, y, x*y);
        y++;
    }
}