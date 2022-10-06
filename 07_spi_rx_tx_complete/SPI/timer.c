/*
 * main_func.c
 *
 * Created: 9/26/2022 11:12:11 AM
 *  Author: Sergiu Maier
 */ 

#include "timer.h"

void init_timer(){
	
	TCCR0A |= (1 << WGM01)|(0 << WGM00);           //mod ctc
	OCR0A = 0xF9;                                  //duty cycle 10ms
	TCCR0B |= (0 << CS02)|(1 << CS01)|(1 << CS00); //prescalar 64
	TIMSK0 |= (1 << OCIE0A);
}

void init_devices(){
	
	cli();
	
	init_timer();
	
	sei();
}

ISR(TIMER0_COMPA_vect){
	
	cli();
	
	contor++;
	
	if(contor >= 1000){
		secunde++;
		contor = 0;
		flag_timer = 1;
	}
	
	sei();
}

void incrementare_minute(){
	
	if(secunde >= 60)	//in ISR aveam 01:59 in loc de 01:00
	{
		secunde %= 60;
		minute++;
	}
}

void afisare_timp(){
	
	incrementare_minute();	
	
	if(flag_timer == 1)
	{	
		send_data(CLEAR);
		send_data("\n\r |-------------|-------------|\n\r");
		send_data(" | Timp: ");
		
		itoa(secunde, ch_sec, 10);
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
		
		send_data(" |\n\r |-------------|-------------|\n\r");
		new_line();
		
		flag_timer = 0;
	}
} 

