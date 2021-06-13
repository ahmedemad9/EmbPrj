//#include <stdint.h>
//#include <C:/Keil/EE319Kware/inc/tm4c123gh6pm.h>
#include "tm4c123gh6pm.h"
#include "tm4c123.h"

void SystemInit(){ 
	SCB->CPACR|=((3UL<<10*2)|(3UL<<11*2));
}

void LED_init(void);
void Seven_init(void);
void UART_init(void);
void array (char*str, int maxlenth);
void parcing(char data [], float*lat, float*lon);
float CalcGPSDistance(float lat1, float lon1, float lat2, float lon2);
void checkDist(int distance);
void ssd_v2(int c);

int main() {
	
	float lat;
	float lon;
	int maxlenth=70;
	float oldlat;
	float oldlon;
	float distance=0;
	int fixFlag=0; //{'0'}
	char y[75]={'0'};//"$GPRMC,220516,A,3004.48000,N,3123.96000,W,173.8,231.8,130694,004.2,W*70";			//i made an edit here
	//ahmed edited the following section
	//char x[75]="$GPRMC,220516,A,3004.48000,N,3123.97000,W,173.8,231.8,130694,004.2,W*70";			//i made an edit here

	int counter=0;
	int dist;
	int flag=0;

	//int fix_flag=0;
	LED_init();
	Seven_init();
	UART_init();
//ssd_v2(555);
	while(fixFlag==0){
		//ssd_v2(999);

		array(y,maxlenth);
				//ssd_v2(888);

		parcing(y,&lat,&lon);
			GPIO_PORTF_DATA_R |= 0x08;
		//ssd_v2(111);
		if(lat!=0 && lon !=0) fixFlag=1;
	}
	//ssd_v2(222);

																	GPIO_PORTF_DATA_R &=~ 0x08;

	while(flag==0) {
		if( (counter%95) == 0){
			oldlat=lat;
			oldlon=lon;
			//ssd_v2(777);
			array(y,maxlenth);
			//parcing(y,&lat,&lon);
			parcing(y,&lat,&lon);

			//if(lat==0 || lon ==0){ lat=1; lon=1;}
			distance += CalcGPSDistance(oldlat, oldlon, lat, lon);
		}
		counter++;
				ssd_v2(distance);

		checkDist(distance);
		//dist = distance;
		//ssd_v2(333);
		if ((GPIO_PORTF_DATA_R & 0x10) ==0x00) flag=1 ;  		

	}
																GPIO_PORTF_DATA_R |= 0x02;
	while(1)	ssd_v2(distance);

	return 0;
}
