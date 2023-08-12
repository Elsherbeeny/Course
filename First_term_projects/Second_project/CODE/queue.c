#include"queue.h"

fifo_buffer_state fifo_init(x*fifo,student_info* buffer,int length){
    if(!fifo ||!buffer){
        return fifo_null;
    }
    fifo->base=buffer;
    fifo->head=buffer;
    fifo->tail=buffer;
    fifo->length=length;
    fifo->counter=0;
    return fifo_no_error;


}
int check_roll(x*fifo,int x){
    int y;
    student_info *ptr=fifo->base;

    for(y=0;y<fifo->counter;y++){
        if(ptr->roll_number==x){
            return 0;
        }
        ptr++;
    }
    return 1;
}

fifo_buffer_state add_student_file(x*fifo){
    char fname[50];
    char lname[50];
    int roll_num ,cid[5],x;
    int file_count=0,flag=0;
    float GPA;
    int line=0;

    if(!fifo->base || !fifo->head || !fifo->tail ){
        printf("____________NO DATA_______\n");
        return fifo_null;

    }
    if(fifo->counter==fifo->length)
	{
		printf("________FULL______\n");
		return fifo_full;
}
FILE *p_file=fopen("data.txt","r");
if(p_file==NULL){
    printf("_______File not found_______\n");
    return fifo_error;
    }


while(fscanf(p_file,"%d %s %s %f %d %d %d %d %d [^\n]",&roll_num,fname,lname,&GPA,&cid[0],&cid[1],&cid[2],&cid[3],&cid[4])!=EOF)
{
    if(fifo->counter==fifo->length){
        printf("______________FULL DATA BASE_____________\n");
        return fifo_full;
    }
    if(check_roll(fifo,roll_num)==0)
		{
			printf("Roll Number is already taken before \n");
			line++;
			continue;
		}
		fifo->head->roll_number=roll_num;
		fifo->head->gpa=GPA;
		strcpy(fifo->head->first_name,fname);
		strcpy(fifo->head->last_name,lname);
		for(x=0;x<5;x++)
		{
			flag=0;
			if(cid[x]<0 || cid[x]>30)

			{
				flag=1;
				break;
			}
			fifo->head->coure_id[x]=cid[x];
		}
		if(flag==1) //invalid
		{
			printf("non valid course id we will skip this student \n");
			line++;
			continue;
		}
		fifo->head++;
		fifo->counter++;
		line++;
		file_count++;
}

printf("_______FILE END______\n");

fclose(p_file);
printf("____%d Students are successfully added ____ ",file_count);
return fifo_no_error;



}
fifo_buffer_state add_student_manually(x*fifo){
 int temp_int,y, x;
char temp_str[30];
   if(!fifo->base || !fifo->head || !fifo->tail ){
        printf("____________NO DATA_______\n");
        return fifo_null;

    }
if(fifo->counter==fifo->length)
{
	printf("___________FULL______________\n");
	return fifo_full;
}
printf("Add Student Details \n");

printf("Enter the Roll Number \n");
scanf("%d",&temp_int);

if(check_roll(fifo,temp_int)==0)
{
	printf("Roll Number is already in use \n");
	return fifo_error;
}
fifo->head->roll_number = temp_int;

printf("Enter First name of the student:\n");
scanf("%s",fifo->head->first_name);

printf("Enter Last name of the student:\n");

scanf("%s",fifo->head->last_name);
printf("Enter the GPA you obtained\n");

scanf("%s",temp_str);
fifo->head->gpa=atof(temp_str);
printf("Enter the courses id \n");
for(x=0;x<5;x++)
{
	printf("course %d id :\n",x+1);
	scanf("%s",temp_str);
	y=atoi(temp_str);
	if(y>0 && y<30)              // check avalablity;
	{
		fifo->head->coure_id[x]=y;
		continue;
	}
	printf("Course ID is wrong\n");
	x--;
}
fifo->head++;
fifo->counter++;
printf("Student Details are added successfully \n");
printf("the total number of students is : %d\n",fifo->counter);
printf("you can add up to %d students \n",fifo->length);
printf("you can add more about %d students \n",fifo->length - fifo->counter);

return fifo_no_error;
}

fifo_buffer_state find_roll(x*fifo){
    char temp_str[30];
    int temp_roll;
    student_info* current=fifo->base;
    int x,y;
   if(!fifo->base || !fifo->head || !fifo->tail ){
        printf("____________NO DATA_______\n");
        return fifo_null;

    }
if(fifo->counter==0)         // check if is empty
{
	printf("___________EMPTY___________\n");
	return fifo_empty;
}

printf("Enter student roll number\n");
scanf("%s",temp_str);
temp_roll=atoi(temp_str);

for(x=0;x<fifo->counter;x++){
    if(current->roll_number==temp_roll){
        printf("Stundet's roll number is %d \n",current->roll_number);
        printf("Student first name is %s\n",current->first_name);
        printf("Student Last name is %s\n",current->last_name);
        printf("Student GPA is %f \n",current->gpa);
        for(y=0;y<5;y++){
            printf("enrolled    course %d\n",current->coure_id[y]);
        }
        return fifo_no_error;
    }
    current++;
}
printf("The number you entered is not found\n");
return fifo_error;

}




fifo_buffer_state find_first(x*fifo){
  char temp_str[30];
    int flag=0;
    student_info* current =fifo->base;
    int x,y;
   if(!fifo->base || !fifo->head || !fifo->tail ){
        printf("____________NO DATA_______\n");
        return fifo_null;

    }
if(fifo->counter==0)         // check if is empty
{
	printf("___________EMPTY___________\n");
	return fifo_empty;
}
printf("Enter the Name\n");
scanf("%s",temp_str);
for(x=0;x<fifo->counter;x++){
        if(strcmpi(current->first_name,temp_str)==0){
            printf("Student Roll number is %d\n",current->roll_number);
            printf("Student last name is %s\n",current->last_name);
            printf("Student GPA is %.2f \n",current->gpa);
            for(y=0;y<5;y++){
       printf("enrolled    course %d\n",current->coure_id[y]);
        }
        flag=1;
        }
current++;

}
if (flag==0){
    printf("__________Name was not found_____________\n");
    return fifo_error;
}
return fifo_no_error;
}
fifo_buffer_state find_course(x*fifo){
     char temp_str[30];
     int temp_course_id;
    int flag=0;
    student_info* current =fifo->base;
    int x,y,z;
     if(!fifo->base || !fifo->head || !fifo->tail ){
        printf("____________NO DATA_______\n");
        return fifo_null;

    }
if(fifo->counter==0)         // check if is empty
{
	printf("___________EMPTY___________\n");
	return fifo_empty;
}
printf("Enter Course id \n");
scanf("%s",temp_str);
temp_course_id=atoi(temp_str);
for(x=0;x<fifo->counter;x++){
    for(z=0;z<5;z++){
        if(current->coure_id[z]==temp_course_id){
            printf("Student Roll number is %d\n",current->roll_number);
            printf("Student last name is %s\n",current->last_name);
            printf("Student GPA is %.2f \n",current->gpa);
            for(y=0;y<5;y++){
       printf("enrolled    course %d\n",current->coure_id[y]);
            }
       flag=1;

        }

    }
    current++;
}
if(flag==0){
    printf("________NO Students found________");
    return fifo_error;
}
    return fifo_no_error;
}
fifo_buffer_state total_students(x*fifo){
    if(!fifo->base || !fifo->head || !fifo->tail ){
        printf("____________NO DATA_______\n");
        return fifo_null;

    }
    if(fifo->counter==0)         // check if is empty
    {
	printf("___________EMPTY___________\n");
	return fifo_empty;
    }
    printf("The Total number of students is %d\n",fifo->counter);
    printf("You can still add up to %d\n",fifo->length);
    printf("%d Students until full\n",fifo->length-fifo->counter);
    return fifo_no_error;
}
fifo_buffer_state delte_student(x*fifo){
char temp_str[30];
    int temp_roll,index=0;
    student_info* current =fifo->base;
    int x,y;
   if(!fifo->base || !fifo->head || !fifo->tail ){
        printf("____________NO DATA_______\n");
        return fifo_null;

    }
if(fifo->counter==0)         // check if is empty
{
	printf("___________EMPTY___________\n");
	return fifo_empty;
}
printf("Enter The Student Roll number you want to delete\n");
scanf("%s",temp_str);
temp_roll=atoi(temp_str);
for(x=0;x<fifo->counter;x++){
    if(current->roll_number==temp_roll){
        printf("Stundet's roll number is %d \n",current->roll_number);
        printf("Student first name is %s\n",current->first_name);
        printf("Student Last name is %s\n",current->last_name);
        printf("Student GPA is %f \n",current->gpa);
        for(y=0;y<5;y++){
            printf("enrolled    course %d\n",current->coure_id[y]);
        }
        printf("Are you sure you want to delete press 1 for yes and 2 for no\n");
        scanf("%s",temp_str);
        temp_roll=atoi(temp_str);
        if(temp_roll==1){
            shift_buffer(index,fifo);
            fifo->head--;
            fifo->counter--;
            return fifo_no_error;

        }else if(temp_roll==2){
        printf("__________________Process cancle_______________\n");
        return fifo_no_error;
        }else{
        printf("______________Wrong Choice____________\n");
        return fifo_no_error;
        }

    }
    current++;
    index++;

}
printf("________________NOT FOUND_______________\n");
return fifo_error;


}
fifo_buffer_state shift_buffer(int index,x*fifo){
int x;
for(x=index;x<fifo->counter;x++){
    buffer[x]=buffer[x+1];

}
printf("_____________Deleted SUCCSESFULLY___________________\n");
return fifo_no_error;
}

fifo_buffer_state update_student(x*fifo){ //by role number
         char temp_str[30];
     int temp_roll;
     int temp_opt;
    student_info* current =fifo->base;
    int x,y,z,w;
     if(!fifo->base || !fifo->head || !fifo->tail ){
        printf("____________NO DATA_______\n");
        return fifo_null;

    }
if(fifo->counter==0)         // check if is empty
{
	printf("___________EMPTY___________\n");
	return fifo_empty;
}
printf("Enter Student roll number \n");
scanf("%s",temp_str);
temp_roll=atoi (temp_str);

for(x=0;x<fifo->counter;x++){
    if(current->roll_number==temp_roll){
        printf("Stundet's roll number is %d \n",current->roll_number);
        printf("Student first name is %s\n",current->first_name);
        printf("Student Last name is %s\n",current->last_name);
        printf("Student GPA is %f \n",current->gpa);
        for(y=0;y<5;y++){
            printf("enrolled    course %d\n",current->coure_id[y]);
        }
        printf("Enter the data you want to update\n");
        printf("1. first name\n");
        printf("2. last name\n");
        printf("3. GPA\n");
        printf("4. Course ID");
        scanf("%s",temp_str);
        temp_opt = atoi(temp_str);
        switch (temp_opt){

        case 1: {
        printf("Enter the new first name\n");
        scanf("%s",current->first_name);
        break;
        }
        case 2:{
        printf("Enter the new last name \n");
        scanf("%s",current->last_name);
        break;
        }
        case 3:{
        printf("Enter the new GPA\n");
        scanf("%s",temp_str);
        current->gpa=atof(temp_str);
        break;

        }case 4:{
        printf("Enter the new courses ID\n");
        for(z=0;z<5;z++){
            printf("course %d id :\n",z+1);
            scanf("%s",temp_str);
            w=atoi(temp_str);
            if(w>0 && w<30){
                current->coure_id[z]=w;
                continue;
            }
            printf("Course id isn't correct\n");
            z--;
        }
        break;
        }
        default :{
            printf("_______________________Wrong Choice__________________\n");
            return fifo_error;

        }
        }
        printf("Information updated succesfully \n");

        return fifo_no_error;

}
    current++;
}
        printf("_________________NOT FOUND ____________________\n");
    return fifo_error;
    }

    fifo_buffer_state show_all(x*fifo){
         student_info* current =fifo->base;
    int x,y;
   if(!fifo->base || !fifo->head || !fifo->tail ){
        printf("____________NO DATA_______\n");
        return fifo_null;

    }
if(fifo->counter==0)         // check if is empty
{
	printf("___________EMPTY___________\n");
	return fifo_empty;
}
for(x=0;x<fifo->counter;x++){
            printf("Student Roll number is %d\n",current->roll_number);
            printf("Student First name is %s\n",current->first_name);
            printf("Student last name is %s\n",current->last_name);
            printf("Student GPA is %.2f \n",current->gpa);
            for(y=0;y<5;y++){
       printf("enrolled    course %d\n",current->coure_id[y]);
        }
        current++;
    }
    printf("Total number of students %d\n",fifo->counter);
    return fifo_no_error;
    }












