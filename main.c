#include <stdint.h>
//#include <C:/Keil/EE319Kware/inc/tm4c123gh6pm.h>
#include <tm4c123gh6pm.h>
#include <tm4c123.h>

void SystemInit(){ 
	SCB->CPACR|=((3UL<<10*2)|(3UL<<11*2));
}

	void LED_init(void);
	void Seven_init(void);
	void UART_init(void);
	void array (char*str, int maxlenth);
	void parcing(char data [], float*lat, float*lon);
	double CalcGPSDistance(double lat1, double lon1, double lat2, double lon2);
	void checkDist(int distance);
	void ssd_v2(int c);

int main() {
	float lat;
	float lon;
	int maxlenth=350;
	float oldlat;
	float oldlon;
	float distance=0;
	char y[]={0};
	int counter=0;
	int dist;
	int flag=0;
	LED_init();
	Seven_init();
	UART_init();
	array(y,maxlenth);
	parcing(y,&lat,&lon);
	while(flag==0) {
		if(counter%1000 == 0){
			oldlat=lat;
			oldlon=lon;
			array(y,maxlenth);
			parcing(y,&lat,&lon);
			distance += CalcGPSDistance(oldlat, oldlon, lat, lon);
		}
		if (GPIO_PORTF_DATA_R == 0x01) flag=1 ;  		
		counter++;
		checkDist(distance);
		dist = distance;
		ssd_v2(dist);
	}
	return 0;
}
