/*
 * SPI.c
 *
 * Created: 9/29/2022 10:53:40 AM
 * Author : Sergiu Maier
 */ 

#include "USART.h"

int main(void)
{	
	init_devices();
	init_USART(MYUBRR);
	
	send_data(CLEAR);
	afisare_meniu();
	new_line();
	
	while(1) 
    {
		
    }
}

