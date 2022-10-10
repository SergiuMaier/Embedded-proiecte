/*
 * functii_afisare.c
 *
 * Created: 10/6/2022 10:51:48 AM
 *  Author: Sergiu Maier
 */ 

#include "functii_afisare.h"
#include <stdio.h>

void new_line(){
	
	send_data("\n\r>>");
}

void afisare_meniu(){
	
	send_data("\n\rApasa tasta:\n\r 1. Meniu\n\r 2. Timp\n\r 5. LED ON/OFF\n\r");
}

void switch_data(char c){
	//char a[200];
	
	switch(c)
	{
	case '1':
		
		//PORTB |= (1 << PINB0);
	
		send_data(CLEAR);  	  
		send_data("\n\r Ascuns\n\r");
		afisare_meniu();
		new_line();
		flag_afisare_timp = 0;
		break;
	
	case '2': 
		
		new_line();
	    flag_afisare_timp = 1;
		break;
			
	case '5': 
		
		stare_led = !stare_led;
		aprinde_led();
		break;
		
	default: 
		
		//sprintf(a, "incorect");
		//send_data(a);
		
		send_data("\n\rINCORECT!\n\r");
		afisare_meniu();
		new_line();
		break;
	}
}

void aprinde_led(){
	
	if(stare_led == 1){
		send_data("\n\rLED ON\n\r");
		PORTB |= (1 << PINB0);
		new_line();
	}
	else{
		send_data("\n\rLED OFF\n\r");
		PORTB &= ~(1 << PINB0);
		new_line();
	}
}

void afisare_program(){
	
	incrementare_minute();
	
	if((flag_timer == 1) && (flag_afisare_timp == 1))
	{
		send_data(CLEAR);
		send_data("\n\r Timp: ");
		
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
		
		if((secunde >= 0) && (secunde < 10)) //interval pt rezolvare bug 00:059
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
		new_line();
		flag_timer = 0;
	}
}

