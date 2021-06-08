#include <stdio.h>
#include <stdlib.h>
#include "C:\Keil\ARM\SFD\TI\TM4C123\tm4c123gh6pm.h"
#include "tm4c123.h"

void array (char*str, int maxlenth){
    char c;
    int i;
    for(i=0; i<maxlenth; i++){
        c=UART2_Receiver();
        scanf("%c",&c);
        str[i]= c;
    }

}
