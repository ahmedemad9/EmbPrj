#include <stdio.h>
#include <stdlib.h>
#include "tm4c123gh6pm.h"
#include "tm4c123.h"
char UART2_Receiver(void);		//I made an edit here

void array (char*str, int maxlenth){
    char c;
    int i;
    for(i=0; i<maxlenth; i++){
        //c=UART2_Receiver();
        //scanf("%c",&c);
        //str[i]= c;
    }

}
