#include "US_Sensor.h"

extern void (*US_State)();

unsigned int distance;

int gentrate_random(int l,int r,int count){
    int i;
    for(i=0;i<count;i++){
        int rand_num =(rand()%(r-l+1))+1;
        return rand_num;
    }

}

void US_INIT(){
    printf("US_Init\n");
}

STATE_Define(US_Busy) {
    US_State_Id =US_Busy;

    distance= gentrate_random(45,55,1);

    printf("US_State_busy  : distance=%n",distance);

    US_Distance_Set(distance);
    US_State= STATE(US_Busy);

}


