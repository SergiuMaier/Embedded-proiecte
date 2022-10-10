/*
 * main_func.c
 *
 * Created: 9/26/2022 11:12:11 AM
 *  Author: Sergiu Maier
 */ 

#include "timer.h"

void init_timer(){

	TCCR0A |= (1 << WGM01)|(0 << WGM00);           //mod ctc
	OCR0A = 0xF9;                                  //pt 10ms
	TCCR0B |= (0 << CS02)|(1 << CS01)|(1 << CS00); //prescalar 64
	TIMSK0 |= (1 << OCIE0A);
}

void init_devices(){
	
	cli();
	
	//init_porturi:
	DDRB = 0x03;
	PORTB = 0x00;
	
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
	
	if(secunde >= 60){	//in ISR aveam 01:59 in loc de 01:00
		secunde %= 60;
		minute++;
	}
}



