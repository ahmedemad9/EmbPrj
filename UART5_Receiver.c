#include "tm4c123gh6pm.h"


char UART5_Receiver(void)
{
char data;
while ((UART5_FR_R & UART_FR_RXFE) != 0); // wait until Rx buffer is not full
data = UART5_DR_R; // before giving it another byte
return (unsigned char)data;
}
