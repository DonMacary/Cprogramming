/*********************************************************************
/   AUTHOR: ELF
/   COURSE: C Programming
/   PROGRAM NAME: perfLab14B.c
/   PROGRAM DESCRIPTION: Performance Lab 14B - Linked Lists
/   INSTRUCTIONS:

# Linked Lists Lab 1

![](/assets/subbie.jpg)

## Requirments

* Utilize headers for all declarations
* Utilize proper naming schemas
* Document code
* Push code to Github
* Use branching! Create a development branch and push to there. Merge when all requirments are met
* Break your code out into functions
* Utilize multiple C files if needed

## Instructions

1. Create a linked list, the struct members should contain the following:
* Each students initals
* Each students favoriate musical artist
* Each studnets dream car
* Required data for linked list completion
* **May be worth each student just posting their data into a slack channel so everyone can grab off of it**
2. Create a menu allowing for the following:
* Print out of all students and all of their data
* Print out of all students and only one of their data members on request of user (ex. print out all students and their fav car)
* Print out of only a specific student (This one can be challanging)
3. **BONUS**
* Add additonal students to the end
* Remove students at the end
* Remove a specific student (This one is challanging)
4. Push code to Github and post the link in code (This is so that we can get more practice with git)
* Ensure you are commiting often
* *Advice:* Commit anything a moderate feature is added or changed
* ex: You added the ability to print out a specific student
* ex: You removed a section of code that was giving you issues
* *Advice:* You can commit often without the need to push your code. It's recommended to push code after larger work is done
* ex: You finished an entire requirment
* ex: You changed a large amount of code
* ex: You have a ton of commits

/*********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Header.h"


int main(void)
{
	int menuChoice = 0;
	struct Student student1 = { "Donnie Macary", 1, "DDM", "Blink182", "Acura MDX", NULL };
	struct Student student2 = { "Susan Macary", 2, "SPM", "The Beatles", "Honda Pilot", &student1 };
	struct Student student3 = { "John Macary", 3, "JRM", "Phish", "Honda Civic SI", &student2 };
	struct Student student4 = { "Don Macary", 4, "DDM", "The Doors", "Ford Mustand", &student3 };
	struct Student student5 = { "Rachel Nieymeyer", 5, "RSN", "Crosby Stills and Nash", "Honday Odyssey", &student4 };
	struct Student student6 = { "Stephanie Mabrey", 6, "SLM", "Zac Brown Band", "Honda Civic", &student5 };
	struct Student student7 = { "Stacy Kornmeyer", 7, "SMK", "DaveMatthews Band", "Honda Odyssey", &student6 };
	struct Student * head = &student7;
	//all my main will do is print the menu and then use that selection to do the appropriate functionality
	do
	{
		int goodInput = 0;
		print_menu();

		//this loop gts input from user and error checks it
		while (goodInput == 0)
		{
			printf("Which option would you like to choose? ");
			char inputStr[5] = { 0 };

			fgets(inputStr, sizeof(inputStr), stdin);
			menuChoice = atoi(inputStr);

			if (!strchr(inputStr, '\n'))
			{
				printf("Invalid Input!\n");
				while (fgetc(stdin) != '\n');
			}
			else if (menuChoice < 1 || menuChoice > 7)
			{
				printf("You must enter a number 1-7\n");
			}
			else
			{
				goodInput = 1;
			}
		}
		switch (menuChoice)
		{
		case 1:
			print_all_students(head);
			break;
		case 2:
			print_students_with_data(head);
			break;
		case 3:
			print_one_student(head);
			break;
		case 4:
			add_student(head);
			break;
		case 5:
			remove_last_student(head);
			break;
		case 6:
			remove_specific_student(head);
			break;
		case 7:
			printf("Have a nice day!\n");
			return 1;
		default:
			break;
		}

	} while (menuChoice != 6);


	while (1);
	return 1;
}