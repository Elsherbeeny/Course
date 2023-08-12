#include"alarm_act.h"
#include"stdio.h"
#include"stdlib.h"

void (*Alarm_Act_State)();

void Alarm_ON(){
    Alarm_Act_State=STATE(Alarm_Act_ON);
    
}
void ALarm_OFF(){
    Alarm_Act_State=STATE(Alarm_Act_OFF);
}

STATE_Define(Alarm_Act_OFF) {
    Alarm_Act_state_id=Alarm_Act_OFF;
    Set_Alarm_actuator(1);

}
STATE_Define(Alarm_Act_ON){
    Alarm_Act_state_id=Alarm_Act_ON;
    Set_Alarm_actuator(0);
}

