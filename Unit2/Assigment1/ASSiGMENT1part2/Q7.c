#include<stdio.h>

void main(){
    int x,y=1;
    printf("Enter int");
    scanf("%d",&x);
    if(x>=0){
        for(int i=1;i<=x;i++){
            y=y*i;
        }
        printf("\n factorial =%d",y);
    }else{
        printf("\n negative numbers doesnot have factorial");
    }

}