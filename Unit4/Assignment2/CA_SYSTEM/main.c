#include "CA.h"
#include "US_Sensor.h"
#include "DC_Controller.h"

void setup(){
     US_INIT();
     DC_INIT();

    CA_State=STATE(CA_Waiting);
    US_State=STATE(US_Busy);
    DC_State=STATE(DC_Idle);
}

void main(){
    volatile int d;
    setup();
    while(1){
        US_State();
        CA_State();
        DC_State();
    }
}
