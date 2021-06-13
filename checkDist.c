#include "tm4c123gh6pm.h"


void checkDist(int distance){
	if(distance>=100){	
		GPIO_PORTF_DATA_R |= 0x08;
	}
}
