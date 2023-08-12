#include"pressure_sensor.h"
#include"driver.h"
#include"state.h"

void (*Pressure_Sensor_State);

int Pval=0;
int Pull_timer=100;

STATE_Define(Pressure_Sensor_Reading){
    Pressure_Sensor_State_id=Pressure_Sensor_Reading;

    Pval=getPressureVal();
    Set_Pressure(Pval);
    Pressure_Sensor_State-Pressure_Sensor_Waiting;


}

STATE_Define(Pressure_Sensor_Waiting){
    Pressure_Sensor_State_id-Pressure_Sensor_Waiting;
    Delay(Pull_timer);
    Pressure_Sensor_State=Pressure_Sensor_Reading;
}