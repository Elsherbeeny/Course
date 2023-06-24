#include <stdio.h>

void main(){
    int x[20], element, location , num;
    printf("Enter the number of elements from 0 to 20:");
    scanf("%d",&num);
    if(num>20){
        printf("\n Error please enter a number less than 20");
        scanf("%d",&num);
    }
    for(int i=0;i <num; i++){
        x[i]=i+1;
        printf("%d\t",x[i]);
    }
    printf("\n enter the number the will be inserted:");
    scanf("%d",&element);
    printf("\n enter the location:\n");
    scanf("%d",&location);
    for (int i=num;i>=location;i--){
        x[i]=x[i-1];
    }
    num++;
    x[location-1]=element;
    for(int i=0;i<num;i++){
        printf("%d\t",x[i]);
    }




}