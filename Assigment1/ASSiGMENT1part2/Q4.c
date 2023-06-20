#include<stdio.h>

void main(){
    float x ;
    printf("Enter the NUM");
    scanf("%f",&x);
    if(x>0){
        printf("\n number is positive");

    }else if(x<0){
        printf("\n number is negative");

    }else{
        printf("\n number is zero");
    }


}