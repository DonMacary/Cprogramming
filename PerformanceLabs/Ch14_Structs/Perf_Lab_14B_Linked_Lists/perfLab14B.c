#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Header.h"


#define MAX_BUFFER 64



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
		printf("Student: %s ", tempHead->name);
		printf("\tStudent ID: %d \n", tempHead->studentID);
		printf("\tInitials: %s", tempHead->initials);
		printf("\tFavorite Artist: %s", tempHead->favArtists);
		printf("\tDream Car: %s", tempHead->dreamCar);
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
			printf("Student: %s", tempHead->name);
			switch (dataChoice)
			{
			case 1:
				printf("\tID Number: %d\n", tempHead->studentID);
				tempHead = tempHead->next_student;
				break;
			case 2:
				printf("\tInitials: %s", tempHead->initials);
				tempHead = tempHead->next_student;
				break;
			case 3:
				printf("\tFavorite Artist: %s", tempHead->favArtists);
				tempHead = tempHead->next_student;
				break;
			case 4:
				printf("\tDream Car %s ", tempHead->dreamCar);
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
					printf("Student: %s ", tempHead->name);
					printf("\tStudent ID: %d \n", tempHead->studentID);
					printf("\tInitials: %s", tempHead->initials);
					printf("\tFavorite Artist: %s", tempHead->favArtists);
					printf("\tDream Car: %s", tempHead->dreamCar);
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
			//return 1;
			//the following code asks the user to print the name of the person they would like to look up
			int goodInput2 = 0;
			char userInput[MAX_BUFFER] = { 0 };
			while (goodInput2 == 0)
			{
				printf("Enter the name of the student you would like to look up or 'EXIT' to return to the Main Menu: \n");

				fgets(userInput, sizeof(userInput), stdin);
				
				if (!strchr(userInput, '\n'))
				{
					printf("Invalid Input!\n");
					while (fgetc(stdin) != '\n');
				}
				
				else
				{
					goodInput2 = 1;
				}
			}
			int iterator = 0;
			//eliminate the new line character in the user inputed string
			while (userInput[iterator] != '\0')
			{
				//find the new line character in the string
				if (userInput[iterator] == '\n')
				{
					userInput[iterator] = '\0';
				}
				iterator++;
			}
			//create a string that is exactly the length of the string the user inputed (with no extra null characters)
			char *string = malloc(strlen(userInput)+1);
			strcpy(string, userInput);
			//realloc(userInput, strlen(userInput));
			//if the user types EXIT
			if (strstr(string, "EXIT") != NULL)
			{
				free(string);
				return 1;
			}
			while (tempHead != NULL)
			{
				//this if statement checks if the user input is contained in any of the names in the linked list
				if (strstr(tempHead->name, string) != NULL)
				{
					printf("Student: %s ", tempHead->name);
					printf("\tStudent ID: %d \n", tempHead->studentID);
					printf("\tInitials: %s", tempHead->initials);
					printf("\tFavorite Artist: %s", tempHead->favArtists);
					printf("\tDream Car: %s", tempHead->dreamCar);
					printf("----------------------------------\n\n");
					studentPrinted++;
					tempHead = tempHead->next_student;
				}
				else
				{
					tempHead = tempHead->next_student;
				}
			}
			if (studentPrinted == 0)
			{
				free(string);
				printf("There is no student in the list with that name\n");
				return 1;
			}
			free(string);
		}

	}
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
* NOTES:		This function adds a student to the linked list and then points the head to that students memory address
*
*
*/
extern struct Student * add_student(struct Student * head)
{
	struct Student * tempHead = head;
	int goodInput = 0;
	int inputValue = 0;
	//ask if the user would like to add a new student
	while (goodInput == 0)
	{
		printf("Would you like to add a new student? Enter 1 for yes, 0 for No ");
		char inputStr[5] = { 0 };

		fgets(inputStr, sizeof(inputStr), stdin);
		inputValue = atoi(inputStr);

		if (!strchr(inputStr, '\n'))
		{
			printf("Invalid Input!\n");
			while (fgetc(stdin) != '\n');
		}
		else if (inputValue < 0 || inputValue > 1)
		{
			printf("You must enter a number 1-100\n");
		}
		else
		{
			goodInput = 1;
		}
	}
	//if they dont want to add a new student go back to main menu
	if (inputValue == 0)
	{
		return head;
	}
	else
	{
		struct Student * newStudent = (struct Student*)malloc(sizeof(struct Student));
		goodInput = 0;
		//get the user's name
		while (goodInput == 0)
		{
			char inputString[MAX_BUFFER] = { 0 };
			printf("Enter the student's full name: ");
			fgets(inputString, MAX_BUFFER, stdin);
			if (!strchr(inputString, '\n'))
			{
				printf("Invalid Input!\n");
				while (fgetc(stdin) != '\n');
			}
			else
			{
				goodInput = 1;
			}

			strcpy(newStudent->name, inputString);
		}
		goodInput = 0;
		//get the user's initials
		while (goodInput == 0)
		{
			printf("Enter the student's initials: ");
			char inputString[MAX_BUFFER] = { 0 };
			fgets(inputString, MAX_BUFFER, stdin);
			if (!strchr(inputString, '\n'))
			{
				printf("Invalid Input!\n");
				while (fgetc(stdin) != '\n');
			}
			else
			{
				goodInput = 1;
			}
			strcpy(newStudent->initials, inputString);
		}
		goodInput = 0;
		//get the user's favorite artist
		while (goodInput == 0)
		{
			printf("Enter the student's favorite artist: ");
			char inputString[MAX_BUFFER] = { 0 };
			fgets(inputString, MAX_BUFFER, stdin);
			if (!strchr(inputString, '\n'))
			{
				printf("Invalid Input!\n");
				while (fgetc(stdin) != '\n');
			}
			else
			{
				goodInput = 1;
			}
			strcpy(newStudent->favArtists, inputString);
		}
		goodInput = 0;
		//get the user's dream car
		while (goodInput == 0)
		{
			printf("Enter the student's Dream Car: ");
			char inputString[MAX_BUFFER] = { 0 };
			fgets(inputString, MAX_BUFFER, stdin);
			if (!strchr(inputString, '\n'))
			{
				printf("Invalid Input!\n");
				while (fgetc(stdin) != '\n');
			}
			else
			{
				goodInput = 1;
			}
			strcpy(newStudent->dreamCar, inputString);
		}
		newStudent->studentID = tempHead->studentID + 1;		//make sure the student's ID is the next ID number 
		newStudent->next_student = tempHead;					//make the next student = to the current head
		head = newStudent;										//make the new student the current head
		return head;
	}
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
extern struct Student * remove_last_student(struct Student * head)
{
	struct Student * tempHead = head;

	int goodInput = 0;
	int inputValue = 0;
	//ask if the user would like to add a new student
	while (goodInput == 0)
	{
		printf("Would you like to remove the last student? Enter 1 for yes, 0 for No ");
		char inputStr[5] = { 0 };

		fgets(inputStr, sizeof(inputStr), stdin);
		inputValue = atoi(inputStr);

		if (!strchr(inputStr, '\n'))
		{
			printf("Invalid Input!\n");
			while (fgetc(stdin) != '\n');
		}
		else if (inputValue < 0 || inputValue > 1)
		{
			printf("You must enter a number 1-100\n");
		}
		else
		{
			goodInput = 1;
		}
	}
	//if they dont want to remove the last student go back to main menu
	if (inputValue == 0)
	{
		return head;
	}
	//otherwise -> remove the head and set the next student to be the head
	else
	{
		//if the current head is null then there is nothing left to remove and print an error!
		if (head->studentID == NULL )
		{
			printf("These users are base users and cannot be deleted\n");
			return head;
		}
		else
		{
			head = head->next_student;	//set the head to the next element
			//nullify all the data in the current head
			printf("Removing student %s", tempHead->name);
			strcpy(tempHead->name, "\0");	
			tempHead->studentID = NULL;
			strcpy(tempHead->initials, "\0");
			strcpy(tempHead->favArtists, "\0");
			strcpy(tempHead->dreamCar, "\0");
			tempHead->next_student = NULL;
			//free(tempHead);	//free the tempHead
			return head;	//return the head (because its pointing to the next student now

		}
	}
		
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
extern struct Student * remove_specific_student(struct Student * head)
{
	while (1)
	{
		struct Student * tempHead = head;
		int goodInput = 0;
		int studentToRemove = 0; //stores the number of the student ID the user wants to remove
		int studentRemoved = 0; //value for whether or not a student was removed - if 0 then there wasnt if !0 then he was
								//ask if the user would like to add a new student
		while (goodInput == 0)
		{
			printf("Enter the Student ID of the student you would like to remove, if you do not know their ID enter 0 to look up by name or exit ");
			char inputStr[5] = { 0 };

			fgets(inputStr, sizeof(inputStr), stdin);
			studentToRemove = atoi(inputStr);

			if (!strchr(inputStr, '\n'))
			{
				printf("Invalid Input!\n");
				while (fgetc(stdin) != '\n');
			}
			else if (studentToRemove < 0 || studentToRemove > 100)
			{
				printf("You must enter a number 1-100\n");
			}
			else
			{
				goodInput = 1;
			}
		}
		//if they dont want remove a specific student go back to main menu
		if (studentToRemove == 0)
		{
			print_one_student(head);
			
			
		}
		//otherwise find the student they want to remove and remove him
		else
		{
			//if the student they want to remove is the current head then use the remove last student function
			if (head->studentID == studentToRemove)
			{
				head = remove_last_student(head);
				return head;
			}
			//otherwise find the student the want to remove and remove him
			else
			{
				while (tempHead != NULL)
				{
					//if we find the student we want to remove
					if (tempHead->studentID == studentToRemove)
					{
						struct Student * removeThisStudent = tempHead;	//set a new struct variable to the next student which is the one we want to remove
						tempHead = head; //reset our linked list back to the beginning
						printf("Removing student %s", removeThisStudent->name);
						//loop through the list again until the next student is equal to the student we want to remove
						while (tempHead->next_student != removeThisStudent)
						{
							tempHead = tempHead->next_student;
						}
						//set the current student's next student = the student we want to removes next student
						tempHead->next_student = removeThisStudent->next_student;
						//NULLIFY everything in the student we want to remove
						strcpy(removeThisStudent->name, "\0");
						removeThisStudent->studentID = NULL;
						strcpy(removeThisStudent->initials, "\0");
						strcpy(removeThisStudent->favArtists, "\0");
						strcpy(removeThisStudent->dreamCar, "\0");
						removeThisStudent->next_student = NULL;
						studentRemoved = 1;
						return head;
					}
					else
					{
						tempHead = tempHead->next_student;
					}

				}
				if (studentRemoved == 0)
				{
					printf("There was no student with this ID in the list\n");
				}
			}
		}
	}
}


