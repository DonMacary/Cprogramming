//Practicing random stuff in chapter 5
//ELF


#include <stdio.h>
#include <math.h>

int main(void)
{
    //////// ARITHMETIC OPERATOR QUIZ BONUS QUESTION ////////
    int y = 4;
    int x;
    printf("num 1 real: %d\n", 1 + 2 * (3 + y) + 5);        // Result 20

    //rewrite
    printf("num 1 rewrite: %d\n", 5 * y + (3-2-1));            //result is still 20
    

    //////// RELATIONAL OPERATOR QUIZ BONUS QUESTION ////////
    x = 2; y = 6;
    printf("num 2 real: %d\n",x != y != 3 >= x);          // Result 0
    // 1 != 3 >= x
    // 1 >= x
    // 0
    //rewrite       Result still = 0
    printf("num 2 rewrite: %d\n",x >= 3 != y == x);
    //0 != y ==x
    //1 == x
    //0

    //////// ASSIGNMENT OPERATOR QUIZ BONUS QUESTION ////////
    x = 9; y = 3;
    printf("num3 real: %d\n",(y %= y) || (x /= x--));    // Result 0
    //0 || 0
    //0
    printf("num3 rewrite: %d\n", (y -= y) || (x -= x));


    // What would be a better way of writing these?

}