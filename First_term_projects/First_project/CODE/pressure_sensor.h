#ifndef PRESSURE_SENSOR_H_
#define PRESSURE_SENSOR_H_

#include"driver.h"
#include"state.h"

enum{
    Pressure_Sensor_Reading,
    Pressure_Sensor_Waiting
}Pressure_Sensor_State_id;


STATE_Define(Pressure_Sensor_Reading);
STATE_Define(Pressure_Sensor_Waiting);

extern void (*Pressure_Sensor_State);
#endif