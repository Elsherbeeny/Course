#include <stdint.h>
#include <stdio.h>

#include "driver.h"
#include"state.h"
#include"pressure_sensor.h"
#include"alarm_act.h"
#include"alarm_mointor.h"
#include"main_alg.h"





void setup () 
{

    GPIO_INITIALIZATION(); 
	
	
	Pressure_Sensor_State =STATE(Pressure_Sensor_Reading);
	Main_Alg_State =STATE(Main_Alg_Not_High);
	Alarm_Act_State =STATE(Alarm_Act_OFF);
	Alarm_Monitor_State =STATE(Alarm_Monitor_OFF);
   
}

	


int main (){
	setup();
	GPIO_INITIALIZATION();

	
	while (1)
	{
		//Implement your Design
		void (*Pressure_Sensor_State)();
		Main_Alg_State();
		Alarm_Monitor_State();
		Alarm_Act_State(); 
		Delay(10);
	}

}
