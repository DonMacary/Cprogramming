#include <stdio.h>

extern int sort_int_array(int * intArray, int arrayLen)
{
	if (!intArray)
	{
		return -1;
	}
	if (arrayLen <= 1)
	{
		return -2;
	}
	int i = 0;
	int j = 0;
	int temp = 0;

	for (j=0; j<(arrayLen-1); j++)
	{
		for (i=0; i < (arrayLen - 1); i++)
		{
			if (intArray[i+1] > intArray[i])
			{
				temp = intArray[i];
				intArray[i] = intArray[i+1];
				intArray[i+1] = temp;
			}
		}
	}
	return 0;
}
