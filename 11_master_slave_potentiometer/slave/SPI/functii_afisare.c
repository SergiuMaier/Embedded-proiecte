/*
 * functii_afisare.c
 *
 * Created: 10/17/2022 10:51:48 AM
 *  Author: Sergiu Maier
 */ 

#include "functii_afisare.h"

void switch_data(char data[])
{	
	if(strcmp(data, "LED ON\n") == 0){
		schimbare_stare_led(&PORTB, PINB0, 1);
		send_data("ON\n\r");
	}
	else if(strcmp(data, "1") == 0){
		//send_data("works\n\r");
		start_conversie();
		send_data("\n\r");
	}
	else if(strcmp(data, "LED OFF\n") == 0){
		schimbare_stare_led(&PORTB, PINB0, 0);
		send_data("OFF\n\r");
	}
	else if(strcmp(data, "TIMP\n") == 0){
		afisare_timp();
	}
	else if(strcmp(data, "VALOARE\n") == 0){
		start_conversie();
		send_data("\n\r");
	}
	else if(strcmp(data, "CLEAR\n") == 0){
		send_data(CLEAR);send_data(CLEAR);
		send_data("\n\r"); //rezolvare bug nerecunoastere comanda dupa clear
	}
}

void schimbare_stare_led(volatile uint8_t *port, uint8_t pin, uint8_t stare)
{
	if(stare == 1)
		*port |= (1 << pin);
	else
		*port &= ~(1 << pin);
}

void afisare_timp()
{
	incrementare_minute();
		
	if(flag_timer == 1)
	{			
		send_data("Timp curent: ");
		
		itoa(secunde,  ch_sec, 10); //conversie sec si min din int in char
		itoa(minute, ch_min, 10);
		
		//format 00:00
			
		if(minute < 10)
		{
			send_data("0");
			send_data(ch_min);
		}
		else
			send_data(ch_min);
		
		if((secunde >= 0) && (secunde < 10))
		{
			send_data(":0");
			send_data(ch_sec);
		}
		else
		{
			send_data(":");
			send_data(ch_sec);
		}
		
		send_data("\n\r");
		
		flag_timer = 0;
	}
}


