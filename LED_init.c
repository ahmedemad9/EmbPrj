 #include "tm4c123gh6pm.h"

void LED_init(void)
{

SYSCTL_RCGCGPIO_R |=0x20; 	             // clock for portF
while ( (SYSCTL_PRGPIO_R & 0x20) ==0 ) {}
GPIO_PORTF_LOCK_R =0x4C4F434B;           // Lock
GPIO_PORTF_CR_R |= 0x1E;                 // using only pF1 as switch
GPIO_PORTF_DIR_R |=0x0E;                 // pF1  set to output
GPIO_PORTF_DEN_R |=0x1F;                 // pF1 set to digital
GPIO_PORTF_AMSEL_R &=~0x1F;              // analog disabled
GPIO_PORTF_AFSEL_R &=~0x1F;              // disable alternative function
GPIO_PORTF_PCTL_R = 0;
GPIO_PORTF_PUR_R|= 0x11;
}
