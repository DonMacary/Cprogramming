#include <stdio.h>

int main(void)
{
	char testCase[] = {'A', 'B', 'C', 0};
	double currentTemp[] = {100.1234, 99.876543, 133.7};
	int numOfRuns[] = {3, 4, 5};
	
	printf("%-12Test Case %-12Temp(F) %12-# of Runs\n");
	printf("%-12c %-012.2f %-12d\n", testCase[0], currentTemp[0], numOfRuns[0]);
	printf("%-12c %-012.2f %-12d\n", testCase[1], currentTemp[1], numOfRuns[1]);
	printf("%-12c %-012.2f %-12d\n", testCase[2], currentTemp[2], numOfRuns[2]);
	return 0;
}
