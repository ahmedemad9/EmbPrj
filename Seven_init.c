#include "tm4c123gh6pm.h"


void Seven_init(void){

	GPIO_PORTB_AMSEL_R &=~0XFF;
	GPIO_PORTB_DIR_R |=0XFF;
	GPIO_PORTB_DEN_R |=0XFF;
	GPIO_PORTB_AFSEL_R &=~0XFF;
	GPIO_PORTB_PCTL_R &=~0XFFFFFFFF;
	
}
