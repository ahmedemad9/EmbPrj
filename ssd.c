#include "D:/Kei4l/tm4c123gh6pm.h"

void delayMs(int n){
int i,j; 
 
 for(i=0;i<n;i++){
	for(j=0;j<3180;j++);
 }
}

 
 void ssd(int c){
	int a[3];
	int i;
	
	for(i=0;i<3;i++){
		a[i]=c%10;
	  c/=10;
	}
	//GPIO_PORTB_DATA_R |=0xF0;
	for(i=0;i<3;i++){
		//GPIO_PORTB_DATA_R &=~ 0x0f; //remove old value
		GPIO_PORTB_DATA_R = a[i];
		GPIO_PORTB_DATA_R |= 0xf0;	
		GPIO_PORTB_DATA_R &=~(0x10<<i);
		delayMs(10);
	}
}
