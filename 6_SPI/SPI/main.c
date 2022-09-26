/*
 * SPI.c
 *
 * Created: 9/21/2022 10:53:40 AM
 * Author : Sergiu Maier
 */ 

#include "main_defines.h"
//#include "main_func.h"
#include "USART_func.h"
#include <avr/io.h>
#include <stdlib.h>
#include <avr/interrupt.h>
#include <util/delay.h>

int main(void)
{	
	DDRB |= 0x01;
	PORTB |= 0x00;
	char val[10];
	int secunde = 0;
	
	//init_devices();	
	USART_Init(MYUBRR);
	
    while(1) 
    { 
		SendData(CLEAR);
		
		itoa(secunde, val, 10);
		SendData("Time:");
		
		if(secunde < 10)
			SendData("  00:00:0");
		else
			SendData("  00:00:");	
		
		secunde++;
		
		if(secunde >= 60){
			secunde = 0; 
		}
		
		SendData(val);
		SendData("\n\r");
		_delay_ms(1000);
    }
}

