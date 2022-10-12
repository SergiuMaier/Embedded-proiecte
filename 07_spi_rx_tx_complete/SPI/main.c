/*
 * SPI.c
 *
 * Created: 9/29/2022 10:53:40 AM
 * Author : Sergiu Maier
 */ 

#include "USART.h"
#include "functii_afisare.h"

int main(void)
{	
	init_devices();
	init_USART(MYUBRR);
	
	send_data(CLEAR);
	afisare_meniu();
	new_line();
	
	while(1) 
    {
		receive_data();
		afisare_timp();
    }
}

