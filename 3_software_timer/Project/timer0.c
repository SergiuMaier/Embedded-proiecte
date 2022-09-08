/*
 * timer0_func.c
 *
 * Created: 9/1/2022 12:35:25 PM
 *  Author: sergi
 */ 
#include "timer0_def.h"

void timer0_init(void){
	
	TCCR0A |= (1 << WGM01) | (0 << WGM00);  //modul CTC
	OCR0A = 0xF9;
	TIMSK0 |= (1 << OCIE0A);
}

void start_timer0(){
	TCCR0B |= START_TIMER0;
}

void stop_timer0(){
	TCCR0B &= STOP_TIMER0;
}