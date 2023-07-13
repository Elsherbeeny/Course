#include <stdio.h>

void main(){
    char alpha[27];
    char* pointer;
    pointer=alpha;
    printf("the alphabet are:\n");
    for(int i=0;i<26;i++){
        *pointer=i+'a';
        printf("%c \t",*pointer);
        pointer++;
    }
}