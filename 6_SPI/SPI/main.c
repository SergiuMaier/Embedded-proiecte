/*
 * SPI.c
 *
 * Created: 9/21/2022 10:53:40 AM
 * Author : Sergiu
 */ 

#include <avr/io.h>

#include "main_defines.h"
#include "main_func.h"
#include "USART_func.h"

int main(void)
{	
	init_devices();
	USART_Init(MYUBRR);
   
    while(1) 
    {
		apelare();
    }
}

