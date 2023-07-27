#include "CA.h"

int CA_Speed =0;
int CA_Distance =0;
int CA_therhold =50;

void (*CA_State)();

void US_Distance_Set(int d){
    CA_Distance =d;
    (CA_Distance <=CA_therhold) ? (CA_State=STATE(CA_Waiting)):(CA_State=STATE(CA_Driving));
    printf("__________distance%d_________\n",CA_Distance);

}
STATE_Define(CA_Waiting) {

    CA_State_Id = CA_Waiting;
    printf("NOW______CA-waiting_________Distance=%d_____speed%d_____\n",CA_Distance,CA_Speed);

    CA_Speed=0;
    DC_Motor(CA_Speed);   
}


STATE_Define(CA_Driving){

    CA_State_Id = CA_Driving;
    printf("NOW_____CA-Driving_____Distance%d_____speed%d______",CA_Distance,CA_Speed);
    CA_Speed=30;
    DC_Motor(CA_Speed);
}