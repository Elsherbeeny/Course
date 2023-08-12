#include "queue.h"

int main(void) {
	int temp;
	x buffer_controller;
	fifo_init(&buffer_controller,buffer,50);

	printf("Welcome to the Student Management System\n");
	while(1)
	{
		printf("-------------------StudentProject-------------------------\n");
		printf("Choose A number from what is shown blow\n");
		printf("1. Add the Student Details manually\n");
		printf("2. Add the Student Details from a file \n");
		printf("3. Search for student by roll number\n");
		printf("4. Search for student details by name\n");
		printf("5. Find who is enrolling in a certain course by id\n");
		printf("6. View the total number of students\n");
		printf("7. Delete a certain student by Roll number \n");
		printf("8. Update Student details by Roll number \n");
		printf("9. Show all information\n");
		printf("10. EXIT\n");
		printf(" Enter your choice to perform the task\n");
		scanf("%d",&temp);
		switch(temp)
		{
		case 1 :
		{
			add_student_manually(&buffer_controller);
			break;
		}
		case 2 :
		{
			add_student_file(&buffer_controller);
			break;
		}
		case 3 :
		{
			find_roll(&buffer_controller);
			break;
		}
		case 4 :
		{
			find_first(&buffer_controller);
			break;
		}
		case 5 :
		{
			find_course(&buffer_controller);
			break;
		}
		case 6 :
		{
			total_students(&buffer_controller);
			break;
		}
		case 7 :
		{
			delte_student(&buffer_controller);
			break;
		}
		case 8 :
		{
			update_student(&buffer_controller);
			break;
		}
		case 9 :
		{
			show_all(&buffer_controller);
			break;
		}
		case 10 :
            printf("_______OUT_______");
            exit(0);
            break;

		default :
		{
			printf("Wrong choice\n");
			break;

		}

	}
	}
}
