#ifdef NULL
#undef NULL
#endif

#ifndef NULL
#define NULL ((void *)0)
#endif

int main(void)
{
	char * stringPointer = NULL;

	return 0;
}
