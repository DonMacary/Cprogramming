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
void popList(node ** head);


int main(void)
{
    node * HEAD = (node*)malloc(sizeof(node));  //head
    node * MQT18_01_S2 = (node*)malloc(sizeof(node));
    node * MQT18_01_S3 = (node*)malloc(sizeof(node));  //tail

    //head
    strcpy(HEAD->student_initials, "LOL");
    HEAD->student_number = 1;
    HEAD->next_node = MQT18_01_S2;

    //node2
    strcpy(MQT18_01_S2->student_initials, "KAY");
    MQT18_01_S2->student_number = 2;
    MQT18_01_S2->next_node = MQT18_01_S3;

    //tail
    strcpy(MQT18_01_S3->student_initials, "YAY");
    MQT18_01_S3->student_number = 3;
    MQT18_01_S3->next_node = NULL;


    spillList(HEAD);


    // ################ POPPING NODE WITH HEAD VAR NAME ################
    printf("\n\nPopping Node\n");

    popList(&HEAD); // popList takes a double pointer to head as an argument
    spillList(HEAD);

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

// Removes the head node and reasigns it to next
void popList(node ** head)
{
    node * next_node = NULL;

    next_node = (*head)->next_node;
    free(*head);
    *head = next_node;
}
