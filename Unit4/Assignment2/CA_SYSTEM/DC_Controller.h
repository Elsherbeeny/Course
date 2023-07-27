#ifndef DC_Controller_H
#define DC_Controller_H


#include"state.h"

enum {
    DC_Idle,
    DC_Busy
}DC_State_Id;

void DC_INIT();
STATE_Define(DC_Idle) ;
STATE_Define(DC_Busy) ;

extern void(*DC_State)();

#endif

