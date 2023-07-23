
#include"Linked_list.c"
int main()
{
	
	

	uint8_t option_num[10];

	while (1)
	{
        printf("Choose an Option from list to do:  \n");
	    printf("_________________________________  \n");
	    printf("1 : Add student                   \n");
	    printf("2 : Delete student                \n");
	    printf("3 : view students                 \n");
	    printf("4 : Delete all                    \n");
	    printf("5 : Get Nth of node from the first\n");
	    printf("6 : Get Nth of node from the end  \n");
	    printf("7 : Find the middle               \n");
	    printf("8: Reverse                       \n");
	    printf("_________________________________  \n");
		printf("Enter an option: ");
		gets(option_num);

		//switching an option
		switch (atoi(option_num)) {
		case 1:
			Add_Student();
			break;
		case 2:
			Delete_Student();
			break;
		case 3:
			View_Student();
			break;
		case 4:
			Delete_All();
			break;
		case 5:
			Get_Nth_NODE_First ();
			break;
		case 6:
			Get_Nth_NODE_End ();
			break;
		case 7:
			Find_Middle();
			break;
		case 8:
			Reverse();
			break;
		default:
			printf("Wrong Option\n");
			break;
		}
	}
}