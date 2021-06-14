#include "tm4c123gh6pm.h"

void ssd_v2(int c);
void checkDist(int distance){
	if( distance>100 ){	
		GPIO_PORTF_DATA_R = 0x04;
		ssd_v2(distance);
	}
	else {
GPIO_PORTF_DATA_R &= ~(0XFF);	
	}
}
