#ifndef ALARM_ACT_H
#define ALARm_ACT_H


#include"state.h"
#include<stdlib.h>
#include<stdio.h>
#include"driver.h"


enum {
    Alarm_Act_OFF,
    Alarm_Act_ON
}Alarm_Act_state_id;

STATE_Define(Alarm_Act_ON);
STATE_Define(Alarm_Act_OFF);


extern void (*Alarm_Act_State)();
#endif




