#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Student90COS
{
    char student_initials[4];
    int student_number;
    struct Student90COS * next_node;
}node;

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
}
