#include "tm4c123gh6pm.h"

void delayMs(int n){
int i,j; 
 
 for(i=0;i<n;i++){
	for(j=0;j<3180;j++);
 }
}
