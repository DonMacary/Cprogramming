#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BUFFER 256

struct Student {
	char *name;
	char initials[4];
	char * favArtists;
	char * dreamCar;
	struct Student * next_student;
};

extern int print_menu(void)
{
	printf("STUDENT LIST MENU: \n");
	printf("------------------------------\n");
	printf("1.) Print all students in database\n");
	printf("2.) Print all students in database with a data point\n");
	printf("3.) Print a specific student\n");
	printf("4.) Add a student to database\n");
	printf("5.) Remove last student from databasae\n");
	printf("6.) Remove a specific student from database\n");
	printf("7.) Exit\n");
	return 1;
}

extern int print_all_students(struct Student * head)
{
	struct Student * tempHead = head;
	int counter = 1;
	printf("This prints all of the students!\n");
	while (!tempHead)
	{
		printf("Student %d: %s \n", counter, tempHead->name);
		counter++;
		tempHead = tempHead->next_student;
	}
	return 1;
}

extern int print_students_with_data(struct Student * head)
{
	printf("This prints all the students and one data attribute\n");
	return 1;
}

extern int print_one_student(struct Student * head)
{
	printf("This prints just one student!\n");
	return 1;
}

extern int add_student(struct Student * head)
{
	printf("This adds one student to the end of the linked list\n");
	return 1;
}

extern int remove_last_student(struct Student * head)
{
	printf("This removes the last student from the list!\n");
	return 1;
}

extern int remove_specific_student(struct Student * head)
{

	printf("This removes a specific student from the list!\n");
	return 1;
}


