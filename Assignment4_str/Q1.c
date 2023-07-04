#include<stdio.h>

struct Sstudent {
    char Sstudent_name [50];
    int Sstudent_roll;
    float Sstudent_marks;
}student;

void print_student(struct Sstudent x){
    printf("The student information is :\n Name:%s \tRollnumber:%d \tMarks:%f",x.Sstudent_name,x.Sstudent_roll,x.Sstudent_marks);

}

void main(){
    printf("Enter student name :");
    gets(student.Sstudent_name);
    printf("\n Enter student roll number:");
    scanf("%d",&student.Sstudent_roll);
    printf("\nEnter student Marks:");
    scanf("%f",&student.Sstudent_marks);
    print_student(student);


}