#include<stdio.h>
#define pi 3.14
#define area(r) pi*r*r

void main(){
    float area ,radius;
    printf("Enter the raduis:");
    scanf("%f",&radius);
    area= area(radius);
    printf("The area =%f",area);
}