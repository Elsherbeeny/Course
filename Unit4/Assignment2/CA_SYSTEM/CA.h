#ifndef CA_DEF_H
#define CA_DEF_H

#include "state.h"

enum{
    CA_Waiting,
    CA_Driving

}CA_State_Id;

STATE_Define(CA_Waiting);
STATE_Define(CA_Driving);

extern void (*CA_State)();
#endif