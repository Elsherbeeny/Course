#include<stdio.h>
#include<string.h>

void main (){
    char x[100],temp;
    int y,z=0;
    printf("Enter a sentence:");
    gets(x);
    y=strlen(x)-1;
    while(z<y){
        temp=x[z];
        x[z]=x[y];
        x[y]=temp;
        z++;
        y--;


    }
    printf("\nthe reverse is %s",x);
    


}