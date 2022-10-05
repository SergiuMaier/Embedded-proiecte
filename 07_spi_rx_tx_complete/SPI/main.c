/*
 * SPI.c
 *
 * Created: 9/29/2022 10:53:40 AM
 * Author : Sergiu Maier
 */ 

#include "USART.h"
#include "timer.h"

extern uint8_t flag_afisare_timp;

int main(void)
{	
	//pt debug:	
	//DDRB = 0x01;
	//PORTB = 0x00;
	
	init_devices();	
	init_USART(MYUBRR);
	
	send_data(CLEAR);
	rand_nou();
	
	while(1) 
    {
		receive_data();
		 	
		if(flag_afisare_timp == 1) //se poate face o functie 
			afisare_timp();
    }
}

