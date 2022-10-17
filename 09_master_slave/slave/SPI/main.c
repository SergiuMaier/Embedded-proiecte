/*
 * SPI.c
 *
 * Created: 9/29/2022 10:53:40 AM
 * Author : Sergiu Maier
 */ 

//-----------SLAVE------------//

#include "USART.h"

int main(void)
{	
	init_devices();
	init_USART(MYUBRR);
	
	send_data(CLEAR); //clear putty
	//afisare_meniu();  //afisare lista comenzi
	//new_line();       //rand nou unde se poate introduce o comanda
	
	while(1) 
    {
		start_program();   
    }
}

