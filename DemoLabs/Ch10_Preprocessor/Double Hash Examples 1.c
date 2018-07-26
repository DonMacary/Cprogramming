#include <stdio.h>

#define STRINGIFY_FOR_REAL(x) #x
#define STRINGIFY(a) STRINGIFY_FOR_REAL(a)

#define PASTE_FOR_REAL(x, y) x##y
#define PASTE(a, b) PASTE_FOR_REAL(a, b)

int main(void)
{
//	char PASTE(that, Guy)[] = {STRINGIFY(PASTE(That, Guy))};

//	puts(thatGuy);

	puts(STRINGIFY(PASTE(That, PASTE(Per, son))));

	puts(STRINGIFY_FOR_REAL(PASTE_FOR_REAL(That, Guy)));

	return 0;
}
