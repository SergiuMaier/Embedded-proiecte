/*
 * SPI.c
 *
 * Created: 9/29/2022 10:53:40 AM
 * Author : Sergiu Maier
 */ 

#include "USART.h"
#include "timer.h"

int main(void)
{		
	init_devices();	
	USART_Init(MYUBRR);
	
	while(1) 
    { 			
		SendData(CLEAR);
		afisare_timp();
    }
}

