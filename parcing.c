//#include <stdlib.h>
	//float atof(char *str);
#include "tm4c123gh6pm.h"

void parcing(char data [], float*lat, float*lon){
int x=0, com=0, latdeg=0,londeg=0, lonmin=0, lonsec=0, latmin=0, latsec=0, i;
int checkFixFlag=0;
char latarray[10];
char lgarray[10];
	float floatlat;
	float floatlg;
	int c=0, d=0;
	int accept_flag=0;


//float floatlat=0 , floatlg=0;
	for(i=0; i <= 72 ; i++){
		if( data[i]=='$' && x==0 && (accept_flag==0)){

			if( data[++i]=='G' && x==1 && (accept_flag==0)){

				if( data[++i]=='P' && x==2 && (accept_flag==0)){

					if( data[++i]=='R' && x==3 && (accept_flag==0)){
	
						if( data[++i]=='M' && x==4 && (accept_flag==0)){

							if( data[++i]=='C' && x==5 && (accept_flag==0)){

								if( (data[++i]==',') && (x==6) && (accept_flag==0)){
									com++;
									GPIO_PORTF_DATA_R = 0x08;
		/*********************************************************/accept_flag=1;
								}
							}
						}
					}
				}
			}
		}
		if(com==2){
			//while(data[i+1]!='A'){
            if( data[i+1]=='A' && checkFixFlag==0){
							checkFixFlag=1;
                }
						else{
							*lon=0;
							*lat=0;
							//goto exit;
						}
		}
		if(com==3 && checkFixFlag==1){
			if(data[i]=='.'){
				latmin=(data[i-1]-'0')+((data[i-2]-'0')*10);
				 latsec=((data[i+1]-'0')*10000)+((data[i+2]-'0')*1000)+((data[i+3]-'0')*100)+((data[i+4]-'0')*10)+(data[i+5]-'0');
				if((data[i-5] !=' ') && (data[i-5] !=','))
				{
				  latdeg=(data[i-3]-'0')+(data[i-4]-'0')*10+(data[i-5]-'0')*100;}
				else{
					latdeg=(data[i-3]-'0')+(data[i-4]-'0')*10;}
	        *lat=latdeg + ((float)latmin/60) +((float)latsec/6000000); ////  i edited a constant here
			}

		}
		if(com==5 && checkFixFlag==1){
			if(data[i]=='.'){
				lonmin=(data[i-1]-'0')+((data[i-2]-'0')*10);
				lonsec=((data[i+1]-'0')*10000)+((data[i+2]-'0')*1000)+((data[i+3]-'0')*100)+((data[i+4]-'0')*10)+(data[i+5]-'0');
				if((data[i-5] !=' ') && (data[i-5] !=','))
				{
				  londeg=(data[i-3]-'0')+(data[i-4]-'0')*10+(data[i-5]-'0')*100  ;}
				else{
					londeg=(data[i-3]-'0')+(data[i-4]-'0')*10;}
	        *lon=londeg + ((float)lonmin/60) +((float)lonsec/6000000); ////  i edited a constant here
			}
		}
/*		if(com==3 && checkFixFlag==1){
                latarray[c++]=data[i];
                floatlat=atof(&latarray[1]);
                latdeg=(int)(floatlat/100);
                latmin=(float)(floatlat-latdeg*100);
                *lat=(float)latdeg+((float)latmin/60);
		}
		if(com==5 && checkFixFlag==1){
                lgarray[d++]=data[i];
                floatlg=atof(&lgarray[1]);
                londeg=(int)(floatlg/100);
                lonmin=(float)(floatlg-londeg*100);
                *lon=londeg+((float)lonmin/60);
		}*/

}
exit:;
						GPIO_PORTF_DATA_R &=~ 0x08;

}
