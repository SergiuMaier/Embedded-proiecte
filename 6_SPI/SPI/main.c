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
#include <util/delay.h>

int main(void)
{	
	char val[10];
	int a = 0;

	//init_devices();	
	USART_Init(MYUBRR);
	
    while(1) 
    { 
		itoa(a, val, 10);
		
		if(a < 10){
			SendData("00:00:0");
			//a++;
		}
		else{
			SendData("00:00:");	
			//a++;
		}
		a++;
		SendData(val);
		SendData("\n\r");
		
		//a++;
		_delay_ms(1000);
    }
}

