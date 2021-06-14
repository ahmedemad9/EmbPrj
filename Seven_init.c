#include "tm4c123gh6pm.h"

void Seven_init(void){
SYSCTL_RCGCGPIO_R |=0x02; 	             // clock for portB
while ( (SYSCTL_PRGPIO_R & 0x02) ==0 ) {}
	GPIO_PORTB_AMSEL_R=0;
	GPIO_PORTB_DIR_R |=0XFF;
	GPIO_PORTB_DEN_R |=0XFF;
	GPIO_PORTB_AFSEL_R =0;
	GPIO_PORTB_PCTL_R =0;
}
