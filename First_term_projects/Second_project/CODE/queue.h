#ifndef QUEUE_H_
#define QuEUE_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    char first_name[50];
    char last_name[50];
    int roll_number;
    float gpa;
    int coure_id[10];
}student_info;
student_info buffer[50];

typedef struct{
	student_info *head;
	student_info *tail;
	student_info *base;
	int counter;
	int length;
} x;

typedef enum{
    fifo_no_error,
    fifo_full,
    fifo_empty,
    fifo_null,
    fifo_error
}fifo_buffer_state;


int check_roll(x*fifo,int x);
fifo_buffer_state fifo_init(x*fifo,student_info* buffer,int length);
fifo_buffer_state add_student_file(x*fifo);
fifo_buffer_state add_student_manually(x*fifo);
fifo_buffer_state find_roll(x*fifo);
fifo_buffer_state find_first(x*fifo);
fifo_buffer_state find_course(x*fifo);
fifo_buffer_state total_students(x*fifo);
fifo_buffer_state delte_student(x*fifo);
fifo_buffer_state shift_buffer(int index,x*fifo);
fifo_buffer_state update_student(x*fifo);
fifo_buffer_state show_all(x*fifo);








#endif // QUEUE_H_
