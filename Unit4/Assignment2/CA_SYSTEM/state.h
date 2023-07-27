#ifndef STATE_H_
#define STATE_H_

#define STATE_Define(_stateFunc_) void ST_##_stateFunc_ ()
#define STATE(_stateFunc_) ST_##_stateFunc_

#include<stdio.h>
#include<stdlib.h>

void US_Distance_Set(int d);
void DC_Motor(int s);

#endif