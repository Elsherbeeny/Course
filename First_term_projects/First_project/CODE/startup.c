

#include <stdint.h>


void Reset_Handler ();

void Default_Handler()
{
	Reset_Handler();
}



void NMI_Handler ()__attribute__((weak,alias("Default_Handler")));;
void H_Fault_Handler ()__attribute__((weak,alias("Default_Handler")));;
 
static unsigned long stack_top[256]; 


void (* const g_p_fn_Vectors[])() __attribute__((section(".vectors"))) =  
{
   (void(*)()) ((unsigned long)stack_top + sizeof(stack_top)),
    &Reset_Handler,
    &NMI_Handler,
    &H_Fault_Handler,
}; 

extern unsigned int _E_text;
extern unsigned int _S_data;
extern unsigned int _E_data;
extern unsigned int _S_bss;
extern unsigned int _E_bss;

void Reset_Handler()
{
	int i ; 
	
	
	unsigned int DATA_size = (unsigned char*)&_E_data - (unsigned char*)&_S_data;
	unsigned char* P_src = (unsigned char*)&_E_text ;
    unsigned char* P_dst = (unsigned char*)&_S_data ;

    for(i=0 ; i < DATA_size ; i++ )
	{
		*((unsigned char*)P_dst++) = *((unsigned char*)P_src++) ; 
	}
	
	unsigned int BSS_size = (unsigned char*)&_E_bss - (unsigned char*)&_S_bss;
	P_dst = (unsigned char*)&_S_bss ; 
	
	for(i=0 ; i < BSS_size ; i++ )
	{
		*((unsigned char*)P_dst++) =(unsigned char) 0; 
	}
	

	
	main();
}
