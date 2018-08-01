#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Header.h"


#define MAX_BUFFER 256


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

/*
* FUNCTION:		 print_all_students(struct Student * head)
*
* ARGUMENTS:	- *head is a pointer to the head of a linked list of students
*
*
* RETURNS:		1 on SUCCES
*				0 on FAILURE (WILL NOT BE IMPLEMENTED IN THIS PROJECT!!!!
*
* NOTES:		This function takes in the linked list and prints all of the students and all of their attributes
*
*
*/
extern int print_all_students(struct Student * head)
{
	struct Student * tempHead = head;
	printf("This prints all of the students!\n");
	while (tempHead != NULL)
	{
		printf("Student: %s \n", tempHead->name);
		printf("\tStudent ID: %d \n", tempHead->studentID);
		printf("\tInitials: %s\n", tempHead->initials);
		printf("\tFavorite Artist: %s\n", tempHead->favArtists);
		printf("\tDream Car: %s\n", tempHead->dreamCar);
		printf("----------------------------------\n\n");
		tempHead = tempHead->next_student;
	}
	return 1;
}

/*
* FUNCTION:		 print_all_students_with_data(struct Student * head)
*
* ARGUMENTS:	- *head is a pointer to the head of a linked list of students
*
*
* RETURNS:		1 on SUCCES
*				0 on FAILURE (WILL NOT BE IMPLEMENTED IN THIS PROJECT!!!!
*
* NOTES:		This function takes in the linked list and prints all of the students and only one of their attributes - note this attribute is user defined within this function
*
*
*/
extern int print_students_with_data(struct Student * head)
{
	//this loops through until the user enters in the exit option (5) therefor it being a while(1) is fine... 
	while (1)
	{
		//I am initializing all inputs within the while loop so each time the user iterates through everything is reset to normal
		int goodInput = 0; //error checking for input
		struct Student * tempHead = head; 
		int dataChoice = 0;
		// prints the data options the user can ask for
		printf("OPTIONS\n");
		printf("1.)ID Number\n");
		printf("2.)Initials\n");
		printf("3.)Favorite Artist\n");
		printf("4.)Dream Car\n");
		printf("5.)Return to Main Menu\n");

		//error checking loop for the data option selection
		while (goodInput == 0)
		{
			printf("Which piece of data would you like to chose? ");
			char inputStr[5] = { 0 };

			fgets(inputStr, sizeof(inputStr), stdin);
			dataChoice = atoi(inputStr);

			if (!strchr(inputStr, '\n'))
			{
				printf("Invalid Input!\n");
				while (fgetc(stdin) != '\n');
			}
			else if (dataChoice < 1 || dataChoice > 5)
			{
				printf("You must enter a number 1-5\n");
			}
			else
			{
				goodInput = 1;
			}
		}
		//loops through ever user in the linked list and prints out whichever option the user selected
		while (tempHead != NULL)
		{
			printf("\n----------------------------------\n");
			printf("Student: %s\n", tempHead->name);
			switch (dataChoice)
			{
			case 1:
				printf("\tID Number: %d\n", tempHead->studentID);
				tempHead = tempHead->next_student;
				break;
			case 2:
				printf("\tInitials: %s\n", tempHead->initials);
				tempHead = tempHead->next_student;
				break;
			case 3:
				printf("\tFavorite Artist: %s\n", tempHead->favArtists);
				tempHead = tempHead->next_student;
				break;
			case 4:
				printf("\tDream Car %s \n", tempHead->dreamCar);
				tempHead = tempHead->next_student;
				break;
			case 5:
				return 1;
				break;
			default:
				return 1;
				break;
			}
			
		}
		
	}
	
	
	return 1;
}


/*
* FUNCTION:		 print_one_student(struct Student * head)
*
* ARGUMENTS:	- *head is a pointer to the head of a linked list of students
*
*
* RETURNS:		1 on SUCCES
*				0 on FAILURE (WILL NOT BE IMPLEMENTED IN THIS PROJECT!!!!
*
* NOTES:		This function asks the user which student they would like to print and then prints that student
*
*
*/
extern int print_one_student(struct Student * head)
{
	//this loops through until the user chooses to exit therefor it being a while(1) is fine... 
	while (1)
	{
		int goodInput = 0;
		struct Student * tempHead = head;
		int studentToPrint = 0; //stores the number of the student ID the user wants to print
		int studentPrinted = 0; //value for whether or not a student was printed - if 0 then there wasnt if !0 then he was
		while (goodInput == 0)
		{
			printf("Enter the Student ID of the student you would like to print, if you do not know their ID enter 0 to look up by name or exit ");
			char inputStr[5] = { 0 };

			fgets(inputStr, sizeof(inputStr), stdin);
			studentToPrint = atoi(inputStr);

			if (!strchr(inputStr, '\n'))
			{
				printf("Invalid Input!\n");
				while (fgetc(stdin) != '\n');
			}
			else if (studentToPrint < 0 || studentToPrint > 100)
			{
				printf("You must enter a number 1-100\n");
			}
			else
			{
				goodInput = 1;
			}
		}
		if (studentToPrint > 0)
		{
			while (tempHead != NULL)
			{
				if (tempHead->studentID == studentToPrint)
				{
					printf("Student: %s \n", tempHead->name);
					printf("\tStudent ID: %d \n", tempHead->studentID);
					printf("\tInitials: %s\n", tempHead->initials);
					printf("\tFavorite Artist: %s\n", tempHead->favArtists);
					printf("\tDream Car: %s\n", tempHead->dreamCar);
					printf("----------------------------------\n\n");
					studentPrinted = 1;
					tempHead = NULL;
				}
				else
				{
					tempHead = tempHead->next_student;
				}
			}
			if (studentPrinted == 0)
			{
				printf("No student with that ID was found, please try again!\n");
			}
		}
		//create functionality to look up the student by their name
		else
		{

			return 1;
		}

	}


	return 1;
}

/*
* FUNCTION:		add_student(struct Student * head)
*
* ARGUMENTS:	- *head is a pointer to the head of a linked list of students
*
*
* RETURNS:		1 on SUCCES
*				0 on FAILURE (WILL NOT BE IMPLEMENTED IN THIS PROJECT!!!!
*
* NOTES:		This function adds a student to the linked list and then points thte head to that students memory address
*
*
*/
extern int add_student(struct Student * head)
{
	printf("This adds one student to the end of the linked list\n");
	return 1;
}

/*
* FUNCTION:		 remove_last_student(struct Student * head)
*
* ARGUMENTS:	- *head is a pointer to the head of a linked list of students
*
*
* RETURNS:		1 on SUCCES
*				0 on FAILURE (WILL NOT BE IMPLEMENTED IN THIS PROJECT!!!!
*
* NOTES:		This function removes the last student of the linked list and points the head to the new last student
*
*
*/
extern int remove_last_student(struct Student * head)
{
	printf("This removes the last student from the list!\n");
	return 1;
}

/*
* FUNCTION:		 remove_specific_student(struct Student * head)
*
* ARGUMENTS:	- *head is a pointer to the head of a linked list of students
*
*
* RETURNS:		1 on SUCCES
*				0 on FAILURE (WILL NOT BE IMPLEMENTED IN THIS PROJECT!!!!
*
* NOTES:		This function asks the user which student they would like to remove and then removes that student from the linked list
*
*
*/
extern int remove_specific_student(struct Student * head)
{

	printf("This removes a specific student from the list!\n");
	return 1;
}


