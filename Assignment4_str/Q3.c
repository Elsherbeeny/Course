#include<stdio.h>

  struct Si_num{
    float real;
    float img;
}sum,x,y,temp;


struct Si_num complex(struct Si_num x,struct Si_num y,struct Si_num temp){
    temp.real=x.real+y.real;
    temp.img=x.img+y.img;
    return temp;

}

void main(){
    printf("Enter the first number \nReal:");
    scanf("%f",&x.real);
    printf("imagnire:");
    scanf("%f",&x.img);
    printf("Enter the second number \n Real");
    scanf("%f",&y.real);
    printf("imangnire:");
    scanf("%f",&y.img);
    temp=complex(x,y,sum);
    printf("the sum =%f+%fj",temp.real,temp.img);
}