/*
 * functii_afisare.c
 *
 * Created: 10/6/2022 10:51:48 AM
 *  Author: Sergiu Maier
 */ 

#include "functii_afisare.h"
#include "USART.h"
#include <stdio.h>

void new_line(){
	
	send_data(">>");
}

void afisare_meniu(){
	
	send_data("\n\rApasa tasta:\n\r 1. Meniu\n\r 2. Timp\n\r 3. LED ON/OFF\n\r\n\r");
}

void switch_data(char c){
	
	switch(c)
	{
	case '1':
		
		//send_data(CLEAR);  	  
		afisare_meniu();
		new_line();
		flag_afisare_timp = 0;
		break;
	
	case '2': 
		
	    flag_afisare_timp = 1;
		break;
	
	case '3': 
		
		stare_led = !stare_led;
		aprinde_led();
		break;
	
	default: 

		send_data("INCORECT!\n\r");
		afisare_meniu();
		new_line();
		break;
	}
}

//caracter gresit -> printeaza tot din default corect
//caracter din case -> printeaza case + default
//se blocheaza dupa 2 caractere

void aprinde_led(){
	
	if(stare_led == 1){
		PORTB |= (1 << PINB0);
		send_data("LED ON\n\r");
		//new_line();
	}
	else{
		PORTB &= ~(1 << PINB0);
		send_data("LED OFF\n\r");
		//new_line();
	}
}

void afisare_timp(){
	
	incrementare_minute();
		
	if((flag_timer == 1) && (flag_afisare_timp == 1))
	{	
		
		//send_data(CLEAR);
		
		//send_data("Timp: ");
		
		itoa(secunde,  ch_sec, 10);
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
			send_data(":");
			send_data(ch_sec);
		}
		else
		{
			send_data(":");
			send_data(ch_sec);
		}
		
		
		send_data("\n\r");
		new_line();
		flag_timer = 0;
	}
}

