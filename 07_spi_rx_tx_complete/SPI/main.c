/*
 * SPI.c
 *
 * Created: 9/29/2022 10:53:40 AM
 * Author : Sergiu Maier
 */ 

#include "USART.h"
#include "timer.h"
#include "functii_afisare.h"

extern uint8_t flag_afisare_timp;
extern uint8_t stare_led;
	
int main(void)
{	
	//pt debug:	
	DDRB = 0x01;
	PORTB = 0x00;
	
	init_devices();	
	init_USART(MYUBRR);
	
	send_data(CLEAR);
	afisare_meniu();
	new_line();
	
	while(1) 
    {
		receive_data();
		 	
		if(flag_afisare_timp == 1)
			afisare_timp();
		
    }
}

