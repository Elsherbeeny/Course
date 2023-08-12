#ifndef ALARM_MONITOR_H_
#define ALARM_MONITOR_H_

#include "state.h"
#include"driver.h"
#include"stdlib.h"
#include"stdio.h"

enum {
    Alarm_Monitor_OFF,
    Alarm_Monitor_ON,
    Alarm_Monitor_Wait
}Alarm_Monitor_State_id;

STATE_Define(Alarm_Monitor_Wait);
STATE_Define(Alarm_Monitor_OFF);
STATE_Define(Alarm_Monitor_ON);

extern void (*Alarm_Monitor_State)();

#endif


