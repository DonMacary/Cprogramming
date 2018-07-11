#include <stdio.h>

int main(void)
{
	char myFavoriteWord [8] = {0};
	
	myFavoriteWord[0] = 77;
	myFavoriteWord[1] = 117;
	myFavoriteWord[2] = 115;
	myFavoriteWord[3] = 116;
	myFavoriteWord[4] = 97;
	myFavoriteWord[5] = 110;
	myFavoriteWord[6] = 103;
	
	printf("My favorite word is %s \n", myFavoriteWord);
	
	getchar();
    
	return 0;
	
}