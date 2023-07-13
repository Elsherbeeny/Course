#include <stdio.h>

void main (){

    float x,y,z;
    printf("Enter the value of a :");
    scanf("%f",&x);
    printf("\n Enter the value of b :");
    scanf("%f",&y);
    z=x;
    x=y;
    y=z;
    printf("After swap A=%f \n b=%f",x ,y); 
}