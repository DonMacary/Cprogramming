#pragma once
#ifndef LINKED_LAB_HEADER
#define LINKED_LAB_HEADER

#define MAX_BUFFER 256

extern int print_menu(void);

extern int print_all_students(struct Student * head);

extern int print_students_with_data(struct Student * head);

extern int print_one_student(struct Student * head);

extern int add_student(struct Student * head);

extern int remove_last_student(struct Student * head);

extern int remove_specific_student(struct Student * head);

struct Student {
	char *name;
	char initials[4];
	char * favArtists;
	char * dreamCar;
	struct Student * next_student;
};


#endif
