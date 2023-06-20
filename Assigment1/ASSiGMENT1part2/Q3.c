#include<stdio.h>

void main(){
    float x,y,z;
    printf("Enter 3 numbers");
    scanf("%f%f%f",&x,&y,&z);
    if(x>y && x>z){
        printf("\n The largest number is %f",x);
    }else if(y>x && y>z){
        printf("\n The largest number is %f",y);
    }else{
        printf("\n The largest number is %f",z);
    }


}