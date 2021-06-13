#include "tm4c123gh6pm.h"
char UART2_read(void){
    while((UART2_FR_R & 0x10) == 0x10);
    return UART2_DR_R & 0xFF;
}
