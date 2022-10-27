/*
 * SPI.c
 *
 * Created: 9/29/2022 10:53:40 AM
 * Author : Sergiu Maier
 */ 

//-----------SLAVE------------//

#include "ADC.h"
#include "USART.h"

int main(void)
{	
	init_devices();
	init_ADC();
	init_USART(MYUBRR);
	
	send_data(CLEAR);
	
	while(1) 
    {
		start_program();
    }
}

