#include "tm4c123gh6pm.h"


char UART2_Receiver(void)
{
char data;
while ((UART2_FR_R & UART_FR_RXFE) != 0); // wait until Rx buffer is not full
data = UART2_DR_R; // before giving it another byte
return (unsigned char)data;
}
