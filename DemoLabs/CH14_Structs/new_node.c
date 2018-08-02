#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Student90COS
{
    char student_initials[4];
    int student_number;
    struct Student90COS * next_node;
}node;

void spillList(node *n);


int main(void)
{
    node * MQT18_01_S1 = (node*)malloc(sizeof(node));  //head
    node * MQT18_01_S2 = (node*)malloc(sizeof(node));
    node * MQT18_01_S3 = (node*)malloc(sizeof(node));  //tail

    //head
    strcpy(MQT18_01_S1->student_initials, "LOL");
    MQT18_01_S1->student_number = 1;
    MQT18_01_S1->next_node = MQT18_01_S2;

    //node2
    strcpy(MQT18_01_S2->student_initials, "KAY");
    MQT18_01_S2->student_number = 2;
    MQT18_01_S2->next_node = MQT18_01_S3;

    //tail
    strcpy(MQT18_01_S3->student_initials, "YAY");
    MQT18_01_S3->student_number = 3;
    MQT18_01_S3->next_node = NULL;


    spillList(MQT18_01_S1);

    // ############ ADDING A NEW NODE BETWEEN S1 and S2##############
    node * MQT18_01_S4 = (node*)malloc(sizeof(node));

    strcpy(MQT18_01_S4->student_initials, "MOV");
    MQT18_01_S4->student_number = 4;
    MQT18_01_S4->next_node = MQT18_01_S2;

    // EDIT Node 1
    MQT18_01_S1->next_node = MQT18_01_S4;

    // Print the new list
    printf("\n\n NEW LIST\n");
    spillList(MQT18_01_S1);


    /*
    -There are more advanced ways of doing this via itterating and such.
    -But obviously this will complicate the program more. How much more
    advanced it needs to be is up to you.
    */

}

// Prints out a list starting at node n
void spillList(node *n)
{
    while (n != NULL)
    {
        printf("%d: %s\n", n->student_number, n->student_initials);
        n = n->next_node;
    }
}
