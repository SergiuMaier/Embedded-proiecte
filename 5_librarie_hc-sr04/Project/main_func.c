/*
 * main_func.c
 *
 * Created: 9/01/2022 10:14:32 AM
 *  Author: Sergiu Maier
 */ 

#include "main_func.h"
#include "main_defines.h"
#include "timer0_func.h"
#include "senzor_hc_sr04.h"

void pinSet(volatile uint8_t *port, uint8_t pin){
	
	*port |=  1 << pin;
}

void pinReset(volatile uint8_t *port, uint8_t pin){
	
	*port &=  ~(1 << pin);
}

ISR(TIMER0_COMPA_vect){  
	
	cli();
	
	contor_secunde++;
	timp++;
	
	if(contor_secunde >= (1/GENERARE_INTRERUPERE)){
		secunde++;
		contor_secunde = 0;
	}
	
	sei();
}

ISR(INT0_vect){ 
	
	cli();
	
	if(PIND & (1 << PIND2))
		timp_start = timp; //primul front al semnalului
	else
	{
		timp_final = timp - timp_start;  //timp intre fronturi
		timp = 0;
	}
	
	sei();
}
