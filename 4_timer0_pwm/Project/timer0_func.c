/*
 * timer0_func.c
 *
 * Created: 9/13/2022 12:35:25 PM
 *  Author: sergiu
 */ 

#include "timer0_func.h"
#include "main_func.h"

void timer0_init(void){
	
	TCCR0A |= (1 << COM0A1)|(0 << COM0A0);  //non-inverting mode
	TCCR0A |= (1 << WGM01)|(1 << WGM00);    //fast PWM 
	OCR0A = 0; 							//factor de umplere
	TIMSK0 |= (1 << OCIE0A);
}

void start_timer0(){
	TCCR0B |= (1 << CS02)|(0 << CS01)|(1 << CS00); //prescalar 1024
}

void stop_timer0(){
	TCCR0B &= STOP_TIMER0;
}