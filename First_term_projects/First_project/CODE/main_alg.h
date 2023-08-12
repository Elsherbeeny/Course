#ifndef MAIN_ALG_H_
#define MAIN_ALG_H_

#include"state.h"
#include"driver.h"

enum {
    Main_Alg_High,
    Main_Alg_Not_High
}Main_Alg_State_id;

STATE_Define(Main_Alg_High);
STATE_Define(Main_Alg_Not_High);

extern void(*Main_Alg_State)();
#endif