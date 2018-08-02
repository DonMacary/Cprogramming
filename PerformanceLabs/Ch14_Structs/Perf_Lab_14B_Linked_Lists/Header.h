#pragma once
#ifndef LINKED_LAB_HEADER
#define LINKED_LAB_HEADER
#define _CRT_SECURE_NO_WARNINGS 1

#define MAX_BUFFER 64

extern int print_menu(void);

extern int print_all_students(struct Student * head);

extern int print_students_with_data(struct Student * head);

extern int print_one_student(struct Student * head);

extern struct Student * add_student(struct Student * head);

extern struct Student * remove_last_student(struct Student * head);

extern struct Student * remove_specific_student(struct Student * head);

struct Student
{
	char name[MAX_BUFFER];
	int studentID;
	char initials[5];
	char favArtists[MAX_BUFFER];
	char dreamCar[MAX_BUFFER];
	struct Student * next_student;
};


#endif
