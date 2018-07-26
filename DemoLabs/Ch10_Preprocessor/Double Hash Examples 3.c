#include <stdio.h>
#include <stdbool.h>

#define MERGE(x, y) x##y
#define FIRST_NAME(person, fName) strcpy(MERGE(person,.thePersonsFirstName), #fName);
#define LAST_NAME(person, lName) strcpy(MERGE(person,.thePersonsLastName), #lName);
#define ID(person, num) person##.thatPersonsEmployeedIdentificationNumber = num
#define COOL(person, boolean) person##.isThatPersonCoolOrNot = boolean

struct PeopleAtWork
{
	char thePersonsFirstName[50];
	char thePersonsLastName[50];
	int thatPersonsEmployeedIdentificationNumber;
	bool isThatPersonCoolOrNot;
};

int main(void)
{
	struct PeopleAtWork hark;

	FIRST_NAME(hark, Joseph);
	LAST_NAME(hark, Harkleroad);
	ID(hark, I.3.);
	COOL(hark, true);

	return 0;
}
