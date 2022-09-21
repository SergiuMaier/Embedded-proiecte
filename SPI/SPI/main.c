/*
 * SPI.c
 *
 * Created: 9/21/2022 10:53:40 AM
 * Author : Sergiu
 */ 

#include <avr/io.h>
#include "main_defines.h"
#include "USART_func.h"

int main(void)
{
	USART_Init(MYUBRR);
   
    while (1) 
    {
		//SendData("Sergiu\r\n");
    }
}

