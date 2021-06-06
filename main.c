#include <stdint.h>
#include "tm4c123gh6pm.h"

void LED_init(void);
void Seven_init(void);
void checkDist(int distance);
void ssd(int c);
void ssd_v2(int c);

int main() {
	int distance;
	LED_init();
	Seven_init();
	
	while(1){
		GPIO_PORTF_DATA_R |= 0x04;
		distance = 103;
		checkDist(distance);
		ssd(distance);
		ssd_v2(distance);
		 	}
	
	return 0;
}
