#include "stdint.h"
#include "C:/Keil/EE319Kware/inc/tm4c123gh6pm.h"

void keypad_init(void) {
	SYSCTL_RCGCGPIO_R |= 0x04; /* enable clock to GPIOC */
	SYSCTL_RCGCGPIO_R |= 0x10; /* enable clock to GPIOE */
	while ((SYSCTL_PRGPIO_R&0x04) == 0 && (SYSCTL_PRGPIO_R&0x10) == 0 ){};  /* Wait till sittle*/
	GPIO_PORTE_DIR_R |= 0x0F; /* set row pins 3-0 as output */
	GPIO_PORTE_DEN_R|= 0x0F; /* set row pins 3-0 as digital pins */
	GPIO_PORTC_DIR_R &= ~0xF0; /* set column pin 7-4 as input */
	GPIO_PORTC_DEN_R |= 0xF0; /* set column pin 7-4 as digital pins */
}
unsigned char keypad_getkey(void) {
const unsigned char keymap[4][4] = {
{ '1', '2', '3', 'A'},
{ '4', '5', '6', 'B'},
{ '7', '8', '9', 'C'},
{ '*', '0', '#', 'D'},
};

int row;
 
/* check to see any key pressed first */
GPIO_PORTE_DATA_R = 0; /* enable all rows */
if ((GPIO_PORTC_DATA_R & 0xF0) == 0xF0) return 0; /* no key pressed */
 
while (1)
{

GPIO_PORTE_DATA_R = 0x0E; /* enable row 0 */
if ((GPIO_PORTC_DATA_R  & 0xF0 ) != 0xF0) break;
 


GPIO_PORTE_DATA_R = 0x0D; /* enable row 1 */
if ((GPIO_PORTC_DATA_R  & 0xF0 ) != 0xF0) break;
 
GPIO_PORTE_DATA_R = 0x0B; /* enable row 2 */
if ((GPIO_PORTC_DATA_R  & 0xF0 ) != 0xF0) break;
 
GPIO_PORTE_DATA_R = 0x07; /* enable row 3 */
if ((GPIO_PORTC_DATA_R  & 0xF0) != 0xF0) break;
 
 
/* gets here when one of the rows has key pressed */
if ((GPIO_PORTC_DATA_R & 0xF0 ) == 0xE0) return keymap[row][0]; /* key in column 0 */
if ((GPIO_PORTC_DATA_R & 0xF0 ) == 0xD0) return keymap[row][1]; /* key in column 1 */
if ((GPIO_PORTC_DATA_R & 0xF0 ) == 0xB0) return keymap[row][2]; /* key in column 2 */
if ((GPIO_PORTC_DATA_R & 0xF0 ) == 0x70) return keymap[row][3]; /* key in column 3 */
}
return 0;
}

