#include <stdio.h>
void reverse_sent();
void main (){
    char n[100];
    printf("enter a sentence :");
    reverse_sent();
   

}
void reverse_sent(){
    char x;
    scanf("%c",&x);
    if(x !='\n'){
        reverse_sent();
        printf("%c",x);
    }

}
