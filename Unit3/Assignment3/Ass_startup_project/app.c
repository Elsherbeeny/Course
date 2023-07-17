#include<stdint.h>


typedef volatile unsigned int vuint32_t;
//register address
#ifndef RCC_BASE
#define RCC_BASE  0x40021000
#endif
#ifndef GPIOA_BASE
#define GPIOA_BASE 0x40010800
#endif
#define RCC_APB2ENR (*(volatile uint32_t*) (RCC_BASE +0x18))
#define GPIOA_CRH  (*(volatile uint32_t*) (GPIOA_BASE +0x04))
#define GPIOA_ODR (*(volatile uint32_t*) (GPIOA_BASE +0x0C))

typedef union {
	vuint32_t allfields;
	struct{
		vuint32_t reserved:13;
		vuint32_t P_13:1;
	}pin;
}R_ODDR_t;
volatile R_ODDR_t* R_ODDR =(volatile R_ODDR_t*)(GPIOA_BASE+0x0C);

int main(){
	RCC_APB2ENR |= 1<<2;
	GPIOA_CRH &= 0xFF0FFFFF;
	GPIOA_CRH |=0x00200000;
	int i;
	while(1){
		R_ODDR ->pin.P_13=1;
		for( i=0;i<5000;i++);
		R_ODDR ->pin.P_13=0;
		for( i=0;i<5000;i++);
	}
	return 0;
}
