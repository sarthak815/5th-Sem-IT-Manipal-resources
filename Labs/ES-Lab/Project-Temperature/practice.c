#include<lpc17xx.h>
unsigned int num[17] = {0X3F,0x06, 0x5B, 0X4F, 0X66, 0X6D, 0X7D, 0X07, 0X7F, 0X67, 0X77, 0X7C, 0X39, 0X5D, 0X79, 0X71};
unsigned int i,j;
int main(){
	SystemInit();
	SystemCoreClockUpdate();
	LPC_PINCON->PINSEL2 = 0X00000000;
	LPC_GPIO1->FIODIR = 0X00000FF0;

	for(i=0;i<17;i++){
		LPC_GPIO1->FIOPIN = num[i]<<4;
	
	}
	
}