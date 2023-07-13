#include<stdio.h>

void main(){
    char s[100];
    int count=0;
    printf("Enter the string:");
    gets(s);
    for(int i=0;s[i]!='\0';i++){
        count++;
    }
    printf("\n the number of char is %d",count);
}