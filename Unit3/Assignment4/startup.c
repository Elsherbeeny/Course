#include<stdint.h>

#define STACK_Start_SP 0x20001000
extern uint64_t _stack_top;
extern int main(void);
void Rest_Handler(void);
void Default_Handler(){
	Rest_Handler();
}
void NMI_Handler ()__attribute__ ((weak ,alias("Default_Handler")));
void H_Fault_Handler ()__attribute__ ((weak ,alias("Default_Handler")));
static unsigned long Stack_top[256];

void (* const g_p_fn_Vectors[])() __attribute__ ((section(".vectors")))=
{
(void (*)())  ((unsigned long)Stack_top +sizeof(Stack_top)),
&Rest_Handler,
&NMI_Handler,
&H_Fault_Handler
};

extern unsigned int _S_DATA;
extern unsigned int _E_DATA;
extern unsigned int _E_BSS;
extern unsigned int _S_BSS;
extern unsigned int _E_TEXT;

void Rest_Handler(void){
	unsigned int DATA_size = (unsigned char *)&_E_DATA-(unsigned char *)&_S_DATA;
	unsigned char* P_src = (unsigned char*) &_E_TEXT;
	unsigned char* P_dst = (unsigned char*) &_S_DATA;
	int i;
	for (i=0;i<DATA_size;i++){
		*((unsigned char*) P_dst++)=*((unsigned char*) P_src++);
	}
	
	unsigned int BSS_size = (unsigned char *)&_S_BSS-(unsigned char*)_E_BSS;
	P_dst=(unsigned char *)&_S_BSS;
	for (i=0;i<BSS_size;i++){
		*((unsigned char*)P_dst++)=0;
	}
	main();
}