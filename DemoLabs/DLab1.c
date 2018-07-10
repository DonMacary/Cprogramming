#include <stdio.h>

int main(void)
{
    int integer = 1;
    float singlePrecision = 2.2;
    double doublePrecision = 3.3;
    char singleChar = '$';
    char singleChar2 = 33;

    printf("your integer is %d \n", integer);
    printf("your float is %f \n", singlePrecision);
    printf("your double is %lf \n", doublePrecision);
    printf("your first char is %c \n", singleChar);
    printf("your second char is %c \n", singleChar2);

    return 0;
}