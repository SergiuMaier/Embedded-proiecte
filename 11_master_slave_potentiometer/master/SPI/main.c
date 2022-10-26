/*
 * SPI.c
 *
 * Created: 9/29/2022 10:53:40 AM
 * Author : Sergiu Maier
 */ 

//-----------MASTER------------//

#include "USART.h"

int main(void)
{	
	init_USART(MYUBRR);
	
	send_data(CLEAR);
	
	while(1) 
    {
		start_program(); 
    }
}

