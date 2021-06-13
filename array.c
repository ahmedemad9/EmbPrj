//#include <stdio.h>
//#include <stdlib.h>
#include "tm4c123gh6pm.h"
#include "tm4c123.h"
char UART2_read(void);		//I made an edit here

void array (char*str, int maxlenth){
    char c;
	//int asterisk_flag=0,read_permission=0;
    int i;
    for(i=0; i<maxlenth; i++){
        c=UART2_read();
			if(c=='*') goto watermelon;
/*			if(asterisk_flag>=1){
				asterisk_flag++;
			}*/
       else str[i]= c;
    }
		watermelon:
		c=UART2_read();
		c=UART2_read();
		c=UART2_read();
}
