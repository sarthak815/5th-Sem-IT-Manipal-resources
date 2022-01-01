#include<LPC17xx.h>
unsigned int i, j;
unsigned long LED;



int main(void)
{
SystemInit();
SystemCoreClockUpdate();

LPC_PINCON->PINSEL0 &= 0x00000000;
LPC_GPIO0->FIODIR |= 0x00000FF0;

while(1)
{
LED = 0x00000050;
LPC_GPIO0->FIOSET = LED;
for(j=0;j<10;j++);

LPC_GPIO0->FIOCLR = LED;
for(j=0;j<10;j++);



LED = 0x00000060;
LPC_GPIO0->FIOSET = LED;
for(j=0;j<10;j++);

LPC_GPIO0->FIOCLR = LED;
for(j=0;j<10;j++);

LED = 0x00000070;
LPC_GPIO0->FIOSET = LED;
for(j=0;j<10;j++);

LPC_GPIO0->FIOCLR = LED;
for(j=0;j<10;j++);



LED = 0x00000080;
LPC_GPIO0->FIOSET = LED;
for(j=0;j<10;j++);

LPC_GPIO0->FIOCLR = LED;
for(j=0;j<10;j++);

LED = 0x00000070;
LPC_GPIO0->FIOSET = LED;
for(j=0;j<10;j++);

LPC_GPIO0->FIOCLR = LED;
for(j=0;j<10;j++);

LED = 0x00000060;
LPC_GPIO0->FIOSET = LED;
for(j=0;j<10;j++);

LPC_GPIO0->FIOCLR = LED;
for(j=0;j<10;j++);
}
}