#include <stdio.h>
#include "addnums.h"

int main()
{
    int num1 = 4;
    int num2 = 5;

    int sum = add_nums(num1, num2);

    printf("Sum: %i\n", sum);

    return 0;
}