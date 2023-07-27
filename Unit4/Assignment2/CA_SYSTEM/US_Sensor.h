#ifndef US_Sensor_
#define US_Sensor_

#include "state.h"


enum{
    US_Busy
}US_State_Id;

void US_INIT();
STATE_Define (US_Busy);

void(*US_State)();

#endif
