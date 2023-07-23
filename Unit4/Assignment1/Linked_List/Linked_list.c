#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include "Linked_list.h"
#include <string.h>
#include<math.h>


Student_t* p_NewStudent     = NULL ;
Student_t* p_FirstStudent   = NULL ;
Student_t* p_LastStudent    = NULL ;
Student_t* p_PrevStudent    = NULL ;
Student_t* p_CurrentStudent = NULL ;
Student_t* p_NextStudent    = NULL ;


uint8_t temp[40];
uint32_t length;

int Get_length (struct Student* ptr){
    if(ptr){
        return 1+Get_length(ptr->gp_next_student);
    }else{
    return 0;
    }
}

Status Fill_student(struct Student* ptr){
    printf("Enter the student ID:");
    gets(temp);
    p_NewStudent->DATA.id=atoi(temp);
    printf("\nEnter the student Name:");
    gets(p_NewStudent->DATA.name);
    printf("\n Enter the student height:");
    gets(temp);
    p_NewStudent->DATA.height=atof(temp);

    printf("________________________\n");
}

Status Add_Student()
{
	//allocate new record in the heap
	p_NewStudent = (Student_t*) malloc(sizeof(Student_t));
	//check if malloc() isn't succeeded
	if (!p_NewStudent)
	{
		printf("error");
		return Error ;
	}

	
	if (!p_FirstStudent){
		p_FirstStudent = p_NewStudent;
        }
	else 
	{
		//Navigate last student
		p_LastStudent = p_FirstStudent;
		while(p_LastStudent->gp_next_student){
			p_LastStudent = p_LastStudent->gp_next_student;
        }
		p_LastStudent->gp_next_student = p_NewStudent;
    }
	p_LastStudent = p_NewStudent;

    Fill_student(p_NewStudent);
    p_NewStudent->gp_next_student=NULL;
    length++;
    return No_error;
}

Status Delete_Student(){
    printf("\nEnter the student ID:");
    gets(temp);
    p_CurrentStudent=p_FirstStudent;
      //empty
      if (p_FirstStudent == NULL)
    	printf("list is empty\n");
    //not empty
    if(p_FirstStudent){
        //if the id was for the first one
        if(p_FirstStudent->DATA.id==atoi(temp)){
            p_FirstStudent=p_FirstStudent->gp_next_student;
            free(p_CurrentStudent->gp_next_student);
        }else{
            while(p_CurrentStudent->DATA.id!=atoi(temp)){
                if(!p_CurrentStudent){
                    printf("\n the ID wasn't found");
                    printf("_______________________");
                    return Error;
                }
                p_PrevStudent=p_CurrentStudent;
                p_CurrentStudent=p_CurrentStudent->gp_next_student;

            }
            if(!p_CurrentStudent->gp_next_student){
                p_PrevStudent->gp_next_student=NULL;

            }else{
                p_PrevStudent->gp_next_student=p_CurrentStudent->gp_next_student;
                free(p_CurrentStudent);
            }
        }
    }
    length--;
    printf("\n__________________________");
    return No_error;
   
    
}
Status View_Student (){

uint32_t count = 0 ;

	p_CurrentStudent = p_FirstStudent;

	if (p_FirstStudent == NULL)
	{
		printf("list is empty\n");
		printf("_________________________________  \n");
		return Empty;
	}

	printf("Students are\n");
	while (p_CurrentStudent)
	{
		printf("Record number %d\n",count+1);
		printf("\tID    : %d\n",p_CurrentStudent->DATA.id);
		printf("\tName  : %s\n",p_CurrentStudent->DATA.name);
		printf("\tHeight: %f\n",p_CurrentStudent->DATA.height);

		p_CurrentStudent = p_CurrentStudent->gp_next_student;
		count++;
	}
	printf("_________________________________  \n");
	return Sucsses ;
}

Status Delete_All (){
    if(!p_FirstStudent){
        printf("\nthe list is empty:");
        return Error;
    }else{
        p_CurrentStudent=p_FirstStudent;
        while(p_CurrentStudent)
        {
            p_CurrentStudent=p_FirstStudent->gp_next_student;
            free(p_FirstStudent->gp_next_student);
            p_FirstStudent=p_CurrentStudent;

        }
        printf("__________List is empty____________");
        length=0;
        return Sucsses;
    }
}

Status Get_Nth_NODE_First (){
    printf("Enter the index:\n");
    gets(temp);
    uint32_t count=0;
    if(p_FirstStudent ==NULL){
        printf("list is empty");
        printf("________________");
    }

    if(atoi(temp)>length-1){
        printf("The index is not found");
        printf("_____________________");
        return Sucsses;
    }
    p_CurrentStudent=p_FirstStudent;
    while (atoi(temp)!=count)
    {
        p_CurrentStudent=p_CurrentStudent->gp_next_student;
        count++;
    }
    printf("Record student of index %d\n",atoi(temp));
    printf("\tID  %d\n",p_CurrentStudent->DATA.id);
    printf("\t Name:%s \n",p_CurrentStudent->DATA.name);
    printf("\t Height:%f",p_CurrentStudent->DATA.height);
    printf("\n________________________");
    return Sucsses;
}
Status Get_Nth_NODE_End ()
{
	//get index of student to view
	printf("Enter his index(end): \n");
	gets(temp);

	uint32_t count = 0;
	//list is empty
	if (p_FirstStudent == NULL) {
		printf("list is empty\n");
		printf("_________________________________  \n");
		return Empty;
	}

	//check if that index exists or not
	if (atoi(temp) > length) {
		printf("This index not found\n");
		printf("_________________________________  \n");
		return Sucsses;
	}

	//set direction pointer
	p_CurrentStudent = p_FirstStudent;
	while (atoi(temp) != (length-count))
	{
		//Go to next student
		p_CurrentStudent = p_CurrentStudent->gp_next_student;
		count++;
	}

	printf("Record Student of index %d\n", atoi(temp));
	printf("\tID    : %d\n", p_CurrentStudent->DATA.id);
	printf("\tName  : %s\n", p_CurrentStudent->DATA.name);
	printf("\tHeight: %f\n", p_CurrentStudent->DATA.height);
	printf("_________________________________  \n");

	return Sucsses;
}

Status Find_Middle()
{
	uint32_t mid = floor((length / 2));
	uint32_t count = 0;


	p_CurrentStudent = p_FirstStudent;
	while (mid != count)
	{

		p_CurrentStudent = p_CurrentStudent->gp_next_student;
		count++;
	}
	printf("Record Student of index %d\n", count);
	printf("\tID    : %d\n", p_CurrentStudent->DATA.id);
	printf("\tName  : %s\n", p_CurrentStudent->DATA.name);
	printf("\tHeight: %f\n", p_CurrentStudent->DATA.height);
	printf("_________________________________  \n");

	return Sucsses ;
}


Status Reverse (){
    p_PrevStudent=NULL;
    p_CurrentStudent=p_FirstStudent;
    p_NextStudent=p_CurrentStudent->gp_next_student;
    while(p_CurrentStudent){
        if(p_CurrentStudent==p_FirstStudent)
        p_LastStudent=p_FirstStudent;


        p_NextStudent = p_CurrentStudent->gp_next_student;
		p_CurrentStudent->gp_next_student = p_PrevStudent;
		p_PrevStudent = p_CurrentStudent;
		p_CurrentStudent = p_NextStudent;

	}
	
	p_FirstStudent = p_PrevStudent;
	
	View_Student();

	return No_error;
}
    



