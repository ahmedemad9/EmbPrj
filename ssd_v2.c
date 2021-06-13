 #include "tm4c123gh6pm.h"
 
 void delayMs(int n);
 
 void ssd_v2(int c){
	int i;
	
	for(i=0;i<3;i++){
		GPIO_PORTB_DATA_R = c%10;
		GPIO_PORTB_DATA_R |= 0xf0;	
		GPIO_PORTB_DATA_R &= ~(0x10<<i);
		c/=10;
		delayMs(2);
	}
}
