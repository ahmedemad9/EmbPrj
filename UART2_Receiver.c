char UART2_Receiver(void)
{
char data;
while ((UART2_FR_R & UART_FR_RXFE) != 0); // wait until Rx buffer is not full before giving it another byte
data = UART2_DR_R;
return (unsigned char)data;
}
