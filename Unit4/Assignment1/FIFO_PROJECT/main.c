#include"FIFO.h"
#include"FIFO.c"
#include<stdio.h>
#define FIFO_LENGTH 5

FIFO_BUFFER_T FIFO_UART;

FIFO_T buf[FIFO_LENGTH],temp;


void main (){
    int i;
    if ( FIFO_INIT( &FIFO_UART , buf , FIFO_LENGTH ) == FIFO_NOERROR )
		printf ("Initialization is Done\n");

    for(i=0;i<FIFO_LENGTH;i++){
        if ( FIFO_Enqueue( &FIFO_UART , i ) == FIFO_NOERROR )
		    printf (" \nNO ERROR in Enqueue\t%d \n", i );
		else
			printf (" \tERROR in Enqueue\t%d\n", i );
    }
    for( int i=0 ; i<5 ; i++ )
	{
		if ( FIFO_Dequeue( &FIFO_UART , &temp ) == FIFO_NOERROR )
			printf (" \tNO ERROR\t%d \n" , temp );
		else
			printf ("\t ERROR in Dequeue\t %d\n" , temp );
	}




}
