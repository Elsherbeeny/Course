#include<stdio.h>
#include<stdlib.h>
#include"DC_Controller.h"

extern void (*DC_State) ();
unsigned int speed;
void DC_INIT(){
    printf("DC_INIT\n");
}

void DC_Motor(int s){
    speed=s;
    DC_State =STATE(DC_Busy);
    printf("CA--------->DC     DC_Motor()\n");

}
void ST_DC_Idle() {
    DC_State_Id = DC_Idle;
    DC_State =STATE(DC_Idle);
}

void ST_DC_Busy() {
    
    DC_State_Id=DC_Busy;
    DC_State = STATE(DC_Busy);

    printf("NOW______DC_Busy____ Speed=%d\n",speed);
}