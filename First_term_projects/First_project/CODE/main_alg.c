#include"main_alg.h"
#include"driver.h"

void (*Main_Alg_State)();

int Main_Pval=0;
int Main_Threshold=20;

void Set_Pressure(int Pval){
    if(Pval>Main_Threshold){
        Main_Alg_State=STATE(Main_Alg_High);
    }else{
        Main_Alg_State=STATE(Main_Alg_Not_High);
    }
}

STATE_Define(Main_Alg_High){
    Main_Alg_State_id=Main_Alg_High;

    High_Pressure();
    Main_Pval=getPressureVal();
    Set_Pressure(Main_Pval);
}

STATE_Define(Main_Alg_Not_High){
    Main_Alg_State_id=Main_Alg_Not_High;
    Main_Pval=getPressureVal();
    Set_Pressure(Main_Pval);
}
