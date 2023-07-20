#define SYSCTRL_Base              0x400FE000
#define GPIO_PORTF_Base           0x40025000

#define SYSCTL_RCGC2_R   (*(unsigned long *)(SYSCTRL_Base+0X108))
#define GPIO_PORTF_DIR_R  (*(unsigned long *)(GPIO_PORTF_Base+0x400))
#define GPIO_PORTF_DEN_R  (*(unsigned long *)(GPIO_PORTF_Base+0X51C))
#define GPIO_PORTF_DATA_R (*(unsigned long *)(GPIO_PORTF_Base+0x3FC))

void main(void){
    volatile unsigned long delay_cont;
    SYSCTL_RCGC2_R =0x20;
    for (delay_cont=0;delay_cont <200;delay_cont++);
    GPIO_PORTF_DIR_R |= 1<<3;
    GPIO_PORTF_DEN_R |= 1<<3;
    while(1){
        GPIO_PORTF_DATA_R |= (1<<3);
        for (delay_cont=0;delay_cont<2000;delay_cont++);
        GPIO_PORTF_DATA_R &= ~(1<<3);
        for (delay_cont=0;delay_cont<2000;delay_cont++);
    }
} 