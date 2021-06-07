#include <stdio.h>
#include <stdlib.h>
#include "C:\Keil\ARM\SFD\TI\TM4C123\tm4c123gh6pm.h"
#include "tm4c123.h"


void array (char*str, int maxlenth){
    char c;
    int i;
    for(i=0; i<maxlenth; i++){
        c=UART2_read();
        str[i]= c;
    }

}

void parcing(char data [], float*lat, float*lon, char*latdir, char*londir){
int x=0, com=0, latdeg=0,londeg=0, lonmin=0, lonsec=0, latmin=0, latsec=0, i;
	for(i=0; i <= 200 ; i++){
		if( data[i]=='$' && x==0){
			x=1;
		}
		if( data[i]=='G' && x==1){
			x=2;
		}
		if( data[i]=='P' && x==2){
			x=3;
		}
		if( data[i]=='R' && x==3){
			x=4;
		}
		if( data[i]=='M' && x==4){
			x=5;
		}
		if( data[i]=='C' && x==5){
			x=6;
		}
		if( (data[i]==',')&& (x==6)){
			com++;
		}
		if(com==3){
			if(data[i]=='.'){
				latmin=(data[i-1]-'0')+((data[i-2]-'0')*10);
				latsec=((data[i+1]-'0')*1000)+((data[i+2]-'0')*100)+((data[i+3]-'0')*10)+(data[i+4]-'0');
				if((data[i-5] !=' ') && (data[i-5] !=','))
				{
				  latdeg=(data[i-3]-'0')+(data[i-4]-'0')*10+(data[i-5]-'0')*100;}
				else{
					latdeg=(data[i-3]-'0')+(data[i-4]-'0')*10;}
	        *lat=latdeg + ((float)latmin/60) +((float)latsec/3600);
			}
		}
		if(com==5){
			if(data[i]=='.'){
				lonmin=(data[i-1]-'0')+((data[i-2]-'0')*10);
				lonsec=((data[i+1]-'0')*1000)+((data[i+2]-'0')*100)+((data[i+3]-'0')*10)+(data[i+4]-'0');
				if((data[i-5] !=' ') && (data[i-5] !=','))
				{
				  londeg=(data[i-3]-'0')+(data[i-4]-'0')*10+(data[i-5]-'0')*100  ;}
				else{
					londeg=(data[i-3]-'0')+(data[i-4]-'0')*10;}
	        *lon=londeg + ((float)lonmin/60) +((float)lonsec/3600);
			}
		}
		if(com==4){
            if((data[i] =='N')|| (data[i] =='S')||(data[i] =='E')||(data[i] =='W') ){
                *latdir=data[i];}
		}
		if(com==6){
			if((data[i] =='N')|| (data[i] =='S')||(data[i] =='E')||(data[i] =='W')){
                *londir=data[i];}
		}
}
}
