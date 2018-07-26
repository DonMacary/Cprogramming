#define WRAP(x) #x


#ifdef __unix__
#define WRAPPER WRAP(__unix__)
#elif _WIN32
#	ifdef _WIN64
#		define WRAPPER WRAP(_WIN64)
#	else
#		define WRAPPER WRAP(_WIN32)
#	endif
#elif __linux__
#define WRAPPER WRAP(__linux__)
#elif __APPLE__
#define WRAPPER WRAP(__APPLE__)
#else
//#error "Unknown compiler"
#endif

#define WAIT getchar(); getchar();
int main(void)
{
	puts(WRAPPER);

	WAIT 
	return 0;
}
