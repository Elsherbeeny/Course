#include<uart.h>

#define UART0DR *((volatile unsigned int* const) (unsigned int *)0x101f1000)

void UART_Send_String(unsigned char* PX_String){
    while(PX_String!='\0'){
        UART0DR=(unsigned int*) PX_String;
        PX_String++;

    }
}