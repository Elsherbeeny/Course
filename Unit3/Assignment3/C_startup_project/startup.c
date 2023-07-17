#include<stdint.h>

#define STACK_Start_SP 0x20001000
extern uint64_t _stack_top;
extern int main(void);
void Rest_Handler(void);
void Default_Handler(){
	Rest_Handler();
}
void NMI_Handler(void) __attribute__ ((weak,alias ("Default_Handler")));
void H_fault_Handler(void) __attribute__ ((weak,alias ("Default_Handler")));
void MM_fault_Handler(void) __attribute__ ((weak,alias ("Default_Handler")));
void Bus_fault_Handler(void) __attribute__ ((weak,alias ("Default_Handler")));
void Usage_fault_Handler(void) __attribute__ ((weak,alias ("Default_Handler")));

uint32_t vectors[] __attribute__((section(".vectors"))) ={
	(uint32_t)&_stack_top,
	(uint32_t)&Rest_Handler,
	(uint32_t)&NMI_Handler,
	(uint32_t)&H_fault_Handler,
	(uint32_t)&MM_fault_Handler,
	(uint32_t)&Bus_fault_Handler,
	(uint32_t)&Usage_fault_Handler
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