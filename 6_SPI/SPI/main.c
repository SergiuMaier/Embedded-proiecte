/*
 * SPI.c
 *
 * Created: 9/21/2022 10:53:40 AM
 * Author : Sergiu Maier
 */ 

#include "USART.h"
#include "timer.h"

int main(void)
{	
	DDRB |= 0x01; //pt debug
	PORTB |= 0x00;
	
	init_devices();	
	USART_Init(MYUBRR);
	
	while(1) 
    { 				
		afisare_timp();
    }
}

