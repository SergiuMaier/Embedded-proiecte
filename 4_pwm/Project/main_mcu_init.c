/*
 * main_mcu_init.c
 *
 * Created: 8/31/2022 9:00:08 AM
 *  Author: Sergiu Maier
 */ 

#include "main_mcu_init.h"
#include "main_defines.h"
#include "timer0_func.h"
#include "main_func.h"

#include <stdio.h>

void port_init(void){
	
	DDRD = 0x40;   //01000000
	PORTD = 0x40;

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