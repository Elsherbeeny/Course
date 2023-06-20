#include<stdio.h>

void main(){
    char x;
    printf("Enter a char:");
    scanf("%c",&x);
    if(x == 'a'|| x=='A'|| x=='e'|| x=='E'|| x=='i'|| x=='I'|| x=='o'|| x=='O'|| x=='u'|| x=='U'){
        printf("\nthe char is vowel");
    }else{
        printf("\nthe char is consonat");
    }

}