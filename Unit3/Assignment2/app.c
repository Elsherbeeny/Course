#include"uart.h"
unsigned char STRING[100]="Learn-IN-Depth->Ahmed";
void main(){
    UART_Send_String(STRING);

}