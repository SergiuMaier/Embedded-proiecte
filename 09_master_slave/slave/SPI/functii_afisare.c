/*
 * functii_afisare.c
 *
 * Created: 10/6/2022 10:51:48 AM
 *  Author: Sergiu Maier
 */ 

#include "functii_afisare.h"

void new_line()
{
	send_data("\n\r>>");
}

void afisare_meniu()
{
	send_data("\n\rComenzi:\n\r 1. meniu\n\r 2. timp\n\r 3. led on\n\r 4. led off\n\r 5. clear\n\r");
}

void switch_data(char data[])
{	
	//-----------verificare daca se primesc mesaje de la master---------------/
	
	//if(data){
		//send_data(data);
		//send_data("0");
		//send_data("\n\r");
		
		//sau
		
	//	schimbare_stare_led(&PORTB, PINB0, 1);
	//}
	
	//---------------------------------------------------------------------/
	
	if(strcmp(data, "\rled on") == 0)
		schimbare_stare_led(&PORTB, PINB0, 1);
	
	else if(strcmp(data, "\rled off") == 0)
		schimbare_stare_led(&PORTB, PINB0, 0);
		
	else if(strcmp(data, "\rtimp") == 0)
		afisare_timp();
		
	else if(strcmp(data, "\rclear") == 0)
		send_data(CLEAR);

	else{
		send_data("'");
		send_data(data);
		send_data("' ");
		send_data("nu este o comanda!\n\r");
	}
}

void schimbare_stare_led(volatile uint8_t *port, uint8_t pin, uint8_t stare)
{
	if(stare == 1)
	{
		*port |= (1 << pin);
		send_data("ON\n\r");
	}
	else
	{
		*port &= ~(1 << pin);
		send_data("OFF\n\r");
	}
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


