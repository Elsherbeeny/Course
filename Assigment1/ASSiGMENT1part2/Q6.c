#include<stdio.h>

void main(){
    int x,y;
    printf("Enter an intger");
    scanf("%d",&x);
    for(int i=1;i<=x;i++){
        y+=i;
    }
    printf("\n the sum is %d",y);
}