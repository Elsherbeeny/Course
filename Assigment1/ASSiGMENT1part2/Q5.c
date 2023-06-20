#include<stdio.h>

void main(){

    char x;
    printf("Enter a char:");
    scanf("%c",&x);
    if(x>='a' && x<='z'){
        printf("\n char is an alphabet");
    }else{
        printf("\n char is not an alphabet");
        
    }
}