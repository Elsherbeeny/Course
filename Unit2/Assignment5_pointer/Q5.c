#include<stdio.h>

struct employee{
    char* empname;
    int empid;
};
void main(){
    static struct employee emp1={"john",1001},emp2={"alex",1002},emp3={"hamo",1003};
    struct employee (*arr[])={&emp1,&emp2,&emp3};
    struct employee (*(*ptr)[3])=&arr;

    printf("Employee name :%s\n",(**(*ptr+1)).empname);
    printf("\nEmployee id =%d",(*(*ptr+1))->empid);

}