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
	int maxlenth=350;
	float oldlat;
	float oldlon;
	float distance=0;
	int fixFlag=0;
	char y[75]="$GPRMC,220516,A,00030.04480,N,00031.23969,W,173.8,231.8,130694,004.2,W*70";			//i made an edit here
	//ahmed edited the following section
	char x[75]="$GPRMC,220516,A,00030.04480,N,00031.23970,W,173.8,231.8,130694,004.2,W*70";			//i made an edit here

	int counter=0;
	int dist;
	int flag=0;
	//int fix_flag=0;
	LED_init();
	Seven_init();
	UART_init();
	while(fixFlag==0){
		//array(y,maxlenth);
		parcing(y,&lat,&lon);
		if(lat!=0 && lon !=0) fixFlag=1;
	}
	while(flag==0) {
		if( (counter%1000) == 0){
			oldlat=lat;
			oldlon=lon;
			//array(y,maxlenth);
			parcing(x,&lat,&lon);
			if(lat==0 || lon ==0){ lat=1; lon=1;}
			distance += CalcGPSDistance(oldlat, oldlon, lat, lon);
		}
		if (GPIO_PORTF_DATA_R == 0x01) flag=1 ;  		
		counter++;
		checkDist(distance);
		dist = distance;
		ssd_v2(dist);
	}
	ssd_v2(dist);

	return 0;
}
