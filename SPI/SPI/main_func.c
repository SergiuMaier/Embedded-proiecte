/*
 * main_func.c
 *
 * Created: 9/21/2022 12:29:37 PM
 *  Author: sergiu
 */ 

#include "main_func.h"
#include "main_defines.h"

void interrupt_init(void){
	
	EICRA |= (1 << ISC11) | (1 << ISC10) | (1 << ISC01) | (1 << ISC00);
	EIMSK |= (1 << INT1) | (1 << INT0);
	EIFR |= (0 << INTF1) | (0 << INTF0);
	PCICR |= (0 << PCIE2) | (0 << PCIE1) | (0 << PCIE0);
}

void timer_init(void){
	
	TCCR0A |= (1 << WGM01) | (0 << WGM00);
	OCR0A = 0xF9; 
	TCCR0B |= (1<<CS02)|(0<<CS01)|(0<<CS00); //256
	TIMSK0 |= (1 << OCIE0A);
}

void init_devices(){
	
	cli();
	
	interrupt_init();
	timer_init();
	
	sei();
}

//void increment_minute(void){
	//
	//minute++;
	//
	//if(minute >= 60){
		//ore++;
		//minute %= 60;
	//}
//}

void send_data(char *ptr){
	
	while(*ptr != 0x00){
		USART_Transmit(*ptr);
		ptr++;
	}
}

ISR(TIMER0_COMPA_vect){
	
	cli();
	
	contor++;
	
	if(contor >= 250)
	{
		secunde++;
		contor = 0;
		
		//if(secunde >= 60)
		//{
			//increment_minute();
			//secunde %= 60;
		//}	
	}
	
	sei();
}