#include<stdio.h>

struct Sstudent{
    char name[50];
    int roll;
    float marks;
};
void main(){
   struct Sstudent x[10];
   printf("Student informantion please\n");
   //taking the student information
   for(int i=0;i<10;i++){
    printf("Enter name for student %d:",i+1);
    gets(x[i].name);
    printf("Enter roll marks for student %d:",i+1);
    scanf("%d",&x[i].roll);
    printf("Enter the marks for student %d",i+1);
    scanf("%f",&x[i].marks);

   }
   //printing the student informations
   for(int i=0;i<10;i++){
    printf("Student NO.%d",i+1);
    printf("Name:%s\nRollMarks:%d\nMarks:%.2f",x[i].name,x[i].roll,x[i].marks);
   }

}