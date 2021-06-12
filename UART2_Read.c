char UART2_Read(void)
{
while ((UART2_FR_R & UART_FR_RXFE) != 0); // wait until Rx buffer is not full before giving it another byte
return UART2_DR_R & 0xFF;
}
