#include<stdio.h>

void main(){
    int m=29;
    printf("The address of m=%p, the value=%d\n",&m,m);
    int* pm=&m;
    printf("The address of the pointer =%p, the value=%d\n",pm,*pm);
    m=34;
    printf("The address of the pointer =%p, the value=%d\n",pm,*pm);
    *pm=7;
    printf("The address of the pointer =%p, the value=%d\n",pm,*pm);

}