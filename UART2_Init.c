void UART2_Init(void)                     // called once
{
SYSCTL_RCGCUART_R |= SYSCTL_RCGCUART_R2; // activate UART2
SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R3; // Clock initialization port D
GPIO_PORTD_LOCK_R = 0x4C4F434B;          // UNLOCK for pD7
GPIO_PORTD_CR_R = 0xC0;
GPIO_PORTD_AFSEL_R |= 0xC0;                                             // enable alternative function for pD6 pD7
GPIO_PORTD_PCTL_R = (GPIO_PORTD_PCTL_R &~ 0xff000000) | (GPIO_PCTL_PD6_U2RX | GPIO_PCTL_PD7_U2TX);            //with TX
GPIO_PORTD_AMSEL_R |= 0;                                               // analog disabled
GPIO_PORTD_DEN_R |= 0xC0;                                             // pins 6,7 set to digital
UART2_CTL_R = 0;                         // disable UART
UART2_IBRD_R = 104;                      // IBRD = 16000000/(16*9600) = 104.16666
UART2_FBRD_R = 11;                       // FBRD = (0.1667*64) + 0.5 = 11.1667
UART2_LCRH_R = (UART_LCRH_FEN | UART_LCRH_WLEN_8);                       //FIFO enable 8 bit length
UART2_CTL_R = (UART_CTL_RXE | UART_CTL_TXE | UART_CTL_UARTEN);           //with Tx
}
