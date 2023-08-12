#include"alarm_mointor.h"
#include"alarm_act.h"
#include"driver.h"
#include"stdio.h"
#include"stdlib.h"

void (*Alarm_Monitor_State)();

void High_Pressure(){
    Alarm_Monitor_State=ST_Alarm_Monitor_ON;
}

STATE_Define(Alarm_Monitor_OFF){
    Alarm_Monitor_State_id=Alarm_Monitor_OFF;

    ALarm_OFF();
    Alarm_Monitor_State=STATE(Alarm_Monitor_OFF);

}

int alarmtime=60;

STATE_Define(Alarm_Monitor_Wait){
    Alarm_Monitor_State_id=Alarm_Monitor_Wait;

    Delay(alarmtime);

    Alarm_Monitor_State=STATE(Alarm_Monitor_OFF);

}

STATE_Define(Alarm_Monitor_ON){
    Alarm_Monitor_State_id=Alarm_Monitor_ON;
    Alarm_ON();
    Alarm_Monitor_State=STATE(Alarm_Monitor_Wait);
}