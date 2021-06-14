#include "tm4c123gh6pm.h"

char UART2_Receiver(void)
{
char data;
while ((UART2_FR_R & 0x10) != 0); // wait until Rx buffer is not full
data = UART2_DR_R &0xFF ; // before giving it another byte
return data;
}
