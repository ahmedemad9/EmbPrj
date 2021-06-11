void parcing(char data [], float*lat, float*lon, char*latdir, char*londir){
int x=0, com=0, latdeg=0,londeg=0, lonmin=0, lonsec=0, latmin=0, latsec=0, i;
int checkFixFlag=0;
	for(i=0; i <= 72 ; i++){
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
           //printf(" yarab ne5las %c \n", data[i]);
		}
		if( (data[i]==',')&& (x==6)){
			com++;
		//	printf("%d ",com);
		}
		if(com==2){
			//while(data[i+1]!='A'){
            if( data[i+1]=='A' && checkFixFlag==0){
            //printf("%c \n",data[i+1]);
							checkFixFlag=1;
              //break;
                }
						else{
							*lon=0;
							*lat=0;
						}
          // printf(" %d \n",x);
		}
		if(com==3 && checkFixFlag==1){
			if(data[i]=='.'){
				latmin=(data[i-1]-'0')+((data[i-2]-'0')*10);
				latsec=((data[i+1]-'0')*1000)+((data[i+2]-'0')*100)+((data[i+3]-'0')*10)+(data[i+4]-'0');
				if((data[i-5] !=' ') && (data[i-5] !=','))
				{
				  latdeg=(data[i-3]-'0')+(data[i-4]-'0')*10+(data[i-5]-'0')*100;}
				else{
					latdeg=(data[i-3]-'0')+(data[i-4]-'0')*10;}
	        *lat=latdeg + ((float)latmin/60) +((float)latsec/3600);
	           //printf("hellppp\n");
			}

		}
		if(com==5 && checkFixFlag==1){
			if(data[i]=='.'){
				lonmin=(data[i-1]-'0')+((data[i-2]-'0')*10);
				lonsec=((data[i+1]-'0')*1000)+((data[i+2]-'0')*100)+((data[i+3]-'0')*10)+(data[i+4]-'0');
				if((data[i-5] !=' ') && (data[i-5] !=','))
				{
				  londeg=(data[i-3]-'0')+(data[i-4]-'0')*10+(data[i-5]-'0')*100  ;}
				else{
					londeg=(data[i-3]-'0')+(data[i-4]-'0')*10;}
	        *lon=londeg + ((float)lonmin/60) +((float)lonsec/3600);
	        //printf("????????? \n");
			}
		}

}

}
