#include "tm4c123gh6pm.h"
 
 void delayMs(int n);
 
 void ssd_v2(int c){
	int i,j,k;
	
	for(j=0;j<75 ;j++){
		k=c;
		for (i=0 ;i<3;i++) {
		GPIO_PORTB_DATA_R =  k%10;
		GPIO_PORTB_DATA_R |= 0xf0;	
		GPIO_PORTB_DATA_R &= ~(0x10<<i);
		k/=10;
		delayMs(2);
	}
} 
	}
