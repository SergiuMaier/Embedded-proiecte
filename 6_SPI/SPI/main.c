/*
 * SPI.c
 *
 * Created: 9/21/2022 10:53:40 AM
 * Author : Sergiu Maier
 */ 

#include <avr/io.h>

#include "main_defines.h"
#include "main_func.h"
#include "USART_func.h"

int main(void)
{	
	DDRB = 0x01;
	PORTB = 0x00;
	//init_devices();
	USART_Init(MYUBRR);
   
    while(1) 
    {
		//PORTB |= (1 << PINB0);  
		//apelare();
		send_data("aprins\n\r");
    }
}

