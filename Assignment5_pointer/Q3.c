#include<stdio.h>

void main(){
    char string[50], reverse[50];
    char *str=string,*rev=reverse;
    int i=-1;
    printf("Enter the string u want to reverse:");
    gets(string);
    while(str){
        str++;
        i++;
    }while(i>=0){
        str--;
        *rev=*str;
        rev++;
        --i;

    }
    *rev='\0';
    printf("\n the reverse string:%s",rev);
}