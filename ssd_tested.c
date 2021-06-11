 #include "tm4c123gh6pm.h"
 
 void delayMs(int n);
 
 void ssd(int c){
	int a[3];
	int i;
	
	for(i=0;i<3;i++){
		a[i]=c%10;
	  c/=10;
	}
	for(i=0;i<3;i++){
		GPIO_PORTB_DATA_R = a[i];
		GPIO_PORTB_DATA_R |= 0xf0;	
		GPIO_PORTB_DATA_R &= ~(0x10<<i);
		delayMs(5);
	}
}
