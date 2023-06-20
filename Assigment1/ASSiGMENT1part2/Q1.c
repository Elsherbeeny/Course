#include<stdio.h>

void main(){
    int x;
    printf("Enter the number you want to check :");
    scanf("%d",&x);
    if(x%2 ==0){
        printf("\nThe number is even");
    }else{
        printf("\nThe number is odd ");
    }
    
}