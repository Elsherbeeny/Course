#include"lifo.h"
#include"stdio.h"
#include<stdlib.h>
#include"lifo.c"

#define LIFO_BUFFER_LENGTH 5


LIFO_BUFFER_T LIFO_UART;
LIFO_T buf[LIFO_BUFFER_LENGTH], temp;

void main (){
    LIFO_INIT(&LIFO_UART,buf,LIFO_BUFFER_LENGTH);
    int i;
    for(i=0;i<LIFO_BUFFER_LENGTH;i++){
        LIFO_PUSH(&LIFO_UART,i);
    }

    for(i=0;i<LIFO_BUFFER_LENGTH;i++){
        LIFO_POP(&LIFO_UART,&temp);
        printf("\n%d",temp);
    }



}
