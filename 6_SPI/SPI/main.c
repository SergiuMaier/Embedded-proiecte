/*
 * SPI.c
 *
 * Created: 9/29/2022 10:53:40 AM
 * Author : Sergiu Maier
 */ 

#include "USART.h"
#include "timer.h"

int main(void)
{		
	init_devices();	
	init_USART(MYUBRR);
	
	//introducere_mesaj();
	
	//uint8_t semafor = 0;
	//
	//if(UDR0 == "TIMP"){
		//semafor = 1;
	//}else if(UDR0 == "STOP")
	//{
		//semafor = 0;
		//SendData(CLEAR);
		//introducere_mesaj();
	//}
	//
	while(1) 
    { 	
		//if(semafor == 1)
			afisare_timp();
    }
}

