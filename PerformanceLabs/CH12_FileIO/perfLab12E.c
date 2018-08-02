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
		* For George Herbert Dubya Bush, write the following to the the file...George H. Dubya Bush has a username of ghdbush.

		### BUILD THOSE SAFETY CHECKS!!!!!

**********************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
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
			char middleInit[2] = 0;

			//this loop checks to make sure the user inputs a good, null terminated string... Mainly to check if they didnt put too many characters which could overwrite the null terminator
			while (goodStrInput == 0)
			{
				printf("Please enter the middle initial of the student you would like to enroll: ");
				fgets(middleInit, sizeof(middleInit), stdin);
				if (!strchr(middleInit, '\n')) //if there is no return character in the string that means that it was overwritten and there are too many characters
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
				printf("Please enter the first name of the student you would like to enroll: ");
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
			//Remove newline character from each name
			if (strchr(firstName, '\n'))
			{

			}
			

		//	fputs(tempStudentStr, classRoster_ptr);
		//	fputs(filler, classRoster_ptr);
		//	fputs(tempUserNameStr, classRoster_ptr);
			
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
