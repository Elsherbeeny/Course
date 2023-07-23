#ifndef LINKED_LISt_H
#define LINKED_LIST_H

#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

struct Sdata {
    uint32_t id;
    uint8_t name[40];
    float height;
};
typedef struct Student
{
    struct Sdata DATA;
    struct Student* gp_next_student;
    
}Student_t;

typedef enum{
    Sucsses,
    Error,
    No_error,
    Empty
}Status;

int Get_length (struct Student* ptr);
Status Fill_student(struct Student* ptr);

Status Add_Student ();
Status Delete_Student ();
Status View_Student ();
Status Delete_All ();
Status Get_Nth_NODE_First ();
Status Get_Nth_NODE_End ();
Status Find_Middle ();
Status Reverse ();

#endif
