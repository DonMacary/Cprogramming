/********************************************************************************************************************
/   AUTHOR: ELF
/   COURSE: C Programming
/   PROGRAM NAME: perfLab12E.c
/   PROGRAM DESCRIPTION: Performance Lab 12E - USERNAMES
/   INSTRUCTIONS:
		## PERFORMANCE LAB: USERNAMES

		File I/O – fprintf()

		**“Usernames”**

		* Prompt the user for the number of students.
		* Read the first, middle, and last name for each student.
		* Remove any newline characters from all strings.


		* Append each name to a “class roster” file in the following format:
		* For George Herbert Dubya Bush, write the following to the s
		### BUILD THOSE SAFETY CHECKS!!!!!

**********************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_BUFFER 64

int main(void)
{


	char tempNumStudents[4] = { 0 };
	int goodInput = 0;
	int numberOfStudents = 0;
	while (goodInput == 0)
	{
		numberOfStudents = 0;
		printf("How many students would you like to create? (1-100) ");

		fgets(tempNumStudents, sizeof(tempNumStudents), stdin);  //gets input for nubmer of players and writes it to a temp string

		numberOfStudents = atoi(tempNumStudents);  //convert temp to an integer, and assigns to numberOfStudents
		if (!strchr(tempNumStudents, '\n')) //if there is no return character in the string that means that it was overwritten and there are too many characters
		{
			printf("Too many characters!\n");
			while (fgetc(stdin) != '\n'); // in this case keep reading all the input until there is a new line
		}
		if (numberOfStudents <= 0 || numberOfStudents > 100 )  //if the number given is less than 0 return an error
		{
			printf("Error: Enter a number between 1 and 100\n");
			goodInput = 0;
		}
		else //
		{
			goodInput = 1;
			
		}
	}
	printf("Number of students: %d\n", numberOfStudents);
	FILE *classRoster_ptr = fopen("class_roster.txt", "a");
	char filler[] = " has a username of ";
	if (classRoster_ptr != NULL)
	{
		for (int i = 0; i < numberOfStudents; i++)
		{
			int goodStrInput = 0;
			char firstName[MAX_BUFFER] = { 0 };

			//this loop checks to make sure the user inputs a good, null terminated string... Mainly to check if they didnt put too many characters which could overwrite the null terminator
			while (goodStrInput == 0)
			{
				printf("Please enter the first name of the student you would like to enroll: ");
				fgets(firstName, sizeof(firstName), stdin);
				if (!strchr(firstName, '\n')) //if there is no return character in the string that means that it was overwritten and there are too many characters
				{
					printf("Too many characters!\n");
					while (fgetc(stdin) != '\n'); // in this case keep reading all the input until there is a new line
				}
				else
				{
					goodStrInput = 1;
				}
			}
			goodStrInput = 0;
			char middleName[MAX_BUFFER] = { 0 };

			//this loop checks to make sure the user inputs a good, null terminated string... Mainly to check if they didnt put too many characters which could overwrite the null terminator
			while (goodStrInput == 0)
			{
				printf("Please enter the middle name of the student you would like to enroll: ");
				fgets(middleName, sizeof(middleName), stdin);
				if (!strchr(middleName, '\n')) //if there is no return character in the string that means that it was overwritten and there are too many characters
				{
					printf("Too many characters!\n");
					while (fgetc(stdin) != '\n'); // in this case keep reading all the input until there is a new line
				}
				else
				{
					goodStrInput = 1;
				}
			}
			goodStrInput = 0;
			char lastName[MAX_BUFFER] = { 0 };

			//this loop checks to make sure the user inputs a good, null terminated string... Mainly to check if they didnt put too many characters which could overwrite the null terminator
			while (goodStrInput == 0)
			{
				printf("Please enter the last name of the student you would like to enroll: ");
				fgets(lastName, sizeof(lastName), stdin);
				if (!strchr(lastName, '\n')) //if there is no return character in the string that means that it was overwritten and there are too many characters
				{
					printf("Too many characters!\n");
					while (fgetc(stdin) != '\n'); // in this case keep reading all the input until there is a new line
				}
				else
				{
					goodStrInput = 1;
				}
			}
			for (int i = 0; i < MAX_BUFFER; i++)
			{
				//Remove newline characters from each name
				if (*(firstName + i) == '\n')
				{
					*(firstName + i) = ' ';
				}
				if (*(middleName + i) == '\n')
				{
					*(middleName + i) = ' ';
				}
				if (*(lastName + i) == '\n')
				{
					*(lastName + i) = ' ';
				}
			}
			//initialiaze a variable to store the username array into
			char userName[MAX_BUFFER + 3] = { 0 };
			userName[0] = tolower(*(firstName)); //store the first character of the first name
			userName[1] = tolower(*(middleName)); //store the first character of the middle name
			int size = strlen(lastName);
			//this loop stores the lastname into the userName 
			for (int j = 0; j < size; j++)
			{
				
				*(userName + j + 2) = *(lastName + j);
				//makes sure the first letter is lowercase
				if (j == 0)
				{
					*(userName + j + 2) = tolower(*(userName + j + 2));
				}
			}
			//add all the text for this student into the file 
			fputs(firstName, classRoster_ptr);
			fputs(middleName, classRoster_ptr);
			fputs(lastName, classRoster_ptr);
			fputs(filler, classRoster_ptr);
			fputs(userName, classRoster_ptr);
			fputs("\n", classRoster_ptr);
			
		}
	}
	else
	{
		printf("There was an error opening the file!\n");
		return -1;
	}
	
	fclose(classRoster_ptr);
	while (1);
	return 1;
}
