#ifndef _STATE_H_
#define _STATE_H_

#include<stdio.h>
#include<stdlib.h>

#define STATE_Define(_stateFun_) void ST_##_stateFun_()    
#define STATE(_stateFun_) ST_##_stateFun_


void Set_Pressure(int Pval);
void High_Pressure();
void Alarm_ON();
void Alarm_OFF();

#endif
