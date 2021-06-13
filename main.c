#include <stdio.h>
#include <stdint.h>
#include <C:/Keil/EE319Kware/inc/tm4c123gh6pm.h>
#include <tm4c123gh6pm.h>
#include <tm4c123.h>
#include <stdlib.h>

void SystemInit(){ 
SCB->CPACR|=((3UL<<10*2)|(3UL<<11*2));
}

void LED_init(void);
void Seven_init(void);
void UART2_init(void);
double CalcGPSDistance(double lat1, double lon1, double lat2, double lon2);
void checkDist(int distance);
void ssd_v2(int c, int seconds);

 
unsigned char Gpsdata;             // for incoming serial data
unsigned int finish =0;             // indicate end of message
unsigned int pos=0;             // position counter
unsigned int lat_count=0;             // latitude data counter
unsigned int lon_count=0;             // longitude data counter
unsigned int flag =0;             // GPS flag
unsigned int comma=0;            // comma counter
char lat[20];                      // latitude array
char lon[20];                       // longitude array
float flat, latdeg ,latmin,lati ,latsec;
float flon, londeg ,lonmin,longt, lonsec; 
void parsing(){
    
char UART2_read(void);
    
    while(finish==0){
            
        Gpsdata = UART2_read();    
        flag = 1;
    
        if( Gpsdata == '$' && pos==0){
            pos=1;
        }
        if( Gpsdata=='G' && pos==1){
            pos=2;
        }
        if( Gpsdata=='P' && pos==2){
            pos=3;
        }
        if( Gpsdata=='R' && pos==3){
            pos=4;
        }
        if( Gpsdata=='M' && pos==4){
            pos=5;
        }
        if( Gpsdata=='C' && pos==5){
            pos=6;
        }
        if( (Gpsdata==',')&& (pos==6)){
            comma++;
      flag=0;
        }
         if(comma==3 && flag==1){
        lat[lat_count++] =  Gpsdata;         // latitude
        flag=0;
       }

       if(comma==5 && flag==1){
         lon[lon_count++] =  Gpsdata;         // Longitude
         flag=0;
       }

       if( Gpsdata == '*' && comma >= 5 && flag == 1){
         lat[lat_count] ='\0';             // end of GPRMC message
         lon[lon_count]  = '\0';
         
         comma = 0;                      // end of GPRMC message
         lat_count = 0;
         lon_count = 0;
         flag     = 0;
         finish  = 1;
		flat = atof(lat);
    flon = atof(lon);
		 latdeg =(int)(flat/100);
    latmin=(float)(flat-latdeg*100);    
    lati=latdeg+((float)latmin/60);        

    londeg=(int)(flon/100);
    lonmin=(float)(flon-londeg*100);
    longt=londeg+((float)lonmin/60);
		/*londeg = ((int) flon - ((int) flon % 100)) / 100;
		lonmin = flon - ((int) flon - ((int) flon % 100));
    lonsec = (flon - (int) flon) * 60;
		longt = londeg + lonmin/60 + lonsec/3600;
		
		latdeg = ((int) flat - ((int) flat % 100)) / 100;
		latmin = flat - ((int) flat - ((int) flat % 100));
    latsec = (flat - (int) flat) * 60;
		lati = latdeg + latmin/60 + latsec/3600;*/
      }
    }

	 finish = 0;
   pos = 0;
    /*flat = atof(lat);
    flon = atof(lon);
		londeg = ((int) flon - ((int) flon % 100)) / 100;
		lonmin = flon - ((int) flon - ((int) flon % 100));
    lonsec = (flon - (int) flon) * 60;
		longt = londeg + lonmin/60 + lonsec/3600;
		
		latdeg = ((int) flat - ((int) flat % 100)) / 100;
		latmin = flat - ((int) flat - ((int) flat % 100));
    latsec = (flat - (int) flat) * 60;
		lati = latdeg + latmin/60 + latsec/3600;
		*/
    /*latdeg =(int)(flat/100);
    latmin=(float)(flat-latdeg*100);    
    lati=latdeg+((float)latmin/60);        

    londeg=(int)(flon/100);
    lonmin=(float)(flon-londeg*100);
    longt=londeg+((float)lonmin/60); */       
}
int main() {
float newlat;
float newlon;
float oldlat;
float oldlon;
float total_distance=0;
float dist=0;
int quit = 0;
int flg =0;
UART2_init();
parsing();
LED_init();
Seven_init();
while (1) {
	while(quit==0) {
		if (flg == 0 ) flg=1;
		//while ((GPIO_PORTF_DATA_R & 0x01)){} 
    parsing();
		newlat = lati;
		newlon = longt;
		dist = CalcGPSDistance(oldlat, oldlon, newlat, newlon);
		total_distance += dist;
    checkDist(total_distance);
		ssd_v2(total_distance , 5);
    oldlat=lati;
    oldlon=longt;
            if ((GPIO_PORTF_DATA_R & 0x10) == 0x00) quit =1;
        }
GPIO_PORTF_DATA_R = 0x02;
ssd_v2(total_distance , 5);
}
        }
