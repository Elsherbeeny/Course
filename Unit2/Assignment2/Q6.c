#include <stdio.h>
#include<string.h>

void main (){
    char sent[100],charchater;
    int count=0;
    printf("Enter a sentence:");
    gets(sent);
    printf("\nEnter the charchater you want to check :");
    scanf("%c",&charchater);
    for(int i=0;sent[i]!='\0';i++){
        if(charchater==sent[i]){
            count++;
        }
    }
    printf("\n the frequency of the char %c is %d",charchater,count);

}