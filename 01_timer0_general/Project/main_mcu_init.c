/*
 * main_mcu_init.c
 *
 * Created: 8/31/2022 9:00:08 AM
 *  Author: Sergiu Maier
 */ 

#include "main_mcu_init.h"
#include "main_defines.h"
#include "main_func.h"

#include <stdio.h>

void port_init(void){
	
	DDRB = 0x0F;	//00001111
	PORTB = 0x00;
	DDRD |= (1 << PIND2) | (1 << PIND3);  //INT0 & INT1
	PORTD |= (1 << PIND2) | (1 << PIND3);
}

void timer0_init(void){
	
	TCCR0A |= (1 << WGM01) | (0 << WGM00);  //modul CTC
	
	calcul_valoare_registru_ocr0a();	//OCR0A
	
	TCCR0B |= TIMER_PRESCALAR_256;		//prescalar ales pt valoarea 0.004s (vezi main_defines.h)
	TIMSK0 |= (1 << OCIE0A);
}

void interrupt_init(void){
	
	EICRA |= (1 << ISC11) | (1 << ISC10) | (1 << ISC01) | (1 << ISC00);
	EIMSK |= (1 << INT1) | (1 << INT0);
	EIFR |= (0 << INTF1) | (0 << INTF0);
	PCICR |= (0 << PCIE2) | (0 << PCIE1) | (0 << PCIE0);
}

void init_devices(void){
	
	cli();
	
	port_init();
	interrupt_init();
	timer0_init();
	
	sei();
}
